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
//	pgpRogueLib.h
//
//	Header file for pgpRogueLib class.
//	It provides a templated interface to SLAC Generic PGP Hardware registers
//	via the Rogue LibraryBase C++ API
//
#ifndef	pgpRogueLib_H
#define	pgpRogueLib_H

#include <memory>
#include <string>
#include <string.h>

// rogue headers 
#include <rogue/Helpers.h>
#include <rogue/LibraryBase.h>
#include <rogue/hardware/axi/AxiMemMap.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/interfaces/memory/Constants.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Master.h>
#include <rogue/protocols/srp/SrpV3.h>

// rogueRegister headers
#include "ClMemoryMaster.h"

#define PGP_DATACHAN_REG_ACCESS		0
#define PGP_DATACHAN_FRAME_ACCESS	1

/*	Diagnostic variables	*/
extern int				DEBUG_PGP_ROGUE_LIB;

class rogueAddrMap;
typedef std::shared_ptr<rogueAddrMap> rogueAddrMapPtr;


///	pgpRogueLib class
class pgpRogueLib :	public rogue::LibraryBase
{
public:		//	Public member functions
	// Create a static class creator to return our custom class wrapped with a shared pointer
	static std::shared_ptr<pgpRogueLib> create( unsigned int board ) {
		static std::shared_ptr<pgpRogueLib> ret = std::make_shared<pgpRogueLib>( board );

		return(ret);
	}

	///	Constructor
	pgpRogueLib( unsigned int board );

	/// Destructor
	virtual ~pgpRogueLib();

	void connect( );
	void disconnect( );

	/// dumpVariables() allows dumping the value of rogue variables to a file
	void dumpVariables( const char * pszFilePath, bool fWriteOnly, bool fForceRead, bool verbose );

	// Functions to allow setting or showing the value of rogue variables
	void setVariable(  const std::string & rootPath, const char * pszVarPath, double value );
	void setVariable(  const char * pszVarPath, double value );
	void showVariable( const char * pszVarPath, bool verbose );
	void showVariableList( bool verbose );

	rogue::interfaces::memory::VariablePtr	FindVar( const std::string & rootPath, const char * pFmt, ... ) __attribute__((format(__printf__,3,4)));
	rogue::interfaces::memory::VariablePtr	FindVar( const char * pFmt, ... ) __attribute__((format(__printf__,2,3)));
	rogue::interfaces::memory::VariablePtr	_VFindVar( const std::string & rootPath, const char * pFmt, va_list argList );

	///	Get Device Name
	const std::string	&	GetDevName( ) const
	{
		return m_devName;
	}

	///	Get Driver Version
	const std::string	&	GetDrvVersion( ) const
	{
		return m_DrvVersion;
	}

	///	Get Library Version
	const std::string	&	GetLibVersion( ) const
	{
		return m_LibVersion;
	}

	/// Load Config file
	void LoadConfigFile( const char * pszFilePath, double stepDelay );

	void ResetCounters();

#if 0

	int AdcCalibration();

	/// Configure timing for LCLS-I
	void ConfigureLclsTimingV1();

	void GetEventBuilderBlowoffPath( unsigned int triggerNum, std::string & retPath );
	void GetEventBuilderSoftRstPath( unsigned int triggerNum, std::string & retPath );
	void GetTriggerMasterEnablePath( unsigned int triggerNum, std::string & retPath );

	void WaitForRxLinkUp( const char * pszDiagLabel );

	int		setTriggerEnable( unsigned int triggerNum, bool fEnable );
	bool	getTriggerEnable( unsigned int triggerNum );

#endif
	template<class R> int readVarPath(	const char * pVarPath, R & valueRet );
	template<class R> int writeVarPath(	const char * pVarPath, const R & value );
	template<class R> int writeVarPath( rogue::interfaces::memory::VariablePtr pVar, const R & value );

private:
	//	Private member variables
	int					m_fd;
	unsigned int		m_board;
	bool				m_fConnected;
	std::string			m_devName;
	std::string			m_DrvVersion;	// Driver Version
	std::string			m_LibVersion;	// Library Version

};

// Shared pointer alias
typedef std::shared_ptr<pgpRogueLib> pgpRogueLibPtr;

#endif	//	pgpRogueLib_H
