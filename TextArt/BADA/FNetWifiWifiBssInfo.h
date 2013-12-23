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
 * @file	FNetWifiWifiBssInfo.h
 * @brief	This is the header file for the %WifiBssInfo class.
 *
 * This header file contains the declarations of the %WifiBssInfo class.
 */
#ifndef FNET_WIFI_WIFIBSSINFO_H
#define FNET_WIFI_WIFIBSSINFO_H

// Includes
#include "FNetConfig.h"
#include "FBaseObject.h"
#include "FNetWifiWifiTypes.h"
#include "FNetWifiWifiSecurityInfo.h"

namespace Osp { namespace Net { namespace Wifi {

class WifiBssInfoEx;

/**
 * @class	WifiBssInfo
 * @brief	This class provides the methods for managing the BSS information of a Wi-Fi network.
 * @since	1.0
 *
 * The %WifiBssInfo class provides the methods for managing the BSS information of a Wi-Fi network.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _EXPORT_NET_ WifiBssInfo :
	public Osp::Base::Object
{

public:
	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~WifiBssInfo(void);

// Lifecycle
private:
	/*
	* This is the default constructor for this class.
	*
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
	* @see			Construct()
	*/
	WifiBssInfo(void);

	/*
	* This is the copy constructor for the WifiBssInfo class.
	*
	* @param[in] 	value				An instance of %WifiBssInfo
	*/
	WifiBssInfo(const WifiBssInfo& value);

	/*
	* This assignment operator copies BSS information from the specified instance of %WifiBssInfo to the calling instance of %WifiBssInfo.
	*
	* @return		The reference of this instance
	* @param[in] 	value		A reference to the %WifiBssInfo instance to be copied
	*/
	WifiBssInfo& operator =(const WifiBssInfo& value);

// Operation
public:
	/**
	* Gets the SSID of this BSS.
	*
	* @since		 1.0
	* @return		 The SSID
	*/
	Osp::Base::String GetSsid(void) const;

	/**
	* Gets the ID of this BSS.
	*
	* @since		 1.0
	* @return		 The BSSID in the form '00-00-00-00-00-00'
	*/
	Osp::Base::String GetBssId(void) const;

	/**
	* Gets the type of this BSS.
	*
	* @since		1.0
	* @return		The type of this BSS
	*/
	WifiBssType GetBssType(void) const;

	/**
	* Gets the radio channel of this BSS.
	*
	* @since		1.0
	* @return		The radio channel of this BSS
	*/
	WifiRadioChannel GetRadioChannel(void) const;

	/**
	* Gets the security information of this BSS.
	*
	* @since		1.0
	* @return		The authentication and encryption type of this BSS
	*/
	const WifiSecurityInfo* GetSecurityInfo(void) const;

	/**
	* Gets the Received Signal Strength Indication (RSSI) value of the BSS at the time of scanning.
	*
	* @since		1.0
	* @return		The RSSI value in dbm
	*/
	long GetRssi(void) const;

	/**
	* Gets the data rate of this BSS.
	*
	* @since		1.0
	* @return		The data rate value (Mbps),
	*				else @c -1.0 if the supported data rate is unknown
	*/
	float GetDataRate(void) const;

private:
	/*
	* Sets the SSID of this BSS.
	*
	* @param[in] 	ssid		The SSID
	*/
	void SetSsid(Osp::Base::String& ssid);

	/*
	* Sets the ID of this BSS.
	*
	* @param[in] 	bssId		The BSSID in the form '00-00-00-00-00-00'
	*/
	void SetBssId(Osp::Base::String& bssId);

	/*
	* Sets the type of this BSS.
	*
	* @param[in] 	bssType		The type of this BSS
	*/
	void SetBssType(WifiBssType bssType);

	/*
	* Sets the radio channel of this BSS.
	*
	* @param[in] 	channel		The radio channel of this BSS
	*/
	void SetRadioChannel(WifiRadioChannel channel);

	/*
	* Sets the security information of this BSS.
	*
	* @param[in] 	secuInfo	The authentication and encryption type of this BSS
	*/
	void SetSecurityInfo(const WifiSecurityInfo& secuInfo);

	/*
	* Sets the Received Signal Strength Indication (RSSI) value of BSS at scanning time
	*
	* @param[in] 	rssi		The RSSI value (dB)
	*/
	void SetRssi(long rssi);

	/*
	* Sets the data rate of this BSS.
	*
	* @param[in] 	dataRate	The data rate value (Mbps)
	* @remarks		If the supported data rate is unknown, default value is @c -1.0.
	*/
	void SetDataRate(float dataRate);

private:

	Osp::Base::String		__ssid;
	Osp::Base::String		__bssId;
	WifiBssType 			__bssType;
	WifiRadioChannel 		__channel;
	WifiSecurityInfo		__secuInfo;
	long					__rssi;
	float					__dataRate;

	WifiBssInfoEx*			__pWifiBssInfoEx;

	friend class WifiBssInfoEx;
	friend class __WifiManagerAgent;
	friend class __WifiManagerPiClientReceiver;
};

} } }
#endif // FNET_WIFI_WIFIBSSINFO_H

