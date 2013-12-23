/* $Change: 1142016 $ */
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
 * @file		FBaseUtilStringUtil.h 
 * @brief		This is the header file for the %StringUtil class.
 *
 * This header file contains the declarations of the %StringUtil class.
 */
#ifndef _FBASE_UTIL_STRING_UTIL_H_
#define _FBASE_UTIL_STRING_UTIL_H_

//Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FBaseBuffer.h"
#include "FBaseResult.h"

namespace Osp { namespace Base { namespace Utility {
/**
 * @class	StringUtil
 * @brief	This class provides various utility methods for String.
 * @since	1.0
 * 
 * The %StringUtil class provides various utility methods for String.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %StringUtil class.
 *
 * @code
 *	// includes
 *	#include <FBase.h>
 *
 *	// namespace
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *
 *	void
 *	MyClass::StringUtilSample(void)
 *	{
 *		String str1(L"Sigma and Pi : \u03A0 and \u03A3");
 *		String str2;
 *		
 *		// String to McharBuffer
 *		McharBuffer* pMb = StringUtil::StringToMbN(str1);
 *
 *
 *		// Get a length of string in McharBuffer
 *		int length = StringUtil::GetStringLengthInMb(*pMb);
 *
 *
 *		// McharBuffer to String
 *		StringUtil::MbToString(*pMb, str2);
 *
 *		if (str1.Equals(str2))		// true
 *		{
 *			...
 *		}
 *
 *		delete pMb;
 *	}
 * @endcode
 */
class	_EXPORT_BASE_ StringUtil
{
// Operations (Static)
public:
	/**
	 * Converts an McharBuffer to a null-terminated string. @n
	 * The position of the buffer is not changed.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		mb		An %McharBuffer instance
	 * @param[out]		str		The current position
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid, or
	 *									@c null does not exist between the position and limit of buffer.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see					StringToMbN(), Osp::Base::McharBuffer
	 */
	static result MbToString(const McharBuffer& mb, String& str);

	/**
	 * Gets a new McharBuffer from the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since				1.0
	 * @return			A pointer to the %McharBuffer instance from the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to be read
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see					MbToString(), Osp::Base::McharBuffer
	 */
	 static McharBuffer* StringToMbN(const String& str);

	/**
	 * Gets a new McharBuffer from a substring of the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since				1.0
	 * @return			A pointer to the %McharBuffer instance from the substring of the specified string, @n
	 *					else @c null if an exception occurs
	 * @param[in]		str		The string to be read
	 * @param[in]		index	The starting index for the substring in the string @n
	 *							It must not be longer than the length of the string.
	 * @param[in]		length	The length of the substring @n
	 *							It must not be longer than the length of the given string minus the specified @c index.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified @c str is an empty string.
	 * @exception		E_OUT_OF_RANGE		The @c index and @c length are outside the bounds of the data structure.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see					MbToString(), Osp::Base::McharBuffer
	 */
	 static McharBuffer* StringToMbN(const String& str, int index, int length);


	/**
	 * Gets the string length in the McharBuffer. @n
	 * The string length is the length from the current position of the %McharBuffer to the @c null character.
	 * The position of the buffer is not changed.
	 *
	 * @since				1.0
	 * @return			The length of the %McharBuffer instance, @n
	 *					else @c -1 if the %McharBuffer instance is not terminated with the @c null character
	 * @param[in]		mb		An %McharBuffer instance
	 * @remarks			If @c null does not exist between the position and the limit of the buffer, the method returns @c -1.
	 * @see					Osp::Base::McharBuffer
	 */
	static int GetStringLengthInMb(const McharBuffer& mb);

	/**
	 * Gets a new ByteBuffer encoded from the specified string. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since				1.0
	 * @return			A pointer to the %ByteBuffer instance encoded from the specified string, @n
	 * 					else @c null if an exception occurs
	 * @param[in]		unicodeString	A string to encode
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see					Osp::Base::ByteBuffer, Osp::Base::String
	 */
	static ByteBuffer* StringToUtf8N(const String& unicodeString);


