/* $Change: 1233246 $ */
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
 * @file	FSclCalEvent.h
 * @brief	This is the header file for the %CalEvent class.
 *
 * This header file contains the declarations of the %CalEvent class.
 */
#ifndef _FSCL_CALEVENT_H_
#define _FSCL_CALEVENT_H_

// Includes
#include "FBaseColIList.h"
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FBaseDateTime.h"
#include "FLclCalendar.h"

#include "FSocialTypes.h"
#include "FSclRecord.h"
#include "FSclReminder.h"
#include "FSclRecurrence.h"
#include "FSclAttendee.h"

namespace Osp { namespace Social {

// Enums and Constants
/**
* @enum		EventCategory
* @brief	Defines the categories to classify the event.
*
* @since 	1.0
*/
typedef enum {
	EVENT_CATEGORY_APPOINTMENT	= 0x00000001,		/**< The appointment category*/
	EVENT_CATEGORY_ANNIVERSARY	= 0x00000002,		/**< The anniversary category */
} EventCategory;

/**
* @enum		EventPriority
* @brief	Defines the possible priority levels of the event.
*
* @since 	1.0
*/
typedef enum {
	EVENT_PRIORITY_LOW,			/**< The low priority */
	EVENT_PRIORITY_NORMAL,		/**< The normal priority */
	EVENT_PRIORITY_HIGH			/**< The high priority */
} EventPriority;

/**
* @enum		EventStatus
* @brief	Defines the possible statuses of the event.
*
* @since 	1.0
*/
typedef enum {
	EVENT_STATUS_NONE,		/**< The none status	*/
	EVENT_STATUS_CONFIRMED,	/**< The confirmed status	*/
	EVENT_STATUS_CANCELLED,	/**< The canceled status	*/
	EVENT_STATUS_TENTATIVE	/**< The tentative status	*/
} EventStatus;

/**
* @enum		BusyStatus
* @brief	Defines the busy statuses of the event.
*
* @since 	1.0
*/
typedef enum {
	BUSY_STATUS_FREE,			/**< The free status	*/
	BUSY_STATUS_BUSY,			/**< The busy status	*/
	BUSY_STATUS_UNAVAILABLE,	/**< The unavailable status	*/
	BUSY_STATUS_TENTATIVE		/**< The tentative status	*/
} BusyStatus;


/** The maximum length of the subject field.
*
*	@since	1.0
*/
static const int MAX_EVENT_SUBJECT_LENGTH			= 100;
/** The maximum length of the description field. 
*
*	@since	1.0
*/
static const int MAX_EVENT_DESCRIPTION_LENGTH		= 1000;
/** The maximum length of the location field. 
*
*	@since	1.0
*/
static const int MAX_EVENT_LOCATION_LENGTH			= 100;
/** All the event categories. 
*
*	@since	1.0
*/
static const unsigned long EVENT_CATEGORY_ALL			= EVENT_CATEGORY_APPOINTMENT | EVENT_CATEGORY_ANNIVERSARY;

/**
 * @enum CalEventPropertyId
 * Defines the IDs for accessing the properties of %CalEvent.
 * The property ID is used for IRecordEventListener::OnRecordChangedN().
 *
 * @deprecated	This enum is deprecated because it is not used any more.
 * @since	1.0
 */
enum CalEventPropertyId {
	CALEVENT_PROPERTY_ID_ALL_DAY_EVENT,			/**< An ID for the all day event property */
	CALEVENT_PROPERTY_ID_TIME_ZONE,				/**< An ID for the time zone property */
	CALEVENT_PROPERTY_ID_SUBJECT,				/**< An ID for the subject property */
	CALEVENT_PROPERTY_ID_DESCRIPTION,			/**< An ID for the description property */
	CALEVENT_PROPERTY_ID_TIME,					/**< An ID for the start and end time property */
	CALEVENT_PROPERTY_ID_LOCATION,				/**< An ID for the location property */
	CALEVENT_PROPERTY_ID_CATEGORY,				/**< An ID for the category property */
	CALEVENT_PROPERTY_ID_SENSITIVITY,			/**< An ID for the sensitivity property */
	CALEVENT_PROPERTY_ID_REMINDER,				/**< An ID for the reminder property */
	CALEVENT_PROPERTY_ID_RECURRENCE,			/**< An ID for the recurrence property */
	CALEVENT_PROPERTY_ID_RECURRENCE_EXCEPTION,	/*<	[NOT SUPPORTED] An ID for the recurrence exception property */
	CALEVENT_PROPERTY_ID_STATUS,				/**< An ID for the status property */
	CALEVENT_PROPERTY_ID_BUSY_STATUS,			/**< An ID for the busy status property */
	CALEVENT_PROPERTY_ID_PRIORITY,				/**< An ID for the priority property */
	CALEVENT_PROPERTY_ID_ATTENDEE,				/**< An ID for the attendee property */
	CALEVENT_PROPERTY_ID_UID,					/**< An ID for the globally unique ID property */
	CALEVENT_PROPERTY_ID_TIME_STAMP,			/**< An ID for the timestamp property
												 * @deprecated   This enum value is deprecated because the timestamp property is not proper for the calendar event.								 
												 */
	CALEVENT_PROPERTY_ID_LAST_REVISION			/**< An ID for the calendar date and time of the last update in Coordinated Universal Time (UTC). Read-only (#DateTime type)  @b since: @b 2.0 */
};

/**
 *	@class	CalEvent
 *	@brief	This class provides the methods to manage the information of a calendar book event.
 *	@since	1.0
 *
 *	The %CalEvent class describes an occasion planned in a particular situation. @n
 *  An event is a subset of vEvent. A %CalEvent instance includes the category, subject, description, start time, end time, location, and sensitivity.  
 *  %CalEvent also includes the recurring and reminder data. For more information, see the Recurrence, and Reminder classes.
 *  
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/calevent.htm">Calendar Events</a>.
 *
 *  The following example demonstrates how to use the %CalEvent class.

 *	@code
 *
	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Osp::Base;
	using namespace Osp::Social;
	using namespace Osp::Locales;

	void
	CreateCalEventWithTimeZone(void)
	{
		DateTime startWallTime, endWallTime;
		DateTime startUtcTime, endUtcTime;

		// Suppose a user set 2010/2/17 12:00:00 ~ 2010/2/17 14:00:00 in wall time for start/end time.
		startWallTime.SetValue(2010, 2, 17, 12, 0, 0);
		endWallTime.SetValue(2010, 2, 17, 14, 0, 0);

		// Gets the system time zone.
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();

		// Converts the wall time to UTC time before set start and end time of the event.
		startUtcTime = timeZone.WallTimeToUtcTime(startWallTime);
		endUtcTime = timeZone.WallTimeToUtcTime(endWallTime);

		// Creates an event.
		CalEvent event;

		// Sets the values.
		event.SetTimeZone(timeZone);
		event.SetStartAndEndTime(startUtcTime, endUtcTime);
	}
 *
 * @endcode
 *
 */
class  _EXPORT_SOCIAL_ CalEvent:
	public Osp::Social::Record
{
	friend class Osp::Social::__CalendarbookPi;

// Enums and Constants
public:


// Construct Operation
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	CalEvent(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~CalEvent(void);

	/**
	 * This is the copy constructor for the %CalEvent class.
	 *
	 * @since		1.0
	 *
	 * @param[in]	value		An instance of %CalEvent
	 */
	CalEvent(const CalEvent& value);

	/**
	 * Copies the data contained in the specified instance of %CalEvent to the current instance.
	 *
	 * @since		1.0
	 *
	 * @param[in]	value		An instance of %CalEvent
	 */
	CalEvent& operator =(const CalEvent& value);

// Get/Set operation
public:

	/**
	 * Checks whether this instance is a %CalEvent instance. @n
	 * A one-time calendar event has only one instance and a recurring calendar event has more than one instance. @n
	 * Each instance of %CalEvent has its own recurrence ID.
	 *
	 * @since		1.0
	 *
	 * @return		@c true if this instance is a %CalEvent instance, @n
	 *				else @c false
	 */
	bool	IsInstance(void) const;

	/**
	 * Checks whether the calendar event has a recurring pattern.
	 *
	 * @since		1.0
	 *
	 * @return		@c true if the calendar event has a recurring pattern, @n
	 *				else @c false
	 */
	bool	IsRecurring(void) const;

	/**
	 * Gets the original calendar event ID. @n
	 * The %CalEvent instance has an original @c CalEventId, that is a record ID of its entry.
	 *
	 * @since	1.0
	 *
	 * @return	The original calendar event ID, @n
	 *			else #INVALID_RECORD_ID if the record ID is invalid
	 */
	RecordId	GetOriginalCalEventId(void)	const;

	/**
	 * Checks whether the calendar event is an all day event.
	 *
	 * @since		1.0
	 *
	 * @return		@c true if calendar event is an all day event, @n
	 *				else @c false
	 */
	bool	IsAllDayEvent(void) const;

	/**
	 * Sets the calendar event as an all day event.
	 *
	 * @since		1.0
	 *
	 * @param[in]	isAllDayEvent	Set to @c true to make the calendar event an all day event, @n
	 *								else @c false
	 */
	void	SetAllDayEvent(bool isAllDayEvent);

	/**
	 * Gets the globally unique ID. @n
	 * UID: globally Unique IDentifier (vCalendar 1.0)
	 *
	 * @since		1.0
	 *
	 * @return		The globally unique ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::ByteBuffer*    GetUIDN(void) const;

	/**
	 * Sets the globally unique ID.
	 * UID: globally Unique IDentifier (vCalendar 1.0)
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	pUID					The globally unique ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result	SetUID(const Osp::Base::ByteBuffer* pUID);

	/**
	 * Gets the timestamp. @n
	 * If the timestamp value is not set, this method returns the minimum value of DateTime, that can be retrieved by DateTime::GetMinValue() (that is, 
	 * "January 1 1 00:00:00").
	 *
	 * @deprecated	This method is deprecated because the timestamp property is not proper for the calendar event.
	 * @since		1.0
	 *
	 * @return		The timestamp
	 */
	Osp::Base::DateTime		GetTimeStamp(void) const;

	/**
	 * Sets the timestamp.
	 *
	 * @deprecated	This method is deprecated because the timestamp property is not proper for the calendar event.
	 * @since		1.0
	 *
	 * @param[in]	timeStamp	The timestamp
	 */
	void		SetTimeStamp(const Osp::Base::DateTime& timeStamp);
	
	/**
	 * Gets the calendar event status. @n
	 * The default status is #EVENT_STATUS_NONE.
	 *
	 * @since		1.0
	 *
	 * @return		The calendar event status
	 * @see			EventStatus
	 */
	EventStatus	GetStatus(void) const;
	
	/**
	 * Sets the calendar event status.
	 *
	 * @since		1.0
	 *
	 * @param[in]	status		The status
	 * @see			EventStatus
	 */
	void	SetStatus(EventStatus status);

	/**
	 * Gets the busy status. @n
	 * The default busy status is #BUSY_STATUS_BUSY.
	 *
	 * @since		1.0
	 *
	 * @return		The busy status
	 * @see			BusyStatus
	 */
	BusyStatus	GetBusyStatus(void) const;

	/**
	 * Sets the busy status.
	 *
	 * @since		1.0
	 *
	 * @param[in]	busyStatus		The busy status
	 * @see			BusyStatus
	 */
	void	SetBusyStatus(BusyStatus busyStatus);

	/**
	 * Gets the priority level of the calendar event. @n
	 * The default priority level is #EVENT_PRIORITY_LOW.
	 *
	 * @since		1.0
	 *
	 * @return		The priority level
	 *
	 */
	EventPriority	GetPriority(void) const;

	/**
	 * Sets the priority level of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @param[in]	priority	The priority level to be set
	 *
	 */
	void	SetPriority(EventPriority priority);

	/**
	 * Adds an attendee.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	attendee			The attendee to be added  @n
	 *									The specified @c attendee must have an email address.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	An attendee with the same email address already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The attendee values may be lost if an anniversary event including the attendee is modified in the base application.
	 */
	result AddAttendee(const Attendee& attendee);

	/**
	 * Removes an attendee.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	attendee			The attendee to be removed  @n
	 *									The specified @c attendee must have an email address.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		An attendee that has the same email address is not found.
	 */
	result RemoveAttendee(const Attendee& attendee);

	/**
	 * Gets a list of all the attendees.
	 *
	 * @since		1.0
	 *
	 * @return		A list of the attendees
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Attendee
	 */
	Osp::Base::Collection::IList* GetAllAttendeesN(void) const;

	/**
	 * Gets the time zone.
	 *
	 * @since		1.0
	 *
	 * @return		The time zone
	 * @see			Osp::Locales::TimeZone
	 */
	Osp::Locales::TimeZone	GetTimeZone(void) const;

	/**
	 * Sets the time zone. @n
	 * Recurrence is calculated based on the time zone, thus the time zone must be set before setting a recurrence. 
	 * If the time zone is not set, it will be considered as Greenwich Mean Time (GMT) 0. 
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	timeZone			The time zone to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @remarks		As anniversaries and all day events are not affected by a time zone, it is recommended not to set the time zone. 
	 * @see			Osp::Locales::TimeZone
	 */
	result	SetTimeZone (const Osp::Locales::TimeZone& timeZone);

	/**
	 * Gets a list of all the instances generated from a calendar event entry. @n
	 * If an event is a one-time calendar event, only one instance is returned. @n
	 * Otherwise, a list of instances generated from the recurrence information is returned. @n
	 * The result list will be sorted by the start date of the instances. @n
	 *
	 * Instead of using this method, use the Calendarbook::GetEventInstancesN() method.
	 *
	 * @deprecated	This method is deprecated, as the method cannot successfully work if the number of recurrence instances is too large.
	 * @since		1.0
	 *
	 * @return		A list of calendar events
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The current event is a %CalEvent instance that has a recurrence ID.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				This method may cause an abnormal operation when the number of recurrence instances is too large (the number of limits depends upon the 
	 *				resources available on a device).
	 * 				It is recommended to use the Calendarbook::GetEventInstancesN() method rather than using this method in this case.
	 * @see			CalEvent
	 */
	Osp::Base::Collection::IList*	GetInstancesN(void) const;

	/**
	 * Gets the specified @c recurrenceId of the calendar event.
	 *
	 * @deprecated	This method is deprecated because it is not commonly used.
	 * @since		1.0
	 *
	 * @return		The %CalEvent instance of the @c recurrenceId
	 * @param[in]	recurrenceId			The recurrence ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The current event is a %CalEvent instance that has a recurrence ID.
	 * @exception	E_INVALID_ARG			The specified @c recurrenceId is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	CalEvent*	GetInstanceN(const RecurrenceId& recurrenceId) const;

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Adds a recurrence exception (exdate type). @n
	 * The instance with the specified recurrenceId is excluded from the recurrence set. @n
	 * This method works only for recurring CalEvent entries.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	recurrenceId	The recurrenceId to add the exception(exdate)
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is a CalEvent instance( has a RecurrenceId).
	 * @exception	E_INVALID_ARG			The specified @c recurrenceId is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST		The recurrenceId has already been added.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 */
	result AddRecurrenceException(const RecurrenceId& recurrenceId);

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Adds a recurrence exception (change type). @n
	 * The changed properties of the specified event instance are applied to the recurrence set. @n
	 * This method works only for recurring CalEvent entries.
	 *
	 * @since			1.0
	 *
	 * @return		An error code
	 * @param[in]	instance	The instance to add the change exception
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is a CalEvent instance (has a RecurrenceId).
	 * @exception	E_INVALID_ARG			The specified @c recurrenceId is invalid.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 */
	result AddRecurrenceException(const CalEvent& instance);

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Updates a recurrence exception (change type). @n
	 * This method works only for recurring CalEvent entries.
	 *
	 * @since			1.0
	 *
	 * @return		An error code
	 * @param[in]	instance	The instance to update the change exception
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is a CalEvent instance( has a RecurrenceId).
	 * @exception	E_INVALID_ARG			The specified @c recurrenceId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c recurrenceId is not found.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 */
	result UpdateRecurrenceException(const CalEvent& instance);

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Removes a recurrence exception (exdate and change types). @n
	 * This method works only for recurring CalEvent entries.
	 *
	 * @since			1.0
	 *
	 * @return		An error code
	 * @param[in]	recurrenceId			The recurrenceId to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is a CalEvent instance( has a RecurrenceId).
	 * @exception	E_INVALID_ARG			The specified @c recurrenceId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c recurrenceId is not found.
	 */
	result RemoveRecurrenceException(const RecurrenceId& recurrenceId);

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Gets a list of recurrence exceptions. @n
	 * If the type is RECURRENCE_EXCEPTION_TYPE_EXDATE, the list consists of RecurrenceId instances.
	 * Or if the type is RECURRENCE_EXCEPTION_TYPE_CHANGE, the list consists of CalEvent instances.
	 * This method works only for recurring CalEvent entries.
	 *
	 * @since			1.0
	 *
	 * @return		A list of the RecurrenceIds which belong to the specified recurrence type
	 * @param[in]	type					The type of recurrence exception
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is a CalEvent instance( has a RecurrenceId).
	 * @exception	E_INVALID_ARG			The specified @c type is invalid.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			RecurrenceId, CalEvent
	 */
	Osp::Base::Collection::IList* 	GetRecurrenceExceptionsN(RecurrenceExceptionType type) const;

	/**
	 * Gets the recurrence ID. @n
	 * This method works only for the %CalEvent instances.
	 *
	 * @since		1.0
	 *
	 * @return		The recurrence ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance is a %CalEvent instance that does not have a recurrence ID.
	 */
	RecurrenceId	GetRecurrenceId(void) const;

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Gets the recurrence exception type. @n
	 * This method works only for CalEvent instances.
	 *
	 * @since			1.0
	 *
	 * @return		The Recurrence exception type
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance does not have recurrence or is not a CalEvent instance (does not have a RecurrenceId).
	 */
	RecurrenceExceptionType 	GetRecurrenceExceptionType(void) const;

	/**
	 * Gets the subject of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		The subject, @n
	 *				else @c null if there is no subject value
	 *
	 */
	Osp::Base::String GetSubject(void) const;

	/**
	 * Gets the description of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		The description
	 *
	 */
	Osp::Base::String GetDescription(void) const;

	/**
	 * Gets the start date and time of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An instance of DateTime representing the start date and time
	 *
	 */
	Osp::Base::DateTime GetStartTime(void) const;

	/**
	 * Gets the end date and time of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An instance of %DateTime representing the end date and time
	 *
	 */
	Osp::Base::DateTime GetEndTime(void) const;

	/**
	 * Gets the location of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		The location
	 *
	 */
	Osp::Base::String GetLocation(void) const;

	/**
	 * Gets the category of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		The category of the calendar event
	 *
	 */
	EventCategory GetCategory(void) const;

	/**
	 * Gets the sensitivity of the calendar event. @n
	 * The default value is #SENSITIVITY_PUBLIC.
	 *
	 * @since		1.0
	 *
	 * @return		The sensitivity of the calendar event
	 *
	 */
	RecordSensitivity GetSensitivity(void) const;


	/**
	 * Gets the reminder for the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		A pointer to an instance of Reminder, @n
	 *				else @c null if the reminder is not set
	 *	
	 */
	const Reminder* GetReminder(void) const;

	/**
	 * Gets the recurrence of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		A pointer to an instance of %Recurrence, @n
	 *				else @c null if the event is not a recurring event
	 *
	 */
	const Recurrence* GetRecurrence(void) const;

	/**
	 * Gets the last updated date and time of the calendar event.
	 *
	 * @since		2.0
	 *
	 * @return		The last updated date and time
	 */
	Osp::Base::DateTime GetLastRevisedTime(void) const;

	/**
	 * Sets the subject of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	subject				The subject of the calendar event
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c subject exceeds #MAX_EVENT_SUBJECT_LENGTH.
	 */
	result SetSubject(const Osp::Base::String& subject);

	/**
	 * Sets the description of the current calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	description			The description of the event
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c description exceeds #MAX_EVENT_DESCRIPTION_LENGTH.
	 */
	result SetDescription(const Osp::Base::String& description);

	/**
	 * Sets the start and end date and time of the calendar event. @n
	 * If the start date and time is not fixed, the default date and time are set. @n
	 * The default start date and time is the current date and time. @n
	 * The start date and time must be earlier than or equal to the end date and time. @n
	 * If the recurrence date is already set, this method returns an exception.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	start				The start date and time
	 * @param[in]	end					The end date and time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c dtEnd value is earlier than the specified @c dtStart value.
	 * @exception	E_INVALID_CONDITION	The recurrence date is already set.
	 * @remarks		The start and end time of the anniversary and all day events created from the base applications is the local time of the location where 
	 *				they are added. @n
	 *				All the other events are Coordinated Universal Time (UTC). @n 
	 *				In order to integrate it with the base applications, set the start and end time properly according to the above guidelines. @n
	 * 				If the seconds value of the start time is set, the alarm will not be fired.
	 * @remarks		There is no automatic time conversion based on the time zone property of the calendar event.
	 */
	result SetStartAndEndTime(const Osp::Base::DateTime& start, const Osp::Base::DateTime& end);


	/**
	 * Sets the location of the current calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	location			The location of the event
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c location exceeds #MAX_EVENT_LOCATION_LENGTH.
	 */
	result SetLocation(const Osp::Base::String& location);

	/**
	 * Sets the category of the calendar event. @n
	 * If the category is not set, the default category (#EVENT_CATEGORY_APPOINTMENT) is set.
	 *
	 * @since		1.0
	 *
	 * @param[in]	category			The category of the event
	 * @remarks		The start and end time of the anniversary and all day events created from the base applications, is the local time of the location where 
	 *				they are added. @n
	 *				All the other events are Coordinated Universal Time (UTC). @n 
	 *				In order to integrate it with the base applications, set the start and end time properly according to the above guidelines.
	 */
	void SetCategory(EventCategory category);

	/**
	 * Sets the sensitivity of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @param[in]	sensitivity		The sensitivity of the calendar event
	 */
	void  SetSensitivity(RecordSensitivity sensitivity);


	/**
	 * Sets the reminder of the calendar event.
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	pReminder				The reminder to be set, @n
	 *										else @c null to remove the previous reminder
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *
	 * The following example demonstrates how to use this method.
	 * @code
	 * MyClass::SetEventReminder(void)
	 * {
	 *    result r = E_SUCCESS;
	 *    Reminder* pReminder = new Reminder();
	 *
	 *    pReminder->SetMinutesBefore(10);
	 *
	 *    r = __pCalEvent->SetReminder(pReminder);
	 *
	 *    delete pReminder;
	 *
	 * }
	 * @endcode
	 */
	result SetReminder(const Reminder* pReminder);

	/**
	 * Sets the recurrence of the calendar event. @n
	 * Recurrences for categories such as Anniversary only accept a yearly pattern. @n  
	 * The recurrence rule date should be equal to the start date of the event. @n
	 * If the event start date is different than the recurrence rule date, the event start date is set to match the recurrence rule date. @n
	 * For example, if an event start date is 17/02/2010, that is Wednesday and the recurrence rule date is Thursday of every week,
	 * the event start date changes to 18/02/2010, after this method is called. @n
	 * Note that the start/end date and the time zone must be set before setting a recurrence. 
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	pRecurrence				The recurrence to be set, @n
	 *										else @c null to remove the previous recurrence
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The current event is a %CalEvent instance that has a recurrence ID.
	 * @exception	E_TYPE_MISMATCH			The recurrence pattern is not a yearly pattern in case of the event being an Anniversary.
	 * @exception	E_INVALID_CONDITION		Either of the following conditions has occurred: @n
	 *										- The recurrence rule date is earlier than the start or end date and time of the event. @n
	 *										- The recurrence rule is invalid, for example the rule 2/30/2010 for a yearly pattern. @n
	 *										- The duration of the event is too long. @n
	 *										   It should be shorter than the (interval x frequency) days set for the recurrence rule.
	 * @exception   E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- When the frequency is #FREQ_WEEKLY, #DayOfWeek is not set. @n
	 *										- When the frequency is #FREQ_MONTHLY, neither #DayOfMonth nor #DayOfWeek and #WeekOfMonth are not set. @n
	 *										- When the frequency is #FREQ_YEARLY, neither #DayOfMonth and #MonthOfYear nor #DayOfWeek, 
	 *										   #WeekOfMonth and #MonthOfYear are not set. @n
	 *										- When the frequency is #FREQ_YEARLY and #MonthOfYear is 2, #DayOfMonth is greater than 29 ( > 29 ). @n
	 *										- When the frequency is #FREQ_YEARLY and #MonthOfYear is 4 or 6 or 9 or 11, 
	 *										   #DayOfMonth is greater than 30 ( > 30 ).
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *
	 * The following example demonstrates how to use this method.
	 * @code
	 * MyClass::SetEventRecurrence(void)
	 * {
	 *	result r = E_SUCCESS;
	 *	Recurrence* pRecurrence = new Recurrence();
	 *
	 *	pRecurrence->SetFrequency(FREQ_WEEKLY);
	 *	pRecurrence->SetDayOfWeek(CAL_MONDAY);
	 *
	 *	r = __pCalEvent->SetRecurrence(pRecurrence);
	 *
	 *	delete pRecurrence;
	 *
	 * }
	 * @endcode
	 */
	result SetRecurrence(const Recurrence* pRecurrence);

private:	// for PI
	/*
	 * Sets the instance.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The instance has INVALID_RECORD_ID, or @n
	 * 									this CalEvent is already an instance type.
	 */
	result	SetInstance(const RecurrenceId& recurrenceId);

private:
	result CheckRecurrenceValidation(const Recurrence* pRec);
	result CheckRecurrenceUntil(const Recurrence* pRec);
	result CheckRecurrenceFrequency(const Recurrence *pRec);

	result CheckRecurrenceDate(const Recurrence *pRec);
	result RecomputeStartDateForWeekly(const Recurrence* pRec);
	result RecomputeStartDateForMonthly(const Recurrence *pRec);
	result RecomputeStartDateForYearly(const Recurrence *pRec);

	result CheckRecurrenceDateValidation(const Recurrence *pRec);

	void CopyCalEvent(const CalEvent& value);

	int	GetAttendeeIndex(const Attendee& attendee);
	Osp::Base::Collection::IList*	GenerateRecurrenceIdsN(void) const;
	bool	IsValidRecurrenceId(const RecurrenceId& recurrenceId) const;
	int		GetRecurrenceIdIndex(const Osp::Base::Collection::IList* pRIDList, const RecurrenceId& recurrenceId) const;
	int		GetRXExdateIndex(const RecurrenceId& recurrenceId) const;
	int		GetRXChangeIndex(const RecurrenceId& recurrenceId) const;
	CalEvent* 	CreateInstanceN(const RecurrenceId& recurrenceId) const;

	bool	GetNextRID(const Osp::Base::DateTime& curRID, Osp::Base::DateTime& nextRID) const;
	int		GetNextDayOfWeek(int curDayOfWeek) const;

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Sets the recurrence of the current CalEvent. @n
	 *
	 * @return		An error code
	 * @param[in]	pRecurrence				The recurrence to set @n
											@c null, to remove the previous recurrence
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The instance is a CalEvent instance (has a RecurrenceId).
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 */
	result	_SetRecurrence(const Recurrence* pRecurrence);

private:
	bool	__isInstance;
	RecurrenceId	__recurrenceId;
	RecordId	__originalEventId;
	bool	__isAllDayEvent;
	Osp::Base::ByteBuffer*	__pUID;
	Osp::Base::DateTime		__timeStamp;
	EventStatus			__status;
	BusyStatus			__busyStatus;
	EventPriority			__priority;
	Osp::Base::Collection::IList* __pAttendeeList;
	Osp::Locales::TimeZone	__timeZone;
	Osp::Base::Collection::IList* __rxExdateList;	// recurrence exceptions: exdate
	Osp::Base::Collection::IList* __rxChangeList;	// recurrence exceptions: change

	Osp::Base::String __subject;
	Osp::Base::String __description;
	Osp::Base::DateTime __dtStart;
	Osp::Base::DateTime __dtEnd;
	Osp::Base::String __location;
	EventCategory __category;
	RecordSensitivity __sensitivity;
	Reminder* __pReminder;
	Recurrence* __pRecurrence;
	
	friend class CalEventEx;
	class CalEventEx* __pCalEventEx;
};

};};// Osp::Social

#endif//_FSCL_CALEVENT_H_



