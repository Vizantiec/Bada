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
 * @file		FBaseColHashMapT.h 
 * @brief		This is the header file for the %HashMapT class.
 *
 * This header file contains the declarations of the %HashMapT class.
 */
#ifndef _FBASE_COL_HASH_MAP_T_H_
#define _FBASE_COL_HASH_MAP_T_H_

// includes
#include "FBaseObject.h"
#include "FBaseResult.h"
#include "FBaseColIComparerT.h"
#include "FBaseColIHashCodeProviderT.h"
#include "FBaseColIListT.h"
#include "FBaseColIMapT.h"
#include "FBaseColArrayListT.h"
#include "FBaseColMapEntryT.h"
#include "FBaseComparerT.h"


namespace Osp { namespace Base { namespace Collection {

// Forward declaration
template<class KeyType, class ValueType> class __HashMapEntryT;
template<class KeyType, class ValueType> class __HashMapEnumeratorT;
template<class KeyType> class __HashMapDefaultProviderT;

/**
 * @class HashMapT
 * @brief This class provides a template-based collection of associated keys and values 
 * that are organized based on the hash code of the key.
 * @since	 1.0
 *
 * The %HashMapT class provides a template-based collection of associated keys and values 
 * that are organized based on the hash code of the key.
 * It contains unique keys and each key maps to one single value.
 * The key and value cannot be a null reference. Several methods in the %HashMapT class need assignment (=) operators of KeyType and ValueType.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to use the %HashMapT class.

 * @code
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Collection;
 *
 *	
 *	void
 *	MyClass::HashMapTSample(void)
 *	{
 *		HashMapT<int, int> map;
 *	
 *		// Construct a HashMapT instance with default capacity, load factor, hash code provider, and comparer.
 *		map.Construct();
 *	
 *
 *		map.Add(1, 100);	// map.GetCount(): 1
 *		map.Add(2, 200);	// map.GetCount(): 2
 *		map.Add(3, 300);	// map.GetCount(): 3
 *		
 *	
 *		int key;
 *		int value;
 *
 *		// Get a value with the specified key (GetValue)
 *		key = 1;
 *		map.GetValue(key, value);	// value: 100
 *	
 *
 *		// Remove a value with the specified key (Remove)
 *		map.Remove(key);
 *
 *	
 *		// Use enumerator to access elements in the map
 *		IMapEnumeratorT<int, int>*	pMapEnum = map.GetMapEnumeratorN();
 *		while (pMapEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pMapEnum->GetKey(key);
 *			pMapEnum->GetValue(value);
 *		}
 *	
 *		delete pMapEnum;
 *
 *	}
 * @endcode
 */
template<class KeyType, class ValueType>
class HashMapT :
	public IMapT<KeyType, ValueType>,
	public Object
{
public:

// Lifecycle

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	 		1.0
	 * @remarks		After creating an instance of the %HashMapT class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	HashMapT(void)
	:	__pTable(null),
		__count(0),
		__capacity(0),
		__loadFactor(0),
		__threshold(0),
		__pProvider(null),
		__pComparer(null),
		__defaultConstruct(false),
		__modCount(0)		
	{
	}


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~HashMapT(void)
	{
		__modCount++;
		if (null != __pTable)
		{
			Reset();
			delete []__pTable;
		}

		if (__defaultConstruct)
		{
			delete __pProvider;
			delete __pComparer;
		}
		
	}


	/**
	 * Initializes this instance of %HashMapT with the specified parameters.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or 
	 *								the @c capacity or the @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		To work properly, the key type should be of a primitive number type.
	 * @see			HashMapT()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[E_INVALID_ARG] The capacity(%d) MUST be greater than or equal to 0.", capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[E_INVALID_ARG] The loadFactor(%f) MUST be greater than or equal to 0.0.", loadFactor);

		result r = E_SUCCESS;
		// set capacity
		if (0 == capacity)
		{
			__capacity = DEFAULT_CAPACITY;
		}
		else
		{
			__capacity = 1;
			while (__capacity < capacity)
				__capacity <<= 1;
		}

		// set load factor
		if (0 == loadFactor)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		// set threshold
		__threshold = static_cast<int>(__capacity * __loadFactor);

		// set hash code provider
		__pProvider = new __HashMapDefaultProviderT<KeyType>();
		
		// set comparer
		__pComparer = new Osp::Base::ComparerT<KeyType>();

		__defaultConstruct = true;

		__pTable = new __HashMapEntryT<KeyType, ValueType>*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");
		for (int i = 0; i < __capacity; i++)
		{
			__pTable[i] = null;
		}

		return r;

CATCH:
		__capacity = 0;
		delete __pProvider;
		delete __pComparer;

		return r;
	}


	/**
	 * Initializes this instance of the %HashMapT class by copying the elements of a specified map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			HashMapT()
	 */
	result Construct(const IMapT<KeyType, ValueType>& map, float loadFactor = 0.75) 
	{
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[E_INVALID_ARG] The loadFactor(%f) MUST be greater than or equal to 0.0.", loadFactor);

		result r = E_SUCCESS;

		if (0 == loadFactor)
		{
			loadFactor = DEFAULT_LOAD_FACTOR;
		}

		int capacity = static_cast<int>(map.GetCount() / loadFactor) + 1;

		r = Construct(capacity, loadFactor);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		r = AddAll(map);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		return r;

CATCH:
		Reset();
		delete []__pTable;
		__pTable = null;

		__capacity = 0;
		__pProvider = null;
		__pComparer = null;

		return r;
	}


	/**
	 * Initializes this instance of an empty %HashMapT class, with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity	The initial capacity @n
	 *							If it is @c 0, the default capacity (16) is used.
	 * @param[in]	loadFactor	The maximum ratio of the elements to buckets @n
	 *							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProviderT-derived class that supplies the hash codes 
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparerT-derived class to use when comparing keys
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	Either of the following conditions has occurred: @n
	 *								- A specified input parameter is invalid. @n
	 *								- The specified @c capacity is negative. @n
	 *								- The @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMapT()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProviderT<KeyType>& provider, 
		const IComparerT<KeyType>& comparer)
	{
		TryReturn(capacity >= 0, E_INVALID_ARG, "[E_INVALID_ARG] The capacity(%d) MUST be greater than or equal to 0.", capacity);
		TryReturn(loadFactor >= 0, E_INVALID_ARG, "[E_INVALID_ARG] The loadFactor(%f) MUST be greater than or equal to 0.0.", loadFactor);

		result r = E_SUCCESS;
		// set capacity
		if (0 == capacity)
		{
			__capacity = DEFAULT_CAPACITY;
		}
		else
		{
			__capacity = 1;
			while (__capacity < capacity)
				__capacity <<= 1;
		}

		// set load factor
		if (0 == loadFactor)
		{
			__loadFactor = DEFAULT_LOAD_FACTOR;
		}
		else
		{
			__loadFactor = loadFactor;
		}

		// set threshold
		__threshold = static_cast<int>(__capacity * __loadFactor);

		// set hash code provider
		__pProvider = const_cast<IHashCodeProviderT<KeyType>*>(&provider);

		// set comparer
		__pComparer = const_cast<IComparerT<KeyType>*>(&comparer);


		__pTable = new __HashMapEntryT<KeyType, ValueType>*[__capacity];
		TryCatch(__pTable != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");
		for (int i = 0; i < __capacity; i++)
		{
			__pTable[i] = null;
		}

		return r;

	CATCH:
		__capacity = 0;
		__pProvider = null;
		__pComparer = null;
		
		return r;
	}


	/**
	 * Initializes this instance of the %HashMapT class by copying the elements of a specified map,
	 * with a specified load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	*							If it is @c 0, the default load factor (0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProviderT-derived class that supplies the hash codes 
	 *							for all keys in this map
	 * @param[in]	comparer	An instance of the IComparerT-derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- The @c loadFactor is negative. @n
	 *									- The @c provider is a @c null or the @c comparer is a @c null.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMapT()
	 */
	result Construct(const IMapT<KeyType, ValueType>& map, float loadFactor, 
		const IHashCodeProviderT<KeyType>& provider, const IComparerT<KeyType>& comparer)
	{
		TryReturn((loadFactor >= 0), E_INVALID_ARG, "[E_INVALID_ARG] The loadFactor(%f) MUST be greater than or equal to 0.0.", loadFactor);

		result r = E_SUCCESS;
		if (0 == loadFactor)
		{
			loadFactor = DEFAULT_LOAD_FACTOR;
		}

		int capacity = static_cast<int>(map.GetCount() / loadFactor) + 1;
		r = Construct(capacity, loadFactor, provider, comparer);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		r = AddAll(map);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		return r;

	CATCH:
		Reset();
		delete []__pTable;
		__pTable = null;

		__capacity = 0;
		__pProvider = null;
		__pComparer = null;

		return r;
	}


// Operation

	/** 
	 * Adds the specified key-value pair to a map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key of the value to add
	 * @param[in]	value	The value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c key already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see Remove()
	 */
	virtual result Add(const KeyType& key, const ValueType& value)
	{
		__HashMapEntryT<KeyType, ValueType>* temp;

		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);
		bool out = false;

		// check whether the pKey exists or not in this map.
		r = ContainsKey(key, out);
		TryCatch((!out), r= E_OBJ_ALREADY_EXIST, "[E_OBJ_ALREADY_EXIST] The key is already exist in this collection.");
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		r = E_SUCCESS;

		// pKey is not exist.
		temp = new __HashMapEntryT<KeyType, ValueType>(key, value, __pTable[i], hash);
		TryCatch(temp != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");
		__pTable[i] = temp;
		__modCount++;

		if (__count++ >= __threshold)
		{
			r = Resize(__capacity * 2);
			TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));
		}

