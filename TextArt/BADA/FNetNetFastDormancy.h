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
 * @if PRIVCORE
 *
 * @file		FNetNetFastDormancy.h 
 * @brief		This is the header file for the %NetFastDormancy class.
 *
 * This header file contains the declarations of the %NetFastDormancy class.
 *
 * @endif
 */
#ifndef _FNET_NET_FASTDORMANCY_H_
#define _FNET_NET_FASTDORMANCY_H_

// Includes
#include "FNetConfig.h"
#include "FNetNetTypes.h"
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseByteBuffer.h"


namespace Osp { namespace Net {
// Forward declaration
class INetConnectionPi;
class _DefaultNetConnection;

/**
 * @if PRIVCORE
 *
 * @class	NetFastDormancy 
 * @brief	This class provides the methods for fast dormancy.
 * @deprecated 	This class is deprecated because the platform will manage fast dormancy without permitting the applications to set it.
 * @since		1.0
 *
 * @remarks	This class provides the methods for starting and stopping the Radio Resource Control (RRC) connections for data communication. A network 
 *			connection is thus, always based on a configured network account. After the connection is established, the applications can use the socket and 
 *			HTTP interfaces.
 *
 * The %NetFastDormancy class provides the methods for fast dormancy.
 *
 * @endif
 */
class _EXPORT_NET_ NetFastDormancy :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * @if PRIVCORE
	 *
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *
	 * @endif
	 */
	NetFastDormancy(void);

	/**
	 * @if PRIVCORE
	 *
	 *	This is the destructor for this class. @n
	 * 	This method closes the NetConnection instance and releases the resources related to it.
	 *
	 * @since		1.0
	 * @endif
	 */
	virtual ~NetFastDormancy(void);

	/**
	 * @if PRIVCORE
	 *
	 * Initializes this instance of %NetFastDormancy.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 *
	 * @privgroup	NET_MANAGER
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @endif
	 */
	result Construct(void);

	/**
	 * @if PRIVCORE
	 *
	 * Initializes this instance of %NetFastDormancy with the specified parameter.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 *
	 * @privgroup	NET_MANAGER
	 * @return		An error code
	 * @param[in]	netConnection			The index of the network account to which this %NetConnection is bound to
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_INVALID_ARG			The specified @c netConnection contains an invalid value.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @endif
	 */
	result Construct(const NetConnection& netConnection);


// Operation
public:
	/** 
	 * @if PRIVCORE
	 *
	 * Starts the fast dormancy connection. @n
	 * This method stops the Radio Resource Control(RRC) connection.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 *
	 * @privgroup	NET_MANAGER
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_FAILURE				The method has failed to start the fast dormancy.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @see			Stop()
	 *
	 * @remarks		This method sends the requests to the Radio Network Controller (RNC) only.
	 *				It does not wait for the response from the Radio Network Controller (RNC).
	 *				The Radio Resource Control is a concept and a protocol name for the set of control messages exchanged between the user equipment (UE) and 
	 *				the Radio Network Controller (RNC) in the Universal Mobile Telecommunications System (UMTS) standard.
	 * @endif
	 */
	result Start(void);

	/**
	 * @if PRIVCORE
	 *
	 * Stops the fast dormancy connection. @n
	 * This method starts the Radio Resource Control(RRC) connection.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 *
	 * @privgroup	NET_MANAGER
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_FAILURE				The method has failed to stop the fast dormancy.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @see			Start()
	 *
	 * @remarks		This method send the requests to the Radio Network Controller (RNC) and does not wait for the response from the Radio Network Controller (RNC).
	 *				The Radio Resource Control is a concept and a protocol name for the set of control messages exchanged between the User Equipment (UE) and 
	 *				the Radio Network Controller (RNC) in the UMTS standard.
	 * @endif
	 */
	result Stop(void);


// Operator
private:
	/** 
	 * This is the assignment operator.
	 *
	 * @param[in]	rhs			An instance of %NetConnection
	 * @remarks		This method is declared but not implemented.
	 */
	NetFastDormancy& operator =(const NetFastDormancy& rhs);

// Attribute
private:

//base-platform related
	int __hProtocol;

//status
	bool __isConstructed;

//interface pointer
	Osp::Net::INetConnectionPi* __pNetConnectionInterface;
	Osp::Net::_DefaultNetConnection* __pDefaultNetConnection;

	friend class NetFastDormancyEx;
	class NetFastDormancyEx* __pNetFastDormancyEx;

// Friend class declaration
};

}; }; // Osp::Net

#endif // _FNET_NET_FASTDORMANCY_H_

