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
 * @file		FNetNetAccountManager.h 
 * @brief		This is the header file for the %NetAccountManager class.
 *
 * This header file contains the declarations of the %NetAccountManager class.
 */
#ifndef _FNET_NET_ACCOUNT_MANAGER_H_
#define _FNET_NET_ACCOUNT_MANAGER_H_

// Includes
#include "FBaseString.h"
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FBaseColIList.h"
#include "FBaseColArrayList.h"
#include "FBaseColArrayListT.h"
#include "FNetNetTypes.h" 
#include "FNetNetAccountInfo.h"

namespace Osp { namespace Net {
// Forward declaration
typedef struct __NetInfo NetInfo;
class INetAccountPi;
/**
 * @class	NetAccountManager 
 * @brief	This class provides the methods for creating, deleting, and administering network accounts in the system.
 * @since	1.0
 *
 * 	The %NetAccountManager class provides the methods for creating, deleting, and administering components that can be used for configuring the 
 *			network accounts. These accounts can then be used for connecting to the network.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/network_accounts.htm">Network Accounts</a>.
 */
class _EXPORT_NET_ NetAccountManager :
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
	NetAccountManager(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
 	 */
	virtual	~NetAccountManager(void);

	/** 
	 * Initializes this instance of %NetAccountManager.
	 *  
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_SYSTEM			An internal initialization procedure has failed.
	 */
	result Construct(void);


public :
	/**
	 * Creates a new network account.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref CreateNetAccountPage1 "here".
	 *
	 * @privlevel		SYSTEM
	 * @privgroup		NET_ACCOUNT
	 *
	 * @return			The @c NetAccountId assigned by the creation of a new network account, @n 
	 *					else @c	INVALID_HANDLE if an error occurs
	 * @param[in,out]	netAccountInfo		A NetAccountInfo instance specifying network information to create an account in the registry
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_MAX_EXCEEDED		The registry is full. Cannot create a new network account.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks			This method creates a new network account and returns a @c NetAccountId value that can be used in method calls later to operate on the 
	 *					account. If @c INVALID_HANDLE is returned, the specific error code can be accessed using the GetLastResult() method. A Wi-Fi account 
	 *					cannot be created using %NetAccountManager.
	 * @see				GetNetAccountInfoN(), UpdateNetAccount(), DeleteNetAccount()
	 */
	NetAccountId CreateNetAccount(NetAccountInfo& netAccountInfo);

	/**
     * @page		CreateNetAccountPage1	Compatibility for CreateNetAccount()
     *
     * @section		CreateNetAccountPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# This method can create a network account even if the same account name exists.
     *
     * @section		CreateNetAccountPage1ResolutionSection Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
    */

	/**
	 * Deletes a network account from the registry. @n
	 * If the account is read-only or in service, the deletion fails. The Wi-Fi accounts cannot be deleted by %NetAccountManager.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref NetAccountManagerDeleteNetAccountPage1 "here".
	 *
	 * @privlevel	SYSTEM
	 * @privgroup	NET_ACCOUNT
	 *
	 * @return		An error code
	 * @param[in]	netAccountId		A %NetAccountId instance containing valid account information
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *									the network account is not modifiable at this time.
	 * @exception	E_INVALID_ACCOUNT	The specified network account is invalid.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		If the network account is created by another application, this method fails.
	 *				This method should use a warning pop-up to notify the user.
	 * @see			CreateNetAccount(), GetNetAccountInfoN(), UpdateNetAccount()
	 */
	result DeleteNetAccount(NetAccountId netAccountId);

	/**
     * @page		NetAccountManagerDeleteNetAccountPage1	Compatibility for DeleteNetAccount()
     *
     * @section		NetAccountManagerDeleteNetAccountPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
     * -# This method can delete the network account created by another application.
     * -# If the user sets an invalid proxy address, the application terminates abnormally.
     *
     * @section		NetAccountManagerDeleteNetAccountPage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

	/**
	 * Updates an existing network account.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountManagerUpdateNetAccountPage1 "here".
	 *
	 * @privlevel		SYSTEM
	 * @privgroup		NET_ACCOUNT
	 *
	 * @return			An error code
	 * @param[in]		netAccountInfo		A %NetAccountInfo instance containing network information to update an account
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet, or @n 
	 *                                  	this operation is not allowed on this network account.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception		E_INVALID_ACCOUNT	The input is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks			If the network account is read-only or in service, this method fails. A Wi-Fi account cannot be updated using %NetAccountManager.
	 * 					Before calling this method, the user should call GetNetAccountInfoN() to get the latest information in the registry and change 
	 * 					the desired fields of that information.
	 *					If the network account is created by another application, this method fails.
	 *					This method should use a warning pop-up to notify the user.
	 * @see				CreateNetAccount(), GetNetAccountInfoN(), UpdateNetAccount(), DeleteNetAccount()
	 */
	result UpdateNetAccount(const NetAccountInfo& netAccountInfo);

	/**
     * @page		NetAccountManagerUpdateNetAccountPage1	Compatibility for UpdateNetAccount()
     *
     * @section		NetAccountManagerUpdateNetAccountPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
     * -# This method can update the network account created by another application.
     * -# This method can update the network account even though the same account name exists.
     * -# If the user sets an invalid proxy address, the application terminates abnormally.
     *
     * @section		NetAccountManagerUpdateNetAccountPage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
    */

	/**
	 * Gets the information on a network account.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountManagerGetNetAccountInfoNPage1 "here".
	 *
	 * @return			A NetAccountInfo instance containing account information
	 * @param[in]		netAccountId		The account ID whose information is required			
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet, or @n 
	 *                                  	this operation is not allowed on this network account.
	 * @exception		E_INVALID_ACCOUNT	The specified network account is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception		E_INVALID_PROXY		The proxy address is invalid @b since: @b 2.0.
	 * @remarks			This method returns the %NetAccountInfo instance for a PS account (NET_BEARER_PS) or the WifiNetAccountInfo instance for a WLAN 
	 *					account (NET_BEARER_WIFI) in the %NetAccountInfo type. The Wi-Fi account info contains the default %NetAccountInfo and additional 
	 *					Wi-Fi specific information. The type of instance returned can be determined by calling the GetBearerType() method of the returned 
	 *					instance. The instance can then be cast down to %WifiNetAccountInfo and used in a NET_BEARER_WIFI case. If the application gets the 
	 *					last result by E_INVALID_PROXY, it should use a warning pop-up to notify the user.
	 * @see				CreateNetAccount(), UpdateNetAccount(), DeleteNetAccount()
	 */
	NetAccountInfo* GetNetAccountInfoN(NetAccountId netAccountId);

	/**
     * @page		NetAccountManagerGetNetAccountInfoNPage1	Compatibility for GetNetAccountInfoN()
     *
     * @section		NetAccountManagerGetNetAccountInfoNPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the user sets an invalid proxy address, the application terminates abnormally.
     *
     * @section		NetAccountManagerGetNetAccountInfoNPage1ResolutionSection	Resolutions
	 * -# If the user sets an invalid proxy address, this method sets the last result by E_INVALID_PROXY instead of being terminated abnormally. @n
    */

	/**
	 * Gets a list of all the accounts in the registry.
	 *
	 * @since		1.0
	 * @return 		An IList with NetAccoundIds, which are in the registry 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n 
	 *                                  this operation is not allowed on this network account.
	 * @exception	E_OBJ_NOT_FOUND		The %NetAccountInfo is not found in the registry.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	Osp::Base::Collection::IListT<NetAccountId>*  GetNetAccountIdsN(void) const;

	/**
	 * Gets a list of names of all the registered accounts.
	 *
	 * @since		1.0
	 * @return		An IList containing the indexes to the NetAccountInfos in the registry 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n 
     *                                  this operation is not allowed on this network account.
	 * @exception	E_OBJ_NOT_FOUND		The %NetAccountInfo is not found in the registry.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband or system).
	 */
	Osp::Base::Collection::IList* GetNetAccountNamesN(void) const;

	/**
	 * Gets a network account, which has the specified name.
	 *
	 * @since		1.0
	 * @return		The NetAccountID with the given name, @n
	 *				else @c INVALID_HANDLE in case of an error or if %NetAccountInfo is not found
	 * @param[in]	netAccountName		The network account name to search for
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
     *									this operation is not allowed on this network account.
	 * @exception	E_INVALID_ARG		The specified @c netAccountName is invalid or %NetAccountInfo with this name does not exist.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetAccountId GetNetAccountId(const Osp::Base::String& netAccountName) const;

	/**
	 * Gets a network account, which is set for the bada application on each bearer.
	 *
	 * @since		1.0
	 * @return		The network account, @n
	 *				else INVALID_HANDLE in case of an error or if %NetAccountInfo is not found	
	 * @param[in]	netBearerType		The network account type of bearer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *									this operation is not allowed on this network account.
	 * @exception	E_SYSTEM			An internal error has occurred (baseband).
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				If INVALID_HANDLE is returned but the last result shows success, @n
     *              show a pop-up that asks the user to select the network profile in the Settings menu.
	 */
	NetAccountId GetNetAccountId(NetBearerType netBearerType = NET_BEARER_PS) const;

	/**
	 * @if PRIVCORE
	 *
	 * Gets a network account, which is set for the application like e-mail, IM, and so on.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 *
	 * @privgroup	NET_MANAGER
	 * @return		The @c NetAccountID with the specified name, @n
	 *				else INVALID_HANDLE is returned in case of an error or if %NetAccountInfo is not found
	 * @param[in]	netProfileName		The network profile name for an application such as email
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n 
	 *									this operation is not allowed on this network account.
	 * @exception	E_INVALID_ARG		The @c netAccountName is invalid or %NetAccountInfo with this name does not exist.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	NetAccountId GetAppNetAccountId(const Osp::Base::String& netProfileName) const;

	/**
	 * @if PRIVCORE
	 *
	 * Sets the application-wise default account ID to the one specified by the input argument value.
	 *
	 * @since 			1.1 
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountManagerSetNetAccountIdPage1 "here".
	 *
	 * @privlevel		CORE
	 * @privgroup		NET_MANAGER
	 * @return			An error code
	 * @param[in]		accountId			The network account
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet, or 
	 *										@n this operation is not allowed on this network account.
	 * @exception		E_INVALID_ARG		The specified @c netAccountId is invalid.
	 * @exception		E_SYSTEM			An internal error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @endif
	 */
	result SetNetAccountId(NetAccountId netAccountId);
	
	/**
	 * @if PRIVCORE
     * @page		NetAccountManagerSetNetAccountIdPage1	Compatibility for SetNetAccountId()
     *
     * @section		NetAccountManagerSetNetAccountIdPage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the user sets an invalid proxy address, the application terminates abnormally.
     *
     * @section		NetAccountManagerSetNetAccountIdPage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * @endif
    */

	/** 
	 * Gets the preferred network.
	 *
	 * @deprecated This method is deprecated because it is moved to the %NetConnectionManager class.
	 *
	 * @since		1.0
	 * @return		The preferred network, @n
	 *				else @c NET_WIFI_FIRST in case of an error or if the preferred network is not set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
   *                                  	this operation is not allowed on this network account.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetPreferenceType GetNetPreference(void) const;

	/** 
	 * Sets the default bearer type.
	 *
	 * @deprecated		This method is deprecated because it is moved to the %NetConnectionManager class.
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref SetNetPreferencePage1 "here".
	 *
	 * @privlevel		NORMAL
	 * @privgroup		NET
	 *
	 * @return			An error code
	 * @param[in]		netPreference		The preferred network
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *                                  	this operation is not allowed on this network account.
	 * @exception		E_INVALID_OPERATION	This operation is not allowed.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks			This preference is not changed during the application life-cycle.
	 *					If this method is not used, the default connection works in the Wi-Fi first mode.
	 */
	result SetNetPreference(NetPreferenceType netPreference = NET_WIFI_FIRST);

	/**
     * @page		SetNetPreferencePage1	Compatibility for SetNetPreference()
     *
     * @section		SetNetPreferencePage1IssueSection	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# This method cannot change the network preference from a second invocation during the application life-cycle.
     *
     * @section		SetNetPreferencePage1ResolutionSection Resolutions
     * Although the issue mentioned above is resolved in bada API version 2.0, it is recommended to use a new method of the %NetConnectionManager class. @n
	 */

// internal Operation
private:
	NetAccountInfo* _GetNetAccountInfoN(NetAccountId netAccountId, NetBearerType netBearerType);
	result GetAccountInfoStatus(NetAccountId accountId, bool& bInService, bool&bIsReady);
	result ConvertNetAccountInfo(NetAccountInfo& accountInfo, NetInfo& netInfo);
	result ConvertNetInfo(NetInfo& netInfo, NetAccountInfo& accountInfo);
	result DeleteNetAccountId(NetAccountId netAccountId);

protected:

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited
	 * This method is prohibited. If this method is used in an application, the application can get rejected during the certification process.
	 *
	 * Creates a new network account.
	 *
	 * @since		1.0
	 *
	 * @return		The AccountId assigned by creation of a new network account
	 * @param[in]	netAccountInfo		A netAccountInfo instance specifying network information to create an account in the registry
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_MAX_EXCEEDED		Registry is full. Cannot create a new network account.
	 * @exception	E_SYSTEM			An internal error occurred.
	 */
	NetAccountId 	_CreateNetAccount(NetAccountInfo& netAccountInfo);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited
	 * This method is prohibited. If this method is used in an application, the application can get rejected during the certification process.
	 *
	 * Deletes a network account from registry.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	netAccountInfo		A netAccountInfo instance specifying network information to delete an account in the registry
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *									the network account is not modifiable at this time.
	 * @exception	E_INVALID_ACCOUNT	The given network account is invalid.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 * @exception	E_SYSTEM			An internal error occurred.
	 */
	result 			_DeleteNetAccount(NetAccountId netAccountId);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited
	 * This method is prohibited. If this method is used in an application, the application can get rejected during the certification process.
	 *
	 * Updates an existing network account.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	netAccountInfo		A NetAccountInfo instance containing network information to update an account
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet, or @n
	 *                                  this operation is not allowed on this network account.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_ACCOUNT	Invalid input.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_SYSTEM			An internal error occurred.
	 * @exception	E_INVALID_OPERATION	This operation is not allowed on this network account instance.
	 */
	result 			_UpdateNetAccount(const NetAccountInfo& netAccountInfo);

protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not responsible for
	 * any behavioral correctness, consistency, and security-related issues that might arise after using this variable.
	 *
	 * The flag for checking the instance construction.
	 *
	 * @since       1.0
	 */
	bool __isConstructed;

private:	// member variables
	INetAccountPi* __pNetAccountInterface;	//PI interface
	friend class NetAccountInfo;

	friend class NetAccountManagerEx;
	class NetAccountManagerEx* __pNetAccountManagerEx;
};

}; }; // Osp::Net
#endif // _FNET_NET_ACCOUNT_MANAGER_H_

