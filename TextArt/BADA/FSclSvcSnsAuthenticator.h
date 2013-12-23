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
 * @file	FSclSvcSnsAuthenticator.h
 * @brief	This is the header file for the %SnsAuthenticator class.
 *
 * This header file contains the declarations of the %SnsAuthenticator class.
 */
#ifndef _FSCL_SVC_SNS_AUTHENTICATOR_H_
#define _FSCL_SVC_SNS_AUTHENTICATOR_H_

#include "FSclConfig.h"
#include "FBaseString.h"
#include "FBaseColIList.h"
#include "FAppAppControl.h"
#include "FAppIAppControlEventListener.h"
#include "FSclSvcISnsAuthenticatorListener.h"

namespace Osp { namespace Social { namespace Services {

/**
 * @class	SnsAuthenticator
 * @brief	This class provides the authentication for a %Social Network Service (SNS).
 * @deprecated	This class is deprecated due to the operation policy of the bada Server.
 * @since	1.0
 *
 * The %SnsAuthenticator class provides the authentication for a %Social Network Service (SNS).
 * It implements the authentication mechanism of a service provider. Implementing the authentication mechanism of a service provider is complicated 
 * and difficult, but it is necessary to access the protected resources of the user. However, %SnsAuthenticator makes it easier to implement these 
 * mechanisms. Each method of %SnsAuthenticator acts as a proxy for the whole authentication process. The only thing that is to be done is to create an 
 * application on the service provider, and get the consumer key and consumer secret. The authentication mechanism depends on the 
 * service provider.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/authentication.htm">Authentication</a>.
 *
 */

class  _EXPORT_SOCIAL_ SnsAuthenticator
	:	public Osp::Base::Object,
	public Osp::App::IAppControlEventListener
{

public:
	/**
	 * This is the default constructor for this class. @n
	 * This creates an uninitialized instance of %SnsAuthenticator.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	SnsAuthenticator(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsAuthenticator(void);

	/**
	* Initializes this instance of %SnsAuthenticator with the specified listener.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	authenticatorListener	The event listener
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has already been constructed, or @n
	*										initializing this instance has failed.
	*/
	result Construct(const Osp::Social::Services::ISnsAuthenticatorListener& authenticatorListener);

private:
	SnsAuthenticator(const SnsAuthenticator& value);
	SnsAuthenticator& operator =(const SnsAuthenticator& value);

public:

	/**
	 * Authenticates the application. @n
	 * This method supports the browser-based authentication in version 1.0. The user can authenticate the application using a browser and the result can be 
	 * received using ISnsAuthenticatorListener::OnSnsAuthenticated().
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider			The service provider to authenticate
	 * @param[in]	consumerKey				The application consumer key obtained from the service provider
	 * @param[in]	consumerSecret			The application consumer secret obtained from the service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is an empty string.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_IN_PROGRESS			The SnsAuthenticator AppControl is already in progress.
	 * @exception	E_OBJ_NOT_FOUND			The SnsAuthenticator AppControl resource is not found.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		For Facebook, extended permissions are required to access user data. This method internally requests for some permissions during the 
	 *				authentication process. The obtained permissions are then used to access the methods of @c SnsGateway.
	 * 				The Authenticate(const Osp::Base::String& serviceProvider, const Osp::Base::String& consumerKey, const Osp::Base::String& consumerSecret, 
	 *				const Osp::Base::String& permissions) method takes the @c permissions parameter to request specific permissions.
	 * @see		Construct()
	 * @see		ISnsAuthenticatorListener::OnSnsAuthenticated()
	 */
	result Authenticate(const Osp::Base::String& serviceProvider, const Osp::Base::String& consumerKey, const Osp::Base::String& consumerSecret);

	/**
	 * Authenticates the application with the specified permissions. @n
	 * The user can authenticate the application using a browser and the result can be received using ISnsAuthenticatorListener::OnSnsAuthenticated().
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	SNS_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider		    The service provider to authenticate
	 * @param[in]	consumerKey			    The application consumer key obtained from the service provider
	 * @param[in]	consumerSecret		    The application consumer secret obtained from the service provider
	 * @param[in]	permissions			    The comma-separated list of permissions defined by the service provider @n
	 * 										There should be no space in a comma-separated list.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is an empty string.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_IN_PROGRESS			The SnsAuthenticator AppControl is already in progress.
	 * @exception	E_OBJ_NOT_FOUND			The SnsAuthenticator AppControl resource is not found.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		Refer to the service provider document for permissions. The current available service provider is Facebook.
	 * @see 		Construct()
	 * @see 		ISnsAuthenticatorListener::OnSnsAuthenticated()
	 */
	result Authenticate(const Osp::Base::String& serviceProvider, const Osp::Base::String& consumerKey, const Osp::Base::String& consumerSecret, const Osp::Base::String& permissions);

	/**
	 * @if PRIVCORE
	 * Authenticates the application with the specified permissions as the new user. @n
	 * User can authenticate the application using a browser and the result can be received using ISnsAuthenticatorListener::OnSnsAuthenticated(). @n
	 * If this method is called, the login page for the new authentication is displayed.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_SNS
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider		    The service provider to authenticate
	 * @param[in]	consumerKey			    The application consumer key obtained from the service provider
	 * @param[in]	consumerSecret		    The application consumer secret obtained from the service provider
	 * @param[in]	permissions			    The comma-separated list of permissions defined by the service provider @n
	 * 										There should be no space in a comma-separated list.
	 * @exception	E_SUCCESS				The method was successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is an empty string.
	 * @exception	E_SYSTEM				A system error occurred.
	 * @exception	E_IN_PROGRESS			The SnsAuthenticator AppControl is already in progress.
	 * @exception	E_OBJ_NOT_FOUND			The SnsAuthenticator AppControl resource was not found.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @remarks Refer to the service provider document for permissions. The current available service provider is Facebook.
	 * @see Construct()
	 * @see ISnsAuthenticatorListener::OnSnsAuthenticated()
	 * @endif
	 */
	result AuthenticateAsNewUser(const Osp::Base::String& serviceProvider, const Osp::Base::String& consumerKey, const Osp::Base::String& consumerSecret, const Osp::Base::String& permissions);

	/**
	 * @if PRIVCORE
	 * Authenticates the application with the specified permissions as the last authorized user. @n
	 * User can authenticate the application using a browser and the result can be received using ISnsAuthenticatorListener::OnSnsAuthenticated(). @n
	 * If user has already authenticated an application which used AuthenticateAsNewUser() or this method, the user need not enter the credential any longer to authenticate other applications which use this method.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_SNS
	 *
	 * @return		An error code
	 * @param[in]	serviceProvider		    The service provider to authenticate
	 * @param[in]	consumerKey			    The application consumer key obtained from the service provider
	 * @param[in]	consumerSecret		    The application consumer secret obtained from the service provider
	 * @param[in]	permissions			    The comma-separated list of permissions defined by the service provider @n
	 * 										There should be no space in a comma-separated list.
	 * @exception	E_SUCCESS				The method was successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed yet.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			A specified input parameter is an empty string.
	 * @exception	E_SYSTEM				A system error occurred.
	 * @exception	E_IN_PROGRESS			The SnsAuthenticator AppControl is already in progress.
	 * @exception	E_OBJ_NOT_FOUND			The SnsAuthenticator AppControl resource was not found.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @remarks Refer to the service provider document for permissions. The current available service provider is Facebook.
	 * @see Construct()
	 * @see ISnsAuthenticatorListener::OnSnsAuthenticated()
	 * @endif
	 */
	result AuthenticateAsLastAuthorizedUser(const Osp::Base::String& serviceProvider, const Osp::Base::String& consumerKey, const Osp::Base::String& consumerSecret, const Osp::Base::String& permissions);

private:
	void  OnAppControlCompleted (const Osp::Base::String &appControlId, const Osp::Base::String &operationId, const Osp::Base::Collection::IList *pResultList);

private:
	ISnsAuthenticatorListener*  __pAuthListener;
	Osp::App::AppControl* __pAuthAppControl;
	Osp::App::AppControl* __pCommonAuthAppControl;

	friend class SnsAuthenticatorEx;
	class SnsAuthenticatorEx* __pSnsAuthenticatorEx;
};

};};};

#endif
