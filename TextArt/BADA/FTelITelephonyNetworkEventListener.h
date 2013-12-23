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
 * @file		FTelITelephonyNetworkEventListener.h 
 * @brief		This is the header file for the %ITelephonyNetworkEventListener interface.
 *
 * This header file contains the declarations of the %ITelephonyNetworkEventListener interface.
 */
 
#ifndef _FTEL_TELEPHONY_NETWORK_EVENT_LISTENER_H_
#define _FTEL_TELEPHONY_NETWORK_EVENT_LISTENER_H_

#include "FBase.h"
#include "FTelConfig.h"
#include "FTelNetworkStatus.h"

namespace Osp { namespace Telephony {

/**
 * @interface	ITelephonyNetworkEventListener 
 * @brief		This interface provides the methods to listen to the change in status of the telephony network.
 * @since		1.0
 *
 * The %ITelephonyNetworkEventListener interface notifies the application about the changes in the telephony network status.
 *
 */
class _EXPORT_TEL_ ITelephonyNetworkEventListener
	: public Osp::Base::Runtime::IEventListener
{
// Operation
public:	

	/**
	* Called when the status of the telephony network is changed.
	*
	* @since			1.0
	*	@param[in]	networkStatus		The new network status
	*	@see				Osp::Telephony::NetworkStatus
	*/
	virtual void OnTelephonyNetworkStatusChanged(const NetworkStatus& networkStatus) = 0;
};	

};};
#endif // _FTEL_TELEPHONY_NETWORK_EVENT_LISTENER_H_
