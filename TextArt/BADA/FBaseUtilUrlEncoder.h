// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FBaseUtilUrlEncoder.h
 * @brief		This is the header file for the %UrlEncoder class.
 *
 * This header file contains the declarations of the %UrlEncoder class.
 */

#ifndef _FBASE_UTIL_URLENCODER_H_
#define _FBASE_UTIL_URLENCODER_H_

// Includes
#include "FBaseString.h"

namespace Osp { namespace Base { namespace Utility {
/**
 * @class	UrlEncoder
 * @brief	This class provides a method for encoding a string using a specific encoding scheme.
 * @since	2.0
 *
 * The %UrlEncoder class provides a method for encoding a string using a specific encoding scheme.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/url_encoder_decoder.htm">UrlEncoder and UrlDecoder</a>.
 *
 * The following example demonstrates how to use the %UrlEncoder class.
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
 *	MyClass::UrlEncoderSample(void)
 *	{
 *		result r = E_SUCCESS;
 *		String str1(L"url encoding test?");
 *		String str2;
 *
 *		// Encode the input string.
 *		r = UrlEncoder::Encode(str1, L"UTF-8", str2);
 *
 *	}
 * @endcode
 */
 

class _EXPORT_BASE_ UrlEncoder
{
// Operations (Static)
public:
	/**
	* Encodes an input string using a specific encoding scheme. @n
	* It encodes all unsafe characters of a string.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in] 	str							An instance of %String to be encoded
	* @param[in] 	encodingScheme 	 			The supported encoding scheme
	* @param[out] 	encodedStr 	 				The encoded string
	* @exception 	E_SUCCESS 					The method is successful.
	* @exception 	E_INVALID_ARG  				A specified input parameter is invalid.
	* @exception 	E_OUT_OF_MEMORY  			The memory is insufficient.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception 	E_UNSUPPORTED_TYPE  		The specified encoding scheme is not supported.
	* @exception 	E_INVALID_ENCODING_RANGE  	The specified string contains code points that are outside the bounds of the character encoding scheme.
	*
	* @remarks	This method is used for encoding. It encodes input string into an
	* application/x-www-form-urlencoded	format using a specific encoding scheme. This method uses the specified
	* encoding scheme to obtain the bytes for unsafe characters.
	*
	*@see		UrlDecoder
	*/
	static result Encode(const Osp::Base::String& str, const Osp::Base::String& encodingScheme, Osp::Base::String& encodedStr);

// life-cycle
private:
	/**
	* This is the default constructor for this class.
	*
	* @since	2.0
	*/
	UrlEncoder(void);

	/*
	 * This is the destructor for this class.
	 */
	virtual ~UrlEncoder(void);

};	// UrlEncoder
}; }; }; // Osp::Base::Utility
#endif
