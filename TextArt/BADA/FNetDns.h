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
 * @file		FNetDns.h 
 * @brief		This is the header file for the %Dns class.
 *
 * This header file contains the declarations of the %Dns class.
 */
#ifndef _FNET_DNS_REQUEST_H_
#define _FNET_DNS_REQUEST_H_

// Includes
#include "FNetConfig.h"
#include "FBaseResult.h"
#include "FNetIPAddress.h"
#include "FNetIPHostEntry.h"
#include "FNetNetConnection.h"
#include "FNetIDnsEventListener.h"


namespace Osp { namespace Net {
// Forward declaration
class _DefaultNetConnection;
class __DnsDefaultNetConnectionListener;
class IDnsPi;
class __DnsEvent;

/**
 * @class	Dns 
 * @brief	This class provides a way to access the resolver of the Domain Name System (DNS).
 * @since	1.0
 *
 * The %Dns class represents a request for information from a DNS server. A DNS request can be one of two types, represented by the GetHostByAddress() 
 *			and GetHostByName() methods. The GetHostByAddress() method represents a request for the DNS information about a host, while the GetHostByName() 
 *			method represents a request for the DNS host information for an IP address. Both requests can be made in an asynchronous mode.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/domain_name_system_access.htm">Domain Name System Access</a>.
 */
class _EXPORT_NET_ Dns :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 * 
	 * @since		1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	Dns(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~Dns(void);

	/**
	 * Initializes this instance of %Dns with the specified parameters.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	netConnection			A NetConnection on which the DNS request executes
	 * @param[in]	listener				A reference to %IDnsEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_INVALID_ARG			The specified @c netConnection contains an invalid value.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 */
	result Construct(const NetConnection& netConnection, const IDnsEventListener& listener);

	/**
	 * Initializes this instance of %Dns with the specified listener.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	listener				A reference to %IDnsEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 */
	result Construct(const IDnsEventListener& listener);

// Operation
public:
	/** 
	 * Requests a DNS lookup by host name. @n 
	 * This method is asynchronous.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	hostName				The DNS name of the host
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_OPERATION_FAILED		Requested but an error is received while waiting for the response.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @remarks		Only one query is processed at a time in this instance.
     * 				Multiple queries may be discarded.
	 */
	result GetHostByName(const Osp::Base::String& hostName);

	/**
	 * Requests a DNS lookup by IP address. @n
	 * This method is asynchronous.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	ipAddress				An IP address
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_OPERATION_FAILED		Requested but an error is received while waiting for the response.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @remarks		Only one query is processed at a time in this instance.
     * 				Multiple queries may be discarded.
	 */
	result GetHostByAddress(const IpAddress& ipAddress);


// Attribute
private:
	Osp::Net::NetConnection* __pNetConnection;
	IDnsPi* __pDnsInterface;

	Osp::Net::_DefaultNetConnection* __pDefaultNetConnection;
	Osp::Net::__DnsDefaultNetConnectionListener* __pDefaultNetConnectionListener;

	__DnsEvent* __pDnsEvent;

	bool __isConstructed;

	friend class DnsEx;
	class DnsEx* __pDnsEx;
};

}; }; // Osp::Net

#endif // _FNET_DNS_REQUEST_H_

