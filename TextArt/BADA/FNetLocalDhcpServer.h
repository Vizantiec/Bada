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
 * @file	FNetLocalDhcpServer.h 
 * @brief	This is the header file for the %LocalDhcpServer class.
 *
 * This header file contains the declarations of the %LocalDhcpServer class.
 */
#ifndef _FNET_LOCAL_DHCP_SERVER_H_
#define _FNET_LOCAL_DHCP_SERVER_H_

// Includes
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseColIList.h"
#include "FNetConfig.h"

namespace Osp { namespace Net {
// Forward declaration
class NetConnection;
class ILocalDhcpServerEventListener;
class __LocalDhcpServerImpl;
/**
 * @class	LocalDhcpServer 
 * @brief	This class provides the methods for managing the local DHCP server.
 * @since	2.0
 *
 * 	The %LocalDhcpServer class provides the methods for managing the local DHCP server. The Wi-Fi Direct or USB NDIS requires the local DHCP server 
 *			for data communication.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/local_DHCP_server_access.htm">Local DHCP Server Access</a>.
 */
class _EXPORT_NET_ LocalDhcpServer :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class. @n
	 * This method closes the %LocalDhcpServer instance and releases resources related to this %LocalDhcpServer.
	 * @since 	2.0
	 *
	 */
	virtual ~LocalDhcpServer(void);

	/**
	 * Gets a singleton instance of %LocalDhcpServer that it associated with the specified network connection.
	 *
	 * @since 		2.0
	 * @return		An instance of %LocalDhcpServer
	 * @param[in]	netConnection		A run-time session where a local DHCP server used
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static LocalDhcpServer* GetInstance (const NetConnection& netConnection);

// Operation
public:
	/**	
	 * Sets a listener instance for the events about a local DHCP server.
	 *
	 * @since 		2.0
	 * @param[in]	pListener			An instance of ILocalDhcpServerEventListener @n
     *									If it is @c null, it will reset the event listener.
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	result SetLocalDhcpServerEventListener(const ILocalDhcpServerEventListener* pListener);

// Accessor
public:
	/**
	 * Gets a list of all the client information on the local DHCP server.
	 *
	 * @since 		2.0
	 * @return		An IList containing indexes to the DhcpClientInfo on the local DHCP server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		In case of an error or if there is no active connection for the local DHCP server, @c null is returned.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetDhcpClientInfoListN(void) const;

// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 */
	LocalDhcpServer(void);

	/**
	* This is the copy constructor for the %LocalDhcpServer class.
	*
	* @param[in]	value		An instance of %LocalDhcpServer
	*/
	LocalDhcpServer(const LocalDhcpServer& value);

// Operator
private:
	/** 
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs			An instance of %LocalDhcpServer
	 * @remarks		The method is declared but not implemented.
	 */
	LocalDhcpServer& operator =(const LocalDhcpServer& rhs);

// Attribute
private:
	__LocalDhcpServerImpl* __pLocalDhcpServerImpl;
	friend class __LocalDhcpServerImpl;
};

}; }; // Osp::Net

#endif // _FNET_LOCAL_DHCP_SERVER_H_

