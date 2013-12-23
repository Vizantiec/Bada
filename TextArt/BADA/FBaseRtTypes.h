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
 * @file		FBaseRtTypes.h 
 * @brief		This is the header file for types in Runtime package.
 *
 * This header file contains the definition of types in Runtime package.
 */
#ifndef _FRT_TYPES_H_
#define _FRT_TYPES_H_

#include "FBaseTypes.h"


namespace Osp { namespace Base { namespace Runtime {


/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Status of the timer
 *
 * @since       1.0
 */
enum TimerStatus
{
	TIMER_STATUS_NOT_ACTIVATED, 	/**< @internal timer is not activated */	
	TIMER_STATUS_ACTIVATED,		/**< @internal timer has been activated */	
	TIMER_STATUS_CANCELED, 		/**< @internal timer has been canceled */
	TIMER_STATUS_EXPIRED		/**< @internal timer has been expired */	
};

} } }// Osp::Runtime

#endif

