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
 * @file		FBaseColQueue.h 
 * @brief		This is the header file for the %Queue class.
 *
 * This header file contains the declarations of the %Queue class.
 *
 */
#ifndef _FBASE_COL_QUEUE_H_
#define _FBASE_COL_QUEUE_H_

// includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseColICollection.h"


namespace Osp { namespace Base { namespace Collection {
/**
 * @class	Queue
 * @brief	This class represents a first-in-first-out collection of objects, that is, a queue.
 * @since	 1.0
 *
 * The %Queue class represents a first-in-first-out collection of objects, that is, a queue.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/queue_stack.htm">Stack and Queue</a>.
 *
 * The following example demonstrates how to use the %Queue class.
 *
 * @code
 *	#include <FBase.h>
 *	                                                                                                 
 *	using namespace Osp::Base;                                                                     
 *	using namespace Osp::Base::Collection;                                                               
 *	                                                                                                 
 *	void
 *	MyClass::QueueSample(void)
 *	{
 *		Queue queue;
 *		queue.Construct(3);			// capacity = 3
 *	
 *	
 *		String* pStr1 = new String(L"First");
 *		String* pStr2 = new String(L"Second");
 *		String* pStr3 = new String(L"Third");
 *
 *		queue.Enqueue(*pStr1);
 *		queue.Enqueue(*pStr2);
 *		queue.Enqueue(*pStr3);
 *	
 *	
 *		// Read the element at the beginning (Peek)
 *		const Object* pObj = null;
 *		pObj = queue.Peek();		// pObj: "First", queue.GetCount(): 3
 *	
 *	
 *		// Read and remove the element at the beginning (Dequeue)
 *		String* pStr = null;
 *		pStr = static_cast<String*> (queue.Dequeue()); // pStr: "First", queue.GetCount: 2
 *	
 *		delete pStr;	 // Because the queue does not have the Ownership of this pStr after dequeueing
 *
 *
 *		// Deallocate all objects
 *		queue.RemoveAll(true);
 *
 *	}
 * @endcode
 */
class _EXPORT_BASE_ Queue :
	public ICollection,
	public Object
{
private:
	static const int DEFAULT_CAPACITY = 10;

public:

// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	 		1.0
	 * @remarks		After creating an instance of the %Queue class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see Construct()
	 */
	Queue(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~Queue(void);


	/**
	 * Initializes an instance of %Queue with the specified capacity.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity			The number of elements in the queue @n
	 *									The default capacity is @c 10.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @remarks		If the number of elements added to the queue reaches the current capacity, 
	 *				the capacity is automatically increased by memory reallocation.
	 *				Therefore, if the size of the queue can be estimated, 
	 *				specifying the initial capacity eliminates the need to perform a number of 
	 *				resizing operations while adding elements to the queue.
	 * @see			Queue()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY);


	/**
	 * Initializes an instance of %Queue with the elements of the given collection. @n
	 * The capacity of the queue is the same as the number of elements copied.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection The collection to copy elements from
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			Queue()
	 */
	result Construct(const ICollection& collection);


// Operation

	/**
	 * Removes the element at the beginning of this queue and returns it.
	 *
	 * @since	 		1.0
	 * @return		The element at the beginning of this queue, if successful @n
	 *				else @c null if this queue is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this queue is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				Enqueue()
	 */
	virtual Object* Dequeue(void);


	/**
	 * Inserts an object at the end of this queue.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj	 The object to add to this queue
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see				Dequeue()
	 */
	virtual result Enqueue(const Object& obj);


	/**
	 * Gets an enumerator of this queue.
	 *
	 * @since	 		1.0
	 * @return		An enumerator (an instance of the IEnumerator derived class) of this queue, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				IEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets the element at the front of this queue without removing it.
	 *
	 * @since	 		1.0
	 * @return		The element at the beginning of this queue, @n
	 *				else @c null if this queue is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this queue is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual const Object* Peek(void) const;


	/**
	 * Removes all objects and their pointers in @c collection, when the @c deallocate parameter is set to @c true.
	 * 
     *  
	 * @since	 		1.0
	 * @param[in]	deallocate		Set to @c true to deallocate all objects, @n
	 * 								else @c false
	 * @remarks		 This method can be called before deleting the @c collection.
	 */
	virtual void RemoveAll(bool deallocate = false);


// Access 

	/**
	 * Gets the number of objects currently stored in this queue.
	 *
	 * @since	 		1.0
	 * @return		The number of objects currently stored in this queue
	 */
	virtual int GetCount(void) const;


// Inquery

	/**
	 * Checks whether this queue contains the specified object.
	 *
	 * @since	 		1.0
	 * @return		@c true if this queue contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj  The object to locate
	 */
	virtual bool Contains(const Object& obj) const;
	

	/**
	 * Checks whether this queue contains all the elements in the specified collection.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to locate
	 * @param[out]	out  Set to @c true if this queue contains all the elements in the specified collection, @n
	 *					 else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result ContainsAll(const ICollection& collection, bool& out ) const;


	/** 
	 * Compares the specified instance to the current instance for equality. 
	 *
	 * @since	 		1.0
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the specified object is also an instance of %Queue class,
	 *				both queues have the same size, and all corresponding pairs of elements in the two queues are equal.
	 *				In other words, two queues are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle
	
	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	queue The specified instance of Queue to initialize the current instance
	 * @remarks		This constructor is hidden.
	 */
	Queue(const Queue& queue);


// Operator
	
	/*
	 * This is the assignment operator.
	 *
	 * @param[in]	queue The specified instance of Queue to copy to the current instance
	 * @remarks		This operator is hidden.
	 */
	Queue& operator =(const Queue& queue);


// Attribute

	int __capacity;
	int __head;	
	int __tail;
	Object** __pObjArray;
	int __modCount;

// Friend class
	friend class __QueueEnumerator;


private:
	friend class QueueEx;
	class QueueEx* __pQueueEx;

}; // Queue

}; }; }; // Osp::Collection
#endif // _FBASE_COL_QUEUE_H_

