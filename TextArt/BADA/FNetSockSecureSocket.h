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
* @file		FNetSockSecureSocket.h
* @brief	This is the header file for the %SecureSocket class.
*
* This header file contains the declarations of the %SecureSocket class. @n
* The %SecureSocket class provides secured simple methods for sending and receiving data over a network.
*/

#ifndef _FNET_SOCK_SECURESOCKEVENT_EVENT_H_
#define _FNET_SOCK_SECURESOCKEVENT_EVENT_H_

#include "FBaseObject.h"
#include "FBaseResource.h"
#include "FNetNetEndPoint.h"
#include "FNetIP4Address.h"
#include "FNetNetConnection.h"
#include "FNetSockSocketTypes.h"
#include "FNetSockISecureSocketEventListener.h"

namespace Osp { namespace Net {
	class _DefaultNetConnection;
}};

namespace Osp { namespace Net { namespace Sockets {

	/**
	* @enum 	NetSecureSocketSslVersion
	* Defines the version of the secure socket.
	*
	* @since 	1.0
	*/
	enum NetSecureSocketSslVersion
	{
		NET_SOCK_SSL_VERSION_NONE = 0x0000,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. SSL version not set*/
		NET_SOCK_SSL_VERSION_SSLV3 = 0x0300,					/**< The secure socket version is SSLv3 @n
		                                                             The value for SSLv3 is 0x0300. */
		NET_SOCK_SSL_VERSION_TLSV1 = 0x0301						/**< The secure socket version is TLSv1 @n
		                                                             The value for TLSv1 is 0x0301. */
	};

