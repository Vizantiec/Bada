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
 * @file	FNetWifiWifiDirectDeviceInfo.h 
 * @brief	This is the header file for the %WifiDirectDeviceInfo class.
 *
 * This header file contains the declarations of the %WifiDirectDeviceInfo class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTDEVICEINFO_H_
#define _FNET_WIFI_WIFIDIRECTDEVICEINFO_H_

// Includes
#include "FBaseObject.h"

#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"

namespace Osp { namespace Base { namespace Collection {
template <class type>
class IListT;
}}}

namespace Osp {	namespace Net {

// Forward declaration
class IpAddress;

namespace Wifi {

// Forward declaration
class __WifiDirectDeviceInfoImpl;

  
/**
 * @class	WifiDirectDeviceInfo
 * @brief	This class provides the methods for the Wi-Fi Direct device information.
 * @since	2.0
 * 
 * 	The %WifiDirectDeviceInfo class provides methods for getting the information related to a Wi-Fi Direct device.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ WifiDirectDeviceInfo: public Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 */
	WifiDirectDeviceInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	 virtual ~WifiDirectDeviceInfo(void);

	/**
	 * This is the copy constructor for the %WifiDirectDeviceInfo class.
	 *
	 * @since 	2.0
	 *
	 * @param[in]	value	An instance of %WifiDirectDeviceInfo
	 */
	WifiDirectDeviceInfo(const WifiDirectDeviceInfo& value);

	/**
	 * Initializes this instance of %WifiDirectDeviceInfo with the specified device name and the MAC address.
	 *
	 * @since 		2.0
	 * @param[in]	deviceName	The device name @n
	 *							The length of @c deviceName should not exceed @c 64 characters.
	 * @param[in]	macAddr		The MAC address @n
	 *							The value of @c macAddr should be in the form '00-00-00-00-00-00'.
	 *
	 */
	WifiDirectDeviceInfo(const Osp::Base::String& deviceName, const Osp::Base::String& macAddr);

// Operator
public:
	/**
	* Copies the data from the specified instance of %WifiDirectDeviceInfo to the calling instance of %WifiDirectDeviceInfo.
	*
	* @since 		2.0
	* @return		A reference to this instance
	* @param[in]	rhs		A reference to the %WifiDirectDeviceInfo instance to be copied
	*/
	WifiDirectDeviceInfo& operator =(const WifiDirectDeviceInfo& rhs);

// Operations
public:
	/**
	 * Gets the ID of the device.
	 *
	 * @since 		2.0
	 * @return 		The ID of the Wi-Fi Direct device, @n
	 *				else @c -1 if the value is not available
	 * @remarks		This value is only available for a local device information query, such as GetAllDeviceInfoN() or GetLocalDeviceInfoN().
	 */
	WifiDirectDeviceId GetDeviceId(void) const;

	/**
	 * Gets the device name.
	 *
	 * @since 		2.0
	 * @return  	The device name
	 */
	Osp::Base::String GetDeviceName(void) const;

	/**
	 * Gets the MAC address of the device.
	 *
	 * @since 		2.0
	 * @return  	The MAC address in the form '00-00-00-00-00-00'
	 * @remarks 	This MAC address is different from the MAC address provided by the WifiManager or DhcpClientInfo class. 
     *         		Especially, the MAC address that is provided in DhcpClientInfo is a virtual MAC address for the data communication during a Wi-Fi Direct 
	 *				group member.
	 */
	Osp::Base::String GetMacAddress(void) const;

	/**
	 * Gets the IP address of the device.
	 *
	 * @since 		2.0
	 * @return		An IpAddress pointer to the local address in the calling instance
	 * @remarks		The IP address is provided only using WifiDirectGroupOwner::GetAllGroupMemberInfoListN(),
	 * 				WifiDirectGroupClient::RequestGroupOwnerInfo(), WifiDirectGroupClient::RequestAllGroupMemberInfo(),
	 * 				or WifiDirectDevice::GetLocalDeviceInfoN() after becoming a group member.
	 */
	const Osp::Net::IpAddress* GetIpAddress(void) const;

	/**
	 * Gets the SSID.
	 *
	 * @since 		2.0
	 * @return		The SSID, @n
	 *				else an empty string if the member type of the device is not a Wi-Fi Direct group owner or client
	 */
	Osp::Base::String GetSsid(void) const;

	/**
	 * Gets the status of the device.
	 *
	 * @since 		2.0
	 * @return 		The status of the Wi-Fi Direct device
	 */
	WifiDirectDeviceStatus GetDeviceStatus(void) const;

	/**
	 * Gets the member type of the Wi-Fi Direct device.
	 *
	 * @since 		2.0
	 * @return 		The member type of the Wi-Fi Direct device
	 */
	WifiDirectGroupMemberType GetGroupMemberType(void) const;

    /**
     * Gets the category of the Wi-Fi Direct device type.
	 *
	 * @since 		2.0
     * @return		The category of the Wi-Fi Direct device type
     */
    WifiDirectDeviceTypeCategory GetDeviceTypeCategory(void) const;

    /**
     * Gets the list of the supporting Wi-Fi Protected Setup (WPS) configuration modes.
     *
     * @since 		2.0
     * @return 		The list of the supporting WPS configuration modes
	 * @remarks 	The result of this method is available only using Scan() or GetLocalDeviceInfoN() in the WifiDirectDevice class.
     */
    const Osp::Base::Collection::IListT<WifiWpsConfigurationMode>* GetSupportedWpsConfigurationModeList(void) const;


	
//Member variables
private :
	__WifiDirectDeviceInfoImpl* __pWifiDirectDeviceInfoImpl;
	friend class __WifiDirectDeviceInfoImpl;


};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTDEVICEINFO_H_
 

