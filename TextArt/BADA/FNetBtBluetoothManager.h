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
 * @file    FNetBtBluetoothManager.h
 * @brief   This is the header file for the %BluetoothManager class.
 *
 * This header file contains the declarations of the %BluetoothManager class.
 */
#ifndef FNET_BT_BLUETOOTHMANAGER_H
#define FNET_BT_BLUETOOTHMANAGER_H

#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetBtBluetoothTypes.h"

namespace Osp { namespace Base {
class String;
class ByteBuffer;
}}

namespace Osp { namespace Base { namespace Collection {
class IList;
}}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class BluetoothDevice;
class IBluetoothManagerEventListener;
class IBluetoothDeviceEventListener;
class __BluetoothManagerAgent;

/**
 * @class   BluetoothManager
 * @brief   This class is used to obtain information about the local device or the paired devices, and to configure
 *          the %Bluetooth stack.
 * @since   1.0
 *
 * The %BluetoothManager class is used to obtain information about the local device or the paired devices, and to configure the
 * %Bluetooth stack.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothManager: public Base::Object {

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
    BluetoothManager(void);

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothManager(void);

    /**
     * Initializes this instance of the %BluetoothManager class with the specified listener.
     *
     * @since       1.0
     *
     * @return      An error code
     * @param[in]   listener                    The listener to handle the %BluetoothManager event
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this method is called repeatedly.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @exception   E_SYSTEM                    A system error has occurred.
     */
    result Construct(const IBluetoothManagerEventListener& listener);

    /**
     * Activates %Bluetooth on the device.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS               The %Bluetooth activation process is in progress.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of the
     *                                          specified operation. @n
     *                                          For example, %Bluetooth is already activated.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @see         IBluetoothManagerEventListener::OnBluetoothActivated()
     */
    result Activate(void);

    /**
     * Deactivates %Bluetooth on the device.
     *
     * @since       1.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS               The %Bluetooth deactivation process is in progress.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of the
     *                                          specified operation. @n
     *                                          For example, the %Bluetooth is already deactivated.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @see         IBluetoothManagerEventListener::OnBluetoothDeactivated()
     */
    result Deactivate(void);

    /**
     * Checks whether a %Bluetooth-specific profile is available.
     *
     * @since       1.0
     *
     * @return      @c true if the specified type of connection is available, @n
     *              else @c false
     * @param[in]   type                        The connection type
     *
     */
    bool IsAvailable(BluetoothConnectionType type) const;

    /**
     * Gets the local device information.
     *
     * @deprecated  This method is deprecated because the return value of this method is a dangling pointer if this
     *              instance of %BluetoothManager is deleted. In addition to this, the %BluetoothDevice class
     *              represents only remote devices since 2.0. Instead of using this method, the GetLocalDeviceAddress()
     *              and GetLocalDeviceName() methods are recommended.
     * @since       1.0
     *
     * @return      The local device information
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const BluetoothDevice* GetLocalDevice(void) const;

    /**
     * Gets the local %Bluetooth device address.
     *
     * @since       2.0
     *
     * @return      The local %Bluetooth device address
     * @remarks     The address is expressed as a @c 6 byte hexadecimal value delimited by colons. @n
     *              For example, "00:3D:47:EF:8A:03".
     */
    Osp::Base::String GetLocalDeviceAddress(void) const;

    /**
     * Gets the local %Bluetooth device name.
     *
     * @since       2.0
     *
     * @return      The local %Bluetooth device name
     */
    Osp::Base::String GetLocalDeviceName(void) const;

    /**
     * Gets the operational mode of the %Bluetooth unit.
     *
     * @deprecated  %BluetoothDeviceStateType is deprecated. Therefore, this method is also deprecated, because the
     *              return value of this method is of type %BluetoothDeviceStateType. Instead of using this method, the
     *              BluetoothManager::IsActivated() and BluetoothManager::GetDiscoverableMode() methods are recommended.
     *
     * @since       1.0
     *
     * @return      The operational mode
     */
    BluetoothDeviceStateType GetLocalDeviceState(void) const;

    /**
     * Checks whether the local %Bluetooth is activated.
     *
     * @since       2.0
     *
     * @return      @c true if the local %Bluetooth is activated, @n
     *              else @c false
     */
    bool IsActivated(void) const;

    /**
     * Gets the discoverable mode of the local device.
     *
     * @since       2.0
     *
     * @return      The discoverable mode of the local device
     */
    BluetoothDiscoverableMode GetDiscoverableMode(void) const;

    /**
     * Checks whether the device discovery is in progress.
     *
     * @since       2.0
     *
     * @return      @c true if the device discovery is in progress, @n
     *              else @c false
     */
    bool IsDiscoveryInProgress(void) const;

    /**
     * Sets the name of the local device.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   deviceName                  The new device name
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_INVALID_ARG               The specified device name is an empty string.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     This method does not affect the system settings. The device name is only valid while an application
     *              is active. The searching device detects the local devices in close proximity based on the specified
     *              device name. The specified device name is automatically truncated if its size is greater than @c 64
     *              bytes.
     */
    result SetLocalDeviceName(const Osp::Base::String& deviceName);

    /**
     * Refreshes the paired device list.
     *
     * @deprecated  This method is deprecated because the paired device list of this instance of %BluetoothManager is
     *              refreshed automatically. An application should not call this method to refresh the list.
     * @since       1.0
     *
     * @return      An error code
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @exception   E_SYSTEM                    A system error has occurred.
     */
    result RefreshPairedDeviceList(void);

