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
 * @file		FNetHttpHttpMessage.h 
 * @brief		This is the header file for the %HttpMessage class.
 *
 * This header file contains the declarations of the %HttpMessage class.
 */

#ifndef _FNET_HTTP_HTTP_MESSAGE_H_
#define _FNET_HTTP_HTTP_MESSAGE_H_

// Includes
#include "FBaseByteBuffer.h"
#include "FBaseColQueue.h"
#include "FNetHttpHttpHeader.h"

namespace Osp 
{ 
namespace Net 
{ 
namespace Http 
{

/**
 * @class	HttpMessage
 * @brief	This class is the base class for %HttpRequest and %HttpResponse.
 * @since 	1.0
 *
 * The %HttpMessage class represents the %HTTP messages for the data exchanged between the client and the server, specifically for a request or a 
 *			response. Both message types consist of a start line, zero or more header fields, an empty line indicating the end of the header fields, and 
 *			possibly a message body.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>. 
 */

class _EXPORT_NET_ HttpMessage :
	public Osp::Base::Object
{

// Lifecycle
protected:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since 1.0
	 */
	HttpMessage(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~HttpMessage(void);

// Operation
protected:
	/**
	 * Writes the message body. @n
	 * This method can be called several times consecutively. All the message bodies are stored in the queue.
	 * 
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	body						The message body data
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified @c body contains an invalid value.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The size of the specified body is out of range.
	 * @exception 	E_INVALID_STATE				The current state of the instance prohibits the execution of the specified operation. @n
	 *											The %HttpMessage instance has not been constructed as yet.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @remarks		This method only considers the data between the position and the limit of the %ByteBuffer as valid.
	 *				The position and limit has to be set appropriately before invoking this method.
	 * @see			ReadBodyN()
	 */
	virtual result WriteBody(const Osp::Base::ByteBuffer& body) = 0;


// Accessor
protected:
	/** 
	 * Gets the header. @n
	 * This method is used to access the headers associated with a transaction request or response.
	 * The handle is obtained from either the HttpRequest or the HttpResponse objects associated with the transaction. Adding, modifying, or removing a 
	 * header field is done using this header handle.
	 *
	 * @since 		1.0	
	 * @return		The pointer to %HttpHeader that is to be modified, @n
	 *				else @c null if %HttpMessage is not constructed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE		The method invoked is invalid. @n
	 *									Invoke this method before receiving a response header.
	 * @exception	E_INVALID_HEADER	The header is @c null. 
	 */	
	virtual HttpHeader* GetHeader(void) const = 0;


	/** 
	 * Gets the body of the message associated with %HttpRequest or %HttpResponse.
	 *
	 * @since 		1.0
	 * @return		The message body
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method before receiving a response body.
	 * @exception	E_EMPTY_BODY			The requested body is empty. 
	 * @exception	E_OUT_OF_RANGE			The size of the message body is out of range.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @exception	E_IO					The method has failed to read the data.
 	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @remarks		Once this method is invoked, the returned message body is removed from the message body queue.
	 *				In other words, the message body queue does not hold all the bodies permanently. 
	 * @see			WriteBody()
	 */	
	virtual Osp::Base::ByteBuffer* ReadBodyN(void)  = 0;


// Attribute
protected:

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not responsible for
	 * any behavioral correctness, consistency, and security-related issues that might arise after using this variable.
	 *
	 * The total length of the message body
	 *
	 * @since       1.0
	 */
	unsigned int __totalLen; // total length of message body.

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not responsible for
	 * any behavioral correctness, consistency, and security-related issues that might arise after using this variable.
	 *
	 * The message queue
	 *
	 * @since       1.0
	 */
	Osp::Base::Collection::Queue __pBodyQueue; // stores a message body. 

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not responsible for
	 * any behavioral correctness, consistency, and security-related issues that might arise after using this variable.
	 *
	 * The header of message
	 *
	 * @since       1.0
	 */
	HttpHeader* __pHeader; // stores a message header.
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_MESSAGE_H_

