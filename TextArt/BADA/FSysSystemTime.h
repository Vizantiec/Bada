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
 * @file		FSysSystemTime.h 
 * @brief		This is the header file for the %SystemTime class.
 *
 * This header file contains the declarations of the %SystemTime class.
 */

#ifndef _FSYS_SYSTEM_TIME_H_
#define _FSYS_SYSTEM_TIME_H_

#include "FBaseObject.h"
#include "FBaseTimeSpan.h"
#include "FBaseDateTime.h"

#include "FSysConfig.h"

#if defined(GetCurrentTime)	// This macro is defined in the win32 method
#undef GetCurrentTime
#endif

namespace Osp { namespace System {
/**
 * @class	SystemTime
 * @brief	This class provides methods to get the system time.
 * @since 1.0
 *
 * The %SystemTime class provides methods to get the current system time, ticks, and uptime. 
 * It also supports the UTC, standard, and wall time modes.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/system/systime.htm">System Time</a>.
 */

/**
 * @enum	TimeMode
 * Defines the three types of time modes.
 *
 * @since 1.0
 */
enum TimeMode
{
	UTC_TIME,  /**< The UTC Time */
	STANDARD_TIME, /**< The Standard Time */
	WALL_TIME, /**< The Wall Time */
};

class _EXPORT_SYSTEM_ SystemTime
{
public:
// static method
	/**
	 * Gets the uptime in milliseconds since the system is booted.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]  uptime The uptime in milliseconds
	 * @exception	E_SUCCESS	The method is successful. 
	 */
	static result GetUptime(Osp::Base::TimeSpan& uptime);


	/**
	 * Gets the current system time.
	 *
	 * @since 		1.0
	 * @return		An error code
   * @param[out]  currentTime The current system time in UTC
	 * @exception	E_SUCCESS	The method is successful. 
	 */		
	static result GetCurrentTime(Osp::Base::DateTime& currentTime);

	/**
	 * Gets the current system time.
   *
   * @since 		1.0
 	 * @return		An error code
	 * @param[in]	timeMode	The time mode UTC_TIME, STANDARD_TIME, or WALL_TIME
	 * @param[out]  currentTime The current system time
	 * @exception	E_SUCCESS	The method is successful. 
	 */		
	static result GetCurrentTime(TimeMode timeMode, Osp::Base::DateTime& currentTime);


	/**
	 * Gets the current system time in milliseconds since 1/1/1970 UTC.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[out] ticks The system time in milliseconds
	 * @exception	E_SUCCESS	The method is successful. 
	 */		
	static  result GetTicks(long long& ticks);

private:
	SystemTime(void);
	

private:
	friend class SystemTimeEx;
	class SystemTimeEx* __pSystemTimeEx;

};	
};	};
#endif // _FSYS_SYSTEM_TIME_H_
