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
 * @file		FSclCalendarbook.h
 * @brief		This is the header file for the %Calendarbook class.
 *
 * This header file contains the declarations of the %Calendarbook class.
 */
#ifndef _FSCL_CALENDARBOOK_H_
#define _FSCL_CALENDARBOOK_H_

// Includes
#include "FSclIRecordEventListener.h"
#include "FSclIRecordClearResultListener.h"
#include "FSclIRecordListener.h"
#include "FSclCalEvent.h"
#include "FSclCalTodo.h"
#include "FSocialTypes.h"

#include "FBaseDataType.h"

namespace Osp { namespace Social {

// Enums and Constants
/**
 * @if PRIVCORE
 * @enum		CalendarbookType
 * Defines the types to classify the calendar book.
 * @since		2.0
 * @endif
 */
typedef enum
{
	CALENDARBOOK_TYPE_ALL,				/**< @if PRIVCORE A calendar book for both the events and to-do items @endif */
	CALENDARBOOK_TYPE_EVENT,			/**< @if PRIVCORE A calendar book for events @endif */
	CALENDARBOOK_TYPE_TODO				/**< @if PRIVCORE A calendar book for the to-do items @endif */
} CalendarbookType;

/**
 * @if PRIVCORE
 * Defines the calendar book ID that is used to identify a specific instance of %Calendarbook.
 *
 * @since 		1.0
 * @endif
 */
typedef	long	CalendarId;

/**
 * @if PRIVCORE
 * An invalid calendar book ID indicates that the calendar book has not been correctly stored in the database.
 *
 * @since 		1.0
 * @endif
 */
static const CalendarId INVALID_CALENDAR_ID	= -1;

/**
 * @if PRIVCORE
 * The maximum length of the calendar book name.
 *
 * @since 		1.0
 * @endif
 */
static const int MAX_CALENDARBOOK_NAME_LENGTH	= 256;

class ICalendarbookPi;
class _RecordEvent;

/**
 * @class	Calendarbook 
 * @brief	This class manages the information of a calendar book.
 * @since	1.0
 *
 * 
 * The %Calendarbook class manages the information of a calendar book.
 * The calendar book is a centralized database that is used by multiple applications to store events and to-do information.
 * A calendar book represents the methods to read, add, remove, and update the events and to-do lists stored in the device.
 * The users must be notified of changes in the calendar book as multiple applications can share, change, or remove the data.
 *
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/calendarbook_namespace.htm">Calendar</a>.
 *
 * The following diagram illustrates the relationships between %Calendarbook and related classes.
 * @image html social_calendarbook_using_the_apis_classdiagram.png
 *
 * The following example demonstrates how to use the %Calendarbook class.
 *	@code
 *
	#include <FSocial.h>
	#include <FLocales.h>

	using namespace Osp::Social;
	using namespace Osp::Base;
	using namespace Osp::Base::Collection;
	using namespace Osp::Locales;
	
	void
	MyCalendarbook::Example(void)
	{
		result r = E_SUCCESS;

		Calendarbook* pCalendarbook = new Calendarbook();
		r = pCalendarbook->Construct(null);
		if (IsFailed(r))
		{
			AppLogException( "initializing the calendar book has failed");
			delete pCalendarbook;
			return;
		}

		DateTime startRange;
		DateTime endRange;
		IList* pEventList = null;

		startRange.SetValue(2009, 3, 1);
		endRange.SetValue(2009, 3, 8);

		// Gets the time zone of the system.
		LocaleManager localeManager;
		localeManager.Construct();

		TimeZone timeZone = localeManager.GetSystemTimeZone();
		
		// Gets the events.
		pEventList = pCalendarbook->GetEventsN(startRange, endRange, timeZone, 1, 20, EVENT_CATEGORY_APPOINTMENT);
		if (IsFailed(GetLastResult()) || pEventList == null)
		{
			AppLogException( "GetEvents is failed");
			delete pCalendarbook;
			return;
		}

		// Gets a specific event.
		CalEvent* pCalEvt = (CalEvent*)pEventList->GetAt(0);
		if (pCalEvt != null)
		{
			String newSubject(L"new Subject");
			pCalEvt->SetSubject(newSubject);

			// Updates a specific event.
			r = pCalendarbook->UpdateEvent(*pCalEvt);
			if (IsFailed(r))
			{
				AppLogException( "update event is failed.");
			}
		}

		pCalEvt = (CalEvent*)pEventList->GetAt(1);
		if (pCalEvt != null)
		{
			// Removes a specific event.
			r = pCalendarbook->RemoveEvent(*pCalEvt);
			if (IsFailed(r))
			{
				AppLogException( "remove event is failed.");
			}
		}

		pEventList->RemoveAll(true);
		delete pEventList;
		delete pCalendarbook;
	}
 *
 *	@endcode
 *
 */

class  _EXPORT_SOCIAL_ Calendarbook:
	public Osp::Base::Object
{
// Enums and Constants
public:

// Construct Operation

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	Calendarbook(void);

	/**
	* This is the destructor for this class.
	*
	* @since 		1.0
	*/
	~Calendarbook(void);


	/**
	 * Initializes this instance of %Calendarbook with the specified event listener. @n
	 * The events and to-do lists can be read, added, removed, and updated after construction.
	 * If the event listener is registered, the application notifies the user when a record is added, removed, or updated in the device.
	 * 
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	pListener				The event listener to be registered, @n
	 *										else @c null if an event listener need not be registered
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Construct(const IRecordEventListener* pListener = null );

	/**
	 * @if PRIVCORE
	 * Initializes this instance of %Calendarbook with the specified ID and event listener. @n
	 * The events and to-do lists can be read, added, removed, and updated after construction. 
	 * If the event listener is registered, the application notifies the user when a record is added, removed, or updated in the device.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calendarbookId			The calendar book ID to be initialized
	 * @param[in]	pListener				The event listener to be registered, @n
	 *										else @c null if an event listener need not be registered
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c calendarbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c calendarbookId does not exist.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result Construct(CalendarId calendarbookId, const IRecordEventListener* pListener);

// Two phase construction idiom.
private:
	Calendarbook(const Calendarbook& value);
	Calendarbook&	operator =(const Calendarbook& value);

//Operations
public:

	/**
	 * @if PRIVCORE
	 * Gets the calendar book ID.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else INVALID_CALENDAR_ID if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId	GetId(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the calendar book type.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book type, @n
	 *				else CALENDARBOOK_TYPE_ALL if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarbookType	GetCalendarbookType (void) const;

	/**
	 * @if PRIVCORE
	 * Gets the name of the service provider.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The name of the service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetServiceProviderName(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the account of the service provider.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The account for the service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetServiceProviderAccount(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the name of the calendar book.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The name of the calendar book
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetName(void) const;

	/**
	 * @if PRIVCORE
	 * Updates the name of the calendar book.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompCalendarbookUpdateNamePage "here".
	 * @privlevel		CORE
	 * @privgroup		MULTI_CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	name					The new name of the calendar book
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The length of the specified @c name is longer than #MAX_CALENDARBOOK_NAME_LENGTH, or @n 
	 *										the specified @c name is an empty string.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified @c name already exists.
	 * @exception	E_OBJ_NOT_FOUND			The calendar book cannot be accessed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result	UpdateName(const Osp::Base::String& name);

	/**
	 * @page 	CompCalendarbookUpdateNamePage	Compatibility for UpdateName()
	 * @section	CompCalendarbookUpdateNameIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If a calendar book with a similar calendar book name already exists, the E_OBJ_ALREADY_EXIST exception is returned.
	 *
	 * @section	CompCalendarbookUpdateNameSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. 
	 */

	/**
	 * Adds a calendar event to the calendar book. @n
	 * After adding the event to the database successfully, the event has a valid record ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calEvent				The calendar event to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_STORAGE_FULL			The capacity of this event is full.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c recordId is not #INVALID_RECORD_ID. @n
	 * 										- The specified @c calEvent is not #RECORD_TYPE_EVENT. @n
	 * 										- The specified @c calEvent is not an entry type instance. @n
	 * 										- The date of the event is invalid. @n
	 * 										- The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result AddEvent(CalEvent& calEvent);

	/**
	 * Adds a CalTodo instance to this calendar book. @n
	 * After adding the to-do item to the database successfully, the item has a valid record ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calTodo					The %CalTodo to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_STORAGE_FULL			The capacity of this to-do is full.
	 * @exception	E_INVALID_ARG			The specified @c recordId is not #INVALID_RECORD_ID, or the date of the to-do item is invalid. @n
 	 * 										The valid range of the date is from 12:00:00, midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
 	 * @if PRIVCORE
 	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
 	 * @endif
 	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result AddTodo(CalTodo& calTodo);

	/**
	 * Removes the specified calendar event from this calendar book. @n
	 * After removing the event from the database successfully, the event has #INVALID_RECORD_ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calEvent				The calendar event to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c recordId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	result RemoveEvent(CalEvent& calEvent);

	/**
	 * Removes the specified calendar event from this calendar book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	eventId					The calendar event ID to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c eventId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	result RemoveEvent(RecordId eventId);

	/**
	 * Removes the specified CalTodo instance from the calendar book. @n
	 * After removing the to-do item from the database successfully, the item has #INVALID_RECORD_ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calTodo					The %CalTodo ID to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The recordId is #INVALID_RECORD_ID.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	result RemoveTodo(CalTodo& calTodo);

	/**
	 * Removes the specified CalTodo instance from the calendar book.
	 *
	 * @since		1.0
 	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	todoId					The %CalTodo ID to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveTodo(RecordId todoId);

	/**
	 * @if PRIVCORE
	 * Removes all the events from this calendar book.
	 *
	 * @since 		1.0
	 *
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	pResultListener			The listener to receive the event when all the records are cleared
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		When the request is completed, the application is notified using the IRecordClearResultListener::OnAllRecordsCleared() method.
	 * @see			IRecordClearResultListener::OnAllRecordsCleared()
	 * @endif
	 */
	result RemoveAllEvents(const IRecordClearResultListener* pResultListener = null);

	/**
	 * @if PRIVCORE
	 * Removes all the to-do items from this calendar book.
	 *
	 * @since		1.0
	 *
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	pResultListener			The listener to receive the event when all the records are cleared
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		When the request is completed, the application is notified using the IRecordClearResultListener::OnAllRecordsCleared() method.
	 * @see			IRecordClearResultListener::OnAllRecordsCleared()
	 * @endif
	 */
	result RemoveAllTodos(const IRecordClearResultListener* pResultListener = null);

	/**
	 * Updates the specified calendar event to the internal data storage.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calEvent				The CalEvent instance to be updated
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c recordId is #INVALID_RECORD_ID. @n
	 * 										- The @c calEvent is not #RECORD_TYPE_EVENT. @n
	 * 										- The @c calEvent is not an entry type instance. @n
	 * 										- The date of the event is invalid. @n
	 * 									  	   The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	result UpdateEvent(const CalEvent& calEvent);

	/**
	 * Updates the specified CalTodo instance on the internal data storage.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calTodo					The %CalTodo instance to be updated
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified recordId is #INVALID_RECORD_ID, or the date of the to-do item is invalid. @n
	 *										The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
 	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	result UpdateTodo(const CalTodo& calTodo);

	/**
	 * Gets the specified event ID that is matched with the RecordId.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		The matched event
	 * @param[in]	eventId					The event ID to be found
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified @c eventId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
 	 */
	CalEvent*	GetEventN(RecordId eventId) const;

	/**
	 * Gets the CalEvent instances that are within the specified time range. @n
	 * The %CalEvent instances are retrieved based only on the start and end times. @n
	 * The time conversion is not done on the time zone property of %CalEvent.
	 *
	 * @deprecated	This method is deprecated as the method may return an improper result. Instead of using this method, use the 
	 * 				Calendarbook::GetEventInstancesN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, 
	 *				const Osp::Locales::TimeZone &timeZone, int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) method that takes 
	 *				TimeZone as an additional argument.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		A list containing all of the matched %CalEvent instances, @n
	 *				else an empty list if there are no matched instances or @c null if an exception occurs @n
	 *				The instances are sorted by the time of the event.
	 * @param[in]	start				The start of the time range
	 * @param[in]	end					The end of the time range
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @param[in]	category			The event category @n
	 *									If a specific category is set, the events that have the specified category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 * 									- The specified category is invalid. @n
	 *									- The start time is later than the end date. @n
	 *									- The start or end time is not in a valid range. @n
	 * 									The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The start and end times of the anniversary events and all day events created from the base applications are the local time of where they 
	 *				are added. The start and end times of all the other events are in Coordinated Universal Time (UTC) format. As no time conversion is 
	 *				performed, set the start and end times correctly according to the above guidelines in order to be interoperable with preloaded base 
	 *				applications, such as contact and organizer.
	 * 	The anniversary might not be returned if the duration of the event is longer than one day. 
	 */
	Osp::Base::Collection::IList* GetEventInstancesN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) const;

