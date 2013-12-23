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
 * @file		FLocRouteServicePreferences.h
 * @brief		This is the header file for the RouteServicePreferences class.
 *
 * This header file contains the declarations of the RouteServicePreferences class.
 *
 */

#ifndef _FLOC_ROUTE_SERVICE_PREFERENCES_H_
#define _FLOC_ROUTE_SERVICE_PREFERENCES_H_

// include
#include "FLocationConfig.h"
#include "FLocServicePreferences.h"

// forward declaration
struct MRouteServicePreferences;
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Locations { class RectangleGeographicArea; }; };


namespace Osp { namespace Locations { namespace Services {

/**
 * @class RouteServicePreferences
 * @brief This class is used to capture the preferences related to route service providers.
 * @deprecated	This class is deprecated.
 * @since 1.0
 *
 * The %RouteServicePreferences class captures the preferences related to route service providers.
 * It also encapsulates the preferences that are used when requesting routing services from a service provider.
 * The preferences may include the type of the route, the transport mode used to travel the route, and the areas and
 * features to be avoided when calculating the route.
 *
 * An application retrieves an instance of this class with the IServiceProvider::GetServicePreferencesN() method. The returned instance
 * contains either the default values, or the last used values for all the preferences. An application can check the values with the 
 * Get* methods and it may change these default values with the Set* methods.
 *
 * The API implementation and a route service provider may also add new preferences. The mechanism to define
 * additional preference properties is provided in the ServicePreferences superclass. Property keys for the additional
 * preferences defined by each route service provider can be retrieved with the ServicePreferences::GetAdditionalPropertyKeys() 
 * method.
 */
class _EXPORT_LOCATION_ RouteServicePreferences : public Osp::Locations::Services::ServicePreferences 
{
// constant
public:
	/**
	 * Route type for the fastest route.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String ROUTE_FASTEST;

	/**
	 * Route type for a lower traffic route.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String ROUTE_LEAST_TRAFFIC;

	/**
	 * Route type for a scenic route.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String ROUTE_SCENIC;

	/**
	 * Route type for shortest route.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String ROUTE_SHORTEST;

	/**
	 * A constant for a bicycle transport mode.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String TRANSPORT_BICYCLE;

	/**
	 * A constant for a car transport mode.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String TRANSPORT_CAR;

	/**
	 * A constant for a pedestrian transport mode.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String TRANSPORT_PEDESTRIAN;

	/**
	 * A constant for a public transport mode.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	static const Osp::Base::String TRANSPORT_PUBLIC;

// Lifecycle
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	RouteServicePreferences(void);

public:	
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~RouteServicePreferences(void);


// Operation
public:	


	/**
	 * Checks if the specified instance equals the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		@c true if the objects are equal @n
	 *				@c false, otherwise
	 * @param[in]	obj	 The object to compare with the current instance 
	 */
	virtual bool Equals(const Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An integer value indicating the hash value of the current instance 
	 */
	int GetHashCode(void) const;


	/**
	 * Gets the maximum number of matches set for the route service provider. @n
	 *
	 * The method returns the default value set by the service provider, or value set with the @ref SetMaxMatchesCount() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The maximum number of matches set
	 */
	int GetMaxMatchesCount(void) const;



	/**
	 * Gets a list of geographical areas that should be avoided in route generation. @n
	 *
	 * The returned list contains the default values set by the service provider, or values set with the @ref SetAreasToAvoid() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of the geographical areas to be avoided @n
	 *          @c null, if no areas have been set or if not supported by the provider (@ref GeographicArea list)
	 * 
	 */
	const Osp::Base::Collection::IList* GetAreasToAvoid (void) const;



	/**
	 * Gets a list of features that must be avoided in route generation. @n
	 *
	 * The returned list contains the default values set by the service provider, or the values set with the @ref SetFeaturesToAvoid() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of the features to be avoided @n
	 *          @c null, if no features have been set or if not supported by the provider (@ref Osp::Base::String list)
	 * 
	 */
	const Osp::Base::Collection::IList* GetFeaturesToAvoid (void) const;



	/**
	 * Gets a list of free form addresses that should be avoided in route generation. @n
	 *
	 * The returned list contains the default values set by the service provider, or the values set with the @ref SetFreeformAddressesToAvoid() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of the free form addresses to be avoided @n
	 *          @c null, if no addresses have been set or if not supported by the provider (@ref Osp::Base::String list)
	 * 
	 */
	const Osp::Base::Collection::IList* GetFreeformAddressesToAvoid (void) const;



	/**
	 * Gets a list of structured addresses that should be avoided in route generation. @n
	 *
	 * The returned list contains the default values set by the service provider, or the values set with the @ref SetAddressesToAvoid() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of the structured addresses to be avoided @n
	 *          @c null, if no addresses need to be avoided or if not supported by the provider (@ref AddressInfo list)
	 * 
	 */
	const Osp::Base::Collection::IList* GetAddressesToAvoid  (void) const;
	


	/**
	 * Gets the preferred route type set by the application for route generation. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetRouteType() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The preferred route type @n
	 *			Empty string, if not supported by the service provider
	 */
	Osp::Base::String GetRouteType(void) const;



	/**
	 * Gets the preferred transport mode set by the application for route generation. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetTransportMode() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The preferred transport mode @n
	 * 			Empty string, if not supported by the service provider
	 */
	Osp::Base::String	GetTransportMode(void) const;



	/**
	 * Gets the preference for retrieving the route instructions. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetInstructionsUsed() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	@c true, if supported by the service provider and preferred to retrieve instruction data @n
	 *			@c false, otherwise
	 */
	bool	IsInstructionsUsed (void) const;



	/**
	 * Gets the preference for retrieving the route geometry. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetGeometryUsed() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	@c true, if supported by the service provider and preferred to retrieve geometry data @n
	 *			@c false, otherwise
	 */
	bool	IsGeometryUsed (void) const;



	/**
	 * Gets the preference for using real-time traffic in route generation. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetTrafficDataUsed() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	@c true, if supported by the service provider, and preferred to use real-time traffic data @n
	 *			@c false, otherwise
	 */
	bool	IsTrafficDataUsed (void) const;



	/**
	 * Gets a list of the preferred instruction formats.@n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetInstructionFormatList() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of the preferred instruction formats @n
	 *          @c null, if no format have been set or if not supported by the provider (@ref Osp::Base::String list)
	 *
	 */
	const Osp::Base::Collection::IList* GetInstructionFormatList (void) const;



	/** 
	 * Gets the bounding box of the route geometry. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetGeometryBoundingBox() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The bounding box of the route geometry 
	 */
	const RectangleGeographicArea* GetGeometryBoundingBox (void) const;



	/**
	 * Gets the preference for retrieving the route instruction geometry. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetInstructionGeometryUsed() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	@c true, if supported by the service provider and preferred to retrieve the route instruction geometry @n
				@c false, otherwise
	 */
	bool	IsInstructionGeometryUsed (void) const;



	/**
	 * Gets the preference for retrieving the route instruction bounding box. @n
	 *
	 * The method returns the default value set by the service provider, or the value set with the @ref SetInstructionBoundingBoxUsed() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	@c true, if supported by the service provider, and preferred to retrieve the route instruction bounding box @n
	 *			@c false, otherwise
	 */
	bool	IsInstructionBoundingBoxUsed (void) const;


   


    /******** Modifiers ********/


	/**
	 * Sets the maximum number of matches returned from the route service provider. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	maxNumberOfMatches	The maximum number of matches expected by the application
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c maxNumberOfMatches is less than or equal to @c 0.
	 */
	result SetMaxMatchesCount(int maxNumberOfMatches);



	/**
	 * Sets the areas to be avoided in route generation. @n
	 *
	 * Possible types of geographic areas to be avoided can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTED_AREA_TYPE_TO_AVOID as the property key. @n
	 *
	 * Passing @c null or an empty list as the parameter means that there are no areas to be avoided. 
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pAreas	The geographical areas to be avoided in route generation @n
							Can be @c null if no areas are to be avoided (@ref GeographicArea list)
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c pAreas contains an unsupported geographic area.
	 * @exception	E_INVALID_ARG The specified @c pAreas contains a non-geographic Area type.
	 * @exception	E_INVALID_ARG The specified @c pAreas contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pArea is corrupted. For example, numElement < 0.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 * @exception	E_SYSTEM A system-specific error occurred.
	 * @remarks Only supports @ref RectangleGeographicArea for now. Future releases support @ref CircleGeographicArea and @ref PolygonGeographicArea.
	 */
	result	SetAreasToAvoid (const Osp::Base::Collection::IList* pAreas);



	/**
	 * Sets the features to be avoided in route generation. @n
	 *
	 * These features can be toll ways or bridges. @n
	 *
	 * Possible values for features to be avoided can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTED_FEATURES_TO_AVOID as the property key. @n
	 *
	 * Passing @c null or an empty list as the parameter means that there are no features to be avoided.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pFeatures	The features to be avoided in route generation @n
	 *							@c null or empty list if no features are to be avoided 
	 *							(@ref Osp::Base::String list)
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c pFeatures contains an unsupported feature.
	 * @exception	E_INVALID_ARG The specified @c pFeatures contains an empty String element.
	 * @exception	E_INVALID_ARG The specified @c pFeatures contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pFeatures is corrupted. For example, numElement < @c 0.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 * @exception	E_SYSTEM A system-specific error occurred.
	 */
	result	SetFeaturesToAvoid (const Osp::Base::Collection::IList* pFeatures);



	/**
	 * Sets the free form addresses to be avoided in route generation. @n
	 *
	 * The support for free form addresses to be avoided can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_FREEFORM_ADDR_TO_AVOID as the property key. @n
	 *
	 * Passing @c null or an empty list as the parameter means that there are no addresses to be avoided. 
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pFreeformAddr	The free form addresses to be avoided in route generation @n
	 *								@c null or empty if no addresses are to be avoided 
	 *								(@ref Osp::Base::String list)
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The freeform addresses to avoid were not supported by the provider.
	 * @exception	E_INVALID_ARG The specified @c pFreeformAddr contains an empty String element.
	 * @exception	E_INVALID_ARG The specified @c pFreeformAddr contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pFreeformAddr is corrupted. For example, numElement < @c 0. 
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetFreeformAddressesToAvoid (const Osp::Base::Collection::IList* pFreeformAddr);



	/**
	 * Sets the structured addresses to be avoided in route generation. @n
	 *
	 * The support for structured addresses to be avoided can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_STRUCTURED_ADDR_TO_AVOID as the property key. @n
	 *
	 * Passing @c null or an empty list as the parameter means that there are no addresses to be avoided. 
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pStructuredAddr		The structured addresses to be avoided in route generation @n
	 *									Can be @c null if no addresses are to be avoided 
	 *									(@ref AddressInfo list)
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG Structured addresses to avoid are not supported by the provider.
	 * @exception	E_INVALID_ARG The specified @c pStructuredAddr contains a non-AddressInfo element.
	 * @exception	E_INVALID_ARG The specified @c pStructuredAddr contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pStructuredAddr is corrupted. For example, numElement < @c 0. 
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetAddressesToAvoid (const Osp::Base::Collection::IList* pStructuredAddr);



	/**
	 * Sets the route type to be used in route generation. @n
	 *
	 * Possible route type values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using 
	 * @ref ProviderCapabilities::ROUTE_SUPPORTED_ROUTE_TYPES as the property key.@n
	 * 
	 * Passing @c null or an empty String as the routeType sets the route type as the default type of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pRouteType		The type of the requested route @n
	 *								Can be @c null or empty if default type is used
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c pRouteType was not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetRouteType (const Osp::Base::String* pRouteType);



	/**
	 * Sets the transport mode to be used in route generation. @n
	 *
	 * Possible transport mode values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using
	 * @ref ProviderCapabilities::ROUTE_SUPPORTED_TRANSPORT_MODES as the property key.	@n
	 * 
	 * Passing @c null or an empty string as the transportMode sets the transport mode as the default mode of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pTransportMode	The transport mode to be used in route generation @n
	 *								Can be @c null or empty if default mode is used
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c pTransportMode is not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetTransportMode (const Osp::Base::String* pTransportMode);



	/**
	 * Checks whether the route service provider must provide the instructions in the service requests.
	 *
	 * The support for instruction retrieval can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_INSTRUCTION_RETRIEVAL as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	useInstructions		Set to @c true, if the instructions must be provided @n
	 *									@c false, otherwise
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The instruction retrieval was not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetInstructionsUsed (bool useInstructions);



	/**
	 * Checks whether the route service provider must provide the geometry in the service requests.
	 *
	 * The support for geometry retrieval can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_GEOMETRY_RETRIEVAL as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	useGeometry		Set to @c true, if the geometry must be provided @n
	 *								@c false, otherwise
 	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The geometry retrieval was not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetGeometryUsed (bool useGeometry);



	/**
	 * Sets the preference for using real-time traffic in route generation. 
	 *
	 * The support for real-time traffic can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_REALTIME_TRAFFIC as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	useTrafficData	Set to @c true, if it is preferable to use real-time traffic data @n
	 *								@c false, otherwise
 	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The real-time traffic data is not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetTrafficDataUsed (bool useTrafficData);



	/**
	 * Sets the preferred route instruction format list.@n
	 *
	 * Possible instruction format values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using
	 * @ref ProviderCapabilities::ROUTE_SUPPORTED_INSTRUCTION_FORMAT as the property key.@n
	 *
	 * Passing @c null or an empty list as the formatList sets the instruction format as the default format of the service provider.@n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pFormatList		The preferred instruction formats @n
	 *								Can be @c null or empty if default format is used  (@ref Osp::Base::String list)
 	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c pFormatList contains an unsupported instruction format.
	 * @exception	E_INVALID_ARG The specified @c pFormatList contains an empty String element.
	 * @exception	E_INVALID_ARG The specified @c pFormatList contains a @c null element.
	 * @exception	E_INVALID_ARG The specified @c pFormatList is corrupted. For example, numElement < @c 0.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 *
	 * @remarks Only supports (@ref Osp::Base::String text/plain) for now.
	 */
	result	SetInstructionFormatList (const Osp::Base::Collection::IList* pFormatList);



	/**
	 * Sets the bounding box of the route geometry. 
	 *
	 * The support for bounding box can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_GEOMETRY_BOUNDING_BOX as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pBoundingBox	The bounding box of the route geometry @n
	 *								Can be @c null if default (full route geometry) is used
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified geometry bounding box is not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetGeometryBoundingBox (const RectangleGeographicArea* pBoundingBox);



	/**
	 * Checks whether the route service provider must provide the route instruction geometry in the service requests.
	 *
	 * The support for instruction geometry can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_INSTRUCTION_GEOMETRY as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	useInstructionGeometry	Set to @c true, if the route instruction geometry must be provided @n
	 *										@c false, otherwise
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The instruction geometry retrieval is not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetInstructionGeometryUsed (bool useInstructionGeometry);



	/**
	 * Checks whether the route service provider must provide the route instruction bounding box in the service requests. 
	 *
	 * The support for instruction bounding box can be queried with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using @ref ProviderCapabilities::ROUTE_SUPPORTS_INSTRUCTION_BOUNDING_BOX as the property key. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	useInstructionBoundingBox	Set to @c true, if the route request should return the route instruction bounding box @n
	 *											@c false, otherwise
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The instruction bounding box retrieval is not supported by the provider.
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 */
	result	SetInstructionBoundingBoxUsed (bool useInstructionBoundingBox);

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result	SynchronizeRouteData(void);
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	void    ClrRouteServicePreferences(void);

private:
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_areaToAvoid(void);
	
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_featureToAvoid(void);
	
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_freeformAddrToAvoid(void);
	
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_structuredAddrToAvoid(void);
	
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_instructionFormat(void);
	
	/* 
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result  SynchronizeData_geometryBoundingBox(void);	


// Data members
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * construction flag
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 *
	 */
	bool __isConstructed;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * MRouteServicePreferences instance
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 *
	 */
	MRouteServicePreferences*	__pPreferences;

private:
	RectangleGeographicArea* __pGeometryBoundingBox;

	Osp::Base::Collection::IList* __pAreaAvoid;             // GeographicArea list
	Osp::Base::Collection::IList* __pFeatureAvoid;          // Osp::Base::String list
	Osp::Base::Collection::IList* __pFreeformAddrAvoid;     // Osp::Base::String list
	Osp::Base::Collection::IList* __pStructuredAddrAvoid;   // AddressInfo list
	Osp::Base::Collection::IList* __pInstructionFormat;     // Osp::Base::String list

private:
	friend class RouteServicePreferencesEx;
	class RouteServicePreferencesEx* __pRouteServicePreferencesEx;

};	// class RouteServicePreferences

}; }; };	// Osp::Locations::Services

#endif // _FLOC_ROUTE_SERVICE_PREFERENCES_H_
