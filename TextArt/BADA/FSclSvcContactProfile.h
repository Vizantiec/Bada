/* $Change: 1144988 $ */
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
* @file		FSclSvcContactProfile.h
* @brief	This is the header file for the %ContactProfile class.
*
* This header file contains the declarations of the %ContactProfile class.
*/
#ifndef _FSCL_SVC_CONTACT_PROFILE_H_
#define _FSCL_SVC_CONTACT_PROFILE_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseColArrayList.h"
#include "FSclAddress.h"
#include "FSclSvcProfile.h"
#include "FSclPhoneNumber.h"

namespace Osp { namespace Social { namespace Services {
	// To create friendship.
	class __ProfileUtil;


// Enums and Constants
/** The maximum length of the email property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_PROFILE_EMAIL_LENGTH		= 320;
/** The maximum length of the URL property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_PROFILE_URL_LENGTH			= 550;
/** The number of addresses that can be stored in %ContactProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int PROFILE_ADDRESS_CAPACITY		= 50;
/** The number of phone numbers that can be stored in %ContactProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int PROFILE_PHONE_NUMBER_CAPACITY	= 50;
/** The number of emails that can be stored in %ContactProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int PROFILE_EMAIL_CAPACITY			= 50;
/** The number of URLs that can be stored in %ContactProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int PROFILE_URL_CAPACITY			= 50;


/**
* Defines the IDs for accessing the properties of %ContactProfile.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
enum ContactProfilePropertyId {
	CP_PID_ADDRESSES,				/**< The address property ID */
	CP_PID_EMAILS,					/**< The email property ID */
	CP_PID_PHONE_NUMBERS,			/**< The phone number property ID */	
	CP_PID_URLS						/**< The URL property ID */	
};

/** The count of the properties in %ContactProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int CONTACT_PROFILE_PROPERTY_COUNT		=	4;

/**
* @class	ContactProfile 
* @brief	This class represents the contact profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* 	The %ContactProfile class represents the contact profile of a user. The contact profile contains phone numbers, e-mail addresses, URLs, and addresses.
* 	The contact profile is not constructed. It is obtained from the server using the ProfileService::GetMyProfile() or ProfileService::GetProfile() 
*	methods. The profile has a valid user ID.
*   This class represents the contact profile of a user.
*
*/
class  _EXPORT_SOCIAL_ ContactProfile:
	public Osp::Social::Services::Profile
{
	// Friend class
	friend class __ProfileUtil;

	// Construct Operations
private:


protected:	
	/**
	* Initializes this instance of %ContactProfile with the specified user ID.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	userId		The user ID
	*
	*/
	ContactProfile(const UserId& userId);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	ContactProfile(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~ContactProfile(void);

	/**
	* This is the copy constructor for the %ContactProfile class.
	* It creates an instance of %ContactProfile with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value		The instance of the %ContactProfile
	*/
	ContactProfile(const ContactProfile& value);

	/** 
	* Copies the contact profiles present in the specified instance to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The reference of the current instance
	* @param[in]	value	An instance of %ContactProfile to copy from
	*/
	ContactProfile&	operator =(const ContactProfile& value);

	// Operations
public:
	/**
	* Adds the specified address to the contact profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	address				The address to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_ARG 		The specified @c address is an empty string.
	* @exception	E_OVERFLOW  		The count of addresses in this contact profile exceeds #PROFILE_ADDRESS_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @remarks		The %ContactProfile does not support Osp::Social::AddressType::ADDRESS_TYPE_OTHER type. @n
	*				If the type of the specified Address is Osp::Social::AddressType::ADDRESS_TYPE_OTHER, 
	*				the type will be considered as Osp::Social::AddressType::ADDRESS_TYPE_WORK type.
	* @see 	Osp::Social::Address
	*/
	result AddAddress(const Address& address);

	/**
	* Adds the specified email address to the contact profile.
	* The email string must include the '@' character and the size of email must be greater than @c 3.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	email				The email address to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.	
	* @exception	E_INVALID_ARG 		The specified @c email is an empty string, or @n
	* 									the length of the @c email exceeds #MAX_PROFILE_EMAIL_LENGTH.
	* @exception	E_OVERFLOW  		The count of email addresses in this contact profile exceeds #PROFILE_EMAIL_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result AddEmail(const Osp::Base::String& email);

	/**
	* Adds the specified phone number to the contact profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	phoneNumber			The phone number to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.	
	* @exception	E_INVALID_ARG 		The specified @c phoneNumber is empty.
	* @exception	E_OVERFLOW  		The count of phone numbers in this contact profile exceeds #PROFILE_PHONE_NUMBER_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @see	Osp::Social::Services::PhoneNumber
	*/
	result AddPhoneNumber(const PhoneNumber& phoneNumber);

	/**
	* Adds the specified URL to the contact profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	url					The URL to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_ARG 		The specified @c url is an empty string, or @n
	*									the length of @c url exceeds #MAX_PROFILE_URL_LENGTH.
	* @exception	E_OVERFLOW  		The count of URLs in this contact profile exceeds #PROFILE_URL_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result AddUrl(const Osp::Base::String& url);

	/**
	* Replaces the address at the specified index with the specified address.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	index				The index of the address to be replaced
	* @param[in]	address				The new address
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE  	The specified @c index is out of range (valid range: 0 <= index && index < GetCount(CP_PID_ADDRESSES)).
	* @exception	E_INVALID_ARG		The specified @c address is an empty string.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @remarks		The %ContactProfile does not support Osp::Social::AddressType::ADDRESS_TYPE_OTHER type. @n
	*				If the type of the specified address is Osp::Social::AddressType::ADDRESS_TYPE_OTHER, 
	*				the type will be considered as Osp::Social::AddressType::ADDRESS_TYPE_WORK type.
	* @see	GetCount(), Osp::Social::Address
	*/
	result SetAddressAt(int index, const Address& address);

	/**
	* Replaces the email address at the specified index. @n
	* The email string must include the '@' character and the size of email must be larger than @c 3.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	index				The index of the email address to be replaced
	* @param[in]	email				The new email address
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE  	The specified @c index is out of range (valid range: 0 <= index && index < GetCount(CP_PID_EMAILS)).
	* @exception	E_INVALID_ARG 		The specified @c email is an empty string, or @n
	*									the length of the @c email exceeds #MAX_PROFILE_EMAIL_LENGTH.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @see 	GetCount()
	*/
	result SetEmailAt(int index, const Osp::Base::String& email);

	/**
	* Replaces the phone number at the specified index with the specified phone number.
	* 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	index				The index of the phone number to be replaced
	* @param[in]	phoneNumber			The new phone number
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE  	The specified @c index is out of range (valid range: 0 <= index && index < GetCount(CP_PID_PHONE_NUMBERS)).
	* @exception	E_INVALID_ARG 		The specified @c phoneNumber is empty.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @see GetCount(), Osp::Social::Services::PhoneNumber
	*/
	result SetPhoneNumberAt(int index, const PhoneNumber& phoneNumber);

	/**
	* Replaces the URL at the specified index with the specified URL.
	* 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	index				The index of the URL to be replaced
	* @param[in]	url					The new URL
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE  	The specified @c index is out of range (valid range: 0 <= index && index < GetCount(CP_PID_URLS)).
	* @exception	E_INVALID_ARG 		The specified @c url is an empty string, or @n
	*									the length of the specified @c url exceeds #MAX_PROFILE_URL_LENGTH.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @see 	GetCount()
	*/
	result SetUrlAt(int index, const Osp::Base::String& url);

	/**
	* Gets the count of items belonging to the specified property.
	* 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The count of items belonging to the specified property
	* @param[in]	id			The ID of the property
	*/
	int GetCount(ContactProfilePropertyId id) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The value of the specified property as a list, @n
	*				else an empty list if the specified property has no value @n
	*				Since the value of a property can have multiple items, this method returns a list of items. @n
	*				If ID is #CP_PID_PHONE_NUMBERS, the items in the result list are instances of Osp::Social::PhoneNumber. @n
	*				Or, if ID is #CP_PID_ADDRESSES, the items in the result list are instances of Osp::Social::Address. @n
	*				Or, if ID is #CP_PID_EMAILS or #CP_PID_URLS, the items in the result list are instances of Osp::Base::String @n
	*				
	* @param[in]	id					The ID of the property whose value is to be returned
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c id is not supported.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::Collection::IList* GetValueN(ContactProfilePropertyId id) const;

	/**
	* Removes the item at the specified index of the specified property.
	* 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	id					The ID of the property
	* @param[in]	index				The index of the item to be removed
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c id is not supported.
	* @exception	E_OUT_OF_RANGE  	The specified @c index is out of range (valid range: 0 <= index && index < The count of items of the specified property).
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result RemoveAt(ContactProfilePropertyId id, int index);

private:
	bool IsEmptyAddress(const Address& value);
	Osp::Base::Collection::IEnumerator* GetValueEnumeratorN(ContactProfilePropertyId id) const;
	Osp::Base::Collection::IEnumerator* GetDeletedItemsN(ContactProfilePropertyId id) const;

	result AddAddress(const Address& address, const Osp::Base::String* pSeqId);
	result AddAddress(const Address& address, const Osp::Base::String* pSeqId, bool isUpdated);
	result AddEmail(const Osp::Base::String& email, const Osp::Base::String* pSeqId);
	result AddEmail(const Osp::Base::String& email, const Osp::Base::String* pSeqId, bool isUpdated);
	result AddPhoneNumber(const PhoneNumber& phoneNumber, const Osp::Base::String* pSeqId);
	result AddPhoneNumber(const PhoneNumber& phoneNumber, const Osp::Base::String* pSeqId, bool isUpdated);
	result AddUrl(const Osp::Base::String& url, const Osp::Base::String* pSeqId);
	result AddUrl(const Osp::Base::String& url, const Osp::Base::String* pSeqId, bool isUpdated);


private:
	Osp::Base::Collection::ArrayList* __pAddressList;
	Osp::Base::Collection::ArrayList* __pEmailList;
	Osp::Base::Collection::ArrayList* __pPhoneList;	
	Osp::Base::Collection::ArrayList* __pUrlList;

	Osp::Base::Collection::ArrayList* __pDeletedAddrList; //the list for seqIds of deleted addresses
	Osp::Base::Collection::ArrayList* __pDeletedEmailList; //the list for seqIds of deleted emails
	Osp::Base::Collection::ArrayList* __pDeletedPhoneList; //the list for seqIds of deleted phone numbers
	Osp::Base::Collection::ArrayList* __pDeletedUrlList; //the list for seqIds of deleted URLs

private:
	friend class ContactProfileEx;
	class ContactProfileEx* __pContactProfileEx;

}; // ContactProfile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_CONTACT_PROFILE_H_