	/**
	 * Gets the %CalEvent instances that are within the specified time range. @n
	 * The %CalEvent instances are retrieved based only on the start and end times. The time conversion is not done on the time zone property of %CalEvent. @n
	 * While GetEventInstancesN() retrieves the data synchronously, this method returns the data asynchronously using 
	 * IRecordListener::OnEventInstancesReceivedN(). Therefore, it is highly recommended to use the asynchronous method because getting event instances may 
	 * take a long time.
	 *
	 * @deprecated	This method is deprecated as the method may return an improper result. Instead of using this method, use the 
	 *				Calendarbook::GetEventInstances(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, 
	 *				int pageNo, int countPerPage, unsigned long category, RequestId &reqId, const IRecordListener &listener) method that takes TimeZone as an 
	 *				additional argument.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	start				The start of the time range
	 * @param[in]	end					The end of the time range
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @param[in]	category			The event category @n
	 * 									If a specific category is set, the events that have the specified category are returned. @n
	 * 									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	listener			The listener for receiving the responses of the request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *									- The specified category is invalid. @n
	 *									- The start time is later than the end date. @n
	 *									- The start or end time is not in a valid range. @n
	 * 									   The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		IRecordListener::OnRecordsReceivedN(), Calendarbook::GetEventInstancesN() @n
	 *				The start and end times of the anniversary and all day events created from the base applications are the local time of where they are 
	 *				added. The start and end times of all the other events are in Coordinated Universal Time (UTC) format. As no time conversion is 
	 *				performed, set the start and end times correctly according to the above guidelines in order for it to be interoperable with the preloaded 
	 *				base applications, such as contact and organizer.
	 * 		The anniversary event might not be returned if the duration of the event is longer than one day. 
	 */
	result	GetEventInstances(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, int pageNo, int countPerPage, unsigned long category, RequestId& reqId, const IRecordListener& listener) const;

