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
 * @file		FBaseColLinkedList.h 
 * @brief		This is the header file for the %LinkedList class.
 *
 * This header file contains the declarations of the %LinkedList class.
 */
#ifndef _FBASE_COL_LINKED_LIST_H_
#define _FBASE_COL_LINKED_LIST_H_

// Includes
#include "FBaseColIComparer.h"
#include "FBaseColIList.h"


namespace Osp { namespace Base { namespace Collection {

// Forward declaration
class __ListNode;

/**
 * @class LinkedList
 * @brief This class represents a collection of objects that can be individually accessed by index.
 * @since	 1.0
 * 
 * The %LinkedList class represents a collection of objects that can be individually accessed by index.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/arraylist_linkedlist.htm">ArrayList and LinkedList</a>.
 *
 * The following example demonstrates how to use the %LinkedList class.
 *
 * @code
 *	#include <FBase.h>
 *	                                                                                                 
 *	using namespace Osp::Base;                                                                     
 *	using namespace Osp::Base::Collection;                                                               
 *
 *	                                                                                                 
 *	void
 *	MyClass::LinkedListSample(void)
 *	{
 *		LinkedList	list;
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
class _EXPORT_BASE_ LinkedList :
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
	 * @since	 1.0
	 */
	LinkedList(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~LinkedList(void);


// Operation

	/**
	 * Adds the given object to the end of this list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj		An object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see Remove()
	 */	 
	virtual result Add(const Object& obj);


	/** 
	 * Adds the elements of the given collection to the end of this list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection A collection to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds just the pointer; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection);


	/**
	 * Returns an enumerator (an instance of the IEnumerator derived class) to the list.
	 *
	 * @since	 		1.0
	 * @return		An enumerator of the calling list object, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Osp::Base::Collection::IEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets the object at the specified index of the calling list.
	 *
	 * @since	 		1.0
	 * @return		A pointer to the object at the specified index of the list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index The index of the object to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const;


	/**
	 * Gets the object at the specified index of the calling list.
	 *
	 * @since	 		1.0
	 * @return		A pointer to the object at the specified index of the list, @n
	 *				else @c null if the index is not valid
	 * @param[in]	index The index of the object to read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index);


	/** 
	 * Gets an IList with the specified range from the calling list object.
	 *
	 * @since	 		1.0
	 * @return		An %IList pointer if successful, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @exception	E_SUCCESS				The method is successful.	 
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The %IList stores just the pointers to the elements in the list, not the elements themselves.
	 *      		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const;


	/** 
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
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
	 *										the specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0.
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
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
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
	 *										the specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		If the @c index equals to the number of elements, then the new element
	 *				is added at the end of this list.
	 *      		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			Add(), RemoveAt()
	 */	
	virtual result InsertAt(const Object& obj, int index);


	/** 
	 * Inserts the elements of the collection at the specified location.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to insert elements from
	 * @param[in]	startIndex	The starting index at which the elements should be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c startIndex is either greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		If the @c startIndex equals to the number of elements then the new elements
	 *				are added at the end of this list.
	 *      		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems(), AddItems()
	 */	
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex);

	
	/**
	 * Removes the first occurrence of the specified object from the list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj	An object to remove
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c obj is not found.
	 * @see			Add(), RemoveAt()
	 */
	virtual result Remove(const Object& obj, bool deallocate = false);


	/**
	 * Removes the object at the specified location in the list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	index The index at which the object should be removed
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									The specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see		InsertAt()
	 */	
	virtual result RemoveAt(int index, bool deallocate = false);


	/** 
	 * Removes all elements within the specified range from the list.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range 
	 * @param[in]	count		The number of element to remove
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The specified index is outside the bounds of the data structure. @n
	 *									- The specified @c startIndex is either equal to or greater than the number of elements or less than @c 0. @n
	 *									- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @see			AddItems(), InsertItemsFrom()
	 */	
	virtual result RemoveItems(int startIndex, int count, bool deallocate = false);


