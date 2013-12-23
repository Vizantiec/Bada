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
 * @file		FBaseRtThreadMutex.h
 * @brief		This is the header file for the %Mutex class.
 *
 * This header file contains the declarations of the %Mutex class.
 */

#ifndef _FTHREAD_MUTEX_H_
#define _FTHREAD_MUTEX_H_

#include "FBaseResult.h"
#include "FBaseString.h"


namespace Osp { namespace Base { namespace Runtime {


/**
 *  @class 	Mutex
 *	@brief	This class represents a mutex; a type of synchronization mechanism. 
 *	@since	1.0
 *
 *  The %Mutex class represents a mutex; a type of synchronization mechanism. 
 *	It is a binary semaphore. Only one thread can acquire the %Mutex.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/mutex_and_semaphore.htm">Mutex and Semaphore</a>.
 *
 *	@see 	Semaphore, Thread
 *
 * The following example demonstrates how to use the %Mutex class.
 *
 *	@code
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Runtime;
 *
 *  result
 *	MyApp::AddRef(void)
 *	{
 *    __pMutex->Acqure();
 *
 *    __count++;
 *
 *    __pMutex->Release();
 *	}
 *
 *	@endcode
 *
 *
 */
//class _EXPORT_BASE_ Mutex :
//	public virtual ISynchronizer
  class _EXPORT_BASE_ Mutex
{
// Lifecycle
public:

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		1.0
	 *	@remarks	After creating an instance of this class, one of
	 *				the Create() methods must be called explicitly to initialize this instance.
	 */
	Mutex(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~Mutex(void);

	/**
	 *	Creates an unnamed mutex.
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred.
	 */
 	result Create(void);

	/**
	 *	Creates a named mutex. @n
	 *	If a mutex with the specified name already exists, this creates a mutex which references that particular mutex.
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@param[in]	name			The name of the mutex
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred.
	 */
	result Create(const Osp::Base::String& name);

// Operation
public:

	/**
	 *  @internal
	 *
	 * 	This method is for internal use only. The bada platform team is not 
	 * 	responsible for any behavioral correctness, consistency, and 
	 * 	security-related issues that might arise after using this method.
	 *
	 *	Acquires the Mutex if it is not acquired. @n
	 *	If the Mutex is already acquired by another thread,
	 *	the current thread is blocked until the Mutex is released.
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@param[in]	timeout			The period during which the thread tries to acquire the mutex
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_TIMEOUT		The operation cannot be completed within the specified time period. @n
	 *	@exception	E_SYSTEM		An unknown operating system error occurred. @n
	 *								Failed to acquire the Mutex because an OS failure occurred.
	 */
	result Acquire(long timeout) const;

	/**
	 *	Releases the mutex.
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@exception	E_SUCCESS	The method is successful.
	 *	@exception	E_SYSTEM	An unknown operating system error has occurred. @n
	 *							The method has failed to acquire the mutex because an OS failure has occurred.
	 */
	result Release(void) const;

	/**
	 *	Acquires the mutex if it is not acquired. @n
	 *	If the mutex is already acquired by another thread,
	 *	the current thread is blocked until the mutex is released.
	 *
	 *	@since			1.0
	 *	@return			An error code
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_SYSTEM		An unknown operating system error has occurred. @n
	 *								The method has failed to acquire the mutex because an OS failure has occurred.
	 */
	result Acquire(void) const;

// Lifecycle

private:
	void* __pMutex;
	Osp::Base::String __name;

private:
	friend class MutexEx;
	class MutexEx* __pMutexEx;
};


//}
} } }// Osp::Runtime


#endif

