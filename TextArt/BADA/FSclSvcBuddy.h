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
* @file		FSclSvcBuddy.h
* @brief	This is the header file for the %Buddy class.
*
* This header file contains the declarations of the %Buddy class.
*/
#ifndef _FSCL_SVC_BUDDY_H_
#define _FSCL_SVC_BUDDY_H_

// Includes
#include "FSclConfig.h"
#include "FBaseTypes.h" // for using UserId
#include "FBaseErrors.h" // for using error code
#include "FSclSvcBuddyTypes.h"

namespace Osp { namespace Social { namespace Services {

// To create a friendship.
class __BuddyUtil;

/**
* @class 	Buddy 
* @brief	This class represents a buddy.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
* 
* The %Buddy class represents a buddy.
*
* The following diagram illustrates the relationships between the %Buddy and related classes.
* @image html social_buddy_using_the_apis_classdiagram.png
*/
class  _EXPORT_SOCIAL_ Buddy:
	public Osp::Base::Object
{
	// Friend class
	friend class __BuddyUtil;

	// Construct Operations
protected:
	/**
	* Initializes this instance with the specified user ID and user name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	userId		The user ID
	* @param[in]	userName	The user name
	*/
	Buddy(const UserId& userId, const Osp::Base::String& userName);

public:

	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	Buddy(void);

	/**
	* This is the copy constructor for the %Buddy class.
	*
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 	An instance of %Buddy
	*/
	Buddy(const Buddy& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~Buddy(void);

public:
	/**
	* Copies the data contained in the specified %Buddy instance to this instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 		The source instance of %Buddy
	*/
	Buddy& operator =(const Buddy& value);	

	//Operations
public:
	/**
	* Gets the user ID of the buddy.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The user ID of the buddy
	*/
	UserId GetUserId(void) const;

	/**
	* Gets the user name of the buddy. @n
	* The user name is the @c BP_PID_USER_NAME property of the profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The user name of the buddy
	*/
	Osp::Base::String GetName(void) const;
	
	/**
	* Gets the label of the buddy.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The label of the buddy, @n
	*			else an empty string if the buddy has no label
	*/
	Osp::Base::String GetLabel(void) const;

	/**
	* Gets the friendship level of the buddy.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The friendship level of the buddy
	*/
	BuddyFriendshipLevel GetFriendshipLevel(void) const;

	/**
	* Sets the label for this buddy.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	label 			The label to be set
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified @c label exceeds #MAX_BUDDY_LABEL_LENGTH.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	*/
	result SetLabel(const Osp::Base::String& label);

	/**
	* Sets the friendship level of the buddy.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	level	The friendship level to be set
	*/
	void SetFriendshipLevel(BuddyFriendshipLevel level);

	//variables
private:
	UserId __userId;
	Osp::Base::String __userName;
	Osp::Base::String __label;
	BuddyFriendshipLevel __friendshipLevel;

	friend class BuddyEx;
	class BuddyEx* __pBuddyEx;
}; // class buddy

};};};// Osp::Social::Services

#endif// _FSCL_SVC_BUDDY_H_
