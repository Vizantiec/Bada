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
 * @file		FNetWifiIWifiDirectDeviceListener.h 
 * @brief		This is the header file for the %IWifiDirectDeviceListener interface.
 *
 * This header file contains the declarations of the %IWifiDirectDeviceListener interface.
 */

#ifndef _FNET_WIFI_IWIFIDIRECTDEVICELISTENER_H_
#define _FNET_WIFI_IWIFIDIRECTDEVICELISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FNetWifiWifiTypes.h"
#include "FNetConfig.h"
namespace Osp {	namespace Base { namespace Collection {

// Forward declaration
class IList;
}}} // Osp::Base::Collection

namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class WifiDirectGroupInfo;
class WifiDirectDeviceInfo;
class WifiDirectGroupMember;
  
/**
 * @interface  IWifiDirectDeviceListener
 * @brief      This interface implements the listeners for the WifiDirectDevice events.
 * @since      2.0
 * 
 * 	The %IWifiDirectDeviceListener interface represents a listener to get the Wi-Fi Direct device status or information for the WifiDirectDevice events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ IWifiDirectDeviceListener: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
 	/**
 	* This is the destructor for this interface.
	*
	* @since 	2.0
 	*/
virtual ~IWifiDirectDeviceListener(void) {}

// Operations
public:
   /**
	* Called to notify the application that the local Wi-Fi Direct device is activated.
	*
	* @since		2.0
	*
	* @param[in]	localDeviceId		An ID for a Wi-Fi Direct device
	* @param[in]	r					The error code that occurred during activation
 	* @exception	E_SUCCESS			The activation is successful.
	* @exception	E_SYSTEM			A system error has occurred.
 	*
	* @see			Osp::Net::Wifi::WifiDirectDevice::Activate()
	*/
	virtual void OnWifiDirectDeviceActivated(WifiDirectDeviceId localDeviceId, result r) = 0;

   /**
	* Called to notify the application that the local Wi-Fi Direct device is deactivated.
	*
	* @since		2.0
	*
	* @param[in]	localDeviceId 		An ID for a Wi-Fi Direct device
	* @param[in]	r					The error code that occurred during deactivation
 	* @exception	E_SUCCESS			The deactivation is successful.
  	* @exception	E_SYSTEM			A system error has occurred.
 	*
	* @see			Osp::Net::Wifi::WifiDirectDevice::Deactivate()
	*/
	virtual void OnWifiDirectDeviceDeactivated(WifiDirectDeviceId localDeviceId, result r) = 0;

   /**
	* Called to notify the application with the result and related information for a request of group creation or group creation cancellation.
	*
	* @since 2.0
	*
	* @param[in]	localDeviceId 					An ID for a Wi-Fi Direct device
	* @param[in]	wifiDirectGroupInfo				The WifiDirectGroupInfo instance set by the winning group owner after negotiation
	* @param[in]	wifiDirectGroupOwnerDeviceInfo	The WifiDirectDeviceInfo instance of the group owner
	* @param[in]	pWifiDirectMember				The WifiDirectGroupMember instance that is cast to the
	*												WifiDirectGroupOwner or the WifiDirectGroupClient instance as a result of the negotiation
	*												after the creation of a group
	* @param[in]	r								The error code that occurred during group creation or group creation cancellation
 	* @exception	E_SUCCESS						The Wi-Fi Direct group creation is successful.
	* @exception	E_SYSTEM						A system error has occurred.
 	* @exception	E_OPERATION_CANCELED			The operation is canceled explicitly.
 	* @exception	E_AUTHENTICATION				The authentication has failed during the Wi-Fi connection process.
	* @exception	E_DHCP 							The DHCP operation has failed.
	* @exception	E_NOT_RESPONDING 				The target is not responding.
	* @exception    E_REJECTED						The connection request is rejected.
	* @exception	E_REMOTE_DEVICE_NOT_FOUND   	The Wi-Fi Direct device is not found. 
 	*
 	* @see			Osp::Net::Wifi::WifiDirectDevice::CreateGroup(), Osp::Net::Wifi::WifiDirectDevice::CancelGroupCreation()
 	*
 	* @remarks		If a device becomes a group client, the GetGroupOwnerIntent() and GetMaxNumberOfClients() methods in the WifiDirectGroupInfo class do not contain valid information.
	*/
	virtual void OnWifiDirectGroupCreatedN(WifiDirectDeviceId localDeviceId, const WifiDirectGroupInfo &wifiDirectGroupInfo, const WifiDirectDeviceInfo &wifiDirectGroupOwnerDeviceInfo, WifiDirectGroupMember* pWifiDirectMember, result r)=0;

   /**
	* Called to notify the application that the scan is completed.
	*
	* @since 		2.0
	*
	* @param[in]	localDeviceId 				An ID for a Wi-Fi Direct device
	* @param[in]	pWifiDirectDeviceInfoList	A list of WifiDirectDeviceInfo information representing the Wi-Fi Direct devices discovered by scan
	* @param[in]	r							The error code that occurred during the scan
 	* @exception	E_SUCCESS					The scan is successful.
 	* @exception	E_SYSTEM					A system error has occurred.
 	* @exception	E_OPERATION_CANCELED		The operation is canceled explicitly.
 	*
 	* @see			Osp::Net::Wifi::WifiDirectDevice::Scan(), Osp::Net::Wifi::WifiDirectDevice::CancelScan()
 	*/
	virtual void OnWifiDirectScanCompletedN(WifiDirectDeviceId localDeviceId, Osp::Base::Collection::IList *pWifiDirectDeviceInfoList, result r)=0;

   /**
	* Called to notify the application that the connection to a Wi-Fi Direct group owner is completely established.
	*
	* @since 		2.0
	*
	* @param[in]	localDeviceId 					An ID for a Wi-Fi Direct device
	* @param[in]	wifiDirectGroupOwnerDeviceInfo	The WifiDirectDeviceInfo of the connected Wi-Fi Direct group owner
	* @param[in]	r								The error code that occurred during connection
	* @exception	E_SUCCESS						The association is successful.
	* @exception	E_SYSTEM						A system error has occurred.
	* @exception	E_OPERATION_CANCELED		   The operation is canceled explicitly.
	* @exception	E_AUTHENTICATION				The authentication has failed during the Wi-Fi connection process.
	* @exception	E_DHCP 							The DHCP operation has failed.
	* @exception	E_NOT_RESPONDING 				The target is not responding.
	* @exception    E_REJECTED						The connection request is rejected.
	* @exception	E_REMOTE_DEVICE_NOT_FOUND   	The Wi-Fi Direct device is not found. 
	*
	* @see			Osp::Net::Wifi::WifiDirectDevice::Associate(), Osp::Net::Wifi::WifiDirectDevice::CancelGroupCreation()
	*
	* @remarks		If the specified remote device is not the group owner while the association is in progress, the E_REMOTE_DEVICE_NOT_FOUND exception is returned.
	*/
 	virtual void OnWifiDirectAssociationCompleted(WifiDirectDeviceId localDeviceId, const WifiDirectDeviceInfo &wifiDirectGroupOwnerDeviceInfo, result r) = 0;

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
		virtual void OnWifiDirectDeviceListener_Reserved1(void) {}

		/**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectDeviceListener_Reserved2(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectDeviceListener_Reserved3(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectDeviceListener_Reserved4(void) {}

	   /**
	 	* @internal
		* This method is for internal use only. The bada platform team is not responsible
		* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
		*
		* Following method is reserved and may change its name at any time without prior notice.
		*
		* @since       2.0
		*/
       virtual void OnWifiDirectDeviceListener_Reserved5(void) {}


};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_IWIFIDIRECTDEVICELISTENER_H_
