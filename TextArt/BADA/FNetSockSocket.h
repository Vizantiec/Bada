/* $Change: 1198808 $ */
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
* @file		FNetSockSocket.h
* @brief	This is the header file for the %Socket class.
*
* This header file contains the declarations of the %Socket class. @n
* The %Socket is a base class that provides methods for sending and receiving the data over a network.
*/

#ifndef _FNET_SOCK_SOCKET_H_
#define _FNET_SOCK_SOCKET_H_

#include "FBaseObject.h"
#include "FBaseResource.h"
#include "FNetNetEndPoint.h"
#include "FNetNetConnection.h"

#include "FNetIP4Address.h"
#include "FNetSockSocketTypes.h"
#include "FNetSockSocketLingerOption.h"
#include "FNetSockSocketIpMulticastRequestOption.h"

#include "FNetSockISocketEventListener.h"

namespace Osp { namespace Net {
	class _DefaultNetConnection;
}};

namespace Osp { namespace Net { namespace Sockets {

	// Forwarding class
	class ISocketEventListener;
	class __SocketEvent;
	class  ISocketPi;
	class LingerOption;
	class IpMulticastRequestOption;
	class SocketEx;

	/**
	* @class	Socket
	* @brief	This class is the base class that provides simple methods for sending and receiving the data over a network.
	* @since 	1.0
	*
	* The %Socket class is the base class that provides simple methods for sending and receiving the data over a network.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*/
	class _EXPORT_NET_ Socket :
		public Osp::Base::Object,
		public Osp::Base::__Resource
	{
	// Lifecycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since 		1.0
		* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
		* @see 			Construct()
		*/
		Socket(void);

		/**
		* This is the destructor for this class.
		*
		* @since 		1.0
		* @see 			Close()
		*/
		virtual ~Socket(void);

		/**
		* Initializes this instance of %Socket class with the specified parameters. @n
		* The socket is initialized in a non-blocking mode by default.
		* Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %Socket in the blocking mode.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	netConnection				A run-time session where a %Socket instance will be used
		* @param[in]	addressFamily				A ::NetSocketAddressFamily value
		* @param[in]	socketType					A ::NetSocketType value
		* @param[in]	protocol					A ::NetSocketProtocol value
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_MAX_EXCEEDED				All sockets are in use.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
		* @exception	E_UNSUPPORTED_TYPE			The socket type is not supported.
		* @exception	E_UNSUPPORTED_FAMILY		The address family is not supported.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception	E_INVALID_CONNECTION		The network connection is invalid.
		* @exception	E_FAILURE					The method has failed.
		* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks 		The @c netConnection parameter specifies a run-time network connection. @n
		*				The @c addressFamily parameter specifies an address family. @n
		*				The @c socketType parameter specifies the type of the socket. @n
		*				The @c protocol parameter specifies the protocol used by the socket. @n
		*				The first parameter must be a valid run-time network connection. @n
		*				The three parameters (without @c netConnection) are not independent. @n
		*				Some address families restrict the protocols which can be used with them,
		*				and often the socket type is implicit in the protocol. @n
		*				If the combination of address family, socket type, and protocol type results in
		*				an invalid socket, this method returns an error. @n
		*				This method is used for a socket of type NET_SOCKET_PROTOCOL_TCP, NET_SOCKET_PROTOCOL_UDP, or NET_SOCKET_PROTOCOL_SSL. @n
		*				If the blocking mode is being used, and a method call is made which does not
		*				complete immediately, the application blocks execution until the requested operation is completed. @par
		*				If the execution is to be continued even though the requested operation
		*				is not complete, the non-blocking mode should be used, which is the default mode in this method. @n
		*				For each socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
		*				and maintained, so that it can receive asynchronous notifications of socket events. @n
		*				To register the listener, AddSocketListener() should be used after calling this method. @n
		*				If a socket in the blocking mode needs to be used, Ioctl() (with NET_SOCKET_FIONBIO) should be called after initializing the socket
		*				through this method. @n
		*				Note that a loopback socket is not supported.
		* @see			Ioctl() for understanding the blocking/non-blocking mode
		*/
		result Construct(const NetConnection& netConnection, NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

		/**
		* Initializes this instance of %Socket class with the specified parameters. @n
		* The socket is initialized in a non-blocking mode by default.
		* Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %Socket in the blocking mode.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	addressFamily				A ::NetSocketAddressFamily value
		* @param[in]	socketType					A ::NetSocketType value
		* @param[in]	protocol					A ::NetSocketProtocol value
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_MAX_EXCEEDED				All sockets are in use.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
		* @exception	E_UNSUPPORTED_TYPE			The socket type is not supported.
		* @exception	E_UNSUPPORTED_FAMILY		The address family is not supported.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception	E_INVALID_CONNECTION		The network connection is invalid.
		* @exception	E_FAILURE					The method has failed.
		* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		The @c addressFamily parameter specifies an address family. @n
		*				The @c socketType parameter specifies the type of the socket. @n
		*				The @c protocol parameter specifies the protocol used by the socket. @n
		*				The three parameters are not independent. @n
		*				Some address families restrict the protocols which can be used with them,
		*				and often the socket type is implicit in the protocol. @n
		*				If the combination of address family, socket type, and protocol type results in
		*				an invalid socket, this method returns an error. @n
		*				This method is used for a socket of the type NET_SOCKET_PROTOCOL_TCP, NET_SOCKET_PROTOCOL_UDP, or NET_SOCKET_PROTOCOL_SSL. @n
		*				If the blocking mode is being used, and a method call is made which does not
		*				complete immediately, the application blocks the execution
		*				until the requested operation is completed. @par
		*				If the execution is to be continued even though the requested operation
		*				is not complete, the non-blocking mode should be used, which is the default mode in this method. @n
		*				For each socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
		*				and maintained, so that it can receive asynchronous notifications of the socket events. @n
		*				To register the listener, AddSocketListener() should be used after calling this method. @n
		*				If a socket in the blocking mode needs to be used, Ioctl (with NET_SOCKET_FIONBIO) should be called after initializing the socket
		*				through this method. @n
		*				Note that loopback socket is not supported.
		* @see			Ioctl() for understanding the blocking/non-blocking mode
		*/
		result Construct(NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

		/**
		* @if PRIVCORE
		* Initializes this instance of %Socket class with the specified parameter. @n
		* The socket is initialized in a non-blocking mode by default. @n
		* Use Ioctl() (with NET_SOCKET_FIONBIO) to use a %Socket in the blocking mode.
		*
		* @since 		1.0
		* @privlevel	CORE
		* @privgroup  	LOCAL_SOCKET
		*
		* @return		An error code
		* @param[in]	addressFamily				A ::NetSocketAddressFamily value (Only NET_SOCKET_AF_LOCAL)
		* @param[in]	socketType					A ::NetSocketType value
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_MAX_EXCEEDED				All sockets are in use.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_UNSUPPORTED_TYPE			The socket type is not supported.
		* @exception	E_UNSUPPORTED_FAMILY		The address family is not supported.
		* @exception	E_FAILURE					The method has failed.
		* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		Do not use this method without obtaining prior permissions from the bada platform team. @par
		* 				If the blocking mode is being used, and a method call is made which does not
		*				complete immediately, the application blocks the execution
		*				until the requested operation is completed. @par
		*				If the execution is to be continued even though the requested operation
		*				is not complete, the non-blocking mode should be used, which is the default mode in this method. @n
		*				For each socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
		*				and maintained, so that it can receive asynchronous notifications of socket events. @n
		*				To register the listener, the AddSocketListener() should be used after calling this method. @n
		*				If a socket in the blocking mode needs to be used, Ioctl (with NET_SOCKET_FIONBIO) should be called after initializing the socket
		*				through this method.
		* @see			Ioctl() for understanding the blocking/non-blocking mode
		*
		* @endif
		*
		*/
		result Construct(NetSocketAddressFamily addressFamily, NetSocketType socketType);

	// Operation
	public:
		/**
		* Closes the socket. @n
		* All the resources associated with the socket are freed.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception  	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		If the %Socket is not initialized through one of the Construct() methods, or this method is called more than once,
		*				this method returns E_INVALID_STATE.
		*/
		result Close(void);

		/**
		* Binds the socket to a local address.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	localEndPoint				The local NetEndPoint to associate with the %Socket
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_ALREADY_BOUND				The address is already in use.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception  	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		Use this method if a specific local endpoint should be used. @n
		*				This method can be used on both the connectionless and connection-oriented protocols. @n
		*				For connection-oriented sockets, Bind() need not be called
		*				before using the Connect() method, unless a specific local endpoint needs to be used. @n
		*				The Bind() method must be called before the Listen() method.
		*/
		result Bind(const Osp::Net::NetEndPoint& localEndPoint);

		/**
		* Establishes a connection to a remote host for a connection-oriented socket. @n
		* This socket is of the NET_SOCKET_TYPE_STREAM type.
		*
		* @since 			1.0
		* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
		*                	For more information, see @ref SocketConnectPage "here".
		*
		* @privlevel		NORMAL
		* @privgroup		SOCKET
		*
		* @return			An error code
		* @param[in]		remoteEndPoint				A NetEndPoint representing the remote device
		* @exception		E_SUCCESS					The method is successful.
		* @exception		E_INVALID_SOCKET			The socket is invalid.
		* @exception		E_INVALID_STATE				The socket is not in a valid state.
		* @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
		* @exception		E_IN_PROGRESS				A previous request is in progress.
		* @exception		E_INVALID_ARG				A specified input parameter is invalid.
		* @exception		E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception		E_CONNECTION_FAILED			The socket is not connected.
		* @exception		E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception		E_ALREADY_CONNECTED			The socket is already connected.
		* @exception		E_UNSUPPORTED_FAMILY		The address family is not supported.
		* @exception		E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
		* @exception    	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception		E_SYSTEM					A system error has occurred.
		* @exception    	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks			If the socket is a connectionless socket (that is, of the NET_SOCKET_TYPE_DATAGRAM type), this method fails. @n
		*					After Connect() is called, the data can be sent to and received from the remote device using Send() and Receive() respectively. @n
		*					If a connection-oriented protocol is used and Bind() is not called before calling Connect(), the underlying service provider 
		*					assigns the local network address and port number.
		*/
		result Connect(const Osp::Net::NetEndPoint& remoteEndPoint);

        /**
        * @page			SocketConnectPage	Compatibility for Connect()
        *
        * @section		SocketConnectPageIssueSection	Issues
        * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
        * -# If the application provides an invalid NetEndPoint, the application terminates abnormally.
        *
        * @section		SocketConnectPageResolutionSection	Resolutions
        *  The issue mentioned above is resolved in bada API version 1.2 as follows: @n
        *  -# If the application provides an invalid NetEndPoint, it returns E_INVALID_ARG instead of being terminated abnormally. @n
        */

		/**
		* Sends the data to a socket of the type NET_SOCKET_TYPE_STREAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	buffer						The ByteBuffer that contains the data to be sent
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception  E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The Send() method sends the data to the remote host specified in the Connect() or Accept() method. @n
		*				The Send() method sends the data in the @c buffer parameter, starting from the current position of the buffer. @n
		*				After the operation, the position of the buffer is incremented by the number of bytes successfully sent. @n
		*				The new position cannot be larger than the original limit. @N
		*				The Send() method can be used only for connection-oriented sockets. @n
		*				In the blocking mode, if there is no space left in the send queue, the socket blocks until space becomes available. @n
		*				In the non-blocking mode, this method returns the error E_WOULD_BLOCK. @n
		*				Send() may complete successfully even if it sends less than the number of bytes
		*				in the buffer. The application should keep track of the number of bytes sent
		*				and retry the operation until the application sends the bytes in the buffer. @n
		*				There is no guarantee that the data that is sent appears on the network immediately. @n
		*				To increase network efficiency, the underlying system may delay transmission until a significant amount
		*				of outgoing data is collected. The successful completion of the Send() method means that the underlying
		*				system has had room to buffer the data for a network send. @n
		*				If it is important to send every byte to the remote host immediately,
		*				SetSockOpt() (with NET_SOCKET_TCP_NODELAY) can be used to enable no delay, the value of type ::NetSocketOptName.
		*/
		result Send(Osp::Base::ByteBuffer& buffer);

		/**
		* Sends the data to a socket of the type NET_SOCKET_TYPE_STREAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	pBuffer						The pointer to the buffer containing the data to be sent
		* @param[in]	length						The length of the data in the buffer
		* @param[out]	sentLength					The length of the data that is sent successfully
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The Send() method sends the data to the remote host specified in the Connect() or Accept() method. @n
		*				The Send() method sends the data in the buffer of length @c length, starting from the current position of the buffer. @n
		*				The Send() method can be used only for connection-oriented sockets. @n
		*				In the blocking mode, if there is no space left in the send queue, the socket blocks until space becomes available. @n
		*				In the non-blocking mode, this method returns the E_WOULD_BLOCK error. @n
		*				Send() may complete successfully even if it sends less than the number of bytes
		*				in the buffer. The application should keep track of the number of bytes sent
		*				and retry the operation until the application sends the bytes in the buffer. @n
		*				There is no guarantee that the data that is sent appears on the network immediately. @n
		*				To increase the network efficiency, the underlying system may delay the transmission until a significant amount
		*				of outgoing data is collected. The successful completion of the Send() method means that the underlying
		*				system has had room to buffer the data for a network send. @n
		*				If it is important to send every byte to the remote host immediately,
		*				SetSockOpt() (with NET_SOCKET_TCP_NODELAY) can be used to enable no delay, the value of type ::NetSocketOptName.
		*/
		result Send(void* pBuffer, int length, int& sentLength);

		/**
		* Sends the data to a socket of the type NET_SOCKET_TYPE_DATAGRAM.
		*
		* @since 			1.0
		* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
		*                	For more information, see @ref SocketSendToPage1 "here".
		*
		* @return			An error code
		* @param[in]		buffer						The ByteBuffer containing the data to be sent
		* @param[in]		remoteEndPoint				The NetEndPoint representing the destination for the data
		* @exception		E_SUCCESS					The method is successful.
		* @exception		E_INVALID_SOCKET			The socket is invalid.
		* @exception		E_INVALID_STATE				The socket is not in a valid state.
		* @exception		E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception		E_INVALID_ARG				A specified input parameter is invalid.
		* @exception		E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
		* @exception		E_OUT_OF_RANGE				The message length has exceeded the maximum limit of the socket.
		* @exception  		E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception		E_SYSTEM					A system error has occurred.
		*
		* @remarks		The SendTo() method sends the data to the remote host specified by the @c remoteEndPoint parameter. @n
		*				The SendTo() method sends the data in the @c buffer parameter, starting from the current position of the buffer. @n
		*				After the operation, the position of the buffer is incremented by the number of bytes successfully sent. @n
		*				The new position cannot be larger than the original limit. @n
		*				The SendTo() method can be used only for connectionless sockets. @n
		*				In the blocking mode, if space is not available in the send queue, the socket blocks
		*				until space becomes available. If the socket is in the non-blocking mode,
		*				the method returns the error E_WOULD_BLOCK.
		*/
		result SendTo(Osp::Base::ByteBuffer& buffer, const Osp::Net::NetEndPoint& remoteEndPoint);

        /**
        * @page			SocketSendToPage1	Compatibility for SendTo()
        *
        * @section		SocketSendToPage1IssueSection	Issues
        * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
        * -# If the application provides an invalid NetEndPoint, the application terminates abnormally.
        *
        * @section		SocketSendToPage1ResolutionSection	Resolutions
        * The issue mentioned above is resolved in bada API version 1.2 as follows: @n
        * -# If the application provides an invalid NetEndPoint, it returns E_INVALID_ARG instead of being terminated abnormally. @n
        */

		/**
		* Sends the data to a socket of the type NET_SOCKET_TYPE_DATAGRAM.
		*
		* @since 			1.0
		* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
		*                	For more information, see @ref SocketSendToPage2 "here".
		*
		* @return			An error code
		* @param[in]		pBuffer					The pointer to the buffer containing the data to be sent
		* @param[in]		length					The length of the data in buffer
		* @param[in]		remoteEndPoint			The NetEndPoint representing the destination for the data
		* @param[out]		sentLength				The length of the data that is sent successfully
		* @exception		E_SUCCESS				The method is successful.
		* @exception		E_INVALID_SOCKET		The socket is invalid.
		* @exception		E_INVALID_STATE			The socket is not in a valid state.
		* @exception		E_UNSUPPORTED_OPTION	The specified parameters are not supported.
		* @exception		E_INVALID_ARG			A specified input parameter is invalid.
		* @exception		E_WOULD_BLOCK			A non-blocking socket operation cannot be completed immediately.
		* @exception		E_HOST_UNREACHABLE		The network cannot be reached from this host at this time.
		* @exception		E_OUT_OF_RANGE			The message length has exceeded the maximum limit of the socket.
		* @exception  		E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception		E_SYSTEM				A system error has occurred.
		*
		* @remarks			The SendTo() method sends the data to the remote host specified by the @c remoteEndPoint parameter. @n
		*					The SendTo() method sends the data in the buffer. The length of the data is specified by @c length, starting from the current 
		*					position of the buffer. @n
		*					The SendTo() method can be used only for connectionless sockets. @n
		*					In the blocking mode, if space is not available in the send queue, the socket blocks
		*					until space becomes available. If the socket is in the non-blocking mode,
		*					the method returns the E_WOULD_BLOCK error.
		*/
		result SendTo(void* pBuffer, int length, const Osp::Net::NetEndPoint& remoteEndPoint, int& sentLength);

        /**
        * @page			SocketSendToPage2	Compatibility for SendTo()
        *
        * @section		SocketSendToPage2IssueSection	Issues
        * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
        * -# If the application provides an invalid NetEndPoint, the application terminates abnormally.
        *
        * @section		SocketSendToPage2ResolutionSection	Resolutions
        *  The issue mentioned above is resolved in bada API version 1.2 as follows: @n
        * -# If the application provides an invalid NetEndPoint, it returns E_INVALID_ARG instead of being terminated abnormally. @n
        */

		/**
		* Receives the data from a socket of the type NET_SOCKET_TYPE_STREAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	buffer						The ByteBuffer that is the storage location for the received data
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				The specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The Receive() method copies the data into the @c buffer parameter, starting from the current position of the buffer.
		*				After the operation, the position of the buffer is incremented by the number of bytes successfully received.
		*				The new position cannot be larger than the original limit.
		*				The Receive() method can only be called from connection-oriented sockets.
		*				If no data is available at the socket and the socket is in the blocking mode,
		*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
		*				the error E_WOULD_BLOCK is returned instead.
		*/
		result Receive(Osp::Base::ByteBuffer& buffer) const;

		/**
		* Receives the data from a socket of type NET_SOCKET_TYPE_STREAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	pBuffer						The pointer of buffer that is the storage location for the received data
		* @param[in]	length						The length of the data in buffer
		* @param[out]	rcvdLength					The length of the data that is received successfully
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The Receive() method copies the data into the buffer. The length of the data is specified by @c length starting from the current 
		*				position of the buffer. @n
		*				The Receive() method can be called only from connection-oriented sockets. @n
		*				If no data is available at the socket and the socket is in the blocking mode,
		*				this method blocks until the data arrives. If the socket is in the non-blocking mode,
		*				the E_WOULD_BLOCK error is returned instead.
		*/
		result Receive(void* pBuffer, int length, int& rcvdLength) const;

		/**
		* Receives the data from a socket of the type NET_SOCKET_TYPE_DATAGRAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	buffer						The ByteBuffer storage location for the received data
		* @param[out]	remoteEndPoint				The NetEndPoint of the remote server 
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_OUT_OF_RANGE				The message length exceeded the maximum limit.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		This method copies the data into the specified buffer, starting from the current position of the buffer.
		*				After the operation, the position of the buffer is incremented by the number of bytes successfully received.
		*				The new position cannot be larger than the original limit.
		*				The method returns the remote host endpoint from which the data is sent.
		*				The ReceiveFrom() method can only be called from connectionless sockets; that is,
		*				this method is used only if connectionless datagrams are to be received
		*				from an unknown host or multiple hosts.
		*				The ReceiveFrom() method reads the first enqueued datagram received
		*				into the local network buffer. If the datagram received is larger
		*				than the remaining bytes of the buffer, the ReceiveFrom() method returns the error E_OUT_OF_RANGE.
		*				If no data is available at the socket and the socket is in the blocking mode,
		*				this method blocks until data arrives. If the socket is in the non-blocking mode,
		*				the error E_WOULD_BLOCK is returned instead.
		*/
		result ReceiveFrom(Osp::Base::ByteBuffer& buffer, Osp::Net::NetEndPoint& remoteEndPoint) const;

		/**
		* Receives the data from a socket of the type NET_SOCKET_TYPE_DATAGRAM.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	pBuffer						The pointer to the buffer that is the storage location for the received data
		* @param[in]	length						The length of the data in buffer
		* @param[out]	remoteEndPoint				The NetEndPoint of the remote server
		* @param[out]	rcvdLength					The length of the data which is received successfully
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_OUT_OF_RANGE				The message length exceeded the maximum limit.
		* @exception  E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		This method copies the data into the buffer until length, starting from the current position of the buffer.
		*				The method returns the remote host endpoint from which the data is sent.
		*				The ReceiveFrom() method can only be called from connectionless sockets; that is,
		*				this method is used only if connectionless datagrams are to be received
		*				from an unknown host or multiple hosts.
		*				The ReceiveFrom() method reads the first enqueued datagram received
		*				into the local network buffer. If the datagram received is larger
		*				than the value of length parameter, the ReceiveFrom() method will return an error (E_OUT_OF_RANGE).
		*				If no data is available at the socket and the socket is in the blocking mode,
		*				this method blocks until data arrives. If the socket is in the non-blocking mode,
		*				the E_WOULD_BLOCK error is returned instead.
		*/
		result ReceiveFrom(void* pBuffer, int length, Osp::Net::NetEndPoint& remoteEndPoint, int& rcvdLength) const;

		/**
		* Places the %Socket in a listening state.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	backLog						The maximum length of the pending connections queue
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation could not be completed immediately.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
		* @exception	E_ALREADY_CONNECTED			The socket is already connected.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception  	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		The Listen() method causes a connection-oriented socket to listen for
		*				the incoming connection attempts. The @c backlog parameter specifies
		*				the number of incoming connections that can be queued for acceptance.
		*				The Bind() method must be called before calling this method.
		*/
		result Listen(int backLog);

		/**
		* Accepts an incoming connection. @n
		* This method extracts the first connection from the queue of pending connections, and
		* creates a new socket with the same socket type, protocol type, and protocol family
		* as the listening socket.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		A new socket for a newly created connection with the same socket type, protocol type, and protocol family, @n
		*				else @c null if an error occurs
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_WOULD_BLOCK				A non-blocking socket operation cannot be completed immediately.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		This operation is not supported for this socket.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception  	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		Before calling the Accept() method, the Listen() method must be called first
		*				to listen for and queue the incoming connection requests.
		*				In the blocking mode, Accept() blocks until an incoming connection attempt
		*				is queued. After accepting a connection, the original %Socket
		*				continues queuing the incoming connection requests until it is closed.
		*				Note that if no connection is pending in the queue and the socket is in the blocking mode,
		*				this method blocks until a new connection arrives. If the socket is in the non-blocking mode,
		*				the E_WOULD_BLOCK exception is thrown. The specific error code can be accessed using the GetLastResult() method.
		*/
		Socket* AcceptN(void) const;

		/**
		* Executes the specified command on the socket.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*	
		* @return		An error code
		* @param[in]	cmd		 					The command to be executed on the socket sockDesc
		* @param[in,out]value						The value of the IOCTL command
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception  	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception  	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		This method manipulates the underlying device parameters of socket descriptors. @par
		*				NET_SOCKET_FIONBIO option is used for setting the non-blocking/blocking mode on a socket. @n
		*				NET_SOCKET_FIONREAD option is used for getting the number of bytes that are immediately available for reading. @n
		*				NET_SOCKET_FIONWRITE option is used for getting the number of bytes that have not yet been
		*		        acknowledged by the other side of the connection. This option is not supported in this SDK. @n
		*				NET_SOCKET_SIOCATMARK option is used to determine if all out of band (OOB) data has been read.
		*				Currently sockets do not support this option.
		*
		*/
		result Ioctl(NetSocketIoctlCmd cmd, unsigned long& value) const;

		/**
		* Sets the socket to the asynchronous mode by a specified message to the specified event handler when the socket events occur.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	socketEventType				The socket events of ::NetSocketEventType @n
		*											Multiple events can be combined using the bitwise "|" operator.
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_INVALID_ARG				The specified input parameter is invalid.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT 					An attempt to connect to the server has timed out.
		*
		*/
		result AsyncSelectByListener(unsigned long socketEventType);

		/**
		* Adds the specified listener to the socket.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	listener				A reference to ISocketEventListener
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_INVALID_SOCKET		The socket is invalid.
		* @exception	E_INVALID_STATE			The associated socket is not in a valid state.
		* @exception	E_SYSTEM				A system error has occurred.
		*/
		result AddSocketListener(const ISocketEventListener&  listener);

		/**
		* Removes the specified listener.
		*
		* @since 		1.0
		* @return 		An error code
		* @param[in]	listener				A reference to ISocketEventListener
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_OBJ_NOT_FOUND			The specified object is not found within the indicated range.
		* @exception	E_INVALID_SOCKET		The socket is invalid.
		* @exception	E_INVALID_STATE			The associated socket is not in a valid state.
		* @exception	E_SYSTEM				A system error has occurred.
		*/
		result RemoveSocketListener(const ISocketEventListener&  listener);

	// Accessor
	public:
		/*
		* Returns the __SocketEvent object associated with this Socket.
		* It is fired when the events of this Socket occur.
		*
		* @return		The __SocketEvent object associated with this Socket
		* @remarks		For each Socket used in the non-blocking mode, an event listener (ISocketEventListener)
		*				should be registered and maintained, via which asynchronous notifications of Socket events
		*				can be received. If you want to use a Socket in the non-blocking mode,
		*				you should call Socket::AddSocketListener of the socket object,
		*				after initializing the Socket through the Construct method.
		*				The current implementation of Socket allows only one listener to be added to its event only once.
		*/
		//const Osp::Base::Runtime::IEvent* GetSocketEvent(void) const;

		/**
		* Gets the peer EndPoint for this socket. @n
		* It returns a NetEndPoint containing the peer IP address and port number.
		*
		* @since 		1.0
		* @return		The peer EndPoint for the calling %Socket instance, @n
		*				else @c null if the socket is not connected to any peer
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_STATE		The socket is not in a valid state.
		* @exception	E_SYSTEM			A system error has occurred.
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			GetLocalEndPoint()
		*/
		const NetEndPoint* GetPeerEndPoint(void) ;

		/**
		* Gets the local EndPoint for this socket. @n
		* It returns a NetEndPoint containing the local IP address and port number.
		*
		* @since 		1.0
		* @return		The local EndPoint for the calling %Socket instance, @n
		*				else @c null
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_STATE		The socket is not in a valid state.
		* @exception	E_SYSTEM			A system error has occurred.
		* @remarks		This NetEndPoint must be cast to a NetEndPoint before retrieving any information.
		*/
		const NetEndPoint* GetLocalEndPoint(void) ;

		/**
		* Gets an option of the socket.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					A ::NetSocketOptLevel value
		* @param[in]	optionName					A ::NetSocketOptName value
		* @param[out]	optionValue					The integer to receive the option setting
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INIT_FAILED				The socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		* @remarks		%Socket options determine the behavior of the current socket.
		*				Upon successful completion of this method,
		*				@c optionValue shall contain the value of the specified %Socket option.
		*				For an option with a bool data type, a non-zero value is returned if the option is enabled. Otherwise,
		*				a zero value is returned. For an option with an integer data type, the method returns the appropriate value.
		*				%Socket options are grouped by the level of protocol support.@par
		*				Listed below are the various %Socket options that can be obtained using this overload. These options are
		*				grouped by the appropriate NetSocketOptLevel.
		*				Use the appropriate NetSocketOptLevel for the @c optionLevel parameter. The option you choose to get
		*				must be specified in the @c optionName parameter. If you want to set the current value of some of
		*				the options listed, use the SetOption() method. @par
		*				The OptionNames are categorized under their specific option levels. @par
		*				NET_SOCKET_IPPROTO_TCP  @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_NODELAY: Disables the Nagle algorithm for send coalescing. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_MAXSEG: Specifies the MSS(Maximum Segment Size) for TCP. @par
		*				NET_SOCKET_IPPROTO_IP @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TTL: Time-to-live. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TOS: Type-of-service and precedence. @par
		*				NET_SOCKET_SOL_SOCKET @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_ACCEPTCONN: The socket is listening. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_BROADCAST: Permits the sending of broadcast messages. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_KEEPALIVE: Uses keep-alive. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_LINGER: Lingers on close if data is present. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_OOBINLINE: Leaves the received Out Of Band data in line. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVBUF: Buffer size for receives. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVTIMEO: Receives a time-out. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_REUSEADDR: Allows the socket to be bound to an address that is already in use. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDBUF: Buffer size for sends. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDTIMEO: Sends a time-out. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_TYPE: Gets the socket type. @n
		* @see SetSockOpt()
		*/
		result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int& optionValue) const;

		/**
		* Gets the socket option status of SO_LINGER.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					The Socket option level @n
		*											The @c optionLevel is NET_SOCKET_SOL_SOCKET
		* @param[in]	optionName					The Socket configuration option @n 
		*											The @c optionName is NET_SOCKET_SO_LINGER
		* @param[out]	optionValue					The LingerOption that is to receive the option setting
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INIT_FAILED				The socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		* @see Osp::Net::Sockets::LingerOption
		*/
		result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, LingerOption& optionValue) const;

		/**
		* Changes an option of the socket.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					A ::NetSocketOptLevel value
		* @param[in]	optionName					A ::NetSocketOptName value
		* @param[in]	optionValue					The value of the option
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INIT_FAILED				The socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		* @remarks		The SetSockOpt() method is used to change the value of the option specified by the @c optionName parameter.
		*				%Socket options determine the behavior of the current socket. For an option with a bool data type,
		*				a non-zero value must be specified to enable the option, and a zero value must be specified to disable the option.
		*				For an option with an integer data type, the appropriate value must be specified. %Socket options are grouped
		*				by the level of protocol support. @par
		*				Listed below are the various socket options that can be set using this overload. These options are
		*				grouped by the appropriate NetSocketOptLevel. If you intend to set any of these options, be sure to
		*				use the appropriate NetSocketOptLevel for the @c optionLevel parameter. The option you choose to set
		*				must be specified in the @c optionName parameter. If you want to get the current value of some of
		*				the options listed, use the GetSockOpt() method. @par
		*				The OptionNames are categorized under their specific option levels. @par
		*				NET_SOCKET_IPPROTO_TCP @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_NODELAY: Disables the Nagle algorithm for send coalescing. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_TCP_MAXSEG: Specifies the MSS(Maximum Segment Size) for TCP. @par
		*				NET_SOCKET_IPPROTO_IP @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TTL: Time-to-live. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_IP_TOS: Type-of-service and precedence. @par
		*				NET_SOCKET_SOL_SOCKET @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_BROADCAST : Permits sending of broadcast messages. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_KEEPALIVE: Uses keep-alive. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_LINGER: Lingers on close if data present. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_OOBINLINE: Leaves received Out Of Band data in line. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVBUF: Buffer size for receives. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_RCVTIMEO: Receives a time-out. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_REUSEADDR: Allows the socket to be bound to an address that is already in use. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDBUF: Buffer size for sends. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SNDTIMEO: Sends a time-out.
		*
		*
		*/
		result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int optionValue);

