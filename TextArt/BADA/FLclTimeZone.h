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
 * @file		FLclTimeZone.h 
 * @brief		This is the header file for the %TimeZone class.
 * @see			Osp::Locales::Locale 
 *
 * This header file contains the declaration of the %TimeZone class. 
 */

#ifndef	_FLCL_TIME_ZONE_H_
#define	_FLCL_TIME_ZONE_H_

// includes
#include "FBase.h"
#include "FLclConfig.h"
#include "FLclTimeRule.h"


namespace Osp { namespace Locales {

/**
 * @class		TimeZone
 * @brief		This class represents the time zones.
 * @since		1.0
 *
 * The %TimeZone class represents a time zone offset and figures out Daylight Saving Time (DST). 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/time_zone.htm">Time Zones</a>.
 *
 * The following example demonstrates how to use the %TimeZone class.
 *
@code

#include <FLocales.h>

using namespace Osp::Locales;

result
MyClass::MyTimeZone(void)
{
	// Gets the system time zone
	LocaleManager localeManager;
	localeManager.Construct();

	TimeZone timeZone = localeManager.GetSystemTimeZone();

	String tiemZoneId = timeZone.GetId();
	int rawOffset = timeZone.GetRawOffset();
	int dstSavings = timeZone.GetDstSavings();
}
@endcode
 *
 */

class _EXPORT_LOCALES_ TimeZone :
	public Osp::Base::Object
{
// Construct Operations
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	TimeZone(void);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~TimeZone(void);


	/**
	 * This is the copy constructor for the %TimeZone class. @n
	 * It initializes an instance of %TimeZone with the values of the specified instance of %TimeZone.
	 *
	 * @since				1.0
	 * @param[in]		otherTimeZone					An instance of TimeZone
	 */
	TimeZone(const TimeZone& otherTimeZone);

	/**
	 * Assigns the value of the specified instance of %TimeZone to the current instance of %TimeZone.
	 *
	 * @since				1.0
	 * @return			A reference value of the current instance
	 * @param[in]		otherTimeZone					An instance of TimeZone
	 *
	 */
	TimeZone& operator= (const TimeZone& otherTimeZone);

	
	/**
	 * Initializes this instance of %TimeZone with the specified raw GMT offset and the name of the time zone without including DST. 
	 *
	 * @since				1.0
	 * @param[in]		rawOffset						The base time zone offset to GMT in minutes
	 * @param[in]		id								The time zone ID
	 */
	TimeZone(int rawOffset, const Osp::Base::String& id);

	
	/**
	 * Initializes this instance of %TimeZone with the specified raw GMT offset, 
	 * the name of the time zone, and the rules for starting/ending DST. @n
	 *
	 * @since				1.0
	 * @param[in]		rawOffset						The base time zone offset to GMT in minutes
	 * @param[in]		id								The time zone ID
	 * @param[in]		startRule						The DST starting rule
	 * @param[in]		endRule							The DST end rule
	 * @param[in]		dstOffset						The amount of time in minutes saved during DST
	 */
	TimeZone(int rawOffset, const Osp::Base::String& id, 
		const TimeRule& startRule, const TimeRule& endRule, int dstOffset);


// Operators
public:

	/**
	 * Checks whether the specified instance of %TimeZone equals the value of the current instance.
	 *
	 * @since				1.0
	 * @return			@c true if the two instances are equal, @n
	 *					else @c false
	 * @param[in]		otherTimeZone					A reference to another TimeZone instance
	 */
	bool operator== (const TimeZone& otherTimeZone) const;


	/**
	 * Checks whether the %TimeZone instance is equal to the current instance.
	 *
	 * @since				1.0
	 * @return			@c true if the two instances are not equal, @n
	 *					else @c false
	 * @param[in]		otherTimeZone					A reference to TimeZone instance
	 */
	bool operator!= (const TimeZone& otherTimeZone) const;


// Operations
public:
	/**
	 * Sets the DST time.
	 *
	 * @since				1.0
	 * @param[in]		dstSavings						The amount of time in minutes @n
	 *													The time is advanced with respect to the standard time when the DST rules are in effect.
	 */
	void SetDstSavings(int dstSavings);


	/**
	 * Sets the DST starting and end rule.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		startRule						The DST starting rule
	 * @param[in]		endRule							The DST end rule
	 * @param[in]		dstSavings						The DST offset in minutes
	 * @exception		E_SUCCESS						The method is successful.
	 * @exception		E_OUT_OF_RANGE					The specified @c dstSavings is less than 24 hours.
	 */
	result SetDstRules(const TimeRule& startRule, const TimeRule& endRule, int dstSavings = 60);


	/**
	 * Sets the DST end rule.
	 *
	 * @since				1.0
	 * @param[in]		endRule							The DST end rule
	 */
	void SetDstEndingRule(const TimeRule& endRule);


	/**
	 * Sets the DST starting rule.
	 *
	 * @since				1.0
	 * @param[in]		startRule						The DST starting rule
	 */
	void SetDstStartingRule(const TimeRule& startRule);


	/**
	 * Sets the difference in minutes between the local standard time and GMT, 
	 * without including DST (that is, raw offset).
	 *
	 * @since				1.0
	 * @param[in]		rawOffset						The difference in minutes between the local standard time and GMT, without including DST
	 */
	void SetRawOffset(int rawOffset);	


	/**
	 * Sets the DST starting year.
	 * 
	 * @since				1.0
	 * @param[in]		year							The DST starting year
	 */
	void SetDstStartingYear(int year);
		

	/**
	 * Sets the ID of the time zone.
	 *
	 * @since				1.0
	 * @param[in]		id								The ID of the time zone
	 */
	void SetId(const Osp::Base::String& id);


	/**
	 * Converts the Coordinated Universal Time (UTC) time to the standard time.
	 *
	 * @since				1.0
	 * @return			The standard time
	 * @param[in]		utcTime							The UTC time
	 */
	Osp::Base::DateTime UtcTimeToStandardTime(const Osp::Base::DateTime& utcTime);


	/**
	 * Converts the UTC time to the wall time.
	 *
	 * @since				1.0
	 * @return			The wall time
	 * @param[in]		utcTime							The UTC time
	 */
	Osp::Base::DateTime UtcTimeToWallTime(const Osp::Base::DateTime& utcTime);


	/**
	 * Converts the standard time to the UTC time.
	 *
	 * @since				1.0
	 * @return			The UTC time
	 * @param[in]		standardTime					The standard time
	 */
	Osp::Base::DateTime StandardTimeToUtcTime(const Osp::Base::DateTime& standardTime);


	/**
	 * Converts the wall time to the UTC time.
	 *
	 * @since				1.0
	 * @return			The UTC time
	 * @param[in]		wallTime						The wall time
	 */
	Osp::Base::DateTime WallTimeToUtcTime(const Osp::Base::DateTime& wallTime);


// Accessor
	/**
	 * Gets the amount of time in minutes to be added to the local standard time to get the local wall time.
	 *
	 * @since				1.0
	 * @return			The amount of time in minutes
	 * 
	 */
	int GetDstSavings(void) const;

	/**
	 * Gets the starting year of the DST.
	 * 
	 * @since				1.0
	 * @return			The starting year of the DST set by the SetDstStartingYear() method, @n
   *                    else @c 0 if the starting year of the DST is undefined  
	 * @see 				SetDstStartingYear()
	 */
	int GetDstStartingYear(void) const;	


	/**
	 * Gets the raw and GMT offset for the specified instance of %DateTime in the current time zone.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		date						An instance of DateTime
	 * @param[in]		local						Set to @c true if the date is in local wall time, @n
	 *												else @c false if it is in GMT time 
	 * @param[out]		rawOffset					The time zone's raw offset in minutes 
	 * @param[out]		dstOffset					The offset to be added to @c rawOffset to obtain the total offset between the local and GMT time. @n
	 *												If DST is not in effect, it is zero.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_RANGE				The argument is out of range.
	 * @remarks			Local millisecond = GMT milliseconds + rawOffset(in milliseconds) + dstOffset(in milliseconds). 
	 *							All computations are performed in Gregorian calendar.
	 */
	result GetOffset(const Osp::Base::DateTime& date, bool local, int& rawOffset, int& dstOffset) const;


	/**
	 * Gets the difference in milliseconds between the local standard time and GMT, taking into consideration both the raw offset and the effect of DST.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		ticks						The time ticks value @n  
	 *                                               The value can be either GMT time or local wall time.
	 * @param[out]		offset						The offset between the local standard time and GMT, taking into consideration the DST
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_OUT_OF_RANGE				The specified @c date is out of range.
	 */
	result GetOffset(long long ticks, int& offset) const;


	/**
	 * Gets the difference in minutes between the local standard time and GMT, without including DST (that is, raw offset).
	 *
	 * @since				1.0
	 * @return			The raw offset
	 *
	 */
	int GetRawOffset(void) const;


	/**
	 * Gets the ID of the time zone.
	 *
	 * @since				1.0
	 * @return			The ID of the time zone
	 */
	Osp::Base::String GetId(void) const;


	/**
	 * Gets the DST starting rule.
	 *
	 * @since				1.0
	 * @return			A pointer to the DST start rule, @n
	 *					else a @c null pointer if the DST start rule is undefined
	 */
	const TimeRule* GetDstStartingRule(void) const;


	/**
	 * Gets the DST end rule.
	 *
	 * @since				1.0
	 * @return			A pointer to the DST end rule, @n
	 *					else a @c null pointer if the DST end rule is undefined
	 */
	const TimeRule* GetDstEndingRule(void) const;


// Inquiry
	/**
	 * Checks whether the current instance of %TimeZone uses DST.
	 *
	 * @since				1.0
	 * @return			@c true if the current instance uses DST, @n
	 *					else @c false
	 */
	bool IsDstUsed(void) const;


// Static Functions
public:

	/**
	 * Gets the GMT time zone. @n
	 * The GMT time zone has a raw offset of @c 0 and does not use DST.
	 *
	 * @since			1.0
	 * @return		The GMT time zone
	 */
	static TimeZone GetGmtTimeZone(void);


	/**
	 * Gets the time zone instance from the given ID. @n
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		id				The time zone ID
	 * @param[out]		timeZone		The time zone for the given ID
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c id is not supported.
	 * @remarks			The %TimeZone instance for the specified @c id does not contain the DST information.
	 *      			The supported time zone list depends on the device. Therefore, it should be checked before using this method.
	 * @see 				LocaleManager::GetAvailableTimeZonesN()
	 */
	static result GetTimeZone(const Osp::Base::String &id, Osp::Locales::TimeZone &timeZone);


	/**
	 * Gets the %TimeZone instance from the specified ID and UTC time. @n
	 *
	 * @since				1.1
	 * @return			An error code
	 * @param[in]		id				The time zone ID
	 * @param[in]  		utcTime			The UTC time
	 * @param[out]		timeZone		The time zone for the specified ID and UTC time
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c id is not supported.
	 * @remarks			The %TimeZone instance for the specified ID and UTC time contains the DST information.
	 *      			The supported time zone list depends on the device. Therefore, it should be checked before using this method.
	 * @see 				LocaleManager::GetAvailableTimeZonesN()
	 */
	static result GetTimeZone(const Osp::Base::String &id, const Osp::Base::DateTime &utcTime, Osp::Locales::TimeZone &timeZone);


	/**
	 * Converts the UTC time to the standard time.
	 *
	 * @since				1.0
	 * @return     	The standard time
	 * @param[in]  	utcTime			The UTC time
	 * @param[in]  	rawOffset		The time zone's raw offset in minutes
	 */
	static Osp::Base::DateTime UtcTimeToStandardTime(const Osp::Base::DateTime &utcTime, int rawOffset);


	/**
	 * Converts the Standard time to the UTC time.
	 *
	 * @since				1.0
	 * @return     	The UTC time
	 * @param[in]  	standardTime		The Standard time
	 * @param[in]  	rawOffset		The time zone's raw offset in minutes
	 */
	static Osp::Base::DateTime StandardTimeToUtcTime(const Osp::Base::DateTime &standardTime, int rawOffset);


	/**
	 * Converts the UTC time to the Wall time.
	 *
	 * @since				1.0
	 * @return     	The Wall time
	 * @param[in]  	utcTime 			The UTC time
	 * @param[in]  	rawOffset		The time zone's raw offset in minutes
	 * @param[in]  	dstOffset		The amount of time in minutes saved during DST
	 */
	static Osp::Base::DateTime UtcTimeToWallTime(const Osp::Base::DateTime &utcTime, int rawOffset, int dstOffset);


	/**
	 * Converts the Wall time to the UTC time.
	 *
	 * @since				1.0
	 * @return     	The UTC time
	 * @param[in]  	wallTime			The Wall time
	 * @param[in]  	rawOffset		The time zone's raw offset in minutes
	 * @param[in]  	dstOffset		The amount of time in minutes saved during DST
	 */
	static Osp::Base::DateTime WallTimeToUtcTime(const Osp::Base::DateTime &wallTime, int rawOffset, int dstOffset);



// Private function
private:
		
	/**
	 * Returns the DST starting year.
	 *
	 * @return				The DST starting year
	 */
	int GetStartYear(void) const;

	/**
	 * Compares a date to a specified rule date.
	 * 
	 * @return				@c  1, if the date is after the rule date @n
	 *						@c -1, if the date is before the rule date @n
	 *						@c  0, if the date is equal to the rule date
	 */
	static int CompareToRule(int month,
							int monthLen,
							int prevMonthLen,
							int DayOfWeekInMonth,
							int dayOfWeek,
							long long millis,
							int millisDelta,
							int ruleMode,
							int ruleMonth,
							int ruleDayOfWeek,
							int ruleDay,
							long long ruleMillis);

	static int CompareTimeUnit(long long source, long long destination);

	/**
	 * Compares two TimeRule instances.
	 *
	 * @return			@c true, if they are the same @n
	 *					@c false, otherwise
	 * @param[in]		sourceRule							The source DST rule
	 * @param[in]		destinationRule						The destination DST rule
	 */
	bool CompareRule(const TimeRule& sourceRule, const TimeRule& destinationRule) const;

	/**
	 * Returns the difference in minutes between local standard time and UTC, 
	 * taking into consideration both the raw offset and the effect of DST.
	 *
	 * @return			An error code
	 * @param[in]		era									The era of the given date
	 * @param[in]		year								The year of the given date
	 * @param[in]		month								The month of the given date (1-based; January is 1.)
	 * @param[in]		day									The day-of-week-in-month of the given date (1-based)
	 * @param[in]		dayOfWeek							The day-of-week of the given date (1-based; Sunday is 1)
	 * @param[in]		millisec							The milliseconds in day in local standard time
	 * @param[out]		offset								The offset between local standard time and GMT, taking into consideration both the raw offset and the effect of DST
	 * @exception		E_SUCCESS							The method is successful.
	 * @exception		E_OUT_OF_RANGE			If @c era, @c year, @c month, @c DayOfWeekInMonth, @c dayOfWeek and @c millisec are out of range.
	 */
	result GetOffset(int era, int year, int month, int day, int dayOfWeek, int millisec, int& offset) const;

	/**
	 * Checks that the current instance and @c otherTimeZone have the same rule and offset.
	 *
	 * @return			@c true, if they have the same rule and offset @n
	 *					@c false, otherwise
	 * @param[in]		otherTimeZone						An instance of TimeZone to be compared with
	 */
	bool HasSameRules(const TimeZone& otherTimeZone) const;

// Attribute
private:
	static const int DAY_UNDEFINED = 	-1;

	Osp::Base::String __id;

	int	__rawOffsetInMillisec;
	int __dstSavingsInMillisec;
	int __dstStartingYear;
	bool __isDstUsed;

	TimeRule __startingRule;
	TimeRule __endingRule;
	
	static const int ONE_HOUR_IN_MILLISEC = 60 * 60 * 1000; // the number of milliseconds in one hour
	static const int ONE_DAY_IN_MILLISEC = 24 * ONE_HOUR_IN_MILLISEC; // the number of milliseconds in one day(hour*min*sec*1000milli)


private:
	friend class TimeZoneEx;
	class TimeZoneEx* __pTimeZoneEx;
};
};	}; // Osp::Locales
#endif // _FLCL_TIME_ZONE_H_


