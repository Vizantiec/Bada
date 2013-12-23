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
 * @file		FBaseColArrayList.h 
 * @brief		This is the header file for the %ArrayList class.
 *
 * This header file contains the declarations of the %ArrayList class.
 */
#ifndef _FBASE_COL_ARRAY_LIST_H_
#define _FBASE_COL_ARRAY_LIST_H_

// Includes
#include "FBaseObject.h"
#include "FBaseColIComparer.h"
#include "FBaseColIList.h"

namespace Osp { namespace Base { namespace Collection {

/**
 * @class ArrayList
 * @brief This class represents a collection of objects that can be individually accessed by an index.
 * @since	 1.0
 *
 * 
 * The %ArrayList class represents a collection of objects that can be individually accessed by an index. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %ArrayList class.
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
 *	MyClass::ArrayListSample(void)
 *	{
 *		ArrayList	list;
 *	
 *		list.Construct();
 *	
 *		list.Add(*(new Integer(1)));	// 1
 *		list.Add(*(new Integer(2)));	// 1,2
 *		list.Add(*(new Integer(3)));	// 1,2,3
 *	
 *	
 *		Integer*	pInt = static_cast<Integer*> (list.GetAt(0));
 *		Integer*	pValue = new Integer(1);
 *		if (pValue->Equals(*pInt))		// true
 *		{
 *			// Should be here
 *		}
 * 	
 *		delete pValue; 
 *
 *	
 *		list.InsertAt(*(new Integer(4)), 1);	// 1,4,2,3
 *	
 *	
 *		pValue = new Integer(3);
 *		list.Remove(*pValue, true);		// 1,4,2
 *	
 *		delete pValue;
 *	
 *	
 *		list.RemoveAt(0, true);			// 4,2
 *	
 *
 *		IntegerComparer* pIntegerComparer = new IntegerComparer();
 *		list.Sort(*pIntegerComparer);	// 2,4
 *
 *		delete pIntegerComparer;
 *	
 *
 *		// Use enumerator to access elements in the list
 *		IEnumerator*	pEnum = list.GetEnumeratorN();
 *		Object*			pObj = null;
 *		while (pEnum->MoveNext() == E_SUCCESS)
 *		{
 *			pObj = pEnum->GetCurrent();
 *		}
 *	
 *		delete pEnum;
 *
 *
 *		// Deallocate all objects
 *		list.RemoveAll(true);
 *	
 *	}
 * @endcode
 */
class _EXPORT_BASE_ ArrayList :
	public IList,
	public Object
{
private:
	static const int DEFAULT_CAPACITY = 10;

public:

// Lifecycle

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of the %ArrayList class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	ArrayList(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~ArrayList(void);


	/** 
	 * Initializes this instance of %ArrayList with the specified parameter and sets its initial capacity to the 
	 * indicated value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity	The number of elements @n
	 *  						The default capacity is @c 10.
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception	E_INVALID_ARG	  A specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @exception	E_OUT_OF_MEMORY	  The memory is insufficient.
	 * @remarks		If the number of elements added to the list reaches the current capacity, 
	 *				the capacity is automatically increased by memory reallocation.
	 *				Therefore, if the size of the list can be estimated, 
	 *				specifying the initial capacity eliminates the need to perform a number of 
	 *				resizing operations while adding elements to the list.
	 * @see			ArrayList()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY);


	/** 
	 * Initializes this instance of %ArrayList by copying the elements of the specified 
	 * collection. The capacity of the list is the same as the number of elements copied.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			ArrayList()
	 */
	result Construct(const ICollection& collection);


// Operation

	/**
	 * Adds the specified object to the end of this list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj		An object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			Remove()
	 */	 
	virtual result Add(const Object& obj);


	/** 
	 * Adds the elements of the specified collection to the end of this list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection);


	/**
	 * Gets an enumerator (an instance of the IEnumerator-derived class) of this list.
	 *
	 * @since	 		1.0
	 * @return		An instance of the IEnumerator-derived class, @n
	 * 				else @c null if some exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets the object at the specified index of this list.
	 *
	 * @since	 		1.0
	 * @return		The object at the specified index of this list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index	The index of the object in the calling list to be read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const;


	/**
	 * Gets the object at the specified index of this list.
	 *
	 * @since	 		1.0
	 * @return		The object at the specified index of this list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index	The index of the object to be read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index);


	/** 
	 * Gets the IList within the specified range of this list.
	 *
	 * @since	 		1.0
	 * @return		A pointer to %IList, @n
	 *				else @c null if some exception occurs
	 * @param[in]	startIndex	The starting index of the range 
	 * @param[in]	count		The number of elements to be read
	 * @exception	E_SUCCESS				The method is successful.	
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than zero. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The %IList stores just the pointers to the elements in the list, not the elements themselves.
	 *             	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const;


	/** 
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int& index) const;

	
	/** 
	 * Searches for an object starting from the specified index. @n
	 * Gets the index of the object if found.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[in]	startIndex	The starting index for the search @n
	 *							It must be less than the number of elements.
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either equal to or greater than the number of elements or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int startIndex, int& index) const;

	
	/** 
	 * Searches for an object within the specified range. @n
	 * Gets the index of the object if found.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to be read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int startIndex, int count, int& index) const;


	/** 
	 * Searches for the last occurrence of an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[out]	index		The index of the last occurrence of the specified object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(const Object& obj, int& index) const;


	/** 
	 * Inserts the object at the specified location.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 	An object to insert
	 * @param[in]	index	The index at which the object should be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new element. 
	 *				If the @c index equals to the number of elements, then the new element
	 *				is added at the end of this list.
	 *				This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			Add(), RemoveAt()
	 */	
	virtual result InsertAt(const Object& obj, int index);


	/** 
	 * Inserts the elements of the collection at the specified location.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The starting index at which the collection should be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c startIndex is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The elements that follow the insertion point move down to accommodate the new element. 
	 *				If the @c startIndex equals to the number of elements then the new elements
	 *				are added at the end of this list.
	 *          	This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems(), AddItems()
	 */	
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex);


	/**
	 * Removes the first occurrence of the specified object.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 	An object to remove
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add(), RemoveAt(), RemoveAll()
	 */
	virtual result Remove(const Object& obj, bool deallocate = false);


	/**
	 * Removes the object at the specified location.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	index	The index at which the object should be removed
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than zero.
	 * @remarks		The elements that follow the deletion point move up to occupy the vacated spot.
	 * @see			InsertAt(), Remove()
	 */	
	virtual result RemoveAt(int index, bool deallocate = false);


	/** 
	 * Removes all the elements within the specified range.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to be read
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than zero. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @remarks		The elements that follow the deletion point move up to occupy the vacated spot.
	 * @see			AddItems()
	 */	
	virtual result RemoveItems(int startIndex, int count, bool deallocate = false);


	/**
	 * Removes all of the elements that are in the intersection of the specified @c collection
	 * and this list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection The collection to be removed from this list
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			Remove(), RemoveAt()
	 */	
	virtual result RemoveItems(const ICollection &collection, bool deallocate = false);


	/**
	 * Removes all of the object pointers in the collection and also removes all of the objects
	 * when the deallocate parameter is set to true. @n
	 * This method can be called before the collection is deleted.
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate		Set to @c true to deallocate all objects, @n
	 * 								else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);



	/** 
	 * Replaces the object at the specified index with the specified object.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 	An object to set
	 * @param[in]	index	The index at which the object should be set
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Object& obj, int index, bool deallocate = false);


	/** 
	 * Sets the capacity of this list to the specified value.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	newCapacity	The new capacity of this list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified input parameter is invalid, or
	 *								  the @c newCapacity is negative.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		When the new capacity is less than the current capacity, the elements
	 *				within the truncated memory are not destroyed.
	 * @see			Construct(), Trim(), GetCapacity()
	 */	
	virtual result SetCapacity(int newCapacity);


	/** 
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	comparer	The IComparer implementation to use when comparing elements
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_ARG_INVALID	The specified input parameter is invalid.
	 */	
	virtual result Sort(const IComparer& comparer);


	/** 
	 * Sets the capacity to the actual number of elements in this list.
	 *
	 * @since	 1.0
	 */
	virtual void Trim(void);


// Access

	/** 
	 * Gets the current capacity of this list.
	 *
	 * @since	 	1.0
	 * @return	The current capacity of this list
	 * @see			SetCapacity()
	 */	
	virtual int GetCapacity(void) const;


	/**
	 * Gets the number of objects currently stored in this list.
	 *
	 * @since	 		1.0
	 * @return		The number of objects currently stored in this list
	 */
	virtual int GetCount(void) const;


// Inquery

	/** 
	 * Checks whether a list contains the specified object.
	 *
	 * @since	 1.0
	 * @return		@c true if the object is present in the list, @n
	 *				else @c false
	 * @param[in]	obj The object to be located
	 * @see			ContainsAll()
	 */
	virtual bool Contains(const Object& obj) const;


	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to be checked for in the list
	 * @param[out]	out			Set to @c true if the list contains all the elements of the specified collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		If the specified @c collection is empty, the @c out parameter will be set to @c true.
	 * @see			Contains()
	 */
	virtual result ContainsAll(const ICollection& collection, bool& out) const;


	/** 
	 * Compares the specified Object instance with the calling %ArrayList instance.
	 *
	 * @since	 		1.0
	 * @return		@c true if the given object matches the calling List, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the calling list
	 * @remarks		This method returns @c true only if the specified object @c obj is also an instance of %ArrayList class,
	 *				both lists have the same size, and all the corresponding pairs of the elements in the two lists are equal.
	 *				In other words, the two lists are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	list	The instance of the ArrayList class to copy from
	 * @remarks		This constructor is hidden.
	 */
	ArrayList(const ArrayList& list);


// Operator	

	/**
	 * This is the assignment operator.
	 *
	 * @param[in]	list	The instance of the ArrayList class to assign from
	 * @remarks		This operator is hidden.
	 */
	ArrayList& operator =(const ArrayList& list);


// Operation

	/**
	 * Sorts the specified sub-list.
	 *
	 * @return		An error code
	 * @param[in]	startIndex The starting point of the sub-list to be sorted
	 * @param[in]	endIndex The end point of the sub-list to be sorted 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the comparer has failed to compare the elements.
	 */
	result QuickSort(int startIndex, int endIndex);


// Attribute

	int __capacity;
	int __count;
	Object** __pObjArray;
	int __modCount;
	IComparer* __pComparer;

// Friend class
	friend class __ArrayListEnumerator;


private:
	friend class ArrayListEx;
	class ArrayListEx* __pArrayListEx;

}; // ArrayList

}; }; }; // Osp::Base::Collection
#endif// _FBASE_COL_ARRAY_LIST_H_

