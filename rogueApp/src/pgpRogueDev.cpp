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
//	pgpRogueDev driver
//
//	EPICS device support for rogue compatible firmware on a KCU1500 pciE card.
//	Device data streams are accessed via the SLAC Rogue streaming API.
//

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <typeinfo>

// EPICS headers
#include <iocsh.h>
#include <errlog.h>
#include <epicsExport.h>
#include <epicsThread.h>

// rogue headers
//#include "rogue/GeneralError.h"
//#include "rogue/Logging.h"
#include "rogue/Version.h"

// aes-stream-drivers headers 
//#include <AxisDriver.h>
#include <AxiVersion.h>
//#include <DmaDriver.h>

#include "pgpRogueDev.h"

using namespace	std;
namespace ris = rogue::interfaces::stream;

int		DEBUG_PGP_ROGUE	= 0;
int		DEBUG_PGP_ROGUE_DEV	= 2;

#define	N_PGP_ROGUE_DEV	4

///	ppgRogue map - Stores ptr to all pgpRogueDev instances indexed by name
//map<string, pgpRogueDevPtr *>	pgpRogueDev::ms_pgpRogueDevMap;
static	pgpRogueDevPtr	gPgpRogueDev[N_PGP_ROGUE_DEV];

int		pgpRogueDev::setTriggerEnable( unsigned int triggerNum, bool fEnable )
{
	int		status	= 0;
	return status;
}


///	Constructor
pgpRogueDev::pgpRogueDev(
	unsigned int				board,
	unsigned int				lane )
