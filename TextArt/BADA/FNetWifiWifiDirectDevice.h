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
 * @file	FNetWifiWifiDirectDevice.h
 * @brief	This is the header file for the %WifiDirectDevice class.
 *
 * This header file contains the declarations of the %WifiDirectDevice class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTDEVICE_H_
#define _FNET_WIFI_WIFIDIRECTDEVICE_H_

// Includes
#include "FBaseObject.h"
#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"

namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class __WifiDirectDeviceImpl;
class IWifiDirectDeviceListener;
class IWifiDirectGroupOwnerListener;
class IWifiDirectGroupClientListener;
class WifiDirectGroupInfo;
class WifiDirectDeviceInfo;
class WifiDirectGroupMember;

/**
 * @class  	WifiDirectDevice
 * @brief   This class provides the methods for the Wi-Fi Direct device.
 * @since 	2.0
 * 
 * 	The %WifiDirectDevice class provides the methods to manage the Wi-Fi Direct device, create a Wi-Fi Direct group, scan the Wi-Fi Direct devices, 
 *			associate a Wi-Fi Direct group owner, create a WifiDirectGroupMember instance, and allow the listener to get the events related to a Wi-Fi Direct 
 *			device and group.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ WifiDirectDevice: public Base::Object
{
// Lifecycle
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~WifiDirectDevice(void);
// Operations
	/**
	 * Adds the specified listener for the Wi-Fi Direct device.
	 *
	 * @since		2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the listener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result AddWifiDirectDeviceListener(const IWifiDirectDeviceListener &listener);

	/**
	 * Adds the specified listener for the Wi-Fi Direct group owner.
	 *
	 * @since		2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the IWifiDirectGroupOwnerListener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result AddWifiDirectGroupOwnerListener(const IWifiDirectGroupOwnerListener &listener);

	/**
	 * Adds the specified listener for the Wi-Fi Direct group client.
	 *
	 * @since 		2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the IWifiDirectGroupClientListener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 */
	result AddWifiDirectGroupClientListener(const IWifiDirectGroupClientListener &listener);

	/**
	 * Removes the specified listener for the Wi-Fi Direct device.
	 *
	 * @since 		2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the IWifiDirectDeviceListener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND	The specified object is not found within the indicated range.
	 */
	result RemoveWifiDirectDeviceListener(const IWifiDirectDeviceListener &listener);

	/**
	 * Removes the specified listener for the Wi-Fi Direct group owner.
	 *
	 * @since 		2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the IWifiDirectGroupOwnerListener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND	The specified object is not found within the indicated range.
	 */
	result RemoveWifiDirectGroupOwnerListener(const IWifiDirectGroupOwnerListener &listener);

	/**
	 * Removes the specified listener for the Wi-Fi Direct group client.
	 *
	 * @since 2.0
	 *
	 * @return 		An error code
	 * @param[in]  	listener 		A reference to the IWifiDirectGroupClientListener instance
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OBJ_NOT_FOUND	The specified object is not found within the indicated range.
	 */
	result RemoveWifiDirectGroupClientListener(const IWifiDirectGroupClientListener &listener);

	/**
	 * Activates the local Wi-Fi Direct device.
	 *
	 * @since 		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The activation is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_IN_PROGRESS		The activation process is in progress.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	 *									For example, the Wi-Fi Direct device is already activated.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @see			IWifiDirectDeviceListener::OnWifiDirectDeviceActivated()
	 */
	result Activate(void);

	/**
	 * Checks whether the local device is activated.
	 *
	 * @since 		2.0
	 *
	 * @return		@c true if the local device is activated, @n
	 *				else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	bool IsActivated(void) const;

   /**
	* Deactivates the local Wi-Fi Direct device.
	*
	* @since 		2.0
	*
	* @privlevel	NORMAL
    * @privgroup	WIFI
	*
	* @return		An error code 
	* @exception	E_SUCCESS			The deactivation is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_IN_PROGRESS		The deactivation process is in progress.
	* @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	* 									For example, the Wi-Fi Direct device is already deactivated.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see			IWifiDirectDeviceListener::OnWifiDirectDeviceDeactivated()
	*/
	result Deactivate(void);

	/**
	 * Gets the current setting information of a Wi-Fi Direct group.
	 *
	 * @since 		2.0
	 *
	 * @return		The Wi-Fi Direct group information, @n
	 *				else @c null
 	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	WifiDirectGroupInfo* GetGroupSettingInfoN(void) const;

	/**
	 * Gets the current information of a Wi-Fi Direct device.
	 *
	 * @since 		2.0
	 *
	 * @return		The Wi-Fi Direct device information, @n
	 *				else @c null
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	WifiDirectDeviceInfo* GetLocalDeviceInfoN(void) const;

    /**
     * Gets the preferred method for the Wi-Fi Protected Setup (WPS) configuration.
     *
     * @since 		2.0
     *
     * @return      The preferred configuration mode for WPS
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				WIFI_WPS_CONFIG_MODE_NONE will be returned in case of the E_SYSTEM exception.
	 */
    WifiWpsConfigurationMode GetWpsConfigurationModePreference(void) const;


	/**
	 * Sets the name of a local device.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	name				The name of a local device
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified device name is an empty string.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	 *									For example, the Wi-Fi Direct device is already activated.
	 *
	 * @remarks 	This method does not affect the system setting and the device name is only valid during the group lifetime. @n
	 *              When an application in the deactivated state calls this method, the peer devices
	 *				detect the device specified in the @c name parameter.
	 *				For example, use this method before using Activate(). @n
	 *              The specified device name is automatically truncated if its size is greater than @c 64 bytes.
	 */
	result SetLocalDeviceName(const Osp::Base::String &name);

    /**
    * Sets the preferred method for the WPS configuration.
    *
    * @since 		2.0
    *
    * @return		An error code
    * @param[in]	mode   				The preferred mode for the WPS configuration
    * @exception 	E_SUCCESS           The method is successful.
    * @exception 	E_SYSTEM            A system error has occurred.
    * @exception 	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
    *									For example, the Wi-Fi Direct device is a group member.
    *
    * @remarks   The preferred configuration mode of the system is the Push Button Configuration (PBC) method. @n
    *            This method can change the preferred configuration method for the WPS procedure.
    *            If the remote device does not support the specified configuration method,
    *            a common configuration method is selected between the two devices automatically.
    *            Therefore, this method does not guarantee the use of specified WPS configuration method. @n
    *            This method should be called before using CreateGroup() or Associate() to specify the user preferred WPS configuration mode.
    */
    result SetWpsConfigurationModePreference(WifiWpsConfigurationMode mode);


	/**
	 * Creates a Wi-Fi Direct group by negotiating with a nearby Wi-Fi Direct device.
	 *
	 * @since 		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 *
	 * @param[in]	pWifiDirectGroupInfo		A pointer to WiFiDirectGroupInfo
	 * @param[in]	pWifiDirectRemoteDeviceInfo	A pointer to WiFiDirectDeviceInfo
	 * @exception	E_SUCCESS		  			The method is successful.
	 * @exception	E_SYSTEM  	 	 			A system error has occurred.
	 * @exception	E_IN_PROGRESS				A previous request is in progress.
	 * @exception	E_INVALID_ARG				The specified @c pWifiDirectRemoteDeviceInfo contains an invalid argument.
	 * @exception	E_INVALID_OPERATION			The current state of the instance prohibits the execution of this operation. @n
	 *											For example, the Wi-Fi Direct group is already created.
	 * @exception	E_PRIVILEGE_DENIED  		The application does not have the privilege to call this method.
	 *
	 * @remarks		It is not mandatory for this method to contain values in both the parameters. @n
	 * 				If @c pWifiDirectGroupInfo is specified and the group is created with the specified group configuration information,
     * 				this group configuration information is valid until the group is destroyed. @n
	 * 				If @c pWifiDirectGroupInfo is not specified, the Wi-Fi Direct group is created as per the default system configuration settings. @n
	 * 				If @c pWifiDirectRemoteDeviceInfo is not specified, the Wi-Fi Direct group is created with the first found device having the same local 
	 *				device name. @n
	 * 				Use SetLocalDeviceName() method to set the device name before activation. @n
	 * 				To obtain a list of Wi-Fi Direct devices that can be candidates for the @c pWifiDirectRemoteDeviceInfo parameter, use the Scan() method 
	 *				prior to using this method. @n
	 * 				To connect a specified Wi-Fi Direct group owner directly, the Scan() and Associate() methods can be used. @n
	 * 				Before this method is called, the event listeners should be added in order to ensure the completion of group creation and to process the 
	 *				request as a group owner or client. @n
	 * 				If the autonomous group owner mode is set to @c true in the specified @c pWifiDirectGroupInfo parameter, 
	 * 				@c pWifiDirectRemoteDeviceInfo should be set to @c null and IWifiDirectGroupClientListener would not be required.
	 *
	 * @see 		IWifiDirectDeviceListener::OnWifiDirectGroupCreatedN()
	 */
	result CreateGroup(const WifiDirectGroupInfo *pWifiDirectGroupInfo = null, const WifiDirectDeviceInfo *pWifiDirectRemoteDeviceInfo = null);

	/**
	 * Cancels the Wi-Fi Direct group creation.
	 *
	 * @since 		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_IN_PROGRESS		A previous request is in progress.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	 * 									For example, when there is no group being created.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 *
	 * @see			Associate(), CreateGroup(), IWifiDirectDeviceListener::OnWifiDirectGroupCreatedN()
	 */
	result CancelGroupCreation(void);

	/**
	 * Scans the nearby Wi-Fi Direct devices.
	 *
	 * @since 		2.0
	 *
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_IN_PROGRESS		A previous request is in progress.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
     *									For example, the Wi-Fi Direct device is deactivated.
	 * @exception	E_PRIVILEGE_DENIED 	The application does not have the privilege to call this method.
	 *
	 * @see			IWifiDirectDeviceListener::OnWifiDirectScanCompletedN()
	 *
	 * @remarks		This operation does not work while the Wi-Fi scanning or connection to the AP is in progress or established.
	 */
	result Scan(void);

    /**
     * Cancels the previous Wi-Fi Direct scan operation.
	 *
	 * @since 		2.0
     *
     * @privlevel   NORMAL
     * @privgroup   WIFI
     *
     * @return      An error code
     *
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_SYSTEM			A system error has occurred.
	 * @exception	E_IN_PROGRESS		A previous request is in progress.
     * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	 *									For example, the scan operation is not in process.
     * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     *
     * @see			IWifiDirectDeviceListener::OnWifiDirectScanCompletedN()
     */
    result CancelScan(void);


	/**
	* Establishes a connection with a specific group owner.
	*
	* @since 		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	WIFI
	*
	* @return		An error code
	* @param[in]	wifiDirectGroupOwnerDeviceInfo	The WiFiDirectDeviceInfo value of a group owner
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM						A system error has occurred.
	* @exception	E_IN_PROGRESS					A previous request or group creation is in progress.
	* @exception 	E_INVALID_ARG					The specified @c wifiDirectGroupOwnerDeviceInfo contains an invalid argument.
	* @exception    E_INVALID_OPERATION				The current state of the instance prohibits the execution of this operation. @n
	* 												For example, the member type of a device is already a group owner or client. 
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*
	* @remarks		If a connection is already established with another device, the previous connection should be disconnected
	*				before using this method.
	*
	* @see			IWifiDirectDeviceListener::OnWifiDirectAssociationCompleted()
	*/
	result Associate(const WifiDirectDeviceInfo &wifiDirectGroupOwnerDeviceInfo);

	/**
	 * Gets the Wi-Fi Direct member instance.
	 *
	 * @since 2.0
	 *
	 * @return		The Wi-Fi Direct member instance, @n
	 *				else @c null if the status of the device is WIFI_DIRECT_GROUP_MEMBER_TYPE_NONE
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation. @n
	 *									For example, the member type of a device is not a group owner or client.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	WifiDirectGroupMember* GetWifiDirectMemberN(void);
	
	/**
     * Checks whether the local Wi-Fi Direct device is currently discoverable.
     *
     * @since 2.0
     *
     * @return      @c true if the local Wi-Fi Direct device is currently discoverable, @n
     *              else @c false
     *
     * @remarks     At times, even though the Wi-Fi Direct device is activated the device cannot be discovered due to the visibility
	 *				setting, or if the device is performing some operation, such as Wi-Fi scanning. 
     *              
     */
    bool IsDiscoverable(void) const;

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see 		Construct()
	 */
    WifiDirectDevice(void);

	WifiDirectDevice(const WifiDirectDevice& value);

	WifiDirectDevice& operator =(const WifiDirectDevice& rhs);

	/**
	 * Initializes this instance of %WifiDirectDevice.
	 *
	 * @return 		An error code
	 * @param[in]  	localDeviceId 	An ID for a Wi-Fi Direct device
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_INVALID_STATE This instance is in an invalid state. @n
	 *								For example, this instance has already been constructed.
	 * @exception	E_INVALID_ARG	The specified @c localDeviceId is invalid.
	 */
	result Construct(WifiDirectDeviceId localDeviceId);
		

//Member variables
private :
	__WifiDirectDeviceImpl* __pWifiDirectDeviceImpl;
	friend class __WifiDirectDeviceImpl;

};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTDEVICE_H_

