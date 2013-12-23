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
 * @file		FUiIAnimationEventListener.h 
 * @brief		This is the header file for the %IAnimationEventListener interface.
 *
 * This header file contains the declarations of the %IAnimationEventListener interface.
 * If a change event is generated, a method of this class is called.
 * So, for tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_IANIMATION_EVENT_LISTENER_H_
#define _FUI_IANIMATION_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
 /**
  * @interface	IAnimationEventListener 
  * @brief		This interface implements the listener for animation events.
  * @since	1.0
  *
  * The %IAnimationEventListener interface is the listener interface for receiving animation events. 
  * The class that processes an animation event implements this interface, and the instance created with that class is registered
  * with a UI control, using the control's @ref AddAnimationEventListener() method. When the animation event occurs, the
  * @ref OnAnimationStopped() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_animation.htm">Animation</a>.
  *
  *
  */
class IAnimationEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IAnimationEventListener(void) {}

	/**
	 * Called when the animation is stopped.
	 *
	 * @since				1.0
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnAnimationStopped(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IANIMATION_EVENT_LISTENER_H_