	/**
	* @enum 	NetSecureSocketSslCipherSuiteID
	* Defines the CipherSuite ID.
	*
	* @since 	1.0
	*/
	enum NetSecureSocketSslCipherSuiteID{
		NET_SOCK_TLS_SSL_NULL_WITH_NULL_NULL	=				0x0000,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The CipherSuite ID is 0x0000 */
		//NET_SOCK_TLS_SSL_RSA_WITH_NULL_MD5 =         		    0x0001,		/*< The CipherSuite ID is 0x0001 */
		//NET_SOCK_TLS_SSL_RSA_WITH_NULL_SHA =         		    0x0002,		/*< The CipherSuite ID is 0x0002 */
		//NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_RC4_40_MD5 =     	0x0003,		/**< The CipherSuite ID is 0x0003 */
		NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_MD5 =	   		 		0x0004,		/**< The CipherSuite ID is 0x0004 */
		NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_SHA =             	0x0005,		/**< The CipherSuite ID is 0x0005 */
		//NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5 =     0x0006,		/*< The CipherSuite ID is 0x0006 */
		//NET_SOCK_TLS_SSL_RSA_WITH_IDEA_CBC_SHA =            	0x0007,		/*< The CipherSuite ID is 0x0007 */
		NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_DES40_CBC_SHA =   		0x0008,		/**< The CipherSuite ID is 0x0008 */
		NET_SOCK_TLS_SSL_RSA_WITH_DES_CBC_SHA =             	0x0009,		/**< The CipherSuite ID is 0x0009 */
		NET_SOCK_TLS_SSL_RSA_WITH_3DES_EDE_CBC_SHA =         	0x000A,		/**< The CipherSuite ID is 0x000A */
		//NET_SOCK_TLS_SSL_DH_DSS_WITH_3DES_EDE_CBC_SHA =     	0x000D,		/*< The CipherSuite ID is 0x000D */
		//NET_SOCK_TLS_SSL_DH_RSA_WITH_3DES_EDE_CBC_SHA =     	0x0010,		/*< The CipherSuite ID is 0x0010 */
		//NET_SOCK_TLS_SSL_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA = 	0x0011,		/*< The CipherSuite ID is 0x0001 */
		//NET_SOCK_TLS_SSL_DHE_DSS_WITH_DES_CBC_SHA =          	0x0012,		/*< The CipherSuite ID is 0x0002 */
		//NET_SOCK_TLS_SSL_DHE_DSS_WITH_3DES_EDE_CBC_SHA =     	0x0013,		/*< The CipherSuite ID is 0x0003 */
		//NET_SOCK_TLS_SSL_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA = 	0x0014,		/*< The CipherSuite ID is 0x0004 */
		//NET_SOCK_TLS_SSL_DHE_RSA_WITH_DES_CBC_SHA =          	0x0015,		/*< The CipherSuite ID is 0x0005 */
		//NET_SOCK_TLS_SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA =     	0x0016,		/*< The CipherSuite ID is 0x0006 */
		//NET_SOCK_TLS_SSL_DH_anon_EXPORT_WITH_RC4_40_MD5 =    	0x0017,		/*< The CipherSuite ID is 0x0007 */
		//NET_SOCK_TLS_SSL_DH_anon_WITH_RC4_128_MD5 =          	0x0018,		/*< The CipherSuite ID is 0x0008 */
		//NET_SOCK_TLS_SSL_DH_anon_EXPORT_WITH_DES40_CBC_SHA = 	0x0019,		/*< The CipherSuite ID is 0x0009 */
		//NET_SOCK_TLS_SSL_DH_anon_WITH_DES_CBC_SHA =          	0x001A,		/*< The CipherSuite ID is 0x001A */
		//NET_SOCK_TLS_SSL_DH_anon_WITH_3DES_EDE_CBC_SHA =     	0x001B,		/*< The CipherSuite ID is 0x001B */
		NET_SOCK_TLS_SSL_RSA_WITH_AES_128_CBC_SHA =          	0x002F,		/**< The CipherSuite ID is 0x002F */
		//NET_SOCK_TLS_SSL_DH_DSS_WITH_AES_128_CBC_SHA =       	0x0030,		/*< The CipherSuite ID is 0x0030 */
		//NET_SOCK_TLS_SSL_DH_RSA_WITH_AES_128_CBC_SHA =       	0x0031,		/*< The CipherSuite ID is 0x0031 */
		//NET_SOCK_TLS_SSL_DHE_DSS_WITH_AES_128_CBC_SHA =      	0x0032,		/*< The CipherSuite ID is 0x0032 */
		//NET_SOCK_TLS_SSL_DHE_RSA_WITH_AES_128_CBC_SHA =      	0x0033,		/*< The CipherSuite ID is 0x0033 */
		//NET_SOCK_TLS_SSL_DH_anon_WITH_AES_128_CBC_SHA =      	0x0034,		/*< The CipherSuite ID is 0x0034 */
		//NET_SOCK_TLS_SSL_RSA_WITH_AES_256_CBC_SHA =          	0x0035,		/*< The CipherSuite ID is 0x0035 */
		//NET_SOCK_TLS_SSL_DH_DSS_WITH_AES_256_CBC_SHA =       	0x0036,		/*< The CipherSuite ID is 0x0036 */
		//NET_SOCK_TLS_SSL_DH_RSA_WITH_AES_256_CBC_SHA =       	0x0037,		/*< The CipherSuite ID is 0x0037 */
		//NET_SOCK_TLS_SSL_DHE_DSS_WITH_AES_256_CBC_SHA =      	0x0038,		/*< The CipherSuite ID is 0x0038 */
		//NET_SOCK_TLS_SSL_DHE_RSA_WITH_AES_256_CBC_SHA =      	0x0039,		/*< The CipherSuite ID is 0x0039 */
		//NET_SOCK_TLS_SSL_DH_anon_WITH_AES_256_CBC_SHA =      	0x003A,		/*< The CipherSuite ID is 0x003A */

