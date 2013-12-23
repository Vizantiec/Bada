/* $Change: 1142016 $ */
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
 * @file		FBaseFloat.h
 * @brief		This is the header file for the %Float class.
 *
 * @see			Osp::Base::Number
 *
 * This header file contains the declarations of the %Float class.
 */
#ifndef _FBASE_FLOAT_H_
#define _FBASE_FLOAT_H_

//Includes
#include "FBaseNumber.h"


namespace Osp { namespace Base {
/**
 *	@class	Float
 *	@brief	This class is the wrapper class for the @c signed @c float built-in type.
 *	@since	1.0
 *
 *	The %Float class represents a single-precision 32-bit floating number. The %Float class wraps a @c float type value. This enables
 *	passing a @c float value to a method that only accepts an instance of Object class. This class provides methods to compare instances
 *	of this type, convert the value of an instance to its string representation, and convert the string representation
 *	of a number to an instance of this type. 
 *
 * The following example demonstrates how to use the %Float class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	// This method checks whether the given string object contains the string
 *	// representation of the pre-defined minimum float value.
 *	result
 *	MyClass::Verify(String& string, bool& out)
 *	{
 *		// Create an instance of Double and initialize
 *		static const Float MINIMUM(1.23L);
 *
 *		// Set return code as success for error handling
 *		result r = E_SUCCESS;
 *
 *		float f;
 *
 *		// Parse 'string' representation of numeric value
 *		// Returns f (value as signed float)
 *		r = Float::Parse(string, f);
 *
 *		// Error Handling
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		// Compare
 *		out = (MINIMUM.CompareTo(f) == 0) ? true: false;
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ Float :
	public Number
{
// Lifecycle
public:
	/**
	 *	Initializes this instance of %Float with the specified value.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	A @c float value
	 */
	Float(float value = 0.0);


	/**
	 *	This is the copy constructor for the %Float class. 
	 *
	 *	@since			1.0
	 *	@param[in]	value 	An instance of %Float
	 */
	Float(const Float& value);


	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~Float(void);


// Operator
public:

	/**
	* This operator assigns the value of the specified instance of %Float to the current instance of %Float.
	*
	*	@since			1.0
	* @param[in]	rhs	An instance of %Float
	*/
	Float& operator =(const Float& rhs);


// Operation
public:

	/**
	 *	Compares two @c float values.
	 *
	 *	@since		1.0
	 *	@return		A 32-bit signed integer value:
	 *	@code
	 *	<  0  if the value of f1 is less than the value of f2
	 *	== 0  if the value of f1 is equal to the value of f2
	 *	>  0  if the value of f1 is greater than the value of f2
	 *	@endcode
	 *	@param[in]	f1	The first @c float value to compare
	 *	@param[in]	f2	The second @c float value to compare
	 */
	static int Compare(float f1, float f2);


	/**
	 *	Compares the value of the current instance with the value of the specified instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A 32-bit signed integer value:
	 *	@code
	 *	@li <  0  	if the value of the current instance is less than the value of the specified instance
	 *	@li == 0 	if the value of the current instance is equal to the value of the specified instance
	 *	@li >  0  	if the value of the current instance is greater than the value of the specified instance
	 *	@endcode
	 *	@param[in]	value 	An instance of the %Float class to compare
	 */
	int CompareTo(const Float& value) const;


	/**
	 *	Checks whether the value of the specified instance of %Object is equal to the value of the current instance of %Float.
	 *
	 *	@since		1.0
	 *	@return		@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Float, @n
	 *				else @c false
	 *	@param[in]	obj		An instance of %Object to compare
	 *	@see		Osp::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;


	/**
	 *	Gets the hash value of the current instance of %Float.
	 *
	 *	@since		1.0
	 *	@return		An integer value indicating the hash value of the current instance of %Float
	 *	@remarks 	Two equal instances should return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@par
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Parses the specified string representing a numeric value and
     * returns the value as @c signed @c float (as out parameter).
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@param[in]	s			A unicode string representing a @c signed @c float value
	 *	@param[out]	ret			The numeric representation of the string
	 *	@exception	E_SUCCESS	 The method is successful.
	 *	@exception	E_NUM_FORMAT The specified string does not contain a number that can be parsed.
	 *	@see		Osp::Base::Double::Parse()
	 */
	static result Parse(const String& s, float& ret);


