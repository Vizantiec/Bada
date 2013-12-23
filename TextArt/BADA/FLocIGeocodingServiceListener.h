/* $Change: 1267243 $ */
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
 * @file	FLocIGeocodingServiceListener.h
 * @brief	This is the header file for the %IGeocodingServiceListener interface.
 *
 * This header file contains declarations of the %IGeocodingServiceListener interface.
 *
 */

#ifndef _FLOC_IGEOCODING_SERVICE_LISTENER_H_
#define _FLOC_IGEOCODING_SERVICE_LISTENER_H_

#include "FLocationConfig.h"
#include "FBaseTypes.h"

// Forward declaration
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class IGeocodingServiceProvider;

/**
 * @interface	IGeocodingServiceListener
 * @brief		This interface provides a callback mechanism for the geocoding service providers to send information about the service request to the 
 *				applications.
 * @deprecated	This interface is deprecated.
 * @since 		1.0
 *
 *	The %IGeocodingServiceListener interface provides a callback mechanism for the geocoding service providers to send information about the service request to the 
 *				applications. Applications implement this interface and register it in a service request to the service provider, represented by 
 *				IGeocodingServiceProvider, to obtain information from it.
 *
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geocoding_service.htm">Geocoding Service</a>. 
 */
class _EXPORT_LOCATION_ IGeocodingServiceListener 
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IGeocodingServiceListener(void);

// Operation
public:
	/** 
	 * Called by the geocoding service provider when the result of the request has been received.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	requestId				The request ID
	 * @param[in]	provider				The provider to whom the request is made
	 * @param[in]	pLandmarks				The list of landmarks as the result, @n
	 *										else @c null if an error has occurred
	 * @param[in]	r						An error code
	 * @param[in]	errorCode				The error code from the server
	 * @param[in]	errorMsg				The error message from the server
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_LOCATION_SERVICE 		An error has occurred, such as loss of network connection or location fix in the service provider that prevents it 
	 *										from finishing the service request.
	 * @exception	E_OPERATION_CANCELED	The service request has been canceled by the @ref IGeocodingServiceProvider::CancelRequest() method.
	 * @exception	E_SERVER 				An error has occurred on the server side.
	 * @remarks 	@c pLandmarks and its elements should be deleted.
	 */
	virtual void OnGeocodingRequestResultReceivedN(RequestId requestId, const IGeocodingServiceProvider& provider,
		Osp::Base::Collection::IList* pLandmarks, result r, const Osp::Base::String& errorCode,
		const Osp::Base::String& errorMsg) = 0;

	/** 
	 * Called by the geocoding service provider when a reverse-geocoding request result has been received.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	requestId				The request ID
	 * @param[in]	provider				The provider to whom the request is made
	 * @param[in]	pLandmarks				The list of landmarks as the result, @n
	 *										else @c null if an error has occurred
	 * @param[in]	r						An error code
	 * @param[in]	errorCode				The error code from the server
	 * @param[in]	errorMsg				The error message from the server
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_LOCATION_SERVICE 		An error has occurred, such as loss of network connection or location fix in the service provider that prevents it 
	 *										from finishing the service request.
	 * @exception	E_OPERATION_CANCELED	The service request has been canceled by the @ref IGeocodingServiceProvider::CancelRequest() method.
	 * @exception	E_SERVER 				An error has occurred on the server side.
	 * @remarks 	@c pLandmarks and its elements should be deleted.
	 *
	 */
	virtual void OnReverseGeocodingRequestResultReceivedN(RequestId requestId, const IGeocodingServiceProvider& provider,
		Osp::Base::Collection::IList* pLandmarks, result r, const Osp::Base::String& errorCode,
		const Osp::Base::String& errorMsg) = 0;

};	// class IGeocodingServiceListener

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IGEOCODING_SERVICE_LISTENER_H_
