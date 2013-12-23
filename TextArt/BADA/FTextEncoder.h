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
 * @file		FTextEncoder.h 
 * @brief		This is the header file for the %Encoder class.
 *
 * This header file contains the declarations of the %Encoder class.
 *  
 */
#ifndef _FTEXT_ENCODER_H_
#define _FTEXT_ENCODER_H_

// Include
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseBuffer.h"
#include "FTextConfig.h"


namespace Osp { namespace Text {
/**
 * @class	Encoder
 * @brief	This class is an implementation of the character encoder.
 * @since	1.0
 *
 * The %Encoder class converts blocks of characters to blocks of encoded bytes 
 * through successive calls to the GetBytes() method. This class maintains the state consistency information between 
 * successive calls to GetBytes(), enabling it to encode a character into a sequence of bytes, 
 * such as surrogate pairs, that span adjacent blocks.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/converting_text_data_separate_blocks.htm">Converting Text Data in Separate Blocks</a>.
 */


class _EXPORT_TEXT_ Encoder :
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Encoder(void) { };

// Operations
public:
	/** 
	 * Calculates the total number of bytes that are required to encode a range of characters in the specified McharBuffer instance.
	 *
	 * @since			1.0
	 * @return		An error code               
	 * @param[in]	chars An instance of McharBuffer that is to be encoded
	 * @param[in]	charIndex The index from where encoding begins in the McharBuffer instance 
   * @param[in] charCount The total number of characters to encode 
   * @param[in] flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *						else @c false
	 * @param[out]  byteCount The total number of bytes required to encode the specified range of characters
	 * @exception	E_SUCCESS                The method is successful.  	
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                         the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE		 The value of an argument is outside the valid range defined by the method, or
	 *										   the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW              This operation has caused the memory to underflow, or
	 *										   the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.
     *          
	 * @see				Decoder::GetCharCount()
	 */
	virtual result GetByteCount(const Osp::Base::McharBuffer& chars, 
		int charIndex, int charCount, int& byteCount, bool flush = false) = 0;

	/** 
	 * Encodes an instance of the specified McharBuffer into an instance of %ByteBuffer.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *						else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte plus one in the buffer and the starting position is zero.
 	 * @param[in]	chars An instance of McharBuffer that is to be encoded
	 * @param[in]   flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
     *				else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                         the specified @c chars is empty.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme.  
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 * @see	      Decoder::GetCharsN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars, bool flush = false) = 0;

	/** 
	 * Encodes an instance of McharBuffer into an instance of %ByteBuffer as per the specified range.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ByteBuffer instance where the resultant encoded string is stored, @n
	 *					else @c null if an exception occurs @n
	 *						The buffer limit is the position of the last encoded byte in the buffer and the starting position is zero.
	 * @param[in]	chars An instance of McharBuffer that is to be encoded
	 * @param[in]	charIndex The index from where encoding begins in the McharBuffer instance 
     * @param[in]   charCount The total number of characters to encode
	 * @param[in] flush Set to @c true to allow this instance to flush its state at the end of the conversion, @n
	 *						else @c false
	 * @exception	E_SUCCESS                The method is successful.
	 * @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid, or 
	 *                                         the specified @c chars is empty.
	 * @exception	E_OUT_OF_RANGE       The value of an argument is outside the valid range defined by the method, or
	 *                                         the length of the specified @c charIndex or @c charCount is greater than the length of the specified @c chars.
	 * @exception   E_UNDERFLOW	             This operation has caused the memory to underflow, or
	 *                                         the sum of the length of the specified @c charIndex and @c charCount is greater than the length of the specified @c chars.
	 * @exception	E_INVALID_ENCODING_RANGE The specified string contains code points that are outside the bounds of the character encoding scheme. 		
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The pointer to the %ByteBuffer instance is not terminated by a @c null character.         
	 * @see	        Decoder::GetCharsN()
	 */
	virtual Osp::Base::ByteBuffer* GetBytesN(const Osp::Base::McharBuffer& chars, int charIndex, int charCount, 
		bool flush = false) = 0;

private:
	friend class EncoderEx;
	class EncoderEx* __pEncoderEx;
};
 
} }// Osp::Text
#endif//_FTEXT_ENCODER_H_
