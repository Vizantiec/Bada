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
 * @file    FNetBtBluetoothSppInitiator.h
 * @brief   This is the header file for the %BluetoothSppInitiator class.
 *
 * This header file contains the declarations of the %BluetoothSppInitiator class.
 */
#ifndef FNET_BT_BLUETOOTHSPPINITIATOR_H
#define FNET_BT_BLUETOOTHSPPINITIATOR_H

#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

namespace Osp { namespace Base {
class ByteBuffer;
}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class BluetoothDevice;
class IBluetoothSppInitiatorEventListener;
class __BluetoothSppInitiatorAgent;

/**
 * @class   BluetoothSppInitiator
 * @brief   This class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) initiator, such as the
 *          outgoing connection requests.
 * @since   1.0
 *
 * The %BluetoothSppInitiator class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) initiator, such as the outgoing
 * connection requests.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothSppInitiator: public Base::Object {

public:
    /**
     * This is the default constructor for this class.
     *
     * @since       1.0
     *
     * @remarks     After creating an instance of this class, the Construct() method must be called explicitly to
     *              initialize this instance.
     * @see         Construct()
     */
    BluetoothSppInitiator(void);

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothSppInitiator(void);

    /**
     * Initializes this instance of %BluetoothSppInitiator with the specified listener.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   listener                The event listener for the SPP initiator
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(const IBluetoothSppInitiatorEventListener& listener);

    /**
     * Sets up a connection to a remote SPP acceptor. @n
     * This method establishes a connection after the SPP acceptor accepts the request.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   remoteDevice                The remote device to be connected
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet or
     *                                          %Bluetooth is not activated.
     * @exception   E_IN_PROGRESS               The connection process is in progress.
     * @exception   E_ALREADY_CONNECTED         The connection with an SPP acceptor has already been established.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SERVICE_UNAVAILABLE       The SPP connection is unavailable.
     * @exception   E_REMOTE_DEVICE_NOT_FOUND   The input device is not found. @n
     *                                          This exception is currently not in use.
     * @exception   E_FAILURE                   The method has failed.
     * @see         IBluetoothSppAcceptorEventListener::OnSppConnectionRequested()
     */
    result Connect(const BluetoothDevice& remoteDevice);

    /**
     * Disconnects the current connection. @n
     * If this method is called before the SPP acceptor accepts the connection request, the
     * IBluetoothSppInitiatorEventListener::OnSppConnectionResponded() and E_SYSTEM is thrown. @n
     * If this method is called on connection, the IBluetoothSppInitiatorEventListener::OnSppDisconnected() and
     * E_SUCCESS is thrown.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet or %Bluetooth is
     *                                      not activated.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, the connection request is not sent or a connection with a
     *                                      remote device is not established yet.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
     * @see         IBluetoothSppInitiatorEventListener::OnSppDisconnected()
     * @see         IBluetoothSppAcceptorEventListener::OnSppDisconnected()
     */
    result Disconnect(void);

    /**
     * Sends the specified data.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   buffer                  The data to be sent
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet or %Bluetooth is
     *                                      not activated.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, the connection request is not sent or a connection with a
     *                                      remote device is not established yet.
     * @exception   E_INVALID_ARG           The argument has no data.
     * @exception   E_SYSTEM                A system error has occurred.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @remarks     The size of the buffer should not exceed @c 1000 bytes.
     * @see         IBluetoothSppAcceptorEventListener::OnSppDataReceived()
     */
    result SendData(const Osp::Base::ByteBuffer& buffer);

private:

    BluetoothSppInitiator(const BluetoothSppInitiator& value);
    BluetoothSppInitiator& operator =(const BluetoothSppInitiator& value);

    __BluetoothSppInitiatorAgent*           __pInitiatorAgent;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHSPPINITIATOR_H
