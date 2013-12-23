/* $Change: 1202329 $ */
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
* @file		FSclSvcMessagingService.h
* @brief	This is the header file for the %MessagingService class.
*
* This header file contains the declarations of the %MessagingService class.
*
*/

#ifndef	_FSCLSVC_MESSAGINGSERVICE_H_
#define	_FSCLSVC_MESSAGINGSERVICE_H_

#include "FSclSvcMessagingTypes.h"
#include "FSclSvcIMessagingServiceEventListener.h"
#include "FSclSvcIMessagingServiceListener.h"

struct _IMessageAgent;
struct __MessageAgentListenerImpl;
struct __MessageAgentEventListenerImpl;

namespace Osp { namespace Social { namespace Services {
class MessagingServiceEx;

	/**
	* @class		MessagingService
	* @brief		This class provides the methods to use the social messaging service.
    * @deprecated	This class is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* The %MessagingService class provides a top-level interface for a social messaging service.
	* With this class, an application can exchange messages.
	*
	* The following example demonstrates how to create a %MessagingService instance and use it.
        *
	* @code
	*
	#define TEST_TARGET_ID1		L"testuser01"

	class MessagingServiceListener : public IMessagingServiceListener, public IMessagingServiceEventListener, Object
	{
	public:
		void OnMessageChecked(RequestId reqId, result r, const Osp::Base::String &errorCode, const Osp::Base::String &errorMsg);
		void OnTextMessageSent(RequestId reqId, result r, const Osp::Base::String &errorCode, const Osp::Base::String &errorMsg);
		void OnTextMessageReceived(const UserId &userId, const Osp::Base::DateTime &dateTime, const Osp::Base::String &message);
	};
	void MessagingServiceListener::OnMessageChecked(RequestId reqId, result r, const Osp::Base::String &errorCode, const Osp::Base::String &errorMsg)
	{
		// Do something.
	}
	void MessagingServiceListener::OnTextMessageSent(RequestId reqId, result r, const Osp::Base::String &errorCode, const Osp::Base::String &errorMsg)
	{
		// Do something.
	}
	void MessagingServiceListener::OnTextMessageReceived(const UserId &userId, const Osp::Base::DateTime &dateTime, const Osp::Base::String &message)
	{
		// Do something.
	}

	class MessagingServiceSample : public Object
	{
	public:
		void Test(void);
	};
	void MessagingServiceSample::Test(void)
	{
		// Creates a MessagingServiceListener instance.
		MessagingServiceListener* pListener = new MessagingServiceListener();

		RequestId reqId;
		result r = E_SUCCESS;

		MessagingService* pMessagingService = new MessagingService();
		r = pMessagingService->Construct(*pListener, *pListener);
		if (IsFailed(r))
		{
		  delete pMessagingService;
		  delete pListener;
		  return;
		}

		// Starts a polling timer to retrieve a saved message from the server.
		r = pMessagingService->StartPollingTimer(60);
		if (IsFailed(r))
		{
		  delete pMessagingService;
		  delete pListener;
		  return;
		}

		// Sends a text message to the server.
		r = pMessagingService->SendTextMessage(TEST_TARGET_ID1, 1, L"test message", reqId);
		if (IsFailed(r))
		{
		  delete pMessagingService;
		  delete pListener;
		  return;
		}

		// Resource cleanup when terminating the application.

		// Stops a polling timer.
		r = pMessagingService->StopPollingTimer();
		if (IsFailed(r))
		{
		  delete pMessagingService;
		  delete pListener;
		  return;
		}

		delete pMessagingService;
		delete pListener;
	}
	*
	@endcode
	*/
	class  _EXPORT_SOCIAL_ MessagingService : public Osp::Base::Object
	{
		// Lifecycle
	public:
		/**
		* This is the default constructor for this class.
		* @since		1.0
		* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
		* @see			Construct()
		*/
		MessagingService(void);

		/**
		* This is the destructor for this class.
		*
		* @since	1.0
		*/
		~MessagingService(void);

	private:
		MessagingService(const MessagingService& value);
		MessagingService& operator = (const MessagingService& value);


	public:

