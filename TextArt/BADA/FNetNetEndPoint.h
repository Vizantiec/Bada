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
 * @file		FNetNetEndPoint.h 
 * @brief		This is the header file for the %NetEndPoint class.
 *
 * This header file contains the declarations of the %NetEndPoint class.
 */
#ifndef _FNET_NET_END_POINT_H_
#define _FNET_NET_END_POINT_H_

// Includes
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FNetIPAddress.h"
#include "FNetSockSocketTypes.h"


namespace Osp { namespace Net {
// Forward declaration
namespace Sockets {
	class Socket;
	class SecureSocket;
	class IpMulticastRequestOption;
};

/**
 * @class	NetEndPoint 
 * @brief	This class identifies the network address.
 * @since	1.0
 *
 * 	The %NetEndPoint class provides a base class that represents the network address of a resource or service.
 *
 */
class _EXPORT_NET_ NetEndPoint :
	public Osp::Base::Object
{
// Lifecycle
public:

	/**
	 * Initializes this instance of %NetEndPoint with the specified address and port number.
	 *
	 * @since 		1.0
	 * @param[in] 	ipAddress 		The IP address of the target endpoint
	 * @param[in] 	port			The port number
	 * @exception 	E_SUCCESS 		The instance is initialized successfully. 
	 * @exception 	E_INVALID_ARG 	A specified input parameter is invalid.
	 * @remarks 	  	The GetLastResult() method is used to check whether the %NetEndPoint instance is created successfully. 
	 */
	NetEndPoint(const IpAddress& ipAddress, unsigned short port);

	/**
	 * Initializes this instance of %NetEndPoint with the specified %NetEndPoint instance.
	 *
	 * @since 		1.0
	 * @param[in] 	netEndPoint		A %NetEndPoint instance to initialize the calling instance 
	 * @exception 	E_SUCCESS 		The instance is initialized successfully.
	 * @exception 	E_INVALID_ARG 	The specified input parameter is invalid.
	 * @remarks 	  	The GetLastResult() method is used to check whether the %NetEndPoint instance is created successfully. 
	 */
	NetEndPoint(const NetEndPoint& netEndPoint);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	virtual ~NetEndPoint(void);


// Inquery
public:
	/** 
	 * Gets the address family to which the calling %NetEndPoint instance belongs.
	 *
	 * @since 		1.0
	 * @return		The address family of the calling instance
	 * @exception	E_SUCCESS			The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state @b since: @b 1.1.
	 */
	NetAddressFamily  GetNetAddressFamily(void) const;

	/** 
	 * Gets the port number of the endpoint.
	 *
	 * @since 		1.0
	 * @return		The port number of the endpoint
	 * @exception	E_SUCCESS			The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state @b since: @b 1.1.
	 */
	unsigned short GetPort(void) const;

	/** 
	 * Gets the IP address of the calling instance.
	 *
	 * @since 		1.0
	 * @return		The IP address of the endpoint, @n
	 *				else @c null if the address info is invalid 
	 * @exception	E_SUCCESS			The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state @b since: @b 1.1.
	 */
	IpAddress* GetAddress(void) const;

	/**
	 * Gets the current endpoint.
	 *
	 * @since 		1.0
	 * @return		The current endpoint, @n
	 *				else @c null string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The string output of this method is formatted as follows: IPADDRESS:PORT. @n
	 *				IPADDRESS is a string representing a number expressed in the Internet Standard "." (dotted) notation (for example, 165.213.173.7). @n
	 *				PORT is a string representing a port number in host byte order. For example, 165.213.173.7:2000 is a possible string. @n
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	 Osp::Base::String GetNetEndPoint(void) const;

	
// Query
public:
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 *
	 * Checks the current status of NetEndPoint - whether IpAddress and port info is valid or not.
	 *
	 * @since 		1.0
	 * @return		@c true if valid IpAddress and valid port number is inserted and the construction is complete @n
	 *						@c false, otherwise
	 */
	bool IsValid(void);

// Lifecycle
private:
	/**
	 * Initializes this instance of NetEndPoint with the specified host and port number.
	 *
	 * @param[in]	host			The host address of the target endpoint
	 * @param[in]	port			The port number
	 * @exception	E_SUCCESS 		The instance is initialized successfully. 
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remark		The GetLastResult() method is used to check whether the %NetEndPoint instance is created successfully. 
	 */
	NetEndPoint(const Osp::Base::String& host, unsigned short port = 0);

// Inquery
private:
	/** 
	 * Gets the host address of the calling instance.
	 *
	 * @return		The host address of the endpoint, @n
	 *				else @c null if the host address information is invalid or an error occurs
	 * @exception	E_SUCCESS 			The instance is initialized successfully. 
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remark		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String* GetHost(void) const;


// Operation
private :
	/* 
	 * Changes IpAddress and port of Constructed NetEndPoint - INTERNAL USE ONLY!
	 *
	 * @return		An error code
	 * @remark		@c true is returned only if valid IpAddress & valid port number is inserted & construction 
	 *				is complete.
	 */
	 result Set(IpAddress& addr, unsigned short port);


// Attribute
private :
	IpAddress* __pIpAddress;
	unsigned short __port;
	bool __isValid;	// construction success & valid IP address - port allocation succeeded. __isConstructed is absorbed to this variable


// Friend class declaration 
	friend class NetAccountInfo;
	friend class NetAccountManager;
	friend class Osp::Net::Sockets::Socket;
	friend class Osp::Net::Sockets::SecureSocket;
	friend class Osp::Net::Sockets::IpMulticastRequestOption;

	friend class NetEndPointEx;
	class NetEndPointEx* __pNetEndPointEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_END_POINT_H_

