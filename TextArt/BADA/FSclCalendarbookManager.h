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
 * @file		FSclCalendarbookManager.h
 * @brief		This is the header file for the %CalendarbookManager class.
 *
 * This header file contains the declarations of the %CalendarbookManager class.
 */
#ifndef _FSCL_CALENDARBOOK_MANAGER_H_
#define _FSCL_CALENDARBOOK_MANAGER_H_

// Includes
#include "FSclCalendarbook.h"

namespace Osp { namespace Social {

class ICalendarbookManagerPi;

/**
 * @if PRIVCORE
 * @class	CalendarbookManager	
 * @brief	This class represents the calendar book manager.
 * @since	1.0
 *
 * The %CalendarbookManager class manages the creation and deletion of a calendar book. It also retrieves the lists of calendar books.
 * @endif
 */
class  _EXPORT_SOCIAL_ CalendarbookManager:
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
	CalendarbookManager(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	~CalendarbookManager(void);

	/**
	 * @if PRIVCORE
	 * Initializes this instance of %CalendarbookManager.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 * 
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @endif
	 */
	result Construct(void);

// Two phase construction idiom.
private:
	CalendarbookManager(const CalendarbookManager& value);
	CalendarbookManager&	operator =(const CalendarbookManager& value);

// Operations
public:
	/**
	 * @if PRIVCORE
	 * Creates a calendar book for the specified service provider and account. @n
	 * The calendar book has a calendar book name as specified in the @c name parameter. @n
	 * Each calendar book has a corresponding calendar book ID.
	 *
	 * @since			1.0
	 * @compatibility	This class has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompCalendarbookManagerCreateCalendarbookPage "here".
	 * @privlevel		CORE
	 * @privgroup		MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else @c INVALID_CALENDAR_ID if an exception occurs
	 * @param[in]	serviceProvider		The name of the service provider
	 * @param[in]	account				The account of the service provider
	 * @param[in]	name				The calendar book name
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 *									- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 *									- The length of the specified @c name is greater than #MAX_CALENDARBOOK_NAME_LENGTH. @n
	 *									- One of the specified arguments is empty.
	 * @exception	E_OBJ_ALREADY_EXIST	A calendar book with the same name, service provider, and account already exists.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId	CreateCalendarbook(const Osp::Base::String& serviceProvider, const Osp::Base::String& account, const Osp::Base::String& name);

	/**
	 * @page	CompCalendarbookManagerCreateCalendarbookPage	Compatibility for CreateCalendarbook()
	 * @section	CompCalendarbookManagerCreateCalendarbookIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If a calendar book with the same name, service provider, and account already exists, the E_OBJ_ALREADY_EXIST exception is returned.
	 *
	 * @section	CompCalendarbookManagerCreateCalendarbookSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * @if PRIVCORE
	 * Creates a calendar book for the service provider and account. @n
	 * The calendar book has a calendar book name as specified in the @c name parameter and a type as specified in the @c type parameter. @n
	 * Each calendar book has a corresponding calendar book ID.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else @c INVALID_CALENDAR_ID if an exception occurs
	 * @param[in]	serviceProvider			The name of the service provider
	 * @param[in]	account					The account of the service provider
	 * @param[in]	name					The calendar book name
	 * @param[in]	type					The calendar book type
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 *                  					- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 *                  					- The length of the specified @c name is greater than #MAX_CALENDARBOOK_NAME_LENGTH. @n
	 *                  					- One of the specified arguments is empty.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId   CreateCalendarbook(const Osp::Base::String& serviceProvider, const Osp::Base::String& account, const Osp::Base::String& name, const CalendarbookType& type);

	/**
	 * @if PRIVCORE
	 * Creates a calendar book on the local device with the specified name. @n
	 * Each calendar book has a corresponding calendar book ID.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else @c INVALID_CALENDAR_ID if an exception occurs
	 * @param[in]	name				The calendar book name
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The length of the specified @c name is greater than #MAX_CALENDARBOOK_NAME_LENGTH, or @n
	 * 									the specified @c name is empty.
	 * @exception	E_OBJ_ALREADY_EXIST	A calendar book with the same name already exists.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId	CreateCalendarbook(const Osp::Base::String& name);

	/**
	 * @if PRIVCORE
	 * Deletes the calendar book with the specified calendar book ID. @n
	 * The data belonging to the calendar book is also deleted.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		An error code
	 * @param[in]	calendarbookId		The calendar book ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c calendarbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c calendarbookId is not found.
	 * @exception	E_ILLEGAL_ACCESS	The specified @c calendarbookId is the ID of the default calendar book. @n
	 *									The default calendar book cannot be deleted.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result DeleteCalendarbook(CalendarId calendarbookId);

	/**
	 * @if PRIVCORE
	 * Gets all calendar books(CalendarIds) belonging to the service provider and the account. @n
	 * The #CalendarId is stored in the IList as a #Long class instance that wraps the calendar ID.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		A list of CalendarIds, @n
	 *				else @c null if an exception occurs
	 * @param[in]	serviceProvider		The name of the service provider
	 * @param[in]	account				The account of the service provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 *              					- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 *									- One of the specified arguments is empty.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c serviceProvider and the specified @c account are not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	Osp::Base::Collection::IList*	GetAllCalendarbooksN(const Osp::Base::String& serviceProvider, const Osp::Base::String& account) const;

	/**
	 * @if PRIVCORE
	 * Gets all the calendar books on the device. @n
	 * The result of this method always includes the default calendar book that cannot be deleted.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		A list of CalendarIds, @n
	 *				else an empty list if there is no calendar book, or @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::Collection::IList*	GetAllCalendarbooksN(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the calendar books belonging to the service provider. @n
	 * The calendar book ID is stored in the IList as a @c Long class instance, that wraps the calendar book ID.
	 *	
	 * @since 		2.0
	 * @privlevel 	CORE
	 * @privgroup 	MULTI_CALENDARBOOK
	 *
	 * @return		A list of CalendarIds, @n
	 *				else an empty list if there is no calendar book, or @c null if an exception occurs
	 * @param[in]	serviceProvider			The name of the service provider
	 * @param[in]	account					The account of the service provider
	 * @param[in]	type					The calendar book type
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 *										- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 *										- The length of the specified @c account is greater than the #MAX_ACCOUNT_LENGTH. @n
	 *										- One of the specified arguments is empty.
	 * @exception	E_OBJ_NOT_FOUND	 		The specified @c serviceProvider and the @c account are not found, or @n
	 * 										the specified @c type is not found.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::Collection::IList*   GetCalendarbooksN(const Osp::Base::String& serviceProvider, const Osp::Base::String& account, const CalendarbookType& type) const;

	/**
	 * @if PRIVCORE
	 * Gets the CalendarId corresponding to the calendar book name of the service provider and the account.
	 *
	 * @deprecated	This method is deprecated because there may exist more than one calendar book with the same name, service provider, and account. In order 
	 *				to avoid any data loss, use GetCalendarbooksN() or GetAllCalendarbooksN(). 
	 *  
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else @c INVALID_CALENDAR_ID if an exception occurs
	 * @param[in]	serviceProvider	    The name of the service provider
	 * @param[in]	account		        The account of the service provider
	 * @param[in]	name				The calendar book name	
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 *              					- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 *              					- The length of the specified @c name is greater than #MAX_CALENDARBOOK_NAME_LENGTH. @n
	 *              					- One of the specified arguments is empty.
	 * @exception	E_OBJ_NOT_FOUND		Either of the following conditions has occurred: @n
	 *									- The specified calendar book name does not exist. @n
	 *									- The service provider does not exist. @n
	 *									- The account does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId	GetCalendarbookId(const Osp::Base::String& serviceProvider, const Osp::Base::String& account, const Osp::Base::String& name) const;

	/**
	 * @if PRIVCORE
	 * Gets the CalendarId corresponding to the specified calendar book name on the device.
	 *
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	MULTI_CALENDARBOOK
	 *
	 * @return		The calendar book ID, @n
	 *				else @c INVALID_CALENDAR_ID if an exception occurs
	 * @param[in]	name				The calendar book name
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The length of the specified @c name is greater than #MAX_CALENDARBOOK_NAME_LENGTH, or @n
	 * 									the specified @c name is empty.	 	 
	 * @exception	E_OBJ_NOT_FOUND		The specified @c name does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	CalendarId	GetCalendarbookId(const Osp::Base::String& name) const;

private :
	ICalendarbookManagerPi*	__iCalendarbookManagerInterface;
	
	friend class CalendarbookManagerEx;
	class CalendarbookManagerEx* __pCalendarbookManagerEx;

};

};};// Osp::Social

#endif//_FSCL_CALENDARBOOK_MANAGER_H_