		return r;

	CATCH:
		return r;
	}


	/**
	 * Gets the elements of a map in an instance of the IMapEnumeratorT-derived class.
	 *
	 * @since	 		1.0
	 * @return		An instance of the %IMapEnumeratorT-derived class, if successful @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator, Osp::Base::Collection::IMapEnumerator
	 */
	virtual IEnumeratorT<MapEntryT<KeyType, ValueType> >* GetEnumeratorN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		__HashMapEnumeratorT<KeyType, ValueType>* pEnum = new __HashMapEnumeratorT<KeyType, ValueType>(*this, __modCount);
		TryCatch(pEnum != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");

		return pEnum;

	CATCH:
		SetLastResult(r);
		return null;
	}


	/**
	 * Gets the elements of a map in an instance of the IMapEnumeratorT class.
	 *
	 * @since	 		1.0
	 * @return		An instance of the %IMapEnumeratorT class, if successful @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator, Osp::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumeratorT<KeyType, ValueType>* GetMapEnumeratorN(void) const
	{
		return static_cast<IMapEnumeratorT<KeyType, ValueType>* > (GetEnumeratorN());
	}


	/** 
	 * Gets the value associated with a specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									The comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value) const
	{
		result r = E_OBJ_NOT_FOUND;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagated.", GetErrorMessage(r));

				// key is found
				if (cmpResult == 0) 
				{
					value = pEntry->value;
					r = E_SUCCESS;
					break;
				}

				r = E_OBJ_NOT_FOUND;
			}
		}

		return r;
	}


	/** 
	 * Gets the value associated with a specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key	The key to locate
	 * @param[out]	value	The value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			SetValue()
	 */
	virtual result GetValue(const KeyType& key, ValueType& value)
	{
		return (static_cast<const HashMapT<KeyType, ValueType>*>(this))->GetValue(key, value);
	}


