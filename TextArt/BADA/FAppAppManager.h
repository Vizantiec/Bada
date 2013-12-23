/* $Change: 1198808 $ */
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
 * @file			FAppAppManager.h 
 * @brief			This is the header file for the %AppManager class.
 *
 * This header file contains the declarations of the %AppManager class.
 */

#ifndef _FAPP_APP_MANAGER_H_
#define _FAPP_APP_MANAGER_H_

#include "FAppTypes.h"
#include "FAppAppControl.h"
#include "FAppIPackageEventListener.h"

namespace Osp { namespace Base { namespace Runtime { class IEvent; }; }; };
namespace Osp { namespace Base { namespace Collection { class Stack; }; }; };
namespace Osp { namespace Base { namespace Collection { class HashMap; }; }; };
namespace Osp { namespace Base { namespace Collection { class ArrayList; }; }; };


namespace Osp { namespace App {

class IAppProxy;
class IPackageEventListener;
class __AppPackageEvent;
class IAppControlEventListener;
class IAppControlListener;
class __AppControlEvent;
class IAppCheckpointEventListener;

/**
 * @class		AppManager
 * @brief		This class manages all the applications.
 * @since		1.0
 *
 * The %AppManager class manages all the applications.
 * The application manager supports normal and conditional application launch, and application control search and launch.
 * It looks up the specific application control from the application control registry and creates an application control instance.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>, <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>, and <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/app_controls.htm">Application Controls</a>.

 *
 */
class _EXPORT_APP_ AppManager :
	public Osp::Base::Object
{
// enum
public:
	
	/**
	 * @internal
	 * @enum __AppType
	 * Defines application type.
	 *
	 * @since		1.0
	 */
	enum __AppType
	{
		APP_TYPE_APPLICATION,		/**< @internal UI Application type */
		APP_TYPE_SERVICE,				/**< @internal Agent type */
		APP_TYPE_UNKNOWN				/**< @internal Unknown type */
	};

	/**
	 * @enum LaunchOption
	 * Defines the launch options.
	 *
	 * @since		1.0
	 */
	enum LaunchOption
	{
		LAUNCH_OPTION_DEFAULT	/**< The launch option: default */
	};

// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 */
	AppManager(void);

	/*
	 * Constructs the instance of this class.
	 *
	 * @return	An error code
	 * @param[in]	pAppProxy	The pointer to the IAppProxy instance
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(IAppProxy* pAppProxy);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~AppManager(void);

// Operation
public:

	/**
	* Finds the application control that the caller wants to start. @n
	* It resolves the matched application control with the delivered application control provider ID and operation ID.
	*
	* @since	1.0
	* @return	A pointer to the newly created AppControl instance if a matched %AppControl is found, @n
	*			else @c null
	* @param[in]	providerId	The provider ID
	* @param[in]	operationId		The operation ID
	* @see Osp::App::AppControl
    *
	* The following example demonstrates how to find the application control.
	*
	* @code
    * ArrayList* pDataList = new ArrayList();
    * String* pData = new String(L"tel:1234567890");
    * String* pData2 = new String(L"type:voice");
    *
    * pDataList->Construct();
    * pDataList->Add(*pData);
    * pDataList->Add(*pData2);
    *
    * AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_PROVIDER_CALL, APPCONTROL_OPERATION_CALL);
    * pAc->Start(pDataList, null);
    *
    * pDataList->RemoveAll(true);
    * delete pDataList;
    * @endcode
	*/
	static AppControl* FindAppControlN(const Osp::Base::String& providerId, const Osp::Base::String& operationId);

	/**
	 * Returns a list of AppControl instances that match the specified operation ID, category,
	 * data type, and URI scheme.
	 *
	 * @since		2.0
	 * @return	A pointer to the list of the %AppControl instances that matches the specified operation ID, category, URI scheme, and data type, @n
	 * 			else @c null if it fails
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pCategory			The application control category
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 * 							The '.' prefix should be used when specifying the file extension.
	 * @param[in]	pUriScheme			The URI scheme
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		At least one of the The specified @c pOperationId, @c pCategory, @c pDataType, or @c pUriScheme should not be @c null.
	 * @exception	E_INVALID_FORMAT	The specified URI scheme is invalid (RFC 2396).
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	For the delivered launch arguments, see Application::GetAppArgumentListN().
	 * @see Osp::App::AppControl, Application::GetAppArgumentListN()
	 */
	 static Osp::Base::Collection::IList* FindAppControlsN(const Osp::Base::String* pOperationId, const Osp::Base::String* pCategory, const Osp::Base::String* pDataType, const Osp::Base::String* pUriScheme);

	/**
	 * Starts the application control if there is only one application control that matches the specified URI, operation ID, and data type. @n
	 * If there are more than one application controls, the one that the user selects is started.
	 *
	 * The following are the acceptable formats for the URI:
	 *
	 * -# URI with well-known schemes such as http, mailto, and tel.
	 * -# URI encoded in the bada-defined grammar to represent the (appcontrol provider ID, operation ID) pairs.
	 *
	 * The appcontrol ID and operation ID pair is represented by @n@n
	 * [appcontrol provider ID]://[shortened operation ID]?[key1=value1]&[key2=value2;value3] @n@n
	 * The string form of the operation ID is 'osp.appcontrol.operation.[OPERATION ID]', and the shortened form of the operation ID
	 * is '[OPERATION ID]'. For example, the App::APPCONTROL_OPERATION_CALL
	 * variable has the value 'osp.appcontrol.operation.call', and the shortened form of the operation ID is 'call'.
	 *
	 *
	 * @since		2.0
	 * @return	An error code
	 * @param[in]	uri			The URI that has a maximum size of @c 1024 bytes
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 * 							The '.' prefix should be used for the @c dataType when specifying the file extension.
	 * @param[in]	pListener	A listener that gets notified when the resolved application control has started
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The size of @c uri has exceeded the maximum limit.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE		The system pop-up cannot be launched.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_IN_PROGRESS		The target application control is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The application controls such as App::APPCONTROL_PROVIDER_CALL and App::APPCONTROL_PROVIDER_BROWSER require proper privilege.
	 * @remarks		The E_INVALID_STATE exception is thrown when the default form is not accessible.
	 * @remarks		For the encoded application control information, the delivered parameter for AppControl::Start() is
	 * 				the ordered optional part of the specified URI after "?" character. Each token of the optional part
	 * 				is separated by an ampersand ('&') and is equivalent to the array of the @c pDataList parameter. For example,
	 * 				'AAA&key1=value1&key2=value2&key3=value4=value5'. The first occurrence of '=' after every token is replaced with ':'.
	 * 				For example, 'AAA, key1:value1, key2:value2, key3:value4=value5'.
	 * 				
	 * @see	IAppControlListener, Application::GetAppArgumentListN(), FindAppControlN(), FindAppControlsN(), AppControl::Start()
	 *
	 * The following example demonstrates how to use the FindAppControlN() method.
	 *
	 * @code
     * ArrayList* pDataList = new ArrayList();
     * String* pData = new String(L"tel:1234567890");
     * String* pData2 = new String(L"type:voice");
     *
	 * pDataList->Construct();
	 * pDataList->Add(*pData);
	 * pDataList->Add(*pData2);
	 *
	 * AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_PROVIDER_CALL, APPCONTROL_OPERATION_CALL);
	 * pAc->Start(pDataList, null);
	 *
	 * pDataList->RemoveAll(true);
	 * delete pDataList;
	 * @endcode
	 *
     *
     * The following example demonstrates how to use the StartAppControl() method.
     *
     * @code
     * StartAppControl(L"osp.appcontrol.provider.call://call?tel=1234567890&type=voice", null, null, null);
     * @endcode
	 */
	static result StartAppControl(const Osp::Base::String& uri, const Osp::Base::String* pOperationId, const Osp::Base::String* pDataType, const IAppControlListener* pListener);

	/**
	 * Starts the application control if there is only one application control that matches the specified operation ID, category, URI scheme, and data type. @n
	 * If there are more than one application controls, the one that the user selects is started.
	 *
	 * @since		2.0
	 * @return	An error code
	 * @param[in]	pOperationId	The operation ID
	 * @param[in]	pCategory			The application control category
	 * @param[in]	pDataType	The MIME type (RFC 2046) or file extension @n
	 * 							The '.' prefix should be used when specifying the file extension.
	 * @param[in]	pUriScheme			The URI scheme
	 * @param[in]	pDataList	The data list to be delivered to the resolved application control @n
	 *                       It has a maximum size of @c 1024 bytes.
	 * @param[in]	pListener	A listener that gets notified when the resolved application control has started
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		At least one of the specified @c pOperationId, @c pCategory, @c pDataType, or @c pUriScheme should not be @c null.
	 * @exception	E_MAX_EXCEEDED		The size of @c pDataList has exceeded the maximum limit.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified file extension for @c pDataType is not supported.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE		The system pop-up cannot be launched.
	 * @exception	E_OBJ_NOT_FOUND		The application control is not found.
	 * @exception	E_IN_PROGRESS		The target application control is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The application controls such as App::APPCONTROL_PROVIDER_CALL and App::APPCONTROL_PROVIDER_BROWSER require proper privilege.
	 * @remarks		E_INVALID_STATE occurs when the default form is not accessible.
	 * @remarks		For delivered launch arguments, see Application::GetAppArgumentListN().
	 * @see	IAppControlListener, Application::GetAppArgumentListN(), FindAppControlsN(), AppControl::Start()
	 */
	static result StartAppControl(const Osp::Base::String* pOperationId, const Osp::Base::String* pCategory, const Osp::Base::String* pDataType, const Osp::Base::String* pUriScheme, const Osp::Base::Collection::IList* pDataList, const IAppControlListener* pListener);

	/**
	* Retrieves the application manager instance.
	*
	* @since	1.0
	* @return	A pointer to the %AppManager instance, @n
	*			else @c null if it fails
	*/
	static AppManager* GetInstance(void);

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* @since		1.0
	*/
	void AppControlSetResult(const Osp::Base::Collection::IList* pCallbackResult);

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* @since		1.0
	*/
	void AppControlFinish(void *p);

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* @since		1.0
	*/
	void PutAppControlEvent(const IAppControlEventListener* pListener);

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* @since		1.0
	*/
	__AppControlEvent* GetAppControlEvent(void);


	/**
	 * Launches an application. @n
	 * The launch arguments are given as input parameters for Application::OnUserEventReceivedN() or can be obtained by 
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @since			1.1
     * @privlevel	SYSTEM
	 * @privgroup   APP_SERVICE
	 *
	 * @return	An error code
	 * @param[in]	appId				The application's ID to be executed
	 * @param[in]	pArguments			A pointer to the list of string arguments that has a maximum size of @c 1024 bytes @n
	 *									The default value is @c null.
	 * @param[in]	option				The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c appId is empty.
	 * @exception	E_OBJ_NOT_FOUND		The target application is not installed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED		The size of @c appId or @c pArguments has exceeded the maximum limit.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			Application::OnUserEventReceivedN(), Application::GetAppArgumentListN()
	 */
	result LaunchApplication(const AppId& appId, const Osp::Base::Collection::IList* pArguments, LaunchOption option);

	/**
	 * @if PRIVCORE
	 * Launches an installed application. @n
	 * The launch arguments are given as input parameters for Application::OnUserEventReceivedN() or can be obtained by 
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @deprecated	This method is deprecated because it has a size limitation (80 bytes). Instead of using this method, it is recommended to use LaunchApplication() with SYSTEM privilege.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup	APP_MANAGER
	 *
	 * @return	An error code
	 * @param[in]	appId				The application's ID to be executed
	 * @param[in]	pArguments			A pointer to the list of arguments @n
	 *                                  This argument is optional for the application and its maximum size is @c 80 bytes.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c appId is empty.
	 * @exception	E_OBJ_NOT_FOUND		The target application is not installed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED		The size of @c appId or @c pArguments has exceeded the maximum limit.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			Application::OnUserEventReceivedN(), Application::GetAppArgumentListN()
	 * @endif
	 */
	result LaunchApplication(const AppId& appId, const Osp::Base::Collection::IList* pArguments);

	/**
	 * @if PRIVCORE
	 * Terminates an application.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup	APP_MANAGER
	 *
	 * @return	An error code
	 * @param[in]	appId				The application's ID to be executed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND		The application is not installed or not running.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result TerminateApplication(const AppId& appId);

	/**
	* @if PRIVCORE
	* Checks whether an application is running.
	*
	* @since			1.0
  * @privlevel	CORE
	* @privgroup	APP_MANAGER
	*
	* @return	@c true if the application is running, @n
  *        	else @c false
	* @param[in]	appId 				The installed application ID
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @remarks Do not use this method without obtaining prior permissions from the bada platform team.
	* @endif
	*/
	bool IsRunning(const AppId& appId) const;
	
	
	/**
	* @if PRIVCORE
	* Returns a list of running applications at the time of invocation.
	*
	* @since      2.0
    * @privlevel	CORE
	* @privgroup	APP_MANAGER
	*
    * @return	A pointer to the running state application list (AppId), @n
        *    				else @c null if an error occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_INVALID_STATE 			This instance is in an invalid state. 
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @remarks Do not use this method without obtaining prior permissions from the bada platform team.
	* @endif
	*/
	Osp::Base::Collection::IList* GetRunningAppListN(void);


	/**
	 * Registers an application with a specific condition and launches it if the condition is met. @n
	 * If the requested application is already running, the application is notified via Application::OnUserEventReceivedN().
	 * The launch arguments are given as input parameters for Application::OnUserEventReceivedN() or can be obtained by 
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @since      1.2
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	 *				For more information, see @ref CompRegisterAppLaunchPage "here".
	 * @privlevel  NORMAL
	 * @privgroup  APP_OPERATION
	 *
	 * @return     An error code
	 * @param[in]  condition      The launch condition for the application @n
	 *	 						  The condition has L"Key='value'" format and is case sensitive. To use single or double quotes in the condition values, prefix them with a slash (\' or \"). @b Since: @b 2.0 @n
	 *							  For more information on the condition formats, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>.
	 * 							  <table><tr><th>Condition Format</th><th>Meaning</th></tr>
	 							  <tr><td>L"DateTime='mm/dd/yyyy hh:mm:ss'"</td>
								  <td>The specified condition is the local due time.</td></tr>
	 							  <tr><td>L"DueTime='mm/dd/yyyy hh:mm:ss' LaunchPeriod='mm'"</td>
								  <td>The specific condition is the time period after due time. @b Since: @b 2.0</td></tr>
	 							  <tr><td>L"Serial='command'"</td><td>The specified condition is a serial
	 							  communication input command.</td></tr>
	 							  <tr><td>L"NFC='command'"</td><td>The specified condition is a Near Field Communication (NFC) tag that has the NFC Data Exchange Format (NDEF) data.
	 							  @b Since: @b 2.0</td></tr></table> @n
	 							  
	 *
	 * @param[in]  pArguments	  A list of string arguments has a maximum size of @c 1024 bytes. @n
	 *							  The parameter can also contain @c null. @n
	 *						      For more information on the arguments, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>.
	 * @param[in]  option         The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_ARG		The launch condition is empty or too long (Maximum 400 bytes).
	 * @exception  E_INVALID_FORMAT		The specified condition format is invalid.
	 * @exception  E_INVALID_CONDITION  The specified condition format is valid but the condition has at least one or more invalid values.
	 * @exception  E_OBJ_ALREADY_EXIST	The specified condition is already registered by a different application.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception  E_MAX_EXCEEDED		The size of @c pArguments has exceeded the maximum limit.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks    When the registered application is about to be launched, the delivered args[0] contains
	 *             the App::APP_LAUNCH_CONDITIONAL value and args[1] contains the registered condition value.
	 *             The actual launch arguments starts from args[2]. For more information, see Application::GetAppArgumentListN().
	 * @remarks    The newly introduced launch condition does not work on the previous SDK version with the E_INVALID_CONDITION exception.
	 * @remarks    When the same launch condition is registered, it overwrites the previous launch argument without throwing an exception.
	 * @remarks    The LaunchPeriod requires more consideration, as an inappropriately short period value may lead
	 *             to an adverse effect on the device battery.
	 * @remarks    For the NFC condition, the detected NDEF message can be acquired using the Osp::Net::Nfc::NfcManager::GetCachedNdefMessageN() method.
	 * @see        UnregisterAppLaunch(), IsAppLaunchRegistered(), LaunchApplication(),
                   Application::OnUserEventReceivedN(), Application::GetAppArgumentListN(),
                   Osp::Base::DateTime::ToString(), Osp::Io::SerialPort and Osp::Net::Nfc::NfcManager::GetCachedNdefMessageN()
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 * 	DateTime time;
	 * 	SystemTime::GetCurrentTime(WALL_TIME, time);
	 * 	time.AddMinutes(1);
	 *
	 * 	String cond;
	 * 	cond.Format(70, L"DueTime='%S' LaunchPeriod='60'", time.ToString().GetPointer());
	 *
	 * 	// Registers a periodic condition that fires every 60 minutes starting after one minute
	 * 	AppManager::GetInstance()->RegisterAppLaunch(cond, null, AppManager::LAUNCH_OPTION_DEFAULT)
	 *
	 * @endcode
	 */
	result RegisterAppLaunch(const Osp::Base::String& condition, const Osp::Base::Collection::IList* pArguments, LaunchOption option);

	/**
	 * @page	CompRegisterAppLaunchPage Compatibility for RegisterAppLaunch()
	 * @section	CompRegisterAppLaunchPageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issues:
	 *
	 *	-# E_OBJ_ALREADY_EXIST occurs when the specified condition is already registered by another application.
	 *	-# The method overwrites the previously registered launch condition, if the calling application tries to register with a new launch condition.
	 *	-# For the delivered parameter, args[1] has App::OPERATION_DEFAULT.
	 *	-# The method returns E_INVALID_FORMAT if the condition value contains a single quote or a double quote character.
	 *	-# Privilege group is changed from APP_SERVICE to APP_OPERATION in bada API version 2.0.
	 *
	 * @section          CompRegisterAppLaunchPageResolution Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	 *
	 *      -# This method allows the registration of the specified condition for the calling application even if the
	 *      condition is already registered for another application.
	 *      A system pop-up is displayed to resolve the candidates when the specified condition is met.
	 *      -# This method allows registering multiple launch conditions for each application.
	 *      -# The delivered args[1] argument for the called application is now the registered condition string.
	 */
	 
	/**
	 * Unregisters the previously registered launch condition.
	 *
	 * @since      1.2
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	 *				For more information, see @ref CompConditionalAppLaunchPrivilegePage "here".
	 * @privlevel  NORMAL
	 * @privgroup  APP_OPERATION
	 *
	 * @return     An error code
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks     E_SUCCESS occurs when there is no registered launch condition.
	 * @see         RegisterAppLaunch(), IsAppLaunchRegistered()
	 */
	result UnregisterAppLaunch(void);

	/**
	 * @page	CompConditionalAppLaunchPrivilegePage Compatibility for %Conditional %App %Launch
	 * @section	CompConditionalAppLaunchPrivilegePageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue:
	 *
	 *	-# Privilege group is changed from APP_SERVICE to APP_OPERATION in bada API version 2.0.
	 *
	 */

	/**
	 * Unregisters the specified launch condition.
	 *
	 * @since      2.0
	 * @privlevel  NORMAL
	 * @privgroup  APP_OPERATION
	 *
	 * @return     An error code
	 * @param[in]  condition      		The launch condition for the application
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_OBJ_NOT_FOUND		The specified launch condition is not found.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @see         RegisterAppLaunch(), IsAppLaunchRegistered()
	 */
	result UnregisterAppLaunch(const Osp::Base::String& condition);

	 /**
	  * Checks whether a launch condition is registered for the application.
	  *
	  * @since      1.2
	  * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	  *				For more information, see @ref CompConditionalAppLaunchPrivilegePage "here".
	  * @privlevel  NORMAL
	  * @privgroup  APP_OPERATION
	  *
	  * @return     @c true if a condition is already registered to the application invoking this method, @n
	  *             else @c false
	  * @exception  E_SUCCESS			The method is successful.
	  * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	  *
	  * @remarks     The specific error code can be accessed using the GetLastResult() method.
	  * @remarks     Do not use this method without obtaining prior permissions from the bada platform team.
	  * @see         RegisterAppLaunch(), UnregisterAppLaunch()
	  */
	 bool IsAppLaunchRegistered(void) const;

	 /**
	 * @if PRIVCORE
	 * Registers the specified application with a specific condition and launches it if the condition is met. @n
	 * If the requested application is already running, the application is notified via Application::OnUserEventReceivedN().
	 * The launch arguments are specified as input parameters for Application::OnUserEventReceivedN() or can be obtained by
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @since      2.0
	 * @privlevel  CORE
	 * @privgroup  APP_MANAGER
	 *
	 * @return     An error code
	 * @param[in]  appId          The ID of the application registered for launch
	 * @param[in]  condition      The launch condition for the application @n
	 *	 						  The condition has L"Key='value'" format and is case sensitive. To use single or double quotes in the condition values, prefix them with a slash (\' or \"). @b Since: @b 2.0 @n
	 *							  For more information on the condition formats, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/registering_launch_condition.htm">Registering a Launch Condition</a>.
	 * 							  <table><tr><th>Condition Format</th><th>Meaning</th></tr>
	 							  <tr><td>L"DateTime='mm/dd/yyyy hh:mm:ss'"</td>
								  <td>The specified condition is the local due time.</td></tr>
	 							  <tr><td>L"DueTime='mm/dd/yyyy hh:mm:ss' LaunchPeriod='mm'"</td>
								  <td>The specific condition is the time period after due time. @b Since: @b 2.0</td></tr>
	 							  <tr><td>L"Serial='command'"</td><td>The specified condition is a serial
	 							  communication input command.</td></tr>
	 							  <tr><td>L"NFC='command'"</td><td>The specified condition is a Near Field Communication (NFC) tag that has the NFC Data Exchange Format (NDEF) data.
	 							  @b Since: @b 2.0</td></tr></table> @n
	 							  
	 *
	 * @param[in]  pArguments	  A list of string arguments has a maximum size of @c 1024 bytes. @n
	 *							  The parameter can also contain @c null. @n
	 *						      For more information on the arguments, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/launching_other_apps_within_apps.htm">Launching Other Applications</a>.
	 * @param[in]  option         The launch option (currently only AppManager::LAUNCH_OPTION_DEFAULT is available)
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception  E_INVALID_ARG		The launch condition is empty or too long (Maximum 400 bytes).
	 * @exception  E_INVALID_FORMAT		The specified condition format is invalid.
	 * @exception  E_INVALID_CONDITION  The specified condition format is valid but the condition has at least one or more invalid values.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception  E_MAX_EXCEEDED		The size of @c pArguments has exceeded the maximum limit.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks    When the registered application is about to be launched, the delivered args[0] contains
	 *             the App::APP_LAUNCH_CONDITIONAL value and args[1] contains the registered condition value.
	 *             The actual launch arguments starts from args[2]. For more information, see Application::GetAppArgumentListN().
	 * @remarks    The newly introduced launch condition does not work on the previous SDK version and the E_INVALID_CONDITION exception is thrown.
	 * @remarks    Registering the same launch condition overwrites the previous launch argument without throwing an exception.
	 * @remarks    The launch period requires more consideration because an inappropriate short period value may lead
	 *             to an adverse effect on the device battery.
	 * @remarks    For the NFC launch condition, the detected NDEF message can be acquired using the Osp::Net::Nfc::NfcManager::GetCachedNdefMessageN() method.
	 * @see        UnregisterAppLaunch(), IsAppLaunchRegistered(), LaunchApplication(),
					Application::OnUserEventReceivedN(), Application::GetAppArgumentListN(),
					Osp::Base::DateTime::ToString(), Osp::Io::SerialPort and Osp::Net::Nfc::NfcManager::GetCachedNdefMessageN()
	 * @endif
	 */
	result RegisterAppLaunch(const AppId& appId, const Osp::Base::String& condition, const Osp::Base::Collection::IList* pArguments, LaunchOption option);

	/**
	 * @if PRIVCORE
	 * Unregisters the launch condition.
	 *
	 * @since      2.0
	 * @privlevel  CORE
	 * @privgroup  APP_MANAGER
	 *
	 * @return     An error code
	 * @param[in]  appId          The application ID
	 * @param[in]  pCondition      		The launch condition to unregister @n 
	 *                                  If the parameter contains @c null, all the conditions are unregistered. 
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception  E_OBJ_NOT_FOUND		The specified launch condition is not found.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @see         RegisterAppLaunch(), IsAppLaunchRegistered()
	 * @endif
	 */
	result UnregisterAppLaunch(const AppId& appId, const Osp::Base::String* pCondition);

	/**
	 * @if PRIVCORE
	 * Checks whether a previously registered launch condition is present for the specified application.
	 *
	 * @since      2.0
	 * @privlevel  CORE
	 * @privgroup  APP_MANAGER
	 *
	 * @return     @c true if a condition is already registered to the specified application with the specified condition, @n
	 *             else @c false
	 * @param[in]  appId          The application ID
	 * @param[in]  pCondition     The launch condition to register for the specified @c appId @n
     *                            If the parameter contains @c null, the method checks for any registered launch condition for the specified @c appId.
	 * @exception  E_SUCCESS			The method is successful.
	 * @exception  E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception  E_SYSTEM				A system error has occurred.
	 * @exception  E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         RegisterAppLaunch(), UnregisterAppLaunch()
	 * @endif
	 */
	bool IsAppLaunchRegistered(const AppId& appId, const Osp::Base::String* pCondition = null) const;

     /**
	  * Sets a checkpoint event listener. @n
	  * The listener gets notified when a checkpoint event is fired. To unset the listener, pass a @c null value to the @c listener parameter.
	  *
	  * @since	2.0
	  *
	  * @return	An error code
	  * @param[in]	listener		The listener to receive the checkpoint event
	  * @exception  E_SUCCESS			The method is successful.
 	  * @exception  E_OBJ_ALREADY_EXIST	The listener is already set.
 	  * @exception  E_SYSTEM		A system error has occurred.
 	  * @see		IAppCheckpointEventListener
	  * 
	  */
	 result SetCheckpointEventListener(const Osp::App::IAppCheckpointEventListener& listener);

	 /**
	 * Sends the result list for the application control request. @n
	 * The client can get the result list by implementing IAppControlEventListener::OnAppControlCompleted().
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	appControlRequestId	The application control request ID @n
	 *                          The application control request ID is given as an argument of
	 *                          Application::GetAppArgumentListN() or Application::OnUserEventReceivedN().
	 * @param[in]	pResultList	The list of the result strings of the application control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The application control request is not found.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @see	IAppControlEventListener, Application::GetAppArgumentListN(), Application::OnUserEventReceivedN()
	 */
	static result SendAppControlResult(const Osp::Base::String& appControlRequestId, const Osp::Base::Collection::IList* pResultList);

	 /**
	 * @if PRIVCORE
	 * Gets the application ID for given request Id
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return		application ID @n
	 * 				If an error occurs, @c null is returned.
	 * @param[in]	appControlRequestId	The application control request ID @n
	 * 							The application control request ID is specified as the argument of the 'AppControl request ID'
	 *							in Application::GetAppArgumentListN() or Application::OnUserEventReceivedN().
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The requestId is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The application ID is not found.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks This method returns @c null with E_SYSTEM exception if the caller application is platform application.
	 * @see	Application::GetAppArgumentListN(), Application::OnUserEventReceivedN()
	 * @endif
	 */
	static AppId* GetAppIdOfAppControlClientN(const Osp::Base::String& appControlRequestId);

private:
	static AppManager* CreateInstance(IAppProxy* pAppProxy);

	static void AppControlCB(const char* pDatas[], void* pParam, int bSetForeground);

	result __LaunchApplication(const AppId& appId, const Osp::Base::Collection::IList* pArguments, LaunchOption option, long argMaxSize);

private:
	static Osp::Base::Collection::HashMap* __pAppMgrInstances;
	Osp::Base::Collection::ArrayList* __pAppList;

	Osp::Base::Collection::Stack* __pAppControlEventStack;

	Osp::Base::Runtime::IEvent* __pAppPackageEvent;
	
	IAppProxy* __pAppProxy;

	friend class __NativeApplication;
	friend class __NativeService;
	friend class __BaseApplication;
	friend class AppControl;

private:
	friend class AppManagerEx;
	class AppManagerEx* __pAppManagerEx;
};
}; }; // Osp::App



#endif // _FAPP_APP_MANAGER_H_
