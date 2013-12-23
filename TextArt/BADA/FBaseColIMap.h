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
 * @file		FBaseColIMap.h 
 * @brief		This is the header file for the %IMap interface.
 *
 * This header file contains declarations of the %IMap interface.
 */
#ifndef _FBASE_COL_IMAP_H_
#define _FBASE_COL_IMAP_H_

// includes
#include "FBaseColICollection.h"
#include "FBaseColIMapEnumerator.h"
#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Collection {

class IList;
class MapEntry;

/**
 * @interface IMap
 *
 * @brief	This interface represents a collection of key-value pairs. 
 * @since	1.0
 *
 * The %IMap interface abstracts a collection of key-value pairs. An %IMap instance 
 * contains unique keys and each key maps to a single value.			
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 */
class _EXPORT_BASE_ IMap :
	public ICollection
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~IMap(void);


// Operation

	/** 
	 * Adds the specified key-value pair to the map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	The key to add
	 * @param[in]	value 	The corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(const Object& key, const Object& value) = 0;


	/** 
	 * Gets the value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key 	The key to find the associated value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual const Object* GetValue(const Object& key) const = 0;


	/** 
	 * Gets the value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key 	The key to find the associated value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual Object* GetValue(const Object& key) = 0;


	/** 
	 * Gets a list of all the keys in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to a list of all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IList interface returned by the GetValuesN() method.
	 *      		The %IList interface stores just the pointers to the elements in the map, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const = 0;


	/** 
	 * Gets a list of all the values in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to a list of all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const = 0;


	/** 
	 * Removes the value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key for which the value is to be removed
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, bool deallocate = false) = 0;


	/**
	 * Removes all the object pointers in the collection. If the @c deallocate parameter is set to @c true, the method also removes all the objects. This method can be called before deleting the collection.
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate		Set to @c true to deallocate all the objects, @n
	 * 								else @c false
	 */
	virtual void RemoveAll(bool deallocate = false) = 0;


	/** 
	 * Replaces the value associated with the specified key with the specified value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	The key for which the value is to be replaced
	 * @param[in]	value 	The new value
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks	Use the Add() method to add a new key-value pair.
	 * @see		Add(), GetValue()
	 */
	virtual result SetValue(const Object& key, const Object& value, bool deallocate = false) = 0;


// Inquery

	/** 
	 * Checks whether the map contains the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 */
	virtual result ContainsKey(const Object& key, bool& out) const = 0;


	/** 
	 * Checks whether the map contains the specified value.
	 *
	 * @since	 		1.0
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value 	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const Object& value) const = 0;


	/**
	* Gets an instance of the IMapEnumerator for the map.
	*
	* @since	 		1.0
	* @return			%IMapEnumerator object of this map, @n
	* 				else @c null if an exception occurs
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			IEnumerator, IMapEnumerator
	*/
	virtual IMapEnumerator* GetMapEnumeratorN(void) const = 0;


};// IMap

}; }; }; // Osp::Base::Collection
#endif// _FBASE_COL_IMAP_H_

