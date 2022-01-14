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
//	pgpRogueDev.h
//
//	Header file for pgpRogueDev class.
//	It provides a device class to encapsulate
//	register I/O via the SLAC Rogue API
//
#ifndef	pgpRogueDev_H
#define	pgpRogueDev_H

#include <memory>
#include <string>
#include <string.h>
#include <epicsMutex.h>
#include <epicsTime.h>
#include <dbScan.h>
#include <devSup.h>
#include <waveformRecord.h>
#include "pgpRogueLib.h"
#include "wave8RogueLib.h"
#include "memoryBuffer.h"

// rogue headers 
#include <rogue/hardware/axi/AxiMemMap.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/interfaces/memory/Constants.h>
#include <rogue/interfaces/stream/Fifo.h>
//#include <rogue/interfaces/stream/RateDrop.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Master.h>
//#include <rogue/protocols/batcher/Data.h>
#include <rogue/protocols/batcher/SplitterV1.h>

// rogueRegister headers
#include "DataStream.h"

#define PGP_DATACHAN_REG_ACCESS		0
#define PGP_DATACHAN_FRAME_ACCESS	1
#define PGP_NUM_SIGNALS				8
#define N_PGP_LANES					8


typedef int (* DataCallback)( void * pClientContext, DataCbInfo * pCbInfo );

struct _rogue_info;
typedef struct _rogue_info		rogue_info_t;


///	pgpRogueDev class
class pgpRogueDev
{
public:		//	Public member functions
	// Create a static class creator to return our custom class wrapped with a shared pointer
	static std::shared_ptr<pgpRogueDev> create( unsigned int board, unsigned int lane, const char * szAddrMapPath, const char * szPgpReg ) {
		static std::shared_ptr<pgpRogueDev> ret = std::make_shared<pgpRogueDev>( board, lane, szAddrMapPath, szPgpReg );

		return(ret);
	}

	///	Constructor
	pgpRogueDev(	unsigned int				board,
					unsigned int				channel,
					const char	*				szAddrMapPath,
					const char	*				szPgpReg );

	/// Destructor
	virtual ~pgpRogueDev();

	void connect( );
	void disconnect( );

    void	report(	FILE	*	fp,	int	details	);

	/// Registered with epicsAtExit() for clean disconnect
	static void ExitHook( void * pThis );
 
 	/// Shutdown driver
	void Shutdown( );

	///	Get Device Name
	const std::string	&	GetDevName( ) const
	{
		return m_devName;
	}

	///	Get Driver Version
	const std::string	&	GetDrvVersion( ) const
	{
		if ( m_pRogueLib )
			return m_pRogueLib->GetDrvVersion();
		return m_DrvVersion;
	}

	///	Get Library Version
	const std::string	&	GetLibVersion( ) const
	{
		if ( m_pRogueLib )
			return m_pRogueLib->GetLibVersion();
		return m_LibVersion;
	}

	void ProcessData(	DataCbInfo				*	pCbInfo,
						rogue::interfaces::stream::FramePtr pDataFrame );

	/// Fetch data for the specified signal
	/// Returns number of bytes added to buffer.  -1 on error
	//int	GetData( size_t iSignal, void * pBuffer, size_t sBuffer );

	long update_integrals( epicsTimeStamp tcUpdate, rogue::interfaces::stream::FramePtr	pDataFrame );

	void ResetCounters();

	///	Dump Rogue PGP variables
	int	DumpPgpVars( const char * pszFilePath, bool fWriteOnly, bool fForceRead );

	///	Show Rogue info on stdout
	int	ShowReport( int level );

	///	Set Rogue PGP variable
	int	SetPgpVariable( const char * pszVarPath, double value );

	///	Show Rogue PGP variable on stdout
	int	ShowPgpVariable( const char * pszVarPath, int level );

	///	Load PGP config file
	int	pgpLoadConfig( const char * pszFilename, double stepDelay );

	void cancelDataCallbacks( );

	void requestDataCallbacks(	void			*	pCallbackClient,
								DataCallback		CallbackClientFunc );

	int		setTriggerEnable( unsigned int triggerNum, bool fEnable );

	rogue_info_t *	GetRawDataRogueInfo( size_t iSig ) const
	{
		if ( iSig < PGP_NUM_SIGNALS )
			return m_pRawDataRogueInfo[iSig];
		return NULL;
	}

	void SetRawDataRogueInfo( size_t iSig, rogue_info_t * pRogueInfo )
	{
		if ( iSig < PGP_NUM_SIGNALS )
			m_pRawDataRogueInfo[iSig] = pRogueInfo;
		return;
	}

	void SetIntegralRogueInfo( size_t iSig, rogue_info_t * pRogueInfo )
	{
		if ( iSig < PGP_NUM_SIGNALS )
			m_pIntegralRogueInfo[iSig] = pRogueInfo;
		return;
	}

	/// Return shared_ptr to pgpRogueLib device
	pgpRogueLibPtr	GetRogueLib( ) const
	{
		return m_pRogueLib;
	}
	
	/// Return shared_ptr to wave8RogueLib device
	wave8RogueLibPtr	GetWave8RogueLib( ) const
	{
		return m_pRogueLib;
	}

	static std::shared_ptr<pgpRogueDev>	RogueFindByBoard( unsigned int board );

	static	int	ShowAllRogueDev( int level );

protected:	//	Protected member variables
	bool			m_fExitApp;			// Set true to shutdown ioc

private:
	wave8RogueLibPtr 	m_pRogueLib;			// shared_ptr to pgpRogueLib device

	//	Private member variables
	int					m_fd;
	unsigned int		m_board;
	unsigned int		m_lane;
	bool				m_fConnected;
	std::string			m_devName;
	std::string			m_DrvVersion;	// Driver Version
	std::string			m_LibVersion;	// Library Version
	epicsMutexId		m_devLock;
	rogue_info_t	 *	m_pRawDataRogueInfo[PGP_NUM_SIGNALS];
	rogue_info_t	 *	m_pIntegralRogueInfo[PGP_NUM_SIGNALS];
	epicsTimeStamp		m_tsFrame;		// Timestamp from latest frame

	///	Wave8 Data Stream
	rogue::hardware::axi::AxiStreamDmaPtr		m_pDataChan;
	DataStreamPtr								m_pDataStream;
	rogue::interfaces::stream::FifoPtr			m_pDataFifo;
//	rogue::interfaces::stream::RateDropPtr		m_pRateDrop;
	rogue::protocols::batcher::SplitterV1Ptr	m_pUnbatcher;
	DataStreamPtr								m_pEpicsDataStream;
	rogue::protocols::batcher::SplitterV1Ptr	m_pEpicsUnbatcher;

	void									*	m_pCallbackClient;
	DataCallback								m_CallbackClientFunc;
};

// Shared pointer alias
typedef std::shared_ptr<pgpRogueDev> pgpRogueDevPtr;


struct _rogue_info
{
	std::string			m_varPath;
	pgpRogueLibPtr		m_pRogueLib;
	pgpRogueDevPtr		m_pRogueDev;
	struct dbCommon	*	m_pRecCommon;
	bool				m_fSignedValue;
	uint32_t			m_modelId;
	uint32_t			m_numBits;
	size_t				m_signal;
	size_t				m_newDataCount;
	IOSCANPVT			m_scanIo;
};


#endif	//	pgpRogueDev_H
