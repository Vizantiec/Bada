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
 * @file		FBaseColIMapEnumeratorT.h 
 * @brief		This is the header file for the %IMapEnumeratorT interface.
 *
 * This header file contains declarations of the %IMapEnumeratorT interface.
 */
#ifndef _FBASE_COL_IMAP_ENUMERATOR_T_H_
#define _FBASE_COL_IMAP_ENUMERATOR_T_H_

#include "FBaseColIEnumeratorT.h"
#include "FBaseColMapEntryT.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @interface IMapEnumeratorT
 *
 * @brief	This interface supports simple iteration over a template-based map.
 *			Using this method, you can only access the elements in the map. You cannot modify the elements.
 * @since	1.0
 *
 * @remarks
 * An enumerator remains valid as long as the map remains unchanged.
 * If changes are made to the map, such as adding, modifying, or 
 * deleting elements, the enumerator is irrecoverably invalidated. The next call to any method returns an E_INVALID_OPERATION message.
 *
 * The %IMapEnumeratorT interface supports simple iteration over a template-based map.
 *			Using this method, you can only access the elements in the map. You cannot modify the elements.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 
 *
 */
template<class KeyType, class ValueType>
class IMapEnumeratorT
	:	public IEnumeratorT< MapEntryT<KeyType, ValueType> >
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~IMapEnumeratorT(void) {}


// Operation

	/**
	 * Reads the current key in the map. 
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[out]	key The current key
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or after the last element or the collection is modified after the enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result GetKey(KeyType& key) const = 0;


	/**
	 * Reads the current value in the map. 
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[out]	value The current value
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The enumerator is currently positioned before the first element or after the last element or the collection is modified after the enumerator is created.
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result GetValue(ValueType& value) const = 0;

}; // IMapEnumeratorT

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_IMAP_ENUMERATOR_H_

