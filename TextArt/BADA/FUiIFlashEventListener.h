// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiIFlashEventListener.h 
 * @brief		This is the header file for the %IFlashEventListener interface.
 *
 * This header file contains the declarations of the %IFlashEventListener interface. @n
 * If a flash event is generated, a method of this class is called.
 * 
 */
#ifndef _FUI_IFLASH_EVENT_LISTENER_H_
#define _FUI_IFLASH_EVENT_LISTENER_H_

#include "FUiConfig.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

	/**
	* @enum		FlashLayoutStyle
	* Defines the constants to identify the layout style.
	*
	* @since	1.0
	*/
	enum FlashLayoutStyle
	{
		FLASH_LAYOUT_STYLE_FULLSCREEN = 0,		/**< The layout style is full screen */
		FLASH_LAYOUT_STYLE_CLIENT				/**< The layout style is client */
	};

	/**
	* @enum	FlashTextInputMode
	* Defines the constants to identify the text input mode.
	*
	* @since	1.0
	*/
	enum FlashTextInputMode
	{
		FLASH_TEXT_INPUTMODE_NORMAL = 0,		/**< The text input mode is normal */
		FLASH_TEXT_INPUTMODE_PASSWORD			/**< The text input mode is password */
	};

/**
 * @interface	IFlashEventListener 
 * @brief		This interface implements the listener for the item event.
 * @since		1.0
 *
 * The %IFlashEventListener interface is the MMI interface between the flash content and the host application for receiving flash events.
 * The class that processes a flash event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddFlashEventListener() method. When Set or SetVars is used as a parameter for the fscommand2()
 * method in ActionScript when a specific event occurs, the OnFlashDataReceived() method is invoked. Similarly, if Get or GetVars
 * is used, the OnFlashDataReturned() method is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.flashappprogramming.help/html/dev_guide/flash_interact.htm">Interacting with Flash Content</a>.

 */

class _EXPORT_UI_ IFlashEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IFlashEventListener(void) {}

	/**
	* @page		OnFlashDataReceivedPage Compatibility for OnFlashDataReceived()
	*
	* @section	OnFlashDataReceivedPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 2.0 has following issues: @n
	*			-# When the Set/SetVars command is used as a parameter for fscommand2() in ActionScript, the platform invokes OnFlashDataReceived()
	*				asynchronously. @n
	*			-# The flash ActionScript is continuously processed without waiting for the result of fsommand2(). @n
	*
	* @section	OnFlashDataReceivedPageSolutionSection Resolutions
	*			-# When the Set/SetVars command is used as a parameter for fscommand2() in ActionScript, the platform invokes OnFlashDataReceived()
	*			  synchronously. @n
	*			-# Processing the flash Actionscript is temporarily stopped till the result from fscommand2() is received.
	*/
	
	/**
	 * Called when the Set/SetVars command is used as a parameter for fscommand2() in ActionScript
	 * (fscommand2(command:String, parameter1:String, ..., parameterN:String)).
	 * The methods of the Flash class cannot be used in this listener.
	 *
	 * @since		1.0
	 *
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref FlashDataReceivedPage "here".
	 *
	 * @param[in] 	source				The source of the event
	 * @param[in] 	paramList			The parameter list
	 */
	virtual void OnFlashDataReceived(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList) = 0;

	/**
	 * Called when the Get/GetVars command is used as a parameter for fscommand2() in ActionScript
	 * (fscommand2(command:String, parameter1:String, ..., parameterN:String)).
	 * The methods of the Flash class cannot be used in this listener.
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	paramList		The parameter list
	 */
	virtual void OnFlashDataReturned(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList) = 0;

	/**
	 * Called when a request is made to enter the text in ActionScript. %Flash is paused when this listener is called.
	 * The EnterText() and CancelText() methods of the Flash class must be called to resume the playback.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1.@n
	 *                	For more information, see @ref OnFlashTextEnteredPage "here".
	 *
	 * @param[in]	source				The source of the event
	 * @param[in]	inputMode			The text input mode
	 * @param[in]	defaultText			The default text
	 * @param[in]	limitTextLength		The limit length of the text
	 */

	virtual void OnFlashTextEntered(const Osp::Ui::Control& source, FlashTextInputMode inputMode, const Osp::Base::String& defaultText, int limitTextLength) = 0;
	
	/**
	* @page	OnFlashTextEnteredPage	Compatibility for OnFlashTextEntered()
	*
	* @section	OnFlashTextEnteredPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.1 has following issue: @n
	* -# The @c limitTextLength parameter returns an unreliable value, independent of the flash content. Therefore, it should not be used.
	*
	* @section	OnFlashTextEnteredPageSolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	* @par When working with bada API versions prior to 1.1: @n
	* When constructing an EditField, Keypad, or other text controls in this listener, explicitly specify a value sufficient for the use case.
	*/

	/**
	 * Called when a request is made to change the layout style in the ActionScript.
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	layoutStyle		The layout style (FULLSCREEN / CLIENT)
	 */
	virtual void OnFlashLayoutChanged(const Osp::Ui::Control& source, FlashLayoutStyle layoutStyle) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IFLASH_EVENT_LISTENER_H_

