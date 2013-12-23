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
 * @file		FNetWifiIWifiDirectGroupOwnerListener.h
 * @brief		This is the header file for the %IWifiDirectGroupOwnerListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectGroupOwnerListener interface.
 */

#ifndef _FNET_WIFI_IWIFIDIRECTGROUPOWNERLISTENER_H_
#define _FNET_WIFI_IWIFIDIRECTGROUPOWNERLISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FNetWifiWifiTypes.h"
#include "FNetConfig.h"
#include "FNetNetConnection.h"

namespace Osp {	namespace Net {

// Forward declaration
class NetConnection;

namespace Wifi {


// Forward declaration
class WifiDirectDeviceInfo;
/**
 * @interface	IWifiDirectGroupOwnerListener
 * @brief		This interface implements the listeners for the WifiDirectGroupOwner events.
 * @since		2.0
 *
 * 		The %IWifiDirectGroupOwnerListener interface represents a listener that is used to obtain the Wi-Fi Direct group owner's status or the information for the 
 *				%WifiDirectGroupOwner events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ IWifiDirectGroupOwnerListener: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
 	/**
 	* This is the destructor for this interface.
	*
	* @since 	2.0
 	*/
virtual ~IWifiDirectGroupOwnerListener(void) {}

// Operations
public:
   /**
	* Called to notify the application that a successful association has occurred with a client.
	*
	* @since 		2.0
	*
	* @param[in]	localDeviceId 			An ID for a Wi-Fi Direct device
	* @param[in]	wifiDirectClientInfo	The WifiDirectDeviceInfo instance of a node that is associated
	*/
	virtual void OnWifiDirectClientAssociated(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo &wifiDirectClientInfo)=0;

	/**
	 * Called to notify the application that a disassociation has occurred with a client.
	 *
	 * @since 		2.0
	 *
	 * @param[in]	localDeviceId 			An ID for a Wi-Fi Direct device
	 * @param[in]	wifiDirectClientInfo	The WifiDirectDeviceInfo instance of a node that is disassociated
	 * @param[in]	reason					The reason of association termination
	 *
	 * @remarks		When a client is disconnected by a group owner using WifiDirectGroupOwner::Disconnect, this event is invoked with 
	 *				Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_SELF_INITIATED. @n
	 *				When a client is disconnected on its own using WifiDirectGroupClient::Disassociate, because of being out of range, or due to an abrupt 
	 *				connection loss to the group owner, this event is invoked with Wifi::WIFI_DIRECT_ASSOCIATION_TERMINATION_REASON_DISCONNECTED.
	 */
	virtual void OnWifiDirectClientDisassociated(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo &wifiDirectClientInfo, WifiDirectAssociationTerminationReason reason)=0;

	/**
	 * Called to notify the application that the Wi-Fi Direct group is destroyed.
	 *
	 * @since 		2.0
	 *
	 * @param[in]	localDeviceId 		An ID for a Wi-Fi Direct device
	 * @param[in]	r					The error code that occurs during a group destruction
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @see        	Osp::Net::Wifi::WifiDirectGroupOwner::DestroyGroup()
	 */
	virtual void OnWifiDirectGroupDestroyed(WifiDirectDeviceId localDeviceId, result r)=0;

    /**
    * Called to notify the application that the group member information service has started.
    *
    * @since 		2.0
    *
    * @param[in] 	localDeviceId       An ID for a Wi-Fi Direct device
    * @param[in] 	pNetConnection      The network connection that started with the Wi-Fi Direct net account @n
    *                                	Set to @c null if the system fails to start the network connection.
    * @param[in] 	r                   The error code that occurs during the starting process
    *
    * @exception 	E_SUCCESS           The method is successful.
    * @exception 	E_SYSTEM            A system error has occurred.
    * @exception 	E_OUT_OF_MEMORY     The memory is insufficient.
    * @exception 	E_ALREADY_BOUND     The specified port number is already in use.
    *
    * @see       	Osp::Net::Wifi::WifiDirectGroupOwner::StartGroupMemberInfoService()
    */
    virtual void OnWifiDirectGroupMemberInfoServiceStarted(WifiDirectDeviceId localDeviceId, const Osp::Net::NetConnection* pNetConnection, result r) = 0;

   /**
    * Called to notify the application that the group member information service has stopped.
    *
    * @since 	2.0
    *
    * @param[in] localDeviceId		An ID for a Wi-Fi Direct device
    * @param[in] r					The error code that occurs during the stopping process
    *
    * @exception E_SUCCESS			The method is successful.
    * @exception E_SYSTEM			A system error has occurred.
    *
    * @see       Osp::Net::Wifi::WifiDirectGroupOwner::StopGroupMemberInfoService()
    */
    virtual void OnWifiDirectGroupMemberInfoServiceStopped(WifiDirectDeviceId localDeviceId, result r) = 0;


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
	   virtual void OnWifiDirectGroupOwnerListener_Reserved1(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupOwnerListener_Reserved2(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupOwnerListener_Reserved3(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupOwnerListener_Reserved4(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectGroupOwnerListener_Reserved5(void) {}
};
}}} //Osp::Net::Wifi

#endif // _FNET_WIFI_IWIFIDIRECTGROUPOWNERLISTENER_H_
