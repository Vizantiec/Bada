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
 * @file		FNetWifiWifiDirectGroupMember.h
 * @brief		This is the header file for the %WifiDirectGroupMember class.
 *
 * This header file contains the declarations of the %WifiDirectGroupMember class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTGROUPMEMBER_H_
#define _FNET_WIFI_WIFIDIRECTGROUPMEMBER_H_

// Includes
#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"

namespace Osp {	namespace Net {	namespace Wifi {

/**
 * @class	WifiDirectGroupMember
 * @brief	The %WifiDirectGroupMember class provides the methods to access the Wi-Fi Direct group members.
 * @since	2.0
 *
 * The %WifiDirectGroupMember class provides the methods to access the Wi-Fi Direct group members.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */
class _EXPORT_NET_ WifiDirectGroupMember : public Base::Object  
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~WifiDirectGroupMember(void){}


// Operation
	/**
	 * Gets the type of the Wi-Fi Direct group member.
	 *
	 * @since	2.0
	 *
	 * @return	The type of the Wi-Fi Direct group member
	 */
	WifiDirectGroupMemberType GetGroupMemberType(void) const;


protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	WifiDirectGroupMember(void);

	/**
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
	 *
	 * @since 	2.0
	 *
	 * @param[in] 	value	An instance of the WifiDirectGroupMember class
	 *
	 * @remarks		The method is declared but not implemented.
	 *
	 */
	WifiDirectGroupMember(const WifiDirectGroupMember& value);
	
	/**
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of the WifiDirectGroupMember class
	 *
	 * @remarks		The method is declared but not implemented.
	 * 
	 */
	WifiDirectGroupMember& operator =(const WifiDirectGroupMember& rhs);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void WifiDirectGroupMember_Reserved1(void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void WifiDirectGroupMember_Reserved2(void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void WifiDirectGroupMember_Reserved3(void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void WifiDirectGroupMember_Reserved4(void) { }

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void WifiDirectGroupMember_Reserved5(void) { }
	
	/**
	 * @internal 
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
     * The type of the Wi-Fi Direct group member.
     *
     * @since       2.0
     */
	WifiDirectGroupMemberType	__groupMemberType;


};

}}} // // Osp::Net::Wifi

#endif// _FNET_WIFI_WIFIDIRECTGROUPMEMBER_H_

