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
 * @file		FBaseRtThreadThread.h
 * @brief		This is the header file for the %Thread class.
 *
 * This header file contains the declarations of the %Thread class.
 */
#ifndef _FTHREAD_THREAD_H_
#define _FTHREAD_THREAD_H_


#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseObject.h"
#include "FBaseCol.h"
#include "FBaseRtThreadIRunnable.h"


#if defined (Yield)	// For preventing compile errors
#undef Yield
#endif


namespace Osp { namespace Base { namespace Runtime {

class __Thread;
class __ThreadManager;

/**
 * @internal
 *  
 * This enum is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this method.
 *
 * @enum Status
 * Defines thread status.
 *
 * @since	1.0
 */
enum Status
{
	THREAD_STATUS_INIT,         /**< @internal the thread is initializing */
	THREAD_STATUS_RUNNING,      /**< @internal the thread is running */
	THREAD_STATUS_STOP,        /**< @internal the thread has stopped */
};

/**
 * @enum ThreadType
 * Defines the type of the thread.
 *
 * @since	1.0
 */
enum ThreadType
{
	THREAD_TYPE_WORKER = 0, /**< The worker thread mode */
	THREAD_TYPE_EVENT_DRIVEN, /**< The event-driven thread mode */
	THREAD_TYPE_MAIN	/**< @internal The main thread mode */
};

/**
 * @enum ThreadPriority
 * Defines the priority of the thread.
 *
 * @since	1.0
 */
enum ThreadPriority
{
	THREAD_PRIORITY_HIGH, /**< The high priority*/
	THREAD_PRIORITY_MID, /**< The mid priority*/
	THREAD_PRIORITY_LOW, /**< The low priority*/
};

/**
 * @class 	Thread
 * @brief		This class is the fundamental class for the asynchronous execution of a thread.
 * @since		1.0
 *
 * The %Thread class is the fundamental class for the asynchronous execution of a thread.
 * A bada application can execute several threads during its operation from the multi-threading view.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/thread.htm">Thread</a>.
 *
 *
 */

class _EXPORT_BASE_ Thread :
	 public Osp::Base::Runtime::IRunnable,
	 public Object
{
// Constant
public:
	/**
	 * Default stack size of the thread.
	 *
	 * @since	1.0
	 */
	const static unsigned long DEFAULT_STACK_SIZE = 64 * 1024;


// Class method
public:

	/**
	 * Suspends the execution of the current thread for the specified interval.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	milliSeconds	The time, in milliseconds, for which to suspend the execution @n
	 *								A value of zero causes the thread to relinquish the remainder of its time slice to any other thread of equal priority that is ready to run.
	 *								This parameter cannot be infinite.
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result Sleep(long milliSeconds);


	/**
	 * Causes the current thread context to be temporarily paused and allows other threads to execute.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result Yield(void);


	/**
	 * Ends a thread.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	exitCode	The exit code for the thread @n
	 *							Use the GetExitCode() method to retrieve the thread's exit value.
	 * @exception	E_SUCCESS	The method is successful.
	 */
	static result Exit(int exitCode = 0x00);


	/**
	 * Gets the pointer of the currently running %Thread instance.
	 *
	 * @since		1.0
	 * @return	A pointer to the currently running thread
	 */
	static Thread* GetCurrentThread(void);

// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the
     *              Construct() methods must be called explicitly to initialize this instance.
	 */
	 Thread(void);


	/**
	 * Initializes this instance of %Thread with the specified parameters. @n
	 * This method creates a thread that has no name, no IRunnable instance, and the default stack size.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	threadType		The thread type
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority

	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Construct(ThreadType threadType = THREAD_TYPE_WORKER, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);
	/**
	 * Initializes this instance of %Thread with the specified parameters. @n
	 * This method creates a thread which has a given name, no IRunnable instance, and the default stack size.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	name			The name of the thread
	 * @param[in]	threadType		The thread type
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception	E_SUCCESS		The method is successful.
	 */
	result Construct(const Osp::Base::String& name, ThreadType threadType = THREAD_TYPE_WORKER, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %Thread with the specified parameters. @n
	 * This method creates a thread which has an IRunnable instance and the default stack size, but no name.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	target			The %IRunnable instance
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	An invalid priority is passed.
	 * @remarks		The Run() method is called when the thread starts.
	 */
	result Construct(IRunnable& target, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * Initializes this instance of %Thread with the specified parameters.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	name			The name of the thread
	 * @param[in]	target			The IRunnable instance
	 * @param[in]   stackSize       The thread stack size
	 * @param[in]   priority        The thread priority
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	An invalid priority is passed.
	 * @remarks		The Run() method is called when the thread starts. @n
	 * 				The stack size is the number of bytes for allocating the thread's stack area.
	 * 				Higher value of the stack size can make a deeper method call stack.
	 *				Higher value than the available memory size causes an OutOfMemory exception. @n
	 *				Some systems may have no functionality for thread stack size.
	 *				Therefore @c stackSize can have no effect on these systems.
	 */
	result Construct(const Osp::Base::String& name, IRunnable& target, long stackSize = DEFAULT_STACK_SIZE, ThreadPriority priority = THREAD_PRIORITY_MID);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Thread(void);


	/**
	 * Waits until the thread execution is terminated.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 *
	 */
	result Join(void);


// Operation
public:

	/**
	 * Starts the thread. @n
	 * The Run() method is called when the thread starts.
	 * A thread cannot start while it is running.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The thread is in an invalid state.
	 *
	 */
	result Start(void);

	/**
	 * Forces the thread to stop executing.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The thread is in an invalid state.
	 * @exception	E_SYSTEM			    A system error has occurred.
	 * @remarks      This is only available for event-driven threads.
	 */
	result Stop(void);


	/**
	 * Called if the thread is started without the IRunnable instance. @n
	 * The body for thread execution is specified by inheriting the %Thread class and implementing this method.
	 *
	 * @since		1.0
	 * @return	It is just ignored because there is nowhere to take the returned object
	 * @remarks	The default action of this method returns @c null.
	 * @warning	Do not override this method and use default implementation in case of the event-driven thread.
	 */
	virtual Osp::Base::Object* Run(void);

	/**
	 * Gets an exit code of the thread which is given by calling the Exit() method.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	exitCode				The exit code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The thread is in an invalid state.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result GetExitCode(int& exitCode) const;


// Access
public:

	/**
	 * Gets the name of the thread. @n
	 * The underlying OS performs the thread context switching. Therefore, this method can be used for debugging purposes, such as
     * finding the name of the current thread.
     *
	 * @since		1.0
	 * @return	The name of the thread
	 */
	const Osp::Base::String& GetName(void) const;


// virtual Operation
public:

	/**
	 * Called before the Run() method is executed. @n
	 * The Run() method is executed if this method returns @c true, and @n
	 * if this method returns @c false, the thread is terminated immediately.
	 *
	 * @since			1.0
	 * @return		@c true if this thread can be run, @n
	 *				else @c false
	 * @remarks		You can initialize the event or event listener in this method for running this
	 * 				thread in an event-driven mode.
	 *
	 */
	virtual bool OnStart(void);


	/**
	 * Called after the Run() method is executed.
	 *
	 * @since		1.0
	 * @remarks	You can finalize the event or event listener in this method for running this
	 * 			thread in an event-driven mode.
	 *
	 */
	virtual void OnStop(void);

public:
	/**
	* Sends a user event to the event-driven thread. @n
	* This method can be used only for an event-driven thread. 
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	requestId	The user-defined event Id
	* @param[in]	pArgs		A pointer to a list of arguments
	* @exception	E_SUCCESS The method is successful.
	* @exception 	E_INVALID_OPERATION The method is called in a thread that is not event-driven.
	* 
	* @see			OnUserEventReceived()
	*/
	result 	SendUserEvent (RequestId requestId, const Osp::Base::Collection::IList *pArgs);

	/**
	* Called when the user event is received. @n
	* This method is asynchronous.
	*
	* @since			1.0
	* @param[in]	requestId	The user-defined event Id
	* @param[in]	pArgs		A pointer to a list of arguments
	* @see			SendUserEvent()
	*/
	virtual void 	OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs);
private:
	/**
	 * @internal
	 * Initializes the thread context when thread is started.
	 */
	result Initialize(void);


	/**
	 * @internal
	 * Finalizes the thread context when thread is stopped.
	 */
	result Finalize(void);

private:
	/**
	 * This is the type of the thread.
	 */
	ThreadType __type;


	/**
	 * This is the pointer to the thread core.
	 */
	__Thread* __pThreadCore;

	bool 	__isMonitored;

	friend class __ThreadManager;

private:
	friend class ThreadEx;
	class ThreadEx* __pThreadEx;
};


//}
} } }


#endif

