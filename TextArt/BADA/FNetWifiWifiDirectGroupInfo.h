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
 * @file		FNetWifiWifiDirectGroupInfo.h 
 * @brief		This is the header file for the %WifiDirectGroupInfo class.
 *
 * This header file contains the declarations of the %WifiDirectGroupInfo class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTGROUPINFO_H_
#define _FNET_WIFI_WIFIDIRECTGROUPINFO_H_

// Includes
#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"



namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class __WifiDirectGroupInfoImpl;

  
/**
 * @class  	WifiDirectGroupInfo
 * @brief   This class provides the methods for the Wi-Fi Direct group.
 * @since 	2.0
 * 
 * The %WifiDirectGroupInfo class provides the methods to get or set the information for a Wi-Fi Direct group.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ WifiDirectGroupInfo: public Base::Object
{

// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	WifiDirectGroupInfo(void);

	/**
	 * This is the copy constructor for the %WifiDirectGroupInfo class.
	 *
	 * @since		2.0
	 *
	 * @param[in]	value	An instance of %WifiDirectGroupInfo
	 */
	WifiDirectGroupInfo(const WifiDirectGroupInfo& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~WifiDirectGroupInfo(void);
		
// Operator
public:
	/**
	 * Copies the data from the specified instance of %WifiDirectGroupInfo to the calling instance of %WifiDirectGroupInfo.
	 *
     * @since		2.0
	 * 
	 * @return		A reference to the %WifiDirectGroupInfo instance
	 * @param[in]	rhs		A reference to the %WifiDirectGroupInfo instance to be copied
	 */
	WifiDirectGroupInfo& operator =(const WifiDirectGroupInfo& rhs);

// Operations
public:
	/**
	 * Gets the mode for an autonomous group owner.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the autonomous group owner mode is activated, @n
	 *	    	else @c false
	 */
	bool GetAutonomousGroupOwnerMode(void) const;

	/**
	 * Gets the intent of a group owner. @n
	 * It is used during the negotiation phase.
	 *
	 * @since	2.0
	 *
	 * @return	An intent value
	 */
	int GetGroupOwnerIntent(void) const;
    
	/** 
     * Gets the maximum number of clients to be associated.
	 *
	 * @since	2.0
     *
     * @return	The maximum number of clients to be associated
     */
    int GetMaxNumberOfClients(void) const;

	/**
	 * Gets the SSID.
	 *
	 * @since	2.0
	 *
	 * @return	The SSID
	 */
	Osp::Base::String GetSsid(void) const;

	/**
     * Gets the BSS ID.
	 *
	 * @since	2.0
     *
     * @return	The BSS ID
     */
    Osp::Base::String GetBssId(void) const;

	/**
     * Gets the index of a currently working channel.
	 *
	 * @since	2.0
     *
     * @return	The Wi-Fi radio channel
     */
    WifiRadioChannel GetOperatingChannel(void) const;

	/**
	 * Sets the mode for an autonomous group owner.
	 *
	 * @since		2.0
	 *
	 * @param[in]	mode	Set to @c true if autonomous group owner mode is enabled, @n
	 *						else @c false
	 */
	void SetAutonomousGroupOwnerMode(bool mode);

	/**
     * Sets the intent of a group owner.
	 *
	 * @since		2.0
     *
     * @return       An error code
     * @param[in]    intent			The intent to become a group owner
     * @exception    E_SUCCESS		The method is successful.
     * @exception    E_INVALID_ARG	The specified @c intent is less than @c 0 or exceeds Wifi::WIFI_DIRECT_MAX_GROUP_OWNER_INTENT (15).
	 *
	 * @remarks      A higher intent value means that the intent to become a group owner is higher. 
	 *               If Wifi::WIFI_DIRECT_MAX_GROUP_OWNER_INTENT (15) is selected, it means that a device insists to be a group owner only. 
	 *               If two devices participating in a group creation select the intent value as 
	 *				 Wifi::WIFI_DIRECT_MAX_GROUP_OWNER_INTENT (15), the group creation fails.
	 */
    result SetGroupOwnerIntent(int intent);
    
	/** 
     * Sets the maximum number of clients to be associated.
	 *
	 * @since 		2.0
     *
     * @return		An error code
     * @param[in]   numberOfClient	The maximum number of clients to be associated
     * @exception   E_SUCCESS		The method is successful.
     * @exception   E_INVALID_ARG	The specified @c numberOfClient is less than @c 0 or exceeds Wifi::WIFI_DIRECT_MAX_CONNECTED_CLIENTS (8).
     */
    result SetMaxNumberOfClients(int numberOfClient);
		   
	/**
	 * Sets the SSID.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ssid			The SSID for this group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c ssid is an empty string, or the length of @c ssid exceeds @c 32 characters.
	 *
	 */
	result SetSsid(const Osp::Base::String &ssid);
	

	
//Member variable
private:
	class __WifiDirectGroupInfoImpl* __pWifiDirectGroupInfoImpl;

	friend class __WifiDirectGroupInfoImpl;
};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTGROUPINFO_H_
 

