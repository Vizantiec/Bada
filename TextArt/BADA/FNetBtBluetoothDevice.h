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
 * @file        FNetBtBluetoothDevice.h
 * @brief       This is the header file for the %BluetoothDevice class.
 *
 * This header file contains the declarations of the %BluetoothDevice class.
 */
#ifndef FNET_BT_BLUETOOTHDEVICE_H
#define FNET_BT_BLUETOOTHDEVICE_H

#include "FNetConfig.h"
#include "FNetBtBluetoothTypes.h"
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseByteBuffer.h"
#include "FBaseString.h"

namespace Osp { namespace Base { namespace Collection {
class IList;
}}}

namespace Osp {
    namespace Net {
        namespace Bluetooth {

class __BluetoothDeviceEx;


/**
 * @class   BluetoothDevice
 * @brief   This class provides the information about a remote %Bluetooth device.
 * @since   1.0
 *
 * The %BluetoothDevice class provides the information about a remote %Bluetooth device.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ BluetoothDevice: public Base::Object {

public:
    /**
     * This is the default constructor for this class.
     *
     * @deprecated  This default constructor is deprecated because most of the information is generated internally.
     *              Therefore, creating a %BluetoothDevice instance without any information is not recommended.
     * @since       1.0
     */
    BluetoothDevice(void);

    /**
     * Initializes this instance of %BluetoothDevice with the specified parameters.
     *
     * @since       1.0
     *
     * @param[in]   address                 The %Bluetooth device address
     * @param[in]   deviceName              The name of the device
     * @param[in]   majorClassType          The major class type of the %Bluetooth device
     * @param[in]   minorClassType          The minor class type of the %Bluetooth device
     * @param[in]   serviceClassList        The service class type list
     * @param[in]   serviceList             The service type list
     * @remarks     The @c serviceClassList parameter consists of Osp::Net::Bluetooth::BluetoothServiceClassType values
     *              which are joined by the logical OR operator. @n
     *              The @c serviceList parameter consists of Osp::Net::Bluetooth::BluetoothServiceType values which are
     *              joined by the logical OR operator.
     */
    BluetoothDevice(const Osp::Base::ByteBuffer& address, const Osp::Base::String& deviceName, BluetoothMajorDeviceClassType majorClassType,
                    BluetoothMinorDeviceClassType minorClassType, unsigned long serviceClassList, unsigned long serviceList );

    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    ~BluetoothDevice(void);
 
    /**
     * Gets the address of the %Bluetooth device.
     *
     * @since       1.0
     *
     * @return      The address of the %Bluetooth device
     */
    const Osp::Base::ByteBuffer* GetAddress( void ) const;

    /**
     * Gets the %Bluetooth device name.
     *
     * @since       1.0
     *
     * @return      The %Bluetooth device name
     */
    Osp::Base::String GetName(void) const;

    /**
     * Gets the major device class.
     *
     * @since       1.0
     *
     * @return      The major device class
     */
    BluetoothMajorDeviceClassType GetMajorDeviceClassType(void) const;

    /**
     * Gets the minor device class.
     *
     * @since       1.0
     *
     * @return      The minor device class
     */
    BluetoothMinorDeviceClassType GetMinorDeviceClassType(void) const;

    /**
     * Gets the service class of the %Bluetooth device. @n
     * This service class list consists of Osp::Net::Bluetooth::BluetoothServiceClassType values, which are joined by
     * the logical OR operator.
     *
     * @since       1.0
     *
     * @return      The service class of the device
     * @remarks     This operation is not supported in the local device acquired by BluetoothManager::GetLocalDevice().
     */
    unsigned long GetServiceClassList(void) const;

    /**
     * Gets the %Bluetooth device service list. @n
     * This service list consists of Osp::Net::Bluetooth::BluetoothServiceType values, which are joined by the logical
     * OR operator.
     *
     * @since       1.0
     *
     * @return      The %Bluetooth device service list
     * @remarks     This operation is not supported in the local device acquired by BluetoothManager::GetLocalDevice().
     */
    unsigned long GetServiceList(void) const;

    /**
     * Compares the calling instance with the specified instance.
     *
     * @since       1.0
     * @return      @c true if both the instances are equal, @n
     *              else @c false
     * @param[in]   obj                    The object to compare
     */
    virtual bool Equals(const Osp::Base::Object& obj) const;
    
    /**
     * Gets the hash value of the current instance.
     *
     * @since       1.0
     *
     * @return      The hash value of the current instance
     * @remarks     Two equal instances return the same hash value.
     */
    virtual int GetHashCode(void) const;

// Static Member Functions
public:
    /**
     * Gets a new instance of %BluetoothDevice generated using the result of the %Bluetooth AppControl.
     *
     * @since       1.2
     * @return      The %Bluetooth device containing the specified information extracted from the input data if
     *              successful, @n
     *              else @c null
     * @param[in]   appControlResult        The data list, which is the result of the %Bluetooth AppControl
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_ARG           The specified @c appControlResult contains an invalid value. @n
     *                                      The result of %Bluetooth AppControl is only permitted to be used as an
     *                                      input argument.
     * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_bluetooth.htm">Bluetooth
     *              AppControl</a>.
     */
    static BluetoothDevice* GetInstanceFromAppControlResultN(const Osp::Base::Collection::IList& appControlResult);

private:
    BluetoothDevice(const BluetoothDevice& value);
    BluetoothDevice& operator =(const BluetoothDevice& value);

    Osp::Base::ByteBuffer                   __deviceAddress;
    Osp::Base::String                       __deviceName;
    BluetoothMajorDeviceClassType           __majorClassType;
    BluetoothMinorDeviceClassType           __minorClassType;
    unsigned long                           __serviceClassList;
    unsigned long                           __serviceList;
    __BluetoothDeviceEx*                    __pBluetoothDeviceEx;

    friend class __BluetoothDeviceEx;

};
        }
    }
}
#endif // FNET_BT_BLUETOOTHDEVICE_H
