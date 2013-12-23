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
* @file		FSclSvcIPrivacyManagerListener.h
* @brief	This is the header file for the %IPrivacyManagerListener interface.
*
* This header file contains declarations of the %IPrivacyManagerListener interface.
*/
#ifndef _FSCL_SVC_IPRIVACY_MANAGER_LISTENER_H_
#define _FSCL_SVC_IPRIVACY_MANAGER_LISTENER_H_

#include "FBaseTypes.h" // for using UserId and RequestId
#include "FBaseString.h" 
#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FSclConfig.h"
#include "FSclSvcTypes.h"
#include "FSclSvcUserInfoPrivacy.h"


namespace Osp { namespace Social { namespace Services {

/**
* @interface	IPrivacyManagerListener 
* @brief		This listener interface is for receiving responses to requests initiated from PrivacyManager.
* @deprecated	This interface is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* 	The %IPrivacyManagerListener interface is for receiving responses to requests initiated from %PrivacyManager. All the member methods defined in 
*	%PrivacyManager operate asynchronously. To receive the result of member methods, a class that implements IPrivacyManagerListener must be 
*	specified.
*
*/
class  _EXPORT_SOCIAL_ IPrivacyManagerListener
	: public Osp::Base::Runtime::IEventListener
{
	// Operations
public:

	/**
	* @if PRIVCORE 
	* Called when the response to PrivacyManager::SetProfilesExposureLevel(), PrivacyManager::SetProfileExposureLevel(), or 
	* PrivacyManager::SetCustomProfileExposureLevel() is received.
	* @else 
	* Called when the response to PrivacyManager::SetProfileExposureLevel() or PrivacyManager::SetCustomProfileExposureLevel() is received.
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @endif
	*
	* @since		1.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result of the request
	* @param[in]	errorCode			The error code from the server
	* @param[in]	errorMsg			The error message from the server
	* @exception	E_SUCCESS			The request is successful.
	* @exception	E_SERVER			An error has occurred on the server side. @n
	*									Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @see	@if PRIVCORE PrivacyManager::SetProfilesExposureLevel(), PrivacyManager::SetProfileExposureLevel(), PrivacyManager::SetCustomProfileExposureLevel()
	*		@else PrivacyManager::SetProfileExposureLevel(), PrivacyManager::SetCustomProfileExposureLevel()
	*		@endif
	*/
	virtual void	OnProfileExposureLevelUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* @if PRIVCORE 
	* Called when the response to PrivacyManager::GetProfilesExposureLevel(), PrivacyManager::GetProfileExposureLevel(), or 
	* PrivacyManager::GetCustomProfileExposureLevel() is received.
	* @else 
	* Called when the response to PrivacyManager::GetProfileExposureLevel() or PrivacyManager::GetCustomProfileExposureLevel() is received.
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @endif
	*
	* @since		1.0
	*
	* @param[in]	reqId				The request ID
	* @param[in]	pExposureLevel		The exposure level of the user's profile @n
	*									else @c null if an error occurs
	* @param[in]	r					The result of the request
	* @param[in]	errorCode			The error code from the server
	* @param[in]	errorMsg			The error message from the server
	* @exception	E_SUCCESS			The request is successful.
	* @exception	E_SERVER			An error has occurred on the server side. @n
	*									Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	* @exception	E_PARSING_FAILED	The response data from the server cannot be parsed.
	* @see	@if PRIVCORE PrivacyManager::GetProfilesExposureLevel(), PrivacyManager::GetProfileExposureLevel(), PrivacyManager::GetCustomProfileExposureLevel()
	*		@else PrivacyManager::GetProfileExposureLevel(), PrivacyManager::GetCustomProfileExposureLevel()
	*		@endif
	*/
	virtual void	OnProfileExposureLevelReceived(RequestId reqId, ProfileExposureLevel* pExposureLevel, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::SetUserInfoPrivacy() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::SetUserInfoPrivacy()
	*/
	virtual void	OnUserInfoPrivacyUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::GetUserInfoPrivacy() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pAccessLevel			The access level, @n
	*										else @c null if an error occurs
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::GetUserInfoPrivacy()
	*/
	virtual void	OnUserInfoPrivacyReceived(RequestId reqId, AccessLevel* pAccessLevel, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::GetAllUserInfoPrivacy() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pUserInfoPrivacy		The privacy value of all user information components
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::GetAllUserInfoPrivacy()
	*/
	virtual void	OnAllUserInfoPrivacyReceived(RequestId reqId, const UserInfoPrivacy* pUserInfoPrivacy, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::AddUsersToAcl() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::AddUsersToAcl()
	*/
	virtual void	OnUsersAddedToAcl(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::RemoveUsersFromAcl() or PrivacyManager::RemoveAllUsersFromAcl()is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::RemoveUsersFromAcl(), PrivacyManager::RemoveAllUsersFromAcl()
	*/
	virtual void	OnUsersRemovedFromAcl(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called when the response to PrivacyManager::GetAllUsersInAcl() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The request ID
	* @param[in]	pUserIdList				The list of user IDs in the Access Control List @n
	*										This list consists of pointers to the user IDs and not the actual UserID instances.
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Check @c errorCode and @c errorMsg for details.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	PrivacyManager::GetAllUsersInAcl()
	*/
	virtual void	OnUsersInAclReceivedN(RequestId reqId, Osp::Base::Collection::IList* pUserIdList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

}; // class IPrivacyManagerListener

};};};// Osp::Social::Services

#endif// _FSCL_SVC_IPRIVACY_MANAGER_LISTENER_H_


