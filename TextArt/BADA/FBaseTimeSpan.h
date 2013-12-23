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
 * @file		FBaseTimeSpan.h 
 * @brief		This is the header file for the %TimeSpan class.
 *
 * This header file contains the declarations of the %TimeSpan class.
 */
#ifndef _FBASE_TIMESPAN_H_
#define _FBASE_TIMESPAN_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseObject.h"


namespace Osp { namespace Base {
/**
 *	@class	TimeSpan 
 *	@brief	This class represents a time interval.
 *	@since	1.0
 *
 *	The %TimeSpan class represents a time interval. An instance of %TimeSpan represents a period of time measured in ticks. A tick is the smallest
 *	unit of time used by the platform or system. In bada, it is a millisecond.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/datetime_timespan.htm">DateTime and TimeSpan</a>.
 *
 *	The following example demonstrates how to use the %TimeSpan class.
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::TimeSpanSample(void)
 *	{
 *		TimeSpan span1(1, 1, 1);	// one hour + one minute + one second
 *		TimeSpan span2(1, 23, 70, 100); // 1 days + 23 hours + 70 minutes + 100 seconds
 *		
 *		if (span2 > span1) // true
 *		{
 *			TimeSpan span3 = (span2 - span1);
 *			if (TimeSpan::Compare(span1, span3) == 0) // false
 *			{
 *				...
 *			}
 *		}
 *
 *
 *		long long days, hours, minutes, seconds;
 *
 *		days = span2.GetDays();				// 2 days
 *		hours = span2.GetHours();			// 0 hours
 *		minutes = span2.GetMinutes();		// 11 minutes
 *		seconds = span2.GetSeconds();		// 40 seconds
 *
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ TimeSpan :
	public Object
{
// Lifecycle
public:
	/** 
	 * This is the copy constructor for the %TimeSpan class.
	 *
	 * @since			1.0
	 * @param[in] value		A %TimeSpan instance to be copied
	 */
	TimeSpan(const TimeSpan& value);


	/** 
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since			1.0
	 * @param[in]	hours	The number of hours
	 * @param[in]	minutes	The number of minutes
	 * @param[in]	seconds	The number of seconds
	 */
	TimeSpan(int hours, int minutes, int seconds);


	/** 
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since			1.0
	 * @param[in]	days	The number of days
	 * @param[in]	hours	The number of hours
	 * @param[in]	minutes	The number of minutes
	 * @param[in]	seconds	The number of seconds
	 */
	TimeSpan(int days, int hours, int minutes, int seconds);


	/** 
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since			1.0
	 * @param[in]	days			The number of days
	 * @param[in]	hours			The number of hours
	 * @param[in]	minutes			The number of minutes
	 * @param[in]	seconds			The number of seconds
	 * @param[in]	milliseconds	The number of milliseconds
	 */
	TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds);


	/** 
	 * Initializes an instance of %TimeSpan with the specified number of ticks.
	 *
	 * @since			1.0
	 * @param[in]	ticks	The number of ticks (in milliseconds)
	 */
	TimeSpan(long long ticks);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~TimeSpan(void);


// Operator
public:
	/** 
	 * This operator adds the values of the two instances of %TimeSpan.
	 *
	 *
	 * @since			1.0
	 * @return		An instance of %TimeSpan
	 * @param[in]	rhs	An instance of %TimeSpan to add
	 */
	TimeSpan operator +(const TimeSpan& rhs) const;


	/** 
	 * This operator gives the difference between the values of the two instances of %TimeSpan.
	 *
	 *
	 * @since			1.0
	 * @return		An instance of %TimeSpan
	 * @param[in]	rhs	An instance of %TimeSpan to subtract
	 */
	TimeSpan operator -(const TimeSpan& rhs) const;


	/** 
	 * This operator assigns the value of the specified %TimeSpan instance to the current instance of %TimeSpan.
	 *
	 *
	 * @since			1.0
	 * @return		A reference to the current instance of %TimeSpan
	 * @param[in]	rhs	The instance of %TimeSpan used to assign value to the calling instance
	 */
	TimeSpan& operator =(const TimeSpan& rhs);


	/** 
	 * This operator checks if the value of this instance is equal to the value of the 
	 * specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the two values are equal, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator ==(const TimeSpan& rhs) const;


	/** 
	 * This operator checks if the value of this instance is not equal to 
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the two values are not equal, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator !=(const TimeSpan& rhs) const;


	/** 
	 * This operator checks if the value of the calling instance is less than that of  
	 * the specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the value of calling instance is less than that of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator <(const TimeSpan& rhs) const;


	/** 
	 * This operator checks if the value of the calling instance is greater than that of
	 * the specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the value of calling instance is greater than that of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator >(const TimeSpan& rhs) const;


	/** 
	 * This operator checks if the value of the calling instance is less than or equal to  
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the value of calling instance is less than or equal to the value of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator <=(const TimeSpan& rhs) const;


	/** 
	 * This operator checks if the value of the calling instance is greater than or equal to  
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the value of calling instance is greater than or equal to the value of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator >=(const TimeSpan& rhs) const;


// Operation
public:
	/** 
	 * Compares the two specified instances of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		A 32-bit signed integer value:
	 * @code	 
	 * <  0  if the value of t1 is less than the value of t2
	 * == 0  if the value of t1 is equal to the value of t2
	 * >  0  if the value of t1 is greater than the value of t2
	 * @endcode
	 * @param[in]	t1	An instance of %TimeSpan to be compared
	 * @param[in]	t2	An instance of %TimeSpan to be compared
	 */
	static int Compare(const TimeSpan& t1, const TimeSpan& t2);


