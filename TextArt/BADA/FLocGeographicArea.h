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
 * @file	FLocGeographicArea.h
 * @brief	This is the header file for the %GeographicArea class.
 *
 * This header file contains the declarations of the %GeographicArea class.
 *
 */

#ifndef _FLOC_GEOGRAPHIC_AREA_H_
#define _FLOC_GEOGRAPHIC_AREA_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FLocCoordinates.h"

// Forward declaration
struct MList;
struct MGeographicArea;
struct MCoordinates;
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };

namespace Osp { namespace Locations {

class RectangleGeographicArea;
/**
 * @class	GeographicArea
 * @brief	This class defines a geographical area on the surface of a WGS 84 Ellipsoid (see reference [WGS84]).
 * @deprecated	This class is deprecated.
 * @since 	1.0
 * 
 * The %GeographicArea class represents a geographical area on the surface of a WGS 84 Ellipsoid (see reference [WGS84]). This is an abstract class and provides 
 * 			the methods common to all the shape-specific geographic area classes, such as CircleGeographicArea, RectangleGeographicArea, and 
 *			PolygonGeographicArea that are derived from it. Applications can use these classes to request services, for example, from Osp::Locations::Services::IMapServiceProvider.
 *
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geographic_area.htm">Geographic Area</a>.
 */
class _EXPORT_LOCATION_ GeographicArea
	: public Osp::Base::Object
{
// Lifecycle
private:	
	GeographicArea(const GeographicArea& value);	// copy constructor
	
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
	GeographicArea(void);				// default constructor
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~GeographicArea(void);

// Operation
private:
	GeographicArea& operator=(const GeographicArea& rhs);	// assignment operator
	virtual const MGeographicArea* GetMGeographicArea(void) const = 0;

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
	result SynchronizeData(const MGeographicArea* pMGeoArea);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Converts a list of MCoordinates to a list of Coordinates.
	 *
	 * @deprecated	This method is deprecated.
     * @since 1.0
	 * @remarks Do not delete the input pList regardless of whether if it succeeded or has failed.
	 */
	static Osp::Base::Collection::IList*  ConvertListOfCoordinates(MList* pList);


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
	virtual GeographicArea* DuplicateN(void) const = 0;

	/**
	 * Checks whether the specified coordinate is inside this %GeographicArea instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the given point is inside this geographical area, @n
	 *				else @c false
	 * @param[in]	pCoordinates	The coordinates to be checked @n
	 *								If this is @c null, the result is @c false.
	 */
	virtual bool ContainsCoordinates(const Coordinates* pCoordinates) const = 0;

	/**
	 * Gets the RectangleGeographicArea instance that completely surrounds this geographic area. 
	 * The %RectangleGeographicArea is always aligned with parallels and meridians.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return			A %RectangleGeographicArea instance containing this area
	 * @exception		E_SUCCESS 		The method is successful.
	 * @exception		E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual const RectangleGeographicArea* GetBoundingBox(void) const;

	/**
	 * Gets the coordinates of the center point of this geographic area.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The center point coordinates of the area
	 */
	virtual const Coordinates* GetCenterPoint(void) const;

private:
	Coordinates __centerPoint;
	RectangleGeographicArea* __pBoundingBox;

	friend class Landmark;
	friend class LandmarkFilter;
	friend class __LandmarkStore;
	friend class __LocationProvider;
	friend class __RemoteLandmarkStoreHelper;
	friend class LocationProvider;

private:
	friend class GeographicAreaEx;
	class GeographicAreaEx* __pGeographicAreaEx;

};	// class GeographicArea

}; };	// Osp::Location

#endif // _FLOC_GEOGRAPHIC_AREA_H_
