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
 * @file		FGrpCanvas.h 
 * @brief		This is the header file for the %Canvas class.
 *
 * This header file contains the declarations of the %Canvas class. 
 */
#ifndef _FGRP_CANVAS_H_
#define _FGRP_CANVAS_H_


#ifdef DrawText
#undef DrawText
#endif


#include "FBase.h"
#include "FBaseObject.h"
#include "FBaseColArrayListT.h"
#include "FGrpConfig.h"
#include "FGrpColor.h"
#include "FGrpBitmap.h"
#include "FGrpRectangle.h"
#include "FGrpColor.h"
#include "FGrpCanvasCommon.h"
#include "FGrpBufferInfo.h"
#include "FGrpPixelFormat.h"
#include "FGrpEnrichedText.h"

namespace Osp { namespace Graphics { class Font; } }
namespace Osp { namespace Graphics { class EnrichedText; };};


namespace Osp {namespace Graphics {
/**
 * @class	Canvas
 * @brief	This class provides methods for drawing objects.
 * @since	1.0
 *
 * The %Canvas class provides a rectangular region to draw objects on the display device. The %Canvas instance is 
 * associated with a specific context.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/canvas.htm">Canvas</a>.
 *
 */
class _EXPORT_GRP_ Canvas :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be 
	 *				called explicitly to initialize this instance.
	 */
	Canvas(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Canvas(void);

	/**
	 * Initializes this instance of %Canvas to create a canvas control of the same size as that of the 
	 * device screen.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);	

	/**
	 * @page  	CanvasConstruct 	Compatibility for Construct()
	 * @section CompClassNameMethodNamePageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue:
	 *
 	 * -# The x and y coordinates correspond to the top-left corner of the screen (0,0).
 	 *
 	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
 	 *
 	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	 *
	 * @par When working with bada API versions prior to 1.2:
	 * 
	 * -# Creates a Window Canvas control, which is retrieved from the UI Controls.
	 * -# Copy a normal %Canvas control onto the Window Canvas control, and then display it at the specified screen position.	 
	 */

	/**
	 * Initializes this instance of %Canvas with the specified parameter.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *              For more information, see @ref CanvasConstruct "here".
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the canvas control on the device screen @n
	 *								The width and height of the rectangle must be greater than @c 0.
	 *								If this condition is not satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Construct(const Rectangle& rect);

// Operation
public:
	/**
	 * Clears the current instance of %Canvas with the background color.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result Clear(void);

	/**
	 * Clears a rectangular region of the current instance of %Canvas with the background color.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangular region @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangular region should not fall outside the edges of the 
	 *								current instance of %Canvas entirely.If these conditions are not 
	 *								satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result Clear(const Rectangle& rect);

	/**
	 * Copies the specified rectangular region from the specified instance of %Canvas to the current instance of 
	 * %Canvas at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	destPoint			The location to copy the rectangular region
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the rectangular region on the source %Canvas @n
	 *									The rectangular region should not fall outside the edges of 
	 *									the current instance of %Canvas entirely. If this condition is 
	 *									not satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result Copy(const Point& destPoint, const Canvas& srcCanvas, const Rectangle& srcRect);

	/**
	 * Copies the scaled image of the specified rectangular region from the specified instance of 
	 * %Canvas to the current instance of %Canvas.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	destRect			The location and size of the destination image @n
	 *									The value of @c destRect should not fall outside the edges of 
	 *									the current instance of %Canvas entirely. If this condition is 
	 *									not satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the source image @n
	 *									The value of @c srcRect should not fall outside the edges of 
	 *									the current instance of %Canvas entirely. If this condition is 
	 *									not satisfied, the E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result Copy(const Rectangle& destRect, const Canvas& srcCanvas, const Rectangle& srcRect);

	/**
	 * Gets the line style set for the current instance of %Canvas.
	 *				    
	 * @since		1.0
	 * @return		An instance of %LineStyle
	 */
	LineStyle GetLineStyle(void) const;

	/**
	 * Gets the line width of the current instance of %Canvas.
	 *			
	 * @since		1.0	    
	 * @return		The line width, @n
	 *				else @c -1 if the method fails
	 */
	int GetLineWidth(void) const;	

	/**
	 * Sets the line style for the current instance of %Canvas.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	style				The new line style for the %Canvas control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result SetLineStyle(LineStyle style);

	/**
	 * Sets the line width for the current instance of %Canvas.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	width				The new width for the %Canvas control @n
	 *									The width for the %Canvas control must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result SetLineWidth(int width);

	/**
	 * Gets the color information at the specified point.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point should not fall outside the edges of %Canvas. If this 
	 *								condition is not satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @param[out]	color			An instance of %Color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result GetPixel(const Point& point, Color& color);

	/**
	 * Draws a point at the specified coordinate.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point should not entirely fall outside the edges of %Canvas. 
	 *								If this condition is not satisfied, the E_OUT_OF_RANGE exception 
	 *								is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result SetPixel(const Point& point);

	/**
	 * Draws a line between the two specified points.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point1				The starting point
	 * @param[in]	point2				The end point
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawLine(const Point& point1, const Point& point2);	

	/**
	 * Draws a rectangle.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect				The rectangle to be drawn on the %Canvas control @n
	 *									The width and height of the rectangle must be greater than or equal to @c 0.
	 *									The rectangle should not entirely fall outside the edges of 
	 *									the %Canvas control. If these conditions are not satisfied, 
	 *									the E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawRectangle(const Rectangle& rect);
	
	/**
	 * @page 	CanvasFillPolygon 	Compatibility for FillPolygon()
	 * @section CompClassNameMethodNamePageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 * -# If there are four input points and the below mentioned condition is satisfied, the result of the drawing does not match the expected behavior. @n
	 * "point[0].x == point[3].x && point[1].x == point[2].x && point[0].y == point[1].y && point[2].y == point[3].y"
	 *
	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
	 *
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 *
	 * @par When working with bada API versions prior to 2.0:
	 * 
	 * -# The Canvas::FillRectangle() method must be used for drawing filled rectangles.
	 */

	/**
	 * Fills a rectangular region of the current instance of %Canvas with the specified color.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The rectangular region on the %Canvas control @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result FillRectangle(const Color& color, const Rectangle& rect);

	/**
	 * Draws a round-edged rectangle.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangle @n
	 *					    		The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *					    		The width and height in the @c arcDim parameter must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result DrawRoundRectangle(const Rectangle& rect, const Dimension& arcDim);
	
	/**
	 * Draws a filled rectangle.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *								The width and height mentioned in the @c arcDim parameter must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result FillRoundRectangle(const Color& color, const Rectangle& rect, const Dimension& arcDim);

	/**
	 * Draws an ellipse.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *					    		The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result DrawEllipse(const Rectangle& rect);

	/**
	 * Draws a filled ellipse with the specified color.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0. @n
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result FillEllipse(const Color& color, const Rectangle& rect);

	/**
	 * @page 	CanvasDrawArc 	Compatibility for DrawArc()
	 * @section 	CompClassNameMethodNamePageIssueSection Issues
 	 * @section 	CompCanvasDrawArcPageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 *
	 * -# The value of @c rect should be a regular square.
	 *    If it is not a regular square, the start or end angle of the drawing result does not match the expected one.
	 *
	 * @section 	CompCanvasDrawArcPageIssueSection Resolutions
	 *
	 * The issue mentioned above is resolved in bada API version 2.0.
	 */
	 
	/**
	 * Draws a circular arc.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
 	 *                For more information, see @ref CanvasDrawArc "here".
	 * 		
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	startAngle		The starting angle 
	 * @param[in]	endAngle		The ending angle 
	 * @param[in]	arcStyle		The arc style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result DrawArc(const Rectangle& rect, int startAngle, int endAngle, ArcStyle arcStyle);

	/**
	 * Draws a triangle.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawTriangle(const Point& point1, const Point& point2, const Point& point3);	

	/**
	 * Draw a filled triangle with the specified color.
	 * 
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	color				The fill color
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result FillTriangle(const Color& color, const Point& point1, const Point& point2, const Point& point3);

	/**
	 * Draws a poly-line.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	points				A list containing the location of points @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawPolyline(const Osp::Base::Collection::IList& points);

	/**
	 * Draws a polygon.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	points				A list containing the locations of the vertices of the polygon @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawPolygon(const Osp::Base::Collection::IList& points);

	/**
	 * Draws a filled polygon with the specified color.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *             For more information, see @ref CanvasFillPolygon "here".
	 *	 
	 * @return		An error code
	 * @param[in]	color				The fill color
	 * @param[in]	points				A list containing the locations of the vertices of the polygon @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result FillPolygon(const Color& color, const Osp::Base::Collection::IList& points);

	/**
	 * Sets a font to the %Canvas control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	font				The font @n
	 *									It should be constructed before being passed to this method.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result SetFont(const Font& font);

	/**
	 * Creates and returns a font of the %Canvas control.
	 *
	 * @since		1.0
	 * @return		The font of the %Canvas control, @n
	 *				else @c null if the method fails
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE     This instance is in an invalid state.
	 * @exception 	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
 	 * @remarks 	If a font is not set with the SetFont() method, this method returns the system default font.
	 */
	Font* GetFontN(void);

	/**
	 * Draws a text at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
 	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks  	The foreground color (RGB value only) of the %Canvas control is used as the text color.
     * @remarks  	The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.

	 */
	result DrawText(const Point& point, const Osp::Base::String& text);

	/**
	 * Draws a text at the specified location and length.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @param[in]	length				The number of characters in the string @n
	 *									It must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks  	The foreground color (RGB value only) of the %Canvas control is used as the text color.
 	 * @remarks  	The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.

	 */
	result DrawText(const Point& point, const Osp::Base::String& text, int length);

	/**
	 * Draws a text with an outline rendering at the specified location.
	 *
	 * @since        1.1
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw @n
	 *                                   It must be greater than or equal to @c 0.
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @exception    E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks  	The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 * @remarks  	The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.

	 */
	result DrawText(const Point& point, const Osp::Base::String& text, const Color& outlineColor);

	/**
	 * Draws a text with an outline rendering at the specified location and length.
	 *
	 * @since        1.1
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw
	 * @param[in]    length              The number of characters in the string @n
	 *                                   It must be greater than or equal to @c 0.
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @exception    E_INVALID_STATE     This instance is in an invalid state.
	 *
	 * @remarks  	The foreground color (RGB value only) of the %Canvas control is used as the text color.
 	 * @remarks  	The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.

	 */
	result DrawText(const Point& point, const Osp::Base::String& text, int length, const Color& outlineColor);

	/** 
	 * @page GraphicsCanvasDrawTextEnrichedTextPage Compatibility for DrawText()
	 *
	 * @section GraphicsCanvasDrawTextEnrichedTextPageIssuesSection Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	 * -# The clipped rectangular area of a canvas does not work for drawing the enriched text. 
	 * The final result of the enriched text is not restricted within the clipped rectangular area of the canvas.
	 *
	 * @section GraphicsCanvasDrawTextEnrichedTextPageResultionsSection Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Draws an enriched text at the specified area.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n.
	 *					For more information, see @ref GraphicsCanvasDrawTextEnrichedTextPage "here".
	 * @return		An error code
	 * @param[in]	point					The location to draw the text
	 * @param[in]	enrichedText			The TextElement to draw
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	A specified device is invalid.
	 * @exception	E_INVALID_STATE			The text drawing cannot be executed with the specified text length.
	 *
	 * @remarks  The foreground color (RGB value only) of the %Canvas control is used as the text color.
 	 * @remarks  The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const EnrichedText& enrichedText);

	/**
	 * Draws a bitmap image at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point				The location of the upper-left corner of the bitmap
	 * @param[in]	bitmap				The bitmap to draw @n
	 *									It should be constructed before being passed into this 
	 *									method. BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is 
	 *									not applicable for this method. The bitmap should not 
	 *									entirely fall outside the edges of the %Canvas control. If 
	 *									this condition is not satisfied, the E_OUT_OF_RANGE exception 
	 *									is thrown.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap);

	/**
	 * Draws a bitmap image at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The location and size of the scaled bitmap @n
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If this condition is not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It should be constructed well before being passed into this 
	 *								method. BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not 
	 *								applicable for this method.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
 	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result DrawBitmap(const Rectangle& rect, const Bitmap& bitmap);

	/** 
	 * Draws a color data corresponding to a rectangle of pixels from the specified bitmap onto %Canvas.	   
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	destRect  		The destination rectangle of %Canvas @n 
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle defined by @c destRect will be clipped at the edges 
	 *								of the %Canvas control to prevent the rectangle from falling 
	 *								outside the edges of the %Canvas control. The destination 
	 *								rectangle of a %Canvas control should not fall outside the edges 
	 *								of the %Canvas control entirely. If these conditions are not 
	 *								satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	srcBitmap		The bitmap to draw
	 * @param[in]	srcRect			The source rectangle of a bitmap @n 
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle defined by @c srcRect will be clipped at the edges 
	 *								of the bitmap to prevent the rectangle from falling outside the 
	 *								edges of the bitmap. The source rectangle of a bitmap should not 
	 *								fall outside the edges of the bitmap entirely. If these 
	 *								conditions are not satisfied, the E_OUT_OF_RANGE exception is 
	 *								thrown.
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.	 
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.	 
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If the source and destination rectangles are not of the same size, 
	 *				the source bitmap is stretched to match the destination rectangle. @n
 	 *				BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const Rectangle& destRect, const Bitmap& srcBitmap, const Rectangle& srcRect);

	/**
	 * Draws a flipped bitmap image at the specified location.
	 *
	 * @since		1.0
	 * @return      An error code
	 * @param[in]   point			The location to draw the bitmap
	 * @param[in]   bitmap          The bitmap to draw @n
	 *                              It should be constructed before being passed to this method.
	 * @param[in]   dir             The flip direction
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @remarks		BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.               
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap, FlipDirection dir);
	
	/**
	 * Draws a rotated bitmap image at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	point			A location to draw a bitmap image @n
     *                              This location is relatively defined from the origin (upper-left 
	 *								corner) of the %Canvas control.
	 * @param[in]   bitmap           The bitmap to draw @n
     *                               It should be constructed before being passed to this method.
     * @param[in]   pivot            The center of rotation of a bitmap image @n
     *                               This center is relatively defined from the origin (upper-left 
	 *								corner) of the bitmap.
	 * @param[in]   degree           The amount of rotation in degrees
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state.
	 * @exception   E_INVALID_ARG    A specified input parameter is invalid.
	 *
	 * @remarks     BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
     * @image		html	graphics_rotatebitmap.PNG
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap, const Point& pivot, int degree);
	
	/**
	 * Draws a nine-patched bitmap at the specified location.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   rect			The location and size of the nine-patched bitmap @n
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If this condition is not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It should be constructed before being passed to this method.
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
 	 * @remarks    BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method. @n 	 
 	 *             The nine-patched bitmap should have a stretchable section by drawing one (or more) 1-pixel-wide black line(s) in the
 	 *             left and top part of the border.
     * @image			html	graphics_ninepatchedbitmap.PNG
	 *
	 */
	result DrawNinePatchedBitmap(const Rectangle& rect, const Bitmap& bitmap);
	
	/**
	 * Displays the current instance of %Canvas on the device screen.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result Show(void);

	/**
	 * Displays the specified rectangle of the current instance of %Canvas on the device screen.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The bounds of the %Canvas control to display @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle should not entirely fall outside the edges of the 
	 *								%Canvas control. If these conditions are not satisfied, the 
	 *								E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result Show(const Rectangle& rect);

	/**
	 * @page 	CanvasGetBounds 	Compatibility for GetBounds()
 	 * @section CompCanvasGetBoundsPageIssueSection Issues
	 * Implementation of this method in bada API version 1.1 has the following issues: @n
	 *
	 * -# If the following conditions are satisfied, this method may return incorrect results.
 	 * 	- The application is developed for WVGA (800*480) by using the bada API version 1.1
	 * 	- The application runs on WQVGA (400*240) device
	 *	- The width and height values of the Window Canvas control are not clipped by its parent control
	 * 	- The Window Canvas control has the following bounds: @n
	 * (x > 0 || y > 0) && ((x + width > parent control width) || (x + height > parent control height))
	 *
	 * @section	CompCanvasGetBoundsPageIssueSection	Resolutions
	 * The issue occurs only for the conditions described above.
	 * 
	 * @par The following things can be done when meeting with the above mentioned condition:
	 * -# The bounds of the Window Canvas control should be made to fit into its parent control.
	 * -# The width and height of the bounds of the Window Canvas control should be made smaller than 
	 *	or equal to that of its parent control.
	 *
	 */
	
	/**
	 * Gets the location and size of the current %Canvas instance on the device screen.
	 *
	 * @since	1.0
	 * @compatibility This method has compatibility issues in bada API version @b 1.1 @b only. All other versions are compatible. @n
	 * For more information, see the issue description for @ref CanvasGetBounds "here".
	 *
	 * @return 	The Rectangle instance containing the location and size of the current %Canvas instance
	 * @remarks If this %Canvas instance is a Window Canvas, it returns Rectangle(0, 0, w, h).
	 */
	Rectangle GetBounds(void) const;

	/** 
	 * Sets the clip rectangle for a %Canvas control. @n
	 * When a clip rectangle is set, any drawing is restricted within the specified rectangular area. The 
	 * rectangular area defined is clipped at the edges of the %Canvas control so as to prevent the clipped rectangle
	 * from falling outside the %Canvas control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The bounds of the clip rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The clip rectangle for a Canvas control should not entirely fall 
	 *								outside the edges of the Canvas control. If these conditions are 
	 *								not satisfied, the E_OUT_OF_RANGE exception is thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result SetClipBounds(const Rectangle& rect);

	/** 
	 * Gets the bounds of the clip rectangle of a %Canvas control.
	 *
	 * @since		1.0
	 * @return		An instance of %Rectangle indicating the bounds of the clip rectangle
	 */
	Rectangle GetClipBounds(void) const;
	
	/** 
	 * Locks the %Canvas control for direct pixel access. @n
	 * This sets up a %Canvas control for accessing the pixels directly. Between the calls to the 
	 * Canvas::Lock() and Canvas::UnLock() methods, the data can be written to and read from the 
	 * Canvas control's pixels. Once the operations on the %Canvas control's pixels are finished, the 
	 * Canvas::Unlock() method must be called to release the lock.	 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	info			The information of the %Canvas control
	 * @param[in]	timeout			The time, in milliseconds, that the caller waits for the lock to be obtained @n
	 *								If the lock attempt fails, E_TIMEOUT is thrown. The default value 
	 *								is INFINITE, which means that the method does not return until the lock 
	 *								is acquired.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_TIMEOUT		The operation cannot be completed within the specified time period.
	 * @exception	E_SYSTEM 		An unknown operating system error has occurred. 
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
	 * @remarks 	BufferInfo contains a valid physical memory information, regardless of the 
	 *				logical position and size of the %Canvas control.
	 */	
	result Lock(BufferInfo& info, long timeout = INFINITE);

	/** 
	 * Unlocks the %Canvas control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM 			An unknown operating system error has occurred. 
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The %Canvas control should be unlocked as soon as possible.
	 */
	result Unlock(void);

	/** 
	 * Sets the foreground color.
	 *
	 * @since		1.0
	 * @param[in]	color	The color that is set as foreground color
     */
	void SetForegroundColor(const Color& color);

	/** 
	 * Gets the foreground color.
	 *
	 * @since		1.0
	 * @return		The foreground color
	 */
	Color GetForegroundColor(void);

	/** 
	 * Sets the background color.	 
	 *
	 * @since		1.0
	 * @param[in]	color	The color that is set as background color
	 */
	void SetBackgroundColor(const Color& color);

	/** 
	 * Gets the background color.
	 *
	 * @since		1.0
	 * @return		The background color
	 */
	Color GetBackgroundColor(void);

	/**
	 * @page  	CanvasSetPosition 	Compatibility for SetPosition()
	 * @section CompClassNameMethodNamePageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 *
 	 * -# The x and y coordinates correspond to the top-left corner of the screen (0,0).
 	 *
 	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
 	 *
 	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	 *
	 * @par When working with bada API versions prior to 1.2:
	 * 
	 * -# Create a Window Canvas control, which is retrieved from the UI Controls.
	 * -# Copy a normal %Canvas control onto the Window Canvas control, and then display it at the specified screen position.	 
	 */	

	/**
	 * Moves the current instance of %Canvas to the specified point.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *              For more information, see @ref CanvasSetPosition "here".
	 *
	 * @return		An error code
	 * @param[in]	point					The new position
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	Window Canvas does not support moving the position.	 
	 */
	result SetPosition(const Point& point);

	/**
	 * @page  	CanvasSetPosition2 	Compatibility for SetPosition()
	 * @section CompClassNameMethodNamePageIssueSection Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 *
 	 * -# The x and y coordinates correspond to the top-left corner of the screen (0,0).
 	 *
 	 * @section CompClassNameMethodNamePageSolutionSection Resolutions
 	 *
 	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	 *
	 * @par When working with bada API versions prior to 1.2:
	 * 
	 * -# Create a Window Canvas control, which is retrieved from the UI Controls.
	 * -# Copy a normal %Canvas control onto the Window Canvas control, and then display it at the specified screen position.	 
	 */	

	/**	 
	 * Moves the current instance of %Canvas to the specified point.
	 *
	 * @since		1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref CanvasSetPosition2 "here".
	 *
	 * @return		An error code
	 * @param[in]	x						The new x-coordinate
	 * @param[in]	y						The new y-coordinate
	 * @exception	E_SUCCESS				The method is successful.
  	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	Window Canvas does not support moving the position.	 	 
	 */
	result SetPosition(int x, int y);


// Lifecycle
private:
	Canvas(const Canvas& canvas);
	Canvas& operator =(const Canvas& value);

	friend class Bitmap;
	friend class BitmapEx;
	friend class TextElement;

protected:
	struct __Canvas;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * The value for internal usage.
	 *
	 * @since  1.0
	 */
	__Canvas* __pImpl;

private:
	friend class CanvasEx;
	class CanvasEx* __pCanvasEx;

}; 

} } // Osp::Graphics

#endif //_FGRP_CANVAS_H_

