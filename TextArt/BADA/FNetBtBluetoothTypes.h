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
 * @file    FNetBtBluetoothTypes.h
 * @brief   This is the header file for the enumerations in the Bluetooth namespace.
 *
 * This header file contains the declarations and descriptions of the enumerations in the Bluetooth namespace.
 */
#ifndef FNET_BT_BLUETOOTHTYPES_H
#define FNET_BT_BLUETOOTHTYPES_H

#include "FBaseTypes.h"

namespace Osp {
    namespace Net {
        namespace Bluetooth {

/**
 * @enum        BluetoothDeviceStateType
 * Defines the states of the local %Bluetooth device.
 *
 * @deprecated  This enum type is deprecated because the on/off states and the discoverable mode are not orthogonal.
 *              All the methods that use this enum type are also deprecated. Instead of using this enum type, it is
 *              recommended to use BluetoothManager::IsActivated() and the enum
 *              Osp::Net::Bluetooth::BluetoothDiscoverableMode.
 * @since       1.0
 */
typedef enum
{
    BT_DEVICE_STATE_OFF,                /**< The OFF state             */
    BT_DEVICE_STATE_DISCOVERABLE,       /**< The DISCOVERABLE state    */
    BT_DEVICE_STATE_NOT_DISCOVERABLE    /**< The NOT DISCOVERABLE state*/
} BluetoothDeviceStateType;

/**
 * @enum        BluetoothDiscoverableMode
 * Defines the discoverable mode of the local %Bluetooth device.
 *
 * @since       2.0
 */
typedef enum
{
    BT_DISC_MODE_NOT_DISCOVERABLE,      /**< The mode NOT DISCOVERABLE by other devices */
    BT_DISC_MODE_DISCOVERABLE,          /**< The mode DISCOVERABLE by other devices     */
} BluetoothDiscoverableMode;

/**
 * @enum        BluetoothConnectionType
 * Defines the %Bluetooth connection types.
 *
 * @since       1.0
 */
typedef enum
{
    BT_CONNECTION_GENERIC,              /**< The GENERIC CONNECTION
                                         *   @deprecated    This enumeration field is deprecated. @n
                                         */
    BT_CONNECTION_SPP_ACCEPTOR,         /**< The SPP ACCEPTOR CONNECTION  */
    BT_CONNECTION_SPP_INITIATOR,        /**< The SPP INITIATOR CONNECTION */
    BT_CONNECTION_OPP_SERVER,           /**< The OPP SERVER CONNECTION    */
    BT_CONNECTION_OPP_CLIENT,           /**< The OPP CLIENT CONNECTION    */
    BT_CONNECTION_MAX
} BluetoothConnectionType;


/**
 * @enum        BluetoothServiceClassType
 * Defines the service class type (part of the class of the device), returned from the device discovery.
 *
 * @since        1.0
 */
typedef enum
{
    BT_COD_SVC_LIMITED_DISCOVERABLE_MODE    = 0x0020,   /**< The LIMITED DISCOVERABLE MODE          */
    BT_COD_SVC_POSITIONING                  = 0x0100,   /**< The POSITIONING service class type     */
    BT_COD_SVC_NETWORKING                   = 0x0200,   /**< The NETWORKING service class type      */
    BT_COD_SVC_RENDERING                    = 0x0400,   /**< The RENDERING service class type       */
    BT_COD_SVC_CAPTURING                    = 0x0800,   /**< The CAPTURING service class type       */
    BT_COD_SVC_OBJECT_TRANSFER              = 0x1000,   /**< The OBJECT TRANSFER service class type */
    BT_COD_SVC_AUDIO                        = 0x2000,   /**< The AUDIO service class type           */
    BT_COD_SVC_TELEPHONY                    = 0x4000,   /**< The TELEPHONY service class type       */
    BT_COD_SVC_INFORMATION                  = 0x8000,   /**< The INFORMATION service class type     */
    BT_COD_SVC_ALL                          = 0x01FF,   /**< The ALL services class type            */
    BT_COD_SVC_UNKNOWN                      = 0x0000    /**< The UNKNOWN service class type         */
} BluetoothServiceClassType;

/**
 * @enum        BluetoothMajorDeviceClassType
 * Defines the major device class (part of the class of the device).
 *
 * @since        1.0
 */
typedef enum
{
    BT_COD_MAJ_DEV_CLS_MISC                 = 0x00,     /**< The MISC major device class type             */
    BT_COD_MAJ_DEV_CLS_COMPUTER             = 0x01,     /**< The COMPUTER major device class type         */
    BT_COD_MAJ_DEV_CLS_PHONE                = 0x02,     /**< The PHONE major device class type            */
    BT_COD_MAJ_DEV_CLS_LAN_ACCESS_POINT     = 0x03,     /**< The LAN ACCESS POINT major device class type */
    BT_COD_MAJ_DEV_CLS_AUDIO                = 0x04,     /**< The AUDIO major device class type            */
    BT_COD_MAJ_DEV_CLS_PERIPHERAL           = 0x05,     /**< The PERIPHERAL major device class type       */
    BT_COD_MAJ_DEV_CLS_IMAGING              = 0x06,     /**< The IMAGING major device class type          */
    BT_COD_MAJ_DEV_CLS_UNCLASSIFIED         = 0x1F      /**< The UNCLASSIFIED major device class type     */
}BluetoothMajorDeviceClassType;

/**
 * @enum        BluetoothMinorDeviceClassType
 * Defines the minor device class (part of the class of the device).
 *
 * @since        1.0
 */
typedef enum  {
    BT_COD_MIN_DEV_CLS_UNCLASSIFIED                 = 0x00, /**< The UNCLASSIFIED minor device class type          */

    BT_COD_MIN_DEV_CLS_DESKTOP_WORKSTATION          = 0x04, /**< The DESKTOP WORKSTATION minor device class type   */
    BT_COD_MIN_DEV_CLS_SERVER_CLASS_COMPUTER        = 0x08, /**< The SERVER CLASS COMPUTER minor device class type */
    BT_COD_MIN_DEV_CLS_LAPTOP                       = 0x0C, /**< The LAPTOP minor device class type                */
    BT_COD_MIN_DEV_CLS_HANDHELD_PC_OR_PDA           = 0x10, /**< The HANDHELD PC OR PDA minor device class type    */
    BT_COD_MIN_DEV_CLS_PALM_SIZED_PC_OR_PDA         = 0x14, /**< The PALM SIZED PC OR PDA minor device class type  */
    BT_COD_MIN_DEV_CLS_WEARABLE_COMPUTER            = 0x18, /**< The WEARABLE COMPUTER minor device class type     */

    BT_COD_MIN_DEV_CLS_CELLULAR                     = 0x04, /**< The CELLULAR minor device class type                     */
    BT_COD_MIN_DEV_CLS_CORDLESS                     = 0x08, /**< The CORDLESS minor device class type                     */
    BT_COD_MIN_DEV_CLS_SMART_PHONE                  = 0x0C, /**< The SMART PHONE minor device class type                  */
    BT_COD_MIN_DEV_CLS_WIRED_MODEM_OR_VOICE_GATEWAY = 0x10, /**< The WIRED MODEM OR VOICE GATEWAY minor device class type */
    BT_COD_MIN_DEV_CLS_COMMON_ISDN_ACCESS           = 0x14, /**< The COMMON ISDN ACCESS minor device class type           */

    BT_COD_MIN_DEV_CLS_FULLY_AVAILABLE              = 0x04, /**< The FULLY AVAILABLE minor device class type           */
    BT_COD_MIN_DEV_CLS_1_TO_17_PERCENT_UTILIZED     = 0x20, /**< The 1_TO_17_PERCENT_UTILIZED minor device class type  */
    BT_COD_MIN_DEV_CLS_17_TO_33_PERCENT_UTILIZED    = 0x40, /**< The 17_TO_33_PERCENT_UTILIZED minor device class type */
    BT_COD_MIN_DEV_CLS_33_TO_50_PERCENT_UTILIZED    = 0x60, /**< The 33_TO_50_PERCENT_UTILIZED minor device class type */
    BT_COD_MIN_DEV_CLS_50_to_67_PERCENT_UTILIZED    = 0x80, /**< The 50_to_67_PERCENT_UTILIZED minor device class type */
    BT_COD_MIN_DEV_CLS_67_TO_83_PERCENT_UTILIZED    = 0xA0, /**< The 67_TO_83_PERCENT_UTILIZED minor device class type */
    BT_COD_MIN_DEV_CLS_83_TO_99_PERCENT_UTILIZED    = 0xC0, /**< The 83_TO_99_PERCENT_UTILIZED minor device class type */
    BT_COD_MIN_DEV_CLS_NO_SERVICE_AVAILABLE         = 0xE0, /**< The NO SERVICE AVAILABLE minor device class type      */

    BT_COD_MIN_DEV_CLS_HEADSET_PROFILE              = 0x04, /**< The HEADSET PROFILE minor device class type       */
    BT_COD_MIN_DEV_CLS_HANDSFREE                    = 0x08, /**< The HANDSFREE minor device class type             */
    BT_COD_MIN_DEV_CLS_SIM_CARD_READER              = 0x18, /**< The SIM CARD READER minor device class type       */

} BluetoothMinorDeviceClassType;

/**
 * @enum        BluetoothServiceType
 * Defines the %Bluetooth service type.
 *
 * @since       1.0
 */
typedef enum
{
    BT_SVC_RES_SERVICE          = 0x00000001,  /**< The Reserved service type                       */
    BT_SVC_SPP_SERVICE          = 0x00000002,  /**< The Serial port profile service type            */
    BT_SVC_DUN_SERVICE          = 0x00000004,  /**< The Dial-up networking profile service type     */
    BT_SVC_FAX_SERVICE          = 0x00000008,  /**< The Fax profile service type                    */
    BT_SVC_LAP_SERVICE          = 0x00000010,  /**< The LAN access profile service type             */
    BT_SVC_HSP_SERVICE          = 0x00000020,  /**< The Headset profile service type                */
    BT_SVC_HFP_SERVICE          = 0x00000040,  /**< The Hands-free profile service type             */
    BT_SVC_OPP_SERVICE          = 0x00000080,  /**< The Object push service type                    */
    BT_SVC_FTP_SERVICE          = 0x00000100,  /**< The File transfer service type                  */
    BT_SVC_CTP_SERVICE          = 0x00000200,  /**< The Cordless Terminal service type              */
    BT_SVC_ICP_SERVICE          = 0x00000400,  /**< The Intercom Terminal service type              */
    BT_SVC_SYNC_SERVICE         = 0x00000800,  /**< The Synchronization service type                */
    BT_SVC_BPP_SERVICE          = 0x00001000,  /**< The Print server service type                   */
    BT_SVC_BIP_SERVICE          = 0x00002000,  /**< The Basic Imaging service type                  */
    BT_SVC_PANU_SERVICE         = 0x00004000,  /**< The PAN User service type                       */
    BT_SVC_NAP_SERVICE          = 0x00008000,  /**< The PAN Network access point service type       */
    BT_SVC_GN_SERVICE           = 0x00010000,  /**< The PAN Group Ad-hoc networks service type      */
    BT_SVC_SAP_SERVICE          = 0x00020000,  /**< The SIM Access Profile service type             */
    BT_SVC_A2DP_SERVICE         = 0x00040000,  /**< An advanced audio distribution service type     */
    BT_SVC_AVRCP_SERVICE        = 0x00080000,  /**< An A/V remote control service type              */
    BT_SVC_HID_SERVICE          = 0x00100000,  /**< The HID profile service type                    */
    BT_SVC_VDP_SERVICE          = 0x00200000,  /**< The VDP profile service type                    */
    BT_SVC_PBAP_SERVICE         = 0x00400000,  /**< The PhoneBook Access service type               */
    BT_SVC_HSP_HS_SERVICE       = 0x00800000,  /**< The Headset Headset service type                */
    BT_SVC_HFP_HS_SERVICE       = 0x01000000,  /**< The Hands-free Headset service type             */
    BT_SVC_ALL_SERVICE          = 0x01FFFFFF,  /**< The All-services-supported-by-BTA service type  */
    BT_SVC_MAX,
    BT_SVC_NONE                 = 0            /**< The No service or unknown service type          */
} BluetoothServiceType;

/**
 * @internal
 * This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness,
 * consistency, and security-related issues that might arise after using this enum.
 *
 * @enum        BluetoothServiceClassUUIDType
 * Defines %Bluetooth assigned UUIDs for Service Classes.
 * Reference site: www.bluetooth.org/Technical/AssignedNumbers/service_discovery.htm
 *
 * @since       1.0
 */
typedef enum
          {
    BT_SC_UUID_NONE                                      = 0x0000, /**< @internal NONE                         */
    BT_SC_UUID_SERVICE_DISCOVERY_SERVER                  = 0x1000, /**< @internal The SERVICE_DISCOVERY_SERVER */
    BT_SC_UUID_BROWSE_GROUP_DESCRIPTOR                   = 0x1001, /**< @internal The BROWSE_GROUP_DESCRIPTOR  */
    BT_SC_UUID_PUBLIC_BROWSE_GROUP                       = 0x1002, /**< @internal PUBLIC_BROWSE_GROUP          */
    BT_SC_UUID_SERIAL_PORT                               = 0x1101, /**< @internal SERIAL_PORT                  */
    BT_SC_UUID_LAN_ACCESS_PPP                            = 0x1102, /**< @internal LAN_ACCESS_PPP               */
    BT_SC_UUID_DIALUP_NETWORKING                         = 0x1103, /**< @internal DIALUP_NETWORKING            */
    BT_SC_UUID_IR_MC_SYNC                                = 0x1104, /**< @internal IR_MC_SYNC                   */
    BT_SC_UUID_OBEX_OBJECT_PUSH                          = 0x1105, /**< @internal OBEX_OBJECT_PUSH             */
    BT_SC_UUID_OBEX_FILE_TRANSFER                        = 0x1106, /**< @internal OBEX_FILE_TRANSFER           */
    BT_SC_UUID_IR_MC_SYNC_COMMAND                        = 0x1107, /**< @internal IR_MC_SYNC_COMMAND           */
    BT_SC_UUID_HEADSET                                   = 0x1108, /**< @internal HEADSET                      */
    BT_SC_UUID_CORDLESS_TELEPHONY                        = 0x1109, /**< @internal The CORDLESS_TELEPHONY       */
    BT_SC_UUID_AVRCP                                     = 0x110C, /**< @internal AVRCP                        */
    BT_SC_UUID_A2DP                                      = 0x110D, /**< @internal A2DP                         */
    BT_SC_UUID_INTERCOM                                  = 0x1110, /**< @internal The INTERCOM                 */
    BT_SC_UUID_FAX                                       = 0x1111, /**< @internal FAX                          */
    BT_SC_UUID_HEADSET_AUDIO_GATEWAY                     = 0x1112, /**< @internal HEADSET_AUDIO_GATEWAY        */
    BT_SC_UUID_PANU                                      = 0x1115, /**< @internal PAN User                     */
    BT_SC_UUID_NAP                                       = 0x1116, /**< @internal PAN Network access point     */
    BT_SC_UUID_GN                                        = 0x1117, /**< @internal PAN Group Ad-hoc networks    */
    BT_SC_UUID_IMAGING                                   = 0x111A, /**< @internal IMAGING                      */
    BT_SC_UUID_IMAGING_RESPONDER                         = 0x111B, /**< @internal IMAGING_RESPONDER            */
    BT_SC_UUID_IMAGING_AUTOMATIC_ARCHIVE                 = 0x111C, /**< @internal IMAGING_AUTOMATIC_ARCHIVE    */
    BT_SC_UUID_IMAGING_REFERENCED_OBJECTS                = 0x111D, /**< @internal IMAGING_REFERENCED_OBJECTS   */
    BT_SC_UUID_HANDSFREE                                 = 0x111E, /**< @internal HANDSFREE                    */
    BT_SC_UUID_HANDSFREE_AUDIO_GATEWAY                   = 0x111F, /**< @internal HANDSFREE_AUDIO_GATEWAY      */
    BT_SC_UUID_DIRECT_PRINTING_REFERENCE_OBJECTS_SERVICE = 0x1120, /**< @internal DIRECT_PRINTING_REFERENCE_OBJECTS_SERVICE */
    BT_SC_UUID_REFLECTED_UI                              = 0x1121, /**< @internal The REFLECTED_UI             */
    BT_SC_UUID_BASIC_PRINTING                            = 0x1122, /**< @internal The BASIC_PRINTING           */
    BT_SC_UUID_PRINTING_STATUS                           = 0x1123, /**< @internal The PRINTING_STATUS          */
    BT_SC_UUID_SIM_ACCESS                                = 0x112D, /**< @internal The SIM_ACCESS               */
    BT_SC_UUID_PHONEBOOK_ACCESS_PCE                      = 0x112E, /**< @internal The PBAP Client              */
    BT_SC_UUID_PHONEBOOK_ACCESS_PSE                      = 0x112F, /**< @internal The PBAP Server              */
    BT_SC_UUID_PNP_INFORMATION                           = 0x1200, /**< @internal PNP_INFORMATION              */
    BT_SC_UUID_GENERIC_NETWORKING                        = 0x1201, /**< @internal GENERIC_NETWORKING           */
    BT_SC_UUID_GENERIC_FILE_TRANSFER                     = 0x1202, /**< @internal The GENERIC_FILE_TRANSFER    */
    BT_SC_UUID_GENERIC_AUDIO                             = 0x1203, /**< @internal The GENERIC_AUDIO            */
    BT_SC_UUID_GENERIC_TELEPHONY                         = 0x1204, /**< @internal The GENERIC_TELEPHONY        */
    BT_SC_UUID_MAX
} BluetoothServiceClassUUIDType;

        }
    }
}
#endif // FNET_BT_BLUETOOTHTYPES_H
