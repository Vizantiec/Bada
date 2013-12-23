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
* @file			FMsgISmsMessageEventListener.h
* @brief		This is the header file for the %ISmsMessageEventListener interface.
*
* This header file contains the declarations of the %ISmsMessageEventListener interface.
*/

#ifndef _FMSG_ISMSMESSAGEEVENTLISTENER_H_
#define _FMSG_ISMSMESSAGEEVENTLISTENER_H_

// Includes
#include "FBase.h"
#include "FMsgConfig.h"

namespace Osp { namespace Messaging {

	// Forward declaration
	class SmsMessage;


	/**
	* @interface	ISmsMessageEventListener
	* @brief		This is the listener interface for receiving SMS messages. 
	* @since		2.0
	*
	* The %ISmsMessageEventListener interface must be implemented to handle incoming SMS messages. An application must register this interface using the SmsManager::AddSmsMessageEventListener() method.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class  _EXPORT_MSG_ ISmsMessageEventListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations	
	public:

		/**
		* Called when the SMS message is received.
		*
		* @since		2.0
		* @param[in]	message			The message that is received
		* @see			SmsManager::AddSmsMessageEventListener(), SmsManager::RemoveSmsMessageEventListener()
		*/
		virtual void OnSmsMessageReceived(const SmsMessage& message) = 0;

	protected:

		/**
		* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* @since		2.0
		*/
		virtual void ISmsMessageEventListener_Reserved1 (void) {}

		/**
		* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* @since		2.0
		*/
		virtual void ISmsMessageEventListener_Reserved2 (void) {}

		/**
		* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* @since		2.0
		*/
		virtual void ISmsMessageEventListener_Reserved3 (void) {}

		/**
		* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* @since		2.0
		*/
		virtual void ISmsMessageEventListener_Reserved4 (void) {}

		/**
		* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* @since		2.0
		*/
		virtual void ISmsMessageEventListener_Reserved5 (void) {}
	};
};
};

#endif // _FMSG_ISMSMESSAGEEVENTLISTENER_H_
