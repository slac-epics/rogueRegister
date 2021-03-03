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
//	pgpRogueLib driver
//
//	Header file for pgpRogueLib class.
//	It provides a templated interface to SLAC Generic PGP Hardware registers
//	via the Rogue LibraryBase C++ API
//

#include <stdio.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>


// rogue headers
#include "rogue/GeneralError.h"
#include "rogue/Logging.h"
#include "rogue/Version.h"

// aes-stream-drivers headers 
#include <AxisDriver.h>
#include <AxiVersion.h>
#include <DmaDriver.h>

// rogueRegister headers
#include "pgpRogueLib.h"

using namespace	std;
namespace rim = rogue::interfaces::memory;

typedef	std::map< std::string, rim::VariablePtr >	mapVarPtr_t;

int		DEBUG_PGP_ROGUE_LIB	= 0;
bool	bUseMiniTpg			= 0;
#ifdef SUPPORT_CLINK
//int		doFebConfig		= 0;
//int		doFebFpgaReload	= 1;
#endif  /* SUPPORT_CLINK */

// TODO Move to new file: src/rogue/memory/interfaces/memory/Constants.cpp
// TODO Rename BlockProcessingType2String()?
// TODO Rename rim::Variable::getTypeName()?
// TODO Create new set of rim::Variable types: UInt8, UInt16, UInt32, ..., Int8, ..., Float32, Float64, ...
// TODO Create uint32_t rim::Variable::getType()?
const char * modelId2String( uint32_t modelId )
{
	const char	*	pTypeName;
	switch ( modelId )
	{
	default:			pTypeName	= "Invalid";	break;
	case rim::PyFunc:	pTypeName	= "PyFunc";		break;
	case rim::Bytes:	pTypeName	= "Bytes";		break;
	case rim::UInt:		pTypeName	= "UInt";		break;
	case rim::Int:		pTypeName	= "Int";		break;
	case rim::Bool:		pTypeName	= "Bool";		break;
	case rim::String:	pTypeName	= "String";		break;
	case rim::Float:	pTypeName	= "Float";		break;
	case rim::Double:	pTypeName	= "Double";		break;
	case rim::Fixed:	pTypeName	= "Fixed";		break;
	case rim::Custom:	pTypeName	= "Custom";		break;
	}
	return pTypeName;
}

void pgpRogueLib::ResetCounters( )
{
	// TODO: Add toggle option to setVariable
//	setVariable( "Top.PgpMon[0].CountReset", 1 );
//	setVariable( "Top.PgpMon[0].CountReset", 0 );

	// This resets   Top.BatcherEventBuilder.DataCnt[0]
//	setVariable( "Top.BatcherEventBuilder.CntRst", 1 );
//	setVariable( "Top.BatcherEventBuilder.CntRst", 0 );

//	setVariable( "Top.TimingFrameRx.ClearRxCounters", 1 );
//	setVariable( "Top.TimingFrameRx.ClearRxCounters", 0 );
}

void pgpRogueLib::GetEventBuilderBlowoffPath( unsigned int triggerNum, std::string & retPath )
{
#ifdef SUPPORT_CLINK
	char		varPath[256];
	const char * pszBlowoff		 = "Top.BatcherEventBuilder.Blowoff";
	snprintf( varPath, 256, pszBlowoff, triggerNum );
	retPath	= varPath;
#else  /* not SUPPORT_CLINK */
	retPath = "Top.BatcherEventBuilder.Blowoff";
#endif  /* SUPPORT_CLINK */
}


void pgpRogueLib::GetTriggerMasterEnablePath( unsigned int triggerNum, std::string & retPath )
{
	char		varPath[256];
#ifdef SUPPORT_CLINK
	const char * pszMasterEnable = "Top.TriggerEventManager.TriggerEventBuffer[%u].MasterEnable";
#else  /* not SUPPORT_CLINK */
	const char * pszMasterEnable = "Top.TriggerEventManager.TriggerEventBuffer[%u].MasterEnable";
#endif  /* SUPPORT_CLINK */

	snprintf( varPath, 256, pszMasterEnable, triggerNum );
	retPath	= varPath;
}