		/**
		* Enables or disables SO_LINGER with the specified linger time in seconds. @n
		* The maximum timeout value is platform-specific. This setting only affects socket close.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					The Socket option level should be NET_SOCKET_SOL_SOCKET
		* @param[in]	optionName					The Socket configuration option name should be NET_SOCKET_SO_LINGER
		* @param[in]	optionValue					A LingerOption instance that holds the option setting
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INIT_FAILED				The socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is in an invalid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		* @see Osp::Net::Sockets::LingerOption
		*
		*/
		result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, const LingerOption& optionValue);

		/**
		* Enables the adding or dropping of a membership for the specified multicast group. @n
		* Multicast datagram packets are transmitted only to the multicast group members. @n
		* A socket must join a multicast group before the data is received. @n
		* Do not call NET_SOCKET_SO_IP_ADD_MEMBERSHIP with the same group more than once on the same network interface.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					Set to @c NET_SOCKET_IPPROTO_IP
		* @param[in]	optionName					Set to either @c NET_SOCKET_IP_ADD_MEMBERSHIP or @c NET_SOCKET_IP_DROP_MEMBERSHIP only
		* @param[in]	optionValue					The IpMulticastRequestOption class instance that contains the network interface and group address for multicasting
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_INIT_FAILED				The socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The socket is in an invalid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @see Osp::Net::Sockets::IpMulticastRequestOption
		*
		*/
		result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, const IpMulticastRequestOption& optionValue);

