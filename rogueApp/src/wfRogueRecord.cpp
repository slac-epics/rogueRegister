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
//#include <longinRecord.h>
//#include <longoutRecord.h>
#include <waveformRecord.h>
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

// waveform record support
#ifdef __cplusplus
extern "C"
{
#endif

template int        rogue_init_record(	waveformRecord	*, DBLINK );

#ifdef USE_TYPED_DSET
static long init_waveform( struct dbCommon * pCommon )
#else
static long init_waveform( void * pCommon )
#endif
{
	const char * functionName = "init_waveform";
	waveformRecord	*	pRecord	= reinterpret_cast < waveformRecord * >( pCommon );
	int            	 status	= 0;
//	status	= rogue_init_record( pRecord, pRecord->inp );
	DBLINK			link	= pRecord->inp;
	if ( link.type != INST_IO )
	{
		return rogue_bad_field( pRecord, "wrong link type", "" );
	}
	struct instio      *pinstio = &link.value.instio;

	if ( !pinstio->string )
	{
		return rogue_bad_field( pRecord, "invalid link", "" );
	}

	const char			*	sinp	= pinstio->string;
	epicsUInt32            	board;
	epicsUInt32            	lane;
	epicsUInt32            	signal;

	status = sscanf( sinp, "B%u L%u S%u", &board, &lane, &signal );
	if ( status != 3 )
	{
		fprintf( stderr, "%s Error: Cannot parse INP field!\n"
				"Expected 3 numbers for board, lane, and signal.\n"
				"Example: B0 L3 S12\n"
				"Got: %s\n", functionName, sinp );
	}
	if ( DEBUG_ROGUE_RECORDS >= 2 )
		printf( "%s Parse succeeded: Board %u, Lane %u, Signal %u\n", functionName, board, lane, signal );

	pgpRogueDevPtr	pRogueDev = pgpRogueDev::RogueFindByBoard( board );
	if ( pRogueDev == NULL )
	{
		return rogue_bad_field( pRecord, "cannot find rogue device for INP or OUT field!\n%s\n", sinp );
	}

	if ( DEBUG_ROGUE_RECORDS >= 4 )
		printf( "%s Parse succeeded: Board %u, Lane %u, Signal %u\n", functionName, board, lane, signal );

	rogue_info_t	*	pRogueInfo		= new rogue_info_t;
	pRogueInfo->m_signal		= signal;
	pRogueInfo->m_varPath		= "unused";
	pRogueInfo->m_pRogueLib		= pRogueDev->GetRogueLib();
	pRogueInfo->m_pRogueDev		= pRogueDev;
	pRogueInfo->m_fSignedValue	= false;
	pRogueInfo->m_pRecCommon	= (struct dbCommon *) pCommon;
	scanIoInit( &pRogueInfo->m_scanIo );
//	if ( !pVar )
//	{
//		printf( "%s error: %s not found!\n", functionName, pRogueInfo->m_varPath.c_str() );
//	}
	pRecord->dpvt				= pRogueInfo;

	pRogueDev->SetRawDataRogueInfo( signal, pRogueInfo );

	// Do not convert
	return 2;
}

#ifdef USE_TYPED_DSET
static long ioinfo_waveform( int detach, struct dbCommon * pCommon, IOSCANPVT * pioScanRet )
#else
static long ioinfo_waveform( int detach, void * pCommon, IOSCANPVT * pioScanRet )
#endif
{
	const char * functionName = "ioinfo_waveform";
	waveformRecord	*	pRecord	= reinterpret_cast < waveformRecord * >( pCommon );
	//int            	 	status	= 0;
	rogue_info_t	*	pRogueInfo	= (rogue_info_t *) pRecord->dpvt;
	if ( pRogueInfo->m_pRogueDev )
	{
		*pioScanRet = pRogueInfo->m_scanIo;
		if ( DEBUG_ROGUE_RECORDS >= 2 )
			printf( "%s succeeded for signal %zu.\n", functionName, pRogueInfo->m_signal );
	}
	return 0;
}

#ifdef USE_TYPED_DSET
//static int rogue_read_waveform(	waveformRecord	* pRecord );
static long read_waveform( waveformRecord	*	pRecord )
{
	long		status = 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( DEBUG_ROGUE_RECORDS >= 6 )
		printf( "%s: status %ld, waveform nElements=%d\n", functionName, status, pRecord->nelm );
	return status;
}
#else
//static int rogue_read_waveform(	void	* pRecord );
static long read_waveform( void	*	record )
{
	const char 		*	functionName = "read_waveform";
	long				status = 0;
	waveformRecord	*	pRecord	= reinterpret_cast <waveformRecord *>( record );
	if ( DEBUG_ROGUE_RECORDS >= 7 )
		printf( "%s: status %ld, thread %s ...\n",
				functionName, status, epicsThreadGetNameSelf() );
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );

	// data loaded by pgpRogueDev
	if ( pRogueInfo->m_newDataCount	!= 0 )
	{
		if( pRecord->nord != pRogueInfo->m_newDataCount )
		{
			pRecord->nord =  pRogueInfo->m_newDataCount;
			db_post_events( pRecord, &pRecord->nord, (DBE_VALUE|DBE_LOG) );
		}
	}
	pRogueInfo->m_newDataCount	= 0;
	if ( status )
	{
		pRecord->nsta = UDF_ALARM;
		pRecord->nsev = INVALID_ALARM;
		return -1;
	}
	else
	{
		pRecord->udf = FALSE;
	}
	return 0;
}
#endif

