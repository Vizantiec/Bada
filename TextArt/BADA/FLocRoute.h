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
 * @file		FLocRoute.h
 * @brief		This is the header file for the Route class.
 *
 * This header file contains the declarations of the Route class.
 *
 */

#ifndef _FLOC_ROUTE_H_
#define _FLOC_ROUTE_H_

// include
#include "FLocationConfig.h"
#include "FLocRouteSegment.h"
#include "FBaseObject.h"

// forward declaration
namespace Osp { namespace Base { namespace Collection {class HashMap; }; }; };
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Locations { class Coordinates; }; };
namespace Osp { namespace Locations { class RectangleGeographicArea; }; };


namespace Osp { namespace Locations { namespace Services {

/**
 * @class Route
 * @brief This class provides a route.
 * @deprecated	This class is deprecated.
 * @since 1.0
 *
 * The %Route class represents a route. A route consists of one or more route segments combined in the course of travel. A %Route instance contains
 * the summary, length, estimated traveling time, and array of @ref RouteSegment instances that form the actual route.
 */
class _EXPORT_LOCATION_ Route :	public Osp::Base::Object
{

// Lifecycle
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
	Route (const Route& value);	// copy constructor
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	Route & operator=(const Route& rhs);	// assignment operator

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
	Route (void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	result	Construct();
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	void	ClrRoute(void);

public:

	/**
	 * This is the destructor for this class.
	 * 
	 * Removes everything in the object including route segments, geometry, extra responses, and so on.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~Route (void);





// Operation
public:

	/**
	 * Gets the length of the route. @n 
	 * 
	 * The application itself is responsible for the conversion of the length to some other units.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The length of the route @n
	 *				@c -1, if not provided
	 * @see				ServicePreferences::SetLengthUnit() 
	 */
	double	GetLength (void) const;



	/**
	 * Gets the length unit.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The unit of length to be measured @n
	 *				Empty string, if not provided
	 * @see				ServicePreferences::SetLengthUnit()
	 */
	Osp::Base::String	GetLengthUnit (void) const;



	/**
	 * Gets the estimated time it takes to travel the route. @n
	 * 
	 * The estimated time is in seconds.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The @c long value representing the estimated traveling time of the route in seconds @n
	 *				@c -1, if not provided
	 */
	long	GetTravelTime (void) const;



	/**
	 * Gets the coordinates of the starting point of the route. @n
	 * 
	 * This is not necessarily the same as the first point of the route geometry.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The starting coordinates @n
	 *				@c null, if not available
	 */
	const Coordinates* GetStartingPoint (void) const;



	/**
	 * Gets the coordinates of the destination point of the route.  @n
	 * 
	 * This is not necessarily the same as the last point of the route geometry.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The destination coordinates @n
	 *				@c null, if not available
	 */
	const Coordinates* GetDestinationPoint (void) const;



	/**
	 * Gets the segments of the route. @n
	 * 
	 * The segments are ordered from the starting point to the destination so that they form a continuous route.
	 * The returned @ref RouteSegment objects contain more information about the segment, such as its geometry.
	 * The order of the segments is significant. @n
	 * 
	 * For successfully getting the segments, RouteServicePreferences::SetInstructionsUsed(true) should be called.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		A list of route segments @n
	 *				@c null, if not provided (@ref RouteSegment list)
	 * @see			RouteServicePreferences::SetInstructionsUsed()
	 */
	const Osp::Base::Collection::IList* GetSegments (void) const;



	/**
	 * Gets the geometry of the full route. @n
	 * 
	 * The geometry includes intermediate points needed to describe the geometric shape of the route segment. 
	 * For example, a road between two cities that is not simply straight but has several curves in it. 
	 * The geometry is formed by connecting the coordinates with straight lines. The geometry may be a polygon, 
	 * if the starting and destination points of the route segment are the same. @n
	 * 
	 * The first item in the array must be the starting point, and the last item must be the end point of the segment. 
	 * If the start and end point of the segment are the same, the method still returns at least an array of two coordinates. @n
	 * 
	 * For successfully getting the geometry, RouteServicePreferences::SetGeometryUsed(true) should be called.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		A list of coordinates that form the geometry of the full route @n
	 *				@c null, if not provided (@ref Coordinates list)
	 * @see			RouteServicePreferences::SetGeometryUsed()
	 */
	const Osp::Base::Collection::IList* GetGeometry (void) const;
 


	/**
	 * Gets the geographic area of the route. @n
	 * 
	 * The geographic area is the smallest rectangle that can be drawn around the route.
	 * This information can also be used, for example, to request relevant events or locations in the specified area or to request a 
	 * map of the route segment to be drawn.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		A rectangular geographical area that contains the route @n
	 *				@c null, if not provided
	 *
	 */
	const RectangleGeographicArea* GetGeographicArea (void) const;



	/**
	 * Gets the summary of the route. @n
	 * 
	 * This summary describes the route in general. This summary may be shown to the user. If traveling on the route incurs 
	 * a cost to the user, the route service provider may indicate detailed information about the costs in this summary.
	 * The @ref RouteSegment objects in the route contain descriptions about the segments. @n
	 * 
	 * If the @ref Route object has been generated by a route service provider, the summary must be returned in the language
	 * set for the service provider.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The route summary @n
	 *				Empty string, if not provided
	 * @see			ServicePreferences::SetLanguage()
	 */
	Osp::Base::String GetSummary (void) const;



	/**
	 * Checks if traveling the route incurs a cost to the user. @n
	 * 
	 * The cost may be created, for example, by a toll road or bridge.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		@ref TRAVEL_COST_INCURS, if traveling on the route incurs a cost @n
	 *				@ref TRAVEL_COST_NO, if traveling on the route incurs no cost @n
	 *				@ref TRAVEL_COST_UNKNOWN, if information regarding the cost for traveling on certain segments is unavailable
	 */
	TravelCost	GetIncursCosts (void) const;



	/**
	 * Gets the list of the property keys for additional, provider-specific values for the routes that have been defined for a service provider. @n
	 * 
	 * The actual property value can be retrieved with the @ref GetExtraPropertyValue() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		A list of property keys for additional, provider-specific values @n
	 *				@c null, if an exception occurs (@ref Osp::Base::String list)
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Osp::Base::Collection::IList* GetExtraPropertyKeys (void);



	/**
	 * Gets the value of the requested additional, provider-specific property value for the route. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The value of the property @n
	 *				Empty string, if either the key or the value is not defined
	 * @param[in]	key	 The identifier of the property
	 * 
	 */
	Osp::Base::String GetExtraPropertyValue (const Osp::Base::String& key) const;



// Attributes
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A list of route segments
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList*	__pRouteSegments;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A list of route geometry
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList*	__pRouteGeometry;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A list of extra property keys
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList*   __pExtraPropertyKeys; 
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A map consisting of a set of associated extra property key and value.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::HashMap* __pExtraProperties;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The starting point of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Coordinates*	__pStartingPoint;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The destination point of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Coordinates*	__pDestinationPoint;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The bounding box of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	RectangleGeographicArea*	__pRouteBoundingBox;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The route summary of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::String	__routeSummary;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The distance unit of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::String	__distanceUnit;	

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * An enum value indicating whether traveling the route incurs a cost to the user
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	TravelCost	__incursCost;	
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The distance of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	double		__distance;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The duration of the route
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	long		__duration;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * construction flag
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	bool		__isConstructed;

private:
	friend class RouteEx;
	class RouteEx* __pRouteEx;

};	// class Route

}; }; };	// Osp::Locations::Services

#endif // _FLOC_ROUTE_H_
