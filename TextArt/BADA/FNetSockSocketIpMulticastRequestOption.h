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
* @file		FNetSockSocketIpMulticastRequestOption.h
* @brief	This is the header file for the %IpMulticastRequestOption class.
*
* This header file contains the declarations of the %IpMulticastRequestOption class.
*/

#ifndef _FNET_SOCK_SOCKET_IPMREQ_H_
#define _FNET_SOCK_SOCKET_IPMREQ_H_

// Includes
#include "FNetSockSocket.h"
#include "FBaseObject.h"

namespace Osp { namespace Net { namespace Sockets {

	// Forward declaration
	class IpMulticastRequestOptionEx;

	/**
	* @class	IpMulticastRequestOption
	* @brief	This class supports the multicasting in sockets for sending and receiving multicast datagram packets.
    *			For multicasting, a socket must be of type NET_SOCKET_TYPE_DATAGRAM. 
	* @since	1.0
	*
	* The %IpMulticastRequestOption class supports the multicasting in sockets for sending and receiving multicast datagram packets.
   *			For multicasting, a socket must be of type NET_SOCKET_TYPE_DATAGRAM. 
	*
	*	For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*
	* @see		<a href="classOsp_1_1Net_1_1Sockets_1_1Socket.html#216fee163c0c7b4210c1316ebcb7bc32">Osp::Net::Sockets::Socket::SetSockOpt</a>
	*
	* The following example demonstrates how to use the %IpMulticastRequestOption class with the multicast sender.
	*
	*	@code
	*				result res = E_SUCCESS;
	*
	*				// Creates the socket.
	*				Socket* pSocket = new Socket();
	*				res = pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);
	*
	*				// Adds the listener.
	*				MySocketListener* pSockListener = new MySocketListener();
	*				res = pSocket->AddSocketListener(*pSockListener);
	*
	*				// Selects the async event(non-blocking mode)
	*				res= pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_WRITE);
	*
	*				// Creates the multicast group end point to send the data.
	*				Ip4Address multicastAddr("255.1.1.1"); // multicast group address
	*				unsigned short multicastPort = XXXX;  // port
	*				NetEndPoint multicastEndPoint(multicastAddr, multicastPort);
	*
	*				// Creates the data to send.
	*				const char* pSendData = "Send";
	*				Osp::Base::ByteBuffer txBuffer;
	*				txBuffer.Construct(strlen(pSendData) + 1);
	*				txBuffer.SetArray((byte*)pSendData, 0, strlen(pSendData));
	*				txBuffer.Flip();
	*
	*				// Sends the data to the multicast group
	*				res = ptSocket->SendTo(txBuffer, multicastEndPoint);
	*	@endcode
	*
	* The following example demonstrates how to use the %IpMulticastRequestOption class with the multicast receiver.
	*
	*	@code
	*				result res = E_SUCCESS;
	*
	*				// Creates the socket.
	*				Socket* pSocket = new Socket();
	*				res = pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);
	*
	*				// Adds the listener.
	*				MySocketListener* pSockListener = new MySocketListener();
	*				res = pSocket->AddSocketListener(*pSockListener);
	*
	*				// Selects the async event(non-blocking mode).
	*				res = pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_READ);
	*
	*				// Binds to the local end point.
	*				Ip4Address localtAddr(NET_SOCKET_INADDR_ANY); // local address
	*				unsigned short localPort = XXXX;  // port
	*				NetEndPoint localEndPoint(localtAddr, localPort);
	*				res = pSocket->Bind(localEndPoint);
	*
	*				// Creates the multicast group end point.
	*				Ip4Address multicastAddr("255.1.1.1"); // multicast group address
	*				unsigned short multicastPort = YYYY;  // any port
	*				NetEndPoint multicastEndPoint(multicastAddr, multicastPort);
	*
	*				// Creates the network interface end point.
	*				Ip4Address interfaceAddr(NET_SOCKET_INADDR_ANY); // network interface address
	*				unsigned short interfacePort = ZZZZ;  // any port
	*				NetEndPoint interfaceEndPoint(interfaceAddr, interfacePort);
	*
	*				// Initializes the IpMulticastRequestOption.
	*				IpMulticastRequestOption ipMreq(multicastEndPoint, interfaceEndPoint);
	*
	*				// Joins the multicast group.
	*				res = pSocket->SetSockOpt(NET_SOCKET_IPPROTO_IP, NET_SOCKET_IP_ADD_MEMBERSHIP, ipMreq);
	*
	*				// Creates the buffer to receive data.
	*				Osp::Base::ByteBuffer rxBuffer;
	*				rxBuffer.Construct(MAX_BUFFER_SIZE);
	*
	*				// Receives the data from the multicast group.
	*				res = pSocket->ReceiveFrom(rxBuffer, localEndPoint);
	*	@endcode
	*/
	class _EXPORT_NET_ IpMulticastRequestOption :
		public Osp::Base::Object
	{
	// Lifecycle
	public:
	   /**
		* Initializes this instance of %IpMulticastRequestOption with the specified parameters.
		*
		* @since		1.0
		* @param[in]	multicastAddress		A NetEndPoint instance containing the IP address and port of the multicast group to be joined
		* @param[in]	interfaceAddress		A %NetEndPoint instance containing the IP address and port of the network interface on which the datagram
		*										packets will be received
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			A specified input parameter is invalid.
		* @exception	E_SYSTEM				An internal error has occurred.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*
		*/
		IpMulticastRequestOption(const NetEndPoint& multicastAddress, const NetEndPoint& interfaceAddress);

	   /**
		* This is the destructor for this class.
		*
		* @since		1.0
		*/
		virtual ~IpMulticastRequestOption(void);

		/**
		* This is the copy constructor for the %IpMulticastRequestOption class.
		*
		* @since		1.0
		* @param[in]	value			An instance of %IpMulticastRequestOption
		*/
		IpMulticastRequestOption(const IpMulticastRequestOption& value);


	// Operator
		/**
		* This is the assignment operator.
		*
		* @since		1.0
		* @return		A reference to this instance
		* @param[in]	rhs			An instance of %IpMulticastRequestOption
		*/
		const IpMulticastRequestOption& operator =(const IpMulticastRequestOption& rhs);


	// Accessor
	public:
	   /**
		* Sets the multicast group NetEndPoint instance with the specified instance.
		*
		* @since		1.0
		* @return		An error code
		* @param[in]	multicastAddress		A %NetEndPoint instance containing the IP address and port of the multicast group to be joined
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The specified input parameter is invalid.
		*/
		result SetMulticastEndPoint(NetEndPoint& multicastAddress);

	   /**
		* Sets the network interface NetEndPoint with the specified instance.
		*
		* @since		1.0
		* @return		An error code
		* @param[in]	interfaceAddress		A %NetEndPoint instance containing the address and port of the network interface on which the datagram 
		*										packets will be received
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The specified input parameter is invalid.
		*/
		result SetInterfaceEndPoint(NetEndPoint& interfaceAddress);

		/**
		* Gets the NetEndPoint of the multicast group.
		*
		* @since		1.0
		* @return		The multicast group %NetEndPoint, @n
		*				else @c null if the multicast group %NetEndPoint is @c null
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_STATE			The group end point is in an invalid state.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		const NetEndPoint* GetMulticastEndPoint(void) const;

		/**
		* Gets the NetEndPoint of the network interface.
		*
		* @since		1.0
		* @return		The network interface %NetEndPoint, @n
		*				else @c null if the network interface %NetEndPoint is @c null
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_STATE		The interface end point is in an invalid state.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		*/
		const NetEndPoint* GetInterfaceEndPoint(void) const;

	// Lifecycle
	private:
		/**
		*	This is the constructor for this class.
		*/
		IpMulticastRequestOption(void);

	//Attribute
	private:
		NetEndPoint* __pMulticastAddr;
		NetEndPoint* __pInterfaceAddr;

	private:
		// for ABC
		class IpMulticastRequestOptionEx* __pIpMulticastRequestOptionEx;

		// friend class declaration
		friend class Socket;
		friend class IpMulticastRequestOptionEx;
	};

};// Osp::Net::Sockets
};// Osp::Net
};// Osp

#endif // _FNET_SOCK_SOCKET_IPMREQ_H_

