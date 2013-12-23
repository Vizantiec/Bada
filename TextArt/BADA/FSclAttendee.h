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
 * @file	FSclAttendee.h
 * @brief	This is the header file for the %Attendee class.
 *
 * This header file contains the declarations of the %Attendee class.
 */
#ifndef _FSCL_ATTENDEE_H_
#define _FSCL_ATTENDEE_H_

// Includes
#include "FSclConfig.h"
#include "FBaseString.h"

namespace Osp { namespace Social {

// Enums and Constants

/**
 * @enum	AttendeeRole
 * @brief	Defines the role of the attendee.
  * @since 	1.0
 */
enum AttendeeRole {
	ATTENDEE_ROLE_ATTENDEE,				/**< The attendee	*/
	ATTENDEE_ROLE_REQUIRED_ATTENDEE,	/**< The required attendee	*/
	ATTENDEE_ROLE_ORGANIZER				/**< The organizer	*/
};

/**
 * @enum	AttendeeStatus
 *
 * Defines the possible status of the attendee.
 * @since 	1.0
 */
enum AttendeeStatus
{
	ATTENDEE_STATUS_NONE,			/**< The none status */
	ATTENDEE_STATUS_NOT_RESPONDED,	/**< The not-responded status */
	ATTENDEE_STATUS_ACCEPTED,		/**< The accepted status */
	ATTENDEE_STATUS_DECLINED,		/**< The declined status*/
	ATTENDEE_STATUS_TENTATIVE,		/**< The tentative status*/
};

/** The maximum length of the name property. 
*
* @since	1.0
*/
static const int MAX_ATTENDEE_NAME_LENGTH				= 100;
/** The maximum length of the email property.
*
* @since 	1.0
*/
static const int MAX_ATTENDEE_EMAIL_LENGTH				= 320;

/**
 *	@class	Attendee
 *	@brief	This class represents the information of an attendee.
 *	@since	1.0
 *
 *	The %Attendee class represents the information of an attendee. The attendee details include a mandatory
 *  email and an optional name. In addition, the attendee has a role and status information.
 */
class  _EXPORT_SOCIAL_ Attendee:
	public Osp::Base::Object
{
// Construct Operation
public:

	/**
	 * Initializes this instance with the specified email address.
	 *
	 * @since		1.0
	 * @param[in]	email	The email address
	 */
	Attendee(const Osp::Base::String& email);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~Attendee(void);

	/**
	* This is the copy constructor for the %Attendee class.
	*
	* @since		1.0
	* @param[in]	value		An instance of %Attendee
	*/
	Attendee(const Attendee& value);

	/**
	* This is the assignment operator for this class.
	*
	* @since		1.0
	* @param[in]	value		An instance of %Attendee
	*/
	Attendee& operator =(const Attendee& value);

	/**
	* Checks whether the data in the specified instance of %Attendee is equal to the data in the current instance.
	*
	* @since		1.0
	* @return		@c true if the data in the specified instance equals the data in the current instance, @n
	* 				else @c false
	* @param[in]	rhs		An instance of %Attendee
	*/
	bool operator ==(const Attendee& rhs) const;

	/**
	* Compares the specified instance of %Attendee with the calling instance for inequality.
	*
	* @since		1.0
	* @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	*				else @c false
	* @param[in]	rhs		An instance of %Attendee
	*/
	bool operator !=(const Attendee& rhs) const;

// Get/Set operation
public:
	/**
	 * Gets the name of the attendee.
	 *
	 * @since		1.0
	 * @return		The name
	 */
	Osp::Base::String	GetName(void) const;

	/**
	 * Gets the email address of the attendee.
	 *
	 * @since		1.0
	 * @return		The email address
	 */
	Osp::Base::String	GetEmail(void) const;

	/**
	 * Gets the role of the attendee. @n
	 * The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 *
	 * @since		1.0
	 * @return		The role of the attendee 
	 */
	AttendeeRole		GetRole(void) const;

	/**
	 * Gets the status of the attendee. @n
	 * The default value is @c #ATTENDEE_STATUS_NONE.
	 *
	 * @since		1.0
	 * @return		The attendee status
	 */
	AttendeeStatus		GetStatus(void) const;

	/**
	 * Sets the name.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	name			The common name of the attendee
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c name is an empty string, or @n
	 *								the length of the specified @c name exceeds #MAX_ATTENDEE_NAME_LENGTH.
	 */
	result	SetName(const Osp::Base::String& name);

	/**
	 * Sets the email address of the attendee. @n
	 * This is the identifier of an attendee.
	 *
	 * @since		1.0
 	 * @return		An error code
	 * @param[in]	email			The email address
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c email is an empty string, or @n
	 *								the length of the specified @c email exceeds #MAX_ATTENDEE_EMAIL_LENGTH.
	 */
	result	SetEmail(const Osp::Base::String& email);

	/**
	 * Sets the role of the attendee. @n
	 * The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 *
	 * @since		1.0
	 * @param[in]	role	The role of the attendee @n
	 *						The default value is @c #ATTENDEE_ROLE_ATTENDEE.
	 */
	void	SetRole(AttendeeRole role);

	/**
	 * Sets the status of the attendee. @n
	 * The default value is @c #ATTENDEE_STATUS_NONE.
	 *
	 * @since		1.0
	 * @param[in]	status	The status of the attendee @n
	 *						The default value is @c #ATTENDEE_STATUS_NONE.
	 */
	void	SetStatus(AttendeeStatus status);

private :
	Osp::Base::String	__name;
	Osp::Base::String	__email;
	AttendeeRole		__attendeeRole;
	AttendeeStatus		__attendeeStatus;
	
	friend class AttendeeEx;
	class AttendeeEx* __pAttendeeEx;
};

};};// Osp::Social

#endif//_FSCL_ATTENDEE_H_



