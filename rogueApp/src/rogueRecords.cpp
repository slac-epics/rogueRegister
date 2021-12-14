
#include <stdio.h>
#include <alarm.h>
#include <link.h>

#include <devSup.h>
#include <dbCommon.h>
#include <dbFldTypes.h>
#include <aiRecord.h>
#include <aoRecord.h>
#include <biRecord.h>
#include <boRecord.h>
#include <int64inRecord.h>
#include <int64outRecord.h>
#include <mbbiRecord.h>
#include <mbboRecord.h>
#include <longinRecord.h>
#include <longoutRecord.h>
#include <subRecord.h>
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
#include "DataStream.h"


int	DEBUG_ROGUE_RECORDS = 2;
epicsExportAddress( int,  DEBUG_ROGUE_RECORDS );

namespace ris = rogue::interfaces::stream;

int rogue_bad_field(
	void *record,
	const char *message,
	const char *fieldname )
{
	fprintf( stderr, "rogue_init_record: %s %s\n", message, fieldname );
	//recGblRecordError( S_db_badField, record, message );
	//return S_db_badField;
	return 15;
}

#if 0
#include <longoutRecord.h>
#include <aiRecord.h>
#include <aoRecord.h>
#include <biRecord.h>
#include <boRecord.h>
#include <mbbiRecord.h>
#include <mbboRecord.h>
template int        rogue_init_record(	longoutRecord	*, DBLINK );
template int        rogue_init_record(	aiRecord		*, DBLINK );
template int        rogue_init_record(	aoRecord		*, DBLINK );
template int        rogue_init_record(	biRecord		*, DBLINK );
template int        rogue_init_record(	boRecord		*, DBLINK );
template int        rogue_init_record(	mbbiRecord		*, DBLINK );
template int        rogue_init_record(	mbboRecord		*, DBLINK );
#endif

#if 0
template int        rogue_read_record(	aiRecord * );
template int        rogue_read_record(	aoRecord * );
template int        rogue_read_record(	mbbiRecord * );
template int        rogue_read_record(	mbboRecord * );

template int        rogue_write_record(	aoRecord	*, const double		& value );
template int        rogue_write_record(	mbbiRecord	*, const uint64_t	& value );
#endif


// longout record support
template int        rogue_init_record(	longoutRecord	*, DBLINK );
template int        rogue_write_record(	longoutRecord *, const uint64_t & rogueVal );

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef USE_TYPED_DSET
static long init_lo( struct dbCommon * pCommon )
#else
static long init_lo( void * pCommon )
#endif
{
	longoutRecord	*	pRecord	= reinterpret_cast < longoutRecord * >( pCommon );
	int             	status	= rogue_init_record( pRecord, pRecord->out );
	return status;
}

#ifdef USE_TYPED_DSET
static long write_lo( longoutRecord	*	pRecord )
#else
static long write_lo( void	*	record )
#endif
{
#ifndef USE_TYPED_DSET
	longoutRecord	*	pRecord	= reinterpret_cast <longoutRecord *>( record );
#endif
	const char 		*	functionName = "write_lo";
	long				status = 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		if ( DEBUG_ROGUE_RECORDS >= 3 )
			printf( "%s: status %ld, intValue %d\n", functionName, status, pRecord->val );
		int64_t		rogueValue	= static_cast<int64_t>( pRecord->val );
		status = rogue_write_record( pRecord, rogueValue );
	}
	else
	{
		if ( DEBUG_ROGUE_RECORDS >= 3 )
			printf( "%s: status %ld, uintValue %u\n", functionName, status, pRecord->val );
		uint64_t	rogueValue	= static_cast<uint64_t>( pRecord->val );
		status = rogue_write_record( pRecord, rogueValue );
	}
	return status;
}

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_lo;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           write_lo;
#else
	dset				common;
	long (*write_lo)(	struct longoutRecord	*	pRec );
#endif
}	dsetRogueLO =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_lo, NULL }, write_lo };
#else
{ 5, NULL, NULL, init_lo, NULL, write_lo };
#endif


