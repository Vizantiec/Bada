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
 * @file		FNetWifiIAdhocServiceEventListener.h
 * @brief		This is the header file for the %IAdhocServiceEventListener interface.
 *
 * This header file contains the declarations for the %IAdhocServiceEventListener interface.
 *
 */

#ifndef _FNET_WIFI_IADHOCSERVICEEVENTLISTENER_H_
#define _FNET_WIFI_IADHOCSERVICEEVENTLISTENER_H_

#include "FBase.h"

namespace Osp {
    namespace Net {

// Forward declaration
class NetConnection;

		namespace Wifi {

/**
* @interface	IAdhocServiceEventListener
* @brief		This interface implements listeners for the ad hoc service events.
* @deprecated   This interface is deprecated. Instead of using this interface, it is recommended to use interfaces related with Wi-Fi Direct.
* @since		1.0
*
* The %IAdhocServiceEventListener interface implements listeners for the ad hoc service events.
*
*/
class _EXPORT_NET_ IAdhocServiceEventListener : public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IAdhocServiceEventListener(void) {}

// Operations
public:
	/**
	* Called to notify that the ad hoc service has started.
	*
	* @since		1.0
	* @param[in]	pNetConnection		The network connection that is started with an ad hoc net account, @n
	*									@c null if starting the network connection fails
	* @param[in]	r					The error code that occurs during the starting process
	* @exception	E_SUCCESS			The service has started successfully.
	* @exception	E_FAILURE			The method has failed to start the service.
	* @see			Osp::Net::Wifi::AdhocService::StartAdhocService()
	*/
	virtual void OnAdhocServiceStarted(const Osp::Net::NetConnection* pNetConnection, result r) = 0;

	/**
	* Called to notify that the ad hoc service is stopped.
	*
	* @since		1.0
	* @param[in]	r					The error code that occurs during the stopping process
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_FAILURE			The method has failed.
	* @see			Osp::Net::Wifi::AdhocService::StopAdhocService()
	*/
	virtual void OnAdhocServiceStopped(result r) = 0;

	/**
	* Called to notify that the message is received from a neighboring peer.
	*
	* @since		1.0
	* @param[in]	peerName		The peer name of the sender 
	* @param[in]	message			The message received
	*/
	virtual void OnMessageReceived(const Osp::Base::String& peerName , const Osp::Base::String& message) = 0;

};
		}
	}
}

#endif // _FNET_WIFI_IADHOCSERVICEEVENTLISTENER_H_
