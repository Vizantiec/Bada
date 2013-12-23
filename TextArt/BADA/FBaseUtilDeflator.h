/* $Change: 333898 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FBaseUtilDeflator.h
 * @brief		This is the header file for the %Deflator class.
 *
 * This header file contains the declarations of the %Deflator class.
 */
#ifndef _FBASE_UTIL_DEFLATOR_H_
#define _FBASE_UTIL_DEFLATOR_H_

//Includes
#include "FBaseByteBuffer.h"
#include "FBaseUtilTypes.h"

namespace Osp { namespace Base { namespace Utility {

/**
 * @class	Deflator
 * @brief	This class provides the deflate functionality using zlib.
 * @since	1.1
 *
 * The %Deflator class provides the deflate functionality using zlib.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %Deflator class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *
 *	void
 *	MyClass::DeflatorSample(ByteBuffer &buf)
 *	{
 *		ByteBuffer* pBuf1 = null;
 *		ByteBuffer* pBuf2 = null;
 *		ByteBuffer* pBuf3 = null;
 *
 *
 *		//Deflate buf from current position to limit of ByteBuffer buf.
 *		pBuf1 = Deflator::DeflateN(buf);
 *		if (null == pBuf1)
 *		{
 *			//Error case handling...
 *		}
 *		//pBuf1:Deflated Data of buf
 *
 *
 *		//Deflate buf from current position to (limit-2) of ByteBuffer buf.
 *		pBuf2 = Deflator::DeflateN(buf, (buf.GetLimit()-2));
 *		if (null == pBuf2)
 *		{
 *			//Error case handling...
 *		}
 *
 *
 *		//Deflate buf from current position to limit of ByteBuffer buf for BEST_COMPRESSION.
 *		pBuf3 = Deflator::DeflateN(buf, BEST_COMPRESSION);
 *		if (null == pBuf3)
 *		{
 *			//Error case handling...
 *		}
 *
 *
 *		delete pBuf1;
 *		delete pBuf2;
 *		delete pBuf3;
 *	}
 *
 *	@endcode
 */
class	_EXPORT_BASE_ Deflator
{
public:

// Operations (Static)
public:
	/**
	 * Deflates the number of bytes from the source byte buffer to the output byte buffer.
	 *
	 * @since	1.1
	 * @return			A pointer to the ByteBuffer instance with the deflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the deflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to deflate
	 * @param[in]		byteCount	The number of bytes to be deflated from the source buffer
	 * @param[in]		level		Set to BEST_SPEED or BEST_COMPRESSION @n
	 * 								By default, it is set to DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Osp::Base::Utility::Inflator
	 */
	static ByteBuffer* DeflateN (const ByteBuffer& src, int byteCount, CompressionLevel level = DEFAULT_COMPRESSION);

	/**
	 * Deflates data from the source byte buffer to the output byte buffer.
	 *
	 * @since	1.1
	 * @return			A pointer to the ByteBuffer instance with the deflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the deflated data @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src		The buffer to deflate
	 * @param[in]		level	Set to BEST_SPEED or BEST_COMPRESSION @n
	 * 							By default, it is set to DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Osp::Base::Utility::Inflator
	 */
	static ByteBuffer* DeflateN (const ByteBuffer& src, CompressionLevel level = DEFAULT_COMPRESSION);

private:
	/**
	 * This is the default constructor for this class.
	 */
	Deflator(void);


public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.1
	 */
	virtual ~Deflator(void);

private:
	static ByteBuffer* __DeflateN(const ByteBuffer& src, int byteCount, CompressionLevel level);

};
}; };  }; // Osp::Base::Utility
#endif // _FBASE_UTIL_DEFLATOR_H_

