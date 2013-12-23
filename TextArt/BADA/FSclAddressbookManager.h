/* $Change: 658782 $ */
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
 * @file	FSclAddressbookManager.h
 * @brief	This is the header file for the %AddressbookManager class.
 *
 * This header file contains the declarations of the %AddressbookManager class.
 */
#ifndef _FSCL_ADDRESSBOOK_MANAGER_H_
#define _FSCL_ADDRESSBOOK_MANAGER_H_

// Includes
#include "FSclAddressbook.h"

namespace Osp { namespace Social {

class IAddressbookManagerPi;

/**
 * @if PRIVCORE
 * @class	AddressbookManager
 * @brief	This class represents the address book manager.
 * @since	2.0
 *
 * The %AddressbookManager class manages the creation and deletion of an address book. It also retrieves the lists of address book.
 * @endif
 */
class  _EXPORT_SOCIAL_ AddressbookManager:
	public Osp::Base::Object
{
// Enums and Constants
public:

// Construct Operation

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	AddressbookManager(void);

	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	*/
	~AddressbookManager(void);

	/**
	 * @if PRIVCORE
	 * Initializes this instance of %AddressbookManager.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 * 
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @endif
	 */
	result Construct(void);

// Two phase construction idiom.
private:
	AddressbookManager(const AddressbookManager& value);
	AddressbookManager&	operator =(const AddressbookManager& value);

// Operations
public:
	/**
	 * @if PRIVCORE
	 * Creates an address book for the specified service provider and account. @n
	 * Each address book has a corresponding ID (AddressbookId).
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The address book ID, @n
	 *				else @c INVALID_ADDRESSBOOK_ID if an exception occurs
	 * @param[in]	serviceProvider		The name of the service provider
	 * @param[in]	account				The account for the service provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 * 									- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 * 									- One of the specified arguments is empty.
	 * @exception	E_OBJ_ALREADY_EXIST	An address book with the same service provider and same account already exists.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	AddressbookId	CreateAddressbook(const Osp::Base::String& serviceProvider, const Osp::Base::String& account);

	/**
	 * @if PRIVCORE
	 * Deletes the address book with the specified address book ID. @n
	 * All the data belonging to the address book is also deleted.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	addressbookId		The address book ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c addressbookId is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c addressbookId is not found.
	 * @exception	E_ILLEGAL_ACCESS	The specified @c addressbookId is the ID of the default address book. @n
	 *									The default address book cannot be deleted.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result DeleteAddressbook(AddressbookId addressbookId);

	/**
	 * @if PRIVCORE
	 * Gets the address book ID corresponding to the specified service provider and account.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	EXTERNAL_CONTACTS
	 *
	 * @return		The address book ID, @n
	 *				else @c INVALID_ADDRESSBOOK_ID if an exception occurs
	 * @param[in]	serviceProvider		The service provider
	 * @param[in]	account				The account for the service provider
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									- The length of the specified @c serviceProvider is greater than #MAX_SERVICE_PROVIDER_LENGTH. @n
	 * 									- The length of the specified @c account is greater than #MAX_ACCOUNT_LENGTH. @n
	 * 									- One of the specified arguments is empty.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c serviceProvider or @c account does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	AddressbookId	GetAddressbookId(const Osp::Base::String& serviceProvider, const Osp::Base::String& account) const;

	/**
	* @if PRIVCORE
	* Gets all the address books on the device. @n
	* The result of this method always includes the default address book that cannot be deleted.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	EXTERNAL_CONTACTS
	*
	* @return		A list of address book IDs, @n
	* 				else @c null if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	Osp::Base::Collection::IListT<AddressbookId>*	GetAllAddressbooksN(void) const;

private :
	IAddressbookManagerPi*	__iAddressbookManagerInterface;
	
	friend class AddressbookManagerEx;
	class AddressbookManagerEx* __pAddressbookManagerEx;
};

};};// Osp::Social

#endif//_FSCL_ADDRESSBOOK_MANAGER_H_
