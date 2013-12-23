/* $Change: 1144988 $ */
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
 * @file		FNetWifiAdhocService.h 
 * @brief		This is the header file for the %AdhocService class.
 *
 * This header file contains the declarations of the %AdhocService class.
 */

#ifndef _FNET_WIFI_ADHOCSERVICE_H_
#define _FNET_WIFI_ADHOCSERVICE_H_


#include "FBase.h"
#include "FNetConfig.h"
#include "FNetWifiWifiTypes.h"
#include "FNetWifiIAdhocServiceEventListener.h"

namespace Osp {
    namespace Net {

// Forward declaration
class IpAddress;

        namespace Wifi {

// Forward declaration
class __AdhocServiceAgent;

/**
 * @class		AdhocService
 * @brief		This class provides the methods for the opening service through an ad hoc network.
 * @deprecated 	This class is deprecated. Instead of using this class, it is recommended to use classes related with Wi-Fi Direct.
 * @since		1.0
 *
 * 	The %AdhocService class provides the methods for creating an ad hoc network, and managing the ad hoc service. It also enables the listener to get 
 * 			the events related to the ad hoc service.
 *
 * The following example demonstrates how to use the %AdhocService class to create, initialize, and manage an ad hoc service instance.
 *
 * @code
 *
 *	using namespace Osp::Net::Wifi;
 *
 *	result
 *	MyClass::AdhocServiceSample(void)
 *	{
 *		// Creates a listener for AdhocService.
 *		MyListenerClass adhocListener;				
 *
 *		// Creates an instance of AdhocService.
 *		AdhocService adhocService(adhocListener);	
 *		
 *		// Start the AdhocService.
 *		adhocService.StartAdhocService("CompanyName","AppName", WIFI_RADIO_CHANNEL_6, true);
 *	
 *      // Send a broadcast message to a peer.
 *		String message = String("BROADCAST MESSAGE");
 * 		adhocService.SendBroadcastMessage(message);
 *
 *		// Stop the AdhocService. 
 *		adhocService.StopAdhocService();
 *	}
 *
 * @endcode
 *
 */

class _EXPORT_NET_ AdhocService : public Osp::Base::Object
{

// Lifecycle
public:
	
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 * @param[in]  	listener		A reference to the listener instance
	 */
	AdhocService(const IAdhocServiceEventListener& listener);
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	~AdhocService(void);

// Operations
public:

	 /**
	 * Starts an ad hoc service. 
	 *
	 * @since 		 	1.0
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 *                	For more information, see issues in version @ref AdhocServiceStartAdhocServicePage1 "1.2" and @ref AdhocServiceStartAdhocServicePage2 "2.0".
	 * @privlevel		NORMAL
	 * @privgroup		WIFI
	 *
	 * @return			An error code
	 * @param[in]		companyName				The name of the company
	 * @param[in]		appName					The application name
	 * @param[in]		channel					The radio channel
 	 * @param[in]		autoScan				Set to @c true to collect the neighboring peer information and to notify the neighboring peer with the 
	 *											information of the current device automatically, @n
	 *											else @c false
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The ad hoc service has already started.
	 * @exception		E_IN_PROGRESS			A previous request is in progress.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception		E_INVALID_ARG			The specified @c companyName or @c appName is an empty string. @n
	 *											Or, the length of @c companyName @c appName exceeds 31 characters.
	 * @exception		E_OUT_OF_MEMORY  		The memory is insufficient.
	 * @exception		E_SYSTEM  				A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	 * @remarks			An ad hoc connection is created with the Service Set Identifier (SSID) "companyName_appName".
	 * @see				IAdhocServiceEventListener::OnAdhocServiceStarted()
	 */

	result StartAdhocService(const Osp::Base::String& companyName, const Osp::Base::String& appName, 
		WifiRadioChannel channel=WIFI_RADIO_CHANNEL_6, bool autoScan=true);
		
