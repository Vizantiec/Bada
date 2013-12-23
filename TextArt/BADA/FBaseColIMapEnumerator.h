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
 * @file		FBaseColIMapEnumerator.h 
 * @brief		This is the header file for the %IMapEnumerator interface.
 *
 * This header file contains the declarations of the %IMapEnumerator interface.
 */
#ifndef _FBASE_COL_IMAP_ENUMERATOR_H_
#define _FBASE_COL_IMAP_ENUMERATOR_H_

#include "FBaseColIEnumerator.h"
#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Collection {

class MapEntry;

/**
 * @interface IMapEnumerator
 *
 * @brief	This interface supports simple iteration over a map.
 *			Using this method, you can only access the elements in the map. You cannot modify the elements.
 * @since	1.0
 *
 * @remarks
 * An Enumerator remains valid as long as the map remains unchanged.
 * If changes are made to the map, such as adding, modifying, or 
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to any method returns an E_INVALID_OPERATION message.
 *
 * The %IMapEnumerator interface supports simple iteration over a map.
 * Using this method, you can only access the elements in the map. You cannot modify the elements.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 
 *
 */
class _EXPORT_BASE_ IMapEnumerator
:	public IEnumerator
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~IMapEnumerator(void) {}


// Operation

	/**
	 * Gets the current object from the collection.
	 *
	 * @since	 		1.0
	 * @return		A pointer to the current object in the collection, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	 Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetLastResult()
	 */
	virtual Object* GetCurrent(void) const = 0;


	/**
	 * Gets the current key in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to the current key in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	   Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetLastResult()
	 */
	virtual Object* GetKey(void) const = 0;


	/**
	 * Gets the current value in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to the current value in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	 Either of the following conditions has occurred: @n
	 *									- The current state of the instance prohibits the execution of the specified operation. @n
	 *									- The enumerator is currently positioned before the first element or after the last element. @n
	 *									- The collection is modified after the enumerator is created.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				GetLastResult()
	 */
	virtual Object* GetValue(void) const = 0;


}; // IMapEnumerator

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IMAP_ENUMERATOR_H_

