/* $Change: 1224223 $ */
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
 * @file	FUiCtrlFlash.h
 * @brief	This is the header file for the %Flash class.
 *
 * This header file contains the declarations of the %Flash class and its helper classes.
 */

#ifndef _FUICTRL_FLASH_H_
#define _FUICTRL_FLASH_H_

// Includes
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlFlashEnum.h"
#include "FNetNetTypes.h"
#include "FNetNetAccountManager.h"
#include "FUiIFlashEventListener.h"
#include "FUiIFlashUrlListener.h"
#include "FUiIFlashRenderingEventListener.h"

namespace Osp { namespace 	Ui { namespace Controls {

/**
 * @class	Flash
 * @brief 	This class defines the common behavior of a %Flash control.
 * @since	1.0
 *
 * The %Flash class can be used to play %Flash content embedded in the application.
 * 
 * For more information on the class features, see <a href="../com.osp.flashappprogramming.help/html/dev_guide/flash_control.htm">Flash Control</a>.
 *
 * The following example demonstrates how to use the %Flash class for movie playback.
 *
 * @code
 
// Sample code for FlashSample.h
#include <FBase.h>
#include <FUi.h>
#include <FBase.h>
#include <FGraphics.h>

class FlashSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IFlashEventListener,
    public Osp::Ui::IFlashUrlListener,
    public Osp::Ui::IFlashRenderingEventListener
{

public:
    static const int REQUEST_FLASH_PLAY = 100;

    virtual result OnInitializing(void);
    void PlayFlash(void);

public:
    virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs);
    virtual void OnFlashDataReceived(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList);
    virtual void OnFlashDataReturned(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList);
    virtual void OnFlashTextEntered(const Osp::Ui::Control& source, Osp::Ui::FlashTextInputMode inputMode, const Osp::Base::String& defaultText, int limitTextLength);
    virtual void OnFlashLayoutChanged(const Osp::Ui::Control& source, Osp::Ui::FlashLayoutStyle layoutStyle);
    virtual void OnFlashUrlLoaded(const Osp::Ui::Control& source, const Osp::Base::String& flashUrl);
    virtual void OnFlashRenderingCompleted(const Osp::Ui::Control& source, Osp::Graphics::Canvas& canvas);

private:
    Osp::Ui::Controls::Flash *__pFlash;
};

// Sample Code for FlashSample.cpp
#include "FlashSample.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
FlashSample::OnInitializing(void)
{
	// Creates flash
	__pFlash = new Flash();
	__pFlash->Construct(Rectangle(0,0,GetClientAreaBounds().width, GetClientAreaBounds().height), FLASH_STYLE_NORMAL, L"/Res/Bada.swf");

	// Adds a flash to the form
	AddControl(*__pFlash);

	// Sends a User Event
	SendUserEvent(REQUEST_FLASH_PLAY, null);

	return E_SUCCESS;
}

void
FlashSample::PlayFlash()
{
	__pFlash->AddFlashEventListener(*this);
	__pFlash->AddFlashUrlListener(*this);
	__pFlash->AddFlashRenderingEventListener(*this);

	// Displays the form
	Draw();
	Show();

	// Sets focus
	__pFlash->SetFocus();

	// Plays flash
	__pFlash->Play();
}

void
FlashSample::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	if(requestId == REQUEST_FLASH_PLAY)
		PlayFlash();
}

// Implements an IFlashEventListener
void
FlashSample::OnFlashDataReceived(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList)
{
	// Receives data from the flash content
}

void
FlashSample::OnFlashDataReturned(const Osp::Ui::Control& source, const Osp::Base::Collection::IList& paramList)
{
	// Returns data to the flash content
}

void
FlashSample::OnFlashTextEntered(const Osp::Ui::Control& source, Osp::Ui::FlashTextInputMode inputMode, const Osp::Base::String& defaultText, int limitTextLength)
{
	// Loads a keypad to enter text
}

void
FlashSample::OnFlashLayoutChanged(const Osp::Ui::Control& source, Osp::Ui::FlashLayoutStyle layoutStyle)
{
	// Changes form style or flash dimension
}

// Implements an IFlashUrlListener
void
FlashSample::OnFlashUrlLoaded(const Osp::Ui::Control& source, const Osp::Base::String& flashUrl)
{
	// Launches a %Web browser to load the flash Url
}

void
FlashSample::OnFlashRenderingCompleted(const Osp::Ui::Control& source, Osp::Graphics::Canvas& canvas)
{
	// Draws with a canvas
}

 * @endcode
 *
 */

/**
* @page			Supportedfscommand2 Supported fscommand2 list in bada SDK
*
* @section      CategoryGeneral			General
*				-# <b>Escape</b> @n
*					Escape global function. @n@n
*				-# <b>FullScreen</b> @n
*					Sets the size of the display area. @n@n
*				-# <b>SetQuality</b> @n
*					Sets the quality of the content. @n@n				
*				-# <b>Unescape</b> @n
*					Unescape global function. @n@n
*
* @section		CategoryPowerSignal		Power / Signal
*				-# <b>GetBatteryLevel</b> @n
*					The current battery level. @n@n
*				-# <b>GetMaxBatteryLevel</b> @n
*					The maximum battery level of the device. @n@n
*				-# <b>GetPowerSource</b> @n
*					The power source is currently charging or on battery. @n@n
*				-# <b>GetSignalLevel</b> @n
*					The current signal strength as a numeric value. @n@n
*
* @section		CategoryMMI				MMI
*				-# <b>Get / GetVars</b> @n
*					Get values from the device. @n@n
*				-# <b>Set / SetVars</b> @n
*					Set values to the device. @n@n
*				-# <b>Send</b> @n
*					Send an event to the device. @n@n
*
* @section		CategoryVolume			Volume
*				-# <b>GetMaxVolumeLevel</b> @n
*					The maximum volume level of the device as a numeric value. @n@n
*				-# <b>GetVolumeLevel</b> @n
*					The current volume level of the device as a numeric value. @n@n
*
* @section      CategoryHandset			Handset
*				-# <b>GetDevice</b> @n
*					The device on which %Flash Lite is running. @n@n
*				-# <b>GetDeviceID</b> @n
*					The unique identifier of the device. @n@n
*				-# <b>GetLanguage</b> @n
*					The current language of device. @n@n
*				-# <b>GetPlatform</b> @n
*					The current platform, which broadly describes the class of device. @n@n
*
* @section		CategoryMemory			Memory
*				-# <b>GetFreePlayerMemory</b> @n
*					The amount of heap memory, in kilobytes, currently available to %Flash Lite. @n@n
*				-# <b>GetTotalPlayerMemory</b> @n
*					The total amount of heap memory, in kilobytes, allocated to %Flash Lite. @n@n
*
* @section		CategoryDateTime		Date / Time
*				-# <b>GetDateDay</b> @n
*					The current day. @n@n
*				-# <b>GetDateMonth</b> @n
*					The current month. @n@n
*				-# <b>GetDateYear</b> @n
*					The current year. @n@n
*				-# <b>GetDateWeekDay</b> @n
*					The current weekday. @n@n
*				-# <b>GetLocaleLongDate</b> @n
*					The Long date format of current locale. @n@n
*				-# <b>GetLocaleShortDate</b> @n
*					The Short date format of current locale. @n@n
*				-# <b>GetLocalTime</b> @n
*					The local time. @n@n
*				-# <b>GetTimeHours</b> @n
*					The current hours. @n@n
*				-# <b>GetTimeMinutes</b> @n
*					The current minutes. @n@n
*				-# <b>GetTimeSeconds</b> @n
*					The current seconds. @n@n
*				-# <b>GetTimeZoneOffset</b> @n
*					The time zone offset. @n@n
*
* @section		CategoryVibration		Vibration
*				-# <b>StartVibrate</b> @n
*					Begin device vibration. @n@n
*				-# <b>StopVibrate</b> @n
*					Stop vibration. @n@n
*			
* @section		CategoryNetwork			Network
*				-# <b>GetNetworkConnectionName</b> @n
*					The name of the active or default network connection. @n@n
*				-# <b>GetNetworkConnectStatus</b> @n
*					The current network connection status. @n@n
*				-# <b>GetNetworkGeneration</b> @n
*					The current mobile wireless network (such as 2G or 3G). @n@n
*				-# <b>GetNetworkName</b> @n
*					The name of the current network. @n@n
*				-# <b>GetNetworkRequestStatus</b> @n
*					The status of the most recent HTTP request. @n@n
*				-# <b>GetNetworkStatus</b> @n
*					The network status of the phone (that is, whether there is a network registered and whether the phone is currently roaming). @n@n
*
*/

class _EXPORT_CONTROLS_ Flash
	: public Osp::Ui::Control
{
	DECL_CLASSTYPE(Flash);
	
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	Flash(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~Flash(void);

	/**
	* Initializes this instance of %Flash with the specified rectangular region, style, and file paths.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
    *               	For more information, see issues in version @ref FlashConstructPage "1.2" and @ref FlashConstructExceptionPage "2.0".
    *
	* @privlevel		NORMAL
	* @privgroup		FLASH_SERVICE	 
	* 
	* @return			An error code
	* @param[in]		rect					The (X,Y) coordinates of the top-left of the created window @n
	*											The width and height of the window.
 	* @param[in]		style					The style of the %Flash object
	* @param[in]		flashFilePath			The local file path for the %Flash object
	* @param[in]		basePath				The working directory of ActionScript
	*
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_OUT_OF_MEMORY  		The memory is insufficient.
	* @exception		E_INVALID_STATE			This instance has already been constructed.
	* @exception		E_INVALID_ARG			A specified input parameter is invalid.
	* @exception		E_NETWORK_FAILED		The network is unavailable. @n
	*							@b Deprecated: This exception is deprecated.
	* @exception        E_UNSUPPORTED_VERSION   The content version is not supported in this device.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception		E_SYSTEM				A system error has occurred.
	* @remarks			A control is usable if it is added to a container. Therefore, some methods may fail if used earlier. @n
	*					Do not use the general flash animation contents for the URL file path.
	*/
	result Construct(const Osp::Graphics::Rectangle& rect, FlashStyle style, const Osp::Base::String& flashFilePath, const Osp::Base::String& basePath = L"");

	/**
	* @page	FlashConstructPage	Compatibility for result Construct();
	*
	* @section	FlashConstructPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* -# The Flash control must be located in the top-left quadrant of the screen for auto-scale to work.
	*
	* @section	FlashConstructPageSolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2. @n
	*/

	/**
    * @page	FlashConstructExceptionPage	Compatibility for result Construct();
    *
    * @section	FlashConstructExceptionPageIssueSection		Issues
    * 			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
    * 				-# Returns E_SYSTEM when the version of the flash content is higher than that supported by the bada SDK.
    * 				-# The %Flash control can be constructed without the FLASH_SERVICE privilege.
    *
    * @section	FlashConstructExceptionPageSolutionSection		Resolutions
    *			The issue mentioned above is resolved in bada API version 2.0 as follows: @n
    *				-# Returns E_UNSUPPORTED_VERSION when the version of the flash content is higher than that supported by the bada SDK.	
    *				-# Returns E_PRIVILEGE_DENIED when the application does not have the FLASH_SERVICE privilege.
	*				
    */

	/**
	* Adds an IFlashEventListener instance. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since		1.0
	* @param[in]	listener 	The listener to be added
	*/
	void AddFlashEventListener(const Osp::Ui::IFlashEventListener& listener);

	/**
	* Adds an IFlashRenderingEventListener instance. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 		2.0
	* @param[in]	listener 	The listener to be added
	*/
	void AddFlashRenderingEventListener(const Osp::Ui::IFlashRenderingEventListener& listener);

	/**
	* Adds an IFlashUrlListener instance. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since 		1.1
	* @param[in]	listener 	The listener to be added
	*/
	void AddFlashUrlListener(const Osp::Ui::IFlashUrlListener& listener);

	/**
	* Removes an IFlashEventListener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener 	The listener to be removed
	*/
	void RemoveFlashEventListener(const Osp::Ui::IFlashEventListener& listener);

	/**
	* Removes an IFlashRenderingEventListener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 		2.0
	* @param[in]	listener 	The listener to be removed
	*/
	void RemoveFlashRenderingEventListener(const Osp::Ui::IFlashRenderingEventListener& listener);

	/**
	* Removes an IFlashUrlListener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since 		1.1
	* @param[in]	listener 	The listener to be removed
	*/
	void RemoveFlashUrlListener(const Osp::Ui::IFlashUrlListener& listener);


	/**
	* Starts a flash animation. @n
	* Only one flash file can be played at a time.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
    *                   For more information, see issues in version @ref FlashPlayPage "1.2" and @ref FlashPlayPage2 "2.0".
    *
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.
    */
	void Play(void);

	/**
	* @page		FlashPlayPage				Compatibility for result Play(void)
	*
	* @section	FlashPlayPageIssueSection		Issues
	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*				-# The Flash control continues to play without sound when the sound resource is required by a higher priority task, such as an incoming call or alarm.
	*
	* @section	FlashPlayPageChangeSection		Resolutions
	*				The issue mentioned above is resolved in bada API version 1.2.
	*/

    /**
    * @page     FlashPlayPage2		Compatibility for result Play(void) 
    *
    * @section  FlashPlayPage2IssueSection			Issues
    *           Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
    *           	-# This method does not set any exceptions. Therefore, GetLastResult() returns an unreliable value. @n    
    *				-# This method can resume the flash playback. @n
    *				-# Flash can load any resource, for example, image, or video located in an untrusted location. @n
    *
    * @section  FlashPlayPage2SolutionSection		Resolutions
    *           The issues mentioned above are resolved in bada API version 2.0 as follows: @n
    *           	-# It is possible to obtain appropriate exceptions by using the GetLastResult()method. @n    
    *           	-# If this method is called while flash is in the FLASH_PAUSED or FLASH_PLAYING state, GetLastResult() returns E_INVALID_STATE. @n
    *           	-# Flash decides whether to play the content. It depends on the security option flag set while publishing the content from a
	*					Flash authoring tool. @n
    */	

    /**
    * @page     FlashResumePage		Compatibility for result Play(void) 
    *
    * @section  FlashResumePageIssueSection			Issues
    *           Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
    *           	-# This method does not set any exceptions. Therefore, GetLastResult() returns an unreliable value. @n    
    *				-# This method can play the flash playback. @n
    *
    * @section  FlashResumePageSolutionSection		Resolutions
    *           The issues mentioned above are resolved in bada API version 2.0 as follows: @n
    *           	-# It is possible to obtain appropriate exceptions by using the GetLastResult()method. @n    
    *           	-# If this method is not called while flash is in the FLASH_PAUSED state, GetLastResult() returns E_INVALID_STATE. @n
    */	

    /**
    * @page     FlashPlayExceptionPage		Compatibility for Flash 
    *
    * @section  FlashPlayExceptionPageIssueSection			Issues
    *           Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
    *           	-# This method does not set any exceptions. Therefore, GetLastResult() returns an unreliable value. @n
    *
    * @section  FlashPlayExceptionPageSolutionSection		Resolutions
    *           The issue mentioned above is resolved in bada API version 2.0 as follows: @n
    *           	-# It is possible to obtain appropriate exceptions by using the GetLastResult()method. @n
    */

	/**
	* Stops a flash animation.
	*
	* @since	1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*               	For more information, see @ref FlashPlayExceptionPage "here".
	*
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.    
    */
	void Stop(void);

	/**
	* Pauses a flash animation.
	*
	* @since		1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*               	For more information, see @ref FlashPlayExceptionPage "here".
	*
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.    
	*/
	void Pause(void);

	/**
	* Resumes a flash animation.
	*
	* @since		1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*               	For more information, see @ref FlashResumePage "here".
	*
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.    
	*/
	void Resume(void);

	/**
	 * Sets the quality of a flash animation.
	 *
	 * @since		1.0
	 * @param[in]	quality 	The quality of the flash animation
	 */
	void SetQuality(FlashQuality quality);

	/**
	* Gets the quality of the flash animation.
	*
	* @since		1.0
	* @return		The quality of the flash animation
	*/
	FlashQuality GetQuality(void) const;

	/**
	* Sets the repeat mode of the flash animation.
	*
	* @since		1.0
	* @param[in]	repeatMode 		The repeat mode of the flash animation
	*/
	void SetRepeatMode(FlashRepeatMode repeatMode);

	/**
	* Gets the repeat mode of the flash animation.
	*
	* @since		1.0
	* @return		The repeat mode of the flash animation
	*/
	FlashRepeatMode GetRepeatMode(void) const;

	/**
	* Enables or disables the sound.
	*
	* @since		1.0
    * @param[in]	enable		Set to @c true to enable the sound, @n
    *                        	else @c false
	*/
	void SetSoundEnabled(bool enable);

	/**
	* Checks whether the sound is enabled.
	*
	* @since		1.0
	* @return		@c true if the sound is enabled, @n
	*				else @c false
	*/
	bool IsSoundEnabled(void) const;

	/**
	* Gets the playing status of the flash animation.
	*
	* @since		1.0
	* @return		The playing status of the flash animation
	*/
	FlashStatus GetStatus(void) const;

	/**
	* Sends the data to the ActionScript in a flash animation.
	*
	* @since		1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*               	For more information, see @ref FlashPlayExceptionPage "here".
	*	
	* @param[in]	data	The data to be sent to the ActionScript
	*
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	void SendDataToActionScript(const Osp::Base::String& data);

	/**
	* Sends the data to the ActionScript when the ActionScript receives the specified event from an application.
	*
	* @since		1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*               	For more information, see @ref FlashPlayExceptionPage "here".
	*
	* @param[in]	actionScriptListener	The name of the specified event
	* @param[in]	dataValueList		    A list of the data
	*
	* @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    * @exception    E_SYSTEM            A system error has occurred.
    * @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	void SendDataEventToActionScript(const Osp::Base::String& actionScriptListener, const Osp::Base::Collection::IList& dataValueList);

	/**
	* Sets the background color of the flash. @n
	* The color is set on the %Flash control including the background area of the content. 
    * The background color is displayed when at least one frame of the flash content is played.
	*
	* @since		1.0
	* @param[in]	color		The normal background color
	*/
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	* Gets the background color of the current instance of the %Flash control.
	*
	* @since		1.0
	* @return		The background color
	*/
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;

	/**
	* Enters the text into the flash text input field, and resumes the flash playback. @n
	* This method can be used after the OnFlashTextEntered() event callback is called.
	*
	* @since		1.0
	* @param[in]	text				The text block to be entered
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result EnterText(const Osp::Base::String& text);

	/**
	* Cancels the text input and resumes the flash playback. @n
	* This method can be used after the OnFlashTextEntered() event callback is called.
	*
	* @since 		1.1
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	result CancelText(void);

    /**
    * Sets the volume of the current instance of the %Flash control. @n
	* The range of the volume is from @c 0 to @c 100.
    *
    * @since		1.0
    * @param[in]	volume				The new value of volume
    * @exception	E_SUCCESS			The method is successful.
    * @exception	E_OUT_OF_RANGE 		The specified volume is out of range.
    * @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
    */	
    result SetVolume(int volume);

    /**
    * Gets the volume of the current instance of the %Flash control.
    *
    * @since		1.0
    * @return		An integer value representing the current volume level @n
    *				The range of the return value is from @c 0 to @c 100.
    */
    int GetVolume(void) const;

protected:

	/**
    * @internal    
    * This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
	*
	* Frees the resources allocated by this control and destroys its native window if it is present).
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS	The method was successful.
	* @exception	E_SYSTEM	Failed to free the resource possessed by this instance.
	*/
	result Dispose(void);

private:

	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The Flash Event Adaptor.
    * @since         1.0
    */
	void* __pFlashEventAdaptor;

	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The Flash Event.
    * @since         1.0
    */
	Osp::Base::Runtime::IEvent* __pFlashEvent;

	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The network account manager
    * @since         1.0
    */	
    Osp::Net::NetAccountManager* __pNetAccountManager;

	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The network account id
    * @since         1.0
    */	
    Osp::Net::NetAccountId	__netAccountId;

	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The current Flash instance
    * @since         1.0
    */	
    static Flash* __pFlashInstance;

private:
	friend class FlashEx;
	/**
    * @internal    
    * This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The internal data structure
    * @since         1.0
    */
	class FlashEx* __pFlashEx;

protected:
	friend class FlashImpl;
	/**
    * @internal    
    * This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
	*
	* Gets the implementation instance of this control
	*
	* @since         2.0
	*/
	class FlashImpl* GetImpl(void) const;
};
}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_FLASH_H_