void pgpRogueLib::GetEventBuilderSoftRstPath( unsigned int triggerNum, std::string & retPath )
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


int		pgpRogueLib::setTriggerEnable( unsigned int triggerNum, bool fEnable )
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

bool	pgpRogueLib::getTriggerEnable( unsigned int triggerNum )
{
	return false;
}


#include "rogueAddrMap.h"
std::string		strRogueAddrMap( ROGUE_ADDR_MAP );

#if 0
class rogueAddrMap : public rogue::LibraryBase
{
public:
	// static class creator
	static std::shared_ptr<rogueAddrMap> create()
	{
		static std::shared_ptr<rogueAddrMap> ret = std::make_shared<rogueAddrMap>();
		return(ret);
	}

	rogueAddrMap();
};
typedef std::shared_ptr<rogueAddrMap> rogueAddrMapPtr;

rogueAddrMap::rogueAddrMap()
	:	rogue::LibraryBase()
{
#if 1
	printf( "NOT Parsing ROGUE_ADDR_MAP!\n" );
#else
	printf( "rogueAddrMap: Parsing ROGUE_ADDR_MAP\n" );
	parseMemMap( ROGUE_ADDR_MAP ); // From generated rogueAddrMap.h
	printf( "rogueAddrMap: ROGUE_ADDR_MAP parsed successfully\n" );
#endif
}
#endif


///	Constructor
pgpRogueLib::pgpRogueLib(
	unsigned int				board,
	unsigned int				lane	)
:	rogue::LibraryBase(),
	m_board(		board	),
	m_lane(			lane	),
	m_fConnected(	0		),
	m_devName(				),
	m_DrvVersion(			),
	m_LibVersion(			),
	m_pAxiMemMap(			),
	m_pAxiMemMaster(		)
{
	const char		*	functionName	= "pgpRogueLib::pgpRogueLib";

	/*
	 * Check arguments
	 */

	char	acDevName[60];
	sprintf( acDevName, "/dev/datadev_%u", board );
	m_devName = acDevName;

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
			printf("pgpRogueLib: -- Core Axi Version --\n");
			printf("firmwareVersion : %x\n", vsn.firmwareVersion);
			printf("buildString     : %s\n", vsn.buildString); 
			//printf("upTimeCount     : %u\n", vsn.upTimeCount);
			//printf("deviceId        : %x\n", vsn.deviceId);
			//printf("buildString     : %s\n", vsn.buildString);

			// TODO: Need a better mapping of these version strings to PVs
			m_DrvVersion = vsn.firmwareVersion;
			//m_LibVersion = vsn.buildString;
		}
	}
	close( m_fd );
	m_fd = 0;

	//
	// Connect Rogue Library
	//
	//m_pRogueLib = rogue::LibraryBase::create();
	//m_pRogueLib = rogueAddrMap::create();

	//
	// Connect DATACHAN 0 KCU1500 Register Access
	//
	m_pAxiMemMap		= rogue::hardware::axi::AxiMemMap::create( m_devName );
	m_pAxiMemMaster		= ClMemoryMaster::create( );
	m_pAxiMemMaster->setSlave( m_pAxiMemMap );
	const char	*	szMemName = "PCIe_Bar0";
	addMemory( szMemName, m_pAxiMemMap );
	//m_pRogueLib->addMemory( szMemName, m_pAxiMemMap );
	printf("pgpRogueLib: addMemory AxiMemMap interface %s\n", szMemName );

	{
		uint32_t dest = (0x100 * m_lane) + PGP_DATACHAN_REG_ACCESS;
		m_pW8RegChan[m_lane]	= rogue::hardware::axi::AxiStreamDma::create( m_devName, dest, true);

		//
		// Connect DATACHAN 0 WAVE8 Register Access
		//
		m_pSrpW8[m_lane] = rogue::protocols::srp::SrpV3::create();	// Serial Rouge Protocol handler
		// Create bidirectional links between SRP and W8RegChan 
		m_pW8RegChan[m_lane]->addSlave( m_pSrpW8[m_lane] );
		m_pSrpW8[m_lane]->addSlave( m_pW8RegChan[m_lane] );

		const char	*	szMemName = "Unnamed_5";
		addMemory( szMemName, m_pSrpW8[m_lane] );
		//m_pRogueLib->addMemory( szMemName, m_pSrpW8[m_lane] );
		printf("pgpRogueLib: addMemory srpW8 interface %s\n", szMemName );

		// Create W8MemMaster and link it to SRP
		m_pW8MemMaster[m_lane] = rim::Master::create( );
		m_pW8MemMaster[m_lane]->setSlave( m_pSrpW8[m_lane] );
	}
	{
	const mapVarPtr_t &	mapVars		= getVariableList();
	printf( "%s: %zu variables\n", functionName, mapVars.size() );
	sleep(5);
	}
	printf( "Parsing %zu length ROGUE_ADDR_MAP\n", strlen( ROGUE_ADDR_MAP ) );
