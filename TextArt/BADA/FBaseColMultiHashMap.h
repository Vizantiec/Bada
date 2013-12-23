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
 * @file		FBaseColMultiHashMap.h
 * @brief		This is the header file for the %MultiHashMap class.
 *
 * This header file contains the declarations of the %MultiHashMap class.
 */
#ifndef _FBASE_COL_MULTI_HASH_MAP_H_
#define _FBASE_COL_MULTI_HASH_MAP_H_

// includes
#include "FBaseObject.h"
#include "FBaseColIComparer.h"
#include "FBaseColIHashCodeProvider.h"
#include "FBaseColIMultiMap.h"


namespace Osp { namespace Base { namespace Collection {

// Forward declaration
class __MultiHashMapEntry;

/**
 * @class MultiHashMap
 * @brief This class represents a collection of associated keys and values that are organized based on the hash code of the key.
 * @since	1.0
 *
 *  The %MultiHashMap class represents a collection of associated keys and values that are organized based on the hash code of the key.
 * There is no limit on the number of elements with the same key, but duplicated elements with the same key are not allowed.
 * The key and value cannot be @c null.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %MultiHashMap class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Collection;
 *
 *
 *	void
 *	MyClass::MultiHashMapSample(void)
 *	{
 *		MultiHashMap map;
 *
 *		// Construct a MultiHashMap instance with default values for capacity, load factor, hash code provider, and comparer.
 *		map.Construct();
 *
 *		String*		pStr0 = new String(L"Zero");
 *		String*		pStr1 = new String(L"One");
 *		String*		pStr2 = new String(L"Two");
 *
 *		map.Add(*pStr0, *(new Integer(0)));	 	// map.GetCount(): 1, map: (Zero -> 0)
 *		map.Add(*pStr1, *(new Integer(1)));		// map.GetCount(): 2, map: (Zero -> 0), (One -> 1)
 *		map.Add(*pStr2, *(new Integer(2)));		// map.GetCount(): 3, map: (Zero -> 0), (One -> 1), (Two -> 2)
 *		map.Add(*pStr2, *(new Integer(20)));	// map.GetCount(): 4, map: (Zero -> 0), (One -> 1), (Two -> 2, 20)
 *
 *
 *		// Get values with the specified key (GetValuesN)
 *		String*		pKey = new String(L"Two");
 *		Integer*	pValue = null;
 *
 *		IEnumerator *pValueEnum = map.GetValuesN(*pKey);
 *		while(pValueEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pValue = static_cast<Integer*> (pValueEnum->GetCurrent());
 *		}
 *
 *		delete pValueEnum;
 *
 *
 *		// Remove values with the specified key (Remove)     // pStr2, Integer(2), Integer(20) removed
 *		map.Remove(*pKey, true);
 *
 *		delete pKey;
 *
 *
 *		// Use enumerator to access elements in the map
 *		IMapEnumerator* pMapEnum = map.GetMapEnumeratorN();
 *		while (pMapEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pKey = static_cast<String*> (pMapEnum->GetKey());
 *			pValue = static_cast<Integer*> (pMapEnum->GetValue());
 *		}
 *
 *		delete pMapEnum;
 *
 *
 *		// Deallocate all objects
 *		map.RemoveAll(true);
 *
 *	}
 * @endcode
 */
class _EXPORT_BASE_ MultiHashMap :
	public IMultiMap,
	public Object
{
public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	 		1.0
	 * @remarks		After creating an instance of the %MultiHashMap class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see 			Construct()
	 */
	MultiHashMap(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~MultiHashMap(void);


	/**
	 * Initializes a new instance of %MultiHashMap with the specified capacity and load factor.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The GetHashCode() method of the key object is used for hashing and the
	 *				Equals() method of the key object is used for comparing the keys.
	 * @see			MultiHashMap()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75);


	/**
	 * Initializes a new instance of %MultiHashMap by copying the elements of the given map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map				The map to be copied
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets @n
	 *								If it is @c 0, the default load factor(0.75) is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			MultiHashMap()
	 */
	result Construct(const IMultiMap& map, float loadFactor = 0.75);


	/**
	 * Initializes a new instance of the %MultiHashMap class, with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity @n
	 *							If it is @c 0, the default capacity (16) is used.
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMap()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProvider& provider,
		const IComparer& comparer);


	/**
	 * Initializes a new instance of the %MultiHashMap class by copying the elements of the specified map,
	 * with the specified load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map			A map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 *      		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			MultiHashMap()
	 */
	result Construct(const IMultiMap& map, float loadFactor, const IHashCodeProvider& provider,
		const IComparer& comparer);


// Operation

	/**
	 * Adds the specified key-value pair to this map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	A key of the value to add
	 * @param[in]	value 	A value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified pair of @c key and @c value already exists.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			Remove()
	 */
	virtual result Add(const Object& key, const Object& value);


	/**
	 * Gets an enumerator of this map.
	 *
	 * @since	 		1.0
	 * @return		An enumerator (an instance of the IEnumerator derived class) of this map, @n
	 *				else @c null if some exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If the key has multiple values, the enumeration proceeds as follows: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 * @see			IEnumerator(), IMapEnumerator()
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets an enumerator of this map.
	 *
	 * @since	 		1.0
	 * @return		An enumerator (an instance of the IMapEnumerator derived class) of this map, @n
	 *				else @c null if some exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		If the key has multiple values, the enumeration proceeds as follows: {A: a}, {B: b}, {B: c}, {B, d}, {C: e}, ...
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			IEnumerator(), IMapEnumerator()
	 */
	virtual IMapEnumerator* GetMapEnumeratorN(void) const;


	/**
	 * Gets an Enumerator of the values associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An enumerator (an instance of the IEnumerator derived class) of the values associated with the specified key, @n
	 *				else @c null if some exception occurs
	 * @param[in]	key 	A key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual IEnumerator* GetValuesN(const Object& key) const;


	/**
	 * Gets a list of all the keys in this map.
	 *
	 * @since	 		1.0
	 * @return		A list of all the keys in this map
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IList interface returned by the GetValuesN() method.
	 *          	The %IList stores just the pointers to the elements in the map, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const;


	/**
	 * Gets a list of all the values in this map.
	 *
	 * @since			1.0
	 * @return		A list of all the values in this map
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const;


	/**
	 * Removes all the values with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key to be removed
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, bool deallocate = false);


	/**
	 * Removes the specified value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key whose mapping is to be removed from the map
	 * @param[in]	value	The value to be removed
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key and @c value pair is not found in the map.
	 * @remarks		The specified key is also removed if there are no more values associated with it.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, const Object& value, bool deallocate = false);


	/**
	 * Removes all the object pointers in the @c collection. @n
	 * Also removes all the objects if @c deallocate is set to @c true.
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate			Set to @c true to deallocate all objects, @n
	 * 									else @c false
	 * @remarks		This method can be called before deleting @c collection.
	 */
	virtual void RemoveAll(bool deallocate = false);


	/**
	 * Replaces the value associated with the given key with a new value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	A key
	 * @param[in]	value 	A value to be replaced
	 * @param[in]	newValue	A new value to replace the existing value
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key and @c value pair is not found in the map.
	 * @remarks		To add a new key-value pair, use the Add() method.
	 * @see			Add(), GetValuesN()
	 */
	virtual result SetValue(const Object& key,
		const Object& value, const Object& newValue, bool deallocate = false);


// Access

	/**
	 * Gets the number of values currently stored in this map.
	 *
	 * @since	 		1.0
	 * @return		The number of values currently stored in this map
	 */
	virtual int GetCount(void) const;


	/**
	 * Gets the number of values whose key matches the key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	A key to locate
	 * @param[out]	count	The number of values whose key is the @c key
 	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 */
	virtual result GetCount(const Object& key, int& count) const;


// Inquery

	/**
	 * Checks whether the map contains the specified key and value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[in]	value 	The value to locate
	 * @param[out]	out		Set to @c true if the map contains the specified key and value pair, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful. @n
	 * @exception	E_INVALID_ARG		The current state of the instance prohibits the execution of the specified operation, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsKey(), ContainsValue()
	 */
	virtual result Contains(const Object& key, const Object& value, bool& out) const;


	/**
	 * Checks whether the map contains the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key 	The key to locate
	 * @param[out]	out		@c true if the map contains the specified key @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsValue(), Contains()
	 */
	virtual result ContainsKey(const Object& key, bool& out) const;


	/**
	 * Checks whether the map contains the specified value.
	 *
	 * @since	 		1.0
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value 	The value to locate
	 *
	 * @see				ContainsKey(), Contains()
	 */
	virtual bool ContainsValue(const Object& value) const;


	/**
	 * Compares the specified instance to the current instance for equality.
	 *
	 * @since	 		1.0
	 * @return		@c true if the two instances are equal, @n
	 *				@c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of %MultiHashMap class,
	 *				both maps have the same number of elements, and both maps contain the same elements.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	map An instance of MultiHashMap to initialize the current instance
	 * @remarks		This constructor is hidden.
	 */
	MultiHashMap(const MultiHashMap& map);


// Operator

	/**
	 * This is the assignment operator.
	 *
	 * @param[in]	map An instance of MultiHashMap to initialize the current instance
	 * @remarks		This operator is hidden.
	 */
	MultiHashMap& operator =(const MultiHashMap& map);


// Operation

	/**
	 * Copies all the pairs from the specified map to this map.
	 *
	 * @return		An error code
	 * @param[in]	map The map to be copied
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c map is modified during the operation of this method.
	 */
	result AddAll(const IMultiMap& map);


	/**
	 * Gets a hash value for the specified object.
	 *
	 * @return		An @c int hash value for the specified object
	 * @param[in]	obj 	The object to get hash value
	 */
	int Hash(const Object& obj) const;


	/**
	 * Rehashes the contents of this map into a new array with a
   * larger capacity. @n
   * This method is called automatically when the number of keys in this map reaches its threshold.
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity @n
	 *								It must be a power of two and be greater than current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 */
	result Resize(int newCapacity);


	/**
	 * This method clears all key-value pairs in this map.
	 *
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 */
	void Reset(bool deallocate = false);


// Attribute

	__MultiHashMapEntry** __pTable;
	int __count;
	int __capacity;
	float __loadFactor;
	int __threshold;
	IHashCodeProvider* __pProvider;
	IComparer* __pComparer;
	bool __defaultConstruct;
	int __modCount;

	static const int DEFAULT_CAPACITY = 16;
	static const float DEFAULT_LOAD_FACTOR;


// Friend class
	friend class __MultiHashMapEnumerator;


private:
	friend class MultiHashMapEx;
	class MultiHashMapEx* __pMultiHashMapEx;

}; // MultiHashMap

}; }; }; // Osp::Base::Collection
#endif //_FBASE_COL_MULTI_HASH_MAP_H_

