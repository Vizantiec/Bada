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
 * @file		FUiITimeChangeEventListener.h 
 * @brief		This is the header file for the %ITimeChangeEventListener interface.
 *
 * This header file contains the declarations of the %ITimeChangeEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, for tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_ITIME_CHANGE_EVENT_LISTENER_H_
#define _FUI_ITIME_CHANGE_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {

 /**
  * @interface	ITimeChangeEventListener 
  * @brief		This interface implements the listener for the time change events.
  * @since		1.0
  *
  * The %ITimeChangeEventListener interface is the listener interface for receiving time change events. 
  * The class that processes a time change event implements this interface, and the instance created with that class is registered
  * with a UI control, using the control's AddTimeChangeEventListener() method. When the time change event occurs, the
  *  OnTimeChanged() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.

  */
class _EXPORT_UI_ ITimeChangeEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~ITimeChangeEventListener(void) {}

	/**
	 * Called when there is a change in time. @n
	 * The changed hour and minute values are passed as input parameters.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in]	hour		The hour
     * @param[in]	minute		The minute
	 */
	virtual void OnTimeChanged(const Osp::Ui::Control& source, int hour, int minute) = 0;

	/**
	* Called when a time change is canceled.
	*
	* @since		1.0
	* @param[in] 	source		The source of the event
	*/
	virtual void OnTimeChangeCanceled(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ITIME_CHANGE_EVENT_LISTENER_H_

