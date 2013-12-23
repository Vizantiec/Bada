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
 * @file		FNetHttpHttpAuthentication.h 
 * @brief		This is the header file for the %HttpAuthentication class.
 * @since		1.0
 *
 * This header file contains the declarations of the %HttpAuthentication class.
 */

#ifndef _FNET_HTTP_HTTP_AUTH_H_
#define _FNET_HTTP_HTTP_AUTH_H_

// Includes
#include "FNetHttpHttpTypes.h"

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpHttpCredentials.h"


namespace Osp { namespace Net { namespace Http {
class HttpCredentials;
class IHttpTransactionPi;
/**
 * @class	HttpAuthentication
 * @brief	This class encapsulates an %HTTP authentication.
 * @since	1.0
 *
 * 	The %HttpAuthentication class encapsulates the %HTTP authentication activity of the client over the duration of a single transaction.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpAuthentication class.
 *
 * @code
 *	
 *	#include <FBase.h>
 *	#include <FNet.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Net;
 *	using namespace Osp::Net::Http;
 *
 *	void
 *	MyTransactionEventListener::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired)
 *	{
 *
 * 		HttpTransaction* pTransaction = const_cast<HttpTransaction*>(&httpTransaction); 
 *
 *		if(bAuthRequired)
 *		{
 * 			HttpAuthentication* pAuth = pTransaction->OpenAuthenticationInfoN();
 * 			String basicName("Name");
 * 			String basicpass("Pass");
 * 			HttpCredentials* pCredential = new HttpCredentials(basicName, basicpass);

 *			String* pRealm = pAuth->GetRealmN();
 * 			NetHttpAuthScheme scheme = pAuth->GetAuthScheme();
 * 			if(scheme == NET_HTTP_AUTH_WWW_BASIC || scheme == NET_HTTP_AUTH_PROXY_BASIC)
 * 				HttpTransaction* pNewTransaction =  pAuth->SetCredentials(*pCredential);
 *		}
 *	}
 *
 * @endcode
 */
class _EXPORT_NET_ HttpAuthentication :
	public Osp::Base::Object
{
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	~HttpAuthentication(void);
	/**
	 * Gets the realm value received.
	 *
	 * @since			1.0
	 * @privlevel		NORMAL
	 * @privgroup		HTTP
	 *
	 * @return			The realm value
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The method invoked is invalid.
	 * @exception		E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception		E_SYSTEM 			A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String* GetRealmN(void) const;
	/**
	 * Gets the authentication scheme received.
	 *
	 * @since			1.0
	 * @privlevel		NORMAL
	 * @privgroup		HTTP
	 *
	 * @return			The authentication scheme, @n
	 *					else @c -1 if an error occurs
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The method invoked is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM			A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.					
	 */
	NetHttpAuthScheme GetAuthScheme(void)const;
	/**
	 * Sets the credentials required for setting the "WWW-Authenticate" header in the %HttpRequest class.
	 *
	 * @since			1.0
	 * @privlevel		NORMAL
	 * @privgroup		HTTP
 	 *
	 * @return			The new transaction pointer
	 * @param[in]		credentials				The credentials
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid.
	 * @exception		E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @exception		E_AUTHENTICATION		The authentication has failed.
	 * @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks			This method is used to set the username and password for the given domain and the authentication 
	 *					scheme on the reception of the OnTransactionHeaderCompleted() callback.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpTransaction*  SetCredentials(HttpCredentials& credentials);
	// bool IsAuthRequired();
private :
	/**
	 * Sets the realm value of the authentication information.
	 *
	 * @return			An error code
	 * @param[in]		realm					The realm value
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid.
	 * @exception		E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks			The transaction event will use this method to set the realm value of the authentication information
	 *					stored in the transaction.
	 *
	 */
	result SetRealm(const Osp::Base::String& realm);
	/**
	 * Sets the authentication scheme value for the instance stored in the transaction.
	 *
	 * @return			An error code
	 * @param[in]		scheme				The authentication scheme
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		The method invoked is invalid.
	 * @exception		E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetAuthScheme(NetHttpAuthScheme scheme);
	/**
	 * Starts a transaction with authentication using the credentials set by the user.
	 *
	 * @return			The new transaction pointer
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid.
	 * @exception		E_AUTHENTICATION		The authentication has failed.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpTransaction* Authenticate(void);
	/**
	 * Initializes this instance of %HttpAuthentication with the specified %HTTP transaction.
	 *
	 * @return			An error code
	 * @param[in]		pTransaction			The %HTTP transaction
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid.
	 * @exception		E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(HttpTransaction* pTransaction);
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize the instance.
	 * @see			Construct()
	 */
	HttpAuthentication(void);
	/** 
	* This is the copy constructor for the %HttpAuthentication class. @n
	* This method constructs an instance of the %HttpAuthentication class with the values of the specified instance.
	*
	* @param[in]	value	An instance of %HttpAuthentication
	*/	
	HttpAuthentication(const HttpAuthentication& value);

	/**
	 * Initializes this instance of %HttpAuthentication with the information in the specified instance of %NetHttpAuthData.
	 *
	 * @return			An error code
 	 * @param[in]		data					The authentication information
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 */
	result InitAuthenticationInfo(NetHttpAuthData& data);

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]		rhs				An instance of %HttpAuthentication
	 */
	HttpAuthentication& operator=(const HttpAuthentication& rhs);


private:

	Osp::Base::String* __pRealm;
	NetHttpAuthScheme __scheme; 
	HttpCredentials* __pHttpCredentials;
	bool __isConstructed;
	HttpTransaction * __pTransaction;
	Osp::Base::String* __pDomain;
	Osp::Base::String* __pNonce;
	Osp::Base::String* __pOpaque;
	Osp::Base::String* __pAlgo;
	Osp::Base::String* __pQop;
	int __inc;
	bool __bStale;

	friend class HttpTransaction; 
	friend class HttpSession;   
	friend class IHttpTransactionPi;
	friend class __HttpTransactionEvent;

	friend class HttpAuthenticationEx;
	class HttpAuthenticationEx* __pHttpAuthenticationEx;
};

}; 
}; 
}; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_AUTH_H_
