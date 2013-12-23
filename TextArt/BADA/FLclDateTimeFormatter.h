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
 * @file		FLclDateTimeFormatter.h 
 * @brief		This is the header file for the %DateTimeFormatter class.
 *
 * This header file contains the declarations of the %DateTimeFormatter class. 
 *  
 */
#ifndef	_FLCL_DATE_TIME_FORMATTER_H_
#define	_FLCL_DATE_TIME_FORMATTER_H_

// Includes
#include "FBase.h"
#include "FLclLocale.h"
#include "FLclTimeZone.h"
#include "FLclNumberFormatter.h"
#include "FLclCalendar.h"
#include "FLclDateTimeSymbols.h"


namespace Osp { namespace Locales {
	class __FieldPosition;
};};


namespace Osp { namespace Locales {

/**
 * @internal
 * This method is for internal use only. The bada platform team is not
 * responsible for any behavioral correctness, consistency, and
 * security-related issues that might arise after using this method.
 *
 * @enum DateTimeFormatField
 * Defines the style DateTimeFormatField.
 *
 * @since		1.0
 */
typedef enum DateTimeFormatField 
{
	DATE_TIME_FORMAT_ERA_FIELD = 0,						/**< @internal For 'G' field alignment */ 
	DATE_TIME_FORMAT_YEAR_FIELD = 1,						/**< @internal For 'y' field alignment */  
	DATE_TIME_FORMAT_MONTH_FIELD = 2,					/**< @internal For 'M' field alignment */
	DATE_TIME_FORMAT_DATE_FIELD = 3,						/**< @internal For 'd' field alignment */
	DATE_TIME_FORMAT_HOUR_OF_DAY1_FIELD = 4,			/**< @internal For 'k' field alignment */
	DATE_TIME_FORMAT_HOUR_OF_DAY0_FIELD = 5,			/**< @internal For 'H' field alignment */
	DATE_TIME_FORMAT_MINUTE_FIELD = 6,					/**< @internal For 'm' field alignment */
	DATE_TIME_FORMAT_SECOND_FIELD = 7,					/**< @internal For 's' field alignment */
	DATE_TIME_FORMAT_FRACTIONAL_SECOND_FIELD = 8,		/**< @internal For 'S' field alignment */
	DATE_TIME_FORMAT_DAY_OF_WEEK_FIELD = 9,				/**< @internal For 'E' field alignment */
	DATE_TIME_FORMAT_DAY_OF_YEAR_FIELD = 10,			/**< @internal For 'D' field alignment */
	DATE_TIME_FORMAT_DAY_OF_WEEK_IN_MONTH_FIELD = 11,	/**< @internal For 'F' field alignment */
	DATE_TIME_FORMAT_WEEK_OF_YEAR_FIELD = 12,			/**< @internal For 'w' field alignment */
	DATE_TIME_FORMAT_WEEK_OF_MONTH_FIELD = 13,			/**< @internal For 'W' field alignment */
	DATE_TIME_FORMAT_AM_PM_FIELD = 14,					/**< @internal For 'a' field alignment */
	DATE_TIME_FORMAT_HOUR1_FIELD = 15,					/**< @internal For 'h' field alignment */
	DATE_TIME_FORMAT_HOUR0_FIELD = 16,					/**< @internal For 'k' field alignment */
	DATE_TIME_FORMAT_TIMEZONE_FIELD = 17,				/**< @internal For 'z' field alignment */
	DATE_TIME_FORMAT_YEAR_WOY_FIELD = 18,				/**< @internal For 'Y' field alignment */
	DATE_TIME_FORMAT_DOW_LOTIME_FIELD_FIELD = 19,		/**< @internal For 'e' field alignment */
	DATE_TIME_FORMAT_EXTENDED_YEAR_FIELD = 20,			/**< @internal For 'u' field alignment */
	DATE_TIME_FORMAT_JULIAN_DAY_FIELD = 21,				/**< @internal For 'g' field alignment */
	DATE_TIME_FORMAT_MILLISECONDS_IN_DAY_FIELD = 22,	/**< @internal For 'A' field alignment */
	DATE_TIME_FORMAT_TIMEZONE_RFC_FIELD = 23,			/**< @internal For 'Z' field alignment */
	DATE_TIME_FORMAT_FIELD_COUNT = 24 /**< @internal Field count */
} DateTimeFormatField;


/**
 * @enum DateTimeStyle
 * Defines the style for date and time.
 *
 * @since		1.0
 */
enum DateTimeStyle 
{
	DATE_TIME_STYLE_NONE = -1,	/**< The date time style: None */
	DATE_TIME_STYLE_FULL = 0,	/**< The date time style: Full */
	DATE_TIME_STYLE_LONG = 1,	/**< The date time style: Long */
	DATE_TIME_STYLE_MEDIUM = 2,	/**< The date time style: Medium */
	DATE_TIME_STYLE_SHORT = 3,	/**< The date time style: Short */
	DATE_TIME_STYLE_DATE_OFFSET = DATE_TIME_STYLE_SHORT + 1,	/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	DATE_TIME_STYLE_DATE_TIME = 8,								/*< @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	DATE_TIME_STYLE_DEFAULT = DATE_TIME_STYLE_MEDIUM			/**< The default date time style: Medium */
};

// Forward declaration
class NumberFormatter;

/**
 * @class		DateTimeFormatter
 * @brief		This class provides methods for formatting the date and time formats. 
 * @since		1.0
 *
 * The %DateTimeFormatter class is used to format the date and time formats in a language-independent manner. 
 * The date and time are represented as an Osp::Base::DateTime instance.
 * 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/datetime_formatter.htm">Date and Time Formatter</a>.
 *
 * @see		Osp::Base::DateTime, DateTimeSymbols
 *
 * The following example demonstrates how to use the %DateTimeFormatter class.
 *
 * @code
#include <FBase.h>
#include <FLocales.h>
#include <FSystem.h>

using namespace Osp::Base;
using namespace Osp::Locales;
using namespace Osp::System;

void
LocaleApp::DateTimeFormatterExample(void)
{
	String formattedString;

	// Construct locale
	Locale locale(LANGUAGE_ENG, COUNTRY_US);

	// Get today
	DateTime today;
	SystemTime::GetCurrentTime(UTC_TIME, today);

	// Get date formatter
	DateTimeFormatter* pDateFormatter = DateTimeFormatter::CreateDateFormatterN(locale, DATE_TIME_STYLE_DEFAULT);

	// Format today with date formatter
	pDateFormatter->Format(today, formattedString);

	// Get time formatter
	DateTimeFormatter* pTimeFormatter = DateTimeFormatter::CreateTimeFormatterN(locale, DATE_TIME_STYLE_DEFAULT);

	// Format today with date formatter
	pTimeFormatter->Format(today, formattedString);

	// Customized pattern
	String cutomizedPattern = L"EEE d MMM yy";
	pDateFormatter->ApplyPattern(cutomizedPattern);

	// Format today with date formatter
	pDateFormatter->Format(today, formattedString);

	delete pDateFormatter;
	delete pTimeFormatter;
}
@endcode
 *
 */
class _EXPORT_LOCALES_ DateTimeFormatter :
	public Osp::Base::Object
{
// Static Method
public:

	// DateFormatter
	/**
	 * Gets the date formatter with the specified formatting style for the system locale.
	 * 
	 * @since				1.0
    * @return			A pointer to the system locale date formatter, @n
  	  *     					else @c null if an error occurs
	 * @param[in]		style						The formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateFormatterN(DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);


	/** 
	 * Gets the date formatter with the specified formatting style for the specified locale.
	 * 
	 * @since				1.0
     * @return			A pointer to the specified locale date formatter, @n
  	  *     						else @c null if an error occurs
	 * @param[in]		locale						The locale
	 * @param[in]		style						The formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateFormatterN(const Locale& locale, DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);


	// TimeFormatter
	/**
	 * Gets the time formatter with the specified formatting style for the system locale.
	 * 
	 * @since				1.0
     * @return			A pointer to the system locale time formatter, @n
 	  *    						 else @c null if an error occurs
	 * @param[in]		style						The formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateTimeFormatterN(DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);


	/** 
	 * Gets the time formatter with the specified formatting style for the specified locale.
	 *
	 * 
	 * @since				1.0
    * @return			A pointer to the specified locale time formatter, @n
 	  *    					 else @c null if an error occurs
	 * @param[in]		style						The formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @param[in]		locale						The locale
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateTimeFormatterN(const Locale& locale, DateTimeStyle style = DATE_TIME_STYLE_DEFAULT);
		

	/**
	 * Gets the date/time formatter with the specified formatting style for the system locale.
	 * 
	 * @since				1.0
    * @return	A pointer to the system locale date/time formatter, @n
 	  *    			 else @c null if an error occurs
	 * @param[in]		dateStyle					The date formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @param[in]		timeStyle					The time formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateTimeFormatterN(DateTimeStyle dateStyle = DATE_TIME_STYLE_DEFAULT, DateTimeStyle timeStyle = DATE_TIME_STYLE_DEFAULT);


	/** 
	 * Gets the date/time formatter with the specified formatting style for the specified locale.
	 * 
	 * @since				1.0
     * @return		A pointer to the specified locale date/time formatter, @n
 	  *     					else @c null if an error occurs
	 * @param[in]		locale						The locale
	 * @param[in]		dateStyle					The date formatting style @n
	 *												For example, "M/d/yy" is the short form for displaying only date in the US locale.
	 * @param[in]		timeStyle					The time formatting style @n
	 *												For example, "h:mm a" is the short form for displaying the 12-hour time format in the US locale.
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateDateTimeFormatterN(const Locale& locale, DateTimeStyle dateStyle = DATE_TIME_STYLE_DEFAULT, DateTimeStyle timeStyle = DATE_TIME_STYLE_DEFAULT);


// Construct Operations
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~DateTimeFormatter(void);


// Operations
public:

	/**
	 * Formats a DateTime object into a date/time string and appends the resulting string to the specified string buffer.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		date				The DateTime object to format
	 * @param[out]		str					The string to append to the resultant string
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance is in an invalid state. @n
	 *										After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 * @remarks			This method does not handle the time zone information, so "z" pattern always returns "GMT+00:00".
	 * @see					Osp::Base::DateTime
	 */
	virtual result Format(const Osp::Base::DateTime& date, Osp::Base::String& str) const;


	/**
	 * Formats a Calendar object into a date/time string and appends the resulting string to the specified string buffer.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		calendar				The Calendar object to format
	 * @param[out]		str						The string to append to the resultant string
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state. @n
	 *											After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 * @see					Osp::Base::DateTime
	 */
	virtual result Format(const Calendar& calendar, Osp::Base::String& str) const;


private:

// Operation

	/** 
	 * Creates an @b uninitialized instance.
	 *
	 * @remarks		After creating an instance of this class, you must explicitly call the @e Construct() method
	 *				to initialize the instance. 
	 * @see Construct()
	 */
	DateTimeFormatter(void);

	/**
	 * Creates an instance and returns an instance of DateTimeFormatter with the specified styles and the locale
	 * or it returns @c null if some error occurs.
	 *
	 * @return			A pointer of DateTimeFormatter that is created
	 * @param[in]		dateSyle									A style for the Date
	 * @param[in]		timeStyle									A style for the Time
	 * @param[in]		locale										The locale
	 * @exception		E_SUCCESS									The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION						The specified @c locale is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static DateTimeFormatter* CreateInstanceN(const Locale& locale, DateTimeStyle dateStyle, DateTimeStyle timeStyle);


	// Operations
public:

	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* Initializes a SimpleDateTimeFormat using the given pattern and the default date format symbols for the given locale.
	* 
	* @since					1.0
	* @return					An error code
	* @param[in]			pattern		The pattern describing the date and time format
	* @param[in]			loc		The locale whose date format symbols should be used. 
	* @exception			E_SUCCESS								The method is successful.
	* @exception			E_INVALID_ARG							The specified @c pattern is invalid or its length is @c 0.
	*/
	result Construct(const Osp::Base::String& pattern, const Locale& loc);


	/**
	* @internal
	* This method is for internal use only. The bada platform team is not
	* responsible for any behavioral correctness, consistency, and
	* security-related issues that might arise after using this method.
	*
	* Initializes a SimpleDateTimeFormat using the given pattern and date format symbols. 
	* 
	* @since					1.0
	* @return					An error code
	* @param[in]			pattern		The pattern describing the date and time format
	* @param[in]			pSymbols	The pointer of date format symbols to be used for formatting
	* @exception			E_SUCCESS								The method is successful.
	* @exception			E_INVALID_ARG							The specified @c pattern is invalid or its length is @c 0.
	*/
	result Construct(const Osp::Base::String& pattern, const DateTimeSymbols* pSymbols = null);


	/** 
	* Applies the specified pattern string to the date format. 
	*
	* @since					1.0
	* @param[in]			pattern					The new date and time pattern for the date format
	* @exception			E_SUCCESS				The method is successful.
	* @exception			E_INVALID_ARG			The specified @c pattern is invalid or its length is @c 0.
	*/
	result ApplyPattern(const Osp::Base::String& pattern);


	/** 
	* Gets a pattern string describing the date format.
	*
	* @since			1.0
	* @return			A String describing the date format
	*/
	Osp::Base::String GetPattern(void) const;


	/** 
	* Gets the date and time format symbols of the formatter.
	*
	* @since				1.0
	* @return				A pointer to DateTimeSymbols for the formatter instance
	* @see					SetDateTimeSymbols()
	*/
	const DateTimeSymbols* GetDateTimeSymbols(void) const;


	/** 
	* Sets the date and time format symbols of the date format. 
	*
	* @since				1.0
	* @param[in]		newSymbols			The new date and time format symbols 
	* @see					GetDateTimeSymbols()
	*/
	void SetDateTimeSymbols(const DateTimeSymbols& newSymbols);


private:

	// Operation

	/** 
	* Initializes the instance of SimpleTimeDateFormat using the given pattern 
	* and the default date format symbols for the given locale.
	* 
	* @return				An error code
	* @param[in]			dateStyle									The date style
	* @param[in]			timeStyle									The time style
	* @param[in]			newLoc										The given locale
	* @exception			E_SUCCESS									The method is successful.
	* @exception			E_UNSUPPORTED_OPERATION						The specified @c locale is not supported.
	*/
	result Construct(DateTimeStyle dateStyle, DateTimeStyle timeStyle, const Locale& newLoc);


	/**
	* Initializes attributes of this instance.
	*
	* @return				An error code
	* @exception			E_SUCCESS									The method is successful.
	*/
	result Initialize(const Locale& locale);


	/**
	* Does the real date/time formatting.
	*
	* @return				An error code
	* @param[in]			cal											The Calendar object to format
	* @param[in]			ch											The pattern character
	* @param[in]			count										The count of remaining pattern character
	* @param[in]			pos											On input: an alignment field, if desired @n
																		On output: the offsets of the alignment field
	* @param[out]			str											The String where the formatted string is to be appended
	*/
	void SubFormat(Calendar& cal, mchar ch, int count, __FieldPosition& pos, Osp::Base::String& str) const;


	/**
	* Formats a number with the specified minimum and maximum number of digits 
	* and appends the result string to a given string buffer.
	*
	* @param[in]			value										The value to format
	* @param[in]			minDigits									The minimum number of digits
	* @param[in]			maxDigits									The maximum number of digits
	* @param[out]			str											The String where the formatted string is to be appended
	*/
	void ZeroPaddingNumber(int value, int minDigits, int maxDigits, Osp::Base::String& str) const;

	/**
	 * Formats a DateTime into a date/time string and appends the result string to a given string buffer.
	 *
	 * @return				An error code
	 * @param[in]			date										The DateTime object to format
	 * @param[in]			pos											On input: an alignment field, if desired @n
	 *																	On output: the offsets of the alignment field
	 * @param[out]			str											The String where the formatted string is to be appended
	 * @exception			E_SUCCESS									The method is successful.
	 * @exception			E_INVALID_STATE								This instance is in an invalid state. @n
	 *																	After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 * @see					Osp::Base::DateTime
	 */
	result Format(const Osp::Base::DateTime& date, __FieldPosition& pos, Osp::Base::String& str) const;


	/**
	 * Formats a Calendar into a date/time string and appends the result string to a given string buffer.
	 *
	 * @return				An error code
	 * @param[in]			cal											The Calendar object to format
	 * @param[in]			pos											On input: an alignment field, if desired @n
	 *																	On output: the offsets of the alignment field
	 * @param[out]			str											The String where the formatted string is to be appended
	 * @exception			E_SUCCESS									The method is successful.
	 * @exception			E_INVALID_STATE								This instance is in an invalid state. @n
	 *																	After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 * @see					Calendar()
	 */
	result Format(const Calendar& cal, __FieldPosition& pos, Osp::Base::String& str) const;


	// Attribute
	Osp::Base::String	__pattern;
	Locale __locale;
	DateTimeSymbols* __pSymbols; 	

	static const TimeField __PATTERN_INDEX_TO_CALENDAR_FIELD[];
	static const DateTimeFormatField __PATTERN_INDEX_TO_DATE_FORMAT_FIELD[];

protected:
	// Attribute
	
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
	NumberFormatter* __pNumberFormat;

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
	Calendar* __pCalendar;


private:
	friend class DateTimeFormatterEx;
	class DateTimeFormatterEx* __pDateTimeFormatterEx;
}; // DateTimeFormatter
} }// Osp::Locales

#endif//_FLCL_DATE_TIME_FORMATTER_H_

