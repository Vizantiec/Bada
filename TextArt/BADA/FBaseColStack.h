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
 * @file		FBaseColStack.h 
 * @brief		This is the header file for the %Stack class.
 *
 * This header file contains the declarations of the %Stack class.
 *
 */
#ifndef _FBASE_COL_STACK_H_
#define _FBASE_COL_STACK_H_

#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseColICollection.h"


namespace Osp { namespace Base { namespace Collection {

/**
 * @class	Stack
 * @brief	This class represents a simple last-in-first-out collection of objects, that is, a stack.
 * @since	 1.0
 *
 * The %Stack class represents a simple last-in-first-out collection of objects, that is, a stack.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/queue_stack.htm">Stack and Queue</a>.
 *
 * The following example demonstrates how to use the %Stack class.
 *
 * @code
 *	#include <FBase.h>
 *	                                                                                                 
 *	using namespace Osp::Base;                                                                     
 *	using namespace Osp::Base::Collection;                                                               
 *	                                                                                                 
 *	void
 *	MyClass::StackSample(void)
 *	{
 *		Stack stack;
 *		stack.Construct(3);			// capacity = 3
 *	
 *	
 *		String* pStr1 = new String(L"First");
 *		String* pStr2 = new String(L"Second");
 *		String* pStr3 = new String(L"Third");
 *
 *		stack.Push(*pStr1);
 *		stack.Push(*pStr2);
 *		stack.Push(*pStr3);
 *	
 *	
 *		// Read the element at the top (Peek)
 *		const Object* pObj = null;
 *		pObj = stack.Peek();		// pObj: "Third", stack.GetCount(): 3
 *	
 *	
 *		// Read and remove the element at the top (Pop)
 *		String* pStr = null;
 *		pStr = static_cast<String*> (stack.Pop()); // pStr: "Third", stack.GetCount(): 2
 *	
 *	    delete pStr;	// Because the stack does not have the ownership of this pStr after popping
 *
 *
 *		// Deallocate all objects
 *		stack.RemoveAll(true);
 *
 *	}
 * @endcode
 */
class _EXPORT_BASE_ Stack :
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
	 * @remarks		After creating an instance of the %Stack class, one of the Construct() methods must be called explicitly to initialize this instance.
	 * @see 			Construct()
	 */
	Stack(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	 1.0
	 */
	virtual ~Stack(void);


	/**
	 * Initializes this instance of %Stack with the specified capacity.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	capacity		 The number of elements @n
     *                               The default capacity is @c 10.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or
	 *								  the specified @c capacity is negative.
	 * @remarks		If the number of elements added to the stack reaches the current capacity, 
	 *				the capacity is automatically increased by memory reallocation.
	 *				Therefore, if the size of the stack can be estimated, 
	 *				specifying the initial capacity eliminates the need to perform a number of 
	 *				resizing operations while adding elements to the stack.
	 * @see			Stack()
	 */
	result Construct(int capacity = DEFAULT_CAPACITY);


	/**
	 * Initializes this instance of %Stack by copying the elements of the specified collection. @n
	 * The capacity of the stack is the same as the number of elements copied.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection  The collection to copy elements from
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It copies just the pointer; not the element itself.
	 * @see			Stack()
	 */
	result Construct(const ICollection& collection);


// Operation

	/**
	 * Gets an enumerator of this stack.
	 *
	 * @since	 		1.0
	 * @return		An enumerator (an instance of the IEnumerator derived class) of this stack, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				IEnumerator
	 */
	virtual IEnumerator* GetEnumeratorN(void) const;


	/**
	 * Gets the element at the top of this stack without removing it.
	 *
	 * @since	 		1.0
	 * @return		The element at the top of this stack, @n
	 *				else @c null if this stack is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual const Object* Peek(void) const;


	/**
	 * Returns and removes the element at the top of this stack.
	 *
	 * @since	 		1.0
	 * @return		The element at the top of this stack, @n
	 *				else @c null if this stack is empty
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_UNDERFLOW	The operation (arithmetic/casting/conversion) has caused an underflow, or
	 *							this stack is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see				Push()
	 */
	virtual Object* Pop(void);


	/**
	 * Inserts an object at the top of this stack.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	obj  The object to add to this stack
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @remarks		This method performs a shallow copy. It inserts just the pointer; not the element itself.
	 * @see				Pop()
	 */
	virtual result Push(const Object& obj);


	/**
	 * Removes all objects and their pointers in @c collection, when the @c deallocate parameter is set to @c true. @n
     * This method can be called before deleting the objects in a collection. 
	 * 
	 * 
	 *
	 * @since	 		1.0
	 * @param[in]	deallocate		Set to @c true to deallocate all objects, @n
	 * 								else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);


// Access 

	/**
	 * Gets the number of objects currently stored in this stack.
	 *
	 * @since	 		1.0
	 * @return		The number of objects currently stored in this stack
	 */
	virtual int GetCount(void) const;


// Inquery

	/**
	 * Checks whether this stack contains the specified object.
	 *
	 * @since	 		1.0
	 * @return		@c true if this stack contains the specified object, @n
	 *				else @c false
	 * @param[in]	obj  The object to locate
	 */
	virtual bool Contains(const Object& obj) const;


	/**
	 * Checks whether this stack contains all of the elements in the specified collection.
	 *
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	collection	The collection to locate
	 * @param[out]	out  Set to @c true if this stack contains all the elements in the specified collection, @n
	 *					 else @c false 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *									the @c collection is modified during the operation of this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result ContainsAll(const ICollection& collection, bool& out ) const;


	/** 
	 * Checks whether the specified instance equals the current instance. 
	 *
	 * @since	 		1.0
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj The object to be compared with the current instance
	 * @remarks		This method returns @c true only if the specified object is also an instance of %Stack class,
	 *				both stacks have the same size, and all corresponding pairs of elements in the two stacks are equal.
	 *				In other words, two stacks are equal if they contain the same elements in the same order.
	 */
	virtual bool Equals(const Object& obj) const;


private:

// Lifecycle

	/**
	 * This is the copy constructor for this class.
	 *
	 * @param[in]	stack The other instance of Stack
	 * @remarks		This constructor is hidden.
	 */
	Stack(const Stack& stack);


// Operator

	/**
	 * This is the assignment operator.
	 *
	 * @since	 1.0
	 * @param[in]	stack The other instance of Stack
	 * @remarks		This operator is hidden.
	 */
	Stack& operator =(const Stack& stack);


// Attribute

	int __capacity;
	int __index;	
	Object** __pObjArray;
	int __modCount;

// Friend class
	friend class __StackEnumerator;


private:
	friend class StackEx;
	class StackEx* __pStackEx;

}; // Stack

}; }; }; // Osp::Base::Collection
#endif // _FBASE_COL_STACK_H_

