#include <stdio.h>
#include <string.h>

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

	if (	pRecord->scan == menuScanI_O_Intr
		&&	pRecord->inp.type == INST_IO )
	{
		struct instio      *pinstio = &pRecord->inp.value.instio;
		if ( pinstio->string &&	strstr( pinstio->string, "Integrators.AdcIntegral" ) )
		{
			//printf( "%s: SetIntegralRogueInfo for signal %zu.\n", pRecord->name, pRogueInfo->m_signal );
			pRogueInfo->m_pRogueDev->SetIntegralRogueInfo( pRogueInfo->m_signal, pRogueInfo );
		}
	}
	// TODO: Do we need to call rogue_read_record during record initialization?
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
	if ( pRogueInfo->m_newDataCount	!= 0 )
	{
		// Data already loaded via update_longin()
		status = 0;
		if ( DEBUG_ROGUE_RECORDS >= 4 )
			printf( "%s %s: status %ld, I/O intValue %d\n", functionName, pRecord->name, status, pRecord->val );
	}
	else if ( pRogueInfo->m_fSignedValue )
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
	pRogueInfo->m_newDataCount = 0;
	return status;
}
#endif

extern "C" long update_longin( longinRecord * pRecord, epicsTimeStamp tcUpdate, epicsInt32 newValue )
{
	if ( ! pRecord )
		return -1;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	int		status	= 0;
	pRecord->time	= tcUpdate;
	pRecord->val	= newValue;
	pRogueInfo->m_newDataCount	= 1;
	if ( DEBUG_ROGUE_RECORDS >= 5 )
	{
		char	acBuff[40];
		epicsTimeToStrftime( acBuff, 40, "%F %H:%M:%S.%04f", &pRecord->time );
		printf( "%s: tsFrame %s, pulseId 0x%X, val %d\n", pRecord->name, acBuff, pRecord->time.nsec & 0x1FFFF, newValue );
	}

	// Process longin record via read_longin() using high priority scanIo Q
	scanIoImmediate( pRogueInfo->m_scanIo, pRecord->prio );

	if ( status )
	{
		pRecord->nsta = UDF_ALARM;
		pRecord->nsev = INVALID_ALARM;
		return -1;
	}
	else
	{
		pRecord->nsta = NO_ALARM;
		pRecord->nsev = NO_ALARM;
		pRecord->udf = FALSE;
	}
	return 0;
}

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
{ { 5, NULL, NULL, init_li, rogue_ioinfo }, read_li };
#else
{ 5, NULL, NULL, init_li, (DEVSUPFUN) rogue_ioinfo<longinRecord>, read_li };
#endif


epicsExportAddress( dset, dsetRogueLI );

#ifdef __cplusplus
}
#endif
