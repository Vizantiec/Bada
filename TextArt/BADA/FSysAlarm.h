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
 * @file		FSysAlarm.h 
 * @brief		This is the header file for the %Alarm class.
 *
 * This header file contains declarations of the %Alarm class.
 */

#ifndef _FSYS_ALARM_H_
#define _FSYS_ALARM_H_

// Include
#include "FBaseDateTime.h"
#include "FSysConfig.h"
#include "FSysIAlarmEventListener.h"

namespace Osp { namespace System {

class IAlarmEventListenerPi;

/**
 * @class	Alarm
 * @brief	This class provides methods for creating, deleting, and updating an alarm. 
 * @since 1.0
 *
 * The %Alarm class provides methods to create a one-time or repeating alarm.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/system_namespace.htm">System Guide</a>.
 */

class IAlarmPi;

class _EXPORT_SYSTEM_ Alarm :
	public Osp::Base::Object
{
public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 1.0
	 */
	Alarm(void);

	/**
	 * This is the destructor for this class. @n
	 * It unregisters the current instance of %Alarm from the system.
	 *
	 * @since 1.0
	 */
	~Alarm(void);

	/**
	 * Initializes an instance of %Alarm with the specified listener.
	 *
	 * @since     1.0
	 * @return		An error code
	 * @param[in]	listener	A reference to IAlarmEventListener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception   E_SYSTEM    A system error has occurred.
	 */	
	result Construct(const IAlarmEventListener& listener);

public:
	/**
	 * Sets a one-time alarm.
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	duetime		The time for the alarm to ring
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception   E_INVALID_STATE This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		 The specified @c duetime is invalid.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
	 */
	result Set(const Osp::Base::DateTime& duetime);

	/**
	 * Sets a repeating alarm.
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	start	The time for the alarm to ring first
	 * @param[in]	period	The interval in minutes between consecutive alarm rings
	 * @param[in]	pEnd	The time for the alarm ring to end
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception   E_INVALID_STATE This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
	 * @remarks	If @c pEnd is @c null, the alarm repeats forever. 
	 */
	result Set(const Osp::Base::DateTime& start, int period, const Osp::Base::DateTime* pEnd = null);

public:
	/**
	 * Cancels the alarm.
	 *
	 * @since     1.0
	 * @privlevel	NORMAL
	 * @privgroup SYSTEM_SERVICE
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful. 
	 * @exception   E_INVALID_STATE This instance has not been constructed as yet.
	 * @exception   E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM    A system error has occurred.
	 */
	result Cancel(void);

public:
// Getters

	/**
	 * Gets the start time for the current instance of %Alarm.
	 *
	 * @since   1.0
	 * @return	An instance of DateTime indicating the start time for the alarm
	 */
	const Osp::Base::DateTime GetStartTime(void) const;

	/**
	 * Gets the period of the current instance of %Alarm in minutes.
	 *
	 * @since 1.0
	 */
	int GetPeriod(void) const; 

	/**
	 * Gets the end time for the current instance of %Alarm.
	 *
	 * @since   1.0
	 * @return	 A pointer to DateTime indicating the end time for the alarm, @n
	 *			else @c null if the end time has not been set
	 */
	const Osp::Base::DateTime* GetEndTime(void) const;

private:
	Osp::Base::DateTime __startTime;
	Osp::Base::DateTime* __pEndTime;
	int __period;

	IAlarmEventListenerPi* __pListenerPi;

private:
	IAlarmPi* __pAlarmPi;

private:
	friend class AlarmEx;
	class AlarmEx* __pAlarmEx;

}; // 
};	};	// Osp::System
#endif