	/** 
	 * Gets a list of all the keys in a map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to an IListT object containing all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IListT interface returned by the GetValuesN() method.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IListT<KeyType>* GetKeysN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		ArrayListT<KeyType>* pList = new ArrayListT<KeyType>();
		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				r = pList->Add(pEntry->key);
				TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));
			}
		}

		return pList;

	CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}


	/** 
	 * Gets all the values in a map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to an IListT object containing all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IListT<ValueType>* GetValuesN(void) const
	{
		ClearLastResult();

		result r = E_SUCCESS;

		ArrayListT<ValueType>* pList = new ArrayListT<ValueType>();
		r = pList->Construct(__count);
		TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				r = pList->Add(pEntry->value);
				TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));
			}
		}

		return pList;

	CATCH:
		delete pList;

		SetLastResult(r);
		return null;
	}


	/** 
	 * Removes the value associated with a specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const KeyType& key)
	{
		result r = E_OBJ_NOT_FOUND;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		__HashMapEntryT<KeyType, ValueType>* pPrev = __pTable[i];
		for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagated.", GetErrorMessage(r));

				if (cmpResult == 0) 
				{
					__modCount++;
					if (pPrev == pEntry)
						__pTable[i] = pEntry->pNext;
					else
						pPrev->pNext = pEntry->pNext;
					delete pEntry;
					__count--;
					
					r = E_SUCCESS;
					break;
				}

				r = E_OBJ_NOT_FOUND;
			}
			pPrev = pEntry;
		}

		return r;
	}


	/** 
	 * Removes all key-value pairs in the map.
	 *
	 * @since	 1.0
	 */
	virtual void RemoveAll(void)
	{
		if (__count > 0)
		{
			__modCount++;
			Reset();
			__count = 0;
		}
	}


