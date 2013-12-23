/* $Change: 1232335 $ */
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
 * @file			FAppApplication.h
 * @brief			This is the header file for the %Application class.
 * 
 * This header file contains the declarations of the %Application class.
 */

#ifndef _FAPP_APPLICATION_H_
#define _FAPP_APPLICATION_H_


#include "FBaseObject.h"
#include "FSysBattery.h"
#include "FSysPower.h"
#include "FAppConfig.h"
#include "FAppTypes.h"

namespace Osp { namespace Base { namespace Collection { class HashMap; }; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {


class Application;
class AppRegistry;
class AppResource;
class AppProperty;
class AppManager;
class IAppProxy;
class IAppFrame;
class __NativeApplication;


typedef	Application* (*ApplicationInstanceFactory)(void);


/**
 * @class		Application
 * @brief		This class is the base class of a bada application.
 * @since		1.0
 *
 * The %Application class is the base class of a bada application.
 * An application must inherit from this class when it is created. This class provides the basic features necessary to define the
 * application.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/app_namespace.htm">App Guide</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/system_events.htm">System Events</a>.
 *
 
 */
class _EXPORT_APP_ Application :
	public Osp::Base::Object
{
// Lifecycle
protected:
	/**
	 * This is the default constructor for this class.
 	 *
	 * @since		1.0
	 */
	Application(void);


// Lifecycle
private:
	/**
	 * This is the copy constructor for the %Application class.
	 */
	Application(const Application& value);


// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Application(void);


// Operator
private:
	/**
	 * This is the assignment operator for this class.
	 */
	Application& operator=(const Application& source);


// Access
public:
	/**
	 * Gets the frame of an application. @n
	 * The frame is the outermost boundary of an application. An application's frame 
	 * carries a canvas and all the UI events are generated within this frame.
	 *
	 * @since		1.0
	 *
	 * @return	A pointer to the IAppFrame interface, @n
	 *			else @c null if it fails or it is invoked from OnAppTerminating()
	 * @remarks	This method may return @c null if called from the desctrctor of UI controls.
	 */
	IAppFrame* GetAppFrame(void) const;


	/**
	 * Gets the instance that manages the application's states and preferences.
	 *
	 * @since		1.0
	 *
	 * @return	A pointer to the AppRegistry instance, @n
	 *			else @c null if it fails
	 */
	AppRegistry* GetAppRegistry(void) const;


	/**
	* Gets the object that manages an application's resources.
	*
	* @since		1.0
	* @return	A pointer to the AppResource instance, @n
	*		    else @c null if it fails
	*/
	AppResource* GetAppResource(void) const;


	/**
	* Gets the list of the launch arguments. @n
	* The launch arguments can be obtained from Application::OnAppInitializing(). These arguments enable an application to
    * prepare the UI elements well,
	* such as constructing an appropriate form that is to be displayed right after the application is launched. @n
	* Note that since API version 1.1, the information is provided to the application as the input parameters 
    *       for Application::OnUserEventReceivedN(). This event handler is most useful in handling service requests from
	*       another application or platform when the target application is already being executed.
	*
	* For more information on the launch arguments, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	*				For more information, see @ref CompGetAppArgumentListNPage "here".
	* @return	A pointer to the list (ArrayList preferred) that contains the String instances
	* @see AppControl, OnUserEventReceivedN(), AppManager::LaunchApplication(), AppManager::RegisterAppLaunch(),
	* 		AppManager::StartAppControl()
	*/
	Osp::Base::Collection::IList* GetAppArgumentListN(void) const;

	/**
	 * @page	CompGetAppArgumentListNPage Compatibility for GetAppArgumentListN()
	 * @section	CompGetAppArgumentListNPageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue:
	 *
	 *	-# The values of args[0] to args[2] for the following methods have changed from bada API version 2.0.
	 *	<table border="1" cellpadding="1" cellspacing="1">
	 *	<tr><th>&nbsp;</th><th>%Application Launch (AppManager::LaunchApplication) or Notification (NotificationManager)</th>
	 *	<th>Conditional %Application Launch (AppManager::RegisterAppLaunch)</th></tr>
	 *	<tr><td>args[0]</td><td align="center" colspan="2">path of application executable</td></tr>
	 *	<tr><td>args[1]</td><td align="center">"osp.appcontrol.APPMGR"</td><td align="center">"osp.appcontrol.CONDMGR"</td></tr>
	 *	<tr><td>args[2]</td><td align="center" colspan="2">"osp.operation.MAIN"</td></tr>
	 *	<tr><td>args[>=3]</td><td align="center" colspan="2">actual arguments</td></tr>
	 *	</table>
	 *
	 */


	/**
	 * Gets the current state of the application.
	 *
	 * @since		1.0
	 * @return	The current state of the application in an AppState object
	 */
	AppState GetAppState(void) const;


	/**
	 * Gets the name of the application. @n
	 * If the language is changed, this method returns the localized application name. 
	 *
	 * @since		1.0
	 * @return	The application name
	 * @remarks	Do not override this method.
	 */
	virtual Osp::Base::String GetAppName(void) const;

	/**
	 * Gets the application's version.
	 *
	 * @since		1.0
	 * @return	The application version
	 */
	Osp::Base::String GetAppVersion(void) const;


	/**
	 * Gets the application's ID.
	 *
	 * @since		1.0
	 * @return	The application ID
	 * @remarks	Do not override this method.
	 */
	virtual AppId GetAppId(void) const;
	
// Access
protected:
	/**
	* Gets the application's secret code.
	*
	* @since	1.0
	* @return	The application secret code
	* @remarks	Do not override this method.
	*/
	virtual AppSecret GetAppSecret(void) const; 

// Operation
public:
	/**
	 * Terminates an application while it is running. @n
	 * The OnAppTerminating() method is called after this method is executed successfully.
	 *
	 * @since			1.0
	 * @return An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result Terminate(void);


	/**
	 * Called when an application's state changes to App::INITIALIZING. @n
	 * In general, most of the activities involved in initializing an application, including restoring the application's states, should be done in this method.
	 * After this method succeeds, the application's state changes to App::RUNNING.
	 * If the method fails, the application's state changes to App::TERMINATING and the OnAppTerminating() method is called subsequently.
	 *
	 * @since		1.0
	 * @return	@c true if the method is successful, @n
	 *		else @c false
	 * @param[in]	appRegistry		The instance that manages the application's states
	 * @remarks	Introducing the modal dialogs (for example, MessageBox) in this method is not allowed, because it blocks the initialization procedure.
	 */
	virtual bool OnAppInitializing(AppRegistry& appRegistry)= 0;


	/**
	 * Called when an application's state changes from App::RUNNING to App::TERMINATING. @n
	 * All the activities involved in terminating the application, including saving the application's states, should be done in this method.
	 * After this method, the application code cannot be implemented. The application is destroyed subsequently.
	 *
	 * @since		1.0
	 * @return	@c true if the method is successful, @n
	 *			else @c false
	 * @param[in]	appRegistry			The instance that manages the application's states
	 * @param[in]	forcedTermination	Set to @c true if the application is terminated by interruptions, @n
	 *									else @c false
	 * @remarks	Accessing UI is not allowed in this method.
	 */
	virtual bool OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination = false)= 0;


