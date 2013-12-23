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
 * @file	FUiIWindowEventListener.h 
 * @brief	This is the header file for the %IWindowEventListener interface.
 *
 * This header file contains the declarations of the IWindowEventListener interface. @n
 * If a window event is generated, a method of this class is called. @n
 * So, for tasks related to the window event, use the methods of this class.
 *
 */

#ifndef _FUI_IWINDOW_EVENT_LISTENER_H_
#define _FUI_IWINDOW_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FBaseTypes.h"

namespace Osp { namespace Ui { class Window;    } }

namespace Osp {namespace Ui {
/**
 * @interface	IWindowEventListener
 * @brief		This interface implements the listener for the window event.
 * @since		1.0
 *
 * The %IWindowEventListener interface is the listener interface for receiving window events. 
 * The class that processes a window event implements this interface, and the instance created with that class is registered with
 * a Window, using the Window's AddWindowEventListener() method. When the window event occurs, a method of that instance is
 * invoked. This interface is also related to the ContextMenu, DatePicker, DateTimePicker, Frame, Keypad, MessageBox, OptionMenu,
 * Popup, and TimePicker controls.
 */
class _EXPORT_UI_ IWindowEventListener :
		public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
     * @internal
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~IWindowEventListener(void) {}

	/**
	 * Called when a window becomes the topmost window.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 *
	 */
	virtual void OnWindowActivated(const Osp::Ui::Window& source) = 0;
	
	/**
	 * Called when the window is no longer the topmost window.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 *
	 */
	virtual void OnWindowDeactivated(const Osp::Ui::Window& source) = 0;
	
};

} }; // Osp::Ui

#endif // _FUI_IWINDOW_EVENT_LISTENER_H_

