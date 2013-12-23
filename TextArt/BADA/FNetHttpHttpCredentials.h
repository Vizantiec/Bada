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
 * @file	FNetHttpHttpCredentials.h
 * @brief	This is the header file for the %HttpCredentials class.
 *
 * This header file contains the declarations of the %HttpCredentials class.
 */

#ifndef _FNET_HTTP_HTTP_CREDENTIALS_H_
#define _FNET_HTTP_HTTP_CREDENTIALS_H_

// Includes
#include "FNetHttpHttpTypes.h"

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpTransaction.h"

namespace Osp { namespace Net { namespace Http {

/////////////////////////////////////////////////////////////////////////////
/**
 * @class	HttpCredentials
 * @brief	This class represents the credentials required for authentication.
 * @since 	1.0
 *
 * 	The %HttpCredentials class represents the credentials required for authentication, that is, the user name and password.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 */
//////////////////////////////////////////////////////////////////////////
class _EXPORT_NET_ HttpCredentials :
	public Osp::Base::Object
{

public :
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 */
	HttpCredentials(void);

	/**
	 * Initializes an instance of %HttpCredentials with the specified user name and password.
	 *
	 * @since 		1.0
	 * @param[in]	name				The user name string
	 * @param[in]	password			The password string
	 */
	HttpCredentials(const Osp::Base::String& name, const Osp::Base::String& password);
	/**
	* This is the copy constructor for the %HttpCredentials class. @n
	* It constructs an instance of %HttpCredentials with the values of the specified instance.
	*
	* @since 		1.0
	* @param[in]	value	An instance of %HttpCredentials
	*/
	HttpCredentials(const HttpCredentials& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	virtual ~HttpCredentials(void);

	/**
	 * This is the assignment operator.
	 *
	 * @since 		1.0
	 * @param[in]	rhs		An instance of %HttpCredentials
	 */
	HttpCredentials& operator=(const HttpCredentials& rhs);

	/**
	 * Sets the user name for the current instance of %HttpCredentials.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @param[in]	name				The user name string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetName(const Osp::Base::String& name);

	/**
	 * Sets the password for the current instance of %HttpCredentials.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @param[in]	password			The password string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetPassword(const Osp::Base::String& password);

	/**
	 * Gets the user name of the current instance of %HttpCredentials.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		The user name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
  	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetName(void) const;

	/**
	 * Gets the password of the current instance of %HttpCredentials.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
  	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetPassword(void) const;

private :
	Osp::Base::String __userName;
	Osp::Base::String __password;
	friend class HttpAuthentication;
	friend class HttpTransaction;

	friend class HttpCredentialsEx;
	class HttpCredentialsEx* __pHttpCredentialsEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_CREDENTIALS_H_
