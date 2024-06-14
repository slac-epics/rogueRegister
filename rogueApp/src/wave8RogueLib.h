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
//	wave8RogueLib.h
//
//	Header file for wave8RogueLib class.
//	It provides a templated interface to SLAC Generic PGP Hardware registers
//	via the Rogue LibraryBase C++ API
//
#ifndef	wave8RogueLib_H
#define	wave8RogueLib_H

#include <memory>
#include <string>
#include <string.h>

// rogue headers 
#include <rogue/Helpers.h>
#include <rogue/hardware/axi/AxiMemMap.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/interfaces/memory/Constants.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Master.h>
#include <rogue/protocols/srp/SrpV3.h>

// rogueRegister headers
#include "LibraryBase.h"
#include "pgpRogueLib.h"
//#include "ClMemoryMaster.h"


///	wave8RogueLib class
class wave8RogueLib :	public	pgpRogueLib
{
public:		//	Public member functions
	// Create a static class creator to return our custom class wrapped with a shared pointer
	static std::shared_ptr<wave8RogueLib> create( unsigned int board, unsigned int lane, const char * pszAddrMapFileName )
	{
		static std::shared_ptr<wave8RogueLib> ret = std::make_shared<wave8RogueLib>( board, lane, pszAddrMapFileName );

		return(ret);
	}

	///	Constructor
	wave8RogueLib(	unsigned int	board,
					unsigned int	lane,
					const char	*	pszAddrMapFileName  );

	/// Destructor
	virtual ~wave8RogueLib();

	void connect( );
	void disconnect( );

	int AdcCalibration();
	void parseAddrMapFile( const char * pszAddrMapFileName );

	/// Configure timing for LCLS-I
	void ConfigureLclsTimingV1();

	void GetEventBuilderBlowoffPath( unsigned int triggerNum, std::string & retPath );
	void GetEventBuilderSoftRstPath( unsigned int triggerNum, std::string & retPath );
	void GetTriggerMasterEnablePath( unsigned int triggerNum, std::string & retPath );

	void ResetCounters();

	void WaitForRxLinkUp( const char * pszDiagLabel );

	int		setTriggerEnable( unsigned int triggerNum, bool fEnable );
	bool	getTriggerEnable( unsigned int triggerNum );

private:
	//	Private member variables
	unsigned int		m_lane;

	///
	// Firmware Lane assignments:
	// Lane 0: First wave8
	// Lane 1: 2nd wave8,
	// Lane 2: 3rd wave8
	// Lane 3: 4th wave8
	// ...
	// Lane 7: 8th wave8
	//
	// PGP channel mapping
	// PGP[lane].VC[0] = SRPv3 (register access)
	// PGP[lane].VC[1] = wave8 data (streaming data)
	// PGP[lane].VC[2] = PRBS stream (?)
	// PGP[lane].VC[3] = Unused
	//
	// DMA channel mapping
	// DMA[lane].DEST[0] = SRPv3
	// DMA[lane].DEST[1] = Event Builder Batcher (super-frame)
	// DMA[lane].DEST[1].DEST[0] = XPM Trigger Message (sub-frame)
	// DMA[lane].DEST[1].DEST[1] = XPM Transition Message (sub-frame)
	// DMA[lane].DEST[1].DEST[2] = Data? (sub-frame)
	// DMA[lane].DEST[2] = Data?
	// DMA[lane].DEST[255:3] = Unused
	///

	rogue::hardware::axi::AxiStreamDmaPtr		m_pW8RegChan;
	rogue::interfaces::memory::MasterPtr		m_pW8MemMaster;
	rogue::protocols::srp::SrpV3Ptr				m_pSrpW8;
};

// Shared pointer alias
typedef std::shared_ptr<wave8RogueLib> wave8RogueLibPtr;

#endif	//	wave8RogueLib_H
