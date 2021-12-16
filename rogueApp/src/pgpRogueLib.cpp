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
#include <typeinfo>
#include <unistd.h>


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
#if 0
	setVariable( "Top.PgpMon[0].Ctrl.CountReset", 1 );
	setVariable( "Top.PgpMon[0].Ctrl.CountReset", 0 );

	// This resets   Top.BatcherEventBuilder.DataCnt[0]
	setVariable( "Top.BatcherEventBuilder.CntRst", 1 );
	setVariable( "Top.BatcherEventBuilder.CntRst", 0 );

	setVariable( "Top.TimingFrameRx.ClearRxCounters", 1 );
	setVariable( "Top.TimingFrameRx.ClearRxCounters", 0 );
#endif
}

#if 0
void pgpRogueLib::GetEventBuilderBlowoffPath( unsigned int triggerNum, std::string & retPath )
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


void pgpRogueLib::GetTriggerMasterEnablePath( unsigned int triggerNum, std::string & retPath )
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

// TODO: Make different devices be subclasses of pgpRogueLib
#include "wave8AddrMap.h"
std::string		strWave8AddrMap( ROGUE_ADDR_MAP );
#endif


///	Constructor
pgpRogueLib::pgpRogueLib(
	unsigned int		board )
//	const char	*		pszAddrMapFileName
:	rogue::LibraryBase(),
	m_board(		board	),
	m_fConnected(	0		),
	m_devName(				),
	m_DrvVersion(			),
	m_LibVersion(			)
#if 0
	,m_pAxiMemMap(			),
	m_pAxiMemMaster(		)
#endif
{
//	const char		*	functionName	= "pgpRogueLib::pgpRogueLib";

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
	m_fd = -1;
	m_fConnected = 1;	// Do we need this?

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
	printf("pgpRogueLib: addMemory AxiMemMap interface %s\n", szPcieMemName );

	m_pW8RegChan	= rogue::hardware::axi::AxiStreamDma::create( m_devName, PGP_DATACHAN_REG_ACCESS, true);

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
	printf("pgpRogueLib: addMemory srpW8 interface %s\n", szMemName );

	// Create W8MemMaster and link it to SRP
	m_pW8MemMaster = rim::Master::create( );
	m_pW8MemMaster->setSlave( m_pSrpW8 );

	const mapVarPtr_t &	mapVars		= getVariableList();
	printf( "%s: %zu variables\n", functionName, mapVars.size() );

	printf( "Parsing %zu length ROGUE_ADDR_MAP\n", strlen( ROGUE_ADDR_MAP ) );
//	parseAddrMapFile( pszAddrMapFileName );
	parseMemMap( strWave8AddrMap ); // From generated wave8AddrMap.h
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
#endif
}

/// virtual Destructor
pgpRogueLib::~pgpRogueLib()
{
	if ( m_fd > 0 )
	{
		close( m_fd );
		m_fd = -1;
	}
}


