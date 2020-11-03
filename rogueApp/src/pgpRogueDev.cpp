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

int		DEBUG_PGP_ROGUE_DEV	= 2;


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
	m_board(		board	),
	m_lane(			lane	),
	m_fConnected(	0		),
	m_devName(				),
	m_devLock(				),
	m_pDataChan(			),
	m_pDataStream(			)
{
//	const char		*	functionName	= "pgpRogueDev::pgpRogueDev";

	// Create mutexes
    m_devLock	= epicsMutexMustCreate();

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
	m_pDataChan	= rogue::hardware::axi::AxiStreamDma::create( m_devName, dest, true);
	//m_pFebFrameChan	= rogue::hardware::axi::AxiStreamDma::create( m_devName, dest, true);

	//
	// Connect DATACHAN 1 Frame Stream
	m_pDataStream	= ImageStream::create(this);
	m_pDataChan->addSlave( m_pDataStream );
	//rogueStreamConnect( m_pDataChan, m_pDataStream );
	double	rateDropPeriod		= 1.0;	// seconds?
	bool	rateDropUsePeriod	= true;
	m_pRateDrop	= ris::RateDrop::create( rateDropUsePeriod, rateDropPeriod );
	m_pDataChan->addSlave( m_pRateDrop );

	// 	ris::FifoPtr create(uint32_t maxDepth, uint32_t trimSize, bool noCopy)
	m_pDataFifo	= ris::Fifo::create( 0, 0, false );
	m_pRateDrop->addSlave( m_pDataFifo );
	
	// unbatchers
	//m_pEpicsUnbatcher	= rogue::protocols::batcher::SplitterV1::create(this);
	//m_pDataFifo->addSlave( m_pEpicsUnbatcher );
	//m_pUnbatcher	= rogue::protocols::batcher::SplitterV1::create(this);
	//m_pDataChan->addSlave( m_pUnbatcher );

	m_fConnected = 1;	// Do we need this?
	//StartRun( m_fd );
}

/// virtual Destructor
pgpRogueDev::~pgpRogueDev()
{
	close( m_fd );
}

/// Configure timing for LCLS-I






void pgpRogueDev::connect( )
{
}

void pgpRogueDev::disconnect( )
{
}

void pgpRogueDev::ProcessImage(
	ImageCbInfo		* pImageInfo )
{
	const char		*	functionName	= "pgpRogueDev::ProcessImage";
	if ( DEBUG_PGP_ROGUE_DEV >= 5 ) printf( "%s\n", functionName );
	//epicsTimeStamp		tsImage	= pImageInfo->m_tsImage;

	if  ( m_CallbackClientFunc != NULL )
		(*m_CallbackClientFunc)( m_pCallbackClient, pImageInfo );

	return;
}

void pgpRogueDev::cancelImageCallbacks( )
{
	m_pCallbackClient		= NULL;
	m_CallbackClientFunc	= NULL;
}

void pgpRogueDev::requestImageCallbacks( void * pClientContext, ImageCallback callbackFunction )
{
	m_pCallbackClient		= pClientContext;
	m_CallbackClientFunc	= callbackFunction;
}
