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
 * @file		FUiCtrlIFormBackEventListener.h 
 * @brief		This is the header file for the %IFormBackEventListener interface.
 *
 * This header file contains the declarations of the %IFormBackEventListener interface.
 */
#ifndef _FUICTRL_IFORM_BACK_EVENT_LISTENER_H_
#define _FUICTRL_IFORM_BACK_EVENT_LISTENER_H_

// includes
#include "FBaseRtIEventListener.h"

// forward declarations
namespace Osp { namespace Ui { namespace Controls { class Form; }; }; };

// namespace declaration
namespace Osp { namespace Ui { namespace Controls {

/**
 * @interface	IFormBackEventListener 
 * @brief		This interface implements the listener for Form related events.
 * @since		2.0
 *
 * The %IFormBackEventListener interface is the listener interface for receiving Form-related back button events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_form.htm">Form</a>.
 */
class _EXPORT_CONTROLS_ IFormBackEventListener:
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IFormBackEventListener (void) {}


// Operation
public:
        /**
         * Called when the current %Form control needs to be closed to revert back to the previous %Form control.
         *
         * @since		2.0
         * @param[in]	source		The source of the event
         * @remarks		This event is fired when the user clicks on the software 'back' button on the Footer control, or the hardware back button on the 
		 *				device.
	 */
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source) = 0;


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
    virtual void IFormBackEventListener_Reserved1 (void) { } 

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
    virtual void IFormBackEventListener_Reserved2 (void) { } 

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
    virtual void IFormBackEventListener_Reserved3 (void) { } 

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
    virtual void IFormBackEventListener_Reserved4 (void) { } 

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
    virtual void IFormBackEventListener_Reserved5 (void) { } 
}; 

}; /* Osp::Ui::Controls */ }; /*Osp::Ui*/ }; /* Osp */

#endif // _FUICTRL_IFORM_BACK_EVENT_LISTENER_H_

