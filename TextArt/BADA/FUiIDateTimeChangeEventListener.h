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
 * @file		FUiIDateTimeChangeEventListener.h
 * @brief		This is the header file for the %IDateTimeChangeEventListener interface.
 *
 * This header file contains the declarations of the %IDateTimeChangeEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, if applications perform jobs related to change events, they use the methods of this class.
 *
 */
#ifndef _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_
#define _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {

 /**
  * @interface	IDateTimeChangeEventListener
  * @brief		This interface implements the listener for Date and Time change events.
  * @since		1.0
  *
  * The %IDateTimeChangeEventListener interface is the listener interface for receiving date and time change events. 
  * The class that processes a date and time change event implements this interface, and the instance created with that class is
  * registered with a UI control, using the control's AddDateTimeChangeEventListener() method. When the date and time change event
  *  occurs, the OnDateTimeChanged() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
  */
class _EXPORT_UI_ IDateTimeChangeEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~IDateTimeChangeEventListener(void) {}

	/**
	 * Called when there is a change in DateTime. @n 
	 * The changed values of day, month, year, hour and minute are passed as input parameters.
	 *
	 * @since			1.0
	 * @param[in] 		source		    The source of the event
	 * @param[in]		year			The year value
	 * @param[in]		month			The month value
	 * @param[in]		day				The day value
	 * @param[in]		hour			The hour value
	 * @param[in]		minute			The minute value
	 *
	 */
	virtual void OnDateTimeChanged(const Osp::Ui::Control& source, int year, int month, int day, int hour, int minute) = 0;


	/**
	* Called when the date and time change is canceled.
	*
	* @since			1.0
	* @param[in] 	source		The source of the event
	*/
	virtual void OnDateTimeChangeCanceled(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IDATETIME_CHANGE_EVENT_LISTENER_H_

