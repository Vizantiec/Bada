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
 * @file		FBaseColIList.h 
 * @brief		This is the header file for the %IList interface.
 *
 * This header file contains the declarations of the %IList interface.
 */
#ifndef _FBASE_COL_ILIST_H_
#define _FBASE_COL_ILIST_H_

// Includes
#include "FBaseColICollection.h"
#include "FBaseColIComparer.h"
#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @interface IList
 *
 * @brief	This interface represents a collection of objects that can be individually accessed by an index.
 * @since	1.0
 *
 * The %IList interface represents a collection of objects that can be individually accessed by an index.
 *
 */
class _EXPORT_BASE_ IList :
	public ICollection
{
public:

// Lifecycle

	/**
	 * This is the destructor for this interface.
	 *
	 * @since	1.0
	 */
	virtual ~IList(void);


// Operation

	/** 
	 * Adds the specified object to the list.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj		The object to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		In a collection of contiguous elements, such as a list, the elements 
	 *				that follow the insertion point move down to accommodate the new element. 
	 *				If the collection is indexed, the indexes of the elements that are moved 
	 *				are also updated. This behavior does not apply to collections where 
	 *				elements are conceptually grouped into buckets, such as a hashtable.
	 *      		This method performs a shallow copy. It adds the pointer only; not the element itself.
	 * @see Remove()
	 */
	virtual result Add(const Object& obj) = 0;


	/** 
	 * Adds the elements of the specified collection to the end of the list.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	collection The collection to add to the list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It adds the pointer only; not the element itself.
	 * @see			RemoveItems()
	 */
	virtual result AddItems(const ICollection& collection) = 0;


	/** 
	 * Searches for an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj			The object to locate
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 */
	virtual result IndexOf(const Object& obj, int& index) const = 0;
	

	/** 
	 * Inserts an object at the specified location in the list.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj		The object to insert
	 * @param[in]	index	The index at which the object should be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c index is greater than the number of elements in the list or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		If the @c index equals the number of elements in the list, the new element
	 *				is added at the end of the list.
	 *      		This method performs a shallow copy. It inserts the pointer only; not the element itself.
	 * @see			Add(), RemoveAt()
	 */	
	virtual result InsertAt(const Object& obj, int index) = 0;


	/** 
	 * Searches for an object starting from the specified index. @n
	 * Gets the index of the object if found.
	 *
	 * @since			1.0
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
	virtual result IndexOf(const Object& obj, int startIndex, int& index) const = 0;

	
	/** 
	 * Searches for an object within the specified range. @n
	 * Gets the index of the object if found.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to read
	 * @param[out]	index		The index of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c obj is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(const Object& obj, int startIndex, int count, int& index) const = 0;


	/** 
	 * Searches for the last occurrence of an object in this list. @n
	 * Gets the index of the object if found.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj 		The object to locate
	 * @param[out]	index		The index of the last occurrence of the specified object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(const Object& obj, int& index) const = 0;


	/** 
	 * Inserts the elements of a collection in the list at the specified location.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to insert
	 * @param[in]	startIndex	The starting index at which the collection should be inserted
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the @c startIndex is greater than the number of elements in the list or less than @c 0.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the specified @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		If the @c startIndex equals the number of elements in the list, the new elements
	 *				are added at the end of the list.
	 *      		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see			RemoveItems(), AddItems()
	 */	
	virtual result InsertItemsFrom(const ICollection& collection, int startIndex) = 0;


	/** 
	 * Gets the object at the specified location.
	 *
	 * @since			1.0
	 * @return		The object at the specified location, @n
	 *				else @c null if the @c index is not valid
	 * @param[in]	index	The index of the object to get
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than zero.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetAt()
	 */
	virtual const Object* GetAt(int index) const = 0;


	/** 
	 * Gets the object at the specified location.
	 *
	 * @since			1.0
	 * @return		The object at the specified location, @n
	 *				else @c null if the @c index is not valid
	 * @param[in]	index	The index of the object to get
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.	 
	 * @see			SetAt()
	 */
	virtual Object* GetAt(int index) = 0;


	/** 
	 * Gets all the elements of the list within the specified range.
	 *
	 * @since			1.0
	 * @return		A pointer to an IList with elements lying within the specified range, @n
	 *				else @c null if an exception occurs
	 * @param[in]	startIndex	The starting index of the range 
	 * @param[in]	count		The number of elements to be read
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than zero. @n
	 *										- The @c count is greater than the number of elements in the list starting from @c startIndex
	 *										or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The IList stores just the pointers to the elements in the list, not the elements themselves.
	 *          	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual IList* GetItemsN(int startIndex, int count) const = 0;


	/** 
	 * Removes the first occurrence of the specified object.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj			The object to remove
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c obj is not found.
	 * @see			Add(), RemoveAt()
	 */	
	virtual result Remove(const Object& obj, bool deallocate = false) = 0;


	/** 
	 * Removes the object at the specified location.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	index The index at which the object should be removed
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 */	
	virtual result RemoveAt(int index, bool deallocate = false) = 0;


	/** 
	 * Removes all the elements within the specified range.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements in the range
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds of the data structure. @n
	 *										- The specified @c startIndex is either equal to or greater than the number of elements in the list or less than @c 0. @n
	 *										- The @c count is greater than the number of elements starting from @c startIndex
	 *										or less than @c 0.
	 * @see			AddItems()
	 */	
	virtual result RemoveItems(int startIndex, int count, bool deallocate = false) = 0;


	/**
	 * Removes all the elements from the list that are common to the specified collection.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	collection 			The collection to be removed from this list
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			Remove(), RemoveAt()
	 */	
	virtual result RemoveItems(const ICollection &collection, bool deallocate = false) = 0;


	/**
	 * Removes all the object pointers in the collection. @n
	 * If the deallocate param is set to @c true, it removes all the objects in the collection. @n 
	 * This method can be called just before deleting the collection.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	deallocate			Set to @c true to deallocate all the objects, @n
	 * 									else @c false
	 */
	virtual void RemoveAll(bool deallocate = false) = 0;


	/** 
	 * Replaces the object at the specified index with the specified object.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	obj 	The new object
	 * @param[in]	index	The index at which the new object should be set
	 * @param[in]	deallocate			Set to @c true to deallocate the object, @n
	 * 									else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or
	 *										the specified @c index is either equal to or greater than the number of elements in the list or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(const Object& obj, int index, bool deallocate = false) = 0;


	/**
	 * @internal
	 * This method should not be used. A link error occurs when this method is used.
	 *
	 * @since	1.0
	 */
	result Sort(const IComparer& comparer);


// Inquiry

public:
	/** 
	 * Checks whether the list contains the specified object.
	 *
	 * @since			1.0
	 * @return		@c true if the list contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj 	The object to locate
	 */
	virtual bool Contains(const Object& obj) const = 0;


	/**
	 * Checks whether the list contains all the elements of the specified collection.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to be checked for containment in this list
	 * @param[out]	out			Set to @c true if the list contains all the elements of the specified collection, @n
	 *							else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the specified @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		If the given @c collection is empty, the @c out parameter is set to @c true.
	 * @see			Contains()
	 */
	virtual result ContainsAll(const ICollection& collection, bool& out) const = 0;

};

}; }; }; // Osp::BASE::Collection
#endif// _FBASE_COL_ILIST_H_

