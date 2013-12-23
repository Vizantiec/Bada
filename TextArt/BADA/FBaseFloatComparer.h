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
 * @file		FBaseFloatComparer.h 
 * @brief		This is the header file for the %FloatComparer class.
 *
 * @see			Float and Osp::Base::Collection::IComparer
 *
 * This header file contains the declarations of the %FloatComparer class.
 */
#ifndef _FBASE_FLOAT_COMPARER_H_
#define _FBASE_FLOAT_COMPARER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseColIComparer.h"



namespace Osp { namespace Base {
/**
 *	@class	FloatComparer
 *	@brief	This class checks for equivalence between 2 instances of the Float type. 
 *	@since	1.0
 *
 *	The %FloatComparer class checks for equivalence between 2 instances of the Float type. 
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/collection_comparison.htm">Collection Comparisons</a>.
 *
 *  The following example demonstrates how to use the %FloatComparer class.
 *  
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::FloatComparerSample(void)
 *	{
 *		Float f1(123);
 *		Float f2(124);
 *		FloatComparer comparer;
 *
 *		// Compare the 2 instances of Float
 *		int cmp;
 *		comparer.Compare(f1, f2, cmp);
 *		if (cmp < 0) // true
 *		{
 *			...
 *		}
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ FloatComparer :
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
	FloatComparer(void);


	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~FloatComparer(void);


// Operation
public:
	/** 
	 *	Compares two given instances of type Float.
	 *
	 *	@since		1.0
	 *  @return		An error code
	 *	@param[in]	obj1 	The first instance of type %Float
	 *	@param[in]	obj2 	The second instance of type %Float
	 *	@param[out] cmp		The result of comparison
	 *  @exception	E_SUCCESS		The method is successful.
	 *  @exception	E_INVALID_ARG	The specified object instances are not of the expected type.
	 *  @remarks	The value of @c cmp can be: 
	 *	@code	 
	 *	<  0  if the value of obj1 is less than the value of obj2
	 *	== 0  if the value of obj1 is equal to the value of obj2
	 *	>  0  if the value of obj1 is greater than the value of obj2
	 *	@endcode
	 */
	virtual result Compare(const Osp::Base::Object& obj1, const Osp::Base::Object& obj2, int& cmp) const;


private:
	friend class FloatComparerEx;
	class FloatComparerEx* __pFloatComparerEx;
};
}; }; // Osp::Base
#endif// _FBASE_FLOAT_COMPARER_H_
