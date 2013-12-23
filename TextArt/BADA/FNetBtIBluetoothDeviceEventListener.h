/* $Change: 904484 $ */
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
 * @file    FNetBtIBluetoothDeviceEventListener.h
 * @brief   This is the header file for the %IBluetoothDeviceEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothDeviceEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHDEVICEEVENTLISTENER_H
#define FNET_BT_IBLUETOOTHDEVICEEVENTLISTENER_H

#include "FNetConfig.h"
#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

// Forward declaration
class BluetoothDevice;

/**
 * @interface   IBluetoothDeviceEventListener
 * @brief       This interface implements the listener for %Bluetooth remote device events.
 * @since       2.0
 *
 * The %IBluetoothDeviceEventListener interface specifies the methods used to create notifications for the different
 * kinds of %Bluetooth remote device events, including device discovery, service discovery, and pairing of the devices.
 * When a %Bluetooth device event is generated, one of these methods is called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothDeviceEventListener : public Base::Runtime::IEventListener
{

public:
    /**
     * This is the destructor for this class.
     *
     * @since       2.0
     */
    virtual ~IBluetoothDeviceEventListener(void) {}

    /**
     * Called when the device discovery process for finding the nearby %Bluetooth devices has started.
     *
     * @since       2.0
     *
     * @param[in]   r                   The start status
     * @exception   E_SUCCESS           The device discovery process is launched successfully.
     * @exception   E_SYSTEM            A system error has occurred.
     * @see         BluetoothManager::StartDiscovery()
     */
    virtual void OnBluetoothDiscoveryStarted(result r) = 0;

    /**
     * Called when a remote device is found during the device discovery process.
     *
     * @since       2.0
     *
     * @param[in]   pFoundDevice        The remote device that is found
     * @remarks     This event may be issued only if the device discovery process has started successfully.
     * @see         BluetoothManager::StartDiscovery()
     */
    virtual void OnBluetoothRemoteDeviceFoundN(BluetoothDevice* pFoundDevice) = 0;

    /**
     * Called when the device discovery process for finding the nearby %Bluetooth devices has completed.
     *
     * @since       2.0
     *
     * @param[in]   isCompleted         Set to @c true if the device discovery process is successfully completed, @n
     *                                  else @c false @n
     *                                  For example, the discovery is canceled.
     * @remarks     This event must be issued only if the discovery starts successfully.
     * @see         BluetoothManager::CancelDiscovery()
     */
    virtual void OnBluetoothDiscoveryDone(bool isCompleted) = 0;

    /**
     * Called when a service list is received from a remote device using the service discovery process.
     *
     * @since       2.0
     *
     * @param[in]   targetDevice                The remote device that sends its service list
     * @param[in]   serviceList                 The service list that is received
     * @param[in]   r                           The result of receiving the service list
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_REMOTE_SERVICE_NOT_FOUND  The service list of the remote device is not found.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     @c serviceList consists of Osp::Net::Bluetooth::BluetoothServiceType values which are joined by OR
     *              operator.
     */
    virtual void OnBluetoothServiceListReceived(const BluetoothDevice& targetDevice, unsigned long serviceList, result r) = 0;

    /**
     * Called when a new remote device is paired with this local device.
     *
     * @since       2.0
     *
     * @param[in]   pairedDevice        The device with which the local device is paired
     * @remarks     This method is able to be called even though the specified device already exists in the paired
     *              device list. Because the authorized key with the remote device is no more valid.
     */
    virtual void OnBluetoothPaired(const BluetoothDevice& pairedDevice) = 0;

    /**
     * Called when the already paired device is unpaired with this local device.
     *
     * @since       2.0
     *
     * @param[in]   unpairedDevice      The device with which the local device is unpaired
     */
    virtual void OnBluetoothUnpaired(const BluetoothDevice& unpairedDevice) = 0;

protected:
    // Reserved virtual methods for later extension.
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void IBluetoothDeviceEventListener_Reserved1 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void IBluetoothDeviceEventListener_Reserved2 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void IBluetoothDeviceEventListener_Reserved3 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void IBluetoothDeviceEventListener_Reserved4 (void) {}

    /**
     * @internal
     * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness,
     * consistency, and security-related issues that might arise after using this method.
     *
     * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
     *
     * @since       2.0
     */
    virtual void IBluetoothDeviceEventListener_Reserved5 (void) {}
};
} } }

#endif // FNET_BT_IBLUETOOTHDEVICEEVENTLISTENER_H
