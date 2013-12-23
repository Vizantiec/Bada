/* $Change: 797580 $ */
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
 * @file	FNetHttpIHttpProgressEventListener.h
 * @brief	This is the header file for the %IHttpProgressEventListener interface.
 *
 * This header file contains the declarations of the %IHttpProgressEventListener interface.
 */

#ifndef _FNET_HTTP_IHTTPPROGRESSEVENTLISTENER_H_
#define _FNET_HTTP_IHTTPPROGRESSEVENTLISTENER_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseRtIEventListener.h"
#include "FNetHttpHttpSession.h"
#include "FNetHttpHttpTransaction.h"

namespace Osp { namespace Net { namespace Http {

/**
 * @interface	IHttpProgressEventListener
 * @brief		This interface provides the listeners for the HTTP progress events.
 * @since 		2.0
 *
 * 	The %IHttpProgressEventListener interface is the listener for the %HTTP progress events, when the %HTTP message is uploaded or downloaded. In order to use this listener, 
 *				the listener must be set to the HttpTransaction instance using the SetHttpProgressListener() method.
 */

class _EXPORT_NET_ IHttpProgressEventListener :
	public Osp::Base::Runtime::IEventListener
{

// Lifecycle
public:
	/** 
	* This is the destructor for this class.
	*
	* @since 2.0
	*/
	virtual ~IHttpProgressEventListener(void) {}

public:
	/**
	 * Called to notify when the content body of the request message is being uploaded.
	 *
	 * @since 		2.0
	 * @param[in]	httpSession				The session information of the %Http transaction event
	 * @param[in]	httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]	currentLength			The current length of the uploaded data (in bytes)
	 * @param[in]	totalLength				The total length of the data (in bytes) to be uploaded
	 * @remarks		If the content length of the request message is not set, the value of @c totalLength is -1.
	 */
	virtual void OnHttpUploadInProgress(HttpSession& httpSession, HttpTransaction& httpTransaction, long long currentLength, long long totalLength) = 0;

	/**
	 * Called to notify when the content body of the response message is being downloaded.
	 *
	 * @since 		2.0
	 * @param[in]	httpSession				The session information of the %Http transaction event
	 * @param[in]	httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]	currentLength			The current length of the downloaded data (in bytes)
	 * @param[in]	totalLength				The total length of the data (in bytes) to be downloaded
	 * @remarks		If the content length of the response message is not set, the value of @c totalLength is -1.
	 */
	virtual void OnHttpDownloadInProgress(HttpSession& httpSession, HttpTransaction& httpTransaction, long long currentLength, long long totalLength) = 0;

protected:

	// Reserved virtual methods for later extension.
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnHttpProgressEventListener_Reserved1(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnHttpProgressEventListener_Reserved2(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void OnHttpProgressEventListener_Reserved3(void) {}
};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_IHTTPPROGRESSEVENTLISTENER_H_

