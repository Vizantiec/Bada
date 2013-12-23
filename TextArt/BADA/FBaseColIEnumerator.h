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
 * @file		FBaseColIEnumerator.h 
 * @brief		This is the header file for the %IEnumerator interface.
 *
 * This header file contains the declarations of the %IEnumerator interface.
 *
 */
#ifndef _FBASE_COL_IENUMERATOR_H_
#define _FBASE_COL_IENUMERATOR_H_

#include "FBaseTypes.h"
#include "FBaseConfig.h"


namespace Osp {namespace Base {class Object;}}


namespace Osp { namespace Base { namespace Collection {

/**
 * @interface IEnumerator
 *
 * @brief	This interface supports simple iteration over a collection. 
 *			You can only access the elements in a collection through %IEnumerator. The elements cannot be modified through this interface.
 * @since 	1.0
 *
 * @remarks
 * An Enumerator remains valid as long as the collection remains unchanged.
 * If changes are made to the collection, such as adding, modifying, or
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to GetCurrent(), MoveNext(), or Reset() fails and returns
 * E_INVALID_OPERATION.
 *
 * The %IEnumerator interface supports simple iteration over a collection. 
 * You can only access the elements in a collection through %IEnumerator. The elements cannot be modified through this interface.
 *
 */
class _EXPORT_BASE_ IEnumerator
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since 	1.0
	 */
	virtual ~IEnumerator(void) {}


// Operation

	/**
	 * Gets the current object in the collection.
	 *
	 * @since 		1.0
	 * @return		The current object in the collection, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element 
	 *									or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetLastResult()
	 */
	virtual Osp::Base::Object* GetCurrent(void) const = 0;
	

	/**
	 * Advances IEnumerator to the next element of the collection. @n
	 * After the enumerator is first created or reset using the Reset() method,
	 * the first call to this method positions the enumerator to the first element in the collection. 
	 *
	 * @since 		1.0
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
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the collection is modified after the enumerator is created.
	 */
	virtual result Reset(void) = 0;


}; // IEnumerator

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IENUMERATOR_H_

