/* $Change: 1230458 $ */
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
 * @file	FSocialServices.h 
 * @brief	This is the header file for %Services namespace.
 *
 * This header file contains the declarations and descriptions of the %Services namespace.
 */

#ifndef _FSOCIAL_SERVICES_H_
#define _FSOCIAL_SERVICES_H_

// Includes
#include "FSclSvcTypes.h"

#include "FSclSvcProfileTypes.h"
#include "FSclSvcProfileService.h"
#include "FSclSvcIProfileServiceListener.h"
#include "FSclSvcProfiles.h"
#include "FSclSvcBasicProfile.h"
#include "FSclSvcPersonalProfile.h"
#include "FSclSvcContactProfile.h"
#include "FSclSvcSocialProfile.h"
#include "FSclSvcCustomProfile.h"
#include "FSclSvcEducationInfo.h"
#include "FSclSvcWorkInfo.h"
#include "FSclSvcCustomProfileFilter.h"

#include "FSclSvcBuddyTypes.h"
#include "FSclSvcBuddyService.h"
#include "FSclSvcIBuddyServiceListener.h"
#include "FSclSvcBuddy.h"
#include "FSclSvcBuddyCategory.h"
#include "FSclSvcSentBuddyRequest.h"
#include "FSclSvcReceivedBuddyRequest.h"
#include "FSclSvcBuddyResponse.h"

#include "FSclSvcPrivacyManager.h"
#include "FSclSvcIPrivacyManagerListener.h"
#include "FSclSvcUserInfoPrivacy.h"

#include "FSclSvcMessagingService.h"
#include "FSclSvcIMessagingServiceListener.h"
#include "FSclSvcIMessagingServiceEventListener.h"

#include "FSclSvcSnsGateway.h"
#include "FSclSvcISnsGatewayListener.h"
#include "FSclSvcISnsContentListener.h"
#include "FSclSvcISnsPeopleListener.h"
#include "FSclSvcISnsPostListener.h"
#include "FSclSvcSnsAlbumInfo.h"
#include "FSclSvcSnsImageInfo.h"
#include "FSclSvcSnsPhotoInfo.h"
#include "FSclSvcSnsStatusText.h"
#include "FSclSvcSnsProfile.h"
#include "FSclSvcSnsActivity.h"
#include "FSclSvcSnsUploadContentInfo.h"
#include "FSclSvcSnsPagingParam.h"
#include "FSclSvcSnsAuthenticator.h"
#include "FSclSvcISnsAuthenticatorListener.h"
#include "FSclSvcSnsAuthResult.h"
#include "FSclSvcSnsPostInfo.h"

namespace Osp { namespace Social {
/**
 * @namespace		Osp::Social::Services
 * @brief		This namespace contains the classes and interfaces for social-related services.
 * @deprecated		This namespace is deprecated due to the operation policy of the bada Server.
 * @since		1.0 
 *
 * @remarks		@b Header @b %file: @b \#include @b <FSocial.h> @n
 *				@b Library: @b FOsp
 *
 * The %Services namespace contains the classes and interfaces for social-related services.
 * The purpose of the %Services namespace is to build social relationships between bada users, and to use these relationships to enrich any service that is 
 * built and running on top of bada. This namespace includes the classes and methods for the following services:
 * - Profile service
 * - Buddy service
 * - Privacy management
 * - SNS authentication @n
 *
 * For more information on the %Services namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/social_namespace.htm">Social Guide</a>.
 *
 */
namespace Services
{

};		// Osp::Social::Services
};};	// Osp::Social

#endif// _FSOCIAL_SERVICES_H_

