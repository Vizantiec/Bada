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
* @file		FSclSvcPersonalProfile.h
* @brief	This is the header file for the %PersonalProfile class.
*
* This header file contains the declarations of the %PersonalProfile class.
*/
#ifndef _FSCL_SVC_PERSONAL_PROFILE_H_
#define _FSCL_SVC_PERSONAL_PROFILE_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseDateTime.h"
#include "FSclSvcProfile.h"
#include "FSclSvcTypes.h"


namespace Osp { namespace Social { namespace Services {
	// To create friendship.
	class __ProfileUtil;
// Enums and Constants

/**
* @enum	PersonalProfilePropertyId
* Defines the IDs for accessing the properties of %PersonalProfile.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
enum PersonalProfilePropertyId {
	PP_PID_BIRTHDAY,			/**< The birthday property ID (value type: Osp::Base::DateTime)*/
	PP_PID_RELATIONSHIP_STATUS,	/**< The relationship status property ID (value type: Osp::Base::String )*/
	PP_PID_WEDDING_ANNIVERSARY,	/**< The wedding anniversary property ID (value type: Osp::Base::DateTime)*/
	PP_PID_JOB_TITLE,			/**< The job title property ID (value type: Osp::Base::String )*/
	PP_PID_JOB_ROLE,			/**< The job role property ID (value type: Osp::Base::String )*/
	PP_PID_COMPANY,				/**< The company property ID (value type: Osp::Base::String )*/
	PP_PID_HOMETOWN,			/**< The hometown property ID (value type: Osp::Base::String )*/
	PP_PID_RELIGION,			/**< The religion property ID (value type: Osp::Base::String )*/
	PP_PID_NOTE,				/**< The note property ID (value type: Osp::Base::String )*/
	PP_PID_LANGUAGE_CODE,		/**< The language code ID (value type: Osp::Base::String )*/
	PP_PID_LOCAL_TIME_ZONE		/**< The local time zone ID(value type: Osp::Base::String )*/
};

/**  The count of the properties of %PersonalProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int	PERSONAL_PROFILE_PROPERTY_COUNT		=	11;

/** The maximum length of the job title property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_JOB_TITLE_LENGTH			= 50;
/** The maximum length of the job role property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_JOB_ROLE_LENGTH			= 50;
/** The maximum length of the company property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_COMPANY_LENGTH				= 50;
/** The maximum length of the hometown property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_HOMETOWN_LENGTH			= 100;
/** The maximum length of the religion property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_RELIGION_LENGTH			= 50;
/** The maximum length of the note property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_NOTE_LENGTH				= 100;
/** The maximum length of the language code property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_LANGUAGE_CODE_LENGTH	= 3;
/** The maximum length of the time zone ID property.
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_PROFILE_LOCAL_TIME_ZONE_LENGTH	= 50;


/** The relationship status: married 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const Osp::Base::String PROFILE_RELATIONSHIP_STATUS_MARRIED = L"1";
/** The relationship status: engaged 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const Osp::Base::String PROFILE_RELATIONSHIP_STATUS_ENGAGED = L"2";
/** The relationship status: in a relationship 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const Osp::Base::String PROFILE_RELATIONSHIP_STATUS_IN_RELATIONSHIP = L"3";
/** The relationship status: single 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const Osp::Base::String PROFILE_RELATIONSHIP_STATUS_SINGLE = L"4";


/**
* @class	PersonalProfile
* @brief	This class represents the personal profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* 	The %PersonalProfile class represents the personal profile of a user. The personal profile contains a birthday, relationship status, wedding anniversary, job title, job role, company, hometown, religion, note, 
*			language code, and local time zone property. The personal profile is not constructed. It is obtained from the server using the 
*			ProfileService::GetMyProfile() or ProfileService::GetProfile() methods. The profile has a valid user ID.
*  
*/
class  _EXPORT_SOCIAL_ PersonalProfile:
	public Osp::Social::Services::Profile
{
	// Friend class
	friend class __ProfileUtil;

	// Construct operations
protected:
	/**
	* Initializes a new %PersonalProfile instance with the given user ID.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	userId			The user ID
	*/
	PersonalProfile(const UserId& userId);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	PersonalProfile(void);


	/**
	* This is the copy constructor for the %PersonalProfile class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value		A %PersonalProfile instance to initialize the calling instance
	*/
	PersonalProfile(const PersonalProfile& value);

	/**
	* Copies the value of the instance on the right-hand side to the instance on the left-hand side of the operator.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The reference to the calling instance
	* @param[in]	value		The instance to be copied
	*/
	PersonalProfile&	operator =(const PersonalProfile& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~PersonalProfile(void);

	// Operations
public:
	/**
	* Gets the value of the specified string property. @n
	* The properties that have a value of the String type are relationship status, job title, job role, company, hometown, religion, note, language code, 
	* and local time zone.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	id					The ID of the property whose value is to be obtained
	* @param[out]	value				The value of the specified property, @n
	*									else an empty string if the specified property has no value
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The property identified by the specified @c id is not of the String type.
	*/
	 result GetValue(PersonalProfilePropertyId id, Osp::Base::String& value) const;

	/**
	* Gets the value of the specified DateTime property. @n
	* The properties that have a value of the DateTime type are birthday and wedding anniversary. @n
	* If the DateTime value is not set for the specified property, the property has the minimum value of the DateTime, @n
	* which can be retrieved by DateTime::GetMinValue(). (i.e "January 1 1 00:00:00")
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	id				The ID of the property
	* @param[out]	value			The value of the specified property
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The property identified by the specified @c id is not of the DateTime type.
	*/
	result GetValue(PersonalProfilePropertyId id, Osp::Base::DateTime& value) const;

	/**
	* Replaces the value of the specified ID with the specified string value. @n
	* The properties that have a value of the String type are relationship status, job title, job role, company, hometown, religion, note, language code, 
	* and local time zone. @n
	* Use this method only if the property ID is @c PP_PID_RELATIONSHIP_STATUS, @c PP_PID_JOB_TITLE, @c PP_PID_JOB_ROLE, @c PP_PID_COMPANY, 
	* @c PP_PID_HOMETOWN, @c PP_PID_RELIGION, @c PP_PID_NOTE, @c PP_PID_LANGUAGE_CODE or @c PP_PID_LOCAL_TIME_ZONE. @n
	* @c PP_PID_LANGUAGE_CODE: The LanguageCode represents ISO 639-2 language code strings. @n
	* @c PP_PID_LOCAL_TIME_ZONE: See the Locales::LocaleManager class for the local time zone ID. @n
	* The language code with uppercase is converted into lowercase.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	id				The ID of the property
	* @param[in]	value			The new value to be set
	* @exception	E_SUCCESS		The method is successful.	
	* @exception	E_INVALID_ARG	Either of the following conditions has occurred: @n
	*								- The value of the specified property is an empty string. @n
	* 								- The time zone ID is invalid. @n
	*								- The length of value exceeds the maximum allowable length for the property. @n
	*								- Check the constants ( @n 
	*									#MAX_PROFILE_JOB_ROLE_LENGTH, @n
	*									#MAX_PROFILE_JOB_TITLE_LENGTH, @n
	*									#MAX_PROFILE_COMPANY_LENGTH, @n
	*									#MAX_PROFILE_HOMETOWN_LENGTH, @n 
	*									#MAX_PROFILE_RELIGION_LENGTH, @n
	*									#MAX_PROFILE_NOTE_LENGTH, @n
	*									and #MAX_PROFILE_LANGUAGE_CODE_LENGTH); @n
	*								- The value of the relationship status property is not @n
	*									#PROFILE_RELATIONSHIP_STATUS_MARRIED, @n
	*									#PROFILE_RELATIONSHIP_STATUS_ENGAGED, @n
	*									#PROFILE_RELATIONSHIP_STATUS_IN_RELATIONSHIP @n
	*									or #PROFILE_RELATIONSHIP_STATUS_SINGLE.
	* @see LocaleManager::GetAvailableTimeZonesN(), LocaleManager::GetSystemTimeZone()
	*
	* @code
	* using namespace Osp::Base;
	* using namespace Osp::Social::Services;
	* using namespace Osp::Locales;
	*
	* void
	* MyClass::SomeMethod(PersonalProfile& personalProfile)
	* {
	*
	*	// Sets the relationship status ( PROFILE_RELATIONSHIP_STATUS_MARRIED,
	*	//							 PROFILE_RELATIONSHIP_STATUS_ENGAGED,
	*	//							 PROFILE_RELATIONSHIP_STATUS_IN_RELATIONSHIP or PROFILE_RELATIONSHIP_STATUS_SINGLE)
	*	personalProfile.SetValue(PP_PID_RELATIONSHIP_STATUS, PROFILE_RELATIONSHIP_STATUS_SINGLE);
	*
	*	// Sets the language code.
	*	personalProfile.SetValue(PP_PID_LANGUAGE_CODE, Locale::LanguageCodeToString(LANGUAGE_KOK));
	*
	*	LocaleManager localeManager;
	*	localeManager.Construct();
	*
	*	// Sets the time zone ID. The time zone ID list can be got by using LocaleManager::GetAvailableTimeZonesN or LocaleManager::GetSystemTimeZone.
	*	personalProfile.SetValue(PP_PID_LOCAL_TIME_ZONE , localeManager.GetSystemTimeZone().GetId());
	*
	* }
	* @endcode
	*/
	result SetValue(PersonalProfilePropertyId id, const Osp::Base::String& value);

	/**
	* Replaces the value of the specified ID with the specified DateTime value. @n
	* Use this method only if the property ID is @c PP_PID_BIRTHDAY or @c PP_PID_WEDDING_ANNIVERSARY.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	id					The ID of the property
	* @param[in]	value				The value to be set
	* @exception	E_SUCCESS			The method is successful.		
	* @exception	E_INVALID_ARG		The property identified by the specified @c id is not of the DateTime type. @n
	*									The properties that have a value of the DateTime type are birthday and wedding anniversary.
	*
	* @code
	* using namespace Osp::Base;
	* using namespace Osp::Social::Services;
	*
	* void
	* MyClass::SomeMethod(PersonalProfile& personalProfile)
	* {
	*
	*	// Sets the birthday.
	*	DateTime birthday;
	*	birthday.SetValue(1970, 12, 25);
	*	personalProfile.SetValue(PP_PID_BIRTHDAY, birthday);
	*
	*	// Sets the wedding anniversary.
	*	DateTime anniversary;
	*	anniversary.SetValue(2009, 10, 25);
	*	personalProfile.SetValue(PP_PID_WEDDING_ANNIVERSARY, anniversary);
	*
	* }
	* @endcode
	*/
	result SetValue(PersonalProfilePropertyId id, const Osp::Base::DateTime& value);

	/**
	* Removes the value of the specified property ID.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	id				The ID of the property to be removed
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	The specified property ID is @c #PP_PID_LOCAL_TIME_ZONE. @n
	*								The values of the local time zone cannot be removed.
	*/
	result RemoveValue(PersonalProfilePropertyId id);

private:
	bool IsUpdatedProperty(PersonalProfilePropertyId id) const;
	Osp::Base::String GetValueString(PersonalProfilePropertyId id) const;
	result SetValueString(PersonalProfilePropertyId id, const Osp::Base::String& value);
	result SetValueDateTime(PersonalProfilePropertyId id, const Osp::Base::DateTime& value);

private:
	Osp::Base::String __properties[PERSONAL_PROFILE_PROPERTY_COUNT];
	bool __dirtyBits[PERSONAL_PROFILE_PROPERTY_COUNT];

private:
	friend class PersonalProfileEx;
	class PersonalProfileEx* __pPersonalProfileEx;

}; // PersonalProfile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_PERSONAL_PROFILE_H_
