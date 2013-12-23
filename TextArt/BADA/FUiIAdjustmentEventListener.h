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
 * @file		FUiIAdjustmentEventListener.h 
 * @brief		This is the header file for the %IAdjustmentEventListener class.
 *
 * This header file contains the declarations of the %IAdjustmentEventListener class. @n
 * If a change event is generated, a method of this class is called. @n
 * So, for tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_IADJUSTMENT_EVENT_LISTENER_H_
#define _FUI_IADJUSTMENT_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
 /**
  * @interface	IAdjustmentEventListener 
  * @brief		This interface implements the listener for adjustment events.
  * @since		1.0
  *
  * The %IAdjustmentEventListener interface is the listener interface for receiving adjustment events, which
  * are fired when the knob of a Slider moves. The class that processes an adjustment event implements this interface, and the
  * instance created with that class is registered with a UI control, using the control's AddAdjustmentEventListener() method.
  * When the adjustment event occurs, the OnAdjustmentValueChanged() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_slider.htm">Slider</a>.

  */
class IAdjustmentEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IAdjustmentEventListener(void) {}

	/**
	 * Called when a change event occurs.
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in]	adjustment		The adjustment value
	 */
	virtual void OnAdjustmentValueChanged(const Osp::Ui::Control& source, int adjustment) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IADJUSTMENT_EVENT_LISTENER_H_