    /**
     * Called when an application moves to the foreground. @n
     *
     * User interaction is enabled when the application is in the foreground. @n
	 * An application moves to the foreground when:
	 *
     * - An application is selected from the Task Manager.
     * - An application icon in the Launcher application is pressed when it is running in the background.
     * - An application is to be launched while it is running in the background.
     * - A system pop-up such as an incoming call, notification (for example, SMS), or a low battery warning 
	 *    pop-up disappears.
     *
     *
     * %OnForeground() is called when the application is moved to the foreground. @n
     * When the %OnForeground() method is invoked, the following actions are recommended:
	 *
     * - Resume the graphic processing such as 3D or animation, as the application now has the focus.
     * - Resume the operations that stopped when the application is last moved to the background.
     *
     * @since					1.0
     * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
     *                    For more information, see @ref CompApplicationOnForeground "here".
     * @remarks      When the system needs to refresh a screen component, it can call the %OnForeground() method even if the application is present in the foreground.
     */
    virtual void OnForeground(void);

    /**
     * @page CompApplicationOnForeground Compatibility for OnForeground()
     * @section CompApplicationOnForegroundIssues Issues
     *    Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
     *
     * -#  When a full-screen UI control such as DatePicker or Keypad disappears, OnForeground() is called.
     *
     * @section CompApplicationOnForegroundResolutions Solutions
     * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above.
     */


	/**
	 * Called when another application moves to the top or the system pop-up is displayed. @n
	 * User interaction is disabled when the application is in the background. @n
	 * An application moves to the background when:
	 *
	 * - A system pop-up such as an incoming call or a low battery warning pop-up is displayed.
	 * - A device is locked.
	 * - The Home key is pressed.
	 *
	 * %OnBackground() is called when the application is moved to the background. @n
	 * Whenever %OnBackground() is invoked, the following actions are recommended:
	 *
	 * - Stop the graphic processing such as 3D or animation, as they will not be displayed.
	 * - Release unnecessary resources.
	 * - Stop media processing, manipulations, and location updates.
	 * 
	 * @since		1.0
	 * @remarks	When notification (for example: SMS) pops up, %OnBackground() is not called.
	 *			When a system pop-up is displayed, an application becomes partially hidden 
	 *			(App::APP_UI_STATE_PARTIAL_BACKGROUND).
	 *			If an application is partially hidden, it is recommended to hold the activated 
	 *			tasks or resources instead of stopping or releasing them.
	 * @see GetAppUiState()
	 */
	virtual void OnBackground(void);


	/**
	 * Called when the system detects that the system wide memory or application heap is insufficient to run the application any further. @n
	 * Resources that are not in use currently can be released in this method.
	 *
	 * @since		1.0
	 */
	virtual void OnLowMemory(void);


