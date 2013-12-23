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
 * @file		FNetWifiWifiDirectDeviceManager.h
 * @brief		This is the header file for the %WifiDirectDeviceManager class.
 *
 * This header file contains the declarations of the %WifiDirectDeviceManager class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTDEVICEMANAGER_H_
#define _FNET_WIFI_WIFIDIRECTDEVICEMANAGER_H_

// Includes
#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"


namespace Osp { namespace Base { namespace Collection {
class IList;
}}}

namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class __WifiDirectDeviceManagerImpl;
class WifiDirectDevice;
class WifiDirectDeviceInfo;

/**
 * @class	WifiDirectDeviceManager
 * @brief	This class provides the methods for the Wi-Fi Direct device management.
 * @since	2.0
 * 
 * 	The %WifiDirectDeviceManager class provides the methods for creating a WifiDirectDevice instance and managing the Wi-Fi Direct devices. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ WifiDirectDeviceManager: public Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
    WifiDirectDeviceManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~WifiDirectDeviceManager(void);

// Operations
public:
	/**
	 * Gets a list of all the devices and the information pertaining to them provided by the system.
	 *
	 * @since		2.0
	 *
	 * @return		An IList containing WifiDirectDeviceInfo of local devices in the system, @n
	 * 				else @c null
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	The Wi-Fi Direct device information is not available because the device does not support the Wi-Fi Direct feature.
	 *
	 * @remarks		Currently, a single %WifiDirectDeviceInfo instance is returned because the concurrent mode is not supported.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	static Osp::Base::Collection::IList* GetAllDeviceInfoN(void);

	/**
	 * Gets an instance of WifiDirectDevice.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of WifiDirectDevice, @n
	 *				else @c null
	 * @param[in]  	pLocalDeviceInfo 		A pointer to %WifiDirectDeviceInfo
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_UNSUPPORTED_OPERATION	The device does not support the Wi-Fi Direct feature.
	 *
	 * @remarks 	If the value of @c pLocalDeviceInfo is @c null, the WifiDirectDevice instance is created for the system default device. 
	 *          	Otherwise, the value of @c pLocalDeviceInfo should be one of the elements obtained from GetAllDeviceInfoN() to
	 *				create a valid WifiDirectDevice instance.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	static WifiDirectDevice* GetWifiDirectDeviceN(const WifiDirectDeviceInfo* pLocalDeviceInfo = null);

private:
	WifiDirectDeviceManager(const WifiDirectDeviceManager& value);
	WifiDirectDeviceManager& operator =(const WifiDirectDeviceManager& rhs);

//Member variables
private:
	__WifiDirectDeviceManagerImpl* __pWifiDirectDeviceManagerImpl;
	friend class __WifiDirectDeviceManagerImpl;

};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTDEVICEMANAGER_H_

