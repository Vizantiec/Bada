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
* @file			FNetSockSocketTypes.h 
* @brief		This is the header file for the enumerators of the %Socket namespace.
*
* This header file contains the enumerators for %Socket operations.
*/

#ifndef _FNET_SOCK_SOCKET_TYPES_H_
#define _FNET_SOCK_SOCKET_TYPES_H_

#include "FNetNetTypes.h"

namespace Osp { namespace Net { namespace Sockets {

	typedef Handle		HSocket;	/*< Socket handle */
	#define NET_SOCKET_INADDR_ANY	(Ip4Address)0
	#define NET_SOCKET_IP4ADDRESS_MAX	16

	/**
	* @enum 	NetSocketEventType
	* Defines the type of socket events.
	*
	* @since	1.0
	*/
	enum NetSocketEventType
	{
		NET_SOCKET_EVENT_NONE,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_EVENT_WRITE			= 0x01,		/**< The write event */
		NET_SOCKET_EVENT_READ			= 0x02,		/**< The read event */
		NET_SOCKET_EVENT_CLOSE			= 0x04,		/**< The close event */
		NET_SOCKET_EVENT_ACCEPT			= 0x08,		/**< The accept event */
		NET_SOCKET_EVENT_CONNECT		= 0x10,		/**< The connect event */
		NET_SOCKET_EVENT_SERVCERT_FAIL	= 0x20,		/**< The server's certificate failed event @n
														 Only for %SecureSocket. */
	};

	/**
	* @enum 	NetSocketAddressFamily
	* Defines an address family.
	*
	* @since	1.0
	*/
	enum NetSocketAddressFamily
	{
		NET_SOCKET_AF_NONE,							/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_AF_LOCAL,						/*< The local socket for loopback*/
		NET_SOCKET_AF_IPV4,							/**< An IP version 4 address family */
		//NET_SOCKET_AF_IPV6						/*< An IP version 6 address family */
	};

	/**
	* @enum 	NetSocketType
	* Defines a socket type.
	*
	* @since	1.0
	*/
	enum NetSocketType
	{
		NET_SOCKET_TYPE_NONE,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_TYPE_STREAM,						/**< The stream socket */
		NET_SOCKET_TYPE_DATAGRAM					/**< The datagram socket */
	};

	/**
	* @enum 	NetSocketProtocol
	* Defines a protocol type.
	*
	* @since	1.0
	*/
	enum NetSocketProtocol
	{
		NET_SOCKET_PROTOCOL_NONE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_PROTOCOL_TCP,					/**< The TCP protocol */
		NET_SOCKET_PROTOCOL_UDP,					/**< The UDP protocol */
		NET_SOCKET_PROTOCOL_SSL						/**< The SSL protocol */
	};

	/**
	* @enum	 	NetSocketIoctlCmd
	* Defines the commands that control the socket I/O.
	*
	* @since	1.0
	*/
	enum NetSocketIoctlCmd
	{
		NET_SOCKET_IOCTLCMD_NONE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_FIONBIO,							/**< The command to set the non-blocking/blocking mode on a socket */
		NET_SOCKET_FIONREAD,						/**< The command to determine the amount of data pending in the network input buffer */
		NET_SOCKET_FIONWRITE,						/**< The functionality is not supported in this SDK */
		NET_SOCKET_SIOCATMARK						/**< The command to determine whether all out-of-band data is read */
	};

	/**
	* @enum 	NetSocketOptLevel
	* Defines the socket option levels. @n
	* The level decides the context of the option.
	*
	* @since	1.0
	*/
	enum NetSocketOptLevel
	{
		NET_SOCKET_OPTLEVEL_NONE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_IPPROTO_TCP,						/**< The socket options apply only to the TCP sockets */
		NET_SOCKET_IPPROTO_IP,						/**< The socket options apply only to the IP sockets */
		NET_SOCKET_SOL_SOCKET						/**< The socket options apply to all the sockets */
	};