		/**
		* @internal
		* This is internal. If used in an application, the application can get rejected during the certification process.
		* The GetSocketFd method gets the socket descriptor
		*
		* @since 			1.0
		* @return			A socket fd
		* @remarks		Unauthorized use of this method does not guarantee normal operation. On failure, this method returns @c -1.
		*/
		int GetSocketFd();

	private:
		/**
		* Frees the resource allocated by this %Socket instance.
		*
		* @return		An error code
		* @exception	E_SUCCESS		The method is successful.
		* @exception	E_FAILURE		The method has failed.
		* @remarks 		The implementer of the derived class of Resource class must override this method and provide specific resource deallocation routine.
		*/
		result Dispose(void);

	// Lifecycle
	private:
		/**
		* Initializes this instance of Socket class with the specified parameters.
		*
		* @return		An error code
		* @param[in]	hSocket						A low-level handle representing a socket
		* @param[in]	socket						A Socket object
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_INVALID_STATE				The socket is not in a valid state.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_SOCKET			The socket is invalid.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @remarks 		This method is used for initializing a newly accepted socket using its listening %Socket object. @n
		*				The socket is created in the non-blocking mode by default,
		*				which means SetBlocking() should be used to use a %Socket object in the blocking mode.
		*/
		result Construct(int hSocket, const Socket& socket);

