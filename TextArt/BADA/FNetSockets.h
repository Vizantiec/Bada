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
* @file		FNetSockets.h
* @brief	This is the header file for the %Sockets namespace.
*
* This header file contains the declarations and descriptions of the %Sockets namespace.
*/

#ifndef _FNET_SOCKETS_H_
#define _FNET_SOCKETS_H_

#include "FNetSockSocket.h"
#include "FNetSockISocketEventListener.h"
#include "FNetSockSecureSocket.h"
#include "FNetSockISecureSocketEventListener.h"
#include "FNetSockSocketIpMulticastRequestOption.h"
#include "FNetSockSocketLingerOption.h"
#include "FNetSockSocketUtility.h"
#include "FNetSockSocketTypes.h"

namespace Osp { namespace Net {
	/**
	* @namespace	Osp::Net::Sockets
	* @brief		This namespace contains the classes and interfaces for Transmission Control Protocol (TCP) or User Datagram Protocol (UDP) socket 
	*				programming.
	* @since 		1.0
	*
	* @remarks  	@b Header @b %file: @b \#include @b <FNet.h> @n
    *				@b Library : @b FOsp @n
	*
	* 				The %Osp::Net::Sockets sub-namespace implements the socket data communication protocols by providing a rich set of methods for connecting, 
	*				sending, and receiving data over a network.
	* 
	* For more information on the %Sockets namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*
	*
	* The following diagram illustrates the relationships between the classes belonging to the %Sockets namespace.
	* @image html net_socket_using_the_apis_classdiagram.png
	*
	
	* The following example demonstrates how to use a TCP client non-blocking socket.
	*
	*				@code
	*				result res = E_SUCCESS;
	*
	*				// Creates the socket.
	*				Socket* pClientSocket = new Socket();
	*				res = pClientSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_STREAM, NET_SOCKET_PROTOCOL_TCP);
	*
	*				// Adds listener.
	*				MySocketClientListener* pSockClientListener = new MySocketClientListener();
	*				res = pClientSocket->AddSocketListener(*pSockClientListener);
	*
	*				// Selects asynchronous event (non-blocking mode).
	*				res= pClientSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT| NET_SOCKET_EVENT_CLOSE);
	*
	*				// Creates peer endpoint.
	*				Ip4Address peerAddr("XXX.XXX.XXX.XXX"); //server socket address.
	*				unsigned short peerPort = YYY;  // port
	*				NetEndPoint* pPeerEndPoint = new NetEndPoint(peerAddr, peerPort);
	*
	*				// Connects the socket.
	*				res = pClientSocket->Connect(*pPeerEndPoint);
	*				@endcode
	*/

	namespace Sockets
	{
	}; // Osp::Net::Sockets
}; // Osp::Net
}; // Osp
#endif // _FNET_SOCKETS_H_
