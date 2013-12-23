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
* @file		FSclSvcTypes.h 
* @brief	This is the header file for the commonly used enumerations in the %Services namespace.
*
* This header file contains the declarations of the commonly used enumerations.
*/
#ifndef _FSCL_SVC_TYPES_H_
#define _FSCL_SVC_TYPES_H_

#include "FBaseString.h"

namespace Osp { namespace Social { namespace Services {
//////////////////////////////////////////////////////////////////////////////////
// Enum
//////////////////////////////////////////////////////////////////////////////////|

/**
* @enum	AccessLevel
* Defines the access levels.
* The access level determines who can access the specific user information.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
enum AccessLevel {		
	ACCESS_NONE,				/**< The access level with access to none */
	ACCESS_BUDDY,				/**< The buddy access level: Only buddies have access */
	ACCESS_ALL_USERS			/**< All Users access level: All users have access */	
};

/**
* @enum UserInfoType
* Defines the types of user information for access control.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
enum UserInfoType {		
	INFO_PERSONAL_PROFILE,					/**< The personal profile */		
	INFO_CONTACT_PROFILE_ADDRESSES,			/**< The address property in the contact profile */
	INFO_CONTACT_PROFILE_EMAILS,			/**< The email addresses property in the contact profile */
	INFO_CONTACT_PROFILE_PHONENUMBERS,		/**< The phone Number property in the contact profile */
	INFO_CONTACT_PROFILE_URLS,				/**< The URL property in the contact profile */
	INFO_SOCIAL_PROFILE_EDUCATION_HISTORY,	/**< The education History property in the social profile */
	INFO_SOCIAL_PROFILE_WORK_HISTORY,		/**< The work History property in the social profile */
	INFO_CUSTOM_PROFILE,					/**< The custom profile */
	INFO_LOCATION							/**< The location */	
};


/**
* @enum	ProfileExposureLevel
* Defines the exposure levels of the profile.
* The exposure level determines whether a profile is exposed to other users or not.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
enum ProfileExposureLevel {		
	PROFILE_CLOSED,				/**< The closed profile: other users can neither view nor search for the profile */
	PROFILE_VIEWABLE,			/**< The viewable profile: other users can view the profile but they cannot search for it */
	PROFILE_SEARCHABLE			/**< The searchable profile: other users can view and search for the profile */
};


/**
 * @enum	ProfileSearchScope
 * Defines the search scope of CustomProfile.
 *
 * @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
 * @since	2.0
 */
enum ProfileSearchScope {
	PROFILE_SEARCH_SCOPE_APP_USERS,		/**< The users that have signed up for the calling application */
	PROFILE_SEARCH_SCOPE_BUDDIES_IN_APP	/**< The buddies in the calling application */
};

};};};// Osp::Social::Services

#endif	// _FSCL_SVC_TYPES_H_

