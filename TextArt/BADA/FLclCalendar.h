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
 * @file		FLclCalendar.h 
 * @brief		This is the header file for the %Calendar class.
 *
 * This header file contains the declarations of the %Calendar class.
 *  
 */
#ifndef	_FLCL_CALENDAR_H_
#define	_FLCL_CALENDAR_H_

// Includes
#include "FLclLocale.h"
#include "FBase.h"
#include "FLclConfig.h"
#include "FLclTimeZone.h"


namespace Osp { namespace Locales {
/**
 * @class		Calendar
 * @brief		This class provides methods for displaying a calendar.
 * @since		1.0
 *
 * The %Calendar class is an abstract base class for displaying a calendar. It is used to convert between the Osp::Base::DateTime instance and a set of time fields, such as TIME_FIELD_YEAR, TIME_FIELD_MONTH, and TIME_FIELD_DAY_OF_MONTH.
 * Subclasses of %Calendar interpret Osp::Base::DateTime according to the rules of a specific calendar system. GregorianCalendar is commonly used.
 *
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/calendar.htm">Calendar</a>.
 *
 * @see Osp::Locales::TimeZone
 *
 * The following example demonstrates how to set or add the time field to a %Calendar instance.
 *
 @code
 *
 #include <FBase.h>
 #include <FLocales.h>

 using namespace Osp::Base;
 using namespace Osp::Locales;

 void
 MyClass::CalendarExample(void)
 {
	int offset = 60;
	String timeZoneName(L"Europe/Paris");
	TimeZone timeZone(offset, timeZoneName);

	Calendar* pCalendar = Calendar::CreateInstanceN(timeZone, CALENDAR_GREGORIAN);
	pCalendar->SetTime(2009,5,25);

	// Increase one day. The date will be 2009/5/26
	pCalendar->AddTimeField(TIME_FIELD_DAY_OF_MONTH, 1);

	// Decrease two months. The date will be 2009/3/26
	pCalendar->AddTimeField(TIME_FIELD_MONTH, -2);

	delete pCalendar;
 }
 @endcode
 */

/**
* @enum TimeField
* Defines the time fields for date and time. @n
* This enumeration is used in %Calendar.
*
* @since		1.0
*/
enum TimeField
{
	TIME_FIELD_ERA,							/**< Era : 0 - BC, 1 - AD */				// Example: 0..1
	TIME_FIELD_YEAR,						/**< Year : 1-based */						// Example: 1..big number
	TIME_FIELD_MONTH,						/**< Month : 1-based (1~12)*/				// Example: 1..12
	TIME_FIELD_WEEK_OF_YEAR,				/**< Week of Year : 1-based (1~53) */		// Example: 1..53
	TIME_FIELD_WEEK_OF_MONTH,				/**< Week of Month : 1-based (1~5) */		// Example: 1..5
	TIME_FIELD_DAY_OF_MONTH,				/**< Date : 1-based (1~31) */				// Example: 1..31
	TIME_FIELD_DAY_OF_YEAR,					/**< Day of Year : 1-based (1~365) */		// Example: 1..365
	TIME_FIELD_DAY_OF_WEEK,					/**< Day of Week : 1-based (1~7) */			// Example: 1..7
	TIME_FIELD_DAY_OF_WEEK_IN_MONTH,		/**< Day of Week in Month : 1-based (1~5)*/	// Example: 1..5, may be specified as -1
	TIME_FIELD_AM_PM,						/**< AmPm : 0-based */						// Example: 0..1
	TIME_FIELD_HOUR,						/**< Hour : 0-based (0~11) */				// Example: 0..11
	TIME_FIELD_HOUR_OF_DAY,					/**< Hour of Day : 0-based (0~23) */		// Example: 0..23
	TIME_FIELD_MINUTE,						/**< Minute : 0-based (0~59) */				// Example: 0..59
	TIME_FIELD_SECOND,						/**< Second : 0-based (0~59) */				// Example: 0..59
	TIME_FIELD_MILLISECOND,					/**< Millisecond : 0-based (0~999) */		// Example: 0..999
	TIME_FIELD_ZONE_OFFSET,					/**< Time Zone Offset : GMT-12 ~ GMT+12 */	// Example: -720..720
	TIME_FIELD_DST_OFFSET,					/**< Daylight Saving Offset */				// Example: 0 or 60
	TIME_FIELD_YEAR_WOY,					/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	TIME_FIELD_DOW_LOCAL,					/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	TIME_FIELD_EXTENDED_YEAR,				/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	TIME_FIELD_JULIAN_DAY,					/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	TIME_FIELD_MILLISECONDS_IN_DAY,		/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	TIME_FIELD_FIELD_COUNT				/**< The number of time field */
};

class _EXPORT_LOCALES_ Calendar :
	public Osp::Base::Object
{
	////////////////////////////////////////////////////////////////////////////////////////////////
	// Enumeration

protected:
	/**
	* @enum AmPm
	* Defines the AM/PM mode. @n
	* This is a.m./p.m. The indexing is 0-based.
	*
	* @since		1.0
	*/
	enum AmPm
	{
		AM,	/**< The time is in A.M */
		PM	/**< The time is in P.M */
	};

	/**
	* @enum	CalendarLimitType
	* Defines calendar limitations.
	*
	* @since		1.0
	*/
	enum CalendarLimitType
	{
		CALENDAR_LIMIT_MINIMUM = 0,				/**< The minimum limit */
		CALENDAR_LIMIT_GREATEST_MINIMUM,	/**< The greatest minimum limit */
		CALENDAR_LIMIT_LEAST_MAXIMUM,			/**< The least maximum limit */
		CALENDAR_LIMIT_MAXIMUM,					/**< The maximum limit */
		CALENDAR_LIMIT_COUNT							/**< The number of limit type */
	};

	/**
	* @enum	StampValue
	* Defines the stamp value.
	*
	* @since		1.0
	*/
	enum StampValue
	{
		UNSET = 0,				/**< Unset */
		COMPUTED,				/**< Computed */
		MINIMUM_USER_STAMP		/**< Minimum user stamp */
	};

private:
	enum
	{
		RESOLVE_STOP = -1,
		RESOLVE_REMAP = 32
	};

	////////////////////////////////////////////////////////////////////////////////////////////////
	// Calendar class lifecycle
protected:
	/**
	 * This is the default constructor for this class. @n
	 * This creates an uninitialized instance of the class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly
	 *				to initialize this instance.
	 * @see				Construct()
	 */
	Calendar(void);


	/**
	 * Initializes this instance of %Calendar.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 */
	virtual result Construct(void);


	/**
	 * Initializes this instance of %Calendar with the specified parameter.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		calendar					The Calendar instance to copy
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 *
	 */
	virtual result Construct(const Calendar& calendar);


	/**
	 * Initializes this instance of %Calendar with the specified @c time zone and @c locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		timezone					An instance of TimeZone
	 * @param[in]		locale						An instance of Locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 */
	result Construct(const Osp::Locales::TimeZone& timezone, const Locale& locale);


public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
 	 */
	virtual ~Calendar(void);

	// Operations
public:
	/**
	* Adds the specified amount to the given time field, based on the calendar rules. @n
	* It is equivalent to calling SetTimeField(field, GetTimeField(field)+amount) with two adjustments. @n
	*
	* @b Add @b Rule1: The value of the time field @c field after the call minus the value of the field
	* before the call is delta modulo any overflow that has occurred in the field.
	* Overflow occurs when a time field value exceeds its range and, as a result, the next larger field
	* is incremented or decremented and the field value is adjusted back into its range. @n
	*
	* @b Add @b Rule2: If a smaller field is expected to be invariant, but it is impossible for it to be
	* equal to its prior value because of changes in its minimum or maximum value after the time field @c field
	* is changed, then its value is adjusted to be as close as possible to its expected value. @n
	*
	* A smaller field represents a smaller unit of time. TIME_FIELD_HOUR is a smaller field than TIME_FIELD_DAY_OF_MONTH.
	* No adjustment is made to smaller fields that are not expected to be invariant.
	* The calendar system determines what fields are expected to be invariant.
	*
	* In addition, this method forces recomputation of the calendar's milliseconds and
	* all time fields immediately. @n
	* 
	* For example, consider a GregorianCalendar set to Oct. 31. 2004.
	* Calling AddTimeField(TIME_FIELD_MONTH, 13) sets the calendar to Nov. 30. 2005. @n
	* The TIME_FIELD_MONTH field is set to NOVEMBER by @b Rule1, since adding 13 months to October gives the
	* November of the next year.
	* Since, the TIME_FIELD_DAY_OF_MONTH cannot be 31 in November in a GregorianCalendar, the TIME_FIELD_DAY_OF_MONTH is set to 30 by @b Rule2.
	*
	* @since		1.0
	* @return			An error code
	* @param[in]		field						The time field
	* @param[in]		amount						The amount to add
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has not been constructed as yet or a time field value is invalid.
	*/
	virtual result AddTimeField(TimeField field, int amount) = 0;


	/**
	* Compares the current instance of %Calendar with the specified instance.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		otherCalendar				The instance of Calendar to be compared
	* @param[out]		after						Set to @c true if the current instance of Calendar is after the specified instance of Calendar, @n
	*												else @c false
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has not been constructed as yet or a time field value is invalid.
	* @exception		E_OUT_OF_RANGE				The value of the argument is outside the valid range defined by the method.
	*/
	result After(const Calendar& otherCalendar, bool& after);


	/**
	* Compares the current instance of %Calendar with the specified instance.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		otherCalendar				The instance of Calendar to be compared
	* @param[out]		before						Set to @c true if the current instance of Calendar is before the specified instance of Calendar, @n
	*												else @c false
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has not been constructed as yet or a time field value is invalid.
	* @exception		E_OUT_OF_RANGE				The value of the argument is outside the valid range defined by the method.
	*/
	result Before(const Calendar& otherCalendar, bool& before);


	/**
	* Clears all the time fields and sets it to @c 0. @n
	* Zero is not the default value for each field. It means the field is cleared.
	*
	* @since				1.0
	* @return				An error code
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has already been constructed.
	*/
	result Clear(void);


	/**
	* Clears the specified time field and sets it to @c 0. @n
	* Zero is not the default value for each field. It means the field is cleared.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		field						The time field to be cleared
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has already been constructed.
	*/
	result Clear(TimeField field);


	/**
	* Compares the current instance of %Calendar with the specified instance.
	*
	* @since			1.0
	* @return			@c true if the value of the current instance of Calendar is equal to the specified instance, @n
	*					else @c false
	* @param[in]	otherCalendar				An instance of Calendar to be compared
	*/
	bool Equals(const Calendar& otherCalendar);


	/**
	* Adds the specified @c amount to the specified time field without changing the larger fields (for example, TIME_FIELD_YEAR field cannot be changed when the input field is TIME_FIELD_MONTH). @n
	* If the specified @c amount is negative, the @c amount value is deducted from the specified time field value.
	* In this method, the time field of this instance is operated upon. If the value of the specified @c field goes out of range, E_OUT_OF_RANGE is returned.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		field							The time field to be rolled
	* @param[in]		amount							The amount to add to the time field
	* @exception		E_SUCCESS						The method is successful.
	* @exception		E_INVALID_STATE					This instance has not been constructed as yet or a time field value is invalid.
	* @exception		E_INVALID_ARG					The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	* @exception		E_OUT_OF_RANGE		 A time field or its value is out of range.
	*/
	virtual result Roll(TimeField field, int amount);


	/**
	* Sets the specified time field with the specified value. @n
	* This sets an internal member variable to indicate that the field has been changed.
	* Although the time field is changed, the milliseconds of %Calendar are not recomputed
	* until GetTimeField(TimeField field), GetTime(void), or GetTimeInMillisec(long long& ms) is called.
	* Thus, even if you call this method several times, unnecessary multiple computations are not triggered. @n
	* 
	*
	* As a result of changing a field using SetTimeField(TimeField, int), other fields may also change
	* depending on the field, the field value, and the calendar system. @n
	*
	* For example, consider a GregorianCalendar set to Oct. 31. 2004.
	* Calling SetTimeField(TIME_FIELD_MONTH, NOVEMBER) sets the calendar to Nov. 31. 2004. @n
	* But, if you call GetTime(void), then Dec. 1. 2004 is returned because Nov. 31. 2004 does not exist.
	* However, a call to SetTimeField(TIME_FIELD_MONTH, SEPTEMBER) before a call to GetTime(void) sets the calendar
	* to Sep. 30. 2004, since no recomputation has occurred after the first call to SetTimeField().
	*
	* The value of field is not affected by it being local time or UTC time.
	* The value is only overwritten.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		field					The time field to set
	* @param[in]		value					The value to be set
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_OUT_OF_RANGE			A time field or its value is out of range in lenient mode.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception		E_INVALID_ARG			The specified @c field is invalid.
	*/
	result SetTimeField(TimeField field, int value);


	/**
	* Sets the first day of the week.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		dayOfWeek				The value to be set as the first day of the week
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception		E_INVALID_ARG			The specified @c dayOfWeek is invalid.
	*/
	result SetFirstDayOfWeek(DayOfWeek dayOfWeek);


	/**
	* Enables or disables the leniency of date and time interpretations.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		lenient					Set to @c true if the date and time interpretation is set to lenient, @n
	*											else @c false
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	*/
	result SetLenient(bool lenient);


	/**
	* Sets the minimal days required in the first week.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		value					The minimal days required in the first week
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	*/
	result SetMinDaysInFirstWeek(short value);


	/**
	* Sets the value of year, month, day, hour, minute, and seconds. @n
	* The date and time are local time.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		year					The value to be set for year
	* @param[in]		month					The value to be set for month @n
	*											The indexing is 1-based. Therefore, 1 means January.
	* @param[in]		day						The value to be set for day
	* @param[in]		hour					The value to be set for hour
	* @param[in]		minute					The value to be set for minute
	* @param[in]		second					The value to be set for second
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception		E_OUT_OF_RANGE			 A time field or its value is out of range in lenient mode.
	*/
	result SetTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);


