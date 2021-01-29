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
//	memoryBuffer.h
//
//	Header file for memoryBuffer class.
//	It provides a wrapper to encapsulate a block of memory with
//	a std::basic_streambuf template.
//
#ifndef	memoryBuffer_H
#define	memoryBuffer_H


template<	class ItemT,
			class Traits = std::char_traits<ItemT>
		>	class basic_MemoryBuffer : public std::basic_streambuf<ItemT, Traits>
{
public:
	basic_MemoryBuffer( ItemT * ptr, std::size_t size )
	{
		setg( ptr, ptr, ptr + size );
	}
};

#endif	//	memoryBuffer_H
#ifndef	MemoryStream_H
#define	MemoryStream_H
#include <ostream>

template<	class ItemT,
			class Traits = std::char_traits<ItemT>
		>	class basic_MemoryOutputString : public std::basic_ostream<ItemT>
{
public:
	basic_MemoryOutputString( ItemT * ptr, std::size_t size )
		:	std::basic_ostream<ItemT>( &m_Buffer ),
			m_Buffer( ptr, size )
	{
		rdbuf( &m_Buffer );
	}

private:
	basic_MemoryBuffer<ItemT>	m_Buffer;
};
#endif	//	MemoryStream_H
