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
//	pgpRogueDev.h
//
//	Header file for pgpRogueDev class.
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

// rogue headers 
#include <rogue/hardware/axi/AxiMemMap.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/interfaces/memory/Constants.h>
#include <rogue/interfaces/stream/Fifo.h>
#include <rogue/interfaces/stream/RateDrop.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Master.h>

// ADPgpCamlink headers
#include "ImageStream.h"

#define PGP_DATACHAN_REG_ACCESS		0
#define PGP_DATACHAN_FRAME_ACCESS	1

typedef int (* ImageCallback)( void * pClientContext, ImageCbInfo * pCbInfo );


///	pgpRogueDev class
class pgpRogueDev
{
public:		//	Public member functions
	// Create a static class creator to return our custom class wrapped with a shared pointer
	static std::shared_ptr<pgpRogueDev> create( unsigned int board, unsigned int lane ) {
		static std::shared_ptr<pgpRogueDev> ret = std::make_shared<pgpRogueDev>( board, lane );

		return(ret);
	}

	///	Constructor
	pgpRogueDev(	unsigned int				board,
					unsigned int				channel	);

	/// Destructor
	virtual ~pgpRogueDev();

	void connect( );
	void disconnect( );

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

	void ProcessImage(	ImageCbInfo				*	pCbInfo );

	void ResetCounters();

	void cancelImageCallbacks( );

	void requestImageCallbacks(	void			*	pCallbackClient,
								ImageCallback		CallbackClientFunc );

	int		setTriggerEnable( unsigned int triggerNum, bool fEnable );

private:
	//	Private member variables
	unsigned int		m_fd;
	unsigned int		m_board;
	unsigned int		m_lane;
	bool				m_fConnected;
	std::string			m_devName;
	std::string			m_DrvVersion;	// Driver Version
	std::string			m_LibVersion;	// Library Version
	epicsMutexId		m_devLock;

	///
	// Firmware Lane assignments:
	// Lane 0: First camera
	// Lane 1: 2nd camera,
	// Lane 2: 3rd camera
	// Lane 3: 4th camera
	//
	// PGP channel mapping
	// PGP[lane].VC[0] = SRPv3 (register access)
	// PGP[lane].VC[1] = Camera Image (streaming data)
	// PGP[lane].VC[2] = Camera UART (serial I/O)
	// PGP[lane].VC[3] = Unused
	//
	// DMA channel mapping
	// DMA[lane].DEST[0] = SRPv3
	// DMA[lane].DEST[1] = Event Builder Batcher (super-frame)
	// DMA[lane].DEST[1].DEST[0] = XPM Trigger Message (sub-frame)
	// DMA[lane].DEST[1].DEST[1] = XPM Transition Message (sub-frame)
	// DMA[lane].DEST[1].DEST[2] = Camera Image (sub-frame)
	// DMA[lane].DEST[2] = Camera UART
	// DMA[lane].DEST[255:3] = Unused

	///	Wave8 Data Stream
	rogue::hardware::axi::AxiStreamDmaPtr		m_pDataChan;
	ImageStreamPtr								m_pDataStream;
	rogue::interfaces::stream::FifoPtr			m_pDataFifo;
	rogue::interfaces::stream::RateDropPtr		m_pRateDrop;

	void									*	m_pCallbackClient;
	ImageCallback								m_CallbackClientFunc;
};

// Shared pointer alias
typedef std::shared_ptr<pgpRogueDev> pgpRogueDevPtr;

#endif	//	pgpRogueDev_H
