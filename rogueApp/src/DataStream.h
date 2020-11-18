#ifndef	CL_STREAM_SLAVE_H
#define	CL_STREAM_SLAVE_H

#ifndef	__STDC_FORMAT_MACROS
#define	__STDC_FORMAT_MACROS
#endif /* __STDC_FORMAT_MACROS */
#include <inttypes.h>
#include <callback.h>
#include <epicsTime.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Frame.h>
#include <rogue/interfaces/stream/FrameIterator.h>
#include <rogue/interfaces/stream/FrameLock.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/protocols/batcher/CoreV1.h>
#include <rogue/protocols/batcher/Data.h>

class pgpRogueDev;

typedef struct _ImageCbInfo
{
	epicsTimeStamp						m_tsImage;
	rogue::protocols::batcher::DataPtr	m_ImageDataPtr;

}	ImageCbInfo;


class DataStream : public rogue::interfaces::stream::Slave
{
public:

	// Create a static class creator to return our custom class
	// wrapped with a shared pointer
	static std::shared_ptr<DataStream> create( pgpRogueDev * pRogueDev )
	{
		static std::shared_ptr<DataStream> ret = std::make_shared<DataStream>( pRogueDev );
		return(ret);
	}

	DataStream( pgpRogueDev * pRogueDev )
		:	rogue::interfaces::stream::Slave( )
		,	m_pRogueDev(	pRogueDev	)
	{
	}

	//void acceptFrame ( std::shared_ptr<rogue::interfaces::stream::Frame> frame );
	void acceptFrame ( rogue::interfaces::stream::FramePtr frame );

	void frameCallback( CALLBACK * pCallbackPvt );

private:
	pgpRogueDev		*	m_pRogueDev;
	void			*	m_pCallbackClient;
	ImageCbInfo			m_ImageInfo;
	rogue::protocols::batcher::CoreV1	m_FrameCore;
};

// Shared pointer alias
typedef std::shared_ptr<DataStream> DataStreamPtr;

#endif	/* CL_STREAM_SLAVE_H */
