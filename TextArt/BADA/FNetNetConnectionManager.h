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
 * @file		FNetNetConnectionManager.h 
 * @brief		This is the header file for the %NetConnectionManager class.
 *
 * This header file contains the declarations of the %NetConnectionManager class.
 */
#ifndef _FNET_NET_CONNECTION_MANAGER_H_
#define _FNET_NET_CONNECTION_MANAGER_H_

// Includes
#include "FBase.h"
#include "FNetConfig.h"
#include "FNetNetTypes.h"
#include "FNetNetConnection.h"
#include "FNetManagedNetConnection.h"

namespace Osp { namespace Net {
// Forward declaration
typedef struct __NetInfo NetInfo;
class INetAccountPi;

/**
 * @class	NetConnectionManager 
 * @brief	This class provides the methods for managing the network connections.
 * @since 	2.0
 *
 * 	The %NetConnectionManager class provides the methods for creating and retrieving connections for data communication.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 */
class _EXPORT_NET_ NetConnectionManager :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	NetConnectionManager(void);

	/**
	 * This is the destructor for this class. @n
	 * This method closes the %NetConnectionManager instance and also releases the resources associated with it.
	 *
	 * @since		2.0
	 */
	virtual ~NetConnectionManager(void);

	/**
	 * Initializes this instance of %NetConnectionManager.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	result Construct(void);

// Operation
public:
	/**
	 * Creates a new network connection.
	 *
	 * @since 		2.0
	 *
	 * @return		A %NetConnection instance containing the account information, @n
	 *				else @c null if an error occurs
	 * @param[in]	netAccountId		The index of the network account to which this %NetConnection is bound
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n 
   *                                  this operation is not allowed on this network account.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_MAX_EXCEEDED		Unable to setup a new connection due to too many existing connections.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetConnection* CreateNetConnectionN(NetAccountId netAccountId);

	/** 
	 * Gets an instance of the current connection that is managed by the system. 
	 *
	 * @since 		2.0
	 *
	 * @return		A ManagedNetConnection instance containing the account information, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
 	ManagedNetConnection* GetManagedNetConnectionN(void) const;

	/** 
	 * Gets the preferred network.
	 *
	 * @since 		2.0
	 *
	 * @return		The preferred network, @n
	 *				else @c NET_WIFI_FIRST if there is an error or if the preferred network is not set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
     *                                  this operation is not allowed on this network account.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetPreferenceType GetNetPreference(void) const;

	/** 
	 * Sets the default bearer type.
	 *
	 * @since 		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	netPreference		The preferred network
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *                                  this operation is not allowed on this network account.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		If this method is not used, the default connection works in the Wi-Fi first mode.
	 */
	result SetNetPreference(NetPreferenceType netPreference);


// Accessor
public:
	/**
	 * Gets the connection information that is related to a network account.
	 *
	 * @since 		2.0
	 *
	 * @return		A %NetConnectionInfo instance specifying the information on this network connection, @n
	 *				else @c null if there is an error or if an active connection is not found
	 * @param[in]	netAccountId		The network account ID
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static NetConnectionInfo* GetNetConnectionInfoN(NetAccountId netAccountId) ;

	/**
	 * Gets a list of all the network connections information that is used by the system.
	 *
	 * @since 		2.0
	 *
	 * @return		An IList containing indexes to the active %NetConnectionInfo in the network, @n
	 *				else @c null if there is an error or if there is no active connection in the system
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static Osp::Base::Collection::IList* GetAllNetConnectionInfoN(void) ;

// Operation
private:
	/**
	 * Converts the connection information from NetInfo structure to NetConnectionInfo class. 
	 *
	 * @return		An error code
	 * @param[in]	netInfo				The NetInfo instance
	 * @param[out]	netConnectionInfo	The network information related to the network connection
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	static result ConvertNetInfo(NetInfo& netInfo, NetConnectionInfo& netConnectionInfo);

// LifeCycle
private:
	/**
	* This is the copy constructor for the %NetConnectionManager class.
	*
	* @param[in]	value		An instance of %NetConnectionManager
	*/
	NetConnectionManager(const NetConnectionManager& value);

// Operator
private:
	/** 
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs			An instance of %NetConnectionManager
	 * @remarks		The method is declared but not implemented.
	 */
	NetConnectionManager& operator =(const NetConnectionManager& rhs);

// Attribute
private:

//status
	bool			__isConstructed;

//interface pointer
	INetAccountPi*	__pNetAccountInterface;

// Friend class declaration
	friend class NetConnection;
	friend class ManagedNetConnection;

// New member Extension
	friend class NetConnectionManagerEx;
	class NetConnectionManagerEx* __pNetConnectionManagerEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_CONNECTION_H_

