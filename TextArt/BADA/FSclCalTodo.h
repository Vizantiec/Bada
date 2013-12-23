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
 * @file		FSclCalTodo.h
 * @brief		This is the header file for the %CalTodo class.
 *
 * This header file contains the declarations of the %CalTodo class.
 */
#ifndef _FSCL_CALTODO_H_
#define _FSCL_CALTODO_H_

// Includes

#include "FSclRecord.h"
#include "FSclRecurrence.h"
#include "FSocialTypes.h"

namespace Osp { namespace Social {  

// Enums and Constants
/**
 * @enum	TodoStatus
 * Defines the possible to-do status types.
 *
 * @since	1.0
 */

typedef enum {
	TODO_STATUS_NONE			= 0x00000001,		/**< The None status			*/
	TODO_STATUS_NEEDS_ACTION	= 0x00000002,	/**< The Needs Action status	*/
	TODO_STATUS_COMPLETED		= 0x00000004,		/**< The Completed status		*/
	TODO_STATUS_IN_PROCESS		= 0x00000008,		/**< The In Process status		*/
	TODO_STATUS_CANCELLED		= 0x00000010,		/**< The Canceled status		*/
} TodoStatus;

/**
 * @enum	TodoPriority
 * Defines the possible to-do priority levels.
 *
 * @since 	1.0
 */
typedef enum {
	TODO_PRIORITY_LOW			= 0x00000001,		/**< The Low priority		*/
	TODO_PRIORITY_NORMAL		= 0x00000002,		/**< The Normal priority	*/
	TODO_PRIORITY_HIGH			= 0x00000004,		/**< The High priority		*/
} TodoPriority;

/** The maximum length of the subject field. 
*
* @since 	1.0
*/
static const int MAX_TODO_SUBJECT_LENGTH			= 100;
/** The maximum length of the description field. 
*
* @since 	1.0
*/
static const int MAX_TODO_DESCRIPTION_LENGTH		= 1000;

/** All the to-do statuses. 
*
* @since 	1.0
*/
static const unsigned long TODO_STATUS_ALL	= TODO_STATUS_NONE | TODO_STATUS_NEEDS_ACTION | TODO_STATUS_COMPLETED | TODO_STATUS_IN_PROCESS | TODO_STATUS_CANCELLED;

/** All the to-do priorities.	
*
* @since 	1.0
*/

static const unsigned long TODO_PRIORITY_ALL	= TODO_PRIORITY_LOW | TODO_PRIORITY_NORMAL | TODO_PRIORITY_HIGH;

/**
 * @enum	CalTodoPropertyId
 * Defines the IDs for accessing the properties of %CalTodo.
 * The property ID is used for IRecordEventListener::OnRecordChangedN().
 *
 * @deprecated	This enum is deprecated because it is not used any more.
 * @since 	1.0
 */
enum CalTodoPropertyId {
	CALTODO_PROPERTY_ID_SUBJECT,		/**< The subject property ID */
	CALTODO_PROPERTY_ID_DESCRIPTION,	/**< The description property ID */
	CALTODO_PROPERTY_ID_DATE,			/**< The start and due date property ID */
	CALTODO_PROPERTY_ID_PRIORITY,		/**< The priority property ID */
	CALTODO_PROPERTY_ID_STATUS,			/**< The status property ID */
	CALTODO_PROPERTY_ID_SENSITIVITY,	/**< The sensitivity property ID */
	CALTODO_PROPERTY_ID_LAST_REVISION	/**< An ID for the calendar date and time of the last update in Coordinated Universal Time (UTC). 
											Read-only (#DateTime type) @b since: @b 2.0. */
};

/**
 *	@class	CalTodo
 *	@brief	This class represents the calendar book to-do information.
 *	@since	1.0
 *
 * The %CalTodo class is a subset of vTodo. An instance of %CalTodo includes the subject, description, start date, due date, location, sensitivity, 
 *			priority, and status.
 * This class represents the information of a calendarbook to-do.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/caltodo.htm">Calendar Tasks</a>.
 *
 */
class  _EXPORT_SOCIAL_ CalTodo:
	public Osp::Social::Record
{
// Construct Operation
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	1.0
	 */
	CalTodo(void);

	/**
	* This is the destructor for this class.
	*
	* @since 	1.0
	*/
	virtual ~CalTodo(void);

	/**
	* This is the copy constructor for the %CalTodo class. @n
	* It copies the values of the specified instance of %CalTodo to the current instance. 
	*
	* @since 		1.0
	*
	* @param[in]	value		An instance of %CalTodo
	*/
	CalTodo(const CalTodo& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %CalTodo to the current instance.
	*
	* @since 		1.0
	*
	* @param[in]	value		An instance of %CalTodo
	*/
	CalTodo& operator =(const CalTodo& value);

// Get/Set operation
public:

	/** 
	 * Gets the subject of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @return		The subject 
	 *
	 */
	Osp::Base::String GetSubject(void) const;
	
	/** 
	 * Gets the description of the current instance of %CalTodo.
	 *
	 * @since    1.0
	 *
	 * @return	 The description
	 *
	 */
	Osp::Base::String GetDescription(void) const;

	/** 
	 * Gets the start date of the current instance of %CalTodo. @n
	 * The time portion of DateTime is ignored.
	 *
	 * @since 		1.0
	 *
	 * @return		The start date
	 *
	 */
	Osp::Base::DateTime GetStartDate(void) const;

	/** 
	 * Gets the due date of the current instance of %CalTodo. @n
	 * The time portion of DateTime is ignored.
	 *
	 * @since 		1.0
	 *
	 * @return		The due date
	 *
	 */
	Osp::Base::DateTime GetDueDate(void) const;

	/** 
	 * Gets the priority level of the current instance of %CalTodo. @n
	 * The default priority level is #TODO_PRIORITY_LOW.
	 *
	 * @since 		1.0
	 *
	 * @return		The priority level
	 *
	 */
	TodoPriority GetPriority(void) const;

	/** 
	 * Gets the status of the current instance of %CalTodo. @n
	 * The default status is #TODO_STATUS_NONE.
	 *
	 * @since		1.0
	 *
	 * @return		The to-do status
	 *
	 */
	TodoStatus GetStatus(void) const;
	
	/** 
	 * Gets the sensitivity of the current instance of %CalTodo. @n
	 * The default value is #SENSITIVITY_PUBLIC.
	 *
	 * @since		1.0
	 *
	 * @return		The to-do sensitivity 
	 *
	 */
	RecordSensitivity GetSensitivity(void) const;

	/**
	 * Gets the last updated date and time of the current instance of %CalTodo.
	 *
	 * @since		2.0
	 *
	 * @return		The last updated date and time
	 */
	Osp::Base::DateTime GetLastRevisedTime(void) const;

	/** 
	 * Sets the subject of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @return		An error code
	 * @param[in]	subject				The to-do subject
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The length of the specified @c subject exceeds #MAX_TODO_SUBJECT_LENGTH.
	 */
	result SetSubject(const Osp::Base::String& subject);

	/** 
	 * Sets the description of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @return		An error code
	 * @param[in]	description		The to-do description, @n
	 *								else @c null to remove the existing value
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c description exceeds #MAX_TODO_DESCRIPTION_LENGTH.
	 */
	result SetDescription(const Osp::Base::String& description);

	/** 
	 * Sets the start date and due date for the current instance of %CalTodo. @n
	 * If the start date is not set, the current date is considered as the start date. The due date must be later than or equal to the start date. @n
	 * The time portion of DateTime is ignored. The default time is 00:00:00.
	 *
	 * @since 		1.0
	 *
	 * @return		An error code
	 * @param[in]	start			The start date
 	 * @param[in]	due				The due date
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c due value is earlier than the specified @c start value.
	 */
	result SetStartAndDueDate(const Osp::Base::DateTime& start, const Osp::Base::DateTime& due);


	/** 
	 * Sets the priority level of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @param[in]	priority		The priority level to be set
	 *
	 */
	void SetPriority(TodoPriority priority);
	
	/** 
	 * Sets the status of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @param[in]	status			The status to be set
	 *
	 */
	void SetStatus(TodoStatus status);

	/** 
	 * Sets the sensitivity of the current instance of %CalTodo.
	 *
	 * @since 		1.0
	 *
	 * @param[in]	sensitivity		The sensitivity to be set
	 *
	 */
	void SetSensitivity(RecordSensitivity sensitivity);
	
private:
		void CopyCalTodo(const CalTodo& value);
private:
	Osp::Base::String __subject;
	Osp::Base::String __description;
	Osp::Base::DateTime __dStart;
	Osp::Base::DateTime __dDue;
	TodoPriority __priority;
	TodoStatus __status;
	RecordSensitivity __sensitivity;
	
	friend class CalTodoEx;
	class CalTodoEx* __pCalTodoEx;
};

};};// Osp::Social

#endif//_FSCL_CALTODO_H_



