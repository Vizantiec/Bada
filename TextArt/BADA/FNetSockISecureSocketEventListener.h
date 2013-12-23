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
* @file		FNetSockISecureSocketEventListener.h
* @brief	This is the header file for the %ISecureSocketEventListener interface.
*
* This header file contains the declarations of the %ISecureSocketEventListener interface.
*/

#ifndef _FNET_SOCKBASE_EVENT_LISTENER_H_
#define _FNET_SOCKBASE_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FNetSockSocketTypes.h"

namespace Osp { namespace Net { namespace Sockets {

	// Forward declaration
	class SecureSocket;

	/**
	* @interface	ISecureSocketEventListener
	* @brief		This interface contains an event listener for the applications, which issues secure socket requests.
	* @since 		1.0
	*
	* 		The %ISecureSocketEventListener interface specifies the methods used for creating the notifications about the different kinds of socket 
	*				events. These events are sent out when using a secure socket in a non-blocking mode. An event listener is added by calling the 
	*				AddSecureSocketListener() method. One of these methods is called when a socket event is generated.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*/
	class _EXPORT_NET_ ISecureSocketEventListener :
		public Osp::Base::Runtime::IEventListener
	{
	// Lifecycle
	public:
		/**
		* This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~ISecureSocketEventListener(void) {}

	// Operation
	public:
		/**
		* Called to notify a connecting secure socket that its connection attempt has been completed successfully.
		*
		* @since		1.0
		* @param[in]	socket		The SecureSocket instance
		*/
		virtual void OnSecureSocketConnected(SecureSocket& socket) = 0;

		/**
		* Called to notify the registered secure socket that the peer secure socket has been closed due to normal or forced termination of network. @n
		* It is also used to notify a connecting secure socket that its connection attempt has resulted in an error.
		*
		* @since 		1.0
		* @param[in]	socket		The SecureSocket instance
		* @param[in]	reason		The reason of type NetSocketClosedReason for a closed secure socket
		* @remarks		If the reason is NET_SOCKET_CLOSED_REASON_NO_CERTIFICATE, start the Application control (APPCONTROL_PROVIDER_CERTIFICATE_MANAGER) for getting the selected client certificate. @n
		* 				For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>. (Osp::App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER)
		*/
		virtual void OnSecureSocketClosed(SecureSocket& socket, NetSocketClosedReason reason) = 0;

		/**
		* Called to notify a secure socket that the data is ready to be retrieved.
		*
		* @since 		1.0
		* @param[in]	socket		The SecureSocket instance
		* @remarks		This data can be retrieved by calling Receive().
		*/
		virtual void OnSecureSocketReadyToReceive(SecureSocket& socket) = 0;


		/**
		* Called to notify a secure socket that the data can be sent.
		*
		* @since 		1.0
		* @param[in]	socket		The SecureSocket instance
		* @remarks		This data can be sent by calling Send().
		*/
		virtual void OnSecureSocketReadyToSend(SecureSocket& socket) = 0;

		/**
		* Called to notify a secure socket that the verification of the server's certificate has failed. @n
		* Either of the following decisions can be taken after the verification fails: @n
		* - Continue with SSL handshaking without verification.
		* - Close the secure socket.
		*
		* @since 		1.0
		* @param[in] 	socket	 The SecureSocket instance
		*/
		virtual void OnSecureSocketServCertFailed(SecureSocket& socket) =0;
	};

}; // Osp::Net::Sockets
}; // Osp::Net
}; // Osp
#endif // _FNET_SOCKBASE_EVENT_LISTENER_H_
