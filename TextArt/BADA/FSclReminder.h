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
 * @file	FSclReminder.h
 * @brief	This is the header file for the %Reminder class.
 *
 * This header file contains the declarations of the %Reminder class.
 */
#ifndef _FSCL_REMINDER_H_
#define _FSCL_REMINDER_H_

// Includes
#include "FSclConfig.h"
#include "FBaseString.h"

namespace Osp { namespace Social { 

// Enums and Constants

/** The maximum value of the reminder offset (in minutes). 
*
* @since		1.0
*/
static const int MAX_REMINDER_OFFSET_VALUE				= 40320;

/**
 *	@class	Reminder
 *	@brief	This class represents the information of a reminder.
 *	@since	1.0
 *
 *	The %Reminder class represents the information of a reminder. An application uses this class to get or set the information of a reminder, 
 *  such as the reminder time or the media file to be played for the reminder.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/recurrence_reminder_sensitivity.htm">Recurrence, Reminder, and Sensitivity Properties of Calendar Items</a>.
 *
 */
class  _EXPORT_SOCIAL_ Reminder:
	public Osp::Base::Object
{

friend class __CalendarbookPi;

// Construct Operation
public:

	/**
	 * This is the default constructor for this class. @n
	 * The default values are set. @n
	 * The time offset of @c 0 minutes for a reminder is set. @n
	 * The sound file name is @c null.
	 *
	 * @since	1.0
	 */
	Reminder(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~Reminder(void);

	/**
	* This is the copy constructor for the %Reminder class.
	*
	* @since		1.0
	* @param[in]	value		An instance of %Reminder
	*/
	Reminder(const Reminder& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %Reminder to the current instance.
	*
	* @since		1.0
	* @param[in]	value		An instance of %Reminder
	*/
	Reminder& operator =(const Reminder& value);

// Get/Set operation
public:
	/** 
	 * Gets the time offset of the reminder prior to an event time. @n
	 * For an event, the time offset is calculated as the number of minutes before the start DateTime. @n
	 * The default time offset is @c 0.
	 * 
	 * @since	1.0
	 * @return	The number of minutes
	 */
	int GetMinutesBefore(void) const;
	
	/** 
	 * Gets the sound file for the reminder. @n
	 * There is no default file name. 
	 *
	 * @since		1.0
	 * @return		The file path and name
	 *
	 */
	Osp::Base::String GetSoundFile(void) const;

	
	/** 
	 * Sets the time offset of the reminder prior to an event time. @n
	 * For an event, the time offset is calculated as the number of minutes before the start DateTime.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	minutes			The time offset in minutes
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified time offset is less than @c 0, or @n 
	 *								the specified time offset is more than #MAX_REMINDER_OFFSET_VALUE.
	 */
	result SetMinutesBefore(int minutes);

	/** 
	 * Sets the sound file for the reminder.
	 * The sound file must be in '/Media' or '/Storagecard/Media' or '/SystemFS/Media'(read only).
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	filePath		The path and name of the new sound file,  @n
	 *								else @c null to remove the previously set sound file
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c filePath exceeds the maximum length, or @n
	 *							 	the file path is invalid or the file does not exist.
	 */
	result SetSoundFile(const Osp::Base::String& filePath);

	
	
private:
	int __minutes_before;
	Osp::Base::String __file_path;
	
	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process. @n
	 *
	 * Sets the sound file for the current instance of Reminder.
	 *
	 * @return			An error code
	 * @param[in]   filePath		The path and name of new sound file @n
	 *					@c null, to remove previously set sound file
	 * @exception   E_SUCCESS		The method is successful.
	 */
	result _SetSoundFilePath(const Osp::Base::String& filePath) const;

	friend class ReminderEx;
	class ReminderEx* __pReminderEx;
};

};};// Osp::Social

#endif//_FSCL_REMINDER_H_



