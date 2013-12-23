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
* @file		FSclPhoneNumber.h
* @brief	This is the header file for the %PhoneNumber class.
*
* This header file contains the declarations of the %PhoneNumber class.
*/
#ifndef _FSCL_PHONE_NUMBER_H_
#define _FSCL_PHONE_NUMBER_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {

// Enums and Constants
/**
* Defines the types of phone number.
*
* @since			1.0
*/
enum PhoneNumberType {
	PHONENUMBER_TYPE_HOME,		/**< The phone number type is home telephone*/
	PHONENUMBER_TYPE_WORK,		/**< The phone number type is work telephone*/
	PHONENUMBER_TYPE_MOBILE,	/**< The phone number type is mobile */	
	PHONENUMBER_TYPE_HOME_FAX,	/**< The phone number type is home fax */  
	PHONENUMBER_TYPE_WORK_FAX,	/**< The phone number type is work fax */   
	PHONENUMBER_TYPE_PAGER,		/**< The phone number type is pager */        
	PHONENUMBER_TYPE_OTHER		/**< The phone number type is other */	
};

/** The maximum length of the phone number property. 
*
* @since	1.0
*/
static const int MAX_PHONE_NUMBER_LENGTH		= 50;

/**
* @class	PhoneNumber 
* @brief	This class stores the information of a phone number.
* @since	1.0
*
* 	The %PhoneNumber class consists of the phone number and phone number type.
*
* The following example demonstrates how to use the %PhoneNumber class.
*
* @code
using namespace Osp::Base;
using namespace Osp::Social::Services;

void
MyClass::SomeMethod(void)
{	
	result r = E_SUCCESS;
	// Creates an instance of PhoneNumber.
	PhoneNumber phoneNumber = PhoneNumber();

	// Sets the number.
	r = phoneNumber.SetPhoneNumber(L"010-111-2222");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the type.
	phoneNumber.SetType(PHONENUMBER_TYPE_MOBILE);	

	return E_SUCCESS;
}
* @endcode
*/
class  _EXPORT_SOCIAL_ PhoneNumber:
	public Osp::Base::Object
{
	// Construct Operation
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	*/
	PhoneNumber(void);

	/**
	* Initializes this instance of %PhoneNumber with the specified type and phone number.
	*
	* @since		1.0
	* @param[in]	type		The type of the phone number
	* @param[in]	number		The phone number
	*/
	PhoneNumber(PhoneNumberType type, const Osp::Base::String& number);

	/**
	* This is the copy constructor for the %PhoneNumber class.
	*
	* @since		1.0
	* @param[in]	value		An instance of %PhoneNumber
	*/
	PhoneNumber(const PhoneNumber& value);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~PhoneNumber(void);

public:
	/**
	* Copies the data contained in the specified instance of %PhoneNumber to the current instance.
	*
	* @since		1.0
	* @param[in]	value	An instance of %PhoneNumber
	*/
	PhoneNumber& operator =(const PhoneNumber& value);

	/**
	* Checks whether the data in the specified instance of %PhoneNumber is equal to the data in the current instance.
	*
	* @since		1.0
	* @return		@c true if the data in the specified instance equals the data in the current instance, @n
	*				else @c false
	* @param[in]	rhs		An instance of %PhoneNumber
	*/
	bool operator ==(const PhoneNumber& rhs) const;

	/** 
	* Checks whether the data in the specified instance of %PhoneNumber is not equal to the data in the current instance.
	*
	* @since		1.0
	* @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	*				else @c false
	* @param[in]	rhs		An instance of %PhoneNumber
	*/
	bool operator !=(const PhoneNumber& rhs) const;

	// Operations
public:	
	/** 
	* Gets the type of the phone number.
	*
	* @since	1.0
	* @return	The type of the phone number
	*/
	PhoneNumberType GetType(void) const;

	/** 
	* Gets the phone number.
	*
	* @since	1.0
	* @return	The phone number
	*/
	Osp::Base::String GetPhoneNumber(void) const;

	/** 
	* Sets the type of the phone number.
	*
	* @since		1.0
	* @param[in]	type		The type of the phone number
	*/
	void SetType(PhoneNumberType type);

	/** 
	* Sets the phone number for the current instance of %PhoneNumber. @n
	* Only alphabets (a~z, A~Z), numbers, plus (+), asterisk (*), pound (#), and comma (,) are allowed for the phone number
	* and all the other characters will be removed.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	number			The phone number
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified number is an empty string, or @n
	*								the length of the specified number exceeds #MAX_PHONE_NUMBER_LENGTH.
	*/
	result SetPhoneNumber(const Osp::Base::String& number);

private:	
	PhoneNumberType __type;
	Osp::Base::String __phoneNumber;	
	
	friend class PhoneNumberEx;
	class PhoneNumberEx* __pPhoneNumberEx;

}; // PhoneNumber

};};// Osp::Social

#endif//_FSCL_PHONE_NUMBER_H_


