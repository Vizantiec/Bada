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
* @file			FMsgEmailManager.h
* @brief		This is the header file for the %EmailManager class.
*
* This header file contains the declarations of the %EmailManager class.
*/

#ifndef _FMSG_EMAILMANAGER_H_
#define _FMSG_EMAILMANAGER_H_

// Includes
#include "FBase.h"
#include "FMsgIEmailListener.h"
#include "FMsgEmailMessage.h"
#include "FMsgRecipientList.h"

namespace Osp { namespace Messaging {

	// Forward declaration for class extension.
	class EmailManagerEx;

	/**
	* @class	EmailManager
	* @brief	This class provides methods to use the email messaging service.
	* @since	1.0
	*
	* The %EmailManager class is used to send email messages.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* The following example demonstrates how to use the %EmailManager class.
	*
	* @code
	*
	// Creates a listener to override the OnEmailMessageSent() function of IEmailListener
	// in order to be notified of a change in the state of the message being sent.

	class EmailListener : public IEmailListener, Object
	{
	public:
		void OnEmailMessageSent(result r);
	};
	void EmailListener::OnEmailMessageSent(result r)
	{
		// Do something.
	}

	class SendEmailMessage : public Object
	{
	public:
		void EmailTest(void);
	};
	void SendEmailMessage::EmailTest(void)
	{
		result r = E_SUCCESS;

		// Creates an EmailListener instance.
		EmailListener* pListener = new EmailListener();

		// Creates an %EmailManager instance with the listener as the callback to check the status of the message being sent.
		EmailManager* pEmailManager = new EmailManager();
		r = pEmailManager->Construct(*pListener);

		// Creates a recipient list instance and adds recipients.
		RecipientList recipient;
		r = recipient.Add (RECIPIENT_TYPE_TO, L"test10@bada.com");
		r = recipient.Add (RECIPIENT_TYPE_CC, L"test09@bada.com");
		r = recipient.Add (RECIPIENT_TYPE_BCC, L"test08@bada.com");

		// Creates a email message instance.
		EmailMessage emailMessage;
		r = emailMessage.SetSubject(L"Subject!!!");
		r = emailMessage.SetText(L"Hello, World");
		r = emailMessage.AddAttachment(L"/Home/Res/testfile.dat");

		// Sends the message, and sets the @c saveToSentbox parameter to true if the message should be saved in the Sentbox; otherwise, set to false.
		// EmailListener callback is called once the message is completely sent.
		r = pEmailManager->Send(emailMessage, recipient, true);
	}
	*
	* @endcode
	*/
	class _EXPORT_MSG_ EmailManager :
		public Osp::Base::Object
	{
		// Lifecycle
	public:

		/**
		*	This is the default constructor for this class.
		*
		* @since	1.0
		*/
		EmailManager(void);

		/**
		*	This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~EmailManager(void);

	private:
		EmailManager(const EmailManager& value);
		EmailManager& operator =(const EmailManager& rhs);

		// Operation
	public:
		/**
		* Initializes this instance of %EmailManager with the specified parameter.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	listener		The listener to receive a send result asynchronously
		* @exception 	E_SUCCESS		The method is successful.
		* @exception	E_INVALID_STATE	This instance has not been constructed as yet, or the platform is not initialized properly.
		*/
		result			Construct(const IEmailListener &listener);

		/**
		* Sends the email message.
		*
		* @since			1.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return			An error code
		* @param[in]	message					The message to be sent
		* @param[in]	recipientList			The list of recipients
		* @param[in]	saveToSentbox			Set to @c true to save the message in the Sentbox, @n
		*										else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_STATE			The messaging service is inactive.
		* @exception	E_ON_INITIALIZING		The mailbox is not completely loaded as yet.
		* @exception	E_STORAGE_FULL			The storage is full.
		* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_INVALID_ACCOUNT		The email account is not set.
		* @exception	E_INVALID_CONDITION		The profile is not set.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FDN_MODE				The FDN mode has been activated.
		* @exception	E_INVALID_ARG			The number of recipients is @c 0.
		* @exception	E_MAX_EXCEEDED			 The number of recipients has crossed the maximum limit (Maximum 20).
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		
		* @remarks		The value of the flag, @c saveToSentbox, is fixed to @c false in the Emulator.
		* @see			IEmailListener::OnEmailMessageSent()
		*/
		result			Send(const EmailMessage& message, const RecipientList& recipientList, bool saveToSentbox);


	private:
		EmailEvent*			__pEmailEvent;
		bool				__isConstructed;
		IMessagePi*			__pEmailMessagePi;

		// for class extension.
	private:
		EmailManagerEx* __pEmailManagerEx;

		// friend class.
		friend class EmailManagerEx;
	};
};
};

#endif // _FMSG_EMAILMANAGER_H_
