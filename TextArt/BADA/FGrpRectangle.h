/* $Change: 1028567 $ */
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
 * @file		FGrpRectangle.h 
 * @brief		This is the header file for the %Rectangle class.
 *
 * This header file contains the declarations of the %Rectangle class.
 */
#ifndef _FGRP_RECTANGLE_H_
#define _FGRP_RECTANGLE_H_


#include "FBaseObject.h"
#include "FGrpConfig.h"


namespace Osp { namespace Graphics { class Point; };};
namespace Osp { namespace Graphics { class Dimension; };};


namespace Osp { namespace Graphics {
/**
 * @class	Rectangle
 * @brief	This class abstracts a rectangular region.
 * @since	1.0
 *
 * The %Rectangle class represents a rectangular region in a coordinate space, which is specified by the rectangle 
 * object's top-left point (x, y) in the coordinate space, along with its width and height.
 *
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/shapes.htm">Shapes</a>.
 */
class _EXPORT_GRP_ Rectangle :
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class. @n
	 * It initializes an instance of %Rectangle with x(=0), y(=0), width(=-1), height(=-1).
	 *
	 * @since		1.0
	 * @remarks		The attribute value is @c 0 when initialized.
	 */
	Rectangle(void);
	
	/** 
	 * Initializes an instance of %Rectangle with the specified location and dimension.
	 *
	 * @since		1.0
	 * @param[in]	x		The x coordinate of the top-left corner of the rectangle
	 * @param[in]	y		The y coordinate of the top-left corner of the rectangle
	 * @param[in]	width	The width of the rectangle
	 * @param[in]	height	The height of the rectangle
	 *
	 */
	Rectangle(int x, int y, int width, int height);

	/**
	 * Initializes an instance of %Rectangle at the location specified by @c point and 
	 * with dimension specified by @c dim.
	 *	
	 * @since		1.0
	 * @param[in]	point		The location of the top-left corner of the rectangle
	 * @param[in]	dim			The width and height of the rectangle
	 */
	Rectangle(const Point& point, const Dimension& dim);
	
	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Rectangle(void);

// Operation
public:
	/**
	 * Checks whether the location and dimension of the current instance of %Rectangle match those of the 
	 * specified instance of %Rectangle.
	 *
	 * @since		1.0
	 * @return		@c true if the location and dimension of the current instance match those of the specified instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Rectangle
	 */
	bool operator ==(const Rectangle& rhs) const;
		
	/**
	 * Checks whether the location and dimension of the current instance of %Rectangle do not match those of the 
	 * specified instance of %Rectangle. 
	 *
	 * @since		1.0
	 * @return		@c true if the location and dimension of the current instance do not match those of the specified instance, @n
	 * 				else @c false
	 * @param[in]	rhs		An instance of %Rectangle
	 */
	bool operator !=(const Rectangle& rhs) const;

	/**
	 * Checks whether the specified point lies inside the current instance of %Rectangle.
	 *
	 * @since		1.0
	 * @return		@c true if the location represented by @c point lies inside the current instance of %Rectangle, @n
	 *				else @c false
	 * @param[in]	point	An instance of %Point
	 */
	bool Contains(const Point& point) const;

	/** 
	 * Checks whether the value of the current instance of %Rectangle equals the value of the specified instance of 
	 * %Rectangle.
	 *
	 * @since		1.0
	 * @return		@c true if the value of the current instance of Rectangle equals the value of the specified instance of %Rectangle, @n	 
	 *				else @c false
	 * @param[in]	obj		An instance of %Rectangle
	 * @remarks 	The %Rectangle class has a semantic value, which means that the Equals() method checks whether the 
	 * 				two instances have the same location and size.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	 * Replaces the value of the current instance of %Rectangle with the intersection of the current instance and 
	 * the specified instance of %Rectangle. @n
	 * If the two instances of %Rectangle do not intersect, the current instance is set to empty.
	 *
	 * @since		1.0
	 * @param[in]	rect	An instance of %Rectangle
	 */
	Rectangle GetIntersection(const Rectangle& rect) const;