	/**
	* Sets the calendar's current time with the specified Osp::Base::DateTime.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		dateTime				The DateTime instance to set
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	* @remarks			The time specified is the local time.
	* @see					GetTime()
	*/
	result SetTime(const Osp::Base::DateTime& dateTime);


	/**
	* Sets the current time of this %Calendar instance with the specified value.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		millisec				The new time in milliseconds from the starting day (Jan. 1. 1.)
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception		E_OUT_OF_RANGE			A time field or its value is out of range.
	*/
	result SetTimeInMillisec(long long millisec);


	/**
	* Sets the time zone of the calendar to the specified time zone.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompCalendarSetTimeZonePage "here".
	*
	* @return			An error code
	* @param[in]	timeZone				The time zone to set
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @see				GetTimeZone()
	*/
	result SetTimeZone(const TimeZone& timeZone);


	/**
	* @page				CompCalendarSetTimeZonePage Compatibility for SetTimeZone()
	* @section			CompCalendarSetTimeZonePageIssueSection Issues
	*					Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*
	*	-# If the SetTimeZone() method is being used for setting the time zone,
  	*	the time which is already set using the SetTimeField() or SetTime() method changes accordingly.
	*	-# If the time zone of Calendar uses the SetTimeZone() method and the 
	*	SetTimeField() or SetTime() method is used to change the hour or minute field, improper values are set.
	*	However, other fields such as year, month, and day work as expected.
	*
	* @section			CompCalendarSetTimeZonePageSolutionSection Resolutions
	*
	* The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*/