		/* Samsung does not support below cipher suites */
		/*
		TLS_SSL_ECDH_ECDSA_WITH_NULL_SHA_DRAFT09 =  			0x0047,
		TLS_SSL_ECDH_ECDSA_NULL_SHA =               			0x0047,
		TLS_SSL_ECDH_ECDSA_WITH_RC4_128_SHA_DRAFT09 = 			0x0048,
		TLS_SSL_ECDH_ECDSA_WITH_DES_CBC_SHA_DRAFT09 = 			0x0049,
		TLS_SSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA_DRAFT09 =  	0x004A,
		TLS_SSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA_DRAFT09 =   	0x004B,
		TLS_SSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA_DRAFT09 =   	0x004C,
		TLS_SSL_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA =   		0x0063,
		TLS_SSL_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA =   			0x0065,
		TLS_SSL_DHE_DSS_WITH_RC4_128_SHA =          			0x0066,
		TLS_SSL_PSK_WITH_RC4_128_SHA =              			0x008A,
		TLS_SSL_PSK_WITH_3DES_EDE_CBC_SHA =         			0x008B,
		TLS_SSL_PSK_WITH_AES_128_CBC_SHA =          			0x008C,
		TLS_SSL_PSK_WITH_AES_256_CBC_SHA =          			0x008D,
		TLS_SSL_DHE_PSK_WITH_RC4_128_SHA =          			0x008E,
		TLS_SSL_DHE_PSK_WITH_3DES_EDE_CBC_SHA =     			0x008F,
		TLS_SSL_DHE_PSK_WITH_AES_128_CBC_SHA =      			0x0090,
		TLS_SSL_DHE_PSK_WITH_AES_256_CBC_SHA =      			0x0091,
		TLS_SSL_RSA_PSK_WITH_RC4_128_SHA =          			0x0092,
		TLS_SSL_RSA_PSK_WITH_3DES_EDE_CBC_SHA =     			0x0093,
		TLS_SSL_RSA_PSK_WITH_AES_128_CBC_SHA = 					0x0094,
		TLS_SSL_RSA_PSK_WITH_AES_256_CBC_SHA = 					0x0095,
		TLS_SSL_ECDH_ECDSA_WITH_NULL_SHA =          			0xC001,
		TLS_SSL_ECDH_ECDSA_WITH_RC4_128_SHA =       			0xC002,
		TLS_SSL_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA =  			0xC003,
		TLS_SSL_ECDH_ECDSA_WITH_AES_128_CBC_SHA =   			0xC004,
		TLS_SSL_ECDH_ECDSA_WITH_AES_256_CBC_SHA =   			0xC005,
		TLS_SSL_ECDHE_ECDSA_WITH_NULL_SHA          = 			0xC006,
		TLS_SSL_ECDHE_ECDSA_WITH_RC4_128_SHA       = 			0xC007,
		TLS_SSL_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA  = 			0xC008,
		TLS_SSL_ECDHE_ECDSA_WITH_AES_128_CBC_SHA   = 			0xC009,
		TLS_SSL_ECDHE_ECDSA_WITH_AES_256_CBC_SHA   = 			0xC00A,
		TLS_SSL_ECDH_anon_WITH_NULL_SHA            = 			0xC015,
		TLS_SSL_ECDH_anon_WITH_RC4_128_SHA         = 			0xC016,
		TLS_SSL_ECDH_anon_WITH_3DES_EDE_CBC_SHA    = 			0xC017,
		TLS_SSL_ECDH_anon_WITH_AES_128_CBC_SHA     = 			0xC018,
		TLS_SSL_ECDH_anon_WITH_AES_256_CBC_SHA     = 			0xC019,
		TLS_SSL_ECMQV_ECDSA_WITH_NULL_SHA             = 		0xFF4F,
		TLS_SSL_ECMQV_ECDSA_WITH_RC4_128_SHA          = 		0xFF50,
		TLS_SSL_ECMQV_ECDSA_WITH_3DES_EDE_CBC_SHA     = 		0xFF52,
		TLS_SSL_ECMQV_ECDSA_WITH_AES_128_CBC_SHA      = 		0xFF53,
		TLS_SSL_ECMQV_ECDSA_WITH_AES_256_CBC_SHA      = 		0xFF54,
		*/

		NET_SOCK_TLS_SSL_SYSTEM_DEFAULT_CIPHERSUITES =			0xFFFF		/** If the user selects this ID, the %SecureSocket instance decides the cipher suite bundle itself @n
																			 *	For the OAF SSL, the below cipher suites will be included in "ClientHello" message @n
																			 *	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_MD5
																			 *	NET_SOCK_TLS_SSL_RSA_WITH_RC4_128_SHA
																			 *	NET_SOCK_TLS_SSL_RSA_EXPORT_WITH_DES40_CBC_SHA
																			 *	NET_SOCK_TLS_SSL_RSA_WITH_DES_CBC_SHA
																			 *	NET_SOCK_TLS_SSL_RSA_WITH_3DES_EDE_CBC_SHA
																			 *	NET_SOCK_TLS_SSL_RSA_WITH_AES_128_CBC_SHA
																			 */
	};

	// Forwarding class declaration.
	class __SecureSocketEvent;
	class ISecureSocketEventListener;
	class ISecureSocketPi;
	class SecureSocketEx;

