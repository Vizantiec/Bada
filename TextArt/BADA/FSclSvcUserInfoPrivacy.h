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
* @file		FSclSvcUserInfoPrivacy.h
* @brief	This is the header file for the %UserInfoPrivacy class.
*
* This header file contains the declarations of the %UserInfoPrivacy class.
*/
#ifndef _FSCL_SVC_USER_INFO_PRIVACY_H_
#define _FSCL_SVC_USER_INFO_PRIVACY_H_

#include "FSclConfig.h"
#include "FSclSvcTypes.h"


namespace Osp { namespace Social { namespace Services {
// To create a friendship.
class __PrivacyUtil;

/**  The count of the user information groups. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
static const int PRIVACY_USER_INFO_COUNT = 9;


/**
* @class	UserInfoPrivacy
* @brief	This class contains the privacy policies (access level) of all user information.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %UserInfoPrivacy class contains the privacy policies (access level) of all user information.
*
*/

class  _EXPORT_SOCIAL_ UserInfoPrivacy:
	public Osp::Base::Object
{
	// Friend class
	friend class __PrivacyUtil;
	// Construct Operations
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
	*/
	UserInfoPrivacy(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
	*/
	virtual ~UserInfoPrivacy(void);
		
	/**
	* This is the copy constructor for the %UserInfoPrivacy class. @n
	* This creates an instance of the %UserInfoPrivacy class with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %UserInfoPrivacy
	*/
	UserInfoPrivacy(const UserInfoPrivacy& value);

	/**
	* Copies the data contained in the specified instance of %UserInfoPrivacy to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	The source instance of %UserInfoPrivacy
	*/
	UserInfoPrivacy& operator =(const UserInfoPrivacy& value);

	// Operations
public:
	/**
	* Gets the access level of the specified user information.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompUserInfoPrivacyGetAccessLevelPage "here".
	*
	* @return		The access level of the user information, @n
	*				else @c ACCESS_NONE if the value of the specified @c userInfoType is not found
	* @param[in]	userInfoType			The type of the user information
	* @exception 	E_SUCCESS				The method is successful.
	* @exception 	E_INVALID_ARG			The specified @c userInfoType is invalid.
	* @exception 	E_UNSUPPORTED_TYPE		The specified @c userInfoType is not found.
	*/
	AccessLevel GetAccessLevel(UserInfoType userInfoType) const;

	/**
	* @page	CompUserInfoPrivacyGetAccessLevelPage	Compatibility for AddUsersToAcl()
	* @section	CompUserInfoPrivacyGetAccessLevelPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# In some cases, applications arbitrarily access the privacy policy of the user.
	*
	* @section	CompUserInfoPrivacyGetAccessLevelPageSolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	* - ACCESS_NONE is returned, if the value of the @c userInfoType is not found.
	* The following exceptions occur: @n
	* -# E_SUCCESS @n
	* -# E_INVALID_ARG @n
	* -# E_UNSUPPORTED_TYPE @n
	* The specific error code can be accessed using the GetLastResult() method.
	*/

private:
	/*
	* Sets the access level of the specified user information.
	*	
	* @param[in]	userInfoType	The type of user information
	* @param[in]	accessLevel		The access level of user information
	*/
	void SetAccessLevel(UserInfoType userInfoType, AccessLevel accessLevel);
	
private:
	AccessLevel __accessLevelList[PRIVACY_USER_INFO_COUNT];

	friend class UserInfoPrivacyEx;
	class UserInfoPrivacyEx* __pUserInfoPrivacyEx;
}; // class UserInfoPrivacy

};};};// Osp::Social::Services

#endif// _FSCL_SVC_USER_INFO_PRIVACY_H_