:
	m_fExitApp(		false	),
	m_pRogueLib(	NULL	),
	m_fd(			0		),
	m_board(		board	),
	m_lane(			lane	),
	m_fConnected(	0		),
	m_devName(				),
	m_devLock(				),
	m_pDataChan(			),
	m_pDataStream(			)
{
	const char		*	functionName	= "pgpRogueDev::pgpRogueDev";

	// Create mutexes
    m_devLock	= epicsMutexMustCreate();

    // Initialize I/O Intr processing
	for ( size_t iSig = 0; iSig < PGP_NUM_SIGNALS; iSig++ )
	{
		scanIoInit( &m_scanIoSignal[iSig] );
		if ( m_scanIoSignal[iSig] == NULL )
			errlogPrintf( "%s: ERROR, scanIoInit failed!\n", functionName );
	}

    // Install exit hook for clean shutdown
//	epicsAtExit( (EPICSTHREADFUNC)pgpRogueDev::ExitHook, (void *) this );

	/*
	 * Check arguments
	 */

	char	acDevName[60];
	sprintf( acDevName, "/dev/datadev_%u", board );
	m_devName = acDevName;

#if 0
	uint8_t mask[DMA_MASK_SIZE];
	dmaInitMaskBytes(mask);
	for (unsigned lane=0; lane<4; lane++) {
		dmaAddMaskBytes((uint8_t*)mask, (lane<<8 | channel));
	}
#endif

	m_LibVersion = rogue::Version::current();
	// See if we can connect to the device
	m_fd = open(m_devName.c_str(), O_RDWR);
	if (m_fd < 0) {
		std::cout << "Error opening " << m_devName << std::endl;
	}
	else
	{
		AxiVersion vsn;
		if ( axiVersionGet(m_fd, &vsn) >= 0 )
		{
			printf("pgpRogueDev: -- Core Axi Version --\n");
			printf("firmwareVersion : %x\n", vsn.firmwareVersion);
			printf("buildString     : %s\n", vsn.buildString); 
			//printf("upTimeCount     : %u\n", vsn.upTimeCount);
			//printf("deviceId        : %x\n", vsn.deviceId);
			//printf("buildString     : %s\n", vsn.buildString);

			// TODO: Need a better mapping of these version strings to EPICS PVs
			m_DrvVersion = vsn.firmwareVersion;
			//m_LibVersion = vsn.buildString;
		}
	}

	//
	// Create Data Channels
	// TODO: Make a function than encapsulates this
	uint32_t	dest;
	dest = (0x100 * m_lane) + PGP_DATACHAN_FRAME_ACCESS;
	if ( DEBUG_PGP_ROGUE_DEV >= 1 )
		printf( "%s: Creating DataChan for %s, dest %u ...\n", functionName, m_devName.c_str(), dest );
	m_pDataChan	= rogue::hardware::axi::AxiStreamDma::create( m_devName, dest, true);

	// Full rate unbatcher
	m_pUnbatcher	= rogue::protocols::batcher::SplitterV1::create();
	m_pDataChan->addSlave( m_pUnbatcher );

	//
	// Connect DATACHAN 1 Frame Stream
	if ( DEBUG_PGP_ROGUE_DEV >= 1 )
		printf( "%s: Connecting DataChan to DataStream ...\n", functionName );
	m_pDataStream	= DataStream::create(this, "DataStream");
	m_pDataChan->addSlave( m_pDataStream );
	// or
	// m_pUnbatcher->addSlave( m_pDataStream );

	double	rateDropPeriod		= 1.0;	// seconds?
	bool	rateDropUsePeriod	= true;
	if ( DEBUG_PGP_ROGUE_DEV >= 1 )
		printf( "%s: Connecting DataChan to RateDrop, period %f0.3 ...\n", functionName, rateDropPeriod );
	m_pRateDrop	= ris::RateDrop::create( rateDropUsePeriod, rateDropPeriod );
	m_pDataChan->addSlave( m_pRateDrop );

	if ( DEBUG_PGP_ROGUE_DEV >= 1 )
		printf( "%s: Connecting RateDrop to Fifo ...\n", functionName );
	// 	ris::FifoPtr create(uint32_t maxDepth, uint32_t trimSize, bool noCopy)
	m_pDataFifo	= ris::Fifo::create( 0, 0, false );
	m_pRateDrop->addSlave( m_pDataFifo );
	
	// EPICS unbatcher
	m_pEpicsUnbatcher	= rogue::protocols::batcher::SplitterV1::create();
	m_pDataFifo->addSlave( m_pEpicsUnbatcher );

	m_pEpicsDataStream	= DataStream::create(this, "EpicsStream");
	m_pEpicsUnbatcher->addSlave( m_pEpicsDataStream );

	m_fConnected = 1;	// Do we need this?
	//StartRun( m_fd );
}

/// virtual Destructor
pgpRogueDev::~pgpRogueDev()
{
//	Shutdown();

	// Cleanup driver
	//delete m_pSyncDataAcquirer;
	//m_pSyncDataAcquirer	= NULL;

	close( m_fd );
	epicsMutexDestroy(	m_devLock );
}

/// Configure timing for LCLS-I

void pgpRogueDev::connect( )
{
}

void pgpRogueDev::disconnect( )
{
}

void pgpRogueDev::ProcessData(
	DataCbInfo		* pDataInfo )
{
	const char		*	functionName	= "pgpRogueDev::ProcessData";
	if ( DEBUG_PGP_ROGUE_DEV >= 5 ) printf( "%s\n", functionName );
	//epicsTimeStamp		tsData	= pDataInfo->m_tsData;

	// From wave8-git/firmware/python/wave8/RawDataReceiver.py
	// # Get data from frame
	// loadSize = frame.getPayload()
	// dat = bytearray(loadSize)
	// frame.read(dat,0)
	// ris::fromFrame( it, loadSize, dat )
	//
	// array = []
	// array = [	int.from_bytes( dat[i:i+2], byteorder='little', signed=False )
	// 					for i in range(0,loadSize,2)	]
	if  ( m_CallbackClientFunc != NULL )
		(*m_CallbackClientFunc)( m_pCallbackClient, pDataInfo );

	return;
}

