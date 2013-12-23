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
* @file		FSclEmail.h
* @brief	This is the header file for the %Email class.
*
* This header file contains the declarations of the %Email class.
*/
#ifndef _FSCL_EMAIL_H_
#define _FSCL_EMAIL_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {

// Enums and Constants
/**
* Defines the types of email.
*
* @since 1.0
*/
enum EmailType {
	EMAIL_TYPE_PERSONAL,	/**< The personal email type*/
	EMAIL_TYPE_WORK,		/**< The work email type*/
	EMAIL_TYPE_OTHER		/**< The other email type*/
};

/**
 * The maximum length of the email property.
 *
 * @since 1.0
 */
static const int MAX_EMAIL_LENGTH				= 100;

/**
* @class	Email 
* @brief	This class represents an email.
* @since	1.0
*
* The %Email class represents an email.
* An email consists of the email address and email type.
*
* The following example demonstrates how to use the %Email class. 
*
* @code
using namespace Osp::Base;
using namespace Osp::Social;

void
MyClass::SomeMethod(void)
{	
	result r = E_SUCCESS;
	// Creates an instance of %Email.
	Email email = Email();

	// Sets the email address.
	r = email.SetEmail(L"hello@bada.com");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the email type.
	email.SetType(EMAIL_TYPE_PERSONAL);

	return E_SUCCESS;
}
* @endcode
*/
class  _EXPORT_SOCIAL_ Email:
	public Osp::Base::Object
{
	// Construct Operation
public:
	/**
	* This is the default constructor for this class.
	*
	* @since 1.0
	*/
	Email(void);

	/**
	* Initializes this instance of %Email with the specified @c type and @c email. @n
	* This constructs an instance of %Email of the specified type.
	*
	* @since 		1.0
	* @param[in]	type		The type of email
	* @param[in]	email		The email address
	*/
	Email(EmailType type, const Osp::Base::String& email);

	/**
	* This is the copy constructor for the %Email class. @n
	* This constructs an instance of %Email with the values of the specified instance.
	*
	* @since 		1.0
	* @param[in]	value	An instance of %Email
	*/
	Email(const Email& value);

	/**
	* This is the destructor for this class.
	*
	* @since 		1.0
	*/
	virtual ~Email(void);

public:
	/**
	* Copies the data contained in the specified instance of %Email to the current instance.
	*
	* @since 		1.0
	* @param[in]	value	An instance of %Email
	*/
	Email& operator =(const Email& value);

	/**
	* Checks whether the value of the specified instance of %Email is equal to the value of the current instance.
	*
	* @since 		1.0
	* @return		@c true if the value of the specified instance of %Email equals the value of the current instance, @n
	* 				else @c false
	* @param[in]	rhs		An instance of %Email
	*/
	bool operator ==(const Email& rhs) const;

	/** 
	* Checks whether the value of the specified instance of %Email does not equal the value of the current instance.
	*
	* @since 		1.0
	* @return		@c true if the value of the specified instance of %Email does not equal the value of the current instance, @n
	* 				else @c false
	* @param[in]	rhs		An instance of %Email
	*/
	bool operator !=(const Email& rhs) const;

	// Operations
public:	
	/** 
	* Gets the type of the email.
	*
	* @since 	1.0
	* @return	The type of the email
	*/
	EmailType GetType(void) const;

	/** 
	* Gets the email address.
	*
	* @since 	1.0
	* @return	The email address
	*/
	Osp::Base::String GetEmail(void) const;

	/** 
	* Sets the type of the email.
	*
	* @since 		1.0
	* @param[in]	type		The type of the email to be set
	*/
	void SetType(EmailType type);

	/** 
	* Sets the email address.
	*
	* @since 		1.0
	* @return		An error code
	* @param[in]	email			The email address
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c email address is an empty string, or @n
	*								the length of the specified email string exceeds #MAX_EMAIL_LENGTH.
	*/
	result SetEmail(const Osp::Base::String& email);

private:	
	EmailType __type;
	Osp::Base::String __email;	
	
	friend class EmailEx;
	class EmailEx* __pEmailEx;

}; // Email

};};// Osp::Social

#endif//_FSCL_EMAIL_H_


