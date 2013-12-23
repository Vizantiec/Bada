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
* @file		FSclSvcProfile.h
* @brief	This is the header file for the %Profile class.
*
* This header file contains the declarations of the %Profile class.
*/
#ifndef _FSCL_SVC_PROFILE_H_
#define _FSCL_SVC_PROFILE_H_

// Includes
#include "FBaseResult.h"
#include "FBaseTypes.h" // for using UserId
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

/**
* @class	Profile 
* @brief	This class represents the profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* 	The %Profile class represents the profile of a user.
*
* The following diagram illustrates the relationships between %Profile and related classes.
* @image html social_profile_using_the_apis_classdiagram.png
*/
class  _EXPORT_SOCIAL_ Profile:
	public Osp::Base::Object
{
	// Construct Operation
protected:
	/**
	* This is the default constructor for this class.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	Profile(void):__pProfileEx(null)
	{};

	/**
	* This is the constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	userId			The user ID
	*/
	Profile(const UserId& userId);

	/**
	* Sets the userId.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	userId			The user ID
	*/
	void SetUserId(const UserId& userId);


public:

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~Profile(void);

	//Operations
public:
	/**
	* Gets the user ID of the profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The user ID of the profile
	*/
	UserId GetUserId(void) const;

private:
	UserId	__userId;	

private:
	friend class ProfileEx;
	class ProfileEx* __pProfileEx;

}; // Profile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_PROFILE_H_