	/** 
	 * Replaces the value associated with a specified key with a new value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key for which the value is to be replaced
	 * @param[in]	value	The new value to replace
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 * @see			Add(), GetValue()
	 */
	virtual result SetValue(const KeyType& key, const ValueType& value)
	{
		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		int cmpResult = -1;
		for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{			
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagated.", GetErrorMessage(r));
				if (cmpResult == 0) // key is exist -> change value.
				{
					pEntry->value = value;
					break;
				}
			}
		}

		if (cmpResult != 0)
		{
			r = E_OBJ_NOT_FOUND;
		}
		
		__modCount++;

		return r;
	}
	

// Access
	/**
	 * Gets the number of pairs currently stored in a map.
	 *
	 * @since	 		1.0
	 * @return		The pairs stored in the map
	 */
	virtual int GetCount(void) const
	{
		return __count;
	}


// Inquery

	/** 
	 * Checks whether a map contains the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key	The key to locate
	 * @param[out]	out 	Set to @c true if the map contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 */
	virtual result ContainsKey(const KeyType& key, bool& out) const
	{
		out  = false;

		result r = E_SUCCESS;
		int hash = Hash(key);
		int i = hash & (__capacity - 1);

		for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
		{
			if (hash == pEntry->hash)
			{
				int cmpResult;
				r = __pComparer->Compare(key, pEntry->key, cmpResult);
				if (IsFailed(r))
				{
					out = false;
					TryReturn(r == E_SUCCESS, E_INVALID_ARG, "[%s] Propagated.", GetErrorMessage(r));
				}

				if (cmpResult == 0)
				{
					out  = true;
					break;
				}
			}
		}

		return E_SUCCESS;
	}


	/** 
	 * Checks whether a map contains the specified value.
	 *
	 * @since	 		1.0
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const ValueType& value) const
	{
		bool out = false;
		for (int i = 0; i < __capacity; i++)
		{
			for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
			{
				if (value == pEntry->value)
				{
					out = true;
					break;
				}
			}
			if (out)
				break;
		}

		return out;
	}


	/** 
	 * Compares two instances of the %HashMapT class.
	 *
	 * @since	 		1.0
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same number of elements and all the elements of each other.
	 */
	virtual bool Equals(const Object& obj) const
	{
		bool out = true;

		const HashMapT<KeyType, ValueType>* other = dynamic_cast<const HashMapT<KeyType, ValueType>*>(&obj);
		if (null == other) // obj is not HashMapT<KeyType, ValueType>
		{
			out = false;
		}
		else if (other == this)
		{
			out = true;
		}
		else if (__count != other->__count)
		{
			out = false;
		}
		else
		{
			for (int i = 0; i < __capacity; i++)
			{
				for (__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i]; null != pEntry; pEntry = pEntry->pNext)
				{
					ValueType otherValue;
					result r = other->GetValue(pEntry->key, otherValue);
					if (IsFailed(r))
					{
						// Do not log the exception, because it is normal or trivial in most cases.
						out = false;
						break;
					}
					if (pEntry->value != otherValue)
					{
						out = false;
						break;
					}
				}
				if (!out)
					break;
			}
		}

