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
 * @file		FTextLatin1Encoding.h 
 * @brief		This is the header file for the %Latin1Encoding class.
 *
 * This header file contains the declarations of the %Latin1Encoding class.
 * This class is derived from the %Encoding class.
 */
#ifndef _FTEXT_LATIN1_ENCODING_H_
#define _FTEXT_LATIN1_ENCODING_H_

// Include
#include "FTextEncoding.h"

namespace Osp { namespace Text {
/**
 * @class	Latin1Encoding
 * @brief	This class is an implementation of the Latin1 encoding.
 * @since	1.0
 *
 * The %Latin1Encoding class is an implementation of the Latin1 encoding.
 * ISO Latin-1 is a superset of the American Standard Code for Information Interchange(ASCII) character set and is very similar to the American National Standards Institute (ANSI) character set used in Windows, 
 * though the two are not identical.
 * Latin1 also serves as the basis for the ANSI character set of MS Windows.
 * Only the characters in ISO Latin-1 are guaranteed to be supported on an Internet website.
 * When a %Web browser, such as Internet Explorer or Firefox formats a %Web page on a client system, such as
 * Windows, it maps the ISO Latin-1 characters as best it can into the native character set.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>. 
 *
 *  The following example demonstrates how to use the %Latin1Encoding class.

 *
 * 	@code
 *	// Includes
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	// Namespace
 *	using namespace Osp::Base;
 *	using namespace Osp::Text;
 *
 *	void
 *	MyClass::Latin1EncodingSample(void)
 *	{
 *		Latin1Encoding latin1;
 *
 *		String str(L"Latin1Test \u00A1\u00A2");
 *
 *
 *		int byteCount;
 *		latin1.GetByteCount(str, byteCount);
 *
 *		// Encodes
 *		ByteBuffer* pBuffer = latin1.GetBytesN(str);
 *
 *
 *		int charCount;
 *		latin1.GetCharCount(*pBuffer, charCount);
 *
 *		// Decodes
 *		String decodedStr;
 *		latin1.GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))		// true
 *		{
 *			....
 *		}
 *
 *		delete pBuffer;
 *
 *	}
 * 	@endcode
 */


class _EXPORT_TEXT_ Latin1Encoding :
	public Encoding
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Latin1Encoding(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Latin1Encoding(void);

// Operations
public:
	/** 
	 * Encodes an instance of McharBuffer into an instance of %ByteBuffer.
	 * @since			1.0

	 * @return		                          A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
     *                                        else @c null if an exception occurs @n
	 *						                 The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	chars                    An instance of McharBuffer that is to be encoded
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c chars is empty or invalid.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetCharsN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars) const;

	/** 
	 * Encodes an instance of %String into an instance of %ByteBuffer.
	 * @since			1.0
	 * @return		                          A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
     *                                        else @c null if an exception occurs @n
	 *						                  The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	str                       A string to encode
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c str is empty or invalid.
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
	 * @exception	E_SUCCESS                 The method is successful.
	 * @exception	E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception	E_INVALID_ARG             A specified input parameter is invalid, or
	 *                                        the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	  The value of an argument is outside the valid range defined by the method, or
	 *                                        the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	              This operation has caused the memory to underflow, or
	 *                                        the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW                This operation has caused the memory to overflow, or
	 *                                        the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                          
	 * @remarks     This method encodes a range of characters in a McharBuffer into a range of bytes in a ByteBuffer.  	
   *          
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/**
	 * Encodes an instance of %String into an instance of %ByteBuffer as per the specified range. @n
	 * The position and limit of the pointer to the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
 	 * @param[in]	str                      A string to encode 
	 * @param[in]	charIndex                The index from where encoding begins in the McharBuffer instance 

   * @param[in]   charCount                  The total number of characters to encode
	 * @param[out]  bytes                    The ByteBuffer instance where the resultant encoded string is stored
   * @param[in]   byteIndex                  The starting index of the resultant encoding in the %ByteBuffer instance

	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE		 	 The value of an argument is outside the valid range defined by the method, or
	 *                                          the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or
	 *										   the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *                                         
	 *
	 * @see			GetString()
	 */
	virtual result GetBytes(const Osp::Base::String& str, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/** 
	 * Decodes an instance of %ByteBuffer into an instance of McharBuffer.
	 * @since			1.0
	 * @return		                        A pointer to the McharBuffer instance where the resultant decoded data is stored, @n
     *                                      else @c null if an exception occurs @n
	 *						                The buffer limit is the position of the last decoded byte plus one and the starting position is zero.
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                        the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 
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
	 * @param[in]	bytes                       An instance of %ByteBuffer that is to be decoded
	 * @param[in]   byteIndex                   The index from where decoding begins 
	 * @param[in]   byteCount                   The total number of bytes to decode
	 * @param[out]  chars                       The McharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex                    The index from where encoding begins in the McharBuffer instance   
	 * @exception	E_SUCCESS                   The method is successful.
	 * @exception	E_OUT_OF_MEMORY             The memory is insufficient.
	 * @exception	E_INVALID_ARG               A specified input parameter is invalid, or
	 *                                          the specified @c bytes or @c chars is empty.
	 * @exception	E_OUT_OF_RANGE	     	    The value of an argument is outside the valid range defined by the method, or
	 *									        the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	                This operation has caused the memory to underflow, or
	 *										    the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes. 
	 * @exception   E_OVERFLOW	               This operation has caused the memory to overflow, or
	 *										    the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
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
	 * @param[out]  str                      A %String instance @n                                                              
	                                         It contains the decoded representation of the specified %ByteBuffer instance. 
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c bytes is empty.
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
	 * @param[in]	bytes                       An instance of %ByteBuffer that is to be decoded 
	 * @param[in]   index                       The index from where decoding begins
	 * @param[in]   count                       The total number of bytes to decode
	 * @param[out]  str                         A %String instance @n                                                              
	                                            It contains the decoded representation of the specified %ByteBuffer instance. 
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or
	 *                                         the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	 The value of an argument is outside the valid range defined by the method, or
	 *										   the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
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
	  * @return			The maximum number of bytes required for encoding a given number of characters
	  * @param[in]	charCount The total number of characters to encode
	  * @remarks    GetMaxByteCount() can be used to determine an appropriate buffer size for the byte arrays passed to the GetBytes() method for encoding.
	  *
	  * @see		GetByteCount(), GetBytes()
	  */
	 virtual int GetMaxByteCount(int charCount) const;


	 /** 
	  * Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	  *
	  * @since			1.0
	  * @return			The maximum number of characters generated by decoding the specified number of bytes
	  * @param[in]	byteCount The total number of bytes to encode
	  * @remarks    This method can be used to determine an appropriate buffer size for character arrays passed to
	  *	            GetChars() or a decoder for encoding.
	  *
	  * @see		GetByteCount, GetChars()
	  */
	 virtual int GetMaxCharCount(int byteCount) const;


	/** 
	 * Gets the encoder for current encoding. 
	 *
	 * @since				1.0
	 * @return			A pointer to the %Encoder instance for the current encoding  
	 * @remarks     Contrary to GetBytes(), an Encoder can convert partial sequences of characters into 
	 *              partial sequences of bytes by maintaining the appropriate state between the conversions.
	 *              Currently only Utf8Encoding supports this method. Other classes return @c null.
	 *
	 * @see			GetBytes()
	 */
	virtual Encoder* GetEncoderN(void) const;

	/** 
	 * Gets the decoder for the current encoding.
	 *
	 * @since				1.0
	 * @return		A pointer to the %Decoder instance for the current encoding 
	 * @remarks     Contrary to the GetChars() methods, a Decoder can convert partial sequences of bytes 
	 *              into partial sequences of characters by maintaining the appropriate state between the conversions.
	 *              Currently only Utf8Encoding supports this method. Other classes return @c null.
	 *
	 * @see			GetChars() 
	 */
	virtual Decoder* GetDecoderN(void) const;

private:
	friend class Latin1EncodingEx;
	class Latin1EncodingEx* __pLatin1EncodingEx;
};


} }// Osp::Text
#endif//_FTEXT_LATIN1_ENCODING_H_
