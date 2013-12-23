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
 * @file        FNetBluetooth.h
 * @brief       This is the header file for the %Bluetooth namespace.
 *
 * This header file contains the declarations and descriptions of the %Osp::Net::Bluetooth namespace.
 */
#ifndef _FNET_BLUETOOTH_H_
#define _FNET_BLUETOOTH_H_

#include "FNetBtBluetoothTypes.h"
#include "FNetBtBluetoothDevice.h"
#include "FNetBtBluetoothManager.h"
#include "FNetBtIBluetoothDeviceEventListener.h"
#include "FNetBtIBluetoothManagerEventListener.h"
#include "FNetBtBluetoothOppServer.h"
#include "FNetBtIBluetoothOppServerEventListener.h"
#include "FNetBtBluetoothOppClient.h"
#include "FNetBtIBluetoothOppClientEventListener.h"
#include "FNetBtBluetoothSppAcceptor.h"
#include "FNetBtIBluetoothSppAcceptorEventListener.h"
#include "FNetBtBluetoothSppInitiator.h"
#include "FNetBtIBluetoothSppInitiatorEventListener.h"

namespace Osp { namespace Net {
/**
 * @namespace   Osp::Net::Bluetooth
 * @brief       This namespace contains the classes and interfaces for %Bluetooth services.
 * @since       1.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *              @b Library : @b FOsp @n
 *
 * The %Bluetooth namespace contains the classes and interfaces for %Bluetooth services that provide the mechanisms for
 * peer-to-peer communication involving connecting, sending, and receiving data over a %Bluetooth connection. It
 * consists of the submodules that support different profiles such as GAP, OPP, and SPP.
 *
 * For more information on the %Bluetooth namespace features, see
 * <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/bluetooth_namespace.htm">Bluetooth Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Bluetooth namespace.
 * @image html net_bluetooth_using_the_apis_classdiagram.png
 *
 */
namespace Bluetooth
{
}; }; }; // Osp::Net::Bluetooth
#endif // _FNET_BLUETOOTH_H_