#if 1
	parseMemMap( strRogueAddrMap ); // From generated rogueAddrMap.h
	printf( "ROGUE_ADDR_MAP parsed successfully\n" );
#else
	m_pRogueLib->parseMemMap( ROGUE_ADDR_MAP );
	printf( "m_pRogueLib: ROGUE_ADDR_MAP parsed successfully\n" );
#endif
	std::cout << std::flush;
	sleep(5);

#ifdef SUPPORT_CLINK
//	if ( doFebFpgaReload )
//		FebFpgaReload();
#endif  /* SUPPORT_CLINK */

	//const mapVarPtr_t &	mapVars		= getVariableList();
	//printf( "%s: %zu variables\n", functionName, mapVars.size() );
	//printf( "m_pRogueLib: %zu variables\n", (m_pRogueLib->getVariableList()).size() );

#if 1
	// Force an initial read of all variables
	printf( "%s: Reading %zu variables\n", functionName, getVariableList().size() );
	try
	{
		readAll();
	}
#else
	// Force an initial read of all variables
	printf( "%s: Reading %zu variables\n", functionName, (m_pRogueLib->getVariableList()).size() );
	try
	{
		m_pRogueLib->readAll();
	}
#endif
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
#if 1
	printf( "%s: Read %zu variables\n", functionName, getVariableList().size() );
#else
	printf( "%s: Read %zu variables\n", functionName, (m_pRogueLib->getVariableList()).size() );
#endif

#ifdef SUPPORT_CLINK
	// Hack: Configure for LCLS-I timing
	ConfigureLclsTimingV1();

	LoadConfigFile( "db/defaults_LCLS-I.txt", 0.003 );

	// Misc python resets, etc
	setVariable( "ClinkDevRoot.ClinkPcie.AxiPcieCore.DmaIbAxisMon.CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.AxiPcieCore.DmaObAxisMon.CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[0].EventBuilder.SoftRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[0].EventBuilder.SoftRst", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[1].EventBuilder.SoftRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[1].EventBuilder.SoftRst", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[2].EventBuilder.SoftRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[2].EventBuilder.SoftRst", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[3].EventBuilder.SoftRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Application.AppLane[3].EventBuilder.SoftRst", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[0].Flush", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[0].Flush", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpTxAxisMon[0].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpRxAxisMon[0].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[1].Flush", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[1].Flush", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpTxAxisMon[1].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpRxAxisMon[1].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[2].Flush", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[2].Flush", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpTxAxisMon[2].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpRxAxisMon[2].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[3].Flush", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[3].Flush", 0 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpTxAxisMon[3].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.PgpRxAxisMon[3].CntRst", 1 );
	setVariable( "ClinkDevRoot.ClinkPcie.Hsio.TimingRx.TimingPhyMonitor.CntRst", 1 );
#endif  /* SUPPORT_CLINK */

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
	m_fConnected = 1;	// Do we need this?
}

/// virtual Destructor
pgpRogueLib::~pgpRogueLib()
{
	close( m_fd );
}


