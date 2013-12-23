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
 * @file		FGrpColor.h 
 * @brief		This is the header file for the %Color class.
 *
 * This header file contains the declarations of the %Color class. 
 *
 */
#ifndef _FGRP_COLOR_H_
#define _FGRP_COLOR_H_


#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FGrpConfig.h"


namespace Osp {namespace Graphics {
/**
 * @class	Color
 * @brief	This class encapsulates a color.
 * @since	1.0
 *
 * The %Color class provides an ARGB (Alpha, Red, Green, Blue) color model.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/color.htm">Color</a>.
 */
class _EXPORT_GRP_ Color :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Color(void);

	/**
	 * This is the copy constructor for the Color class. @n
	 * This constructor initializes the instance of Color with the attributes of the specified instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	color	An instance of %Color
	 */
	Color(const Color& color);

	/**
	 * This constructor initializes the instance of Color with the specified ARGB values.
	 *
	 * @since			1.0
	 * @param[in]	r	The red component
	 * @param[in]	g	The green component
	 * @param[in]	b	The blue component
	 * @param[in]	a	The alpha component
	 */
	Color(byte r, byte g, byte b, byte a = 0xFF);

	/**
	 * This constructor initializes the instance of Color with the specified RGB value.
	 *
	 * @since			1.0
	 * @param[in]	rgb			The RGB color value
	 * @param[in]	hasAlpha	Set to @c true if @c rgb contains an alpha value, @n
								else @c false
	 */
	Color(unsigned int rgb, bool hasAlpha = true);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Color(void);

//Operator
public:
	/**
	 * Checks whether the two instances of Color are equal.
	 *
	 * @since			1.0
	 * @return		@c true if the values of the two instances of Color are similar, @n
					else @c false
	 * @param[in]	rhs		An instance of %Color
	 */
	bool operator ==(const Color& rhs) const;

	/**
	 * Checks whether the two instances of Color are not equal.
	 *
	 * @since			1.0
	 * @return		@c true if the values of the two instances of Color are not similar, @n
					else @c false
	 * @param[in]	rhs		An instance of %Color
	 *
	 */
	bool operator !=(const Color& rhs) const;

	/**
	 * Assigns the values of the RGB components of the specified instance to the current instance of Color.
	 *
	 * @since			1.0
	 * @return		The reference to the instance of Color
	 * @param[in]	rhs		An instance of %Color
	 */
	Color& operator =(const Color& rhs);

// Operation
public:
	/** 
	 * Checks whether the current instance of Color equals the specified instance of Color.
	 *
	 * @since			1.0
	 * @return		@c true if the values of the current instance is equal to the value of the specified instance, @n
					else @c false
	 * @param[in]	obj		An instance of %Color
	 * @remarks 	This method overrides Osp::Base::Object::Equals(). This method uses the values of the RGB components to compare the two instances.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 *	Gets the hash value of the current instance of Color.
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
	 * Gets the value of the alpha component of the current instance of Color.
	 *
	 * @since		1.0
	 * @return	A @c byte representation of the alpha component of the current instance of Color
	 */
	byte GetAlpha(void) const;

	/**
	 * Gets the value of the blue component of the current instance of Color.
	 *
	 * @since		1.0
	 * @return	A @c byte representation of the blue component of the current instance of Color
	 */
	byte GetBlue(void) const;

	/**
	 * Gets the RGB components of the current instance of Color.
	 *
	 * @since				1.0
	 * @param[out]	r	The red component
	 * @param[out]	g	The green component
	 * @param[out]	b	The blue component
	 * @param[out]	a	The alpha component
	 */
	void GetColorComponents(byte& r, byte& g, byte& b, byte& a) const;

	/**
	 * Gets the value of the green component of the current instance of Color.
	 *
	 * @since		1.0
	 * @return	A @c byte representation of the green component of the current instance of Color
	 */
	byte GetGreen(void) const;

	/**
	 * Gets the value of the red component of the current instance of Color.
	 *
	 * @since		1.0
	 * @return	A @c byte representation of the red component of the current instance of Color
	 */
	byte GetRed(void) const;

	/**
	 * Gets the 32-bit integer value of the current instance of Color.
	 *
	 * @since		1.0
	 * @return	An unsigned integer value representing the current instance of Color
	 */
	unsigned int GetRGB32(void) const;

	/**
	 * Sets the value of the alpha component of the current instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	a	The new value of the alpha component
	 */
	void SetAlpha(byte a);

	/**
	 * Sets the value of the blue component of the current instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	b	The new value of the blue component
	 */
	void SetBlue(byte b);	

	/**
	 * Sets the values of the RGB components of the current instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	r	The red component
	 * @param[in]	g	The green component
	 * @param[in]	b	The blue component
	 * @param[in]	a	The alpha component
	 */
	void SetColorComponents(byte r, byte g, byte b, byte a = 0xFF);

	/**
	 * Sets the value of the green component of the current instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	g	The new value of the green component
	 */
	void SetGreen(byte g);

	/**
	 * Sets the value of the red component of the current instance of Color.
	 *
	 * @since			1.0
	 * @param[in]	r	The new value of the red component
	 */
	void SetRed(byte r);

	/**
	 * Sets the current instance of Color to the specified 32-bit integer value.
	 *
	 * @since			1.0
	 * @param[in]	rgb			The new RGB color value
	 * @param[in]	hasAlpha	@c true if @c rgb contains alpha value, @n
								else @c false
	 */
	void SetRGB32(unsigned int rgb, bool hasAlpha = true);
	
// Constant
public:
	/**
	 * This attribute is pre-defined. Its value is black.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_BLACK;
	
	/**
	 * This attribute is pre-defined. Its value is blue.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_BLUE;
	
	/**
	 * This attribute is pre-defined. Its value is cyan.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_CYAN;
	
	/**
	 * This attribute is pre-defined. Its value is green.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_GREEN;
	
	/**
	 * This attribute is pre-defined. Its value is grey.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_GREY;
	
	/**
	 * This attribute is pre-defined. Its value is magenta.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_MAGENTA;
	
	/**
	 * This attribute is pre-defined. Its value is red.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_RED;
	
	/**
	 * This attribute is pre-defined. Its value is violet.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_VIOLET;
	
	/**
	 * This attribute is pre-defined. Its value is yellow.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_YELLOW;
	
	/**
	 * This attribute is pre-defined. Its value is white.
	 *
	 * @since	1.0
	 */
	const static  Color COLOR_WHITE;

// Attribute
private:
	unsigned int __color;

private:
	friend class ColorEx;
	class ColorEx* __pColorEx;

};

}; }; // Osp::Graphics

#endif //_FGRP_COLOR_H_


