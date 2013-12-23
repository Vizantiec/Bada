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
 * @file		FNetHttpHttpRequest.h 
 * @brief		This is the header file for the %HttpRequest class.
 *
 * This header file contains the declarations of the %HttpRequest class.
 */

#ifndef _FNET_HTTP_HTTP_REQUEST_H_
#define _FNET_HTTP_HTTP_REQUEST_H_

// Includes
#include "FNetHttpHttpTypes.h"

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpIHttpEntity.h"

namespace Osp { namespace Net { namespace Http {

class HttpMessage;
class HttpTransaction;
class IHttpProcessingPi;

/////////////////////////////////////////////////////////////////////////////
/**
 * @class	HttpRequest
 * @brief	This class represents a request message.
 * @since 	1.0
 *
 * The %HttpRequest class represents an HTTP request message that stores a method (for example, HTTP GET), a URI, and the other message headers 
 * 			and the body supplied by the %HttpMessage base class.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpRequest class.
 *
 * @code
 * 
 *	void
 *	Test(void)
 *	{
 *		result r = E_SUCCESS;
 *	
 *		// Opening a session - a transaction should be done beforehand.
 *
 *		// Get the request instance.
 *	 	HttpRequest* pHttpRequest = null;
 *		pHttpRequest = pHttpTransaction->GetRequest();
 *	 	if (null == pHttpRequest)
 *		{
 *			r = GetLastResult(); 
 *			AppLog("Get the request instance failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	
 *		// Method Setting
 *		NetHttpMethod method = NET_HTTP_METHOD_POST;
 *		r = pHttpRequest->SetMethod(method);  
 *	 	if (IsFailed(r))
 *		{
 *			AppLog("Method Setting failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	
 *		String uri;
 *		r = uri.Append(L"http://www.bada.com");
 *		if (IsFailed(r))
 *		{
 *			AppLog("Uri Construction failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	
 *		// Uri Setting
 *		r = pHttpRequest->SetUri(uri);
 *		if (IsFailed(r))
 *		{
 *			AppLog("Uri Setting failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	
 *		// Header Setting
 *		HttpHeader* pHttpHeader = null;
 *		pHttpHeader = pHttpRequest->GetHeader();
 *		if (null == pHttpHeader)
 *	 	{
 *			r = GetLastResult(); 
 *			AppLog("Uri Setting failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	 
 *		// Header Setting
 *		r = pHttpHeader->AddField(L"Content-Length", L"1024");
 *		if (IsFailed(r))
 *		{
 *			AppLog("Header Setting failed. (%s)\n", GetErrorMessage(r));
 *		}
 *	}
 *
 * @endcode
 */
//////////////////////////////////////////////////////////////////////////

class _EXPORT_NET_ HttpRequest :
	public HttpMessage
{

// Operation
public:
	/**
	 * Sets an HTTP method of the request header. @n
	 * The default method is @c NET_HTTP_METHOD_GET.
	 * 
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	method				An HTTP method
	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet. @n
	 *									The corresponding transaction is already submitted.
	 * @remarks		The detailed descriptions of the HTTP methods are as follows: @n
	 *				1) The OPTIONS() method represents a request for information about the communication options available on the request/response chain 
	 *				identified by the Request-URI. This method may include a message body to make more detailed queries. To do so, specify the Content-Length 
	 *				(or Transfer-Encoding), and Content-Type header fields. However, if the server does not support this, the server may discard the body. @n
	 *				2) The GET() method retrieves whatever information is identified by the Request-URI. @n
	 *				3) The HEAD() method is identical to GET() except that the server must not return a response message body. The GET() and HEAD() methods do 
	 * 				not include a message body. @n
	 *				4) The POST() method is used to request that the origin server accepts the entity enclosed in the request as a new subordinate of the 
	 *				resource identified by the Request-URI. @n
	 *				5) The PUT() method requests that the enclosed entity be stored under the supplied Request-URI. @n
	 *				When you are using the POST() or PUT() methods, be sure to specify the Content-Length header field, which is the message body length. @n
	 *				6) The DELETE() method requests that the origin server deletes the resource identified by the Request-URI.
	 * @see			GetMethod(), HttpHeader::AddField()
	 */
	result SetMethod(NetHttpMethod method);


	/**
	 * Sets a URI of the request header.
	 * 
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	uri					The raw URI @n
	 *									The URI must be a valid URI.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c uri is invalid.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet. @n
	 *									The corresponding transaction is already submitted.
	 * @remarks		The URI should be encoded properly according to RFC 2396 before using this method.
	 *				The ending slash is a required part of a URL specifying a directory.
	 * @see			Osp::Base::Utility::Uri, GetUri()
	 */
	result SetUri(const Osp::Base::String& uri);


	/**
	 * Sets the request message body.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	body						The message body data
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The submitted body size is out of range. 
	 * @exception	E_INVALID_STATE				This instance has not been constructed as yet. @n
	 * 											The SetEntity() function is already called, the corresponding transaction is already submitted, or a chunked 
	 *											mode is not enabled.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @remarks		This method can be used in two different situations. @n
	 *				@li Before submitting the request: @n 
	 *				In this case, this method can be called several times consecutively, and all the bodies are appended together in the message queue until 
	 *				the HttpRequest::Submit() method is called. Set the message body, when the POST() or PUT() method is used. @n
	 *				@li After receiving an ADDCHUNK event: @n
	 *				In this case, this method should be invoked only once at a time. The recommended chunk size is given in OnTransactionReadyToWrite(). @n
	 * @see			SetMethod(), NetHttpMethod
	 */
	virtual result WriteBody(const Osp::Base::ByteBuffer& body);

	/**
	 * Sets the request entity.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	entity						An instance of IHttpEntity to be sent
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The body size is out of range.
	 * @exception	E_INVALID_STATE				Either this instance has not been constructed as yet, or
	 *											the WriteBody() method is already called.
	 * @remarks		The instance of IHttpEntity is used by the internal platform.
	 * 				Do not delete or change the instance of %IHttpEntity before the OnTransactionCompleted() or OnTransactionAborted() method is called.
	 */
	result SetEntity(IHttpEntity& entity);


// Accessor
public:
	/** 
	 * Gets the HttpHeader object of the HTTP request. 
	 *
	 * @since 		1.0
	 * @return		The header object of the HTTP request, @n
	 *				else @c null if the header is not set properly
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_HEADER			The header is @c null.		  
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks		This method is used to access the header associated with a transaction's request. The handle is obtained from the HttpRequest object 
	 *				associated with the transaction. Adding, modifying, or removing a header field is done using this header handle.
	 */	
	virtual HttpHeader*  GetHeader(void) const;

	/**
	 * Sets the string to be sent in the cookie header field of %HttpRequest.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	cookieString			The cookie String @n
	 *										For example, Cookie: cookie-name1=cookie-value1;cookie-name2=cookie-value2.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result SetCookie(const Osp::Base::String& cookieString);

	/**
	 * Gets the cookie header field of %HttpRequest.
	 *
	 * @since 		1.0
	 * @return		The cookie string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Base::String GetCookie(void) const;

// Lifecycle
protected:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
	 * @see 		Construct()
	 */
	HttpRequest(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	virtual ~HttpRequest(void);

	/**
	 * Initializes this instance of %HttpRequest with the specified parameters.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	httpTransaction			The HTTP transaction 
	 * @param[in]	pCommonHeader			A header object that stores the common header
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is @c null.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Construct(const HttpTransaction& httpTransaction, const HttpHeader* pCommonHeader);

// Accessor
protected:
	/**
	 * Gets an HTTP method of the request header.
	 * 
	 * @since 			1.0
	 * @return			HTTP method
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception   	E_INVALID_STATE		This instance has not been constructed as yet.
	 */	
	NetHttpMethod GetMethod(void) const;


	/**
	 * Gets a URI of the request header. 
	 * 
	 * @since 		1.0
	 * @return		An error code
	 * @param[out]	uri					The raw URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	result GetUri(Osp::Base::String& uri) const;


	/** 
	 * Gets the message body associated with an HTTP Request.
	 *
	 * @since 		1.0
	 * @return		The response body object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_EMPTY_BODY			The requested body is empty.
	 * @exception	E_OUT_OF_MEMORY			The ByteBuffer size is smaller than the request body size.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
 	 * @exception	E_OUT_OF_RANGE			The @c data size exceeds the maximum range.
	 * @remarks		Be sure to @c Flip() the @c body, which is ByteBuffer, before reading any data in the ByteBuffer instance.
	 */	
	virtual Osp::Base::ByteBuffer* ReadBodyN(void);

private:
	result __WriteBody(const Osp::Base::ByteBuffer& body);

private:
	/**
	 * This is the copy constructor for the %HttpRequest class. @n
	 * This constructor initializes a new instance of the %HttpRequest class with the value from another instance.
	 *
	 * @param[in]	value 	An instance of %HttpRequest
	 */
	HttpRequest(const HttpRequest &value);
	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs				An instance of %HttpRequest
	 */
	HttpRequest& operator=(const HttpRequest& rhs);

// Attribute
private:
	IHttpProcessingPi* __pHttpProcessingInterface;
	HttpTransaction* __pHttpTransaction; // To get the HttpSession handle and HttpTransaction Handle.
	
	NetHttpMethod __method;
	Osp::Base::String __uri;

	Osp::Base::String __setCookieString;
	bool __isChunkedMode;
	bool __isSubmitted;
	bool __isConstructed;

	// Friend class declaration.
	friend class HttpTransaction;
	friend class HttpSession;
	friend class HttpResponse;

	friend class HttpRequestEx;
	class HttpRequestEx* __pHttpRequestEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_REQUEST_H_

