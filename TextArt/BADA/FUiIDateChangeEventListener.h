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
 * @file		FUiIDateChangeEventListener.h 
 * @brief		This is the header file for the %IDateChangeEventListener interface.
 *
 * This header file contains the declarations of the IDateChangeEventListener interface.
 * If a change event is generated, a method of this class is called.
 * So, for tasks related to the change events, use the methods of this class.
 *
 */
#ifndef _FUI_IDATE_CHANGE_EVENT_LISTENER_H_
#define _FUI_IDATE_CHANGE_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {

 /**
  * @interface	IDateChangeEventListener 
  * @brief		This interface implements the listener for Date change events.
  * @since		1.0
  *
  * The %IDateChangeEventListener interface is the listener interface for receiving date change events. 
  * The class that processes a date change event implements this interface, and the instance created with that class is registered
  * with a UI control, using the control's AddDateChangeEventListener() method. When the date change event occurs, the
  * OnDateChanged() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.

  */
class _EXPORT_UI_ IDateChangeEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~IDateChangeEventListener(void) {}

	/**
	 * Called when there is a change in the date. @n
	 * The changed values of the year, month and day are passed as input parameters.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in]	year		The year
	 * @param[in]	month		The month
	 * @param[in]	day			The day
	 */
	virtual void OnDateChanged(const Osp::Ui::Control& source, int year, int month, int day) = 0;


	/**
	* Called when the change in date is canceled.
	*
	* @since		1.0
	* @param[in] 	source		The source of the event
	*/
	virtual void OnDateChangeCanceled(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IDATE_CHANGE_EVENT_LISTENER_H_