    /**
     * Searches for an element that matches a %Bluetooth address.
     *
     * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
     *              instance of %BluetoothManager is deleted. In addition to this, it is also an invalid pointer if the
     *              paired device list is updated internally. Instead of using this method, GetPairedDeviceByAddressN()
     *              is recommended.
     * @since       1.0
     *
     * @return      The instance of %BluetoothDevice containing the specified address, @n
     *              else @c null if the search is not successful
     * @param[in]   deviceAddress               The address to be located
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_NOT_FOUND             The specified device is not found in the paired device list.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const BluetoothDevice* GetPairedDeviceByAddress(const Osp::Base::ByteBuffer& deviceAddress) const;

    /**
     * Searches for an element that matches a %Bluetooth address.
     *
     * @since       2.0
     *
     * @return      The instance of %BluetoothDevice containing the specified address, @n
     *              else @c null if the search is not successful
     * @param[in]   deviceAddress               The address to be located
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_NOT_FOUND             The specified device is not found in the paired device list.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    BluetoothDevice* GetPairedDeviceByAddressN(const Osp::Base::ByteBuffer& deviceAddress) const;

    /**
     * Gets the elements matching a device name in the paired device list.
     *
     * @since       1.0
     *
     * @return      A list containing the matching devices, @n
     *              else @c null if the search is not successful
     * @param[in]   deviceName                  The name of the device to be located
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_NOT_FOUND             The specified device is not found in the paired device list.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Base::Collection::IList* GetPairedDeviceByNameN(const Osp::Base::String& deviceName) const;

    /**
     * Gets the element at the specified index.
     *
     * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
     *              instance of %BluetoothManager is deleted. In addition to this, it is also an invalid pointer if the
     *              paired device list is updated internally. Instead of using this method, GetPairedDeviceListN() and
     *              Osp::Base::Collection::IList::GetAt() are recommended.
     * @since       1.0
     *
     * @return      The instance of %BluetoothDevice at the specified index, @n
     *              else @c null if there is no element
     * @param[in]   index                       The index in the list
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OBJ_NOT_FOUND             The specified index is not found in the paired device list.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const BluetoothDevice* GetPairedDeviceAt(int index) const;

    /**
     * Gets the paired device list.
     *
     * @deprecated  This method is deprecated because the return value of this method is a dangling pointer, if this
     *              instance of %BluetoothManager is deleted. In addition to this, some elements of the list may also
     *              be invalid pointers if the paired device list is updated internally. Instead of using this method,
     *              GetPairedDeviceListN() is recommended.
     * @since       1.0
     *
     * @return      A pointer to the paired device list on success, @n
     *              else @c null
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const Osp::Base::Collection::IList* GetPairedDeviceList(void) const;

    /**
     * Gets the paired device list.
     *
     * @since       2.0
     *
     * @return      A pointer to the paired device list on success, @n
     *              else @c null
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Base::Collection::IList* GetPairedDeviceListN(void) const;

    /**
     * Sets a remote device event listener for searching devices and services.
     *
     * @since       2.0
     *
     * @return      An error code
     * @param[in]   pListener                   The device event listener to be added
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     Only one event listener can be set. If the input parameter is @c null, the listener currently set
     *              is unregistered.
     */
    result SetBluetoothDeviceListener(const IBluetoothDeviceEventListener* pListener);

    /**
     * Starts a device discovery process.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS               The device discovery process is in progress.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of this
     *                                          operation.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryStarted()
     * @see         IBluetoothDeviceEventListener::OnBluetoothRemoteDeviceFoundN()
     * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryDone()
     */
    result StartDiscovery(void);

    /**
     * Stops the device discovery process.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS               The termination of the device discovery process is in progress.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of this
     *                                          operation. @n
     *                                          For example, the discovery has not started as yet.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @see         IBluetoothDeviceEventListener::OnBluetoothDiscoveryDone()
     */
    result CancelDiscovery(void);

    /**
     * Retrieves the service list from a remote device.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   pairedDevice                A remote device that is already paired with the local device
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_IN_PROGRESS               The retrieving is in progress.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of this
     *                                          operation. @n
     *                                          For example, the discovery is in progress.
     * @exception   E_NOT_PAIRED                The input device is not found in the paired device list.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     The target remote device should be a paired device.
     * @see         IBluetoothDeviceEventListener::OnBluetoothServiceListReceived()
     */
    result RetrieveServiceList(const BluetoothDevice& pairedDevice);

    /**
     * Unpairs the paired devices.
     *
     * @since       2.0
     * @privlevel   NORMAL
     * @privgroup   BLUETOOTH
     *
     * @return      An error code
     * @param[in]   pairedDevice                The paired device to be unpaired
     * @exception   E_SUCCESS                   The method is successful.
     * @exception   E_INVALID_STATE             This instance is in an invalid state. @n
     *                                          For example, this instance has not been constructed as yet.
     * @exception   E_INVALID_OPERATION         The current state of the instance prohibits the execution of this
     *                                          operation. @n
     *                                          For example, the %Bluetooth is not activated, or retrieving the service
     *                                          list is in progress.
     * @exception   E_NOT_PAIRED                The input device is not found in the paired device list.
     * @exception   E_PRIVILEGE_DENIED          The application does not have the privilege to call this method.
     * @exception   E_SYSTEM                    A system error has occurred.
     * @remarks     The process of unpairing is to remove the specified device from the paired device list. No
     *              notification is transmitted to the remote device.
     *              This method is synchronous. Only when the result of this method is E_SUCCESS, the unpaired event is
     *              fired.
     * @see         IBluetoothDeviceEventListener::OnBluetoothUnpaired()
     */
    result Unpair(const BluetoothDevice& pairedDevice);

private:
    BluetoothManager(const BluetoothManager& value);
    BluetoothManager& operator =(const BluetoothManager& value);

    __BluetoothManagerAgent*                    __pBluetoothManagerAgent;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHMANAGER_H
