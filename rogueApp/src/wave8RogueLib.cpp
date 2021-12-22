//////////////////////////////////////////////////////////////////////////////
// This file is part of 'rogueRegister'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'rogueRegister', including this file,
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
//
//	wave8RogueLib driver
//
//	Header file for wave8RogueLib class.
//	It provides a templated interface to SLAC Wave8 PGP Hardware registers
//	via the Rogue LibraryBase C++ API
//

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <exception>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <sys/stat.h>
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <unistd.h>
#include <vector>


// rogue headers
#include "rogue/GeneralError.h"
#include "rogue/Logging.h"
#include "rogue/Version.h"

// aes-stream-drivers headers 
#include <AxisDriver.h>
#include <AxiVersion.h>
#include <DmaDriver.h>

// rogueRegister headers
#include "wave8RogueLib.h"

using namespace	std;
namespace rim = rogue::interfaces::memory;

typedef	std::map< std::string, rim::VariablePtr >	mapVarPtr_t;

#define	N_ADC				4
#define	N_ADC_CHAN			8
#define	N_ADC_LANE_PER_CHAN	8
#define	N_ADC_DELAYS		32


void wave8RogueLib::ResetCounters( )
{
	pgpRogueLib::ResetCounters( );

	// TODO: Add toggle option to setVariable
	setVariable( "Top.PgpMon[0].Ctrl.CountReset", 1 );
	setVariable( "Top.PgpMon[0].Ctrl.CountReset", 0 );

	// This resets   Top.BatcherEventBuilder.DataCnt[0]
	setVariable( "Top.BatcherEventBuilder.CntRst", 1 );
	setVariable( "Top.BatcherEventBuilder.CntRst", 0 );

	setVariable( "Top.TimingFrameRx.ClearRxCounters", 1 );
	setVariable( "Top.TimingFrameRx.ClearRxCounters", 0 );
}

void wave8RogueLib::GetEventBuilderBlowoffPath( unsigned int triggerNum, std::string & retPath )
{
#ifdef SUPPORT_CLINK
	char		varPath[256];
	const char * pszBlowoff		 = "ClinkDevRoot.ClinkPcie.Application.AppLane[%u].EventBuilder.Blowoff";
	snprintf( varPath, 256, pszBlowoff, triggerNum );
	retPath	= varPath;
#else  /* not SUPPORT_CLINK */
	retPath = "Top.BatcherEventBuilder.Blowoff";
#endif  /* SUPPORT_CLINK */
}


void wave8RogueLib::GetTriggerMasterEnablePath( unsigned int triggerNum, std::string & retPath )
{
	char		varPath[256];
#ifdef SUPPORT_CLINK
	const char * pszMasterEnable = "ClinkDevRoot.ClinkPcie.Hsio.TimingRx.TriggerEventManager.TriggerEventBuffer[%u].MasterEnable";
#else  /* not SUPPORT_CLINK */
	const char * pszMasterEnable = "Top.TriggerEventManager.TriggerEventBuffer[%u].MasterEnable";
#endif  /* SUPPORT_CLINK */

	snprintf( varPath, 256, pszMasterEnable, triggerNum );
	retPath	= varPath;
}


void wave8RogueLib::GetEventBuilderSoftRstPath( unsigned int triggerNum, std::string & retPath )
{
#ifdef SUPPORT_CLINK
	char		varPath[256];
	const char * pszSoftRst		 = "Top.BatcherEventBuilder.SoftRst";
	snprintf( varPath, 256, pszSoftRst, triggerNum );
	retPath	= varPath;
#else  /* not SUPPORT_CLINK */
	retPath = "Top.BatcherEventBuilder.SoftRst";
#endif  /* SUPPORT_CLINK */
}


