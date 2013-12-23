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
* @file			FUixMotionCommon.h 
* @brief		This is the header file for the %Uix namespace.
*
* This header file contains the declarations of the %Uix namespace.
*/

#ifndef _FUIX_MOTION_COMMON_H_
#define _FUIX_MOTION_COMMON_H_

//include
#include "FUixConfig.h"

namespace Osp{ namespace Uix{ 

/**
 * @enum	MotionType
 * Defines the types of motions provided.
 *
 * @since	1.0
 * @see 	Motion::SetEnabled()
 */
enum MotionType 
{
	MOTION_TYPE_NONE = 0x0000,		/**< The motion type: None */
	MOTION_TYPE_SNAP = 0x0001,		/**< The motion type: Snap */
	MOTION_TYPE_SHAKE = 0x0002,		/**< The motion type: Shake */
	MOTION_TYPE_DOUBLETAP = 0x0004,	/**< The motion type: Tap */
	MOTION_TYPE_ALL = 0xFFFF,		/**< The motion type: All */
};

/**
 * @enum  MotionState
 * Defines the state of motions. @n
 * Some event can only be found in a subset of states described below.
 *
 * @since	1.0
 * @see 	IMotionEventListener::OnShakeDetected()
 */
enum MotionState
{
	MOTION_STARTED,		/**< The specified motion has just started */
	MOTION_INPROGRESS,	/**< The specified motion is happening */	
	MOTION_ENDED,		/**< The specified motion has just ended */
	MOTION_CANCELLED,	/**< Reserved */
};

/**
 * @enum  MotionSnapType
 * Defines the types of snap provided.
 *
 * @since	1.0
 * @see 	IMotionEventListener::OnSnapDetected()
 */
enum MotionSnapType
{
	MOTION_SNAP_X_POSITIVE, /**< Snaps to positive X */
	MOTION_SNAP_X_NEGATIVE, /**< Snaps to negative X */
	MOTION_SNAP_Y_POSITIVE, /**< Snaps to positive Y */
	MOTION_SNAP_Y_NEGATIVE, /**< Snaps to negative Y */
	MOTION_SNAP_Z_POSITIVE, /**< Snaps to positive Z */
	MOTION_SNAP_Z_NEGATIVE, /**< Snaps to negative Z */
};

} } // Osp::Uix

#endif