	/**
	 * Checks whether the current instance of %Rectangle intersects with the specified instance of %Rectangle.
	 *		
	 * @since		1.0
	 * @return		@c true if the current instance of %Rectangle intersects with the specified instance of %Rectangle, @n
	 * 				else @c false
	 * @param[in]	rect	An instance of %Rectangle
	 *			
	 */
	bool IsIntersected(const Rectangle& rect) const;

	/**
	 * Computes the union of the specified and current instances of %Rectangle and stores the result in the current 
	 * instance.
	 *
	 * @since		1.0
	 * @return		An instance of %Rectangle containing the union of the two rectangles
	 * @param[in]	rect	An instance of %Rectangle
	 */
	Rectangle GetUnion(const Rectangle& rect) const;

	/**
	 * Gets the coordinates of the point at the bottom-right corner of the rectangle.
	 *
	 * @since		1.0
	 * @return		The coordinates of the point at the bottom-right corner of the rectangle
	 */
	Point GetBottomRight(void) const;

	/**
	 * Gets the coordinates of the point at the top-left corner of the rectangle.
	 *				    
	 * @since		1.0
	 * @return		The coordinates of the point at the top-left corner of the rectangle
	 */
	Point GetTopLeft(void) const;	

	/**
	 * Checks whether this %Rectangle is empty. @n
	 * A %Rectangle is empty if its width or its height is less than or equal to @c 0.
	 *
	 * @since		1.0
	 * @return		@c true if this rectangle is empty,	@n
	 *				else @c false
	 */
	bool IsEmpty() const;

	/**
	 * Sets the size of this %Rectangle to match the specified Dimension.
	 *
	 * @since		1.0
	 * @param[in]	dim		The new size for the %Dimension
	 */
	void SetSize(const Dimension& dim);

	/**
	 * Sets the size of this %Rectangle to match the specified dimension.
	 *
	 * @since		1.0
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetSize(int width, int height);

	/**
	 * Moves this %Rectangle to the specified point.
	 *
	 * @since		1.0
	 * @param[in]	point	The new position
	 */
	void SetPosition(const Point& point);

	/**
	 * Sets the location and the dimensions of the current instance of %Rectangle with the specified values of the 
	 * x and y coordinates of the top-left corner point and the width and height.
	 *
	 * @since		1.0
	 * @param[in]	x		The new x coordinate
	 * @param[in]	y		The new y coordinate
	 */
	void SetPosition(int x, int y);

	/**
	 * Sets the location and the dimensions of the current instance of %Rectangle with the specified x and y 
	 * coordinates of the top-left corner point and the specified dimensions.
	 *
	 * @since		1.0
	 * @param[in]	x		The new x coordinate
	 * @param[in]	y		The new y coordinate
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the location and the dimensions of the current instance of %Rectangle with the specified location and 
	 * dimension.
	 *
	 * @since		1.0
	 * @param[in]	point	An instance of %Point
	 * @param[in]	dim		An instance of %Dimension
	 */
	void SetBounds(const Point& point, const Dimension& dim);

	/**
	 * Translates this %Rectangle to the new point by the specified distance along the x axis and y axis.
	 *
	 * @since		1.0
	 * @param[in]	deltaX	The distance to move this %Rectangle along the x axis
	 * @param[in]	deltaY	The distance to move this %Rectangle along the y axis
	 */
	void Translate(int deltaX, int deltaY);

// Attribute
public:
	/**
	 * The x coordinate of the top-left corner of the rectangle.
	 *
	 * @since	1.0
	 */
	int x;

	/**
	 * The y coordinate of the top-left corner of the rectangle.
	 *
	 * @since	1.0
	 */
	int y;

	/**
	 * The width of this rectangle.
	 *
	 * @since	1.0
	 */
	int width;

	/**
	 * The height of this rectangle.
	 *
	 * @since	1.0
	 */
	int height;

private:
	friend class RectangleEx;
	class RectangleEx* __pRectangleEx;

};

}; }; // Osp::Graphics

#endif //_FGRP_RECTANGLE_H_

