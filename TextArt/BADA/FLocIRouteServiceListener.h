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
 * @file		FLocIRouteServiceListener.h
 * @brief		This is the header file for the IRouteServiceListener interface.
 *
 * This header file contains the declarations of the IRouteServiceListener interface.
 */

#ifndef _FLOC_IROUTE_SERVICE_LISTENER_H_
#define _FLOC_IROUTE_SERVICE_LISTENER_H_

// include
#include "FLocationConfig.h"
#include "FBaseTypes.h"

// forward declaration
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };
namespace Osp { namespace Base { class String; }; };


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class IRouteServiceProvider;

/**
 * @interface	IRouteServiceListener
 * @brief		This interface provides a callback mechanism for the route service providers to send information
 * about the service request to applications.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IRouteServiceListener interface provides a callback mechanism for the route service providers to send information
 * about the service request to applications.
 * Applications implement this interface and register it in the service request in IRouteServiceProvider
 * to obtain search results from the service provider.
 */
class _EXPORT_LOCATION_ IRouteServiceListener 
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IRouteServiceListener(void);

// Operation
public:

	/**
	 * Called by the route service provider when the requested route has been calculated by the
	 * @ref IRouteServiceProvider::GetRoute() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @param[in]	requestId	The ID of the request sent to the server
	 * @param[in]	provider	The @ref IRouteServiceProvider instance that calculated the requested route
	 * @param[in]	pRoute		The list of calculated routes @n
	 *							If the calculation of alternative routes is not supported by the provider, only one route object is included in the list @n
	 *							@c null, if an error occurs (@ref Route list)
	 * @param[in]	r			The result of the request
	 * @param[in]	errorCode	The error code from the server
	 * @param[in]	errorMsg	The error message from the server
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_LOCATION_SERVICE An error occurred such as loss of network  or location fix.
	 * @exception	E_OPERATION_CANCELED The service request has been canceled by @ref IRouteServiceProvider::CancelRequest() method.
	 * @exception	E_OUT_OF_MEMORY Insufficient memory. @n
	 *				The response route data is too big to be processed. Route geometry usually takes a 
	 *				large memory space in case the distance is too long and zoom level is detailed.
	 * @exception	E_SERVER An error occurred on the server side.
	 * @remark		The passed route List instance and its elements need to be deleted by the application.
	 * @see			@ref IRouteServiceProvider::GetRoute()
	 * @see			@ref Osp::Base::Collection::IList::RemoveAll()
	 *
	 */
	virtual void OnRouteReceivedN (RequestId requestId, const IRouteServiceProvider& provider,
		Osp::Base::Collection::IList* pRoute, result r,
		const Osp::Base::String& errorCode,	const Osp::Base::String& errorMsg) = 0;


};	// class IRouteServiceListener

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IROUTE_SERVICE_LISTENER_H_