	/** 
	 * Compares the value of the calling instance to the value of the specified instance. 
	 *
	 * @since			1.0
	 * @return		A 32-bit signed integer value:
	 * @code	 
	 * <  0  if the value of the current instance is less than the value of obj
	 * == 0  if the value of the current instance is equal to the value of obj
	 * >  0  if the value of the current instance is greater than the value of obj
	 * @endcode
	 * @param[in]	value	An instance of %TimeSpan to compare
	 */
	int CompareTo(const TimeSpan& value) const;


	/** 
	 * Checks whether the specified instance of Object is equal to the current instance of %TimeSpan.
	 *
	 * @since			1.0
	 * @return		@c true if the specified instance of %Object is equal to the current instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	obj An instance of %Object to compare 
	 * @see			Osp::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;


	/** 
	 * Gets the absolute value of the calling instance.
	 *
	 *  @since			1.0
	 *	@return			An instance of %TimeSpan containing the absolute value
	 *	@remarks		This method is used to get absolute difference between two %TimeSpan instances.
	 *	@code
	 *	TimeSpan t1(1000); // 1000 milliseconds
	 *	TimeSpan t2(2000); // 2000 milliseconds
	 *	TimeSpan t3 = t1 - t2; // t3 == -1000
	 *	TimeSpan t4 = t3.Duration(); // t4 == 1000
	 *	@endcode
	 */
	TimeSpan Duration(void) const;


	/** 
	 * Gets the hash value of this instance.
	 *
	 * @since		1.0
	 * @return	The hash code of the calling instance
	 * @see			Osp::Base::Object::Equals()
	 */
	virtual int GetHashCode(void) const;


	/** 
	 * Gets the negative value of the calling instance.
	 *
	 * @since			1.0
	 * @return		A %Timespan instance containing the negative value of the calling instance
	 */
	TimeSpan Negate(void) const;


// Accessor
public:
	/** 
	 * Gets the number of whole days represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of whole days represented by the calling instance
	 */
	long long GetDays(void) const;


	/** 
	 * Gets the number of hours represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of hours represented by the calling instance
	 */
	long long GetHours(void) const;


	/** 
	 * Gets the number of minutes represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of minutes represented by the calling instance
	 */
	long long GetMinutes(void) const;


	/** 
	 * Gets the number of seconds represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of seconds represented by the calling instance
	 */
	long long GetSeconds(void) const;


	/** 
	 * Gets the number of milliseconds represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of milliseconds represented by the calling instance
	 */
	long long GetMilliseconds(void) const;


	/** 
	 * Gets the number of ticks represented by the calling instance.
	 *
	 * @since			1.0
	 * @return		The number of ticks represented by the calling instance
	 */
	long long GetTicks(void) const;


// Constant
public:
	/** 
	 * A constant holding the number of ticks in a day. 
	 *
	 * @since	1.0
	 */
	static const long long NUM_OF_TICKS_IN_DAY = 86400000;


	/** 
	 * A constant holding the number of ticks in an hour. 
	 *
	 * @since	1.0
	 */
	static const long long NUM_OF_TICKS_IN_HOUR = 3600000;


	/** 
	 * A constant holding the number of ticks in a minute. 
	 *
	 * @since	1.0
	 */
	static const long long NUM_OF_TICKS_IN_MINUTE = 60000;


	/** 
	 * A constant holding the number of ticks in a second. 
	 *
	 * @since	1.0
	 */
	static const long long NUM_OF_TICKS_IN_SECOND = 1000;


// Operation
private:
	/* 
	 * Gets the numbers of ticks.
	 * @return		The numbers of ticks
	 * @param[in]	days			The number of whole days
	 * @param[in]	hours			The number of hours
	 * @param[in]	minutes			The number of minutes
	 * @param[in]	seconds			The number of seconds
	 * @param[in]	milliseconds	The number of milliseconds
	 */
	static long long CalcTicks(int days, int hours, int minutes, int seconds, int milliseconds);


// Attribute
private:
	long long __ticks;


private:
	friend class TimeSpanEx;
	class TimeSpanEx* __pTimeSpanEx;
};		// Osp::Base::TimeSpan
}; };	// Osp::Base
#endif //_FBASE_TIMESPAN_H_
