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
 * @file		FText.h 
 * @brief		This is the header file for the %Text namespace.
 *
 * This header file contains the declarations of the %Text namespace.
 */

#ifndef _FTEXT_H_
#define _FTEXT_H_

#include "FTextEncoding.h"
#include "FTextUtf8Encoding.h"
#include "FTextAsciiEncoding.h"
#include "FTextLatin1Encoding.h"
#include "FTextGsmEncoding.h"
#include "FTextUcs2Encoding.h"
#include "FTextEncoder.h"
#include "FTextDecoder.h"
#include "FTextUtf8Encoder.h"
#include "FTextUtf8Decoder.h"


namespace Osp
{
/**
 * @namespace	Osp::Text
 * @brief			This namespace contains classes that encode and decode characters.
 * @since			1.0
 *
 * @remarks 	@b Header @b %file: @b \#include @b <FText.h> @n
 *						@b Library: @b FOsp
 *
 *
 *	
 * The %Text namespace contains the %Encoding class, which is the base class for encoding and decoding many character encodings, such as UTF-8, UCS-2, Latin-1, GSM, and ASCII. It also contains the %Decoder and %Encoder classes for converting text blocks. The main purpose of this namespace is to support inter-
 * operability between the various existing languages and scripts.
 * %Text is a data consisting of a sequence of characters.
 * It is also defined as a series of characters that can be displayed on a 
 * display terminal or printed on paper for human reading.
 *
 * 
 *
 * For more information on the %Text namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/text/text.htm">Text Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Text namespace.
 * @image html text_using_the_apis_classdiagram.png
 *
 *
 * 
 * 
 *
 */


namespace Text
{

} // Osp::Text 
} // Osp


#endif//_FTEXT_H_
