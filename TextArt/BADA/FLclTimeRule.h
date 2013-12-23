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
 * @file		FLclTimeRule.h 
 * @brief		This is the header file for the %TimeRule class.
 *
 * This header file contains the declarations of the %TimeRule class.
 */
#ifndef	_FLCL_TIME_RULE_H_
#define	_FLCL_TIME_RULE_H_

// includes
#include "FBaseObject.h"
#include "FSysSystemTime.h"
#include "FLclConfig.h"


namespace Osp { namespace Locales {

/**
 * @class		TimeRule
 * @brief		This class is for setting and getting the time rule. 
 * @since		1.0
 *
 * The %TimeRule class defines the time rule and provides the methods for setting and getting it.
 * This class does not execute any operation with its value and is mainly used when periodically repeated time rules are defined.
 * For example, the daylight saving time rule.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/time_rules.htm">Time Rules</a>.
 *
 * @see		Osp::Locales::TimeZone
 */ 

/**
* @enum Month
* Defines the months. @n
* The indexing is 1-based.
*
* @since		1.0
*/
enum Month
{
	JANUARY = 1,	/**< January	*/
	FEBRUARY,		/**< February	*/
	MARCH,			/**< March		*/
	APRIL,			/**< April		*/
	MAY,			/**< May		*/
	JUNE,			/**< June		*/
	JULY,			/**< July		*/
	AUGUST,			/**< August		*/
	SEPTEMBER,		/**< September	*/
	OCTOBER,		/**< October	*/
	NOVEMBER,		/**< November 	*/
	DECEMBER,		/**< December 	*/
	MONTH_UNDEFINED = -1	/*< Undefined */
};


/**
* @enum DayOfWeek
* Defines the days of the week. @n
* The indexing is 1-based.
*
* @since		1.0
*/
enum DayOfWeek
{
	SUNDAY = 1,					/**< Sunday */
	MONDAY,						/**< Monday */
	TUESDAY,					/**< Tuesday */
	WEDNESDAY,					/**< Wednesday */
	THURSDAY,					/**< Thursday */
	FRIDAY,						/**< Friday */
	SATURDAY,					/**< Saturday */
	DAY_OF_WEEK_UNDEFINED = -1	/*< Undefined */
};

/**
 * @enum Week
 * Defines the week.
 *
 * @since		1.0
 */
typedef enum
{
	FIRST_WEEK = 1,				/**< The first week */
	SECOND_WEEK = 2,			/**< The second week */
	THIRD_WEEK = 3,				/**< The third week */
	FOURTH_WEEK = 4,			/**< The fourth week */
	FIFTH_WEEK = 5,				/**< The fifth week */
	SIXTH_WEEK = 6,				/**< The sixth week */
	LAST_WEEK	 = -2,			/**< The last week */
	WEEK_UNDEFINED = -1			/*< Undefined */
} Week;

/**
 * @internal
 * This method is for internal use only. The bada platform team is not
 * responsible for any behavioral correctness, consistency, and
 * security-related issues that might arise after using this method.
 *
 * Possible DST rule mode
 *
 * @since		1.0
 */
typedef enum {
	EXACT_DAY = 0,
	DAY_OF_WEEK_IN_MONTH,
	AFTER_THE_SPECIFIED_DAY,
	BEFORE_THE_SPECIFIED_DAY,
	BACKWARD_FROM_END_OF_MONTH
} DstRuleMode;


class _EXPORT_LOCALES_ TimeRule :
	public Osp::Base::Object
{
// Life cycle
public:
	/**
	 * Initializes the current instance of %TimeRule with the values of the specified %TimeRule instance.
	 *
	 * @since				1.0
	 * @param[in]		timeRule			An instance of TimeRule
	 */
	TimeRule(const TimeRule& timeRule);


	/**
	 * Assigns the value of the specified instance to the current instance of %TimeRule.
	 *
	 * @since				1.0
	 * @param[in]		timeRule			An instance of TimeRule
	 */
	TimeRule& operator= (const TimeRule& timeRule);



	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~TimeRule(void);


	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c day, @c hour, 
	 * @c minute, and @c timeMode.
	 *
	 * @since				1.0
	 * @param[in]		month				The month
	 * @param[in]		day					The day
	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - UTC_TIME, STANDARD_TIME, or WALL_TIME
	 */
	TimeRule(Month month, int day, int hour = 0, int minute = 0, Osp::System::TimeMode timeMode = Osp::System::WALL_TIME);


	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c week, 
	 * @c dayOfWeek, @c hour, @c minute, and @c timeMode.
	 *
	 * @since				1.0
	 * @param[in]		month				The month
	 * @param[in]		week				The week
	 * @param[in]		dayOfWeek			The day of the week
	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - UTC_TIME, STANDARD_TIME, or WALL_TIME
	 */
	TimeRule(Month month, Week week, DayOfWeek dayOfWeek, 
		int hour = 0, int minute = 0, Osp::System::TimeMode timeMode = Osp::System::WALL_TIME); 


	/**
	 * Initializes the current instance of %TimeRule with the specified @c month, @c day, 
	 * @c dayOfWeek, @c onOrAfterDay setting, @c hour, @c minute, and @c timeMode.
	 *
	 * @since				1.0
	 * @param[in]		month				The month
	 * @param[in]		day					The day
	 * @param[in]		dayOfWeek			The day of the week
	 * @param[in]		onOrAfterDay		Set to @c true to select the first @c dayOfWeek 
   *                                        @b on @b or @b after @c day, @n
   *                                        else @c false to select the last @c dayOfWeek
   *                                        @b on @b or @b before @c day. 

	 * @param[in]		hour				The hour
	 * @param[in]		minute				The minute
	 * @param[in]		timeMode			The time mode - UTC_TIME, STANDARD_TIME, or WALL_TIME
	 */
	TimeRule(Month month, int day, DayOfWeek dayOfWeek, 
		bool onOrAfterDay, int hour = 0, int minute = 0, Osp::System::TimeMode timeMode = Osp::System::WALL_TIME);


// Accessors
	/**
	 * Gets the month.
	 *
	 * @since				1.0
	 * @return			The month
	 */
	Month GetMonth(void) const;


	/**
	 * Gets the day.
	 *
	 * @since				1.0
	 * @return			An integer value indicating the day, @n
	 *					else @c -1 if the value of day is undefined
	 */
	int GetDay(void) const;


	/**
	 * Gets the week.
	 *
	 * @since				1.0
	 * @return			The week, @n
	 *					else @c -1 if the value of week is undefined
	 */
	Week GetWeek(void) const;


	/**
	 * Gets the day of the week.
	 *
	 * @since				1.0
	 * @return			The day of the week, @n
	 *					else @c -1 if the value of day of the week is undefined
	 */
	DayOfWeek GetDayOfWeek(void) const;


	/**
	 * Gets the hour.
	 *
	 * @since				1.0
	 * @return			An integer value indicating the hour
	 */
	int GetHour(void) const;


	/**
	 * Gets the minute.
	 *
	 * @since				1.0
	 * @return			An integer value indicating the minute
	 */
	int GetMinute(void) const;


	/**
	 * Gets the time mode.
	 *
	 * @since				1.0
	 * @return			An instance of TimeMode
	 */
	Osp::System::TimeMode GetTimeMode(void) const;


	/**
	 * Gets the value of the @c onOrAfterDay field.
	 *
	 * @since				1.0
	 * @return			A @c boolean value of the @c onOrAfterDay field
	 */
	bool IsOnOrAfterDay(void) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the current rule mode.
	 *
	 * @since				1.0
	 * @return			The rule mode value of this instance
	 */
	DstRuleMode GetRuleMode(void) const;

private:
	/**
	 * Initializes a TimeRule instance with given values.
	 *
	 * @return			An error code
	 * @param[in]		month					The month
	 * @param[in]		day						The day
	 * @param[in]		week					The week
	 * @param[in]		dayOfWeek				The day of week
	 * @param[in]		beforeAfter				If @c after is ON_OR_AFTER_DAY, this rule selects the first @c dayOfWeek
	 *											@b on @b or @b after @c day.
	 *											If @c after is ON_OR_BEFORE_DAY, this rule selects the last @c dayOfWeek
	 *											@b on @b or @b before @c day.
	 * @param[in]		hour					The hour
	 * @param[in]		minute					The minute
	 * @param[in]		timeMode				The time mode - UTC_TIME, STANDARD_TIME, WALL_TIME
	 */
	void SetValue(Month month, int day, Week week, 
		DayOfWeek dayOfWeek, bool onOrAfterDay, int hour, 
		int minute, Osp::System::TimeMode timeMode);

private:
	static const int DAY_UNDEFINED = 	-1;

	Month __month;
	int __day;
	Week __week;
	DayOfWeek __dayOfWeek;
	int __hour;
	int __minute;
	Osp::System::TimeMode __timeMode;
	bool __onOrAfterDay;


private:
	friend class TimeRuleEx;
	class TimeRuleEx* __pTimeRuleEx;

};

};	};	// Osp::Locales
#endif	// _FLCL_TIME_RULE_H_

	
	



