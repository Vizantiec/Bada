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
 * @file		FUiITextEventListener.h 
 * @brief		This is the header file for the %ITextEventListener interface.
 *
 * This header file contains the declarations of the %ITextEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * So, if the applications perform tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_ITEXT_EVENT_LISTENER_H_
#define _FUI_ITEXT_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {

 /**
  * @interface	ITextEventListener 
  * @brief		This interface implements the listener for text events.
  * @since		1.0
  *
  * The %ITextEventListener interface is the listener interface for receiving text events, for example, from EditFields. 
  * The class that processes a text event implements this interface, and the instance created with that class is registered with a
  *  UI control, using the control's AddTextEventListener() method. When the text event occurs, the OnTextValueChanged() method of
  *  that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>, <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_textbox.htm">TextBox</a>, and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_searchbar.htm">SearchBar</a>.

  */
class ITextEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~ITextEventListener(void) {}

	/**
	 * Called when a text is changed.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     				For more information, see @ref CompIEventListenerOnTextValueChanged "here".
	 * @param[in] 		source		The source of the event
	 * @remarks			For EditField or EditArea with INPUT_STYLE_FULLSCREEN input style, this listener method is invoked when the user presses "Done" 
	 *					soft-key. Whereas, for EditField or EditArea with INPUT_STYLE_OVERLAY input style, this method is called whenever the user presses a 
	 *					key.
	 * @remarks  		Note that when a non-character key is pressed, OnTextValueChanged() callback is invoked.
	 */
	virtual void OnTextValueChanged(const Osp::Ui::Control& source) = 0;

	/**
	 * @page	CompIEventListenerOnTextValueChanged	Compatibility for OnTextValueChanged()
	 * @section	CompIEventListenerOnTextValueChangedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When texts are inserted by prediction feature in the predictive input mode of EditArea or EditField, OnTextValueChanged() callback is not invoked.
	 *
	 * @section	CompIEventListenerOnTextValueChanged Resolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2. or above. @n
	 */


	/**
	 * Called when a change made to the text is canceled.
	 *	
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @remarks     This listener method is called when the user presses "Cancel" soft-key for EditField or EditArea with INPUT_STYLE_FULLSCREEN input 
	 *				style.	 
	 */
	virtual void OnTextValueChangeCanceled(const Osp::Ui::Control& source) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ITEXT_EVENT_LISTENER_H_

