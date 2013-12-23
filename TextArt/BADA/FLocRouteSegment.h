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
 * @file		FLocRouteSegment.h
 * @brief		This is the header file for the RouteSegment class.
 *
 * This header file contains the declarations of the RouteSegment class.
 *
 */

#ifndef _FLOC_ROUTE_SEGMENT_H_
#define _FLOC_ROUTE_SEGMENT_H_

// include
#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FLclLocale.h"

// forward declaration
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class HashMap; }; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };
namespace Osp { namespace Locations { class RectangleGeographicArea; }; };


namespace Osp { namespace Locations { namespace Services {

/**
 * The enumeration type checks whether traveling through the specified route incurs a cost to the user. The cost may be created, for example,
 * by a toll road or bridge. If the route service provider wants to specify more detailed costs,
 * it may include this information in the route segment description.
 * TRAVEL_COST_INCURS indicates that traveling on the route incurs some cost, TRAVEL_COST_NO indicates that no cost is incurred, and TRAVEL_COST_UNKNOWN 
 * indicates that the route service provider does not have information about the cost.
 *
 * @deprecated	This enumerated type is deprecated.
 * @since 1.0
 */
enum TravelCost
{
	/** traveling the route incurs a cost to the user */
	TRAVEL_COST_INCURS, 
	/**	traveling the route does not incur costs at all */
	TRAVEL_COST_NO,
	/** the route service provider does not have information about the cost*/
	TRAVEL_COST_UNKNOWN
};


/**
 * @class RouteSegment
 * @brief This class represents a segment of a route.
 * @deprecated	This class is deprecated.
 * @since 1.0
 *
 * The %RouteSegment class represents a segment of a route.
 * A %RouteSegment instance contains the description, length, geometry, and estimated traveling time.
 */
class _EXPORT_LOCATION_ RouteSegment : public Osp::Base::Object
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
	RouteSegment (const RouteSegment& value); // copy constructor
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	RouteSegment & operator=(const RouteSegment& rhs); // assignment operator

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
	RouteSegment (void);	

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
	void	ClrRouteSegment(void);

public:

    /**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~RouteSegment (void);


// Operation
public:

	/**
	 * Gets the length of the route segment. @n
	 * 
	 * The application itself is responsible for the conversion of the length to some other units.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The length of the segment @n
	 *			@c -1, if not provided
	 * @see			ServicePreferences::SetLengthUnit() 
	 */
	double		GetLength (void) const;



	/**
	 * Gets the estimated time it takes to travel the route segment. @n
	 * 
	 * The estimated time is in seconds.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The @c long value representing the estimated traveling time of the segment in seconds @n
	 *			@c -1, if not provided
	 */
	long		GetTravelTime (void) const;



	/**
	 * Checks whether traveling through the specified route segment incurs a cost to the user. @n
	 * 
	 * The cost may be created, for example, by a toll road or bridge. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return		@ref TRAVEL_COST_INCURS, if traveling on the segment incurs a cost to the user @n
	 *			@ref TRAVEL_COST_NO, if traveling on the segment incurs no cost to the user @n
	 *			@ref TRAVEL_COST_UNKNOWN, if not provided
	 *
	 */
	TravelCost	GetIncursCosts (void) const;



	/**
	 * Gets the description given for the route segment. @n
	 * 
	 * This description may contain some characteristics about the segment or other additional information about the route segment. 
	 * This information may be shown to the user. If traveling this route of the segment incurs some cost to the user, the route service provider may
	 * indicate the amount of cost in this route segment description. @n
	 * 
	 * If this @ref RouteSegment object has been generated by a route service provider, the description must be returned in
	 * the language set for the service provider.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The description of the segment @n
	 *			empty string, if not provided
	 * @see		ServicePreferences::SetLanguage()
	 */
	Osp::Base::String GetDescription (void) const;



	/**
	 * Gets the geographic area of the route segment. @n
	 * 
	 * The geographic area is the smallest rectangle that can be drawn around the route segment.
	 * This information can also be used, for example, to request relevant events or locations in the specified area, or to request
	 * a map of the route segment to be drawn. The direction of the geographic area is always true north. @n
	 * 
	 * For successfully getting the geographic area, RouteServicePreferences::SetInstructionBoundingBoxUsed(true) should be called.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A rectangular geographical area that contains the segment @n
	 *			@c null, if not provided
	 * @see		RouteServicePreferences::SetInstructionBoundingBoxUsed()
	 */
	const RectangleGeographicArea* GetGeographicArea (void) const;



