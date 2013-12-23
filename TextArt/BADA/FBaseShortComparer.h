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
 * @file		FBaseShortComparer.h 
 * @brief		This is the header file for the %ShortComparer class.
 *
 * @see			Short and Osp::Base::Collection::IComparer 
 *
 * This header file contains the declarations of the %ShortComparer class.
 */
#ifndef _FBASE_SHORT_COMPARER_H_
#define _FBASE_SHORT_COMPARER_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseColIComparer.h"


namespace Osp { namespace Base {
/**
 *	@class	ShortComparer
 *	@brief	This class compares 2 instances of the %Short type for equivalence.
 *	@since	1.0
 *
 *	The %ShortComparer class compares 2 instances of the %Short type for equivalence.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 * The following example demonstrates how to use the %ShortComparer class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::ShortComparerSample(void)
 *	{
 *		Short s1(123);
 *		Short s2(124);
 *		ShortComparer comparer;
 *
 *		int cmp;
 *		comparer.Compare(s1, s2, cmp);
 *		if (cmp < 0) // true
 *		{
 *			...
 *		}
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ ShortComparer :
	public Object,
	public Osp::Base::Collection::IComparer
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	ShortComparer(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ShortComparer(void);


// Operation
public:
	/** 
	 *	Compares two specified instances of type Short.
	 *
	 *	@since			1.0
	 *  @return			An error code
	 *	@param[in]	obj1 			An object of %Short to compare
	 *	@param[in]	obj2 			An object of %Short to compare
	 *	@param[out] cmp				The result of comparison
	 *  @exception	E_SUCCESS		The method is successful.
	 *  @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 *  @remarks		The value of @c cmp can be: 
	 *	@code	 
	 *	<  0  if the value of obj1 is less than the value of obj
	 *	== 0  if the value of obj1 is equal to the value of obj
	 *	>  0  if the value of obj1 is greater than the value of obj
	 *	@endcode
	 */
	virtual result Compare(const Osp::Base::Object& obj1, const Osp::Base::Object& obj2, int& cmp) const;


private:
	friend class ShortComparerEx;
	class ShortComparerEx* __pShortComparerEx;
};
}; }; // Osp::Base
#endif// _FBASE_SHORT_COMPARER_H_
