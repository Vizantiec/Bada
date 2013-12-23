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
 * @file	  FNetHttpHttpCookie.h 
 * @brief	  This is the header file for the %HttpCookie class.
 *
 * This header file contains the declarations of the %HttpCookie class.
 */

#ifndef _FNET_HTTP_HTTP_COOKIE_H_
#define _FNET_HTTP_HTTP_COOKIE_H_

// Includes
#include "FNetHttpHttpTypes.h"

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpTransaction.h"
#include "FBaseUtil.h"
#include "FBaseColArrayList.h"

namespace Osp 
{ 
	namespace Net 
{ 
	namespace Http 
{
/**
 * @class	HttpCookie
 * @brief	This class provides a Http cookie.
 * @since	1.0
 *
 * The %HttpCookie class provides a %Http cookie. The %HttpCookie instance encapsulates the cookie received by the server in a particular HttpResponse instance.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpCookie class.
 *
 * @code
 *	
 *	#include <FBase.h>
 *	#include <FNet.h>
 *
 *  using namespace Osp::Base;
 *  using namespace Osp::Net;
 *  using namespace Osp::Net::Http;
 *  using namespace Osp::Base::Collection;
 *
 * 	void
 * 	MyTransactionEventListener::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired)
 * 	{
 *		IList* pCookieList = null;
 * 		HttpCookie* pCookie = null;
 * 		HttpTransaction* pTransaction = const_cast<HttpTransaction*>(&(httpTransaction));
 * 		HttpResponse* pResponse = pTransaction->GetResponse();
 * 		HttpHeader* pHeader = pResponse->GetHeader();
 *
 *		String* pRawHeader = null;
 * 		pRawHeader = pHeader->GetRawHeaderN();
 *
 *		String domain = null;
 * 		String version =null;
 * 		String path = null;
 * 		String expire = null;
 * 		String cookieName = null;
 * 		String cookieValue = null;
 *
 * 		pCookieList = pResponse->GetCookies();
 *
 *		for(int i =0;i<pCookieList->GetCount();i++)
 *		{
 *			pCookie = static_cast<HttpCookie*>(pCookieList->GetAt(i));;
 *
 * 			domain = pCookie->GetDomain();
 * 			version = pCookie->GetVersion();
 * 			path = pCookie->GetPath();
 * 			expire = pCookie->GetExpires();
 * 			cookieName = pCookie->GetCookieName();
 * 			cookieValue = pCookie->GetCookieValue();
 *		}
 *		delete pRawHeader;
 *	}
 * @endcode
 */
class _EXPORT_NET_ HttpCookie 
	: public Osp::Base::Object {

public:

	 /**
	 * Gets the domain name of the cookie.
	 *
	 * @since		1.0
	 * @return      The domain name of the cookie, @n
	 *				else an empty string if no domain name is received in the cookie
	 */
	 Osp::Base::String GetDomain(void) const;

     /**
     * Gets the path name of the cookie.
     *
     * @since		1.0
     * @return      The path name of the cookie, @n
	 *				else an empty string if no path name is received in the cookie
     */
	 Osp::Base::String GetPath(void) const;

     /**
     * Gets the version of the cookie.
     *
     * @since		1.0
     * @return      The version of the cookie, @n
	 *				else an empty string if no version is received in the cookie
     */
	 Osp::Base::String GetVersion(void) const;

     /**
     * Gets the expiration date and time of the cookie.
     *
     * @since		1.0
     * @return      The expiration date and time of the cookie, @n
	 *				else an empty string if no expiration date and time is received in the cookie
     */
	 Osp::Base::String GetExpires(void) const;

     /**
     * Checks whether the cookie is secured.
     *
     * @since		1.0
     * @return      @c true if the cookie is secured, @n
	 *				else @c false
     */
	 bool IsSecure(void) const;

     /**
     * Gets the name of the cookie.
     *
     * @since		1.0
     * @return      The name of the cookie
     */
	 Osp::Base::String GetCookieName(void) const;

     /**
     * Gets the value of the cookie.
     *
     * @since		1.0
     * @return      The value of the cookie
     */
	 Osp::Base::String GetCookieValue(void) const;

     /**
     * Gets the comment URL of the cookie.
     *
     * @since		1.0
     * @return      The comment URL of the cookie, @n
	 *				else an empty string if no comment URL is received in the cookie
     */
     Osp::Base::String GetCommentUrl(void) const;

     /**
     * Gets the comment on the cookie.
     *
     * @since		1.0
     * @return		The comment on the cookie, @n
	 *				else an empty string if no comment is received in the cookie
     */
     Osp::Base::String GetComment(void) const;

     /**
     * Checks whether the 'HttpOnly' flag is set in the cookie.
     *
     * @since		1.0
     * @return		@c true if the 'HttpOnly' flag is set, @n
	 *				else @c false
     */
	 bool IsHttpOnly(void) const;

     /**
     * Gets the port list.
     *
     * @since		1.0
     * @return		The port list, which is a comma separated series of digits, @n
	 *				else an empty string if no port list is received
     */
     Osp::Base::String GetPorts(void) const;

     /**
     * Gets the maximum age of the cookie.
     *
     * @since		1.0
     * @return      The maximum age of the cookie, @n
	 *				else @c -1 if no maximum age is received in the cookie
     */
     int GetMaxAge(void) const;

     /**
     * Checks whether the 'Discard' flag is set in the cookie.
     *
     * @since		1.0
     * @return      @c true if the 'Discard' flag is set, @n
	 *				else @c false
     */
	 bool GetDiscard(void) const;

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating a new instance, one of the appropriate Construct() methods must be called explicitly to
	 *				initialize the new instance properly.
	 * @see		  	Construct()
	 */
	 HttpCookie(void);

	/**
	 * This is the destructor for this class.
	 */
	~HttpCookie(void);

	/**
	 * This is the copy constructor for the %HttpCookie class. @n
	 * It creates an instance of %HttpCookie with the values of the specified instance.
	 * Do not use directly.
	 *
	 * @param[in]	cookie		An instance of %HttpCookie
	 */
	 HttpCookie(const HttpCookie& cookie);

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs			An instance of %HttpCookie
	 */
	 HttpCookie& operator=(const HttpCookie& rhs);

 	/**
	 * Initializes this instance of %HttpCookie with the specified parameters.
	 *
	 * @return		An error code
	 * @param[in]	cookieName			The cookie name
	 * @param[in]	cookieValue			The cookie value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result Construct(const Osp::Base::String& cookieName, const Osp::Base::String& cookieValue);
 	/**
	 * Initializes this instance of %HttpCookie with the specified parameter.
	 *
	 * @return		An error code
	 * @param[in]	cookieName			The cookie name
	 * @exception	E_SUCCESS			The method Is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result Construct(const Osp::Base::String& cookieName);
  
	 /**
	 * Sets the domain name of the cookie.
	 *
	 * @return		An error code
	 * @param[in]	domain				The domain name of the cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @see			GetDomain()
	 */
	 result SetDomain(const Osp::Base::String& domain);

  /**
	 * Sets the path name of the cookie.
	 *
	 * @return		An error code
	 * @param[in]	path				The path name of the cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @see			GetPath()
	 */
	 result SetPath(const Osp::Base::String& path);
  /**
	 * Sets the version name of the cookie.
	 *
	 * @return		An error code
	 * @param[in]	version				The version name of the cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @see			GetVersion()
	 */
	 result SetVersion(const Osp::Base::String& version);
  /**
	 * Sets the expiry date and time of the cookie.
	 *
	 * @return		An error code
	 * @param[in]	expires 			The expiry date and time of the cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @see			GetExpires()
	 */
	 result SetExpires(const Osp::Base::String& expires);
 
	 /**
	 * Sets whether the cookie is secure or not.
	 *
	 * @return		An error code
	 * @param[in]	value				Set to @c true if the cookie is secure, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @see			IsSecure()
	 */
	 result SetSecure(bool value);
  	
	 /**
	 * Sets the value of the received cookie.
	 *
	 * @return		An error code
	 * @param[in]	cookieValue 		The value of the received cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetCookieValue(const Osp::Base::String& cookieValue);

	 /**
	 * Sets the comment URL for the received cookies.
	 *
	 * @return		An error code
	 * @param[in]	uri					The comment URL of the received cookies
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetCommentUrl(const Osp::Base::String& uri);

	 /**
	 * Sets the comment of the received cookies.
	 *
	 * @return		An error code
	 * @param[in]	comment				The comment of the received cookies
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetComment(const Osp::Base::String& comment);

	 /**
	 * Sets the 'HttpOnly' flag value of the received cookie.
	 *
	 * @return		An error code
	 * @param[in]	value				The HttpOnly flag
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetHttpOnly(bool value);

	 /**
	 * Sets the "Discard" flag of the received cookie.
	 *
	 * @return		An error code
	 * @param[in]	value				The discard flag
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetDiscard(bool value);

	 /**
	 * Sets the ports of the received cookie.
	 *
	 * @return		An error code
	 * @param[in]	portList			The port of the received cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetPorts(const Osp::Base::String& portList);

	 /**
	 * Sets the maximum age of the received cookie.
	 *
	 * @return		An error code
	 * @param[in]	maxage 				The maximum age of the received cookie
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	 result SetMaxAge(int maxage);

private:
	Osp::Base::String __comment;
	Osp::Base::String __name;
	Osp::Base::String __cookieValue;
	Osp::Base::String __commentUrl;
	Osp::Base::String __domain;
	Osp::Base::String __expires;
	bool __isHttpOnly;
	bool __isSecure;
	bool __discard;
	Osp::Base::String __path;
	Osp::Base::String __portList;
	Osp::Base::String __version;
	int __maxAge;

	bool __isConstructed;
// Friend Class
	friend class HttpTransaction;
	friend class HttpSession;
	friend class __HttpTransactionEvent;
	friend class HttpResponse;

	friend class HttpCookieEx;
	class HttpCookieEx* __pHttpCookieEx;
};

}; 
}; 
}; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_COOKIE_H_


