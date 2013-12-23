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
 * @file		FBaseBoolean.h 
 * @brief		This is the header file for the %Boolean class.
 *
 * This is the header file for the %Boolean class. 
 */
#ifndef _FBASE_BOOL_H_
#define _FBASE_BOOL_H_

// includes
#include "FBaseObject.h"
#include "FBaseString.h"

namespace Osp { namespace Base {
/**
 *	@class	Boolean 
 *	@brief	This class is the wrapper class for the @c bool data type.
 *	@since	1.0
 *
 * The %Boolean class wraps a bool type value. This enables passing a bool value to a method that only accepts an instance of the Object class.
 * It provides methods to convert %Boolean instances to String and String instances to %Boolean. 
 *
 * The following example demonstrates how to use the %Boolean class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::Test(void)
 *	{
 *		Boolean b1(true);
 *
 *		String string1(b1.ToString());		// string1 == L"true"
 *
 *
 *		// Boolean::Parse(string1) compares the string1 with L"true"
 *		if (Boolean::Parse(string1))		// true
 *		{
 *			...
 *		}
 *
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ Boolean :
	public Object
{
// Lifecycle
public:
	/** 
	 *	Initializes this instance of the %Boolean class with the specified @c value.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	The input @c bool value to initialize the %Boolean instance
	 */
	Boolean(bool value);


	/** 
	 *	This is the copy constructor for the %Boolean class. @n
	 *	Initializes a new instance of the %Boolean class to the specified @c value.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	An instance of the %Boolean class
	 */
	Boolean(const Boolean& value);


	/** 
	 *	Initializes this instance of %Boolean with the specified input string. @n
     *  If the input is "true" (ignoring case), the object is initialized to @c true, 
	 *	else @c false.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	An instance of String
	 */
	Boolean(const String& value);


	/** 
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~Boolean(void);


// Operator
public:
	/** 
	 *	Compares the values of two %Boolean instances.
	 *
	 *	@since			1.0
	 *	@return			@c true if the values of the objects are equal, @n
	 *				    else @c false.
	 *	@param[in]	rhs		A %Boolean instance to compare with the current instance
	 */
	bool operator ==(const Boolean& rhs) const;


	/** 
	 *	Checks whether the two %Boolean instances are equal. 
	 *
	 *	@since			1.0
	 *	@return			@c true if the values of the objects are not equal, @n
	 *				    else @c false
	 *	@param[in]	rhs		A %Boolean instance to compare with the current instance
	 */
	bool operator !=(const Boolean& rhs) const;


// Operation
public:
	/** 
	 *	Converts an instance of the Object class to an instance of %Boolean and then 
	 *	compares it with the calling %Boolean instance. 
	 *
	 *	@since			1.0
	 *	@return			@c true if the value of @c obj matches the value of the calling %Boolean instance, @n
	 *				    else @c false
	 *	@param[in]	obj		A reference to the %Object instance that is to be compared with the calling %Boolean instance
	 *	@see				Osp::Base::Object::Equals
	 */
	virtual bool Equals(const Object& obj) const;


	/** 
	 *	Converts a bool value to an instance of %Boolean and then 
	 *	compares it with the calling %Boolean instance.
	 *
	 *	@since			1.0
	 *  @return			@c true if the parameter matches the calling %Boolean instance, @n
	 *                   else @c false
	 *  @param[in]	value	The @c bool value to compare to this instance
	 */
	bool Equals(bool value) const;


	/**
	 * Returns the value of the calling object as @c bool
	 *
	 * @since			1.0
	 * @return		The value of the %Boolean instance as bool
	 */
	bool ToBool(void) const;


	/** 
	 *	Parses the specified string and converts it to a bool value.
	 *
	 *	@since		1.0
	 *	@return		@c true if the value of the specified string is "true", @n
	 *				else @c false
	 *	@param[in]	s			An instance of String
	 *	@remarks	This method is case sensitive. @n
	 *				It only accepts lowercase strings.
	 *	@code
	 *	bool b1 = Boolean::Parse(trueString); // trueString is L"true"
	 *	bool b1 = Boolean::Parse(falseString); // falseString is L"false"
	 *	@endcode
	 */
	static bool Parse(const String& s);


	/** 
	 *	Parses the specified string and converts it to a bool value. @n
	 *	Case sensitivity can be controlled. 
	 *
	 *	@since		1.0
	 *	@return		@c true if the value of the specified string is "true", @n
	 *				else @c false.
	 *	@param[in]	s					An instance of String
	 *	@param[in]	caseSensitive	Set to @c true to perform a 
	 *								case sensitive comparison of string @c s
	 *	@remarks	If @c caseSensitive is @c true, L"True" returns @c false, else @c true. 
	 *  @code
	 *  bool b1 = Boolean::Parse(L"True", false ); // returns @c true
	 *  bool b1 = Boolean::Parse(L"True", true); // returns @c false
	 *  @endcode
	 */
	static bool Parse(const String& s, bool caseSensitive);


	/** 
	 *	Converts the value of the calling instance from bool to String.
	 *
	 *	@since	1.0
	 *	@return	@c true if this instance is @c true, @n
	 *			else @c false
	 */
	String ToString(void) const;


	/** 
	 *  Converts the specified value from bool to String.
	 *
	 *	@since	1.0
	 *	@return	@c true if the parameter is @c true, @n
	 *			else @c false
	 *	@param[in]	value	A @c bool value to be converted to String
	 */
	static String ToString(bool value); 


// Accessor
public:
	/** 
	 *	Returns a %Boolean instance for which the value corresponds to the primitive value @c true.
	 *
	 *	@since		1.0
	 *	@return		A %Boolean instance equivalent to @c true
	 */
	static const Boolean GetTrue(void);


	/** 
	 *	Returns a %Boolean instance for which the value corresponds to the primitive 
	 *	value @c false.
	 *
	 *	@since		1.0
	 *	@return		A %Boolean instance equivalent to @c false
	 */
	static const Boolean GetFalse(void);


// Attribute
private:
	bool __val;


private:
	friend class BooleanEx;
	class BooleanEx* __pBooleanEx;
};
}; };// Osp::Base
#endif//_FBASE_BOOL_H_
