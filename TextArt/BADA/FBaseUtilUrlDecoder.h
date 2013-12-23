// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FBaseUtilUrlDecoder.h
 * @brief		This is the header file for the %UrlDecoder class.
 *
 * This header file contains the declarations of the %UrlDecoder class.
 */
#ifndef _FBASE_UTIL_URLDECODER_H_
#define _FBASE_UTIL_URLDECODER_H_

// Includes
#include "FBaseString.h"

namespace Osp { namespace Base { namespace Utility {
/**
 * @class	UrlDecoder
 * @brief	This class provides a method for decoding strings using a specific encoding scheme.
 * @since	2.0
 *
 * The %UrlDecoder class provides a method for decoding strings using a specific encoding scheme.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/url_encoder_decoder.htm">UrlEncoder and UrlDecoder</a>.
 *
 * The following example demonstrates how to use the %UrlDecoder class.
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
 *	MyClass::UrlDecoderSample(void)
 *	{
 *		result r = E_SUCCESS;
 *		String str1(L"url+encoding+test%3f");
 *		String str2;
 *
 *		// Decode the input string.
 *		r = UrlDecoder::Decode(str1, L"UTF-8", str2);
 *
 *	}
 * @endcode
 */
 
class _EXPORT_BASE_ UrlDecoder
{
// Operations (Static)
public:
	/**
	* Decodes an encoded string using a specific encoding scheme.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in] 	str				 			An instance of %String to be decoded
	* @param[in] 	encodingScheme	 			The supported encoding scheme
	* @param[out]	decodedStr 	 				The decoded string
	* @exception 	E_SUCCESS 					The method is successful.
	* @exception 	E_INVALID_ARG  				A specified input parameter is invalid.
	* @exception 	E_OUT_OF_MEMORY  			The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception 	E_UNSUPPORTED_TYPE			The specified encoding scheme is not supported.
	* @exception 	E_INVALID_ENCODING_RANGE  	The specified string contains code points that are outside the bounds of the character encoding scheme.
	*
	* @remarks	This method is used for decoding. It decodes an application/x-www-form-urlencoded string using a
    * specific encoding scheme. The supplied encoding scheme is used to determine what characters are represented
	* by any consecutive sequences of the form "%ab", where ab is the two-digit hexadecimal representation of a
	* byte.
	*			
	*@see		UrlEncoder
	*/
	static result Decode(const Osp::Base::String& str, const Osp::Base::String& encodingScheme, Osp::Base::String& decodedStr);

// life-cycle
private:
	/**
	* This is the default constructor for this class.
	*/
	UrlDecoder(void);

	/*
	 * This is the destructor for this class.
	 */
	virtual ~UrlDecoder(void);

};	// UrlDecoder
}; }; }; // Osp::Base::Utility
#endif
