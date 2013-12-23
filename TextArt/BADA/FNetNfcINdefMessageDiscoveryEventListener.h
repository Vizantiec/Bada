/* $Change: 884473 $ */
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
 * @file    FNetNfcINdefMessageDiscoveryEventListener.h
 * @brief   This is the header file for the %INdefMessageDiscoveryEventListener interface.
 *
 * This header file contains the declarations of the %INdefMessageDiscoveryEventListener interface.
 */

#ifndef _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_
#define _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FNetConfig.h"

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class NdefMessage;

/**
 * @interface   INdefMessageDiscoveryEventListener
 * @brief       This interface provides a listener for the events related to the NDEF message discovery.
 * @since       2.0
 *
 * The %INdefMessageDiscoveryEventListener interface specifies the methods used for creating notifications about the NDEF message discovered from the
 * target tag.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ INdefMessageDiscoveryEventListener : public Osp::Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~INdefMessageDiscoveryEventListener(void) {}

    /**
     * Called to notify the application when an NDEF message, that includes the NDEF records with the specified filter
     * type, is detected.
     *
     * @since       2.0
     *
     * @param[in]   pMessage        The detected NDEF message
     * @remarks     This method can be used for read-only access to the data on the target without opening a connection
     *              to it.
     *              The input NdefMessage object should be deleted by the application after use, even outside this
     *              method. The NdefMessage::RemoveAllRecords() method should be called with @c true as the input value
     *              immediately before the NdefMessage object is deleted.
     */
    virtual void OnNdefMessageDetectedN(NdefMessage* pMessage) = 0;

protected:
    // Reserved virtual methods for later extension.
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void INdefMessageDiscoveryEventListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void INdefMessageDiscoveryEventListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void INdefMessageDiscoveryEventListener_Reserved3 (void) {}
};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_INDEF_MESSAGE_DISCOVERY_EVENT_LISTENER_H_
