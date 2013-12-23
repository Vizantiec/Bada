/* $Change: 1143281 $ */
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
* @file		FSclSvcProfileTypes.h 
* @brief	This is the header file for defining the commonly used enumerations.
*
* This header file contains the declarations of the commonly used enumerations.
*/
#ifndef _FSCL_SVC_PROFILE_TYPES_H_
#define _FSCL_SVC_PROFILE_TYPES_H_


namespace Osp { namespace Social { namespace Services {
//////////////////////////////////////////////////////////////////////////////////
// enum
//////////////////////////////////////////////////////////////////////////////////|
/**
* Defines the classes for categorizing the profile properties into some frequently used sub-classes.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
enum ProfileType {
	PROFILE_TYPE_INVALID = 0x00000000,
	PROFILE_TYPE_BASIC	= 0x00000001,	/**< The basic profile. Reference the BasicProfile class. */
	PROFILE_TYPE_PERSONAL = 0x00000002,	/**< The personal profile. Reference the PersonalProfile class. */
	PROFILE_TYPE_CONTACT = 0x00000004,	/**< The contact profile. Reference the ContactProfile class. */
	PROFILE_TYPE_SOCIAL = 0x00000008,	/**< The social profile. Reference the SocialProfile class. */
	PROFILE_TYPE_CUSTOM = 0x00000010	/**< The custom profile. Reference the CustomProfile class. */
};


//////////////////////////////////////////////////////////////////////////////////
// const
//////////////////////////////////////////////////////////////////////////////////
/** The maximum length of the name properties (first name, last name, additional name, name prefix, and name suffix). 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int	MAX_PROFILE_NAME_LENGTH = 50;

/** The maximum length of the user name. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int	MAX_PROFILE_USER_NAME_LENGTH     = 110;

/** The maximum length of the display name. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int	MAX_PROFILE_DISPLAY_NAME_LENGTH  = 110;


};};};// Osp::Social::Services

#endif	// _FSCL_SVC_PROFILE_TYPES_H_