	// Accessors
	/**
	 * Gets the actual maximum value that the specified field can have, given the current date. @n
	 * For example, if the current date is "Feb. 10. 2004" and the time field specified is TIME_FIELD_DAY_OF_MONTH, then the actual
	 * maximum value for this time field is 29.
	 *
	 * @since					1.0
	 * @return				An integer value indicating the actual maximum value, @n
	 *						else @c -1 if Construct() is not called
	 * @param[in]			field		The time field
	 */
	virtual int GetActualMaxTimeField(TimeField field) const;


	/**
	 * Gets the actual minimum value that the specified time field can have, given the current date. @n
	 * For the Gregorian calendar, this is the same as GetMinTimeField(TimeField field) and
	 * GetGreatestMinTimeField(TimeField field).
	 *
	 * @since					1.0
	 * @return				An integer value indicating the actual minimum value, @n
	 *						else @c -1 if Construct() is not called
	 * @param[in]			field		The time field
	 */
	virtual int GetActualMinTimeField(TimeField field) const;


	/**
	* Gets the value of the first day of the week. @n
	* For example, in USA, the first day of the week is SUNDAY. But, it is MONDAY in France.
	*
	* @since				1.0
	* @return				An integer value indicating the first day of the week, @n
	*						else @c -1 if Construct() is not called
	*/
	int GetFirstDayOfWeek(void) const;


