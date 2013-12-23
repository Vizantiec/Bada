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
 * @file		FNet.h 
 * @brief		This is the header file for the %Net namespace.
 *
 * This header file contains the declarations and descriptions of the %Net namespace.
 */

#ifndef _FNET_H_
#define _FNET_H_

#include "FNetNetTypes.h"

#include "FNetNetAccountManager.h"
#include "FNetNetAccountInfo.h"
#include "FNetNetConnectionManager.h"
#include "FNetNetConnection.h"
#include "FNetINetConnectionEventListener.h"
#include "FNetManagedNetConnection.h"
#include "FNetIManagedNetConnectionEventListener.h"
#include "FNetNetConnectionInfo.h"
#include "FNetNetStatistics.h"
#include "FNetNetFastDormancy.h"

#include "FNetIP4Address.h"
#include "FNetIPAddress.h"
#include "FNetNetEndPoint.h"

#include "FNetDns.h"
#include "FNetIDnsEventListener.h"
#include "FNetIPHostEntry.h"

#include "FNetLocalDhcpServer.h"
#include "FNetILocalDhcpServerEventListener.h"
#include "FNetDhcpClientInfo.h"

#include "FNetSockets.h"
#include "FNetHttp.h"
#include "FNetBluetooth.h"
#include "FNetWifi.h"
#include "FNetNfc.h"

namespace Osp {
/**
 * @namespace	Osp::Net
 * @brief		This namespace contains the classes and interfaces for network account, connection, and addressing utilities.
 * @since 		1.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *				@b Library : @b FOsp @n
 *
 * 				The %Net namespace contains the different classes for the %Net namespace. @n
 *
 * 				This namespace helps to access the data communication capabilities of bada. It is responsible for managing connections and 
 *				accounts, and maintaining IP addresses and connections to the system through Bluetooth, Hypertext Transfer Protocol (HTTP), Near Field 
 *				Communication (NFC), Sockets, and Wi-Fi. It also provides methods for retrieving information about a specific host from the Internet Domain 
 *				Name System (DNS).
 * 
 * For more information on the %Net namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/net_namespace.htm">Net Guide</a>.
 
 * The following diagram illustrates the relationships between the classes belonging to the %Net namespace.
 * @image html net_using_the_apis_classdiagram.png 
 * 
 *
 */
namespace Net
{
}; }; // Osp::Net
#endif // _FNET_H_

