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
 * @file		FBaseUtilMath.h 
 * @brief		This is the header file for the %Math class.
 *
 * This header file contains the declarations of the %Math class.
 */
#ifndef _FBASE_UTIL_MATH_H_
#define _FBASE_UTIL_MATH_H_

#include "FBaseTypes.h"
#include "FBaseConfig.h"


namespace Osp { namespace Base { namespace Utility {
/**
 * @class	Math
 * @brief	This class is the wrapper class for %Math Library.
 * @since	1.0
 *
 *
 * The %Math class provides various mathematical methods. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %Math class. 
 *
 * @code
 *	// includes
 *	#include <FBase.h>
 *
 *	// namespace
 *	using namespace Osp::Base::Utility;
 *	
 *	void
 *	MyClass::MathSample(void)
 *	{
 *		double radius = 5.0; 
 *
 *		double area = Math::GetPi() * Math::Pow(radius, 2.0L);
 *		
 *	}
 * @endcode
 */


class _EXPORT_BASE_ Math
{
// Operation
public:
	/**
	 * Gets the absolute value of the specified integer.
	 *
	 * @since				1.0
	 * @return			The absolute value of the specified integer
	 * @param[in]		x	An integer value
	 */
	 static int Abs(int x);

	/**
   * Gets the arc sine of the specified double integer. @n
	 * Returns a value between @c -PI/2 and @c PI/2. 
	 *
	 * @since				1.0
	 * @return			The arc sine of the input, @n
	 *					else Not-a-Number if @c x is out of range
	 * @param[in] 		x	A radian angle @n
	 *					It must be within the range @c -1 to @c 1 (inclusive).
	 * @see				Acos(), Atan()
	 */
	 static double Asin(double x);

	/**
   * Gets the arc cosine of the specified double integer. @n
	 * Returns a value between @c 0 and @c PI. 
	 *
	 * @since				1.0
	 * @return			The arc cosine of the input, @n
	 *					else Not-a-Number if @c x is out of range
	 * @param[in] 		x	A radian angle @n
	 *					It must be within the range @c -1 to @c 1 (inclusive).
	 * @see				Asin(), Atan()
	 */
	 static double Acos(double x);

	/**
   * Gets the arc tangent of the specified double integer. @n
	 * Returns a value between @c -PI/2 and @c PI/2. 
	 *
	 * @since			1.0
	 * @return		The arc tangent of the input 
	 * @param[in] x		A radian angle
	 * @see				Asin(), Acos()
	 */
	 static double Atan(double x);

	/**
	 * Gets the smallest integer that is greater than or equal to the specified double integer. @n
	 * For example, if @c x is @c 3.9, Ceiling(double) returns @c 4.0. @n
	 * The returned value is an integer but the type is @c double.
	 * 
	 * @since			1.0
	 * @return		The smallest integer that is greater than or equal to the input
	 * @param[in] x		A floating point value
	 */
	 static double Ceiling(double x);

 	/**
   * Gets the cosine of the specified double integer. @n
	 * Returns a value between @c -1 and @c 1. 
	 *
	 * @since			1.0
	 * @return		The cosine of the input
	 * @param[in] x		A radian angle
	 * @see				Sin(), Tan()
	 */
	 static double Cos(double x);

	/**
   * Gets the hyperbolic cosine of the specified double integer.
	 *
	 * @since			1.0
	 * @return		The hyperbolic cosine of the input
 	 * @param[in] x		A radian angle
	 */
	 static double Cosh(double x);

	/**
   * Gets the exponential value of the specified double integer. 
	 *
	 * @since			1.0
	 * @return		The exponential value of the input
 	 * @param[in] x		A floating point value
	 */
	 static double Exp(double x);

	/**
	 * Gets the largest integer that is less than or equal to the input. @n
	 * For example, if x is @c 3.3 then Floor(double) returns @c 3.0. @n
	 * The returned value is an integer but the type is @c double.
	 *
	 * @since			1.0
	 * @return		The largest @c double integer that is less than or equal to the input
	 * @param[in] x		A floating point value
	 */
	 static double Floor(double x);
	
	/**
	 * Gets the natural logarithm of the specified number.
	 *
	 * @since			1.0
	 * @return		The natural logarithm of the input
	 * @param[in] x	A floating point value
	 */
	 static double Log(double x);

	/**
	 * Gets the logarithm to the base 10 of the specified number.
	 *
	 * @since			1.0
	 * @return		The logarithm to the base 10 of the input
	 * @param[in] x	A floating point value
	 */
	 static double Log10(double x);

	/**
	 * Gets the greater of the two specified integer values. @n
	 * If both inputs have the same value, this method returns the same value.
	 * 
	 * @since			1.0
	 * @return		The greater of the two integer values
	 * @param[in] x		An integer value
	 * @param[in] y		An integer value
	 * @see				Min()
	 */
	 static int Max(int x, int y);

