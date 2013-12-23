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
 * @file	FSclSvcISnsPeopleListener.h
 * @brief	This is the header file for the %ISnsPeopleListener interface.
 *
 * This header file contains the declarations of the %ISnsPeopleListener interface.
 */
#ifndef _FSCL_SVC_ISNS_PEOPLE_LISTENER_H_
#define _FSCL_SVC_ISNS_PEOPLE_LISTENER_H_


#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FSclConfig.h"

#include "FSclSvcSnsProfile.h"
#include "FSclSvcSnsStatusText.h"
#include "FSclSvcSnsPagingParam.h"

namespace Osp { namespace Social { namespace Services {

/**
* @interface	ISnsPeopleListener 
* @brief		This interface represents a listener that receives the events associated with SnsGateway.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* The %ISnsPeopleListener interface represents a listener that receives the events associated with SnsGateway.
*/
class  _EXPORT_SOCIAL_ ISnsPeopleListener
	: public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* @if PRIVCORE 
	* Called when the SnsGateway::GetMyBuddies() or SnsGateway::GetBuddies() method is completed. @n
	* @else 
	* Called when the SnsGateway::GetMyBuddies() method is completed. @n
	* @endif
	* The application receives the response to this method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pBuddyProfileList		The buddy profile list @n
	*										Every item on this list is an SnsProfile.
	* @param[in]	hasNext					The value indicates whether the next page exists @n
	*										Set to @c true if the next page exists, @n
	*										else @c false
	* @param[in]	pagingParam				The current page number and the desired maximum number of results on this page
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see Osp::Social::Services::SnsProfile
	* @see	@if PRIVCORE SnsGateway::GetMyBuddies(), SnsGateway::GetBuddies()
	*		@else SnsGateway::GetMyBuddies()
	*		@endif
	*/
	virtual void	OnMySnsBuddiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyProfileList,
		bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the SnsGateway::GetStatusText() method is completed. @n
	* The application receives the response to this method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pStatusText				The SnsStatusText of the requested user 
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see Osp::Social::Services::SnsStatusText
	* @see	SnsGateway::GetStatusText()
	*/
	virtual void	OnSnsStatusTextReceived(RequestId reqId, Osp::Social::Services::SnsStatusText* pStatusText,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the SnsGateway::UpdateMyStatusText() method is completed. @n
	* The application receives the response to the method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	serviceProvider			The service provider for which the status text is updated
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	SnsGateway::UpdateMyStatusText()
	*/
	virtual void	OnMySnsStatusTextUpdated(RequestId reqId, Osp::Base::String& serviceProvider,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the SnsGateway::GetProfile() method is completed. @n
	* The application receives the response to the method from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	reqId					The request ID
	* @param[in]	pProfile				The SNS profile
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side. 
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see Osp::Social::Services::SnsProfile
	* @see	SnsGateway::GetProfile()
	*/
	virtual void	OnSnsProfileReceived(RequestId reqId, SnsProfile* pProfile,
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};

};};};

#endif
