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
 * @file		FNetNetConnection.h 
 * @brief		This is the header file for the %NetConnection class.
 *
 * This header file contains the declarations of the %NetConnection class.
 */
#ifndef _FNET_NET_CONNECTION_H_
#define _FNET_NET_CONNECTION_H_

// Includes
#include "FBase.h"
#include "FNetConfig.h"
#include "FNetNetTypes.h"
#include "FNetNetConnectionInfo.h"
#include "FNetINetConnectionEventListener.h"

namespace Osp { namespace Net {
// Forward declaration
typedef struct __NetInfo NetInfo;
class Dns;
class NetFastDormancy;
class INetConnectionPi;
class __NetConnectionEvent;
class __LocalDhcpServerImpl;
namespace Sockets {
	class Socket;
	class SecureSocket;
};
namespace Http {
	class HttpSession;
};

/**
 * @class	NetConnection 
 * @brief	This class provides the methods for all the network connections.
 * @since	1.0
 *
 * 	The %NetConnection class provides the methods for managing the connections for data communication.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/managing_network_connections.htm">Managing Network Connections</a>.
 *
 * The following example demonstrates how to use the %NetConnection class.
 *
 * @code

	// Start the network connection.
	using namespace Osp::Net;

	void
	Test(void)
	{
		// Account ID 
		NetAccountId accountId = INVALID_HANDLE;
    	result r = E_SUCCESS;

		// Account manager
		NetAccountManager netAccountManager;
		r = netAccountManager.Construct();
		accountId = netAccountManager.GetNetAccountId();

		// Construct a listener.
		TestListener* pMyListener = new TestListener();

		// NetConnection instance allocation.
		NetConnection* pNetConnection = new NetConnection;

		// Construct NetConnection.
		r = pNetConnection->Construct(accountId);

		// __NetConnectionEvent AddListener.
		r = pNetConnection->AddNetConnectionListener(pMyListener);

		// NetConnection connect.
		r = pNetConnection->Start();
	}
 * @endcode
 */
class _EXPORT_NET_ NetConnection :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	NetConnection(void);

	/**
	 * This is the destructor for this class. @n
	 * This method closes the %NetConnection instance and also releases the resources associated with it.
	 *
	 * @since	1.0
	 */
	virtual ~NetConnection(void);

	/**
	 * Initializes this instance of %NetConnection with the specified parameter. @n
	 * It automatically binds @c netAccountId with %NetConnection. This method registers an application for receiving the network connection events. @n
	 * A network connection is based on a configured network account for starting the connection. In order to start the network connection, create a new 
	 * network account or obtain the information of an existing network account, and call the Start() method.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetConnectionConstructPage1 "here".
	 *
	 * @return			An error code
	 * @param[in]		netAccountId		The index of the network account to which this %NetConnection is bound
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance is in an invalid state.
	 * @exception		E_MAX_EXCEEDED		Unable to setup a new connection due to too many existing connections.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception		E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_PROXY		The proxy address is invalid @b since: @b 2.0.
	 * @remarks			If the application gets the last result by E_INVALID_PROXY, it should use a warning pop-up to notify the user.
	 */
	result Construct(NetAccountId netAccountId);

	/**
     * @page		NetConnectionConstructPage1	Compatibility for Construct()
     *
     * @section		NetConnectionConstructPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the user sets an invalid proxy address, the application terminates abnormally.
     *
     * @section		NetConnectionConstructPage1ResolutionSection	Resolutions
	 * -# If the user sets an invalid proxy address, this method returns E_INVALID_PROXY instead of being terminated abnormally. @n
    */

// Lifecycle
private:
	/** 
	 * This is the copy constructor for the %NetConnection class.
	 *
	 * @param[in]	value			An instance of %NetConnection
	 * @remarks		The method is declared but not implemented.
	 */	
	NetConnection(const NetConnection& value);