	/**
	 * Gets the geometry of the route segment. @n
	 * 
	 * The geometry includes intermediate points needed to describe the geometric shape of the route segment. For example, 
	 * a road between two cities is not simply straight but has several curves on it. The geometry is formed by connecting the
	 * coordinates with the straight lines. The geometry may be a polygon, if the starting and destination points of the route segment 
	 * are the same. @n
	 * 
	 * The first item in the array must be the starting point, and the last item must be the end point of the segment. If the start and end point of
	 * the segment are the same, the method still returns at least an array of two coordinates. @n
	 * 
	 * For successfully getting the geometry, RouteServicePreferences::SetInstructionGeometryUsed(true) should be called.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of coordinates that form the geometry of the segment @n
	 *			@c null, if not provided (@ref Coordinates list)
	 * @see		RouteServicePreferences::SetInstructionGeometryUsed()
	 */
	const Osp::Base::Collection::IList* GetGeometry (void) const;



	/**
	 * Gets the transport mode for the route segment. @n
	 * 
	 * If this @ref RouteSegment object has been created by the route service provider, this method returns the transport mode 
	 * that is used in the route calculations by the service provider.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The transport mode of the segment @n
	 *			Empty string, if not provided
	 *
	 */
	Osp::Base::String GetTransportMode (void) const;



	/**
	 * Gets the route instruction item for the specified type. @n
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The instructions for this route segment @n
	 *				@c null, if not provided
	 * @param[in]	instructionFormat	The MIME type of the requested instruction @n
	 * 									Only supports "text/plain" for now
	 *
	 */
	const Osp::Base::Object* GetInstructionItem (const Osp::Base::String& instructionFormat) const;



	/**
	 * Gets the MIME types of the instructions that have been set in this object. @n
	 * 
	 * The MIME type can be used to request appropriate instructions with the @ref GetInstructionItem() method. It only supports "text/plain" for now.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		A list of mime types of the instructions items @n
	 *				@c null, if an exception occurs (@ref Osp::Base::String list)
	 * @exception   E_OUT_OF_MEMORY Insufficient memory.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Osp::Base::Collection::IList* GetInstructionFormats (void);



	/**
	 * Gets the list of the property keys for additional, provider-specific values for the route segment that have been defined for a service provider. @n
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
	 * Gets the value of the requested additional, provider-specific property value for the route segment. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The value of the property @n
	 *				Empty string, if either the key or the value is not defined
	 * @param[in]	key	 The identifier of the property
	 * 
	 */
	Osp::Base::String GetExtraPropertyValue (const Osp::Base::String& key) const;



	/**
	 * Gets the instruction language.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The type of language used in the route instruction @n
	 *				@ref Osp::Locales::LANGUAGE_INVALID, if not provided
	 * @see 			ServicePreferences::SetLanguage()
	 */
	Osp::Locales::LanguageCode GetInstructionLanguage (void) const;


// Attributes
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A list of route segment geometry
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList*	__pSegmentGeometry;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A list of instruction formats
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList*	__pInstructionFormats;
		
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
	Osp::Base::Collection::IList*	__pExtraPropertyKeys; 
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * A map consisting of a set of associated instruction format and object.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::HashMap*	__pInstruction;
		
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
	Osp::Base::Collection::HashMap*	__pExtraProperties;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The instruction language of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Locales::LanguageCode	__language;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The bounding box of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	RectangleGeographicArea*	__pSegmentBoundingBox;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The description of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::String	__description;
		
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The transport mode of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::String	__transportMode;

	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * An enum value indicating whether traveling the route segment incurs a cost to the user
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	TravelCost	 __incursCost;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The distance of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	double		 __distance;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * The duration of the route segment.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	long		 __duration;
	
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
	bool		 __isConstructed;

private:
	friend class RouteSegmentEx;
	class RouteSegmentEx* __pRouteSegmentEx;

};	// class RouteSegment

}; }; };	// Osp::Locations::Services

#endif // _FLOC_ROUTE_SEGMENT_H_
