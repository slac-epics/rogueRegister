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

extern int	DEBUG_ROGUE_RECORDS;

extern int rogue_bad_field( void * pRogue, const char *message, const char *fieldname );

template < class R >
int rogue_init_record(
	R		*	record,
	DBLINK		link )
{
	const char * functionName = "template rogue_init_record";
	if ( link.type != INST_IO )
	{
		return rogue_bad_field( record, "wrong link type", "" );
	}
	struct instio      *pinstio = &link.value.instio;

	if ( !pinstio->string )
	{
		return rogue_bad_field( record, "invalid link", "" );
	}

	const char			*	sinp	= pinstio->string;
	int                 	status;
	epicsUInt32            	board;
	epicsUInt32            	lane;
	epicsUInt32            	signal	= 0;
	char                	varPath[512];

	status = sscanf( sinp, "B%u L%u %511s", &board, &lane, varPath );
	if ( status != 3 )
	{
		return rogue_bad_field( record, "cannot parse INP or OUT field!\n%s\n", sinp );
	}

	pgpRogueDevPtr	pRogueDev = pgpRogueDev::RogueFindByBoard( board );
	if ( pRogueDev == NULL )
	{
		return rogue_bad_field( record, "cannot find rogue device for INP or OUT field!\n%s\n", sinp );
	}

	if ( varPath[strlen(varPath)-1] == ']' )
	{
		// This path ends in an array reference that can be used to derive a signal number
		char	*	pArray = strrchr( varPath, '[' );
		if ( pArray )
		{
			unsigned int	sigNum	 = 0;
			status = sscanf( pArray, "[%d]", &sigNum );
			if ( status == 1 )
				signal = sigNum;
		}
	}

	if ( DEBUG_ROGUE_RECORDS >= 4 )
		printf( "%s Parse succeeded: Board %u, Lane %u, VarPath %s\n", functionName, board, lane, varPath );

	rogue_info_t *	pRogueInfo	= new rogue_info_t;
	pRogueInfo->m_signal		= signal;
	pRogueInfo->m_varPath		= varPath;
	pRogueInfo->m_pRogueLib		= pRogueDev->GetRogueLib();
	pRogueInfo->m_pRogueDev		= pRogueDev;
	pRogueInfo->m_fSignedValue	= false;
	pRogueInfo->m_pRecCommon	= (struct dbCommon *) record,
	scanIoInit( &pRogueInfo->m_scanIo );
	rogue::interfaces::memory::VariablePtr	pVar;
	pVar = pRogueInfo->m_pRogueLib->getVariable( pRogueInfo->m_varPath );
	if ( !pVar )
	{
		printf( "%s error: %s not found!\n", functionName, pRogueInfo->m_varPath.c_str() );
	}
	else
	{
		pRogueInfo->m_modelId	= pVar->modelId();
		pRogueInfo->m_numBits	= pVar->bitTotal();
		if ( pVar->modelId() == rogue::interfaces::memory::Int )
		{
			pRogueInfo->m_fSignedValue	= true;
		}
	}
	record->dpvt				= pRogueInfo;

	// Do not convert
	return 2;
}


template < class R, class V >
int rogue_read_record( R * record, V & valueRet )
{
	int					status		= 1;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( record->dpvt );
	status = pRogueInfo->m_pRogueLib->readVarPath( pRogueInfo->m_varPath.c_str(), valueRet );

#if 0
	const char 		*	functionName = "rogue_read_record<R>";
	rogue::interfaces::memory::VariablePtr	pVar;
	pVar = pRogueInfo->m_pRogueLib->getVariable( pRogueInfo->m_varPath );
	if ( !pVar )
	{
		printf( "%s error: %s not found!\n", functionName, pRogueInfo->m_varPath.c_str() );
	}
#endif
	if ( status )
	{
		record->nsta = UDF_ALARM;
		record->nsev = INVALID_ALARM;
		return -1;
	}
	else
	{
		record->udf = FALSE;
	}
	return 0;
}

template < class R, class V >
int rogue_write_record( R * record, const V & value )
{
//	const char 		*	functionName = "rogue_write_record<R>";
	int					status		= 1;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( record->dpvt );
	status = pRogueInfo->m_pRogueLib->writeVarPath( pRogueInfo->m_varPath.c_str(), value );

	return status;
}

template < class R >
long rogue_ioinfo( int detach, struct dbCommon * pCommon, IOSCANPVT * pScanPvt )
{
	if ( !pCommon || !pScanPvt )
		return 0;
	R				*	pRec 		= (R *) pCommon;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRec->dpvt );
	if ( pRogueInfo->m_pRogueDev )
	{
		*pScanPvt = pRogueInfo->m_scanIo;
		if ( DEBUG_ROGUE_RECORDS >= 2 )
			printf( "rogue_ioinfo succeeded for signal %zu.\n", pRogueInfo->m_signal );
	}
	else
	{
		*pScanPvt = NULL;
	}
	return 0;
}

//template<class R, class EV, class RV> int rogue_read_record( R * record, EV & epicsVal, RV &rogueVal );
//template<class R>		   int		 rogue_init_record_specialized(	R * record	);
//template<class R>		   int		 rogue_read_record_specialized(	R * record	);
//template<class R>		   int		 rogue_write_record_specialized(	R * record	);
//template<class R>		   IOSCANPVT rogue_getioscanpvt_specialized(	R * record	);

#endif	/* DEV_ROGUE_H */
