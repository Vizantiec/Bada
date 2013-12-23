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
 * @file		FWebCtrlAuthenticationChallenge.h
 * @brief		This is the header file for the %AuthenticationChallenge class.
 *
 * This header file contains the declarations of the %AuthenticationChallenge class.
 */

 
#ifndef _FWEB_AUTHENTICATIONCHALLENGE_H_
#define _FWEB_AUTHENTICATIONCHALLENGE_H_

#include "FBase.h"
#include "FWebConfig.h"


namespace Osp { namespace Web { namespace Controls {
	class __WebService;
	class __LoadingProxyListener;
};};};

namespace Osp { namespace Web { namespace Controls {


/**
 *
 * @class	AuthenticationChallenge
 * @brief		This class handles the HyperText Transfer Protocol (HTTP) authentication requests. 
 * @since	1.0
 *
 * The %AuthenticationChallenge class sends the user ID and password to the server requesting user authentication.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */

class _EXPORT_WEB_ AuthenticationChallenge
	:public Osp::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~AuthenticationChallenge(void);
	
	/**
	 * Sends the user ID and password to the host. 
	 *
	 * @since				1.0
	 * @param[in]		userId			The user ID for authentication
	 * @param[in]		password			The password for authentication
	 */
	void	Process(const UserId& userId, const Osp::Base::String& password);

	/**
	 * Cancels the authentication request. 
	 *
	 * @since	1.0
	 */
	void	Cancel(void);


protected:

	/**
	 * @internal    
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the constructor for this class.
	 *
	 * @since	1.0
	 */
	AuthenticationChallenge(__WebService& webService);


private:

	__WebService *__pWebService;
	
	friend class __LoadingProxyListener;

	friend class AuthenticationChallengeEx;
	class AuthenticationChallengeEx* __pAuthChallengeEx;
	
	
};

}; };};

#endif
