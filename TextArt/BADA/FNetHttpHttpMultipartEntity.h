/* $Change: 527986 $ */
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
 * @file	FNetHttpHttpMultipartEntity.h
 * @brief	This is the header file for the %HttpMultipartEntity class.
 *
 * This header file contains the declarations of the %HttpMultipartEntity class.
 */

#ifndef _FNET_HTTP_HTTPMULTIPARTENTITY_H_
#define _FNET_HTTP_HTTPMULTIPARTENTITY_H_

// Includes
#include "FNetConfig.h"
#include "FBase.h"
#include "FNetHttpHttpTypes.h"
#include "FNetHttpIHttpEntity.h"
#include "FText.h"

namespace Osp { namespace Net { namespace Http {

/**
 * The constant for the default MIME type of the string part.
 * @since	2.0
 */
static const Osp::Base::String	STRING_PART_DEFAULT_MIME_TYPE			= L"text/plain";

/**
 * The constant for the default MIME type of the file part.
 * @since	2.0
 */
static const Osp::Base::String	FILE_PART_DEFAULT_MIME_TYPE				= L"application/octet-stream";

/**
 * @class	HttpMultipartEntity
 * @brief	This class represents a multipart/form-data entity as defined in RFC 2388.
 * @since 2.0
 *
 * 	The %HttpMultipartEntity class represents a multipart/form-data entity as defined in RFC 2388.
 *  The multipart/form-data entity contains a series of parts.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use this class to upload the content to the server.
 *
 * @code
 *
 *	#include <FBase.h>
 *	#include <FNet.h>
 *
 * 	using namespace Osp::Base;
 *	using namespace Osp::Io;
 *	using namespace Osp::Net;
 *	using namespace Osp::Net::Http;
 *
 *	void
 *	HttpMultipartUploadTest(void)
 *	{
 *
 *	 	   HttpSession* pHttpSession = null;
 *	 	   HttpTransaction* pHttpTransaction = null;
 *	 	   HttpRequest* pHttpRequest = null;
 *	 	   HttpMultipartEntity* pMultipartEntity = null;
 *
 *	  	   MyHttpListener* pHttpListener = new MyHttpListener();
 *
 *	 	   // Creates an HTTP session.
 *	 	   pHttpSession = new HttpSession();
 *	 	   pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, L"http://localhost:port", null);
 *
 *	 	   pHttpTransaction = pHttpSession->OpenTransactionN();
 *	 	   pHttpTransaction->AddHttpTransactionListener(*pHttpListener);
 *	 	   pHttpTransaction->SetHttpProgressListener(*pHttpListener);
 *
 *	 	   pHttpRequest = pHttpTransaction->GetRequest();
 *	 	   pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
 *	 	   pHttpRequest->SetUri(L"http://localhost:port/upload/");
 *
 *		   pMultipartEntity = new HttpMultipartEntity();
 *	 	   pMultipartEntity->Construct();
 *
 *	 	   pMultipartEntity->AddStringPart(L"title", L"bada logo");
 *	 	   pMultipartEntity->AddStringPart(L"date", L"2010-12-25");
 *	 	   pMultipartEntity->AddFilePart(L"upload", L"/Home/bada.jpg", L"bada.jpg", L"image/jpeg", L"ISO-8859-1");
 *
 *	 	   pHttpRequest->SetEntity(*pMultipartEntity);
 *	 	   pHttpTransaction->Submit();
 *
 *	}
 *
 *  ...
 *
 *	void MyHttpListener::OnHttpUploadInProgress(HttpSession &httpSession, HttpTransaction &httpTransaction, long long currentLength, long long totalLength)
 *	{
 *		AppLog("[Upload] Current Bytes: %lld, Total Bytes: %lld", currentLength, totalLength);
 *	}
 *
 * @endcode
 */

class _EXPORT_NET_ HttpMultipartEntity :
	public Osp::Base::Object,
	public IHttpEntity
{

// Lifecycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	HttpMultipartEntity(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~HttpMultipartEntity(void);

	/**
	 * Initializes this instance of %HttpMultipartEntity.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %HttpMultipartEntity with the specified parameters.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	boundary			The boundary of multipart/form-data
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Osp::Base::String& boundary);

private:

	/**
	 * This is the copy constructor for the HttpMultipartEntity class.
	 *
	 * @param[in]	value		An instance of %HttpMultipartEntity
	 */
	HttpMultipartEntity(const HttpMultipartEntity& value);

	/**
	 * This is the assignment operator. 
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs			An instance of %HttpMultipartEntity
	 */
	HttpMultipartEntity& operator =(const HttpMultipartEntity& rhs);

// Operation
public:

	/**
	 * Gets the length of the request content.
	 *
	 * @since 		2.0
	 * @return		A length of content, @n
	 *				else @c -1 if the content length of the request content is unknown
	 */
	virtual long long GetContentLength(void) const;

	/**
	 * Gets the type of the request content.
	 *
	 * @since 		2.0
	 * @return		The type of the content
	 */
	virtual Osp::Base::String GetContentType(void) const;

	/**
	 * Adds the string part to %HttpMultipartEntity with the default MIME type and character set.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name						The name of the part
	 * @param[in]	text						The text of the part @n
	 *											The value of @c text is encoded using the default character encoding standard ("ISO-8859-1").
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet.
	 * @exception	E_INVALID_ENCODING_RANGE 	The @c text contains code points, which are outside the bounds specified by the @c encoding.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The default MIME type is "text/plain".
	 */
	result AddStringPart(const Osp::Base::String& name, const Osp::Base::String& text);

	/**
	 * Adds the string part to the %HttpMultipartEntity.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name						The name of the part
	 * @param[in]	text						The text of the part
	 * @param[in]	mimeType					The MIME type of @c text
	 * @param[in]	charset						The character set of @c text
	 * @param[in]	encoding					An encoding scheme for the specified @c text
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet.
	 * @exception	E_INVALID_ENCODING_RANGE 	The @c text contains code points, which are outside the bounds specified by the @c encoding.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	result AddStringPart(const Osp::Base::String& name, const Osp::Base::String& text, const Osp::Base::String& mimeType, const Osp::Base::String& charset, const Osp::Text::Encoding& encoding);

	/**
	 * Adds the file part to %HttpMultipartEntity with the default MIME type.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	filePath			The path of the file to be uploaded
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The default MIME type is "application/octet-stream".
	 */
	result AddFilePart(const Osp::Base::String& name, const Osp::Base::String& filePath);

	/**
	 * Adds the file part to %HttpMultipartEntity.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	filePath			The path of the file to be uploaded
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	mimeType			The MIME type of the content
	 * @param[in]	charset				The character set of the content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddFilePart(const Osp::Base::String& name, const Osp::Base::String& filePath, const Osp::Base::String& fileName, const Osp::Base::String& mimeType, const Osp::Base::String& charset);

	/**
	 * Adds the binary part to %HttpMultipartEntity with the default MIME type.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	buffer				The buffer of file to upload
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The default MIME-type is "application/octet-stream".
	 */
	result AddFilePartByBuffer(const Osp::Base::String& name, const Osp::Base::String& fileName, const Osp::Base::ByteBuffer& buffer);

	/**
	 * Adds the binary part to %HttpMultipartEntity.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	buffer				The buffer of the file to be uploaded
	 * @param[in]	mimeType			The MIME type of the content
	 * @param[in]	charset				The character set of the content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddFilePartByBuffer(const Osp::Base::String& name, const Osp::Base::String& fileName, const Osp::Base::ByteBuffer& buffer, const Osp::Base::String& mimeType, const Osp::Base::String& charset);


protected:

	/**
	 * Checks whether the next data exists.
	 *
	 * @since 		2.0
	 * @return		@c true if the next data exists, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual	bool	HasNextData(void);

	/**
	 * Gets the next data.
	 *
	 * @since 		2.0
	 * @return		The buffer to be read.
	 * @param[in]	recommendedSize			The recommended size of the data to be sent
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GetNextDataN(int recommendedSize);


private:
	/**
	 * Generates a boundary.
	 *
	 * @return		The generated boundary
	 */
	Osp::Base::String	GenerateBoundary(void) const;


// Member Variables
private:

	bool				__isConstructed;

	Osp::Base::String		__boundary;

	Osp::Base::Collection::IList*	__pStringPartList;
	Osp::Base::Collection::IList*	__pFilePartList;

	friend class HttpMultipartConverter;
	class HttpMultipartConverter* __pHttpMultipartConverter;

	friend class HttpMultipartEntityEx;
	class HttpMultipartEntityEx* __pHttpMultipartEntityEx;
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_HTTPMULTIPARTENTITY_H_

