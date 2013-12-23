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
 * @file		FBaseRtThreadSemaphore.h
 * @brief		This is the header file for the %Semaphore class.
 *
 * This header file contains the declarations of the %Semaphore class.
 */

#ifndef _FTHREAD_SEMAPHORE_H_
#define _FTHREAD_SEMAPHORE_H_

#include "FBaseResult.h"
#include "FBaseString.h"


namespace Osp { namespace Base { namespace Runtime {




/**
 *  @class  Semaphore
 *  @brief  This class represents semaphore; a type of synchronization mechanism.
 *  @since  1.0
 *
 * The %Semaphore class represents a semaphore; a type of synchronization mechanism. 
 * It can provide the acquiring semantics. The semaphore allows the N threads to acquire the semaphore simultaneously. 
 *  
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/mutex_and_semaphore.htm">Mutex and Semaphore</a>.
 */
class _EXPORT_BASE_ Semaphore
{
// Lifecycle
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since  	1.0
	 *	@remarks	After creating an instance of this class, one of
	 *				the Create() methods must be called explicitly to initialize this instance.
	 */
	Semaphore(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *  @since  1.0
	 */
	~Semaphore(void);


	/**
	 *	Creates an unnamed semaphore.
	 *
	 *  @since  		1.0
	 *  @return			An error code
	 *	@param[in]	count			The number of threads that can acquire the semaphore simultaneously @n
	 *								If the count is @c 1, then it is the same as a mutex.
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_INVALID_ARG	The specified @c count is less than @c 0.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred.
	 */
 	result Create( int count = 1);


	/**
	 *	Creates a named semaphore. @n
	 *	If a semaphore with the specified name already exists, this creates a semaphore which references that particular semaphore.
	 *
	 *  @since  		1.0
	 *	@return			An error code
	 *	@param[in]	name			The name of the semaphore
	 *	@param[in]	count			The number of threads that can acquire the semaphore simultaneously
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_INVALID_ARG	The specified @c count is less than @c 0.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred.
	 */
	result Create(const Osp::Base::String& name, int count = 1);

// Operation
public:

/**
	 *	Acquires the semaphore if it is not acquired. @n
	 *	If the semaphore is already acquired, the current thread is blocked until the semaphore is released.
	 *
	 *  @since  		1.0
	 *	@return			An error code
	 *	@param[in]	timeout			The period during which the thread tries to acquire the semaphore
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_TIMEOUT		The operation cannot be completed within the specified time period. @n
	 *								The method has failed to acquire the semaphore because the given time has elapsed.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred. @n
	 *								The method has failed to acquire the semaphore because an OS failure has occurred.
	 */
	result Acquire(long timeout=INFINITE) const;

	/**
	 *	Releases the semaphore.
	 *
	 *  @since  		1.0
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred. @n
	 *								The method has failed to acquire the semaphore because an OS failure has occurred.
	 */
	result Release(void) const;

// Lifecycle

private:
	void* __pSemaphore;
	Osp::Base::String __name;
	int __count;

private:
	friend class SemaphoreEx;
	class SemaphoreEx* __pSemaphoreEx;
};


//}
} } }// Osp::Runtime


#endif