	/**
	 * Called when the battery level changes. @n
	 * It is recommended that the applications consuming more battery power should be terminated if the battery level is Osp::System::BATTERY_CRITICAL.
	 *
	 * @since	1.0
	 * @param	batteryLevel	The device's current battery level
	 */
	virtual void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

	
	/**
	* Sends the user event to the application itself and not to other applications.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	requestId	The user defined event ID
	* @param[in]	pArgs		A pointer to an argument list of type String 
	* @exception	E_SUCCESS	The method is successful.
	* @see			OnUserEventReceivedN()
	*/
	result 	SendUserEvent (RequestId requestId, const Osp::Base::Collection::IList *pArgs);

	/**
	* Called asynchronously when the user event is sent by the SendUserEvent() method. @n
	* The request ID and argument format for the user event can be defined as per the requirement.
	*
	* @since					1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
    *                 For more information, see @ref CompApplicationOnUserEventReceivedNPage "here". 
	*
	* @param[in]	requestId	The user defined event ID
	* @param[in]	pArgs		A pointer to an argument list of type String
	* @see			SendUserEvent(), GetAppArgumentListN(), AppManager::LaunchApplication()
	*/
	virtual void 	OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs);

	/**

	* @page		CompApplicationOnUserEventReceivedNPage Compatibility for OnUserEventReceivedN()
	* @section	CompApplicationOnForegroundIssues Issues
	* 			When an application is launched from another application or system using AppManager::LaunchApplication() 
    *           with arguments, this method is called after OnAppInitializing() and launch arguments are handled in this method. @n
	*			From bada API version 1.1, when launching an application with arguments, the specified request ID and argument formats are used as below:
    * 				- requestId is assigned as the reserved launch ID (App::AppLaunchRequestId) by the system.
    * 				- @c pArgs has the same string list layout as the return arguments of GetAppArgumentListN().
	*
    * @code 
        void
        HelloOspWorld::OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs)
        {
        	if(requestId == AppLaunchRequestId) // If launch arguments come
	        {
		        if(pArgs)
	        	{
		        	for(int i = 0; i < pArgs->GetCount(); i++)
				        AppLog("pData[%d]=%S", i, ((String*)(pArgs->GetAt(i)))->GetPointer());

                    //...

                }
		    }
	        else // UserEvent handling here
	        {
		        //...
	        }   
			((ArrayList*)pArgs)->RemoveAll(true);
            delete pArgs; 
        }
    * @endcode 
	*/


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since			1.0
	 * @param[in]	providerId	The provider ID
	 * @param[in]	operationId	The operation ID
	 * @param[in]	pData		A pointer of type string to an arguments list
	 * @remarks		Instead of using this API, use OnUserEventReceivedN() or GetAppArgumentListN().
	 */
	virtual void OnAppControlOperationRequestedN(const Osp::Base::String& providerId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pData);

// Operation
private:
	/**
	 * Initializes this instance.
	 * @return	An error code
	 * @param[in]	nativeApplication	An instance of __NativeApplication
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result Initialize(const __NativeApplication& nativeApplication);

public:

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Executes an agent implemented by inheriting this Service class.
	 * This method must be called from the entry method - OspMain(), which is generated by IDE.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pServiceFactory		The factory method that creates this application's instance
	 * @param[in]	pArgument			The launch arguments for the application
	 * @param[in]	appAttribute			The attribute of an application (reserved)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_INIT_FAILED		The initialization failure during OnAppInitializing().
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	static result Execute(ApplicationInstanceFactory pAppFactory, const Osp::Base::Collection::IList* pArguments, AppAttributeType appAttribute=AAT_MAIN_APP);


	/**
	* Returns the application's instance pointer.
	*
	* @since	1.0
	* @return A pointer to the %Application instance, @n
	*		  else @c null if it fails
	* @see Application
	*/
	static Application* GetInstance(void);

	/**
	 * Gets the UI state of the application.
	 *
	 * @since 2.0
	 * @return	The UI state of the application
	 * @remarks	Note that Application::OnBackground() is invoked when the UI state of an application changes
	 * 			from App::APP_UI_STATE_FOREGROUND to App::APP_UI_STATE_PARTIAL_BACKGROUND or App::APP_UI_STATE_BACKGROUND.
	 * @see		AppUiState
	 */
	AppUiState GetAppUiState(void);

private:
	/*
	* Adds an application pointer to the application hash map to save it.
	*
	* @param[in]	app	A pointer to the instance of Application to add
	* @see UnSetInstance(), Instance()
	*/
	static result SetInstance(Application* app);

	/*
	* Removes an application pointer from the application hash map.
	*
	* @param[in]	app		Pointer to the instance of Application to remove
	* @see UnSetInstance(), Instance()
	*/
	static void UnSetInstance(Application* app);


// Attributes
private:
	__NativeApplication* __pNativeApplication;
	static Osp::Base::Collection::HashMap* __pAppInstances;

	friend class __NativeApplication;
	friend class __BaseApplication;

private:
	friend class ApplicationEx;
	class ApplicationEx* __pApplicationEx;

};


}; }; //Osp::App


#endif // _FAPP_APPLICATION_H_