		return out;
	}



private:
// Lifecycle
	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	map The instance of the HashMapT class to copy from
	 * @remarks		This constructor is hidden.
	 */
	HashMapT(const HashMapT<KeyType, ValueType>& map);


// Operator
	/**
	 * This is the assignment operator for this class.
	 *
	 * @param[in]	map The instance of the HashMapT class to assign from
	 * @remarks		This operator is hidden.
	 */
	HashMapT<KeyType, ValueType>& operator =(const HashMapT<KeyType, ValueType>& map);


// Operation
	/**
	 * Copies all the pairs from a specified map to this map
	 *
	 * @return		An error code
	 * @param[in]	map The map to be copied
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 */
	result AddAll(const IMapT<KeyType, ValueType>& map)
	{
		result r = E_SUCCESS;

		IMapT<KeyType, ValueType>* pMap = const_cast<IMapT<KeyType, ValueType>* > (&map);
		IMapEnumeratorT<KeyType, ValueType>* pMapEnum = pMap->GetMapEnumeratorN();

		TryCatch(pMapEnum != null, r = GetLastResult(), "[%s] Propagated.", GetErrorMessage(GetLastResult()));
		
		while (true)
		{
			KeyType key;
			ValueType value;

			int hash = 0;
			int i = 0;

			__HashMapEntryT<KeyType, ValueType>* temp = null;

			r = pMapEnum->MoveNext();
			// enumerator is reached to the end of collection
			if (E_OUT_OF_RANGE == r)
			{
				r = E_SUCCESS;
				break;
			}
			TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

			r = pMapEnum->GetKey(key);
			TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

			r = pMapEnum->GetValue(value);
			TryCatch(r == E_SUCCESS, , "[%s] Propagated.", GetErrorMessage(r));

			hash = Hash(key);
			i = hash & (__capacity - 1);
			temp = new __HashMapEntryT<KeyType, ValueType>(key, value, __pTable[i], hash);

			TryCatch(temp != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");
			__pTable[i] = temp;
			__count++;
		}

		if (null != pMapEnum)
			delete pMapEnum;
		return r;

	CATCH:
		if (null != pMapEnum)
			delete pMapEnum;
		return r;
	}


	/**
	 * Gets the hash value for a specified object.
	 *
	 * @return		The hash value for the specified object
	 * @param[in]	obj		The object to get hash value
	 */
	int Hash(const KeyType& obj) const
	{
		int h = __pProvider->GetHashCode(obj);

		h += ~(h << 9);
		if (h >= 0)
			h ^= (h >> 14);
		else
			h ^= ((h >> 14) + (2 << (~14 & 0x1f)));
		h +=  (h << 4);
		if (h >= 0)
			h ^= (h >> 10);
		else
			h ^= ((h >> 10) + (2 << (~10 & 0x1f)));

		return h;
	}


	/**
	 * Rehashes the content of a map to a new array with a greater capacity.
	 *
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity @n
	 *								It must be a power of two and greater than the current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @remarks	This method is called automatically when the number of keys in a map reaches its threshold.
	 */
	result Resize(int newCapacity)
	{
		result r = E_SUCCESS;
		__HashMapEntryT<KeyType, ValueType>** newTable = new __HashMapEntryT<KeyType, ValueType>*[newCapacity];
		TryCatch(newTable != null, r = E_OUT_OF_MEMORY, "[E_OUT_OF_MEMORY]");
		for (int i = 0; i < newCapacity; i++)
		{
			newTable[i] = null;
		}

		for (int i = 0; i < __capacity; i++)
		{
			__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__HashMapEntryT<KeyType, ValueType>* pNext = pEntry->pNext;
				int i = pEntry->hash & (newCapacity - 1);
				pEntry->pNext = newTable[i];
				newTable[i] = pEntry;
				pEntry = pNext;
			}
		}

		delete []__pTable;
		__pTable = newTable;
		__capacity = newCapacity;
		__threshold = static_cast<int>(__capacity * __loadFactor);
		
		return r;

	CATCH:
		return r;
	}


	/**
	 * Clears all key-value pairs in this map.
	 */
	void Reset(void)
	{
		for (int i = 0; i < __capacity; i++)
		{
			__HashMapEntryT<KeyType, ValueType>* pEntry = __pTable[i];
			while (null != pEntry)
			{
				__HashMapEntryT<KeyType, ValueType>* pNext = pEntry->pNext;
				delete pEntry;
				pEntry = pNext;
			}
			__pTable[i] = null;
		}
	}


