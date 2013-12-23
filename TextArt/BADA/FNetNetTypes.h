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
* @file			FNetNetTypes.h 
* @brief		This is the header file for defining the types for the %Net namespace.
*
* This header file contains the definition of the various types and enumerators for the NetConnection operations.
*/
#ifndef _FNET_NET_TYPES_H_
#define _FNET_NET_TYPES_H_

#include "FBase.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseErrorDefine.h"


namespace Osp { namespace Net {

#define NET_IPV4_ADDR_LEN_MAX				4			/* The IPv4 address length */
#define NET_IPV6_ADDR_LEN_MAX				16			/* The IPv6 address length */
#define NET_MSISDN_ADDR_LEN_MAX				21			/* The MSISDN length */
#define NET_SERVCODE_ADDR_LEN_MAX			21			/* The service code length */
#define NET_APN_ADDR_LEN_MAX				64			/* The APN length for PSD. Nokia OTA defines 100 as GPRS_ACCESSPOINTNAME. */
#define NET_DIAL_NUMBER_LEN_MAX				32			/* The maximum length of phone numbers for CSD. */

#define NET_AUTH_ID_LEN_MAX					44			/* The user ID length */
#define NET_AUTH_PASSWD_LEN_MAX				44			/* The password length */

#define NET_APP_NAME_LEN_MAX				32			/* The application name length */
#define NET_NETINFO_NAME_LEN_MAX 			40			/* The network information(Access Point set) length */
#define NET_HOME_URL_LEN_MAX				512			/* The home URL maximum length in an account */

#define NET_IPV4_STR_LEN_MAX				518			/* The length, not including @c null in the last bit.  For example, 165.213.173.105:65535. */
#define NET_DNS_COUNT_MAX 					2

#define NET_ACCOUNT_COUNT_MAX				20			/* The maximum count of NetAccount*/

/**
 * NetAccount ID
 *
 * @since 1.0
 */
typedef int		NetAccountId;
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Protocol Handle
 *
 * @since 1.0
 */
typedef	Handle	HProtocol;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Protocol Handle
 *
 * @since 1.0
 */
typedef unsigned long		IPV4Addr;
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Type of IPV6Addr
 *
 * @since 1.0
 */
typedef byte				IPV6Addr;
/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Type of APN
 *
 * @since 1.0
 */
typedef byte				APN;

/**
 * @enum	NetConnectionState
 * Defines the state of the network connection.
 *
 * @since	1.0
 */
enum NetConnectionState
{
	NET_CONNECTION_STATE_NONE,			/**< The initial state */
	NET_CONNECTION_STATE_STARTING,		/**< The network connection is being established */
	NET_CONNECTION_STATE_STARTED,		/**< The network connection has been established */
	NET_CONNECTION_STATE_STOPPING,		/**< The network connection is being disconnected */
	NET_CONNECTION_STATE_STOPPED,		/**< The network connection has been disconnected. */
	NET_CONNECTION_STATE_SUSPENDED,		/**< The network connection has been suspended */
	NET_CONNECTION_STATE_SUSPEND = 5,	/*< The network connection has been suspended */
	NET_CONNECTION_STATE_RESUMED,		/**< The network Connection is established, and recovered from SUSPEND state - enable to send/receive packet data */
	NET_CONNECTION_STATE_AVAILABLE,		/*< Not used */
	NET_CONNECTION_STATE_UNAVAILABLE,	/*< Not used */
};

/**
 * @enum 	NetConnectionStoppedReason
 * Defines the reason for stoppage of the network connection.
 *
 * @since 2.0 
 */
typedef enum 
{
	NET_CONNECTION_STOPPED_REASON_RESOURCE_RELEASED,	/**< The network connection managed by system stopped because the network resources have been released */
	NET_CONNECTION_STOPPED_REASON_NETWORK_FAILED,		/**< The network has failed */
	NET_CONNECTION_STOPPED_REASON_DEVICE_OFFLINE,		/**< The operation failed because the device is in offline mode */
	NET_CONNECTION_STOPPED_REASON_SERVICE_UNAVAILABLE,	/**< The device is out of the coverage area or in an emergency mode */
	NET_CONNECTION_STOPPED_REASON_RESOURCE_UNAVAILABLE,	/**< The network resource is unavailable */
	NET_CONNECTION_STOPPED_REASON_SYSTEM				/**< A system error has occurred */
} NetConnectionStoppedReason;

/**
 * @enum 	NetProtocolType
 * Defines the network protocol type.
 *
 * @since	1.0
 */
enum NetProtocolType {
	NET_PROTO_TYPE_NONE,			/*<  The undefined type*/
	NET_PROTO_TYPE_IPV4,			/**< The IPV4 type */
	NET_PROTO_TYPE_PPP,				/**< The PPP type */
	NET_PROTO_TYPE_IPV6,			/**< The IPV6 type, currently NOT supported */
};

/**
 * @enum 	NetAddressFamily
 * Defines the network address family.
 *
 * @since	1.0
 */
enum NetAddressFamily
{
	NET_AF_NONE,
	NET_AF_IPV4,			/**< The default. An IPv4 address [RFC791] is represented in decimal format with dots as delimiters */
	NET_AF_IPV6 ,			/**< An IPv6 address [RFC2373] is generally represented in hexadecimal numbers with colons as delimiters. It can also be a combination of hexadecimal and decimal numbers with dots and colons as delimiters*/
	//NET_AF_E164,			/*< A phone number according to the E164 scheme [GENFORM] */
	NET_AF_ALPHANUMERIC,	/**< A generic alphanumeric address (as defined by alphanum in [RFC2396]) */
	NET_AF_APN				/**< A GPRS APN as defined in [GENFORM] */
	//NET_AF_SCODE,			/*< A USSD service code as defined in [GENFORM] */
	//NET_AF_TETRA_ITSI,	/*< A TETRA SDS address with digits in decimal format [WAPWDP] */
	//NET_AF_MAN			/*< A Mobitex MAN address with digits in decimal format [WAPWDP] */
};

/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @enum 	NetStatisticsInfoType
 * Defines the various kinds of data call statistics information.
 *
 * @since	1.0
 */
enum NetStatisticsInfoType
{
	NET_STAT_NONE,
	NET_STAT_CALL_DURATION,			/**< The call duration */
									/**< @deprecated This field is deprecated because it is not supported by platform. */
	NET_STAT_SENT_SIZE,				/**< The size of the packet sent, since the time the network was last reactivated. */
	NET_STAT_RCVD_SIZE,				/**< The size of the packet received, since the time the network was last reactivated. */
	NET_STAT_LAST_CALL_DURATION,	/**< The call duration (Last)*/
									/**< @deprecated This field is deprecated because it is not supported by platform. */
	NET_STAT_LAST_SENT_SIZE,		/**< The sent size (Last)*/
									/**< @deprecated This field is deprecated because it is not supported by platform. */
	NET_STAT_LAST_RCVD_SIZE,		/**< The received size (Last)*/
									/**< @deprecated This field is deprecated because it is not supported by platform. */
	NET_STAT_TOTAL_CALL_DURATION,	/**< The call duration (Total)*/
									/**< @deprecated This field is deprecated because it is not supported by platform. */
	NET_STAT_TOTAL_SENT_SIZE,		/**< The cumulated size of the packet sent since the last reset */
	NET_STAT_TOTAL_RCVD_SIZE		/**< The cumulated size of the packet received since the last reset */
};

/**
 * @enum 	NetPreferenceType
 * Defines the preferred network.
 *
 * @since	1.0
 */
enum NetPreferenceType
{
	NET_WIFI_FIRST,					/**< The preference type to follow preferred mode (Wi-Fi first) @n
									*	This preference type works like NET_PS_ONLY on the Emulator */
	NET_PS_ONLY,					/**< The preference type to only operate services for the PS domain */
	NET_CS_ONLY,					/*<  Not supported; the preference type to only operate services for the CS domain */
	NET_WIFI_ONLY					/**< The preference type to only operate services for Wi-Fi */
};

/**
 * @enum 	NetBearerType
 * Defines the bearer type.
 *
 * @since	1.0	
 */
enum NetBearerType
{
	NET_BEARER_NONE,				/*< The bearer type is not defined */
	NET_BEARER_PS,					/**< The bearer type for the PS domain */
	NET_BEARER_CS,					/*<	 Not supported; the bearer type for the CS domain */
	NET_BEARER_WIFI,				/**< The bearer type for Wi-Fi */
	NET_BEARER_WIFI_DIRECT,			/**< The bearer type for Wi-Fi Direct @n 
									*	This bearer type cannot be tested on the Emulator  @b since: @b 2.0. */
	NET_BEARER_USB					/**< The bearer type for USB NDIS mode @n
									*	Can use this bearer type via USB Tethering mode. @n
									*	This bearer type cannot be tested on the Emulator  @b since: @b 2.0. */
};

/**
 * @enum 	NetAddressScheme
 * Defines the network IP or Domain Name System (DNS) scheme.
 *
 * @since	1.0
 */
enum NetAddressScheme
{
	NET_ADDRESS_SCHEME_NONE,
	NET_ADDRESS_SCHEME_DYNAMIC,		/**< The Dynamic IP or DNS Address */
	NET_ADDRESS_SCHEME_STATIC		/**< The Static IP or DNS Address */
};

/**
 * @enum 	NetNapAuthType
 * Defines the authentication type of the network.
 *
 * @since	1.0
 * @remarks  There is no relevant data.
 */
enum NetNapAuthType
{
	NET_NAPAUTH_NONE,
	NET_NAPAUTH_PAP,				/**< The PAP (Password Authentication Protocol) type */
	NET_NAPAUTH_CHAP				/**< The CHAP (Challenge/Handshake Authentication Protocol) type */		
};

}; }; // Osp::Net

#endif // _FNET_NET_TYPES_H_

