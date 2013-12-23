/* $Change: 826527 $ */
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
 * @file	FNetILocalDhcpServerEventListener.h 
 * @brief	This is the header file for the ILocalDhcpServerEventListener interface.
 *
 * This is the header file for the %ILocalDhcpServerEventListener interface.
 *
 */
#ifndef _FNET_ILOCALDHCPSERVER_EVENT_LISTENER_H_
#define _FNET_ILOCALDHCPSERVER_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"


namespace Osp { namespace Net {
class LocalDhcpServer;
class DhcpClientInfo;
/**
 * @interface	ILocalDhcpServerEventListener
 * @brief		This interface defines the listeners for the local DHCP server events.
 * @since		2.0
 *
 * 		The %ILocalDhcpServerEventListener interface provides the methods for creating notifications about the different kinds of DHCP server events. 
 *				These events are only sent out when %ILocalDhcpServerEventListener is added to a LocalDhcpServer instance, by invoking the 
 *				SetLocalDhcpServerEventListener() method. When a LocalDhcpServer event is generated, one of these methods is called. The methods of this 
 *				interface may be overridden and used in any application that uses the local DHCP server.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 *
 * @see	Osp::Net::DhcpClientInfo
 */
class _EXPORT_NET_ ILocalDhcpServerEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/** This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ILocalDhcpServerEventListener(void) {}


// Operation
public:
	/**
	 * Called to notify the application that the client network connection on the local DHCP server has been connected.
	 *
	 * @since 		2.0
	 * @param[in]	localDhcpServer		The requested local DHCP server
	 * @param[in]	dhcpClientInfo		The connected client information on the local DHCP server event
	 * @see			Osp::Net::DhcpClientInfo
	 */
	virtual void OnDhcpClientConnectedN(LocalDhcpServer& localDhcpServer, DhcpClientInfo& dhcpClientInfo) = 0;

	/**
	 * Called to notify the application that the client network connection on the local DHCP server has been disconnected.
	 *
	 * @since 		2.0
	 * @param[in]	localDhcpServer		The requested local DHCP server
	 * @param[in]	dhcpClientInfo		The disconnected client information on the local DHCP server event
	 * @see			Osp::Net::DhcpClientInfo
	 */
	virtual void OnDhcpClientDisconnectedN(LocalDhcpServer& localDhcpServer, DhcpClientInfo& dhcpClientInfo) = 0;

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
	virtual void OnDhcpServer_Reserved1(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnDhcpServer_Reserved2(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnDhcpServer_Reserved3(void) {}
};

}; }; // Osp::Net

#endif // _FNET_ILOCALDHCPSERVER_EVENT_LISTENER_H_

