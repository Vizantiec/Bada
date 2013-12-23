/* $Change: 1202329 $ */
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
 * @file	FSclSvcISnsActivityListener.h
 * @brief	This is the header file for the %ISnsActivityListener interface.
 *
 * This header file contains the declarations of the %ISnsActivityListener interface.
 */
#ifndef _FSCL_SVC_ISNS_ACTIVITY_LISTENER_H_
#define _FSCL_SVC_ISNS_ACTIVITY_LISTENER_H_


#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FSclConfig.h"

#include "FSclSvcSnsPagingParam.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsActivityListener 
* @brief		This listener interface is for receiving the responses to requests from SnsGateway.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* The %ISnsActivityListener interface is for receiving the responses to requests from SnsGateway.
*/
class  _EXPORT_SOCIAL_ ISnsActivityListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* Called when the response to SnsGateway::GetActivities() is received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The ID of the request
	* @param[in]	pActivityList			The list of activity @n
	*							 			The item of this list is SnsActivity.
	* @param[in]	hasNext					Set to @c true if the next page exists, @n
	*										else @c false @n
	*										The value indicates whether the next page exists.
	* @param[in]	pagingParam				The current page number and the desired maximum count in this page		
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful. 
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	SnsGateway::GetActivities()
	*/
	virtual void	OnSnsActivitiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pActivityList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};

};};};

#endif
