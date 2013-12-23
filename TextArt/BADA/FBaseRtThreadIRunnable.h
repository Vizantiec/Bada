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
 * @file		FBaseRtThreadIRunnable.h 
 * @brief		This is the header file for the %IRunnable interface.
 *
 * This header file contains the declarations of the %IRunnable interface.
 */
#ifndef _FTHREAD_IRUNNABLE_H_
#define _FTHREAD_IRUNNABLE_H_


#include "FBaseResult.h"
#include "FBaseObject.h"


namespace Osp { namespace Base { namespace Runtime {
//namespace Threading {



/**
 * @interface IRunnable
 * @brief	This interface is the basic unit of the task. Also, it is the execution unit of 
 *          the thread. This interface must be inherited by the class whose instances will 
 * 	        run on the thread.
 * @since 1.0
 *
 * @remarks	Classes which inherit the %IRunnable interface must implement the Run() method.
 *
 * The %IRunnable interface is the basic unit of the task. Also, it is the execution unit of 
 * the thread. This interface must be inherited by the class whose instances will 
 * run on the thread.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/thread_programming.htm">Thread Programming</a>.
 *
 * @see		Thread
 *
 * The following example demonstrates how to use the %IRunnable interface. 
 *
 * @code
 *      #include <FBase.h>
 *
 *      using namespace Osp::Base;
 *      using namespace Osp::Base::Runtime;
 *
 *	class MyRun : 
 * 		public Osp::Base::Object,
 * 		public Osp::Base::Runtime::IRunnable
 *	{
 *	public:
 * 		Object* Run(void)
 * 		{
 * 			for(int i = 0; i < 10000; ++i)
 * 			{
 * 				// Do some job
 * 			}
 * 		
 * 			return null;
 * 		}
 *	}
 *
 * @endcode
 *
 *
 *
 */
class _EXPORT_BASE_ IRunnable
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~IRunnable(void);


// Operation
public:
	/** 
	 * Executes the task. @n
	 * This method is an executable body of the task. In many cases, this method is called by the thread.
	 * Although this method can return the result of the execution, the returned value might be discarded
	 * by the executor of this task.
	 *
	 * @since 	1.0
	 * @return	A pointer to the result of the task, @n
	 *			else @c null
	 */
	virtual Osp::Base::Object* Run(void) = 0;

};


//} 
} } }// Osp::Runtime


#endif