long update_waveform( waveformRecord	*	pRecord, epicsTimeStamp tcUpdate, ris::FramePtr	pDataFrame )
{
	const char		*	functionName	= "update_waveform";
	long				status = 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	pRecord->time = tcUpdate;
	if ( DEBUG_ROGUE_RECORDS >= 5 )
	{
		char	acBuff[40];
		epicsTimeToStrftime( acBuff, 40, "%F %H:%M:%S.%04f", &pRecord->time );
		printf( "%s: Signal %zu, tsFrame %s, pulseId 0x%X\n", functionName, pRogueInfo->m_signal,
				acBuff, pRecord->time.nsec & 0x1FFFF );
	}
	// Load data into buffer
	{	// TODO: Templatize this
	rogue::interfaces::stream::FrameIterator	it;
	pRogueInfo->m_newDataCount	= 0;
	uint16_t	*	pData = (uint16_t *) pRecord->bptr;
	memset( pData, 0, sizeof(uint16_t) * pRecord->nelm );
	if ( pDataFrame )
	{
		it = pDataFrame->begin();
		pRogueInfo->m_newDataCount = pDataFrame->getSize() / sizeof(uint16_t);
		if( pRogueInfo->m_newDataCount > pRecord->nelm )
			pRogueInfo->m_newDataCount = pRecord->nelm;
		if ( pRogueInfo->m_newDataCount > 0 )
		{
			fromFrame( it, pRogueInfo->m_newDataCount * sizeof(uint16_t), pData );

			if ( 1 ) {
			// Fill remainder of record buffer w/ final value
			pData = (uint16_t *) pRecord->bptr + pRogueInfo->m_newDataCount - 1;
			uint16_t	finalValue	= *pData++;
			for ( size_t i = pRogueInfo->m_newDataCount; i < pRecord->nelm; i++ )
				*pData++ = finalValue;
			pRogueInfo->m_newDataCount = pRecord->nelm;
			}
		}
		pDataFrame.reset();
	}
	// Process waveform record via read_waveform() using high priority scanIo Q
	scanIoImmediate( pRogueInfo->m_scanIo, priorityHigh );
	}
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
	DEVSUPFUN           init_waveform;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_waveform;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_waveform)(	struct waveformRecord	*	pRec );
#endif
}	dsetRogueWF =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_waveform, ioinfo_waveform }, read_waveform };
#else
{ 5, NULL, NULL, init_waveform, (DEVSUPFUN) ioinfo_waveform, read_waveform };
#endif

epicsExportAddress( dset, dsetRogueWF );

#ifdef __cplusplus
}
#endif
