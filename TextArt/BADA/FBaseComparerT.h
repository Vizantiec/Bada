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
 * @file		FBaseComparerT.h 
 * @brief		This is the header file for the %ComparerT class.
 *
 * This header file contains the declarations of the %ComparerT class.
 */
#ifndef _FBASE_COMPARER_T_H_
#define _FBASE_COMPARER_T_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseColIComparerT.h"

namespace Osp { namespace Base {
/**
 * @class ComparerT
 *
 * @brief	This class checks for equivalence between 2 values of the same primitive type.
 * @since	 1.0
 *
 * The %ComparerT class checks for equivalence between 2 values of the same primitive type. 
 *
 * The following example demonstrates how to use the %ComparerT class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::ComparerTSample(void)
 *	{
 *		double d1 = 123;
 *		double d2 = 124;
 *		ComparerT<double> comparer;
 *
 *		// Compare the 2 instances of Double
 *		int cmp;
 *		comparer.Compare(d1, d2, cmp);
 *		if (cmp < 0) // true
 *		{
 *			...
 *		}
 *	}
 *	@endcode
 */
template<class Type>
class ComparerT :
	public Osp::Base::Collection::IComparerT<Type>,
	public Object
{
// Lifecycle
public:
	/**
	 * This constructor initializes a new instance of the %ComparerT class.
	 *
	 * @since	 1.0
	 */
	ComparerT(void) {}


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~ComparerT(void) { }


// Operation
public:
	/** 
	 * Compares two given instances of the same type.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj1 	The first object to compare
	 * @param[in]	obj2 	The second object to compare
	 * @param[out]  cmp		The result of comparison
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified objects are not of the expected type.
 	 * @remarks		@c cmp can take one of the following values: 
	 * @code
	 * <  0  if the value of @c obj1 is less than the value of @c obj2
	 * == 0  if the value of @c obj1 is equal to the value of @c obj2
	 * >  0  if the value of @c obj1 is greater than the value of @c obj2
	 * @endcode
	 */
	virtual result Compare(const Type& obj1, const Type& obj2, int& cmp) const
	{
		if (obj1 > obj2)
		{
			cmp = 1;
		}
		else if (obj1 < obj2)
		{
			cmp = -1;
		}
		else 
		{
			cmp = 0;
		}

		return E_SUCCESS;
	}
};
}; };// Osp::Base
#endif// _FBASE_COMPARER_T_H_

