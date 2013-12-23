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
 * @file		FLocIRouteServiceProvider.h
 * @brief		This is the header file for the IRouteServiceProvider interface.
 *
 * This header file contains the declarations of the IRouteServiceProvider interface.
 */

#ifndef _FLOC_IROUTE_SERVICE_PROVIDER_H_
#define _FLOC_IROUTE_SERVICE_PROVIDER_H_

#include "FLocationConfig.h"
#include "FLocIServiceProvider.h"
#include "FBaseTypes.h"

namespace Osp { namespace Base { namespace Collection { class IList; }; }; };


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class RouteServicePreferences;
class IRouteServiceListener;

/**
 * @interface	IRouteServiceProvider
 * @brief		This interface encapsulates the services offered by the route service providers.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IRouteServiceProvider interface encapsulates the services offered by the route service providers. Through this interface applications request route related services from the route service provider. 
 * An application can set preferences for the route service provider by using the @ref RouteServicePreferences class. 
 * The preferences include, for example, the type of the route, the transport mode used to travel the route, and the 
 * areas and features to be avoided when calculating the route. 
 * The preferences are passed in as a parameter to the service requests. Route service providers must follow these preferences. 
 * If the route service providers are unable to follow these preferences, E_LOCATION_SERVICE is thrown in service requests.
 *
 * The state and results of the asynchronous service requests are delivered through the @ref IRouteServiceListener interface callback methods. 
 * In order to receive these results, the application must implement this interface and set the listener in the asynchronous method calls.
 *
 * The %IRouteServiceProvider interface provides a mechanism to request the generation of @ref Route instances. Since generating a route may be an extensive operation, 
 * the route service provider is not required to support the generation of more than one route at a time. 
 *
 * At the lower levels, there may be only one route service provider implementation that handles all the service requests.
 * In this situation the route service provider implementation decides how to handle the possible concurrent service
 * requests. Some implementations may want to queue the requests, whereas another implementation may override the
 * service request, or ask the user what to do.
 */
class _EXPORT_LOCATION_ IRouteServiceProvider 
	:	public Osp::Locations::Services::IServiceProvider
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IRouteServiceProvider(void);

// Operation
public:
	/**
	 * Requests a routing service from a route service provider. @n
	 * The provider may return more than one alternative route.
	 * The coordinates in the first position of the waypoints array are considered the starting point and the last item is considered the
	 * destination for the route. All the other coordinates in the waypoints array are waypoints along the route. The route is
	 * generated through the given waypoints in the given order. Splitting a route into smaller route segments is left to the
	 * route service provider. 
	 *
	 * The waypoints array must always contain at least two points, the starting point and the destination point. 
	 * If an application wants to get a route from the current location to some destination, the application has to fetch the 
	 * current location itself. 
	 * Possible types of waypoint can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using
	 * @ref ProviderCapabilities::ROUTE_SUPPORTED_WAYPOINT_TYPES as the property key.
	 *
	 * If the distance from the specified starting and destination points is too far and the specified zoom level is too detailed, responses 
	 * from service providers may be too large to be processed correctly. The response may be too large even if the number of specified waypoints @n
	 * is too high and/or the waypoints are far from one another. @n
	 * Applications need to manages these issues accordingly.
	 *
	 * This asynchronous method returns the request ID immediately. The results of the asynchronous requests 
	 * are delivered to the application through @ref IRouteServiceListener::OnRouteReceivedN() interface callback method.
	 * In order to receive these results, the application must implement that interface and set the listener in the asynchronous method calls.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                For more information, see @ref CompGetRoute "here".
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	waypoints		The list of waypoint through which a route is generated
	 * @param[in]	pPreferences	The preferences for the route service request, @n
									else @c null to use the provider default preferences
	 * @param[in]	listener		The event listener
	 * @param[out]	requestId		The ID of the request sent to the server
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c waypoints contains less than 2 elements.
	 * @exception	E_INVALID_ARG The specified @c waypoints contains an incompatible element.
	 * @exception	E_INVALID_ARG The specified @c waypoints contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pPreferences are not valid for this service provider.
	 * @exception	E_INVALID_ARG The specified @c pPreferences are set incorrectly.
	 * @exception	E_OUT_OF_MEMORY Insufficient memory.
	 * @exception	E_LOCATION_SERVICE The service provider cannot serve the request or does not support route generation.
	 * @exception	E_SYSTEM A system error occurred.  
	 * @exception	E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @see			CancelRequest()
	 */
	virtual result GetRoute(const Osp::Base::Collection::IList& waypoints, 
		const RouteServicePreferences* pPreferences, 
		const IRouteServiceListener& listener, RequestId& requestId) = 0;

	/**
	 * @page		CompGetRoute Compatibility for GetRoute()
	 *
	 * @section	CompGetRouteIssues Issues
	 *         	Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *        	-# The preferred transport modes for deCarta Route Services is handled incorrectly.
	 *         	Regardless of the specified preferences, the route returned from the provider is always for vehicles.
	 *
	 * @section	CompGetRouteResolutions Resolutions
	 *         	The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above.
	 */


	/**
	 * Requests the route service provider to cancel the request from the GetRoute() method. @n
	 * 
	 * The specified pending service request is aborted on a best effort basis.
	 *
	 * In asynchronous service requests, the application is notified from the cancel request through the 
	 * @ref IRouteServiceListener::OnRouteReceivedN() callback method, which throws the E_OPERATION_CANCELED exception.
	 *	 
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	requestId	The ID of the request to cancel
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c requestId does not exist in the list of pending requests.
	 * @exception	E_OPERATION_FAILED The operation failed.
	 */	
	virtual result CancelRequest(RequestId requestId) = 0;


};	// class IRouteServiceProvider

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IROUTE_SERVICE_PROVIDER_H_
