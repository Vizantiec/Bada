/* $Change: 877168 $ */
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
 * @file    FNetNfcINfcManagerEventListener.h
 * @brief   This is the header file for the %INfcManagerEventListener interface.
 *
 * This header file contains the declarations of the %INfcManagerEventListener interface.
 */

#ifndef _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_
#define _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

namespace Osp { namespace Net { namespace Nfc {

/**
 * @interface   INfcManagerEventListener
 * @brief       This interface provides a listener for the events related to the Near field Communication (NFC)
 *              manager.
 * @since       2.0
 *
 * The %INfcManagerEventListener interface specifies the method used for creating the notifications about a change in the NfcManager status.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ INfcManagerEventListener : public Osp::Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~INfcManagerEventListener(void) {}

    /**
     * Called to notify when the NFC feature is activated on the device.
     *
     * @since       2.0
     *
     * @param[in]   r               The activation status
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     */
    virtual void OnNfcActivated(result r) = 0;

    /**
     * Called to notify when the NFC feature is deactivated on the device.
     *
     * @since       2.0
     *
     * @param[in]   r               The deactivation status
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     */
    virtual void OnNfcDeactivated(result r) = 0;

protected:
    // reserved virtual methods for later extension
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcManagerEventListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcManagerEventListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcManagerEventListener_Reserved3 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcManagerEventListener_Reserved4 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void INfcManagerEventListener_Reserved5 (void) {}

};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_INFC_MANAGER_EVENT_LISTENER_H_

