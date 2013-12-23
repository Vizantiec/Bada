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
 * @file	FLocProviderCapabilities.h
 * @brief	This is the header file for the %ProviderCapabilities class.
 *
 * This header file contains the declarations of the %ProviderCapabilities class.
 *
 */

#ifndef _FLOC_PROVIDER_CAPABILITIES_H_
#define _FLOC_PROVIDER_CAPABILITIES_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FLclLocale.h"

// Forward declaration
struct MProviderCapabilities;
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };
namespace Osp { namespace Base { namespace Collection {class HashMap; }; }; };
namespace Osp { namespace Locations { class RectangleGeographicArea; }; };

namespace Osp { namespace Locations { namespace Services {

/** 
 * @enum	LocationServiceProviderType
 * Defines type constants of the service provider.
 *
 * @deprecated	This enumerated type is deprecated.
 * @since	1.0
 */
typedef enum {
	/** The %Service provider type for map services. */
	LOC_SVC_PROVIDER_TYPE_MAP,
	/** The %Service provider type for route services. */
	LOC_SVC_PROVIDER_TYPE_ROUTE,
	/** The %Service provider type for geocoding and reverse geocoding services. */
	LOC_SVC_PROVIDER_TYPE_GEOCODING,
	/** The %Service provider type for directory services. */
	LOC_SVC_PROVIDER_TYPE_DIRECTORY
} LocationServiceProviderType;

/**
 * @class	ProviderCapabilities
 * @brief	This class collects the information about the capabilities of a service provider.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * 	The %ProviderCapabilities class collects the information about the capabilities of a service provider, including:
 * 			- Type and name of the service
 * 			- Information about the capabilities of the service provider @n
 *
 * With the information available, an application is able to decide which service provider to use when requesting services.
 * 
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/locations_namespace.htm">Locations Guide</a>.
 */
class _EXPORT_LOCATION_ ProviderCapabilities 
	:	public Osp::Base::Object
{
// constant string
public:
/**
 * The property key value for an application to check whether the service provider supports a geocoding service. The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String GEO_SUPPORTS_GEOCODING;

/**
 * The property key value for an application to check whether the service provider supports a reverse geocoding service. The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String GEO_SUPPORTS_REVERSE_GEOCODING;

/**
 * The property key value for an application to represent the countries that a geocoding service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of string objects that contains supported countries and the country
 * codes as defined in ISO-3166. @n
 * A service provider must have one default country. @n
 * The default country must be set as the first item in the list of supported countries.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 * @remarks This value can be an empty list. It means that the supported countries are not determined. All the country codes defined are in the ISO ISO-3166 
 *			format and are acceptable to the service preferences. But the response of the requested service returns an error if the service provider does not 
 *			support the specified country. If this value is an empty list, the default country code of the service preferences is set to the country code of 
 *			the current locale.
 */
	static const Osp::Base::String GEO_SUPPORTED_COUNTRIES;

/**
 * The constant to indicate that the map service provider supports continuous map rotation. With continuous 
 * rotation, the map can be rotated to any azimuth value.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_CONTINUOUS_ROTATION;

/**
 * The constant to indicate that the map service provider supports the map rotation to discrete azimuth values. The
 * azimuth values that the map can be rotated to can be retrieved with the property key
 * @ref MAP_SUPPORTED_ROTATION_AZIMUTHS.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_DISCRETE_ROTATION;

/**
 * The constant to indicate that the map service provider does not support map rotation.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_NO_ROTATION;

/**
 * The property key value for an application to retrieve the azimuth values a map service provider supports during rotation. The azimuth values are specified 
 * in degrees with respect to true north. The value of this property is a (@ref Osp::Base::Integer) list of supported azimuths as Integer types. The azimuths 
 * must be specified in ascending order. If the rotation is not supported (@ref MAP_NO_ROTATION) or it is a continuous (@ref MAP_CONTINUOUS_ROTATION) one,
 * the value of this property must be an empty list.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTED_ROTATION_AZIMUTHS;

/**
 * The property key value for an application to check whether the map service provider is able to rotate maps. @n
 * This applies to the Map objects. The value of this property is a string. The possible values @ref MAP_NO_ROTATION, @ref MAP_CONTINUOUS_ROTATION, and 
 * @ref MAP_DISCRETE_ROTATION are defined in this class. If discrete rotation is supported, the possible azimuth values can be retrieved using the
 * @ref MAP_SUPPORTED_ROTATION_AZIMUTHS property key.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_MAP_ROTATION;

/**
 * The property key value for an application to retrieve the map projection that the map service provider uses. @n
 * The value of this property is a (@ref Osp::Base::String) string that contains the name of the projection as defined in the EPSG Geodetic Parameter Dataset 
 * (see reference [EPSG]).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_PROJECTION;

/**
 * The property key value for an application to retrieve the map layers that the map service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of supported map layers represented as strings. These layers may be streets, 
 * highways, public transportation lines, water areas, parks, buildings, sidewalks, or administrative areas. These layers correspond to the layers used in 
 * the OpenLS specification (see reference [OpenLS]). The layers included in this property must be supported on top of all the supported map bases.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTED_LAYERS;

/**
 * The property key value for an application to retrieve the map bases that the map service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported map bases. A map base can be 
 * regular map, satellite image, aerial image, terrain map, or only latitude and longitude grid. The map service provider must support at least one map base.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTED_MAP_BASES;

/**
 * The property key value for an application to check whether the map service provider supports generating the map objects with a transparent background. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_TRANSPARENT_BACKGROUND;

/**
 * The property key value for an application to check whether the map service provider supports generating the map objects with the landmark overlays. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_LANDMARK_OVERLAYS;

/**
 * The property key value for an application to check whether the map service provider supports generating the map objects with the geographic area overlays. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_GEOGRAPHIC_AREA_OVERLAYS;

/**
 * The property key value for an application to check whether the map service provider supports generating the map objects with coordinates overlays. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_COORDINATES_OVERLAYS;

/**
 * The property key value for an application to check whether the map service provider supports generating the map objects with the route overlays. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String MAP_SUPPORTS_ROUTE_OVERLAYS;

/**
 * The property key value for an application to check whether the map service provider is able to create the @ref IMaps objects. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	2.0
 */
	static const Osp::Base::String MAP_SUPPORTS_MAP_CREATION;

/**
 * The property key value for an application to check whether the map service provider supports continuous zoom. @n 
 * The value of this property is boolean (@ref Osp::Base::Boolean). If this value is @c false, only integer values are available for the zoom level.
 *
 * @deprecated	This constant is deprecated.
 * @since 2.0
 */
	static const Osp::Base::String MAP_SUPPORTS_CONTINUOUS_ZOOM;

// Route related capabilities

/**
 * The property key value for an application to retrieve the features that could be avoided in the route that the service provider supports. @n
 * For example, toll ways and bridges. The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of 
 * features to be avoided. If the route service provider does not support any features to be avoided, an empty list must be used as the value of this 
 * property. @n
 * The features to be avoided can be displayed to the user. The service provider must support the names of the features in all the languages that it 
 * supports. Some route service providers may be able to determine whether traveling routes with different transport modes generate costs to the user.
 * A cost may be a toll road or bridge fee. If the route service providers are able to determine the cost, they should define the cost as one of
 * the avoidable features. This way an application may request routes that do not generate any costs to the user.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 *
 */
	static const Osp::Base::String ROUTE_SUPPORTED_FEATURES_TO_AVOID;

/**
 * The property key value for an application to retrieve the types of areas that could be avoided that the route service provider supports. @n
 * The value of this property is a list of @ref GeographicArea based types. If the route service provider does not support any area types to be avoided, an 
 * empty list must be used as the value of this property.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 *
 */
	static const Osp::Base::String ROUTE_SUPPORTED_AREA_TYPE_TO_AVOID;

/**
 * The property key value for an application to retrieve the route types that the route service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported route types. Some of the 
 * basic route types are defined as constants in the RouteServicePreferences class, and they start with the prefix "ROUTE_". If a service provider supports 
 * other route types than those listed in %RouteServicePreferences, they are also included into the returned list. The route service provider must support
 * at least one route type.
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 *
 */
	static const Osp::Base::String ROUTE_SUPPORTED_ROUTE_TYPES;

/**
 * The property key value for an application to retrieve the transport modes that the route service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of the supported transport modes. Some of 
 * the basic transport modes are defined as constants in the %RouteServicePreferences class, and they start with the prefix "TRANSPORT_". If a service
 * provider supports other transport modes than those listed in %RouteServicePreferences, they are also included into the returned list. The route service 
 * provider must support at least one transport mode.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTED_TRANSPORT_MODES;

/**
 * The property key value for an application to retrieve the waypoint types that the route service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported waypoint types. The route 
 * service provider must support at least one waypoint type.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTED_WAYPOINT_TYPES;

/**
 * The property key value for an application to retrieve the types of instruction formats supported by the route service provider. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported instruction formats. 
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTED_INSTRUCTION_FORMAT;

/**
 * The property key value for an application to check whether the route service provider supports a list of freeform addresses to be avoided. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_FREEFORM_ADDR_TO_AVOID;

/**
 * The property key value for an application to check whether the route service provider supports a list of structured addresses to be avoided. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_STRUCTURED_ADDR_TO_AVOID;

/**
 * The property key value for an application to check whether the route service provider supports the retrieval of the route instructions. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_INSTRUCTION_RETRIEVAL;

/**
 * The property key value for an application to check whether the route service provider supports the retrieval of the route instruction geometry. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_INSTRUCTION_GEOMETRY;

/**
 * The property key value for an application to check whether the route service provider supports the retrieval of the route instruction bounding box. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_INSTRUCTION_BOUNDING_BOX;

/**
 * The property key value for an application to check whether the route service provider supports the retrieval of the route geometry. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_GEOMETRY_RETRIEVAL;

/**
 * The property key value for an application to check whether the route service provider supports the specification of the route bounding box. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_GEOMETRY_BOUNDING_BOX;

/**
 * The property key value for an application to check whether the route service provider supports the usage of the real-time traffic data. 
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 1.0
 */
	static const Osp::Base::String ROUTE_SUPPORTS_REALTIME_TRAFFIC;


/**
 * The property key value for an application to retrieve the filter names supported by the service provider for the search. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported filters. Some of the basic 
 * search filters are defined as constants in DirectoryFilter, and they start with the prefix "SEARCH_FILTER_". If a service provider supports other search 
 * filters than those listed in the %DirectoryFilter class, they are also included in the returned list. 
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String DIR_SUPPORTED_SEARCH_FILTERS;

/**
 * The property key value for an application to check whether the directory service provider supports a circular geographic area as the local filter for the 
 * search request. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_CIRCLE_GEOGRAPHIC_AREA;

/**
 * The property key value for an application to check whether the directory service provider supports a rectangular geographic area as the local filter for 
 * the search request. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_RECTANGLE_GEOGRAPHIC_AREA;

/**
 * The property key value for an application to check whether the directory service provider supports a polygonal geographic area as the local filter for the 
 * search request. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_POLYGON_GEOGRAPHIC_AREA;

/**
 * The property key value for an application to check whether the directory service provider supports a structured address as the local filter for the search 
 * request. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_ADDRESS;

/**
 * The property key value for an application to check whether the directory service provider supports a freeform address as the local filter for the search 
 * request. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_FREEFORM_ADDRESS;

/**
 * The property key value for an application to check whether the directory service provider supports sorting. @n
 * The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String DIR_SUPPORTS_SORT;

/**
 * The property key value for an application to retrieve the criterion values that the directory service provider supports for sorting. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported sorting criteria. The 
 * criteria can be a name, category, or distance. @n
 * If sorting is not supported, the value of this property must be an empty array.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String DIR_SUPPORTED_SORT_CRITERIONS;

/**
 * The property key value for an application to retrieve the languages the service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains the supported languages. The language tags are 
 * defined in the ISO 639-2 format. A service provider must have one default language. The default language must be set as the first item in the list of 
 * supported languages.
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 * @remarks	This value can be an empty list. It means that the supported languages are not determined. @n
 *			All the language tags are defined in the ISO 639-2 format and are acceptable in the service preferences. But the response of the requested 
 * 			service returns an error, if the service provider does not support the specified language. If this value is an empty list, the default language 
 * 			tag of the service preferences is set to the language of the current locale.
 *
 */
	static const Osp::Base::String SUPPORTED_LANGUAGES;

/**
 * The property key value for an application to retrieve the length units that the service provider supports. @n
 * The value of this property is a (@ref Osp::Base::Collection::ArrayList) list of String type that contains a list of supported length units. The possible 
 * unit values are "METRIC", "IMPERIAL", and "NAUTICAL". In the metric system the length unit is a meter, in the imperial system, a yard, and in the nautical 
 * system, a nautical mile. The service provider must support at least one length unit.
 *
 * @deprecated	This constant is deprecated.
 * @since 	1.0
 */
	static const Osp::Base::String SUPPORTED_LENGTH_UNITS;

/**
 * The property key value for an application to check whether the service provider uses the network when performing the service request. @n
 * Network access may be needed if a route service provider does the route calculation on a remote server using a data connection. The use of a network may 
 * generate a financial cost to the user. The value of this property is boolean (@ref Osp::Base::Boolean).
 *
 * @deprecated	This constant is deprecated.
 * @since	1.0
 */
	static const Osp::Base::String USES_NETWORK;

// Lifecycle
private:
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	ProviderCapabilities(const ProviderCapabilities& caps);
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	ProviderCapabilities(void);
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~ProviderCapabilities(void);

private:
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	ProviderCapabilities& operator=(const ProviderCapabilities& caps);

public:

	/**
	 * Gets a list of the property keys that have been set. @n
	 * The actual property value can be retrieved with the @ref GetPropertyValue() method. The service provider must support the general property keys 
	 * (@ref SUPPORTED_LANGUAGES, @ref SUPPORTED_LENGTH_UNITS, and @ref USES_NETWORK), and all the service-specific properties starting with the service 
	 * prefix defined in this class. Additionally, the property keys are included based on the capabilities of the service provider, and they must have the 
	 * values defined.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The key values of the assigned properties (@ref Osp::Base::String list)
	 */
	const Osp::Base::Collection::IList* GetPropertyKeys(void) const;

	/**
	 * Gets the value of the requested property as an Object. @n
	 * The application must cast the returned value into the right object type as defined in the property key description. The property keys are identified 
	 * by the values of the String constants defined in this namespace and are extended by the service provider. It is not necessary for the input parameter 
	 * to be an instance of the String defined by the constant field.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The value of the property, @n
	 *				else @c null if the key is not defined
	 * @param[in]	key	  The identifier of the property
	 */
	const Osp::Base::Object* GetPropertyValue(const Osp::Base::String& key) const;

	/**
	 * Gets the name of the service provider. @n
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The name of the service provider
	 */
	Osp::Base::String GetServiceProviderName(void) const;

	/**
	 * Gets the service type of this instance. @n
	 * One instance of the %ProviderCapabilities class collects the capabilities of one service type. The types are defined as constants in the 
	 * %LocationServiceProviderType enum class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The service type of the service provider capabilities
	 * @see		LocationServiceProviderType
	 */
	LocationServiceProviderType GetServiceProviderType(void) const;

// Attributes
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * MProviderCapabilities instance
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	MProviderCapabilities*	__pProviderCaps;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Properties of provider capabilities
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::HashMap* __pProperties;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Keys of provider capabilities. This is a list of the reference pointers of the key string.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList* __pKeys;

private:
	friend class ProviderCapabilitiesEx;
	class ProviderCapabilitiesEx* __pProviderCapabilitiesEx;

};	// class ProviderCapabilities

}; }; };	// Osp::Locations::Services

#endif // _FLOC_PROVIDER_CAPABILITIES_H_