// Attribute

	__HashMapEntryT<KeyType, ValueType>** __pTable;
	int __count;
	int __capacity;
	float __loadFactor;
	int __threshold;
	IHashCodeProviderT<KeyType>* __pProvider;
	IComparerT<KeyType>* __pComparer;
	bool __defaultConstruct;
	int __modCount;

	static const int DEFAULT_CAPACITY = 16;
	static const float DEFAULT_LOAD_FACTOR;


// Friend class

	friend class __HashMapEnumeratorT<KeyType, ValueType>;


}; // HashMapT



///////////////////////////////////////////////////////////
// Implementation


///////////////////////////////////////////////////////////
// class __HashMapEntryT

/** 
 * @internal
 * @class	__HashMapEntryT
 * @brief	This is an entry for the HashMapT class.
 * @since	1.0
 */
template<class KeyType, class ValueType>
class __HashMapEntryT
	: public Object
{
public:

// Lifecycle

	/**
	 * This is the constructor for this class.
	 *
	 * @since	 		1.0
	 * @param[in]	k		The key to be included in this entry
	 * @param[in]	v		The value to be included in this entry
	 * @param[in]	next	A pointer to the next entry
	 * @param[in]	h		A hash value of the key
	 */
	__HashMapEntryT(const KeyType& k, const ValueType& v, __HashMapEntryT<KeyType, ValueType>* next, int h)
	:	key(k),
		value(v),
		hash(h),
		pNext(next)
	{
	}


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~__HashMapEntryT(void) 
	{
	}


// Attribute
	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	KeyType key;

	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	ValueType value;

	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	int hash;

	/**
	 * @internal
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	__HashMapEntryT<KeyType, ValueType>* pNext;

};


///////////////////////////////////////////////////////////
// class __HashMapEnumeratorT

/**
 * @internal
 * @class	__HashMapEnumeratorT
 * @brief	This is an implementation of the IMapEnumeratorT interface for the HashMapT class.
 * @since	1.0
 */
template<class KeyType, class ValueType>
class __HashMapEnumeratorT :
	public IMapEnumeratorT<KeyType, ValueType>,
	public Object
{
public:

// Lifecycle

	/**
	 * This is the constructor for this class.
	 *
	 * @since	 		1.0
	 * @param[in]	map			The map to enumerate
	 * @param[in]	modCount	The modification count to detect the change in the map 
	 */
	__HashMapEnumeratorT(const HashMapT<KeyType, ValueType>& map, int modCount)
	:	__map(map), 
		__modCount(modCount), 
		__pEntry(null), 
		__index(-1)
	{
	
	}



	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~__HashMapEnumeratorT(void)
	{
	
	}


// Operation

	/**
	 * Reads the current object in the map. 
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[out]	obj The current object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or 
	 *									past the last element or the map is modified after this enumerator is created.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result GetCurrent(MapEntryT<KeyType, ValueType>& obj) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION, "[E_INVALID_OPERATION] The source collection is modified after the creation of this enumerator.");
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[E_INVALID_OPERATION] Invalid position(pEntry is null).");

		obj = MapEntryT<KeyType, ValueType>(__pEntry->key, __pEntry->value);
		return E_SUCCESS;
	}


	/**
	 * Advances this enumerator to the next elements of the map.
	 * When this enumerator is first created, or when the Reset() method is called, or when the MoveNext() method is first called, the enumerator positions itself to the first element in the map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the map is modified after this enumerator is created.
	 * @exception	E_OUT_OF_RANGE		The enumerator has passed the end of the map.
	 * @see			Reset()
	 */
	result MoveNext(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION, "[E_INVALID_OPERATION] The source collection is modified after the creation of this enumerator.");

		result r = E_SUCCESS;
		if ((null != __pEntry) && (null != __pEntry->pNext))
		{
			__pEntry = __pEntry->pNext;
		}
		else
		{
			while (1)
			{
				if (++__index >= static_cast<int>(__map.__capacity))
				{
					// Do not log the E_OUT_OF_RANGE, because it is normal or trivial in most cases.
					r = E_OUT_OF_RANGE;
					break;
				}
				__pEntry = __map.__pTable[__index];
				if (null != __pEntry)
				{
					break;
				}
			}
		}

		return r;
	}


	/**
	 * Positions the enumerator before the first element in a map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the map is modified after this enumerator is created.
	 */
	result Reset(void)
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION, "[E_INVALID_OPERATION] The source collection is modified after the creation of this enumerator.");

		__index = -1;
		__pEntry = null;
		return E_SUCCESS;
	}


	/**
	 * Reads the current key in a map. 
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[out]	key The current key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or
	 *									past the last element or the map is modified after this enumerator is created.
	 */
	result GetKey(KeyType& key) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION, "[E_INVALID_OPERATION] The source collection is modified after the creation of this enumerator.");
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[E_INVALID_OPERATION] Invalid position(pEntry is null).");

		key = __pEntry->key;
		return E_SUCCESS;
	}


	/**
	 * Reads the current value in a map
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[out]	value The current value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									This enumerator is currently positioned before the first element or 
	 *									past the last element or the map is modified after the enumerator is created.
	 */
	result GetValue(ValueType& value) const
	{
		TryReturn((__modCount == __map.__modCount), E_INVALID_OPERATION, "[E_INVALID_OPERATION] The source collection is modified after the creation of this enumerator.");
		TryReturn((__pEntry != null), E_INVALID_OPERATION, "[E_INVALID_OPERATION] Invalid position(pEntry is null).");

		value = __pEntry->value;
		return E_SUCCESS;
	}

