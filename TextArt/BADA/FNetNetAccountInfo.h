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
 * @file		FNetNetAccountInfo.h 
 * @brief		This is the header file for the %NetAccountInfo class.
 *
 * This header file contains the declarations of the %NetAccountInfo class.
 */
#ifndef _FNET_NET_ACCOUNT_INFO_H_
#define _FNET_NET_ACCOUNT_INFO_H_

// Includes
#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseResult.h"
#include "FBaseErrors.h"
#include "FNetNetTypes.h"
#include "FNetIPAddress.h"
#include "FNetIP4Address.h"
#include "FNetNetEndPoint.h"


namespace Osp { namespace Net {
// Forward declaration
namespace Wifi {
	class WifiNetAccountInfo;
	class WifiNetAccountManager;
	class __WifiNetAccountPi;
};

/**
 * @class	NetAccountInfo 
 * @brief	This class provides the methods for all the network accounts. 
 * @since	1.0
 *
 * The %NetAccountInfo class represents all the configuration parameters for setting up network connections. %NetAccountInfo contains the base 
 * 			information to connect various bearers and it is designed to be used for the Programmed Data Processor (PDP) context activation. The Wi-Fi 
 *			accounts are derived from this class and contain additional information specific to Wi-Fi (such as SSID).
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/network_accounts.htm">Network Accounts</a>.
 */
class _EXPORT_NET_ NetAccountInfo :
	public Osp::Base::Object
{

// Lifecycle
public:
	/** 
	* This is the default constructor for this class.
	*
	* @since	1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance. 
	*/
	NetAccountInfo(void);

	/** 
	* This is the destructor for this class.	
	*
	* @since	1.0 
	*/
	virtual ~NetAccountInfo(void);

	/** 
	 * Initializes this instance of %NetAccountInfo with the specified %NetAccountInfo instance. @n
	 * Only the data part is cloned. Attributes such as NetAccountId and the connection status, which are linked with the registry are set to default values.
	 * 
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	netAccountInfo		A %NetAccountInfo instance to initialize the calling instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_INVALID_ARG		The specified @c netAccountInfo is invalid.
	 */
	result Construct(const NetAccountInfo& netAccountInfo);

	/** 
	 *  Initializes this instance of %NetAccountInfo.
	 *
	 *  @since		1.0
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 *  @exception	E_INVALID_STATE		This instance has already been constructed.
	 */
	result Construct(void);


// Accessor
public:
	/** 
	 * Gets an account ID.
	 *
	 * @since		1.0
	 * @return		The accountID
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	 NetAccountId GetAccountId(void) const ;

	/** 
	 * Gets the name of an account.
	 *
	 * @since		1.0
	 * @return		The name of the account, @n
	 *				else a null string if the name is not set or not constructed
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAccountName()
	 */
	 Osp::Base::String GetAccountName(void) const;

	/** 
	 * Sets the name of an account. @n
	 * If this method fails, the state of this instance does not change. If the length of accountName is over @c NET_NETINFO_NAME_LEN_MAX, 
	 * the accountName string is trimmed to the length of @c NET_NETINFO_NAME_LEN_MAX.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	accountName				The name of an account
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * 
	 * @see			GetAccountName()
	 */
	result SetAccountName(const Osp::Base::String& accountName);

	/** 
	 * Gets the protocol type.
	 *
	 * @since		1.0
	 * @return		The type of the protocol 
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetProtocolType()
	 */
	NetProtocolType GetProtocolType(void) const;

	/** 
	 * Sets the protocol type.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	netProtocolType			The type of the protocol
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		If this method fails, the state of this instance does not change.
	 * @see			GetProtocolType()
	 */
	result SetProtocolType(NetProtocolType netProtocolType);

	/** 
	 * Gets an Access Point Name.
	 *
	 * @since		1.0
	 * @return		The Access Point Name, @n
	 *				else a null string if the name is not set or the instance is not constructed
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAccessPointName()
	 */
	Osp::Base::String GetAccessPointName(void) const;

	/** 
	 * Sets the name of the access point. @n
	 * If this method fails, the state of this instance does not change. If the length of accessPointName is over @c NET_APN_ADDR_LEN_MAX, 
	 * the accessPointName string is trimmed to the length of @c NET_APN_ADDR_LEN_MAX.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	accessPointName			The Access Point Name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @see			GetAccessPointName()
	 */
	result SetAccessPointName(const Osp::Base::String& accessPointName);

	/**
	 * Gets the setting for the local address scheme. @n
	 * This scheme can be dynamic or static.
	 *
	 * @since		1.0
	 * @return		The address scheme
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLocalAddress(), GetLocalAddress()
	 */
	NetAddressScheme GetLocalAddressScheme(void) const;

	/** 
	 * Gets the local address.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountInfoPage "here".
	 *
	 * @return			The local address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception		E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @exception		E_INVALID_ARG			This operation is not allowed in the dynamic address scheme @b since: @b 1.1.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme @b since: @b 2.0.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetLocalAddress() 
	 */
	const IpAddress*  GetLocalAddress(void) const;

	/** 
	 * Enables or disables the use of a static local IP address. 
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	localAddrScheme			An indicator specifying whether to use a static local IP address
	 * @param[in]	pLocalAddress			The local IP address @n
     *										If @c localAddrScheme is set to NET_ADDRESS_SCHEME_STATIC, the local IP address assigned is static.
     *										If @c localAddrScheme is set to NET_ADDRESS_SCHEME_DYNAMIC or NET_ADDRESS_SCHEME_NONE, this parameter is ignored.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * 				
	 * @see			GetLocalAddress()		
	 */
	result SetLocalAddress(NetAddressScheme localAddrScheme, const IpAddress* pLocalAddress);

	/**
	 * Gets the setting for the DNS address scheme.
	 *
	 * @since		1.0
	 * @return		The address scheme for the DNS
	 * @exception	E_SUCCESS			The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetPrimaryDnsAddress(), GetSecondaryDnsAddress(), SetDnsAddress()
	 */
	NetAddressScheme GetDnsAddressScheme(void) const;

	/**
	 * Gets the setting for the primary DNS address.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountInfoPage "here".
	 *
	 * @return			The IpAddress of primary DNS address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG			This operation is not allowed in the dynamic address scheme.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme @b since: @b 2.0. 
	 *
	 * @remarks			When this instance is got by @ref NetAccountManager::GetNetAccountInfoN, 
	 *					- this method returns a statically assigned primary DNS address pointer if the DNS address scheme is NET_ADDRESS_SCHEME_STATIC
	 *					- this method returns @n null if the DNS address scheme is NET_ADDRESS_SCHEME_DYNAMIC @n
	 * 		The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetSecondaryDnsAddress()
	 */
	const IpAddress* GetPrimaryDnsAddress(void) const;

	/**
	 * Gets the setting for the secondary DNS address.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref NetAccountInfoPage "here".
	 *
	 * @return			The secondary DNS IP address, @n
	 *					else @c null if an error occurs or the dynamic address scheme is being used
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG			This operation is not allowed in the dynamic address scheme.
	 * @exception		E_INVALID_OPERATION		This operation is not allowed in the dynamic address scheme @b since: @b 2.0. 
	 *
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				SetDnsAddress()
	 */
	const IpAddress* GetSecondaryDnsAddress(void) const;

	/**
	 * @page		NetAccountInfoPage	Compatibility for %NetAccountInfo class
	 *
	 * @section		NetAccountInfoPageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# This method sets the last result by E_INVALID_ARG when the address scheme is dynamic.
	 *
	 * @section		NetAccountInfoPageResolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0. @n
	 * -# This method sets the last result by E_INVALID_OPERATION when the address scheme is dynamic. 
	*/

	/**
	 * Enables or disables the use of a static DNS address with the specified IpAddress objects. @n
	 * If @c dnsAddrScheme is NET_ADDRESS_SCHEME_DYNAMIC, both @c primaryDnsAddress and @c secondaryDnsAddress are ignored. @n
	 * If @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC, @c primaryDnsAddress should be a valid IpAddress. 
	 * However, @c pSecondaryDnsAddress can be @c null. 
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	dnsAddrScheme			An indicator specifying whether or not to use a static DNS address
	 * @param[in]	pPrimaryDnsAddress		The statically assigned primary DNS address if @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC
	 * @param[in]	pSecondaryDnsAddress	The statically assigned secondary DNS address if @c dnsAddrScheme is NET_ADDRESS_SCHEME_STATIC
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *				
	 * @see			GetPrimaryDnsAddress(), GetSecondaryDnsAddress()
	 */
	result SetDnsAddress(NetAddressScheme dnsAddrScheme, 
		const IpAddress* pPrimaryDnsAddress,  const IpAddress* pSecondaryDnsAddress);

	/** 
	 * Gets the proxy address of the network accounts.
	 *
	 * @since		1.0
	 * @return		The proxy address, @n
	 *				else @c null if an error occurs or the address is not set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
     * @exception	E_UNSUPPORTED_FORMAT	The specified address format is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const NetEndPoint* GetProxyAddress(void) const;

	/** 
	 * Sets the proxy address of the network accounts.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	pProxyEndPoint			A pointer to a NetEndPoint instance containing the IP address and port
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		If this method fails, the state of this instance does not change.  
	 *
	 */
	result SetProxyAddress(NetEndPoint* pProxyEndPoint);

	/** 
	 * Gets the authentication configuration of network accounts. @n
	 * The user is not provided with read access to the credential information present in the registry if the network account information is extracted from 
	 * the registry using @ref NetAccountManager::GetNetAccountInfoN().
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	authenticationType	The type of the authentication used
	 * @param[out]	id					The ID
	 * @param[out]	password			The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_ILLEGAL_ACCESS	The user is not provided with read access to the credential information present in the registry, if the network 
	 *									account information is extracted from the registry using NetAccountManager::GetNetAccountInfoN().
	 *
	 * @remarks		If this method fails, the state of this instance does not change.  
	 * @see			SetAuthenticationInfo()
	 *
	 */
	result GetAuthenticationInfo(NetNapAuthType& authenticationType,
		Osp::Base::String& id, Osp::Base::String& password) const;

	/** 
	 * Sets the authentication configuration of the network accounts. @n
	 * If the length of ID is over @c NET_AUTH_ID_LEN_MAX, it is trimmed to @c NET_AUTH_ID_LEN_MAX length. @n
	 * If the length of Password is over @c NET_AUTH_PASSWD_LEN_MAX, it is trimmed to @c NET_AUTH_PASSWD_LEN_MAX length.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	NET
	 *
	 * @return		An error code
	 * @param[in]	authenticationType	The type of the authentication used
	 * @param[in]	id					The ID
	 * @param[in]	password			The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		If this method fails, the state of this instance does not change.  
	 * @see			GetAuthenticationInfo(), NET_AUTH_ID_LEN_MAX, NET_AUTH_PASSWD_LEN_MAX
	 *				
	 */
	result SetAuthenticationInfo(NetNapAuthType authenticationType,
		const Osp::Base::String& id, const Osp::Base::String& password);

	/**
	 * Gets the operational bearer type of this account.
	 *
	 * @since		1.0
	 * @return		The operational bearer type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	NetBearerType GetBearerType(void) const ;

	/**
	 * Gets the maximum length of the user name.
	 *
	 * @since		1.0
	 * @return		The maximum length of the user name
	 */
	int GetMaximumLengthOfId(void);

	/**
	 * Gets the maximum length of the password.
	 *
	 * @since		1.0
	 * @return		The maximum length of the password
	 */
	int GetMaximumLengthOfPassword(void);

	/**
	 * Gets the maximum length of the account name.
	 *
	 * @since		1.0
	 * @return		The maximum length of the account name
	 */
	int GetMaximumLengthOfAccountName(void);

	/**
	 * Gets a value that indicates whether the network account is read-only. @n
	 * If it returns @c true, this account is read-only; so any change to this account is not permitted. @n
	 * When it returns @c false, modification is possible.
	 *
	 * @since		1.0
	 * @return		@c true if this account is read only, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful @b since: @b 1.1.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet @b since: @b 1.1.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsReadOnly(void) const ;


private:
	/*
	 * @Internal
	 * Sets Operation bearer type of this Account
	 *				
	 * @return		An error code
	 * @param[in]	bearerType				The type of bearer this account is intended to @n For example, PDP, WLAN
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 */
	result SetBearerType(NetBearerType bearerType);


private:
// Accessor
	/** 
	 * Gets the authentication configuration of the network accounts.
	 *
	 * @return		An error code
	 * @param[out]	pNetAccountAuthentication	The authentication configuration of a network account
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				The requested configuration parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 *
	 * @see			SetAuthentication()
	 */
	result GetAuthentication(NetNapAuthType& authenticationType,
		Osp::Base::String& id, Osp::Base::String& password) const;

	/** 
	 * Sets an account ID.
	 *
	 * @return		An error code
	 * @param[in]	account ID				The ID of the account
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The requested configuration parameter is invalid.
	 */
	 result SetAccountId(NetAccountId accountId) ;

// Inquiry
	/** 
	 * Gets a value that indicates whether the network account is in service.
	 *
	 * @warning		This is a prototype.
	 *
	 * @return		An error code
	 * @param[out]	on						Set to @c true, if this account is in service, @n
	 *										else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ACCOUNT		The account ID of this instance is not valid.
	 * @exception	E_FAILURE				The method has failed.
	 *
	 * @remarks		If on is @c true, this account is in service so any change to this account is not permitted. 
	 *				When this account is not in service, modification is possible.
	 *				
	 */
	result IsInService(bool& on) const;


// Member variables 
private :
//lifecycle
	bool __isConstructed;

private:
//information buffer
	NetBearerType __opMode;

private:
//attribute
	NetProtocolType __protocolType;
	
	Osp::Base::String __apn;	//Access Point Name

	NetAddressScheme __localAddrScheme;
	NetAddressScheme __dnsAddrScheme;

	IpAddress* __pLocalAddress;
	IpAddress* __pPrimaryDnsAddress;
	IpAddress* __pSecondaryDnsAddress;

	NetEndPoint* __pProxyEndPoint;

	NetNapAuthType	__authType;
	Osp::Base::String __szAuthId;
	Osp::Base::String __szAuthPasswd; 
	
	Osp::Base::String __szAccountName;	// Account name

	Net::NetAccountId __accountId;		// equal to hProtoAccount in System
	bool __isReadOnly;
	bool __isRefdFromRegistry;	// Whether this AccountInformation is read from AccountDB or compatible storage (ex. Registry)
	bool __isValid;

// Friend class declaration.
	friend class NetAccountManager;
	friend class NetConnection;
	friend class Wifi::WifiNetAccountInfo;
	friend class Wifi::WifiNetAccountManager;
	friend class Wifi::__WifiNetAccountPi;

	friend class NetAccountInfoEx;
	class NetAccountInfoEx* __pNetAccountInfoEx;
};

}; }; // Osp::Net

#endif // _FNET_NET_ACCOUNT_INFORMATION_H_
