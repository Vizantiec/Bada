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
* @if PRIVCORE
*
* @file			FMsgISmsEventListener.h 
* @brief		This is the header file for the %ISmsEventListener interface.
*
* This header file contains the declarations of the %ISmsEventListener interface.
*
* @endif
*/

#ifndef _FMSG_ISMSEVENTLISTENER_H_
#define _FMSG_ISMSEVENTLISTENER_H_

// Includes
#include "FBase.h"
#include "FMsgConfig.h"

namespace Osp { namespace Messaging {

	// Forward declaration
	class SmsMessage;


	/**
	* @if PRIVCORE
	*
	* @interface	ISmsEventListener
	* @brief		This is the listener interface for receiving SMS messages. 
	* @since		1.0
	*
	* The %ISmsEventListener interface is the listener interface for receiving SMS messages. 
    * An application implements this interface and registers it using the SmsManager::AddSmsEventListener() method to receive SMS messages.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*
	* @endif
	*/
	class  _EXPORT_MSG_ ISmsEventListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations	
	public:

		/**
		* @if PRIVCORE
		*
		* Handles the incoming SMS message.
		*
		* @since			1.0
		* @param[in]	port				A port number
		* @param[in]	dateTime			The date and time when the message is received
		* @param[in]	message				The message that is received
		* @see			SmsManager::AddSmsEventListener(), SmsManager::RemoveSmsEventListener()
		*
		* @endif
		*/
		virtual void OnSmsMessageReceived(int port, const Osp::Base::DateTime& dateTime, const SmsMessage& message) = 0;	
	};

};
};

#endif // _FMSG_ISMSEVENTLISTENER_H_