private:

// Attribute

	const HashMapT<KeyType, ValueType>& __map;
	int __modCount;
	__HashMapEntryT<KeyType, ValueType>* __pEntry;
	int __index;

};



///////////////////////////////////////////////////////////
// class __HashMapDefaultProviderT

/**
* @internal
* @class	__HashMapDefaultProviderT
* @brief	This is an implementation of the IHashCodeProviderT interface for the HashMap class.
* @since	1.0
*/
template<class KeyType>
class __HashMapDefaultProviderT
	:	public IHashCodeProviderT<KeyType>,
	public Object
{
public:

	// Lifecycle

	/**
	* This is the default constructor for this class.
	*
	* @since	 1.0
	*/
	__HashMapDefaultProviderT(void) {}


	/**
	* This is the destructor for this class.
	*
	* @since	 1.0
	*/
	virtual ~__HashMapDefaultProviderT(void) {}


	// Operation

	/**
	* Gets the hash code of the specified object
	*
	* @since	 	1.0
	* @return		The hash code of the specified object
	* @see			Osp::Base::Object::GetHashCode
	*/
	int GetHashCode(const KeyType& obj) const
	{
		return (int)obj;
	}


};



///////////////////////////////////////////////////////////
// class HashMapT

template<class KeyType, class ValueType>
const float HashMapT<KeyType, ValueType>::DEFAULT_LOAD_FACTOR = 0.75;


}; }; }; // Osp::Base::Collection
#endif //_FBASE_COL_HASH_MAP_T_H_

