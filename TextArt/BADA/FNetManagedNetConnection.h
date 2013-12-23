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
 * @file	FNetManagedNetConnection.h 
 * @brief	This is the header file for the %ManagedNetConnection class.
 *
 * This header file contains declarations of the %ManagedNetConnection class.
 */
#ifndef _FNET_MANAGED_NET_CONNECTION_H_
#define _FNET_MANAGED_NET_CONNECTION_H_

// Includes
#include "FBase.h"
#include "FNetConfig.h"
#include "FNetNetTypes.h"
#include "FNetNetConnectionInfo.h"
#include "FNetIManagedNetConnectionEventListener.h"

// Forward declaration
struct _IConnectionManager;
struct __ConnectionManagerListenerImpl;

namespace Osp { namespace Net {
// Forward declaration
class INetConnectionPi;
class __ConnectionManagerListenerWrapper;

/**
 * @class	ManagedNetConnection 
 * @brief	This class provides the methods for the network connection managed by the system.
 * @since	2.0
 *
 * 	The %ManagedNetConnection class provides functionalities for accessing the information about the default connection for data communication 
 *			managed by the system. Once the connection is established, the applications can use sockets and HTTP interfaces.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/default_network_connection.htm">Default Network Connection</a>.
 */
class _EXPORT_NET_ ManagedNetConnection :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class. @n
	 * This method closes the %ManagedNetConnection instance and releases the resources related to %ManagedNetConnection.
	 *
	 * @since	2.0
	 */
	virtual ~ManagedNetConnection(void);

// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct
	 */
	ManagedNetConnection(void);

	/**
	 * Initializes this instance of ManagedNetConnection. @n
	 * This method does not automatically bind netAccountId with %ManagedNetConnection. 
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 * @remarks		This method registers an application for receiving network connection events and status.
	 */
	result Construct(void);

// Operation
public:
	/**
	 * Sets a listener object to the current instance of %ManagedNetConnection.
	 *
	 * @since		2.0
	 * @param[in]	pListener			An instance of IManagedNetConnectionEventListener @n
	 *									If this is @c null, it will reset the event listener.
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	result SetManagedNetConnectionEventListener(const IManagedNetConnectionEventListener* pListener);

// Accessor
public:
	/** 
	 * Gets the network account on which the current instance is based, to establish a connection with a remote server or a gateway.
	 *
	 * @since		2.0
	 * @return		The NetAccountId of the current instance of %ManagedNetConnection, @n
	 *				else @c INVALID_HANDLE if the network connection managed by the system is inactive
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The network connection is inactive.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetNetAccountId(void) const;

	/**
	 * Gets the connection state of the current instance of %ManagedNetConnection.
	 *
	 * @since		2.0
	 * @return		An instance of NetConnectionState specifying the state of the network connection, @n
	 *				else @c NET_CONNECTION_STATE_STOPPED if the network connection managed by the system is inactive
	 */
	NetConnectionState  GetConnectionState(void) const;

	/**
	 * Gets the information about the current network connection.
	 *
	 * @since		2.0
	 * @return		A pointer to an instance of NetConnectionInfo specifying the information about this network connection
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The network connection is inactive.
	 * @remarks		This method requires a %NetConnectionInfo instance reference.
	 *				%NetConnectionInfo is only available when the network connection managed by the system is active. In other states, this returns null.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 * @warning 	Do not delete the returned %NetConnectionInfo instance. This instance is directly referencing the internal connectionInfo of 
	 *				%ManagedNetConnection.
	 */
	const NetConnectionInfo* GetNetConnectionInfo(void) const;

// Operation
private:
	/*
	 * Updates the information associated with the %ManagedNetConnection instance.
	 *
	 * @return		The error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_FAILURE		The method has failed to free the resource possessed by this instance. 
	 */
	result UpdateNetConnectionInfo(void);

// Accessor
private:
	/* 
	 * Gets the protocol handle.
	 *
	 * @return		The handle value, @n
	 *				else @c INVALID_HANDLE if %ManagedNetConnection is invalid
	 * @remarks		The classes derived from the %ManagedNetConnection class can use this method to get a low-level protocol handle. 
	 *				The handle returned by this method may be used to acquire access beyond the scope of the %ManagedNetConnection class.
	 */
	Handle GetHandle(void);

// Lifecycle
private:
	/** 
	 * This is the copy constructor for the %ManagedNetConnection class.
	 *
	 * @param[in]	value			An instance of the %ManagedNetConnection class
	 * @remarks		The function is declared but not implemented.
	 */	
	ManagedNetConnection(const ManagedNetConnection& value);

// Operator
private:
	/** 
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs		An instance of the Socket
	 */
	ManagedNetConnection& operator =(const ManagedNetConnection& rhs);

// Attribute
private:
// base-platform related
	Handle					__hProtocol;

// status
	bool					__isConstructed;
	NetConnectionState		__connectionState;

// Information
	NetConnectionInfo		__netConnectionInfo;

// interface pointer
	INetConnectionPi*		__pNetConnectionInterface;
	_IConnectionManager*	__pConnectionManager;

	__ConnectionManagerListenerImpl*		__pConnectionManagerEventListenerImpl;
	IManagedNetConnectionEventListener*		__pConnectionEventListener;

// Friend class declaration
	friend class NetConnectionManager;
	friend class __ConnectionManagerListenerWrapper;

// New member Extension
	friend class ManagedNetConnectionEx;
	class ManagedNetConnectionEx* __pManagedNetConnectionEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_MONITORINGH_