#if 0


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
#endif

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
			nScan = fscanf( cfgFile, "%s", varPath );
			if ( nScan == EOF )
				break;
			if ( varPath[0] == '#' )
			{
				// Ignore comment lines
				size_t		bufSize	= 1000;
				char	*	commentBuf	= (char *) malloc(bufSize);
				getline( &commentBuf, &bufSize, cfgFile );
				if ( DEBUG_PGP_ROGUE_LIB >= 3 )
					printf( "comment: %s\n", commentBuf );
				free( commentBuf );
				continue;
			}
			nScan = fscanf( cfgFile, " = %lf", &dValue );
			if( nScan != 1 )
			{
				nScan = fscanf( cfgFile, " = %ld", &lValue );
				if( nScan == 1 )
					dValue = static_cast<double>(lValue);
			}
			if( nScan != 1 )
			{
				nScan = fscanf( cfgFile, " = 0x%lx", &lValue );
				if( nScan == 2 )
					dValue = static_cast<double>(lValue);
			}
			if( nScan == 1 )
			{
				setVariable( varPath, dValue );
				nanosleep( &delay, NULL );
				nValues++;
			}
			else
			{
				size_t		bufSize	= 1000;
				char	*	commentBuf	= (char *) malloc(bufSize);
				getline( &commentBuf, &bufSize, cfgFile );
				printf( "%s: Error parsing %s\n", functionName, pszFilePath );
				printf( "at: %s\n", commentBuf );
				free( commentBuf );
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

rim::VariablePtr	pgpRogueLib::FindVar(
	const string & rootPath,
	const char * format, ... )
{
	va_list		argList;
	rim::VariablePtr	pVar;
	va_start( argList, format );
	pVar = _VFindVar( rootPath, format, argList );
	va_end (argList);

	return( pVar );
}

rim::VariablePtr	pgpRogueLib::FindVar(
	const char	*	format, ... )
{
	string	rootPath( "" );
	va_list		argList;
	rim::VariablePtr	pVar;
	va_start( argList, format );
	pVar = _VFindVar( rootPath, format, argList );
	va_end (argList);

	return( pVar );
}

rim::VariablePtr	pgpRogueLib::_VFindVar(
	const string	&	rootPath,
	const char			*	format,
	va_list					argList )
{
	char	varPath[256];
	(void) vsnprintf( varPath, 256, format, argList );
	string	fullVarPath( rootPath );
	fullVarPath.append( varPath );
	rim::VariablePtr pVar = getVariable( fullVarPath );
	if ( !pVar )
		printf( "pgpRogueLib::FindVar: Error finding %s\n", fullVarPath.c_str() );
	return( pVar );
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
		// Suppress errors for SFP Identifier as it's used to enable other SFP registers
		// TODO: print the first error for each varPath and suppress duplicate errors after that.
		std::string	idStr( ".Identifier" );
		size_t		idPos = pVar->name().rfind( idStr );
		if ( idPos == std::string::npos )
			// Variable name doesn't contain ".Identifier"
			printf( "%s %s rogue error: %s!\n", functionName, varPath.c_str(), e.what() );
		else if ( pVar->name().find( ".Sfp" ) == std::string::npos )
			// Variable name doesn't contain ".Sfp"
			printf( "%s %s rogue error from %s: %s!\n", functionName, pVar->name().c_str(), varPath.c_str(), e.what() );
		else if ( pVar->name().compare( idPos, pVar->name().length(), idStr ) == std::string::npos )
			// Sfp Variable name doesn't end with ".Identifier"
			printf( "%s %s rogue error from SFP %s: %s!\n", functionName, pVar->name().c_str(), varPath.c_str(), e.what() );
	}
	catch ( std::exception & e )
	{
		printf( "%s %s error: %s!\n", functionName, varPath.c_str(), e.what() );
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
template int pgpRogueLib::readVarPath( const char * pszVarPath, int64_t		& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, uint64_t	& valueRet );
template int pgpRogueLib::readVarPath( const char * pszVarPath, std::string	& valueRet );

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
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const double	& value );
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const int64_t	& value );
template int pgpRogueLib::writeVarPath( const char * pszVarPath, const uint64_t	& value );

template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const bool		& value );
template int pgpRogueLib::writeVarPath( rim::VariablePtr pVar, const double		& value );
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
		if ( !pVar )
		{
			printf( "%s: NULL pVar!\n", functionName );
			continue;
		}
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

// TODO: Add toggleVariable function, set to 1 for N sec
void pgpRogueLib::setVariable( const char * pszVarPath, double value )
{
	std::string		rootPath( "" );
	setVariable( rootPath, pszVarPath, value );
}

void pgpRogueLib::setVariable( const std::string & rootPath, const char * pszVarPath, double value )
{
	uint64_t	u64Value;
	int64_t		i64Value;
	bool		bValue;
	float		fValue;
	double		dValue;
	ostringstream	varPath;
	varPath << rootPath << string(pszVarPath);
	rogue::interfaces::memory::VariablePtr	pVar;
	//pVar = m_pRogueLib->getVariable( varPath );
	pVar = getVariable( varPath.str() );
	if ( pVar )
	{
		// Removed verbose printf option here
		// Use DEBUG_PGP_ROGUE=3 for writeVarPath diagnostics
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
			writeVarPath( varPath.str().c_str(), u64Value );
			break;
		case rim::Int:
			i64Value	= static_cast<int64_t>(value);
			writeVarPath( varPath.str().c_str(), i64Value );
			break;
		case rim::Bool:
			bValue	= static_cast<bool>(value);
			writeVarPath( varPath.str().c_str(), bValue );
			break;
		case rim::Float:
			fValue	= static_cast<float>(value);
			writeVarPath( varPath.str().c_str(), fValue );
			break;
		case rim::Double:
			dValue	= static_cast<double>(value);
			writeVarPath( varPath.str().c_str(), dValue );
			break;
		}
	}
	else
	{
		printf( "pgpRogueLib error: %s not found!\n", varPath.str().c_str() );
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
		m_fd = -1;
	}
#if 0
	m_pAxiMemMaster.reset();
	m_pAxiMemMap.reset();
#endif
}

