#ifndef	CL_STREAM_SLAVE_H
#define	CL_STREAM_SLAVE_H

#ifndef	__STDC_FORMAT_MACROS
#define	__STDC_FORMAT_MACROS
#endif /* __STDC_FORMAT_MACROS */
#include <inttypes.h>
#include <epicsTime.h>
#include <rogue/interfaces/stream/Slave.h>
#include <rogue/interfaces/stream/Frame.h>
#include <rogue/interfaces/stream/FrameIterator.h>
#include <rogue/interfaces/stream/FrameLock.h>
#include <rogue/hardware/axi/AxiStreamDma.h>
#include <rogue/protocols/batcher/CoreV1.h>
#include <rogue/protocols/batcher/Data.h>

class DataStreamSlave : public rogue::interfaces::stream::Slave
//class DataStreamSlave : public rogue::hardware::axi::AxiStreamDma
{
public:

	// Create a static class creator to return our custom class
	// wrapped with a shared pointer
	static std::shared_ptr<DataStreamSlave> create()
	{
		static std::shared_ptr<DataStreamSlave> ret = std::make_shared<DataStreamSlave>();
		return(ret);
	}

	DataStreamSlave() : rogue::interfaces::stream::Slave() { }

	void acceptFrame ( std::shared_ptr<rogue::interfaces::stream::Frame> frame );
};

// Shared pointer alias
typedef std::shared_ptr<DataStreamSlave> DataStreamSlavePtr;

#endif	/* CL_STREAM_SLAVE_H */
