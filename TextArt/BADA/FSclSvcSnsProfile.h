/* $Change: 1202329 $ */
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
* @file		FSclSvcSnsProfile.h
* @brief	This is the header file for the %SnsProfile class.
*
* This header file contains the declarations of the %SnsProfile class.
*/
#ifndef _FSCL_SVC_SNS_PROFILE_H_
#define _FSCL_SVC_SNS_PROFILE_H_

#include "FSclConfig.h"
#include "FBaseString.h"
#include "FBaseColIList.h"
#include "FBaseColArrayList.h"
#include "FBaseDateTime.h"

#include "FSclSvcSnsStatusText.h"


namespace Osp { namespace Social { namespace Services {

	class __SnsUtil;
/**
* @enum SnsProfilePropertyId
* Defines the properties of a profile.
*
* @deprecated	This enum is deprecated due to the operation policy of the bada Server.
* @since		1.0
*/
enum SnsProfilePropertyId {
	SNS_PROFILE_PID_DISPLAY_NAME,					/**< The display name */
	SNS_PROFILE_PID_USER_NAME,						/**< The user name */
	SNS_PROFILE_PID_FIRST_NAME,						/**< The first name */
	SNS_PROFILE_PID_LAST_NAME,						/**< The last name */
	SNS_PROFILE_PID_PHOTO_URL,						/**< The photo URL */
	SNS_PROFILE_PID_GENDER,							/**< The gender */
	SNS_PROFILE_PID_LOCATION,						/**< The location */
	SNS_PROFILE_PID_OCCUPATION,						/**< The occupation */
	SNS_PROFILE_PID_COMPANY,						/**< The company */
	SNS_PROFILE_PID_HOMETOWN,						/**< The hometown */
	SNS_PROFILE_PID_NOTE,							/**< The note */
	SNS_PROFILE_PID_BIRTHDAY,						/**< The birthday */
	SNS_PROFILE_PID_URLS,							/**< The URLs */
	SNS_PROFILE_PID_ADDRESSES,						/**< The addresses */
	SNS_PROFILE_PID_EMAILS,							/**< @if PRIVCORE The email addresses @b since: @b 2.0 @endif*/
	SNS_PROFILE_PID_PHONE_NUMBERS					/**< @if PRIVCORE The phone numbers @b since: @b 2.0 @endif*/
};

/**
* @class		SnsProfile
* @brief		This class provides the methods to manage the information in an SNS profile. @n
*				The data on this profile is updated by the users on a specific service provider.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* 
* The %SnsProfile class provides the methods to manage the information in an SNS profile. @n
*				The data on this profile is updated by the users on a specific service provider.

* The metadata of a profile is different for each service provider. Some data may not be available for a specific service provider. @n
* Only the following properties are supported as metadata for a profile:
* @n
<table>
<tr><td> Property	</td>	<td> Property ID </td> <td> Value type	</td>	<td> Description </td></tr>
<tr><td> First name </td>	<td> SNS_PROFILE_PID_FIRST_NAME </td><td> String </td>	<td> The first name of the user </td></tr>
<tr><td> Last name </td>	<td> SNS_PROFILE_PID_LAST_NAME </td><td> String </td>	<td> The last name of the user </td></tr>
<tr><td> Display name  </td>	<td> SNS_PROFILE_PID_DISPLAY_NAME </td><td> String </td>	<td> The display name of the user </td></tr>
<tr><td> User name </td>	<td> SNS_PROFILE_PID_USER_NAME </td><td> String </td>	<td> The name of the user </td></tr>
<tr><td> Photo URL </td>	<td> SNS_PROFILE_PID_PHOTO_URL </td><td> String </td>	<td> The profile photo URL to get the photo image  </td></tr>
<tr><td> Gender </td>	<td> SNS_PROFILE_PID_GENDER </td><td> String </td>	<td> The gender of the user. @c PROFILE_GENDER_FEMALE or @c PROFILE_GENDER_MALE </td></tr>
<tr><td> Location </td>	<td> SNS_PROFILE_PID_LOCATION </td><td> String </td>	<td> The user entered location </td></tr>
<tr><td> Occupation </td>	<td> SNS_PROFILE_PID_OCCUPATION </td><td> String </td>	<td> The occupation or business category  </td></tr>
<tr><td> Company </td>	<td> SNS_PROFILE_PID_COMPANY </td><td> String </td>	<td> The name of the company the user works for </td></tr>
<tr><td> Hometown </td>	<td> SNS_PROFILE_PID_HOMETOWN </td><td> String </td>	<td> The hometown </td></tr>
<tr><td> Note </td>	<td> SNS_PROFILE_PID_NOTE </td><td> String </td>	<td> The note written by the user </td></tr>
<tr><td> Birthday  </td>	<td> SNS_PROFILE_PID_BIRTHDAY </td><td> DateTime </td>	<td> The birthday </td></tr>
<tr><td> URLs </td>	<td> SNS_PROFILE_PID_URLS </td><td> List of String  </td>	<td> The list of URLs the user inserted </td></tr>
<tr><td> Addresses </td>	<td> SNS_PROFILE_PID_ADDRESSES </td><td> List of Social::Address </td>	<td> The type and addresses. The address type can be either home or work </td></tr>
@if PRIVCORE
<tr><td> %Email addresses </td>	<td> SNS_PROFILE_PID_EMAILS </td> <td> List of String </td>	<td> The list of emails </td> </tr>
<tr><td> Phone numbers </td>	<td> SNS_PROFILE_PID_PHONE_NUMBERS </td><td> List of Social::PhoneNumber  </td>	<td> The type and phone numbers. The phone number type can be home, work, mobile, or other.  </td></tr>
@endif
</table>
* @n
* The following table represents the properties supported by each service provider:
<table>
<tr><td> Property		</td>	<td> Property ID					</td>	<td> Twitter </td><td> Facebook </td>	<td> MySpace </td></tr>
<tr><td> First name		</td>	<td> SNS_PROFILE_PID_FIRST_NAME		</td>	<td> - </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> Last name		</td>	<td> SNS_PROFILE_PID_LAST_NAME		</td>	<td> - </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> Display name	</td>	<td> SNS_PROFILE_PID_DISPLAY_NAME	</td>	<td> O </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> User name		</td>	<td> SNS_PROFILE_PID_USER_NAME		</td>	<td> O </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Photo URL		</td>	<td> SNS_PROFILE_PID_PHOTO_URL		</td>	<td> O </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> Gender			</td>	<td> SNS_PROFILE_PID_GENDER			</td>	<td> - </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> Location		</td>	<td> SNS_PROFILE_PID_LOCATION		</td>	<td> - </td>	  <td> - </td>			<td> - </td></tr>
<tr><td> Occupation	</td>		<td> SNS_PROFILE_PID_OCCUPATION		</td>	<td> - </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Company		</td>	<td> SNS_PROFILE_PID_COMPANY		</td>	<td> - </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Hometown		</td>	<td> SNS_PROFILE_PID_HOMETOWN		</td>	<td> - </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Note			</td>	<td> SNS_PROFILE_PID_NOTE			</td>	<td> - </td>	  <td> O(About Me)</td>	<td> O(About Me) </td></tr>
<tr><td> Birthday		</td>	<td> SNS_PROFILE_PID_BIRTHDAY		</td>	<td> - </td>	  <td> O </td>			<td> O </td></tr>
<tr><td> URLs			</td>	<td> SNS_PROFILE_PID_URLS			</td>	<td> O </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Addresses		</td>	<td> SNS_PROFILE_PID_ADDRESSES		</td>	<td> O </td>	  <td> O </td>			<td> O </td></tr>
@if PRIVCORE
<tr><td> %Email addresses</td>	<td> SNS_PROFILE_PID_EMAILS			</td>	<td> - </td>	  <td> O </td>			<td> - </td></tr>
<tr><td> Phone numbers	</td>	<td> SNS_PROFILE_PID_PHONE_NUMBERS	</td>	<td> - </td>	  <td> O </td>			<td> - </td></tr>
@endif
</table>
* @n
* @remarks	If this %SnsProfile instance is obtained from SnsGateway::GetMyBuddies(), some properties are not supported: first name, last name, occupation, 
* 			hometown, note, URLs, and addresses. Moreover, some properties(gender, location, birthday) may not be supported for a specific service provider. 
*			To get these properties, call SnsGateway::GetProfile().
* @n
*/

class  _EXPORT_SOCIAL_ SnsProfile :
	public Osp::Base::Object
{
	friend class __SnsUtil;

private:

	/**
	* Initializes this instance of %SnsProfile with the specified parameters.
	*/
	SnsProfile(const Osp::Base::String& serviceProvider, const Osp::Base::String& snsUserId);

public:

	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	SnsProfile(void);

	/**
	* This is the copy constructor for the %SnsProfile class. @n
	* It creates an instance of the %SnsProfile with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value	An instance of %SnsProfile
	*/
	SnsProfile(const SnsProfile& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SnsProfile to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value	An instance of %SnsProfile
	*/
	SnsProfile& operator =(const SnsProfile& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~SnsProfile(void);

public:

	/**
	* Gets the service provider of the SNS profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The service provider
	*/
	Osp::Base::String	GetServiceProvider(void) const;

	/**
	* Gets the SNS user ID of the SNS profile.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The SNS user ID
	*/
	Osp::Base::String	GetSnsUserId(void) const;

	/**
	* Gets the status text information.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An instance of SnsStatusText
	*/
	Osp::Social::Services::SnsStatusText	GetStatusText(void) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value as a String instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a string value.
	*/
	result GetValue(SnsProfilePropertyId propertyId, Osp::Base::String& value) const;

	/**
	* Gets the value of the specified property. @n
	* The possible property is @c SNS_PROFILE_PID_BIRTHDAY. @n
	* If a specific service provider does not provide the specific property, or the user has not specified the DateTime value for the specified property,
	* the property has the minimum value of the DateTime, which can be retrieved by DateTime::GetMinValue(), for example, "January 11 00:00:00".
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value as a DateTime instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a DateTime value.
	*/
	result GetValue(SnsProfilePropertyId propertyId, Osp::Base::DateTime& value) const;

	/**
	* Gets the value of the specified property. @n
	* @if PRIVCORE	The only possible properties for this method are @c SNS_PROFILE_PID_PHONE_NUMBERS, @c SNS_PROFILE_PID_EMAILS, @c SNS_PROFILE_PID_URLS, 
	* and @c SNS_PROFILE_PID_ADDRESSES.
	* @else			The only possible properties for this method are @c SNS_PROFILE_PID_URLS and @c SNS_PROFILE_PID_ADDRESSES.
	* @endif
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		A list of values for the specified @c propertyId, @n
					or an empty list if the specified property value is not set or @c null if an exception occurs.
	* @param[in]	propertyId			The property ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c propertyId does not have a List value.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	* 				If the specified @c propertyId is not in a valid range of SnsProfilePropertyId, the application can be terminated @b since: @b 2.0.
	*/
	Osp::Base::Collection::IList* GetValueN(SnsProfilePropertyId propertyId) const;

private:
	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as a String instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a String value.
	*/
	result SetValue(SnsProfilePropertyId propertyId, const Osp::Base::String& value);

	/**
	* Sets the value of the property. @n
	* The possible property is @c SNS_PROFILE_PID_BIRTHDAY.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as a DateTime instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a DateTime value.
	*/
	result SetValue(SnsProfilePropertyId propertyId, const Osp::Base::DateTime& value);

	/**
	* Sets the value of the property. @n
	* The possible property is @c SNS_PROFILE_PID_PHONE_NUMBERS, @c SNS_PROFILE_PID_EMAILS, @c SNS_PROFILE_PID_URLS, @c SNS_PROFILE_PID_ADDRESSES, 
	* @c SNS_PROFILE_PID_EDUCATION_HISTORY, @c SNS_PROFILE_PID_WORK_HISTORY.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as an IList instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a List value.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	*/
	result SetValue(SnsProfilePropertyId propertyId, const Osp::Base::Collection::IList& valueList);

	/**
	* Sets the status text information of the SNS user ID.
	*
	* @param[in]	statusText	The status text information
	*/
	void	SetStatusText(Osp::Social::Services::SnsStatusText& statusText);


private:

	Osp::Base::String			__serviceProvider;
	Osp::Base::String			__snsUserId;

	// basic
	Osp::Base::String			__displayName;
	Osp::Base::String			__userName;
	Osp::Base::String			__firstName;
	Osp::Base::String			__lastName;
	Osp::Base::String			__photoUrl;
	Osp::Base::String			__gender;
	Osp::Base::String			__location;

	//contact
	Osp::Base::Collection::ArrayList		__addresses;
	Osp::Base::Collection::ArrayList 		__urls;

	// personal
	Osp::Base::DateTime		__birthday;
	Osp::Base::String		__occupation;
	Osp::Base::String		__company;
	Osp::Base::String		__hometown;
	Osp::Base::String		__note;

	Osp::Social::Services::SnsStatusText		__presence;

	friend class SnsProfileEx;
	class SnsProfileEx* __pSnsProfileEx;
};

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_PROFILE_H_
