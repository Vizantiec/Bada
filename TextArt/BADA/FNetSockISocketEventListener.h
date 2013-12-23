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
* @file		FNetSockISocketEventListener.h
* @brief	This is the header file for the %ISocketEventListener interface.
*
* This header file contains the declarations of the %ISocketEventListener interface.
*/

#ifndef _FNET_SOCK_ICLIENT_SOCKET_EVENT_LISTENER_H_
#define _FNET_SOCK_ICLIENT_SOCKET_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FNetSockSocketTypes.h"

namespace Osp { namespace Net { namespace Sockets {

	// Forward declaration
	class Socket;

	/**
	* @interface	ISocketEventListener
	* @brief		This interface contains a listener for the socket events.
	* @since 		1.0
	*
	* 	The %ISocketEventListener interface specifies the methods used for creating notifications about the different kinds of socket events. 
	*				These events are only sent out when using the socket in a non-blocking mode. A listener is registered by calling the AddSocketListener() 
	*				method. One of these methods is called when a socket event is generated.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*
	* The following example demonstrates how to use the %ISocketEventListener interface.
	*
	* @code
		using namespace Osp::Net::Sockets;

		class TestListener :
			public Object,
			public virtual ISocketEventListener
		{
		public:
			TestListener() {}

			~TestListener() {}

			void OnSocketConnected(Socket& socket)
			{
				AppLog("OnConnected\n");
			}

			void OnSocketClosed(Socket& socket, NetSocketClosedReason reason)
			{
				AppLog("OnClosed\n");
			}

			void OnSocketReadyToReceive(Socket& socket)
			{
				AppLog("OnReadyToReceive\n");
			}

			void OnSocketReadyToSend(Socket& socket)
			{
				AppLog("OnReadyToSend\n");
			}
		};
	* @endcode
	*/
	class _EXPORT_NET_ ISocketEventListener :
		public Osp::Base::Runtime::IEventListener
	{
	// Lifecycle
	public:
		/**
		* This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~ISocketEventListener(void) {}


	// Operation
	public:
		/**
		* Called to notify a connecting socket that its connection attempt has been completed successfully.
		*
		* @since 		1.0
		* @param[in]	socket		The %Socket instance
		*/
		virtual void OnSocketConnected(Socket& socket) = 0;

		/**
		* Called to notify the registered socket that the peer socket has been closed due to normal or forced termination of the network. @n
		* It is also used to notify a connecting socket that its connection attempt has resulted in an error.
		*
		* @since 		1.0
		* @param[in]	socket		The Socket instance
		* @param[in]	reason		The reason of type NetSocketClosedReason for a closed socket
		*/
		virtual void OnSocketClosed(Socket& socket, NetSocketClosedReason reason) = 0;

		/**
		* Called to notify a socket that the data is ready to be retrieved.
		*
		* @since 		1.0
		* @param[in]	socket		The %Socket instance
		* @remarks		The data can be retrieved by calling Receive() or ReceiveFrom().
		*/
		virtual void OnSocketReadyToReceive(Socket& socket) = 0;

		/**
		* Called to notify a socket that the data can be sent.
		*
		* @since 		1.0
		* @param[in]	socket		The %Socket instance
		* @remarks		The data can be sent using Send() or SendTo().
		*/
		virtual void OnSocketReadyToSend(Socket& socket) = 0;

		/**
		* Called to notify a socket that it has received a new connection from a peer.
		*
		* @since 		1.0
		* @param[in]	socket		The Socket instance
		*/
		virtual void OnSocketAccept(Socket& socket) = 0;
	};

}; // Osp::Net::Sockets
}; // Osp::Net
}; // Osp
#endif // _FNET_SOCK_ICLIENT_SOCKET_EVENT_LISTENER_H_