	/**
	 * Gets the %CalEvent instances that are within the specified time range. @n
	 * The events are retrieved based only on the start and end times. @n
	 * The time conversion is not done on the time zone property of %CalEvent.
	 *
	 * @deprecated	This method is deprecated as the method may return an improper result. Instead of using this method, use the 
	 *				Calendarbook::GetEventsN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, 
	 *				int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) method that takes TimeZone as an additional argument.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
 	 * @return		A list containing all the matched %CalEvent instances, @n
	 *				else an empty list if there is no matched event or @c null if an exception occurs @n
	 *				The events are sorted by the time of the event.
	 * @param[in]	start				The start of the time range
	 * @param[in]	end					The end of the time range
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @param[in]	category			The event category @n
	 *									If a specific category is set, the events that have the specified category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *									- The start time is later than the end date. @n
	 *									- The specified category is invalid. @n
	 *									- The start or end time is not in a valid range. @n
	 * 									   The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
  	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The start and end times of the anniversary events and all day events created from the base applications are the local time of where they 
	 *				are added. The start and end times of all the other events are in Coordinated Universal Time (UTC) format. As no time conversion is 
	 *				performed, set the start and end times correctly according to the above guidelines, in order for it to be interoperable with the 
	 *				preloaded base applications, such as contact and organizer.
	 *	 	The event that has recurrence is returned if the end date of an event matches with the start date of the specified search range. However, 
	 *				the event that does not have recurrence is not returned.
	 *				The anniversary event might not be returned if the duration of the event is longer than one day.
	 */
	Osp::Base::Collection::IList* GetEventsN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) const;