epicsExportAddress( dset, dsetRogueLO );

#ifdef __cplusplus
}
#endif

#ifdef DBR_INT64
// int64in record support
#ifdef __cplusplus
extern "C"
{
#endif
template int        rogue_init_record(	int64inRecord	*, DBLINK );
template int        rogue_read_record(	int64inRecord *, int64_t  & rogueVal );
template int        rogue_read_record(	int64inRecord *, uint64_t & rogueVal );

#ifdef USE_TYPED_DSET
static long init_li64( struct dbCommon * pCommon )
#else
static long init_li64( void * pCommon )
#endif
{
	int64inRecord	*	pRecord		= reinterpret_cast < int64inRecord * >( pCommon );
	int             	status		= rogue_init_record( pRecord, pRecord->inp );
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( status == 0 )
	{
		if ( pRogueInfo->m_fSignedValue )
		{
			int64_t		rogueValue;
			rogue_read_record( pRecord, rogueValue );
			pRecord->val = static_cast<epicsInt64>( rogueValue );
		}
		else
		{
			uint64_t	rogueValue;
			rogue_read_record( pRecord, rogueValue );
			pRecord->val = static_cast<epicsInt64>( rogueValue );
		}
	}
	return status;
}

#ifdef USE_TYPED_DSET
static long read_li64( int64inRecord	*	pRecord )
{
	long				status		= 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		int64_t		rogueValue;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt64>( rogueValue );
	}
	else
	{
		uint64_t	rogueValue;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt64>( rogueValue );
	}
	//pRecord->linr = 0;		// prevent conversions
	return status;
}
#else
static long read_li64( void	*	record )
{
	const char 		*	functionName = "read_li64";
	long				status		= 0;
	int64inRecord	*	pRecord		= reinterpret_cast <int64inRecord *>( record );
	rogue_info_t	*	pRogueInfo	= reinterpret_cast <rogue_info_t  *>( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		int64_t		rogueValue	= -1L;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt64>( rogueValue );
		if ( DEBUG_ROGUE_RECORDS >= 4 )
			printf( "%s: status %ld, intValue %lld\n", functionName, status, pRecord->val );
	}
	else
	{
		uint64_t	rogueValue	= 0L;
		status = rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsInt64>( rogueValue );
		if ( DEBUG_ROGUE_RECORDS >= 4 )
			printf( "%s: status %ld, uintValue %llu\n", functionName, status, pRecord->val );
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
	DEVSUPFUN           init_li64;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_li64;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_li64)(	struct int64inRecord	*	pRec );
#endif
}	dsetRogueLI64 =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_li64, NULL }, read_li64 };
#else
{ 5, NULL, NULL, init_li64, NULL, read_li64 };
#endif


epicsExportAddress( dset, dsetRogueLI64 );

#ifdef __cplusplus
}
#endif

// int64out record support
template int        rogue_init_record(	int64outRecord	*, DBLINK );
template int        rogue_write_record(	int64outRecord *, const uint64_t & rogueVal );

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef USE_TYPED_DSET
static long init_lo64( struct dbCommon * pCommon )
#else
static long init_lo64( void * pCommon )
#endif
{
	int64outRecord	*	pRecord	= reinterpret_cast < int64outRecord * >( pCommon );
	int             	status	= rogue_init_record( pRecord, pRecord->out );
	return status;
}

