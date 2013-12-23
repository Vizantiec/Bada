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
* @file		FLocCtrlMapOverlayShape.h
* @brief	This is the header file for the %MapOverlayShape class.
*
* This header file contains the declarations of the %MapOverlayShape class.
*/

#ifndef _FLOC_CTRL_MAPVIEW_SHAPES_H_
#define _FLOC_CTRL_MAPVIEW_SHAPES_H_

#include <FLocCtrlNativeMapOverlay.h>
#include <FGraphics.h>

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayShape;

/**
 * @class	MapOverlayShape
 * @brief	This class defines the common behaviors for shapes (circle, rectangle, polygon, polyline).
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * 	The %MapOverlayShape class defines the common behaviors for shapes (circle, rectangle, polygon, polyline). The overlay layer is interactive and provides event handlers for shapes. With these event handlers, the applications can add interactivity, such 
 *			as opening a website for a restaurant on a map, exchanging data and interacting with an application, or drawing on a map.
 *
 * 
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
 */

class _EXPORT_LOCATION_CONTROL MapOverlayShape :
	public Osp::Locations::Controls::NativeMapOverlay
{
public:

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~MapOverlayShape(void);

	/**
	* Gets the center coordinates of the overlay shape.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The center coordinates of the overlay shape
	*/
	virtual Osp::Locations::Coordinates GetCoordinates(void) const;

	/**
	* Sets the stroke color of the overlay shape. @n
	* The default color is black.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	color	The color to be set
	*/
	void SetStrokeColor(const Osp::Graphics::Color & color);

	/**
	* Gets the stroke color of the overlay shape.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The stroke color of the overlay shape
	*/
	Osp::Graphics::Color GetStrokeColor(void) const;

	/**
	* Sets the stroke (line) weight of the overlay shape. @n
	* The default weight is @c 3. The minimum value of @c weight is @c 1 and the maximum value of @c weight is @c 100.
	*
	* @deprecated 	This method is deprecated because a new method has been added.
	* 				Instead of using this method, use the SetStrokeWidth(int width) method that
	*				does not change the line width of the shape depending on the zoom level of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return      An error code
	* @param[in]   weight  			The weight to be set
	* @exception   E_SUCCESS			The method is successful.
	* @exception   E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	*/
	result SetStrokeWeight(int weight);

	/**
	* Sets the stroke (line) width of an overlay shape. @n
	* The default width is @c 3. The minimum value of @c width is @c 1 and the maximum value of @c width is @c 100
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return      An error code
	* @param[in]   width			The line width in pixels
	* @exception   E_SUCCESS		The method is successful.
	* @exception   E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	*/
	result SetStrokeWidth(int width);

	/**
	*
	* Gets the stroke weight of the overlay shape.
	*
	* @deprecated 	This method is deprecated because a new method has been added.
	* 				Instead of using this method, use the GetStrokeWidth() method.
	* @since		1.0
	*
	* @return		The stroke weight of the overlay shape
	*/
	int GetStrokeWeight(void) const;

	/**
	* Gets the stroke width of the overlay shape in pixels.
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return		The stroke width of the overlay shape in pixels
	*/
	int GetStrokeWidth(void) const;

	/**
	* Sets the stroke style of the overlay shape. @n
	* The default style is solid.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	lineStyle	The LineStyle to be set
	*/
	void SetStrokeStyle(Osp::Graphics::LineStyle lineStyle);

	/**
	* Gets the stroke style of the overlay shape.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The stroke style of the overlay shape
	*/
	Osp::Graphics::LineStyle GetStrokeStyle(void) const;

	/**
	*
	* Fills the overlay shape with the given color. @n
	* This is a virtual method.
    * @deprecated  This virtual method is deprecated because the behavior of this method does not contain a draw
	* 				operation as Osp::Graphics::Canvas::FillRectangle() does.
	* 				Instead of using this method, use the SetFillColor(const Osp::Graphics::Color& color) method that will fill the color of the overlay 
	*				shape.
	*
	* @since		1.0
	* @param[in]	color	The color fill for the inside of the shape
	*/
	virtual void FillShape(const Osp::Graphics::Color& color);

	/**
	* Sets the fill color of the overlay shape.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @param[in]	color	The fill color to be set
	*/
	void SetFillColor(const Osp::Graphics::Color& color);

	/**
	* Gets the fill color of the overlay shape.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		The fill color of the overlay shape
	*/
	Osp::Graphics::Color GetFillColor(void) const;

protected:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	MapOverlayShape(void);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of MapOverlayShape to destination.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.
	*/	
	result CopyData(__IMapOverlayShape& dest) const;
	
private:
	
	result SetStrokeWidth(int weight, bool adaptToZoomLevel);

protected:

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Canvas instance.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Graphics::Canvas*	__pCanvas;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	* 
	* The stroke color of shape.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Graphics::Color __strokeColor;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The stroke weight of shape.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	int __strokeWeight;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The stroke style of shape.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Graphics::LineStyle __strokeStyle;
		
	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Determines whether to fill the rectangle or not.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	bool										__bFillColor;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* The color to be fill.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Graphics::Color						__fillColor;

private:
	
	friend class MapOverlayShapeEx;
	class MapOverlayShapeEx* __pMapOverlayShapeEx;

};

};};};

#endif
