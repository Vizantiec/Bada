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
 * @file		FAppNotificationManager.h 
 * @brief		This is the header file for the %NotificationManager class.
 * 
 * This header file contains the declarations of the %NotificationManager class.
 */

#ifndef _FAPP_NOTIFICATION_MANAGER_H_
#define _FAPP_NOTIFICATION_MANAGER_H_


#include "FBase.h"
#include "FAppTypes.h"
#include "FAppConfig.h"

namespace Osp { namespace App {

/** The maximum length of the notification message. 
*
* @since		1.0
*/
static const int MAX_NOTIFICATION_MESSAGE_LENGTH		= 127;

/**
 * @if PRIVCORE
 * The maximum length of the launch arguments for the notification in bytes.
 * @since	2.0
 * @endif
 */
static const int MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH	= 1024;

/** The maximum length of the notification badge number. 
*
* @since		1.0
*/
static const int MAX_NOTIFICATION_BADGE_NUMBER			= 999;

/**
 * @class		NotificationManager
 * @brief		This class provides the methods to alert the user about a notification.
 * @since		1.0
 *
 * The %NotificationManager class provides the methods to alert the user about a notification.
 *
 * For more information about the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/notifications.htm">Notifications</a>.
 *
 * The following example demonstrates how to use the %NotificationManager class. 
 *
 * @code
 *
 *	result
 *	MyClass::NotificationSample(void)
 *	{
 *		int badgeNumber;
 *		NotificationManager* pNotiMgr = new NotificationManager();
 *		pNotiMgr->Construct();
 *		badgeNumber = pNotiMgr->GetBadgeNumber();
 *		badgeNumber++; 
 *		pNotiMgr->Notify(L"A new message has arrived.", badgeNumber);
 *
 *	}
 *
 * @endcode 
 *
 */
class _EXPORT_APP_ NotificationManager :
	public Osp::Base::Object
{

// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	NotificationManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~NotificationManager(void);

	/**
	 * Initializes this instance of %NotificationManager.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Construct(void);

	/**
	 * Gets the badge number of the application icon.
	 *
	 * @since				1.0
   * @privlevel		NORMAL
	 * @privgroup 	NOTIFICATION	 	 
	 *
	 * @return		The current badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception 	E_OBJ_NOT_FOUND  	The application is not installed.	 
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *          In case of failure, this method returns @c -1.       	 
	 */
	int GetBadgeNumber(void) const;

	/**
	 * Notifies the user using a badge number.
	 *
	 * @since				1.0
   * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION		 
	 *
	 * @return		An error code	 
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful. 
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *                                  the specified @c badgeNumber is less than @c 0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	
	 */
	result Notify(int badgeNumber) const;	
	
	/**
	 * Notifies the user using a message.
	 *
	 * @since				1.0
   * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION		 
	 *
	 * @return		An error code	 
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.		
	 */
	result Notify(const Osp::Base::String& messageText) const;	

	/**
	 * Notifies the user using a message and badge number.
	 *
	 * @since				1.0
   * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION		 
	 *
	 * @return		An error code	 
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number	 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c badgeNumber is less than @c 0, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.	 
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.		
	 */
	result Notify(const Osp::Base::String& messageText, int badgeNumber) const;

	/**
	 * Notifies the user using a message and badge number. @n
	 * If the user checks the message, @c launchArguments is delivered to the application. @n
	 * @c launchArguments is specified as input parameter for Application::OnUserEventReceivedN() or can be obtained by
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @since				1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompNotifyWithDataPage "here".
	 * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION and NOTIFICATION_WITH_DATA
	 *
	 * @return		An error code	 
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number
	 * @param[in]	launchArguments		The message for application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0. @n	
	 *									- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n	 
	 *									- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
     *										The Construct() method is not called. 
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			Application::OnUserEventReceivedN(), Application::GetAppArgumentListN()
	 */
	result Notify(const Osp::Base::String& messageText, int badgeNumber, const Osp::Base::String& launchArguments) const;
	
	/**
	 * @page             CompNotifyWithDataPage Compatibility for Notify()
	 * @section          CompNotifyWithDataPageIssue Issues
	 *                   Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 *		-# The maximum length of @c launchArguments is increased from 127 to
	 *		App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH from bada API version 2.0.
	 *
	 */

	/**
	 * @if PRIVCORE
	 * Removes the notification message.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup	NOTIFICATION_REMOVAL
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_SYSTEM			A system error occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state: @n
	 *                                  - The Construct() method is not called. @n
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 The method returns E_SUCCESS when there is no outstanding notification.
	 * @endif
	 */
	result RemoveNotification(void);

	/**
	 * Notifies the user about the ongoing activity using a message.
	 *
	 * @since				2.0
	 * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 */
	result NotifyOngoingActivity(const Osp::Base::String& messageText) const;

	/**
	 * Notifies the user about the ongoing activity using a message. @n
	 * @c launchArguments is specified as input parameter for Application::OnUserEventReceivedN() or can be obtained by
	 * invoking Application::GetAppArgumentListN(), especially within Application::OnAppInitializing().
	 *
	 * @since				2.0
	 * @privlevel		NORMAL
	 * @privgroup   NOTIFICATION and NOTIFICATION_WITH_DATA
	 *
	 * @return		An error code
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for the application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			Application::OnUserEventReceivedN(), Application::GetAppArgumentListN()
	 */
	result NotifyOngoingActivity(const Osp::Base::String& messageText, const Osp::Base::String& launchArguments) const;

	/**
	 * Removes the notification message for the ongoing activity.
	 *
	 * @since			2.0
	 * @privlevel	NORMAL
	 * @privgroup	NOTIFICATION
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	 The method returns E_SUCCESS when there is no outstanding notification. 
     */
	result RemoveOngoingActivityNotification(void);


	/**
	 * @if PRIVCORE	
	 * Gets the badge number of the application icon.
	 *
	 * @since				1.0
   * @privlevel		CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF	 	 
	 *
	 * @return		The current badge number	 
	 * @param[in]	appId				The application ID			 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND     The application is not installed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.		
	 * 
	 * @remarks The specific error code can be accessed using the GetLastResult() method. @n
	 *			In case of failure, this method returns @c -1.
	 *
	 * @endif	 
	 */
	int GetBadgeNumber(const AppId& appId ) const;

	/**
	 * @if PRIVCORE		
	 * Notifies the user using a badge number on behalf of the specified application.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
   *                For more information, see @ref CompNotifyOnBehalfPage "here".
   * @privlevel	CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF		 
	 *
	 * @return		An error code	 
	 * @param[in]	appId				The application ID			 
	 * @param[in]	badgeNumber			The badge number
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *                                  the specified @c badgeNumber is less than @c 0.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed @b since: @b 2.0.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to get any notification as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	
	 * 
	 * @endif		 
	 */
	result NotifyOnBehalf(const AppId& appId, int badgeNumber) const;
	
	/**
	 * @if PRIVCORE		
	 * Notifies the user using a message on behalf of the specified application.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
   *                For more information, see @ref CompNotifyOnBehalfPage "here".
   * @privlevel	CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF		 
	 *
	 * @return		An error code	 
	 * @param[in]	appId				The application ID			 
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or 
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed @b since: @b 2.0.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	
	 * 
	 * @endif		 
	 */
	result NotifyOnBehalf(const AppId& appId, const Osp::Base::String& messageText) const;

	/**
	 * @if PRIVCORE		
	 * Notifies the user using a message and badge number on behalf of the specified application.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
   *                For more information, see @ref CompNotifyOnBehalfPage "here".
   * @privlevel	CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF		 
	 *
	 * @return		An error code	 
	 * @param[in]	appId				The application ID		 
	 * @param[in]	messageText			The notification message
	 * @param[in]	badgeNumber			The badge number	 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The specified @c badgeNumber is less than @c 0. @n
	 *									- The length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception	E_APP_NOT_INSTALLED  The application is not installed @b since: @b 2.0.
	 * @exception	E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the bada platform policy @b since: @b 2.0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * 
	 * @endif		 
	 */
	result NotifyOnBehalf(const AppId& appId, const Osp::Base::String& messageText, int badgeNumber) const;

	/**
	 * @if PRIVCORE
	 * @page             CompNotifyOnBehalfPage Compatibility for NotifyOnBehalf()
	 * @section          CompNotifyOnBehalfPageIssue Issues
	 *                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 *
	 *      -# If the destination application is not installed, NotifyOnBehalf() does not work as expected.
	 *      -# If the destination application type is not permitted to receive any notification as per the bada platform policy, E_SUCCESS is returned
	 *      and an unexpected behavior occurs.
	 *
	 * @section          CompNotifyOnBehalfPageResolution Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 *
	 *      -# If the destination application is not installed, E_APP_NOT_INSTALLED is returned.
	 *      -# If the destination application type is not permitted to receive any notification as per the bada platform policy, E_INVALID_OPERATION is returned.
	 *
	 * @par When working with bada API versions prior to 2.0:
	 *
     *	 -# An application can trigger an event on behalf of another application using the NotifyOnBehalf() method.
	 *      However, before calling the NotifyOnBehalf() method, use the PackageManager::IsAppInstalled() method to check whether the application to be used on behalf is installed.
	 *
	 * @endif
	 */

	/**
	* @if PRIVCORE
	* Notifies the user using a message and badge number on behalf of the specified application. @n
	* If the user checks the message, the @c launchArguments is delivered to the application.
	*
	* @since               2.0
	* @privlevel  CORE
	* @privgroup   NOTIFICATION_ON_BEHALF
	*
	* @return             An error code
	* @param[in]  appId				The application ID
	* @param[in]  messageText		The notification message
	* @param[in]  launchArguments	The launch arguments for the application
	* @exception  E_SUCCESS			The method is successful.
	* @exception  E_INVALID_ARG		Either of the following conditions has occurred: @n
	*								- A specified input parameter is invalid. @n
	*								- The length of the specified @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	*								- The length of the specified @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	* @exception  E_APP_NOT_INSTALLED	The application is not installed.
	* @exception  E_INVALID_OPERATION	The target application with the specified application ID is not permitted to receive any notification as per the bada platform policy.
	* @exception  E_SYSTEM				A system error has occurred.
	* @exception  E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	* @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @endif
	*/
	result NotifyOnBehalf(const AppId& appId, const Osp::Base::String& messageText, const Osp::Base::String& launchArguments) const;

	/**
	 * @if PRIVCORE
	 * Notifies the user about the ongoing activity using a message on behalf of the specified application.
	 *
	 * @since				2.0
	 * @privlevel		CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH.
	 * @exception 	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivityOnBehalf(const AppId& appId, const Osp::Base::String& messageText) const;

	/**
	 * @if PRIVCORE
	 * Notifies the user about the ongoing activity using a message on behalf of the specified application.
	 *
	 * @since				2.0
	 * @privlevel		CORE
	 * @privgroup   NOTIFICATION_ON_BEHALF
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	messageText			The notification message
	 * @param[in]  launchArguments	The launch arguments for application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The length of @c messageText is greater than App::MAX_NOTIFICATION_MESSAGE_LENGTH. @n
	 *									- The length of @c launchArguments is greater than App::MAX_NOTIFICATION_LAUNCH_ARGUMENTS_LENGTH.
	 * @exception 	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The type of application calling this method is invalid as per the bada platform policy.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method is not called.
	 * @exception E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	 */
	result NotifyOngoingActivityOnBehalf(const AppId& appId, const Osp::Base::String& messageText, const Osp::Base::String& launchArguments) const;

	/**
	 * @if PRIVCORE
	 * Removes the notification message for ongoing activity on behalf of the specified application.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup	NOTIFICATION_ON_BEHALF
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *                                  The Construct() method is not called.
	 * @exception   E_PRIVILEGE_DENIED  The application did not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns E_SUCCESS.
	 * @endif
	 */
	result RemoveOngoingActivityNotificationOnBehalf(const AppId& appId);

	/**
	 * @if PRIVCORE
	 * Removes the notification message on behalf of the specified application.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup	NOTIFICATION_ON_BEHALF
	 *
	 * @return		An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @exception	E_SYSTEM			A system error occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state: @n
	 *									- The Construct() method is not called. @n
	 * @exception   E_PRIVILEGE_DENIED  The application did not have the privilege to call this method.
	 * @remarks		Although there is no outstanding notification for the calling application, this method returns E_SUCCESS.
	 * @endif
	 */
	result RemoveNotificationOnBehalf(const AppId& appId);

private:
	void* __pIMAppNotifier;
	Osp::Base::String __appId;	

	friend class NotificationManagerEx;
	class NotificationManagerEx* __pNotificationManagerEx;
	
};


}; }; // Osp::App



#endif // _FAPP_NOTIFICATION_MANAGER_H_
