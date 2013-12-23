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
* @file		FSclSvcIProfileServiceListener.h
* @brief	This is the header file for the %IProfileServiceListener interface.
*
* This header file contains the declarations of the %IProfileServiceListener interface.
*/
#ifndef _FSCL_SVC_IPROFILE_SERVICE_LISTENER_H_
#define _FSCL_SVC_IPROFILE_SERVICE_LISTENER_H_

// Includes

#include "FBaseTypes.h" // for using UserId and RequestId
#include "FBaseRtIEventListener.h"
#include "FSclConfig.h"
#include "FSclSvcProfiles.h"
#include "FSclSvcBasicProfile.h"
#include "FSclSvcPersonalProfile.h"
#include "FSclSvcContactProfile.h"
#include "FSclSvcSocialProfile.h"
#include "FSclSvcCustomProfile.h"
#include "FSclSvcProfileTypes.h"


namespace Osp { namespace Social { namespace Services {

/**
* @interface	IProfileServiceListener
* @brief		This listener interface is for receiving the responses to requests which are initiated from ProfileService.
* @deprecated	This interface is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* The %IProfileServiceListener interface is for receiving the responses to requests which are initiated from ProfileService.
*/
class  _EXPORT_SOCIAL_ IProfileServiceListener
	: public Osp::Base::Runtime::IEventListener
{
	// Operations
public:
	/**
	* Called when the response to ProfileService::GetMyProfile() is received from the server.
	* The received ContactProfile data is not sorted. The items (EducationInfo, WorkInfo) of the received SocialProfile are sorted by start date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	requestedProfileType	The profile type requested by ProfileService::GetMyProfile()
	* @param[in]	pBasicProfile			The basic profile received from the server, @n
	*										else @c null if an error occurs or the basic profile is not requested
	* @param[in]	pPersonalProfile		The personal profile received from the server, @n
	*										else @c null if an error occurs or the personal profile is not requested
	* @param[in]	pContactProfile			The contact profile received from the server, @n
	*										else @c null if an error occurs or the contact profile is not requested
	* @param[in]	pSocialProfile			The social profile received from the server, @n
	*										else @c null if an error occurs or the social profile is not requested
	* @param[in]	pCustomProfile			The custom profile received from the server, @n
	*										else @c null if an error occurs or the custom profile is not requested
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	ProfileService::GetMyProfile()
	*/
	virtual void	OnMyProfileReceived(RequestId reqId,
						unsigned long requestedProfileType, BasicProfile* pBasicProfile, PersonalProfile *pPersonalProfile,
						ContactProfile* pContactProfile, SocialProfile* pSocialProfile, CustomProfile* pCustomProfile,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to ProfileService::GetProfile() is received from the server.
	* The received ContactProfile data is not sorted. The items (EducationInfo, WorkInfo) of the received SocialProfile are sorted by start date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	requestedProfileType	The profile type requested by ProfileService::GetProfile()
	* @param[in]	pBasicProfile			The basic profile received from the server, @n
	*										else @c null if an error occurs or the basic profile is not requested
	* @param[in]	pPersonalProfile		The personal profile received from the server, @n
	*										else @c null if an error occurs or the personal profile is not requested
	* @param[in]	pContactProfile			The contact profile received from the server, @n
	*										else @c null if an error occurs or the contact profile is not requested
	* @param[in]	pSocialProfile			The social profile received from the server, @n
	*										else @c null if an error occurs or the social profile is not requested
	* @param[in]	pCustomProfile			The custom profile received from the server, @n
	*										else @c null if an error occurs or the custom profile is not requested
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	ProfileService::GetProfile()
	*/
	virtual void	OnProfileReceived(RequestId reqId,
						unsigned long requestedProfileType, const BasicProfile* pBasicProfile, const PersonalProfile *pPersonalProfile,
						const ContactProfile* pContactProfile, const SocialProfile* pSocialProfile, const CustomProfile* pCustomProfile,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to ProfileService::GetProfiles() is received from the server.
	* The received ContactProfile data is not sorted. The items (EducationInfo, WorkInfo) of the received SocialProfile are sorted by start date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	requestedProfileType	The profile type requested by ProfileService::GetProfiles()
	* @param[in]	pProfilesList			A list of the Profiles which have a BasicProfile, a PersonalProfile, a ContactProfile, a SocialProfile, 
	*										and a CustomProfile, @n
	*										else @c null if an error occurs
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	ProfileService::GetProfiles()
	*
	* @code
	*
		Profiles* pProfiles = null;
		pProfiles = dynamic_cast<Profiles*>(pProfilesList->GetAt(0));
		const BasicProfile *pBasicProfile = dynamic_cast<const BasicProfile *>(pProfiles->GetProfile(PROFILE_TYPE_BASIC));
	    String fistName = pBasicProfile->GetValue(BP_PID_FIRST_NAME);

	* @endcode
	*/
	virtual void	OnProfilesReceivedN(RequestId reqId,
					unsigned long requestedProfileType, Osp::Base::Collection::IList* pProfilesList,
					result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* @if PRIVCORE 
	* Called when the response to ProfileService::UpdateMyProfile() or ProfileService::UpdateMyProfiles() is received from the server. In case of 
	* ProfileService::UpdateMyProfiles(), the response can be identified by the specified reqId and updatedProfileType.
	* @else 
	* Called when the response to ProfileService::UpdateMyProfile() is received from the server.
	* @endif
	* If the error occurs on the server side, all the modified profile data of the request is not updated.
	* The updated ContactProfile data is not sorted. The updated items(EducationInfo, WorkInfo)of the received SocialProfile are sorted by start date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	updatedProfileType		@if PRIVCORE The profile type updated by ProfileService::UpdateMyProfile() or ProfileService::UpdateMyProfiles()
	*										@else The profile type updated by ProfileService::UpdateMyProfile()
	*										@endif
	* @param[in]	pUpdatedProfile			The updated profile, @n
	*										else @c null if an error occurs
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED		The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	@if PRIVCORE ProfileService::UpdateMyProfile(), ProfileService::UpdateMyProfiles()
	*		@else ProfileService::UpdateMyProfile()
	*		@endif
	*/
	virtual void	OnMyProfileUpdated(RequestId reqId, ProfileType updatedProfileType, Profile* pUpdatedProfile,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to ProfileService::SearchProfilesByName(), ProfileService::SearchProfilesByEmail(), 
	* ProfileService::SearchProfilesByPhoneNumber(), ProfileService::SearchProfilesByLoginId(), or ProfileService::SearchProfilesByCustomProfileFilter() is 
	* received from the server.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pBasicProfileList		The result list containing profiles of matched users, @n
	*										else an empty list if no match is found or @c null if an error occurs @n
	*										The list consists of the basic profiles of users.
	* @param[in]	pageNo					The page number of the result list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The result count of pages on this search
	* @param[in]	totalCount				The result count of this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS				The request is successful.
	* @exception	E_SERVER				An error has occurred on the server side.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see			BasicProfile, ProfileService::SearchProfilesByName(), ProfileService::SearchProfilesByEmail(), 
	* ProfileService::SearchProfilesByPhoneNumber(), ProfileService::SearchProfilesByLoginId(), ProfileService::SearchProfilesByCustomProfileFilter()
	*/
	virtual void	OnProfileSearchResultsReceivedN(RequestId reqId,
						Osp::Base::Collection::IList* pBasicProfileList,
						int pageNo, int countPerPage, int totalPageCount, int totalCount,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
};

};};};// Osp::Social::Services

#endif// _FSCL_SVC_IPROFILE_SERVICE_LISTENER_H_


