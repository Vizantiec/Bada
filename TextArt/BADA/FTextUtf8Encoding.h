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
 * @file		FTextUtf8Encoding.h 
 * @brief		This is the header file for the %Utf8Encoding class.
 *
 * This header file contains the declarations of the %Utf8Encoding class.
 * This class is derived from the %Encoding class.
 */
#ifndef _FTEXT_UTF8_ENCODING_H_
#define _FTEXT_UTF8_ENCODING_H_

// include
#include "FTextEncoding.h"
#include "FTextUtf8Encoder.h"
#include "FTextUtf8Decoder.h"


namespace Osp { namespace Text {

/**
 * @class	Utf8Encoding
 * @brief	This class is an implementation of the UTF-8 encoding.
 * @since	1.0
 *	
 * The %Utf8Encoding class is an implementation of the UTF-8 encoding.
 * Universal Transformation Format-8 (UTF-8) is a translated language used on the internet. It converts Unicode to 8-bit bytes. UTF-8 encoding supports all the Unicode character values and surrogates.
 * 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %Utf8Encoding class.

 *
 * 	@code
 *	// includes
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	// namespace
  *	using namespace Osp::Base;
 *	using namespace Osp::Text;
 *
 *	void
 *	MyClass::Utf8EncodingSample(void)
 *	{
 *		Utf8Encoding utf8;
 *
 *	 	String str(L"(\u03a0) and (\u03a3)"); 
 *
 *
 *		int byteCount;
 *		utf8.GetByteCount(str, byteCount);
 *
 *		// Encoding
 *		ByteBuffer* pBuffer = utf8.GetBytesN(str);
 *
 *
 *		int charCount;
 *		utf8.GetCharCount(*pBuffer, charCount);
 *
 *		// Decoding
 *		String decodedStr;
 *		utf8.GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))		// true
 *		{
 *			....
 *		}
 *
 *		delete pBuffer;
 *
 *	}
 * @endcode
 *
 */


class _EXPORT_TEXT_ Utf8Encoding :
	public Encoding
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Utf8Encoding(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Utf8Encoding(void);

// Operations
public:
	/** 
	 * Calculates the total number of bytes that are generated by encoding an instance of specified string.
	 * This method determines the total number of bytes that are generated when the specified string is encoded.
   *
   * @since			1.0
	 * @return		An error code 
	 * @param[in]	str                       The string to encode 
	 * @param[out]  byteCount                 The total number of bytes required to encode the string
	 * @exception	E_SUCCESS                 The method is successful.
	 * @exception	E_INVALID_ARG             A specified input parameter is invalid, or 
	 *                                        the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme. 
	 *                                        
   *          
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::String& str, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are generated by encoding an instance of specified McharBuffer.
	 * GetByteCount() can be used to determine the exact number of bytes
	 * produced if the given array of characters is encoded.  
	 *
	 * @since			1.0
	 * @return		An error code 
	 * @param[in]	chars                 An instance of McharBuffer that is to be encoded 
	 * @param[out]  byteCount              The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c chars is empty.
   * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 
	 *                                         
   *          
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are required to encode a range of characters in the specified McharBuffer instance.

	 * This method determines the total number of bytes that are generated when the specified array of characters is encoded.
	 *
	 * @since			1.0
	 * @return		An error code               
	 * @param[in]	chars                    An instance of McharBuffer that is to be encoded 
	 * @param[in]	charIndex                The index from where encoding begins in the McharBuffer instance 
   * @param[in]   charCount                  The total number of characters to encode 
	 * @param[out]  byteCount                 The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.  	
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                       the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		  	 The value of an argument is outside the valid range defined by the method, or
	 *										  the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or 
	 *										   the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
   *          
	 * @see			GetMaxByteCount() 
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, int& byteCount) const;

	/** 
	 * Encodes an instance of specified McharBuffer into an instance of %ByteBuffer.
	 * @since			1.0
	 * @return		                        A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
     *                                      else @c null if an exception occurs @n
	 *						                The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	chars                   An instance of McharBuffer that is to be encoded 
   * @exception	E_SUCCESS                   The method is successful.
	 * @exception	E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_INVALID_ARG           The specified @c chars is empty or invalid.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 
	 *                                         
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetCharsN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars) const;

	/** 
	 * Encodes an instance of specified %String into an instance of %ByteBuffer
	 * @since			1.0
	 * @return		                        A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
     *                                      else @c null if an exception occurs @n
	 *						                The buffer limit is the position of the last encoded byte plus one and the starting position is zero
 	 * @param[in]	str                     A string to encode
   * @exception	E_SUCCESS                   The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                        
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
   * 
	 * @see			GetString()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::String& str) const;

	/** 
	 * Encodes an instance of McharBuffer into an instance of %ByteBuffer as per the specified range. @n
	 * The position and limit of the pointer to the %ByteBuffer instance is not changed.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars                     An instance of McharBuffer that is to be encoded 
	 * @param[in]	charIndex                 The index from where encoding begins in the McharBuffer instance 
     * @param[in]   charCount                   The total number of characters to encode
	 * @param[out]  bytes                     The %ByteBuffer instance where the resultant encoded string is stored
     * @param[in]   byteIndex                 The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE      	 The value of an argument is outside the valid range defined by the method, or
	 *                                       the @c charIndex or @c charCount is greater than the length of @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *                                         the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or 
	 *                                        the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
   *          
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/** 
	 * Encodes an instance of %String into an instance of %ByteBuffer as per the specified range.
	 * The position and limit of the pointer to the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
 	 * @param[in]	str                          A string to encode 
	 * @param[in]	charIndex                    The index from where encoding begins in the McharBuffer instance
   * @param[in]   charCount                      The total number of characters to encode
	 * @param[out]  bytes                        The %ByteBuffer instance where the resultant encoded string is stored
   * @param[in]   byteIndex                      The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE		 	 The value of an argument is outside the valid range defined by the method, or
	 *                                         the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or
	 *										   the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
	 *
	 * @see			GetString()
	 */
	virtual result GetBytes(const Osp::Base::String& str, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/** 
	 * Calculates the total number of characters that are generated by decoding an instance of %ByteBuffer.
	 * The GetCharCount() method can be used to determine the exact the number of characters 
	 * produced if the given range of bytes is converted. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[out]  charCount                The total number of characters that are generated by decoding the specified %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
	 *          
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int& charCount) const;

	/** 
	 * Calculates the total number of characters that are generated by decoding a range of elements specified in the %ByteBuffer instance.
	 * The GetCharCount() method can be used to determine the exact the number of characters 
	 * produced if the given range of bytes is converted. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                         An instance of %ByteBuffer that is to be decoded
	 * @param[in]   byteIndex                    The index from where decoding begins
	 * @param[in]   byteCount                     The total number of bytes to decode
	 * @param[out]  charCount                 The total number of characters that are generated by decoding the specified %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                       the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE        The value of an argument is outside the valid range defined by the method, or 
	 *										   the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *								          the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
   *          
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/** 
	 * Decodes an instance of specified %ByteBuffer into an instance of McharBuffer.
	 * @since			1.0
	 * @return		              A pointer to the McharBuffer instance where the resultant decoded data is stored, @n
     *                                      else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last decoded byte plus one and the position is zero.
	 * @param[in]	bytes                  An instance of %ByteBuffer that is to be decoded
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is empty or invalid.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetBytesN()
	 */
	virtual Osp::Base::McharBuffer* GetCharsN(const Osp::Base::ByteBuffer& bytes) const;

	/** 
	 * Decodes an instance of %ByteBuffer into an instance of McharBuffer as per the specified range. @n
	 * The position and limit of the pointer to the McharBuffer instance is not changed.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[in]   byteIndex                The index from where decoding begins
	 * @param[in]   byteCount                The total number of bytes to decode
	 * @param[out]  chars                    The McharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex                The index from where encoding begins in the McharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c bytes or @c chars is empty.
	 * @exception	E_OUT_OF_RANGE	         The value of an argument is outside the valid range defined by the method, or
	 *									       the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes. 
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or
	 *										   the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
	 *
	 * @see			GetBytes()
	 */
	virtual result GetChars(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, 
		Osp::Base::McharBuffer& chars, int charIndex = 0) const;

	/** 
	 * Gets a string containing the decoded representation of the specified %ByteBuffer instance.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[out]  str                        A %String instance @n                                                              
	                                           It contains the decoded representation of the specified %ByteBuffer instance. 
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                       the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                        
	 *
	 * @see			GetBytesN()
	 */
	virtual result GetString(const Osp::Base::ByteBuffer& bytes, Osp::Base::String& str) const;

	/** 
	 * Gets a string containing the decoded representation of the specified %ByteBuffer instance.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[in]   index                    The index from where decoding begins
	 * @param[in]   count                    The total number of bytes to decode
	 * @param[out]  str                      A %String instance @n                                                              
	                                         It contains the decoded representation of the specified %ByteBuffer instance. 
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                        the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	 The value of an argument is outside the valid range defined by the method, or
	 *										  the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or
	 *										 the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                        
	 *
	 * @see			GetBytes()
	 */
	 virtual result GetString(const Osp::Base::ByteBuffer& bytes, int index, int count, Osp::Base::String& str) const;


	/** 
	 * Gets the maximum number of bytes required for encoding a given number of characters.
	 *
	 * @since			1.0
	 * @return		The maximum number of bytes required for encoding a given number of characters
	 * @param[in]	charCount The total number of characters to encode
  * @remarks     GetMaxByteCount() can be used to determine an appropriate buffer size for the byte arrays passed to the GetBytes() method for encoding.  	
   *          
	 *
	 * @see			GetByteCount(), GetBytes() 
	 */
	 virtual int GetMaxByteCount(int charCount) const;


	 /** 
	 * Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	 *
	 * @since				1.0
	 * @return			The maximum number of characters generated by decoding the specified number of bytes
	 * @param[in]		byteCount The total number of bytes to encode
	 * @remarks     This method can be used to determine an appropriate buffer size for the character arrays passed to 
	 *	            GetChars() or a decoder for encoding. 
	 *          
	 * @see			GetCharCount(), GetChars()
	 */
	 virtual int GetMaxCharCount(int byteCount) const;


	/** 
	 * Gets the encoder for the current encoding. 
	 *
	 * @since				1.0
	 * @return			A pointer to the %Encoder instance for the current encoding  
	 * @remarks     Contrary to GetBytes(), an encoder can convert partial sequences of characters into 
	 *              partial sequences of bytes by maintaining the appropriate states between the conversions.
	 *
	 * @see			GetBytes() 
	 */
	virtual Encoder* GetEncoderN(void) const;

	/** 
	 * Gets the decoder for the current encoding.
	 *
	 * @since				1.0
	 * @return			A pointer to the %Decoder instance for the current encoding 
	 * @remarks     Contrary to the GetChars() methods, a decoder can convert partial sequences of bytes 
	 *              into partial sequences of characters by maintaining the appropriate states between the conversions.
	 *
	 * @see			GetChars() 
	 */
	virtual Decoder* GetDecoderN(void) const;

private:

	friend class Utf8Decoder;

	friend class Utf8EncodingEx;
	class Utf8EncodingEx* __pUtf8EncodingEx;
};

} }// Osp::Text
#endif//_FTEXT_UTF8_ENCODING_H_
