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
 * @file		FBaseColICollection.h 
 * @brief		This is the header file for the %ICollection interface.
 *
 * This header file contains the declarations of the %ICollection interface.
 *
 */
#ifndef _FBASE_COL_ICOLLECTION_H_
#define _FBASE_COL_ICOLLECTION_H_


#ifdef ICollection
#undef ICollection
#endif

#include "FBaseTypes.h"
#include "FBaseColIEnumerator.h"
#include "FBaseRtThreadMutex.h"

#ifdef ICollection
#undef ICollection
#endif

namespace Osp { namespace Base { namespace Collection {

/**
 * @interface ICollection
 *
 * @brief	This interface represents a collection of objects.
 *			It defines the size, enumerators, and the synchronization mechanism of a collection.
 * @since	1.0
 * 
 * The %ICollection interface represents a collection of objects. It defines the size, enumerators, and the synchronization mechanism of a collection.
 *
 */
class _EXPORT_BASE_ ICollection
{
public:

// Lifecycle

	/**
	 * This is the destructor for this interface.
	 *
	 * @since	1.0
	 */
	virtual ~ICollection(void) {}


// Operation

	/**
	 * Gets the number of objects currently stored in the collection.
	 *
	 * @since			1.0
	 * @return		An integer value indicating the number of objects currently stored in the collection
	 */
	virtual int GetCount(void) const = 0;


	/**
	 * Returns the enumerator of the ICollection derived class,
	 * or returns @c null if some exception occurs.
	 *
	 * @since			1.0
	 * @return	    A pointer to an enumerator interface of the ICollection derived class, @n
	 *				else @c null if an exception occurs.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	 * @remarks		Use this method to obtain an enumerator (an instance of the IEnumerator derived class)
	 *				to iterate over a collection (an instance of the ICollection derived class).
	 *              The specific error code can be accessed using GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator
	 *
	 */
	virtual IEnumerator* GetEnumeratorN(void) const = 0;	

}; // ICollection


}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_ICOLLECTION_H_

