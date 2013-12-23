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
 * @file		FBaseColICollectionT.h 
 * @brief		This is the header file for the %ICollectionT interface.
 *
 * This header file contains the declarations of the %ICollectionT interface.
 *
 */
#ifndef _FBASE_COL_BASE_ICOLLECTION_T_H_
#define _FBASE_COL_BASE_ICOLLECTION_T_H_

#include "FBaseTypes.h"
#include "FBaseColIEnumeratorT.h"
#include "FBaseRtThreadMutex.h"

namespace Osp { namespace Base { namespace Collection {

/**
 * @interface ICollectionT
 *
 * @brief	This interface represents a template-based collection of objects.
 *			It defines the size, and enumerators.
 * @since	1.0
 *
 * The %ICollectionT interface represents a template-based collection of objects.
 *			It defines the size, and enumerators.
 */
template <class Type>
class ICollectionT
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ICollectionT(void) {}


// Operation

	/**
	 * Gets the number of objects currently stored in the collection.
	 *
	 * @since			1.0
	 * @return		The number of objects currently stored in the collection
	 */
	virtual int GetCount(void) const = 0;


	/**
	 * Returns the enumerator of the %ICollectionT derived class,
	 * or returns @c null if an exception occurs.
	 *
	 * @since			1.0
	 * @return		A pointer to an enumerator interface of the %ICollectionT derived class, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	  The memory is insufficient.
	 * @remarks		Use this method to obtain an enumerator (an instance of the IEnumeratorT derived class)
	 *				to iterate over a collection (an instance of the %ICollectionT derived class).
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator
	 */
	virtual IEnumeratorT<Type>* GetEnumeratorN(void) const = 0;

}; // ICollectionT

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_ICOLLECTION_T_H_

