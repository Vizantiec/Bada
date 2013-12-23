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
 * @if PRIVCORE
 * @file	FNetHttpOspServerUtil.h
 * @brief	This is the header file for the %OspServerUtil class.
 *
 * This header file contains the declarations of the %OspServerUtil class.
 *
 * @endif
 */

#ifndef _FNET_HTTP_OSPSERVERUTIL_H_
#define _FNET_HTTP_OSPSERVERUTIL_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FNetConfig.h"
#include "FNetHttpHttpTypes.h"

namespace Osp { namespace Net { namespace Http {

/**
 * @if PRIVCORE
 * @class	OspServerUtil
 * @brief	This is the utility class for communicating with the Osp server.
 * @since 	1.2
 *
 * The %OspServerUtil class is the utility class for communicating with the Osp server.
 * It generates an authorization header required by the Osp server.
 *
 * @endif
 */
class _EXPORT_NET_ OspServerUtil
{
public:

	/**
	 * @if PRIVCORE
	 * Generates an authorization header for communicating with the Osp server.
	 *
	 * @since 		1.2
	 * @privlevel	CORE
	 * @privgroup   SNS_SSO
	 *
	 * @return		An error code
	 * @param[in]	method					An HTTP method
	 * @param[in]	uri						The raw URI @n
	 *										The URI must be a valid URI.
	 * @param[in]	pBody					The message body data
	 * @param[out]	authorizationHeader		The generated authorization header
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	 * @remarks		The URI should be encoded properly according to RFC 2396 before using this method.
	 *				The ending slash is a required part of a URL specifying a directory.
	 * 		The "x-osp-version" header should be added for communicating with the Osp server.
	 *  	Do not use this method without obtaining prior permissions from the bada platform team.
	 *
	 * @code
	 *
	 *	String* pProxyAddr = null;
	 *	String hostAddr = L"http://www.ospserver.net";
	 *	String uri = L"http://www.ospserver.net/test";
	 *	HttpHeader* pHeader= null;
	 *	HttpTransaction* pHttpTransaction = null;
	 *
	 *	__pHttpSession = new HttpSession();
	 *	__pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr, hostAddr, null);
	 *
	 *	pHttpTransaction = __pHttpSession->OpenTransactionN();
	 *	pHttpTransaction->AddHttpTransactionListener(*this);
	 *
	 *	HttpRequest* pHttpRequest = pHttpTransaction->GetRequest();
	 *	pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);
	 *	pHttpRequest->SetUri(uri);
	 *
	 *	// Make a body.
	 *	ByteBuffer reqBody;
	 *	const char* pBodyArray = "body message";
	 *	int len = strlen(pBodyArray);
	 *	reqBody.Construct(len);
	 *	reqBody.SetArray((byte*)pBodyArray, 0, len);
	 *	reqBody.Flip();
	 *
	 *	pHeader = pHttpRequest->GetHeader();
	 *
	 *  String ospAuthorization;
	 *  // Generate an authentication header for Osp server.
	 *  r = OspServerUtil::GenerateAuthorizationHeader(NET_HTTP_METHOD_POST, uri, &reqBody, ospAuthorization);
	 *
	 *	// Add an Osp header.
	 *	pHeader->AddField(L"Authorization", ospAuthorization);
	 *	pHeader->AddField(L"x-osp-version", L"v1");
	 *
	 *	pHeader->AddField(L"Content-Length", Integer::ToString(len));
	 *
	 *  pHttpRequest->WriteBody(reqBody);
	 *	pHttpTransaction->Submit();
	 *
	 * @endcode
	 *
	 * @endif
	 */
	static result  GenerateAuthorizationHeader(NetHttpMethod method, const Osp::Base::String& uri, const Osp::Base::ByteBuffer* pBody, Osp::Base::String& authorizationHeader);

private:

	/**
	 * This is the default constructor for this class.
	 */
	OspServerUtil(void);

	/**
	 * This is the destructor for this class.
	 */
	virtual ~OspServerUtil(void);
};

};
};
}; //Osp::Net::Http
#endif // _FNET_HTTP_OSPSERVERUTIL_H_
