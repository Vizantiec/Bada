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
* @file		FSclSvcBuddyCategory.h
* @brief	This is the header file for the %BuddyCategory class.
*
* This header file contains the declarations of the %BuddyCategory class.
*/
#ifndef _FSCL_SVC_BUDDY_CATEGORY_H_
#define _FSCL_SVC_BUDDY_CATEGORY_H_

// Includes
#include "FSclConfig.h"
#include "FBaseErrors.h" // for using error code
#include "FSclSvcBuddyTypes.h"

namespace Osp { namespace Social { namespace Services {

// To create friendship.
class __BuddyUtil;

/**
* @class	BuddyCategory 
* @brief	This class represents a buddy category.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* 	The %BuddyCategory class represents a buddy category. A buddy category is a user-defined group of buddies with similar characteristics.
* 	For example, a user may create a category containing his family, or members of a book club. Since the buddy category is identified by the name, 
*	the name must be unique within the scope of the user.
*
*/
class  _EXPORT_SOCIAL_ BuddyCategory:
	public Osp::Base::Object
{
	// Friend class
	friend class __BuddyUtil;

protected:
	/**
	* Initializes this instance with the specified category ID and name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	categoryId		The ID of the buddy category
	* @param[in]	categoryName	The name of the buddy category
	*/
	BuddyCategory(const BuddyCategoryId& categoryId, const Osp::Base::String& categoryName);

	// Construct Operations
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	BuddyCategory(void);

	/**
	* This is the copy constructor for the %BuddyCategory class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 	An instance of %BuddyCategory
	*/
	BuddyCategory(const BuddyCategory& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~BuddyCategory(void);

public:
	/**
	* Copies the data contained in the specified %BuddyCategory to this instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 	The source instance of the %BuddyCategory
	*/
	BuddyCategory& operator =(const BuddyCategory& value);	
	
	// Operations
public:
	/**
	* Gets the ID of the buddy category.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The ID of the buddy category
	*/
	BuddyCategoryId GetId(void) const;

	/**
	* Gets the name of the buddy category.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The name of the buddy category
	*/
	Osp::Base::String GetName(void) const;

	/**
	* Sets the name of the buddy category. @n
	* Since the buddy category is identified by its name, the name must be unique within the scope of the user.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	categoryName 		The name of the buddy category
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c categoryName is an empty string, or @n
	* 									the length of the specified @c categoryName exceeds #MAX_BUDDY_CATEGORY_NAME_LENGTH. 
	*/
	result SetName(const Osp::Base::String& categoryName);


	// Variables
private:
	BuddyCategoryId __id;
	Osp::Base::String __name;

	friend class BuddyCategoryEx;
	class BuddyCategoryEx* __pBuddyCategoryEx;
}; // class BuddyCategory

};};};// Osp::Social::Services

#endif// _FSCL_SVC_BUDDY_CATEGORY_H_
