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
 * @file	FLocPolygonGeographicArea.h
 * @brief	This is the header file for the %PolygonGeographicArea class.
 *
 * This header file contains the declarations of the %PolygonGeographicArea class.
 *
 */

#ifndef _FLOC_POLYGON_GEOGRAPHIC_AREA_H_
#define _FLOC_POLYGON_GEOGRAPHIC_AREA_H_

#include "FLocationConfig.h"
#include "FLocGeographicArea.h"
#include "FLocRouteServicePreferences.h"
#include "FBaseColArrayList.h"

// Forward declaration
namespace Osp { namespace Locations { namespace Services { class RouteServicePreferences; }; }; };
struct MPolygonGeographicArea;

namespace Osp { namespace Locations {

/**
 * @class	PolygonGeographicArea
 * @brief	This class represents a polygon geographic area on a WGS 84 Ellipsoid.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 *	The %PolygonGeographicArea class represents a polygon geographic area on a WGS 84 Ellipsoid (see reference [WGS84]). Applications can use this class to request 
 *			services, for example, from the Osp::Locations::Services::IMapServiceProvider.
 *
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geographic_area.htm">Geographic Area</a>. 
 */
class _EXPORT_LOCATION_ PolygonGeographicArea 
	: public GeographicArea
{
// Lifecycle
private:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
     * @since   1.0
	 * @param[in]	pPolygonGeoArea	MPolygonGeographicArea object pointer to be set. the ownership will be transferred.
	 * @remarks	Do not delete the passed MPolygonGeographicArea object after Constructing it with this method.
	 * 
	 */
	PolygonGeographicArea(MPolygonGeographicArea* pPolygonGeoArea);

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	PolygonGeographicArea(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~PolygonGeographicArea(void);

	/**
	 * Initializes this instance of %PolygonGeographicArea with the specified parameter.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	value	The polygon geographic area object to be copied
	 */
	PolygonGeographicArea(const PolygonGeographicArea& value);	// copy constructor

// Operation
private:
	/**
	 * @internal
 	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
     * @since 1.0
	 * @return MGeographicArea instance pointer
	 * @remarks Do not delete the returned pointer. its ownership will not be transferred.
	 */
	virtual const MGeographicArea* GetMGeographicArea(void) const;

public:
	/**
	 * Sets the coordinates that form the given PolygonGeographicArea object. @n
	 * The polygonal area is constructed by combining the corner points with the shortest path on the WGS 84 Ellipsoid starting from the first element in the 
	 * array. The last path is drawn starting from the last element in the array to the first element to form a closed shape by the method.
	 *
	 * The polygon area cannot contain polar areas. This restriction is required because the confining box of the polygon crossing the polar areas cannot be 
	 * represented with RectangleGeographicArea. The polygon area must therefore be formed as not containing the polar areas of the two possible areas that 
	 * the given polygon defines. If the given coordinates for an area contain one of the polar areas, E_INVALID_ARG is thrown.
	 *
	 * This specification only supports simple polygons, that is, polygons whose sides do not intersect. If the input array contains coordinates that form a 
	 * complex polygon with an intersecting side then E_INVALID_ARG is thrown. Complex polygons can always be represented with multiple simple polygons.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	coordinates			The coordinates that form the polygon geographic area 
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c coordinates is an empty list or has elements that are not Coordinate objects, or @n
	 *									the specified @c coordinates form a complex polygon or the area contains polar areas.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 */
	result Set(const Osp::Base::Collection::IList& coordinates);

	/**
	 * Copies a given polygon geographic area.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	rhs		The polygon geographic area object to be copied
	 *
	 */
	PolygonGeographicArea& operator=(const PolygonGeographicArea& rhs);


protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
	 */
	result SynchronizeData(const MPolygonGeographicArea* pPolygonGeoArea);

public:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
 	 *
	 * @deprecated	This method is deprecated.
 	 * @since		1.0
 	 * @return	A duplicated GeographicArea instance
	 */
	virtual GeographicArea* DuplicateN(void) const;

	/**
	 * Checks whether the specified coordinate is inside the specified %GeographicArea object.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the specified coordinate is inside the specified geographical area, @n
	 *				else @c false
	 * @param[in]	pCoordinates	The coordinates to be checked
     * @remarks     Geographical calculation on a polygonal area is based on the Mercator projections and not the WGS 84 Ellipsoid.
	 */
	virtual bool ContainsCoordinates(const Coordinates* pCoordinates) const;

	/**
	 * Gets the coordinates of the center point of the specified geographic area. @n
	 * The center point of a polygon with more than 3 vertices is the center point of the longest diagonal. For a triangle, this method returns the 
	 * intersection of the medians of the triangle. A median is the line from a vertex to the midpoint of the opposite side. If the polygon is a line, the 
	 * center point is the midpoint of the line. For a point polygon, the point itself is returned as the center point. The center point may be outside the 
	 * polygon.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The center point coordinates of the area
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @remarks     Geographical calculation on a polygonal area is based on the Mercator projections and not the WGS 84 Ellipsoid.
	 */
	virtual const Coordinates* GetCenterPoint(void) const;

	/**
	 * Overrides the Equals() method in the Object class to compare the equality of values in two PolygonGeographicArea objects. @n
	 * The coordinates array that forms the polygon area (retrieved with the GetCoordinates() method) may start from a different coordinate in two different 
	 * instances. However, as long as the order of the coordinates remains the same, they both form the same polygon area. For example, coordinates c1, c2 
	 * and c3 form the same area as coordinates c2, c3 and c1. If the starting point of the polygon is different but they still contain an equal set of 
	 * coordinates in the same order, this method returns @c true.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, @ref CompPolygonEqualsPage "here".
	 * @return			@c true if objects are equal, @n
	 *					else @c false
	 * @param[in]		obj		The Object with which the comparison is done
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	* @page   	CompPolygonEqualsPage	Compatibility for Equals()
	* @section 	CompPolygonEqualsPageIssuesSection	Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# An application can terminate when it compares two %PolygonGeographicAreas having the same coordinates but with a different order of the coordinates.
	*
	* @section 	CompPolygonEqualsPageResolutionsSection		Resolutions 
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	* 
	*/

	/**
	 * Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The hash value of the instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets a list of %Coordinates instances that form the polygonal geographical area. @n
	 * The coordinates form a round trip around the area and these coordinates have been given in the constructor.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		A list containing the coordinates of the polygon geographical area (@ref Coordinates)
	 */
	const Osp::Base::Collection::IList* GetCoordinates(void) const;

// Attributes
private:
	MPolygonGeographicArea* __pPolygonGeoArea;
	Osp::Base::Collection::ArrayList __coordinates;

	friend class Landmark;
	friend class _LocationUtil;
	friend class Services::RouteServicePreferences;

private:
	friend class PolygonGeographicAreaEx;
	class PolygonGeographicAreaEx* __pPolygonGeographicAreaEx;


};	// class PolygonGeographicArea

}; };	// Osp::Location

#endif // _FLOC_POLYGON_GEOGRAPHIC_AREA_H_
