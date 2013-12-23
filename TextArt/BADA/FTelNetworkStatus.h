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
 * @file		FTelNetworkStatus.h 
 * @brief		This is the header file for the %NetworkStatus class.
 *
 * This header file contains the declarations of the %NetworkStatus class.
 */
 
#ifndef _FTEL_NETWORK_STATUS_H_
#define _FTEL_NETWORK_STATUS_H_

#include "FBase.h"
#include "FTelConfig.h"

namespace Osp { namespace Telephony {

/**
 * @class	NetworkStatus
 * @brief	This class provides status information of the current network. 
 * @since	1.0
 *
 * The %NetworkStatus class provides methods to get the current network status information,
 * such as the roaming status, call service, and data service.
 *
 * The following example demonstrates how to use the %NetworkStatus class.
 *
 * @code
 *
 *	result
 *	MyClass::GetNetworkStatus(void)
 *	{
 *		NetworkStatus networkStatus;
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
 *		bool isCallAvail = networkStatus.IsCallServiceAvailable();
 *		bool isDataAvail = networkStatus.IsDataServiceAvailable();
 *		bool isRoaming = networkStatus.IsRoaming();
 *
 *		delete pNetworkManager;
 *		return E_SUCCESS;
 *	}
 *
 * @endcode
 */
class _EXPORT_TEL_ NetworkStatus
	: public Osp::Base::Object
{
// Life cycle
public:

	/**
	 *	This is the default constructor for this class.	
	 *
	 * @since	1.0
	 */
	NetworkStatus(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~NetworkStatus(void) {};

// Access
public:	

	/**
	 * Checks whether the current network is in roaming status.
	 *
	 * @since			1.0
   * @privlevel	NORMAL
	 * @privgroup TELEPHONY		
	 *
	 * @return		@c true if the current network is in roaming status, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	bool IsRoaming(void) const;
	
	/**
	 * Checks whether call service is available.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY		
	 *
	 * @return		@c true if call service is available, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	bool IsCallServiceAvailable(void) const;

	/**
	 * Checks whether data service is available.
	 *
	 * @since			1.0
   * @privlevel	NORMAL
	 * @privgroup TELEPHONY		
	 *
	 * @return		@c true if data service is available, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	bool IsDataServiceAvailable(void) const;

private:
	bool __isRoaming;
	bool __isCallServiceAvailable; 
	bool __isDataServiceAvailable;

	friend class __NetworkManagerPi;
	
private:
	friend class NetworkStatusEx;
	class NetworkStatusEx* __pNetworkStatusEx;
};

};};
#endif // _FTEL_NETWORK_STATUS_H_
