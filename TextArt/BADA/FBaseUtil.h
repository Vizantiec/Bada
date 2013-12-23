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
 * @file		FBaseUtil.h 
 * @brief		This is the header file for the %Utility namespace.
 *
 * This header file contains the declarations of the %Utility namespace. 
 *
 */
#ifndef _FBASE_UTIL_H_
#define _FBASE_UTIL_H_

// Math
#include "FBaseUtilMath.h"

// StringTokenizer
#include "FBaseUtilStringTokenizer.h"

// StringUtil
#include "FBaseUtilStringUtil.h"

// Uri
#include "FBaseUtilUri.h"

// Inflator
#include "FBaseUtilInflator.h"

// Deflator
#include "FBaseUtilDeflator.h"

//UrlEncoder 
#include "FBaseUtilUrlEncoder.h"

//Url Decoder
#include "FBaseUtilUrlDecoder.h"

//FileZip
#include "FBaseUtilFileZipper.h"

//FileUnzip
#include "FBaseUtilFileUnzipper.h"

//ZipEntry
#include "FBaseUtilZipEntry.h"

//Regular expression
#include "FBaseUtilRegularExpression.h"


/**
 * @namespace		Osp::Base::Utility
 * @brief				This namespace contains classes for various utilities.
 * @since				1.0
 * @remarks     @b Header @b %file: @b \#include @b <FBase.h> @n
 *				@b Library : @b FOsp
 *
 *
 * The %Utility namespace contains interfaces and classes that 
 * define various utilities of an object, such as Math and StringTokenizer.
 * It also contains methods to perform some common functions needed by the applications, such as file zipping and URL encoding and decoding.   
 * 
 * For more information on the %Base::Utility namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 * 
 * The following diagram illustrates the relationships between the classes belonging to the %Utility namespace.
 * @image html base_utility_namespace_classdiagram.png
 * 
 *
 *
 **/
namespace Osp { namespace Base { namespace Utility {

}; // Utility

}; }; // Osp::Base

#endif // _FBASE_UTIL_H_