	/**
	* @class	SecureSocket
	* @brief	This class provides the Secure Sockets Layer (SSL) supported socket with security features.
	* @since	1.0
	*
   * The %SecureSocket class provides the Secure Sockets Layer (SSL) supported socket with security features.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*/
	class _EXPORT_NET_ SecureSocket :
		public Osp::Base::Object,
		public Osp::Base::__Resource
	{
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since 	1.0
		* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
		* @see 		Construct()
		*/
		SecureSocket(void);

		/**
		* This is the destructor for this class.
		*
		* @since 	1.0
		* @see 		Close()
		*/
		virtual ~SecureSocket(void);

		/**
		* Initializes this instance of the %SecureSocket class. @n
		* By default, the %SecureSocket class is initialized in the non-blocking mode and it only works in the non-blocking mode.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	netConnection			A run-time session where a %SecureSocket object is used
		* @param[in]	addressFamily			A ::NetSocketAddressFamily value
		* @param[in]	socketType				The type of secure socket @n
		*										The value should be NET_SOCKET_TYPE_STREAM.
		* @param[in]	protocol				The protocol used by this secure socket @n
		*										The value should be NET_SOCKET_PROTOCOL_SSL.
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_MAX_EXCEEDED			All sockets are in use.
		* @exception	E_INVALID_STATE			The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
		* @exception	E_INVALID_ARG			A specified input parameter is invalid.
		* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
		* @exception	E_UNSUPPORTED_TYPE		The secure socket type is not supported.
		* @exception	E_UNSUPPORTED_FAMILY	The address family is not supported.
		* @exception	E_SYSTEM				A system error has occurred.
		* @exception	E_INVALID_CONNECTION	The network connection is invalid.
		* @exception	E_FAILURE				The method has failed due to an undefined error.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		*
		* @remarks 		The @c netConnection parameter specifies a run-time network connection. @n
		*				The @c addressFamily parameter specifies an address family. @n
		*				The @c socketType parameter specifies the type of the secure socket. SSL only supports stream-based protocols. @n
		*				The @c protocol parameter specifies the protocol used by the secure socket. SSL protocol is defined as NET_SOCKET_PROTOCOL_SSL. @n
		*				The first parameter must be a valid run-time network connection. The three parameters are not independent. Some address families 
		*				restrict the protocols that can be used with them, and often the secure socket type is implicit in the protocol. If the combination 
		*				of the address family, socket type, and protocol type results in an invalid secure socket, this method returns an error. For each 
		*				secure socket used in the non-blocking mode, an event listener (ISecureSocketEventListener) should be registered and maintained. 
		*				Using this listener, asynchronous notifications of secure socket events can be received. AddSecureSocketListener() is used to 
		*				register an event listener.
		*
		*/
		result Construct(const Osp::Net::NetConnection& netConnection, NetSocketAddressFamily addressFamily,
			NetSocketType socketType, NetSocketProtocol protocol);

		/**
		* Initializes this instance of %SecureSocket. @n
		* By default, the %SecureSocket class is initialized in the non-blocking mode and it only works in the non-blocking mode.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @param[in]	addressFamily			A ::NetSocketAddressFamily value
		* @param[in]	socketType				The type of secure socket @n
		*										The value should be NET_SOCKET_TYPE_STREAM.
		* @param[in]	protocol				The protocol used by this secure socket @n
		*										The value should be NET_SOCKET_PROTOCOL_SSL.
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_MAX_EXCEEDED			All sockets are in use.
		* @exception	E_INVALID_STATE			The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
		* @exception	E_INVALID_ARG			A specified input parameter is invalid.
		* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
		* @exception	E_UNSUPPORTED_TYPE		The secure socket type is not supported.
		* @exception	E_UNSUPPORTED_FAMILY	The address family is not supported.
		* @exception	E_SYSTEM				A system error has occurred.
		* @exception	E_INVALID_CONNECTION	The network connection is invalid.
		* @exception	E_FAILURE				The method has failed due to an undefined error.
		* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
		*
		* @remarks		The @c addressFamily parameter specifies an address family. @n
		* 				The @c socketType parameter specifies the type of the secure socket. SSL only supports stream-based protocols. @n
		* 				The @c protocol parameter specifies the protocol used by the secure socket. The SSL protocol is defined as NET_SOCKET_PROTOCOL_SSL. @n
		* 				The three parameters are not independent. Some address families restrict the protocols that can be used with them, and often the 
		*				secure socket type is implicit in the protocol. If the combination of the address family, socket type, and protocol type results in
		* 				an invalid secure socket, this method returns an error. For each secure socket used in the non-blocking mode, an event listener 
		*				(ISecureSocketEventListener) should be registered and maintained. Using this listener, asynchronous notifications of secure socket 
		*				events can be received. AddSecureSocketListener() is used to register an event listener.
		*/

		result Construct(NetSocketAddressFamily addressFamily, NetSocketType socketType, NetSocketProtocol protocol);

		/*
		* Binds the secure socket to a local address.
		*
		* @return		An error code
		* @param[in]	localEndPoint						The local NetEndPoint to associate with the secure socket
		* @exception	E_SUCCESS							The method is successful.
		* @exception	E_INVALID_SOCKET					The secure socket is invalid.
		* @exception	E_INVALID_STATE						The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION				The specified parameters are not supported.
		* @exception	E_INVALID_ARG						The specified input parameter is invalid.
		* @exception	E_ALREADY_BOUND						The address is already in use.
		* @exception	E_SYSTEM							A system error has occurred.
		* @remarks		Use the Bind() method to use a specific local endpoint. @n
		*				For connection-oriented sockets, do not call Bind() before using the Connect() method unless a specific local endpoint needs to be 
		*				used. Call Bind() before the Listen() method.
		*/
		//result Bind(const Osp::Net::NetEndPoint& localEndPoint);

		/**
		*
		* Establishes a connection to a remote host.
		*
		* @since 			1.0
		* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
		*                	For more information, see @ref SecureSocketConnectPage "here".
		*
		* @privlevel		NORMAL
		* @privgroup		SOCKET
		*
		* @return			An error code
		* @param[in]		remoteEndPoint				A NetEndPoint representing the remote device
		* @exception		E_SUCCESS					The method is successful.
		* @exception		E_INVALID_SOCKET			The secure socket is invalid.
		* @exception		E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception		E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
		* @exception		E_IN_PROGRESS				A previous request is in progress.
		* @exception		E_INVALID_ARG				The specified input parameter is invalid.
		* @exception		E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
		* @exception		E_CONNECTION_FAILED			The secure socket is not connected.
		* @exception		E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception		E_ALREADY_CONNECTED			The secure socket is already connected.
		* @exception		E_UNSUPPORTED_FAMILY		The address family is not supported.
		* @exception		E_UNSUPPORTED_PROTOCOL		The protocol is not supported.
		* @exception    	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception		E_SYSTEM					A system error has occurred.
		* @exception    	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		Starts connection to a remote peer including SSL handshaking.
		*				After the Connect()method is called, OnSecureSocketConnected() is called. The data is sent to the remote device
		*				using the Send() method, or the data is received using the Receive() method. If the Bind()method is not called before calling the 
		*				Connect() method, the underlying service provider assigns the local network address and port number.
		*/
		result Connect(const Osp::Net::NetEndPoint& remoteEndPoint);

        /**
        * @page			SecureSocketConnectPage	Compatibility for Connect()
        *
        * @section		SecureSocketConnectPageIssueSection	Issues
        * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
        * -# If the application provides an invalid NetEndPoint, the application terminates abnormally.
        *
        * @section		SecureSocketConnectPageResolutionSection Resolutions
        *  The issue mentioned above is resolved in bada API version 1.2 as follows: @n
        *  -# If the application provides an invalid NetEndPoint, it returns E_INVALID_ARG instead of being terminated abnormally. @n
        */

		/**
		*
		* Sends the data to a secure socket of the NET_SOCKET_TYPE_STREAM type.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	buffer						The ByteBuffer containing the data to be sent
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				The specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_CONNECTION_FAILED			The secure socket is not connected.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The Send() method sends the data to the remote host specified in the Connect() method.
		* 				The Send() method sends the data in the @c buffer parameter, starting from the current position of the buffer. After the operation, 
		*				the position of the buffer is incremented by the number of bytes successfully sent. The new position cannot be larger than the 
		*				original limit. If space is not available in the send queue, the secure socket returns the E_WOULD_BLOCK error. The Send() method may 
		*				complete successfully even if it sends less bytes than the number of bytes present in the buffer. It is the application's 
		*				responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the 
		*				buffer. There is also no guarantee that the data that is sent appears on the network immediately. To increase network efficiency, the 
		*				underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the 
		*				Send() method means that the underlying system has had room to buffer the data for a network send. If it is important for the 
		*				application to send every byte to the remote host immediately, use Setsockopt() (with NET_SOCKET_TCP_NODELAY) of type 
		*				::NetSocketOptName to enable no delay.
		*/
		result Send(Osp::Base::ByteBuffer& buffer);


		/**
		*
		* Sends the data to a secure socket of the NET_SOCKET_TYPE_STREAM type.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	pBuffer					The pointer to the buffer containing the data to be sent
		* @param[in]	length					The length of the data in the buffer
		* @param[out]	sentLength				The length of the data sent successfully
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_SOCKET		The secure socket is invalid.
		* @exception	E_INVALID_STATE			The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION	The specified parameters are not supported.
		* @exception	E_INVALID_ARG			A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK			A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_CONNECTION_FAILED		The secure socket is not connected.
		* @exception	E_TIMEOUT				An attempt to connect to the server has timed out.
		* @exception    E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_SYSTEM				A system error has occurred.
		*
		* @remarks		The Send() method sends the data to the remote host specified in the Connect() method.
		* 				The Send() method sends the data in the buffer of length @c length, starting from the current position of the buffer.
		* 				If space is not available in the send queue, the secure socket returns the E_WOULD_BLOCK error.
		* 				The Send() method may complete successfully even if it sends less bytes than the number of bytes
		* 				in the buffer. It is the application's responsibility to keep track of the number of bytes sent
		* 				and to retry the operation until the application sends the bytes in the buffer.
		* 				There is also no guarantee that the data that is sent appears on the network immediately.
		* 				To increase the network efficiency, the underlying system may delay the transmission until a significant amount
		* 				of outgoing data is collected. A successful completion of the Send() method means that the underlying
		* 				system has had room to buffer the data for a network send.
		*				If it is important to your application to send every byte to the remote host immediately,
		*				can use SetSockOpt() (with NET_SOCKET_TCP_NODELAY) of type ::NetSocketOptName to enable no delay.
		*/
		result Send(void* pBuffer, int length, int& sentLength);

		/**
		*
		* Receives the data from a secure socket of the NET_SOCKET_TYPE_STREAM type.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	buffer						The ByteBuffer that is the storage location for the received data
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				The specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		This method copies the data into the @c buffer parameter, starting from the current position of the buffer.
		* 				After the operation, the position of the buffer is incremented by the number of bytes successfully received.
		* 				The new position cannot be larger than the original limit. The Receive() method can be called from connection-oriented sockets only.
		* 				If no data is available at the secure socket, E_WOULD_BLOCK is returned.
		*
		*/
		result Receive(Osp::Base::ByteBuffer& buffer) const;


		/**
		*
		* Receives the data from a secure socket of the NET_SOCKET_TYPE_STREAM type.
		*
		* @since 		1.0
		* @return		An error code
		* @param[out]	pBuffer						The pointer to the buffer that is the storage location for the received data
		* @param[in]	length						The length of the data in buffer
		* @param[out]	rcvdLength					The length of the data that is received successfully
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_WOULD_BLOCK				A non-blocking secure socket operation cannot be completed immediately.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		This method copies the data into the buffer of length @c length, starting from the current position of the buffer.
		*				The Receive() method can be called from the connection-oriented sockets only. 
		*				If no data is available at the secure socket, the error E_WOULD_BLOCK is returned.
		*/
		result Receive(void* pBuffer, int length, int& rcvdLength) const;

		/**
		*
		* Closes the secure socket. @n
		* All the resources associated with the secure socket are freed.
		*
		* @since 		1.0
		* @privlevel	NORMAL
		* @privgroup	SOCKET
		*
		* @return		An error code
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception    E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception	E_SYSTEM					A system error has occurred.
		* @exception    E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		If the secure socket is not initialized through one of the Construct() methods or this method is called more than once,
		*				then this method returns the exception E_INVALID_STATE.
		*/
		result Close(void);

		/**
		* Gets an option of the secure socket.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					A ::NetSocketOptLevel value
		* @param[in]	optionName					A ::NetSocketOptName value
		* @param[out]	optionValue					The integer to receive the option setting
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_INIT_FAILED				The secure socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The secure socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		* @remarks		The secure socket options determine the behavior of the current secure socket. 
		*				Upon the successful completion of this method, the integer variable specified 
		*				by the @c optVal parameter contains the value of the specified secure socket option.
		*				For an option with a bool data type, a nonzero value is returned if the option is enabled. Otherwise,
		*				a zero value is returned. For an option with an integer data type, the method returns the appropriate value.
		*				The secure socket options are grouped by the level of protocol support.
		*				Listed below are the various secure socket options that can be obtained using this overload. These options are
		*				grouped by the appropriate NetSocketOptLevel. 
		*				If any of these options are to be obtained, use the appropriate NetSocketOptLevel for the @c optionLevel parameter. The option that 
		*				is chosen, must be specified in the @c optionName parameter. To set the current value of some of the listed options, use the 
		*				SetSockOpt() method. 
		*				@par
		*				The NET_SOCKET_SOL_SOCKET options that can be set using this overloaded method are: @n
		*				&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLVERSION: Gets the SSL version of the secure socket. @n
		*				&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCIPHERSUITEID: Gets the SSL cipher suite ID of the secure socket.
		* @see 			SetSockOpt()
		*/
		result GetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int& optionValue) const;

