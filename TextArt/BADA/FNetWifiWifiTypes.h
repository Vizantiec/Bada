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
 * @file		FNetWifiWifiTypes.h
 * @brief		This is the header file for the enumerations in the %Wifi namespace.
 *
 * This header file contains the type declarations of the %Wifi namespace. 
 */
#ifndef FNET_WIFI_WIFITYPES_H
#define FNET_WIFI_WIFITYPES_H

#include "FBaseTypes.h"
#include "FBaseByteBuffer.h"

namespace Osp { namespace Net { namespace Wifi {

#define WIFI_MAX_KEY_LEN_NO_ENCRYPTION		32						/**< The maximum length of a security key value without encryption */
#define WIFI_MAX_KEY_LEN_WEP_64				10						/**< The maximum length of a security key value with Wired Equivalent Privacy (WEP) */
#define WIFI_MAX_KEY_LEN_WEP				26						/**< The maximum length of a security key value with Wired Equivalent Privacy (WEP) */
#define WIFI_MAX_KEY_LEN_AES				64						/**< The maximum length of a security key value with Advanced Encryption Standard (AES) */
#define WIFI_MAX_KEY_LEN_TKIP				WIFI_MAX_KEY_LEN_AES	/**< The maximum length of a security key value with Temporal Key Integrity Protocol (TKIP) */
#define WIFI_MAX_KEY_LEN_EAP				256						/**< The maximum length of the user and password values of Extensible Authentication Protocol method */
#define WIFI_DIRECT_MAX_DEVICE_ID			4						/**< The maximum number of device IDs */


/**
 * The encryption key data type
 *
 * @since 	1.0
 */
typedef char		KeyData;				
typedef int			WifiProfileId;			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/

/**
 * The Wi-Fi Direct Device ID
 *
 * @since 	2.0
 */
typedef int			WifiDirectDeviceId;

//////////////////////////////////////////////////////////////////////////////////
// const
//////////////////////////////////////////////////////////////////////////////////
/** The maximum number of associated clients
*
* @since			2.0
*/
static const int WIFI_DIRECT_MAX_CONNECTED_CLIENTS = 8;

/** The maximum number of group owners intent for negotiation
*
* @since			2.0
*/
static const int WIFI_DIRECT_MAX_GROUP_OWNER_INTENT	= 15;


/**
 * @enum		WifiPowerStatus
 * Defines the power status of the local Wi-Fi device.
 *
 * @since		1.0
 * @see			WifiManager::GetPowerStatus()
 */
typedef enum
{
	WIFI_POWER_STATUS_OFF = 0,				/**< The local Wi-Fi device is turned off */
	WIFI_POWER_STATUS_ON,					/**< The local Wi-Fi device is turned on  */
	WIFI_POWER_STATUS_DEEP_SLEEP,			/**< The local Wi-Fi device enters deep sleep mode */
} WifiPowerStatus;

/**
 * @enum		WifiBssType
 * Defines the type of Basic Service Set (BSS).
 *
 * @since		1.0
 */
typedef enum
{
	WIFI_BSS_TYPE_INFRASTRUCTURE = 0,	/**< The infrastructure type which usually consists of a single Access Point (AP).
										// However, in order to provide sufficient coverage, it could be necessary to use two or more APs.
										// Logically, there needs to be an interconnection among APs, and this concept is called Distribution System (DS).
										// Connecting with multiple APs through DS creates a wireless network of an arbitrary size.
										// This is called Extended Service Set (ESS). Finally, a logical connection point to the wired LAN is supported by a concept designated as Portal.
										*/
	WIFI_BSS_TYPE_INDEPENDENT, 			/**< The simplest Wi-Fi configuration is called as Independent Basic Service Set (IBSS) or ad hoc.
										// The IBSS is a self-contained network that only supports direct communication between Stations (STAs) that belong to the same BSS.
										// The most common example of this connection is the use of Wi-Fi to establish peer-to-peer network connection between two STAs.
										*/
	WIFI_BSS_TYPE_ANY,					/**< The type with no specification */
	WIFI_BSS_TYPE_MAX = 0xFF			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
} WifiBssType;

/**
 * @enum		WifiAuthenticationType
 * Defines IEEE 802.11 authentication. 
 * IEEE 802.11 authentication operates at the link level between IEEE 802.11 stations (STAs).
 * IEEE 802.11 does not provide end-to-end (message origin to message destination) or user-to-user authentication.
 *
 * @since		1.0
 */
typedef enum
{
	WIFI_AUTHENTICATION_OPEN = 0x00,		/**< The Open System Authentication that admits any STA to the DS */
	WIFI_AUTHENTICATION_SHARED,				/**< The Shared Key Authentication relies on the WEP to demonstrate knowledge of a WEP encryption key */
	WIFI_AUTHENTICATION_WPA,				/**< The Enterprise Authentication that supports WPA (Wi-Fi Protected Access) */
	WIFI_AUTHENTICATION_WPA_PSK,			/**< The Personal Authentication that supports WPA; PSK stands for PreShared Key */
	WIFI_AUTHENTICATION_WPA2,				/**< The Enterprise Authentication that supports WPA2 */
	WIFI_AUTHENTICATION_WPA2_PSK,			/**< The Personal Authentication that supports WPA2; PSK stands for PreShared Key */
    WIFI_AUTHENTICATION_WPA_WPA2_MIXED_PSK,	/**< The Personal Authentication that supports both WPA and WPA2; PSK stands for PreShared Key  @b Since: @b 2.0 */
    WIFI_AUTHENTICATION_MAX = 0xFF			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
} WifiAuthenticationType;

/**
 * @enum		WifiEncryptionType
 * Defines the IEEE 802.11 encryption that provides the data confidentiality aspects of a closed wired media.
 *
 * @since		1.0
 */
typedef enum
{
	WIFI_ENCRYPTION_NONE = 0x00,	/**< The type with no encryption */
	WIFI_ENCRYPTION_WEP,			/**< The Wired Equivalent Privacy. This is only used for open and shared methods */
	WIFI_ENCRYPTION_TKIP,			/**< The Temporal Key Integrity Protocol */
	WIFI_ENCRYPTION_AES,			/**< The Advanced Encryption Standard */
	WIFI_ENCRYPTION_TKIP_AES_MIXED,	/**< The TKIP and AES are both supported  @b Since: @b 2.0 */
	WIFI_ENCRYPTION_MAX	= 0xFF		/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
} WifiEncryptionType;

/**
 * @enum	WifiEapType
 * Defines the Extensible Authentication Protocol (EAP) method types that provide a specific authentication mechanism.
 *
 * @since	1.2
 */
typedef enum
{
	WIFI_EAP_NONE = 0x00,			/**< The method type where no EAP method is used */
	WIFI_EAP_SIM = 0x01,			/**< The EAP-SIM; EAP for GSM Subscriber Identity */
	WIFI_EAP_AKA = 0x02,			/**< The EAP-AKA; EAP for UMTS Authentication and Key Agreement */
	WIFI_EAP_TTLS_MSCHAPV2 = 0x03,	/**< The EAP-TTLS/MSCHAPv2; Tunnel MSCHAPv2 through TTLS(Tunneled Transport Layer Security) */
	WIFI_EAP_PEAP_MSCHAPV2 = 0x04,	/**< The PEAPv0/EAP-MSCHAPv2; Tunnel MSCHAPv2 through PEAP(Protected Extensible Authentication Protocol) */
	WIFI_EAP_PEAP_GTC = 0x05,		/**< The PEAPv1/EAP-GTC; Tunnel GTC through PEAP(Protected Extensible Authentication Protocol) */
	WIFI_EAP_TLS = 0x06				/**< The EAP-TLS, Not supported yet */
} WifiEapType;

/**
 * @enum		WifiWepKeyLen
 * Defines the Wired Equivalent Privacy (WEP) key length.
 *
 * @since		1.0
 */
 typedef enum
{
    WIFI_WEP_KEY_LEN_64BIT = 0x00,	/**< The WEP key of length 64bits @n
                                       	The minimum length of the WEP key is 5 digits (40bits). */
	WIFI_WEP_KEY_LEN_128BIT,		/**< The WEP key of length 128bits @n
	                                    The minimum length of the WEP key is 13 digits (104bits). */
	WIFI_WEP_KEY_LEN_MAX = 0xFF		/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
} WifiWepKeyLen;

/**
 * @enum		WifiWepKeyIndex
 * Defines the Wired Equivalent Privacy (WEP) key index.
 *
 * @since		1.0
 * @remarks		Only WIFI_WEP_KEY_INDEX_1 is supported now.
 */
 typedef enum
{
	WIFI_WEP_KEY_INDEX_1 = 1,	/**< The WEP Key Index 1 */
	WIFI_WEP_KEY_INDEX_2 = 2,	/**< The WEP Key Index 2 */
	WIFI_WEP_KEY_INDEX_3 = 3,	/**< The WEP Key Index 3 */
	WIFI_WEP_KEY_INDEX_4 = 4,	/**< The WEP Key Index 4 */
} WifiWepKeyIndex;

/**
 * @enum		WifiRadioChannel
 * Defines the BSS radio channel.
 *
 * @since		1.0
 * @remarks		The channel control is not supported as yet.
 */
typedef enum
{
	WIFI_RADIO_CHANNEL_1   		= 1,		/**< The Radio Channel 1 */
	WIFI_RADIO_CHANNEL_2   		= 2,		/**< The Radio Channel 2 */
	WIFI_RADIO_CHANNEL_3   		= 4,		/**< The Radio Channel 3 */
	WIFI_RADIO_CHANNEL_4   		= 8,		/**< The Radio Channel 4 */
	WIFI_RADIO_CHANNEL_5   		= 16,		/**< The Radio Channel 5 */
	WIFI_RADIO_CHANNEL_6   		= 32,		/**< The Radio Channel 6 */
	WIFI_RADIO_CHANNEL_7   		= 64,		/**< The Radio Channel 7 */
	WIFI_RADIO_CHANNEL_8   		= 128,		/**< The Radio Channel 8 */
	WIFI_RADIO_CHANNEL_9   		= 256,		/**< The Radio Channel 9 */
	WIFI_RADIO_CHANNEL_10  		= 512,		/**< The Radio Channel 10 */
	WIFI_RADIO_CHANNEL_11  		= 1024,		/**< The Radio Channel 11 */
	WIFI_RADIO_CHANNEL_12  		= 2048,		/**< The Radio Channel 12 */
	WIFI_RADIO_CHANNEL_13  		= 4096,		/**< The Radio Channel 13 */
	WIFI_RADIO_CHANNEL_14  		= 8192,		/**< The Radio Channel 14 */
	WIFI_RADIO_CHANNEL_UNKNOWN  = 0			/**< @internal This is internal. If used in an application, the application can get rejected during the certification process.*/
} WifiRadioChannel;

/**
 * @enum	WifiDirectDeviceStatus
 * Defines the status of a Wi-Fi Direct device.
 *
 * @since	2.0
 */
typedef enum
{
	WIFI_DIRECT_DEVICE_DEACTIVATED    = 0, 	        /**< The Wi-Fi interface is deactivated */
	WIFI_DIRECT_DEVICE_ACTIVATED  					/**< The Wi-Fi interface is activated  */
} WifiDirectDeviceStatus;

/**
 * @enum	WifiDirectGroupMemberType
 * Defines the type of a Wi-Fi Direct device.
 *
 * @since	2.0
 */
typedef enum
{
	WIFI_DIRECT_GROUP_MEMBER_TYPE_NONE		= 0,	/**< The Wi-Fi Direct Group Non-member. That is, the device does not belong to any group */
	WIFI_DIRECT_GROUP_MEMBER_TYPE_OWNER,  			/**< The Wi-Fi Direct Group Owner */
	WIFI_DIRECT_GROUP_MEMBER_TYPE_CLIENT 			/**< The Wi-Fi Direct Group Client */
} WifiDirectGroupMemberType;


/**
 * @enum	WifiDirectDeviceTypeCategory
 * Defines the category of the Wi-Fi Direct device type.
 *
 * @since	2.0
 */
typedef enum
{
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_COMPUTER					= 0,	/**< The PC, Server, Media Center, UMPC, Notebook, Desktop, MID, Netbook, and so on */
    WIFI_DIRECT_DEVICE_TYPE_CATEGORY_INPUT_DEVICE,                      /**< The Keyboard, Mouse, Joystick, Trackball, Gaming controller, Remote, Touchscreen, Biometric reader, Barcode reader, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_PRINTER_SCANNER_FAX_COPIER,        /**< The Printer, Print Server, Scanner, Fax, Copier, All-in-one, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_CAMERA,                            /**< The Digital still camera, Video camera, Web camera, Security camera, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_STORAGE,                           /**< The NAS */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_NETWORK_INFRASTRUCTURE,            /**< The AP, Router, Switch, Gateway, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_DISPLAY,                           /**< The Television, Electronic picture frame, Projector, Monitor, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_MULTIMEDIA_DEVICE,                 /**< The DAR, PVR, MCX, Set-top box, Media server, Media adapter, Media extender, Portable video player, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_GAMING_DEVICE,                     /**< The Xbox, Playstation, Game console, Game console adaptor, Portable gaming device, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_TELEPHONE,                         /**< The Windows Mobile, Phone, Smartphone, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_AUDIO_DEVICE,                      /**< The Audio tuner, Audio receiver, Speaker, Portable Music Player, Headset, Headphone, Microphone, and so on */
	WIFI_DIRECT_DEVICE_TYPE_CATEGORY_OTHERS						= 255	/**< A device which is not classified into the above types */
} WifiDirectDeviceTypeCategory;

/**
 * @enum    WifiDirectAssociationTerminationReason
 * Defines the reason for the Wi-Fi Direct group client association's termination.
 *
 * @since   2.0
 */
typedef enum 
{
	WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED = 0,      /**< The enumerator that is delivered to a group owner or group client who initiates the disassociation request */
	WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED				/**< The enumerator that is delivered to a group owner or group client who receives the disassociation request or when a client is disconnected due to out of range or abrupt connection loss to the group owner */
}WifiDirectAssociationTerminationReason;

/**
 * @enum WifiWpsConfigurationMode
 * Defines the configuration method for the Wi-Fi Protected Setup (WPS).
 *
 * @since     2.0
 */

typedef enum
{
	WIFI_WPS_CONFIG_MODE_NONE = 0,          /**< The configuration mode with no method to be provided */
	WIFI_WPS_CONFIG_MODE_PIN_DISPLAY,       /**< A method to display the PIN code */
    WIFI_WPS_CONFIG_MODE_PIN_KEYPAD,        /**< A method to provide the keypad to input the PIN */
    WIFI_WPS_CONFIG_MODE_PBC                /**< A method of Push Button Configuration (PBC) */
} WifiWpsConfigurationMode;


}; }; };

#endif // FNET_WIFI_WIFITYPES_H

