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
* @file		FLocCtrlMapOverlayPolygon.h 
* @brief	This is the header file for the %MapOverlayPolygon class.
*
* This header file contains the declarations of the %MapOverlayPolygon class.
*/
#ifndef _FLOC_CTRL_MAPVIEW_POLYGON_H_
#define _FLOC_CTRL_MAPVIEW_POLYGON_H_

#include <FLocCtrlMapOverlayShape.h>
#include <FLocPolygonGeographicArea.h>

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayPolygon;

/**
 * @class	MapOverlayPolygon
 * @brief	This class defines the common behaviors for a polygon. 
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %MapOverlayPolygon class displays a polygon overlay.
 * 			It also provides the methods for getting the rectangle bounds of a polygon and the polygon geographical area on the WGS 84 Ellipsoid. @n
 * The Map control renders each edge of the overlay as a straight line on the map and not as a geodesic (a segment of a Great circle).
 *  
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>. 
 */
class _EXPORT_LOCATION_CONTROL MapOverlayPolygon :
	public Osp::Locations::Controls::MapOverlayShape
{
public:
	
	/**
	* Initializes this instance of %MapOverlayPolygon with the specified parameter.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	area	The area of this control  
	*/
	MapOverlayPolygon(const Osp::Locations::PolygonGeographicArea& area);

	/** 
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~MapOverlayPolygon();

	/**
	* Gets the class of the polygon geographical area on the WGS 84 Ellipsoid.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The PolygonGeographicArea of polyline
	*/
	Osp::Locations::PolygonGeographicArea GetGeographicArea(void) const;

	
	/**	
	* Gets the rectangle bound of the polygon.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The rectangle bounds of the polygon
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Copy the source data of MapOverlayPolygon to destination
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.	 
	*/
	result CopyData(__IMapOverlayPolygon& dest) const;
		
protected:
	
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the polygon.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlay(Osp::Graphics::Canvas& canvas);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the shadow of the polygon.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlayShadow(Osp::Graphics::Canvas& canvas); 

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Checks whether the polygon is hit.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hit status of the polygon
	* @param[in]	anchor	The pixel value transformed from the center coordinates of the polygon
	* @param[in]	pt		The hit point
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const;

private:
	
	/*
	* The PolygonGeographicArea instance.
	*/
	Osp::Locations::PolygonGeographicArea*		__pBound;

	/*
	* The List instance.
	*/
	Osp::Base::Collection::IList*	__polygonArea;

private:
	
	friend class MapOverlayPolygonEx;
	class MapOverlayPolygonEx* __pMapOverlayPolygonEx;

};		// MapOverlayControlPolygon

};};};	// Osp::Ui::Controls

#endif	// _FLOC_CTRL_MAPVIEW_POLYGON_H_
