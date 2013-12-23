/* $Change: 383273 $ */
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
 * @file		FBaseUtilMemory.h
 * @brief		This is the header file for the memory stubs.
 *
 * This header file contains the memory stubs.
 */

#ifndef _FBASE_UTIL_MEMORY_H_
#define _FBASE_UTIL_MEMORY_H_
#include "FBaseSys.h"
#include "FBaseDataType.h"

_EXPORT_BASE_	void*	Osp_alloc(unsigned int size);
_EXPORT_BASE_	void*	Osp_allocEx(unsigned int size, const char *file, int line);

_EXPORT_BASE_	void	Osp_free(void* p);
_EXPORT_BASE_	void	Osp_freeEx(void* pMem, const char *file, int line);

_EXPORT_BASE_	void*	Osp_calloc(unsigned int elementCount, unsigned int elementSize);
_EXPORT_BASE_	void*	Osp_callocEx(unsigned int elementCount, unsigned int elementSize, const char *file, int line);

_EXPORT_BASE_	void*	Osp_realloc(void* p, unsigned int size);
_EXPORT_BASE_	void*	Osp_reallocEx(void* p, unsigned int size, const char *file, int line);

#endif

