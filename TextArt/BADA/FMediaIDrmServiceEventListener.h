// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaIDrmServiceEventListener.h
 *	@brief	This is the header file for the %IDrmServiceEventListener interface.
 *
 *	This header file contains the declarations of the %IDrmServiceEventListener interface.
 */
#ifndef FMEDIA_IDRMSERVICE_EVENTLISTENER_H_
#define FMEDIA_IDRMSERVICE_EVENTLISTENER_H_

#include <FBase.h>
#include "FMediaConfig.h"

namespace Osp { namespace Media {

class DrmService;

/**
 *  @if PRIVCORE
 *	@interface	IDrmServiceEventListener
 *	@brief	This interface provides a listener for the DrmService class.
 *  @since	2.0
 *
 *	The %IDrmServiceEventListener interface provides various event callback methods for the %DrmService class.
 *	@endif
 */
class _EXPORT_MEDIA_ IDrmServiceEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 * Called when the requested license is received.
	 *	@since	2.0
	 *
	 * @param[in]	src						The instance of %DrmService that sent this event
	 * @param[in]	reqId					The request ID that is returned to DrmService::RequestLicense()
	 * @param[in]	r						The result of the request
	 * @param[in]	pErrorMsg				The error message
	 * @param[in]	pResponse				The response data sent by the DRM service provider
	 * @exception	E_SUCCESS				The request is successful.
	 * @exception	E_INVALID_DOMAIN		The domain server is invalid.
	 * @exception	E_NOT_JOINED			The client has not joined the domain server.
	 * @exception	E_INVALID_CONTENT		The given file or license is invalid.
	 * @exception	E_CONNECTION_FAILED 	The network connection has failed.
	 * @exception	E_OPERATION_FAILED		The requested operation has failed.
	 * @exception	E_URL_CHANGED		The URL has changed.The redirect URL is returned through pResponse parameter.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks	The E_NOT_JOINED exception occurs when the domain certificate is required and 
	 *           the client has not joined the domain server.
	 */
	virtual void OnDrmServiceLicenseReceived(DrmService &src, RequestId reqId, result r, const Osp::Base::String* pErrorMsg, const Osp::Base::String* pResponse ) = 0;

	/**
	 * Called when the result of the domain join request is received.
	 *	@since	2.0
	 *
	 * @param[in]	src						The instance of %DrmService that sent this event
	 * @param[in]	reqId					The request ID that is returned to DrmService::JoinDomain()
	 * @param[in]	r						The result of the request
	 * @param[in]	pErrorMsg				The error message sent by the DRM service provider
	 * @param[in]	pResponse				The response data sent by the DRM service provider
	 * @exception	E_SUCCESS				The request is successful.
	 * @exception	E_INVALID_DOMAIN		The domain server is invalid.
	 * @exception	E_CONNECTION_FAILED 	The network connection has failed.
	 * @exception	E_OPERATION_FAILED		The requested operation has failed.
	 * @exception	E_URL_CHANGED		The URL has changed. The redirect URL is returned through pResponse parameter.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual void OnDrmServiceJoinedDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse ) = 0;

	/**
	 * Called when the result of the domain leave request is received.
	 *	@since	2.0
	 *
	 * @param[in]	src						The instance of %DrmService that sent this event
	 * @param[in]	reqId					The request ID that is returned to DrmService::LeaveDomain()
	 * @param[in]	r						The result of the request
	 * @param[in]	pErrorMsg				The error message sent by the DRM service provider
	 * @param[in]	pResponse				The response data sent by the DRM service provider
	 * @exception	E_SUCCESS				The request is successful.
	 * @exception	E_INVALID_DOMAIN		The domain server is invalid.
	 * @exception	E_CONNECTION_FAILED 	The network connection has failed.
	 * @exception	E_OPERATION_FAILED		The requested operation has failed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual void OnDrmServiceLeftDomain(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse ) = 0;

	/**
	 * Called when the result of the metering information is sent.
	 *	@since	2.0
	 *
	 * @param[in]	src						The instance of DrmService that sent this event
	 * @param[in]	reqId					The request ID that is returned to DrmService::SendMeteringInfo()
	 * @param[in]	r						The result of the request
	 * @param[in]	pErrorMsg				The error message sent by the DRM service provider
	 * @param[in]	pResponse				The response data sent by the DRM service provider
	 * @exception	E_SUCCESS				The request is successful.
	 * @exception	E_INVALID_DOMAIN		The domain server is invalid.
	 * @exception	E_CONNECTION_FAILED 	The network connection has failed.
	 * @exception	E_OPERATION_FAILED		The requested operation has failed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual void OnDrmServiceMeteringInfoSent(DrmService &src, RequestId reqId, result r, const Osp::Base::String *pErrorMsg, const Osp::Base::String *pResponse ) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
	virtual void IDrmServiceEventListener_Reserved01(void) {}
	
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
	virtual void IDrmServiceEventListener_Reserved02(void) {}
	
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
	virtual void IDrmServiceEventListener_Reserved03(void) {}
	
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
	virtual void IDrmServiceEventListener_Reserved04(void) {}
};

}; };


#endif