	/**
	 * Decodes a null-terminated UTF-8 string into a Unicode string. @n
	 * The position of the buffer is not changed.
	 * 
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		pUtf8String		A pointer to a String instance containing UTF-8 codes
	 * @param[out]		unicodeString	A string containing Unicode characters
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				@c pUtf8String is a @c null reference.
	 * @exception		E_INVALID_ENCODING_RANGE	The indicated string contains UTF-8 code that is outside the bounds specified by the character encoding scheme. 
	 * @exception		E_OUT_OF_MEMORY				The memory is insufficient.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *	
	 *	 const char* pUtf8String = "Utf8ToString";
	 *
	 *	 String str;
	 *
	 *	 // Decodes a UTF-8 string into a Unicode string
	 *	 StringUtil::Utf8ToString(pUtf8String, str);
	 *
	 * @endcode
	 */
	static result Utf8ToString(const char* pUtf8String, String& unicodeString);

	
	/**
	 * Decodes a string consisting of base 64 digits to a ByteBuffer. @n
	 * The buffer's limit is the length of the string plus one and the starting position is @c 0.
	 *
	 * @since				1.2
	 *
	 * @return			A pointer to the %ByteBuffer instance decoded from the specified string, @n
	 * 					else @c null if an exception occurs
	 * @param[in]		base64String	A string to decode
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid. @n
	 *										The specified @c base64String is not a valid Base64 string.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 *
	 * The following example demonstrates how to use the DecodeBase64StringN() method.
	 *
	 * @code
	 *
	 *	const char* pChar = "abcdefg123456";
	 *	int size = strlen(pChar);
	 *
	 *	String encodedStr;
	 *	ByteBuffer buffer;
	 *	buffer.Construct(size + 1);
	 *
	 *	buffer.SetArray((byte*)pChar, 0, size);
	 *	buffer.SetByte('\0');
	 *	buffer.Flip();
	 *
	 *	StringUtil::EncodeToBase64String(buffer, encodedStr);
	 *
	 *	// Decodes a String consisting of base 64 digits to a ByteBuffer
	 *	ByteBuffer* pDecodedBuffer = StringUtil::DecodeBase64StringN(encodedStr);
	 *
	 * @endcode
	 */
	static ByteBuffer* 	DecodeBase64StringN(const String& base64String);


	/**
	 * Encodes a ByteBuffer into a string consisting of base 64 characters. @n
	 * The position of the buffer is not changed.
	 *
	 * @since				1.2
	 *
	 * @return			An error code
	 * @param[in]		buffer			A %ByteBuffer instance to encode
	 * @param[out]		encodedString	A String instance consisting of base 64 characters
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid, or
	 *										the @c buffer is empty.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 * The following example demonstrates how to use the EncodeToBase64String() method.
	 *
	 * @code
	 *
	 *	const char* pChar = "abcdefg123456";
	 *	int size = strlen(pChar);
	 *
	 *	String encodedStr;
	 *	ByteBuffer buffer;
	 *	buffer.Construct(size + 1);
	 *
	 *	buffer.SetArray((byte*)pChar, 0, size);
	 *	buffer.SetByte('\0');
	 *	buffer.Flip();
	 *
	 *	// Encodes a ByteBuffer into a String consisting of base 64 characters
	 *	StringUtil::EncodeToBase64String(buffer, encodedStr);
	 *
	 * @endcode
	 */
	static result EncodeToBase64String(const ByteBuffer& buffer, String& encodedString);

	
// life-cycle
private:
	/**
	 * This is the default constructor for this class.
	 */
	StringUtil(void);

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since				1.0
	 */
	virtual ~StringUtil(void);


};
}; };  }; // Osp::Base::Utility
#endif // _FBASE_UTIL_STRING_UTIL_H_