void pgpRogueDev::cancelDataCallbacks( )
{
	m_pCallbackClient		= NULL;
	m_CallbackClientFunc	= NULL;
}

void pgpRogueDev::requestDataCallbacks( void * pClientContext, DataCallback callbackFunction )
{
	m_pCallbackClient		= pClientContext;
	m_CallbackClientFunc	= callbackFunction;
}

int	pgpRogueDev::DumpPgpVars( const char * pszFilePath, bool fWriteOnly, bool fForceRead )
{
	const char	*	functionName = "pgpRogueDev::DumpPgpVars";
	if ( m_pRogueLib == NULL )
	{
		printf( "%s error: %s PGP Dev not configured!\n", functionName, m_devName.c_str() );
		return -1;
	}
	m_pRogueLib->dumpVariables( pszFilePath, fWriteOnly, fForceRead, false );
	return 0;
}

int pgpRogueDev::SetPgpVariable( const char * pszVarPath, double value )
{
	const char	*	functionName = "pgpRogueDev::SetPgpVariable";
	if ( m_pRogueLib == NULL )
	{
		printf( "%s error: %s PGP Dev not configured!\n", functionName, m_devName.c_str() );
		return -1;
	}
	m_pRogueLib->setVariable( pszVarPath, value, false );
	return 0;
}

int pgpRogueDev::ShowPgpVariable( const char * pszVarPath, int level )
{
	const char	*	functionName = "pgpRogueDev::ShowPgpVariable";
	if ( m_pRogueLib == NULL )
	{
		printf( "%s error: %s PGP Dev not configured!\n", functionName, m_devName.c_str() );
		return -1;
	}
	m_pRogueLib->showVariable( pszVarPath, level != 0 );
	return 0;
}

extern "C" int
pgpRogueDevConfig(
	int				board,
	int				lane,
	bool			)
{
	if ( gPgpRogueDev[lane] )
	{
		gPgpRogueDev[lane]->disconnect();
		gPgpRogueDev[lane].reset();
	}
	gPgpRogueDev[lane] = pgpRogueDev::create( board, lane );
    return 0;
}

pgpRogueDevPtr	pgpRogueDev::RogueFindByBoard( unsigned int board )
{
	if ( board >= N_PGP_ROGUE_DEV )
	{
		return NULL;
	}
	return gPgpRogueDev[board];
}

int pgpRogueDev::ShowReport( int level )
{
    if ( level < 0 )
		return 0;

	cout << "\tRogue " << m_devName	<< " is installed on board " << m_board << " Lane " << m_lane << endl;
	if ( level >= 1 )
	{
		//cout	<< "\t\tType: "			<< m_RogueClass
		//		<< " "					<< m_RogueModel
		//		<< ", configuration: " 	<< m_ConfigFile << endl;
	}
	if ( level >= 3 && m_pRogueLib )
	{
		m_pRogueLib->showVariableList( level >= 4 );
	}
    return 0;
}

extern "C"
int ShowAllRogueDev( int level )
{
	if ( level < 0 )
		return 0;

	for ( size_t i = 0; i < N_PGP_ROGUE_DEV; i++ )
	{
		if ( !gPgpRogueDev[i] )
			continue;
		gPgpRogueDev[i]->ShowReport( level );
	}

    return 0;
}


// Register function:
//		int ShowAllRogue( int level )
static const iocshArg		ShowAllRogueArg0		= { "level",		iocshArgInt };
static const iocshArg	*	ShowAllRogueArgs[1]	=
{
	&ShowAllRogueArg0
};
static const iocshFuncDef   ShowAllRogueFuncDef	= { "ShowAllRogue", 1, ShowAllRogueArgs };
static int  ShowAllRogueCallFunc( const iocshArgBuf * args )
{
	return static_cast<int>( ShowAllRogueDev( args[0].ival ) );
}
void ShowAllRogueRegister(void)
{
	iocshRegister( &ShowAllRogueFuncDef, reinterpret_cast<iocshCallFunc>(ShowAllRogueCallFunc) );
}