	/**
	* Gets the greatest minimum value that the specified time field could have.
	*
	* @since				1.0
	* @return				An integer value indicating the greatest minimum value for the specified time field, @n
	*						else @c -1 if Construct() is not called
	* @param[in]			field		The time field
	*/
	virtual int GetGreatestMinTimeField(TimeField field) const;


	/**
	* Gets the least maximum value that the specified time field could have.
	*
	* @since				1.0
	* @return				An integer value indicating the least maximum value for the specified time field, @n
	*						else @c -1 if Construct() is not called
	* @param[in]			field		The time field
	*/
	virtual int GetLeastMaxTimeField(TimeField field) const;


	/**
	* Gets the maximum value that the specified time field could have.
	*
	* @since				1.0
	* @return				An integer value indicating the maximum value for the specified time field, @n
	*						else @c -1 if the method fails
	* @param[in]			field		The time field
	*/
	virtual int GetMaxTimeField(TimeField field) const;


	/**
	* Gets the minimum value that the specified time field could have.
	*
	* @since				1.0
	* @return				An integer value indicating the minimum value for the specified time field, @n
	*						else @c -1 if the method fails
	* @param[in]			field		The time field
	*/
	virtual int GetMinTimeField(TimeField field) const;


	/**
	* Gets the minimum number of days required in the first week of the year. @n
	* For example, if the first week is defined as the one that contains the first day of
	* the first month of a year, this method returns 1.
	*
	* @since				1.0
	* @return				An integer value indicating the minimum number of days required in the first week, @n
	*						else @c -1 if Construct() is not called
	*/
	int GetMinDaysInFirstWeek(void) const;


