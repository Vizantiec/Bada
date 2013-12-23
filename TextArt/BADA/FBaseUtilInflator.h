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
 * @file		FBaseUtilInflator.h
 * @brief		This is the header file for the %Inflator class.
 *
 * This header file contains the declarations of the %Inflator class.
 */
#ifndef _FBASE_UTIL_INFLATOR_H_
#define _FBASE_UTIL_INFLATOR_H_

//Includes
#include "FBaseByteBuffer.h"

namespace Osp { namespace Base { namespace Utility {
/**
 * @class	Inflator
 * @brief	This class provides the inflate functionality using zlib.
 * @since	1.1
 *
 * The %Inflator class provides the inflate functionality using zlib.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %Inflator class. 
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *
 *	void
 *	MyClass::InflatorSample(ByteBuffer &buf)
 *	{
 *
 *		ByteBuffer* pBuf1 = null;
 *		ByteBuffer* pBuf2 = null;
 *
 *
 *		//Inflate buf from current position to limit of ByteBuffer buf.
 *		pBuf1 = Inflator::InflateN(buf);
 *		if (null == pBuf1)
 *		{
 *			//Error case handling...
 *		}
 *		//pBuf1:Inflated Data of buf
 *
 *
 *		//Inflate buf from current position to (limit-2) of ByteBuffer buf.
 *		pBuf2 = Inflator::InflateN(buf, (buf.GetLimit()-2));
 *		if (null == pBuf2)
 *		{
 *			//Error case handling...
 *		}
 *
 *
 *		delete pBuf1;
 *		delete pBuf2;
 *	}
 *
 * @endcode
 */
class	_EXPORT_BASE_ Inflator
{
// Operations (Static)
public:

	/**
	 * Inflates the number of bytes from the source byte buffer to the output byte buffer.
	 *
	 * @since				1.1
	 * @return			A pointer to the ByteBuffer instance with the inflated equivalent of the source buffer @n 
	 *					The buffer's limit is the length of the inflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to inflate
	 * @param[in]		byteCount	The number of bytes to be inflated from the source buffer
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Osp::Base::Utility::Deflator
	 */
	static ByteBuffer* InflateN (const ByteBuffer& src, int byteCount);

	/**
	 * Inflates data from the source byte buffer to the output byte buffer.
	 *
	 * @since				1.1
	 * @return			A pointer to the ByteBuffer instance with the inflated equivalent of the source buffer @n 
	 *					The buffer's limit is the length of the inflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to inflate
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Osp::Base::Utility::Deflator
	 */
	static ByteBuffer* InflateN (const ByteBuffer& src);

// life-cycle
private:
	/**
	 * This is the default constructor for this class.
	 */
	Inflator(void);



public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.1
	 */
	virtual ~Inflator(void);

private:
	static ByteBuffer* __InflateN (const ByteBuffer& src, int byteCount);

};
}; };  }; // Osp::Base::Utility
#endif // _FBASE_UTIL_INFLATOR_H_

