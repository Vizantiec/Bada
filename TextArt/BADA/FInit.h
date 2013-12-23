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
 * @file		FInit.h
 * @brief		This is the header file for initializing Osp.
 *
 * This header file contains the initialization function of Osp.
 *
 */
#ifndef _FINIT_H_
#define _FINIT_H_

extern "C" 
{

typedef enum{
	FRAMEWORK_BOOT,
	FRAMEWORK_SHUTDOWN
} SavannaDispatch;

void FBaseDispatch(unsigned int flag);
void FIoDispatch(unsigned int flag);
void FSysDispatch(unsigned int flag);
void FLocalesDispatch(unsigned int flag);
void FLocationsInit(void);
void FLocationsDispatch(unsigned int flag);
void FCommerceDispatch(unsigned int flag);
void FNetDispatch(unsigned int flag);
void FLocationsSvcDispatch(unsigned int flag);
}

#endif	//_FINIT_H_