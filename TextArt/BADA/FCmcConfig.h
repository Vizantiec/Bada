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
/* 
 * @file	FCmcConfig.h 
 * @brief	This is the header file for the configuration of Osp::Commerce.
 *
 * This header file contains the configurations of Osp::Commerce.
 */

#ifndef _FCMC_CONFIG_H_
#define _FCMC_CONFIG_H_

#if defined(_WIN32)             // MS Compiler & MinGW GCC
#	if defined(_FCOMMERCEAPI_EXPORTS)
#       define _EXPORT_COMMERCE_ __declspec(dllexport)
#	else
#		define _EXPORT_COMMERCE_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_COMMERCE_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_COMMERCE_

#else
#	define _EXPORT_COMMERCE_

#endif

#endif	// _FCMC_CONFIG_H_

