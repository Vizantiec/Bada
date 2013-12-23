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
 * @file	FSclCategory.h
 * @brief	This is the header file for the %Category class.
 *
 * This header file contains the declarations of the %Category class.
 */
#ifndef _FSCL_CATEGORY_H_
#define _FSCL_CATEGORY_H_

// Includes
#include "FBase.h"
#include "FBaseColIList.h"
#include "FBaseColIComparer.h"
#include "FSclRecord.h"

namespace Osp { namespace Social {
	
// To create a friendship.
class __AddressbookPi;

// Enums and Constants

/**
 * @deprecated	This constant is deprecated because the maximum length of the category name has been changed.
 *
 * The maximum length of the category name.
 * @since  	1.0
 * */
static const int MAX_CATEGORY_NAME_LENGTH	= 20;

/**
 * @class	Category	
 * @brief	This class represents a category in the contact database. Each category and contact can belong to multiple categories.
 * @since	1.0 
 *
 * The %Category class represents a category in the contact database. Each category and contact can belong to multiple categories.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/category.htm">Category</a>.
 */
class  _EXPORT_SOCIAL_ Category:
	public Record
{

	friend class Osp::Social::__AddressbookPi;
	friend class Osp::Social::Addressbook;

// Construct Operations
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	    1.0
	 * @remarks		In order to add a new category to Addressbook, the category name needs to be set using Category::SetName().
	 * @see			SetName()
	 */
	Category(void);

	/**
	 * This is the copy constructor for the %Category class.
	 *
	 * @since		1.0
	 * @param [in]	value		An instance of %Category
	 */
	Category(const Category& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~Category(void);

	/**
	* This operator copies the data contained in the specified instance of %Category to the current instance.
	*
	* @since		1.0
	* @param [in]	value		The source instance of %Category
	*/
	Category&	operator =(const Category& value);

// Operations
public:
	/**
	 * Adds the specified contact ID to the category. @n
	 * If the contact is already a member of this category, the operation is not performed.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param [in]	contactId			The contact ID to be added
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c contactId is already a member of this category.
	 * @exception	E_INVALID_ARG		The specified @c contactId is not a valid contact ID.
	 */
	result	AddMember(const RecordId contactId);

	/**
	 * Gets the total number of members in the category.
	 * 
	 * @since		1.0
	 * @return		The number of members in the category
	 */
	int GetMemberCount(void) const;

	/**
	 * Gets the name of the category.
	 * 
	 * @since				1.0
	 * @compatibility		This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 						For more information, see @ref CompCategoryGetNamePage "here".
	 *
	 * @return				The name of the category
	 */
	Osp::Base::String GetName(void) const;

	/**
	 * @page		CompCategoryGetNamePage		Compatibility for GetName()
	 * @section		CompCategoryGetNamePageIssueSection		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the length of the category name is greater than 20 characters, only the first 20 characters are returned.
	 *
	 * @section		CompCategoryGetNamePageSolutionSection		Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Checks whether the category contains the specified contact.
	 * 
	 * @since		1.0
	 * @return		@c true if the category contains the specified contact, @n
	 *				else @c false
	 * @param [in]	contactId		The contact ID to be checked
	 * @remarks		If the contact ID is not #RECORD_TYPE_CONTACT, @c false is returned.
	 */
	bool HasMember(const RecordId contactId) const;

	/**
	 * Removes the specified contact from the category. @n
	 * If the specified contact is not a member of the category, the operation is not performed.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param [in]	contactId			The contact ID to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c contactId is not a valid contact ID.
	 */
	result RemoveMember(const RecordId contactId);

	/**
	 * Sets the specified name for the category.
	 *
	 * @since				1.0
	 * @compatibility		This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 						For more information, see @ref CompCategorySetNamePage "here".
	 *
	 * @return		An error code
	 * @param [in]	name		        The name of the category
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c name is an empty string or its length exceeds the maximum length.
	 * @remarks	The maximum length is 20 characters for bada API versions @b prior @b to @b 2.0, 
	 *			whereas, it is 100 characters for bada API versions @b since @b 2.0.
	 */
	result SetName(const Osp::Base::String& name);

	/**
	 * @page		CompCategorySetNamePage		Compatibility for SetName()
	 * @section		CompCategorySetNamePageIssueSection		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the length of the category name to be set, is greater than 20 characters, E_INVALID_ARG is returned.
	 *
	 * @section		CompCategorySetNamePageSolutionSection		Resolutions
	 * The issue mentioned above is resolved bada in API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*/

private:

	/*
	 * Gets the RecordId list of this category for all the members.
	 * This method is only for AddressbookPi.
	 * 
	 * @return		The @c RecordId list of all the members @n
	 *				The list consists of a @c LongLong instance @n
	 *				The returned list must be removed after it is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList*	GetMembersN(void) const;

	/*
	 * Checks whether the name is updated.
	 *
	 * @return		@c true if the name is updated, @n
	 * 				else @c false
	 */
	bool	IsNameUpdated(void) const;

	/*
	 * Gets the @c RecordId list of this category for all the added members.
	 *
	 * @return		The RecordId list of the members, null if there isn't any @n
	 *				The list consists of RecordId instances (@c long @c long) @n
	 *				The returned list must be removed after it is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IListT<RecordId>*	GetAddedMembersN(void) const;

	/*
	 * Gets the @c RecordId list of this category for all the removed members.
	 *
	 * @return		The RecordId list of the members, null if there isn't any @n
	 *				The list consists of RecordId instances (@c long @c long) @n
	 *				The returned list must be removed after it is used.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IListT<RecordId>*	GetRemovedMembersN(void) const;

	/*
	 * Clears the flags.
	 */
	void	ClearFlags(void);

private:
	Osp::Base::String					__name;	/* Name of this category. */
	Osp::Base::Collection::IList*		__pMembers;	/* Members of this category. */
	
	friend class CategoryEx;
	class CategoryEx* __pCategoryEx;

};

};};// Osp::Social

#endif//_FSCL_CATEGORY_H_

