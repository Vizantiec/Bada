// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiCtrlISliderEventListener.h 
 * @brief		This is the header file for the %ISliderEventListener interface.
 *
 * This header file contains the declarations of the %ISliderEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, if the applications perform tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUICTRL_ISLIDER_EVENT_LISTENER_H_
#define _FUICTRL_ISLIDER_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FUiCtrlSliderEnum.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { namespace Controls { class Slider;  } } }

namespace Osp { namespace Ui { namespace Controls {
 /**
  * @interface	ISliderEventListener 
  * @brief		This interface implements the listener for all slider events.
  * @since		2.0
  *
  * The %ISliderEventListener interface is the listener interface for receiving Slider events, which are fired when the slider knob moves.
  * The class that processes a slider event implements this interface, and the instance created with that class is registered with
  *  a UI control, using the control's AddSliderEventListener() method. When the slider event occurs, the OnSliderBarMoved()
  *  method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_slider.htm">Slider</a>.
  */
class _EXPORT_CONTROLS_ ISliderEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ISliderEventListener(void) {}
	
	/**
	 * Called when the Slider bar moves. 
	 *
	 * @since     2.0
	 * @param[in] source	The source of the event
	 * @param[in] value   	The current value indicated by the knob
	 * @remarks   This event is fired when the knob is moved until the user releases the knob. 
	 */
	virtual void OnSliderBarMoved(Osp::Ui::Controls::Slider& source, int value) = 0; 
	
protected:	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void SliderEventListener_Reserved1 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void SliderEventListener_Reserved2 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void SliderEventListener_Reserved3 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void SliderEventListener_Reserved4 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void SliderEventListener_Reserved5 (void) {}
};

}; /* Osp::Ui::Controls */ }; /* Osp::Ui*/ }; /* Osp */

#endif // _FUICTRL_ISLIDER_EVENT_LISTENER_H_

