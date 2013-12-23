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
 * @file		FSysIAlarmEventListener.h 
 * @brief		This is the header file for the %IAlarmEventListener interface.
 *
 * This header file contains the declarations of the %IAlarmEventListener interface.
 */
#ifndef _FSYS_IALARM_EVENT_LISTENER_H_
#define _FSYS_IALARM_EVENT_LISTENER_H_

#include "FBaseResult.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace System {

// Forward declaration
class AlarmEvent;
class Alarm;

/**
 * @interface	IAlarmEventListener
 * @brief	This interface is the listener of the alarm event.
 * @since 1.0
 *
 * The %IAlarmEventListener interface must be registered and implemented by an application to receive Alarm events from the system.
 *
 */
class _EXPORT_SYSTEM_ IAlarmEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifetime
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~IAlarmEventListener(void) {}


// Operation
public:

	/**
	 *	Called when the alarm expires.
	 *
	 *  @since	1.0
	 *	@param[in]	alarm		The alarm that expires
	 */
	virtual void OnAlarmExpired(Alarm& alarm) = 0;

};
};	}; // Osp::System

#endif // _FSYS_IALARM_EVENT_LISTENER_H_



