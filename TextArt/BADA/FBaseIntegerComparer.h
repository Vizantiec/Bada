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
 * @file		FBaseIntegerComparer.h 
 * @brief		This is the header file for the %IntegerComparer class.
 *
 * @see			Integer and Osp::Base::Collection::IComparer
 *
 * This header file contains the declarations of the %IntegerComparer class.
 */
#ifndef _FBASE_INTEGER_COMPARER_H_
#define _FBASE_INTEGER_COMPARER_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseColIComparer.h"


namespace Osp { namespace Base {
/**
 *	@class	IntegerComparer
 *	@brief	This class checks for equivalence between 2 instances of the Integer type.
 *	@since	1.0
 *
 *	The %IntegerComparer class checks for equivalence between 2 instances of the Integer type. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 * The following example demonstrates how to use the %IntegerComparer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::IntegerComparerSample(void)
 *	{
 *		Integer i1(123);
 *		Integer i2(124);
 *		IntegerComparer comparer;
 *
 *		int cmp;
 *		comparer.Compare(i1, i2, cmp);
 *		if (cmp < 0) // true
 *		{
 *			...
 *		}
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ IntegerComparer :
	public Object,
	public Osp::Base::Collection::IComparer
{
// Lifecycle
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since	1.0
	 */
	IntegerComparer(void);


	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~IntegerComparer(void);


// Operation
public:
	/** 
	 * Compares two given instances of type Integer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj1 	The first instance of type %Integer
	 * @param[in]	obj2 	The second instance of type %Integer
	 * @param[out]	cmp		The result of comparison
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 * @remarks	The value of @c cmp can be: 
	 * @code	 
	 * <  0  if the value of obj1 is less than the value of obj2
	 * == 0  if the value of obj1 is equal to the value of obj2
	 * >  0  if the value of obj1 is greater than the value of obj2
	 * @endcode
	 */
	virtual result Compare(const Osp::Base::Object& obj1, const Osp::Base::Object& obj2, int& cmp) const;


private:
	friend class IntegerComparerEx;
	class IntegerComparerEx* __pIntegerComparerEx;
};
}; }; // Osp::Base
#endif// _FBASE_INTEGER_COMPARER_H_
