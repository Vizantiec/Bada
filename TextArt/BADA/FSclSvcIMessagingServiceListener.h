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
* @file		FSclSvcIMessagingServiceListener.h
* @brief	This is the header file for the %IMessagingServiceListener interface.
*
* This header file contains the declaration of the %IMessagingServiceListener interface.
*
*/

#ifndef	_FSCLSVC_IMESSAGINGSERVICELISTENER_H_
#define	_FSCLSVC_IMESSAGINGSERVICELISTENER_H_

#include "FSclSvcMessagingTypes.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Social { namespace Services {
	/**
	* @interface	IMessagingServiceListener
	* @brief		This listener interface receives responses from the server.  
	* @deprecated	This interface is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* The %IMessagingServiceListener interface receives responses from the server.
	*/
	class  _EXPORT_SOCIAL_ IMessagingServiceListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations
	public:
		/**
		* Called when the response to MessagingService::SendTextMessage() is received from the server.
		*
		* @since		1.0
		* @param[in]	reqId				The request ID
		* @param[in]	r					The result of the request
		* @param[in]	errorCode			The error code from the server
		* @param[in]	errorMsg			The error message from the server
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_SYSTEM			An unknown operating system error has occurred.
		* @exception	E_CONNECTION_FAILED	The network connection has failed.
		* @exception	E_SERVER			An error has occurred on the server side.
		* @see			Osp::Social::Services::MessagingService::SendTextMessage()
		*/
		virtual void OnTextMessageSent(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

		/**
		* Called when the response to MessagingService::CheckMessage() is received from the server.
		*
		* @since		1.0
		* @param[in]	reqId				The request ID
		* @param[in]	r					The result of the request
		* @param[in]	errorCode			The error code from the server
		* @param[in]	errorMsg			The error message from the server
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_SYSTEM			An unknown operating system error has occurred.
		* @exception	E_CONNECTION_FAILED	The network connection has failed.
		* @exception	E_SERVER			An error has occurred on the server side.
		* @see			Osp::Social::Services::MessagingService::CheckMessage()
		*/
		virtual void OnMessageChecked(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	};
}; }; }; // Osp::Social::Services
#endif // _FSCLSVC_IMESSAGINGSERVICELISTENER_H_