	/**
	 * Initializes this instance of NetConnection.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_STATE					This instance is in an invalid state.
	 * @exception	E_MAX_EXCEEDED					Unable to setup a new connection due to too many existing connections.
	 * @exception	E_INVALID_ARG					The specified @c appName is invalid or an empty String.
	 * @exception	E_EVENT_DISPATCHER_NOT_EXIST	The event dispatcher is not found.
	 * @exception	E_SYSTEM						An internal error has occurred. @n
	 *												The event handler cannot be found.
	 * @remarks		This method registers an application for receiving the network connection events. A network connection is based on a configured network 
	 *				account for starting the connection. In order to start the network connection, create a new network account or obtain the information of 
	 *				an existing network account, and call the Start() method.
	 */
	result Construct();


// Operation
public:
	/**
	 *	Adds a listener to %NetConnection. @n
	 *	The added listener can listen to events when they are fired.
	 *
	 * 	@since		1.0
	 *	@param[in]	listener				A reference to INetConnectionEventListener
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			This instance has not been constructed as yet or it may be closed.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result AddNetConnectionListener(const INetConnectionEventListener& listener);

	/**
	 * Removes the specified %INetConnectionEventListener instance.
	 *
	 * @since		1.0
	 * @param[in]	listener				A reference to %INetConnectionEventListener
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet or it may be closed.
	 * @exception	E_OBJ_NOT_FOUND			The EventListener is not found.
	 */
	result RemoveNetConnectionListener(const INetConnectionEventListener& listener);
	
	/** 
	 * Starts the network connection. 
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_ACCOUNT		The specified network account ID is invalid. 
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection. 
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SERVICE_LIMITED		A connection is already active. Therefore, cannot setup a co-existing network connection.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @remarks		When the network is available, after calling this method, the OnNetConnectionStarted() method of the registered 
	 *				%INetConnectionEventListener instance is called.
	 * @see			Stop()
	 */
	result Start(void);

	/** 
	 * Stops the network connection. 
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection. 
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @remarks		This method stops the network connection of an application.  Additionally, it does not ensure immediate disconnection of the network 
	 *				service (For example, 3G data service or Wi-Fi). The network service remains active till all the applications stop using the network 
	 *				connection. Once stopped, the network connection can be restarted using the Start() method.	 
	 *
	 * @see			Start(), Close()
	 */
	result Stop(void);

	/** 
	 * Closes the network connection. @n
	 * All the resources associated with the network connection are freed. This is a forced operation. The Close() method disconnects the network connection 
	 * with a remote server or gateway.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied to the resources bound to this %NetConnection. 
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @remarks		This method stops the network connection of an application. Additionally, it does not ensure immediate disconnection of the network 
	 *				service (For example, 3G data service or Wi-Fi). The network service remains active till all the applications stop using the network 
	 *				connection. 
	 *
	 * @see			Stop()
	 */
	result Close(void);	

// Accessor
public:
	/** 
	 * Gets the network account ID of this instance. @n
	 * This ID is used to establish a network connection with a remote server or gateway.
	 *
	 * @since		1.0
	 * @return		The %NetAccountId of this %NetConnection which is bound at Construct(), @n
	 *				else @c INVALID_HANDLE if %NetConnection is invalid or not constructed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	NetAccountId GetNetAccountId(void) const;

	/**
	 * Gets the network connection information.
	 *
	 * @since		1.0
	 * @return		A NetConnectionInfo instance specifying information on this network connection
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @remarks		This method requires a NetConnectionInfo instance reference. The network connection information is only available when the network 
	 *				connection is "Active". For other states, this method returns @c null.
	 * @warning 	Do not delete the returned NetConnectionInfo instance. This instance directly references the internal connection information of 
	 *				%NetConnection.
	 */
	const NetConnectionInfo* GetNetConnectionInfo(void) const;

	/**
	 * Gets the connection information for the specified account.
	 *
	 * @deprecated This method is deprecated because it is moved to the %NetConnectionManager class.
	 *
	 * @since 		1.2
	 *
	 * @return		A NetConnectionInfo instance specifying information on this network connection, @n
	 *				else @c null in case of an error or if an active connection is not found
	 * @param[in]	netAccountId		The network account
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ACCOUNT	The specified network account ID is invalid.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static NetConnectionInfo* GetNetConnectionInfoN(NetAccountId netAccountId) ;

	/**
	 * Gets a list of all the connection information used by the system.
	 *
	 * @deprecated	This method is deprecated because it is moved to the NetConnectionManager class.
	 *
	 * @since 		1.2
	 *
	 * @return		An IList containing indexes to NetConnectionInfo in the network, @n
	 *				else @c null in case of an error or if an active connection is not found
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static Osp::Base::Collection::IList* GetAllNetConnectionInfoN(void) ;


	/**
	 * Gets the state of the network connection.
	 *
	 * @since		1.0
	 * @return		The state of the network connection
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 */
	NetConnectionState  GetConnectionState(void) const;

// Operation
private:
	/**
	 * Converts the network connection information from NetInfo to NetConnectionInfo. 
	 *
	 * @return		An error code
	 * @param[in]	netInfo				The network information related to a network connection
	 * @param[out]	netConnectionInfo	The network information instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	static result ConvertNetInfo(NetInfo& netInfo, NetConnectionInfo& netConnectionInfo);
	
	/** 
	 * Updates the information associated with this NetConnection instance.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_FAILURE		The method has failed to free the resource possessed by this instance.
	 *
	 */
	result UpdateNetConnectionInfo(void);