		/**
		* Changes an option of the secure socket.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	optionLevel					A ::NetSocketOptLevel value
		* @param[in]	optionName					A ::NetSocketOptName value
		* @param[in]	optionValue					The option value
		* @exception	E_SUCCESS					The method is successful.
		* @exception	E_INVALID_SOCKET			The secure socket is invalid.
		* @exception	E_INIT_FAILED				The secure socket is not initialized.
		* @exception	E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception	E_INVALID_ARG				A specified input parameter is invalid.
		* @exception	E_INVALID_STATE				The secure socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception	E_IN_PROGRESS				A previous request is in progress.
		* @exception	E_CONNECTION_FAILED			The secure socket is not connected.
		* @exception	E_SYSTEM					A system error has occurred.
		*
		* @remarks		The SetSockOpt() method is used to change the value of the option specified by the @c optionName parameter.
		*				The secure socket options determine the behavior of the current secure socket. For an option with a bool data type,
		*				specify a nonzero value to enable the option, and a zero value to disable the option. 
		*				For an option with an integer data type, specify the appropriate value. The secure socket options are grouped
		*				by the level of protocol support.
		*				Listed below are the various secure socket options that can be set using this overload. These options are
		*				grouped by the appropriate NetSocketOptLevel.  If any of these options are to be set, use the appropriate NetSocketOptLevel for the
		*				@c optionLevel parameter. The chosen option must be specified in the @c optionName parameter.
		*				To get the current value of some of the options listed, use the GetSockOpt() method. 
		*				@par
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLVERSION: To enable the SSL version of the secure socket. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCIPHERSUITEID: To set the SSL cipher suite ID of the secure socket. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCERTVERIFY: To enable SSL certificate verification on the secure socket. @n
		*					&nbsp;&nbsp;&nbsp;NET_SOCKET_SO_SSLCERTID: To set the SSL certificate ID for the client authentication. Start the Application control (APPCONTROL_PROVIDER_CERTIFICATE_MANAGER) for getting the selected client certificate. For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>. (Osp::App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER) @n
		*/
		result SetSockOpt(NetSocketOptLevel optionLevel, NetSocketOptName optionName, int optionValue);

