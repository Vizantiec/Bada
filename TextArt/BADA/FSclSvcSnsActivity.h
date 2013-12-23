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
* @file		FSclSvcSnsActivity.h
* @brief	This is the header file for the %SnsActivity class.
*
* This header file contains the declarations of the %SnsActivity class.
*/
#ifndef _FSCL_SVC_SNS_ACTIVITY_H_
#define _FSCL_SVC_SNS_ACTIVITY_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseDateTime.h"
#include "FSclConfig.h"
#include "FSclSvcTypes.h"
#include "FSclSvcSnsTypes.h"

namespace Osp { namespace Social { namespace Services {

class __SnsUtil;

	/**
	* @enum SnsActivityPropertyId
	* Defines the property of an activity.
	*
	* @deprecated	This enum is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	enum SnsActivityPropertyId {
		SNS_ACTIVITY_PID_TARGET_ID,					/**< The target ID */
		SNS_ACTIVITY_PID_OWNER_ID,					/**< The owner ID */
		SNS_ACTIVITY_PID_OWNER_NAME,				/**< The owner name */
		SNS_ACTIVITY_PID_OWNER_PROFILE_PHOTO_URL, 	/**< The owner profile photo URL */
		SNS_ACTIVITY_PID_ACT_TIME,					/**< The act time */
		SNS_ACTIVITY_PID_CONTENT,					/**< The activity content*/
		SNS_ACTIVITY_PID_THUMBNAIL_URL,				/**< An image thumbnail URL */

	};

/**
* @class		SnsActivity 
* @brief		This class represents the information of an SNS activity.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
* 
* 
* The %SnsActivity class represents the information of an SNS activity.
*
* Some service providers may not support the activity entity. The following properties can be obtained.
* @n
<table>
<tr><td> Property	</td>					<td> Property ID </td>					<td> Value type	</td>	<td> Description </td></tr>
<tr><td> Activity target ID	</td>			<td> SNS_ACTIVITY_PID_TARGET_ID </td>	<td> String </td>		<td> The ID of the activity target such as the photoId and the snsUserId </td></tr>
<tr><td> Activity owner ID </td>			<td> SNS_ALBUM_PID_OWNER_ID </td>		<td> String </td>		<td> The snsUserId of the owner who performs the activity </td></tr>
<tr><td> Activity owner name </td>			<td> SNS_ACTIVITY_PID_OWNER_NAME </td>	<td> String </td>		<td> The user name of the owner who performs the activity </td></tr>
<tr><td> Activity owner profile photo URL</td>	<td> SNS_ACTIVITY_PID_OWNER_PROFILE_PHOTO_URL </td>			<td> String </td>	<td> The profile photo URL of the activity owner </td></tr>
<tr><td> Activity act time </td>			<td> SNS_ACTIVITY_PID_ACT_TIME </td>	<td> DateTime </td>		<td> The time when the user performs the activity  </td></tr>
<tr><td> Activity content </td>			<td> SNS_ACTIVITY_PID_CONTENT </td> <td> String </td>				<td> The content of the activity, such as the status text and the photo title </td></tr>
<tr><td> Activity thumbnail image URL		</td>	<td> SNS_ACTIVITY_PID_THUMBNAIL_URL </td> <td> String </td>	<td> The thumbnail image URL, such as the photo </td></tr>
</table>
* @n	
* @n
* In Twitter, the activity means the tweet updated by a specific user. The following table represents the details: @n
* @n
<table>
<tr><td> Target type </td> <td> Always 'status' </td></tr>
<tr><td> Target ID </td> <td> None</td></tr>
<tr><td> Content </td> <td> The content of tweet</td></tr>
<tr><td> Thumbnail Image URL </td> <td> None</td></tr>
</td>
</tr>
</table>
*/																					  
class  _EXPORT_SOCIAL_ SnsActivity:												  
	public Osp::Base::Object														  
{																					  
	friend class __SnsUtil;															  
																					  
private:
	/**
	* Initializes this instance of %SnsActivity with the specified parameters.
	*/
	SnsActivity(const Osp::Base::String& serviceProvider, SnsActivityType activityType, const Osp::Base::String& activityTargetId, 
		const Osp::Base::String& ownerId, const Osp::Base::String& ownerName, const Osp::Base::String& ownerProfilePhotoUrl,
		const Osp::Base::DateTime& actTime, const Osp::Base::String& activityContent, const Osp::Base::String& thumbnailUrl);

public:
	/**
	* This is the default constructor for this class.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	SnsActivity(void);

	/**
	* This is the copy constructor for the %SnsActivity class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @param[in]	value		An instance of %SnsActivity
	*/
	SnsActivity(const SnsActivity& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~SnsActivity(void);

	// Operations
public:
	/**
	* Gets the service provider.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The service provider
	*/
	Osp::Base::String	GetServiceProvider(void) const;

	/**
	* Gets the type of activity.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		The type of activity
	*/
	SnsActivityType	GetActivityType(void) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsActivityPropertyId propertyId, Osp::Base::String& value ) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsActivityPropertyId propertyId, Osp::Base::DateTime& value ) const;

private:
	/**
	* Sets the value of the specified property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsActivityPropertyId propertyId, const Osp::Base::String& value );

	/**
	* Sets the value of the specified property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsActivityPropertyId propertyId, const Osp::Base::DateTime value );

private:
	Osp::Base::String		__serviceProvider;
	SnsActivityType			__activityType;
	Osp::Base::String		__activityTargetId;
	Osp::Base::String		__ownerId;
	Osp::Base::String		__ownerName;
	Osp::Base::String		__ownerProfilePhotoUrl;
	Osp::Base::String		__content;
	Osp::Base::DateTime		__actTime;
	Osp::Base::String		__thumbnailUrl;

	friend class SnsActivityEx;
	class SnsActivityEx* __pSnsActivityEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_ACTIVITY_H_
