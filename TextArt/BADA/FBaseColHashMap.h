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
 * @file		FBaseColHashMap.h 
 * @brief		This is the header file for the %HashMap class.
 *
 * This header file contains the declarations of the %HashMap class.
 */
#ifndef _FBASE_COL_HASH_MAP_H_
#define _FBASE_COL_HASH_MAP_H_

// includes
#include "FBaseColIComparer.h"
#include "FBaseColIHashCodeProvider.h"
#include "FBaseColIMap.h"
#include "FBaseConfig.h"


namespace Osp { namespace Base { namespace Collection {

// Forward declaration
class __HashMapEntry;

/**
 * @class HashMap
 *
 * @brief This class represents a collection of associated keys and values that are organized based on the hash code of the key.
 * @since	 1.0
 *
 * The %HashMap class contains unique keys and each key maps to one single value.
 * The key and value cannot be a @c null reference.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/hashmap_multihashmap.htm">HashMap and MultiHashMap</a>.
 *
 * The following example demonstrates how to create and initialize a %HashMap instance and how to use its methods.
 *
 * @code
 *
 *	#include <FBase.h>
 *	                                                                                                 
 *	using namespace Osp::Base;                                                                     
 *	using namespace Osp::Base::Collection;                                                               
 *
 *	             
 *	void                                                                                                   
 *	MyClass::HashMapSample(void)                                                                       
 *	{                                                                                                        
 *
 *		HashMap map;
 *
 *		// Construct a HashMap instance with default capacity, load factor, hash code provider, and comparer.
 *		map.Construct();
 *
 *
 *		String*		pStr0 = new String(L"Zero");                                                                     
 *		String*		pStr1 = new String(L"One");                                                                     
 *		String*		pStr2 = new String(L"Two");                                                                     
 *	                                                                                                         
 *		map.Add(*pStr0, *(new Integer(0)));	// map.GetCount() : 1, map : (Zero -> 0)                          
 *		map.Add(*pStr1, *(new Integer(1)));	// map.GetCount() : 2, map : (Zero -> 0), (one -> 1)              
 *		map.Add(*pStr2, *(new Integer(2)));	// map.GetCount() : 3, map : (Zero -> 0), (one -> 1), (Two -> 2)  
 *		                                                                                                      
 *	                                                                                                         
 *		// Get a value with the specified key (GetValue)     
 *		String*		pKey = new String(L"Zero");
 *		Integer*	pValue = static_cast<Integer*> (map.GetValue(*pKey));	// pValue : 0                                                           
 *
 *
 *		// Remove a value with the specified key (Remove)     
 *		map.Remove(*pKey, true);
 *
 *		delete pKey;
 *
 *	                                                                                                         
 *		// Use enumerator to access elements in the list                                                      
 *		IMapEnumerator*		pMapEnum = map.GetMapEnumeratorN();                                                                          
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
class _EXPORT_BASE_ HashMap :
	public IMap,
	public Object
{
public:

// Lifecycle

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	 		1.0
	 * @remarks		After creating an instance of the %HashMap class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	HashMap(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~HashMap(void);


	/**
	 * Initializes an instance of an empty %HashMap class with the initial capacity and load factor.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, @n
	 *								the @c capacity or the @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The GetHashCode() method of key objects is used for hashing and
	 *				the Equals() method of key objects is used for comparing keys.
	 * @see			HashMap()
	 */
	result Construct(int capacity = 16, float loadFactor = 0.75);


	/**
	 * Initializes an instance of a %HashMap class by copying the elements of the specified map.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map				The map to copy
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @remarks		This method performs a shallow copy. It copies only the pointer; not the element itself.
	 * @see			HashMap()
	 */
	result Construct(const IMap& map, float loadFactor = 0.75);


	/**
	 * Initializes an instance of an empty %HashMap class with the specified initial capacity, load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity		The initial capacity @n
	 *								If it is @c 0, the default capacity(16) is used.
	 * @param[in]	loadFactor		The maximum ratio of elements to buckets @n
	 *								If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider		An instance of the IHashCodeProvider derived class that supplies the hash codes for all the keys in this map 
	 * @param[in]	comparer		An instance of the IComparer derived class to use when comparing the keys
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or
	 *								  the @c capacity or the @c loadFactor is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMap()
	 */
	result Construct(int capacity, float loadFactor, const IHashCodeProvider& provider, 
		const IComparer& comparer);


	/**
	 * Initializes an instance of a %HashMap class by copying the elements of a specified map with a specified load factor, hash code provider, and comparer.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	map			The map to copy
	 * @param[in]	loadFactor	The maximum ratio of elements to buckets @n
	 *							If it is @c 0, the default load factor(0.75) is used.
	 * @param[in]	provider	An instance of the IHashCodeProvider derived class that supplies the hash codes for all keys in this map
	 * @param[in]	comparer	An instance of the IComparer derived class to use when comparing keys
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the @c loadFactor is negative.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c map is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It copies only the pointer ; not the element itself.
	 * @remarks		The instances of hash code provider and comparer will not be deallocated later from this map.
	 * @see			HashMap()
	 */
	result Construct(const IMap& map, float loadFactor, const IHashCodeProvider& provider, 
		const IComparer& comparer);


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
	 * @remarks		This method performs a shallow copy. It adds only the pointer; not the element itself.
	 * @see			Remove()
	 */
	virtual result Add(const Object& key, const Object& value);


