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
 * @file		FNetIP4Address.h 
 * @brief		This is the header file for the %Ip4Address class. 
 * @since		1.0
 *
 * This header file contains the declarations of the %Ip4Address class.
 */
#ifndef _FNET_IP4_ADDRESS_H_
#define _FNET_IP4_ADDRESS_H_

 
// Includes
#include "FBaseResult.h"
#include "FNetIPAddress.h"
#include "FNetSockSocketTypes.h"

namespace Osp { namespace Net {
/**
 * @class	Ip4Address 
 * @brief	This class represents an Internet Protocol version 4 (IPv4) address.
 * @since	1.0
 *
 * 	The %Ip4Address class specifies the IPv4 address. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/net_namespace.htm">Net Guide</a>. @n
 *
 * The following example demonstrates how to use the %Ip4Address class.
 *
 * @code
 *	using namespace Osp::Base;
 *	using namespace Osp::Net;
 * 
 *	result
 *	MyClass::SomeMethod(void)
 *	{
 *		// Return code.
 * 		result r = E_SUCCESS;
 * 	
 *		Osp::Base::String ip4String(L"192.168.0.1");
 *		Ip4Address* pIp4Address = new Ip4Address(ip4String);
 *	
 *		// Gets the raw IP address.
 *		int sizeOfIp4Address = 4;
 *		ByteBuffer bb;
 *		r = bb.Construct(sizeOfIp4Address);
 *		r = pIp4Address->GetAddress(bb);
 *
 *		// Success
 * 		return (r);
 * 	}
 * @endcode
 */
class _EXPORT_NET_ Ip4Address :
	public IpAddress
{
private:
	/**
	 * This is the default constructor for this class.
	 *	 
	 * @remarks	Declared as private to hide from user access. The overridden constructor should be used.
	 */
	Ip4Address(void);


// Lifecycle
public:
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 *  
	 *	Initializes a new Ip4Address instance with the address specified as a ByteBuffer.
	 * 
	 * @since			1.0 
	 * @param[in]	ipAddr			The raw IP address as a ByteBuffer
	 * @exception E_SUCCESS			The instance is created successfully.
	 * @exception E_UNDERFLOW		The specified ByteBuffer is insufficient to contain an IP4 address.
	 *
	 * @remarks 	  The GetLastResult() method is used to check whether the Ip4Address instance is created successfully. 
	 */
	Ip4Address(const Osp::Base::ByteBuffer& ipAddr);

	/**
	 * Initializes this instance of %Ip4Address with the address specified as a string.
	 *
	 * @since		1.0 
	 * @param[in]	ipAddr			The IP Address as a string @n 
	 *								This string represents the IP address in dot-decimal notation (for example, 165.213.173.7)  .
	 * @exception	E_SUCCESS		The instance is created successfully.
	 * @exception	E_INVALID_ARG	The specified @c ipAddr is invalid.
	 *
	 * @remarks 		The GetLastResult() method is used to check whether the %Ip4Address instance is created successfully. 
	 */
	Ip4Address(const Osp::Base::String& ipAddr);

	/** 
	 * Initializes this instance of %Ip4Address with the specified %Ip4Address object.
	 *
	 * @since		1.0 
	 * @param[in]	ipAddr			An %Ip4Address instance 
	 */	
	Ip4Address(const Ip4Address& ipAddr);

	/**
	 * Initializes this instance of %Ip4Address with the address specified as an integer.
	 *
	 * @since		1.0 
	 * @param[in]	ipAddr			A unsigned @c long number containing the raw IP address @n
	 *								This is a 32-bit unsigned number. It should be in host byte order.
	 * @exception	E_SUCCESS		The instance is created successfully. 	
	 * @exception	E_INVALID_ARG	The specified @c ipAddr is invalid.
	 * @remarks		The GetLastResult() method is used to check whether the %Ip4Address instance is created successfully. 
	 * @see			IpAddress::NetworkToHostOrder(), IpAddress::HostToNetworkOrder()
	 */
	Ip4Address(unsigned long ipAddr);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0 
	 */
	virtual ~Ip4Address(void);


// Accessor
public:
	/** 
	 * Gets the address family to which the %Ip4Address belongs.
	 *
	 * @since		1.0 
	 * @return		NET_AF_IPV4
	 */
	NetAddressFamily GetNetAddressFamily(void) const;

	/** 
	 * Gets the raw IP address.
	 *
	 * @since		1.0 
	 * @return		An error code
	 * @param[out]	ipAddr			A ByteBuffer object containing the raw IP address
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OVERFLOW		The length of the remaining bytes of @c ipAddr is less than @c 4.
	 * @remarks		This method returns the raw IP address of the %Ip4Address object. The result is in host byte order. This method writes the raw address 
	 *				in the buffer parameter, starting from the current position. After the operation, the position of the buffer is incremented by the number 
	 *				of bytes successfully written even if the operation fails. The new position cannot be larger than the original limit.	
	 */
	 result GetAddress(Osp::Base::ByteBuffer& ipAddr) const;

	/** 
	 * Gets the IP address of the endpoint in textual presentation. @n
	 * An endpoint consists of an IP address and a port.
	 *
	 * @since		1.0 
	 * @return		The %Ip4Address, @n
	 *				else a null string if the address is not set
	 * @remarks		%Ip4Address is in the standard dot-decimal notation.
	 */
	 Osp::Base::String ToString(void) const;

	/** 
	 * Gets the raw IP address as an integer. @n
	 * The result is in host byte order.
	 *
	 * @since		1.0 
	 * @return		An error code
	 * @param[out]	ipAddr				An unsigned @c long integer containing the raw IP address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 * @see			IpAddress::NetworkToHostOrder(), IpAddress::HostToNetworkOrder()
	 */
	 result GetAddress(unsigned long& ipAddr) const;

// Inquiry
public:
	/**
	* @internal
	* This is internal. If used in an application, the application can get rejected during the certification process.
	*
	* This query interface returns current status of Ip4Address instance 
	* whether valid IP Address is allocated
	*
	* @since			1.0
	* @return			@c true if the IP Address is valid, @n
	*					else @c false
	*/
	bool  IsValid(void);


// Utility 	
private :
	result __InetNtoa(unsigned long ipAddress, Osp::Base::String& ipAddrStringFormat);
	result __InetAton(unsigned long& ipAddress, Osp::Base::String& ipAddrStringFormat);
	const Object* Clone(void);


// Operation
private:
	/*
	* @Internal
	* This assignment operator copies the address contained in the specified instance of Ip4Address
	* to this instance of Ip4Address.
	*
	* @param[in]	rhs A reference to another Ip4Address instance
	*/
	void  operator=(Ip4Address& ip4Address);


// Attribute
private:
	unsigned long __address; // IPv4 address in host byte order.

	Osp::Base::String __addressInTextualFormat;

	bool __isValid;


// Friend class declaration.
	friend class NetAccountInfo;
	friend class NetConnectionInfo;
	friend class NetEndPoint;
	friend class NetConnection;
	friend class _DefaultNetConnection;
	friend class ManagedNetConnection;
	friend class NetConnectionManager;
	friend class NetAccountManager;
	friend class __LocalDhcpServerImpl;

	friend class Ip4AddressEx;
	class Ip4AddressEx* __pIp4AddressEx;
};

}; }; // Osp::Net

#endif // _FNET_IP4_ADDRESS_H_

