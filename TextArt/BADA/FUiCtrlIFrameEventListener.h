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
 * @file	FUiCtrlIFrameEventListener.h 
 * @brief	This is the header file for the %IFrameEventListener interface.
 *
 * This header file contains the declarations of the %IFrameEventListener interface. @n
 * If a frame lifecycle event is generated, a method of this class is called. @n
 * So, if an application needs to perform tasks related to the frame event, provide the implementation of the methods declared in this interface.
 */

#ifndef _FUICTRL_IFRAME_EVENT_LISTENER_H_
#define _FUICTRL_IFRAME_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { namespace Controls { class Frame; } } }

namespace Osp { namespace Ui { namespace Controls {
/**
 * @interface	IFrameEventListener
 * @brief		This interface implements the listener for the frame lifecycle event.
 * @since		1.0
 *
 * The %IFrameEventListener interface is the listener interface for receiving %Frame lifecycle events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_frame.htm">Frame</a>.
 * 
 */
class _EXPORT_CONTROLS_ IFrameEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
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
	virtual ~IFrameEventListener(void) {}

// Operations
public:
	/**
	 * Called when a Frame instance is about to be destroyed. @n
	 * This method is called just before the system destroys the %Frame instance of an application during the application termination sequence.  
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @remarks     This method releases any resources that need to be deallocated before the destruction of the Frame instance.
	 */
	virtual void OnFrameTerminating(const Osp::Ui::Controls::Frame& source) = 0;
	
}; // IFrameEventListener

} } }; // Osp::Ui::Controls

#endif // _FUICTRL_IFRAME_EVENT_LISTENER_H_
