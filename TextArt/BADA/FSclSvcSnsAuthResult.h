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
 * @file		FSclSvcSnsAuthResult.h
 * @brief		This is the header file for the %SnsAuthResult class.
 *
 * This header file contains the declarations of the %SnsAuthResult class.
 */
#ifndef _FSCL_SVC_SNS_AUTHRESULT_H_
#define _FSCL_SVC_SNS_AUTHRESULT_H_

#include "FSclConfig.h"
#include "FBaseString.h"
#include "FBaseObject.h"

namespace Osp { namespace Social { namespace Services {

class SnsAuthenticator;
class SnsGateway;
class __SnsUtil;
/**
* @class	SnsAuthResult
* @brief	This class provides the result of the SNS authentication.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
*
* The %SnsAuthResult class contains the result of an authentication request.
* If the authentication mechanism of the service provider is OAuth, the meaning of the keys is described in the OAuth specification (http://www.oauth.net).
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/authentication.htm">Authentication</a>.
* 
*/
class  _EXPORT_SOCIAL_ SnsAuthResult:
		public Osp::Base::Object
{
			friend class SnsAuthenticator;
			friend class SnsGateway;
			friend class __SnsUtil;
private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	1.0
	 */
	SnsAuthResult(Osp::Base::String& serviceProvider, Osp::Base::String& consumerKey, Osp::Base::String& consumerSecret, Osp::Base::String& token, Osp::Base::String& tokenSecret, Osp::Base::String& snsUserId, Osp::Base::String& snsUserName, Osp::Base::String& persistKey, Osp::Base::String& persistKeyExpires, Osp::Base::String& sessionKey);

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	1.0
	 */
	SnsAuthResult(Osp::Base::String& serviceProvider, Osp::Base::String& consumerKey, Osp::Base::String& consumerSecret, Osp::Base::String& token, Osp::Base::String& tokenSecret);

public:
	/**
	* This is the copy constructor for the %SnsAuthResult class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value		An instance of %SnsAuthResult
	*/
	SnsAuthResult(const SnsAuthResult& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsAuthResult(void);

	/**
	* Gets the service provider.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The service provider
	*/
	Osp::Base::String	GetServiceProvider(void) const;

	/**
	* Gets the consumer key.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The consumer key
	*/
	Osp::Base::String	GetConsumerKey(void) const;

	/**
	* Gets the consumer secret.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The consumer secret
	*/
	Osp::Base::String	GetConsumerSecret(void) const;

	/**
	* Gets the token key.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The token key
	*/
	Osp::Base::String	GetTokenKey(void) const;

	/**
	* Gets the token secret.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The token secret
	*/
	Osp::Base::String	GetTokenSecret(void) const;

	/**
	* Gets the ID of the user who authenticated the application.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The user ID
	*/
	Osp::Base::String	GetSnsUserId(void) const;

	/**
	* Gets the name of the user who authenticated the application.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return 	The user name
	*/
	Osp::Base::String	GetSnsUserName(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the persist key.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since	2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_SNS
	 *
	 * @return 		The persist key
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetSnsGatewayPersistentKey(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the persist key expires.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since	2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_SNS
	 *
	 * @return 		The persist key expires
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetSnsGatewayPersistentKeyExpires(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the session key.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since	2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_SNS
	 *
	 * @return 		The session key
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetSnsGatewaySessionKey(void) const;
	
private:
	/**
	* Gets the persist key.
	*
	* @return 	The persist key
	*/
	Osp::Base::String	GetPersistKey(void) const;

	/**
	* Gets the persist key expires.
	*
	* @return 	The persist key expires
	*/
	Osp::Base::String	GetPesistKeyExpires(void) const;

	/**
	* Gets the session key.
	*
	* @return 	The session key
	*/
	Osp::Base::String	GetSessionKey(void) const;

private:
	Osp::Base::String __serviceProvider;
	Osp::Base::String __consumerKey;
	Osp::Base::String __consumerSecret;
	Osp::Base::String __token;
	Osp::Base::String __tokenSecret;
	Osp::Base::String __snsUserId;
	Osp::Base::String __snsUserName;
	Osp::Base::String __persistKey;
	Osp::Base::String __persistKeyExpires;
	Osp::Base::String __sessionKey;

	friend class SnsAuthResultEx;
	class SnsAuthResultEx* __pSnsAuthResultEx;
};

};};};

#endif
