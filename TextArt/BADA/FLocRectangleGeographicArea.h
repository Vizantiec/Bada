/* $Change: 1006494 $ */
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
 * @file	FLocRectangleGeographicArea.h
 * @brief	This is the header file for the %RectangleGeographicArea class.
 *
 * This header file contains the declarations of the %RectangleGeographicArea class.
 *
 */

#ifndef _FLOC_RECTANGLE_GEOGRAPHIC_AREA_H_
#define _FLOC_RECTANGLE_GEOGRAPHIC_AREA_H_

#include "FLocationConfig.h"
#include "FLocGeographicArea.h"
#include "FLocRouteServicePreferences.h"
#include "FBaseColArrayList.h"

// Forward declaration
struct MRectangleGeographicArea;
namespace Osp { namespace Locations { namespace Services { class ProviderCapabilities; }; }; };
namespace Osp { namespace Locations { namespace Services { class RouteServicePreferences; }; }; };

namespace Osp { namespace Locations {
/**
 * @class	RectangleGeographicArea
 * @brief	This class represents a rectangular geographical area on a WGS 84 Ellipsoid (see reference [WGS84]).
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %RectangleGeographicArea class represents a rectangular geographical area on a WGS 84 Ellipsoid (see reference [WGS84]). Applications can use this class to request 
 * 			services from, for example, the Osp::Locations::Services::IMapServiceProvider.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geographic_area.htm">Geographic Area</a>.
 */
class _EXPORT_LOCATION_ RectangleGeographicArea 
		:	public GeographicArea
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
	 * @param[in]	pRectGeoArea	MRectangleGeographicArea object pointer to be set. the ownership will be transferred
	 * @remarks	Do not delete the passed MRectangleGeographicArea instance after constructing it with this method.
	 * 
	 */
	RectangleGeographicArea(MRectangleGeographicArea* pRectGeoArea);

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	RectangleGeographicArea(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~RectangleGeographicArea(void);

	/**
	 * Initializes this instance of %RectangleGeographicArea with the specified parameter.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @param[in]	value	The rectangular geographic area object to be copied
	 */
	RectangleGeographicArea(const RectangleGeographicArea& value);

// Operation
private:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
     * @since   1.0
	 * @return MGeographicArea instance pointer
	 * @remarks Do not delete the returned pointer. Its ownership is not transferred.
	 */
	virtual const MGeographicArea* GetMGeographicArea(void) const;

public:
	/**
	 * Sets the boundary of the specified %RectangleGeographicArea object. The object is created as a rectangle from the specified @c lowerLeftCorner,
	 * and @c upperRightCorner coordinates. The coordinates are combined with lines that are aligned with parallels, and meridians. @n
	 * Creating the object from the @c lowerLeftCorner to @c upperRightCorner allows for the crossing of @c 180 longitude.
	 * Longitudes @c -180 and @c 180 denote the same longitude. If an application wants to create a rectangle that crosses the @c -180
	 * longitude, it sets the longitude of @c lowerLeftCorner to a higher value than the longitude of the @c upperRightCorner.
	 * This ensures that the rectangle created crosses the @c 180 longitude. Constructing an area with the longitude of
	 * @c lowerLeftCorner as -180, and the longitude of @c upperRightCorner as @c 180 gives an area that goes around the
	 * earth.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	lowerLeftCorner		The coordinates of the lower left corner of the rectangle
	 * @param[in]	upperRightCorner	The coordinates of the upper right corner of the rectangle
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 */
	result Set(const Coordinates& lowerLeftCorner, const Coordinates& upperRightCorner);

	/**
	 * Sets the boundary of the specified %RectangleGeographicArea object. The object is constructed as a rectangle from specified parameter values.
	 * This method is the same as calling the other constructor with coordinates constructed from the @c minLat, @c minLon pair, and
	 * the @c maxLat, @c maxLon pair. The valid values for @c minLat and @c maxLat are, [-90.0, 90.0]. The valid values for @c minLon and
	 * @c maxLon are, [-180.0, 180.0]. If @c minLon > @c maxLon, the rectangle is created so that the @c 180 longitude is crossed.
	 * The method constructs %Coordinates objects from the parameter values, and it must set the altitude to @c NaN.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in] 	minLat				The minimum latitude of the rectangle area in the range [-90.0, 90.0]
	 * @param[in] 	maxLat				The maximum latitude of the rectangle area in the range [-90.0, 90.0]
	 * @param[in] 	minLon				The minimum longitude of the rectangle area in the range [-180.0, 180.0]
	 * @param[in] 	maxLon				The maximum longitude of the rectangle area in the range [-180.0, 180.0]
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified @c minLat is greater than the specified @c maxLat, or @n
	 *									a specified input parameter is out of the valid range.
	 */
	result Set(double minLat, double maxLat, double minLon, double maxLon);

	/**
	 * Copies the specified rectangular geographic area.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @param[in]	rhs	 	The rectangular geographic area object to be copied
	 */
	RectangleGeographicArea& operator=(const RectangleGeographicArea& rhs);	// assignment operator

protected:
	/**
	 * @internal
     *
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
	 */
	result SynchronizeData(const MRectangleGeographicArea* pRectGeoArea);

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
	 * Checks whether the specified coordinates are inside the %GeographicArea instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		@c true if the specified point is inside the geographical area, @n
	 *				else @c false
	 * @param[in]	pCoordinates	The coordinates to be checked
	 */
	virtual bool ContainsCoordinates(const Coordinates* pCoordinates) const;

	/**
	 * Gets the coordinates of the center point of the geographic area. @n
	 * The center point of the rectangle is the point with mean latitude and mean longitude.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The coordinates of the center point of the area
	 */
	virtual const Coordinates* GetCenterPoint(void) const;

	/**
	 * Compares the equality of value of the specified %RectangleGeographicArea object with this instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		@c true if the objects are equal, @n
	 *				else @c false
	 * @param[in]	obj	  The Object with which the comparison is done
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	 * Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the two %Coordinates objects that were used to construct this rectangular geographical area. @n
	 * The first element in the returned array contains the @c lowerLeftCorner, and the second element contains the @c upperRightCorner coordinates. If the
	 * constructor taking the @c double values is used, this method returns in the first element a %Coordinates object constructed from @c minLat and @c 
	 * minLon values. The second element contains a %Coordinates object constructed from the @c maxLat and @c maxLon values.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An IList() containing the coordinates of the rectangular geographical area (@ref Coordinates)
	 */
	const Osp::Base::Collection::IList* GetCoordinates(void) const;

// Attributes
private:
	MRectangleGeographicArea* __pRectGeoArea;
	Osp::Base::Collection::ArrayList __coordinates;

	friend class GeographicArea;
	friend class CircleGeographicArea;
	friend class PolygonGeographicArea;
	friend class Landmark;
	friend class _LocationUtil;
	friend class Services::ProviderCapabilities;
	friend class Services::RouteServicePreferences;
	friend class RectangleZoneServiceInfo;
	friend class RemoteLocationProvider;

private:
	friend class RectangleGeographicAreaEx;
	class RectangleGeographicAreaEx* __pRectangleGeographicAreaEx;

};	// class RectangleGeographicArea

}; };	// Osp::Location

#endif // _FLOC_RECTANGLE_GEOGRAPHIC_AREA_H_
