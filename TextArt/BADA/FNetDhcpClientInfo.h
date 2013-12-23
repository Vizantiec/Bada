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
 * @file	FNetDhcpClientInfo.h 
 * @brief	This is the header file for the %DhcpClientInfo class.
 *
 * This header file contains the declarations of the %DhcpClientInfo class.
 */
#ifndef _FNET_DHCP_CLIENT_INFO_H_
#define _FNET_DHCP_CLIENT_INFO_H_

// Includes
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FNetConfig.h"
#include "FNetIPAddress.h"


namespace Osp { namespace Net {

// Forward declaration
class __LocalDhcpServerImpl;
class __DhcpClientInfoImpl;
class __LocalDhcpServerEvent;

/**
 * @class	DhcpClientInfo 
 * @brief	This class represents a client information on the local Dynamic Host Configuration Protocol (DHCP) server.
 * @since	2.0
 *
 * The %DhcpClientInfo class provides functionality for getting information on the local DHCP server.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 */
class _EXPORT_NET_ DhcpClientInfo :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~DhcpClientInfo(void);

// Accessor
public:
	/** 
	 * Gets the name of the DHCP client device.
	 *
	 * @since		2.0
	 * @return		The name of the DHCP client device, @n
	 *				else a null string if the name is not set or not constructed
	 */
	 Osp::Base::String GetName(void) const;

	/** 
	 * Gets the IP address of the DHCP client device.
	 *
	 * @since		2.0
	 * @return		The IpAddress pointer
	 * @remarks		This method returns a dynamically assigned IP address.
	 */
	const IpAddress* GetIpAddress(void) const;

	/**
	 * Gets the MAC address of the DHCP client device.
	 *
	 * @since		2.0
	 * @return		The MAC address in the form '00-00-00-00-00-00'
	 * @remarks 	In case of the Wi-Fi Direct bearer type, the MAC address is virtual and is used only for the frame packetization.
     * 				This MAC address is different from the MAC address provided by the %WifiManager or the %WifiDirectDevice class.
	 */
	Osp::Base::String GetMacAddress(void) const;

// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 *
	 */
	DhcpClientInfo(void);

	/*
	* This is the copy constructor for the %DhcpClientInfo class.
	*
	* @param[in] 	value	An instance of the %DhcpClientInfo class
	*/
	DhcpClientInfo(const DhcpClientInfo& value);

// Operator
private:
	/*
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs		An instance of the %DhcpClientInfo class
	 * @remarks		The method is declared but not implemented.
	 */
	DhcpClientInfo& operator =(const DhcpClientInfo& rhs);

// Attribute
private: 
	__DhcpClientInfoImpl* __pDhcpClientInfoImpl;
	friend class __LocalDhcpServerImpl;
	friend class __DhcpClientInfoImpl;
	friend class __LocalDhcpServerEvent;
};

}; }; // Osp::Net

#endif // _FNET_DHCP_CLIENT_INFO_H_
