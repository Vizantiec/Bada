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
 * @file        FNetBtBluetoothOppServer.h
 * @brief       This is the header file for the %BluetoothOppServer class.
 *
 * This header file contains the declarations of the %BluetoothOppServer class.
 */
#ifndef FNET_BT_BLUETOOTHOPPSERVER_H
#define FNET_BT_BLUETOOTHOPPSERVER_H

#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FBaseResult.h"

namespace Osp { namespace Base {
class String;
}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class IBluetoothOppServerEventListener;
class __BluetoothOppServerAgent;

/**
 * @class    BluetoothOppServer
 * @brief    This class provides the methods to handle the %Bluetooth Object Push Profile (OPP) server, such as the
 *           incoming connection requests.
 * @since    1.0
 *
 * The %BluetoothOppServer class provides the methods to handle the %Bluetooth Object Push Profile (OPP) server, such as the incoming
 * connection requests.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothOppServer: public Osp::Base::Object {

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
    BluetoothOppServer(void);

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothOppServer(void);

    /**
     * Initializes this instance of %BluetoothOppServer with the specified listener.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   listener                The event listener for the OPP server
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(const IBluetoothOppServerEventListener& listener);

    /**
     * Accepts a push request from a remote OPP client. @n
     * This method starts the file transfer.
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
     *                                      For example, the service is not started yet or a push request is not
     *                                      received from a remote device.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
     */
    result AcceptPush(void);

    /**
     * Rejects a push request from a remote OPP client.
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
     *                                      For example, the service is not started yet or a push request is not
     *                                      received from a remote device.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
     */
    result RejectPush(void);

    /**
     * Sets the destination path of the file to be received.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   dstPath                 The new destination file path
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance has not been constructed as yet.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, trying to change the path on Push transition is prohibited.
     * @exception   E_INACCESSIBLE_PATH     The specified @c dstPath is inaccessible.
     * @exception   E_FAILURE               The method has failed.
     */
    result SetDestinationPath(const Osp::Base::String& dstPath);

    /**
     * Starts the OPP service and associates a listener with it.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   dstPath                 The new destination file path
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
     *                                      For example, this instance has not been constructed as yet or %Bluetooth is
     *                                      not activated.
     * @exception   E_IN_PROGRESS           The service has already started.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_SERVICE_UNAVAILABLE   The OPP service is unavailable.
     * @exception   E_INACCESSIBLE_PATH     The specified @c dstPath is inaccessible.
     * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
     *                                      operation. @n
     *                                      For example, The stop process is in progress.
     * @exception   E_FAILURE               The method has failed.
     */
    result StartService(const Osp::Base::String& dstPath);

    /**
     * Stops the OPP service. @n
     * This method cancels the file transfer before stopping the service.
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
     *                                      For example, the service is not started as yet.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_IN_PROGRESS           The stop process is in progress.
     * @exception   E_FAILURE               The method has failed.
     */
    result StopService(void);

    /**
     * Sets the minimum interval of invocation of IBluetoothOppServerEventListener::OnOppTransferInProgress() in
     * percentage. @n
     * The default value is @c 5.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   percent                 The minimum period of progress interval as a percentage value
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_OUT_OF_RANGE          The value of the argument is outside the valid range defined by the method.
     * @exception   E_INVALID_STATE         This instance has not been constructed as yet.
     * @see         IBluetoothOppServerEventListener::OnOppTransferInProgress()
     */
    result SetMinProgressInterval(int percent);

private:

    BluetoothOppServer(const BluetoothOppServer& value);
    BluetoothOppServer& operator =(const BluetoothOppServer& value);

    __BluetoothOppServerAgent*              __pServerAgent;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHOPPSERVER_H