	/**
	 * Removes all the elements that are common in the specified @c collection
	 * and the list.
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
	virtual result RemoveItems(const ICollection& collection, bool deallocate = false);


	/**
	 * Removes all objects and their pointers in @c collection, when the @c deallocate parameter is set to @c true. @n
	 * This method can be called before deleting the objects in a collection.
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate			Set to @c true to deallocate all objects, @n
	 * 									else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);


	/** 
	 * Replaces the object at the specified index with the given object.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj 	An object to set
	 * @param[in]	index	The index at which the object should be set
	 * @param[in]	deallocate		Set to @c true to deallocate the object, @n
	 * 								else @c false
	 * @exception	E_SUCCESS			The method is successful.	 
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or
	 *									the specified @c index is equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Object& obj, int index, bool deallocate = false);


	/** 
	 * Sorts the elements of this list using the comparer provided.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	comparer The IComparer implementation to use when comparing elements
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								the @c comparer is not valid.
	 */	
	virtual result Sort(const IComparer& comparer);


// Access

	/**
	 * Gets the number of objects currently stored in this list.
	 *
	 * @since	 		1.0
	 * @return		The number of objects currently stored in this list
	 */
	virtual int GetCount(void) const;


// Inquery

	/** 
	 * Checks whether the list contains the specified object.
	 *
	 * @since	 		1.0
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj 	The object to locate
     * @see			ContainsAll()
	 */
	virtual bool Contains(const Object& obj) const;


	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to be checked for containment in this list
	 * @param[out]	out 		Set to @c true if this list contains all of the elements in the specified collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		If the given @c collection is empty, the @c out parameter is set to @c true.
	 * @see			Contains()
	 */
	virtual result ContainsAll(const ICollection& collection, bool& out) const;


	/** 
	 * Compares the given object with the calling %LinkedList object.
	 *
	 * @since	 		1.0
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the calling object
	 * @remarks		This method returns @c true only if the specified object is also an instance of the %LinkedList class,
	 *				both lists have the same size, and all corresponding pairs of elements in the two lists are equal.
	 *				In other words, two lists are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	list The LinkedList object to initialize the new object
	 * @remarks		This constructor is hidden.
	 */
	LinkedList(const LinkedList& list);


// Operator

	/**
	 * This is the assignment operator.
	 *
	 * @param[in]	list The LinkedList object to copy to the calling object
	 * @remarks		This operator is hidden.
	 */
	LinkedList& operator =(const LinkedList& list);


// Operation

	/**
	 * Allocates and adds a memory block.
	 *
	 * @return		An error code
	 * @param[in]	blockSize	The size of block to be allocated
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result AddBlock(int blockSize = DEFAULT_CAPACITY);


	/**
	 * Frees memory blocks of the list.
	 *
	 */
	void DeleteBlock(void);


	/**
	 * Inserts an object to the beginning of the LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	obj 	The object to insert
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertFirst(const Object& obj);


	/**
	 * Inserts an object to the end of the LinkedList.
	 *
	 * @return		An error code
	 * @param[in]	obj 	The object to insert
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertLast(const Object& obj);


	/**
	 * Inserts an object after the specified node.
	 *
	 * @return		An error code
	 * @param[in]	obj 	The object to insert
	 * @param[in]	pPrevNode The node after which the object should be inserted 
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result InsertNext(const Object& obj, __ListNode* pPrevNode);


	/**
	 * Gets a node from Available node list.
	 * 
	 * @return		A pointer to a new List Node if successful @n
	 *				@c null, if no node is available
	 */
	__ListNode* GetNewNode(void);


	/**
	 * Gets the node at the specified index.
	 *
	 * @return		A node at the specified index
	 * @param[in]	index The index of the node to read
	 */
	__ListNode* GetNode(int index) const;


	/**
	 * Removes the specified node.
	 *
	 * @param[in]	pNode The pointer of the node to remove
	 * @param[in]	deallocate	Set to @c true to deallocate the node, @n
	 *							else @c false
	 */
	void RemoveNode(__ListNode* pNode, bool deallocate = false);


	/**
	 * Sorts the specified sub-list within the LinkedList object.
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the sort
	 * @param[in]	endIndex	The ending index of the sort
	 * @param[in]	comparer	The comparer instance to be used
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the comparer has failed to compare the elements.
	 */
	result QuickSort(int startIndex, int endIndex, const IComparer* comparer);


// Attribute

	__ListNode* __pListHead;
	__ListNode* __pListTail;
	__ListNode* __pAvailableHead;
	__ListNode* __pAvailableTail;
	__ListNode* __pBlocks;
	int __count;
	int __capacity;
	int __modCount;


// Friend class
	friend class __LinkedListEnumerator;


private:
	friend class LinkedListEx;
	class LinkedListEx* __pLinkedListEx;

};

}; }; }; // Osp::Base::Collection
#endif// _FBASE_COL_LINKED_LIST_H_

