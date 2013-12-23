/* $Change: 1198808 $ */
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
 * @file	FSclSvcSnsSsoManager.h
 * @brief	This is the header file for the %SnsSsoManager class.
 *
 * This header file contains the declarations of the %SnsSsoManager class.
 */
#ifndef _FSCL_SVC_SNS_SSO_MANAGER_H_
#define _FSCL_SVC_SNS_SSO_MANAGER_H_

#include "FSclSvcISnsSsoListener.h"
#include "FSclSvcSnsLoginStatus.h"
#include "FSclConfig.h"
#include "FBaseString.h"

namespace Osp { namespace Social { namespace Services {

class ISnsSsoManagerPi;
class _SnsSsoEvent;
/**
 * @if PRIVCORE
 * @class		SnsSsoManager
 * @brief		This class provides the methods to manage the login status information of the SNS.
 * @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
 * @since		1.0
 *
 * The %SnsSsoManager class provides the methods to manage the login status information of the SNS.
 * 
 * @endif
 *
 */

class  _EXPORT_SOCIAL_ SnsSsoManager:
	public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This creates an uninitialized instance of %SnsSsoManager.
	 *
	 * @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	SnsSsoManager(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since		1.0
	*/
	virtual ~SnsSsoManager(void);

	/**
	* Initializes this instance of %SnsSsoManager with the specified listener.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since		1.0
	* @return		An error code
	* @param[in]	pSsoListener		The listener to receive the notification of the login status
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	*/
	result Construct(const ISnsSsoListener* pSsoListener);

private:
	SnsSsoManager(const SnsSsoManager& value);
	SnsSsoManager& operator =(const SnsSsoManager& value);

public:

	/**
	 * @if PRIVCORE
	 * Sets the login status information.
	 *
	 * @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	SNS_SSO
	 *
	 * @return		An error code
	 * @param[in]	loginStatus				The login information for a specific service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see 		Construct()
	 * @remarks		Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result SetLoginStatus(const Osp::Social::Services::SnsLoginStatus& loginStatus);


	/**
	 * @if PRIVCORE
	 * Gets the login status for all the service providers. @n
	 * This method returns a formatted string that contains the login status and other session information. @n
	 * Format: @n
	 * strTmpSpName|&&|IsSpLoginned|&&|LoginID|&&|LoginPassword|&&|SessionKey|&&|CryptoSessionKey|&&|UserSpId|&&|DisplayName|&&|ProfilePhotoUrl|&&|RedirecURL|&&|MKey
	 * @n
	 * Attributes are separated with '|&&|' and each service provider is separated with ';'.
	 * An attribute can be skipped if it has no data, but the '|&&|' token needs to be added.
	 *
	 * @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	SNS_SSO
	 *
	 * @return		The login status information
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see 		Construct()
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * 				Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	Osp::Base::String GetLoginStatus(void);


private:
	ISnsSsoManagerPi* __pISsoManagerPi;
	_SnsSsoEvent* __pSnsSsoEvent;

	friend class SnsSsoManagerEx;
	class SnsSsoManagerEx* __pSnsSsoManagerEx;
};

};};};

#endif
