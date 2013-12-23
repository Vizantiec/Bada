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
* @file			FMsgMmsManager.h
* @brief		This is the header file for the %MmsManager class.
*
* This header file contains the declarations of the %MmsManager class.
*/

#ifndef _FMSG_MMSMANAGER_H_
#define _FMSG_MMSMANAGER_H_

// Includes
#include "FBase.h"
#include "FMsgIMmsListener.h"
#include "FMsgMmsMessage.h"
#include "FMsgRecipientList.h"

namespace Osp { namespace Messaging {

	// Forward declaration for class extension.
	class MmsManagerEx;

	/**
	* @class	MmsManager
	* @brief	This class provides methods to use the MMS messaging service.
	* @since	1.0
	*
	* The %MmsManager class is used to send MMS messages.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* The following example demonstrates how to use the %MmsManager class.
	*
	* @code
	*
	// Creates a listener to override the OnMmsMessageSent() function of IMmsListener
	// in order to be notified of a change in the state of the message being sent.

	class MmsListener : public IMmsListener, Object
	{
	public:
		void OnMmsMessageSent(result r);
	};
	void MmsListener::OnMmsMessageSent(result r)
	{
		// Do something.
	}

	class SendMmsMessage : public Object
	{
	public:
		void MmsTest(void);
	};
	void SendMmsMessage::MmsTest(void)
	{
		result r = E_SUCCESS;

		// Creates an MmsListener instance.
		MmsListener* pListener = new MmsListener();

		// Creates an MMS manager instance with the listener as the callback to check the status of the message being sent.
		MmsManager* pMmsManager = new MmsManager();
		r = pMmsManager->Construct(*pListener);

		// Creates a recipient list instance and add recipients.
		RecipientList recipient;
		r = recipient.Add (RECIPIENT_TYPE_TO, L"01012345678");
		r = recipient.Add (RECIPIENT_TYPE_CC, L"01012345679");
		r = recipient.Add (RECIPIENT_TYPE_BCC, L"01012345670");

		// Creates an MMS message instance.
		MmsMessage mmsMessage;
		r = mmsMessage.SetSubject(L"Subject!!!");
		r = mmsMessage.SetText(L"Hello, World");
		r = mmsMessage.AddAttachment(MMS_IMAGE, L"/Home/Res/image.jpg");
		r = mmsMessage.AddAttachment(MMS_IMAGE, L"/Home/Res/audio.wav");

		// Sends the message, and set the saveToSentbox parameter to true if the message should be saved in the Sentbox; otherwise, set to false.
		// MmsListener callback is called once the message has been completely sent.
		r = pMmsManager->Send(mmsMessage, recipient, true);
	}
	*
	* @endcode
	*/
	class _EXPORT_MSG_ MmsManager :
		public Osp::Base::Object
	{
		// Lifecycle
	public:

		/**
		*	This is the default constructor for this class.
		*
		* @since	1.0
		*/
		MmsManager(void);

		/**
		*	This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~MmsManager(void);

	private:
		MmsManager(const MmsManager& value);
		MmsManager& operator =(const MmsManager& rhs);

		// Operation
	public:
		/**
		* Initializes this instance of %MmsManager with the specified parameter.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	listener		The listener to receive a send result asynchronously
		* @exception 	E_SUCCESS		The method is successful.
		* @exception	E_INVALID_STATE	This instance has not been constructed as yet, or the platform is not initialized properly.
		*/
		result			Construct(const IMmsListener &listener);

		/**
		* Sends the MMS message.
		*
		* @since			1.0
		* @privlevel	SYSTEM
		* @privgroup	MESSAGING
		*
		* @return		An error code
		* @param[in]	message					The message to be sent
		* @param[in]	recipientList			The list of recipients
		* @param[in]	saveToSentbox			Set to @c true to save the message in the Sentbox, @n
		*										else @c false
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_ON_INITIALIZING		The mailbox is not completely loaded as yet.
		* @exception	E_INVALID_STATE			The messaging service is inactive.
		* @exception	E_STORAGE_FULL			The storage is full.
		* @exception	E_DEVICE_UNAVAILABLE	The device is unavailable.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_INVALID_CONDITION		The profile is not set.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FDN_MODE				The FDN mode has been activated.
		* @exception	E_INVALID_ARG			The number of recipients is @c 0 or the message is empty.
		* @exception	E_MAX_EXCEEDED			The number of recipients has crossed the maximum limit (Maximum 10).
		* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
		* @remarks		Some service providers may not support sending MMS messages with an empty subject or body.
		*				In this case, the result of the status report will be the E_FAILURE exception.
		*				From bada 2.0, the CC and BCC recipients in the @c recipientList are merged with the TO recipients when sending an MMS message.
		* @see			IMmsListener::OnMmsMessageSent()
		*/
		result			Send(const MmsMessage& message, const RecipientList& recipientList, bool saveToSentbox);

	private:
		MmsEvent*			__pMmsEvent;
		bool				__isConstructed;
		IMessagePi*			__pMmsMessagePi;

		// for class extension
	private:
		MmsManagerEx* __pMmsManagerEx;

		// friend class
		friend class MmsManagerEx;
	};
};
};

#endif // _FMSG_MMSMANAGER_H_
