/* $Change: 1236181 $ */
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
 * @file		FUiIScrollPanelEventListener.h 
 * @brief		This is the header file for the %IScrollPanelEventListener interface.
 *
 * This header file contains the declarations of the %IScrollPanelEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * Applications that do jobs related to change events call the methods of this class.
 *
 */
#ifndef _FUI_ISCROLLPANEL_EVENT_LISTENER_H_
#define _FUI_ISCROLLPANEL_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {

/**
* @enum	ScrollPanelStatus
*
* Defines the constants used to identify the overlay status of %ScrollPanel. @n
* This is used for the overlay keypad support.
* @deprecated     This enum is deprecated because it is not supported by the platform.
* @since	1.0
*/
enum ScrollPanelStatus
{
	OVERLAY_CONTROL_CREATED,	/**< An overlay keypad created on top of %ScrollPanel	*/
	OVERLAY_CONTROL_OPENED,		/**< An overlay keypad opened on top of %ScrollPanel	*/
	OVERLAY_CONTROL_CLOSED, 	/**< An overlay keypad closed */
	OTHER_CONTROL_SELECTED 		/**< Another control in the %ScrollPanel is selected */
};

 /**
  * @interface	IScrollPanelEventListener 
  * @brief		This interface implements a listener for %ScrollPanel events.
  * @since		1.0
  *
  * The %IScrollPanelEventListener interface is the listener interface for receiving change events related to controls (especially an overlay keypad) within the
  * ScrollPanel. The class that processes a change event implements this interface, and the instance created with that class is
  * registered with a UI control, using the control's AddScrollPanelEventListener() method. When the change event occurs, a method
  * of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_panels.htm">Panels</a> and <a href="../com.osp.cppappprogramming.help/html/tutorials/ui_tutorial/using_overlay_keypad_with_scroll.htm">Using EditArea or EditField Overlay Keypad with ScrollPanel</a>.

  */
class _EXPORT_UI_ IScrollPanelEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~IScrollPanelEventListener(void) {}

	/**
	 * Called when an overlay keypad is created on the %ScrollPanel control.
	 *
	 * @since		1.0
	 * @param[in] 	source				The source of the event
	 */
	virtual void OnOverlayControlCreated(const Osp::Ui::Control& source) = 0;

	/**
	 * Called when an overlay keypad is opened on the %ScrollPanel control.
	 *
	 * @since		1.0
	 * @param[in] 	source				The source of the event
	 */
	virtual void OnOverlayControlOpened(const Osp::Ui::Control& source) = 0;

	/**
	 * Called when an overlay keypad is closed on the %ScrollPanel control.
	 *
	 * @since		1.0
	 * @param[in] 	source				The source of the event
	 */
	virtual void OnOverlayControlClosed(const Osp::Ui::Control& source) = 0;

	/**
	 * Called when a control on the %ScrollPanel control is selected.
	 *
	 * @since		1.0
	 * @param[in] 	source				The source of the event
	 */
	virtual void OnOtherControlSelected(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ISCROLLPANEL_EVENT_LISTENER_H_