	/**
	* @enum 	NetSocketOptName
	* Defines the socket configuration option names.
	*
	* @since	1.0
	*/
	enum NetSocketOptName
	{
		NET_SOCKET_OPTNAME_NONE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_TCP_NODELAY,						/**< The option name is Level: NET_SOCKET_IPPROTO_TCP - Set/Get is possible */
		NET_SOCKET_TCP_MAXSEG,						/**< The option name is Level: NET_SOCKET_IPPROTO_TCP - Set/Get is possible */
		NET_SOCKET_IP_TTL,							/**< The option name is Level: NET_SOCKET_IPPROTO_IP - Set/Get is possible */
		NET_SOCKET_IP_TOS,							/**< The option name is Level: NET_SOCKET_IPPROTO_IP - Set/Get is possible */
		NET_SOCKET_IP_ADD_MEMBERSHIP,				/**< The option name is Level: NET_SOCKET_IPPROTO_IP - Only Set is possible */
		NET_SOCKET_IP_DROP_MEMBERSHIP,				/**< The option name is Level: NET_SOCKET_IPPROTO_IP - Only Set is possible */
		NET_SOCKET_SO_ACCEPTCONN,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible */
		NET_SOCKET_SO_BROADCAST,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_DEBUG,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported) */
		NET_SOCKET_SO_DONTROUTE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported) */
		NET_SOCKET_SO_ERROR,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible (Currently, not supported) */
		NET_SOCKET_SO_KEEPALIVE,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_LINGER,						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_OOBINLINE,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_RCVBUF,						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_RCVLOWAT,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported) */
		NET_SOCKET_SO_RCVTIMEO,						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_REUSEADDR ,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_SNDBUF,						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_SNDLOWAT,						/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value. The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible (Currently, not supported) */
		NET_SOCKET_SO_SNDTIMEO,						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_TYPE,							/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible */

		//Secure Socket only
		NET_SOCKET_SO_SSLVERSION ,					/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		//NET_SOCKET_SO_SSLSESSIONLIFETIME ,		/*< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible (currently not supported) */
		//NET_SOCKET_SO_SSLCONNECTIONWAITTIME,		/*< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible (currently not supported) */
		//NET_SOCKET_SO_SSLCONNECTIONSTATE,			/*< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible (currently not supported) */
		//NET_SOCKET_SO_SSLCIPHERSUITENAME,			/*< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Get is possible (currently not supported) */
		NET_SOCKET_SO_SSLCIPHERSUITEID,				/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Set/Get is possible */
		NET_SOCKET_SO_SSLCERTVERIFY,				/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible */
		NET_SOCKET_SO_SSLCERTID						/**< The option name is Level: NET_SOCKET_SOL_SOCKET - Only Set is possible @b since: @b 2.0 */
	};

	/**
	* @enum 	NetSocketClosedReason
	* Defines a socket closed reason.
	*
	* @since	1.0
	*/
	enum NetSocketClosedReason
	{
		NET_SOCKET_CLOSED_REASON_NONE,					/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum value.*/
		NET_SOCKET_CLOSED_REASON_NORMAL,				/**< A normal closed status by peer */
		NET_SOCKET_CLOSED_REASON_TIMEOUT,				/**< The connection attempt failed due to timeout */
		NET_SOCKET_CLOSED_REASON_NETWORK_UNAVAILABLE,	/**< The network is unavailable */
		NET_SOCKET_CLOSED_REASON_SYSTEM,				/**< An internal error occurred */
		NET_SOCKET_CLOSED_REASON_NO_CERTIFICATE,		/**< The reason is there is no client's SSL certificate @b since: @b 2.0 */
		NET_SOCKET_CLOSED_REASON_BY_USER				/**< The connection closed by user @b since: @b 2.0 */
	};

};// Osp::Net::Sockets
};// Osp::Net
};// Osp
#endif //_FNET_SOCK_SOCKET_TYPES_H_

