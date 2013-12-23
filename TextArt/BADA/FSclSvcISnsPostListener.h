/* $Change:  $ */
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
 * @file		FSclSvcISnsPostListener.h
 * @brief		This is the header file for the %ISnsPostListener interface.
 *
 * This header file contains the declarations of the %ISnsPostListener interface.
 */
#ifndef _FSCL_SVC_ISNS_POST_LISTENER_H_
#define _FSCL_SVC_ISNS_POST_LISTENER_H_


#include "FBaseRtIEventListener.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsPostListener
* @brief	This listener interface receives responses to requests associated with publishing a post through SnsGateway.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.2
*
* The %ISnsPostListener interface receives responses to requests associated with publishing a post through SnsGateway.
*/
class  _EXPORT_SOCIAL_ ISnsPostListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called when the response to SnsGateway::PublishPost() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.2
	* @param[in]	reqId			The ID of the request
	* @param[in]	pPostId			The ID of the post published @n
									The parameter is set to @c null when the publishing of the post fails.
	* @param[in]	r				The result of the request
	* @param[in]	errorCode		The error code from the server
	* @param[in]	errorMsg		The error message from the server
	* @exception	E_SUCCESS		The request was successful.
	* @exception	E_SERVER		An error occurred on the server side.
	* @exception	E_CONNECTION_FAILED Network connection failed.
	* @exception	E_PARSING_FAILED	The response data from the server could not be parsed.
	* @see	SnsGateway::PublishPost()
	*/
	virtual void	OnSnsPostPublished(RequestId reqId, Osp::Base::String* pPostId,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};

};};};

#endif
