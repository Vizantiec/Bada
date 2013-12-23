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
 * @file    FNetBtBluetoothOppClient.h
 * @brief   This is the header file for the %BluetoothOppClient class.
 *
 * This header file contains the declarations of the %BluetoothOppClient class.
 */
#ifndef FNET_BT_BLUETOOTHOPPCLIENT_H
#define FNET_BT_BLUETOOTHOPPCLIENT_H

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"

namespace Osp { namespace Base {
class String;
}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class BluetoothDevice;
class IBluetoothOppClientEventListener;
class __BluetoothOppClientAgent;

/**
 * @class   BluetoothOppClient
 * @brief   This class provides the methods to handle the %Bluetooth Object Push Profile (OPP) client, such as the
 *          outgoing connection requests.
 * @since   1.0
 *
 * The %BluetoothOppClient class provides the methods to handle the %Bluetooth Object Push Profile (OPP) client, such as the outgoing
 * connection requests.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothOppClient: public Osp::Base::Object {
 
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
    BluetoothOppClient(void);

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothOppClient(void);

    /**
     * Initializes this instance of %BluetoothOppClient with the specified listener.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   listener                The event listener for the OPP client
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state. @n 
     *                                      For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result Construct(const IBluetoothOppClientEventListener& listener);

    /**
     * Pushes a file to a remote OPP server. @n
     * The file transfer starts when the OPP server accepts the request.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   remoteDevice                The remote OPP server
     * @param[in]   filePath                    The path of the source file
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet or
     *                                          %Bluetooth is not activated.
     * @exception   E_IN_PROGRESS               The push process is in progress.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SERVICE_UNAVAILABLE       The OPP service is unavailable.
     * @exception   E_INACCESSIBLE_PATH         The specified @c filePath is inaccessible.
     * @exception   E_REMOTE_DEVICE_NOT_FOUND   The input device is not found. @n
     *                                          This exception is currently not in use.
     * @exception   E_FAILURE                   The method has failed.
     * @see         IBluetoothOppServerEventListener::OnOppPushRequested()
     */
    result PushFile(const BluetoothDevice& remoteDevice, const Osp::Base::String& filePath);

    /**
     * Cancels the file push request in progress. @n
     * If this method is called before the OPP server accepts the push request, the
     * IBluetoothOppClientEventListener::OnOppPushResponded() method is called and the exception E_SYSTEM is thrown. @n
     * If this method is called during the file transfer, the IBluetoothOppClientEventListener::OnOppTransferDone()
     * method is called with @c isCompleted as @c false.
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
     *                                      For example, the push request is not sent or accepted by a remote device.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_FAILURE               The method has failed.
     * @see         IBluetoothOppClientEventListener::OnOppPushResponded()
     * @see         IBluetoothOppClientEventListener::OnOppTransferDone()
     */
    result CancelPush(void) const;

    /**
     * Sets the minimum interval of invocation of IBluetoothOppClientEventListener::OnOppTransferInProgress() in
     * percentage. @n
     * The default value is @c 5.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   percent                 The minimum period of progress interval as a percentage value
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_OUT_OF_RANGE          The value of an argument is outside the valid range defined by the method.
     * @exception   E_INVALID_STATE         This instance has not been constructed as yet.
     * @see         IBluetoothOppClientEventListener::OnOppTransferInProgress()
     */
    result SetMinProgressInterval(int percent);

private:

    BluetoothOppClient(const BluetoothOppClient& value);
    BluetoothOppClient& operator =(const BluetoothOppClient& value);

    __BluetoothOppClientAgent*              __pClientAgent;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHOPPCLIENT_H
