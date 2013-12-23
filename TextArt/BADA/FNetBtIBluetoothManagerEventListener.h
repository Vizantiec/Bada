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
 * @file    FNetBtIBluetoothManagerEventListener.h
 * @brief   This is the header file for the %IBluetoothManagerEventListener interface.
 *
 * This header file contains the declarations of the %IBluetoothManagerEventListener interface.
 */
#ifndef FNET_BT_IBLUETOOTHMANAGEREVENTLISTENER_H
#define FNET_BT_IBLUETOOTHMANAGEREVENTLISTENER_H

#include "FBaseRtIEventListener.h"

namespace Osp { namespace Net { namespace Bluetooth {

/**
 * @interface   IBluetoothManagerEventListener
 * @brief       This interface implements the listener for the %BluetoothManager events.
 * @since       1.0
 *
 * The %IBluetoothManagerEventListener interface specifies the methods used for creating notifications about the
 * different kinds of BluetoothManager events. When a BluetoothManager event is generated, one of these methods is
 * called.
 *
 * For more information on the class features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 */
class _EXPORT_NET_ IBluetoothManagerEventListener : public Base::Runtime::IEventListener {

public:
    /**
     * This is the destructor for this class.
     *
     * @since       1.0
     */
    virtual ~IBluetoothManagerEventListener(void) {}
 
    /**
     * Called when %Bluetooth is activated on the device.
     *
     * @since       1.0
     * @param[in]   r               The activation status
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     */
    virtual void OnBluetoothActivated(result r) = 0;

    /**
     * Called when %Bluetooth is deactivated on the device.
     *
     * @since       1.0
     * @param[in]   r               The deactivation status
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     */
    virtual void OnBluetoothDeactivated(result r) = 0;
};
} } }
#endif // FNET_BT_IBLUETOOTHMANAGEREVENTLISTENER_H
