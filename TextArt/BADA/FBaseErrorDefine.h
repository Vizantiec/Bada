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
 * @file		FBaseErrorDefine.h 
 * @brief		This header file defines Osp framework's common error codes.
 *
 * This header file contains the definitions of error codes used in the Osp framework.
 */

#ifndef _FBASE_ERROR_DEFINE_H_
#define _FBASE_ERROR_DEFINE_H_

// Includes
#include "FBaseTypes.h"

#define E_SEVERITY_POS					31
#define E_TYPE_POS						29

#define SET_E_SEVERITY(X)				((unsigned long) PUT_MASK(0, (X), E_SEVERITY_POS))
#define SET_E_TYPE(X)					((unsigned long) PUT_MASK(0, (X), E_TYPE_POS))
#define SET_E_CAUSE(X)					((unsigned long) (X))


// Error severities
/*
 * The method is successful.
 */
#define E_SUCCESS						(SET_E_SEVERITY(0))
#define E_FAILURE						(SET_E_SEVERITY(1))


// Error types
#define ERR_SRC_FRAMEWORK				(E_FAILURE + SET_E_TYPE(1))
#define ERR_SRC_USER					(E_FAILURE + SET_E_TYPE(2))


// Macros for OAFD error codes
#define IsFailed(X)						((long)X != E_SUCCESS)


#endif//_FBASE_ERROR_DEFINE_H_

