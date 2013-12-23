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
* @file		FLocCtrlMapOverlayRectangle.h 
* @brief	This is the header file for the %MapOverlayRectangle class.
*
* This header file contains the declarations for the %MapOverlayRectangle class.
*/
#ifndef _FLOC_CTRL_MAPVIEW_RECT_H_
#define _FLOC_CTRL_MAPVIEW_RECT_H_

#include <FLocCtrlMapOverlayShape.h>

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayRectangle;

/**
 * @class	MapOverlayRectangle
 * @brief	This class defines the common behaviors for a rectangle. 
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %MapOverlayRectangle class displays a rectangle overlay. It also provides the methods for getting the rectangle bounds of a rectangle and the rectangular geographical area on the WGS 84 Ellipsoid. @n
 * The Map control renders each edge of the overlay as a straight line on the map and not as a geodesic (a segment of a Great circle).
 *
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
 */
class _EXPORT_LOCATION_CONTROL MapOverlayRectangle :
	public Osp::Locations::Controls::MapOverlayShape
{
public:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/	
	MapOverlayRectangle(void);

	/** 
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~MapOverlayRectangle(void);

protected:

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the rectangle.
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
	* Draws the shadow of a rectangle.
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
	* Checks whether the rectangle is hit.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hit status of the rectangle
	* @param[in]	anchor	The pixel value transformed from the center coordinates of the rectangle
	* @param[in]	pt		The hit point
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const;

public:
	
	/**
	* Initializes this instance of %MapOverlayRectangle with the specified parameters.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref RectangleConstructPage "here".
	*
	* @return			An error code
	* @param[in]		minLat			The minimum latitude in the range [-90, 90] 
	* @param[in]		maxLat			The maximum latitude in the range [-90, 90] 
	* @param[in]		minLon			The minimum longitude in the range [-180, 180] 
	* @param[in]		maxLon			The maximum longitude in the range [-180, 180] 
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_INVALID_ARG	The specified @c minLat is greater than the specified @c maxLat, or
	* 									an input parameter is out of the valid range.
	* @exception		E_OUT_OF_MEMORY	The memory is insufficient.
	*/
	result Construct(double minLat, double maxLat, double minLon, double maxLon);

	/**
	* @page		RectangleConstructPage Compatibility for Construct()
	*
	* @section		RectangleConstructPageIssueSection Issues
	*				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*				-# E_SYSTEM is returned for all exception cases.
	*
	* @section		RectangleConstructPageResolutionSection Resolutions
	* 				-# E_INVALID_ARG is returned if the specified @c minLat is greater than the specified @c maxLat, or
	* 				an input parameter is out of the valid range.
	* 				-# E_OUT_OF_MEMORY is returned in case of insufficient memory.
	*/

	/**
	* Gets the rectangle bounds of the rectangle.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The rectangle bounds of the rectangle
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const;

	/**
	* Gets the class of the rectangular geographical area on the WGS 84 Ellipsoid.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The RectangleGeograpchicArea of the rectangle
	*/
	Osp::Locations::RectangleGeographicArea GetGeographicArea(void) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of MapOverlayRectangle to destination.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.
	*/
	result CopyData(__IMapOverlayRectangle& dest) const;

private:

	/*
	* RectangleGeographicArea instance.
	*/
	Osp::Locations::RectangleGeographicArea		__bound;

private:
	
	friend class MapOverlayRectangleEx;
	class MapOverlayRectangleEx* __pMapOverlayRectangleEx;

};		// MapOverlayRectangle

};};};	// Osp::Ui::Controls

#endif	// _FLOC_CTRL_MAPVIEW_RECT_H_
