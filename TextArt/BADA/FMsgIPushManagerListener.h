/* $Change: 618169 $ */
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
 * @file		FMsgIPushManagerListener.h
 * @brief		This is the header file for the %IPushManagerListener interface.
 *
 * This header file contains the declarations of the %IPushManagerListener interface.
 */

#ifndef _FMSG_IPUSHMANAGERLISTENER_H_
#define _FMSG_IPUSHMANAGERLISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FMsgConfig.h"

namespace Osp { namespace Messaging {

	/**
	* @interface	IPushManagerListener
	* @brief		This listener interface receives the registration result.
	* @since		2.0
	*
	* The %IPushManagerListener interface must be implemented to receive results of the push event registration. An application must register this interface using the PushManager::Construct() method.
	*/
	class  _EXPORT_MSG_ IPushManagerListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations	
	public:
		/**
		* Called when the result is received from PushManager::RegisterPushService().
		*
		* @since		2.0
		* @param[in]	reqId				The request ID
		* @param[in]	registrationId		The registration ID of the device @n
        *                                   The application should deliver this ID to the application server.
		* @param[in]	r					The result of the request
		* @param[in]	errorCode			The error code from the server
		* @param[in]	errorMsg			The error message from the server
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_SYSTEM			An unknown operating system error has occurred.
		* @exception	E_CONNECTION_FAILED	The network connection has failed.
		* @exception	E_SERVER			An error has occurred on the server side.
		* @exception	E_SERVICE_UNAVAILABLE	The service is unavailable. @n
		* Check whether <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	    *				Component Setup</a> is completed.	
		* @see			PushManager::RegisterPushService()
		*/
		virtual void OnPushServiceRegistered(RequestId reqId, const Osp::Base::String& registrationId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

		/**
		* Called when the result is received from PushManager::UnregisterPushService().
		*
		* @since		2.0
		* @param[in]	reqId				The request ID
		* @param[in]	r					The result of the request
		* @param[in]	errorCode			The error code from the server
		* @param[in]	errorMsg			The error message from the server
		* @exception 	E_SUCCESS			The method is successful.
		* @exception	E_SYSTEM			An unknown operating system error has occurred.
		* @exception	E_CONNECTION_FAILED	The network connection has failed.
		* @exception	E_SERVER			An error has occurred on the server side.
		* @see			PushManager::UnregisterPushService()
		*/
		virtual void OnPushServiceUnregistered(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	};
};
};

#endif // _FMSG_IPUSHLISTENER_H_
