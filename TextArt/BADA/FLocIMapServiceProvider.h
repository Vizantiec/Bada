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
 *
 * @file	FLocIMapServiceProvider.h
 * @brief	This is the header file for the %IMapServiceProvider interface.
 *
 * This header file contains the declarations of the %IMapServiceProvider interface.
 *
 */

#ifndef _FLOC_IMAP_SERVICE_PROVIDER_H_
#define _FLOC_IMAP_SERVICE_PROVIDER_H_

#include "FLocationConfig.h"
#include "FLocIServiceProvider.h"

// Forward declaration
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };
namespace Osp { namespace Locations { class RectangleGeographicArea; }; };

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class IMaps;
class IMapServiceListener;

/**
 * @interface	IMapServiceProvider
 * @brief		This interface collects the services that the map providers offer.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IMapServiceProvider interface collects the services that the map providers offer.
 * Through this interface, the applications request map-related services from the map service provider.
 *
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/map_service.htm">Map Service</a>.
 * 
 */
class _EXPORT_LOCATION_ IMapServiceProvider 
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
	virtual ~IMapServiceProvider(void);

// Operation
public:
	/** 
	 *
	 * Requests an IMaps instance from a map service provider. @n
	 * An application may specify the geographic areas, landmarks, coordinates objects, and the routes that are included in the generated %IMaps object. This 
	 * means that the specified items are rendered on the generated map. An application may request only one of these items or any combination of them. An 
	 * application cannot modify the items included in the map. @n
	 *
	 * This is a synchronous method and it blocks until the map image generation is ready.
    * @deprecated	This method is deprecated because Osp::Locations::Control::Map class provides the same functionalities in a more effective way. @n
	 *				Instead of using this method, use the Osp::Locations::Controls::Map class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An %IMaps instance, @n
	 *				else @c null if the map service provider is not able to generate the map according to the input parameters
	 * @param[in]	pInitialViewport	The initial area visible from the map @n
	 *									This parameter can contain a @c null value.
	 * @param[in]	pAreas				The geographic areas to be rendered on the map (@ref GeographicArea list) @n
	 *									This parameter can contain a @c null value.
	 * @param[in]	pLandmarks			The landmarks to be rendered on the map (@ref Landmark list) @n
	 *									This parameter can contain a @c null value.
	 * @param[in]	pCoordinatesList	The coordinates objects to be rendered on the map (@ref Coordinates list) @n
	 *									This parameter can contain a @c null value.
	 * @param[in]	pRoutes				The routes to be rendered on the map (@ref Route list) @n
	 *									This parameter can contain a @c null value.
 	 * @param[in]	width				The width of the area where the map is to be rendered in pixels
     * @param[in]	height				The height of the area where the map is to be rendered in pixels
	 * @param[in]	listener			A reference to IMapServiceListener
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c width or @c height is less than or equal to @c 0.
	 * @exception	E_INVALID_ARG 		The provider does not support the specified geographic area overlays (@c pAreas). @n
	 *									Check ProviderCapabilities::MAP_SUPPORTS_GEOGRAPHIC_AREA_OVERLAYS.
	 * @exception	E_INVALID_ARG 		The provider does not support the specified landmark overlays (@c pLandmarks). @n
	 *									Check ProviderCapabilities::MAP_SUPPORTS_LANDMARK_OVERLAYS.
	 * @exception	E_INVALID_ARG 		The provider does not support the specified coordinates overlays (@c pCoordinateList). @n
	 *									Check ProviderCapabilities::MAP_SUPPORTS_COORDINATES_OVERLAYS.
	 * @exception	E_INVALID_ARG 		The provider does not support the specified route overlays (@c pRoutes). @n
	 *									Check ProviderCapabilities::MAP_SUPPORTS_ROUTE_OVERLAYS.
	 * @exception	E_LOCATION_SERVICE 	The service provider cannot serve the request.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception   E_SYSTEM  			A system error has occurred.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		Some service providers may not support the generation of %IMaps objects with areas, landmarks, coordinates objects or routes.
	 * 				The support can be queried with key @ref ProviderCapabilities::MAP_SUPPORTS_GEOGRAPHIC_AREA_OVERLAYS, 
	 * 				@ref ProviderCapabilities::MAP_SUPPORTS_LANDMARK_OVERLAYS, @ref ProviderCapabilities::MAP_SUPPORTS_COORDINATES_OVERLAYS or
	 * 				@ref ProviderCapabilities::MAP_SUPPORTS_ROUTE_OVERLAYS from the @ref ProviderCapabilities::GetPropertyValue() method. If the generation 
	 *				of @ref IMaps objects with a given overlay is not supported, this method throws E_INVALID_ARG.
	 * @remarks		Do not delete @c pAreas, @c pLandmarks, @c pCoordinatesList, or @c pRoute before deleting the %IMaps instance created by this method call.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IMaps* GetMapN(const RectangleGeographicArea* pInitialViewport,
		const Osp::Base::Collection::IList* pAreas,
		const Osp::Base::Collection::IList* pLandmarks,
		const Osp::Base::Collection::IList* pCoordinatesList,
		const Osp::Base::Collection::IList* pRoutes,
		int width, int height, const IMapServiceListener& listener) = 0;

	/**
	 * Gets an %IMaps instance without any items rendered on the map. @n
	 *
	 * The initial geographic area that is visible from the %IMaps instance is defined with the @c pInitialViewport parameter. This part of the map is 
	 * rendered when calling the IMaps::RenderMap method. If an application does not set the initial viewport, it is defined by the map service provider. The 
	 * width and height parameters define the size of the area where the generated map is later rendered by the application. The size is defined in pixels. 
	 *
	 * This is a synchronous method and it blocks until the map image generation has been ready.
	 *
     * @deprecated	This method is deprecated because the Osp::Locations::Controls::Map class provides the same functionalities in a more effective way. @n
	 *				Instead of using this method, use the Osp::Locations::Controls::Map class.
     *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An IMap instance, @n
	 *				else @c null if the map service provider is not able to generate the map with the input parameters
	 * @param[in]	pInitialViewport	The initial area visible from the map, @n
	 *									This parameter can contain a @c null value.
 	 * @param[in]	width				The width of the area where the map is to be rendered in pixels
     * @param[in]	height				The height of the area where the map is to be rendered in pixels
	 * @param[in]	listener			A reference to IMapServiceListener
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c width or @c height is less than or equal to @c 0.
	 * @exception	E_LOCATION_SERVICE 	The service provider cannot serve the request.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception   E_SYSTEM  			A system error has occurred.  
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IMaps* GetMapN(const RectangleGeographicArea* pInitialViewport,
		int width, int height, const IMapServiceListener& listener) = 0;

};	// class IMapServiceProvider

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IMAP_SERVICE_PROVIDER_H_
