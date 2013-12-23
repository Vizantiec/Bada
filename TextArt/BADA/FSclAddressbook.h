/* $Change: 1224361 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co. Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
* @file		FSclAddressbook.h
* @brief	This is the header file for the %Addressbook class.
*
* This header file contains the declarations of the %Addressbook class.
*/

#ifndef _FSCL_ADDRESSBOOK_H_
#define _FSCL_ADDRESSBOOK_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseColArrayList.h"

#include "FSclContact.h"
#include "FSclIRecordEventListener.h"
#include "FSclIRecordClearResultListener.h"
#include "FSclCategory.h"
#include "FSocialTypes.h"

namespace Osp { namespace Social {

class IAddressbookPi;
class _RecordEvent;

// Enums and Constants

/**
 * @if PRIVCORE
 * Defines the address book ID. @n
 * It is used to identify a specific address book from multiple address books stored in the database.
 *
 * @since 	2.0
 * @endif
 */
typedef	long	AddressbookId;

/**
 * @if PRIVCORE
 * An invalid address book ID indicates that the address book has not been properly stored to the address book database.
 *
 * @since 	2.0
 * @endif
 */
static	const AddressbookId	INVALID_ADDRESSBOOK_ID	=	-1;

/**
 * The minimum length of the query string for searching the contacts by name.
 *
 * @since 	1.0
 * @see 	Addressbook::SearchContactsByNameN()
 */
static const int MIN_NAME_QUERY_LENGTH = 1;
/**
 * The minimum length of the query string for searching the contacts by phone number.
 *
 * @since 	1.0
 * @see 	Addressbook::SearchContactsByPhoneNumberN()
 */
static const int MIN_PHONENUMBER_QUERY_LENGTH = 4;

/**
 * The minimum length of the query string for searching the contacts by email.
 *
 * @since 	1.0
 * @see 	Addressbook::SearchContactsByEmailN()
 */
static const int MIN_EMAIL_QUERY_LENGTH = 1;

/**
 * The minimum length of the query string for searching the contacts by user ID.
 * @deprecated	This constant is deprecated due to the operation policy of bada server.
 *
 * @since 	1.0
 * @see 	Addressbook::SearchContactsByUserIdN()
 */
static const int MIN_USER_ID_QUERY_LENGTH = 1;

/**
 * @class	Addressbook
 * @brief	This class handles the %Addressbook database.
 * @since	1.0
 *
 * The %Addressbook class handles the %Addressbook database, which is a centralized database used by multiple applications to store a subset of the contact information. 
 * It also supports the categorizing of the contacts.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/addressbook_namespace.htm">Address Book</a>. 
 * 
 *The following diagram illustrates the relationships between %Addressbook and the related classes.
 *
 * @image html social_addressbook_using_the_apis_classdiagram.png 
 * 
 * 
 * The following example demonstrates how to use the %Addressbook class to create the categories and add contacts to them.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Osp::Social;
	using namespace Osp::Base;

	void
	AddressbookExample::CreateExample(void)
	{
		result r = E_SUCCESS;
		// Creates and constructs an Addressbook.
		Addressbook addressbook;
		r = addressbook.Construct();
		if(IsFailed(r))
		{
			return;
		}

		// Creates and constructs a contact.
		Contact contact;

		// Sets the contact's properties: first name and last name.
		contact.SetValue(CONTACT_PROPERTY_ID_FIRST_NAME , L"Thomas");
		contact.SetValue(CONTACT_PROPERTY_ID_LAST_NAME , L"Anderson");

		// Sets the contact's properties: add a phone number.
		PhoneNumber phoneNumber(PHONENUMBER_TYPE_MOBILE, L"820223459876");
		contact.AddPhoneNumber(phoneNumber);

		// Sets the contact's properties: add an address.
		Address address;
		address.SetCountry(L"KOR");
		address.SetCity(L"Seoul");
		contact.AddAddress(address);

		// Adds a contact to the address book (when it is added, the recordId is created).
		r = addressbook.AddContact(contact);
		if(IsFailed(r))
		{
			AppLogException( "Fails to add a contact");
			return;
		}

		// Creates and constructs a category ("Friends").
		Category category;
		category.SetName(L"Friends");


		// Adds a category to the address book.
		r = addressbook.AddCategory(category);
		if (IsFailed(r)) {
			return;
		}

		// Adds the contact to the category.
		r = category.AddMember(contact.GetRecordId());
		if (IsFailed(r)) {
			return;
		}

		// Updates the category (so the added category member is applied).
		r = addressbook.UpdateCategory(category);
		if (IsFailed(r)) {
			return;
		}
	}
 *
 * @endcode
 *
 * The following example demonstrates how to use the %Addressbook class to retrieve the contacts associated with each category.
 * @code
 *
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Base::Collection;
	using namespace Osp::Social;

	void
	AddressbookExample::GetContactsExample(void)
	{
		result r = E_SUCCESS;

		// Creates and constructs an Addressbook.
		Addressbook addressbook;
		r = addressbook.Construct();
		if(IsFailed(r))
		{
			return;
		}

		// Gets all the categories.
		IList* pCategoryList = addressbook.GetAllCategoriesN();
		if( (pCategoryList == null) || IsFailed(GetLastResult()) ) {
			return;
		}

		Category* pCategory = null;
		Contact* pContact = null;
		IList* pContactList = null;
		IEnumerator* pContactEnum = null;
		String firstName;
		String lastName;
		IEnumerator* pCategoryEnum = pCategoryList->GetEnumeratorN();
		while (E_SUCCESS == pCategoryEnum->MoveNext())
		{
			pCategory = (Category*) pCategoryEnum->GetCurrent();

			// Gets all the contacts of each category.
			pContactList = addressbook.GetContactsInN(*pCategory, 1, 100);
			if ((pContactList == null) || IsFailed(GetLastResult()))
			{
				continue;
			}

			pContactEnum = pContactList->GetEnumeratorN();
			while (E_SUCCESS == pContactEnum->MoveNext())
			{
				pContact = (Contact*) pContactEnum->GetCurrent();

				//Gets the name.
				pContact->GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
				pContact->GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

				// Displays the first name and last name.
				// ...
			}
			delete pContactEnum;
			pContactList->RemoveAll(true);
			delete pContactList;
		}

		delete pCategoryEnum;
		pCategoryList->RemoveAll(true);
		delete pCategoryList;
	}
 *
 * @endcode
 *
 * The following example demonstrates how to use the %Addressbook class to search for a contact.
 *
 * @code
 *
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Base::Collection;
	using namespace Osp::Social;

	void
	AddressbookExample::SearchExample(void)
	{
		result r = E_SUCCESS;
		//Creates and constructs an Addressbook.
		Addressbook addressbook;
		r = addressbook.Construct();
		if(IsFailed(r))
		{
			return;
		}

		//Searches contacts by name ("Anderson").
		IList* pContactList = addressbook.SearchContactsByNameN(L"Anderson");
		if (pContactList == null || IsFailed(GetLastResult()))
		 {
			return;
		}

		Contact* pContact = null;
		String firstName;
		String lastName;
		IEnumerator* pContactEnum = pContactList->GetEnumeratorN();
		while (E_SUCCESS == pContactEnum->MoveNext())
		{
			pContact = (Contact*) pContactEnum->GetCurrent();

			//Gets the contact's name.
			pContact->GetValue(CONTACT_PROPERTY_ID_FIRST_NAME, firstName);
			pContact->GetValue(CONTACT_PROPERTY_ID_LAST_NAME, lastName);

			// Displays the first name and last name.
			// ...
		}

		delete pContactEnum;
		pContactList->RemoveAll(true);
		delete pContactList;
	}
 *
 * @endcode
 */
class  _EXPORT_SOCIAL_ Addressbook:
	public Osp::Base::Object
{
// Construct Operations
public :
	/**
	 * This is the default constructor for this class. @n
	 * It creates an uninitialized instance of %Addressbook.
	 *
	 * @since 		1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	 *
	 * @see 		Construct()
	 */
	Addressbook(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 		1.0
	 */
	~Addressbook(void);

	/**
	 * Initializes this instance of %Addressbook with the specified listener. @n
	 * The contacts and categories can be read, added, removed, and updated after construction. @n
	 * When registered as an event listener, this method notifies the application when records are added, removed, or updated in the device.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	pListener				The event listener to be registered @n
	 *										The parameter can also contain @c null if not registered as an event listener.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result	Construct(const IRecordEventListener* pListener = null);

	/**
	 * @if PRIVCORE
	 * Initializes this instance of %Addressbook with the specified ID and event listener. @n
	 * The contacts and categories can be read, added, removed, and updated after construction. @n
	 * When registered as an event listener, this method notifies when any records are added, removed, or updated in the device.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	addressbookId			The address book ID to initialize
	 * @param[in]	pListener				The event listener to register @n
	 *										The parameter can also contain @c null if not registered as an event listener.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c addressbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c addressbookId does not exist.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @endif
	 */
	result Construct(AddressbookId addressbookId, const IRecordEventListener* pListener);

// Two phase construction idiom
private:
	Addressbook(const Addressbook& value);
	Addressbook&	operator =(const Addressbook& value);

//Operations
public:

	/**
	 * @if PRIVCORE
	 * Gets the address book ID.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The address book ID, @n
	 *				else @c INVALID_ADDRESSBOOK_ID if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet. 
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	AddressbookId	GetId(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the name of the service provider.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The name of the service provider, @n
	 *				else an empty string if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet. 
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String		GetServiceProviderName(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the account of the service provider.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The account of the service provider, @n
	 *				else an empty string if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet. 
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String	GetServiceProviderAccount(void) const;

	/**
	 * Adds a record to the address book. @n
	 * The contact must have set at least one of the properties. @n
	 * After successfully adding the record, the target record has a valid record ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	contact				The contact to be added
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_STORAGE_FULL		The capacity of this address book is full.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c contact is not a %Contact instance. @n
	 * 									- The record ID is not #INVALID_RECORD_ID. @n
	 * 									- The properties of the contact have not been set.
	 * 					@if PRIVCORE	 When the current address book instance is for a local phone book, the custom property is set @b since: @b 2.0. @endif
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks		The #CONTACT_PROPERTY_ID_DISPLAY_NAME property cannot be set. It automatically consists of the first name and last name. @n
	 * 				Even if the #CONTACT_PROPERTY_ID_DISPLAY_NAME property is a set of %Contact instances, the value is ignored during this operation.
	 */
	result AddContact(Contact& contact);

	/**
	 * Adds a record to the address book.
	 * After this operation is done successfully, the %Category instance has a valid record ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	category			The category to be added
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_STORAGE_FULL		The capacity of this address book is full.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c category is not a Category instance. @n
	 * 									- The record ID is not #INVALID_RECORD_ID. @n
	 * 								 	- The name of the category has not been set. @n
	 * 									- One of the members is an invalid contact.
	 * @exception	E_OBJ_ALREADY_EXIST	A category with the same name already exists in the address book.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		An address book stores only a selective subset of contact properties. @n
	 *				Check the description of the address book to view the properties.
	 */
	result AddCategory(Category& category);

	/**
	 * Removes a contact from the address book.
	 * After this operation is done successfully, the %Contact instance has an invalid record ID (#INVALID_RECORD_ID).
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	contact				The contact to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contact is not a valid %Contact instance.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c contact does not exist in this address book.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveContact(Contact& contact);

	/**
	 * Removes a contact from this address book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	contactId			The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contactId is not a valid contact ID.
	 * @exception	E_OBJ_NOT_FOUND		The specified contact does not exist in this address book.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveContact(RecordId contactId);

	/**
	 * Removes a category from this address book.
	 * After this operation is done successfully, the %Category instance is updated to an invalid record ID (#INVALID_RECORD_ID).
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	category			The category to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c category is not a Category instance.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c category does not exist in this address book.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveCategory(Category& category);

	/**
	 * Removes a category from this address book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	categoryId			The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c categoryId is not a valid category ID.
	 * @exception	E_OBJ_NOT_FOUND		The specified category does not exist in this address book.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveCategory(RecordId categoryId);

	/**
	 * @if PRIVCORE
	 * Removes all the contacts from this address book.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	pResultListener		The listener to receive the event when all the records are cleared
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When the request is completed, the application is notified via IRecordClearResultListener::OnAllRecordsCleared().
	 * @see			IRecordClearResultListener::OnAllRecordsCleared()
	 * @endif
	 */
	result RemoveAllContacts(const IRecordClearResultListener* pResultListener = null);

	/**
	 * @if PRIVCORE
	 * Removes all the categories from the address book.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	pResultListener		The listener to receive the event when all the records are cleared
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When the request is completed, the application is notified via IRecordClearResultListener::OnAllRecordsCleared().
	 * @see			IRecordClearResultListener::OnAllRecordsCleared()
	 * @endif
	 */
	result RemoveAllCategories(const IRecordClearResultListener* pResultListener = null);

	/**
	 * Updates the specified contact in the address book.
	 * The contact must have set at least one of the properties.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	contact				The contact to be updated
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c contact does not exist in this address book.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 * 									- The specified @c contact is not a valid %Contact instance. @n
	 * 									- The properties of the specified @c contact have not been set. @n
	 * 					@if PRIVCORE  When the current %Addressbook instance is for a local phone book, the custom property is set @b since: @b 2.0.	@endif
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When this method is called, the values of those fields that are supported only by the base application (Contacts) such as Department, 
	 *				Spouse, and Children will be discarded. 
	 * 				In order to avoid this issue, it is strongly recommended to use bada API version 2.0 or above. 
	 */
	result UpdateContact(const Contact& contact);

	/**
	 * Updates the specified category in the address book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		An error code
	 * @param[in]	category			The category to be updated
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c category does not exist in this address book.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The specified @c category is not a Category instance. @n
	 * 									- The record ID is #INVALID_RECORD_ID. @n
	 * 									- One of the members is an invalid contact.
	 * @exception	E_OBJ_ALREADY_EXIST	A category with the same name already exists in the address book.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result UpdateCategory(const Category& category);

	/**
	 * Gets a list that contains all the categories present in this address book.
	 * The categories are ordered by name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the categories in the address book, @n
	 *				else an empty list if there is no category, or @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetAllCategoriesN(void) const;

	/**
	 * Gets a list of the contacts in the specified range in the address book. @n
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the contacts in the specified range, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @param[in]	pageNo				The page number of the result list @n
	 *			 						It starts from @c 1.
	 * @param[in]	countPerPage		The maximum count of the result items on a page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_RANGE		The specified @c pageNo or @c countPerPage is less than @c 1.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetContactsN(int pageNo, int countPerPage) const;

	/**
	 * Gets a list of contacts that are in the specified range of the specified category. @n
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the contacts in the specified range of the specified category, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @param[in]	category			The category
	 * @param[in]	pageNo				The page number of the result list, which starts from @c 1
	 * @param[in]	countPerPage		The maximum count of the result items on a page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_RANGE		The specified @c pageNo or @c countPerPage is less than @c 1.
	 * @exception	E_INVALID_ARG		The specified @c category has #INVALID_RECORD_ID.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetContactsInN(const Category& category, int pageNo, int countPerPage) const;

	/**
	 * Gets a list of the contact IDs in the address book. @n
	 * The contact ID is stored in the IList as a @c #LongLong class instance that wraps the contact ID.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetContactsN() to get the contact list.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the contact IDs (#RecordId) in the address book, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		In bada API versions prior to 2.0, this method returns incomplete values. @n
	 * 				For more information, see @ref DefectOfAddressbookGetContactIdsNPage "here".
	 *
	 */
	Osp::Base::Collection::IList* GetContactIdsN(void) const;

	/**
	 * @page	DefectOfAddressbookGetContactIdsNPage	 Issues and workaround solutions for GetContactIdsN()
	 * In bada API versions prior to 2.0, this method returns incomplete contact IDs. @n
	 * The following code snippets are the workaround solution for the above-mentioned issue:
	 *
	 * 1. Define the below-mentioned macro.
	 * @code
	 	 #define ParseRecordId (recordId, type) ( (recordId & 0x00FFFFFFFFFFFFFFLL) | ((long long)type << 56))
	 * @endcode
	 *
	 * 2. Get the fixed contact ID using the macro (ParseRecordId).
	 * The returned contact ID is the contact ID obtained from the result of GetContactIdsN().
	 * @code
		RecordId fixedContactId = INVALID_RECORD_ID;
		fixedContactId = ParseRecordId (returnedContactId, RECORD_TYPE_CONTACT);
	 * @endcode
	 */


	/**
	 * Gets a list of the Category IDs in the address book. @n
	 * The category ID is stored in the IList as a @c LongLong class instance which wraps the category ID.
	 *
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use GetAllCategoriesN() to get the category list.
	 * @since 		2.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the category IDs (#RecordId) in the address book, @n
	 *				else an empty list if there is no category, or @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		In bada API versions prior to 2.0, this method returns incomplete values. @n
	 * 				For more information, see @ref DefectOfAddressbookGetCategoryIdsNPage "here".
	 */
	Osp::Base::Collection::IList* GetCategoryIdsN(void) const;

	/**
	 * @page	DefectOfAddressbookGetCategoryIdsNPage	 Issues and workaround solutions for GetCategoryIdsN()
	 * In bada API versions prior to 2.0, this method returns incomplete category IDs. @n
	 * The following code snippets are the workaround solution for the above-mentioned issue:
	 *
	 * 1. Define the below-mentioned macro.
	 * @code
	 	 #define ParseRecordId (recordId, type) ( (recordId & 0x00FFFFFFFFFFFFFFLL) | ((long long)type << 56))
	 * @endcode
	 *
	 * 2. Get the fixed category ID using the macro (ParseRecordId).
	 * The returned category ID is the category ID obtained from the result of GetCategoryIdsN().
	 * @code
		RecordId fixedCategoryId = INVALID_RECORD_ID;
		fixedCategoryId = ParseRecordId (returnedCategoryId, RECORD_TYPE_CATEGORY);
	 * @endcode
	 */

	/**
	 * Gets a list of all the contacts whose email address contains the specified @c email string. @n
	 * The search operation is performed with a case insensitive key (param: @c email). @n
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the matched contacts, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @param[in]	email				The substring of the email to be searched
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The length of the specified @c email is shorter than #MIN_EMAIL_QUERY_LENGTH, or @n
	 * 									the length of the specified @c email is longer than #MAX_EMAIL_LENGTH.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchContactsByEmailN(const Osp::Base::String& email) const;

	/**
	 * Gets a list of all the contacts that have the specified @c name as a substring of their display name. @n
	 * The display name is a concatenation of the first name, space, and the last name. @n
	 * The search operation is performed with a case insensitive key (param: @c name). @n
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @since 			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompAddressbookSearchContactsByNameNPage "here".
	 * @privlevel		NORMAL
	 * @privgroup		ADDRESSBOOK
	 *
	 * @return		A list of all the matched contacts, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @param[in]	name				The substring of the name to be searched
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The length of the specified @c name is shorter than #MIN_NAME_QUERY_LENGTH, or @n
	 * 									the length of the specified @c name is longer than #MAX_CONTACT_NAME_LENGTH.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Base::Collection::IList* SearchContactsByNameN(const Osp::Base::String& name) const;

	/**
	 * @page	CompAddressbookSearchContactsByNameNPage	Compatibility for SearchContactsByNameN()
	 * @section	CompAddressbookSearchContactsByNameNIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# This method returns all the contacts that have the specified search keyword as a substring of their display name. @n
	 *    However, the method does not work properly with Korean names on Korean operators' devices. 
	 *    Note that in this case, the display name is a concatenation of the first name and the last name without a space in between. 
	 *
	 * @section	CompAddressbookSearchContactsByNameNSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets a list of all the contacts that have the specified @c phoneNumber string as a substring of one of their phone numbers. @n
	 * This method returns the contacts whose phone number match the value of the specified @c phoneNumber. @n
	 * The search operation is performed with a case insensitive key (param: @c phoneNumber). @n 
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the matched contacts @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs
	 * @param[in]	phoneNumber			The substring of the phone number to be searched @n
	 *									This value should contain at least 4 digits.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The length of the specified @c phoneNumber is shorter than #MIN_PHONENUMBER_QUERY_LENGTH, or @n
	 * 									the length of the specified @c phoneNumber is longer than #MAX_PHONE_NUMBER_LENGTH.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchContactsByPhoneNumberN(const Osp::Base::String& phoneNumber) const;

	/**
	 * Gets a list of all the contacts with the specified user ID. @n
	 * The search operation is performed with a case insensitive key (param: @c userId). @n
	 * The contacts are ordered first by the first name, and then by the last name.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the matched contacts, @n
	 *				else an empty list if there is no contact, or @c null if an exception occurs.
	 * @param[in]	userId				The user ID to be searched
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The length of the specified @c userId is shorter than #MIN_USER_ID_QUERY_LENGTH.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchContactsByUserIdN(const UserId& userId) const;

	/**
	 * Gets the number of categories in the address book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		The number of categories in the address book, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCategoryCount(void) const;

	/**
	 * Gets the number of contacts in the address book.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		The number of contacts in the address book, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetContactCount(void) const;

	/**
	 * Gets the contact with the specified contact ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		The matched contact, @n
	 *				else @c null if no contact matches the specified contact ID
	 * @param[in]	contactId			The contact ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c contactId is not a valid contact ID.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND 	The specified record is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Contact* GetContactN(RecordId contactId);

	/**
	 * Gets the category with the specified ID.
	 *
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		The matched category, @n
	 *				else @c null if no category matches the specified category ID
	 * @param[in]	categoryId			The category ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c categoryId is not a valid category ID.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND 	The specified record is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Category* GetCategoryN(RecordId categoryId);

	/**
	 * Gets a list of all the contacts whose information is most recently revised and is in the specified search range. @n
	 * The specified @c start and @c end date values of the search range should be in Coordinated Universal Time (UTC).
	 * The removed contacts are not included in the result.
	 *
	 * @deprecated	This method is deprecated because the management policy of the revised contacts has been changed.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	ADDRESSBOOK
	 *
	 * @return		A list of all the matched contacts, @n
	 *				else an empty list if there is no matched contact, or @c null if an exception occurs
	 * @param[in]	start					The start date of the search range
	 * @param[in]	end						The end date of the search range
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c end value is earlier than the specified @c start value, or @n
	 * 									 	the specified @c start or @c end date is invalid. @n
	 *										The valid range of the date is from 12:00:00 midnight, January 1, 1900 to 11:59:59 P.M, December 31, 2100.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* SearchContactsByLastRevisionN(const Osp::Base::DateTime &start, const Osp::Base::DateTime &end) const;

	/**
	 * @if PRIVCORE
	 * Gets a list of the brief contacts that lie in the specified range of the current instance of Addressbook. @n
	 * The Contact instance has only first name, last name, display name, and a phone number.
	 * If a contact has three phone numbers, this method returns three contacts(#Contact instances)
	 * that contains phone number, name, and the contact ID.
	 * The contacts are ordered first by the contact ID (RecordId), and then by the phone number insert time.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		A list of all the #Contact instances in the specified range @n
	 *				If there is no contact, an empty list is returned, @n
	 *				else @c null if an exception occurs.
	 * @param[in]	pageNo			The page number of the result list that starts from @c 1
	 * @param[in]	countPerPage	The maximum count of the result items on a page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_RANGE		The @c pageNo or @c countPerPage is less than @c 1.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::Collection::IList* GetContactsInBriefN(int pageNo, int countPerPage) const;


private:
	IAddressbookPi*	__pAddressbookPi;
	IRecordEventListener* __pRecordEventListener;
	_RecordEvent*	__pRecordEvent;
	
	friend class AddressbookEx;
	class AddressbookEx* __pAddressbookEx;

};

};};// Osp::Social

#endif//_FSCL_ADDRESSBOOK_H_

