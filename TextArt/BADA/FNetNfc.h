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
 * @file    FNetNfc.h
 * @brief    This is the header file for the %Nfc namespace.
 *
 * This header file contains the declarations and descriptions of the %Nfc namespace.
 */
#ifndef _FNET_NFC_H_
#define _FNET_NFC_H_

#include "FNetNfcNfcTypes.h"
#include "FNetNfcNdefRecordType.h"
#include "FNetNfcNdefRecord.h"
#include "FNetNfcNdefMessage.h"
#include "FNetNfcNfcTag.h"
#include "FNetNfcTagConnection.h"
#include "FNetNfcNdefTagConnection.h"
#include "FNetNfcNfcManager.h"
#include "FNetNfcINfcTagDiscoveryEventListener.h"
#include "FNetNfcINdefMessageDiscoveryEventListener.h"
#include "FNetNfcINfcManagerEventListener.h"
#include "FNetNfcITagConnectionListener.h"
#include "FNetNfcINdefTagConnectionListener.h"


namespace Osp { namespace Net {
/**
 * @namespace   Osp::Net::Nfc
 * @brief       This namespace contains the classes and interfaces for the Near Field Communication (NFC) services.
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *              @b Library : @b FOsp @n
 *
 * The %Nfc namespace contains the various classes and interfaces for the Near Field Communication (NFC) programming that
 * enables the devices to share information within a distance of less than @c 4 centimeters.
 *
 * For more information on the NFC namespace features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 * 
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Nfc namespace.
 * @image html net_nfc_using_the_apis_classdiagram.png 
 *
 */
namespace Nfc
{
}; }; }; // Osp::Net::Nfc
#endif // _FNET_NFC_H_

