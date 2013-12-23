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
 * @file	FNetWifiIWifiManagerEventListener.h
 * @brief	This is the header file for the %IWifiManagerEventListener interface.
 *
 * This is the header file for the %IWifiManagerEventListener interface.
 *
 */

#ifndef FNET_WIFI_IWIFIMANAGEREVENTLISTENER_H
#define FNET_WIFI_IWIFIMANAGEREVENTLISTENER_H

// Includes
#include "FBaseColArrayList.h"
#include "FBaseRtIEventListener.h"
#include "FNetWifiWifiTypes.h"
//#include "FBaseColIList.h"

namespace Osp {
	namespace Base {
		namespace Collection {
class IList;
};};};

namespace Osp {
    namespace Net {
        namespace Wifi {
/**
 * @interface	IWifiManagerEventListener
 * @brief		This interface provides the listeners for WifiManager events.
 * @since		1.0
 *
 * 	The %IWifiManagerEventListener interface specifies the methods used for creating notifications about the different kinds of %WifiManager events. These events are only sent 
 *			out when using %WifiManager. When a %WifiManager event is generated, a method of this class is called. Thus, if an application provides any 
 *			functionality related to the %WifiManager events, override and use the methods of this interface.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_connectivity.htm">Wi-Fi Connectivity</a>.
 */
class _EXPORT_NET_ IWifiManagerEventListener
	: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
  	/**
  	 * This is the destructor for this class.
  	 *
  	 * @since	1.0
  	 */
	virtual ~IWifiManagerEventListener(void) {}

// Operation
public:
   /**
	* Called to notify that the local Wi-Fi radio is activated.
	*
	* @since		1.0
	* @param[in]	r				The error code that occurs during activation
 	* @exception	E_SUCCESS		The activation is successful.
 	* @exception	E_FAILURE		The method has failed to activate.
	* @see			Osp::Net::Wifi::WifiManager::Activate()
	*/
	virtual void OnWifiActivated(result r) = 0;

   /**
	* Called to notify that the local Wifi radio is deactivated.
	*
	* @since		1.0
	* @param[in]	r				The error code that occurs during deactivation
 	* @exception	E_SUCCESS		The deactivation is successful.
 	* @exception	E_FAILURE		The method has failed to deactivate.
	* @see			Osp::Net::Wifi::WifiManager::Deactivate()
	*/
	virtual void OnWifiDeactivated(result r) = 0;

   /**
	* Called to notify that the connection to an access point (only an infrastructure mode BSS) has been completely established.
	*
	* @since		1.0
	* @param[in]	ssid				The SSID of the connected BSS
	* @param[in]	r					The error code that occurs during connection
	* @exception	E_SUCCESS			The connection is successful.
	* @exception	E_FAILURE 			The method has failed to connect.
	* @exception	E_AUTHENTICATION	The authentication fails when Wi-Fi is connected.
	* @exception	E_NOT_RESPONDING 	The target is not responding when Wi-Fi is connected.
	* @exception	E_DHCP 				The DHCP fails in case of a dynamic IP.
	* @see			Osp::Net::Wifi::WifiManager::Connect()
	*/
	virtual void OnWifiConnected(const Osp::Base::String& ssid, result r) = 0;

   /**
	* Called to notify that the connection to a BSS has been terminated.
	*
	* @since	1.0
	*/
	virtual void OnWifiDisconnected(void) = 0;
   
   /**
	* Called to notify that the Received Signal Strength Indication (RSSI) from BSS has been changed.
	*
	* @since		1.0
	* @param[in]	rssi			The updated RSSI value (dbm)
	*/
	virtual void OnWifiRssiChanged(long rssi) = 0;

   /**
	* Called to notify that the scan to find the access points has been completed.
	*
	* @since		1.0
	* @param[in]	pWifiBssInfoList	The list of WifiBssInfo information representing the access points discovered by the scan
	* @param[in]	r					The error code that occurs during the scan
	* @exception	E_SUCCESS			The scan is successful.
	* @exception	E_FAILURE			The scan has failed.
	* @see			Osp::Net::Wifi::WifiManager::Scan()
	*/
	virtual void OnWifiScanCompletedN(const Osp::Base::Collection::IList* pWifiBssInfoList, result r) = 0;

};

}; }; };

#endif // FNET_WIFI_IWIFIMANAGEREVENTLISTENER_H

