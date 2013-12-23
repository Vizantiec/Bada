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
 * @file	FNetWifiWifiNetAccountInfo.h
 * @brief	This is the header file for the %WifiNetAccountInfo class.
 *
 * This header file contains the declarations of the %WifiNetAccountInfo class.
 */
#ifndef FNET_WIFI_WIFINETACCOUNTINFO_H
#define FNET_WIFI_WIFINETACCOUNTINFO_H

// Includes
#include "FBaseObject.h"
#include "FNetNetAccountInfo.h"
#include "FNetWifiWifiSecurityInfo.h"

namespace Osp {
	namespace Net {

class NetAccountManager;

}}


namespace Osp {
	namespace Net {
		namespace Wifi {

// Forward declaration
class WifiNetAccountInfoEx;

/**
 * @class	WifiNetAccountInfo
 * @brief	This class provides the functionality to control the WLAN network accounts.
 * @since	1.0
 *
 * 	The %WifiNetAccountInfo class provides the functionality to control the WLAN network accounts and the basic network accounts. This class inherits the 
 *			NetAccountInformation class.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _EXPORT_NET_ WifiNetAccountInfo :
	public Osp::Net::NetAccountInfo
{
// Lifecycle
private:
	/*
	 * This is the default constructor for this class.
	 * @since		1.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
	 * @see			Construct()
	 */
	WifiNetAccountInfo(void);

	/*
	 * Initializes this instance of %WifiNetAccountInfo with the specified wifiNetAccountInfo instance. @n
	 * Note that only the data part is cloned. Attributes such as NetAccountID and connection status with the registry are set to their default values.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	wifiNetAccountInfo		A %WifiNetAccountInfo instance to initialize the calling instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_INVALID_ARG			The specified @c wifiNetAccountInfo is invalid.
	 */
	result Construct(const WifiNetAccountInfo& wifiNetAccountInfo);

	/*
	 * Initializes this instance of PrimaryNetAccountInformation with the specified ProtoNetInfo object.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 */
	result Construct(void);

// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~WifiNetAccountInfo(void);

// Operation
public:
	/**
	* Gets the BSSID of this account.
	*
	* @since	1.0
	* @return	BSS ID in the form '00-00-00-00-00-00'
	* @remarks	This operation is not yet supported.
	*/
	Osp::Base::String GetBssId(void) const;

	/**
	* Gets the SSID of this account.
	*
	* @since	1.0
	* @return	The SSID of this account
	*/
	Osp::Base::String GetSsid(void) const;

	/**
	* Gets the type of BSS of this account.
	*
	* @since	1.0
	* @return	The type of BSS of this account
	*/
	WifiBssType GetBssType(void) const;

	/**
	* Gets the security information of this account.
	*
	* @since	1.0
	* @return   The authentication and encryption type of this account
	*/
	const WifiSecurityInfo* GetSecurityInfo(void) const;


	/**
	* Gets the radio channel of this account. @n
	* If this value is not set, the default value is WIFI_RADIO_CHANNEL_UNKNOWN.
	*
	* @since		1.0
	* @return		The radio channel of this account
	* @remarks		This operation is not yet supported.
	*/
	WifiRadioChannel GetRadioChannel(void) const;

private:
	/*
	* Sets the BSSID of this account.
	*
	* @param[in]	bssId		The BSSID to be set
	* @remarks		The BSSID is not yet supported.
	*/
	void SetBssId(Osp::Base::String& bssId);

	/*
	* Sets the SSID of this account.
	*
	* @param[in]	ssid		The SSID to be set
	*/
	void SetSsid(Osp::Base::String& ssid);



	/*
	* Sets the type of BSS of this account.
	*
	* @param[in]	bssType		The BSS type to be set
	*/
	void SetBssType(WifiBssType bssType);



	/*
	* Sets the security information of this account.
	*
	* @param[in]	secuInfo	The WifiSecurityInfo to be set
	*/
	void SetSecurityInfo(const WifiSecurityInfo& secuInfo);


	/*
	* Sets the radio channel of this account.
	*
	* @param[in]	channel		The channel value to be set
	* @remarks		Channel control is not yet supported.
	*/
	void SetRadioChannel(WifiRadioChannel channel);

	WifiNetAccountInfo(const WifiNetAccountInfo& value);
	WifiNetAccountInfo& operator =(const WifiNetAccountInfo& value);
private:

	WifiBssType 			__bssType;
	Osp::Base::String		__ssid;
	WifiSecurityInfo		__secuInfo;

	Osp::Base::String		__bssId;		// NOT SUPPORTED
	WifiRadioChannel 		__channel;		// NOT SUPPORTED

	WifiNetAccountInfoEx*			__pWifiNetAccountInfoEx;

	friend class WifiNetAccountManager;
	friend class __AdhocServiceAgent;
	friend class __WifiNetAccountPi;
	friend class Osp::Net::NetAccountManager;
	friend class WifiNetAccountInfoEx;
};

} } }
#endif // FNET_WIFI_WIFINETACCOUNTINFO_H

