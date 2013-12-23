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
 * @file		FBaseColIBidirectionalEnumeratorT.h 
 * @brief		This is the header file for the %IBidirectionalEnumeratorT interface.
 *
 * This header file contains the declarations of the %IBidirectionalEnumeratorT interface.
 *
 */
#ifndef _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_T_H_
#define _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_T_H_

#include "FBaseColIEnumeratorT.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @interface IBidirectionalEnumeratorT
 *
 * @brief	This interface supports a bidirectional iteration over a collection.
 *			One can only access the elements in a collection through %IBidirectionalEnumeratorT. The elements cannot be modified through this interface.
 * @since	1.0
 *
 * @remarks
 * An enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or 
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), MovePrevious(), Reset(), or ResetLast() fails (E_INVALID_OPERATION).
 *
 * The %IBidirectionalEnumeratorT interface supports a bidirectional iteration over a collection.
 *	One can only access the elements in a collection through the %IBidirectionalEnumeratorT. The elements cannot be modified through this interface.
 *
 */
template<class Type>
class IBidirectionalEnumeratorT :
	public IEnumeratorT<Type>
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~IBidirectionalEnumeratorT(void) {}


// Operation

	/**
	 * Advances the %IBidirectionalEnumeratorT to the previous element of the collection. 
	 * A call to the MovePrevious() method after the ResetLast() method positions the enumerator to the last element in the collection.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the front of the collection.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 * @see			Osp::Base::Collection::IEnumeratorT< Type >::MoveNext(), ResetLast()
	 */
	virtual result MovePrevious(void) = 0; 


	/**
	 * Positions the enumerator after the last element in the collection.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 * @see			Osp::Base::Collection::IEnumeratorT< Type >::Reset(), MovePrevious()
	 */
	virtual result ResetLast(void) = 0;


}; // IBidirectionalEnumeratorT

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IBIDIRECTIONAL_ENUMERATOR_T_H_

