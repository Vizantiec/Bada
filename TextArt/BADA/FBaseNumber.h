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
 * @file		FBaseNumber.h 
 * @brief		This is the header file for the %Number class.
 *
 * This header file contains the declarations and definitions of the %Number class. @n 
 * This class is the abstract base class of all wrapped numeric types.
 */
#ifndef _FBASE_NUMBER_H_
#define _FBASE_NUMBER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseString.h"


namespace Osp { namespace Base {
/**
 *	@class	Number
 *	@brief	This class is the base class of all wrapped numeric types.
 *	@since	1.0
 *
 *	The %Number class is the abstract base class of all wrapped numeric classes. 
 *	The subclasses of %Number must provide methods to convert the represented 
 *	numeric value to @c char, @c short, @c int, @c long, @c float, and @c double.
 *
 * The following example demonstrates how to use the %Number class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::NumberSample(void)
 *	{
 *		Long ld(0x12345678L);
 *		int i = ld.Toint(); 		// i == 0x5678
 *		char ch = ld.ToChar();	// ch == 0x78 or 120
 *		...
 *		Int8 j(ch);
 *		Float f1(j.ToFloat()); // f1 == 120.0
 *		...
 *		Double d(120.100005L);
 *		Float f2(d.ToFloat()); 	// f2 == 120.10001
 *		Integer k(f2.ToInt()); 	// k == 120
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ Number :
	public Object
{
// Lifecycle
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Number(void) { };


// Operation
public:
	/** 
	 *	Gets the @c signed @c char equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c char equivalent of the current instance
	 */
	virtual char ToChar(void) const = 0;


	/** 
	 *	Gets the @c signed @c short equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c short equivalent of the current instance
	 */
	virtual short ToShort(void) const = 0;


	/** 
	 *	Gets the @c signed @c int equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c int equivalent of the current instance
	 */
	virtual int ToInt(void) const = 0;


	/** 
	 *	Gets the @c signed @c long equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c long equivalent of the current instance
	 */
	virtual long ToLong(void) const = 0;


	/** 
	*	Gets the @c signed @c long @c long equivalent of the current instance of the %Number class.
	*
	*	@since		1.0
	*	@return		The @c signed @c long @c long equivalent of the current instance
	*/
	virtual long long ToLongLong(void) const = 0;


	/** 
	 *	Gets the @c signed @c float equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c float equivalent of the current instance
	 */
	virtual float ToFloat(void) const = 0;


	/** 
	 *	Gets the @c signed @c double equivalent of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The @c signed @c double equivalent of the current instance
	 */
	virtual double ToDouble(void) const = 0;


	/** 
	 *	Gets the string representing the value of the current instance of the %Number class.
	 *
	 *	@since		1.0
	 *	@return		The string representing the value of the current instance
	 */
	virtual String ToString (void) const = 0;


private:
	friend class NumberEx;
	class NumberEx* __pNumberEx;
};
}; };// Osp::Base
#endif// _FBASE_NUMBER_H_
