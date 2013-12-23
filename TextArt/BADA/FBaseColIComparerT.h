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
 * @file		FBaseColIComparerT.h 
 * @brief		This is the header file for the %IComparerT interface.
 *
 * This header file contains the declarations of the %IComparerT interface.
 */
#ifndef _FBASE_COL_ICOMPARER_T_H_
#define _FBASE_COL_ICOMPARER_T_H_

// Includes
#include "FBaseTypes.h"

namespace Osp { namespace Base { namespace Collection { 
/**
 * @interface IComparerT
 *
 * @brief This interface allows derived classes to compare 2 template-based objects of the 
 * same type.
 * @since	 1.0
 *
 * The %IComparerT interface allows derived classes to compare 2 template-based objects of the 
 * same type.
 */
template<class Type>
class IComparerT
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @since	 1.0
	 */
	virtual ~IComparerT(void) { }


// Operation
public:
	/** 
	 * Compares two given instances of the same type.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj1 	The first object to compare
	 * @param[in]	obj2 	The second object to compare
	 * @param[out]  cmp		The result of the comparison
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified objects are not of the expected type.
	 * @remarks		The @c cmp parameter can be: 
	 * @code	 
	 * <  0  if the value of @c obj1 is less than the value of @c obj2
	 * == 0  if the value of @c obj1 is equal to the value of @c obj2
	 * >  0  if the value of @c obj1 is greater than the value of @c obj2
	 * @endcode
	 */
	virtual result Compare(const Type& obj1, const Type& obj2, int& cmp) const = 0;
};
}; }; };// Osp::Base::Collection
#endif// _FBASE_COL_ICOMPARER_T_H_