	/**
	 * Gets the number of calendar events in the specified time range. @n
	 * The events are retrieved based only on the start and end times.
	 * The time conversion is not done on the time zone property of CalEvent.
	 *
	 * @deprecated	This method is deprecated as the method may return an improper result. Instead of using this method, use the 
	 *				Calendarbook::GetEventCount(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, 
	 *				unsigned long category=EVENT_CATEGORY_ALL) method that takes TimeZone as an additional argument.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return							The number of events in this calendar book, @n
	 *									else @c -1 if an exception occurs
	 * @param[in]	start				The start of the time range
	 * @param[in]	end					The end of the time range
	 * @param[in]	category			The event category @n
	 *									If a specific category is set, the events that have the specified category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The start time is later than the end date. @n
	 * 									- The specified category is invalid. @n
	 *									- The start or end time is not in a valid range. @n
	 * 									   The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
   	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The start and end times of the anniversary events and all day events created from the base applications are the local time of where they 
	 *				are added. The start and end times of all the other events are in Coordinated Universal Time (UTC) format. As no time conversion is 
	 *				performed, set the start and end times correctly according to the above guidelines, in order for it to be interoperable with the 
	 *				preloaded base applications, such as contact and organizer.
	 * 		The event that has a recurrence is returned if the end date of an event matches with the start date of the specified search range. 
	 *				However, the event that does not have recurrence is not returned.
	 *				The anniversary event might not be returned if the duration of the event is longer than one day. 
	 */
	int GetEventCount(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, unsigned long category =EVENT_CATEGORY_ALL) const;

