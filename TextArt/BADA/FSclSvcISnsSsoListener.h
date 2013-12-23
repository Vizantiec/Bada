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
 * @file		FSclSvcISnsSsoListener.h
 * @brief		This is the header file for the %ISnsSsoListener interface.
 *
 * This header file contains the declarations of the %ISnsSsoListener interface.
 */
#ifndef _FSCLSVC_ISNS_SSO_LISTENER_H_
#define _FSCLSVC_ISNS_SSO_LISTENER_H_

#include "FBaseRtIEventListener.h"
#include "FSclSvcSnsTypes.h"

namespace Osp { namespace Social { namespace Services {

/**
 * @if PRIVCORE
 * @interface	ISnsSsoListener
 * @brief		This interface provides a listener that receives the events associated with the login status of the service provider.
 * @deprecated	This method is deprecated because it is not allowed to manage the information of the user's login status for SNS any longer.
 * @since		1.0
 *
 *  The %ISnsSsoListener interface provides a listener that receives the events associated with the login status of the service provider.
 * @endif
 */
class  _EXPORT_SOCIAL_ ISnsSsoListener:
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	* @if PRIVCORE
	* Called when a login action is invoked on the specific service provider. @n
	* If a login action is invoked, call the GetLoginStatus() method to get the login status.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of the user's login status for SNS any longer.
	* @since		1.0
	* @privlevel	CORE
	* @privgroup	SNS_SSO
	*
	* @param[in]	serviceProvider		The service provider @n
	*									Currently, this parameter is not supported. Do not use it.
	* @endif
	*/
	virtual void    OnSnsLoginInvoked(Osp::Social::Services::SnsSsoSp serviceProvider) = 0;

	/**
	* @if PRIVCORE
	* Called when a logout action is invoked on the specific service provider. @n
	* If a logout action is invoked, call the GetLoginStatus() method to get the login status.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of the user's login status for SNS any longer.
	* @since		1.0
	* @privlevel	CORE
	* @privgroup	SNS_SSO
	*
	* @param[in]	serviceProvider		The service provider @n
	* 									Currently, this parameter is not supported. Do not use it.
	* @endif
	*/
	virtual void    OnSnsLogoutInvoked(Osp::Social::Services::SnsSsoSp serviceProvider) = 0;
};

};};};// Osp::Social::Services

#endif

