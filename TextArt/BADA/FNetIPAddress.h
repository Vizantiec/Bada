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
 * @file		FNetIPAddress.h 
 * @brief		This is the header file for the %IpAddress class.
 *
 * This header file contains the declarations of the %IpAddress class.
 */
#ifndef _FNET_IP_ADDRESS_H_
#define _FNET_IP_ADDRESS_H_

// Includes
#include "FBaseObject.h"
#include "FBaseByteBuffer.h"
#include "FBaseString.h"
#include "FBaseResult.h"
#include "FBaseErrors.h"
#include "FNetSockSocketTypes.h"
#include "FNetConfig.h"


namespace Osp { namespace Net {
/**
 * @class	IpAddress 
 * @brief	This abstract class encapsulates an Internet Protocol (IP) address and the methods to manipulate it.
 * @since	1.0
 *
 * 	The %IpAddress class contains the address of a computer on an IP network. Different computers use different conventions for ordering the bytes 
 *			within multi-byte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the 
 *			least-significant byte first (known as little-endian order). To work with the computers that use different byte ordering, all integer values sent 
 *			over the network are sent in network byte order. This class provides methods to change the order. An endpoint includes an IP address 
 *			and a port.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/net_namespace.htm">Net Guide</a>.
 */
class _EXPORT_NET_ IpAddress :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 *
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	IpAddress(void);
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IpAddress(void);

	
// Operation
public:
	/** 
	 * Converts the specified unsigned short address from the host byte order to the network byte order.
	 *
	 * @since		1.0
	 * @return		The address as an unsigned @c short value, in the network @c byte order
	 * @param[in]	host	The IP address to be converted, expressed in host @c byte order
	 *
	 * @see			NetworkToHostOrder()
	 */
	static unsigned short HostToNetworkOrder(unsigned short host);

	/** 
	 * Converts the specified unsigned long address from the host byte order to the network byte order.
	 *
	 * @since		1.0
	 * @return		The address as an unsigned @c long value, in the network @c byte order
	 * @param[in]	host	The IP address to be converted, expressed in host @c byte order
	 *
	 * @see			NetworkToHostOrder()
	 */
	static unsigned long HostToNetworkOrder(unsigned long  host);

	/** 
	 * Converts the specified short integer address from network byte order to host byte order.
	 *
	 * @since		1.0
	 * @return		The address as an unsigned @c short value, in the host @c byte order
	 * @param[in]	network		The IP address to be converted, expressed in the network @c byte order
	 *
	 * @see			HostToNetworkOrder()
	 */
	static unsigned short NetworkToHostOrder(unsigned short network);

	/** 
	 * Converts the specified unsigned long address from the network byte order to the host byte order.
	 *
	 * @since		1.0
	 * @return		The address as an unsigned @c long value, in the host @c byte order
	 * @param[in]	network		The IP address to be converted, expressed in the network @c byte order
	 *
	 * @see				HostToNetworkOrder()
	*/
	static unsigned long NetworkToHostOrder(unsigned long network);


// Accessor
public:
	/** 
	 * Gets the address family to which the %IpAddress belongs.
	 *
	 * @since		1.0
	 * @return		The address family 
	 */
	virtual NetAddressFamily GetNetAddressFamily(void) const = 0;

	/** 
	 * Gets the raw IP address of the endpoint. @n
	 * An endpoint includes an IP address and a port.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	ipAddr				A ByteBuffer object for getting the raw IP address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c ipAddr is invalid.
	 * @exception	E_OVERFLOW			This operation has caused the memory to overflow.
	 * @remarks		The result @c ipAddr is in the host @c byte order. This method writes the raw address into the buffer parameter, starting from the 
	 *				current position of the buffer. After the operation, the position of the buffer is incremented by the number of bytes successfully written
	 *				even if the operation fails. The new position cannot be larger than the original limit.
	 */
	virtual result GetAddress(Osp::Base::ByteBuffer& ipAddr) const = 0;

	/** 
	 * Gets the IP address of the endpoint as a string. @n
	 * An endpoint includes an IP address and a port.
	 * 
	 * @since		1.0
	 * @return		The IP address, @n
	 *				else a null string if the address is not set
	 */
	virtual Osp::Base::String ToString(void) const = 0;


// Friend class declaration.
	friend class Dns;
	friend class NetEndPoint;
	friend class NetAccountInfo;
	friend class NetConnectionInfo;

private :
	virtual const Object* Clone(void) =0;
};

}; }; // Osp::Net

#endif // _FNET_IP_ADDRESS_H_