	// Operation
	private:
		/**
		* Registers the application for notification of socket events.
		*
		* @return		An error code
		* @exception	E_SUCCESS			The method is successful.
		* @remarks 		This method is not doing anything. The body of the method is empty,
		*				It is simply returning E_SUCCESS.
		*/
		result RegisterForEvents(void);

	// LifeCycle
	private:
		/**
		* This is the copy constructor for the Socket class.
		*
		* @param[in]	value		An instance of %Socket
		*/
		Socket(const Socket& value);


	// Operation
	private:
		/**
		* This is the assignment operator. 
		* Do @b not use directly.
		*
		* @param[in]	rhs			An instance of %Socket
		*/
		Socket& operator =(const Socket& rhs);

		// Attribute
	private:
		/**
		* For each %Socket used in the non-blocking mode, an event listener (ISocketEventListener) should be registered
		* and maintained, using which the asynchronous notifications of %Socket events can be received. @n
		* If you want to use a %Socket in the non-blocking mode, you should call Socket::AddSocketListener()
		* after initializing the socket through the Construct() method.
		*/
		HSocket __socketFd;

		bool __isConstructed;
		bool __isClosed;
		bool __isDisposed;
		bool __isMonitored;
		bool __isLoopback;

		/* for creation sockets */
		NetSocketAddressFamily __protocolFamily;
		NetSocketType __socketType;
		NetSocketProtocol __protocol;

		Osp::Net::_DefaultNetConnection* __pDefaultNetConnection;

		__SocketEvent* __pSocketEvent;//
		NetEndPoint* __pLocal;
		NetEndPoint* __pPeer;

		ISocketPi*	__pSocketInterface;

		// Friend class declaration
		friend class __SocketEvent; // RegisterForEvents()

	private:
		// for ABC
		class SocketEx* __pSocketEx;

		friend class SocketEx;
	};

};// Osp::Net::Sockets
};// Osp::Net
};// Osp
#endif // _FNET_SOCK_SOCKET_H_