		/*
		* Execute a command on the secure socket.
		*
		* @since 			1.0
		* @return			An error code
		* @param[in]	cmd		 							The command to perform on the secure socket descriptor
		* @param[out]	value								A value of parameter for @c cmd
		* @exception	E_SUCCESS							The method is successful.
		* @exception    E_INVALID_STATE						The secure socket is not in a valid state.
		* @exception	E_INVALID_ARG						A specified input parameter is invalid.
		* @exception	E_INVALID_SOCKET					Invalid secure socket.
		* @exception	E_UNSUPPORTED_OPTION				The specified parameters are not supported.
		* @exception	E_INVALID_ARG						A specified input parameter is invalid.
		* @exception	E_INVALID_STATE						The secure socket is not in a valid state.
		* @exception	E_NETWORK_UNAVAILABLE				Network is unavailable.
		* @exception	E_SYSTEM							An internal error occurred.
		* @remarks		The Ioctl() method manipulates the underlying device parameters of secure socket
		*			    descriptors. @par
		*				NET_SOCKET_FIONBIO option is used for setting the non-blocking/blocking mode
		*				on a secure socket.
		*				NET_SOCKET_FIONREAD option is used for getting the number of bytes that are
		*				immediately available for reading.
		*				NET_SOCKET_FIONWRITE option is used for getting the number of bytes which have not yet been
		*		        acknowledged by the other side of the connection.Currently secure sockets do not support this option.
		*				NET_SOCKET_SIOCATMARK option is used to determine if all out of band (OOB) data has been read.
		*				Currently secure sockets do not support this option.
		*
		*
		*/
		//result  Ioctl(NetSocketIoctlCmd cmd, int& value) const;

