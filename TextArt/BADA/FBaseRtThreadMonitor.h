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
 * @file		FBaseRtThreadMonitor.h 
 * @brief		This is the header file for the %Monitor class.
 *
 * This header file contains the declarations of the %Monitor class.
 */

#ifndef _FTHREAD_MONITOR_H_
#define _FTHREAD_MONITOR_H_

#include "FBaseResult.h"
#include "FBaseRtThreadMutex.h"
#include "FBaseRtThreadSemaphore.h"


namespace Osp { namespace Base { namespace Runtime {
class Thread;


/**
 * @class 	Monitor
 * @brief	This class represents a monitor; a type of synchronization mechanism that provides acquire/release semantics by Enter/Exit as well as wait/notify semantics by Wait/Notify/NotifyAll.
 * @since 1.0
 *
 * The %Monitor class represents a monitor. %Monitor is a synchronization mechanism that provides acquire/release semantics by Enter/Exit as well as wait/notify semantics by Wait/Notify/NotifyAll.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/monitor.htm">Monitor</a>.
 *
 * The following examples demonstrates how to use the %Monitor class. In the examples, 2 classes, Consumer and Producer, share a space. 
 * Producer writes some data to this space, and Consumer reads it. Consumer and Producer run simultaneously. 
 * Consumer must not miss the data which Producer writes. In this case, Consumer and Producer share the monitor. 
 * Producer notifies Consumer that its writing action is done. Consumer waits for this notification, and reads the data after receiving it.
 *
 * @code
 * 	#include <FBase.h>
 *
 * 	using namespace Osp::Base;
 * 	using namespace Osp::Base::Runtime;
 *
 *	class Producer :
 *		public Osp::Runtime::Thread
 *	{
 *	public:
 *		
 *		// This methods creates a new instance of the Producer thread.
 *		Producer(int* pShared, Osp::Runtime::Monitor* pMonitor);
 *	
 *		// This methods waits for a starting Consumer and sets a value to the shared position. 
 *		//	Finally it notifies the Consumer thread. 
 *		Osp::Base::Object* Run(void);
 *	
 *	private:
 *		Osp::Runtime::Monitor* __pMonitor;
 *		int* __pShared;
 *	};
 *	
 *	class Consumer :
 *		public Osp::Runtime::Thread
 *	{
 *	public:
 *		 
 *		//This methods creates a new instance of the Consumer thread.
 *		Consumer(int* pShared, Osp::Runtime::Monitor* pMonitor);
 *	
 *		// This methods waits for a notification from the Producer thread and reads a value From the shared position. 
 *		Osp::Base::Object* Run(void);
 *	
 *	private:
 *		Osp::Runtime::Monitor* __pMonitor;
 *		int* __pShared;
 *	};
 *
 * @endcode
 *
 * @code
 *
 *	Producer::Producer(int* pShared, Monitor* pMonitor)
 *	:	__pShared(pShared),
 *		__pMonitor(pMonitor)	
 *	{	
 *	}
 *
 *	
 *	Object* 
 *	Producer::Run(void)
 *	{
 *	
 *		result r;
 *	
 *	
 *		// Begin a critical region
 *		r = __pMonitor->Enter();	
 *		if (IsFailed(r))
 *		{
 *			AppLog("Producer::Run: Monitor Enter failed.Wn");
 *			goto CATCH1;
 *		}
 *	
 *		// Wait for a starting Consumer
 *		r = __pMonitor->Wait();	
 *		if (IsFailed(r))
 *		{
 *			AppLog("Producer::Run: Monitor Wait failed.Wn");
 *			goto CATCH2;
 *		}
 *	
 *		// Produce a number value 6 times
 *		for (int i = 0; i < 6; i++)
 *		{
 *			*__pShared = i;
 *			
 *			// Notify the consumer thread 
 *			r = __pMonitor->Notify();
 *			if (IsFailed(r))
 *			{
 *				AppLog("Producer::Run: Monitor Notify failed.Wn");
 *				goto CATCH2;
 *			}
 *			
 *			if (*__pShared == 5) break;
 *	
 *	
 *			// Wait until the consumer thread reads the value
 *			r = __pMonitor->Wait();
 *			if (IsFailed(r))
 *			{
 *				AppLog("Producer::Run: Monitor Wait failed.Wn");
 *				goto CATCH2;
 *			}
 *		}
 *		
 *		// Exit the monitor
 *		r = __pMonitor->Exit();
 *		if (IsFailed(r))
 *		{
 *			AppLog("Producer::Run: Monitor Exit failed.Wn");
 *			goto CATCH1;
 *		}
 *	
 *		return null;
 *	
 *	CATCH1:
 *		return null;
 *	
 *	CATCH2:
 *		__pMonitor->Exit();
 *	
 *		return null;
 *	}
 *	
 *	
 *	Consumer::Consumer(int* pShared, Ptr<Monitor> pMonitor)
 *      :	__pShared(pShared),
 *		__pMonitor(pMonitor)
 *	{
 *	}
 *	
 *	Object* 
 *	Consumer::Run(void)
 *	{
 *		result r;
 *	
 *		// Begin a critical region
 *		r = __pMonitor->Enter();	
 *		if (IsFailed(r))
 *		{
 *			AppLog("Consumer::Run: Monitor Enter failed.Wn");
 *			goto CATCH1;
 *		}
 *	
 *		// Notify the producer thread
 *		r = __pMonitor->Notify();	
 *		if (IsFailed(r))
 *		{
 *			AppLog("Consumer::Run: Monitor Notify failed.Wn");
 *			goto CATCH2;
 *		}
 *	
 *		// Wait for the notification
 *		r = __pMonitor->Wait();
 *		while (!IsFailed(r))	
 *		{
 *			
 *			// Notify the producer thread
 *			r = __pMonitor->Notify();
 *			if (IsFailed(r))
 *			{
 *				AppLog("Consumer::Run: Monitor Notify failed.Wn");
 *				goto CATCH2;
 *			}		
 *	
 *			if (*__pShared == 5) break;
 *	
 *			// Wait for a notification
 *			r = __pMonitor->Wait();
 *			if (IsFailed(r))
 *			{
 *				AppLog("Consumer::Run: Monitor Wait failed.Wn");
 *				goto CATCH2;
 *			}	
 *		}
 *	
 *		// Exit the monitor
 *		r = __pMonitor->Exit();
 *		if (IsFailed(r))
 *		{
 *			AppLog("Consumer::Run: Monitor Exit failed.Wn");
 *			goto CATCH1;
 *		}
 *	
 *		return null;
 *	
 *	CATCH1:
 *		return null;
 *	
 *	CATCH2:
 *		__pMonitor->Exit();
 *		return null;
 *	}
 *	
 * @endcode
 *
 */

class _EXPORT_BASE_ Monitor :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	1.0
	 * @remarks	After creating an instance of this class, one of the 
	 * 			Construct() methods must be called explicitly to initialize this instance.
	 */
	Monitor(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	~Monitor(void);
	

	/**
	 * Initializes this instance of %Monitor.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM		An unknown operating system error has occurred.
	 */
	result Construct(void);


// Operation
public:

	/**
	 * Acquires a lock for a monitor. @n
	 * Semantically, this method declares the beginning of the critical region for the monitor. This region
	 * ends with the Exit() method.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful @n
	 *							(The method is successful in acquiring the lock).
	 * @see			Exit()
	 */
	result Enter(void);


	/**
	 * Releases a lock for a monitor. @n
	 * Semantically, it declares the ending of the critical region for the monitor that begins with 
	 * the Enter() method.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful @n
	 *							(The method is successful in releasing the lock).
	 * @exception	E_INVALID_STATE The current thread has not entered the monitor.
	 * @see			Enter()
	 */
	result Exit(void);

	/**
	 * Releases the lock for the monitor and waits for the notification from the other thread. @n
	 * After receiving the notification, it tries to acquire the lock.
	 * Semantically, it waits until the other thread notifies it.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @see			Notify(), NotifyAll()
	 */
	result Wait(void);

	/**
	 * Notifies one of the waiting threads. @n
	 * The selection of the notified thread is dependent on the underlying OS.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @see			NotifyAll(), Wait()
	 */
	result Notify(void);


	/**
	 * Notifies all waiting threads.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @see			Notify(), Wait()
	 */
	result NotifyAll(void);

private:

	Mutex __ready;
	Semaphore __waitSem;
	unsigned int	__nestedDepth;

	int __notifier;

	int	__numWaitingThread;
	unsigned int	__numNotifyThread;

private:
	friend class MonitorEx;
	class MonitorEx* __pMonitorEx;
};


//} 
} } } 


#endif

