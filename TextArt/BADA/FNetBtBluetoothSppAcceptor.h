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
 * @file        FNetBtBluetoothSppAcceptor.h
 * @brief       This is the header file for the %BluetoothSppAcceptor class.
 *
 * This header file contains the declarations of the %BluetoothSppAcceptor class.
 */
#ifndef FNET_BT_BLUETOOTHSPPACCEPTOR_H
#define FNET_BT_BLUETOOTHSPPACCEPTOR_H

#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

namespace Osp { namespace Base {
class ByteBuffer;
}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class IBluetoothSppAcceptorEventListener;
class __BluetoothSppAcceptorAgent;

/**
 * @class   BluetoothSppAcceptor
 * @brief   This class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) acceptor, such as an
 *          incoming connection request.
 * @since   1.0
 *
 * The %BluetoothSppAcceptor class provides the methods to handle the %Bluetooth Serial Port Profile (SPP) acceptor, such as an incoming
 * connection request.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothSppAcceptor: public Base::Object {

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
    BluetoothSppAcceptor(void);

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothSppAcceptor(void);

    /**
     * Initializes this instance of %BluetoothSppAcceptor with the specified listener.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   listener                The event listener for SPP acceptor
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(const IBluetoothSppAcceptorEventListener& listener);

    /**
     * Accepts a connection request from a remote SPP initiator. @n
     * This method establishes a connection.
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
     *                                      For example, the service is not started yet or the connection request is
     *                                      not yet received from a remote device.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
     */
    result AcceptConnection(void);

    /**
     * Rejects a connection request from a remote SPP initiator.
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
     *                                      For example, the service is not started yet or the connection request is
     *                                      not yet received from a remote device.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothSppInitiatorEventListener::OnSppConnectionResponded()
     */
    result RejectConnection(void);

    /**
     * Starts the SPP service.
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
     * @exception   E_IN_PROGRESS           The service has already started.
     * @exception   E_ALREADY_CONNECTED     The connection with an SPP initiator has already been established.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SERVICE_UNAVAILABLE   The SPP service is unavailable.
     * @exception   E_FAILURE               The method has failed.
     */
    result StartService(void);

    /**
     * Stops the SPP service. @n
     * This method disconnects the current connection before stopping the service.
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
     *                                      For example, the service is not started yet.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     */
    result StopService(void);

    /**
     * Disconnects the current connection.
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
     *                                      For example, the service is not started yet or a connection with a remote
     *                                      device is not established.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothSppAcceptorEventListener::OnSppDisconnected()
     * @see         IBluetoothSppInitiatorEventListener::OnSppDisconnected()
     */
    result Disconnect(void);

    /**
     * Sends the data.
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
     *                                      For example, the service is not started yet or a connection with a remote
     *                                      device is not established.
     * @exception   E_INVALID_ARG           The specified @c buffer is empty.
     * @exception   E_SYSTEM                A system error has occurred.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @remarks     The size of the buffer should not exceed @c 1000 bytes.
     * @see         IBluetoothSppInitiatorEventListener::OnSppDataReceived()
     */
    result SendData(const Osp::Base::ByteBuffer& buffer);

private:

    BluetoothSppAcceptor(const BluetoothSppAcceptor& value);
    BluetoothSppAcceptor& operator =(const BluetoothSppAcceptor& value);

    __BluetoothSppAcceptorAgent*    __pAcceptorAgent;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHSPPACCEPTOR_H
