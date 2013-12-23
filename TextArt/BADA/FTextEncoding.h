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
 * @file		FTextEncoding.h 
 * @brief		This is the header file for the %Encoding class.
 *
 * This header file contains the declarations of the %Encoding class. 
 * This class is the base class for all character encoding classes. 
 */
#ifndef _FTEXT_ENCODING_H_
#define _FTEXT_ENCODING_H_

// Include
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseBuffer.h"
#include "FBaseColIList.h"

#include "FTextEncoder.h"
#include "FTextDecoder.h"

namespace Osp { namespace Text  {


/**
 * @class	Encoding
 * @brief	This class implements character encoding.
 * @since	1.0
 *
 * The %Encoding class is the base class for all classes that implement character encoding.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/converting_all_text_data.htm">Converting All Text Data at Once</a>.
 *
 * The following example demonstrates how to use the %Encoding class.
 *
 *	@code
 *	// includes
 *	#include <FBase.h>
 *	#include <FText.h>
 *
 *	// namespace
 *	using namespace Osp::Base;
 *	using namespace Osp::Text;
 *
 *	void
 *	MyClass::EncodingSample(void)
 *	{
 *		Encoding* pEnc = Encoding::GetEncodingN(L"ISO-8859-2");
 *
 *		String str(L"Encoding Test \u00A1\u00A2");
 *
 *
 *		int byteCount;
 *		pEnc->GetByteCount(str, byteCount);
 *
 *		// Encoding
 *		ByteBuffer* pBuffer = pEnc->GetBytesN(str);
 *
 *
 *		int charCount;
 *		pEnc->GetCharCount(*pBuffer, charCount);
 *
 *		// Decoding
 *		String decodedStr;
 *		pEnc->GetString(*pBuffer, decodedStr);
 *
 *		if (str.Equals(decodedStr))		// true
 *		{
 *			....
 *		}
 *
 *		delete pBuffer;
 *
 *		delete pEnc;
 *
 *	}
 * 	@endcode
 */


//Forward declarations
class AsciiEncoding;
class Utf8Encoding;
class Ucs2Encoding;
class Latin1Encoding;
class GsmEncoding;

class  _EXPORT_TEXT_ Encoding :
	public Osp::Base::Object
{
// Lifecycle
public:

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Encoding(void);

// Operations
public:

	/** 
	 * Calculates the total number of bytes that are required to encode the specified string.
   *
   * @since			1.0
	 * @return		An error code 
	 * @param[in]	str                      The string to encode
	 * @param[out]  byteCount                The total number of bytes that are required to encode the specified string
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes 
	 *              that are generated when the specified string is encoded.
   *          
	 * @see	        GetMaxByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::String& str, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are required to encode the specified characters.
	 *
	 * @since			1.0
	 * @return		An error code 
	 * @param[in]	chars                    An instance of McharBuffer that is to be encoded
	 * @param[out]  byteCount                The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars is empty.
     * @exception	E_INVALID_ENCODING_RANGE    The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes 
	 *              that are generated when the specified array of characters are encoded.  	
   *          
	 * @see	        GetMaxByteCount(), GetByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int& byteCount) const;

	/** 
	 * Calculates the total number of bytes that are required to encode a range of characters in the specified McharBuffer instance.
	 * @since			1.0
	 * @return		An error code               
	 * @param[in]	chars                An instance of McharBuffer that is to be encoded
	 * @param[in]	charIndex            The index from where encoding begins in the McharBuffer instance 
   * @param[in]   charCount              The total number of characters to encode 
	 * @param[out]  byteCount            The total number of bytes that are required to encode the specified range of characters
	 * @exception	E_SUCCESS            The method is successful.  	
	 * @exception	E_INVALID_ARG        A specified input parameter is invalid, or the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW          This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of bytes
	 *              that are generated when the specified array of characters are encoded.  		
     *          
	 * @see			GetMaxByteCount(), GetByteCount()
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		int& byteCount) const;

	/** 
	 *  Encodes an instance of specified McharBuffer into an instance of %ByteBuffer.
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the starting position is zero.
 	 * @param[in]	chars                An instance of McharBuffer that is to be encoded
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c chars is invalid or is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetCharsN(), GetBytesN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars) const = 0;

	/** 
	 * Encodes the specified string of type String to %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last encoded byte plus one and the position is zero.
 	 * @param[in]	str                  The string to encode
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c str is invalid or is an empty string.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * 
	 * @see			GetString()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::String& str) const = 0;

	/** 
	 * Encodes an instance of specified McharBuffer into an instance of %ByteBuffer as per the specified range.
	 * The position and limit of the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars                  The buffer containing the character array that is to be encoded
	 * @param[in]	charIndex              The index from where encoding begins in the McharBuffer instance 
   * @param[in]   charCount                The total number of characters to encode
	 * @param[out]  bytes                  The %ByteBuffer instance where the resultant encoded string is stored
   * @param[in]   byteIndex                The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c chars or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes do not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 
	 * @remarks     This method encodes a range of characters in McharBuffer into a range of bytes in %ByteBuffer.  	
   *          
	 * @see			GetChars()
	 */
	virtual result GetBytes(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex) const = 0;

	/** 
	 * Encodes an instance of %String into an instance of %ByteBuffer as per the specified range.
	 * The position and limit of the %ByteBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
 	 * @param[in]	str                     The string to encode 
	 * @param[in]	charIndex               The index from where encoding begins in the McharBuffer instance 
   * @param[in]   charCount                 The total number of characters to encode
	 * @param[out]  bytes                   The %ByteBuffer instance where the resultant encoded string is stored
   * @param[in]   byteIndex                 The starting index of the resultant encoding in the %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c str or @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE			 The value of an argument is outside the valid range defined by the method, or the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c str.
	 * @exception	E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 * @exception	E_OVERFLOW               This operation has caused the memory to overflow, or the specified @c bytes does not contain sufficient space to store the encoded characters.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetString()
	 */
	virtual result GetBytes(const Osp::Base::String& str, int charIndex, int charCount, 
		Osp::Base::ByteBuffer& bytes, int byteIndex) const = 0;

	/** 
	 * Calculates the total number of characters that are generated by decoding an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[out]  charCount                The total number of characters that are generated by decoding a range of bytes in the specified %ByteBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters 
	 *              that are generated when the specified range of bytes are encoded. 	
   *          
	 * @see			GetMaxCharCount(), GetCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int& charCount) const;

	/** 
	 * Calculates the total number of characters that are generated by decoding a range of elements specified in the %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                 An instance of %ByteBuffer that is to be decoded 
	 * @param[in]   byteIndex             The index from where decoding begins
	 * @param[in]   byteCount             The total number of bytes to decode
	 * @param[out]  charCount             The total number of characters that are generated by decoding a range of bytes in the specified %ByteBuffer instance
	 * @exception	E_SUCCESS             The method is successful.
	 * @exception	E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception	E_INVALID_ARG         A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE        The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW           This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks     This method determines the total number of characters 
	 *              that are generated when the specified range of bytes are encoded.  	
   *          
	 * @see			GetMaxCharCount(), GetCharCount()
	 */
	virtual result GetCharCount(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, int& charCount) const;

	/** 
	 * Decodes an instance of %ByteBuffer into an instance of McharBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the McharBuffer instance where the resultant decoded data is stored, @n
	 *				else @c null if an exception occurs @n
	 *				The buffer limit is the position of the last decoded byte plus one and the starting position is zero.
	 * @param[in]	bytes               An instance of %ByteBuffer that is to be decoded
   * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            The specified @c bytes is invalid or is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			GetBytesN(), GetCharsN()
	 */
	virtual Osp::Base::McharBuffer* GetCharsN(const Osp::Base::ByteBuffer& bytes) const = 0;

	/** 
	 * Decodes an instance of %ByteBuffer into an instance of McharBuffer as per the specified range. 
	 * The position and limit of the McharBuffer instance is not changed.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes                 An instance of %ByteBuffer that is to be decoded 
	 * @param[in]   byteIndex             The index from where decoding begins
	 * @param[in]   byteCount             The total number of bytes to decode
	 * @param[out]  chars                 The McharBuffer instance where the resultant decoded data is stored 
	 * @param[in]   charIndex             The index from where encoding begins in the McharBuffer instance
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE	         The value of an argument is outside the valid range defined by the method, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception	E_UNDERFLOW	             This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes. 
	 * @exception   E_OVERFLOW	             This operation has caused the memory to overflow, or the specified @c chars does not contain sufficient space to store the decoded bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytes(), GetChars()
	 */
	virtual result GetChars(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, 
		Osp::Base::McharBuffer& chars, int charIndex) const = 0;

	/** 
	 * Gets a string that contains the decoded representation of a range of bytes in the specified %ByteBuffer instance..
	 *
	 * @since			1.0
	 * @return		An error code 
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[out]  str                      A %String instance @n                                                              
	                                         It contains the decoded representation of the specified %ByteBuffer instance. 
     * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytesN(), GetString()
	 */
	virtual result GetString(const Osp::Base::ByteBuffer& bytes, Osp::Base::String& str) const = 0;

	/** 
	 * Gets a string that contains the decoded representation of a range of bytes in the specified %ByteBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code 
	 * @param[in]	bytes                    An instance of %ByteBuffer that is to be decoded
	 * @param[in]   index                    The index from where decoding begins
	 * @param[in]   count                    The total number of bytes to decode
	 * @param[out]  str                     A %String instance @n                                                              
	                                        It contains the decoded representation of the specified %ByteBuffer instance. 
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c bytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW				 This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c bytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 *
	 * @see			GetBytes(), GetString()
	 */
	virtual result GetString(const Osp::Base::ByteBuffer& bytes, int index, int count, Osp::Base::String& str) const = 0;

	/** 
	 * Gets the maximum number of bytes that are required to encode the specified number of characters.
	 *
	 * @since			1.0
	 * @return		The maximum number of bytes that are required to encode the specified number of characters
	 * @param[in]	charCount     The total number of characters to encode
   * @remarks     This method determines an appropriate buffer size for the byte arrays passed to the GetBytes() method for encoding.  	
   *          
	 * @see			GetByteCount(), GetBytes()
	 */
	virtual int GetMaxByteCount(int charCount) const = 0;

   /** 
	* Gets the maximum number of characters that are generated by decoding the specified number of bytes.
	*
	* @since		1.0
	* @return		The maximum number of characters that are generated by decoding the specified number of bytes
	* @param[in]	byteCount The total number of bytes to encode
	* @remarks      This method determines an appropriate buffer size for character arrays passed to 
	*	            GetChars() or a decoder for encoding.
    *          
	* @see			GetCharCount(), GetChars()
	*/
   virtual int GetMaxCharCount(int byteCount) const = 0;

	/** 
	 * Gets the encoder for the current encoding. 
	 *
	 * @since			1.0
	 * @return		A pointer to the %Encoder instance for the current encoding  
	 * @remarks     Contrary to GetBytes(), an encoder converts partial sequences of characters into 
	 *              partial sequences of bytes by maintaining an appropriate state between the conversions.
	 *              Currently, only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 *
	 * @see			GetBytes() 
	 */
	virtual Encoder* GetEncoderN(void) const = 0;

	/** 
	 * Gets the decoder for the current encoding.
	 *
	 * @since			1.0
	 * @return		A pointer to the %Decoder instance for the current encoding 
	 * @remarks     Contrary to GetChars(), a decoder converts partial sequences of bytes 
	 *              into partial sequences of characters by maintaining an appropriate state between the conversions.
	 *              Currently, only UTF-8 encoding supports this method. The other classes return a value of @c null.
	 *
	 * @see			GetChars() 
	 */
	virtual Decoder* GetDecoderN(void) const = 0;


// Static methods
public:

	/**
	 * Gets an encoding for the UTF-8 format.
	 *
	 * @since			1.0
	 * @return		An encoding for the UTF-8 format
   *
	 * @see				Osp::Text::Utf8Encoding
	 */
	static Utf8Encoding& GetUtf8Encoding(void);

	/**
	 * Gets an encoding for the UCS-2 format.
	 *
	 * @since			1.0
	 * @return		An encoding for the UCS-2 format
  -*
	 * @see				Osp::Text::Ucs2Encoding
	 */
	static Ucs2Encoding& GetUcs2Encoding(void);

	/**
	 * Gets an encoding for the GSM format.
	 *
	 * @since			1.0
	 * @return		An encoding for the GSM format
	 *
	 * @see				Osp::Text::GsmEncoding
	 */
	static GsmEncoding& GetGsmEncoding(void);

	/**
	 * Gets an encoding for the Latin1 format.
	 *
	 * @since			1.0
	 * @return		An encoding for the Latin1 format
	 *
	 * @see				Osp::Text::Latin1Encoding
	 */
	static Latin1Encoding& GetLatin1Encoding(void);


	/**
	 * Gets an encoding for the ASCII format.
	 *
	 * @since			1.0
	 * @return		An encoding for the ASCII format
   *
	 * @see				Osp::Text::AsciiEncoding
	 */
	static AsciiEncoding& GetAsciiEncoding(void);


	/**
	 * Gets an %Encoding instance from the specified encoding type.
	 *
	 * @since			1.0
	 * @return    An instance of %Encoding, @n
   *                else @c null if the method fails
	 * @param[in]	encodingType 	An encoding type @n
	 *								@b Since: @b 2.0 ISO-8859-5 ~ ISO-8859-16 (except ISO-8859-12), Windows-1250 ~ Windows-1253, and Windows-1257 are newly introduced.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_TYPE 		The specified encoding type is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see			Osp::Text::Encoding::GetAvailableEncodingsN()
	 */
	static Encoding* GetEncodingN(const Osp::Base::String& encodingType);


	/**
	 * Gets a list of all the available encodings.
	 *
	 * @since			1.0
	 * @return		A list of String instances (ASCII, UTF-8, ISO-8859-1, ISO-8859-2, Windows-1254, and so on), @n
	 * 				else @c null if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static Osp::Base::Collection::IList*  GetAvailableEncodingsN(void);


	/**
	 * Converts an instance of %ByteBuffer from one encoding format to another.
	 *
	 * @since			1.0
	 * @return		A new buffer for storing the result of the conversion, @n
	 *				else @c null if an exception occurs @n
	 *			    	The buffer limit is the position of the last converted byte plus one and the starting position is zero.
	 * @param[in]	src                      The source of the encoding
	 * @param[in]	dst                      The destination of the encoding
	 * @param[in]   srcBytes                 The %ByteBuffer instance where the resultant encoded string is stored
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c srcBytes is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
   *
	 * @see		    GetBytes(), GetChars()
	 */
	static Osp::Base::ByteBuffer* ConvertN(const Encoding& src, const Encoding& dst,
		const Osp::Base::ByteBuffer& srcBytes);

	/**
	 * Converts a range of bytes in the %ByteBuffer instance from one encoding format to another.
	 *
	 * @since			1.0
	 * @return		A new buffer for storing result of the conversion, @n
	 *				else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last converted byte plus one and the starting position is zero.
	 * @param[in]	src                      The source of the encoding
	 * @param[in]	dst                      The destination of the encoding
	 * @param[in]   srcBytes                 The %ByteBuffer instance where the resultant encoded string is stored
	 * @param[in]   index                    The starting index of the resultant encoding in the %ByteBuffer instance
     * @param[in]   count                    The total number of bytes to be converted
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or the specified @c srcBytes is empty.
	 * @exception	E_OUT_OF_RANGE           The value of an argument is outside the valid range defined by the method, or the specified @c index or @c count is greater than the length of the specified @c srcBytes.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or the sum of the length of the specified @c index and @c count is greater than the length of the specified @c srcBytes.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see		    GetBytes(), GetChars()
	 */
	static Osp::Base::ByteBuffer* ConvertN(const Encoding& src, const Encoding& dst, const Osp::Base::ByteBuffer& srcBytes,
		int index, int count);


protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the size of the string.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str				An instance of %String
	 * @param[out]	strSize			The size of the string
	 * @exception	E_SUCCESS		The method is successful.
 	 * @exception	E_INVALID_ARG   A specified input parameter is invalid.
	 */
	result GetStringSize(const Osp::Base::String& str, int& strSize) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the size of an instance of McharBuffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars			An instance of McharBuffer
	 * @param[out]	charBufSize	    The size of McharBuffer
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid.
	 */
	result GetBufferSize(const Osp::Base::McharBuffer& chars, int& charBufSize) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified characters are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars				An instance of McharBuffer
	 * @param[in]	charIndex			An index of McharBuffer
	 * @param[in]	charCount			The total number of McharBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars, or the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW         This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 */
	result CheckBufferInput(const Osp::Base::McharBuffer& chars, int charIndex, int charCount) const;


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified characters are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	chars				An instance of McharBuffer
	 * @param[in]	charIndex			An index of McharBuffer
	 * @param[in]	charCount			The count of McharBuffer
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[in]	byteIndex			An index of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars, or the specified @c charIndex, @c charCount, or @c byteIndex is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW         This operation has caused the memory to underflow, or the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 */
	result CheckBufferInput(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		const Osp::Base::ByteBuffer& bytes, int byteIndex) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified string is valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str					A String instance
	 * @param[in]	charIndex			An index of McharBuffer
	 * @param[in]	charCount			The count of McharBuffer
	 * @param[in]	bytes				A ByteBuffer instance
	 * @param[in]	byteIndex			An index of ByteBuffer
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 *									The @c charIndex or @c charCount or @c byteIndex is greater than the length of @c str.
	 * @exception   E_UNDERFLOW         This operation has caused an underflow. @n
	 *                                  The sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c str.
	 */
	result CheckStringInput(const Osp::Base::String& str, int charIndex, int charCount, 
		const Osp::Base::ByteBuffer& bytes, int byteIndex) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified bytes are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[out]  byteBufSize			The size of %ByteBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetBufferSize(const Osp::Base::ByteBuffer& bytes, int& byteBufSize) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified bytes are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[in]	byteIndex			An index of %ByteBuffer
	 * @param[in]	byteCount			The total number of bytes
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The specified @c charIndex or @c charCount is greater than the length of the specified @c chars, or the length of the specified @c byteIndex or @c byteCount is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW         This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 */
	result CheckBufferInput(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount) const;


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified bytes are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[in]	byteIndex			An index of %ByteBuffer
	 * @param[in]	byteCount			The total number of bytes
	 * @param[in]	chars				An instance of McharBuffer
	 * @param[in]	charIndex			An index of McharBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars, or the length of the specified @c byteIndex, @c byteCount, or @c byteIndex is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW         This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 */
	result CheckBufferInput(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount, 
		const Osp::Base::McharBuffer& chars, int charIndex) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the size of an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[out]	charBufSize			The size of McharBuffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result GetBufferSizeForString(const Osp::Base::ByteBuffer& bytes, int& byteBufSize) const;
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the specified bytes are valid.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bytes				An instance of %ByteBuffer
	 * @param[in]	byteIndex			An index of %ByteBuffer
	 * @param[in]	byteCount			The total number of bytes
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE      The length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars, or the length of the specified @c byteIndex, @c byteCount, or @c byteIndex is greater than the length of the specified @c bytes.
	 * @exception   E_UNDERFLOW         This operation has caused the memory to underflow, or the sum of the length of the specified @c byteIndex and @c byteCount is greater than the length of the specified @c bytes.
	 */
	result CheckBufferInputForString(const Osp::Base::ByteBuffer& bytes, int byteIndex, int byteCount) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Check the GSM exception table.
	 *
	 * @since			1.0
	 * @return		@c true, if the text was in the exception table @n
	 *				@c false, otherwise
	 * @param[in]	mszText				A text to check
	 */
	bool IsInGSMCodeExceptTable(mchar mszText) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Change GSM code to mc
	 *
	 * @since			1.0
	 * @return		@c true, if the change was successful @n
	 *				@c false, otherwise
	 * @param[in]	pDes				The destination of the text
	 * @param[in]	bufsize				The size of buffer
	 * @param[in]	pStr					The source of the text
	 * @param[in]	byteCount			The byte count to change
	 */
	bool GsmToMc(mchar* pDes, int bufsize, byte* pStr, int byteCount) const;


protected:

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int MAX_GSM_BYTE_COUNT =	2;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int tabGsmUniMax =			42;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int tabGsmUniMax2 =		10;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	typedef struct
	{
		char		gsm;			/**< @internal Internal variable */ 
		mchar	unicode;			/**< @internal Internal variable */ 
	}GsmUniTable;


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const GsmUniTable GsmTableUni[];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const GsmUniTable GsmTableUni2[];


private:
	friend class EncodingEx;
	class EncodingEx* __pEncodingEx;
}; // Encoding 

} } // Osp::Text

#endif//_FTEXT_ENCODING_H_