	/**
	 * Gets the specified to-do after matching it with the specified record ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		The matched to-do
	 * @param[in]	todoId					The ID of the to-do to be found
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c todoId is invalid.
 	 * @exception	E_OBJ_NOT_FOUND			The specified record is not found.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	CalTodo*	GetTodoN(RecordId todoId) const;

	/**
	 * Gets all the to-do items in the specified time range.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		A list of all the matched @c CalTodo instances, @n
	 *				else an empty list if there is no matched to-do item @n
	 *              The items are sorted by time.
	 * @param[in]	start					The start of the time range
	 * @param[in]	end						The end of the time range
	 * @param[in]	pageNo					The page number of the result list @n
	 *										It starts from @c 1.
	 * @param[in]	countPerPage			The desired maximum count of the result items per page
	 * @param[in]	status					The to-do status @n
	 *										If a specific status is set, the to-dos that have the specified status are returned. @n
	 *										The default status value is #TODO_STATUS_ALL, which means all the statuses are returned.
	 * @param[in]	priority				The to-do priority @n
	 *										If a specific priority is set, the to-dos that have the specified priority are returned. @n
	 *										The default priority value is #TODO_PRIORITY_ALL that means all the priorities are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *										- The start time is later than the end date. @n
	 *										- The start or end time is not in a valid range. @n
	 * 									       The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
   	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The values for @c status and @c priority can be set by assigning values to both the @c status and @c priority. For example, 
	 *				status = #STATUS_COMPLETED, priority = #TODO_PRIORITY_ALL.
	 *
	 */
	Osp::Base::Collection::IList* GetTodosN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, int pageNo, int countPerPage, unsigned long status=TODO_STATUS_ALL, unsigned long priority=TODO_PRIORITY_ALL) const;

	/**
	 * Gets the total number of to-dos in the specified time range.
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		count					The total number of to-dos, @n
	 *										else @c -1 if an exception occurs
	 * @param[in]	start					The start of the time range
	 * @param[in]	end						The end of the time range
	 * @param[in]	status					The to-do status @n
	 *										If a specific status is set, the to-dos that have the specified status are returned. @n
	 *										The default status value is #TODO_STATUS_ALL, which means all the statuses are returned.
	 * @param[in]	priority				The to-do priority @n
	 *										If a specific priority is set, the to-dos that have the specified priority are returned. @n
	 *										The default priority value is #TODO_PRIORITY_ALL that means all the priorities are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The start time is later than the end date, or @n 
	 *										the start or end time is not in a valid range. @n
	 * 									   	The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
 	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
  	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTodoCount(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, unsigned long status=TODO_STATUS_ALL, unsigned long priority=TODO_PRIORITY_ALL) const;

	/**
	 * Gets all the event IDs of the specified category. @n
	 * The event IDs (#RecordId) is stored into IList as a #LongLong class instance that wraps the event ID.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetEventsN() to get the event list.
	 * @since		  		2.0
	 * @if PRIVCORE
	 * @compatibility		This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 						For more information, see @ref CompCalendarbookGetEventIdsNPage "here".
	 * @endif
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
 	 * @return		A list containing all the event IDs (#RecordId), @n
	 *				else an empty list if there is no matched event or @c null if an exception occurs @n
	 *				The events are sorted by the time of the event.
	 * @param[in]	category				The event category @n
	 *										If a specific category is set, the events that have the specified category are returned. @n
	 *										The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c category is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO.
	 * @exception	E_SYSTEM				A system error has occurred.
  	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetEventIdsN(unsigned long category=EVENT_CATEGORY_ALL) const;

	/**
	 * @if PRIVCORE
	 * @page		CompCalendarbookGetEventIdsNPage	Compatibility for GetEventIdsN()
	 * @section		CompCalendarbookGetEventIdsNIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * This method is implemented in bada API version 1.0, @n 
	 * but the privilege is changed from CORE level, MULTI_CALENDARBOOK group to NORMAL level, CALENDARBOOK group in bada API version 2.0.
	 * @endif
	 */

	/**
	 * Gets all the to-do IDs.
	 * The to-do IDs (#RecordId) are stored into IList as a #LongLong class instance that wraps the to-do ID.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetTodosN() to get the todo list.
	 * @since 		2.0
	 * @if PRIVCORE
	 * @compatibility		This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 						For more information, see @ref CompCalendarbookGetTodoIdsNPage "here".
	 * @endif
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		A list containing all the to-do IDs(@c RecordId), @n
	 *				else an empty list if there is no to-do ID or @c null if an exception occurs
	 * @param[in]	status					The to-do status @n
	 *										If a specific status is set, the to-dos that have the specified status are returned. @n
	 *										The default status value is #TODO_STATUS_ALL, which means all the statuses are returned.
	 * @param[in]	priority				The to-do priority @n
	 *										If a specific priority is set, the to-dos that have the specified priority are returned. @n
	 *										The default priority value is #TODO_PRIORITY_ALL that means all the priorities are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c status or @c priority value is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT.
   	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *				The values for @c status and @c priority can be set by assigning values to both the @c status and @c priority. For example, 
	 *				status = #STATUS_COMPLETED, priority = #TODO_PRIORITY_ALL.
	 */
	Osp::Base::Collection::IList* GetTodoIdsN(unsigned long status=TODO_STATUS_ALL, unsigned long priority=TODO_PRIORITY_ALL) const;

	/**
	 * @if PRIVCORE
	 * @page		CompCalendarbookGetTodoIdsNPage		Compatibility for GetTodoIdsN()
	 * @section		CompCalendarbookGetTodoIdsNIssueSection		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * This method is implemented in bada API version 1.0, @n
	 *	but the privilege is changed from CORE level, MULTI_CALENDARBOOK group to NORMAL level, CALENDARBOOK group in bada API version 2.0.
	 * @endif
	 */

	/**
	 * Gets the CalEvent instances that are within the specified time range. @n
     * The anniversary and all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by their 
	 * start and end times in Coordinated Universal Time (UTC). 
     *
	 *
	 * @since 		1.2
	 * @privlevel 	NORMAL
	 * @privgroup 	CALENDARBOOK
	 *
	 * @return		A list containing all of the matched %CalEvent instances, @n
	 *				else an empty list if there are no matched instances or @c null if an exception occurs @n
	 *				The results are listed in the order of their start date. The results with the same start date are ordered by their category in the 
	 *				following order: anniversaries, all day events, and other events. The results in each category are sorted by their start time.
	 * @param[in]	start				The start of the time range
	 * @param[in]	end					The end of the time range
	 * @param[in]	timeZone			The time zone of the specified start and end times
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @param[in]	category			The event category @n
	 *									If a specific category is set, the events that have the specified category are returned. @n
	 *									The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *									- The start time is later than the end date. @n
	 *									- The specified @c category is invalid. @n
	 *									- The start or end time is not in a valid range. @n
	 *								 	The valid range of date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION	The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList*	GetEventInstancesN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) const;

	/**
	 * Gets the %CalEvent instances that are within the specified time range. @n
     * The anniversary and all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by their 
	 * start and end times in Coordinated Universal Time (UTC). 
     *
	 * Although GetEventInstancesN() retrieves the data synchronously, this method returns data asynchronously using  
	 * RecordListener::OnEventInstancesReceivedN(). @n
	 * It is highly recommended to use the asynchronous method because getting the event instances may take a long time.
	 *
	 * @since 		1.2
	 * @privlevel 	NORMAL
	 * @privgroup 	CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in] 	start					The start of the time range
	 * @param[in] 	end						The end of the time range
	 * @param[in] 	timeZone				The time zone of the specified start and end times
	 * @param[in] 	pageNo					The page number of the result list @n
	 *										It starts from @c 1.
	 * @param[in] 	countPerPage			The desired maximum count of the result items on the page
	 * @param[in] 	category				The event category @n
	 *										If a specific category is set, the events that have the specified category are returned. @n
	 *										The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @param[out] 	reqId					The ID of the request
	 * @param[in] 	listener				The listener for receiving the responses of the request
	 * @exception 	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception 	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *										- The start time is later than the end date. @n
	 *										- The start or end time is not in a valid range. @n
	 *										- The specified category is invalid. @n
	 *										   The valid range of date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception 	E_SYSTEM				A system error has occurred.
	 * @remarks		IRecordListener::OnRecordsReceivedN(), Calendarbook::GetEventInstancesN()
	 */
	result	GetEventInstances(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, int pageNo, int countPerPage, unsigned long category, RequestId& reqId, const IRecordListener& listener) const;

	/**
	 * Gets the events that are within the specified time range. @n
     * The anniversary and the all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by 
	 * their start and end times in Coordinated Universal Time (UTC). 
	 *
	 * @deprecated	This method is deprecated because it is ineffective to fetch entry type events.
	 *
	 * @since 		1.2
	 * @privlevel 	NORMAL
	 * @privgroup 	CALENDARBOOK
	 *
	 * @return		A list containing all the matched %CalEvent instances, @n
	 *				else an empty list if there are no matched events or @c null if an exception occurs @n
	 *				The results are listed in the order of their start date. The results with the same start date are ordered by their category in the 
	 *				following order: anniversaries, all day events, and other events. The results in each category are sorted by their start time.
	 * @param[in]	start					The start of the time range
	 * @param[in]	end						The end of the time range
	 * @param[in]	timeZone				The time zone of the specified start and end times
	 * @param[in]	pageNo					The page number of the result list @n
	 *										It starts from @c 1.
	 * @param[in]	countPerPage			The desired maximum count of the result items on the page
	 * @param[in]	category				The event category @n
	 *										If a specific category is set, the events that have the specified category are returned. @n
	 *										The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The specified @c pageNo or @c countPerPage is less than @c 1. @n
	 *										- The start time is later than the end date. @n
	 *										- The specified @c category is invalid. @n
	 *										- The start or end time is not in a valid range. @n
	 *										   The valid range of date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList*	GetEventsN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, int pageNo, int countPerPage, unsigned long category=EVENT_CATEGORY_ALL) const;

	/**
	 * Gets the number of events in the specified time range. @n
     * The anniversary and the all day events are retrieved by their start and end dates in the local time zone, while all other events are retrieved by 
	 * their start and end times in Coordinated Universal Time (UTC). 
	 *
	 * @deprecated	This method is deprecated because it is ineffective to fetch entry type events.
	 *
	 * @since 		1.2
	 * @privlevel 	NORMAL
	 * @privgroup 	CALENDARBOOK
	 *
	 * @return		The number of events in this calendar book, @n
	 *				else @c -1 if an exception occurs
	 * @param[in] 	start					The start of the time range
	 * @param[in] 	end						The end of the time range
	 * @param[in] 	timeZone				The time zone of the specified start and end times
	 * @param[in] 	category				The event category @n
	 *										If a specific category is set, the events that have the specified category are returned. @n
	 *										The default category value is #EVENT_CATEGORY_ALL, which means all the categories are returned.
	 * @exception 	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception 	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The start time is later than the end date. @n
	 *										- The specified @c category is invalid. @n
	 *										- The start or end time is not in a valid range. @n
	 *										   The valid range of date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @if PRIVCORE
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO @b since: @b 2.0.
	 * @endif
	 * @exception 	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int	GetEventCount(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end, const Osp::Locales::TimeZone &timeZone, unsigned long category =EVENT_CATEGORY_ALL) const;

	/**
	 * Gets a list of all the events that are most recently revised and are in the specified search range. @n
	 * The specified @c start and @c end date values of the search range should be in Coordinated Universal Time (UTC). @n
	 * The removed events are not included in the result.
	 *
	 * @deprecated	This method is deprecated because the management policy of the revised events has been changed.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		A list of all the matched %CalEvent instances, @n
	 *				else an empty list if there is no matched event or @c null if an exception occurs
	 * @param[in]	start					The start date of the search range
	 * @param[in]	end						The end date of the search range
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c end value is earlier than the specified @c start value, or @n
	 * 									 	the start or end date is invalid. @n
	 *										The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_TODO.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchEventsByLastRevisionN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end) const;

	/**
	 * Gets a list of all the to-dos for which the last revision is in the specified search range. @n
	 * The specified @c start and @c end date values of the search range should be in Coordinated Universal Time (UTC).
	 * The removed to-dos are not included in the result.
	 *
	 * @deprecated	This method is deprecated because the management policy of the revised to-dos has been changed.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	CALENDARBOOK
	 *
	 * @return		A list of all the matched %CalTodo instances, @n
	 *				else an empty list if there is no matching to-do item or @c null if an exception occurs
	 * @param[in]	start					The start date of the search range
	 * @param[in]	end						The end date of the search range
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c end value is earlier than the specified @c start value, or @n
	 * 									 	the start or end date is invalid. @n
	 *										The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_OPERATION		The calendar book type of this instance is #CALENDARBOOK_TYPE_EVENT.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchTodosByLastRevisionN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end) const;


private:
	result CheckEventValidation(unsigned long category) const;
	result CheckTodoValidation(unsigned long status, unsigned long priority) const;
	result CheckTodoStatusValidation(unsigned long status) const;
	result CheckTodoPriorityValidation(unsigned long priority) const;
	result CheckTimeRangeValidation(const Osp::Base::DateTime& start, const Osp::Base::DateTime& end) const;

//attributes
private:

	/**
	 * Porting Interface Instance
	 */
	ICalendarbookPi*	__iCalendarbookInterface;

	_RecordEvent* __pRecordEvent;

	Osp::Base::String __SPName;
	Osp::Base::String __SPAccount;
	
	friend class CalendarbookEx;
	class CalendarbookEx* __pCalendarbookEx;

};

};};// Osp::Social

#endif//_FSCL_CALENDARBOOK_H_



