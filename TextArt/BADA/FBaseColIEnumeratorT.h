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
 * @file		FBaseColIEnumeratorT.h 
 * @brief		This is the header file for the %IEnumeratorT interface.
 *
 * This header file contains the declarations of the %IEnumeratorT interface.
 *
 */
#ifndef _FBASE_COL_IENUMERATOR_T_H_
#define _FBASE_COL_IENUMERATOR_T_H_

#include "FBaseTypes.h"

namespace Osp { namespace Base { namespace Collection {

/**
 * @interface IEnumeratorT
 *
 * @brief	This interface supports simple iteration over a template-based collection. 
 * You can only access the elements in a collection through %IEnumeratorT. The elements cannot be modified through this interface.
 * @since	1.0
 *
 * @remarks
 * An enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or 
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), or Reset() fails and returns
 * E_INVALID_OPERATION.
 *
 * The %IEnumeratorT interface supports simple iteration over a template-based collection. 
 * You can only access the elements in a collection through %IEnumeratorT. The elements cannot be modified through this interface.
 *
 *
 */
template <class Type>
class IEnumeratorT
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IEnumeratorT(void) {}


// Operation

	/**
	 * Reads the current object in the collection. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	obj A pointer to the current object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or 
	 *									after the last element or the collection is modified after the enumerator is created.
	 */
	virtual result GetCurrent(Type& obj) const = 0;
	

	/**
	 * Advances %IEnumeratorT to the next element of the collection. 
	 * After the enumerator is first created or reset using the Reset() method,
	 * the first call to this method positions the enumerator to the first element in the collection. 
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 * @see			Reset()
	 */
	virtual result MoveNext(void) = 0; 


	/**
	 * Positions the enumerator before the first element in the collection.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 */
	virtual result Reset(void) = 0;


}; // IEnumeratorT


}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IENUMERATOR_T_H_

