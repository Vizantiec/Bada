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
* @file		FSclSvcSnsLoginStatus.h
* @brief	This is the header file for the %SnsLoginStatus class.
*
* This header file contains the declarations of the %SnsLoginStatus class.
*/
#ifndef _FSCL_SVC_SNS_LOGIN_STATUS_H_
#define _FSCL_SVC_SNS_LOGIN_STATUS_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FSclSvcSnsTypes.h"

namespace Osp { namespace Social { namespace Services {

/**
 * @if PRIVCORE
 * @class		SnsLoginStatus
 * @brief		This class provides the information about an SNS login status.
 * @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
 * @since		1.0
 *
 * The %SnsLoginStatus class provides the information about an SNS login status.
 * 
 * @endif
*/
class  _EXPORT_SOCIAL_ SnsLoginStatus :
	public Osp::Base::Object
{
public:
	/**
	* @internal
	* This is internal. If used in an application, the application can get rejected during the certification process. @n
	* Initializes this instance of SnsLoginStatus with the specified parameters.
	* Sets the information of login status. If an attribute has no specific data, set as empty string.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of user's login status for SNS any longer.
	*
	* @since 			1.0
	* @param[in]	serviceProvider			The service provider
	* @param[in]	isLoggedIn				The login status @n
											@c true, if user is logged-in @n
											@c false, otherwise
	* @param[in]	loginId					The user login ID
	* @param[in]	loginPassword			The user login password
	* @param[in]	sessionKey				The session key
	* @param[in]	cryptoSessionKey		The crypto session key
	* @param[in]	snsUserId				The SNS people ID of logged-in user
	* @param[in]	displayName				The display name of logged-in user
	* @param[in]	profilePhotoUrl			The URL of profile photo of logged-in user
	* @param[in]	spKey					The key for the service provider
	*/
	SnsLoginStatus(SnsSsoSp serviceProvider, bool isLoggedIn,
			const Osp::Base::String& loginId, const Osp::Base::String& loginPassword,
			const Osp::Base::String& sessionKey, const Osp::Base::String& cryptoSessionKey,
			const Osp::Base::String& snsUserId, const Osp::Base::String& displayName,
			const Osp::Base::String& profilePhotoUrl, const Osp::Base::String& spKey);

	/**
	* Initializes this instance of %SnsLoginStatus with the specified parameters. @n
	* Sets the information of the login status. If an attribute has no specific data, it is set as an empty string.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @param[in]	serviceProviderName		The service provider name
	* @param[in]	isLoggedIn				The login status @n
	*										Set to @c true if the user is logged-in, @n
	*										else @c false
	* @param[in]	loginId					The user login ID
	* @param[in]	loginPassword			The user login password
	* @param[in]	sessionKey				The session key
	* @param[in]	cryptoSessionKey		The crypto session key
	* @param[in]	snsUserId				The SNS user ID of the logged-in user
	* @param[in]	displayName				The display name of the logged-in user
	* @param[in]	profilePhotoUrl			The URL of the profile photo of the logged-in user
	* @param[in]	redirectLoginUrl		The redirect URL for login
	* @param[in]	spKey					The key for the service provider
	*/
	SnsLoginStatus(const Osp::Base::String& serviceProviderName, bool isLoggedIn,
			const Osp::Base::String& loginId, const Osp::Base::String& loginPassword,
			const Osp::Base::String& sessionKey, const Osp::Base::String& cryptoSessionKey,
			const Osp::Base::String& snsUserId, const Osp::Base::String& displayName,
			const Osp::Base::String& profilePhotoUrl, const Osp::Base::String& redirectLoginUrl, const Osp::Base::String& spKey);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of user's login status for SNS any longer.
	* @since 		1.0
	*/
	virtual ~SnsLoginStatus(void);

	/**
	* This is the copy constructor for the %SnsLoginStatus class. @n
	* It creates an instance of %SnsLoginStatus with the values of the specified instance.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsLoginStatus
	*/
	SnsLoginStatus(const SnsLoginStatus& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SnsLoginStatus to the current instance.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsLoginStatus
	*/
	SnsLoginStatus& operator =(const SnsLoginStatus& value);

public:
	/**
	* @internal
	* This is internal. If used in an application, the application can get rejected during the certification process. @n
	* Gets the service provider.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of user's login status for SNS any longer.
	* @since 			1.0
	* @return			The service provider
	*/
	SnsSsoSp GetServiceProvider(void) const;

	/**
	* Gets the service provider name.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The service provider name
	*/
	Osp::Base::String GetServiceProviderName(void) const;

	/**
	* Checks whether the user is logged in.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		@c true if the user is logged-in on the specific service provider, @n
	*				else @c false
	*/
	bool GetLoginStatus(void) const;

	/**
	* Gets the login ID.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The login ID
	*/
	Osp::Base::String GetLoginId(void) const;

	/**
	* Gets the login password.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The login password
	*/
	Osp::Base::String GetLoginPassword(void) const;

	/**
	* Gets the session key.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The session key
	*/
	Osp::Base::String GetSessionKey(void) const;

	/**
	* Gets the crypto session key.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The crypto session key
	*/
	Osp::Base::String GetCryptoSessionKey(void) const;

	/**
	* Gets the people ID of the specific service provider.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The people ID of the specific service provider
	*/
	Osp::Base::String GetPeopleId(void) const;

	/**
	* Gets the display name of the specific service provider.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The display name of the specific service provider
	*/
	Osp::Base::String GetDisplayName(void) const;

	/**
	* Gets the URL of the logged-in user's profile photo.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The URL of the photo
	*/
	Osp::Base::String GetProfilePhotoUrl(void) const;

	/**
	* Gets the redirect URL for login.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The redirect URL for login
	*/
	Osp::Base::String GetRedirectLoginUrl(void) const;

	/**
	* @internal
	* This is internal. If used in an application, the application can get rejected during the certification process. @n
	* Gets the key for MySpace.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the information of user's login status for SNS any longer.
	*
	* @since 		1.0
	* @return		The key value
	*/
	Osp::Base::String GetMyspaceKey(void) const;

	/**
	* Gets the key for the service provider.
	*
	* @deprecated	This method is deprecated because it is not allowed to manage the user's login status information for SNS any longer.
	* @since 		1.0
	* @return		The key value
	*/
	Osp::Base::String GetServiceProviderKey(void) const;

private:
	SnsSsoSp			__serviceProvider;
	bool				__isLoggedIn;
	Osp::Base::String	__loginId;
	Osp::Base::String	__loginPassword;
	Osp::Base::String	__sessionKey;
	Osp::Base::String	__cryptoSessionKey;
	Osp::Base::String	__peopleId;
	Osp::Base::String	__displayName;
	Osp::Base::String	__profilePhotoUrl;
	Osp::Base::String	__myspaceKey;

	friend class SnsLoginStatusEx;
	class SnsLoginStatusEx* __pSnsLoginStatusEx;
};

};};};// Osp::Social::Services

#endif