#ifdef USE_TYPED_DSET
static long write_lo64( int64outRecord	*	pRecord )
#else
static long write_lo64( void	*	record )
#endif
{
#ifndef USE_TYPED_DSET
	int64outRecord	*	pRecord	= reinterpret_cast <int64outRecord *>( record );
#endif
	const char 		*	functionName = "write_lo64";
	long				status = 0;
	rogue_info_t	*	pRogueInfo	= reinterpret_cast < rogue_info_t * >( pRecord->dpvt );
	if ( pRogueInfo->m_fSignedValue )
	{
		if ( DEBUG_ROGUE_RECORDS >= 3 )
			printf( "%s: status %ld, intValue %lld\n", functionName, status, pRecord->val );
		int64_t		rogueValue	= static_cast<int64_t>( pRecord->val );
		status = rogue_write_record( pRecord, rogueValue );
	}
	else
	{
		if ( DEBUG_ROGUE_RECORDS >= 3 )
			printf( "%s: status %ld, uintValue %llu\n", functionName, status, pRecord->val );
		uint64_t	rogueValue	= static_cast<uint64_t>( pRecord->val );
		status = rogue_write_record( pRecord, rogueValue );
	}
	//pRecord->linr = 0;		// prevent conversions
	return status;
}

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_lo64;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           write_lo64;
#else
	dset				common;
	long (*write_lo64)(	struct int64outRecord	*	pRec );
#endif
}	dsetRogueLO64 =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_lo64, NULL }, write_lo64 };
#else
{ 5, NULL, NULL, init_lo64, NULL, write_lo64 };
#endif


epicsExportAddress( dset, dsetRogueLO64 );

#ifdef __cplusplus
}
#endif
#endif

// ai record support
#ifdef __cplusplus
extern "C"
{
#endif

template int        rogue_init_record(	aiRecord	*, DBLINK );
template int        rogue_read_record(	aiRecord	*, double  & rogueVal );

#ifdef USE_TYPED_DSET
static long init_ai( struct dbCommon * pCommon )
#else
static long init_ai( void * pCommon )
#endif
{
	aiRecord	*	pRecord	= reinterpret_cast < aiRecord * >( pCommon );
	int             status	= rogue_init_record( pRecord, pRecord->inp );
	if ( status == 0 )
	{
		rogue_read_record( pRecord, pRecord->val );
	}
	return status;
}

#ifdef USE_TYPED_DSET
static long read_ai( aiRecord	*	pRecord )
{
	long	status = 0;
	rogue_read_record( pRecord, pRecord->val );
	return status;
}
#else
static long read_ai( void	*	record )
{
	const char 		*	functionName = "read_ai";
	long				status = 0;
	aiRecord		*	pRecord	= reinterpret_cast <aiRecord *>( record );
	rogue_read_record( pRecord, pRecord->val );
	if ( DEBUG_ROGUE_RECORDS >= 4 )
		printf( "%s: status %ld, aiValue %f\n", functionName, status, pRecord->val );
	return status;
}
#endif

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_ai;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_ai;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_ai)(	struct aiRecord	*	pRec );
#endif
}	dsetRogueAI =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_ai, NULL }, read_ai };
#else
{ 5, NULL, NULL, init_ai, NULL, read_ai };
#endif

epicsExportAddress( dset, dsetRogueAI );

#ifdef __cplusplus
}
#endif

// ao record support
template int        rogue_init_record(	aoRecord *, DBLINK );
template int        rogue_write_record(	aoRecord *, const double & rogueVal );

#ifdef __cplusplus
extern "C"
{
#endif

static long init_ao( void * pCommon )
{
	aoRecord	*	pRecord	= reinterpret_cast < aoRecord * >( pCommon );
	return rogue_init_record( pRecord, pRecord->out );
}

static long write_ao( void	*	record )
{
	aoRecord	*	pRecord		= reinterpret_cast <aoRecord *>( record );
	int				status		=  rogue_write_record( pRecord, pRecord->val );

	const char 	*	functionName = "write_ao";
	if ( DEBUG_ROGUE_RECORDS >= 3 )
		printf( "%s: status %d, value %f\n", functionName, status, pRecord->val );
	return status;
}

struct
{
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_ao;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           write_ao;
}	dsetRogueAO =
{ 5, NULL, NULL, init_ao, NULL, write_ao };

epicsExportAddress( dset, dsetRogueAO );

#ifdef __cplusplus
}
#endif

