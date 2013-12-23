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
 * @file    FNetNfcINdefTagConnectionListener.h
 * @brief   This is the header file for the %INdefTagConnectionListener interface.
 *
 * This header file contains the declarations of the %INdefTagConnectionListener interface.
 */

#ifndef _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_
#define _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

namespace Osp { namespace Net { namespace Nfc
{

// Forward declaration
class NdefMessage;

/**
 * @interface   INdefTagConnectionListener
 * @brief       This interface provides a listener for the events related to the NDEF tag connection.
 * @since       2.0
 *
 * The %INdefTagConnectionListener interface specifies the methods used for creating the notifications about the result of an action for the
 * NdefTagConnection, such as reading and writing the NDEF data.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ INdefTagConnectionListener : public Osp::Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~INdefTagConnectionListener(void) {}

    /**
     * Called to notify the application when the read operation from the target tag is completed.
     *
     * @since       2.0
     *
     * @param[in]   pMessage                The read %NdefMessage object, @n
     *                                      else @c null if the method is not successful
     * @param[in]   r                       An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_DATA_NOT_FOUND        The target tag has no NDEF record.
     * @exception   E_INVALID_FORMAT        The read data cannot be formulated to the NDEF message.
     * @exception   E_NOT_RESPONDING        The target tag is not responding.
     * @exception   E_SYSTEM                A system error has occurred.
     * @see         NdefTagConnection::Read()
     * @remarks     The input NdefMessage object should be deleted by the application after use, even outside this
     *              method. The NdefMessage::RemoveAllRecords() method should be called with @c true as the input value
     *              right before the NdefMessage object is deleted.
     */
    virtual void OnNdefReadCompletedN(NdefMessage* pMessage, result r) = 0;

    /**
     * Called to notify the application when the write operation on the target tag is completed.
     *
     * @since       2.0
     *
     * @param[in]   r                       An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_ILLEGAL_ACCESS        The write operation on the target tag is denied. @n
     *                                      The target tag is locked or protected for the write operation.
     * @exception   E_STORAGE_FULL          The storage capacity of the target tag is full.
     * @exception   E_NOT_RESPONDING        The target tag is not responding.
     * @exception   E_SYSTEM                A system error has occurred.
     * @see         NdefTagConnection::Write()
     */
    virtual void OnNdefWriteCompleted(result r) = 0;

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
    virtual void INdefTagConnectionListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void INdefTagConnectionListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void INdefTagConnectionListener_Reserved3 (void) {}
};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_INDEF_TAG_CONNECTION_LISTENER_H_

