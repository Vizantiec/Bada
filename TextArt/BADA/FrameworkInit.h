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
 * @file		FrameworkInit.h
 * @brief		This is the header file for initializing Osp.
 *
 * This header file contains the initialization function of Osp.
 *
 */
#ifndef _FRAMEWORK_INIT_H_
#define _FRAMEWORK_INIT_H_

extern "C" 
{

typedef enum{
	FRAMEWORK_BOOT,
	FRAMEWORK_SHUTDOWN
} SavannaDispatch;

void BaseInit(void);
void FIoDispatch(unsigned int flag);
void LocalesInit(void);

}

#endif	//_FRAMEWORK_INIT_H_