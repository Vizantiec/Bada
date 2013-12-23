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
 * @file		FTelNetworkInfo.h 
 * @brief		This is the header file for the %NetworkInfo class. 
 *
 * This header file contains the declarations of the %NetworkInfo class.
 */
 
#ifndef _FTEL_NETWORK_INFO_H_
#define _FTEL_NETWORK_INFO_H_

#include "FBase.h"
#include "FTelConfig.h"

namespace Osp { namespace Telephony {

/**
 * @class	NetworkInfo 
 * @brief	This class provides information of the current network. 
 * @since	1.0
 *
 * The %NetworkInfo class provides methods to get the current network information, such as MNC, MCC, PLMN, and cell ID.
 *
 * The following example demonstrates how to use the %NetworkInfo class.
 *
 * @code
 *
 *	result
 *	MyClass::GetNetworkInfo(void)
 *	{
 *		int mnc;
 *		int mcc;
 *		int cellId;
 *		int lac;
 *		String plmn;
 *		int rssi;
 *
 *		NetworkInfo networkInfo;
 *
 *		NetworkManager *pNetworkManager = new NetworkManager();
 *
 *		result r = pNetworkManager->Construct(null);
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
 *		mnc = networkInfo.GetMnc();
 *		mcc = networkInfo.GetMcc();
 *		cellId = networkInfo.GetCellId();
 *		lac = networkInfo.GetLac();
 *		plmn = networkInfo.GetPlmn();
 *		rssi = NetworkInfo::GetRssi();
 *
 *		delete pNetworkManager;
 *		return E_SUCCESS;
 *	}
 *
 * @endcode
 */
class _EXPORT_TEL_ NetworkInfo
	: public Osp::Base::Object
{
// Life cycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0	
	 */
	NetworkInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~NetworkInfo(void) {};


// Access
public:	

	/**
	 * Gets the Mobile Network Code (MNC) of the network.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY	 
	 *
	 * @return		The MNC of the network
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	int GetMnc(void) const;

	/**
	 * Gets the Mobile Country Code (MCC) of the network.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY	 
	 *
	 * @return		The MCC of the network
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	int GetMcc(void) const;

	/**
	 * Gets the Public Land Mobile Network (PLMN) string.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY	 
	 *
	 * @return		The PLMN name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	Osp::Base::String GetPlmn(void) const;

	/**
	 * Gets the current cell ID.
	 *
	 * @since			1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	 *				For more information, see @ref TelNetworkInfoGetCellIdPage "here".
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY_LOCATION
	 *
	 * @return		The current cell ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	int GetCellId(void) const;

	/**
	 * @page	TelNetworkInfoGetCellIdPage Compatibility for GetCellId()
	 * @section	TelNetworkInfoGetCellIdPageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 *	-# The privilege group is changed from TELEPHONY to TELEPHONY_LOCATION in bada API version 2.0.
	 */

	/**
	 * Gets the current Location Area Code (LAC).
	 *
	 * @since			1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	 *				For more information, see @ref TelNetworkInfoGetLacPage "here".

     * @privlevel	NORMAL
	 * @privgroup TELEPHONY_LOCATION
	 *
	 * @return		The current LAC
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */

	int GetLac(void) const;

	/**
	 * @page	TelNetworkInfoGetLacPage Compatibility for GetLac()
	 * @section	TelNetworkInfoGetLacPageIssue Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 *	-# The privilege group is changed from TELEPHONY to TELEPHONY_LOCATION in bada API version 2.0.
	 */

	/**
	 * Gets the received signal strength indication of a modem device.
	 *
	 * @since			2.0
	 * @privlevel		NORMAL
	 * @privgroup 		TELEPHONY

	 * @return		The current RSSI @n 
	 *				The possible RSSI value ranges from @c 0 to @c 100.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM       			A system error has occurred.
	 */
	static int GetRssi(void);

private : 
	int __mcc;
	int __mnc;
	Osp::Base::String __plmn;
	int __cellId;
	int __lac;


	friend class __NetworkManagerPi;

private : 
	friend class NetworkInfoEx;
	class NetworkInfoEx* __pNetworkInfoEx;
	
};

};};
#endif // _FTEL_NETWORK_INFO_H_
