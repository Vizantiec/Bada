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
* @file		FSclSvcIMessagingServiceEventListener.h
* @brief	This is the header file for the %IMessagingServiceEventListener interface.
*
* This header file contains the declarations of the %IMessagingServiceEventListener interface.
*
*/

#ifndef	_FSCLSVC_IMESSAGINGSERVICEEVENTLISTENER_H_
#define	_FSCLSVC_IMESSAGINGSERVICEEVENTLISTENER_H_

#include "FSclSvcMessagingTypes.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Social { namespace Services {
	/**
	* @interface	IMessagingServiceEventListener
	* @brief		This is the listener interface for receiving the incoming messages.
	* @deprecated	This interface is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* The %IMessagingServiceEventListener interface is the listener interface for receiving the incoming messages.
	*/
	class  _EXPORT_SOCIAL_ IMessagingServiceEventListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations
	public:

		/**
		* Called to handle the incoming text message from the server.
		*
		* @since		1.0
		* @param[in]	userId				The user ID of the sender
		* @param[in]	dateTime			The date and time that the message is sent (the UTC time)
		* @param[in]	message				The message body
		* @see			Osp::Social::Services::MessagingService::CheckMessage(), Osp::Social::Services::MessagingService::StartPollingTimer()
		*/
		virtual void OnTextMessageReceived(const UserId& userId, const Osp::Base::DateTime& dateTime, const Osp::Base::String& message) = 0;
	};
}; }; }; // Osp::Social::Services
#endif // _FSCLSVC_IMESSAGINGSERVICEEVENTLISTENER_H_