	/**
	* Gets the date and time of the current instance of %Calendar.
	*
	* @since				1.0
	* @return				An instance of DateTime with the current time in local time @n
	*						If Construct() is not called, the Osp::Base::DateTime that has the minimum value is returned.
	* @remarks			The time specified is local time.
	* @see					SetTime()
	*/
	Osp::Base::DateTime GetTime(void) const;


	/**
	* Gets the value of the specified time field. @n
	* Recalculates the specified time field value if the time value has been changed by a call to SetTime(DateTime dt).
	* Returns zero for unset fields if any fields have been explicitly set by a call to SetTimeField(TimeField, int).
	*
	* @since				1.0
	* @return				An integer value indicating the value of the specified time field, @n
	*						else @c 0 if the field is not set or
	*						@c -1 if Construct() is not called
	* @param[in]		field		The given time field
	* @remarks			This method is semantically const, but may alter the instance in memory.
	*						To force a recomputation of all fields regardless of the previous state, call Complete().
	*/
	int GetTimeField(TimeField field) const;


	/**
	* Gets the current time of the instance in the @c long format.
	*
	* @since					1.0
	* @return					An error code
	* @param[out]			millisec						The current time in milliseconds from starting day (Jan. 1. 1.)
	* @exception			E_SUCCESS						The method is successful.
	* @exception			E_INVALID_STATE					This instance has not been constructed as yet or a time field value is invalid.
	* @exception			E_OUT_OF_RANGE					The value of the argument is outside the valid range defined by the method.
	*/
	result GetTimeInMillisec(long long& millisec) const;


	/**
	* Gets a reference to the time zone owned by this instance of %Calendar.
	*
	* @since				1.0
	* @return				The TimeZone instance associated with the current instance of Calendar. @n
	*						If Construct() is not called, the name of time zone is an empty string and its offset is -1.
	* @remarks			The returned reference is valid only until the SetTimeZone() method is called or this instance of Calendar is destroyed.
	* @see					SetTimeZone()
	*/
	TimeZone GetTimeZone(void) const;


	/**
	* Gets the calendar type of the current instance of %Calendar.
	*
	* @since				1.0
	* @return				An instance of CalendarType representing the calendar type of the current instance of Calendar. @n
	*						For example, CALENDAR_GREGORIAN or CALENDAR_CHINESE.
	*/
	virtual CalendarType GetType(void) const = 0;


