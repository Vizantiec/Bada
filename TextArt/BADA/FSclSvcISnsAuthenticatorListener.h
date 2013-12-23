/* $Change: 1229193 $ */
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
 * @file		FSclSvcISnsAuthenticatorListener.h
 * @brief		This is the header file for the %ISnsAuthenticatorListener interface.
 *
 * This header file contains the declarations of the %ISnsAuthenticatorListener interface.
 */
#ifndef _FSCL_SVC_ISNS_AUTHENTICATOR_LISTENER_H_
#define _FSCL_SVC_ISNS_AUTHENTICATOR_LISTENER_H_

#include "FSclSvcSnsAuthResult.h"
#include "FSclConfig.h"
#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FBaseString.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsAuthenticatorListener
* @brief		This interface represents a listener that receives events associated with SnsAuthenticator.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* 	The %ISnsAuthenticatorListener interface represents a listener that receives events associated with SnsAuthenticator. The OnSnsAuthenticated() method returns an 
*			SnsAuthResult instance, which contains the result of authentication. If the user authenticates the application successfully, token key and token 
*			secret exists in the %SnsAuthResult instance.
*
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/authentication.htm">Authentication</a>. @n
* 
* The following example demonstrates how to use the %ISnsAuthenticatorListener interface.
*
* @code
* void
* MySample::OnSnsAuthenticated(Osp::Social::Services::SnsAuthResult& snsAuthResult,
*		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
* {
*     if (IsFailed(r))
*     {
*         // The request has failed because the network connection has failed or something.
*     }
*
*     if (snsAuthResult.GetTokenKey().IsEmpty() || snsAuthResult.GetTokenSecret.IsEmpty())
*     {
*         // The authentication is not successful because the user does not authenticate the application or something.
*     }
*     else (snsAuthResult.GetTokenKey().IsEmpty() == false && snsAuthResult.GetTokenSecret.IsEmpty() == false)
*     {
*         // The authentication is successful.
*     }
* }
* @endcode
* @n
*/
class  _EXPORT_SOCIAL_ ISnsAuthenticatorListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called to notify when the SnsAuthenticator::Authenticate() method is completed. @n
	* Receives the response to this method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	snsAuthResult			The result of authentication
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_SYSTEM				A system error has occurred.
	* @if PRIVCORE
	* @exception	E_SERVICE_BUSY			Authenticator AppControl is already running by the other application.
	* @endif
	* @see	SnsAuthenticator::Authenticate()
	*/
	virtual void	OnSnsAuthenticated(Osp::Social::Services::SnsAuthResult& snsAuthResult,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};

};};};

#endif
