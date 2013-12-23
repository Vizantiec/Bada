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
 * @file		FMsgPushManager.h
 * @brief		This is the header file for the %PushManager class.
 *
 * This header file contains the declarations of the %PushManager class.
 */

#ifndef _FMSG_PUSHMANAGER_H_
#define _FMSG_PUSHMANAGER_H_

// Includes
#include "FBase.h"
#include "FMsgIPushManagerListener.h"
#include "FMsgIPushEventListener.h"

// Forward declaration
struct _IMessageAgent;
struct __MMessageAgentListenerImpl;

namespace Osp { namespace Messaging {
	// Forward declaration
	class __MsgUtil;

	// Forward declaration for class extension.
	class PushManagerEx;

	/**
	* @class	PushManager
	* @brief	This class provides methods to use the push messaging service.
	* @since	2.0
	*
	* @remarks	 The NOTIFICATION privilege group is required to provide notifications to the 
	*            users to launch the application when a new message arrives.
	*
	* @pre		In order to use the push messaging service, you must <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/push_messaging.htm">configure the messaging component</a> on the bada developer site.
	* 
	*
	* The %PushManager class provides methods to register, unregister, and use the push messaging service.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
    *
    * @see 		Osp::App::NotificationManager
	*
	* The following example demonstrates how to use the %PushManager class.
	*
	* @code
	*
	// Creates a listener to override the methods of IPushManagerListener and IPushEventListener.

	class PushListener : public IPushManagerListener, public IPushEventListener, public Object
	{
	public:
		void OnPushServiceRegistered(RequestId reqId, const Osp::Base::String& registrationId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg);
		void OnPushServiceUnregistered(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg);
		void OnPushMessageReceived(const PushMessage& message);
	};
	void PushListener::OnPushServiceRegistered(RequestId reqId, const Osp::Base::String& registrationId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
	{
		if (E_SUCCESS == r) {
			// The application should send registrationId to the application server.
		} else {
			// Error
		}
	}
	void PushListener::OnPushServiceUnregistered(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
	{
		// Do something.
	}
	void PushListener::OnPushMessageReceived(const PushMessage& message)
	{
		// Do something.
	}

	class PushManagerSample : public Object
	{
	public:
		void Initialize(void);
		void EnablePushService(void);
		void DisablePushService(void);
	private:
		PushListener* pPushListener;
		PushManager* pPushManager;
	};
	void PushManagerSample::Initialize(void)
	{
		// Creates a PushListener instance.
		pPushListener = new PushListener();

		// Creates a PushManager instance.
		pPushManager = new PushManager();
		pPushManager->Construct(*pPushListener, *pPushListener);
	}
	void PushManagerSample::EnablePushService(void)
	{
		RequestId reqId;
		result r = E_SUCCESS;

		r = pPushManager->RegisterPushService(reqId);
		if (IsFailed(r)) {
			// Error
			return;
		}

		// The result of registration will be notified by IPushManagerListener::OnPushServiceRegistered().
	}
	void PushManagerSample::DisablePushService(void)
	{
		// The application should notify the application server to stop sending push messages for this device.

		RequestId reqId;
		result r = E_SUCCESS;

		r = pPushManager->UnregisterPushService(reqId);
		if (IsFailed(r)) {
			// Error
			return;
		}

		// The result of unregistration will be notified by IPushManagerListener::OnPushServiceUnregistered().
	}
	*
	* @endcode
	*/
	class _EXPORT_MSG_ PushManager :
		public Osp::Base::Object
	{
		// Lifecycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since	2.0
		*/
		PushManager(void);

		/**
		* This is the destructor for this class.
		*
		* @since	2.0
		*/
		virtual ~PushManager(void);

	private:
		PushManager(const PushManager& value);
		PushManager& operator =(const PushManager& value);

		// Operation
	public:
		/**
		* Initializes this instance of the %PushManager class with the specified parameters.
		*
		* @since		2.0
		* @privlevel	SYSTEM
		* @privgroup	PUSH_MESSAGING
		*
		* @pre			In order to use the push messaging service, 
	    * <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> should be executed.	
		*
		* @return		An error code
		* @param[in]	managerListener		A listener that receives the result of the %PushManager 
		*                                   class asynchronous methods
		* @param[in]	eventListener		A listener that receives the incoming push messages
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_STATE		This instance has already been initialized, or the platform 
		*                                   is not properly initialized.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			IPushManagerListener, IPushEventListener
		*/
		result			Construct(const IPushManagerListener& managerListener, const IPushEventListener& eventListener);

		/**
		* Registers the push messaging service for the current application. @n
		* This method is asynchronous.
		*	
		* @since		2.0
		* @privlevel	SYSTEM
		* @privgroup	PUSH_MESSAGING
		*
		* @pre			In order to use the push messaging service, 
	    * <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> should be executed.	
		*
		* @return		An error code
		* @param[out]	reqId				The request ID
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			IPushManagerListener::OnPushServiceRegistered()
		*/
		result			RegisterPushService(RequestId& reqId);

		/**
		* Unregisters the push messaging service for the current application. @n
		* This method is asynchronous.
		*
		* @since		2.0
		* @privlevel	SYSTEM
		* @privgroup	PUSH_MESSAGING
		*
		* @pre			In order to use the push messaging service, 
	    * <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> should be executed.	
		*
		* @return		An error code
		* @param[out]	reqId				The request ID
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			IPushManagerListener::OnPushServiceUnregistered()
		*/
		result			UnregisterPushService(RequestId& reqId);

		/**
		* Checks whether the push messaging service registration has been completed for the current application.
		*
		* @since		2.0
		*
		* @pre			In order to use the push messaging service, 
	    * <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> should be executed.	
		*
        * @return		@c true if the registration is completed, @n
		* 				else @c false
		*/
		bool			IsPushServiceRegistered(void) const;

		/**
		* Gets the unread push messages. @n
		* If an application receives unread messages with this method, the messages are removed from the system.
		*
		* @since		2.0
		* @privlevel	SYSTEM
		* @privgroup	PUSH_MESSAGING
		*
		* @pre			In order to use the push messaging service, 
	    * <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> should be executed.	
		*
		* @return		A pointer to the list that contains unread push messages
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* 				If the user launches the application using a ticker or a quick panel, 
		*               the push message related to the notification is delivered to the application 
		*               as a launch argument.
		* 				The launch arguments are the input parameters for
		*              Osp::App::Application::OnUserEventReceivedN() or can be obtained by invoking 
		*              Osp::App::Application::GetAppArgumentListN(), 
		*              especially within Osp::App::Application::OnAppInitializing().
		* 				This function returns all the unread messages including the message 
		*               delivered as a launch argument.
		* @see			Osp::App::Application::OnUserEventReceivedN(), Osp::App::Application::GetAppArgumentListN()
		*/
		Osp::Base::Collection::IList*	GetUnreadMessagesN(void);

		// Attributes
	private:
		IPushManagerListener*				__pManagerListener;
		IPushEventListener*					__pEventListener;
		_IMessageAgent*						__pMessageAgent;
		__MMessageAgentListenerImpl*		__pMMessageAgentListenerImpl;
		bool								__bConstructed;

		// for class extension
	private:
		class PushManagerEx* __pPushManagerEx;

		// friend class
		friend class __MsgUtil;
		friend class PushManagerEx;
	};
};
};

#endif // _FMSG_PUSHMANAGER_H_
