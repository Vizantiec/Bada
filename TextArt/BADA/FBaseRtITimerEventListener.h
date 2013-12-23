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
 * @file		FBaseRtITimerEventListener.h 
 * @brief		This is the header file for the %ITimerEventListener interface.
 *
 * This header file contains the declarations of the %ITimerEventListener interface.
 */
#ifndef _FRT_ITIMER_EVENT_LISTENER_H_
#define _FRT_ITIMER_EVENT_LISTENER_H_


#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"


namespace Osp { namespace Base { namespace Runtime {
class Timer;

/**
 * @interface ITimerEventListener
 * @brief     This interface is the listener of the timer event.
 * @since 		1.0
 *
 * The %ITimerEventListener interface is the listener of the timer event.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/timer.htm">Timer</a>.
 *
 * @see		  	Timer()
 */
class _EXPORT_BASE_ ITimerEventListener :
	public IEventListener
{
// Lifetime
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~ITimerEventListener(void) {}


// Operation
public:

	/**
	 *	Called when the timer has expired.
	 *
	 *  @since 	1.0
	 *	@param	timer	The timer that has expired
	 */
	virtual void OnTimerExpired(Timer& timer) = 0;

};


} } }// Osp::Runtime


#endif

