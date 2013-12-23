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
 * @file		FBaseColIMultiMapT.h 
 * @brief		This is the header file for the %IMultiMapT interface.
 *
 * This header file contains the declarations of the %IMultiMapT interface.
 */
#ifndef _FBASE_COL_IMULTI_MAP_T_H_
#define _FBASE_COL_IMULTI_MAP_T_H_

// includes
#include "FBaseColICollectionT.h"
#include "FBaseColIMapEnumeratorT.h"
#include "FBaseColMapEntryT.h"


namespace Osp { namespace Base { namespace Collection {

template<class Type> class IListT;

/**
 * @interface IMultiMapT
 *
 * @brief	This interface represents a template-based collection of key-value pairs. 
 * @since	1.0
 *
 * The %IMultiMapT interface abstracts a template-based collection of key-value pairs. 
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 */
template<class KeyType, class ValueType>
class IMultiMapT :
	public ICollectionT< MapEntryT<KeyType, ValueType> >
{
public:

// Lifecycle

	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~IMultiMapT(void) {}


// Operation

	/** 
	 * Adds the specified key-value pair to the map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key to add
	 * @param[in]	value	The corresponding value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key and @c value already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see Remove()
	 */
	virtual result Add(const KeyType& key, const ValueType& value) = 0;


	/**
	 * Gets the number of values stored in the map.
	 *
	 * @since	  1.0
	 * @return	The number of values currently stored in the map
	 */
	virtual int GetCount(void) const = 0;


	/**
	 * Gets the number of values whose key matches the specified key.
	 *
	 * @since	 		1.0
	 * @return		The number of values whose key matches the specified key
	 * @param[in]	key	The key to locate in the map
	 * @param[out]	count	The number of values whose key matches the specified key
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const KeyType& key, int& count) const = 0;


	/** 
	 * Gets an enumerator of the values associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An instance of the IEnumeratorT derived class with the values associated with the specified key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IEnumeratorT<ValueType>* GetValuesN(const KeyType& key) const = 0;


	/** 
	 * Gets a list of all the keys in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to a list of all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IListT interface returned by the GetValuesN() method.
	 *           	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT<KeyType>* GetKeysN(void) const = 0;


	/** 
	 * Gets a list of all the values in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to a list of all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT<ValueType>* GetValuesN(void) const = 0;


	/** 
	 * Removes all the values associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key whose associated values need to be removed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key) = 0;


	/** 
	 * Removes the specified value associated with the specified key. @n
	 * The key is also removed if there are no more values associated with it.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key	The key whose mapping is to be removed from the map
	 * @param[in]	value	The value to be removed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key and @c value pair is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key, const ValueType& value) = 0;


	/** 
	 * Removes all the key-value pairs in the map.
	 *
	 * @since	 1.0
	 */
	virtual void RemoveAll(void) = 0;


	/** 
	 * Replaces the specified value associated with the specified key with a new value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key			The key whose associated value needs to be replaced 
	 * @param[in]	value		The value associated with the key
	 * @param[in]	newValue	The new value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key and @c value pair is not found in the map.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add(), GetValuesN()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value, const ValueType& newValue) = 0;


// Inquery

	/** 
	 * Checks whether the map contains the specified key-value pair.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key to locate
	 * @param[in]	value	The value to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key-value pair, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful. @n
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsKey(), ContainsValue()
	 */
	virtual result Contains(const KeyType& key, const ValueType& value, bool& out) const = 0;


	/** 
	 * Checks whether the map contains the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key to locate
	 * @param[out]	out 	Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS		The method is successful. @n
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the comparer has failed to compare the keys.
	 * @see			ContainsValue(), Contains()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out ) const = 0;


	/** 
	 * Checks whether the map contains the specified value.
	 *
	 * @since	 		1.0
	 * @return		Set to @c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey(), Contains()
	 */
	virtual bool ContainsValue(const ValueType& value) const = 0;


	/**
	 * Gets an enumerator of the map.
	 *
	 * @since	 		1.0
	 * @return		An instance of the IMapEnumeratorT class for the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If a key has multiple values, the enumeration proceeds as follows: @n
	 * 				{A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ... @n
	 *         		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator, Osp::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT<KeyType, ValueType>* GetMapEnumeratorN(void) const = 0;


};// IMultiMapT

}; }; }; // Osp::Collection
#endif// _FBASE_COL_IMULTI_MAP_T_H_

