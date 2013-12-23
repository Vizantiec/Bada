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
* @file		FLocCtrlMapOverlayPolyline.h
* @brief	This is the header file for the %MapOverlayPolyline class.
*
* This header file contains the declarations of the %MapOverlayPolyline class.
*/
#ifndef _FLOC_CTRL_MAPVIEW_POLYLINE_H_
#define _FLOC_CTRL_MAPVIEW_POLYLINE_H_

#include <FLocCtrlNativeMapOverlay.h>
#include <FLocPolygonGeographicArea.h>
#include <FGrpColor.h>
#include <FGrpCanvasCommon.h>

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayPolyline;

/**
* @class	MapOverlayPolyline
* @brief	This class defines the common behaviors for a polyline.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %MapOverlayPolyline class displays a polyline overlay. It also provides the methods for getting the rectangle bounds and the points of a polyline, and the first item of its coordinates list. @n
* The Map control renders each edge of the overlay as a straight line on the map and not as a geodesic (a segment of a Great circle).
*
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
*/
class _EXPORT_LOCATION_CONTROL MapOverlayPolyline :
	public Osp::Locations::Controls::NativeMapOverlay
{
public:
	
	/**
	 * Gets the first item of the coordinates list of the polyline.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The coordinates of the first item of the polyline
	 */
	virtual Osp::Locations::Coordinates GetCoordinates(void) const;

	/**
	* Gets the rectangle bound of the polyline.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompMapPolylineGetBoundsPage "here".
	*
	* @return			The rectangle bound of the polyline
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const;

	/**
 	* @page		CompMapPolylineGetBoundsPage  Compatibility for GetBounds()
 	*
 	* @section	CompMapPolylineGetBoundsPageIssueSection Issues
 	*			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
 	*			-# An application can get terminated when it dereferences the invalid RectangleGeographicArea object returned by the MapOverlayPolyline::GetBounds() method.
 	*
 	* @section	CompMapPolylineGetBoundsPageResolutionsSection Resolutions
 	* 			The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above.
 	*
 	* @par
	* 			When working with bada API versions prior to 1.2:
 	*			Developers must implement their own algorithm to get the bounds of the polyline, which is the smallest rectangular area that can be drawn around it.
 	*/

protected:

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the polyline.
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
	* Draws the shadow of the polyline.
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
	* This is not supported.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	This method returns @c false
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const;

public:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	MapOverlayPolyline(void);

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~MapOverlayPolyline(void);

	/**
	* @deprecated
	* This constructor is deprecated because a new parameter has been introduced.
	* Instead of using this constructor, use Construct(IList& coordinates, bool simplify).
	*
	* Initializes this instance of %MapOverlayPolyline with the specified parameter.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	coordinates		The List instance of the polyline
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE This instance has already been constructed.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_SYSTEM        The method has failed.
	*/
	result Construct(const Osp::Base::Collection::IList& coordinates);

	/**
	* Initializes this instance of %MapOverlayPolyline with the specified parameters. @n
	* %MapOverlayPolyline is able to simplify a given polyline with a large number of points. This allows the faster drawing of a polyline on a map at the 
	* cost of initial processing time.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.2
	*
	* @return		An error code
	* @param[in]	coordinates		The List instance of a polyline
	* @param[in]	simplify        Set to @c true to enable the polyline simplification, @n
	*								else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c polyline contains less than two coordinates.
	* @exception	E_INVALID_ARG   The specified @c polyline has elements that are not coordinate objects.
	* @exception	E_INVALID_STATE This instance has already been constructed.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_SYSTEM        The method has failed.
	* @remarks		This method does not support the polyline that has the derived classes of Coordinates,
	*				including QualifiedCoordinates, for performance.
	*/
	result Construct(const Osp::Base::Collection::IList& coordinates, bool simplify);

	/**
	* Sets the stroke (line) color of the polyline. @n
	* The default color is black.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	color	The color to be set
	*/
	void SetStrokeColor(const Osp::Graphics::Color & color);

	/**
	* Gets the stroke (line) color of the polyline.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The stroke (line) color of the polyline
	*/
	Osp::Graphics::Color GetStrokeColor(void) const;

	/**
	*
	* Sets the stroke (line) weight of the polyline. @n
	* The default weight is @c 3. The minimum value of @c weight is @c 1 and the maximum value of @c weight is @c 100.
	* @deprecated	This method is deprecated because a new method has been introduced. @n
	* 				Instead of using this method, use the SetStrokeWidth(int width) method that
	*				does not change the line width of the polyline depending on the zoom level of the map.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	weight  		The weight to be set
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	*/
	result SetStrokeWeight(int weight);

	/**
	* Sets the stroke (line) width of the polyline. @n
	* The default width is @c 3. The minimum value of @c width is @c 1 and the maximum value of @c width is @c 100.
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return      An error code
	* @param[in]   width  			The line width in pixels
	* @exception   E_SUCCESS		The method is successful.
	* @exception   E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	*/
	result SetStrokeWidth(int width);

	/**
	*
	* Gets the stroke (line) weight of the polyline.
	*
	* @deprecated	This method is deprecated because a new method has been introduced. @n
	* 				Instead of using this method, use the GetStrokeWidth() method.
	*
	* @since		1.0
	* @return		The stroke (line) weight of the polyline
	*/
	int GetStrokeWeight(void) const;

	/**
	* Gets the stroke (line) width of the polyline in pixels.
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return		The stroke (line) width of the polyline in pixels
	*/
	int GetStrokeWidth(void) const;

	/**
	* Sets the stroke (line) style of the polyline. @n 
	* The default style is solid.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	lineStyle	The LineStyle to be set
	*/
	void SetStrokeStyle(Osp::Graphics::LineStyle lineStyle);

	/**
	* Gets the stroke (line) style of the polyline.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The stroke (line) style of the polyline
	*/
	Osp::Graphics::LineStyle GetStrokeStyle(void) const;

	/**
	* Gets the points of the polyline.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The points of the polyline
	*/
	const Osp::Base::Collection::IList* GetPolylinePoints(void) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of MapOverlayPolyline to destination
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.
	*/
	result CopyData(__IMapOverlayPolyline& dest) const;

private:
	
	result SetStrokeWidth(int weight, bool adaptToZoomLevel);

private:

	/*
	* Canvas instance.
	*/
	Osp::Graphics::Canvas*	__pCanvas;				// not used

	/*
	* List instance.
	*/
	Osp::Base::Collection::IList*	__points;

	/*
	* The stroke(line) color of polyline.
	*/
	Osp::Graphics::Color __strokeColor;

	/*
	* The stroke(line) weight of polyline.
	*/
	int __strokeWeight;

	/*
	* The stroke(line) style of polyline.
	*/
	Osp::Graphics::LineStyle __strokeStyle;

private:
	
	friend class MapOverlayPolylineEx;
	class MapOverlayPolylineEx* __pMapOverlayPolylineEx;

};

};};};

#endif	// _FLOC_CTRL_MAPVIEW_POLYLINE_H_