	/** 
	 * Releases the resources associated with the network connection.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 */
	result Disconnect(void);

	/** 
	 * Tries to establish a connection with a remote server or gateway based on the specified network account ID. @n
	 * The different events that occur during the network connection will be notified via the registered %INetConnectionEventListener instance.
	 *
	 * @return		An error code
	 * @param[in]	netAccount				A %NetAccountId instance 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_IO					The loading of registry with the specified network account ID has failed.
	 * @exception	E_INVALID_ACCOUNT		The specified network account ID is invalid.
	 * @exception	E_INVALID_PROXY			The proxy address is invalid @b since: @b 2.0.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_SERVICE_LIMITED		There is another active connection; cannot set up a co-existing NetConnection.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @remarks		After you call Connect, you can send and receive data to and from the remote device through Sockets and Http APIs.
	 */
	result BindAccount(NetAccountId netAccountID);

	/** 
	 * Tries to erase a network connection established with a remote server or gateway based on the specified network account ID. @n
	 * The different events that occur during the network connection will be notified via the registered %INetConnectionEventListener instance.
	 *
	 * @return		An error code
	 * @param[in]	netAccount				A %NetAccountId instance 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied.
	 * @exception	E_INVALID_CONTEXT		The context information associated with the network connection account is invalid.
	 * @exception	E_IO					The loading of registry with the specified network account ID has failed.
	 * @exception	E_INVALID_ACCOUNT		The specified network account ID is invalid.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_SERVICE_LIMITED		There is another active connection; cannot set up a co-existing NetConnection.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 */
	result UnbindAccount(void);

// Accessor
private:
	/**
	 * @internal
	 * The GetHandle method gets the protocol handle, INVALID_HANDLE is returned
	 *
	 * @return		handle value. if NetConnection is invalid, 
	 * @remarks		Classes deriving from class NetConnection can use this method to get a low-level protocol handle. 
	 *				Use the handle returned by this method if you require access beyond which class NetConnection provides.
	 */
	Handle GetHandle(void) const;

// Operator
private:
	/** 
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs				An instance of %NetConnection
	 * @remarks		The method is declared but not implemented.
	 */
	NetConnection& operator =(const NetConnection& rhs);

// Attribute
private:
	/**
	 * For each %NetConnection used , an event listener (%INetConnectionEventListener) should be registered and maintained, via which asynchronous 
	 * notifications of NetConnection events can be received. If you want to get an event via listener, you should call AddNetConnectionListener() of this 
	 * member which is of type __NetConnectionEvent after initializing the %NetConnection through the Construct() method.
	 */
//Event-related
	__NetConnectionEvent* __pNetConnectionEvent;

//Base-platform related
	int __hProtocol;
	Osp::Net::NetAccountId __netAccountId;
	//Osp::Base::String __applicationName;

//Status
	bool __isConstructed;
	bool __isClosed;
	bool __isDisposed;

	NetConnectionState __connectionState;
//Information
	NetConnectionInfo __netConnectionInfo;

//Interface pointer
	INetConnectionPi* __pNetConnectionInterface;

// Friend class declaration
	friend class __NetConnectionEvent;
	friend class Dns;
	friend class Osp::Net::Sockets::Socket;
	friend class Osp::Net::Sockets::SecureSocket;
	friend class Osp::Net::Http::HttpSession;
	friend class Osp::Net::NetFastDormancy;
	friend class Osp::Net::__LocalDhcpServerImpl;

	friend class NetConnectionEx;
	class NetConnectionEx* __pNetConnectionEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_CONNECTION_H_