	/**
	 * Gets an enumerator (an instance of the IMapEnumerator derived class) of this map.
	 *
	 * @since	 		1.0
	 * @return		An instance of the IMapEnumerator derived class, if successful @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator, Osp::Base::Collection::IMapEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets the elements of the map in an instance of the IMapEnumerator derived class.
	 *
	 * @since	 		1.0
	 * @return		An instance of the %IMapEnumerator derived class, if successful @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator, Osp::Base::Collection::IMapEnumerator
	 */
	virtual IMapEnumerator* GetMapEnumeratorN(void) const;




	/** 
	 * Gets the value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key		The key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual const Object* GetValue(const Object& key) const;


	/** 
	 * Gets the value associated with the specified key.
	 *
	 * @since	 		1.0
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	key		The key to locate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetValue()
	 */
	virtual Object* GetValue(const Object& key);


	/** 
	 * Gets a list of all the keys in a map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to an IList object containing all the keys in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The order of the keys is the same as the corresponding values in the IList interface returned by the GetValuesN() method.
	 *              The IList stores just the pointers to the elements in the map, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetValuesN()
	 */
	virtual IList* GetKeysN(void) const;


	/** 
	 * Gets all the values in the map.
	 *
	 * @since	 		1.0
	 * @return		A pointer to an IList object containing all the values in the map, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The IList stores just the pointers to the elements in the map, not the elements themselves.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetKeysN()
	 */
	virtual IList* GetValuesN(void) const;


	/** 
	 * Removes the values associated with a specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key The key to be removed
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @see			Add()
	 */
	virtual result Remove(const Object& key, bool deallocate = false);


	/**
	 * Removes all the object pointers in the collection. @n
	 * If the deallocate param is @c true, it also removes all of the objects. This method can be called before deleting a collection.
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate		Set to @c true to deallocate all the objects, @n
	 * 								else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);


	/** 
	 * Replaces the value associated with a specified key by allocating it a new value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key whose value is to be replaced 
	 * @param[in]	value	The new value to replace
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare keys.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found in the map.
	 * @remarks		To add a new key-value pair, use the Add() method.
	 * @see			Add(), GetValue()
	 */
	virtual result SetValue(const Object& key, const Object& value, bool deallocate = false);
	

// Access

	/**
	 * Gets the number of pairs currently stored in the map.
	 *
	 * @since	 		1.0
	 * @return		The pairs stored in the map
	 */
	virtual int GetCount(void) const;


// Inquery

	/** 
	 * Checks whether the map contains the specified key.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	key		The key to locate
	 * @param[out]	out			Set to @c true if the map contains the specified key, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the comparer has failed to compare the keys.
	 * @see			ContainsValue()
	 */
	virtual result ContainsKey(const Object& key, bool& out) const;


	/** 
	 * Checks whether the map contains the specified value.
	 *
	 * @since	 		1.0
	 * @return		@c true if the map contains the specified value, @n
	 *				else @c false
	 * @param[in]	value	The value to locate
	 *
	 * @see			ContainsKey()
	 */
	virtual bool ContainsValue(const Object& value) const;


	/** 
	 * Compares two instances of the HashMap class.
	 *
	 * @since	 		1.0
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same number of elements and all the elements contained in each other.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	map		The instance of the HashMap class to copy from
	 * @remarks		This constructor is hidden.
	 */
	HashMap(const HashMap& map);


// Operator

	/**
	 * This is the assignment operator for this class.
	 *
	 * @param[in]	map		The instance of the HashMap class to assign from
	 * @remarks		This operator is hidden.
	 */
	HashMap& operator =(const HashMap& map);


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
	result AddAll(const IMap& map);


	/**
	 * Gets the hash value for a specified object.
	 *
	 * @return		The hash value for the specified object
	 * @param[in]	obj
	 */
	int Hash(const Object& obj) const;


	/**
	 * Rehashes the content of a map to a new array with a greater capacity. 
	 *
	 * @return		An error code
	 * @param[in[	newCapacity	The new capacity @n
	 *							It must be a power of two and must be greater than the current capacity.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @remarks	This method is called automatically when the number of keys in a map reaches its threshold. 
	 */
	result Resize(int newCapacity);


	/**
	 *  Clears all key-value pairs in a map.
	 */
	void Reset(bool deallocate = false);


// Attribute

	__HashMapEntry** __pTable;
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
	friend class __HashMapEnumerator;


private:
	friend class HashMapEx;
	class HashMapEx* __pHashMapEx;

}; // HashMap

}; }; }; // Osp::Base::Collection
#endif //_FBASE_COL_HASH_MAP_H_

