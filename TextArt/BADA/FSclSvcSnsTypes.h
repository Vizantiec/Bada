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
* @file		FSclSvcSnsTypes.h
* @brief	This is the header file for the commonly used enumerations in the %SnsGateway class.
*
* This header file contains some of the type declarations of the %SnsGateway class.
*/

#ifndef _FSCLSVC_SNSTYPES_H_
#define	_FSCLSVC_SNSTYPES_H_

#include "FBase.h"
#include "FSclConfig.h"
#include "FSclSvcTypes.h"

namespace Osp { namespace Social { namespace Services {
	


	/**
	* @enum		SnsActivityType
	* Defines the types of activity.
	*
	* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	enum SnsActivityType {
        SNS_ACTIVITY_TYPE_NONE = 0,             /**< The SNS activity type is None */
        SNS_ACTIVITY_TYPE_STATUS = 1,			/**< The SNS activity type is updating the status text */
        SNS_ACTIVITY_TYPE_STATUS_MOBILE,		/**< The SNS activity type is updating the status text through the mobile device. Only for Facebook */
		
        SNS_ACTIVITY_TYPE_PHOTO,				/**< The SNS activity type is uploading photo */
        SNS_ACTIVITY_TYPE_PHOTO_ADD,			/**< The SNS activity type is uploading photo */
        SNS_ACTIVITY_TYPE_PHOTO_COMMENT,		/**< The SNS activity type is commenting on a photo */
        SNS_ACTIVITY_TYPE_PHOTO_MOBILE,			/**< The SNS activity type is uploading photo through mobile device */
        SNS_ACTIVITY_TYPE_PHOTO_TAG,			/**< The SNS activity type is tagging on photo */
        SNS_ACTIVITY_TYPE_PHOTO_SHARE,			/**< The SNS activity type is sharing photo */
		
        SNS_ACTIVITY_TYPE_EVENT,				/**< The SNS activity type is creating event */
        SNS_ACTIVITY_TYPE_EVENT_PHOTO,			/**< The SNS activity type is adding photo to event */
        SNS_ACTIVITY_TYPE_EVENT_SHARE,			/**< The SNS activity type is sharing event */
		
        SNS_ACTIVITY_TYPE_GROUP,				/**< The SNS activity type is creating group */
        SNS_ACTIVITY_TYPE_GROUP_PHOTO,			/**< The SNS activity type is adding photo to group */
        SNS_ACTIVITY_TYPE_GROUP_SHARE,			/**< The SNS activity type is sharing group */
		
        SNS_ACTIVITY_TYPE_URL_LINK,				/**< The SNS activity type is creating link of URL */
        SNS_ACTIVITY_TYPE_SHARE_LINK,			/**< The SNS activity type is sharing link of URL */
		
        SNS_ACTIVITY_TYPE_NOTE,					/**< The SNS activity type is creating note */
        SNS_ACTIVITY_TYPE_NOTE_SHARE,			/**< The SNS activity type is sharing note */
		
        SNS_ACTIVITY_TYPE_VIDEO,				/**< The SNS activity type is uploading video */
        SNS_ACTIVITY_TYPE_VIDEO_SHARE,			/**< The SNS activity type is sharing video */
        SNS_ACTIVITY_TYPE_VIDEO_LINK,			/**< The SNS activity type is creating link of video */
        SNS_ACTIVITY_TYPE_VIDEO_TAG,            /**< The SNS activity type is tagging on video */

        SNS_ACTIVITY_TYPE_FRIEND,				/**< The SNS activity type is make relationship with friend */
        SNS_ACTIVITY_TYPE_FRIEND_SHARE,			/**< The SNS activity type is sharing friend */

        SNS_ACTIVITY_TYPE_OTHERS				/**< The SNS activity type is undefined */

	};

	/**
	* @enum SnsPrivacyLevel
	* Defines the type of privacy levels for the SNS contents.
	*
	* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	enum SnsPrivacyLevel {
		SNS_PRIVACY_LEVEL_PRIVATE,				/**< The private level*/
		SNS_PRIVACY_LEVEL_CUSTOM,				/**< The custom level*/
		SNS_PRIVACY_LEVEL_FRIENDS_ONLY,			/**< The friends only level*/
		SNS_PRIVACY_LEVEL_NETWORKS_ONLY,		/**< The networks only level*/
		SNS_PRIVACY_LEVEL_FRIENDS_OF_FRIENDS,	/**< The friends of friends level*/
		SNS_PRIVACY_LEVEL_PUBLIC				/**< The public level*/
	};

	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 * @if PRIVCORE
	 * @enum SnsSsoSp
	 * Defines predefined type of service provider.
	 *
	 * @deprecated	This enum is deprecated because it is not allowed to manage the information of user login status for SNS any longer.
	 * @since			1.0
	 * @endif
	*/
	enum SnsSsoSp {
	    SNS_SSO_SP_FACEBOOK = 0,             /**< @internal Facebook */
	    SNS_SSO_SP_MYSPACE = 1,              /**< @internal MySpace */
	    SNS_SSO_SP_TWITTER = 2    			/**< @internal Twitter*/
	};


}; }; }; // Osp::Social::Services

#endif// _FSCLSVC_SNSTYPES_H_
