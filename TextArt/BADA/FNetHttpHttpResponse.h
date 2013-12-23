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
 * @file		FNetHttpHttpResponse.h
 * @brief		This is the header file for the %HttpResponse class.
 *
 * This header file contains the declarations of the %HttpResponse class.
 */

#ifndef _FNET_HTTP_HTTP_RESPONSE_H_
#define _FNET_HTTP_HTTP_RESPONSE_H_

// Includes
#include "FNetHttpHttpTypes.h"

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpHttpCookie.h"
#include "FBaseColLinkedList.h"

namespace Osp { namespace Net { namespace Http {

class IHttpProcessingPi;
class HttpMessage;
class HttpTransaction;
class HttpCookie;
/**
 * @class	HttpResponse
 * @brief	This class represents a response message.
 * @since 	1.0
 *
 * The %HttpResponse class represents a response message that stores a status code, the status text, and the server version information, as well as 
 *			the message headers and body supplied by the HttpMessage base class.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpResponse class.
 *
 * @code
 *
 *	void
 *	MyEventListener::OnTransactionReadyToRead(const Osp::Net::Http::HttpSession& httpSession,
 *							 const Osp::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen)
 *	{
 *		HttpTransaction* pTransaction = const_cast<HttpTransaction*>(&(httpTransaction));
 *		HttpResponse* pResponse = pTransaction->GetResponse();
 *		ByteBuffer* pBody = null;
 *		String statusText;
 *		String version;
 *		if(pResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
 *		{
 *			statusText = pResponse->GetStatusText();
 *			version = pResponse->GetVersion();
 *			pBody = pResponse->ReadBodyN();
 *			delete pBody;
 *		}
 *	}
 *
 * @endcode
 */
//////////////////////////////////////////////////////////////////////////
class _EXPORT_NET_ HttpResponse :
	public HttpMessage
{

// Accessor
public:
	/**
	 * Gets the status code from the response header.
	 *
     * @deprecated This method is deprecated. Instead of using this method, it is recommended to use the GetHttpStatusCode(void) method that returns the status code as an integer type.
	 *
	 * @since 		1.0
	 * @return		The status code, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet. @n
	 *										Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA			The status code is not defined.
	 * @remarks		The @c statusText gives a short textual description of the status code. It is placed after the status code on the first line of the 
	 *				response. The specific error code can be accessed using the GetLastResult() method.
	 * @see			NetHttpStatusCode, SetStatusCode()
	 */
	NetHttpStatusCode GetStatusCode(void) const;


	/**
	 * Gets the HTTP status code from the response header.
	 *
	 * @since 		2.0
	 * @return		The status code, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet. @n
	 *											Invoke this method before receiving a response header.
	 * @remarks		The @c statusText gives a short textual description of the status code. It is placed after the status code on the first line of the 
	 *				response. The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetHttpStatusCode()
	 */
	int GetHttpStatusCode(void) const;



	/**
	 * Gets a short textual description of the status code from the response header. @n
	 * This description is placed after the status code on the first line of the response.
	 *
	 * @since 		1.0
	 * @return		The status description, @n
	 *				else an empty string when the status text is not defined
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet. @n
	 *											Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA				The status text is not defined.
	 * @remarks   	The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetStatusText()
	 */
	Osp::Base::String GetStatusText(void) const;


	/**
	 * Gets the version of the protocol used by the server from the response header.
	 *
	 * @since 		1.0
	 * @return		The protocol version, @n
	 *				else an empty string when the version is not defined
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet. @n
	 *											Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA				The version is not defined.
	 * @remarks  	The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetVersion()
	 */
	Osp::Base::String GetVersion(void) const;


	/**
	 * Gets the HttpHeader object of a response header.
	 *
	 * @since 		1.0
	 * @return		The header object, @n
	 *				else @c null if the header is not received
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet. @n
	 *											Invoke this method before receiving a response header.
	 * @exception	E_INVALID_HEADER			The header is @c null.
	 * @remarks    	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual HttpHeader*  GetHeader(void) const;


	/**
	 * Gets the message body of the response.
	 *
	 * @since 		1.0
	 * @return		The response body object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet. @n
	 *										Invoke this method before receiving a response body.
	 * @exception	E_EMPTY_BODY			The requested body is empty.
	 * @exception	E_OUT_OF_RANGE			The specified @c data size exceeds the maximum range.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @exception	E_IO					The method has failed to read the data.
 	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @remarks		This method can be invoked several times until there is no more data.
	 */
	virtual Osp::Base::ByteBuffer*  ReadBodyN(void);

	/**
	 * Gets the list of Cookies received in the response.
	 *
	 * @since 		1.0
	 * @return		A list containing HttpCookie instances, @n
	 *				else @c null if no cookie is received in the response
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid in this state.
	 */
	Osp::Base::Collection::IList* GetCookies(void);

// LifeCycle
protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
	 * @see 		Construct()
	 */
	HttpResponse(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	virtual ~HttpResponse(void);

	/**
	 * Initializes this instance of %HttpResponse with the specified parameter.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	httpTransaction			The %HTTP transaction
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified input parameter is @c null.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Construct(const HttpTransaction& httpTransaction);


// Operation
protected:
	/**
	 * Sets the status code from the response header.
	 *
     * @deprecated This method is deprecated. Instead of using this method, it is recommended to use the SetHttpStatusCode(int statusCode) method that sets 
	 * the status code as integer type.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	statusCode				The status code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
 	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @remarks		The @c statusCode element is a 3-digit integer result code of the attempt to understand and satisfy the request. The first digit of the 
	 *				@c statusCode defines the class of response. The last two digits do not have any categorization role.
	 * @see			GetStatusCode()
	 */
	result SetStatusCode(NetHttpStatusCode statusCode);

	/**
	 * Sets the status code from the response header.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	statusCode				The status code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
 	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @remarks		The @c statusCode element is a 3-digit integer result code of the attempt to understand and satisfy the request. The first digit of the 
	 *				@c statusCode defines the class of response. The last two digits do not have any categorization role.
	 * @see			GetHttpStatusCode()
	 */
	result SetHttpStatusCode(int statusCode);


	/**
	 * Sets the status text from the response header.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	statusText				The status description
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is @c null.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @remarks		The @c statusText gives a short textual description of the status code. This description is placed after the status code on the first 
	 *				line of the response.
	 * @see			GetStatusText()
	 */
	result SetStatusText(const Osp::Base::String& statusText);


	/**
	 * Sets the version of the protocol used by the server from the response header.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	httpVersion				The protocol version
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is @c null.
 	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @see			GetVersion()
	 */
	result SetVersion(const Osp::Base::String& httpVersion);


	/**
	 * Sets the response body.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	body					The message body data
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
 	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.

	 * @remarks		This method can be invoked several times until there is no more data to write.
	 */
	virtual result WriteBody(const Osp::Base::ByteBuffer& body);


	/**
	 * Reads the data from the data communicated.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	headerLen				The header length to be read
	 * @param[in]	bodyLen					The body length to be read
	 * @param[out]	rcvHeaderLen			The received header length
	 * @param[out]	rcvBodyLen				The received body length
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_IO					The method has failed to read the data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_SESSION		The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION	The transaction handle is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
 	 * @exception	E_OUT_OF_RANGE			The read data exceeds the maximum range.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The comparer failed to compare keys.
	 * @exception	E_INVALID_HEADER 		An invalid header is received in response.
	 */
	result Read(int headerLen, int bodyLen , int& rcvHeaderLen, int& rcvBodyLen);

	/**
	 * Saves the cookie received in the response to %HttpResponse.
	 *
	 * @since 			1.0
	 * @return			An error code
	 * @param[in]		pHeader					A response header
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid in this state.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks			Transaction events use this method to set the cookie received in the response.
	 * @see				GetCookie()
	 */
	result SetCookie(Osp::Net::Http::HttpHeader* pHeader);
// Operation
private:
	/*
	 * Parses the response header.
	 *
	 * @return		An error code
	 * @param[in]	rawHeader				A raw response header
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified instance already exists. @n
	 *										The pair of @c pKey and @c pValue already exists.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The comparer failed to compare the keys.
	 */
	result HeaderParse(const Osp::Base::String& rawHeader);


	/*
	 * Parses a response header field.
	 *
	 * @return		An error code
	 * @param[in]	fieldStr				A field string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified instance already exists. @n
	 *										The pair of @c pKey and @c pValue already exists.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The comparer failed to compare keys.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure.
	 */
	result FieldParse(const Osp::Base::String& fieldStr);


	/*
	 * Checks whether the specified parameter is in the date format.
	 *
	 * @return		@c true if the specified parameter is in the date format, @n
					else @c false
	 * @param[in]	dateStr			The string to be checked
	 */
	bool IsDateFormat(const Osp::Base::String& dateStr) const;

	/**
	 * This is the copy constructor for the %HttpResponse class. @n
	 * This constructor initializes a new instance of the %HttpResponse class with the value from another instance.
	 *
	 * @param[in]	value 	An instance of %HttpResponse
	 */
	HttpResponse(const HttpResponse &value);

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs				An instance of %HttpResponse
	 */
	HttpResponse& operator=(const HttpResponse& rhs);

// Attribute
private:
	IHttpProcessingPi* __pHttpProcessingInterface;
	HttpTransaction* __pHttpTransaction;  // To get the HttpSession handle and HttpTransaction Handle.

	Osp::Base::String __statusText;
	NetHttpStatusCode __statusCode;
	Osp::Base::String	__version;
	Osp::Base::Collection::LinkedList __cookieList;

	bool __isHeaderReceived;
	bool __isBodyReceived;
	bool __isConstructed;

// Friend class declaration.
	friend class HttpTransaction;
	friend class __HttpTransactionEvent;

	friend class HttpResponseEx;
	class HttpResponseEx* __pHttpResponseEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_RESPONSE_H_