	/**
	 *	Gets the @c signed @c char equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;


	/**
	 *	Gets the @c signed @c short equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;


	/**
	 *	Gets the @c signed @c int equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;


	/**
	 *	Gets the @c signed @c long equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;


	/**
	 * Gets the @c signed @c long @c long equivalent of the current instance of the %Float class.
	 *
	 * @since		1.0
	 * @return	A @c signed @c long @c long equivalent of the current instance
	 */
	virtual long long ToLongLong(void) const;


	/**
	 *	Gets the @c signed @c float equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;


	/**
	 *	Gets the @c signed @c double equivalent of the current instance of the %Float class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;


	/**
	 * Gets the string representing the value of the current instance of %Float.
	 *
	 * @since			1.0
	 * @return		A string containing a Unicode representation of the value of the current instance
	 * @remarks		If the value is Not-a-Number (NaN), the result is the string "NaN". Furthermore, infinity
	 *				produces the result "Infinity". 
	 *              @par
	 *				6 digits are given for the precision of this method. Use String::Format() to set the specific precision.
	 */
	virtual String ToString(void) const;


	/**
	 *	Gets the string representing the specified @c float value.
	 *
	 *	@since		1.0
	 *	@return		A string containing a Unicode representation of the specified @c float value
	 *	@param[in]	value 	A @c float value to convert
	 *  @remarks	If the value is Not-a-Number (NaN), the result is the string "NaN". Furthermore, infinity
	 *				produces the result "Infinity". 
	 *              @par
	 *				6 digits are given for the precision of this method. Use String::Format() to set the specific precision.
	 */
	static String ToString(float value);


	/**
	 *	Gets the IEEE 754 floating-point "single format" bit layout representation of the specified @c float value.
	 *
	 *	@since		1.0
	 *	@return		The bits that represent the floating-point number in the IEEE 754 floating-point "single format" bit layout
	 *	@param[in]	value 	A @c float value to convert
	 *	@see		Osp::Base::Double::Parse()
	 */
	static int ToBits(float value);


	/**
	 *	Gets the @c float value corresponding to the specified floating-point value in the IEEE 754 floating-point "single format" bit layout.
	 *
	 *	@since		1.0
	 *	@return		The @c float floating-point value with the same bit pattern
	 *	@param[in]	value 	A floating-point value in the IEEE 754 floating-point "single format" bit layout
	 *	@see		Osp::Base::Double::Parse()
	 */
	static float ToFloatFromBits(int value);


// Inquiry
public:
	/**
	 *	Checks whether the current value of %Float is equal to negative or positive infinity.
	 *
	 *	@since		1.0
	 *	@return		@c true if the current value equals negative or positive infinity, @n
	 *				else @c false
	 */
	bool IsInfinity(void) const;


	/**
	 *	Checks whether the specified @c float value is equal to negative or positive infinity.
	 *
	 *	@since		1.0
	 *	@return		@c true if the specified value equals negative or positive infinity, @n
	 *				else @c false
	 *	@param[in]	value 	A @c float value to check
	 */
	static bool IsInfinity(float value);


	/**
	 *	Checks whether the current value is Not-a-Number.
	 *
	 *	@since		1.0
	 *	@return		@c true if the current value is Not-a-Number, @n
	 *				else @c false
	 */
	bool IsNaN(void) const;


	/**
	 *	Checks whether the specified value is Not-a-Number.
	 *
	 *	@since		1.0
	 *	@return		@c true if the specified value is Not-a-Number, @n
	 *				else @c false
	 *	@param[in]	value 	A @c float value to check
	 */
	static bool IsNaN(float value);



// Accessor
public:

	/**
	 *	Gets a constant holding the largest positive finite value of type @c float. @n
	 *	This is equal to the value defined in Limit.h of the C library.
	 *
	 *	@since		1.0
	 *	@return		A constant holding the largest positive finite value of type @c float
	 */
	static float GetMaxValue(void);


	/**
	 *	Gets a constant holding the smallest positive non-zero value of type @c float. @n
	 *	This is equal to the value defined in Limit.h of the C library.
	 *
	 *	@since		1.0
	 *	@return		A constant holding the smallest possible non-zero value of type @c float
	 */
	static float GetMinValue(void);


// Inquiry
private:
	static bool IsFinite(float value);


// Attribute
private:
	static const int __DBL_MAX_10_EXP = 308;

	float __val;


private:
	friend class FloatEx;
	class FloatEx* __pFloatEx;

};
}; };// Osp::Base
#endif//_FBASE_FLOAT_H_
