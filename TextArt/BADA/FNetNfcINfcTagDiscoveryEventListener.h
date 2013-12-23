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
 * @file    FNetNfcINfcTagDiscoveryEventListener.h
 * @brief   This is the header file for the %INfcTagDiscoveryEventListener interface.
 *
 * This header file contains the declarations of the %INfcTagDiscoveryEventListener interface.
 */

#ifndef _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_
#define _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FNetConfig.h"

namespace Osp { namespace Net { namespace Nfc {

// Forward declaration
class TagConnection;

/**
 * @interface   INfcTagDiscoveryEventListener
 * @brief       This interface provides a listener for the events related to tag discovery.
 * @since       2.0
 *
 * The %INfcTagDiscoveryEventListener interface specifies the methods used for creating the notifications about detecting the target tag.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ INfcTagDiscoveryEventListener : public Osp::Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~INfcTagDiscoveryEventListener(void) {}

    /**
     * Called to notify the application when the tag is detected by the device.
     *
     * @since       2.0
     *
     * @param[in]   pConnection         The connection established with the detected tag
     * @remarks     TagConnection is inherited by NdefTagConnection if the current attached tag supports NDEF
     *              operations.
     *              To verify this, use TagConnection::IsNdefConnection().
     */
    virtual void OnNfcTagDetectedN(TagConnection* pConnection) = 0;

    /**
     * Called to notify the application when the tag is lost by the device.
     *
     * @since       2.0
     *
     * @remarks     The operations of TagConnection returned by OnNfcTagDetectedN() are not processed further after
     *              this event is called, that is, the target tag is lost. Moreover, the TagConnection object cannot be
     *              reused even though the same tag is detected again by the device.
     */
    virtual void OnNfcTagLost(void) = 0;

protected:
    // Reserved virtual methods for later extension.
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcTagDiscoveryEventListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcTagDiscoveryEventListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcTagDiscoveryEventListener_Reserved3 (void) {}
};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_INFC_TAG_DISCOVERY_EVENT_LISTENER_H_

