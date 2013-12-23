//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
// 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiITouchModeChangedEventListener.h
 * @brief		This is the header file for the %ITouchModeChangedEventListener interface.
 *
 * This header file contains the declarations of the %ITouchModeChangedEventListener interface. @n
 * If the touch mode of a device is changed, a method of this class is called.
 * Therefore, if an application performs tasks related to the touch mode event, use the methods of this class.
 *
 */
#ifndef _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_
#define _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
/**
 * @interface	ITouchModeChangedEventListener 
 * @brief		This interface implements the listener for the touch mode changed event.
 * @since	    1.1
 *
 * The %ITouchModeChangedEventListener interface is the listener interface for receiving touch mode change events. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _EXPORT_UI_ ITouchModeChangedEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since				1.1
	 */
	virtual ~ITouchModeChangedEventListener(void) {};

	/**
	 * Called when an action event occurs.
	 *
	 * @since		1.1
	 * @param[in] 	source		    The source of the event
	 * @param[in] 	isInTouchMode	The current mode
	 */
	virtual void OnTouchModeChanged(const Osp::Ui::Control& source, bool isInTouchMode) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ITOUCH_MODE_CHANGED_EVENT_LISTENER_H_
