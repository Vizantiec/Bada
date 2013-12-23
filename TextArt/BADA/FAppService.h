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
 * @file			FAppService.h 
 * @brief			This is the header file of the %Service class.
 * 
 * This header file contains the declarations of the %Service class.
 */

#ifndef _FAPP_SERVICE_H_
#define _FAPP_SERVICE_H_


#include "FBaseObject.h"
#include "FSysBattery.h"
#include "FAppConfig.h"
#include "FAppTypes.h"


namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {


// Forward declaration
class Service;
class AppRegistry;
class AppManager;
class IAppProxy;
class __NativeService;


typedef	Service* (*ServiceInstanceFactory)(void);


 /**
 * @if PRIVCORE
 * @class		Service
 * @brief		This is the base class of an agent application.
 * @since		1.0
 *
 * The %Service class is the base class of an agent application.
 * @endif
 */
class _EXPORT_APP_ Service :
	public Osp::Base::Object
{
// Lifecycle
protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Service(void);


// Lifecycle
private:
	/**
	 * This is the copy constructor for this class.
	 */
	Service(const Service& source);


// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Service(void);


// Operator
private:
	/**
	 * This is the assignment operator.
	 */
	Service& operator=(const Service& source);


// Access
public:
	/**
	 * Gets the instance that manages the application's states and preferences.
	 *
	 * @since		1.0
	 * @return	A pointer to the AppRegistry instance if successful, @n
	 *			else @c null if it fails
	 */
	AppRegistry* GetAppRegistry(void) const;


	/**
	 * Gets the application's current state.
	 *
	 * @since		1.0
	 * @return	The current state of the application in an AppState object
	 */
	AppState GetAppState(void) const;


	/**
	 * Gets the application's name. @n
	 * If the language is changed, it returns localized application name.
	 *
	 * @since		1.0
	 * @return	The application name
	 */
	virtual Osp::Base::String GetAppName(void) const;

	/**
	 * Gets the application's version.
	 *
	 * @since		1.0
	 * @return	The application's version
	 */
	Osp::Base::String GetAppVersion(void) const;

	/**
	 * Gets the application ID. @n
	 * This method also informs the system of the application ID.
	 *
	 * @since		1.0
	 * @return	The application ID
	 */
	virtual AppId GetAppId(void) const;

// Access
protected:
	/**
	* Gets the application's secret code. @n
	* This method also informs the system of the application's secret code.
	*
	* @since	1.0
	* @return	The application's secret code
	*/
	virtual AppSecret GetAppSecret(void) const;

// Operation
public:

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 *
	 * @since		1.0
	 */
	result Initialize(const __NativeService& nativeService);


	/**
	 * Terminates an application when it is running.
	 * The OnAppTerminating() method is called after this method is executed successfully.
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result Terminate(void);


	/**
	 * Called when the application's state changes to App::INITIALIZING. @n
	 * In general, most of the activities involved in initializing an application, including restoring the application's states, should be performed using this method. @n
	 * After this method succeeds, the application's state changes to App::RUNNING. @n
	 * If the method fails, the application's state changes to App::TERMINATING and the OnAppTerminating() method is called subsequently.
	 *
	 * @since		1.0
	 * @return	@c true if the method is successful, @n
	 *		    else @c false
	 * @param[in]	appRegistry	The instance that manages the application's states
	 * @remarks	Introducing the modal dialogs (for example, MessageBox) in this method is not allowed, as it blocks the initialization procedure.
	 */
	virtual bool OnAppInitializing(AppRegistry& appRegistry);


	/**
	 * Called when the application's state changes from App::RUNNING to App::TERMINATING. @n
	 * All the activities involved in terminating the application, including saving the application's states, should be performed using this method. @n
	 * After this method, the application code cannot be implemented. The application is destroyed subsequently.
	 *
	 * @since		1.0
	 * @return	@c true if the method is successful, @n
	 *			else @c false
	 * @param[in]	appRegistry	The instance that manages the application's states
	 * @remark	Accessing UI is not allowed in this method.
	 */
	virtual bool OnAppTerminating(AppRegistry& appRegistry);


	/**
	 * Called when the system determines that the memory left is not sufficient to run the application any further. @n
	 * Resources that are not in use currently can be released in this method. @n
	 *
	 * @since		1.0
	 */
	virtual void OnLowMemory(void);


	/**
	 * Called when the battery level changes. @n
	 * It is recommended that applications consuming more battery power should be terminated if batteryLevel is Osp::System::BATTERY_CRITICAL. @n
	 *
	 * @since	1.0
	 * @param	batteryLevel	The device's current battery level
	 */
	virtual void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);


	/**
	 * Called when the application receives some data from another application.
	 *
	 * @since			1.0
	 * @param[in]	appProxy		The proxy of the application that has sent the data
	 * @param[in]	data			The data itself
	 */
	virtual void OnDataReceived(IAppProxy& appProxy, const Osp::Base::Object& data);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies when AppControl event is delivered.
	 *
	 * @since			1.0
	 * @param[in]	appControlId	The application control ID
	 * @param[in]	operationId		The operation ID used in application control invocation
	 * @param[in]	pData		The list containing AppControl data(String type)
	 * @remarks		Instead of using this API, use OnUserEventReceivedN() or GetAppArgumentListN().
	 */

	virtual void OnAppControlOperationRequestedN(const Osp::Base::String& appControlId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pData);

	/**
	* Sends the user event to the application itself and not to other applications. @n
	*
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	requestId	The user defined event Id
	* @param[in]	pArgs		A pointer to an argument list of type String 
	* @exception	E_SUCCESS	The method is successful.
	* @see			OnUserEventReceivedN()
	*/
	result 	SendUserEvent (RequestId requestId, const Osp::Base::Collection::IList *pArgs);

	/**
	* Called asynchronously when the user event is sent by SendUserEvent() method. @n
	* The request id and argument format for the user event can be defined as per the requirement.
	*
	* @since					1.0
	*
	* @param[in]	requestId	The user defined event Id
	* @param[in]	pArgs		A pointer to an argument list of type String 
	*
	* @remarks
	* Since API version 1.1, when an application is launched from another application or system using AppManager::LaunchApplication() with arguments, this method is called after OnAppInitializing(). @n
	* In case of launching an application with arguments, the following request ID and argument formats are used. @n
	* 	- requestId is assigned as reserved launch Id (App::AppLaunchRequestId) by the system. @n
	* 	- pArgs[0] represents the launch type (for example, App::APP_LAUNCH_NORMAL). @n
	* 	- pArgs[1] represents the operation of launch (default value is OPERATION_DEFAULT). @n
	* 	- pAgrs[>=2] contains the actual arguments sent from the caller. @n
	* @see			SendUserEvent(), AppManager::LaunchApplication()
	*/
	virtual void 	OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs);

	/**
	 * @if PRIVCORE
	 * Executes an agent implemented by inheriting this Service class.
	 * This method must be called from the entry method - OspMain(), which is generated by IDE.
	 *
	 * @since			2.0
	 * @privlevel            CORE
	 * @privgroup          AGENT
	 *
	 * @return		An error code
	 * @param[in]	pServiceFactory		The factory method that creates this application's instance
	 * @param[in]	pArguments			The launch arguments for the application
	 * @param[in]	appAttribute			The attribute of an application (reserved)
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_INIT_FAILED		The initialization failure during OnAppInitializing().
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @endif
	 */
	static result Execute(ServiceInstanceFactory pServiceFactory, const Osp::Base::Collection::IList* pArguments, AppAttributeType appAttribute=AAT_MAIN_APP);


// Attribute
private:
	__NativeService* __pNativeService;
	friend class __NativeService;

private:
	friend class ServiceEx;
	class ServiceEx* __pServiceEx;
};


}; }; // Osp::App


#endif // _FAPP_SERVICE_H_
