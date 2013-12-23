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
 * @file		FNetWifiWifiDirectGroupOwner.h
 * @brief		This is the header file for the %WifiDirectOwner class.
 *
 * This header file contains the declarations of the %WifiDirectOwner class.
 */


#ifndef _FNET_WIFI_WIFIDIRECTGROUPOWNER_H_
#define _FNET_WIFI_WIFIDIRECTGROUPOWNER_H_

// Includes
#include "FNetWifiWifiTypes.h"
#include "FNetWifiWifiDirectGroupMember.h"
namespace Osp {	namespace Base { namespace Collection {

// Forward declaration
class IList;
}}} // Osp::Base::Collection


namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class __WifiDirectGroupOwnerImpl;
class WifiDirectDeviceInfo;

/**
 * @class	WifiDirectGroupOwner
 * @brief   This class provides the methods for the Wi-Fi Direct group owner management.
 * @since	2.0
 *
 * 	The %WifiDirectGroupOwner class provides the methods to manage the Wi-Fi Direct group.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>. 
 */

class _EXPORT_NET_ WifiDirectGroupOwner: public WifiDirectGroupMember
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~WifiDirectGroupOwner(void);

// Operations
public:
	/**
	 * Destroys a Wi-Fi Direct group.
	 *
	 * @since		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_IN_PROGRESS		A previous request is in progress.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *									For example, when the member type of a device is not a Wi-Fi Direct group owner.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 *
	 * @see			IWifiDirectGroupOwnerListener::OnWifiDirectGroupDestroyed()
	 */
	result DestroyGroup(void);

	/**
	 * Disconnects a specified Wi-Fi Direct group client.
	 *
	 * @since 		2.0
	 *
	 * @privlevel   NORMAL
	 * @privgroup   WIFI
	 *
	 * @return      An error code
	 * @param[in]   wifiDirectRemoteDeviceInfo		The device information of a group client to disconnect
	 * @exception   E_SUCCESS						The method is successful.
	 * @exception   E_SYSTEM						A system error has occurred.
	 * @exception   E_IN_PROGRESS					A previous request is in progress.
	 * @exception   E_INVALID_ARG       			The specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION				The current state of the instance prohibits the execution of this operation. @n
	 *												For example, when the member type of a device is not a Wi-Fi Direct group owner.
	 * @exception   E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 *
	 * @see			IWifiDirectGroupOwnerListener::OnWifiDirectClientDisassociated()
	 */
	result Disconnect(const WifiDirectDeviceInfo& wifiDirectRemoteDeviceInfo);

	
	/**
	 * Gets the list of information about all the members of the Wi-Fi Direct group.
	 *
	 * @since		2.0
	 *
	 * @return		The list of WifiDirectDeviceInfo
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									For example, when the member type of a device is not a Wi-Fi Direct group owner.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	 Osp::Base::Collection::IList* GetAllGroupMemberInfoListN(void) const;

	/**
	 * Starts the group member information service.
	 *
	 * @since		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @param[in]	portNumber				A port number to start group member information service with DEFAULT_PORT (3895)
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_OUT_OF_RANGE			The specified port number is less than @c 1024 or greater than @c 65535
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										For example, the member type of @c wifiDirectDevice is not the group owner or client.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *
	 * @see       	Osp::Net::Wifi::IWifiDirectGroupOwnerListener::OnWifiDirectGroupMemberInfoServiceStarted()
	 */
	 result StartGroupMemberInfoService(int portNumber = DEFAULT_PORT);

    /**
     * Stops the group member information service.
     *
     * @since		2.0
     *
     * @privlevel	NORMAL
     * @privgroup	WIFI
     *
     * @return		An error code
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_SYSTEM			A system error has occurred.
     * @exception	E_IN_PROGRESS		A previous request is in progress.
     * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     *
     * @see       Osp::Net::Wifi::IWifiDirectGroupOwnerListener::OnWifiDirectGroupMemberInfoServiceStopped()
     */
     result StopGroupMemberInfoService(void);

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see 		Construct()
	 */
	WifiDirectGroupOwner(void);

	/**
	 * Initializes this instance of WifiDirectGroupOwner with the specified listener.
	 *
	 * @return		An error code
	 * @param[in]	wifiDirectDeviceImpl	A reference to the __WifiDirectDeviceImpl instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	 *										For example, this instance has already been constructed.
	 */
	result Construct(__WifiDirectGroupOwnerImpl& wifiDirectGroupOwnerImpl);

	WifiDirectGroupOwner(const WifiDirectGroupOwner& value);
	WifiDirectGroupOwner& operator =(const WifiDirectGroupOwner& rhs);

private:
       static const int DEFAULT_PORT = 3895;

//Member variables
private :
	__WifiDirectGroupOwnerImpl* __pWifiDirectGroupOwnerImpl;
	friend class __WifiDirectGroupOwnerImpl;

};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTGROUPOWNER_H_

