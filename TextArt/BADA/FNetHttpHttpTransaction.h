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
 * @file	FNetHttpHttpTransaction.h
 * @brief	This is the header file for the %HttpTransaction class.
 *
 * This header file contains the declarations of the %HttpTransaction class.
 */

#ifndef _FNET_HTTP_HTTP_TRANSACTION_H_
#define _FNET_HTTP_HTTP_TRANSACTION_H_

// Includes
#include "FNetConfig.h"
#include "FBaseByteBuffer.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpRequest.h"
#include "FNetHttpHttpResponse.h"
#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpSession.h"
#include "FNetHttpHttpAuthentication.h"
#include "FNetHttpIHttpTransactionEventListener.h"
#include "FNetHttpIHttpEntity.h"
#include "FNetHttpIHttpProgressEventListener.h"


namespace Osp { namespace Net { namespace Http {
class IHttpTransactionPi;
class HttpRequest;
class HttpResponse;
class __HttpTransactionEvent;

/**
 * @class	HttpTransaction
 * @brief	This class manages the HTTP transaction that encapsulates a request and a response.
 * @since	1.0
 *
 * The %HttpTransaction class manages the HTTP transaction that encapsulates a request and a response.
 *	A transaction represents an interaction between the %HTTP client and the %HTTP origin server.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_transaction.htm">HTTP Transaction</a>.
 *
 * The following example demonstrates how to use the %HttpTransaction class.
 *
 * @code
 *
 *	void
 *	Test(void)
 *	{
 *		result r = E_SUCCESS;
 *		String* pProxyAddr = null;
 *		String hostAddr(L"http://www.bada.com");
 *		HttpSession* pSession = null;
 * 	 	HttpTransaction* pTransaction = null;
 *
 *		pSession = new HttpSession();
 *		r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr ,hostAddr, null);
 *		if (IsFailed(r))
 *		{
 *			AppLog("Construct session failed. (%s)\n", GetErrorMessage(r));
 *		}
 *		pTransaction = pSession->OpenTransactionN();
 *		if (null == pTransaction)
 *		{
 *			AppLog("Construct session failed. \n");
 *		}
 *		r = pTransaction->AddHttpTransactionListener(*this);
 *		if (IsFailed(r))
 *		{
 *			AppLog("AddHttpTransactionListener session failed.\n");
 *		}
 *		HttpRequest* pRequest = pTransaction->GetRequest();
 *		if(pRequest == null)
 *		{
 *			AppLog("GetRequest failed. \n");
 *		}
 *
 *		r = pRequest->SetUri(L"http://www.bada.com");
 *		if(IsFailed(r))
 *		{
 *			AppLog("SetUri failed. (%s)\n", GetErrorMessage(r));
 *		}
 *
 *		r = pRequest->SetMethod(NET_HTTP_METHOD_GET);
 *		if(IsFailed(r))
 *		{
 *			AppLog("SetMethod failed. (%s)\n", GetErrorMessage(r));
 *		}
 *		r = pTransaction->Submit();
 *		if(IsFailed(r))
 *		{
 *			AppLog("Submit failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	}
 * @endcode
 */

class _EXPORT_NET_ HttpTransaction :
	public Osp::Base::Object
{

// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 	1.0
	 */
	virtual ~HttpTransaction(void);


// Operation
public:
	/**
	 * Submits the %HTTP request.
	 *
	 * @since 			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                	For more information, see @ref HttpTransactionSubmitPage "here".
	 *
	 * @privlevel		NORMAL
	 * @privgroup		HTTP
	 *
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									  	At least one of Uri, Method, Header, and Body is invalid.
	 * @exception		E_INVALID_HEADER	The header is @c null.		  
	 * @exception 		E_INVALID_STATE		The method invoked is invalid.
	 * @exception		E_OUT_OF_RANGE		The submitted data is out of range.
	 * @exception		E_MAX_EXCEEDED		The number of active transactions has exceeded the maximum limit.
	 * @exception		E_INVALID_PROXY		The proxy server address is invalid.
	 * @exception		E_DNS				The DNS query has failed.
	 * @exception		E_INVALID_OPERATION	This instance has not been constructed as yet.
	 * @exception		E_EMPTY_BODY		The body is empty in a POST method case.
	 * @exception		E_INVALID_SESSION	The session is invalid.
	 * @exception		E_AUTHENTICATION	The authentication has failed.
	 * @exception		E_UNKNOWN			An unknown error has occurred.
	 * @exception		E_SYSTEM			A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks			The appropriate request header and body should be set using %HttpRequest before using this method.
	 *					If the session is in a non-pipeline mode, be sure not to submit a transaction before the previous transaction is completed.
	 * @see				HttpRequest, HttpHeader
	 */
	result Submit(void);

	/**
	 * @page		HttpTransactionSubmitPage 	Compatibility for Submit()
	 *
	 * @section		HttpTransactionSubmitPageIssueSection 	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# If HTTP response header contains non-ASCII characters, the listener of OnTransactionAborted() is called.
	 * -# If the content length of the request header is @c 0, Submit() returns the E_EMPTY_BODY exception.
	 *
	 * @section		HttpTransactionSubmitPageSolutionSection	Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# Submit() returns the E_SUCCESS exception.
	 */

	/**
	 * Gets the authentication information.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	HTTP
	 *
	 * @return		A pointer to HttpAuthentication
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpAuthentication* OpenAuthenticationInfoN(void);

// Accessor
public:
	/**
	 * Gets a pointer to the HttpRequest related to the Transaction. @n
	 * Setting a request header, method, URI, and body can be done by using the @c pHttpRequest pointer.
	 *
	 * @since 		1.0
	 * @return		The HttpRequest object pointer, @n
	 *				else @c null in case of an invalid condition
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE 	This instance has not been constructed as yet.
	 * @exception	E_INVALID_DATA 		The request is not valid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Net::Http::HttpRequest
	 */
	HttpRequest* GetRequest(void) const;

	/**
	 * Gets a pointer to the HttpResponse related to the transaction. @n
	 * Getting a response header and body can be done by using the @c pHttpResponse pointer.
	 *
	 * @since 		1.0
	 * @return		The HttpResponse object pointer, @n
	 *				else @c null if the response is not received
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_DATA 		The response is not received.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			HttpResponse
	 */
	HttpResponse*  GetResponse(void) const;

	/**
	 * Adds the IHttpTransactionEventListener instance. @n
	 * The added listener can listen to events as they are fired.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	listener			The %IHttpTransactionEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result AddHttpTransactionListener(const IHttpTransactionEventListener& listener);

	/**
	 * Removes the %IHttpTransactionEventListener instance.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	listener			The %IHttpTransactionEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range. @n
	 *									The listener is already removed.
	 */
	result RemoveHttpTransactionListener(const IHttpTransactionEventListener& listener);

	/**
	 * Sets the %IHttpProgressEventListener instance.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	listener			The %IHttpProgressEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	result SetHttpProgressListener(const IHttpProgressEventListener& listener);

	/**
	 * Sets a user object to the instance of %HttpTransaction.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	pUserData			The user data to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	result SetUserObject(const Osp::Base::Object* pUserData);

	/**
	 * Gets a user object that is set to the instance of %HttpTransaction.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Object* GetUserObject(void) const;

	/**
	 * Enables OnTransactionReadyToWrite.
	 *
	 * @since 		1.0
	 * @return		@c true if the OnTransactionReadyToWrite listener is active, @n
	 *				else @c false
	 */
	bool EnableTransactionReadyToWrite(void);

	/**
	 * Resumes the transaction after the OnTransactionCertVerificationRequiredN() event is invoked. @n
	 * As described in the %IHttpTransactionEventListener section, the above event occurs in case of the uncertified server certificate.
	 *
	 * @since 		1.0
	 * @return		An error code
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The current state of the instance prohibits the execution of the specified operation.
	 * @see 		IHttpTransactionEventListener::OnTransactionCertVerificationRequiredN()
 	 */
	result Resume(void);

	/**
	 * Pauses the transaction after the OnTransactionCertVerificationRequiredN() event is invoked. @n
	 * As described in the %IHttpTransactionEventListener section, the above event occurs in case of the uncertified server certificate.
	 *
	 * @since 		1.0
	 * @return		An error code
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The current state of the instance prohibits the execution of the specified operation.
	 * @see 		IHttpTransactionEventListener::OnTransactionCertVerificationRequiredN()
 	 */
	result Pause(void);


	/**
	 *  @internal
	 *  This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and
	 *  security-related issues that might arise after using this method.
	 *
	 *  @prohibited
	 *  This method is prohibited. If this method is used in an application, the application can get rejected during the certification process.
	 *
	 *  Resumes data receiving for the current transaction.
	 *
	 *  @since 		2.0
	 *	@return		An error code
 	 *	@exception	E_SUCCESS			The method is successful.
	 *  @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *  @exception	E_SYSTEM			A system error occurred.
 	 */
	result ResumeDataReceiving(void);

	/**
	 *  @internal
	 *  This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and
	 *  security-related issues that might arise after using this method.
	 *
	 *  @prohibited
	 *  This method is prohibited. If this method is used in an application, the application can get rejected during the certification process.
	 *
	 *	Pauses data receiving for the current transaction.
	 *
	 *  @since 		2.0
	 *	@return		An error code
 	 *	@exception	E_SUCCESS			The method is successful.
	 *  @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *  @exception	E_SYSTEM			A system error occurred.
 	 */
	result PauseDataReceiving(void);


	/**
	 *	Sets a client certificate to connect the server.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	certificateId		The selected client certificate to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks    	Start the AppControl(APPCONTROL_PROVIDER_CERTIFICATE_MANAGER) for getting the selected client certificate. @n
	 *              For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>. (Osp::App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER)
	 */
	result SetClientCertificate(int certificateId);

// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see 		Construct()
	 */
	HttpTransaction(void);

	/**
	 * Initializes this instance of HttpTransaction with the specified parameters. @n
	 * It also constructs the corresponding __HttpTransactionEvent, HttpRequest, and HttpResponse. It is used when a common header exists for the session. 
	 * This header is added to the request header.
	 *
	 * @return		An error code
	 * @param[in]	pHttpSession		An HttpSession object
	 * @param[in]	pCommonHeader		A header object that stores the common header
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is @c null.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const HttpSession& pHttpSession, const HttpHeader* pCommonHeader);


	/**
	 * Frees the resources.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method has failed to execute the socket-related operations.
	 */
	virtual result Dispose(void);


	/**
	 * Closes the transaction. @n
	 * This method invokes the Dispose() method internally. 
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
 	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_UNKNOWN			An unknown error has occurred.
	 * @see			Dispose()
	 */
	result Close(void);


// Lifecycle
private:
	/*
	 * This is the copy constructor for this class. @n
	 * Do @b not use directly.
	 *
	 * @param[in]	value			An instance of %HttpTransaction
	 */
	HttpTransaction(const HttpTransaction& value);


// Operation
private:
	/*
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs				An instance of %HttpTransaction
	 */
	HttpTransaction& operator =(const HttpTransaction& rhs);


	/*
	 * Checks whether the request header uses a chunked mode.
	 *
	 * @return		An error code
	 * @param[in]	pHeader					A header
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_INVALID_ARG			A specified input parameter is @c null.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result CheckChunkedMode(HttpHeader*  pHeader);

	/**
	 * Gets the low-level %HTTP transaction handle.
	 *
	 * @return		A low-level handle representing the %HTTP transaction, @n
	 *				else @c -1 if transaction is not valid 
 	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_TRANSACTION	The transaction is invalid.
	 * @exception	E_INVALID_STATE			The current state of the instance prohibits the execution of the specified operation.
 	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	*/
	Handle GetHandle(void) const;


// Accessor
private:
	/**
	* Gets the corresponding transaction handle.
	*
	* @return		An error code
	* @param[out]	hHttpTxn				An HttpTransaction Handle
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_TRANSACTION	The transaction is invalid.
	* @exception	E_INVALID_STATE			The current state of the instance prohibits the execution of the specified operation.
	*/
	result GetTransactionHandle(HHttpTxn& hHttpTxn) const;


	/**
	* Gets the corresponding session handle.
	*
	* @return		An error code
	* @param[out]	hSession				An HttpSession Handle
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_SESSION		The session is invalid.
	* @exception	E_INVALID_STATE			The current state of the instance prohibits the execution of the specified operation.
	*/
	result GetSessionHandle(HHttpSession& hSession) const;

	/**
	* Gets the entity of the HttpTransaction.
	*/
	IHttpEntity* GetRequestEntity(void) const;


// Attribute
private:
	__HttpTransactionEvent* __pHttpTxnEvent;
	IHttpTransactionPi* __pHttpTransactionInterface;
	Net::Http::HttpSession* __pHttpSession;
	HttpRequest* __pHttpRequest;
	HttpResponse* __pHttpResponse;

	Net::Http::HHttpSession __hSession;
	Net::Http::HHttpTxn __hHttpTxn;

	Net::Http::HttpAuthentication* __pHttpAuth;
	Osp::Base::Collection::ArrayList * __pListenerList;
	Osp::Base::ByteBuffer* __pLastRequest;

	bool __isConstructed;

	bool __isCancelled;
	bool __isClosed;
	bool __isSubmitted;
	bool __isChunkedMode;
	bool __enableTransactionReadyToWrite;
	bool __isAuthRequest;
	bool __isResumedCert;

	// Friend class declaration.
	friend class HttpSession; // isClosed
	friend class __HttpTransactionEvent; // __isclosed
	friend class HttpRequest; // using GetSessionHandle()
	friend class HttpResponse; // using GetSessionHandle()
	friend class HttpAuthentication;
	friend class __HttpDefaultNetConnectionEventListenerImpl;

	friend class HttpTransactionEx;
	class HttpTransactionEx* __pHttpTransactionEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_TRANSACTION_H_

