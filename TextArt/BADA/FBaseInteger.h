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
 * @file		FBaseInteger.h
 * @brief		This is the header file for the %Integer class.
 *
 * @see			Number() class()
 *
 * This header file contains the declarations of the %Integer class.
 */
#ifndef _FBASE_INTEGER_H_
#define _FBASE_INTEGER_H_

//Includes
#include "FBaseNumber.h"


namespace Osp { namespace Base {
/**
 *	@class	Integer
 *	@brief	This class is the wrapper class for the signed @c int built-in type.
 *	@since	1.0
 *
 *	The %Integer class represents an integer value ranging from -2147483648 to 2147483647,
 *	that is, -(2^31) to +((2^31)-1). This class is useful when passing a 32-bit signed
 *	integral value to a method that accepts only an instance of Object. Furthermore,
 *	this class provides methods for converting %Integer (and @c int) to String, and %String
 *	to %Integer (and @c int).
 *
 * The following example demonstrates how to use the %Integer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	// This method checks whether the given string object contains a string
 *	// representation of the pre-defined minimum 32-bit integral value.
 *	result
 *	MyClass::Verify(String& string, bool& out)
 *	{
 *		static const Integer MINIMUM(1230);
 *
 *		// method return code
 *		result r = E_SUCCESS;
 *
 *		// parse
 *		int i;
 *		r = Integer::Parse(string, i);
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		// compare
 *		out = (MINIMUM.CompareTo(i) == 0) ? true: false;
 *
 *		return r;
 *	CATCH:
 *		return r;
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ Integer :
	public Number
{
// Lifecycle
public:
	/**
	 *	Initializes this instance of %Integer with the specified value.
	 *
	 *	@since			1.0
	 *  @param[in]	value	An integer value
	 */
	Integer(int value = 0);


	/**
	 *	This is the copy constructor for the %Integer class.	 
	 *
	 *	@since			1.0
	 *	@param[in]	value	An instance of %Integer
	 */
	Integer(const Integer& value);


	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~Integer(void);


// Operator
public:

	/**
	 * This operator assigns the value of the specified instance of %Integer to the current instance of %Integer.
	 *
	 *	@since			1.0
	 *  @param[in]	rhs	An instance of %Integer
	 */
	Integer& operator =(const Integer& rhs);


// Operation
public:

	/**
	 *	Compares two @c int values.
	 *
	 *	@since		1.0
	 *	@return		A signed 32-bit integer value:
	 *	@code
	 *	<  0  if the value of i1 is less than the value of i2
	 *	== 0  if the value of i1 is equal to the value of i2
	 *	>  0  if the value of i1 is greater than the value of i2
	 *	@endcode
	 *	@param[in]	i1	The first @c int value to compare
	 *	@param[in]	i2	The second @c int value to compare
	 */
	static int Compare(int i1, int i2);


	/**
	 *	Compares the value of the current instance with the value of the specified instance of the %Integer class.
	 *
	 *	@since	1.0
	 *	@return	A signed 32-bit integer value:
	 *	@code
	 *	<  0  if the value of the current instance is less than the value of the specified instance
	 *	== 0  if the value of the current instance is equal to the value of the specified instance
	 *	>  0  if the value of the current instance is greater than the value of the specified instance
	 *	@endcode
	 *	@param[in]	value	An instance of the %Integer class to compare
	 */
	int CompareTo(const Integer& value) const;


	/**
	 *	Checks whether the value of the specified instance of Object is equal to the value of the current instance of %Integer.
	 *
	 *	@since		1.0
	 *	@return		@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Integer, @n
	 *				else @c false
	 *	@param[in]	obj An instance of %Object to compare
	 *	@see		Osp::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;


	/**
	 *	Decodes a string into a signed @c int.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *	@param[in]	s			A string representing the numeric value
	 *	@param[out]	ret			The result of the operation
	 *	@exception	E_SUCCESS    The method is successful.
	 *	@exception	E_NUM_FORMAT The specified string does not contain a number that can be parsed.
	 *	@remarks	This method accepts decimal, hexadecimal, and octal numbers given by the
	 *				following grammar:
	 *	@code
	 *	- DecodableString:
	 *		Sign[opt] DecimalNumeral
	 *		Sign[opt] 0x HexDigits
	 *		Sign[opt] 0X HexDigits
	 *		Sign[opt] # HexDigits
	 *		Sign[opt] 0 OctalDigits
	 *	- Sign:
	 *		'-'
	 *	@endcode
	 */
	static result Decode(const String& s, int& ret);

	/**
	 *	Gets the hash value of the current instance of %Integer.
	 *
	 *	@since		1.0
	 *	@return		An integer value indicating the hash value of the current instance of %Integer
	 *	@remarks 	Two equal instances should return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@par
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	 *	Gets the @c signed @c int equivalent of the specified string representing a numeric value.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *	@param[in]	s				A string representing a numeric value
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *	@remarks	This method assumes that the string representing the numeric value
	 *				uses a radix 10.
	 */
	static result Parse(const String& s, int& ret);


	/**
	 *	Gets the @c signed @c int equivalent of the specified string representing a numeric value using the specified radix.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *	@param[in]	s				A string representing a numeric value
	 *  @param[in]	radix			The radix of the string representing the numeric value @n
	 *								It must either be 2, 8, 10, or 16.
	 *	@param[out]	ret				The result of the operation
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_NUM_FORMAT	The specified string does not contain a number that can be parsed.
	 *  @exception	E_OUT_OF_RANGE The specified @c radix is invalid.
	 */
	static result Parse(const String& s, int radix, int& ret);


	/**
	 *	Gets the @c signed @c char equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const;


	/**
	 *	Gets the @c signed @c short equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const;


	/**
	 *	Gets the @c signed @c int equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const;


	/**
	 *	Gets the @c signed @c long equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const;


	/**
	 *	Gets the @c signed @c long @c long equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c long @c long equivalent of the current instance
	 */
	virtual long long ToLongLong(void) const;


	/**
	 *	Gets the @c signed @c float equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const;


	/**
	 *	Gets the @c signed @c double equivalent of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const;


	/**
	 *	Gets the string representing the value of the current instance of the %Integer class.
	 *
	 *	@since		1.0
	 *	@return		A string representing the value of the current instance
	 */
	virtual String ToString(void) const;


	/**
	 *	Gets the string representing the specified @c signed @c int value.
	 *
	 *	@since		1.0
	 *	@return		A string containing a Unicode representation of the specified @c signed @c int value
	 *	@param[in]	value 	A @c signed @c int value to convert
	 */
	static String ToString(int value);


// Constant
public:
	/**
	 *	A constant holding the maximum value of type @c int. @n 
	 *  A @c short integer can hold a value of upto 2^31-1.
	 *
	 *	@since	1.0
	 */
	static const int VALUE_MAX = (int) 0x7FFFFFFF;


	/**
	 *	A constant holding the minimum value of type @c int. @n  
	 *  A @c short integer can hold a value of upto -2^31.
	 *
	 *	@since	1.0
	 */
	static const int VALUE_MIN = (int) 0x80000000;


// Attribute
private:
	int __val;


private:
	friend class IntegerEx;
	class IntegerEx* __pIntegerEx;
};
}; }; //Osp::Base
#endif//_FBASE_INTEGER_H_
