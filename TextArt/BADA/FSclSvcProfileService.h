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
 * @file	FSclSvcProfileService.h
 * @brief	This is the header file for the %ProfileService class.
 *
 * This header file contains the declarations of the %ProfileService class.
 */
#ifndef _FSCL_SVC_PROFILE_SERVICE_H_
#define _FSCL_SVC_PROFILE_SERVICE_H_

// Includes
#include "FBaseTypes.h" // for using UserId and RequestId
#include "FSclSvcTypes.h"
#include "FSclSvcBasicProfile.h"
#include "FSclSvcPersonalProfile.h"
#include "FSclSvcContactProfile.h"
#include "FSclSvcSocialProfile.h"
#include "FSclSvcCustomProfile.h"
#include "FSclSvcIProfileServiceListener.h"
#include "FSclSvcCustomProfileFilter.h"

struct IProfileService;

namespace Osp { namespace Social { namespace Services {


/** The minimum length of the email address which is used by the query. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MIN_PROFILE_EMAIL_QUERY_LENGTH = 3;

/** The minimum length of the phone number which is used by the query.
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MIN_PROFILE_PHONE_NUMBER_QUERY_LENGTH = 3;

/** The minimum length of the login ID which is used by the query. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MIN_PROFILE_LOGINID_QUERY_LENGTH = 3;

/**
 * @class	ProfileService
 * @brief	This class provides a way to access profiles on the server side.
 * @deprecated	This class is deprecated due to the operation policy of the bada Server.
 * @since	1.0
 *
 * 	The %ProfileService class provides a way to access profiles on the server side. All the member methods defined in this class operate asynchronously. To receive 
 *			the result of a member method, a listener class that implements the IProfileServiceListener() method must be specified.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Social namespace.
 * @image html social_profileservice_using_the_apis_classdiagram.png
 *
 * The following example demonstrates how to use the %ProfileService class.
 * @code
using namespace Osp::Base;
using namespace Osp::Social::Services;

// MyProfileServiceListener class. This listener receives the responses to requests by ProfileService.
class MyProfileServiceListener : public IProfileServiceListener
{
	//...
	//...
};

result
GetMyProfile(void)
{
	result r = E_SUCCESS;
	RequestId reqId;

	//The listener instance must be preserved until the instance of ProfileService is terminated.
	MyProfileServiceListener* pProfileServiceListener = new MyProfileServiceListener();

	// Creates an instance of ProfileService.
	ProfileService* pProfileService = new ProfileService();
	pProfileService->Construct(pProfileServiceListener);

	// Request to get my profile by calling the asynchronous method.
	// The instance of asynchronous listener object must be preserved until the response of the asynchronous operation is received.
	r = pProfileService->GetMyProfile(PROFILE_TYPE_BASIC | PROFILE_TYPE_CONTACT, reqId);
	if (IsFailed(r)) { // E_USER_NOT_REGISTERED : If the user is not registered.
		delete pProfileService;
		delete pProfileServiceListener;
		return r;
	}

	// On the completion of the asynchronous operation,
	// the result is delivered to MyProfileServiceListener::OnMyProfileReceived(...);
	// Wait until it completes.
	//...
	//...

	delete pProfileService;
	delete pProfileServiceListener;

	return E_SUCCESS;
}
 * @endcode
 *
 */
class  _EXPORT_SOCIAL_ ProfileService:
	public Osp::Base::Object
{

// Construct Operations
public:
	/**
	 * This is the default constructor for this class.	@n
	 * This method creates an uninitialized instance of ProfileService.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	ProfileService(void);
	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~ProfileService(void);

	/**
	* Initializes this instance of %ProfileService with the specified listener.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	listener			The event listener
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	*/
	result Construct(const IProfileServiceListener& listener);

	// Static Operation
public:

	/**
	* Gets the authenticated device owner.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	PROFILE_SERVICE
	*
	* @pre			The user should be authenticated. @n 
	*				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	userId					The authenticated device owner, @n
	*										else an empty user ID if the device owner is not registered
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	*/
	static result GetMyUserId(UserId& userId);


private:
	//no implementation. force to private
	ProfileService(const ProfileService& value);
	ProfileService& operator =(const ProfileService& value);

// Operations
public:
	/**
	 * Gets the profile of the logged-in user. @n
	 * This method is asynchronous. @n
	 * When the requested profile has been received from the server, the IProfileServiceListener::OnMyProfileReceived() method is called.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 * @pre			If you use the custom profile, <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	 *				Component Setup</a> should be done.
	 *
	 * @return		An error code
	 * @param[in]	requestProfileType		The profile type to be requested @n
	 *										The result of this method contains the profiles of the requested type. @n
	 *										To get the basic profile, use #PROFILE_TYPE_BASIC. @n
	 *										To get the basic profile, personal profile, and the contact profile, 
	 *										use (#PROFILE_TYPE_BASIC | #PROFILE_TYPE_PERSONAL | #PROFILE_TYPE_CONTACT).
	 * @param[out]	reqId					The ID of the request
  	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_USER_NOT_REGISTERED	The user is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see			Construct(), IProfileServiceListener::OnMyProfileReceived()
	 */
	 result GetMyProfile(unsigned long requestProfileType, RequestId& reqId);

	 /**
	 * Gets the profile corresponding to the specified user ID. @n
	 * This method is asynchronous. @n
	 * When the requested profile has been received from the server, the IProfileServiceListener::OnProfileReceived() method is called.
	 *
	 * If the specified @c userId contains whitespace, this method uses the trimmed result.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 * @pre			If you use the custom profile, <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	 *				Component Setup</a> should be done.
	 *
	 * @return		An error code
	 * @param[in]	userId				The user ID
	 * @param[in]	requestProfileType	The profile type to be requested @n
	 *									The result of this method contains the profiles of requested type. @n
	 *									To get the basic profile, use #PROFILE_TYPE_BASIC. @n
	 *									To get the basic profile, personal profile, and the contact profile, 
	 *									use (#PROFILE_TYPE_BASIC | #PROFILE_TYPE_PERSONAL | #PROFILE_TYPE_CONTACT).
	 * @param[out]	reqId				The ID of the request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The @c userID parameter is an empty string, or @n
	 *									the profile type is not supported.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			Construct(), IProfileServiceListener::OnProfileReceived()
	 */
	 result GetProfile(const UserId& userId, unsigned long requestProfileType, RequestId& reqId);

	/**
	 * Gets the profiles which are specified by the list of the user IDs. @n
	 * It is possible to search the information of a maximum of 10 user IDs. @n
	 * This method is asynchronous. @n
	 * When the requested profile has been received from the server, the IProfileServiceListener::OnProfilesReceivedN() method is called.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *	
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 * @pre			If you use the custom profile, <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	 *				Component Setup</a> should be done.
	 *
	 * @return		An error code
	 * @param[in]	userIdList			The list of user IDs
	 * @param[in]	requestProfileType	The profile type to be requested @n
	 *									The result of this method contains the profiles of the requested type. @n
	 *									To get the basic profile, use #PROFILE_TYPE_BASIC. @n
	 *									To get the basic profile, personal profile, and the contact profile, 
	 *									use (#PROFILE_TYPE_BASIC | #PROFILE_TYPE_PERSONAL | #PROFILE_TYPE_CONTACT).
	 * @param[out]	reqId				The ID of the request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									-	The count of the @c userIdList parameter is greater than @c 10. @n
	 *									-	The count of the @c userIdList parameter is less than @c 1. @n	
	 * 									-	The profile type is not supported.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 * @see			Construct(), IProfileServiceListener::OnProfilesReceivedN()
	 */
	 result GetProfiles(const Osp::Base::Collection::IList& userIdList, unsigned long requestProfileType, RequestId& reqId);

	/**
	 * Updates the profile of the logged-in user. @n
	 * The modified properties of the profile are saved on the server side. @n
	 * This method is asynchronous. @n
	 * When the update operation is completed on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called. @n
	 * The application must use the received profile from OnMyProfileUpdated() after updating the profile.
	 *
	 * @deprecated	This method is deprecated and is not supported any longer because it is not allowed to update the user profile arbitrarily.
	 *				@if PRIVCORE To update the profiles of the logged-in user, use UpdateMyProfiles() instead of this method. @endif
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	basicProfile				The BasicProfile of the logged-in user
	 * @param[out]	reqId						The ID of the request
	 * @exception 	E_SUCCESS					The method is successful.
	 * @exception 	E_INVALID_ARG				The input profile does not belong to a registered user.
	 * @exception 	E_INVALID_STATE				This instance has not been constructed as yet.
	 * @exception 	E_USER_NOT_REGISTERED		The user is not registered.
	 * @exception 	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @exception 	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception 	E_UNSUPPORTED_OPERATION		This operation is not supported @b since: @b 2.0
	 * @see			Construct(), IProfileServiceListener::OnMyProfileUpdated()
	 */
	 result UpdateMyProfile(const BasicProfile& basicProfile, RequestId& reqId);

	/**
	 * Updates the profile of the logged-in user. @n
	 * The modified properties of the profile are saved on the server side. @n
	 * This method is asynchronous. @n
	 * When the update operation is completed on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called. @n
	 * The application must use the received profile from OnMyProfileUpdated() after updating the profile.
	 *
	 * @deprecated	This method is deprecated and is not supported any longer because it is not allowed to update the user profile arbitrarily.
	 *				@if PRIVCORE To update the profiles of the logged-in user, use UpdateMyProfiles() instead of this method. @endif
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	personalProfile			The personal profile of the logged-in user
	 * @param[out]	reqId					The ID of the request
	 * @exception 	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_ARG			The input profile does not belong to a registered user.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	 * @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_UNSUPPORTED_OPERATION	This operation is not supported @b since: @b 2.0.
	 * @see			Construct(), IProfileServiceListener::OnMyProfileUpdated()
	 */
	 result UpdateMyProfile(const PersonalProfile& personalProfile, RequestId& reqId);

	/**
	 * Updates the profile of the logged-in user. @n
	 * The modified properties of the profile are saved on the server side. @n
	 * This method is asynchronous. @n
	 * When the update operation is completed on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called.
	 * The application must use the received profile from OnMyProfileUpdated() after updating the profile.
	 *
	 * @deprecated	This method is deprecated and is not supported any longer because it is not allowed to update the user profile arbitrarily.
	 *				@if PRIVCORE To update the profiles of the logged-in user, use UpdateMyProfiles() instead of this method. @endif
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	contactProfile			The contact profile of the logged-in user
	 * @param[out]	reqId					The ID of the request
	 * @exception 	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_ARG			The input profile does not belong to a registered user.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	 * @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_UNSUPPORTED_OPERATION	This operation is not supported @b since: @b 2.0.
	 * @see			Construct(), IProfileServiceListener::OnMyProfileUpdated()
	 */
	 result UpdateMyProfile(const ContactProfile& contactProfile, RequestId& reqId);

	/**
	 * Updates the profile of the logged-in user. @n
	 * The modified properties of the profile are saved on the server side. @n
	 * This method is asynchronous. @n
	 * When the update operation is complete on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called. @n
	 * The updated items(EducationInfo, WorkInfo)of socialProfile are sorted by start date. @n
	 * The application must use the received profile from OnMyProfileUpdated() after updating profile.
	 *
	 * @deprecated	This method is deprecated and is not supported any longer because it is not allowed to update the user profile arbitrarily.
	 *				@if PRIVCORE To update the profiles of the logged-in user, use UpdateMyProfiles() instead of this method. @endif
	 *
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	socialProfile			The social profile of the logged-in user
	 * @param[out]	reqId					The ID of the request
	 * @exception 	E_SUCCESS				The method is successful.
	 * @exception 	E_INVALID_ARG			The input profile does not belong to a registered user.
	 * @exception 	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception 	E_USER_NOT_REGISTERED	The user is not registered.
	 * @exception 	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception 	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_UNSUPPORTED_OPERATION	This operation is not supported @b since: @b 2.0
	 * @see			Construct(), IProfileServiceListener::OnMyProfileUpdated()
	 */
	 result UpdateMyProfile(const SocialProfile& socialProfile, RequestId& reqId);

	 /**
	 * Updates the profile of the logged-in user. @n
	 * The modified properties of the profile are saved on the server side. @n
	 * This method is asynchronous. @n
	 * When the update operation is complete on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called.
	 * The application must use the received profile from OnMyProfileUpdated() after updating the profile.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 * @pre 		<a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
	 *             Component Setup</a> should be done.
	 *
	 * @return		An error code
	 * @param[in]	customProfile			The custom profile of the logged-in user
	 * @param[out]	reqId					The ID of the request
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The input profile does not belong to a registered user.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_USER_NOT_REGISTERED	The user is not registered.
	 * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @see	Construct(), IProfileServiceListener::OnMyProfileUpdated()
	 */
	 result UpdateMyProfile(const CustomProfile& customProfile, RequestId& reqId);

	 /**
	 * Searches the profiles which have the specified string as the name of the person. The name includes the first name and last name of the person. @n
	 * The @c firstName and the @c lastName parameters are matched with the names in the profiles. The search is not case sensitive. @n
	 * This method returns profiles whose names match "parameterData%". For example, if you search for "Tom", the result may return "Tom", "Tomas", or 
	 * "Tomson". @n
	 * If the parameter has the reserved characters of the search keyword, it works as the reserved characters. @n
	 * For example, if you search for "T_m", the result may return "Tam", "Tomas", or "Tumas". @n
	 * The @c firstName is mandatory, but the other parameters are optional. @n
	 * This method is asynchronous, and does not return any data. @n
	 * When the search result has been received from the server, the IProfileServiceListener::OnProfileSearchResultsReceivedN() method is called. @n
	 * Related search fields are: @n
	 * - the first name, the last name and the gender of the BasicProfile @n
	 * - the birthday of the PersonalProfile @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	firstName			The first name to be searched
	 * @param[in]	pLastName			The last name to be searched
	 * @param[in]	pYearOfBirth		The year of birth to be searched @n
	 *									Use the 'YYYY' string format.
	 * @param[in]	pGender				The gender to be searched @n
	 *									Use Osp::Social::Services::PROFILE_GENDER_FEMALE, and Osp::Social::Services::PROFILE_GENDER_MALE.
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									-	The specified @c firstName parameter is an empty string. @n
	 *									-	The name has a carriage return. @n
	 *									-	The specified @c pageNo parameter is less than @c 1. @n	
	 * 									-	The specified @c countPerPage parameter is less than @c 1.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see	Construct(), IProfileServiceListener::OnProfileSearchResultsReceivedN()
	 *
	 * @code
		// Request to search the profiles by calling the asynchronous method.
		// The instance of asynchronous listener object must be preserved until the response of the asynchronous operation is received.
		String yearOfBirth(L"1987");
		r = pProfileService->SearchProfilesByName(L"Gil-dong", null, &yearOfBirth, null, reqId, 1, 20);
		if (IsFailed(r)) {
			// Exception handling
		}

		// On the completion of the asynchronous operation,
		// the result will be delivered to IProfileServiceListener::OnProfileSearchResultsReceivedN(...);
		// Wait until it completes.
	* @endcode
	*/
	 result SearchProfilesByName(const Osp::Base::String& firstName, const Osp::Base::String* pLastName,
								const Osp::Base::String* pYearOfBirth, const Osp::Base::String* pGender,
								RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	 * Searches the profiles which have the specified email string as one of the email addresses of the person. @n
	 * The email parameter is matched with the email addresses in the profiles. The search is not case sensitive. @n
	 * This method returns the profiles whose email address match "parameterData%". @n
	 * If the parameter has the reserved characters of the search keyword, it works as the reserved characters. @n
	 * For example, if you search for "T_m", the result may return "Tam", "Tomas", or "Tumas". @n
	 * This method is asynchronous, and does not return any data. @n
	 * When the search result has been received from the server, the IProfileServiceListener::OnProfileSearchResultsReceivedN() method is called. @n
	 * Related search field is: @n
	 * - the email of the ContactProfile.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	email				The email address to be searched
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	 *									-	The specified @c email parameter is an empty string. @n
	 *									-	The specified @c email parameter has a carriage return. @n	
	 * 									-	The length of the specified @c email parameter is less than #MIN_PROFILE_EMAIL_QUERY_LENGTH. @n
	 *									-	The specified @c pageNo parameter is less than @c 1. @n
	 *									-	The specified @c countPerPage parameter is less than @c 1.
	 * @exception	E_INVALID_STATE 	This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see	Construct(), IProfileServiceListener::OnProfileSearchResultsReceivedN()
	 *
	 */
	result SearchProfilesByEmail(const Osp::Base::String& email,
		RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	 * Search profiles which have the specified string as one of the person's phone numbers. @n
	 * The phoneNumber parameter is matched with the phone numbers in the profiles. The search is not case sensitive. @n
	 * This method returns profiles whose phone numbers match "%parameterData". For example, if you search for "4567", the result may return "1234567", "7894567", or "1004567". @n
	 * If the parameter has the reserved characters of the search keyword, it works as the reserved characters. @n
	 * For example, if you search for "45_7", the result may return "1234567", "7894577", or "1004507". @n
	 * This method is asynchronous, and does not return any data. @n
	 * When the search result has been received from the server, the IProfileServiceListener::OnProfileSearchResultsReceivedN() method is called.
	 * Related search field: @n
	 * the phone number of the ContactProfile.  @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	phoneNumber			The phone number to be searched
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									-	The specified @c phoneNumber parameter is an empty string. @n
	 *									-	The specified @c phoneNumber parameter has a carriage return. @n	
	 *									-	The length of the specified @c phoneNumber parameter is less than #MIN_PROFILE_PHONE_NUMBER_QUERY_LENGTH. @n
	 *									-	The specified @c pageNo parameter is less than @c 1. @n
	 *									-	The specified @c countPerPage parameter is less than @c 1.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			Construct(), IProfileServiceListener::OnProfileSearchResultsReceivedN()
	 */
	result SearchProfilesByPhoneNumber(const Osp::Base::String& phoneNumber,
		RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	 * Searches for the profiles which have the specified @c loginId string. (sign-in Id of the bada Server) @n
	 * The @c loginId parameter is matched with the login IDs of the profiles until a perfect match is found. The specified login ID should be in lower case 
	 * only. @n
	 * This method is asynchronous, and does not return any data. @n
	 * When the search result has been received from the server, the IProfileServiceListener::OnProfileSearchResultsReceivedN() method is called.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n 
	 *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	loginId				The LoginId to be searched
	 * @param[out]	reqId				The ID of the request
	 * @param[in]	pageNo				The page number of the result list @n
	 *									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									-	The specified @c loginId parameter is an empty string. @n
	 *									-	The specified @c loginId parameter has a carriage return. @n	
	 *									-	The length of the specified @c loginId parameter is less than #MIN_PROFILE_LOGINID_QUERY_LENGTH. @n
	 *									-	The specified @c pageNo parameter is less than @c 1. @n
	 *									-	The specified @c countPerPage parameter is less than @c 1.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see	Construct(), IProfileServiceListener::OnProfileSearchResultsReceivedN()
	 */
	result SearchProfilesByLoginId(const LoginId& loginId,
		RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	 * Searches the profiles by using the CustomProfileFilter which consists of search conditions and search scope. @n
	 * If the CustomProfileFilter has no condition or does not exist, the sort order should be determined. @n
	 * This method is asynchronous, and does not return any data. @n
	 * When the search result has been received from the server, the IProfileServiceListener::OnProfileSearchResultsReceivedN() method is called.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 * @privlevel	NORMAL
	 * @privgroup	PROFILE_SERVICE
	 *
	 * @pre			The user should be authenticated. @n
	 * 				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	 *
	 * @return		An error code
	 * @param[in]	pFilter				The filter to search custom profiles
	 * @param[in]	sortOrder1			The sort order of @c pSortBy1
	 * @param[in]	pSortBy1			The property name of CustomProfile for first sort order
	 * @param[in]	sortOrder2			The sort order of @c pSortBy2
	 * @param[in]	pSortBy2			The property name of CustomProfile for second sort order
	 * @param[in]	reqId				The ID of the request
	 * @param[in]	pageNo				The page number of the result list @n
	 * 									It starts from @c 1.
	 * @param[in]	countPerPage		The desired maximum count of the result items on the page
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									-	The specified @c pSortBy1 parameter is @c null when the specified @c sortOrder1 parameter is not SORT_ORDER_NONE. @n
	 *									-	The specified @c pSortBy1 parameter is @c null when the specified @c pSortBy2 parameter is not @c null. @n	
	 *									-	The specified @c pSortBy1 parameter is @c null when the specified @c pFilter parameter is @c null or has no condition. @n
	 *									-	The specified @c pSortBy2 parameter is @c null when the specified @c sortOrder2 parameter is not SORT_ORDER_NONE. @n
	 *									-	The specified @c pageNo parameter is less than @c 1. @n		
	 *									-	The specified @c countPerPage parameter is less than @c 1.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see			Construct(), IProfileServiceListener::OnProfileSearchResultsReceivedN()
	 *
	 * @code
		// Example 1.
		// - Condition: hobby = "tour" AND height > 180 AND weight < 80
		// - Scope: PROFILE_SEARCH_SCOPE_BUDDIES
		// - SortOrder: sorted in descending order of "height"
		result SearchProfiles1(void)
		{
			CustomProfileFilter filter;
			filter.SetScope(PROFILE_SEARCH_SCOPE_BUDDIES);

			String value1(L"tour");
			filter.AddCondition(L"hobby", COMPARISON_OP_EQUAL, &value1);

			String value2(L"180");
			filter.SetCondition(L"height", COMPARISON_OP_GREATER_THAN, &value2);

			String value3(L"80");
			filter.SetCondition(L"weight", COMPARISON_OP_LESS_THAN, &value3);

			// Request to search the profiles by calling the asynchronous method.
			// The instance of asynchronous listener object must be preserved until the response of
			// the asynchronous operation is received.
			String sortBy1(L"height");
			r = pProfileService->SearchProfilesByCustomProfileFilter(&filter, SORT_ORDER_DESCENDING, &sortBy1, SORT_ORDER_NONE, null, reqId, 1, 20);
			if (IsFailed(r)) {
				// Exception handling
			}

			// On the completion of the asynchronous operation,
			// the result will be delivered to IProfileServiceListener::OnProfileSearchResultsReceivedN(...);
			// Wait until it completes.
		}

		// Example 2.
		// - MAX/MIN: The user who is tallest among the users whose weight is under 50
		result SearchProfiles2(void)
		{
			CustomProfileFilter filter;

			String value1(L"50");
			filter.SetCondition(L"weight", COMPARISON_OP_LESS_THAN, &value1);

			// Request to search the profiles by calling the asynchronous method.
			// The instance of asynchronous listener object must be preserved until the response of
			// the asynchronous operation is received.
			String sortBy1(L"height");
			r = pProfileService->SearchProfilesByCustomProfileFilter(&filter, SORT_ORDER_DESCENDING, &sortBy1, SORT_ORDER_NONE, null, reqId, 1, 20);
			if (IsFailed(r)) {
				// Exception handling
			}

			// On the completion of the asynchronous operation,
			// the result will be delivered to IProfileServiceListener::OnProfileSearchResultsReceivedN(...);
			// Wait until it completes.
		}

		// Example 3.
		// - Ranking: Top 10 list based on weight
		result SearchProfiles3(void)
		{
			// Request to search the profiles by calling the asynchronous method.
			// The instance of asynchronous listener object must be preserved until the response of
			// the asynchronous operation is received.
			String sortBy1(L"weight");
			r = pProfileService->SearchProfilesByCustomProfileFilter(null, SORT_ORDER_DESCENDING, &sortBy1, SORT_ORDER_NONE, null, reqId, 1, 10);
			if (IsFailed(r)) {
				// Exception handling
			}

			// On the completion of the asynchronous operation,
			// the result will be delivered to IProfileServiceListener::OnProfileSearchResultsReceivedN(...);
			// Wait until it completes.
		}
	 * @endcode
	 */
	result SearchProfilesByCustomProfileFilter(const Osp::Social::Services::CustomProfileFilter* pFilter,
			Osp::Base::SortOrder sortOrder1, const Osp::Base::String* pSortBy1, Osp::Base::SortOrder sortOrder2,
			const Osp::Base::String* pSortBy2, RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	* @if PRIVCORE
	* Updates the profile of the logged-in user. @n
	* The modified properties of the profile are saved on the server side. @n
	* This method is asynchronous. @n
	* When the update operation is completed on the server, the IProfileServiceListener::OnMyProfileUpdated() method is called per each updated profile. @n
	* The application must use the received profile from OnMyProfileUpdated() after updating profile.
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
	* @param[out]	reqId					The ID of the request
	* @param[in]	pBasicProfile			The BasicProfile of the logged-in user
	* @param[in]	pPersonalProfile		The PersonalProfile of the logged-in user
	* @param[in]	pContactProfile			The ContactProfile of the logged-in user
	* @param[in]	pSocialProfile			The SocialProfile of the logged-in user
	* @param[in]	pCustomProfile			The CustomProfile of the logged-in user
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The input profile does not belong to a registered user.
	*										The specified @c pBasicProfile, @c pPersonalProfile, @c pContactProfile, @c pSocialProfile, and @c pCustomProfile parameters are @c null.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_USER_NOT_REGISTERED	The user is not registered.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see			Construct(), IProfileServiceListener::OnMyProfileUpdated()
	* @endif
	*/
	result UpdateMyProfiles(RequestId &reqId, const BasicProfile* pBasicProfile = null,
			const PersonalProfile* pPersonalProfile = null, const ContactProfile* pContactProfile = null,
			const SocialProfile* pSocialProfile = null, const CustomProfile* pCustomProfile = null);

//variables
private:
		IProfileService* __pIProfileService;
		void* __pMResponseListener; //class which implements _IProfileServiceResponseListener on Sc

private:
	bool IsValidProfileType(int profileType);

private:
	friend class ProfileServiceEx;
	class ProfileServiceEx* __pProfileServiceEx;

};

};};};// Osp::Social::Services

#endif// _FSCL_SVC_PROFILE_SERVICE_H_
