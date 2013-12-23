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
 * @file		FWebCtrlIWebKeypadEventListener.h
 * @brief		This is the header file for the %IWebKeypadEventListener interface.
 *
 * This header file contains the declarations of the %IWebKeypadEventListener interface.
 */


#ifndef _FWEBCTRL_IWEBKEYPADEVENTLISTENER_H_
#define _FWEBCTRL_IWEBKEYPADEVENTLISTENER_H_

#include "FBase.h"
#include "FWebConfig.h"


namespace Osp { namespace Web { namespace Controls {


/**
 * @interface	IWebKeypadEventListener
 * @brief	    This interface provides a listener for keypad events invoked by the <textarea> or <input> tag, which has "text" or "password" value as its attribute.
 * @since	    2.0
 *
 * The %IWebKeypadEventListener interface provides a listener for keypad events invoked by the <textarea> or <input> tag, which has "text" or "password" value as its attribute.
 * It also enables the implementer class to receive the overlay keypad related events.
 */


class _EXPORT_WEB_ IWebKeypadEventListener : 
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */	
	virtual ~IWebKeypadEventListener(void) {}

// Operation
public:
	/**
	 * Called when the keypad is about to be shown on the screen.
	 *
	 * @since	    	2.0
	 * @param[in] 	source	The source of the event
	 * @remarks			When the overlay keypad appears on the screen, the current form's
	 *              area is adjusted to account for the space that is taken up by the overlay keypad.
	 * @see       Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadWillOpen(Osp::Web::Controls::Web& source) = 0;

	/**
	 * Called when the keypad is shown on the screen.
	 *
	 * @since	    	2.0
	 * @param[in] 	source	The source of the event
	 * @remarks			When the overlay keypad appears on the screen, the current form's
	 *              area is adjusted to account for the space that is taken up by the overlay keypad.
	 * @see       Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadOpened(Osp::Web::Controls::Web& source) = 0;

	/**
	 * Called when the keypad is hidden from the screen.
	 *
	 * @since	    	2.0
	 * @param[in] 	source	The source of the event
	 * @see         Osp::Ui::Controls::Form::GetClientAreaBounds()
	 */
	virtual void OnWebKeypadClosed(Osp::Web::Controls::Web& source) = 0;

	
	
protected :

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IWebKeypadEventListener_Reserved1 (void) { } 

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IWebKeypadEventListener_Reserved2 (void) { } 
		
	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/		
	virtual void IWebKeypadEventListener_Reserved3 (void) { } 

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IWebKeypadEventListener_Reserved4 (void) { } 

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IWebKeypadEventListener_Reserved5 (void) { } 
	
};

}; };};
#endif


