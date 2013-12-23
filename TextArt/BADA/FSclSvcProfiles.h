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
* @file		FSclSvcProfiles.h
* @brief	This is the header file for the %Profiles class.
*
* This header file contains the declarations of the %Profiles class.
*/
#ifndef _FSCL_SVC_PROFILES_H_
#define _FSCL_SVC_PROFILES_H_

#include "FBaseTypes.h" // for using UserId
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FSclConfig.h"
#include "FSclSvcProfileTypes.h"
#include "FSclSvcProfile.h"
#include "FSclSvcBasicProfile.h"
#include "FSclSvcPersonalProfile.h"
#include "FSclSvcContactProfile.h"
#include "FSclSvcSocialProfile.h"
#include "FSclSvcCustomProfile.h"


namespace Osp { namespace Social { namespace Services {

/**
* @class	Profiles 
* @brief	This class represents the profiles, that include BasicProfile, PersonalProfile, ContactProfile, SocialProfile, and CustomProfile.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* 	The %Profiles class represents the profiles, that include BasicProfile, PersonalProfile, ContactProfile, SocialProfile, and CustomProfile.
*
*/
class  _EXPORT_SOCIAL_ Profiles:
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
	Profiles(void);

	// Lifecycle
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * This is the copy constructor for the %Profiles class. @n 
	 * It creates an instance of %Profiles with the values of the specified instance.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		1.0
	 * @param[in]	profiles 	The specified instance of %Profiles
	 * @remarks		This constructor is hidden.
	 */
	Profiles(const Profiles& profiles);

// Operator
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * This is the assignment operator.
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 * @param[in]	profiles The other instance of Profiles
	 * @remarks		This operator is hidden.
	 */
	Profiles& operator =(const Profiles& profiles);


public:

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	virtual ~Profiles(void);

	// Operations
public:
	/**
	* Gets the pointer to the specified profile type.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The pointer to the specified @c profileType
	* @param[in]	profileType				The profile type to get
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OBJ_NOT_FOUND			The specified @c profileType does not exist.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	const Profile* GetProfile(ProfileType profileType) const;

protected:
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * The basic profile
	 *
	 * @deprecated	This member variable is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 */
	BasicProfile*		__pBasicProfile;
	
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * The personal profile
	 *
	 * @deprecated	This member variable is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 */
	PersonalProfile*	__pPersonalProfile;
	
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * The contact profile
	 *
	 * @deprecated	This member variable is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 */
	ContactProfile*		__pContactProfile;
	
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * The social profile
	 *
	 * @deprecated	This member variable is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 */
	SocialProfile*		__pSocialProfile;
	
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * The custom profile
	 *
	 * @deprecated	This member variable is deprecated due to the operation policy of the bada Server.
	 * @since			1.0
	 */
	CustomProfile*		__pCustomProfile;
	
friend class __ProfileUtil;

private:
	friend class ProfilesEx;
	class ProfilesEx* __pProfilesEx;


}; // Profiles

};};};// Osp::Social::Services

#endif// _FSCL_SVC_PROFILE_H_
