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
 * @file			FSysIScreenEventListener.h
 * @brief			This is the header file of the %IScreenEventListener interface.
 *
 * This header file contains the declarations of the %IScreenEventListener interface.
 */

#ifndef _FSYS_ISCREEN_EVENT_LISTENER_H
#define _FSYS_ISCREEN_EVENT_LISTENER_H

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace System {

/**
 * @interface	IScreenEventListener
 * @brief	This interface is the listener of the screen event.
 * @since 1.0
 *
 * The %IScreenEventListener interface must be registered and implemented by an application to receive screen events from the system.
 *
 */
class _EXPORT_SYSTEM_ IScreenEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 *	Called when the screen turns on. @n
	 *	Gets the released resources or resumes the operations that were paused or stopped in OnScreenOff().
	 *
	 *  @since 1.0
	 */
	virtual void OnScreenOn (void) = 0;

	/**
	 *	Called when the screen turns off. @n
	 *	Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
   *	Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
   *	Similarly, do not perform lengthy operations in this listener method. All operations must be quick ones.
   *
   *  @since 1.0
	 */
	virtual void OnScreenOff (void) = 0;

};


}; }; // Osp::System

#endif // _FSYS_ISCREEN_EVENT_LISTENER_H
