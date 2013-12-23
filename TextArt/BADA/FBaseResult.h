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
 * @file		FBaseResult.h 
 * @brief		This is the header file for the %Result class.
 *
 * This header file contains the declaration of the %Result class.
 */
#ifndef _FBASE_RESULT_H_
#define _FBASE_RESULT_H_

// includes
#include "FBaseTypes.h"
#include "FBaseErrors.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define SetLastResultReturn(r) \
	SetLastResult(r); \
	return r;


_EXPORT_BASE_ result 
GetLastResult(void);


_EXPORT_BASE_ void 
SetLastResult(result r);


_EXPORT_BASE_ void 
ClearLastResult(void);


struct ErrorTable
{
	result	error;
	//int		index;
	char errorString[50];
};


_EXPORT_BASE_ void
RegisterErrorTable(unsigned long package, struct ErrorTable* pErrorTable);


_EXPORT_BASE_ const char*
GetErrorMessage(result value);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif//_FBASE_RESULT_H_