	// Inquiry
	/**
	* Checks whether the current date for the instance of %Calendar is in Daylight Saving Time (DST).
	*
	* @since					1.0
	* @return					An error code
	* @param[out]			isInDst			Set to @c true if the current date is in DST, @n
	*										else @c false
	* @exception			E_SUCCESS						The method is successful.
	* @exception			E_INVALID_STATE					This instance has not been constructed as yet or a time field value is invalid.
	* @exception			E_OUT_OF_RANGE					A time field or its value is out of range.
	* @remarks				In this method, the time fields of the current instance are calculated. If the value of the time fields go out of range, the E_OUT_OF_RANGE exception is returned.
	*/
	virtual result IsInDst(bool& isInDst) const = 0;


	/**
	* Checks whether the date and time interpretation is lenient.
	*
	* @since			1.0
	* @return			@c true if the date and time interpretation is set to lenient, @n
	*					else @c false
	*/
	bool IsLenient(void) const;


	/**
	* Checks whether the specified time field has a value.
	*
	* @since				1.0
	* @return				@c true if the specified time field has a value, @n
	*					else @c false
	* @param[in]		field		The time field
	*/
	bool IsSet(TimeField field) const;


	// Static Method
public:
	/**
	* Creates an instance of %Calendar of the specified type with the GMT time zone and locale.
	*
	* @since			1.0
	* @return			A pointer to the created Calendar instance, @n
	*					else @c null if the method fails
	* @param[in]		calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remark			The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(CalendarType calendarType = CALENDAR_GREGORIAN);



	/**
	* Creates an instance of %Calendar of the specified type with the specified time zone and the system locale.
	*
	* @since			1.0
	* @return			A pointer to the created Calendar instance, @n
	*					else @c null if the method fails
	* @param[in]		timeZone			An instance of TimeZone
	* @param[in]		calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remark			The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const TimeZone& timeZone, CalendarType calendarType = CALENDAR_GREGORIAN);


	/**
	* Creates an instance of %Calendar of the specified type with the specified @c locale and the GMT time zone.
	*
	* @since			1.0
	* @return			A pointer to the created Calendar instance, @n
	*					else @c null if the method fails
	* @param[in]		locale				The locale for whose country the Calendar instance is needed
	* @param[in]		calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	* @remark			The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);


	/**
	* Creates an instance of %Calendar of the specified type with the specified time zone and locale.
	*
	* @since				1.0
	* @return				A pointer to the created Calendar instance, @n
	*					else @c null if the method fails
	* @param[in]		timeZone			An instance of TimeZone
	* @param[in]		locale				The locale for whose country the Calendar instance is needed
	* @param[in]		calendarType		The type of calendar @n
	*										Default calendar is the Gregorian calendar (CALENDAR_GREGORIAN).
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_SYSTEM			A system error has occurred.
	* @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	* @remark				The specific error code can be accessed using the GetLastResult() method.
	*/
	static Calendar* CreateInstanceN(const TimeZone& timeZone, const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);


	// Constants
public:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Millisecond constants for one day.
	 *
	 * @since	1.0
	 */
	static const int ONE_DAY_IN_MILLISEC = 86400000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Millisecond constants for one hour.
	 *
	 * @since	1.0
	 */	
	static const int ONE_HOUR_IN_MILLISEC = 60 * 60 * 1000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Millisecond constants for one minute.
	 *
	 * @since	1.0
	 */
	static const int ONE_MINUTE_IN_MILLISEC = 60000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Millisecond constants for one second.
	 *
	 * @since	1.0
	 */
	static const int ONE_SECOND_IN_MILLISEC = 1000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Millisecond constants for one week.
	 *
	 * @since	1.0
	 */
	static const long long ONE_WEEK_IN_MILLISEC = 7 * 86400000;


protected:
	/**
	* Adds or subtracts a single unit of time on a given time field without changing larger fields. @n
	* When rolling on the MONTH field, other fields such as DATE field might conflict
	* and needs to be changed.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		field							The time field to change
	* @param[in]		up								Set to @c true if the time field should be rolled upwards, @n
	*													else @c false
	* @exception		E_SUCCESS						The method is successful.
	* @exception		E_INVALID_STATE					This instance has not been constructed as yet, or an internal time field value is invalid.
	* @exception		E_INVALID_ARG					The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	* @exception		E_OUT_OF_RANGE		 A time field or its value is out of range. @n
	*					In this method, the time fields of this instance is calculated.
	*					At that time, if the value of the time fields is out of range, this exception is returned.
	*/
	virtual result RollWithSingleUnit(TimeField field, bool up) = 0;

