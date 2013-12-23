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
 * @file		FTextGsmEncoding.h 
 * @brief		This is the header file for the %GsmEncoding class.
 *
 * This header file contains declarations of the %GsmEncoding class.
 * This class is derived from the %Encoding class. 
 */
#ifndef _FTEXT_GSM_ENCODING_H_
#define _FTEXT_GSM_ENCODING_H_

// Include
#include "FTextEncoding.h"

namespace Osp { namespace Text {

/**
 * @class	GsmEncoding
 * @brief	This class is an implementation of the GSM character encoding.
 * @since	1.0
 *    
 * The %GsmEncoding class is an implementation of the GSM character encoding.
 * The Global System for Mobile Communications (GSM) consists of 128 European characters. It supports a 7-bit
 * default alphabet extension table for encoding. It is a target-dependent encoding type.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %GsmEncoding class.

 *
 *	@code
 *	// Includes
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	// Namespace
 *	using namespace Osp::Base;
 *	using namespace Osp::Text;
 *
 *	void
 *	MyClass::GsmEncodingSample(void)
 *	{
 *		GsmEncoding gsm;
 *
 *		String str(L"GSM Encoding test");
 *
 *
 *		int byteCount;
 *		gsm.GetByteCount(str, byteCount);
 *
 *		// Encoding
 *		ByteBuffer* pBuffer = gsm.GetBytesN(str);
 *
 *
 *		int charCount;
 *		gsm.GetCharCount(*pBuffer, charCount);
 * 
 *		// Decoding
 *		String decodedStr;
 *		gsm.GetString(*pBuffer, decodedStr);
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


class  _EXPORT_TEXT_ GsmEncoding :
	public Encoding

{
// Lifecycle
public:
	/** 
 	 * This is the default constructor for this class.
 	 *
 	 * @since	1.0
	 *
	 */
	GsmEncoding(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~GsmEncoding(void);

// Operations
public:
	/** 
	 * Calculates the total number of bytes that are required to encode a specified %String instance.
   *
   * @since			1.0
 	 * @return		An error code 
	 * @param[in]	str                     A string to encode
	 * @param[out]  byteCount               The total number of bytes required to encode the specified string
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes 
	 *              that are generated when the specified string is encoded.
   *          
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::String& str, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are required to encode a specified McharBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code 
	 * @param[in]	chars                 An instance of McharBuffer that is to be encoded
	 * @param[out]  byteCount             The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
   * @exception	E_INVALID_ENCODING_RANGE  The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters is encoded.  	
   *          
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are required to encode a range of characters in the specified McharBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code               
	 * @param[in]	chars          An instance of McharBuffer that is to be encoded
	 * @param[in]	charIndex The index from where encoding begins in the McharBuffer instance
         * @param[in]   charCount        The total number of characters to encode 
	 * @param[out]  byteCount      The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.  	
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters is encoded.  		
   *          
	 * @see			GetMaxByteCount() 
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, int& byteCount) const;

	/** 
	 * Encodes an instance of the specified McharBuffer into an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	chars                An instance of McharBuffer that is to be encoded
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c chars is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		 The pointer to the %ByteBuffer instance is not terminated by a @c null character.
	 *
	 * @see			GetCharsN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars) const;

	/** 
	 * Encodes an instance of the specified %String into an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	str                  A string to encode
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c str is invalid or empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The pointer to the %ByteBuffer instance is not terminated by a @c null character.
   * 
	 * @see			GetString()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::String& str) const;

	/** 
	 * Encodes an instance of McharBuffer into an instance of %ByteBuffer as per the specified range. @n
	 * The position and limit of the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars                An instance of McharBuffer that is to be encoded
	 * @param[in]	charIndex The index from where encoding begins in the McharBuffer instance 
     * @param[in]   charCount                 The total number of characters to encode
	 * @param[out]  bytes                     The %ByteBuffer instance where the resultant encoded string is stored
     * @param[in]   byteIndex                 The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 
	 * @remarks     This method encodes a range of characters in McharBuffer into a range of bytes in %ByteBuffer.  	
   *          
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/** 
	 * Encodes an instance of %String into an instance of %ByteBuffer as per the specified range. @n
	 * The position and limit of the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
 	 * @param[in]	str                   A string to encode 
	 * @param[in]	charIndex             The index from where encoding begins in the McharBuffer instance 
   * @param[in]   charCount               The total number of characters to encode
	 * @param[out]  bytes                  The %ByteBuffer instance where the resultant encoded string is stored
   * @param[in]   byteIndex               The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE		 	 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetString()
	 */
	virtual result GetBytes(const Osp::Base::String& str, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex = 0) const;

	/** 
	 * Calculates the total number of characters that are generated by decoding an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes              An instance of %ByteBuffer that is to be decoded
	 * @param[out]  charCount          The total number of characters that are generated by decoding the specified %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters 
	 *              that are generated when the specified range of bytes are decoded.
   *          
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int& charCount) const;

	/** 
	 * Calculates the total number of characters that are generated by decoding a range of elements specified in the %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes             An instance of %ByteBuffer that is to be decoded 
	 * @param[in]   byteIndex          The index from where decoding begins
	 * @param[in]   byteCount         The total number of bytes to decode
	 * @param[out]  charCount         The total number of characters that are generated by decoding the specified %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	  The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW               This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters 
	 *              that are generated when the specified range of bytes are decoded.  	
   *          
	 * @see			GetMaxCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/** 
	 *  Decodes an instance of %ByteBuffer into an instance of McharBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the McharBuffer instance where the resultant decoded data is stored, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last decoded byte plus one and the starting position is zero.
	 * @param[in]	bytes                An instance of %ByteBuffer that is to be decoded 
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is invalid or is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetBytesN()
	 */
	virtual Osp::Base::McharBuffer* GetCharsN(const Osp::Base::ByteBuffer& bytes) const;

	/** 
	 * Decodes an instance of %ByteBuffer into an instance of McharBuffer as per the specified range. @n
	 * The position and limit of the McharBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                  An instance of %ByteBuffer that is to be decoded 
	 * @param[in]   byteIndex              The index from where decoding begins
	 * @param[in]   byteCount              The total number of bytes to decode
	 * @param[out]  chars                  The McharBuffer instance where the resultant decoded data is stored
	 * @param[in]   charIndex              The index from where encoding begins in the McharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes or @c chars is empty.
	 * @exception	E_OUT_OF_RANGE	     	 The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes. 
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytes()
	 */
	virtual result GetChars(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, 
		Osp::Base::McharBuffer& chars, int charIndex = 0) const;

	/** 
	 * Gets a string containing the decoded representation of the specified %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes               An instance of %ByteBuffer that is to be decoded
	 * @param[out]  str                 A %String instance @n   
	 *                                  It contains the decoded representation of the specified %ByteBuffer instance. 
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytesN()
	 */
	virtual result GetString(const Osp::Base::ByteBuffer& bytes, Osp::Base::String& str) const;

	/** 
	 * Gets a string containing the decoded representation of the specified %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                      An instance of %ByteBuffer that is to be decoded
	 * @param[in]   index                      The index from where decoding begins
	 * @param[in]   count                      The total number of bytes to decode
	 * @param[out]  str                        A %String instance @n  
	 *                                         It contains the decoded representation of the specified %ByteBuffer instance. 
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE       	 The value of an argument is outside the valid range defined by the method, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytes()
	 */
	 virtual result GetString(const Osp::Base::ByteBuffer& bytes, int index, int count, Osp::Base::String& str) const;


	/** 
	 * Gets the maximum number of bytes required for encoding the specified number of characters.
	 *
	 * @since			1.0
	 * @return		The maximum number of bytes required for encoding the specified number of characters
	 * @param[in]	charCount    The total number of characters to encode
   * @remarks   This method determines an appropriate buffer size for the byte arrays passed to the GetBytes() method for encoding.  	
   *          
	 *
	 * @see			GetByteCount(), GetBytes() 
	 */
	 virtual int GetMaxByteCount(int charCount) const;


	 /** 
	 * Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	 *
	 * @since			1.0
	 * @return		The maximum number of characters that are generated by decoding the specified number of bytes
	 * @param[in]	byteCount The total number of bytes to encode
	 * @remarks   This method determines an appropriate buffer size for character arrays passed to 
	 *	          the GetChars() method or a decoder for encoding. 
	 *          
	 * @see				GetByteCount(), GetChars()
	 */
	 virtual int GetMaxCharCount(int byteCount) const;


	/** 
	 * Gets an encoder for the current encoding. 
	 *
	 * @since				1.0
	 * @return			A pointer to the %Encoder instance for the current encoding  
	 * @remarks     Contrary to GetBytes(), an encoder converts partial sequences of characters into 
	 *              partial sequences of bytes by maintaining the appropriate state between the conversions.
	 *              Currently only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 *
	 * @see			GetBytes() 
	 */
	virtual Encoder* GetEncoderN(void) const;

	/** 
	 * Gets a decoder for the current encoding 
	 *
	 * @since				1.0
	 * @return			A pointer to the %Decoder instance for the current encoding
	 * @remarks     Contrary to GetChars(), a decoder converts partial sequences of bytes 
	 *              into partial sequences of characters by maintaining the appropriate state between the conversions.
	 *              Currently only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 *
	 * @see			GetChars() 
	 */
	virtual Decoder* GetDecoderN(void) const;

private:
	friend class GsmEncodingEx;
	class GsmEncodingEx* __pGsmEncodingEx;
};


} }// Osp::Text
#endif//_FTEXT_GSM_ENCODING_H_
