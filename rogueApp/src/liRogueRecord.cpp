
#include <stdio.h>
#include <alarm.h>
#include <link.h>

#include <devSup.h>
#include <dbCommon.h>
#include <dbFldTypes.h>
//#include <aiRecord.h>
//#include <aoRecord.h>
//#include <biRecord.h>
//#include <boRecord.h>
//#include <int64inRecord.h>
//#include <int64outRecord.h>
//#include <mbbiRecord.h>
//#include <mbboRecord.h>
#include <longinRecord.h>
//#include <longoutRecord.h>
//#include <waveformRecord.h>
#include <caeventmask.h>
#include <dbEvent.h>
//#include <dbAccessDefs.h>
#include <dbLock.h>
#include <dbScan.h>
#include <recGbl.h>
#include <recSup.h>
#include <epicsExport.h>
#include <epicsThread.h>

//#include "drvRogue.h"
#include "rogueRecords.h"
#include "pgpRogueDev.h"
//#include "DataStream.h"



namespace ris = rogue::interfaces::stream;

// longin record support
#ifdef __cplusplus
extern "C"
{
#endif
template int        rogue_init_record(	longinRecord	*, DBLINK );
template int        rogue_read_record(	longinRecord *, int64_t  & rogueVal );
template int        rogue_read_record(	longinRecord *, uint64_t & rogueVal );

#ifdef USE_TYPED_DSET
static long init_li( struct dbCommon * pCommon )
#else
static long init_li( void * pCommon )
#endif
{
	longinRecord	*	pRecord		= reinterpret_cast < longinRecord * >( pCommon );
	int             	status		= rogue_init_record( pRecord, pRecord->inp );
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( status == 0 )
	{
		if ( pRogueInfo->m_fSignedValue )
		{
			int64_t		rogueValue;
			rogue_read_record( pRecord, rogueValue );
			pRecord->val = static_cast<epicsInt32>( rogueValue );
		}
		else
		{
			uint64_t	rogueValue;
			rogue_read_record( pRecord, rogueValue );
			pRecord->val = static_cast<epicsInt32>( rogueValue );
		}
		//pRecord->linr = 0;		// prevent conversions
	}
	return status;
}

#ifdef USE_TYPED_DSET
static long read_li( longinRecord	*	pRecord )	// TODO: Remove ifdef USE_TYPED_DSET
{
	long				status		= 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		int64_t		rogueValue;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt32>( rogueValue );
	}
	else
	{
		uint64_t	rogueValue;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt32>( rogueValue );
	}
	//pRecord->linr = 0;		// prevent conversions
	return status;
}
#else
static long read_li( void	*	record )
{
	const char 		*	functionName = "read_li";
	long				status		= 0;
	longinRecord	*	pRecord		= reinterpret_cast <longinRecord *>( record );
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		int64_t		rogueValue	= -1L;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt32>( rogueValue );
		if ( DEBUG_ROGUE_RECORDS >= 4 )
			printf( "%s: status %ld, intValue %d\n", functionName, status, pRecord->val );
	}
	else
	{
		uint64_t	rogueValue	= 0L;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt32>( rogueValue );
		if ( DEBUG_ROGUE_RECORDS >= 4 )
			printf( "%s: status %ld, uintValue %u\n", functionName, status, pRecord->val );
	}
	return status;
}
#endif

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_li;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_li;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_li)(	struct longinRecord	*	pRec );
#endif
}	dsetRogueLI =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_li, NULL }, read_li };
#else
{ 5, NULL, NULL, init_li, NULL, read_li };
#endif


epicsExportAddress( dset, dsetRogueLI );

#ifdef __cplusplus
}
#endif
