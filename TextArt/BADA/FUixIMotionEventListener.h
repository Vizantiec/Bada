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
 * @file		FUixIMotionEventListener.h
 * @brief		This is the header file for the %IMotionEventListener interface.
 *
 * This header file contains the declarations of the IMotionEventListener interface.
 *
 */


 
#ifndef _FUIX_MOTION_EVENTLISTENER_H_
#define _FUIX_MOTION_EVENTLISTENER_H_

//Includes
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixMotionCommon.h"

namespace Osp{ namespace Uix{

/**
 * @interface	IMotionEventListener
 * @brief		This interface is a listener for the motion sensing events.
 * @since	    1.0
 *
 * The %IMotionEventListener interface is a listener interface for the motion sensing events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/device_motions.htm">Device Motions</a>.
 */
 
class _EXPORT_UIX_ IMotionEventListener 
{

public:
	/**
	 * Called when the snap event is detected. @n
	 * When a snap event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since		1.0
	 * @param[in]	snapType	The type of the snap @n
	 *                          This is one of the types in Osp::Uix::MotionSnapType.
	 * @see			MotionSnapType
	 */
	virtual void OnSnapDetected(MotionSnapType snapType) = 0; 

	/**
	 * Called when the double-tap event is detected. @n
	 * When a double-tap event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since		1.0
	 * @see			MotionSnapType
	 */
	virtual void OnDoubleTapDetected(void) = 0; 

	/**
	 * Called when the shake event is detected. @n
	 * When a shake event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since		1.0
	 * @param[in]	motionState	The type of the event state @n
	 *                          This is one of the states in Osp::Uix::MotionState.
	 * @see			MotionState
	 */
	virtual void OnShakeDetected(MotionState motionState) = 0; 


};

} } // Osp::Uix

#endif