#ifdef SUPPORT_CLINK
/// Configure timing for LCLS-I
void pgpRogueLib::ConfigureLclsTimingV1()
{
//	const char * functionName = "ConfigureLclsTimingV1";
//	const bool		bOne	= 1;
	const bool		bZero	= 0;
	const uint64_t	lOne	= 1L;
	const uint64_t	lZero	= 0L;
	const struct timespec oneSec	= { 1, 0L };
	const struct timespec twoMs		= { 0, 2000000L };

	writeVarPath( "Top.SystemRegs.timingUseMiniTpg",	bZero );
	printf( "Configuring for LCLS-I timing ...\n" );
	writeVarPath( "Top.TimingFrameRx.ModeSelEn",		lZero	);
	writeVarPath( "Top.TimingFrameRx.RxPllReset",		lOne	);
	nanosleep( &oneSec, NULL );

	writeVarPath( "Top.TimingFrameRx.RxPllReset",		lZero	);
	nanosleep( &twoMs, NULL );
	writeVarPath( "Top.TimingFrameRx.ClkSel",			lZero	);
	nanosleep( &twoMs, NULL );
	writeVarPath( "Top.TimingFrameRx.C_RxReset",		lOne	);
	nanosleep( &twoMs, NULL );
	writeVarPath( "Top.TimingFrameRx.C_RxReset",		lZero	);
	nanosleep( &oneSec, NULL );

	WaitForRxLinkUp( "ConfigureLclsTimingV1: Wait 1" );

	// Reset latching RxDown flag
	writeVarPath( "Top.TimingFrameRx.RxDown",		lZero	);

	if ( bUseMiniTpg )
	{
		// TODO: Export bUseMiniTpg as iocsh variable
		writeVarPath( "Top.SystemRegs.timingUseMiniTpg",	bUseMiniTpg );
	}

	WaitForRxLinkUp( "ConfigureLclsTimingV1: Wait 2" );
	//ResetCounters();
	printf( "Configured for LCLS-I timing\n" );
}
#endif  /* SUPPORT_CLINK */

bool pgpRogueLib::LaneReady( size_t iLane )
{
	bool			laneReady	= true;
#ifdef SUPPORT_CLINK
	const char	*	pszVarPathRxRemLinkReady	= "ClinkDevRoot.ClinkPcie.Hsio.PgpMon[%1u].RxRemLinkReady";
	char			laneReadyVarPath[256];
	snprintf( laneReadyVarPath, 256, pszVarPathRxRemLinkReady, iLane );
	readVarPath( laneReadyVarPath, laneReady );
#endif  /* SUPPORT_CLINK */
	return laneReady;
}


/// Wait for RxLinkUp
void pgpRogueLib::WaitForRxLinkUp( const char * pszDiagLabel )
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

