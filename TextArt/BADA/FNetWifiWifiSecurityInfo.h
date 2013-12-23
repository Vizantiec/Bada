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
 * @file		FNetWifiWifiSecurityInfo.h
 * @brief		This is the header file for the %WifiSecurityInfo class.
 *
 * This header file contains the declarations of the %WifiSecurityInfo class.
 */
#ifndef FNET_WIFI_WIFISECURITYINFO_H
#define FNET_WIFI_WIFISECURITYINFO_H

// Includes
#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FNetWifiWifiTypes.h"


namespace Osp { namespace Net {

class __NetAccountPi;

}}


namespace Osp { namespace Net { namespace Wifi {

class WifiSecurityInfoEx;

/**
 * @class	WifiSecurityInfo
 * @brief	This class provides the methods to manage the security information of a Wi-Fi network.
 * @since	1.0
 *
 * 	The %WifiSecurityInfo class is used with the WifiNetAccountInfo class to set and get the security information of a Wi-Fi network.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _EXPORT_NET_ WifiSecurityInfo :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	WifiSecurityInfo(void);

	/**
	 * This is the copy constructor for the %WifiSecurityInfo class.
	 *
	 * @since		1.0
	 * @param[in]	value		An instance of %WifiSecurityInfo
	 */
	WifiSecurityInfo(const WifiSecurityInfo& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~WifiSecurityInfo(void);

// Operation
public:
	/**
	 * Gets the authentication type of this account.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref WifiSecurityGetAuthenticationTypePage "here".
	 *
	 * @return			The authentication type of this account
 	 */
	WifiAuthenticationType GetAuthenticationType(void) const;

	/**
	 * @page		WifiSecurityGetAuthenticationTypePage	Compatibility for GetAuthenticationType()
	 *
	 * @section		WifiSecurityGetAuthenticationTypePageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Returns the WIFI_AUTHENTICATION_WPA2_PSK Wi-Fi authentication type even though both the
	 * Wi-Fi Protected Access (WPA) and Wi-Fi Protected Access II (WPA2) protocols are supported.
	 *
	 * @section		WifiSecurityGetAuthenticationTypePageSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# Returns the WIFI_AUTHENTICATION_WPA_WPA2_MIXED_PSK Wi-Fi authentication type if both the 
	 * Wi-Fi Protected Access (WPA) and Wi-Fi Protected Access II (WPA2) protocols are supported.
	 *
	 * @par 	When working with bada API versions prior to 2.0:
	 * -# Use the WPA2 protocol when the WIFI_AUTHENTICATION_WPA2_PSK Wi-Fi authentication type
	 * is returned regardless of whether the WPA2 protocol or a combination of WPA and WPA2 protocols is supported.
	 */

	/**
	 * Gets the encryption type of this account.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref WifiSecurityGetEncryptionTypePage "here".
	 *
	 * @return			The encryption type
	 * @remarks			If the encryption type is WIFI_ENCRYPTION_TKIP_AES_MIXED, either SetNetworkKeyAes() or
	 SetNetworkKeyTkip() can be used to set the key.  
	 */
	WifiEncryptionType GetEncryptionType(void) const;

	/**
	 * @page	WifiSecurityGetEncryptionTypePage	Compatibility for GetEncryptionType()
	 *
	 * @section		WifiSecurityGetEncryptionTypePageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Returns the WIFI_ENCRYPTION_AES encryption type even though both Temporal Key Integrity
	 * Protocol (TKIP) and Advanced Encryption Standard (AES) are supported.
	 *
	 * @section		WifiSecurityGetEncryptionTypePageSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# Returns the WIFI_ENCRYPTION_TKIP_AES_MIXED encryption type if both Temporal Key Integrity
	 * Protocol (TKIP) and Advanced Encryption Standard (AES) are supported
	 *
	 * @par		When working with bada API versions prior to 2.0:
	 * -# Use the AES when the WIFI_ENCRYPTION_AES encryption type is returned regardless of
	 * whether the AES or a combination of TKIP and AES is supported.
	 */

	/**
	 * Sets the Wired Equivalent Privacy (WEP) key data.
	 *
	 * @since			1.0
	 *
	 * @return			An error code
	 * @param[in]		keyLen					A WifiWepKeyLen enumerator value
	 * @param[in]		keyIndex				The key index of WEP key to be set
	 * @param[in]		key						The key data to be set
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			The length of the specified @c key exceeds 10 bytes when the
	 *											value of @c keyLen is Wifi::WIFI_WEP_KEY_LEN_64BIT,
     *                                          or the length of the specified @c key exceeds 26 bytes when
	 *											the value of @c keyLen is Wifi::WIFI_WEP_KEY_LEN_128BIT.
     * @exception		E_SYSTEM  				A system error has occurred.
	 */
	result SetNetworkKeyWep (WifiWepKeyLen  keyLen, WifiWepKeyIndex keyIndex, const Osp::Base::String& key);

	/**
	 * Sets the Advanced Encryption Standard (AES) key data.
	 *
	 * @since			1.0
	 *
	 * @return			An error code
	 * @param[in]		key						The key data to be set
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			The length of the specified @c key exceeds 64 bytes.
	 * @exception		E_SYSTEM  				A system error has occurred.
	 */
	result SetNetworkKeyAes(const Osp::Base::String& key);

	/**
	 * Sets the Temporal Key Integrity Protocol (TKIP) key data.
	 *
	 * @since			1.0
	 *
	 * @return			An error code
	 * @param[in]		key						The key data to be set
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			The length of the specified @c key exceeds 64 bytes.
	 * @exception		E_SYSTEM  				A system error has occurred.
	 */
	result SetNetworkKeyTkip (const Osp::Base::String& key);

	/**
	 * Sets the Extensible Authentication Protocol (EAP) method information.
	 *
	 * @since			1.2
	 *
	 * @return			An error code
	 * @param[in]		type							The EAP method type
	 * @param[in]		userId							The user ID to be set @n
	 *													Its length should not exceed @c 256 bytes.
	 * @param[in]		password						The password to be set @n
	 *													Its length should not exceed @c 256 bytes.
	 * @param[in]		validateServerCertificate		Set to @c true to determine the validation of the server certificate, @n
	 *													else @c false
	 * @exception		E_SUCCESS						The method is successful.
	 * @exception		E_INVALID_ARG					The length of the specified @c userId or @c password exceeds @c 256 bytes.
	 * @exception		E_UNSUPPORTED_TYPE				The input @c type is not supported.
	 * @exception		E_SYSTEM  						A system error has occurred.
	 */
	result SetEapMethodInfo (WifiEapType type, const Osp::Base::String& userId, const Osp::Base::String& password, bool validateServerCertificate = true);

private:
	/*
	 * This assignment operator copies the Wi-Fi security information from the specified instance of %WifiSecurityInfo to the calling instance of 
	 * %WifiSecurityInfo.
	 *
	 * @return			The reference of this instance
	 * @param[in]		rhs 		A reference to the %WifiSecurityInfo instance to be copied
	 */
	WifiSecurityInfo& operator=(const WifiSecurityInfo& rhs);

	/*
	 * Sets the authentication type of this account.
	 *
	 * @param[in]		authType			The authentication type
	 */
	void SetAuthenticationType(WifiAuthenticationType authType);

	/*
	 * Sets the encryption type of this account.
	 *
	 * @param[in]		encryptionType			The encryption type
	 */
	void SetEncryptionType(WifiEncryptionType encryptionType);

protected:
	/*
	 * @brief			Defines IEEE 802.11 security key with the WEP encryption.
	 */
	typedef struct
	{
		WifiWepKeyLen 	keyLen;		///< WEP Key length(64 or 128 bits).
		int 			keyIndex;	///< WEP Key index(must be 1, 2, 3, or 4).
		KeyData 		key[WIFI_MAX_KEY_LEN_WEP + 1];	///< WEP key value.
	} WifiNetworkKeyWep;

	/*
	 * @brief			Defines IEEE 802.11 security key with the AES encryption.
	 */
	typedef struct
	{
		KeyData	key[WIFI_MAX_KEY_LEN_AES + 1]; 	/**< The AES key value. */
	} WifiNetworkKeyAes;

	/*
	 * @brief			Defines the type definition of IEEE 802.11 security key with the TKIP encryption.
	 */
	typedef struct
	{
		KeyData	key[WIFI_MAX_KEY_LEN_TKIP + 1];	/**< The TKIP key value */
	} WifiNetworkKeyTkip;

private:
	WifiAuthenticationType		__authType;
	WifiEncryptionType			__encrypType;

	WifiNetworkKeyWep			__wepKey;
	WifiNetworkKeyAes			__aesKey;
	WifiNetworkKeyTkip			__tkipKey;

	WifiSecurityInfoEx*			__pWifiSecurityInfoEx;

	friend class WifiSecurityInfoEx;
	friend class WifiNetAccountInfo;
	friend class WifiBssInfo;
	friend class __AdhocServiceAgent;
	friend class Osp::Net::__NetAccountPi;
	friend class __WifiNetAccountPi;
	friend class __WifiManagerPiClientReceiver;
};

} } }
#endif // FNET_WIFI_WIFISECURITYINFO_H

