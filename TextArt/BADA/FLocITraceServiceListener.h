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
 * @file	FLocITraceServiceListener.h 
 * @brief	This is the header file for the %ITraceServiceListener interface.
 *
 * This header file contains the declarations of the %ITraceServiceListener interface.
 */

#ifndef _FLOC_ITRACE_SERVICE_LISTENER_H_
#define _FLOC_ITRACE_SERVICE_LISTENER_H_

#include "FLocationConfig.h"

namespace Osp { namespace Locations { 

/**
* @interface	ITraceServiceListener
* @brief		This interface provides a listener that receives the events associated with the trace service.		
* @deprecated   This interface is deprecated due to the operation policy of the bada Server.
* @since 		1.0
*
* The %ITraceServiceListener interface provides a listener that receives the events associated with the trace service.
*
*/
class _EXPORT_LOCATION_ ITraceServiceListener 
{
// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
     * @deprecated   This method is deprecated due to the operation policy of the bada Server.
     * @since	1.0
     */
	virtual ~ITraceServiceListener(void) {}


// Operations
public:
	/**
	* Called to notify when the subscription to the trace service is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	serviceId				The service ID subscribed
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	*										The error code and message sent from the server were offered.
	*/
	virtual void OnTraceServiceSubscribed(RequestId reqId, const Osp::Base::String& serviceId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

   /**
	* Called to notify when the request for the service information is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pServiceInfo			The service ID subscribed
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED  		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	*										The error code and message sent from the server were offered.
	*/
	virtual void OnTraceServiceReceived(RequestId reqId,  TraceServiceInfo* pServiceInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

   /**
	* Called to notify when the request for the service information is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pTraceServiceInfoList	The list of TraceServiceInfo subscribed for the given target
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	*										The error code and message sent from the server were offered.
	* @remarks		The application must delete the result list.
	*/
	virtual void OnTraceServiceListReceivedN(RequestId reqId, Osp::Base::Collection::IList *pTraceServiceInfoList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

   /**
	* Called to notify when the termination of the trace service is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	* 				  						The error code and message sent from the server were offered. 
	*/
	virtual void OnTraceServiceUnsubscribed (RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	
   /**
	* Called to notify when the request to deactivate the trace service is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	* 				  						The error code and message sent from the server were offered. 
	*/
	virtual void OnTracingStoped(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the request to reactivate the trace service is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED  		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	* 				  						The error code and message sent from the server were offered. 
	*/
	virtual void OnTracingResumed(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
	
	/**
	* Called to notify when the request for accumulated device location is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId						The request ID
	* @param[in]	pTagetDeviceLocationList	The list of device locations accumulated for the given target
	* @param[in]	r							The result for the request @n
	*											The result can be one of the exception codes listed below.
	* @param[in]	errorCode					The error code
	* @param[in]	errorMsg					The error message
	* @exception	E_SUCCESS 					The method is successful.
	* @exception	E_PARSING_FAILED			The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED			The network connection has failed.
	* @exception	E_OPERATION_CANCELED 		The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER					The request to the server has failed. @n
	* 				  							The error code and message sent from the server were offered. 
	* @remarks		The application must delete the result list.
	*/
	virtual void OnTraceDataReceivedN(RequestId reqId, Osp::Base::Collection::IList *pTagetDeviceLocationList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the request for deleting the accumulated device location is completed.
	* 
    * @deprecated   This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result for the request @n
	*										The result can be one of the exception codes listed below.
	* @param[in]	errorCode				The error code
	* @param[in]	errorMsg				The error message
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @exception	E_NETWORK_FAILED 		The network connection has failed.
	* @exception	E_OPERATION_CANCELED 	The service request has been canceled by the @ref Osp::Locations::RemoteLocationProvider::CancelRequest() method.
	* @exception	E_SERVER				The request to the server has failed. @n
	* 				  						The error code and message sent from the server were offered. 
	*/
	virtual void OnTraceDataDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
};		// class ITraceServiceListener

};};	// Osp::Locations


#endif // _FLOC_ITRACE_SERVICE_LISTENER_H_
