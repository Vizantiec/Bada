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
* @file		FSclSvcPrivacyManager.h
* @brief	This is the header file for the %PrivacyManager class.
*
* This header file contains the declarations of the %PrivacyManager class.
*/
#ifndef _FSCL_SVC_PRIVACY_MANAGER_H_
#define _FSCL_SVC_PRIVACY_MANAGER_H_

#include <FBaseTypes.h>
#include <FBaseColIList.h>
#include <FSclConfig.h>
#include <FSclSvcIPrivacyManagerListener.h>
#include <FSclSvcTypes.h>

struct IPrivacyManager;

namespace Osp { namespace Social { namespace Services {

/**
* @class	PrivacyManager
* @brief	This class manages the privacy policy of the signed-in user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* 	The %PrivacyManager class manages the privacy policy of the signed-in user, such as, the privacy of the profile and location data. All the member methods of this 
*			class operate asynchronously. To receive the result of a member method, a class that implements IPrivacyManagerListener must be specified. @n
*
* The following diagram illustrates the relationships between the %PrivacyManager and related classes.
*
* @image html social_privacy_using_the_apis_classdiagram.png
*
* @if PRIVCORE
* The following example demonstrates how to use the %PrivacyManager class.
* @code
	#include <FBase.h>
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Social::Services;

	class PrivacyManagerSample
	: public IPrivacyManagerListener
	{
	public:
		PrivacyManagerSample(void);
		~PrivacyManagerSample(void);

	public:
		result OpenMyProfile(void);

	private:
		void OnProfileExposureLevelUpdated(RequestId reqId, result r, const String& errorCode, const String& errorMsg);
		void OnProfileExposureLevelReceived(RequestId reqId, ProfileExposureLevel* pExposureLevel, result r, const String& errorCode, const String& errorMsg) {};
		void OnUserInfoPrivacyUpdated(RequestId reqId, result r, const OString& errorCode, const String& errorMsg) {};
		void OnUserInfoPrivacyReceived(RequestId reqId, AccessLevel* pAccessLevel, result r, const String& errorCode, const String& errorMsg) {};
		void OnAllUserInfoPrivacyReceived(RequestId reqId, const UserInfoPrivacy* pUserInfoPrivacy, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersAddedToAcl(RequestId reqId, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersRemovedFromAcl(RequestId reqId, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersInAclReceivedN(RequestId reqId, Collection::IList* pUserIdList, result r, const String& errorCode, const String& errorMsg) {};

	private:
		PrivacyManager __privacyManager;
	};

	result
	PrivacyManagerSample::OpenMyProfile(void)
	{
		result r = E_SUCCESS;
		RequestId reqId;

		r = privacyManager.Construct(*this);
		if (IsFailed(r))
			return r;

		// Request to update the profile exposure level.
		// This is the asynchronous operation. When it is completed, OnProfileExposureLevelUpdated() is called.
		r = privacyManager.SetProfileExposureLevel(PROFILE_SEARCHABLE, reqId);
		if (IsFailed(r))
			return r;

		return E_SUCCESS;
	}

	void
	PrivacyManagerSample::OnProfileExposureLevelUpdated(RequestId reqId, result r, const String& errorCode, const String& errorMsg)
	{
		if (IsFailed(r))
			AppLogException("Fail to set Profile Exposure Level (%s, %S)", GetErrorMessage(r), errorMsg.GetPointer());
		else
			AppLog("Success to set Profile Exposure Level");
	}

* @endcode
* @else
* The following example demonstrates how to use the %PrivacyManager class.
* @code
	#include <FBase.h>
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Social::Services;

	class PrivacyManagerSample
	: public IPrivacyManagerListener
	{
	public:
		PrivacyManagerSample(void);
		~PrivacyManagerSample(void);

	public:
		result OpenMyCustomProfile(void);

	private:
		void OnProfileExposureLevelUpdated(RequestId reqId, result r, const String& errorCode, const String& errorMsg);
		void OnProfileExposureLevelReceived(RequestId reqId, ProfileExposureLevel* pExposureLevel, result r, const String& errorCode, const String& errorMsg) {};
		void OnUserInfoPrivacyUpdated(RequestId reqId, result r, const OString& errorCode, const String& errorMsg) {};
		void OnUserInfoPrivacyReceived(RequestId reqId, AccessLevel* pAccessLevel, result r, const String& errorCode, const String& errorMsg) {};
		void OnAllUserInfoPrivacyReceived(RequestId reqId, const UserInfoPrivacy* pUserInfoPrivacy, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersAddedToAcl(RequestId reqId, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersRemovedFromAcl(RequestId reqId, result r, const String& errorCode, const String& errorMsg) {};
		void OnUsersInAclReceivedN(RequestId reqId, Collection::IList* pUserIdList, result r, const String& errorCode, const String& errorMsg) {};

	private:
		PrivacyManager __privacyManager;
	};

	result
	PrivacyManagerSample::OpenMyCustomProfile(void)
	{
		result r = E_SUCCESS;
		RequestId reqId;

		r = privacyManager.Construct(*this);
		if (IsFailed(r))
			return r;

		// Request to update the profile exposure level of the user's custom profile.
		// This is the asynchronous operation. When it is completed, OnProfileExposureLevelUpdated() is called.
		r = privacyManager.SetCustomProfileExposureLevel(PROFILE_SEARCHABLE, reqId);
		if (IsFailed(r))
			return r;

		return E_SUCCESS;
	}

	void
	PrivacyManagerSample::OnProfileExposureLevelUpdated(RequestId reqId, result r, const String& errorCode, const String& errorMsg)
	{
		if (IsFailed(r))
			AppLogException("Fail to set Profile Exposure Level (%s, %S)", GetErrorMessage(r), errorMsg.GetPointer());
		else
			AppLog("Success to set Profile Exposure Level");
	}

* @endcode
* @endif
*/

class  _EXPORT_SOCIAL_ PrivacyManager:
	public Osp::Base::Object
{
	// Construct Operations
public:
	/**
	* This is the default constructor for this class. @n
	* This constructor creates an uninitialized instance of %PrivacyManager.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance. @n
	*				Before using the methods of this class, the user must be registered and signed into the bada Server.
	* @see			Construct()
	*/	
	PrivacyManager(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	virtual ~PrivacyManager(void);

	/**
	* Initializes this instance of %PrivacyManager with the specified listener.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	listener			The event listener
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.	
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @if PRIVCORE
	* @remarks		Note that this method allows only INFO_TYPE_CUSTOM_PROFILE and INFO_TYPE_LOCATION types. @n
	* 				To make use of all the user info types for privacy management, invoke the UseAllUserInfoTypes() method that is provided in bada API 
	*				version 2.0 and above.
	* @endif
	*/
	result Construct(const IPrivacyManagerListener& listener);

private:
	//No implementation. force to private
	PrivacyManager(const PrivacyManager& value);
	PrivacyManager& operator =(const PrivacyManager& value);

	//Operations
public:
	/**
	* Sets the exposure level of the profile of the user. @n
	* The user can determine whether all the profiles are viewable by other users. @n
	* If the exposure level is 'PROFILE_CLOSED', the other users can neither view nor search this profile. @n
	* If the exposure level is 'PROFILE_VIEWABLE', the other users can view this profile, but they cannot search for this user. @n
	* If the exposure level is 'PROFILE_SEARCHABLE', the other users can view this profile and search for this user. @n
	* Furthermore, if the exposure level is set to either 'PROFILE_VIEWABLE' or 'PROFILE_SEARCHABLE', the BasicProfile of the user is open to all other users. @n
	* The rest of the privacies of the profiles are determined by their respective privacy policies. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnProfileExposureLevelUpdated() method is called.
	*
	* @deprecated	This method is deprecated and is not supported any longer because it is not allowed to access the privacy policy of the user arbitrarily.
	*				@if PRIVCORE To set the exposure level of the profiles of the user, use SetProfilesExposureLevel() instead of this method. @endif
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	PRIVACY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	exposureLevel			The exposure level of the profile to be set
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c exposureLevel is invalid.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION	This operation is not supported @b since: @b 2.0.
	* @see Construct(), IPrivacyManagerListener::OnProfileExposureLevelUpdated()
	*/
	result SetProfileExposureLevel(ProfileExposureLevel exposureLevel, RequestId& reqId);

	/**
	* Gets the exposure level of the profile of the user. @n
	* This method sends the request to the server and receives the response asynchronously.
	* When the request is completed, the IPrivacyManagerListener::OnProfileExposureLevelReceived() method is called.
	*
	* @deprecated	This method is deprecated and is not supported any longer because it is not allowed to access the privacy policy of the user arbitrarily.
	*				@if PRIVCORE To get the exposure level of the user's profiles, use GetProfilesExposureLevel() instead of this method. @endif
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	PRIVACY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION	This operation is not supported @b since: @b 2.0.
	* @see Construct(), IPrivacyManagerListener::OnProfileExposureLevelReceived()
	*/
	result GetProfileExposureLevel(RequestId& reqId);

    /**
    * Sets the privacy policy (access level) of the specific user information. @n
    * The privacy policy controls who can view the specific user information. @n
    * This method sends the request to the server and receives the response asynchronously. @n
    * When the request is completed, IPrivacyManagerListener::OnUserInfoPrivacyUpdated() is called.
    *
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
    * @since			1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
    * @privlevel		NORMAL
    * @privgroup		PRIVACY_SERVICE
    *
    * @pre				The user should be authenticated. @n
    *					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
    *
    * @return		An error code
    * @param[in]	userInfoType			The user information to which the privacy policy is applied
    * @param[in]	accessLevel				The access level to be set
    * @param[out]	reqId					The ID of the request sent to the server
    * @exception 	E_SUCCESS				The method is successful.
    * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c userInfoType is invalid, or the specified @c accessLevel is invalid.
    * @exception	E_USER_NOT_REGISTERED	The user is not registered.
    * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
    * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
    * @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, the access level is applied to the custom profile of the calling application.
    * @see Construct(), IPrivacyManagerListener::OnUserInfoPrivacyUpdated()
    */
	result SetUserInfoPrivacy(UserInfoType userInfoType, AccessLevel accessLevel, RequestId& reqId);

	/**
	* Gets the privacy policy (access level) of the specific user information. @n
	* This method sends the request to the server and receives the response asynchronously.
	* When the request is completed, IPrivacyManagerListener::OnUserInfoPrivacyReceived() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
	* @privlevel		NORMAL
	* @privgroup		PRIVACY_SERVICE
	*
	* @pre				The user should be authenticated. @n
	*					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	userInfoType			The type of user information
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception 	E_SUCCESS				The method is successful.
	* @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception 	E_INVALID_ARG			The specified @c userInfoType is invalid.
	* @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception 	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
	* @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, the access level detail of the custom profile of the calling application is obtained.
	* @see 	Construct(),  IPrivacyManagerListener::OnUserInfoPrivacyReceived()
	*/
	result GetUserInfoPrivacy(UserInfoType userInfoType, RequestId& reqId);

	/**
	* Gets the privacy policy (access level) of all the user information components. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnAllUserInfoPrivacyReceived() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	PRIVACY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_USER_NOT_REGISTERED  	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		In case of a custom profile, the access level detail of the custom profile of the calling application is obtained.
	* @see	Construct(),  IPrivacyManagerListener::OnAllUserInfoPrivacyReceived()
	*/
	result GetAllUserInfoPrivacy(RequestId& reqId);

	/**
	* Adds users to the Access Control List (ACL) as per the specified user information. @n
	* The ACL contains the users who are permitted to access the specific user information. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, IPrivacyManagerListener::OnUsersAddedToAcl() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
	* @privlevel		NORMAL
	* @privgroup		PRIVACY_SERVICE
	*
	* @pre				The user should be authenticated. @n
	*					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	userInfoType			The type of user information
	* @param[in]	userIdList				The list of user IDs added to the ACL
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception 	E_SUCCESS				The method is successful.
	* @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception 	E_INVALID_ARG			The specified @c userInfoType is invalid, or the specified @c userIdList is empty.
	* @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception 	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
	* @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, the users are added to the ACL of the custom profile of the calling application.
	* @see Construct(),  IPrivacyManagerListener::OnUsersAddedToAcl()
	*/
	result AddUsersToAcl(UserInfoType userInfoType, const Osp::Base::Collection::IList& userIdList, RequestId& reqId);

	/**
	* @page	CompPrivacyManagerAPIsUsingUserInfoTypePage	Compatibility for AddUsersToAcl(), GetAllUsersInAcl(), GetUserInfoPrivacy(), RemoveAllUsersFromAcl(), RemoveUsersFromAcl(), and SetUserInfoPrivacy()
	* @section	CompPrivacyManagerAPIsUsingUserInfoTypePageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# In some cases, the applications arbitrarily access the privacy policy of the user.
	*
	* @section	CompPrivacyManagerAPIsUsingUserInfoTypePageSolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	* @if PRIVCORE Since bada API version 2.0, E_UNSUPPORTED_TYPE occurs if @c UseAllUserInfoTypes() has not been invoked and the @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION. @n
	* @else Since bada API version 2.0, E_UNSUPPORTED_TYPE occurs if the @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION. @n
	* @endif
	*/

	/**
	* Removes users from the ACL as per the specified user information. @n
	* This method sends the request to the server and receives the response asynchronously.
	* When the request is completed, the IPrivacyManagerListener::OnUsersRemovedFromAcl() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
	* @privlevel		NORMAL
	* @privgroup		PRIVACY_SERVICE
	*
	* @pre				The user should be authenticated. @n
	*					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	userInfoType			The type of user information
	* @param[in]	userIdList				The list of user IDs removed from the ACL
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception 	E_SUCCESS				The method is successful.
	* @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception 	E_INVALID_ARG			The specified @c userInfoType is invalid, or the specified @c userIdList is empty.
	* @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception 	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
	* @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, the users are removed from the ACL of the custom profile of the calling application.
	* @see Construct(),  IPrivacyManagerListener::OnUsersRemovedFromAcl()
	*/
	result RemoveUsersFromAcl(UserInfoType userInfoType, const Osp::Base::Collection::IList& userIdList, RequestId& reqId);

	/**
	* Gets all the users in the ACL as per the specified user information. @n
	* The ACL contains users who are permitted to access the specific user information. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnUsersInAclReceivedN() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
	* @privlevel		NORMAL
	* @privgroup		PRIVACY_SERVICE
	*
	* @pre				The user should be authenticated. @n
	*					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	userInfoType			The type of user information 
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception 	E_INVALID_ARG			The specified @c userInfoType is invalid.
	* @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception 	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
	* @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, all the users in the ACL of the custom profile of the calling application are obtained.
	* @see Construct(),  IPrivacyManagerListener::OnUsersInAclReceivedN()
	*/
	result GetAllUsersInAcl(UserInfoType userInfoType, RequestId& reqId);

	/**
	* Removes all the users from the ACL as per the specified user information. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnUsersRemovedFromAcl() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompPrivacyManagerAPIsUsingUserInfoTypePage "here".
	* @privlevel		NORMAL
	* @privgroup		PRIVACY_SERVICE
	*
	* @pre				The user should be authenticated. @n
	*					For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	userInfoType			The type of user information
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c userInfoType is invalid.
	* @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
    * @exception 	E_UNSUPPORTED_TYPE		@if PRIVCORE The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION, when 
	*										UseAllUserInfoTypes() has not been invoked.
	*										@else
	*										The specified @c userInfoType is neither INFO_CUSTOM_PROFILE nor INFO_LOCATION.
	*										@endif
	* @remarks	If @c userInfoType is set to INFO_CUSTOM_PROFILE, all the users are removed from the ACL of the custom profile of the calling application.
	* @see Construct(),  IPrivacyManagerListener::OnUsersRemovedFromAcl()
	*/
	result RemoveAllUsersFromAcl(UserInfoType userInfoType, RequestId& reqId);

	/**
	* Sets the exposure level of the custom profile of the user defined by the current application. @n
	* The user can determine whether the custom profile is viewable by other users. @n
	* If the exposure level is 'PROFILE_CLOSED', the other users can neither view nor search this profile. @n
	* If the exposure level is 'PROFILE_VIEWABLE', the other users can view this profile, but they cannot search for this user. @n
	* If the exposure level is 'PROFILE_SEARCHABLE', the other users can view this profile and search for this user. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnProfileExposureLevelUpdated() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	PRIVACY_SERVICE
	*
	* @pre			The user should be authenticated. @n
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	exposureLevel			The exposure level of the profile to be set
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c exposureLevel is invalid.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IPrivacyManagerListener::OnProfileExposureLevelUpdated()
	*/
	result SetCustomProfileExposureLevel(ProfileExposureLevel exposureLevel, RequestId& reqId);

	/**
	* Gets the exposure level of the custom profile of the user defined by the current application. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnProfileExposureLevelReceived() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	PRIVACY_SERVICE
	*
	* @pre			The user should be authenticated. @n
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IPrivacyManagerListener::OnProfileExposureLevelReceived()
	*/
	result GetCustomProfileExposureLevel(RequestId& reqId);

	/**
	* @if PRIVCORE
	* Sets the exposure level of the profiles of the user. @n
	* The user can determine whether all the profiles are viewable by other users. @n
	* If the exposure level is 'PROFILE_CLOSED', the other users can neither view nor search this profile. @n
	* If the exposure level is 'PROFILE_VIEWABLE', the other users can view this profile, but they cannot search for this user. @n
	* If the exposure level is 'PROFILE_SEARCHABLE', the other users can view this profile and search for this user. @n
	* Furthermore, if the exposure level is set to either 'PROFILE_VIEWABLE' or 'PROFILE_SEARCHABLE', the basic profile of the user is open to all the other users. @n
	* The privacies of the remaining profiles are determined by their respective privacy policies. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, the IPrivacyManagerListener::OnProfileExposureLevelUpdated() method is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	SOCIAL_SERVICE
	*
	* @pre			The user should be authenticated. @n
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	exposureLevel			The exposure level of the profiles to be set
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c exposureLevel is invalid.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see Construct(), IPrivacyManagerListener::OnProfileExposureLevelUpdated()
	* @endif
	*/
	result SetProfilesExposureLevel(ProfileExposureLevel exposureLevel, RequestId& reqId);

	/**
	* @if PRIVCORE
	* Gets the exposure level of the profiles of the user. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, IPrivacyManagerListener::OnProfileExposureLevelReceived() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	SOCIAL_SERVICE
	*
	* @pre			The user should be authenticated. @n
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	reqId					The ID of the request sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see Construct(), IPrivacyManagerListener::OnProfileExposureLevelReceived()
	* @endif
	*/
	result GetProfilesExposureLevel(RequestId& reqId);

    /**
    * @if PRIVCORE
    * Uses all the user information types defined in UserInfoType.
    *
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
    * @since		2.0
    * @privlevel	CORE
    * @privgroup	SOCIAL_SERVICE
	*
	* @return		An error code
    * @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
    * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
    * @endif
    */
    result UseAllUserInfoTypes(void);

private:
	IPrivacyManager* __pIPrivacyManager;
	void* __pMListener;

	friend class PrivacyManagerEx;
	class PrivacyManagerEx* __pPrivacyManagerEx;
}; // class PrivacyManager

};};};// Osp::Social::Services

#endif// _FSCL_SVC_PRIVACY_MANAGER_H_
