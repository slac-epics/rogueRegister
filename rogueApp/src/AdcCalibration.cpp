#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <unistd.h>
#include "epicsStdio.h"
#include "pgpRogueLib.h"

using	namespace std;
namespace	rim = rogue::interfaces::memory;


#define	N_ADC				4
#define	N_ADC_CHAN			8
#define	N_ADC_LANE_PER_CHAN	8

int pgpRogueLib::AdcCalibration()
{
	const char	*	functionName = "pgpRogueLib::AdcCalibration";
	rim::VariablePtr	pVarDelayLane[N_ADC_CHAN][N_ADC_LANE_PER_CHAN];
	rim::VariablePtr	pVarDMode[N_ADC];
	rim::VariablePtr	pVarInvert[N_ADC];
	rim::VariablePtr	pVarConvert[N_ADC];
	rim::VariablePtr	pVarReg8[N_ADC];
	rim::VariablePtr	pVarRegF[N_ADC];
	rim::VariablePtr	pVarReg10[N_ADC];
	rim::VariablePtr	pVarReg11[N_ADC];
	rim::VariablePtr	pVarReg15[N_ADC];
	char				varPath[256];
	int					status;

	//pVar = getVariable( varPath );
	printf( "AdcCalibration()...\n" );
	// Enable all needed devices
	setVariable( "Top.SystemRegs.enable", 1 );
	setVariable( "Top.AdcPatternTester.enable", 1 );
	for ( unsigned int iAdc = 0; iAdc < N_ADC; iAdc++ )
	{
		unsigned int	iCh = iAdc >> 1;
		snprintf( varPath, 256, "Top.AdcConfig[%u].enable", iAdc );
		setVariable( varPath, 1 );
		snprintf( varPath, 256, "Top.AdcConfig[%u].Readout", iAdc );
		setVariable( varPath, 1 );

		// Set adcRoot to the root path for this ADC
		snprintf( varPath, 256, "Top.AdcConfig[%u]", iAdc );
		string	adcRoot( varPath );

		// Find all delay lane registers
		for ( unsigned int l = 0; l < 8; l++ )
			pVarDelayLane[iCh][l] = FindVar( adcRoot, ".DelayAdcALane[%u]", l );
		iCh++;
		for ( unsigned int l = 8; l < 16; l++ )
			pVarDelayLane[iCh][l] = FindVar( adcRoot, ".DelayAdcBLane[%u]", l );

		pVarDMode[iAdc]		= FindVar( adcRoot, ".DMode" );
		pVarInvert[iAdc]	= FindVar( adcRoot, ".Invert" );
		pVarConvert[iAdc]	= FindVar( adcRoot, ".Convert" );

		// Find all ADC settings registers
		pVarReg8[iAdc]  = FindVar( adcRoot, ".AdcReg_0x0008" );
		pVarRegF[iAdc]  = FindVar( adcRoot, ".AdcReg_0x000F" );
		pVarReg10[iAdc] = FindVar( adcRoot, ".AdcReg_0x0010" );
		pVarReg11[iAdc] = FindVar( adcRoot, ".AdcReg_0x0011" );
		pVarReg15[iAdc] = FindVar( adcRoot, ".AdcReg_0x0015" );
	}

	// Initial configuration for the slow ADC
	setVariable( "Top.SystemRegs.AvccEn0", true);
	setVariable( "Top.SystemRegs.AvccEn1", true);
	setVariable( "Top.SystemRegs.A0p3V3En", true);
	setVariable( "Top.SystemRegs.A1p3V3En", true);
	setVariable( "Top.SystemRegs.Ap1V8En", true);
	setVariable( "top.systemregs.adcctrl1", false);
	setVariable( "Top.SystemRegs.AdcCtrl2", false);
	setVariable( "Top.SystemRegs.AdcReset", true);
	sleep(1);
	setVariable( "Top.SystemRegs.AdcReset", false);
	sleep(1);
	for ( unsigned int iAdc = 0; iAdc < N_ADC; iAdc++ )
	{
	   pVarDMode[iAdc]->setValue((uint64_t)0x3);		// deserializer dmode 0x3
	   pVarInvert[iAdc]->setValue((uint64_t)0x0);		// do not invert data for pattern testing
	   pVarConvert[iAdc]->setValue((uint64_t)0x0);	// do not convert data for pattern testing
	   //pVarReg8[iAdc]->setValue((uint64_t)0x10);	// ADC binary data format
	   pVarRegF[iAdc]->setValue((uint64_t)0x66);		// ADC single pattern
	   pVarReg15[iAdc]->setValue((uint64_t)0x1);		// ADC DDR mode
	}

	setVariable( "Top.AdcPatternTester.Samples", 0xffff);
	setVariable( "Top.AdcPatternTester.Mask", 0xffff);

	bool	delayTestResults[32];

	// Iterate all ADC channels
	for ( unsigned int iCh = 0; iCh < N_ADC_CHAN; iCh++ )
	{
		unsigned int	iAdc = iCh << 1;
		// iterate all lanes on each ADC channel
		for ( unsigned int lane = 0; lane < N_ADC_LANE_PER_CHAN; lane++ )
		{
			// Test each of the 32 possible delay values
			for ( unsigned int delay = 0; delay < 32; delay++ )
			{
				bool	fPassed = true;

				// set tester channel
				setVariable( "Top.AdcPatternTester.Channel", iCh );
				// set delay
				pVarDelayLane[iCh][lane]->setValue((uint64_t) delay );

				// set pattern output in ADC
				unsigned int pattern = pow(2,(lane*2));
				pVarReg10[iAdc]->setValue((uint64_t)(pattern&0xFF00)>>8);
				pVarReg11[iAdc]->setValue((uint64_t) pattern&0x00FF    );

				// set tester pattern
				setVariable( "Top.AdcPatternTester.Pattern", pattern);

				// toggle request bit
				setVariable( "Top.AdcPatternTester.Request", false);
				setVariable( "Top.AdcPatternTester.Request", true);

				// wait until test done
				bool	fDone	= false;
				while ( !fDone )
				{
					if ( readVarPath( "Top.AdcPatternTester.Done", fDone ) != 0 )
					{
						printf( "%s: Error testing Ch %u, Lane %u\n", functionName, iCh, lane );
						break;
					}
				}
				bool	fTestFailed	= false;
				status = readVarPath( "Top.AdcPatternTester.Failed", fTestFailed );
				if ( status != 0 || !fTestFailed )
					fPassed = false;

				// shift pattern for next bit test (2 bits per lane)
				pattern = pattern << 1;
				pVarReg10[iAdc]->setValue((uint64_t)(pattern&0xFF00)>>8);
				pVarReg11[iAdc]->setValue((uint64_t) pattern&0x00FF    );

				// set tester pattern
				setVariable( "Top.AdcPatternTester.Pattern", pattern);

				// toggle request bit
				setVariable( "Top.AdcPatternTester.Request", false);
				setVariable( "Top.AdcPatternTester.Request", true);

				// wait until test done
				fDone	= false;
				while ( !fDone )
				{
					status = readVarPath( "Top.AdcPatternTester.Done", fDone );
					if ( status != 0 )
						break;
				}
				status = readVarPath( "Top.AdcPatternTester.Failed", fTestFailed );
				if ( status != 0 || !fTestFailed )
					fPassed = false;

				delayTestResults[delay] = fPassed;
			}

			// find best delay setting
			vector<unsigned int>	lengths;
			vector<int>				starts;
			vector<int>				stops;
			unsigned int	length		= 0;
			int				start		= -1;
			int				started		= 0;
			uint64_t		bestDelay	= 0L;
			for ( unsigned int i = 5; i < 32; i++ )
			{
				// find a vector of ones minimum width 5
				if (		delayTestResults[i  ] == true
						&&	delayTestResults[i-1] == true
						&&	delayTestResults[i-2] == true
						&&	delayTestResults[i-3] == true
						&&	delayTestResults[i-4] == true
						&&	delayTestResults[i-5] == true )
				{	// Start of vector
					started	=  1;
					length++;
					if ( start < 0 )
						start = i - 5;
				}
				else if (	delayTestResults[i  ] == false
						&&	delayTestResults[i-1] == true
						&&	delayTestResults[i-2] == true
						&&	delayTestResults[i-3] == true
						&&	delayTestResults[i-4] == true
						&&	delayTestResults[i-5] == true )
				{	// End of vector of successful test results
					lengths.push_back(length+5);
					starts.push_back(start);
					stops.push_back(i-1);
					length = 0;
					start = -1;
					started = 0;
				}
				if ( started == 1 and i == 31 )
				{
					lengths.push_back(length+5);
					starts.push_back(start);
					stops.push_back(i-1);
				}
			}

			// find the longest vector of ones
			if ( lengths.size() > 0 )
			{
				vector<unsigned int>::iterator	maxElem;
				maxElem = max_element( lengths.begin(), lengths.end() );
				size_t			index	= maxElem - lengths.begin();
				unsigned int	value	= *maxElem;
				bestDelay = starts[index] + (stops[index]-starts[index])/2;
				if ( DEBUG_PGP_ROGUE_LIB >= 3 )
					printf( "ADC %u, Lane %u BestDelay = %lu, longest run = %u\n", iCh, lane, bestDelay, value );
			}
			else
			{
				printf( "ADC %u, Lane %u FAILED!", iCh, lane );
				bestDelay = 0;
			}

			// set best delay
			pVarDelayLane[iCh][lane]->setValue( bestDelay );
		}
	}
	return 0;
}