	/**
	 * Checks whether the current instance of %Calendar is equivalent to the specified instance of %Calendar.
	 *
	 * @since			1.0
	 * @return		@c true if the current instance of Calendar is equivalent to the specified Calendar instance, @n
	 *				else @c false
	 * @param[in]	calendar		The instance of Calendar to compare with
	 * @remarks		If the specified Calendar instance is equivalent to the current instance, the two instances behave
	 *				exactly the same, but they may be set to different times.
	 */
	virtual bool IsEquivalentTo(const Calendar& calendar) const;


	// Operations
	/**
	* Recomputes the current time from the set time fields, and then fills in any unset time fields.
	*
	* @since					1.0
	* @return					An error code
	* @exception			E_SUCCESS					The method is successful.
	* @exception			E_INVALID_STATE				A value of internal time field is invalid.
	* @exception			E_OUT_OF_RANGE	A time field or its value is out of range. @n
	*						In this method, the time fields of the current instance are calculated. If the value of the time fields go out of range, the E_OUT_OF_RANGE exception is returned.
	*/
	result Complete(void);


	/**
	* Converts the current millisecond time value to TimeField. @n
	* This allows synching up the time field values with a new time that is set for the calendar.
	*
	* @since					1.0
	* @return					An error code
	* @exception			E_SUCCESS					The method is successful.
	* @exception			E_OUT_OF_RANGE	The time fields contain an invalid value. @n
	*						In this method, the time fields of the current instance are calculated. If the value of the time fields go out of range, the E_OUT_OF_RANGE exception is returned.
	*/
	virtual result ComputeTimeFields(void) = 0;


	/**
	* Converts the current values of time field to the millisecond time value.
	*
	* @since					1.0
	* @return					An error code
	* @exception			E_SUCCESS					The method is successful.
	* @exception			E_INVALID_STATE				A value of internal time field is invalid.
	*/
	virtual result ComputeTime(void) = 0;


	// Accessors
	/**
	* Gets the limit of the specified time field.
	*
	* @since					1.0
	* @return					An integer value indicating the limit of the time field
	* @param[in]			field						The time field
	* @param[in]			limitType					The type of limit
	*/
	int GetLimit(TimeField field, CalendarLimitType limitType) const;


	/**
	* Gets the length of the specified month.
	*
	* @since					1.0
	* @return					An integer value indicating the number of days in the specified month
	* @param[in]			extendedYear				An extended year
	* @param[in]			month						A month
	*/
	virtual int GetMonthLength(int extendedYear, int month) const = 0;


	/**
	* Defines limits of different types. @n
	* Derived classes must implement this method for the following fields:
	* TIME_FIELD_ERA, TIME_FIELD_YEAR, TIME_FIELD_MONTH, TIME_FIELD_WEEK_OF_YEAR, TIME_FIELD_WEEK_OF_MONTH,
	* TIME_FIELD_DAY_OF_MONTH, TIME_FIELD_DAY_OF_YEAR, TIME_FIELD_DAY_OF_WEEK_IN_MONTH, TIME_FIELD_YEAR_WOY,
	* TIME_FIELD_EXTENDED_YEAR.
	*
	* @since					1.0
	* @return					The limit of the specified field
	* @param[in]			field						The time field
	* @param[in]			limitType					The type of limit
	*/
	virtual int HandleGetLimit(TimeField field, CalendarLimitType limitType) const = 0;


	/**
	* @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	* Returns the value for a given time field.
	*
	* @since					1.0
	* @return					The value for a given time field
	* @param[in]			field						The time field
	* @remarks				Subclasses can use this method to get the value of time field without re-computation of time.
	*/
	int InternalGet(TimeField field) const;


	/**
	* @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	* Returns the internal time without recomputation.
	*
	* @since					1.0
	* @return				The internal time without recomputation
	*/
	long long InternalGetTime(void) const;


	/**
	* @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	* Replaces the field to a given value.
	*
	* @since					1.0
	* @param[in]			field						The specified field
	* @param[in]			value						The value
	*/
	void InternalSet(TimeField field, int value);