/// Load Config file
void pgpRogueLib::LoadConfigFile( const char * pszFilePath, double stepDelay )
{
	const char	*	functionName	= "pgpRogueLib::LoadConfigFile";
	FILE		*	cfgFile			= fopen( pszFilePath, "r" );
	struct timespec delay	= { (long int) floor(stepDelay), (long int) ((stepDelay - floor(stepDelay)) * 1e9) };
	if ( cfgFile == NULL )
	{
		fprintf( stderr, "LoadConfigFile error: Unable to open %s\n", pszFilePath );
		return;
	}
	printf( "%s: Reading values from %s w/ %.4f sec delay/value ...\n", functionName, pszFilePath, stepDelay );

	unsigned int	nValues	= 0;
	try
	{
		int			nScan	= 0;
		double		dValue;
		int64_t		lValue;
		char		varPath[256];

		while( 1 )
		{
			strcpy( varPath, "unParsed" );
			nScan = fscanf( cfgFile, "%s = %lf", varPath, &dValue );
			if ( nScan == EOF )
				break;
			if( nScan != 2 )
			{
				nScan = fscanf( cfgFile, "%s = %ld", varPath, &lValue );
				if( nScan == 2 )
					dValue = static_cast<double>(lValue);
			}
			if( nScan != 2 )
			{
				nScan = fscanf( cfgFile, "%s = 0x%lx", varPath, &lValue );
				if( nScan == 2 )
					dValue = static_cast<double>(lValue);
			}
			if( nScan == 2 )
			{
				setVariable( varPath, dValue, false );
				nanosleep( &delay, NULL );
				nValues++;
			}
			else
			{
				printf( "%s: Error parsing %s\n", functionName, pszFilePath );
			}
		}
	}
	catch ( rogue::GeneralError & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	catch ( std::exception & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}

	fclose( cfgFile );
	printf( "%s: Read %u values from %s\n", functionName, nValues, pszFilePath );
}

template<class R> int pgpRogueLib::readVarPath( const char * pszVarPath, R & valueRet )
{
	const char *	functionName = "pgpRogueLib::readVarPath";
	int				status	= -1;
	std::string		varPath( pszVarPath );
	rogue::interfaces::memory::VariablePtr	pVar;
	//pVar = m_pRogueLib->getVariable( varPath );
	pVar = getVariable( varPath );
	if ( !pVar )
	{
		printf( "%s error: %s not found!\n", functionName, varPath.c_str() );
		return -1;
	}

	try
	{
		pVar->getValue( valueRet );
		status = 0;
	}
	catch ( rogue::GeneralError & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	catch ( std::exception & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	//pVar->setLogLevel( rogue::Logging::Warning );

	if ( DEBUG_PGP_ROGUE_LIB >= 6 )
	{
		std::cout	<< functionName	<< ": " << varPath
					<< ", typeid = "	<< typeid(R).name()
					<< ", modelId = "	<< modelId2String(pVar->modelId()) << pVar->bitTotal()
					<< ", valueRet = "	<< valueRet << std::endl;
	}
	return status;
}

template int pgpRogueLib::readVarPath( const char * pszVarPath, bool		& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, double		& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, int64_t	& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, uint64_t	& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, std::string & valueRet );

template<class R> int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const R & value )
{
	const char *	functionName = "pgpRogueLib::writeVarPath";
	int				status	= -1;
	if ( !pVar )
	{
		printf( "%s error: Invalid VariablePtr!\n", functionName );
		return -1;
	}

	if ( DEBUG_PGP_ROGUE_LIB >= 6 )
	{
		//if ( pVar->modelId() == rim::Bool )
		//	pVar->setLogLevel( rogue::Logging::Debug );
		if ( typeid(value) == typeid(uint64_t) )
			std::cout << functionName << ": " << pVar->path() << " is uint64_t" << std::endl;
		std::cout	<< functionName	<< ": " << pVar->path()
					<< ", typeid = "	<< typeid(R).name()
					<< ", modelId = "	<< modelId2String(pVar->modelId()) << pVar->bitTotal()
					<< ", value = "	<< value << std::endl;
		printf( "%s type is %s, nBits %u, byteSize %u!\n",
				pVar->path().c_str(),
				modelId2String( pVar->modelId() ), pVar->bitTotal(),
				pVar->byteSize() );
	}

	try
	{
		pVar->setValue( value );
		status = 0;
		if ( pVar->mode() != std::string("WO") )
		{
			R	valueRet;
			pVar->getValue( valueRet );
			if ( DEBUG_PGP_ROGUE_LIB >= 3 || value != valueRet )
			{
				std::cout	<< functionName	<< ": " << pVar->path()
							<< ", setValue="	<< value;
				if ( value != valueRet )
				{
					std::cout	<< ", Error getValue="	<< valueRet << std::endl;
					status	= -2;
				}
				else
					std::cout	<< ", getValue="	<< valueRet << std::endl;
			}
		}
	}
	catch ( rogue::GeneralError & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	catch ( std::exception & e )
	{
		printf( "%s error: %s!\n", functionName, e.what() );
	}
	if ( pVar->modelId() == rim::Bool )
		pVar->setLogLevel( rogue::Logging::Info );

	return status;
}

template<class R> int pgpRogueLib::writeVarPath( const char * pszVarPath, const R & value )
{
	const char *	functionName = "pgpRogueLib::writeVarPath";
	std::string		varPath( pszVarPath );
	rogue::interfaces::memory::VariablePtr	pVar;
	//pVar = m_pRogueLib->getVariable( varPath );
	pVar = getVariable( varPath );
	if ( !pVar )
	{
		printf( "%s error: %s not found!\n", functionName, varPath.c_str() );
		return -1;
	}
	return writeVarPath( pVar, value );
}

template int pgpRogueLib::writeVarPath( const char * pszVarPath, const bool		& value );
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const double		& value );
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const int64_t		& value );
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const uint64_t	& value );

