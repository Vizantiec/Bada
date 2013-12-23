/* $Change: 1186967 $ */
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
 * @file		FSclContact.h
 * @brief		This is the header file for the %Contact class.
 *
 * This header file contains the declarations of the %Contact class.
 */
#ifndef _FSCL_CONTACT_H_
#define _FSCL_CONTACT_H_

// Includes
#include "FBaseInteger.h"
#include "FBaseString.h"
#include "FBaseTypes.h"
#include "FBaseDateTime.h"
#include "FBaseTypes.h" // For using UserID and RequestID.
#include "FBaseColIList.h"
#include "FGraphics.h"

#include "FSclRecord.h"

#include "FSclAddress.h"
#include "FSclPhoneNumber.h"
#include "FSclEmail.h"
#include "FSclUrl.h"
#include "FSclImAddress.h"
#include "FSclCustomField.h"

namespace Osp { namespace Social {

// Enums & constants

/** The maximum length of the name properties (first, last, nickname, and formatted names). 
*
* @since 1.0
*/
static const int MAX_CONTACT_NAME_LENGTH				= 50;
/** The maximum length of the job title property. 
*
* @since 1.0
*/
static const int MAX_CONTACT_JOB_TITLE_LENGTH			= 50;
/** The maximum length of the company property. 
*
* @since 1.0
*/
static const int MAX_CONTACT_COMPANY_LENGTH				= 50;
/** The maximum length of the note property. 
*
* @since 1.0
*/
static const int MAX_CONTACT_NOTE_LENGTH				= 100;


/**
 * @enum	ContactPropertyId
 * Defines the IDs for accessing the single value type properties of %Contact.
 *
 * @since 1.0
 */
enum ContactPropertyId {
	CONTACT_PROPERTY_ID_USER_ID,				/**< 
												 * The user ID property ID (#UserId type)
												 * The UserId is an ID to access the bada Server and to identify users.
												 * If a contact belongs to bada users, the user ID can be stored in a UserId property.
												 * @deprecated	This enum value is deprecated due to the operation policy of the bada Server.
												 */
	CONTACT_PROPERTY_ID_FIRST_NAME,				/**< The first name property ID (#String type) */
	CONTACT_PROPERTY_ID_LAST_NAME,				/**< The last name property ID (#String type) */
	CONTACT_PROPERTY_ID_DISPLAY_NAME,			/**< The formatted name property ID (#String type) */
	CONTACT_PROPERTY_ID_NICK_NAME,				/**< The nick name property ID (#String type) */
	CONTACT_PROPERTY_ID_THUMBNAIL,				/**< The thumbnail property ID (#Bitmap type) */
	CONTACT_PROPERTY_ID_BIRTHDAY,				/**< The birthday property ID (#DateTime type) */
	CONTACT_PROPERTY_ID_JOB_TITLE,				/**< The job title property ID (#String type) */
	CONTACT_PROPERTY_ID_COMPANY,				/**< The company property ID (#String type) */
	CONTACT_PROPERTY_ID_NOTE,					/**< The note property ID (#String type) */
	CONTACT_PROPERTY_ID_ANNIVERSARY,			/**< The anniversary property ID (#DateTime type) */
	CONTACT_PROPERTY_ID_RINGTONE,				/**< The ringtone property ID (#String type) */
	CONTACT_PROPERTY_ID_MIDDLE_NAME,			/**< The middle name property ID (#String type) @b since: @b 1.2 */
	CONTACT_PROPERTY_ID_LAST_REVISION			/**< An ID for the calendar date and time for the last update in Coordinated Universal Time (UTC) @n 												 Read-only (#DateTime type) @b since: @b 2.0. */
};

/**
 * @enum	ContactMultiPropertyId
 * Defines the IDs for accessing the multi-value type properties of a %Contact. @n
 * The properties have several values and they are called multi-type properties.
 *
 * @since	1.0
 */
enum ContactMultiPropertyId {
	CONTACT_MPROPERTY_ID_PHONE_NUMBERS,			/**< The phone number property ID (PhoneNumber class)*/
	CONTACT_MPROPERTY_ID_EMAILS,				/**< The email property ID (Email class)*/
	CONTACT_MPROPERTY_ID_URLS,					/**< The URL property ID (Url class)*/
	CONTACT_MPROPERTY_ID_ADDRESSES,				/**< The address property ID (Address class)*/
	CONTACT_MPROPERTY_ID_IMADDRESSES,			/**< The Instant Message property ID (ImAddress class)*/
	CONTACT_MPROPERTY_ID_CUSTOM					/**< @if PRIVCORE The custom property ID (CustomField class) @b since: @b 2.0 @endif*/
};

/** The number of #ContactPropertyId factors.
*
* @since	1.0
*/
static const int	CONTACT_PROPERTY_ID_NUM		=	14;
/** The number of #ContactMultiPropertyId factors.
*
* @since	1.0
*/
static const int	CONTACT_MPROPERTY_ID_NUM		=	5;


/**
 * @class	Contact
 * @brief	This class provides a contact.
 * @since	1.0
 *
 * The %Contact class provides a contact, a record that represents the contact information of a person. It provides the properties declared in the 
 * #ContactPropertyId and #ContactMultiPropertyId enumerators. Check the descriptions for each property ID carefully to know the exact type of the 
 * property and its value. @n
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/contact.htm">Contact</a>.
 *
 * The following example demonstrates how to use the %Contact class.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Base::Collection;
	using namespace Osp::Social;

	void
	ContactExample(void)
	{
		// Creates a contact.
		Contact contact;

		// Sets the contact's properties.
		contact.SetValue(CONTACT_PROPERTY_ID_FIRST_NAME , L"Thomas");
		contact.SetValue(CONTACT_PROPERTY_ID_LAST_NAME , L"A Anderson");

		PhoneNumber phoneNumber(PHONENUMBER_TYPE_MOBILE, L"820223459876");
		contact.AddPhoneNumber(phoneNumber);


		// Gets the contact's properties.
		String firstName, lastName;
		contact.GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
		contact.GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

		IList* pPhoneNumberList = contact.GetValuesN(CONTACT_MPROPERTY_ID_PHONE_NUMBERS);
		if (pPhoneNumberList != null)
		{
			PhoneNumber* pPhoneNumber = null;
			String number;
			IEnumerator* pEnum = pPhoneNumberList->GetEnumeratorN();
			while (E_SUCCESS == pEnum->MoveNext())
			{
				pPhoneNumber = (PhoneNumber*) pEnum->GetCurrent();
				number = pPhoneNumber->GetPhoneNumber();
				// Using the phone number.
				// ..
			}

			delete pEnum;
			pPhoneNumberList->RemoveAll(true);
			delete pPhoneNumberList;
		}
	}
 *
 * @endcode
 *
 */
class  _EXPORT_SOCIAL_ Contact:
	public Record
{

friend class __AddressbookPi;
friend class __ContactParcel;
friend class Addressbook;

// Construct Operations
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Contact(void);

	/**
	 * This is the copy constructor for the %Contact class.
	 *
	 * @since		1.0
	 * @param[in]	value		An instance of %Contact
	 */
	Contact(const Contact& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	~Contact(void);

	/**
	* This operator copies the data contained in the specified instance of %Contact to the current instance.
	*
	* @since		1.0
	* @param[in]	value		The source instance of %Contact
	*/
	Contact&	operator =(const Contact& value);

//Operations
public:

	/**
	 * @if PRIVCORE
	 * Gets the service provider name.
	 * 
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The service provider name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetServiceProviderName(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the account for the service provider.
	 * 
	 * @since		1.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The account for the service provider
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetServiceProviderAccount(void) const;

	/**
	 * Gets the @c Bitmap object of the thumbnail image. @n
	 * If the thumbnail is not set, @c null is returned. @n
	 * Only the Contact instances retrieved by the #GetContactsN(), #GetContactN(), #SearchContactsByEmailN(), #SearchContactsByNameN(), 
	 * #SearchContactsByPhoneNumberN(), and #SearchContactsByUserIdN() methods have a thumbnail image.
	 *
	 * @since		1.0
	 * @return		The @c Bitmap object of the thumbnail image
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	Osp::Graphics::Bitmap*	GetThumbnailN(void) const;

	/**
	 * Sets the thumbnail image. @n
	 * If the specified @c filePath is an empty string, the current thumbnail image is removed.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	filePath				The file path of the thumbnail image
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	 * @exception	E_INVALID_ARG 			The length of the specified @c filePath exceeds the maximum limit.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result	SetThumbnail(const Osp::Base::String& filePath);

	/**
	 * Gets the value of the specified property.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	id					The ID of the property whose value is to be retrieved
	 * @param[out]	value				The property value as a String instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified contact property ID is not supported.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result GetValue(ContactPropertyId id, Osp::Base::String& value) const;

	/**
	 * Gets the value of the specified DateTime property such as birthday. @n
	 * If the DateTime value has not been set for the specified property, the property has value, '1899, 12, 31, 00:00:00'.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	id					The ID of the property whose value is to be retrieved
	 * @param[out]	value				A DateTime value of the specified property
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified contact property ID is not supported.
	 */
	result GetValue(ContactPropertyId id, Osp::Base::DateTime& value) const;

	/**
	 * Sets the value of the property having the specified ID to the specified value.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompAddressbookSetValuePage "here".
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the property whose value is to be set
	 * @param[in]	value				A new string value to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *	 								- The property with the specified contact property ID is not of the single value type or the String type. @n
	 *									- The @c id is #CONTACT_PROPERTY_ID_DISPLAY_NAME or #CONTACT_PROPERTY_ID_THUMBNAIL. @n
	 *									- The ringtone file path (value) is invalid if @c id is #CONTACT_PROPERTY_ID_RINGTONE. @n
	 *									- The length of @c value exceeds the maximum limit (Check the constants named MAX_(PROPERTY_NAME)_LENGTH).
	 * @remarks 	The #CONTACT_PROPERTY_ID_DISPLAY_NAME and #CONTACT_PROPERTY_ID_THUMBNAIL properties cannot be set. @n
	 * 				The #CONTACT_PROPERTY_ID_DISPLAY_NAME property always consists of the first and last name. @n
	 * 				#CONTACT_PROPERTY_ID_THUMBNAIL is of Bitmap type and it can be set using #SetThumbnail(). @n
	 * 				#CONTACT_PROPERTY_ID_RINGTONE can be set to the path string of the ringtone file.
	 */
	result SetValue(ContactPropertyId id, const Osp::Base::String& value);

	/**
	 * @page		CompAddressbookSetValuePage		Compatibility for SetValue()
	 * @section		CompAddressbookSetValueIssueSection		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# This method restricts the ringtone folder path to '/Media', '/Storagecard/Media', or '/SystemFS/Media'.
	 *
	 * @section CompAddressbookSetValueSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	 * -# This method allows the ringtone files to be stored in the locations permitted by #Osp::Io::File.
	 */

	/**
	 * Sets the specified value for the property having the specified ID.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	id					The ID of the property whose value is to be set
	 * @param[in]	value				A new DateTime value to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The property with the specified contact property ID is not of the single value type or the DateTime type, or @n 
	 *									the property is read-only.
	 */
	result SetValue(ContactPropertyId id, const Osp::Base::DateTime& value);

	/**
	 * Adds the specified phone number to the contact.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	phoneNumber			An instance of PhoneNumber
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified @c phoneNumber is empty.
	 */
	result AddPhoneNumber(const Osp::Social::PhoneNumber& phoneNumber);

	/**
	 * Adds the specified email to the contact.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	email				An instance of Email
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified @c email is empty.
	 */
	result AddEmail(const Osp::Social::Email& email);

	/**
	 * Adds the specified URL to the contact.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	url					An instance of URL
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified URL is empty.
	 */
	result AddUrl(const Osp::Social::Url& url);

	/**
	 * Adds the specified address to the contact.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	address				An instance of Address 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG 		The specified @c address is empty.
	 */
	result AddAddress(const Osp::Social::Address& address);

	/**
	 * Adds the specified instant message information to %Contact.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	imAddress			An instance of ImAddress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified IM address is empty.
	 */
	result AddImAddress(const Osp::Social::ImAddress& imAddress);

	/**
	 * @if PRIVCORE
	 * Adds the specified custom field to %Contact. @n
	 * Note that the custom field is not supported for the local addressbook.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	customField				An instance of CustomField
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The title of the specified @c customField is empty.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @endif
	 */
	result AddCustomField(const Osp::Social::CustomField& customField);

	/**
	 * Removes the specific value at the specified index of the multi value property.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	id					A property ID (It can only be one of the four properties: #CONTACT_MPROPERTY_ID_PHONE_NUMBERS,
	 *									#CONTACT_MPROPERTY_ID_EMAILS, #CONTACT_MPROPERTY_ID_URLS, or #CONTACT_MPROPERTY_ID_ADDRESSES)
	 * @if PRIVCORE
	 * 									, #CONTACT_MPROPERTY_ID_CUSTOM
	 * @endif
	 * @param[in]	index				The index of the value to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The index is outside the bounds of the properties.
	 */
	result RemoveAt(ContactMultiPropertyId id, int index);

	/**
	 * Gets a list of the values belonging to the specific multi value property.
	 *
	 * @since		1.0
	 * @return		A list of the values belonging to the specific multi value property
	 * @param[in]	id					A property ID (It can only be one of the four properties: #CONTACT_MPROPERTY_ID_PHONE_NUMBERS,
	 *						 			#CONTACT_MPROPERTY_ID_EMAILS, #CONTACT_MPROPERTY_ID_URLS, or #CONTACT_MPROPERTY_ID_ADDRESSES)
	 * @if PRIVCORE
	 * 									, #CONTACT_MPROPERTY_ID_CUSTOM
	 * @endif
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetValuesN(ContactMultiPropertyId id) const;

	/**
	 * Sets the specified phone number corresponding to the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 *	
	 * @param[in]	index				An index to set the value
	 * @param[in]	phoneNumber			An instance of PhoneNumber
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c phoneNumber is empty.
	 * @exception	E_OUT_OF_RANGE		The index is outside the bounds of the properties.
	 */
	result SetPhoneNumberAt(int index, const Osp::Social::PhoneNumber& phoneNumber);

	/**
	 * Sets the specified email corresponding to the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 *
	 * @param[in]	index				An index to set the value
	 * @param[in]	email				An instance of Email
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c email is empty.
	 * @exception	E_OUT_OF_RANGE		The index is outside the bounds of the properties.
	 */
	result SetEmailAt(int index, const Osp::Social::Email& email);

	/**
	 * Sets the specified URL corresponding to the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
 	 *
	 * @param[in]	index				An index to set the value
	 * @param[in]	url					An instance of URL
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c url is empty.
	 * @exception	E_OUT_OF_RANGE		The index is outside the bounds of the properties.
	 */
	result SetUrlAt(int index, const Osp::Social::Url& url);

	/**
	 * Sets the specified address corresponding to the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	address				An address instance
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c address is empty.
	 * @exception	E_OUT_OF_RANGE		The index is outside the bounds of the properties.
	 */
	result SetAddressAt(int index, const Osp::Social::Address& address);

	/**
	 * Sets the specified ImAddress corresponding to the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index				An index to set the value
	 * @param[in]	imAddress			An instance of ImAddress
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c imAddress is empty.
	 * @exception	E_OUT_OF_RANGE		The @c index is outside the bounds of the properties.
	 */
	result SetImAddressAt(int index, const Osp::Social::ImAddress& imAddress);

	/**
	 * @if PRIVCORE
	 * Sets a custom field corresponding to the specified index. @n
	 * Note that the custom field is not supported for the local addressbook.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	index					An index to set the value
	 * @param[in]	customField				An instance of CustomField
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The title of the specified @c customField is empty.
	 * @exception	E_OUT_OF_RANGE			The index is outside the bounds of the properties.
	 * @endif
	 */
	result SetCustomFieldAt(int index, const Osp::Social::CustomField& customField);

private:
	Osp::Base::String	__serviceProviderName;
	Osp::Base::String	__serviceProviderAccount;

	UserId __userId;
	Osp::Base::String __firstName;
	Osp::Base::String __lastName;
	Osp::Base::String __displayName;
	Osp::Base::String __nickName;
	Osp::Base::String __jobTitle;
	Osp::Base::String __company;
	Osp::Base::String __note;
	Osp::Base::DateTime __birthday;

	Osp::Base::String __thumbnail;
	Osp::Base::String __tmpPhotoPath;	// for SetThumbnail()

	Osp::Base::Collection::IList* __pPhoneNumbers;
	Osp::Base::Collection::IList* __pEmails;
	Osp::Base::Collection::IList* __pUrls;
	Osp::Base::Collection::IList* __pAddresses;
	Osp::Base::Collection::IList* __pImAddresses;

private:

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Returns the max length of the property.
	 */
	int __GetMaxLength(ContactPropertyId id);

	Osp::Base::Collection::IList* __GetPhoneNumbersN(void) const;
	Osp::Base::Collection::IList* __GetEmailsN(void) const;
	Osp::Base::Collection::IList* __GetUrlsN(void) const;
	Osp::Base::Collection::IList* __GetAddressesN(void) const;
	Osp::Base::Collection::IList* __GetImAddressesN(void) const;
	Osp::Base::Collection::IList* __GetCustomFieldsN(void) const;

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Replaces the value of CONTACT_PROPERTY_ID_DISPLAY_NAME and CONTACT_PROPERTY_ID_THUMBNAIL properties with the specified value.
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the property to replace
	 * @param[in]	value				The new value to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_INVALID_ARG		The @c id is neither CONTACT_PROPERTY_ID_DISPLAY_NAME nor CONTACT_PROPERTY_ID_THUMBNAIL.
	 */
	result _SetValue(ContactPropertyId id, const Osp::Base::String& value);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Gets the value of CONTACT_PROPERTY_ID_THUMBNAIL property.
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the property whose value is to be retrieved
	 * @param[out]	value				The property value as a String instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified contact property ID is not CONTACT_PROPERTY_ID_THUMBNAIL.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 */
	result _GetValue(ContactPropertyId id, Osp::Base::String& value) const;

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Gets temporary photo path
	 */
	Osp::Base::String	_GetTmpPhotoPath() const;
	
	friend class ContactEx;
	class ContactEx* __pContactEx;

};

};};// Osp::Social

#endif//_FSCL_CONTACT_H_
