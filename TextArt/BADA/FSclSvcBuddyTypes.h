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
* @file		FSclSvcBuddyTypes.h 
* @brief	This is the header file that defines the commonly used enumerations.
*
* This header file contains the declarations of the commonly used enumerations.
*/
#ifndef _FSCL_SVC_BUDDY_TYPES_H_
#define _FSCL_SVC_BUDDY_TYPES_H_

#include "FBaseString.h"

namespace Osp { namespace Social { namespace Services {

//////////////////////////////////////////////////////////////////////////////////
// type redefinitions
//////////////////////////////////////////////////////////////////////////////////
/**
* The buddy category ID
*
* @deprecated	This type is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
typedef Osp::Base::String	BuddyCategoryId;

//////////////////////////////////////////////////////////////////////////////////
// enum
//////////////////////////////////////////////////////////////////////////////////|

/**
* Defines the responses to the buddy request.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
enum BuddyResponseType {		
	RESPONSE_ACCEPT = 2,	/**< The response approving the creation of the buddy relationship */	
	RESPONSE_DENY = 3,		/**< The response denying the creation of the buddy relationship	*/		
	RESPONSE_IGNORE = 4		/**< The response ignoring the received buddy request */
};

/**
* Defines the friendship level of a buddy.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
enum BuddyFriendshipLevel {
	FRIENDSHIP_LEVEL_1 = 1, 	/**< The friendship level 1 */
	FRIENDSHIP_LEVEL_2, 		/**< The friendship level 2 */
	FRIENDSHIP_LEVEL_3, 		/**< The friendship level 3 */
	FRIENDSHIP_LEVEL_4, 		/**< The friendship level 4 */
	FRIENDSHIP_LEVEL_5 			/**< The friendship level 5 */
};

//////////////////////////////////////////////////////////////////////////////////
// const
//////////////////////////////////////////////////////////////////////////////////
/** The maximum length of the buddy label. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_BUDDY_LABEL_LENGTH = 50;	

/** The maximum length of the name of the buddy category. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_BUDDY_CATEGORY_NAME_LENGTH		= 50;

};};};// Osp::Social::Services

#endif	// _FSCL_SVC_BUDDY_TYPES_H_

