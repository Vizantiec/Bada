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
 * @file		FLclGregorianCalendar.h 
 * @brief		This is the header file for the %GregorianCalendar class.
 *
 * This header file contains the declarations of the %GregorianCalendar class. 
 *  
 */
#ifndef	_FLCL_GREGORIAN_CALENDAR_H_
#define	_FLCL_GREGORIAN_CALENDAR_H_

#include "FLclCalendar.h"
#include "FLclLocale.h"
#include "FLclTimeZone.h"
#include "FBase.h"
#include "FLclConfig.h"

namespace Osp { namespace Locales {

/**
 * @class		GregorianCalendar
 * @brief		This class is a concrete subclass of calendar and provides the Gregorian calendar that is the most commonly used standard calendar.
 * @since		1.0
 *
 * The %GregorianCalendar class is a concrete subclass of calendar and provides the Gregorian calendar that is the most commonly used standard calendar.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/gregorian_calendar.htm">Gregorian Calendar</a>.
 *
 * @see Osp::Locales::Locale, Osp::Locales::TimeZone
 *
 * The following example demonstrates how to use the %GregorianCalendar class.
 * @code
 #include <FBase.h>
 #include <FLocales.h>

 using namespace Osp::Base;
 using namespace Osp::Locales;
 
 void
 MyClass::GregorianCalendarExample(void)
 {
	 Calendar* pGregorianCalendar = Calendar::CreateInstanceN(CALENDAR_GREGORIAN);
	 
	 pGregorianCalendar->SetTimeField(TIME_FIELD_YEAR, 2005);
	 pGregorianCalendar->SetTimeField(TIME_FIELD_MONTH, JANUARY);
	 pGregorianCalendar->SetTimeField(TIME_FIELD_DAY_OF_MONTH, 3);
	 
	 int dayOfWeek = pGregorianCalendar->GetTimeField(TIME_FIELD_DAY_OF_WEEK);// It is Monday.
	 
	 pGregorianCalendar->Clear();
	 pGregorianCalendar->SetTimeField(TIME_FIELD_YEAR, 1972);
	 pGregorianCalendar->SetTimeField(TIME_FIELD_MONTH, OCTOBER);
	 pGregorianCalendar->SetTimeField(TIME_FIELD_DAY_OF_MONTH, 26); // It is Thursday
	 
	 pGregorianCalendar->AddTimeField(TIME_FIELD_DAY_OF_MONTH, 1);
	 dayOfWeek = pGregorianCalendar->GetTimeField(TIME_FIELD_DAY_OF_WEEK); // It is Friday.
}
 @endcode
 *
 */

/**
 * @internal
 * This method is for internal use only. The bada platform team is not
 * responsible for any behavioral correctness, consistency, and
 * security-related issues that might arise after using this method.
 *
 * @enum		GregorianCalendarEras
 * Defines Era for Gregorian calendar. The indexing is 0-based.
 *
 * @since		1.0
 */
enum GregorianCalendarEras 
{
	GREGORIAN_CALENDAR_BC = 0,		// BC
	GREGORIAN_CALENDAR_AD = 1,		// AD

