/* $Change: 1202329 $ */
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
 * @file	FSclSvcISnsGatewayListener.h
 * @brief	This is the header file for the %ISnsGatewayListener interface.
 *
 * This header file contains the declarations of the %ISnsGatewayListener interface.
 */
#ifndef _FSCL_SVC_ISNS_GATEWAY_LISTENER_H_
#define _FSCL_SVC_ISNS_GATEWAY_LISTENER_H_


#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FSclConfig.h"

#include "FSclSvcSnsProfile.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsGatewayListener 
* @brief		This interface represents a listener that receives events associated with SnsGateway.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* The %ISnsGatewayListener interface represents a listener that receives events associated with SnsGateway.
*/
class  _EXPORT_SOCIAL_ ISnsGatewayListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called when the SnsGateway::IsLoggedIn() method is completed. @n
	* Receives the response to SnsGateway::IsLoggedIn() method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	serviceProvider			The service provider
	* @param[in]	isLoggedIn				The sign-in status @n
	*										Set to @c true if the user is signed in to the service provider, @n
	*										else @c false
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	*
	* @see	SnsGateway::IsLoggedIn()
	*/
	virtual void	OnSnsLoggedInStatusReceived(RequestId reqId, Osp::Base::String& serviceProvider, bool isLoggedIn,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
};

};};};

#endif
