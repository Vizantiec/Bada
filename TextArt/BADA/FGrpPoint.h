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
 * @file		FGrpPoint.h 
 * @brief		This is the header file for the %Point class.
 *
 * This header file contains the declarations of the %Point class.
 */
#ifndef _FGRP_POINT_H_
#define _FGRP_POINT_H_


#include "FBaseObject.h"
#include "FGrpConfig.h"


namespace Osp { namespace Graphics {
/**
 * @class	Point
 * @brief	This class encapsulates a point in a two-dimensional coordinate system.
 * @since	1.0
 *
 * The %Point class represents a location in a two-dimensional coordinate space specified with an integer precision.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/shapes.htm">Shapes</a>.
 */
class _EXPORT_GRP_ Point :
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class. @n
	 * This initializes an instance of Point with the values (0, 0).
	 *
	 * @since	1.0
	 */
 	Point(void);
 	 	
 	/** 
	 * This constructor initializes an instance of Point with the specified location.
	 *
	 * @since			1.0
	 * @param[in]	x  The x-coordinate
	 * @param[in]	y  The y-coordinate
	 */
	Point(int x, int y);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Point(void);

// Operator
public:
	/**
	 * Checks whether the current instance and the specified instance of Point are equal.
	 *
	 * @since			1.0
	 * @return		@c true if the two instances of Point are at the same location, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Point
	 */
	bool operator ==(const Point& rhs) const;
	
	/**
	 * Checks whether the current instance and the specified instance of Point are not equal.
	 *
	 * @since			1.0
	 * @return		@c true if the two instances of Point are at different locations, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Point
	 */
	bool operator !=(const Point& rhs) const; 

	/**
	 * Adds the value of the specified instance of Point and the current instance.
	 *
	 * @since			1.0
	 * @return		A new instance of Point containing the resulting value of the operation
	 * @param[in]	rhs		An instance of %Point
	 */
	Point operator +(const Point& rhs) const;

	/**
	 * Subtracts the value of the specified instance of Point and the current instance.
	 *
	 * @since			1.0
	 * @return		A new instance of Point containing the resulting value of the operation
	 * @param[in]	rhs		An instance of %Point
	 */
	Point operator -(const Point& rhs) const;

	/**
	 * Adds the value of the specified instance of Point to the current instance.
	 *
	 * @since			1.0
	 * @param[in]	point		An instance of %Point
	 */
	void operator +=(const Point& point);

	/**
	 * Subtracts the value of the specified instance of Point from the current instance.
	 *
	 * @since			1.0
	 * @param[in]	point		An instance of %Point
	 */
	void operator -=(const Point& point);
	
// Operation
public:
	/** 
	 * Checks whether the value of the specified instance of Point equals the value of the current instance.
	 *
	 * @since			1.0
	 * @return		@c true if the value of the specified instance equals the value of the current instance, @n
					else @c false
	 * @param[in]	obj		An instance of %Point
	 * @remarks 	The %Point class has a semantic value, which means that the
	 *				Equals() method checks whether the two instances have the same
	 *				location.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 *	Gets the hash value of the current instance.
	 *
	 *  @since		1.0
	 *	@return		The hash value of the current instance
	 *	@remarks 	Two equal instances should return the same hash value. For better performance, 
	 *				the used hash function must generate a random distribution for all inputs.	 
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Sets the x and y coordinates for the current instance of Point.
	 *
	 * @since			1.0
	 * @param[in]	x	The new x-coordinate
	 * @param[in]	y	The new y-coordinate
	 */
	void SetPosition(int x, int y);

	/**
	 * Sets the current instance of Point.
	 *
	 * @since			1.0
	 * @param[in]	point	An instance of %Point
	 */
	void SetPosition(const Point& point);

	/**
	 * Translates this Point to the indicated distance.
	 *
	 * @since			1.0
	 * @param[in]	deltaX	The distance to move this point along the x-axis
	 * @param[in]	deltaY	The distance to move this point along the y-axis
	 */
	void Translate(int deltaX, int deltaY);

// Attribute
public:
	/**
	 *	The x-coordinate of the point.
	 *
	 *  @since	1.0
	 */
	int x;

	/**
	 *	The y-coordinate of the point.
	 *
	 *  @since	1.0
	 */
	int y;

private:
	friend class PointEx;
	class PointEx* __pPointEx;

};

}; }; // Osp::Graphics

#endif //_FGRP_POINT_H_