template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const bool		& value );
template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const double	& value );
template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const int64_t	& value );
template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const uint64_t	& value );

void pgpRogueLib::dumpVariables( const char * pszFilePath, bool fWritableOnly, bool fForceRead, bool verbose )
{
	const char *	functionName = "pgpRogueLib::dumpVariables";

	std::ofstream	dumpFile;
	dumpFile.open( pszFilePath, ios_base::out );
	if ( ! dumpFile.is_open() )
	{
		printf( "%s Error: Unable to open write access for file:\n%s\n", functionName, pszFilePath );
		return;
	}

#if 0
	if ( ! m_pRogueLib )
	{
		printf( "%s Error: Unable to access rogue lib!\n", functionName );
		return;
	}

	const mapVarPtr_t &	mapVars		= m_pRogueLib->getVariableList();
#else
	const mapVarPtr_t &	mapVars		= getVariableList();
#endif
	if ( mapVars.size() == 0 )
	{
		printf( "%s Error: Rogue VariableList is empty!\n", functionName );
		return;
	}

	size_t	nDumped	= 0;
	printf( "%s: %s has %zu registers\n", functionName, pszFilePath, mapVars.size() );
	//dumpFile << functionName << ": " << mapVars.size() << std::endl;
	for ( mapVarPtr_t::const_iterator vit = mapVars.begin(); vit != mapVars.end(); ++vit )
	{
		rim::VariablePtr	pVar	= vit->second;
		try
		{
			if ( not fWritableOnly or pVar->mode() != std::string("RO") )
			{
				//	pVar->setLogLevel( rogue::Logging::Debug );
				dumpFile << pVar->getDumpValue( fForceRead );
				//	pVar->setLogLevel( rogue::Logging::Warning );
				nDumped++;
			}
		}
		catch ( rogue::GeneralError & e )
		{
			// pVar->setLogLevel( rogue::Logging::Warning );
			printf( "%s rogue error: %s!\n", functionName, e.what() );
		}
		catch ( exception & e )
		{
			// pVar->setLogLevel( rogue::Logging::Warning );
			printf( "%s error: %s!\n", functionName, e.what() );
		}
		catch ( ... )
		{
			// pVar->setLogLevel( rogue::Logging::Warning );
			printf( "%s unknown error!\n", functionName );
		}
	}

	printf( "%s: Dumped %zu of %zu registers...\n", functionName, nDumped, mapVars.size() );
	dumpFile.close();
}

void pgpRogueLib::setVariable( const char * pszVarPath, double value, bool verbose )
{
	uint64_t	u64Value;
	int64_t		i64Value;
	bool		bValue;
	float		fValue;
	double		dValue;
	std::string		varPath( pszVarPath );
	rogue::interfaces::memory::VariablePtr	pVar;
	//pVar = m_pRogueLib->getVariable( varPath );
	pVar = getVariable( varPath );
	if ( pVar )
	{
		if ( verbose )
			printf( "%s%u: ", modelId2String( pVar->modelId() ), pVar->bitTotal() );
		switch ( pVar->modelId() )
		{
		case rim::Bytes:
		case rim::Custom:
		case rim::Fixed:
		case rim::PyFunc:
		case rim::String:
		default:
			printf( "pgpRogueLib::setVariable error: Type %s%u not supported.", modelId2String( pVar->modelId() ), pVar->bitTotal() );
			break;
		case rim::UInt:
			u64Value	= static_cast<uint64_t>(value);
			writeVarPath( pszVarPath, u64Value );
			break;
		case rim::Int:
			i64Value	= static_cast<int64_t>(value);
			writeVarPath( pszVarPath, i64Value );
			break;
		case rim::Bool:
			bValue	= static_cast<bool>(value);
			writeVarPath( pszVarPath, bValue );
			break;
		case rim::Float:
			fValue	= static_cast<float>(value);
			writeVarPath( pszVarPath, fValue );
			break;
		case rim::Double:
			dValue	= static_cast<double>(value);
			writeVarPath( pszVarPath, dValue );
			break;
		}
	}
	else
	{
		printf( "pgpRogueLib error: %s not found!\n", varPath.c_str() );
	}
}

