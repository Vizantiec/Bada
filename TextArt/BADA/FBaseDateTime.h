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
 * @file		FBaseDateTime.h 
 * @brief		This is the header file for the %DateTime class.
 *
 * This header file contains the declarations of the %DateTime class.
 */
// Includes
#ifndef _FBASE_DATE_TIME_H_
#define _FBASE_DATE_TIME_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTimeSpan.h"
#include "FBaseString.h"



namespace Osp { namespace Base {
/**
 *	@class	DateTime 
 *	@brief	This class represents the date and time as per the Gregorian calendar.
 *	@since	1.0
 *
 *	The %DateTime class represents dates and times with values ranging from 12:00:00 midnight,
 *	January 1, 1 to 11:59:59 P.M., December 31, 9999 in the Gregorian calendar. It 
 *	provides methods for conversion between the time formats. 
 *
 *	For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/datetime_timespan.htm">DateTime and TimeSpan</a>.
 *
 *  The following example demonstrates how to use the %DateTime class.

 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	
 *	// This method sets both current local time and UTC time.
 *	void
 *	MyClass::DateTimeSample(void)
 *	{
 *		DateTime dt; 
 *		int year, month, day;
 *
 *		dt.SetValue(2009, 10, 25);
 *
 *		dt.AddYears(10);
 *		dt.AddMonths(3);
 *		dt.AddDays(5);
 *
 *
 *		// Get values
 *		year = dt.GetYear();		//	2020
 *		month = dt.GetMonth();		//	1
 *		day = dt.GetDay();			//	30
 *	
 *	}
 *	@endcode
 */
class _EXPORT_BASE_ DateTime :
	public Object
{

private:
	typedef struct
	{
		int		year; 	/**<The year (1 ~ 9999)*/
		int		month;	/**<The month (-12)*/
		int		day;	/**<The day (1-31)*/
		int		hour;	/**<The hour (0-23)*/
		int		minute; /**<The minute (0-59)*/
		int		second;	/**<The second (0-59)*/
	} TmDateTime;


// Lifecycle
public:
	/** 
	 *	This is the default constructor for this class.
	 *
	 *	@since	 	1.0
	 *	@remarks	The value of the instance is the same as the value of the instance returned by the GetMinValue() method.
	 */
	DateTime(void);

	/** 
	 *	This is the copy constructor for the %DateTime class.
	 *
	 *	@since			1.0
	 *	@param[in] 	value		An instance of %DateTime to be copied
	 */
	DateTime(const DateTime& value);

	/** 
	 *	Sets the current instance of %DateTime to the value of the specified
	 *	instance of TimeSpan since the minimum date (GetMinValue(void)).
	 *
	 *	@since	 		1.0
	 *	@param[in]	value	An instance of %TimeSpan
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n 
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or
	 *									is less than the value returned by GetMinValue().
	 */
	result SetValue(const TimeSpan& value);


	/** 
	 *	Sets the current instance of %DateTime to the value of the specified
	 *	instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@param[in]	value	An instance of %DateTime
	 */
	void SetValue(const DateTime& value);


	/** 
	 *	Sets the current instance of %DateTime to the specified @c year, @c month, @c day, @c hour, 
	 *	@c minute, and @c second.
	 *
	 *	@since	 		1.0
	 *	@return			An error code
	 *	@param[in]	year				The year to be set
	 *	@param[in]	month				The month to be set
	 *	@param[in]	day					The day to be set
	 *	@param[in]	hour				The hour to be set
	 *	@param[in]	minute				The minute to be set
	 *	@param[in]	second				The second to be set
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The value of the argument is outside the valid range defined by the method. @n 
	 *									- The arguments are greater than the value returned by GetMaxValue(void) or
	 *									are less than the value returned by GetMinValue(). @n
	 *									- The arguments contain invalid values. @n
	 *									For example, the day is @c 31 when the month is @c 2.
	 */
	result SetValue(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);



// Operator
public:
	/** 
	 *	This operator assigns the value of the specified %DateTime object to the current object. 
	 *
	 *	@since	 		1.0
	 *	@return			A reference to the current object
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	DateTime& operator =(const DateTime& rhs);


	/** 
	 *	This operator checks if the current instance of %DateTime is equal to the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the current instance is equal to the specified instance, @n
	 *				else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator ==(const DateTime& rhs) const;


	/** 
	 *	This operator checks if the current instance of %DateTime is not equal to the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the current instance is not equal to the specified instance, @n
	 *			else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator !=(const DateTime& rhs) const;


	/** 
	 *	This operator checks if the value of the current instance of %DateTime is less than the value of the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the value of the current instance is less than the value of the specified instance, @n
	 *			else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator <(const DateTime& rhs) const;


	/** 
	 *	This operator checks if the value of the current instance of %DateTime is greater than the value of the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the value of the current instance is greater than the value of the specified instance, @n
	 *			else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator >(const DateTime& rhs) const;


	/** 
	 *	This operator checks if the value of the current instance of %DateTime is less than or equal to the value of the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the value of the current instance is less than or equal to the value of the specified instance, @n
	 *			else @c false
	 *	@param[in]	rhs		An instance of %DateTime
	 */
	bool operator <=(const DateTime& rhs) const;


	/** 
	 *	This operator checks if the value of the current instance of %DateTime is greater than or equal to the value of the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			@c true if the value of the current instance is greater than or equal to the value of the specified instance, @n
	 *			else @c false
	 *	@param[in]	rhs	An instance of %DateTime
	 */
	bool operator >=(const DateTime& rhs) const;



// Operation
public:
	/** 
	 *	Adds the specified time span to the instance of %DateTime. 
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	t					The time span to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result Add(const TimeSpan& t);


	/** 
	 *	Adds the specified number of days to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	days				The number of days to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddDays(int days);


	/** 
	 *	Adds the specified number of hours to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	hours				The number of hours to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddHours(int hours);


	/** 
	 *	Adds the specified number of minutes to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	minutes				The number of minutes to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddMinutes(int minutes);
	
	
	/** 
	 *	Adds the specified number of months to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	months				The number of months to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddMonths(int months);


	/** 
	 *	Adds the specified number of seconds to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	seconds				The number of seconds to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddSeconds(int seconds);


	/** 
	 *	Adds the specified number of years to the instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return	An error code
	 *	@param[in]	years				The number of years to add
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result AddYears(int years);


	/** 
	 *	Compares two specified instances of %DateTime. @n
	 *	The two instances should be in the same time zone to make a meaningful comparison.
	 *
	 *	@since	 		1.0
	 *  @return			A 32-bit signed integer value:
	 *	@code	 
	 *	<  0  if the value of dt1 is less than the value of dt2
	 *	== 0  if the value of dt1 is equal to the value of dt2
	 *	>  0  if the value of dt1 is greater than the value of dt2
	 *	@endcode
	 *	@param[in]	dt1	The first instance of %DateTime
	 *	@param[in]	dt2	The second instance of %DateTime
	 */
	static int Compare(const DateTime& dt1, const DateTime& dt2);


	/** 
	 *	Compares the value of the current instance of %DateTime with the value of the specified instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *  @return			A 32-bit signed integer value:
	 *	@code	 
	 *	<  0  if the value of the current instance is less than the value of the specified instance
	 *	== 0  if the value of the current instance is equal to the value of the specified instance
	 *	>  0  if the value of the current instance is greater than the value of the specified instance
	 *	@endcode
	 *	@param[in]		value	An instance of %DateTime
	 */
	int CompareTo(const DateTime& value) const;


	/** 
	 *	Checks whether the specified instance of Object is equal to the current instance of %DateTime.
	 *
	 *	@since	 	1.0
	 *	@return		@c true if the specified instance of %Object is equal to the current instance of %DateTime, @n
	 *				else @c false
	 *	@param[in]	obj An instance of %Object to compare
	 *	@see			Osp::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;


	/** 
	 *	Gets the hash value of the current instance of %DateTime. @n
	 *	The hash value is calculated as (GetTime() ^ (GetTime() >> 16)).
	 *
	 *	@since	  1.0
	 *	@return		The hash value of the current instance of %DateTime
	 *	@see		Osp::Base::Object::Equals()
	 */
	virtual int GetHashCode(void) const;


	/**	 
	 *	Gets the time span from the midnight of the date represented by the current instance of %DateTime.
	 *
	 *	@since	 	1.0
	 *	@return		An instance of %TimeSpan
	 */
	TimeSpan GetTimeOfDay(void) const;


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static method

	/** 
	 *	Gets the number of days in the specified month of the specified year.
	 *
	 *	@since	 		1.0
	 *	@return			An error code
	 *	@param[in]	year				The year
	 *	@param[in]	month				The month
	 *	@param[out]	days				The number of days
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The @c year must be a value between @c 1 and @c 9999 and the @c month must be a value between @c 1 and @c 12.
	 */
	static result GetDaysInMonth(int year, int month, int& days);


	/** 
	 *	Deducts the specified time span from the value of the current instance of %DateTime.
	 *
	 *	@since	 		1.0
	 *	@return			An error code
	 *	@param[in]	t					The time span to deduct
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method. @n
	 *									The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) or 
	 *									is less than the value returned by GetMinValue(void).
	 */
	result Subtract(const TimeSpan& t);


	/** 
	 *	Represents the current instance of %DateTime as a string.
	 *
	 *	@since	  1.0
	 *	@return		A string containing Unicode representation of the value of the current instance of %DateTime
	 *	@remarks	The format of the string representation is "mm/dd/yyyy hh:mm:ss".
	 *	@remarks	Use the Osp::Locale namespace for a string of the locale-specific representation.
	 *	
	 */
	String ToString(void) const;


	/**
	 * Parses the specified string representing the date and time value.
	 * 
	 * @since	 		1.0
	 * @return		An error code
	 * @param[in]	str		A string representing the date and time value
	 * @param[out]	dt		The result of the method
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		The specified string is in an invalid format.
	 * @exception	E_OUT_OF_RANGE			The resulting value of %DateTime is greater than the value returned by GetMaxValue(void) 
	 *									    or is less than the value returned by GetMinValue(), or
	 *									    the specified string contains an invalid value (For example, the day is @c 31 when the month is @c 2).
	 * @remarks		The format of the string is "mm/dd/yyyy hh:mm:ss".
	 */
	static result Parse(const String& str, DateTime& dt);


// Accessors
public:
	/** 
	 *	Gets the year of the current instance of %DateTime.
	 *
	 *	@since	 1.0
	 *	@return	 An integer value indicating the year of the current instance of %DateTime
	 */
	int GetYear(void) const;


	/** 
	 *	Gets the month of the current instance of %DateTime.
	 *
	 *	@since	  1.0
	 *	@return		An integer value indicating the month of the current instance of %DateTime
	 */
	int GetMonth(void) const;


	/** 
	 *	Gets the day of the current instance of %DateTime.
	 *
	 *	@since	  1.0
	 *	@return		An integer value indicating the day of the current instance of %DateTime
	 */
	int GetDay(void) const;


	/** 
	 *	Gets the hour of the current instance of %DateTime.
	 *
	 *	@since	  1.0
	 *	@return		An integer value indicating the hour of the current instance of %DateTime
	 */
	int GetHour(void) const;


	/** 
	 *	Gets the minute of the current instance of %DateTime.
	 *
	 *	@since	  1.0
	 *	@return		An integer value indicating the minute of the current instance of %DateTime
	 */
	int GetMinute(void) const;


	/** 
	 *	Gets the second of the current instance of %DateTime.
	 *
	 *	@since	  1.0
	 *	@return		An integer value indicating the second of the current instance of %DateTime
	 */
	int GetSecond(void) const;


	/** 
	 *	Gets the number of milliseconds (in TimeSpan) since the minimum date (GetMinValue(void)).
	 *
	 *	@since	  1.0
	 *	@return		An instance of %TimeSpan
	 *	@remarks	The returned instance is the time since the value returned by %GetMinValue(void).
	 */
	TimeSpan GetTime(void) const;


	/** 
	 *	Gets the maximum allowable value for date and time (For example: "December 31 9999 23:59:59").
	 *
	 *	@since	  1.0
	 *	@return		An instance of %DateTime
	 */
	static const DateTime& GetMaxValue(void);


	/** 
	 *	Gets the minimum allowable value for date and time (For example: "January 1 1 00:00:00").
	 *
	 *	@since	  1.0
	 *	@return		An instance of %DateTime
	 */
	static const DateTime& GetMinValue(void);


// Inquiry
public:
	/** 
	 *	Checks whether the year represented by the current instance of %DateTime is a leap year.
	 *
	 *	@since	  1.0
	 *	@return		@c true if the year represented by the current instance of %DateTime is a leap year, @n
	 *				else @c false
	 */
	bool IsLeapYear(void) const;


	/** 
	 *	Checks whether the specified year is a leap year.
	 *
	 *	@since	  1.0
	 *	@return		@c true if the specified year is a leap year, @n
	 *				else @c false
	 *	@param[in]	year	The year
	 */
	static bool IsLeapYear(int year);


// Lifecycle
private:
	DateTime(int year, int month, int day, int hour, int minute, int second);



// Operations
private:

	// Counts the number of leap days up to January 1st of a given year.
	int countLeapYear(int year) const
	{
		return (int) ((year-1)/4 - (year-1)/100 + (year-1)/400);		

	}

	// Count the number of days up to January 1st of the specified year.
	int countDays(int year) const
	{
		return (int) ((year-1)*365 + countLeapYear(year));
	}

	// Counts the number of years spanned by a given number of days
	int countYears(int day) const
	{
		double year = (day - countLeapYear(day/365)) / 365.0;

		if (year == 0)
			return 1;
		else
			return (year != (int)year ? 1 + (int)year : (int)year);
	}

	result ConvertSecondsToDate(long long seconds, TmDateTime* pDateTime);
	long long ConvertDateToSeconds(const TmDateTime* pDateTime) const;


// Attribute
private:
	TmDateTime __dateTime;


private:
	friend class DateTimeEx;
	class DateTimeEx* __pDateTimeEx;
};
};};// Osp::Base 
#endif// _FBASE_DATE_TIME_H_
