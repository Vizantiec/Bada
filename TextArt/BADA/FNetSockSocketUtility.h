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
* @file		FNetSockSocketUtility.h
* @brief	This is the header file for the %SocketUtility class.
*
* This header file contains the declarations of the %SocketUtility class. @n
* This class provides utility methods for socket operations.
*/

#ifndef _FNET_SOCK_SOCKETUTILITY1_H_
#define _FNET_SOCK_SOCKETUTILITY1_H_

#include "FNetConfig.h"
#include "FBaseCol.h"

namespace Osp { namespace Net { namespace Sockets {
	// Forward class
	class ISocketUtilityPi;
	class SocketUtilityEx;
	
	/**
	* @class	SocketUtility
	* @brief	This class provides the utility methods for the Socket class.
	* @since 	1.0
	*
	* The %SocketUtility class provides the utility methods for the Socket class.
	* 
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/sockets.htm">Sockets Guide</a>.
	*/
	class _EXPORT_NET_ SocketUtility :
		public Osp::Base::Object
	{
	// Lifecycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since		1.0
		* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
		* @see 			Construct()
		*/
		SocketUtility(void);

		/**
		* Initializes this instance of %SocketUtility.
		*
		* @since		1.0
		* @return		An error code
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_STATE			This instance is in an invalid state.
		* @exception	E_SYSTEM				Interface creation has failed.
		*/
		result Construct(void);

		/**
		* This is the destructor for this class. @n
		* The resources are deallocated by this method. This destructor should be called in the same thread where Construct() is called.
		*
		* @since	1.0
		*/
		virtual ~SocketUtility(void);

	public:
		/**
		* Determines the status of one or more sockets.
		*
		* @since			1.0
		* @privlevel		NORMAL
		* @privgroup		SOCKET
		*
		* @return			An error code
		* @param[in,out]	pCheckRead					An IList of %Socket instances to check for readability
		* @param[in,out]	pCheckWrite					An IList of %Socket instances to check for writability
		* @param[in,out]	pCheckError					An IList of %Socket instances to check for errors
		* @param[in]		microSeconds				The time to wait for a response, in microseconds
		* @exception		E_SUCCESS					The method is successful.
		* @exception		E_INVALID_SOCKET			The socket is invalid.
		* @exception		E_INVALID_STATE				The socket is in an invalid state.
		* @exception		E_UNSUPPORTED_OPTION		The specified parameters are not supported.
		* @exception		E_INVALID_ARG				A specified input parameter is invalid.
		* @exception		E_TIMEOUT					The time limit has expired.
		* @exception		E_NETWORK_UNAVAILABLE		The network is unavailable.
		* @exception    	E_OUT_OF_MEMORY				The memory is insufficient.
		* @exception		E_SYSTEM					A system error has occurred.
		* @exception    	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
		*
		* @remarks		The Select() method determines the status of one or more 
		* 				%Socket instances. There must be at least one socket in an IList
		* 				before the Select() method is used. @n
		* 				To check sockets for readability and writability use @c pCheckRead and @c pCheckWrite of type
		*				IList respectively by calling the Select() method. @n
		* 				To detect error conditions, use @c pCheckError. @n
		* 				After calling Select(), the IList is filled with only those sockets that satisfy the conditions. @n
		*               All the receive operations succeed without blocking in the following cases: @n
		* 				-#  If the socket is in a listening state, the readability means that a call to Accept() succeeds without blocking.
		*				-#  If the connection on a socket is accepted, the readability means that the data is available for reading. @n
		* 				The readability can also indicate whether the remote socket has shutdown the connection. In this
		* 				case a call to Receive() returns immediately with @c 0 bytes.
		* 				If a non-blocking call to Connect() is made, the writability means that the connection is
        *				successful and the @c pCheckError parameter	identifies the sockets that are not
        *				connected successfully. @n
		* 				If a connection has already been established, the writability means that all the send operations
		*				have succeeded without blocking.
		*/
		result Select(Osp::Base::Collection::IList* pCheckRead, Osp::Base::Collection::IList* pCheckWrite,
						 Osp::Base::Collection::IList* pCheckError, int microSeconds);

		/**
		* Converts the specified unsigned @c short integer from a host @c byte order to a network @c byte order.
		*
		* @since		1.0
		* @return		An unsigned @c short integer in network @c byte order
		* @param[in]	hostShort		An unsigned @c short integer in host @c byte order
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			NtoHS()
		*/
		unsigned short HtoNS(unsigned short hostShort);

		/**
		* Converts the specified unsigned @c long integer from a host @c byte order to a network @c byte order.
		*
		* @since		1.0
		* @return		An unsigned @c long integer in network @c byte order
		* @param[in]	hostLong		An unsigned @c long integer in host @c byte order
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			NtoHL()
		*/
		unsigned long	HtoNL(unsigned long hostLong);

		/**
		* Converts the specified unsigned @c short integer from a network @c byte order to a host @c byte order.
		*
		* @since		1.0
		* @return		An unsigned @c short integer in host @c byte order
		* @param[in]	netShort		An unsigned @c short integer in network @c byte order
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			HtoNS()
		*/
		unsigned short	NtoHS(unsigned short netShort);

		/**
		* Converts the specified unsigned @c long integer from a network @c byte order to a host @c byte order.
		*
		* @since		1.0
		* @return		An unsigned @c long integer in host @c byte order
		* @param[in]	netLong			An unsigned @c long integer in network @c byte order
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			HtoNL()
		*/
		unsigned long	NtoHL(unsigned long netLong);

	// LifeCycle
	private:
		/*
		* This is the copy constructor for the SocketUtility class.
		*
		* @param[in]	value			An instance of SocketUtility
		*/
		SocketUtility(const SocketUtility& value);

	// Operation
	private:
		/*
		* This is the assignment operator. 
		* Do @b not use directly.
		*
		* @param[in]	rhs			An instance of %SocketUtility
		*/
		SocketUtility& operator =(const SocketUtility& rhs);

	private:
		bool __isConstructed;
		ISocketUtilityPi* __pSocketUtilityInterface;

	private:
		// for ABC
		class SocketUtilityEx* __pSocketUtilityEx;

		friend class SocketUtilityEx;
	};

};// Osp::Net::Sockets
};// Osp::Net
};// Osp 

#endif
