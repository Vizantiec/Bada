/* $Change: 348791 $ */
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
 * @file			FSysISystemKeyEventListener.h
 * @brief			This is the header file of the %ISystemKeyEventListener interface.
 *
 * This header file contains the declarations of the %ISystemKeyEventListener interface.
 */

#ifndef _FSYS_ISYSTEMKEY_EVENT_LISTENER_H
#define _FSYS_ISYSTEMKEY_EVENT_LISTENER_H

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"
#include "FSysSystemKeyEventManager.h"

namespace Osp { namespace System {

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * @interface	ISystemKeyEventListener
 * @brief	This interface is the listener of the system key event.
 * @since 1.0
 *
 * To receive system key events from the system, implement and register
 * an SystemKeyEventListeenr to the system.
 * The SystemKeyEventListener must be inherited from this interface.
 *
 */
class _EXPORT_SYSTEM_ ISystemKeyEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 *	Called when a system key is pressed.
	 *
	 *  @since 1.0
	 */
	virtual void OnSystemKeyPressed(SystemKeyCode keyCode) = 0;

	/**
	 *	Called when a system key is released.
	 *
	 *  @since 1.0
	 */
	virtual void OnSystemKeyReleased(SystemKeyCode keyCode) = 0;

	/**
	 *	Called when a system key is pressed and held down for some time.
	 *
	 *  @since 1.0
	 */
	virtual void OnSystemKeyLongPressed(SystemKeyCode keyCode) = 0;

};


}; }; // Osp::System

#endif // _FSYS_ISYSTEMKEY_EVENT_LISTENER_H