int		wave8RogueLib::setTriggerEnable( unsigned int triggerNum, bool fEnable )
{
	int				status	= 0;
	std::string		varPath;
	if ( fEnable )
	{
		// Clear Blowoff
		GetEventBuilderBlowoffPath( 0, varPath );
		setVariable( varPath.c_str(),	0 );

		// Toggle SoftRst
		GetEventBuilderSoftRstPath( 0, varPath );
		setVariable( varPath.c_str(),	1 );
		setVariable( varPath.c_str(),	0 );

		// Set Trigger MasterEnable
		GetTriggerMasterEnablePath( triggerNum, varPath );
		setVariable( varPath.c_str(),	1 );
	}
	else
	{
		// Clear Trigger MasterEnable
		GetTriggerMasterEnablePath( triggerNum, varPath );
		setVariable( varPath.c_str(),	0 );

		// Set Blowoff
		GetEventBuilderBlowoffPath( triggerNum, varPath );
		setVariable( varPath.c_str(),	1 );
	}
	return status;
}

bool	wave8RogueLib::getTriggerEnable( unsigned int triggerNum )
{
	return false;
}


// TODO: Make different devices be subclasses of wave8RogueLib
#include "wave8AddrMap.h"
std::string		strWave8AddrMap( ROGUE_ADDR_MAP );


///	Constructor
wave8RogueLib::wave8RogueLib(
	unsigned int		board,
	const char		*	pszAddrMapFileName  )
:	pgpRogueLib(		board	)
#if 0
	,
	m_pAxiMemMap(			),
	m_pAxiMemMaster(		)
