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
 * @file    FNetBtIBluetoothSppAcceptorEventListener.h
 * @brief   This is the header file for the %IBluetoothSppAcceptorEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothSppAcceptorEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHSPPACCEPTOREVENTLISTENER_H
#define FNET_BT_IBLUETOOTHSPPACCEPTOREVENTLISTENER_H

#include "FBaseByteBuffer.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

// Forward declaration
class BluetoothSppAcceptor;
class BluetoothDevice;

/**
 * @interface   IBluetoothSppAcceptorEventListener
 * @brief       This interface provides a listener for the %BluetoothSppAcceptor events.
 * @since       1.0
 *
 * The %IBluetoothSppAcceptorEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothSppAcceptor events. When a BluetoothSppAcceptor event is generated, one of these methods
 * is called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothSppAcceptorEventListener : public Base::Runtime::IEventListener {

public:
    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    virtual ~IBluetoothSppAcceptorEventListener(void) {}

    /**
     * Called to notify an incoming connection request from a remote SPP initiator.
     *
     * @since       1.0
     *
     * @param[in]   device          The remote device that requests the connection
     * @remarks     If BluetoothSppAcceptor::SendData() is invoked in this callback, it does not work as expected.
     *              Therefore, it should be invoked outside this callback thread.
     */
    virtual void OnSppConnectionRequested(const BluetoothDevice& device) = 0;

    /**
     * Called to notify that the connection is disconnected.
     *
     * @since       1.0
     *
     * @param[in]   r               The disconnection status
     * @exception   E_SUCCESS       The connection is terminated successfully.
     * @exception   E_SYSTEM        The method has failed to disconnect.
     */
    virtual void OnSppDisconnected(result r) = 0;

    /**
     * Called to notify when the data is received.
     *
     * @since       1.0
     *
     * @param[in]   buffer          The received data as a ByteBuffer
     */
    virtual void OnSppDataReceived(Osp::Base::ByteBuffer& buffer) = 0;
};
} } }
#endif // FNET_BT_IBLUETOOTHSPPACCEPTOREVENTLISTENER_H
