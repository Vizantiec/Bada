//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All right reserved.
//
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file	FNetIManagedNetConnectionEventListener.h 
 * @brief	This is the header file for the %IManagedNetConnectionEventListener interface.
 *
 * This header file contains the declarations of the %IManagedNetConnectionEventListener interface.
 *
 */
#ifndef _FNET_IMANAGED_NETCONNECTION_EVENTLISTENER_H_
#define _FNET_IMANAGED_NETCONNECTION_EVENTLISTENER_H_


// Includes
#include "FBase.h"

namespace Osp { namespace Net {
class ManagedNetConnection;
/**
 * @interface	IManagedNetConnectionEventListener
 * @brief		This interface is the listener for network connection events.
 * @since		2.0
 *
 * 	The %IManagedNetConnectionEventListener interface specifies the methods used to create the notifications about the different kinds of network 
 *	connection events. These events are sent only when %IManagedNetConnectionEventListener is added to the ManagedNetConnection instance, and 
 *	this is done by invoking the SetManagedNetConnectionEventListener() method. A method of this interface is called when a network connection 
 *	event is generated.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/managing_network_connections.htm">Managing Network Connections</a>. @n
 */
class _EXPORT_NET_ IManagedNetConnectionEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
   /** This is the virtual destructor for this class.
	*
	* @since	2.0
	*/
	virtual ~IManagedNetConnectionEventListener(void) {}

// Operation
public:
	/**
	 * Called to notify that the bearer has been changed. @n
	 * An application can send or receive the data through the Socket or HTTP methods and can obtain the information related to the changed bearer.
	 *
	 * @since		2.0
	 * @param[in]	managedNetConnection	The network connection managed by the system
	 */
	virtual void OnManagedNetConnectionBearerChanged(ManagedNetConnection& managedNetConnection) = 0;

	/**
	 * Called to notify the application that the network connection has been opened and connected. @n
	 * An application can then send or receive the data.
	 *
	 * @since			2.0
	 * @param[in]	managedNetConnection	The network connection managed by the system
	 */
	virtual void OnManagedNetConnectionStarted(ManagedNetConnection& managedNetConnection) = 0;

	/**
	 * Called to notify that the network connection has been closed and disconnected. 
	 *
	 * @since		2.0
	 * @param[in]	managedNetConnection								The network connection managed by the system
	 * @param[in]	reason												A reason code for the error 
	 * @exception	NET_CONNECTION_STOPPED_REASON_RESOURCE_RELEASED		The network connection managed by the system has stopped because network resources have been released.
	 * @exception	NET_CONNECTION_STOPPED_REASON_NETWORK_FAILED		The network has failed.
	 * @exception	NET_CONNECTION_STOPPED_REASON_DEVICE_OFFLINE		The device is in the offline mode.
	 * @exception	NET_CONNECTION_STOPPED_REASON_SERVICE_UNAVAILABLE	The device is out of the coverage area or in an emergency mode.	 
	 * @exception	NET_CONNECTION_STOPPED_REASON_RESOURCE_UNAVAILABLE	The network resource is unavailable.
	 * @exception	NET_CONNECTION_STOPPED_REASON_SYSTEM				A system error has occurred.
	 *
	 */
	virtual void OnManagedNetConnectionStopped(ManagedNetConnection& managedNetConnection, NetConnectionStoppedReason reason) = 0;

	/**
	 * Called to notify the application that the connection status has been changed or is in an unstable or suspended state. @n
	 * Thus an application may neither send nor receive data through the Socket or Http until the network connection is resumed.
	 *
	 * @since		2.0
	 * @param[in]	managedNetConnection	The network connection managed by the system
	 */
	virtual void OnManagedNetConnectionSuspended(ManagedNetConnection& managedNetConnection) = 0;

	/**
	 * Called to notify the application that the network has recovered from a suspended state. @n
	 * Thus an application can send or receive data through the Socket or Http from now on.  
	 *
	 * @since		2.0
	 * @param[in]	managedNetConnection	The network connection managed by the system
	 */
	virtual void OnManagedNetConnectionResumed(ManagedNetConnection& managedNetConnection) = 0;

protected:
	// Reserved virtual methods for later extension.
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnManagedNetConnection_Reserved1(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnManagedNetConnection_Reserved2(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnManagedNetConnection_Reserved3(void) {}
};

}; }; // Osp::Net
#endif // _FNET_IMANAGED_NETCONNECTION_EVENTLISTENER_H_