		/**
		* Adds a listener to the secure socket. @n
		* The listener can listen to the events when they are fired.
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	listener				A reference to ISecureSocketEventListener
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
		* @exception	E_INVALID_SOCKET		The secure socket is invalid.
		* @exception	E_INVALID_STATE			The associated secure socket is not in a valid state.
		* @exception	E_SYSTEM				A system error has occurred.
		*/
		result AddSecureSocketListener(const ISecureSocketEventListener&  listener);

		/**
		* Removes a listener from the secure socket.
		*
		* @since 		1.0
		* @return 		An error code
		* @param[in]	listener				A reference to ISecureSocketEventListener
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_OBJ_NOT_FOUND			The specified object is not found within the indicated range.
		* @exception	E_INVALID_SOCKET		The secure socket is invalid.
		* @exception	E_INVALID_STATE			The associated secure socket is not in a valid state.
		* @exception	E_SYSTEM				A system error has occurred.
		*/
		result RemoveSecureSocketListener(const ISecureSocketEventListener&  listener);

		/**
		* Sets a secure socket to the asynchronous mode by a specified message to the specified event handler when the secure socket events occur. @n
		* The following example demonstrates how to set a secure socket to the asynchronous mode.
		*
		*	@code
		*	result res = E_SUCCESS;
		*
		*	// Creates the secure socket.
		*	SecureSocket* pClientSocket = new SecureSocket();
		*	res = pClientSocket->Construct(NET_SOCKET_AF_IPV4,NET_SOCKET_TYPE_STREAM,NET_SOCKET_PROTOCOL_SSL);
		*
		*	// Adds listener.
		*	MySocketSecureClientListener* pSockClientListener = new MySocketSecureClientListener();
		*	res = pClientSocket->AddSecureSocketListener(*pSockClientListener);
		*
		*	// Selects asynchronous event (non-blocking mode).
		*	res= pClientSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT| NET_SOCKET_EVENT_CLOSE);
		*
		*	// Creates peer endpoint.
		*	Ip4Address peerAddr("XXX.XXX.XXX.XXX"); //secure socket server address.
		*	unsigned short peerPort = YYY;  // port
		*	NetEndPoint* pPeerEndPoint = new NetEndPoint(peerAddr, peerPort);
		*
		*	// Connects the secure socket.
		*	res = pClientSocket->Connect(*pPeerEndPoint);
		*	@endcode
		*
		* @since 		1.0
		* @return		An error code
		* @param[in]	socketEventType			The secure socket events of ::NetSocketEventType @n
		*										Multiple events can be combined using the bitwise "|" operator.
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_SOCKET		The secure socket is invalid.
		* @exception	E_INVALID_STATE			The secure socket is not in a valid state.
		* @exception	E_INVALID_ARG			The specified input parameter is invalid.
		* @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
		* @exception	E_TIMEOUT 				An attempt to connect to the server has timed out.
		*/
		result AsyncSelectByListener(unsigned long socketEventType);