void pgpRogueLib::showVariable( const char * pszVarPath, bool verbose )
{
	std::string		varPath( pszVarPath );
	rogue::interfaces::memory::VariablePtr	pVar;
	//pVar = m_pRogueLib->getVariable( varPath );
	pVar = getVariable( varPath );
	if ( !pVar )
	{
		printf( "pgpRogueLib error: %s not found!\n", varPath.c_str() );
		return;
	}

	try
	{
		if ( verbose )
			printf( "%s%u: ", modelId2String( pVar->modelId() ), pVar->bitTotal() );
		switch ( pVar->modelId() )
		{
		default:
			break;
		case rim::PyFunc:
			break;
		case rim::Bytes:
			break;
		case rim::UInt:
			printf( "%s: %lu\n", varPath.c_str(), pVar->getUInt() );
			break;
		case rim::Int:
			printf( "%s: %li\n", varPath.c_str(), pVar->getInt() );
			break;
		case rim::Bool:
			printf( "%s: %s\n", varPath.c_str(), ( pVar->getBool() ? "True" : "False" ) );
			break;
		case rim::String:
			printf( "%s: '%s'\n", varPath.c_str(), pVar->getString().c_str() );
			break;
		case rim::Float:
			break;
		case rim::Double:
			printf( "%s: %f\n", varPath.c_str(), pVar->getDouble() );
			break;
		case rim::Fixed:
			break;
		case rim::Custom:
			break;
		}
	}
	catch ( rogue::GeneralError & e )
	{
		printf( "ShowPgpVariable error: %s!\n", e.what() );
	}
}

void pgpRogueLib::showVariableList( bool verbose )
{
	const char *	functionName = "pgpRogueLib::showVariableList";
#if 0
	if ( ! m_pRogueLib )
	{
		printf( "%s Error: Unable to access rogue lib!\n", functionName );
		return;
	}

	const mapVarPtr_t &	mapVars		= m_pRogueLib->getVariableList();
#else
	const mapVarPtr_t &	mapVars		= getVariableList();
#endif
	if ( mapVars.size() == 0 )
	{
		printf( "%s Error: Rogue VariableList is empty!\n", functionName );
		return;
	}

	printf( "%s: %zu variables\n", functionName, mapVars.size() );
	for ( mapVarPtr_t::const_iterator vit = mapVars.begin(); vit != mapVars.end(); ++vit )
	{
		rogue::interfaces::memory::VariablePtr	pVar	= vit->second;
		if ( ! pVar )
		{
			printf( "%s Error: Variable %s not found!\n", functionName, vit->first.c_str() );
			continue;
		}

#if 0
		showVariable( vit->first, verbose );
#else
		std::cout	<< pVar->path() << " Type " << pVar->modelId() << pVar->bitTotal() << std::endl;
#endif
	}
}

void pgpRogueLib::connect( )
{
}

void pgpRogueLib::disconnect( )
{
	printf( "pgpRogueLib::disconnect\n" );
	if ( m_fd > 0 )
	{
		close( m_fd );
		m_fd = 0;
	}
	m_pAxiMemMaster.reset();
	//rmMemory( m_pAxiMemMap );
	//m_pRogueLib->rmMemory( m_pAxiMemMap );
	m_pAxiMemMap.reset();
}

