/* $Change: 877171 $ */
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
 * @file    FNetNfcITagConnectionListener.h
 * @brief   This is the header file for the %ITagConnectionListener interface.
 *
 * This header file contains the declarations of the %ITagConnectionListener interface.
 */

#ifndef _FNET_NFC_ITAG_CONNECTION_LISTENER_H_
#define _FNET_NFC_ITAG_CONNECTION_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

// Forward declaration
namespace Osp { namespace Base {
class ByteBuffer;
}}

namespace Osp { namespace Net { namespace Nfc {

/**
 * @interface    ITagConnectionListener
 * @brief        This interface provides a listener for the events related to the tag connection.
 * @since        2.0
 *
 * The %ITagConnectionListener interface provides the methods that are used for creating notifications for the result of the actions of the
 * TagConnection, such as sending a command.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/nfc.htm">NFC Guide</a>.
 */
class _EXPORT_NET_ ITagConnectionListener : public Osp::Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~ITagConnectionListener(void) {}

    /**
     * Called to notify the application when the response is received from the remote tag.
     *
     * @since       2.0
     *
     * @param[in]   pResponse           The response of the command as the ByteBuffer object, @n
     *                                  else @c null if the method is not successful
     * @param[in]   r                   An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_ILLEGAL_ACCESS    The sent command is denied by the target. @n
     *                                  The target tag is locked or protected for executing the command.
     * @exception   E_NOT_RESPONDING    The target tag is not responding.
     * @exception   E_SYSTEM            A system error has occurred.
     * @see         TagConnection::SendCommand()
     * @remarks     The input response (@c pResponse) should be deleted by the application to prevent memory leak.
     */
    virtual void OnNfcResponseReceivedN(Osp::Base::ByteBuffer* pResponse, result r) = 0;

protected:
    // Reserved virtual methods for later extension.
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void ITagConnectionListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void ITagConnectionListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of methods can be changed at any time without prior notice.
     *
     * @since    2.0
     */
    virtual void ITagConnectionListener_Reserved3 (void) {}
};

} } } // Osp::Net::Nfc

#endif // _FNET_NFC_ITAG_CONNECTION_LISTENER_H_