		// Operation
	private:
		/**
		* Frees the resource allocated by this SecureSocket instance.
		*
		* @return		An error code
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FAILURE			The method has failed due to an undefined error.
		* @remarks		The implementer of the derived class of Resource class must override
		*				this method and provide specific resource deallocation routine.
		*/
		result Dispose(void);

		// Operation
	private:
		/**
		* Registers the application for notification of the secure socket events.
		*
		* @return		An error code
		* @exception	E_SUCCESS			The method is successful.
		* @remarks		This method does not do anything. The body of the method is empty.
		*				It is simply returning E_SUCCESS.
		*/
		result RegisterForEvents(void);

		// LifeCycle
	private:
		/**
		* This is the copy constructor for the SecureSocket class.
		*
		* @param[in]	value			An instance of %SecureSocket
		*/
		SecureSocket(const SecureSocket& value);


		// Operation
	private:
		/**
		* This is the assignment operator. @n
		* Do @b not use directly.
		*
		* @param[in]	rhs				An instance of %SecureSocket
		*/
		SecureSocket& operator =(const SecureSocket& rhs);

	private:
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
		__SecureSocketEvent* __pSocketEvent;
		ISecureSocketPi* __pSecureSocketInterface;

	private:
		// for ABC
		class SecureSocketEx* __pSecureSocketEx;

		friend class SecureSocketEx;
	};
}; // Osp::Net::Sockets
}; // Osp::Net
}; // Osp

#endif