	/**
	 * Gets the greater of the two floating point values. @n 
	 * If both inputs have the same value, this method returns the same value. @n
	 * If either value is not a valid number, then this method returns Not-a-Number.
	 *
	 * @since			1.0
	 * @return		The greater of the two floating point values
	 * @param[in] x		A floating point value
	 * @param[in] y		A floating point value
	 * @see				Min()
	 */
	 static double Max(double x, double y);

	/**
	 * Gets the smaller of the two integer values. @n
	 * If both inputs have the same value, this method returns the same value.
	 *
	 * @since			1.0
	 * @return		The smaller of the two integer values
	 * @param[in] x		An integer value
	 * @param[in] y		An integer value
	 * @see				Max()
	 */
	 static int Min(int x, int y);

	/**
	 * Gets the smaller of the two @c double values. @n
	 * If both inputs have the same value, this method returns the same value. @n
	 * If either value is not a valid number, this method returns Not-a-Number.
	 *
	 * @since			1.0
	 * @return		The smaller of the two @c double values
	 * @param[in] x		A floating point value
	 * @param[in] y		A floating point value
	 * @see				Max()
	 */
	 static double Min(double x, double y);

	/**
	 * Gets the value of @c x raised to the power of @c y.
	 *	
	 * @since			1.0
	 * @return		@c x raised to the power of @c y, @n
	 *					else Not-a-Number if @c x and @c y do not satisfy the conditions described below 
	 * @param[in] x	A floating point value
	 * @param[in] y	A floating point value
	 * @remarks		@li @c x cannot be negative if @c y is a fractional value.
	 *					@li	@c x cannot be @c 0 if @c y is less than or equal to @c 0.
	 */
	 static double Pow(double x, double y);

	/**
	 * Gets the nearest integer to the specified number. 
	 *
	 * @since			1.0
	 * @return		The closest integer to the specified input 
	 * @param[in] x		A floating point value
	 */
	 static double Round(double x);

	/**
   * Gets the sine of the specified double integer. @n
	 * Returns a value between @c -1 and @c 1. 
	 *
	 * @since			1.0
	 * @return		The sine of the input
	 * @param[in] x		A radian angle
	 * @see				Cos(), Tan()
	 */
	 static double Sin(double x);

	/**
   * Gets the hyperbolic sine of the specified double integer.
	 *
	 * @since			1.0
	 * @return		The hyperbolic sine of the input 
 	 * @param[in] x		A radian angle
	 */
	 static double Sinh(double x);
	
	/**
	 * Gets the square root of the specified number
	 * 
	 * @since			1.0
	 * @return		The square root of the input, @n
	 *					else Not-a-Number if @c x is a negative number
	 * @param[in] x		A non-negative floating point value
	 */
	 static double Sqrt(double x);

	/**
   * Gets the tangent of the specified double integer. 
	 *
	 * @since			1.0
	 * @return		The tangent of the input
	 * @param[in] x		A radian angle
	 * @see				Sin(), Cos()
	 */
	 static double Tan(double x);

	/**
   * Gets the hyperbolic tangent of the specified double integer.
	 *
	 * @since			1.0
	 * @return		The hyperbolic tangent of the input
 	 * @param[in] x		A radian angle
	 */
	 static double Tanh(double x);


	/**
	 * Initializes a random number generator.
	 *
	 * @since			1.0
	 * @param[in]	seed	An integer value to be used as seed by the pseudo-random number generator algorithm
	 * @see				Rand()
	 */
	 static void Srand(unsigned int seed);


	/**
	 * Gets a random integral number in the range @c 0 to RAND_VALUE_MAX.
	 *
	 * @since			1.0
	 * @return		An integer value between @c 0 and RAND_VALUE_MAX
	 * @remarks		This method uses a seed to generate the pseudo-random numbers, that should be initialized to some distinctive value using Srand().
	 * @see				Srand()
	 */
	 static int Rand(void);


// Access
public:
	/**
   * Gets the constant value of E (the base of natural logarithms). 
	 *
	 * @since				1.0
	 * @return			The constant value of E
 	 */
	 static const double GetE(void);
	
	/**
   * Gets the constant value of PI. 
	 *
	 * @since				1.0
	 * @return			The constant value of PI
 	 */
	 static const double GetPi(void);
	

// Constant
public:
	/** 
	* The maximum value that can be returned by the Rand() method.
	*
	* @since	1.0
	*/
	 static const int RAND_VALUE_MAX = 32767; // 0x7fff


private:
	/**
	 * This is the default constructor for this class.
	 */
	 Math(void);

	 /*
	  * This is the destructor for this class.
	  */
	 virtual ~Math(void);

};
}; }; }; // Osp::Base::Utility
#endif // _FBASE_UTIL_MATH_H_
