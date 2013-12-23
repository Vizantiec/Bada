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
 * @file		FLocations.h 
 * @brief		This is the header file for the %Locations namespace.
 *
 * This header file contains the declarations of the %Locations namespace.
 *
 */
#ifndef _FLOCATIONS_H_
#define _FLOCATIONS_H_

// Includes
#include "FLocCircleGeographicArea.h"
#include "FLocRectangleGeographicArea.h"
#include "FLocPolygonGeographicArea.h"
#include "FLocAddressInfo.h"
#include "FLocLandmark.h"
#include "FLocLandmarkFilter.h"
#include "FLocLandmarkPropertySelector.h"
#include "FLocLocation.h"
#include "FLocCoordinates.h"
#include "FLocQualifiedCoordinates.h"

#include "FLocLandmarkStore.h"
#include "FLocILandmarkSearchListener.h"

#include "FLocLocationProvider.h"
#include "FLocIAreaListener.h"
#include "FLocILocationListener.h"

#include "FLocRemoteLocationProvider.h"
#include "FLocIRemoteLocationListener.h"
#include "FLocITraceServiceListener.h"
#include "FLocILocationReportListener.h"
#include "FLocServiceInfo.h"

#include "FLocRemoteLandmarkStore.h"
#include "FLocIRemoteLandmarkStoreListener.h"

// Services
#include "FLocGeocodingServicePreferences.h"
#include "FLocIGeocodingServiceListener.h"
#include "FLocIGeocodingServiceProvider.h"
#include "FLocIMapServiceListener.h"
#include "FLocIMapServiceProvider.h"
#include "FLocIMap.h"
#include "FLocMapServicePreferences.h"
#include "FLocProviderCapabilities.h"
#include "FLocProviderManager.h"


#include "FLocRoute.h"
#include "FLocRouteSegment.h"
#include "FLocRouteServicePreferences.h"
#include "FLocIRouteServiceProvider.h"
#include "FLocIRouteServiceListener.h"

#include "FLocDirectoryFilter.h"
#include "FLocDirectoryServicePreferences.h"
#include "FLocIDirectoryServiceProvider.h"
#include "FLocIDirectoryServiceListener.h"

// Map controls
#include "FLocCtrlMap.h"
#include "FLocCtrlIMapEventListener.h"
#include "FLocCtrlIMapInfoWindowEventListener.h"
#include "FLocCtrlIMapOverlayEventListener.h"
#include "FLocCtrlMapOverlayCircle.h"
#include "FLocCtrlMapOverlayMarker.h"
#include "FLocCtrlMapOverlayPolygon.h"
#include "FLocCtrlMapOverlayPolyline.h"
#include "FLocCtrlMapOverlayRectangle.h"
#include "FLocCtrlNativeMapInfoWindow.h"


/**
 * @namespace	Osp::Locations
 * @brief		This namespace contains the classes and interfaces for the location-related information and services.
 * @deprecated	This namespace is deprecated.
 * @since		1.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FLocations.h> @n
 *				@b Library: @b FOsp
 *
 * The %Locations namespace has classes and interfaces for acquiring the positions of local and remote devices. It provides useful functionalities, such as 
 * area (zone) monitoring, location tracing, and triggering. This namespace also has classes and interfaces for creating, storing, and searching for 
 * landmarks on the local device. To provide full support during the Location Based Services (LBS) development, this 
 * namespace contains sub-namespaces that contain the classes and interfaces that provide map services, customization, and interactivity.
 *
 * For more information on the %Locations namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/locations_namespace.htm">Locations Guide</a>.
 * 
 * The following diagram illustrates the relationships between the classes and sub-namespaces belonging to the %Locations namespace.
 * @image	html location_locations_using_the_apis_classdiagram.png
 *
 */

namespace Osp { namespace Locations {
}; }; // Osp::Locations



/**
 * @namespace	Osp::Locations::Controls
 * @brief		This namespace contains the classes and interfaces for map-based services.
 * @deprecated	This namespace is deprecated.
 * @since		1.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FLocations.h> @n
 *				@b Library: @b FOsp
 *
 * The %Locations::Controls namespace contains the classes and interfaces to allow the users to control the map more easily. The maps can be rendered in layers. Also  
 * overlays and InfoWindows can be handled, "My Location" displayed, and user input can be managed on the map.
 *
 * For more information on the Locations::Controls namespace, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/map_controls.htm">Map Controls</a>.
 * 
 * The following diagram illustrates the relationships between the classes belonging to the %Locations::Controls namespace.
 * @image html location_locationcontrols_using_the_apis_classdiagram.png
 */

namespace Osp { namespace Locations { namespace Controls {
}; }; }; // Osp::Locations::Controls


/**
 * @namespace	Osp::Locations::Services
 * @brief		This namespace contains the classes and interfaces for location-based services.
 * @deprecated	This namespace is deprecated.
 * @since		1.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FLocations.h> @n
 *				@b Library: @b FOsp
 *
 * 
 * The %Services namespace contains the classes and interfaces that provide the geographic information services, such as map service, geocoding service, 
 * route service, and directory service.
 *
 * The behavior of the location services APIs may be different according to the service provider.
 * For more information on the Locations::Services features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/locations_namespace.htm">Locations Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Locations::Services namespace.
 * @image html location_locationservices_using_the_apis_classdiagram.png
 */

namespace Osp { namespace Locations { namespace Services {
}; }; }; // Osp::Locations::Services

#endif // _FLOCATIONS_H_