		/**
		* Initializes this instance of %MessagingService with the specified listeners.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
		* @return		An error code
		* @param[in]	messagingServiceListener		The listener to receive the result of the MessagingService()
		* @param[in]	messagingServiceEventListener	The listener to receive the incoming messages from the server
		* @exception 	E_SUCCESS 						The method is successful.
		* @exception	E_INVALID_STATE					This instance has already been initialized, or the platform is not properly initialized.
		* @exception	E_OUT_OF_MEMORY 				The memory is insufficient.
		* @exception	E_SYSTEM 						A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 				The application does not have the privilege to call this method.
		* @see			Osp::Social::Services::IMessagingServiceListener, Osp::Social::Services::IMessagingServiceEventListener
		*/
		result			Construct(const IMessagingServiceListener& messagingServiceListener, const IMessagingServiceEventListener& messagingServiceEventListener);


	public:
		/**
		* Starts a polling timer to get the messages from the server.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
	    * @pre			The user should be authenticated. @n 
        *				For more information, see the sign-in AppControl (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
		*
		* @return		An error code
		* @param[in]	pollingInterval		The polling interval in seconds @n
		*									The minimum value is @c 10 seconds.
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The specified input parameter is invalid.
		* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_SYSTEM			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
		* @see			StopPollingTimer()
		*/
		result			StartPollingTimer(int pollingInterval);

		/**
		* Stops a polling timer to get the messages from the server.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
		* @return		An error code
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_STATE 	This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			StartPollingTimer()
		*/
		result			StopPollingTimer(void);

		/**
		* Sends a text message to a single destination. @n
		* This method is asynchronous.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
	    * @pre			The user should be authenticated. @n 
        *				For more information, see the sign-in AppControl (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
		*
		* @return		An error code
		* @param[in]	receiverId			The user ID of the receiver
		* @param[in]	period				The available period of the message in hours @n
		* 									The maximum value is @c 720 hours.
		* @param[in]	message				The message body @n
		* 									The maximum value is @c #MAX_MESSAGING_TEXT_LENGTH.
		* @param[out]	reqId				The request ID
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_ARG 		A specified input parameter is invalid.
		* @exception	E_INVALID_STATE 	This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			Osp::Social::Services::IMessagingServiceListener::OnTextMessageSent()
		*/
		result			SendTextMessage(const UserId& receiverId, int period, const Osp::Base::String& message, RequestId& reqId);

		/**
		* Sends a text message to multiple destinations. @n
		* This method is asynchronous.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
	    * @pre			The user should be authenticated. @n 
        *				For more information, see the sign-in AppControl (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
		*
		* @return		An error code
		* @param[in]	receiverIdList		The list of user IDs of the receivers @n
		* 									This is subject to a maximum of @c 50 users.
		* @param[in]	period				The available period of the message in hours @n
		* 									The maximum value is @c 720 hours.
		* @param[in]	message				The message body @n
		* 									The maximum value is @c #MAX_MESSAGING_TEXT_LENGTH.
		* @param[out]	reqId				The request ID
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_ARG 		A specified input parameter is invalid.
		* @exception	E_INVALID_STATE 	This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @see			Osp::Social::Services::IMessagingServiceListener::OnTextMessageSent()
		*/
		result			SendTextMessage(const Osp::Base::Collection::IList& receiverIdList, int period, const Osp::Base::String& message, RequestId& reqId);

		/**
		* Checks for new messages saved on the server. @n
		* New messages are delivered to the message listener.
		* This method is asynchronous.
		*
		* @since		1.0
		* @privlevel	NORMAL
		* @privgroup	MESSAGING_SERVICE
		*
	    * @pre			The user should be authenticated. @n 
        *				For more information, see the sign-in AppControl (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
		*
		* @return		An error code
		* @param[out]	reqId				The request ID
		* @exception 	E_SUCCESS 			The method is successful.
		* @exception	E_INVALID_STATE 	This instance has not been constructed as yet.
		* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
		* @exception	E_SYSTEM 			A system error has occurred.
		* @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
		* @remarks		This method should not be used along with a polling timer. In addition, this method should not be called again until a previous 
		*				request is completed. This may result in duplicate messages.
		* @see			Osp::Social::Services::IMessagingServiceListener::OnMessageChecked()
		*/
		result			CheckMessage(RequestId& reqId);

	private:

		IMessagingServiceEventListener*		__pMessagingServiceEventListener;
		IMessagingServiceListener*			__pMessagingServiceListener;

		_IMessageAgent*						__pMessageAgent;
		__MessageAgentEventListenerImpl*	__pMessageAgentEventListenerImpl;
		__MessageAgentListenerImpl*			__pMessageAgentListenerImpl;

		bool								__bConstructed;

	private:
		friend class MessagingServiceEx;
		class MessagingServiceEx* __pMessagingServiceEx;
	};
}; }; }; // Osp::Social::Services
#endif // _FSCLSVC_MESSAGINGSERVICE_H_
