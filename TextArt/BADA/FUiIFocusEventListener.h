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
* @file			FUiIFocusEventListener.h 
* @brief		This is the header file for the %IFocusEventListener interface.
*
* This header file contains the declarations of the %IFocusEventListener interface.
*/
#ifndef _FUI_IFOCUS_EVENT_LISTENER_H_
#define _FUI_IFOCUS_EVENT_LISTENER_H_

// includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp { namespace Ui  {

/**
 *  @internal
 *	@enum	FocusStatus
 *	Defines constants used to identify focus status.
 *
 * @since			1.0
 */
enum FocusStatus
{
	FOCUS_GAINED = 0,	/* The control has gained focus */
	FOCUS_LOST = 1		/* The control has lost focus	*/
};

/**
 * @interface	IFocusEventListener
 * @brief		This interface is used as the argument to focus the event listener.
 * @since		1.0
 *
 * The %IFocusEventListener interface is the listener interface for receiving focus events. 
 * The class that processes a focus event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddFocusEventListener() method. When the focus event occurs, a method of that instance is
 * invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.

 */
class _EXPORT_UI_ IFocusEventListener :
    public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	* @internal
	* This is internal. If used in an application, the application can get rejected during the certification process.
	* This is the virtual destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~IFocusEventListener(void) {}

// Operation
public:
	/**
	 * Called when Control gains the input focus. 
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnFocusGained(const Osp::Ui::Control& source) = 0;


	/**
	 * Called when %Control loses the input focus. 
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnFocusLost(const Osp::Ui::Control& source) = 0;
};

} ;} ;// Osp::Ui::IFocusEventListener

#endif// _FUI_IFOCUS_EVENT_LISTENER_H_

