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
 * @file		FNetHttp.h 
 * @brief		This is the header file for the %Http namespace.
 *
 * This header file contains the declarations and descriptions of the %Http namespace.
 */
#ifndef _FNET_HTTP_H_
#define _FNET_HTTP_H_

#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpRequest.h"
#include "FNetHttpHttpResponse.h"
#include "FNetHttpHttpSession.h"
#include "FNetHttpHttpCookieStorageManager.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpIHttpTransactionEventListener.h"
#include "FNetHttpHttpAuthentication.h"
#include "FNetHttpHttpCookie.h"
#include "FNetHttpHttpCredentials.h"
#include "FNetHttpOspServerUtil.h"
#include "FNetHttpIHttpEntity.h"
#include "FNetHttpHttpMultipartEntity.h"
#include "FNetHttpIHttpProgressEventListener.h"


namespace Osp 
{ 
namespace Net 
{
/**
 * @namespace	Osp::Net::Http
 * @brief		This namespace contains the classes and interfaces for the %HTTP 1.1 client programming.
 * @since 		1.0
 *
 * @remarks   	@b Header @b %file: @b \#include @b <FNet.h> @n
 *			   	@b Library : @b FOsp
 *
 * The %Http namespace contains the fundamental classes and interfaces for the %HTTP 1.1 client programming.
 *
 * It provides the implementation of the %HTTP data communication protocol. This namespace provides:
 * - A client interface for the internet applications using the %HTTP protocol for communication with the %HTTP servers on the Internet. 
 * - A %HTTP management module that encapsulates a standard %HTTP request-and-response transaction and provides access to the common %HTTP headers. 
 * - Support for most %HTTP 1.1 features, including pipelining and chunking.
 *
 *    Using this namespace correctly, makes the application a conditional %HTTP 1.1-compliant client, as defined in RFC 2616.
 *
 * For more information on the %HTTP namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Net namespace.
 * @image	html	net_http_using_the_apis_classdiagram.png
 *
 * 
 */
namespace Http
{
}; //	Osp::Net::Http
}; //	Osp::Net
}; //	Osp
#endif // _FNET_H_
