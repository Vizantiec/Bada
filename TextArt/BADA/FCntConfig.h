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
* @file			FCntConfig.h 
* @brief		This header file contains configurations of the Content namespace.
*
* This header file contains configurations of the Content namespace.
*/

#ifndef _FCNT_CONFIG_H_
#define _FCNT_CONFIG_H_

#if defined(_WIN32)             // MS Compiler & MinGW GCC
#	if defined(_FCONTENTAPI_EXPORTS)
#       define _EXPORT_CONTENT_ __declspec(dllexport)
#	else
#		define _EXPORT_CONTENT_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_CONTENT_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_CONTENT_

#else
#	define _EXPORT_CONTENT_

#endif

#endif	// _FCNT_CONFIG_H_

