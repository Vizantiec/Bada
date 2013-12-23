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
 * @file		FNetWifiIWifiDirectGroupClientListener.h
 * @brief		This is the header file for the %IWifiDirectGroupClientListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectGroupClientListener interface.
 */

#ifndef _FNET_WIFI_IWIFIDIRECTGROUPCLIENTLISTENER_H_
#define _FNET_WIFI_IWIFIDIRECTGROUPCLIENTLISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FNetWifiWifiTypes.h"
#include "FNetConfig.h"

namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class WifiDirectDeviceInfo;

/**
 * @interface  IWifiDirectGroupClientListener
 * @brief      This interface implements the listeners for the WifiDirectGroupClient events.
 * @since      2.0
 *
 *		The %IWifiDirectGroupClientListener interface represents a listener that is used to obtain the Wi-Fi Direct client status or the information for WifiDirectGroupClient 
 *				events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ IWifiDirectGroupClientListener: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
 	/**
 	* This is the destructor for this class.
	*
	* @since 	2.0
 	*/
virtual ~IWifiDirectGroupClientListener(void) {}

// Operations
public:
   /**
	* Called to notify the application that a connection to a Wi-Fi Direct group owner has terminated.
	*
	* @since 		2.0
	*
	* @param[in]	localDeviceId		An ID for a Wi-Fi Direct device
	* @param[in]	reason				The reason for the termination of the association
	* @param[in]	r					The error code that occurs during the association
	* @exception	E_SUCCESS			The disassociation is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_NOT_RESPONDING 	The target is not responding.
	*
	* @see			Osp::Net::Wifi::WifiDirectGroupClient::Disassociate()
	*
	* @remarks		When a device is disconnected on its own using WifiDirectGroupClient::Disassociate, this event is invoked with Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED. @n
	*				When a device is disconnected by a group owner using WifiDirectGroupOwner::Disconnect, because it is out of range, or due to abrupt connection loss to the group owner, this event is invoked with Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED.
	*/
	virtual void OnWifiDirectAssociationTerminated(WifiDirectDeviceId localDeviceId, WifiDirectAssociationTerminationReason reason, result r) = 0;

   /**
	* Called to notify the application that the request to acquire the %WifiDirectDeviceInfo from the Wi-Fi Direct group owner has been completed.
	*
	* @since 		2.0
	*
	* @param[in]	localDeviceId 					An ID for a Wi-Fi Direct device
	* @param[in]	wifiDirectGroupOwnerDeviceInfo	The WifiDirectDeviceInfo instance of the Wi-Fi Direct group owner
	* @param[in]	r								The error code that occurs during the request
 	* @exception	E_SUCCESS						The request for group owner information is successful.
 	* @exception	E_SYSTEM						A system error has occurred.
    * @exception 	E_ALREADY_BOUND     			The specified port number is already in use.
    * @exception 	E_OUT_OF_MEMORY     			The memory is insufficient.
    * @exception	E_NOT_RESPONDING 				The target is not responding.
	*
 	* @see			Osp::Net::Wifi::WifiDirectGroupClient::RequestGroupOwnerInfo()
 	*/
	virtual void OnWifiDirectGroupOwnerInfoReceived(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo &wifiDirectGroupOwnerDeviceInfo, result r) = 0;

   /**
	* Called to notify the application that the WifiDirectDeviceInfo list of group members has been received.
	*
	* @since		2.0
	*
	* @param[in]	localDeviceId               An ID for a Wi-Fi Direct device
	* @param[in]	pWifiDirectDeviceInfoList   The list of WifiDirectDeviceInfo @n
	*               	                        @c null, if failed
	* @param[in]	r                   		The error code that occurs during the request
	* @exception	E_SUCCESS           		The response is received successfully.
	* @exception	E_SYSTEM            		A system error has occurred.
    * @exception	E_ALREADY_BOUND     		The specified port number is already in use.
    * @exception	E_OUT_OF_MEMORY     		The memory is insufficient.
	* @exception	E_NOT_RESPONDING    		The group owner is not reachable.
	*
	* @see       Osp::Net::Wifi::WifiDirectGroupClient::RequestAllGroupMemberInfo()
	*/
	virtual void OnWifiDirectAllGroupMemberInfoReceivedN(WifiDirectDeviceId localDeviceId, Osp::Base::Collection::IList* pWifiDirectDeviceInfoList, result r) = 0;

protected:

       /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
	   virtual void OnWifiDirectGroupClientListener_Reserved1(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupClientListener_Reserved2(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupClientListener_Reserved3(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupClientListener_Reserved4(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupClientListener_Reserved5(void) {}



};

}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_IWIFIDIRECTGROUPCLIENTEVENTLISTENER_H_
