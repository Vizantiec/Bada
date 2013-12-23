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
 * @file		FLclDateTimeSymbols.h 
 * @brief		This is the header file for the %DateTimeSymbols class.
 *
 * This header file contains the declarations of the %DateTimeSymbols class. 
 *  
 */
#ifndef	_FLCL_DATE_TIME_SYMBOLS_H_
#define	_FLCL_DATE_TIME_SYMBOLS_H_


// Includes
#include "FBaseColArrayList.h"
#include "FLclConfig.h"
#include "FLclLocale.h"
#include "FLclCalendar.h"

namespace Osp { namespace Locales {

/**
 * @class		DateTimeSymbols
 * @brief		This class provides methods that help in providing date and time symbols.
 * @since		1.0
 *
 * The %DateTimeSymbols class is used for encapsulating localizable date-time formatting data, such as the names of the months, the days of the week, and the time zone data.
 * It is also used by DateTimeFormatter.
 * %DateTimeSymbols specifies the exact character strings to use for various parts of a date or time. For example, the names of the months and days of the week, the strings for AM and PM, and the day of the week considered to be the first day of the week.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/datetime_formatter.htm">Date and Time Formatter</a>.
 * @see			Osp::Locales::DateTimeFormatter
 *	
 */
class _EXPORT_LOCALES_ DateTimeSymbols :
	public Osp::Base::Object
{

public:

// Construct Operations

	/** 
	 * This is the default constructor for this class. @n
	 * This creates an uninitialized instance for the class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see				Construct()
	 */
	DateTimeSymbols(void);
	
	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~DateTimeSymbols(void);


// Operations
	/** 
	 * Initializes this instance of %DateTimeSymbols with the specified @c locale and @c calendarType.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			locale							The locale
	 * @param[in]			calendarType					The calendar type
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION			The specified @c locale or @c calendarType is not supported.
	 */
	result Construct(const Locale& locale, CalendarType calendarType = CALENDAR_GREGORIAN);


	/** 
	 * Initializes this instance of %DateTimeSymbols with the specified parameter. @n
	 * This method loads the format data from the resources for the default locale into the default calendar.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			calendarType					The calendar type
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION			The specified @c calendarType is not supported.
	 */
	result Construct(CalendarType calendarType);


 	/** 
	 * Initializes this instance of %DateTimeSymbols with the specified parameter.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			other							An instance of DateTimeSymbols
	 * @exception			E_SUCCESS						The method is successful.
	 * @exception			E_SYSTEM						A system error has occurred.
	 */
	result Construct(const DateTimeSymbols& other);


	/** 
	 * Gets the list of the era strings. @n
	 * For example: "AD" and "BC".
	 *
	 * @since					1.0
	 * @return				A pointer to the list of era strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetEras()
	 */
	const Osp::Base::Collection::IList* GetEras(void) const;


	/** 
	 * Sets the era strings. @n
	 * Multiple strings can be concatenated by '|'. For example: "AD|BC".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			eras						The era strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c eras contains an invalid value.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @see						GetEras()
	 */
	result SetEras(const Osp::Base::String& eras);
	

	/** 
	 * Gets the list of the month name strings. @n
	 * For example: "January", "February", etc.
	 *
	 * @since					1.0
	 * @return				A pointer to the list of month name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetMonths()
	 */
	const Osp::Base::Collection::IList* GetMonths(void) const;


	/** 
	 * Sets the month name strings concatenated by '|'. @n
	 * For example: "January|February|March|April|May|June|July|August|September|October|November|December".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			months						The new month strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c months contains an invalid value.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @see						GetMonths()
	 */
	result SetMonths(const Osp::Base::String& months);


	/** 
	 * Gets the list of the short month name strings. @n
	 * For example: "Jan", "Feb", etc.
	 *
	 * @since					1.0
	 * @return				A pointer to the list of short month name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetShortMonths()
	 */
	const Osp::Base::Collection::IList* GetShortMonths(void) const;


	/** 
	 * Sets the short month name strings concatenated by '|'. @n
	 * For example: "Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			shortMonths				The new short month name strings concatenated by '|' 
	 * @exception			E_SUCCESS				The method is successful.
	 * @exception			E_INVALID_ARG			The specified @c shortMonths contains an invalid value. See the valid string in the description of the method.
	 * @exception			E_INVALID_STATE			This instance has not been constructed as yet.
	 * @see						GetShortMonths()
	 */
	result SetShortMonths(const Osp::Base::String& shortMonths);


	/** 
	 * Gets the list of the weekday name strings. @n
	 * For example: "Sunday", "Monday", etc.
	 *
	 * @since					1.0
	 * @return				A pointer to the list of weekday name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetWeekdays()
	 */
	const Osp::Base::Collection::IList* GetWeekdays(void) const;


	/** 
	 * Sets the weekday name strings concatenated by '|'. @n
	 * For example: "Sunday|Monday|Tuesday|Wednesday|Thursday|Friday|Saturday".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			weekdays					The new weekday name strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c weekdays contains an invalid value.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet. 
	 * @see						GetWeekdays()
	 */
	result SetWeekdays(const Osp::Base::String& weekdays);


	/** 
	 * Gets the list of the short weekday name strings. @n
	 * For example: "Sun", "Mon", etc.
	 *
	 * @since					1.0
	 * @return				A pointer to the list of short weekday name strings, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetShortWeekdays()
	 */
	const Osp::Base::Collection::IList* GetShortWeekdays(void) const;


	/** 
	 * Sets the weekday name strings concatenated by '|'. @n
	 * For example: "Sun|Mon|Tue|Wed|Thu|Fri|Sat".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			shortWeekdays				The new short weekday strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c shortWeekdays contains an invalid value.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @see						GetShortWeekdays()
	 */
	result SetShortWeekdays(const Osp::Base::String& shortWeekdays);


	/** 
	 * Gets the list of the AM/PM strings. @n
	 * For example: "AM" and "PM".
	 *
	 * @since					1.0
	 * @return				A pointer to the list of AM/PM strings, @n
 	 *						else @c null if this instance has not been constructed as yet
	 * @see						SetAmPm()
	 */
	const Osp::Base::Collection::IList* GetAmPm(void) const;


	/** 
	 * Sets the AM/PM strings concatenated by '|'. @n
	 * For example: "AM|PM".
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			amPm						The new AM/PM strings concatenated by '|'
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_ARG				The specified @c amPm contains an invalid value.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @see						GetAmPm()
	 */
	result SetAmPm(const Osp::Base::String& amPm);


	/** 
	 * Gets the name of the time zone. @n
	 * For example: "Eastern European Time (EET)", "Eastern European Summer Time (EEST)".
	 *
	 * @since					1.0
	 * @return				The time zone name, @n
	 *								else an empty string if @c timeZoneId is not found
	 * @param[in]	timeZoneId		The time zone ID
	 * @param[in]	timeZoneStyle	The parameter may contain one of the following time zone styles:
	 *								@li The normal time zone (0)
	 *								@li The abbreviated time zone (1)
	 *								@li The normal summer time zone (2)
	 *								@li The abbreviated summer time zone (3)
	 * @see							SetTimeZoneName(), AddTimeZoneName()
	 */
	Osp::Base::String GetTimeZoneName(Osp::Base::String& timeZoneId, int timeZoneStyle = 0);


	/**
	 * Sets the time zone name string related to the specified time zone ID.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			timeZoneId							The time zone ID @n
	 *															For example: "Europe/Helsinki".
	 * @param[in]			concatenatedTimeZoneName			The new concatenated time zone name @n
	 *															For example, "Eastern European Time|EET|Eastern European Summer Time|EEST"
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_INVALID_ARG		The specified @c timeZoneId or @c concatenatedTimeZoneName contains an invalid value.
	 * @exception			E_INVALID_STATE		This instance has not been constructed as yet. 
	 * @exception			E_OBJ_NOT_FOUND		The specified @c timeZoneId is not found.
	 * @see						GetTimeZoneName(), AddTimeZoneName()
	 */
	result SetTimeZoneName(const Osp::Base::String& timeZoneId, const Osp::Base::String& concatenatedTimeZoneName);


	/**
	 * Adds a new time zone name string that is related to time zone ID.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			timeZoneId							The time zone ID @n
	 *															For example: "Europe/Helsinki".
	 * @param[in]			concatenatedTimeZoneName			The concatenated time zone name @n
	 *															For example, "Eastern European Time|EET|Eastern European Summer Time|EEST"
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception			E_INVALID_STATE		This instance has not been constructed as yet. 
	 * @exception			E_OBJ_ALREADY_EXIST	The specified @c timeZoneId already exists.
	 * @see					GetTimeZoneName(), SetTimeZoneName()
	 */
	result AddTimeZoneName(const Osp::Base::String& timeZoneId, const Osp::Base::String& concatenatedTimeZoneName);


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Returns the non-localized date-time pattern characters.
	 *
	 * @since					1.0
	 * @return				The non-localized date-time pattern characters
	 * @param[out]		chars							The non-localized date-time pattern characters
	 */
	static Osp::Base::McharBuffer* GetNonLocalizedDateTimePatternN(void);


private:
	DateTimeSymbols(const DateTimeSymbols& symbol);
	DateTimeSymbols& operator=(const DateTimeSymbols& symbol);

// Operation

	/**
	 * Initializes the attributes of the current instance with the specified locale and calendar type.
	 *
	 * @return					An error code
	 * @param[in]				locale				An instance of Locale
	 * @param[in]				calendarType		The calendar type
	 * @exception				E_SUCCESS					The method is successful.
	 * @exception				E_UNSUPPORTED_OPERATION		The specified @c calendarType is not supported.
	 */
	result Initialize(const Locale& locale, CalendarType calendarType);

	/** 
	 * Replaces all the elements of the current instance of DateTimeSymbols with the elements of the specified instance of DateTimeSymbols.
	 *
	 * @param[in]			other					The other DateTimeSymbols
	 */
	void Set(const DateTimeSymbols &other);

	Osp::Base::Collection::IList* CloneArrayListN(const Osp::Base::Collection::IList* pList) const;
	Osp::Base::Collection::IMap* CloneHashMapN(const Osp::Base::Collection::IMap* pMap) const;
	bool IsConstructed(void) const;
	void ReleaseList(Osp::Base::Collection::IList* pList);
	result SetList(Osp::Base::Collection::IList** ppList, int tokenCount, const Osp::Base::String& stringWillBeTokenized);


// Attribute
	Osp::Base::Collection::IList* __pErasList;
	Osp::Base::Collection::IList* __pMonthsList;
	Osp::Base::Collection::IList* __pShortMonthsList;
	Osp::Base::Collection::IList* __pWeekdaysList;
	Osp::Base::Collection::IList* __pShortWeekdaysList;
	Osp::Base::Collection::IList* __pAmPmList;
	Osp::Base::Collection::IMap* __pTimeZonesMap;

	friend class DateTimeFormatter;


private:
	friend class DateTimeSymbolsEx;
	class DateTimeSymbolsEx* __pDateTimeSymbolsEx;

}; // DateTimeSymbols

} }// Osp::Locales

#endif//_FLCL_DATE_TIME_SYMBOLS_H_