// Register Function:
//	int pgpRogueDevConfig( int board, int lane )
static const iocshArg		pgpRogueDevConfigArg0	= { "board",		iocshArgInt };
static const iocshArg		pgpRogueDevConfigArg1	= { "lane",			iocshArgInt };
static const iocshArg		pgpRogueDevConfigArg2	= { "fLcls2Timing",	iocshArgInt };
static const iocshArg	*	pgpRogueDevConfigArgs[3]	=
{
	&pgpRogueDevConfigArg0, &pgpRogueDevConfigArg1, &pgpRogueDevConfigArg2
};
static const iocshFuncDef   pgpRogueDevConfigFuncDef	= { "pgpRogueDevConfig", 3, pgpRogueDevConfigArgs };
static int  pgpRogueDevConfigCallFunc( const iocshArgBuf * args )
{
    return pgpRogueDevConfig( args[0].ival, args[1].ival, args[2].ival );
}
void pgpRogueDevConfigRegister(void)
{
	iocshRegister( &pgpRogueDevConfigFuncDef, reinterpret_cast<iocshCallFunc>(pgpRogueDevConfigCallFunc) );
}

extern "C"
int DumpPgpVars( const char * pszCamName, const char * pszFilePath, int fWriteOnly, int fForceRead )
{
	const char	*	functionName = "DumpPgpVars";
	if ( pszCamName == NULL || pszFilePath == NULL )
	{
		printf( "Usage: %s camPortName dumpPath fWriteOnly fForceRead\n", functionName );
		printf( "Example: %s CAM dumpConfig.yml 1 1\n", functionName );
		return -1;
	}

	//pgpRogueDev	*	pRogue = pgpRogueDev::RogueFindByName( std::string(pszCamName) );
	pgpRogueDevPtr	pRogue = pgpRogueDev::RogueFindByBoard( 0 );
	if ( pRogue == NULL )
	{
		printf( "%s error: Rogue %s not found!\n", functionName, pszCamName );
		return -1;
	}

	return pRogue->DumpPgpVars( pszFilePath, fWriteOnly, fForceRead );
}

// Register function:
//		int DumpPgpVars( camName, dumpFile, fWriteOnly, fForceRead )
static const iocshArg		DumpPgpVarsArg0		= { "camName",		iocshArgString };
static const iocshArg		DumpPgpVarsArg1		= { "dumpFile",		iocshArgString };
static const iocshArg		DumpPgpVarsArg2		= { "fWriteOnly",	iocshArgInt };
static const iocshArg		DumpPgpVarsArg3		= { "fForceRead",	iocshArgInt };
static const iocshArg	*	DumpPgpVarsArgs[4]	=
{
	&DumpPgpVarsArg0, &DumpPgpVarsArg1, &DumpPgpVarsArg2, &DumpPgpVarsArg3
};
static const iocshFuncDef   DumpPgpVarsFuncDef	= { "DumpPgpVars", 4, DumpPgpVarsArgs };
static int  DumpPgpVarsCallFunc( const iocshArgBuf * args )
{
	return static_cast<int>( DumpPgpVars( args[0].sval, args[1].sval, args[2].ival, args[3].ival ) );
}
void DumpPgpVarsRegister(void)
{
	iocshRegister( &DumpPgpVarsFuncDef, reinterpret_cast<iocshCallFunc>(DumpPgpVarsCallFunc) );
}

extern "C"
int SetPgpVariable( const char * pszCamName, const char * pszVarPath, double value )
{
	const char	*	functionName = "SetPgpVariable";
	if ( pszCamName == NULL || pszVarPath == NULL )
	{
		printf( "Usage: %s camPortName varPath\n", functionName );
		printf( "Example: %s CAM ClinkDevRoot.ClinkPcie.AxiPcieCore.AxiVersion.BuildStamp\n", functionName );
		return -1;
	}

	//pgpRogueDev	*	pRogue = pgpRogueDev::RogueFindByName( std::string(pszCamName) );
	pgpRogueDevPtr	pRogue = pgpRogueDev::RogueFindByBoard( 0 );
	if ( pRogue == NULL )
	{
		printf( "%s error: Rogue %s not found!\n", functionName, pszCamName );
		return -1;
	}

	return pRogue->SetPgpVariable( pszVarPath, value );
}

