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
 * @file		FGrpDimension.h 
 * @brief		This is the header file for the %Dimension class.
 *
 * This header file contains the declarations of the %Dimension class.
 */
#ifndef _FGRP_DIMENSION_H_
#define _FGRP_DIMENSION_H_


#include "FBaseObject.h"
#include "FGrpConfig.h"


namespace Osp { namespace Graphics {
/**
 * @class	Dimension
 * @brief	This class represents the width and height of a two dimensional region. 
 * @since	1.0
 *
 * The %Dimension class provides methods to abstract and set the width and height of a two dimensional region.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/shapes.htm">Shapes</a>.
 *
 */
class _EXPORT_GRP_ Dimension :
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class. @n
	 * This constructor initializes an instance of Dimension with the width and the height set as @c 0.
	 *
	 * @since	1.0
	 */
	Dimension(void);

	/** 
	 * Initializes an instance of Dimension with the specified values of width and height.
	 *
	 * @since			1.0
	 * @param[in]	width	The width to set
	 * @param[in]	height	The height to set 
	 */
	Dimension(int width, int height);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Dimension(void);

// Operator
public:
	/**
	 * Checks whether the two instances of Dimension have equal width and height values.
	 *
	 * @since			1.0
	 * @return		@c true if the values of width and height of the two instances of Dimension are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Dimension 
	 */
	bool operator ==(const Dimension& rhs) const;
		
	/**
	 * Checks whether the two instances of the Dimension have different width and height values.
	 *
	 * @since			1.0
	 * @return		@c true if the values of the width and the height of the two instances of Dimension are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Dimension
	 */
	bool operator !=(const Dimension& rhs) const;	

// Operation
public:
	/** 
	 * Checks whether the value of the current instance of %Dimension equals the value of the specified instance.
	 *
	 * @since			1.0
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
					else @c false
	 * @param[in]	obj		An instance of %Dimension
	 * @remarks 	The %Dimension class has a semantic value, which means that the
	 *				Equals() method checks whether the two instances have the same width and height.
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

// Accessor
public:
	/**
	 * Sets the size of the current instance of Dimension.
	 *
	 * @since			1.0
	 * @param[in]	width		The new width
	 * @param[in]	height		The new height
	 */
	void SetSize(int width, int height);

// Attribute
public:
	/**
	 *	The width of the current instance of Dimension.
	 *
	 *	@since	1.0
	 */
	int width;

	/**
	 *	The height of the current instance of Dimension.
	 *
	 * 	@since	1.0
	 */
	int height;

private:
	friend class DimensionEx;
	class DimensionEx* __pDimensionEx;

};

}; }; // Osp::Graphics

#endif //_FGRP_DIMENSION_H_


