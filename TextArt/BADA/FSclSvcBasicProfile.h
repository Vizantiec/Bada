/* $Change: 1145133 $ */
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
* @file		FSclSvcBasicProfile.h
* @brief	This is the header file for the %BasicProfile class.
*
* This header file contains the declarations of the %BasicProfile class.
*/
#ifndef _FSCL_SVC_BASIC_PROFILE_H_
#define _FSCL_SVC_BASIC_PROFILE_H_

// Includes
#include "FBaseString.h"
#include "FBaseTypes.h"
#include "FBaseResult.h"
#include "FSclSvcProfile.h"

namespace Osp { namespace Social { namespace Services {
	// To create friendship.
	class __ProfileUtil;

/**
* Defines the IDs for accessing the properties of %BasicProfile.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
enum BasicProfilePropertyId {
	BP_PID_USER_NAME,				/**< The user name property ID */
	BP_PID_DISPLAY_NAME,			/**< The display name property ID */
	BP_PID_FIRST_NAME,				/**< The first name property ID */
	BP_PID_LAST_NAME,				/**< The last name property ID */
	BP_PID_ADDITIONAL_NAME,			/**< The additional name property ID */
	BP_PID_NAME_PREFIX,				/**< The name prefix property ID */
	BP_PID_NAME_SUFFIX,				/**< The name suffix property ID */
	BP_PID_PHOTO,					/**< The photo property ID */
	BP_PID_GENDER,					/**< The gender property ID */
	BP_PID_COUNTRY					/**< The country property ID */	
};

/** The count of the properties of BasicProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int	BASIC_PROFILE_PROPERTY_COUNT	=	10;

/** The maximum length of the photo property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_PROFILE_PHOTO_LENGTH				= 550;
/** The maximum length of the country property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_PROFILE_COUNTRY_LENGTH				= 3;

/** The property for the gender - male. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const Osp::Base::String PROFILE_GENDER_MALE	= L"M";
/** The property for the gender - female.
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const Osp::Base::String PROFILE_GENDER_FEMALE	= L"F";



/**
* @class	BasicProfile
* @brief	This class provides methods to access the basic profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %BasicProfile provides methods to access the basic profile of a user.
* The basic profile is not constructed. It is obtained from the server using the ProfileService::GetMyProfile() or
* ProfileService::GetProfile() methods. The profile has a valid user ID.
* 
*/
class  _EXPORT_SOCIAL_ BasicProfile:
	public Osp::Social::Services::Profile
{
	// Friend class
	friend class __ProfileUtil;

	// Construct operations
protected:
	/**
	* Initializes this instance of %BasicProfile with the specified @c userId.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	userId			The user ID
	*/
	BasicProfile(const UserId& userId);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	BasicProfile(void);

	/**
	* This is the copy constructor for the %BasicProfile class. @n
	* It constructs an instance of %BasicProfile with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value			An instance of %BasicProfile
	*/
	BasicProfile(const BasicProfile& value);

	/**
	* This assignment operator copies the values of the specified instance of %BasicProfile to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		A reference to the current instance
	* @param[in]	value	A reference to the source instance to copy from
	*/
	BasicProfile&	operator =(const BasicProfile& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~BasicProfile(void);

	// Operations
public:
	/*
	* Returns the user name.
	*
	* @return		The user name
	*/
//	Osp::Base::String GetUserName(void) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The value of the specified property, @n
	*				else an empty string if the specified property has no value
	* @param[in]	id		The ID of the property
	*
	* @code
	* using namespace Osp::Base;
	* using namespace Osp::Social::Services;
	*
	* void
	* MyClass::SomeMethod(BasicProfile& basicProfile)
	* {
	*	// Gets the first name.
	*	String fistName = basicProfile.GetValue(BP_PID_FIRST_NAME);
	*	// Gets the last name.
	*	String lastName = basicProfile.GetValue(BP_PID_LAST_NAME);
	* }
	* @endcode
	*/
	Osp::Base::String GetValue(BasicProfilePropertyId id) const;

	/**
	* Sets the value of the specified ID with the specified value. @n
	* BP_PID_COUNTRY: The CountryCode represents ISO 3166-1 alpha-3 country code strings. @n
	* BP_PID_GENDER : must use the Services::PROFILE_GENDER_FEMALE const string or Services::PROFILE_GENDER_MALE const string.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	id				The ID of the property
	* @param[in]	value			The new value to be set
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	Either of the following conditions has occurred: @n
	*								- The value of the property with the specified @c id is an empty string. @n
	*								- The length of the value exceeds the maximum allowable length for the property. Check #MAX_PROFILE_NAME_LENGTH, 
	*								   #MAX_PROFILE_USER_NAME_LENGTH, #MAX_PROFILE_DISPLAY_NAME_LENGTH, #MAX_PROFILE_PHOTO_LENGTH, and 
	*								   #MAX_PROFILE_COUNTRY_LENGTH. @n
	*								- The value of the #BP_PID_GENDER property is not #PROFILE_GENDER_MALE or #PROFILE_GENDER_FEMALE.
	* @see		Osp::Locales::Locale::CountryCodeToThreeLetterCountryCodeString
	*
	* @code
	* using namespace Osp::Base;
	* using namespace Osp::Social::Services;
	* using namespace Osp::Locales;
	*
	* void
	* MyClass::SomeMethod(BasicProfile& basicProfile)
	* {
	*
	*	// Sets the country: use an ISO 3166-1 alpha-3 country code string.
	*	basicProfile.SetValue(BP_PID_COUNTRY, Locale::CountryCodeToThreeLetterCountryCodeString(COUNTRY_KR));
	*
	*	// Sets the gender.
	*	String gender = PROFILE_GENDER_MALE;
	*	basicProfile.SetValue(BP_PID_GENDER, gender);
	*
	* }
	* @endcode
	*/
	result SetValue(BasicProfilePropertyId id, const Osp::Base::String& value);

	/**
	* Removes the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	id				The ID of the property
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	The specified property ID is #BP_PID_FIRST_NAME or #BP_PID_LAST_NAME, or @n
	*								the values of the first name property and the last name property cannot be removed.
	*
	* @code
	* using namespace Osp::Base;
	* using namespace Osp::Social::Services;
	*
	* void
	* MyClass::SomeMethod(BasicProfile& basicProfile)
	* {
	*	// Removes the value of the country property.
	*	basicProfile.RemoveValue(BP_PID_COUNTRY);
	*
	* }
	* @endcode
	*/
	result RemoveValue(BasicProfilePropertyId id);
private:
	bool IsUpdatedProperty(BasicProfilePropertyId id) const;
	result SetValueString(BasicProfilePropertyId id, const Osp::Base::String& value);

private:
	Osp::Base::String	__properties[BASIC_PROFILE_PROPERTY_COUNT];	/* properties which consists of this record. */
	bool __dirtyBits[BASIC_PROFILE_PROPERTY_COUNT];

private:
	friend class BasicProfileEx;
	class BasicProfileEx* __pBasicProfileEx;

}; // BasicProfile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_BASIC_PROFILE_H_