// bi record support
#ifdef __cplusplus
extern "C"
{
#endif

template int        rogue_init_record(	biRecord	*, DBLINK );
template int        rogue_read_record(	biRecord	*, bool  & rogueVal );

#ifdef USE_TYPED_DSET
static long init_bi( struct dbCommon * pCommon )
#else
static long init_bi( void * pCommon )
#endif
{
	biRecord	*	pRecord	= reinterpret_cast < biRecord * >( pCommon );
	int             status	= rogue_init_record( pRecord, pRecord->inp );
	if ( status == 0 )
	{
		bool	rogueValue;
		rogue_read_record( pRecord, rogueValue );
		pRecord->val = static_cast<epicsEnum16>( rogueValue );

		//pRecord->linr = 0;		// prevent conversions
	}
	return status;
}

#ifdef USE_TYPED_DSET
static long read_bi( biRecord	*	pRecord )
{
	long	status = 0;
	bool	rogueValue;
	rogue_read_record( pRecord, rogueValue );
	pRecord->rval = static_cast<epicsEnum16>( rogueValue );
	//pRecord->linr = 0;		// prevent conversions
	return status;
}
#else
static long read_bi( void	*	record )
{
	const char 		*	functionName = "read_bi";
	long				status = 0;
	biRecord		*	pRecord	= reinterpret_cast <biRecord *>( record );
	bool				rogueValue;
	rogue_read_record( pRecord, rogueValue );
	pRecord->rval = static_cast<epicsEnum16>( rogueValue );
	if ( DEBUG_ROGUE_RECORDS >= 4 )
		printf( "%s: status %ld, biValue %d\n", functionName, status, pRecord->val );
	return status;
}
#endif

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_bi;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_bi;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_bi)(	struct biRecord	*	pRec );
#endif
}	dsetRogueBI =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_bi, NULL }, read_bi };
#else
{ 5, NULL, NULL, init_bi, NULL, read_bi };
#endif

epicsExportAddress( dset, dsetRogueBI );

#ifdef __cplusplus
}
#endif

// bo record support
template int        rogue_init_record(	boRecord *, DBLINK );
template int        rogue_write_record(	boRecord *, const uint64_t & rogueVal );

#ifdef __cplusplus
extern "C"
{
#endif

static long init_bo( void * pCommon )
{
	boRecord	*	pRecord	= reinterpret_cast < boRecord * >( pCommon );
	return rogue_init_record( pRecord, pRecord->out );
}

static long write_bo( void	*	record )
{
	boRecord	*	pRecord		= reinterpret_cast <boRecord *>( record );
	bool			rogueValue	= static_cast<bool>( pRecord->val );
	int				status		=  rogue_write_record( pRecord, rogueValue );

	const char 	*	functionName = "write_bo";
	if ( DEBUG_ROGUE_RECORDS >= 3 )
		printf( "%s: status %d, value %u\n", functionName, status, pRecord->val );
	return status;
}

struct
{
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_bo;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           write_bo;
}	dsetRogueBO =
{ 5, NULL, NULL, init_bo, NULL, write_bo };

epicsExportAddress( dset, dsetRogueBO );

#ifdef __cplusplus
}
#endif

