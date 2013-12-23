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
 * @file		FNetNetConnectionInfo.h 
 * @brief		This is the header file for the %NetConnectionInfo class.
 *
 * This header file contains the declarations of the %NetConnectionInfo class.
 */
#ifndef _FNET_NET_CONNECTION_INFO_H_
#define _FNET_NET_CONNECTION_INFO_H_

// Includes
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetNetTypes.h"
#include "FNetIPAddress.h"


namespace Osp { namespace Net {
/**
 * @class	NetConnectionInfo 
 * @brief	This class represents a base type for the information related to a network connection.
 * @since	1.0
 *
 *
 * 	The %NetConnectionInfo class provides the methods to obtain information related to a network connection. %NetConnectionInfo is valid when 
 *			NetConnection is not in the "NET_CONNECTION_STATE_STOPPED" state.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 */
class _EXPORT_NET_ NetConnectionInfo :
	public Osp::Base::Object
{
// Lifecycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	NetConnectionInfo(void);


	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~NetConnectionInfo(void);



// Accessor
public:
	/** 
	 * Gets the operating bearer type of a mobile station.
	 *
	 * @since		1.0
	 * @return		The operating bearer type of a specific network connection, @n
	 *				else @c NET_BEARER_NONE if this instance is invalid
	 */
	 NetBearerType GetBearerType(void) const ;


	/** 
	 * Gets the operation protocol of a mobile station.
	 *
	 * @since		1.0
	 * @return		The protocol type of a specific network connection, @n
	 *				else @c NET_PROTO_TYPE_NONE	if this instance is invalid
	 */
	 NetProtocolType GetProtocolType(void) const ;


	/** 
	 * Gets the Access Point Name.
	 *
	 * @since		1.0
	 * @return		The Access Point Name as a string, @n
	 *				else a null string if the Access Point Name is empty or this instance is invalid
	 */
	Osp::Base::String GetAccessPointName(void) const;


	/** 
	 * Gets the local address scheme.
	 *
	 * @since		1.0
	 * @return		The address scheme for the local address, @n
	 *				else @c NET_ADDRESS_SCHEME_NONE if this instance is invalid
	 */
	NetAddressScheme GetLocalAddressScheme(void) const;

	/** 
	 * Gets the local address information.
	 *
	 * @since		1.0
	 * @return		An %IpAddress pointer to the local address in the calling instance
	 * @remarks		If GetLocalAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If GetLocalAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the %IpAddress pointer is @c null or not.
	 */
	const IpAddress*  GetLocalAddress(void) const;


	/** 
	 * Gets the setting for the DNS address scheme.
	 *
	 * @since		1.0
	 * @return		The address scheme for the DNS address, @n
	 *				else @c NET_ADDRESS_SCHEME_NONE if this instance is invalid
	 *
	 */
	NetAddressScheme  GetDnsAddressScheme(void) const;

	/** 
	 * Gets the primary DNS address.
	 *
	 * @since		1.0
	 * @return		An %IpAddress pointer to the primary DNS Address of the network connection  
	 * @remarks		If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the %IpAddress pointer is @c null or not, because the DNS address field is not mandatory.
	 */
	const IpAddress* GetPrimaryDnsAddress(void) const;

	
	/** 
	 * Gets the secondary DNS address.
	 *
	 * @since		1.0
	 * @return		An %IpAddress pointer to the secondary DNS Address of the network connection 
	 * @remarks		If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_STATIC, this method returns the statically assigned local addresses. @n
	 *				If GetDnsAddressScheme() is NET_ADDRESS_SCHEME_DYNAMIC, this method returns the dynamically assigned local addresses. @n
	 *				In any case, check whether the %IpAddress pointer is @c null or not, because the DNS address field is not mandatory.
	 */
	const IpAddress* GetSecondaryDnsAddress(void) const;


	/** 
	 * Gets the subnet mask address.
	 *
	 * @since 		2.0
	 * @return		A pointer to the %IpAddress instance representing the subnet mask address of the network connection 
	 * @remarks   	In any case, check whether the %IpAddress pointer is @c null or not, because the subnet mask address field is not mandatory.
	 */
	const IpAddress* GetSubnetMaskAddress(void) const;
	
	/** 
	 * Gets the default gateway address.
	 *
	 * @since		2.0
	 * @return     	A pointer to the %IpAddress instance representing the default gateway address of the network connection
	 * @remarks    	In any case, check whether the %IpAddress pointer is @c null or not, because the gateway address field is not mandatory.
	 */
	const IpAddress* GetDefaultGatewayAddress(void) const;

private: 
//lifecycle
	bool __isValid;  //connection information is retrieved from NetConnection 

//information buffer
	NetBearerType __opMode;
	NetProtocolType __protocolType;
	
	//Access Point Name
	Osp::Base::String __apn;

	//Local&DNS Address
	NetAddressScheme __localAddrScheme;
	NetAddressScheme __dnsAddrScheme;

	IpAddress* __pLocalAddress;
	IpAddress* __pPrimaryDnsAddress;
	IpAddress* __pSecondaryDnsAddress;

// Friend class declaration
	friend class NetConnectionManager;
	friend class NetConnection;
	friend class ManagedNetConnection;
	friend class _DefaultNetConnection;
	friend class __NetConnectionEvent;

	friend class NetConnectionInfoEx;
	class NetConnectionInfoEx* __pNetConnectionInfoEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_CONNECTION_INFORMATION_H_