	/**
	* @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	* Creates and returns a polymorphic copy of this calendar.
	*
	* @since					1.0
	* @return    A polymorphic copy of this calendar
	*/
	virtual Osp::Locales::Calendar* CloneN(void) const = 0;


	/**
	* @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	* Sets fields to compute.
	*
	* @since					1.0
	* @param[in]			fieldMask					The field mask
	*/
	void SetFieldsComputed(int fieldMask);

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The field values for the currently set time for this calendar
	 *
	 * @since 1.0
	 */
	int __timeFields[TIME_FIELD_FIELD_COUNT];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Pseudo-time-stamps which specify when each field was set.
	 * There are two special values - UNSET and INTERNALLY_SET.
	 *
	 * @since 1.0
	 */
	int __stamp[TIME_FIELD_FIELD_COUNT];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The flags which tell if a specified time field for the calendar is set.
	 *
	 * @since 1.0
	 */
	bool __isSet[TIME_FIELD_FIELD_COUNT];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	long long __time; // UTC time

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	Osp::Locales::TimeZone __timeZone;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	bool __isTimeSet;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	bool __areFieldsSet;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	bool __areAllFieldsSet;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	int __nextStamp;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	bool __isLenient;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	bool __isConstructed;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int ERA_MASK		= (1 << TIME_FIELD_ERA);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int YEAR_MASK		= (1 << TIME_FIELD_YEAR);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int MONTH_MASK		= (1 << TIME_FIELD_MONTH);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int WEEK_OF_YEAR_MASK	= (1 << TIME_FIELD_WEEK_OF_YEAR);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int WEEK_OF_MONTH_MASK	= (1 << TIME_FIELD_WEEK_OF_MONTH);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int DAY_OF_MONTH_MASK	= (1 << TIME_FIELD_DAY_OF_MONTH);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int DAY_OF_YEAR_MASK	= (1 << TIME_FIELD_DAY_OF_YEAR);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int DAY_OF_WEEK_MASK	= (1 << TIME_FIELD_DAY_OF_WEEK);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int DAY_OF_WEEK_IN_MONTH_MASK	= (1 << TIME_FIELD_DAY_OF_WEEK_IN_MONTH);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int AM_PM_MASK		= (1 << TIME_FIELD_AM_PM);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int HOUR_MASK		= (1 << TIME_FIELD_HOUR);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int HOUR_OF_DAY_MASK	= (1 << TIME_FIELD_HOUR_OF_DAY);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int MINUTE_MASK	= (1 << TIME_FIELD_MINUTE);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int SECOND_MASK	= (1 << TIME_FIELD_SECOND);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int MILLISECOND_MASK	= (1 << TIME_FIELD_MILLISECOND);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int ZONE_OFFSET_MASK	= (1 << TIME_FIELD_ZONE_OFFSET);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int DST_OFFSET_MASK	= (1 << TIME_FIELD_DST_OFFSET);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	static const int ALL_FIELDS = (1 << TIME_FIELD_FIELD_COUNT) - 1;

private:
	// two phase construction idiom.
	Calendar(const Calendar& calendar);
	Calendar& operator=(const Calendar& calendar);

	/**
	* Adjusts a value of time field.	// This function is not used anywhere.
	*/
	void PinField(TimeField field);


	/**
	* Recomputes the time and updates the status of time fields - __isTimeSet and __areFieldsSet.
	* Must be called when __isTimeSet is @c false.
	*
	* @return				An error code
	* @exception			E_SUCCESS						The method is successful.
	* @exception			E_INVALID_STATE					A value of internal time field is invalid.
	* @exception			E_OUT_OF_RANGE					A time field or its value is out of range.
	*					In this method, the time fields of this instance are calculated.
	*					At that time, if the value of the time fields is out of range, this exception is returned.
	*/
	result UpdateTime(void);


	/**
	* Replaces the @c firstDayOfWeek and the @c minimalDaysInFirstWeek.
	*
	* @param[in]			locale		A given locale
	*/
	void SetWeekCountData(const Locale& locale);

	void AdjustStamp(void);


// Attributes
private:

	DayOfWeek __firstDayOfWeek; // locale dependent.
	short __minDaysInFirstWeek; // locale dependent.


private:
	friend class CalendarEx;
	class CalendarEx* __pCalendarEx;
}; // Calendar

};  };// Locale Osp

#endif//_FLCL_CALENDAR_H_
