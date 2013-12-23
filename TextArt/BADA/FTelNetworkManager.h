/* $Change: 1154502 $ */
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
 * @file		FTelNetworkManager.h 
 * @brief		This is the header file for the %NetworkManager class.
 *
 * This header file contains the declarations of the %NetworkManager class.
 */
 
#ifndef _FTEL_NETWORK_MANAGER_H_
#define _FTEL_NETWORK_MANAGER_H_

#include "FBase.h"
#include "FTelConfig.h"

#include "FTelNetworkInfo.h"
#include "FTelNetworkStatus.h"
#include "FTelITelephonyNetworkEventListener.h"

namespace Osp { namespace Telephony {
class INetworkManagerPi;
class __NetworkEvent;

/**
 * @class	NetworkManager 
 * @brief	This class provides information about the current active network.
 * @since	1.0
 *
 * The %NetworkManager class provides methods to register listeners for monitoring network status changes, and getting information about the currently active network.
 *
 * The following example demonstrates how to use the %NetworkManager class.
 *
 *
 * @code
 *
 *	result
 *	MyClass::GetNetworkManagerInfo(void)
 *	{
 *		NetworkStatus networkStatus;
 *		NetworkInfo networkInfo;
 *
 *		NetworkManager *pNetworkManager = new NetworkManager();
 *
 *		result r = pNetworkManager->Construct(this);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		r = pNetworkManager->GetNetworkStatus(networkStatus);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		r = pNetworkManager->GetNetworkInfo(networkInfo);
 *		if (IsFailed(r))
 *		{
 *			delete pNetworkManager;
 *			return r;
 *		}
 *
 *		delete pNetworkManager;
 *		return E_SUCCESS;
 *	}
 *
 *	void
 *	MyClass::OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus)
 *	{
 *		bool isCallAvail = networkStatus.IsCallServiceAvailable();
 *		bool isDataAvail = networkStatus.IsDataServiceAvailable();
 *		bool isRoaming = networkStatus.IsRoaming();
 *	}
 *
 * @endcode
 */
class _EXPORT_TEL_ NetworkManager 
	: public Osp::Base::Object
		
{
// Life cycle
public:

	/**
	 *	This is the default constructor for this class.	
	 *
	 * @since	1.0
	 */
	NetworkManager(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~NetworkManager(void);

	/**
	 *	Initializes a new instance of this class. This is the two phase construction. @n
	 *	If a @c null pointer is passed during the construction, there will be no listener for the telephony network status change callbacks.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pListener			The listener 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const ITelephonyNetworkEventListener* pListener);
	
// Operation
public:	

	/**
	 * Gets the network status.
	 *
	 * @since			1.0
     * @privlevel	NORMAL
	 * @privgroup TELEPHONY		 
	 *
	 * @return		An error code
 	 * @param[out]	networkStatus				The network status
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_NETWORK_UNAVAILABLE		The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE		The operation has failed because the device is out of the coverage area or in the emergency mode.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state. @n
	 *											The Construct() method must be called. 
	 * @exception   E_PRIVILEGE_DENIED      	The application does not have the privilege to call this method.		 
	 */
	result GetNetworkStatus(NetworkStatus& networkStatus) const;	
	
	/**
	 * Gets the network information. 
	 *
	 * @since			1.0
     * @privlevel	NORMAL
	 * @privgroup TELEPHONY		 
	 *
	 * @return		An error code
 	 * @param[out]	networkInfo					The network information
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_NETWORK_UNAVAILABLE		The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE		The operation has failed because the device is out of the coverage area or in the emergency mode.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state. @n
	 *											The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED      	The application does not have the privilege to call this method.		 
	 */
	result GetNetworkInfo(NetworkInfo& networkInfo) const;

private:
	NetworkManager(const NetworkManager& value);
	NetworkManager& operator =(const NetworkManager& value);

private:
	__NetworkEvent*					__pNetworkEvent;
	ITelephonyNetworkEventListener* __pListener;
	INetworkManagerPi* 				__iNetworkManagerInterface;
	
private:	
	friend class NetworkManagerEx;
	class NetworkManagerEx* __pNetworkManagerEx;
};
	
};};
#endif // _FTEL_NETWORK_MANAGER_H_
