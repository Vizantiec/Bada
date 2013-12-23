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
 * @file		FMsgSmsMessage.h
 * @brief		This is the header file for the messaging classes.
 *
 * This header file contains the declarations of the %SmsMessage class.
 */

#ifndef _FMSG_SMSMESSAGE_H_
#define _FMSG_SMSMESSAGE_H_

// Includes
#include "FMsgISmsEventListener.h"
#include "FMsgConfig.h"
#include "FMsgRecipientList.h"

namespace Osp { namespace Messaging {

	// Forward declaration
	class SmsEvent;
	class IMessagePi;

	// Forward declaration for class extension.
	class SmsMessageEx;

	/**
	* @class	SmsMessage
	* @brief	This class provides methods for handling an SMS message.
	* @since	1.0
	*
	* The %SmsMessage class provides methods for handling SMS messages. It allows you to set and get the body text of an SMS message.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ SmsMessage :
		public Osp::Base::Object
	{
		// Lifecycle
	public:

		/**
		* This is the default constructor for this class.
		*
		* @since	1.0
		*/
		SmsMessage(void);

		/**
		*	This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~SmsMessage(void);

		/**
		* This is the copy constructor for the %SmsMessage class.
		*
		* @since			1.0
		* @param[in]	value	An instance of %SmsMessage
		*/
		SmsMessage(const SmsMessage& value);

	private:

		/**
		* Initializes this instance of the %SmsMessage control with the specified parameters. @n
		* This method is used only for the incoming messages.
		*
		* @param[in]	text				The body text of the message
		* @param[in]	senderAddress		The sender address of the message
		* @param[in]	receivedTime		The received time of the message
		*/
		SmsMessage(const Osp::Base::String& text, const Osp::Base::String& senderAddress, const Osp::Base::DateTime& receivedTime);

		/**
		* Initializes this instance of the %SmsMessage control with the specified parameters. @n
		* This method is used only for the Inbox messages.
		*
		* @param[in]	type				The type of the message box
		* @param[in]	messageId			The unique ID of the message
		* @param[in]	text				The body text of the message
		* @param[in]	hasMoreText			Set to @c true to check whether the message contains more than 160 bytes for the body text, @n
                                    		else @c false 
		* @param[in]	senderAddress		The sender address of the message
		* @param[in]	receivedTime		The received time of the message
		*/
		SmsMessage(SmsMessageBoxType type, int messageId, const Osp::Base::String& text, bool hasMoreText, const Osp::Base::String& senderAddress, const Osp::Base::DateTime& receivedTime);

		/**
		* Initializes this instance of %SmsMessage with the specified parameters. @n
		* This method is used for the messages in the Sentbox or Outbox.
		*
		* @param[in]	type				The type of the message box
		* @param[in]	messageId			The unique ID of the message
		* @param[in]	text				The body text of the message
		* @param[in]	hasMoreText			Set to @c true to check whether the message contains more than 160 bytes for the body text, @n
                                    		else @c false 
		* @param[in]	recipientList		The list of the recipients of the messages in the Sentbox or Outbox
		* @param[in]	sentTime			The sent time for the message
		*/
		SmsMessage(SmsMessageBoxType type, int messageId, const Osp::Base::String& text, bool hasMoreText, const Osp::Messaging::RecipientList& recipientList, const Osp::Base::DateTime& sentTime);

	public:

		/**
		* This assignment operator copies an SMS message from the specified instance of %SmsMessage to the calling instance of %SmsMessage.
		*
		* @since			1.0
		* @return			A reference to the %SmsMessage instance
		* @param[in]	rhs		A reference to the %SmsMessage instance to be copied
		*/
		SmsMessage& operator =(const SmsMessage& rhs);

		// Operation
	public:

		/**
		* Sets the body of the SMS message.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	text				The body of the SMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 80 characters).
		* @see			GetText()
		*/
		result SetText(const Osp::Base::String& text);

		/**
		* Gets the body of the SMS message.
		*
		* @since		1.0
		* @return		The body of the SMS message
		* @remarks		If the message is from the Inbox, Sentbox, or Outbox, it may contain only @c 160 bytes for the body text.
		* 				To check whether the message contains more than @c 160 bytes for the body text, use the HasMoreText() method.
		* 				To get the full body text, use the SmsManager::GetFullText() method with its message ID.
		* @see			SetText(), HasMoreText(), GetId(), SmsManager::GetFullText()
		*/
		Osp::Base::String GetText(void) const;

		/**
		* Gets the sender address of the SMS message.
		*
		* @since			2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return			The sender address of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is only allowed to the incoming message or the message from the Inbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		Osp::Base::String GetSenderAddress(void) const;

		/**
		* Gets the received time of the SMS message.
		*
		* @since			2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return			The received time of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is only allowed to the incoming message or the message from the Inbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* 		In case of an error, this method returns the instance denoting 00:00:00, January 1, 1.
		*/
		Osp::Base::DateTime GetReceivedTime(void) const;

		/**
		* Gets the unique ID of the SMS message.
		*
		* @since		2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		The unique ID of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		In case of an error, this method returns the negative value. For example, @c -1.
		* 		The specific error code can be accessed using the GetLastResult() method.
		*/
		int GetId(void) const;

		/**
		* Gets the sent time of the SMS message.
		*
		* @since			2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		The sent time of the SMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Sentbox or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* 		In case of an error, this method returns the instance denoting 00:00:00, January 1, 1.
		*/
		Osp::Base::DateTime GetSentTime(void) const;

		/**
		* Gets the type of the SMS message box.
		*
		* @since			2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		The type of the SMS message box
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		In case of an error, this method returns the SMS_MESSAGE_BOX_TYPE_NONE value.
		* 		The specific error code can be accessed using the GetLastResult() method.
		*/
		SmsMessageBoxType GetMessageBoxType(void) const;

		/**
		* Gets the list of the recipients.
		*
		* @since			2.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		The list of the recipient
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Sentbox or Outbox.
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		RecipientList GetRecipientList(void) const;

		/**
		* Checks whether the SMS message contains more than @c 160 bytes for the body text.
		*
		* @since	2.0
		*
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		@c true if this SMS message contains more than @c 160 bytes for the body text, @n
		*				else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_OPERATION		This operation is allowed only when the message is from the Inbox, Sentbox, or Outbox.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		* @remarks		If the return value is @c true, the SMS message contains more than @c 160 bytes for the body text. To get the full body text, use SmsManager::GetFullText().
		* 		The specific error code can be accessed using the GetLastResult() method.
		*/
		bool HasMoreText(void) const;

	private:
		Osp::Base::String __text;

		// for class extension
	private:
		SmsMessageEx* __pSmsMessageEx;

		// friend class
		friend class SmsMessageEx;
		friend class SmsEvent;
		friend class __Message;
	};
};
};

#endif // _FMSG_SMSMESSAGE_H_
