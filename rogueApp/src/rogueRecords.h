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
//	rogueRecords.h
//
//	Header file for rogueRecords class.
//	It provides the EPICS record interface to a pgpRogueLib device.
//
#ifndef DEV_ROGUE_H
#define DEV_ROGUE_H

#include <dbScan.h>
#include <link.h>
#include "pgpRogueDev.h"
#include "pgpRogueLib.h"

template<class R>		   int		 rogue_init_record(	R * record, DBLINK link	);
//template<class R, class EV, class RV> int rogue_read_record( R * record, EV & epicsVal, RV &rogueVal );
template<class R, class V> int		 rogue_read_record(  R * record, V & valueRet );
template<class R, class V> int		 rogue_write_record(	R * record, const V & value );
//template<class R>		   int		 rogue_init_record_specialized(	R * record	);
//template<class R>		   int		 rogue_read_record_specialized(	R * record	);
//template<class R>		   int		 rogue_write_record_specialized(	R * record	);
template<class R>		   IOSCANPVT rogue_getioscanpvt_specialized(	R * record	);

#endif	/* DEV_ROGUE_H */
