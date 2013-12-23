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
 * @file		FUiIKeypadEventListener.h 
 * @brief		This is the header file for the %IKeypadEventListener interface.
 *
 * This header file contains the declarations of the %IKeypadEventListener interface.
 */
#ifndef _FUI_IKEYPAD_EVENT_LISTENER_H_
#define _FUI_IKEYPAD_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FUiCtrlEditEnum.h"

namespace Osp { namespace Graphics { class Dimension; }; };
namespace Osp { namespace Ui { class Control; }; };

// Namespace declaration
namespace Osp { namespace Ui {

/**
 * @enum 	KeypadAction
 *
 * Defines the possible keypad action types.
 * @since		2.0
 */
enum KeypadAction
{
    KEYPAD_ACTION_ENTER,	/**< The Enter key */
    KEYPAD_ACTION_GO,		/**< The Go key */
    KEYPAD_ACTION_NEXT,	    /**< The Next key */
    KEYPAD_ACTION_SEND,	    /**< The Send key */
    KEYPAD_ACTION_SEARCH,   /**< The Search key */
    KEYPAD_ACTION_LOGIN,    /**< The Login key */
    KEYPAD_ACTION_SIGN_IN,  /**< The Sign-In key */
    KEYPAD_ACTION_JOIN,	    /**< The Join key */
    KEYPAD_ACTION_DONE	    /**< The Done key */
};

 /**
  * @interface	IKeypadEventListener 
  * @brief	    This interface implements the listener for the keypad events.
  * @since	    2.0
  *
  * The %IKeypadEventListener interface is the listener interface for receiving software keypad events. 
  * The class that processes a software keypad event implements this interface, and the instance created with that class is
  * registered with a UI control, using the control's AddKeypadEventListener() method. When the software keypad event occurs, a
  * method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_searchbar.htm">SearchBar</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.

  */
class _EXPORT_UI_ IKeypadEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 * @since	2.0
	 */
	virtual ~IKeypadEventListener(void) {}


// Operation
public:
	/**
	 * Called when the keypad is about to be shown on the screen.
	 *
	 * @since		2.0
	 * @param[in]	source		The source of the event
	 * @remarks		When the software keypad appears on the screen, the client area of the current Form is adjusted to account for the space that is taken 
	 *              up by the software keypad.
     * @see       	Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadWillOpen(Osp::Ui::Control& source) = 0;

	/**
	 * Called when the keypad is shown on the screen.
	 *
	 * @since		2.0
	 * @param[in]	source		The source of the event
	 * @remarks		When the software keypad appears on the screen, the client area of the current Form is adjusted to account for the space that is taken 
	 *              up by the software keypad.
     * @see			Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadOpened(Osp::Ui::Control& source) = 0;

	/**
	 * Called when the keypad is hidden from the screen.
	 *
	 * @since		2.0
	 * @param[in]	source		The source of the event
	 * @see			Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnKeypadClosed(Osp::Ui::Control& source) = 0;

	/**
	 * Called when the keypad action button is pressed.
	 *
	 * @since		2.0
	 * @param[in]	source			The source of the event
	 * @param[in]	keypadAction	The keypad action
	 * @see 		KeypadAction
	 */
	virtual void OnKeypadActionPerformed(Osp::Ui::Control& source, Osp::Ui::KeypadAction keypadAction) = 0;

// Reserves
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
    virtual void IKeypadEventListener_Reserved1 (void) { } 

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
    virtual void IKeypadEventListener_Reserved2 (void) { } 

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
    virtual void IKeypadEventListener_Reserved3 (void) { } 

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
    virtual void IKeypadEventListener_Reserved4 (void) { } 

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
    virtual void IKeypadEventListener_Reserved5 (void) { } 
};
}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IKEYPAD_EVENT_LISTENER_H_