// Register function:
//		int SetPgpVar( camName, varName, value )
static const iocshArg		SetPgpVarArg0		= { "camName",		iocshArgString };
static const iocshArg		SetPgpVarArg1		= { "varName",		iocshArgString };
static const iocshArg		SetPgpVarArg2		= { "value",		iocshArgDouble };
static const iocshArg	*	SetPgpVarArgs[3]	=
{
	&SetPgpVarArg0, &SetPgpVarArg1, &SetPgpVarArg2
};
static const iocshFuncDef   SetPgpVarFuncDef	= { "SetPgpVar", 3, SetPgpVarArgs };
static int  SetPgpVarCallFunc( const iocshArgBuf * args )
{
	return static_cast<int>( SetPgpVariable( args[0].sval, args[1].sval, args[2].dval ) );
}
void SetPgpVarRegister(void)
{
	iocshRegister( &SetPgpVarFuncDef, reinterpret_cast<iocshCallFunc>(SetPgpVarCallFunc) );
}

extern "C"
int ShowPgpVariable( const char * pszCamName, const char * pszVarPath, int level )
{
	const char	*	functionName = "ShowPgpVariable";
	if ( pszCamName == NULL || pszVarPath == NULL )
	{
		printf( "Usage: %s camPortName varPath\n", functionName );
		printf( "Example: %s CAM ClinkDevRoot.ClinkPcie.AxiPcieCore.AxiVersion.BuildStamp\n", functionName );
		return -1;
	}

	//pgpRogueDev	*	pRogue = pgpRogueDev::RogueFindByName( std::string(pszCamName) );
	pgpRogueDevPtr	pRogue = pgpRogueDev::RogueFindByBoard( 0 );
	if ( pRogue == NULL )
	{
		printf( "%s error: Rogue %s not found!\n", functionName, pszCamName );
		return -1;
	}

	return pRogue->ShowPgpVariable( pszVarPath, level );
}

// Register function:
//		int ShowPgpVar( camName, varName, level )
static const iocshArg		ShowPgpVarArg0		= { "camName",		iocshArgString };
static const iocshArg		ShowPgpVarArg1		= { "varName",		iocshArgString };
static const iocshArg		ShowPgpVarArg2		= { "level",		iocshArgInt };
static const iocshArg	*	ShowPgpVarArgs[3]	=
{
	&ShowPgpVarArg0, &ShowPgpVarArg1, &ShowPgpVarArg2
};
static const iocshFuncDef   ShowPgpVarFuncDef	= { "ShowPgpVar", 3, ShowPgpVarArgs };
static int  ShowPgpVarCallFunc( const iocshArgBuf * args )
{
	return static_cast<int>( ShowPgpVariable( args[0].sval, args[1].sval, args[2].ival ) );
}
void ShowPgpVarRegister(void)
{
	iocshRegister( &ShowPgpVarFuncDef, reinterpret_cast<iocshCallFunc>(ShowPgpVarCallFunc) );
}

extern "C"
{
	epicsExportRegistrar( pgpRogueDevConfigRegister );
	epicsExportRegistrar( DumpPgpVarsRegister );
	epicsExportRegistrar( SetPgpVarRegister );
	epicsExportRegistrar( ShowAllRogueRegister );
	epicsExportRegistrar( ShowPgpVarRegister );
	epicsExportAddress( int, DEBUG_PGP_ROGUE_DEV );
	epicsExportAddress( int, DEBUG_PGP_ROGUE );
}

