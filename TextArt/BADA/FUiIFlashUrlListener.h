// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file	FUiIFlashUrlListener.h 
 * @brief	This is the header file for the %IFlashUrlListener interface.
 *
 * This header file contains the declarations of the %IFlashUrlListener interface. @n
 * If a flash URL event is generated, a method of this class is called.
 *
 */
#ifndef _FUI_IFLASH_URL_LISTENER_H_
#define _FUI_IFLASH_URL_LISTENER_H_

#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	IFlashUrlListener 
 * @brief		This interface implements the listener for Flash getURL() (navigateToURL() in ActionScript 3.0).
 * @since		1.1
 *
 * The %IFlashUrlListener interface is the listener interface for receiving flash URL events. This interface must be implemented, if the Actionscript in
 * the flash content uses built-in functions that request URL loading.
 * The class that processes a flash URL event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddFlashUrlListener() method. When the flash URL event occurs, the OnFlashUrlLoaded()
 * method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.flashappprogramming.help/html/dev_guide/loading_URLs.htm">Loading URLs</a>.


 */


class _EXPORT_UI_ IFlashUrlListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	* This is the destructor for this class.
	*
	* @since			1.1
	*/
	virtual ~IFlashUrlListener(void) {}

	
	/**
	* Called when the flash content requests for URL loading. @n
	* When an ActionScript calls the getURL() method (nativateToURL() in ActionScript 3.0), the application can load the URL using a %Web control.
	*
	* @since		1.1
	* @param[in] 	source			The source of the event
	* @param[in] 	url				The flash URL text
	*/
	virtual void OnFlashUrlLoaded(const Osp::Ui::Control& source, const Osp::Base::String& url) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IFLASH_URL_LISTENER_H_