// mbbi record support
#ifdef __cplusplus
extern "C"
{
#endif

template int        rogue_init_record(	mbbiRecord	*, DBLINK );
template int        rogue_read_record(	mbbiRecord	*, uint64_t & rogueVal );

#ifdef USE_TYPED_DSET
static long init_mbbi( struct dbCommon * pCommon )
#else
static long init_mbbi( void * pCommon )
#endif
{
	mbbiRecord	*	pRecord	= reinterpret_cast < mbbiRecord * >( pCommon );
	int             status	= rogue_init_record( pRecord, pRecord->inp );
	if ( status == 0 )
	{
		uint64_t	rogueValue;
		rogue_read_record( pRecord, rogueValue );
		pRecord->rval = static_cast<epicsEnum16>( rogueValue );
	}
	return status;
}

#ifdef USE_TYPED_DSET
static long read_mbbi( mbbiRecord	*	pRecord )
{
	long		status = 0;
	uint64_t	rogueValue;
	rogue_read_record( pRecord, rogueValue );
	pRecord->rval = static_cast<epicsEnum16>( rogueValue );
	return status;
}
#else
static long read_mbbi( void	*	record )
{
	const char 		*	functionName = "read_mbbi";
	long				status = 0;
	mbbiRecord		*	pRecord	= reinterpret_cast <mbbiRecord *>( record );
	uint64_t			rogueValue;
	rogue_read_record( pRecord, rogueValue );
	pRecord->rval = static_cast<epicsEnum16>( rogueValue );
	if ( DEBUG_ROGUE_RECORDS >= 4 )
		printf( "%s: status %ld, mbbiValue %d\n", functionName, status, pRecord->val );
	return status;
}
#endif

struct
{
#ifndef USE_TYPED_DSET
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_mbbi;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           read_mbbi;
	DEVSUPFUN           special_linconv;
#else
	dset				common;
	long (*read_mbbi)(	struct mbbiRecord	*	pRec );
#endif
}	dsetRogueMBBI =
#ifdef USE_TYPED_DSET
{ { 5, NULL, NULL, init_mbbi, NULL }, read_mbbi };
#else
{ 5, NULL, NULL, init_mbbi, NULL, read_mbbi };
#endif

epicsExportAddress( dset, dsetRogueMBBI );

#ifdef __cplusplus
}
#endif

// mbbo record support
template int        rogue_init_record(	mbboRecord *, DBLINK );
template int        rogue_write_record(	mbboRecord *, const uint64_t & rogueVal );

#ifdef __cplusplus
extern "C"
{
#endif

static long init_mbbo( void * pCommon )
{
	mbboRecord	*	pRecord	= reinterpret_cast < mbboRecord * >( pCommon );
	return rogue_init_record( pRecord, pRecord->out );
}

static long write_mbbo( void	*	record )
{
	mbboRecord	*	pRecord		= reinterpret_cast <mbboRecord *>( record );
	uint64_t		rogueValue	= static_cast<uint64_t>( pRecord->val );
	int				status		= rogue_write_record( pRecord, rogueValue );

	const char 	*	functionName = "write_mbbo";
	if ( DEBUG_ROGUE_RECORDS >= 3 )
		printf( "%s: status %d, value %u\n", functionName, status, pRecord->val );
	return status;
}

struct
{
	long                number;
	DEVSUPFUN           report;
	DEVSUPFUN           init;
	DEVSUPFUN           init_mbbo;
	DEVSUPFUN           get_ioint_info;
	DEVSUPFUN           write_mbbo;
}	dsetRogueMBBO =
{ 5, NULL, NULL, init_mbbo, NULL, write_mbbo };

epicsExportAddress( dset, dsetRogueMBBO );

#ifdef __cplusplus
}
#endif

//	AdcCalibration
//	Configures PLL on FEB for specified pixel clock
//	Inputs:
//		A:	LONG, Board number
//		B:	LONG, Lane  number
//
extern "C" long AdcCalibration( subRecord	*	pSub	)
{
    static const char	*	functionName = "AdcCalibration";
	int			status		= 0;

	// Get input values
	unsigned int	iBoard		= (unsigned int) pSub->a;
//	unsigned int	iLane		= (unsigned int) pSub->b;

	pgpRogueDevPtr	pRogueDev = pgpRogueDev::RogueFindByBoard( iBoard );
	if ( pRogueDev == NULL )
	{
		printf( "%s error: Rogue board %u not found!\n", functionName, iBoard );
		return 0;
	}
	wave8RogueLibPtr	pRogueLib = pRogueDev->GetWave8RogueLib();
	if ( pRogueLib == NULL )
	{
		printf( "%s error: Rogue lib for board %u not found!\n", functionName, iBoard );
		return 0;
	}
	pSub->val = 0;
	status	= pRogueLib->AdcCalibration( );
	if ( status != 0 )
	{
		printf( "%s: Error %d\n", functionName, status );
		return status;
	}

    if ( DEBUG_ROGUE_RECORDS >= 2 )
		printf( "%s: Successful\n", functionName );

	return 0;
}
