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
 * @file		FBaseRtTimer.h
 * @brief		This is the header file for the %Timer class.
 *
 * This header file contains the declarations of the %Timer class.
 */
#ifndef _FRT_TIMER_H_
#define _FRT_TIMER_H_

#include "FBaseString.h"
#include "FBaseResult.h"
#include "FBaseResource.h"
#include "FBaseRtTypes.h"
#include "FBaseRtITimerEventListener.h"


namespace Osp { namespace Base { namespace Runtime {

/**
 * @class	Timer
 * @brief	This class provides the timer service.
 * @since       1.0
 *
 * The %Timer class can activate the timer and notify the listeners.
 * This class is not a periodic timer, only a one-shot timer.
 * If you want to carry out periodic tasks, you must start the timer again after it has fired.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/timer.htm">Timer</a>.
 *
 * The following example demonstrates how to use the %Timer class.
 *
 * @code
 *
 * #include <FBase.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::System;
 *
 * class MyApp
 * 	: public ITimerEventListener
 * {
 *    ...
 * public:
 * 	result InitTimer();
 * public:
 * 	void OnTimerExpired(Timer& timer);
 * };
 * 
 * void
 * MyApp::OnTimerExpired(Timer& timer)
 * {
 * 
 *     ...
 * 
 * 	timer.Start(1000);
 * }
 * 
 * 
 * result
 * MyApp::InitTimer()
 * {
 * 	result r = E_SUCCESS;
 * 
 * 	_pTimer = new Timer;
 * 
 * 	r = _pTimer->Construct(*this);
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 * 
 * 	_pTimer->Start(1000);
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 * 
 * 	return r;
 * CATCH:
 *     return r;
 * }
 * @endcode
 *
 * @see	ITimerEventListener()
 */

class _EXPORT_BASE_ Timer :
	public Osp::Base::Object,
	public Osp::Base::__Resource
{

// Lifecycle
public:


	/**
	 * This is the default constructor for this class.
	 *
	 * @since       1.0
	 */
	Timer(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since       1.0
	 */
	~Timer(void);

	/**
	 * Initializes this instance of %Timer with the specified listener.
	 *
	 * @since     1.0
	 * @return		An error code
	 * @param[in]	listener		The event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Construct(const ITimerEventListener& listener);

	/**
	 * @if PRIVCORE
	 * Initializes this instance of %Timer with the specified parameters.
	 *
	 * @since     1.0
	 * @privlevel	CORE
	 * @privgroup RUNTIME
	 *
	 * @return		An error code
	 * @param[in]	listener	The event listener
	 * @param[in]   awake	  Set to @c true if the timer continues to run even if the system enters sleep mode, @n
	 *                        else @c false if the timer stops running when the system enters sleep mode
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 *
	 * @exception E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 *
	 * @endif
	 */
	result Construct(const ITimerEventListener& listener, bool awake);

// Operation
public:

	/**
	 * Starts the timer.
	 *
	 * @since     1.0
	 * @return		An error code
	 * @param[in]	timeout	 		A timeout interval in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	The state of the timer is not a valid state or
	 *								the timer might be in the TIMER_STATUS_ACTIVATED state.
	 * @remarks		Once it has been started, it cannot be started again until it expires. @n
	 * 			    You must cancel it if you want to re-start the timer.
	 * @see				Cancel()
	 */
	result Start(int timeout);


	/**
	 * Cancels the timer.
	 *
	 * @since     1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	The state of the timer is not a valid state or
	 *								the timer might be in the TIMER_STATUS_NOT_ACTIVATED state.
	 * @remarks		The timer cannot be canceled if it is not started.
	 */
	result Cancel(void);

private:
	/**
	 * This is callback of the matrix timer.
	 */
	static void OnMatrixTimerExpired(const void* pI, void* pMTimer, unsigned long param);


	/**
	* This method frees the resource allocated by this instance.
	* @return		An error code
	* @exception	E_SUCCESS The method is successful.
	* @exception	E_SYSTEM The method is unable to free the resource currently possessed by this instance.
	*/
	result Dispose(void);

private:
	void* __pMTimer;
	void* __pMTimerEventListener;

	ITimerEventListener* __pTimerEventListener;

	TimerStatus __status;
	bool __isMonitored;

private:
	friend class TimerEx;
	class TimerEx* __pTimerEx;

};


} } }// Osp::Runtime


#endif