	/**
	 * @page	AdhocServiceStartAdhocServicePage1	Compatibility for StartAdhocService()
	 *
	 * @section	AdhocServiceStartAdhocServicePage1IssueSection	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -#  Returns E_SUCCESS instead of E_IN_PROGRESS, if StartAdhocService() is called when Wi-Fi is in a disconnecting state.
	 *
	 * @section	AdhocServiceStartAdhocServicePage1ResolutionSection	Resolutions
     * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	 
	/**
	 * @page	AdhocServiceStartAdhocServicePage2 Compatibility for StartAdhocService()
	 *
	 * @section	AdhocServiceStartAdhocServicePage2IssueSection Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 * -#  If the value of @c autoScan is @c false when StartAdhocService() is called, the neighbor information list is not updated periodically.
	 *
	 * @section AdhocServiceStartAdhocServicePage2ResolutionSection Resolutions
     *
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
     *	-#	The neighbor information is updated periodically regardless of the value of @c autoScan.
	 */

	/**
	 * Stops the ad hoc service.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The ad hoc service is stopped successfully.
	 * @exception	E_INVALID_STATE			The ad hoc service has not started as yet.
	 * @exception	E_IN_PROGRESS			A previous request is in progress.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	 * @see			IAdhocServiceEventListener::OnAdhocServiceStopped()
	 */
	result StopAdhocService(void);

	/**
	 * Sets the peer name. 
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	name					The peer name
	 * @exception	E_SUCCESS				The peer name is set successfully.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	 *										For example, this instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			The specified @c name is an empty string. @n
	 *										Or, the length of @c name exceeds 10 characters.
	 * @remarks 	PeerName is not a unique value in the ad hoc network.
	 */
	result SetPeerName(const Osp::Base::String& name);

	/**
	 * Gets the information of the neighboring peers. 
	 *
	 * @since 		1.0
	 * @return		A list of AdhocPeerInfo, @n
	 *				else @c null if no neighbor peer exists
	 * @remarks		If the value of @c autoScan is @c false when StartAdhocService() is called, the neighbor information list is not updated periodically 
	 *				and may be incorrect.
	 */
	Osp::Base::Collection::IList* GetNeighborsN(void) const;

	/**
	 * Sends a unicast message by the peer name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @param[in]	peerName				The peer name that receives the message
	 * @param[in]	message					The contents of the message to be sent
 	 * @exception	E_SUCCESS				The message is sent successfully.
 	 * @exception	E_INVALID_STATE			The ad hoc service has not been started yet.
	 * @exception	E_INVALID_ARG			The specified @c peerName is unknown or @c message is empty.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_MAX_EXCEEDED			The message length has exceeded the maximum limit of the socket.
	 * @remarks		As peer name is not unique, it may send multiple unicast messages.
	 */
	result SendUnicastMessage(const Osp::Base::String& peerName, const Osp::Base::String& message);

	/**
	 * Sends a unicast message by the IP address.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @param[in]	ipAddr					The IP address of the peer that receives the message
	 * @param[in]	message					The contents of the message to be sent
     * @exception	E_SUCCESS				The message is sent successfully.
	 * @exception	E_INVALID_STATE			The ad hoc service has not been started yet.
	 * @exception	E_INVALID_ARG			The specified @c ipAddr is invalid or @c message is empty.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_MAX_EXCEEDED			The message length has exceeded the maximum limit of the socket.
	 */
	result SendUnicastMessage(const Osp::Net::IpAddress& ipAddr, const Osp::Base::String& message);


	/**
	 * Sends a broadcast message to the peers in the same ad hoc service.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	WIFI
	 *
	 * @return		An error code
	 * @param[in]	message					The contents of the message to be sent
     * @exception	E_SUCCESS				The message is sent successfully.
	 * @exception	E_INVALID_STATE			The ad hoc service has not started as yet.
	 * @exception	E_INVALID_ARG			The specified @c message is empty.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_MAX_EXCEEDED			The message length has exceeded the maximum limit of the socket.
	 * @remarks		This method provides a non-connection oriented service without guaranteeing reliability, ordering, or data integrity. Thus, the data may 
	 * arrive out of order, appear duplicated, or go missing without notice.
	 */
	result SendBroadcastMessage(const Osp::Base::String& message);
	
private:
	AdhocService(const AdhocService& value);
	AdhocService& operator =(const AdhocService& value);

	__AdhocServiceAgent*			__pAdhocServiceAgent;

};

        }
    }
}
#endif // _FNET_WIFI_ADHOCSERVICE_H_
