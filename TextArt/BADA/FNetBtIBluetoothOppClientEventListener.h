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
 * @file        FNetBtIBluetoothOppClientEventListener.h
 * @brief       This is the header file for the %IBluetoothOppClientEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothOppClientEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHOPPCLIENTEVENTLISTENER_H
#define FNET_BT_IBLUETOOTHOPPCLIENTEVENTLISTENER_H

#include "FBaseString.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

/**
 * @interface   IBluetoothOppClientEventListener
 * @brief       This interface provides a listener for the %BluetoothOppClient events.
 * @since       1.0
 *
 * The %IBluetoothOppClientEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothOppClient events. When a BluetoothOppClient event is generated, one of these methods
 * is called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothOppClientEventListener : public Base::Runtime::IEventListener {

public:
    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    virtual ~IBluetoothOppClientEventListener(void) {}

    /**
     * Called when the OPP server responded to the push request.
     *
     * @since       1.0
     * @param[in]   r                   The response status
     * @exception   E_SUCCESS           The push request is accepted by the OPP server and the file transfer has begun.
     * @exception   E_REJECTED          The push request is rejected by the OPP server. @n
     *                                  This exception is currently not in use.
     * @exception   E_TIMEOUT           The push request is out of time.
     * @exception   E_SYSTEM            A failure has occurred from the underlying system. @n
     *                                  This failure includes the rejection by the OPP server.
     */
    virtual void OnOppPushResponded(result r) = 0;

    /**
     * Called when the file is being transferred. @n
     * Gets the progress information of the file transfer.
     *
     * @since       1.0
     * @param[in]   percent             The progress in percentage ranging from @c 1 to @c 100 percent
     * @see         BluetoothOppClient::SetMinProgressInterval()
     */
    virtual void OnOppTransferInProgress(int percent) = 0;

    /**
     * Called when the file transfer has finished.
     *
     * @since       1.0
     * @param[in]   filePath            The path of the transferred file including the file name
     * @param[in]   fileSize            The size of the transferred file
     * @param[in]   isCompleted         Set to @c true if the transfer is successfully completed, @n
     *                                  else @c false
     */
    virtual void OnOppTransferDone(const Osp::Base::String& filePath, int fileSize, bool isCompleted) = 0;
};

} } }
#endif // FNET_BT_IBLUETOOTHOPPCLIENTEVENTLISTENER_H
