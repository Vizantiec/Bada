/* $Change: 880962 $ */
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
* @file     FNetNfcNfcTypes.h
* @brief    This is the header file for defining types in the %Nfc namespace.
*
* This header file contains the definition of common types and enumerators for the %NFC features.
*/
#ifndef _FNET_NFC_NFC_TYPES_H_
#define _FNET_NFC_NFC_TYPES_H_

namespace Osp { namespace Net { namespace Nfc {

/**
 * @enum    NfcTagType
 * Defines the types of the NFC tag.
 *
 * @since   2.0
 */
enum NfcTagType
{
    NFC_TAG_TYPE_UNKNOWN = 0x00,            /**< The unknown tag type
                                             * @remarks     This type should not be used for the event filtering
                                             *              purpose as the input argument of
                                             *              NfcManager::AddTagDiscoveryEventListener().
                                             */
    NFC_TAG_TYPE_ISO14443_3A,               /**< The ISO14443 Part 3A tag type @n
                                             * For example, the Mifare UL, the Mifare Classic, and the Mifare DESFire
                                             * tags belong to this type.
                                             */
    NFC_TAG_TYPE_ISO14443_3B,               /**< The ISO14443 Part 3B tag type @n
                                             * For example, the Picopass 2K/32K tags belong to this type.
                                             */
    NFC_TAG_TYPE_FELICA,                    /**< The FeliCa tag type */
    NFC_TAG_TYPE_ISO15693,                  /**< The ISO15693 general RFID tag type */
    NFC_TAG_TYPE_TOPAZ_JEWEL,               /**< The Topaz/Jewel tag type */
    NFC_TAG_TYPE_MIFARE_UL,                 /**< The Mifare Ultralight/Ultralight C tag type */
    NFC_TAG_TYPE_MIFARE_CLASSIC,            /**< The Mifare Classic (1K/4K) tag type */
    NFC_TAG_TYPE_ISO14443_4,                /**< The ISO14443 Part 4 tag type @n
                                             * For example, the Mifare DESFire tag belongs to this type.
                                             */
    NFC_TAG_TYPE_FORUM_TYPE_1,              /**< The NFC forum type 1 */
    NFC_TAG_TYPE_FORUM_TYPE_2,              /**< The NFC forum type 2 */
    NFC_TAG_TYPE_FORUM_TYPE_3,              /**< The NFC forum type 3 */
    NFC_TAG_TYPE_FORUM_TYPE_4,              /**< The NFC forum type 4 */
    NFC_TAG_TYPE_ALL_NDEF_COMPATIBLE = 0xfe,/**< The all NDEF compatible tag type
                                             * @remarks     This type should be used only for event filtering as the
                                             *              input argument of
                                             *              NfcManager::AddTagDiscoveryEventListener().
                                             */
    NFC_TAG_TYPE_ALL = 0xff,                /**< The all tag type
                                             * @remarks     This type should be used only for event filtering as the
                                             *              input argument of
                                             *              NfcManager::AddTagDiscoveryEventListener().
                                             */
};

/**
 * @enum    NdefRecordTypeNameFormat
 * Defines the type name formats of the NDEF record.
 *
 * @since    2.0
 */
// Refer to NFCForum-TS-NDEF_1.0
enum NdefRecordTypeNameFormat
{
    NDEF_TNF_EMPTY = 0x00,                  /**< The empty record type */
    NDEF_TNF_WELL_KNOWN = 0x01,             /**< The NFC forum defined record type */
    NDEF_TNF_MIME_MEDIA = 0x02,             /**< The RFC2046 MIME media record type */
    NDEF_TNF_ABSOLUTE_URI = 0x03,           /**< The absolute URI record type */
    NDEF_TNF_EXTERNAL = 0x04,               /**< The user-defined record type (application specific) */
    NDEF_TNF_UNKNOWN = 0x05,                /**< The unknown record type */
    NDEF_TNF_ALL = 0xff,                    /**< The all record type
                                             * @remarks     This type should be used only for event filtering as the
                                             *              input argument of
                                             *              NfcManager::AddNdefMessageDiscoveryEventListener().
                                             */
};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_NFC_TYPES_H_