#endif
{
	const char		*	functionName	= "wave8RogueLib::wave8RogueLib";

#if 0
	//
	// Connect DATACHAN 0 KCU1500 Register Access
	//
	m_pAxiMemMap		= rogue::hardware::axi::AxiMemMap::create( m_devName );
	m_pAxiMemMaster		= ClMemoryMaster::create( );
	m_pAxiMemMaster->setSlave( m_pAxiMemMap );
	const char	*	szPcieMemName = "PCIe_Bar0";	// From interface name in wave8AddrMap.h
	addMemory( szPcieMemName, m_pAxiMemMap );		// TODO: Can we remove this?  Doesn't seem to be used. Unless for kcu SFPs
	//m_pRogueLib->addMemory( szPcieMemName, m_pAxiMemMap );
	printf("wave8RogueLib: addMemory AxiMemMap interface %s\n", szPcieMemName );
#endif

	m_pW8RegChan	= rogue::hardware::axi::AxiStreamDma::create( GetDevName(), PGP_DATACHAN_REG_ACCESS, true);

	//
	// Connect DATACHAN 0 WAVE8 Register Access
	//
	m_pSrpW8 = rogue::protocols::srp::SrpV3::create();	// Serial Rouge Protocol handler
	// Create bidirectional links between SRP and W8RegChan 
	m_pW8RegChan->addSlave( m_pSrpW8 );
	m_pSrpW8->addSlave( m_pW8RegChan );

//	const char	*	szMemName = "Wave8_Mem0";	// From interface name in wave8AddrMap.h
	const char	*	szMemName = "Unnamed_5";	// From interface name in wave8AddrMap.h
	addMemory( szMemName, m_pSrpW8 );
	//m_pRogueLib->addMemory( szMemName, m_pSrpW8 );
	printf("wave8RogueLib: addMemory srpW8 interface %s\n", szMemName );

	// Create W8MemMaster and link it to SRP
	m_pW8MemMaster = rim::Master::create( );
	m_pW8MemMaster->setSlave( m_pSrpW8 );

	const mapVarPtr_t &	mapVars		= getVariableList();
	printf( "%s: %zu variables\n", functionName, mapVars.size() );

	printf( "Parsing %s ROGUE_ADDR_MAP\n", pszAddrMapFileName );
#if 0
	parseAddrMapFile( pszAddrMapFileName );
#else
//	parseMemMap( pszAddrMapFileName );
	parseMemMap( strWave8AddrMap ); // From generated wave8AddrMap.h
#endif
	printf( "Wave8 ROGUE_ADDR_MAP parsed successfully\n" );
	std::cout << std::flush;

	// Force an initial read of all variables
	printf( "%s: Reading %zu variables\n", functionName, getVariableList().size() );
	try
	{
		readAll();
	}
	catch ( rogue::GeneralError & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	catch ( std::exception & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	catch ( ... )
	{
		printf( "%s unknown error!\n", functionName );
	}
	printf( "%s: Read %zu variables\n", functionName, getVariableList().size() );

	setTriggerEnable( 0, false );
	//setTriggerEnable( 1, false );
	//setTriggerEnable( 2, false );
	//setTriggerEnable( 3, false );

	//showVariableList( true );

	std::string sFpgaVersionPath( "Top.AxiVersion.BuildStamp" );
	showVariable( sFpgaVersionPath.c_str(), true );

	std::string sDataCnt( "Top.BatcherEventBuilder.DataCnt[0]" );
	showVariable( sDataCnt.c_str(), true );
	showVariable( "Top.AxiVersion.FpgaVersion", true );
	showVariable( "Top.AxiVersion.UpTimeCnt", true );
}

/// virtual Destructor
wave8RogueLib::~wave8RogueLib()
{
}


/// Wait for RxLinkUp
void wave8RogueLib::WaitForRxLinkUp( const char * pszDiagLabel )
{
	const struct timespec tenMs	= { 0, 10000000L };
	uint64_t	rxLinkUp	= 0;
	size_t		nTries		= 0;
	while ( rxLinkUp == 0 )
	{
		readVarPath( "Top.TimingFrameRx.RxLinkUp", rxLinkUp );
		if ( rxLinkUp )
			break;
		if ( nTries > 200 )
		{
			printf( "%s: Timeout waiting for RxLinkUp\n", pszDiagLabel );
			break;
		}
		nTries++;
		nanosleep( &tenMs, NULL );
	}
}


void wave8RogueLib::connect( )
{
	pgpRogueLib::connect();
}

void wave8RogueLib::disconnect( )
{
	printf( "wave8RogueLib::disconnect\n" );
#if 0
	m_pAxiMemMaster.reset();
	m_pAxiMemMap.reset();
#endif
	m_pW8RegChan.reset();
	m_pW8MemMaster.reset();
	m_pSrpW8.reset();
	pgpRogueLib::disconnect();
}


int wave8RogueLib::AdcCalibration()
{
	const char	*	functionName = "wave8RogueLib::AdcCalibration";
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

	DEBUG_PGP_ROGUE_LIB = 3;
	//pVar = getVariable( varPath );
	printf( "AdcCalibration()...\n" );
	// Enable all needed devices
	//setVariable( "Top.SystemRegs.enable", 1 );
	//setVariable( "Top.AdcPatternTester.enable", 1 );
	for ( unsigned int iAdc = 0; iAdc < N_ADC; iAdc++ )
	{
		unsigned int	iCh = iAdc * 2;
		//snprintf( varPath, 256, "Top.AdcConfig[%u].enable", iAdc );
		//setVariable( varPath, 1 );
		//snprintf( varPath, 256, "Top.AdcConfig[%u].Readout", iAdc );
		//setVariable( varPath, 1 );

		// Set adcReadout to the root path for this ADC
		snprintf( varPath, 256, "Top.AdcReadout[%u]", iAdc );
		string	adcReadout( varPath );
		snprintf( varPath, 256, "Top.AdcConfig[%u]", iAdc );
		string	adcConfig( varPath );

		// Find all delay lane registers
		for ( unsigned int l = 0; l < N_ADC_LANE_PER_CHAN; l++ )
		{
			pVarDelayLane[iCh  ][l] = FindVar( adcReadout, ".DelayAdcALane[%u]", l );
			pVarDelayLane[iCh+1][l] = FindVar( adcReadout, ".DelayAdcBLane[%u]", l );
		}

		pVarDMode[iAdc]		= FindVar( adcReadout, ".DMode" );
		pVarInvert[iAdc]	= FindVar( adcReadout, ".Invert" );
		pVarConvert[iAdc]	= FindVar( adcReadout, ".Convert" );

		// Find all ADC settings registers
		pVarReg8[iAdc]  = FindVar( adcConfig, ".AdcReg_0x0008" );
		pVarRegF[iAdc]  = FindVar( adcConfig, ".AdcReg_0x000F" );
		pVarReg10[iAdc] = FindVar( adcConfig, ".AdcReg_0x0010" );
		pVarReg11[iAdc] = FindVar( adcConfig, ".AdcReg_0x0011" );
		pVarReg15[iAdc] = FindVar( adcConfig, ".AdcReg_0x0015" );
	}

	// Initial configuration for the slow ADC
	setVariable( "Top.SystemRegs.AvccEn0", true);
	setVariable( "Top.SystemRegs.AvccEn1", true);
	setVariable( "Top.SystemRegs.A0p3V3En", true);
	setVariable( "Top.SystemRegs.A1p3V3En", true);
	setVariable( "Top.SystemRegs.Ap1V8En", true);
	setVariable( "Top.SystemRegs.AdcCtrl1", false);
	setVariable( "Top.SystemRegs.AdcCtrl2", false);
	sleep(1);
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

	bool	delayTestResults[N_ADC_DELAYS];

	// Iterate all ADC channels
	for ( unsigned int iCh = 0; iCh < N_ADC_CHAN; iCh++ )
	{
		const struct timespec tenthSec	= { 0, 100000000L };
		const struct timespec tenMs		= { 0, 10000000L };
		unsigned int	iAdc = iCh >> 1;
		// set pattern tester channel
		sleep(1);
		setVariable( "Top.AdcPatternTester.Channel", iCh );

		// iterate all lanes on each ADC channel
		for ( unsigned int lane = 0; lane < N_ADC_LANE_PER_CHAN; lane++ )
		{
			if ( DEBUG_PGP_ROGUE_LIB >= 3 )
				printf( "%s: Testing ADC %u, Ch %u, Lane %u ...\n", functionName, iAdc, iCh, lane );
			if ( !pVarDelayLane[iCh][lane] )
			{
				printf( "%s: Error Invalid DelayLane ptr for ADC %u, Ch %u, Lane %u!\n", functionName, iAdc, iCh, lane );
				continue;
			}
			sleep(1);

			// set pattern output in ADC
			unsigned int pattern = pow(2,(lane*2));
			pVarReg10[iAdc]->setValue((uint64_t)(pattern&0xFF00)>>8);
			pVarReg11[iAdc]->setValue((uint64_t) pattern&0x00FF    );

			// set tester pattern
			setVariable( "Top.AdcPatternTester.Pattern", pattern);

			// Test each of the 32 possible delay values
			for ( unsigned int delay = 0; delay < N_ADC_DELAYS; delay++ )
			{
				bool	fPassed = true;

				// set delay
				pVarDelayLane[iCh][lane]->setValue((uint64_t) delay );

				// toggle request bit
				setVariable( "Top.AdcPatternTester.Request", false);
				nanosleep( &tenMs, NULL );
				setVariable( "Top.AdcPatternTester.Request", true);

				// wait until test done
				bool	fDone	= false;
				DEBUG_PGP_ROGUE_LIB = 6;
				while ( !fDone )
				{
					nanosleep( &tenMs, NULL );
					if ( readVarPath( "Top.AdcPatternTester.Done", fDone ) != 0 )
					{
						printf( "%s: Error testing Ch %u, Lane %u\n", functionName, iCh, lane );
						break;
					}
				}
				bool	fTestFailed	= false;
				status = readVarPath( "Top.AdcPatternTester.Failed", fTestFailed );
				if ( status != 0 || fTestFailed )
					fPassed = false;
				if ( DEBUG_PGP_ROGUE_LIB >= 5 )
					printf( "PatternTest: ADC %u, Ch %u, Lane %u Bit 0: %s\n", iAdc, iCh, lane, (fPassed ? "Passed" : "FAILED") );
				DEBUG_PGP_ROGUE_LIB = 3;

				// shift pattern for next bit test (2 bits per lane)
				pattern = pattern << 1;
				pVarReg10[iAdc]->setValue((uint64_t)(pattern&0xFF00)>>8);
				pVarReg11[iAdc]->setValue((uint64_t) pattern&0x00FF    );

				// set tester pattern
				setVariable( "Top.AdcPatternTester.Pattern", pattern);

				// toggle request bit
				setVariable( "Top.AdcPatternTester.Request", false);
				setVariable( "Top.AdcPatternTester.Request", true);

				DEBUG_PGP_ROGUE_LIB = 6;
				// wait until test done
				fDone	= false;
				while ( !fDone )
				{
					nanosleep( &tenMs, NULL );
					status = readVarPath( "Top.AdcPatternTester.Done", fDone );
					if ( status != 0 )
						break;
				}
				status = readVarPath( "Top.AdcPatternTester.Failed", fTestFailed );
				if ( status != 0 || fTestFailed )
					fPassed = false;
				if ( DEBUG_PGP_ROGUE_LIB >= 5 )
					printf( "PatternTest: ADC %u, Ch %u, Lane %u Bit 1: %s\n", iAdc, iCh, lane, (fPassed ? "Passed" : "FAILED") );
				DEBUG_PGP_ROGUE_LIB = 3;

				delayTestResults[delay] = fPassed;
			}
			nanosleep( &tenthSec, NULL );
			if ( DEBUG_PGP_ROGUE_LIB >= 3 )
				printf( "%s: Evaluating test results Lane %u ...\n", functionName, lane );
			sleep( 2 );

			// find best delay setting
			vector<unsigned int>	lengths;
			vector<int>				starts;
			vector<int>				stops;
			unsigned int	length		= 0;
			int				start		= -1;
			int				started		= 0;
			uint64_t		bestDelay	= 0L;
			for ( unsigned int i = 5; i < N_ADC_DELAYS; i++ )
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
				if ( DEBUG_PGP_ROGUE_LIB >= 3 )
					printf( "%s: Finding longest of %zu vectors of ones for Lane %u ...\n", functionName, lengths.size(), lane );
				sleep( 2 );
				vector<unsigned int>::iterator	maxElem;
				maxElem = max_element( lengths.begin(), lengths.end() );
				size_t			index	= maxElem - lengths.begin();
				unsigned int	value	= *maxElem;
				bestDelay = starts[index] + (stops[index]-starts[index])/2;
				if ( DEBUG_PGP_ROGUE_LIB >= 3 )
					printf( "ADC %u, Ch %u, Lane %u BestDelay = %lu, longest run = %u\n", iAdc, iCh, lane, bestDelay, value );

				// set best delay
				pVarDelayLane[iCh][lane]->setValue( bestDelay );
			}
			else
			{
				printf( "ADC %u, Ch %u, Lane %u FAILED!\n", iAdc, iCh, lane );
			}
		}
	}

	// Restore normal ADC registers
	for ( unsigned int iAdc = 0; iAdc < N_ADC; iAdc++ )
	{
	   pVarDMode[iAdc]->setValue((uint64_t)0x3);	// deserializer dmode 0x3
	   pVarInvert[iAdc]->setValue((uint64_t)0x1);	// invert data
	   pVarConvert[iAdc]->setValue((uint64_t)0x0);	// convert data for pattern testing
	   pVarRegF[iAdc]->setValue((uint64_t)0x0);		// ADC single pattern
	   pVarReg15[iAdc]->setValue((uint64_t)0x1);	// ADC DDR mode
	}
	setVariable( "Top.SystemRegs.AdcCtrl1", true);
	setVariable( "Top.SystemRegs.AdcCtrl2", true);
	printf( "%s: Test done.\n", functionName );
	return 0;
}
