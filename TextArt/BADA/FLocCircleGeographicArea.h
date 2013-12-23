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
 * @file	FLocCircleGeographicArea.h
 * @brief	This is the header file for the %CircleGeographicArea class.
 *
 * This header file contains the declarations of the %CircleGeographicArea class.
 *
 */

#ifndef _FLOC_CIRCLE_GEOGRAPHIC_AREA_H_
#define _FLOC_CIRCLE_GEOGRAPHIC_AREA_H_

#include "FLocationConfig.h"
#include "FLocGeographicArea.h"
#include "FLocRouteServicePreferences.h"

// Forward declaration
struct MCircleGeographicArea;

namespace Osp { namespace Locations { namespace Services { class RouteServicePreferences; }; }; };

namespace Osp { namespace Locations {

/**
 * @class	CircleGeographicArea
 * @brief	This class represents a circular geographical area on a WGS 84 Ellipsoid (see reference [WGS84]).
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %CircleGeographicArea class represents a circular geographical area on a WGS 84 Ellipsoid (see reference [WGS84]).
 * Applications can use the %CircleGeographicArea instance to request services from, for example, the Osp::Locations::Services::IMapServiceProvider
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geographic_area.htm">Geographic Area</a>. 
 */
class _EXPORT_LOCATION_ CircleGeographicArea
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
	 * @param[in]	pRectGeoArea	MCircleGeographicArea object pointer to be set @n 
					The ownership is transferred.
	 * @remarks	Do not delete the passed MCircleGeographicArea instance after constructing it with this method.
	 * 
	 */
	CircleGeographicArea(MCircleGeographicArea* pCircleGeoArea);

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	CircleGeographicArea(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~CircleGeographicArea(void);

	/**
	 * This is the copy constructor for the %CircleGeographicArea class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @param[in]	value	The %CircleGeographicArea instance to copy
	 */
	CircleGeographicArea(const CircleGeographicArea& value);

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
	 * Copies the instance on the right-hand side to the calling instance. @n
	 * This assignment operator is overloaded. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @param[in]	rhs		The instance to be copied
	 */
	CircleGeographicArea& operator=(const CircleGeographicArea& rhs);	// Assignment operator

	/**
	 * Sets the center and radius of the given CircleGeographicArea object. @n
	 * If the distance from the center point to a pole is less than or equal to the radius, implying that the area contains a pole, 
	 * E_INVALID_ARG is thrown. This restriction is required because the bounding box for that area cannot be constructed.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	center			The center point of the circular geographic area
	 * @param[in]	radius			The radius of the geographic area in meters 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_INVALID_ARG	The resulting area goes over the polar areas.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Set(const Coordinates& center, float radius);

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
	 * Checks whether the specified coordinate point lies within the calling %GeographicArea instance. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the specified coordinate point is inside this geographical area, @n
	 *				else @c false if the specified coordinate point is not inside the geographical area or the specified coordinate point is @c null
	 * @param[in]	pCoordinates	The coordinates to be checked
	 */
	virtual bool ContainsCoordinates(const Coordinates* pCoordinates) const;

	/**
	 * Gets the coordinates of the center point of the calling instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The center point coordinates of the area
	 */
	virtual const Coordinates* GetCenterPoint(void) const;

	/**
	 * Compares the value of the specified instance with that of the calling instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		@c true if the objects are equal, @n
	 *				else @c false
	 * @param[in]	obj		The Object to be compared
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	 * Generates the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the radius.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The radius of the circular geographic area in meters
	 * 
	 */
	float GetRadius(void) const;

// Attributes
private:
	MCircleGeographicArea* __pCircleGeoArea;

	friend class Landmark;
	friend class _LocationUtil;
	friend class Services::RouteServicePreferences;
	friend class RemoteLocationProvider;

private:
	friend class CircleGeographicAreaEx;
	class CircleGeographicAreaEx* __pCircleGeographicAreaEx;
};	// class CircleGeographicArea

}; };	// Osp::Location

#endif // _FLOC_CIRCLE_GEOGRAPHIC_AREA_H_
