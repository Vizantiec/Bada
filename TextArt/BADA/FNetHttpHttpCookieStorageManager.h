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
 * @file		FNetHttpHttpCookieStorageManager.h
 * @brief		This is the header file for the %HttpCookieStorageManager class.
 * @since		1.0
 *
 * This header file contains the declarations of the %HttpCookieStorageManager class.
 */

#ifndef _FNET_HTTP_HTTP_COOKIE_STORAGE_H_
#define _FNET_HTTP_HTTP_COOKIE_STORAGE_H_

// Includes
#include "FNetConfig.h"
#include "FBaseResult.h"
#include "FNetHttpHttpTypes.h"

namespace Osp 
{ 
namespace Net 
{ 
namespace Http 
{
class HttpSession;
/**
 * @class	HttpCookieStorageManager
 * @brief	This class provides a collection of %Http cookies of a particular session.
 * @since 	1.0
 *
 * The %HttpCookieStorageManager class instance encapsulates the cookies received by the client in this particular session.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 */
class  _EXPORT_NET_ HttpCookieStorageManager {

public:
    /**
     * Gets the string to be used in the cookie header of the request corresponding to the requested URL.
     *
     * @since		1.0
     * @return		An error code
     *
     * @param[in]	url					The request URL
     * @param[out]	cookies				The cookie header value @n
	 *						 			For example, cookie-name1=cookie-value1;cookie-name2=cookie-value2.
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_ARG		The specified @c cookies is an empty string.
     * @exception	E_INVALID_STATE		The method invoked is invalid.
     */
    result GetCookies(const Osp::Base::String& url, Osp::Base::String& cookies) const;

    /**
     * Removes all the cookies corresponding to the requested URL from the cookie storage.
     *
     * @since		1.0
     * @privlevel	SYSTEM
     * @privgroup	COOKIE
     *
     * @return		An error code
     * @param[in]	url						The requested URL
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_INVALID_ARG			The specified @c url is an empty string.
     * @exception	E_INVALID_STATE			The method invoked is invalid.
     * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
     * @exception	E_SYSTEM				A system error has occurred.
     * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
     */
    result RemoveCookies(const Osp::Base::String& url);

	/**
	 * Removes all the cookies from the cookie storage.
	 *
	 * @since		1.0
	 * @privlevel	SYSTEM
	 * @privgroup	COOKIE
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result RemoveAllCookies();

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	HttpCookieStorageManager();

	/**
	 * This is the destructor for this class.
	 */
	~HttpCookieStorageManager();

	/**
	 * Initializes this instance of %HttpCookieStorageManager with the specified parameter.
	 *
	 * @return		An error code
	 * @param[in]	pSession			The %HTTP session pointer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 */
	result Construct(HttpSession* pSession);

	/**
	 * This is the copy constructor for the %HttpCookieStorageManager class. @n
	 * This constructor initializes a new instance of the %HttpCookieStorageManager class with the value from another instance.
	 *
	 * @param[in]	value 	An instance of %HttpCookieStorageManager
	 */
	HttpCookieStorageManager(const HttpCookieStorageManager &value);

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs		An instance of %HttpCookieStorageManager
	 */
	HttpCookieStorageManager& operator=(const HttpCookieStorageManager& rhs);

private:
	bool __isConstructed;
	Osp::Net::Http::HttpSession* __pSession;
// Friend Class
	friend class HttpTransaction;
	friend class HttpSession;
	friend class __HttpTransactionEvent;

	friend class HttpCookieStorageManagerEx;
	class HttpCookieStorageManagerEx* __pHttpCookieStorageManagerEx;
};

}; 
}; 
}; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_COOKIE_STORAGE_H_


