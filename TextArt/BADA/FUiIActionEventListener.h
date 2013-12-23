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
 * @file		FUiIActionEventListener.h
 * @brief		This is the header file for the %IActionEventListener interface.
 *
 * This header file contains the declarations of the IActionEventListener interface. @n
 * If an action event is generated, a method of this class is called. @n
 * So, for tasks related to the action event, use the methods of this class.
 *
 */
#ifndef _FUI_IACTION_EVENT_LISTENER_H_
#define _FUI_IACTION_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
/**
 * @interface	IActionEventListener 
 * @brief		This interface implements the listener for action event.
 * @since		1.0
 *
 * The %IActionEventListener interface is the listener interface for receiving action events, for example, from Buttons.
 * The class that processes an action event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's 
 * AddActionEventListener() method. When the action event occurs, the OnActionPerformed() method of that instance is invoked.
 *
 * For more information on the class features, see in individual control topics under <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/controls.htm">UI Controls</a>.
 */
class _EXPORT_UI_ IActionEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~IActionEventListener(void) {}

	/**
	 * Called when an action event occurs.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in] 	actionId	The information about the action event
	 */
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IACTION_EVENT_LISTENER_H_

