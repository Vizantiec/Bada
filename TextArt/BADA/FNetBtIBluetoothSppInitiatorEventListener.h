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
 * @file    FNetBtIBluetoothSppInitiatorEventListener.h
 * @brief   This is the header file for the %IBluetoothSppInitiatorEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothSppInitiatorEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHSPPINITIATOREVENTLISTENER_H
#define FNET_BT_IBLUETOOTHSPPINITIATOREVENTLISTENER_H

#include "FBaseByteBuffer.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

/**
 * @interface   IBluetoothSppInitiatorEventListener
 * @brief       This interface provides a listener for the %BluetoothSppInitiator events.
 * @since       1.0
 *
 * The %IBluetoothSppInitiatorEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothSppInitiator events. When a BluetoothSppInitiator event is generated, one of these
 * methods is called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothSppInitiatorEventListener : public Base::Runtime::IEventListener {

public:
    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    virtual ~IBluetoothSppInitiatorEventListener(void) {}

    /**
     * Called to notify when an SPP acceptor responds to the connection request.
     *
     * @since       1.0
     * @param[in]   r               The status of the connection response
     * @exception   E_SUCCESS       The connection request is accepted by the SPP acceptor and the file transfer has
     *                              begun.
     * @exception   E_REJECTED      The connection request is rejected by the SPP acceptor. @n
     *                              This exception is currently not in use.
     * @exception   E_TIMEOUT       The connection request has timed out.
     * @exception   E_SYSTEM        A failure has occurred from the underlying system. @n
     *                              This failure includes the rejection by the SPP acceptor.
     */
    virtual void OnSppConnectionResponded(result r) = 0;

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
     * Called to notify when the data has been received.
     *
     * @since       1.0
     *
     * @param[in]   buffer          The received data
     */
    virtual void OnSppDataReceived(Osp::Base::ByteBuffer& buffer) = 0;
};
} } }
#endif // FNET_BT_IBLUETOOTHSPPINITIATOREVENTLISTENER_H