	GREGORIAN_CALENDAR_BCE = 0,		// BCE
	GREGORIAN_CALENDAR_CE = 1,		// CE
};

class _EXPORT_LOCALES_ GregorianCalendar :
	public Calendar
{
// lifecycle
public:


	/**
	 * This is the default constructor for this class. @n
	 * It creates an uninitialized instance of this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the
     *               Construct() methods must be called explicitly to initialize this instance.
	 * @see 			Construct()
	 */
	GregorianCalendar(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~GregorianCalendar(void);


	/**
	 * Initializes this instance of %GregorianCalendar with the current GMT time zone and the system locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				This instance has already been constructed.
	 */
	virtual result Construct(void);


	/**
	 * Initializes this instance of %GregorianCalendar with the specified parameter.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		gc							An instance of GregorianCalendar to be copied
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				This instance has already been constructed.
	 *
	 */
	virtual result Construct(const GregorianCalendar& gc);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the specified time zone with the system locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		timezone					An instance of TimeZone
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				This instance has already been constructed.
	 */
	result Construct(const TimeZone& timezone);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the GMT time zone with the specified locale.
	 * 
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		locale						An instance of Locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 */
	result Construct(const Locale& locale);


	/**
	 * Initializes this instance of %GregorianCalendar based on the current time in the specified time zone with the specified system locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		timezone					An instance of TimeZone
	 * @param[in]		locale						An instance of Locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 */
	virtual result Construct(const TimeZone& timezone, const Locale& locale);


	/**
	 * Initializes this instance of 5GregorianCalendar based on the specified year, month, day, hour, minute, and second
	 * in the GMT time zone with the system locale. @n
	 * The Gregorian calendar is lenient: time fields are normalized when the user calls the GetTimeField(TimeField) method.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		year						An integer value used to set the year time field
	 * @param[in]		month						An integer value used to set the month time field @n
	 *												The indexing is 1-based. Therefore, 1 means January.
	 * @param[in]		day							An integer value used to set the date time field
	 * @param[in]		hour						An integer value used to set the hour time field
	 * @param[in]		minute						An integer value used to set the minute time field
	 * @param[in]		second						An integer value used to set the second time field
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception		E_OUT_OF_RANGE				In this method, time fields of this instance are calculated. @n
   *                                                If the value of the time fields is out of range, this exception is returned. 
	 */
	result Construct(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);


	/**
	 * Initializes this instance of %GregorianCalendar based on the specified date and time in the GMT time zone with the system locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		dateTime					An instance of DateTime
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					A system error has occurred.
	 * @exception		E_OUT_OF_RANGE				In this method, time fields of this instance are calculated. @n
   *                                                If the value of the time fields is out of range, this exception is returned. 
	 */
	result Construct(const Osp::Base::DateTime& dateTime);


// Operations
	/**
	 * Adds the specified amount to the specified time field, based on the calendar rules. @n
	 * It is equivalent to calling Set(field, GetTimeField(field)+amount) with two adjustments. @n
	 *
	 * @b Add @b Rule1: The value of @c field after the call minus the value of @c field before the call is delta, modulo any overflow that has occurred in @c field.
     * Overflow occurs when the @c field value exceeds its range and, as a result, the next larger field is incremented or decremented and the @c field value is adjusted back into its range. @n
	 *
	 * @b Add @b Rule2: If a smaller field is expected to be invariant, but it is impossible for it to be equal to its prior value because of 
   * changes in its minimum or maximum value after the @c field value is changed, then its value is adjusted to the closest possible value. @n 
     *
	 * A smaller field represents a smaller unit of time. The TIME_FIELD_HOUR field is smaller than the TIME_FIELD_DAY_OF_MONTH field. 
	 * No adjustment is made to smaller fields that are not expected to be invariant. 
	 * The calendar system determines what fields are expected to be invariant. @n
	 *
	 * In addition, this method forces recomputation of the calendar's milliseconds and all time fields immediately.
	 * @n
	 * For example, consider a GregorianCalendar set to Oct. 31. 2004. Calling AddTimeField(TIME_FIELD_MONTH, 13) sets the calendar to Nov. 30. 2005. 
	 * The TIME_FIELD_MONTH field is set to TIME_FIELD_NOVEMBER by @b Rule1, since adding 13 months to October gives November of the next year. Since 
	 * the TIME_FIELD_DAY_OF_MONTH cannot be 31 in November in a GregorianCalendar, TIME_FIELD_DAY_OF_MONTH is set to 30 by @b Rule2.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		field						The time field
	 * @param[in]		amount						The amount to be added
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c field is invalid.
	 * @exception		E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks			The TIME_FIELD_EXTENDED_YEAR and TIME_FIELD_YEAR_WOY fields cannot be added.
	 */
	virtual result AddTimeField(TimeField field, int amount);


	/**
	 * Gets the actual minimum value that the specified time field can have, given the current date. @n
	 * For the Gregorian calendar, this is the same as GetMinTimeField(TimeField) and GetGreatestMinimum(TimeField).
	 *
	 * @since				1.0
	 * @return			An integer value indicating the actual minimum value, @n
	 *					else @c -1 if Construct() is not called
	 * @param[in]		field		The time field
	 */
	virtual int GetActualMinTimeField(TimeField field) const;


	/**
	 * Gets the actual maximum value that the specified time field can have, given the current date. @n
	 * For example, if the current date is "Feb. 3. 2004", then the maximum value of the DATE field is 29.
	 *
	 * @since				1.0
	 * @return			An integer value indicating the actual maximum value, @n
	 *					else @c -1 if the Construct() method is not called
	 * @param[in]		field		The time field
	 */
	virtual int GetActualMaxTimeField(TimeField field) const;


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the Gregorian Calendar change date. @n
	 * This is the point when the switch from Julian dates to Gregorian dates occurred. 
	 * Default is 00:00:00 local time, October 15, 1582. Previous to this the time and date are Julian dates.
	 *
	 * @since				1.0
	 * @return			The milliseconds which is the Gregorian cutover time for this calendar
	 */
	long long GetGregorianChange(void) const;
	

	/**
	 * Gets the calendar type of the current instance.
	 * 
	 * @since				1.0
	 * @return			An instance of %CalendarType representing the calendar type of the current instance of Calendar @n
	 *					In this case, CALENDAR_GREGORIAN.
	 */
	virtual CalendarType GetType(void) const;

	/**
	 * Checks whether the current date for the current instance is in Daylight Saving Time (DST).
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[out]		isInDst						Set to @c true if the current date is in DST, @n
	 *												else @c false
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				The Construct() method is not called or a value of the internal time field is invalid.
	 * @exception		E_OUT_OF_RANGE		In this method, time fields of this instance are calculated. @n
   *                                        If the value of the time fields is out of range, this exception is returned. 
	 */
	virtual result IsInDst(bool& isInDst) const;


	/**
	 * Checks whether the specified year is a leap year.
	 *
	 * @since				1.0
	 * @return			@c true if the specified year is a leap year, @n
	 *					else @c false
	 * @param[in]		year						The year to check
	 */
	bool IsLeapYear(int year) const;


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Replaces the Gregorian Calendar change date@n
	 * This is the point when the switch from Julian dates to Gregorian dates occurred. 
	 * Default is 00:00:00 local time, October 15, 1582. Previous to this, dates are in the Julian calendar.
	 *
	 * To obtain a pure Julian calendar, set the change @c change to MAX_MILLISECOND. 
	 * To obtain a pure Gregorian calendar, set the change @c change to MIN_MILLISECOND.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		change						The given Gregorian cutover date
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				This instance has not been constructed as yet.
	 */
	result SetGregorianChange(long long change);

	/**
    * Rolls up or down as per the specified amount in the specified field. @n
	  * This method overrides Calendar(void). @n
	 * For more details, refer to Osp::Locales::Calendar::Roll(TimeField, int)
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		field						The time field
	 * @param[in]		amount						The amount to roll up/down
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				This instance has not been constructed as yet, or an internal time field value is invalid.
	 * @exception		E_INVALID_ARG				The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	 * @exception		E_OUT_OF_RANGE		        In this method, time fields of this instance are calculated. @n
    *                                               If the value of the time fields is out of range, this exception is returned. 
	 */
	virtual result Roll(TimeField field, int amount);


// Accessor
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the millisecond which is midnight, local time at or before the Gregorian cutover.
	 *
	 * @since				1.0
	 * @return			The millisecond which is midnight, local time at or before the Gregorian cutover
	 *					If this method fails, @c -1 is returned.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	long long GetNormalizedGregorianCutover(void) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the year of the Gregorian cutover, with @c 0 representing 1 BC, @c -1 representing 2 BC, and so on.
	 *
	 * @since				1.0
	 * @return			The year of the Gregorian cutover
	 *					If this method fails, @c -1 is returned.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetGregorianCutoverYear(void) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the Julian day number of the Gregorian cutover.
	 *
	 * @since				1.0
	 * @return			The Julian day number of the Gregorian cutover
	 *					@c -1, if Construct() is not called
	 */
	int GetCutoverJulianDay(void) const;


// Inquiry
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Informs whether the current calendar is a Gregorian calendar or not.
	 *
	 * @since				1.0
	 * @return			@c true, if the current calendar is a Gregorian calendar @n
	 *					@c false, otherwise
	 */
	bool IsGregorian() const;


	/**
	 * Gets the current time of the instance in milliseconds from epoch.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[out]		millisec					The current time in milliseconds from the epoch
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_STATE				The Construct() method is not called or a value of the internal time field is invalid.
	 */
	result GetTimeInMillisecFromEpoch(long long& millisec) const;


	/**
	 * Sets the current time of the instance with the specified milliseconds value.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		millisec					The new time in milliseconds from the epoch
	 * @exception		E_OUT_OF_RANGE				A time field or its value is out of range.
	 * @exception		E_INVALID_STATE				This instance has not been constructed as yet.
	 */
	result SetTimeInMillisecFromEpoch(long long millisec);


	// Static
	/**
	 * Converts the 1970-epoch day number to the Gregorian year, month, date, day of week, and day of year.
	 *
	 * @since					1.0
	 * @param[in]			day							The 1970-epoch day number
	 * @param[out]		year						The year to be converted
	 * @param[out]		month						The month to be converted
	 * @param[out]		dayOfMonth					The date to be converted
	 * @param[out]		dayOfWeek					The day of week to be converted
	 * @param[out]		dayOfYear					The day of year to be converted
	 */
	static void DayToFields(int day, int& year, int& month, int& dayOfMonth, int& dayOfWeek, int& dayOfYear);


private:
	/**
	* Adds or subtracts a single unit of time on a given time field without changing larger fields. @n
	* When rolling on the TIME_FIELD_MONTH field, other fields such as TIME_FIELD_DAY_OF_MONTH field might conflict and need to be changed.
	*
	* @return			An error code
	* @param[in]		field						The time field
	* @param[in]		up							Set to @c true, if the specified time field is rolled up @n
	*												@c false, otherwise
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has not been constructed as yet, or an internal time field value is invalid.
	* @exception		E_INVALID_ARG				The specified @c field is invalid (for example, TIME_FIELD_DST_OFFSET, TIME_FIELD_ZONE_OFFSET).
	* @exception		E_OUT_OF_RANGE		A time field or its value is out of range.
	*					In this method, the time fields of this instance is calculated.
	*					At that time, if the value of the time fields is out of range, this exception is returned.
	*/
	virtual result RollWithSingleUnit(TimeField field, bool up);

	/**
	 * Converts the current millisecond time value to TimeField. @n
	 * This allows syncing up the time field values with a new time that is set for the calendar.
	 *
	 * @return			An error code
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_RANGE				The time fields contain an invalid value.
	 *					In this method, the time fields of this instance are calculated.
	 *					If the value of the time fields is out of range, this exception is returned.
	 */
	virtual result ComputeTimeFields(void);

	/**
	* Calculates the current values of time field to the millisecond time value.
	*
	* @return			An error code
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_STATE				This instance has not been constructed as yet, or an internal time field value is invalid.
	*/
	result ComputeTime(void);

	/**
	 * Creates a polymorphic copy of the current instance.
	 *
	 * @return		A pointer of a polymorphic copy
	 */
	virtual Osp::Locales::Calendar* CloneN(void) const;

	/**
	 * Returns the pseudo-time-stamp for two fields, given their individual pseudo-time-stamps.
	 * If either of the fields is unset, then the aggregate is unset. Otherwise, the aggregate is the later of the two stamps.
	 *
	 * @return			The pseudo-time-stamp
	 * @param[in]		stamp1						The time stamp for a field
	 * @param[in]		stamp2						The time stamp for another field
	 */
	int AggregateStamp(int stamp1, int stamp2);


	/**
	 * Computes the Julian day.
	 *
	 * @return		The Julian day
	 * @param[in]       isGregorian					Set to @c true if the input year is over the Gregorian cutover @n
	 *												@c false, otherwise
	 * @param[in]		year						The year to compute
	 * @param[in]		fieldMaskParam				The time field to compute
	 */
	long long ComputeJulianDay(bool isGregorian, int year, int& fieldMaskParam);

	/**
	 * Adjusts the value of 'day of week' field.
	 *
	 * @return			The value of 'day of week' field
	 */
	int GetNormalizedDayOfWeek(void);

	/**
	 * Returns the length of a given year and a given month.
	 *
	 * @return			The length of month
	 * @param[in]		year						A year
	 * @param[in]		month						A month
	 */
	virtual int GetMonthLength(int year, int month) const;


	/**
	 * Divides two integer and gets the floor of the quotient and modulus remainder.
	 *
	 * @return			The floor of the quotient
	 * @param[in]		numerator					A numerator
	 * @param[in]		denominator					A denominator
	 * @param[out]		rem							A remainder
	 */
	int FloorDivide(int numerator, int denominator, int& rem);


	/**
	 * Divides two integer and gets the floor of the quotient and modulus remainder.
	 *
	 * @return			The floor of the quotient
	 * @param[in]		numerator					A numerator
	 * @param[in]		denominator					A denominator
	 * @param[out]		rem							A remainder
	 */
	int FloorDivide(long long numerator, int denominator, int& rem);


	/**
	 * Divides two integer and gets the floor of the quotient.
	 *
	 * @return			The floor of the quotient
	 * @param[in]		numerator					A numerator
	 * @param[in]		denominator					A denominator
	 */
	int FloorDivide(int numerator, int denominator);


	/**
	 * Divides two long integer and gets the floor of the quotient.
	 *
	 * @return			The floor of the quotient
	 * @param[in]		numerator					A numerator
	 * @param[in]		denominator					A denominator
	 */
	long long FloorDivide(long long numerator, long long denominator);


	/**
	 * Returns the length of the current year.
	 *
	 * @return			The length of the current year
	 */
	int GetYearLength(void) const;


	/**
	 * Returns the length of a given year.
	 *
	 * @return			The length of a given year
	 * @param[in]		year						A given year
	 */
	int GetYearLength(int year) const;


	/**
	 * Defines the limits of difference types.
	 * Subclass must implement this method for the following fields.
	 * : TIME_FIELD_ERA, TIME_FIELD_YEAR, TIME_FIELD_MONTH, TIME_FIELD_WEEK_OF_YEAR, TIME_FIELD_WEEK_OF_MONTH, TIME_FIELD_DAY_OF_MONTH, TIME_FIELD_DAY_OF_YEAR,
	 * TIME_FIELD_DAY_OF_WEEK_IN_MONTH, TIME_FIELD_YEAR_WOY, TIME_FIELD_EXTENDED_YEAR
	 * 
	 * @return			The limit of a specified field
	 * @param[in]		field						The time field
	 * @param[in]		limitType					One of MINIMUM, GREATEST_MINIMUM, LEAST_MAXIMUM, or MAXIMUM
	 */
	virtual int HandleGetLimit(TimeField field, CalendarLimitType limitType) const;


	/**
	 * Converts the Julian day to day of week.
	 * The Julian date is not a true Julian date, since it is measured from midnight, not noon.
	 *
	 * @return			The day of week (one-based)
	 * @param[in]		julian						The given Julian date
	 */
	int JulianDayToDayOfWeek(long long julian);


	/**
	 * Converts the millisecond time to time fields.
	 * Fields that are completed by this method : TIME_FIELD_ERA, TIME_FIELD_YEAR, TIME_FIELD_MONTH, TIME_FIELD_DAY_OF_MONTH, TIME_FIELD_DAY_OF_WEEK,
	 * TIME_FIELD_DAY_OF_YEAR, TIME_FIELD_WEEK_OF_YEAR, TIME_FIELD_WEEK_OF_MONTH, TIME_FIELD_DAY_OF_WEEK_IN_MONTH.
	 * 
	 * @param[in]		time						The wall-clock time in milliseconds
	 * @param[in]		quick						Set to @c true, if TIME_FIELD_ERA, TIME_FIELD_YEAR,
	 *														TIME_FIELD_MONTH, TIME_FIELD_DAY_OF_MONTH, TIME_FIELD_DAY_OF_WEEK, and TIME_FIELD_DAY_OF_YEAR are to be computed @n
	 * 												@c false, otherwise		
	 */
	void TimeToFields(long long time, bool quick);

	/**
	 * Calculates the value of week of year field.
	 *
	 * @return          The value of week of year    
	 * @param[in]       dayOfWeek                    The value of day of week
	 * @param[in]       dayOfYear                    The value of day of year
	 * @param[in]       rawYear                      The value of year
	 */
	int CalculateWeekOfYear(int dayOfWeek, int dayOfYear, int rawYear);

	/**
	 * Converts the Julian day to milliseconds.
	 *
	 * @return			The millisecond
	 * @param[in]		julianDay					The Julian date to be converted
	 */
	long long JulianDayToMillisec(long long julianDay);


	/**
	 * Converts the milliseconds to the Julian day.
	 * 
	 * @return			The Julian day
	 * @param[in]		millisec					The millisecond to be converted
	 */
	long long MillisecToJulianDay(long long millisec);


	/**
	 * Validates the value of the set time fields.
	 *
	 * @return			@c true, if all value of time fields are valid @n
	 *					@c false, otherwise
	 */
	bool ValidateFields(void);


	/**
	 * Validates the value of a given time field.
	 *
	 * @return			@c true, if a value of given time field is valid @n
 	 *					@c false, otherwise
	 * @param[in]		value						A given value
	 * @param[in]		field						A given field
	 */
	bool CheckBound(int value, TimeField field);


	/**
	 * Returns the week number of a day, within a period.
	 * This may be the week number in a year, or the week number in a month. 
	 *
	 * @return			The week number
	 * @param[in]		dayOfPeriod					The day-of-year or day-of-month
	 * @param[in]		day							The day-of-week for given @c dayOfPeriod. 1-based with 1 = Sunday
	 */
	int WeekNumber(int dayOfPeriod, int dayOfWeek);


	/**
	 * Adjusts the date after a call Add() such as Add(TIME_FIELD_MONTH), Add(TIME_FIELD_YEAR).
	 */
	void PinDayOfMonth(void);


	/**
	 * Implements the conversion from UTC time to the time field value.
	 */
	void ComputeFieldsImplementation(void);


	/**
	 * Divides two integers and gets the floor of the quotient and modulus remainder.
	 *
	 * @return			The floor of the quotient
	 * @param[in]		numerator					A numerator
	 * @param[in]		denominator					A denominator
	 * @param[out]		rem							A remainder
	 */
	static int FloorDivides(int numerator, int denominator, int& rem);


	/**
	 * Checks whether a given year is a leap year.
	 *
	 * @return			@c true, if a given year is leap year @n
	 *					@c false, otherwise
	 * @param[in]		year						A given year
	 */
	static bool IsLeap(int year);


	/**
	 * Initializes the 100-year window that dates with 2-digit years are considered to fall within so that its start
	 * date is 80 years before the current time.
	 */
	static void InitializeSystemDefaultCentury(void);

	// constants	
public:

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Defines the length of months.
	 *
	 * @since 1.0
	 */
	static const int MONTH_LENGTH[24];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Defines the days of a year.
	 *
	 * @since 1.0
	 */
	static const int NUM_DAYS[24];

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The Gregorian cutover number for Julian day.
	 *
	 * @since 1.0
	 */
	static const int CUTOVER_JULIAN_DAY = 2299161;		// Oct. 15. 1582.

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The epoch year.
	 *
	 * @since 1.0
	 */
	static const int EPOCH_YEAR = 1970;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The epoch start for Julian day.
	 *
	 * @since 1.0
	 */
	static const int EPOCH_START_AS_JULIAN_DAY = 2440588; // Jan. 1. 1970(Gregorian)

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * January.1.1 epoch start for Julian day.
	 *
	 * @since 1.0
	 */
	static const int JAN_1_1_JULIAN_DAY = 1721426;	// Jan. 1. 1 CE Gregorian

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Temporary value for the Gregorian cutover.
	 *
	 * @since 1.0
	 */
	static const long long PAPAL_CUTOVER = ((long long)(GregorianCalendar::CUTOVER_JULIAN_DAY - GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long)ONE_DAY_IN_MILLISEC);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Maximum value for longlong.
	 *
	 * @since 1.0
	 */
	static const long long MAX_LONGLONG = (2 ^ 63) - 1;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Minimum value for longlong.
	 *
	 * @since 1.0
	 */
	static const long long MIN_LONGLONG = -1 * (2 ^ 63);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Maximum value for Julian day.
	 *
	 * @since 1.0
	 */
	static const int MAX_JULIAN = 0x7F000000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Minimum value for Julian day.
	 *
	 * @since 1.0
	 */
	static const int MIN_JULIAN = -0x7F000000;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *	 
	 * Maximum millisecond value for Julian day.
	 *
	 * @since 1.0
	 */
	static const long long MAX_MILLISEC = ((GregorianCalendar::MAX_JULIAN - GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long)ONE_DAY_IN_MILLISEC);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Minimum millisecond value for Julian day.
	 *
	 * @since 1.0
	 */
	static const long long MIN_MILLISEC = ((GregorianCalendar::MIN_JULIAN - GregorianCalendar::EPOCH_START_AS_JULIAN_DAY) * (long long)ONE_DAY_IN_MILLISEC);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Epoch offset in millisecond value.
	 *
	 * @since 1.0
	 */
	static const long long EPOCH_OFFSET_IN_MILLISEC = 62135596800000LL; //62135683200000L - 86400000L; // Jan. 1, 1970

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Default Gregorian cutover.
	 *
	 * @since 1.0
	 */
	static const long long DEFAULT_GREGORIAN_CUTOVER = -12219292800000LL;

private:
	long long __gregorianCutover;
	long long __normalizedGregorianCutover; // = __gregorianCutover;
	int __gregorianCutoverYear; // 1582
	int __cutoverJulianDay;

	// min positive value in VC++ 7.0
	static const double __GREGORIAN_DBL_MIN;
	static const double __GREGORIAN_DEFAULT_CENTURY; // Gregorian system default century.

	static double __gregorianDefaultCenturyStart; // Gregorian system default century start.
	static int __gregorianDefaultCenturyStartYear; // Gregorian system default century start year.
	static Osp::Base::Runtime::Mutex* __pMutex;


private:
	friend class GregorianCalendarEx;
	class GregorianCalendarEx* __pGregorianCalendarEx;

}; // GregorianCalendar

};  };// Locale Osp

#endif//_FLCL_GREGORIAN_CALENDAR_H_

