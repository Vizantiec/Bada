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
 * @file		FNetHttpHttpHeader.h 
 * @brief		This is the header file for the %HttpHeader class.
 *
 * This header file contains the declarations of the %HttpHeader class.
 */

#ifndef _FNET_HTTP_HTTP_HEADER_H_
#define _FNET_HTTP_HTTP_HEADER_H_

// Includes
#include "FNetConfig.h"
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseColMultiHashMap.h"
#include "FBaseColIEnumerator.h"
#include "FNetHttpHttpTypes.h"

namespace Osp 
{ 
namespace Net 
{ 
namespace Http 
{

/**
 * @class	HttpHeader
 * @brief	This class encapsulates the header fields associated with a message. 
 * @since	1.0
 *
 * 	The %HttpHeader class is a collection of header fields associated with an %HTTP message. The header fields can be added, read, modified, and 
 *			removed. Also, each field can have multiple values. This class provides easy access to the header.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 */

class _EXPORT_NET_ HttpHeader :
	public Osp::Base::Object
{

// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since 			1.0
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	HttpHeader(void);

	/**
	 * This is the copy constructor for the %HttpHeader class. @n
	 * This initializes an instance of %HttpHeader with the values of the specified instance.
	 *
	 * @since 		1.0
	 * @param[in]	pHeader					An instance of %HttpHeader
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The parameter @c pHeader can be @c null.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpHeader(const HttpHeader* pHeader);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	virtual ~HttpHeader(void);


// Operation
public:
	/** 
	 * Adds a named field, which is a <@c fieldName, @c fieldValue> pair, to the current instance of %HttpHeader.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	fieldName				A field name
	 * @param[in]	fieldValue				A field value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty String.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified field name already exists. @n
	 *										The <@c fieldName, @c fieldValue> pair already exists.
	 * @remarks		The field is created on the first instance when this method is used for a particular field name.
	 *				On subsequent calls, the same field is extended to have several parts, with a new part created to hold the supplied value.
	 *				If you need to submit a request in the chunked mode, you need to explicitly add the header field named 
	 *				"Transfer-Encoding" with the value @c chunked. Otherwise, the non-chunked mode is used as the default value.
	 * @see			RemoveField()
	 */
	result AddField(const Osp::Base::String& fieldName, const Osp::Base::String& fieldValue);

	
	/** 
	 * Removes all the fields with the specified field name.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	fieldName				The field name to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified field name is not found in the current instance of %HttpHeader. @n
	 *										The header field with the specified @c fieldName is not found.
	 * @see				AddField()
	 */
	result RemoveField(const Osp::Base::String& fieldName);


	/** 
	 * Removes only the specified <@c fieldName, @c fieldValue> pair from the current instance of %HttpHeader.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	fieldName				The field name to be removed
	 * @param[in]	fieldValue				The field value to be removed with the specified @c fieldName
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified field name is not found in the current instance of %HttpHeader. @n
	 *						The header field with the specified field name and field value is not found.
	 * @see				AddField()
	 */
	result RemoveField(const Osp::Base::String& fieldName, const Osp::Base::String& fieldValue);


	/**
	 * Removes all the fields of the current instance of %HttpHeader.
	 *
	 * @since 		1.0
	 */
	void RemoveAll(void);


// Accessor
public:
	/**
	 * Gets a raw header string. 
	 *
	 * @since 			1.0
	 * @return			A raw header string
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_HEADER		This header object does not contain any header field.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 *					
	 */
	Osp::Base::String* GetRawHeaderN(void) const;
	

	/** 
	 * Gets a list of all the field names in the current instance of %HttpHeader.
	 *
	 * @since 			1.0
	 * @return			A list that contains all the field names as string values
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_HEADER		This header object does not contain any header field.
	 */
	Osp::Base::Collection::IList* GetFieldNamesN(void) const;


	/** 
	 * Gets the field values corresponding to the specified field name. 
	 *
	 * @since 		1.0
	 * @return		An enumerator containing all the string values of the specified field name 
	 * @param[in]	fieldName				A field name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified field name is not found in the current instance of %HttpHeader. @n
	 *										The header field with the specified @c fieldName is not found.
	 */
	Osp::Base::Collection::IEnumerator* GetFieldValuesN(const Osp::Base::String& fieldName) const;

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 * Gets the field values corresponding to the specified field name.
	 *
	 * @since 		1.0
	 * @return		An enumerator containing all the string values of the specified field name
	 * @param[in]	fieldName				A field name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified field name is not found in the current instance of %HttpHeader. @n
	 *										The header field with the specified @c fieldName is not found.
	 */
	Osp::Base::Collection::IEnumerator* __GetFieldValuesN(const Osp::Base::String& fieldName) const;

// Operation
private:
	/**
	 * Sets the specified header as this header. 
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	header					A new header that need to be set as this header
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_INVALID_HEADER		This header object does not contain any header field.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		This method is only for internal use. 
	 */
	result SetHeader(const HttpHeader& header);

	/**
	 * Checks whether the header contains the specified header name.
	 *
	 * @since 		1.0
	 * @return		@c true if the header contains the specified header name, @n
	 *				else @c false
	 * @param[in]	fieldName				A field name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_HEADER		This header object does not contain any header field.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	bool IsExist(const Osp::Base::String& fieldName) const;

	/**
	 * Checks whether the header contains the specified header name.
	 *
	 * @since 		1.0
	 * @return		@c true if the header contains the specified header name, @n
	 *				else @c false
	 * @param[in]	fieldName				A field name
	 * @param[out]	outFieldName			A field name stored in %HttpHeader
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_HEADER		This header object does not contain any header field.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	bool IsExist(const Osp::Base::String& fieldName, Osp::Base::String& outFieldName) const;

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @since 		1.0
	 * @param[in]	rhs			An instance of %HttpHeader
	 */
	HttpHeader& operator=(const HttpHeader& rhs);


// Attribute
private:
	Osp::Base::Collection::MultiHashMap* __pHeaderMap;
	StringComparer* __pComparer;
	MultiHashMapDefaultProvider* __pProvider;

	// Friend class
	friend class HttpSession;
	friend class HttpTransaction;
	friend class HttpMessage;
	friend class HttpRequest;

	friend class HttpHeaderEx;
	class HttpHeaderEx* __pHttpHeaderEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTP_HEADER_H_

