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
 * @file	FNetWifiWifiDirectGroupClient.h 
 * @brief	This is the header file for the %WifiDirectClient class.
 *
 * This header file contains the declarations of the %WifiDirectClient class.
 */

#ifndef _FNET_WIFI_WIFIDIRECTGROUPCLIENT_H_
#define _FNET_WIFI_WIFIDIRECTGROUPCLIENT_H_

// Includes
#include "FNetConfig.h"
#include "FNetWifiWifiDirectGroupMember.h"

namespace Osp {	namespace Net {	namespace Wifi {

// Forward declaration
class __WifiDirectGroupClientImpl;
class WifiDirectDeviceInfo;
  
/**
 * @class	WifiDirectGroupClient
 * @brief	This class provides methods for the Wi-Fi Direct group client management.
 * @since	2.0
 * 
 * 	The %WifiDirectGroupClient class provides the methods to manage the Wi-Fi Direct client.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/wi-fi_direct_connectivity.htm">Wi-Fi Direct Connectivity</a>.
 */

class _EXPORT_NET_ WifiDirectGroupClient: public WifiDirectGroupMember
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~WifiDirectGroupClient(void);


// Operations
public:
	/**
	* Closes the Wi-Fi connection.
	*
	* @since		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	WIFI
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
    * @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_IN_PROGRESS			A previous request is in progress.
	* @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	*										For example, when the member type of a device is not a Wi-Fi Direct group client.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*
	* @see			IWifiDirectGroupClientListener::OnWifiDirectAssociationTerminated()
	*/
	result Disassociate(void);

   /**
    * Requests the Wi-Fi direct device information of the group owner.
	*
	* @since 2.0
    *
    * @privlevel     NORMAL
    * @privgroup     WIFI
    *
    * @return       An error code
	* @param[in]	portNumber				A port number to connect the group member information service with DEFAULT_PORT (3895)
    * @exception    E_SUCCESS				The method is successful.
    * @exception    E_SYSTEM				A system error has occurred.
    * @exception    E_IN_PROGRESS			The previous request for the group owner information is in progress.
    * @exception    E_INVALID_OPERATION		The current state of the instance prohibits the execution of this operation. @n
	*										For example, when the member type of a device is not a Wi-Fi Direct group client.
	* @exception	E_OUT_OF_RANGE			The specified port number is less than @c 1024 or greater than @c 65535.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
    *
    * @see			IWifiDirectGroupClientListener::OnWifiDirectGroupOwnerInfoReceived()
    *
    * @remarks		The port number used by the group owner should be specified if the group owner changes the port number in WifiDirectGroupOwner::StartGroupMemberInfoService().
    */
	result RequestGroupOwnerInfo(int portNumber = DEFAULT_PORT);

	/**
	* Requests the WifiDirectDeviceInfo list of the Wi-Fi Direct group members.
	*
	* @since		2.0
	*
	* @privlevel     NORMAL
	* @privgroup     WIFI
	*
	* @return       An error code
	* @param[in]	portNumber				A port number to connect the group member information service with DEFAULT_PORT (3895)
	* @exception    E_SUCCESS				The method is successful.
	* @exception    E_SYSTEM				A system error has occurred.
	* @exception    E_IN_PROGRESS			The previous request for the group owner information is in progress.
	* @exception    E_INVALID_OPERATION		The current state of the instance prohibits the execution of this operation. @n
	*										For example, when the member type of a device is not a Wi-Fi Direct group client.
	* @exception	E_OUT_OF_RANGE			The specified port number is less than @c 1024 or greater than @c 65535.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*
	* @see			IWifiDirectGroupClientListener::OnWifiDirectAllGroupMemberInfoReceivedN()
    *
    * @remarks		The port number used by the group owner should be specified if the group owner changed the port number in WifiDirectGroupOwner::StartGroupMemberInfoService().
	*/
	result RequestAllGroupMemberInfo(int portNumber = DEFAULT_PORT);

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
     *
	 * @see 		Construct()
	 */
	WifiDirectGroupClient(void);

	/**
	 * Initializes this instance of WifiDirectGroupClient with the specified parameter.
	 *
	 * @return		An error code
	 *
	 * @param[in]  	wifiDirectGroupClientImpl	A reference to the __WifiDirectGroupClientImpl instance
	 * @exception	E_SUCCESS 					The method is successful.
	 * @exception	E_SYSTEM 					A system error has occurred.
	 * @exception	E_INVALID_STATE 			This instance is in an invalid state. @n
	 *											For example, this instance has already been constructed.
	 */
	result Construct(__WifiDirectGroupClientImpl& wifiDirectGroupClientImpl);

private:
	static const int DEFAULT_PORT = 3895;

//Member variables
private :
	WifiDirectGroupClient(const WifiDirectGroupClient& value);
	WifiDirectGroupClient& operator =(const WifiDirectGroupClient& rhs);

	__WifiDirectGroupClientImpl* __pWifiDirectGroupClientImpl;

	friend class __WifiDirectGroupClientImpl;



};
}}}// Osp::Net::Wifi

#endif // _FNET_WIFI_WIFIDIRECTGROUPCLIENT_H_

