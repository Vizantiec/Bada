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
* @file		FSclSvcSnsPhotoInfo.h
* @brief	This is the header file for the %SnsPhotoInfo class.
*
* This header file contains the declarations of the %SnsPhotoInfo class.
*/
#ifndef _FSCL_SVC_SNS_PHOTO_INFO_H_
#define _FSCL_SVC_SNS_PHOTO_INFO_H_

#include "FBaseDateTime.h"
#include "FBaseString.h"
#include "FBaseColArrayList.h"

#include "FSclConfig.h"
#include "FSclSvcSnsTypes.h"
#include "FSclSvcSnsImageInfo.h"

namespace Osp { namespace Social { namespace Services {

	class __SnsUtil;

/**
* @enum SnsPhotoPropertyId
* Defines the property of the content.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 		1.0
*/
enum SnsPhotoPropertyId {
	SNS_PHOTO_PID_ALBUM,				/**< The album ID */
	SNS_PHOTO_PID_TITLE,				/**< The title */
	SNS_PHOTO_PID_DESCRIPTION,			/**< The description */
	SNS_PHOTO_PID_LOCATION,				/**< The location */
	SNS_PHOTO_PID_GEO_LOCATION,			/**< The GeoLocation */	
	SNS_PHOTO_PID_UPLOAD_TIME,			/**< The upload time */
	SNS_PHOTO_PID_OWNER_ID,				/**< The owner ID */
	SNS_PHOTO_PID_OWNER_NAME,			/**< The owner name */
	SNS_PHOTO_PID_PRIVACY_LEVEL,		/**< The privacy level */	
	SNS_PHOTO_PID_MAIN_IMAGE,			/**< The main image */
	SNS_PHOTO_PID_THUMBNAIL_IMAGES,		/**< The thumbnail image */
	SNS_PHOTO_PID_TAG,					/**< The tag */
};

/**
* @class		SnsPhotoInfo 
* @brief		This class provides the methods to manage the information of an SNS photo.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
*
* The %SnsPhotoInfo class provides the methods to manage the information of an SNS photo.
* The metadata of a photo is different for each service provider. Some data may not be available for a specific service provider. @n
* Only the following properties are supported as metadata for a photo:
* @n
<table>
<tr><td> Property					</td><td> Property ID				</td> <td> Value type	</td>	<td> Description </td></tr>
<tr><td> Album ID					</td><td> SNS_PHOTO_PID_ALBUM		</td> <td> String </td>	<td> The ID of the album to which the photo belongs </td></tr>
<tr><td> Title						</td><td> SNS_PHOTO_PID_TITLE		</td>  <td> String </td>	<td> The title of the photo </td></tr>
<tr><td> Description				</td><td> SNS_PHOTO_PID_DESCRIPTION </td> <td> String </td>	<td> The description of the photo </td></tr>
<tr><td> Location					</td><td> SNS_PHOTO_PID_LOCATION	</td> <td> String </td>	<td> The location of the photo which the owner inserted </td></tr>
<tr><td> GEO location				</td><td> SNS_PHOTO_PID_GEO_LOCATION</td> <td> String </td>	<td> The GPS location of the photo </td></tr>
<tr><td> Upload time				</td><td> SNS_PHOTO_PID_UPLOAD_TIME </td> <td> DateTime </td>	<td> The time when the photo is uploaded </td></tr>
<tr><td> Owner ID					</td><td> SNS_PHOTO_PID_OWNER_ID	</td> <td> String </td>	<td> The @c snsUserId of the user who owns the photo </td></tr>
<tr><td> Owner name					</td><td> SNS_PHOTO_PID_OWNER_NAME	</td> <td> String </td>	<td> The user name of the user who owns the photo </td></tr>
<tr><td> Privacy level				</td><td> SNS_PHOTO_PID_PRIVACY_LEVEL</td> <td> SnsPrivacyLevel </td>	<td> Specifies who can view the photo </td> </tr>
<tr><td> Main image information		</td><td> SNS_PHOTO_PID_MAIN_IMAGE	</td>	<td> SnsImageInfo </td> <td> The photo image information </td></tr>
<tr><td> Thumbnail image information</td><td> SNS_PHOTO_PID_THUMBNAIL_IMAGES </td> <td> List of SnsImageInfo </td>	<td> The thumbnail photo image information </td></tr>
<tr><td> Tag						</td><td> SNS_PHOTO_PID_TAG			</td>	<td> String </td> <td> The comma-separated list of tags applied to the photo  </td></tr>
</table>
*
* 
* The following table represents the properties supported by each service provider: @n
<table>
<tr><td> Property					</td><td> Property ID				</td>      <td> Facebook</td><td> MySpace</td></tr>
<tr><td> Album ID					</td><td> SNS_PHOTO_PID_ALBUM		</td>	   <td> O</td>			<td> -</td>		</tr>
<tr><td> Title						</td><td> SNS_PHOTO_PID_TITLE		</td>	   <td> -</td>			<td> O(caption)</td>		</tr>
<tr><td> Description				</td><td> SNS_PHOTO_PID_DESCRIPTION </td>	   <td> O(caption)</td>	<td> -</td></tr>
<tr><td> Location					</td><td> SNS_PHOTO_PID_LOCATION	</td>	   <td> - </td>			<td> -</td>		</tr>
<tr><td> GEO location				</td><td> SNS_PHOTO_PID_GEO_LOCATION</td>	   <td> - </td>			<td> -</td>		</tr>
<tr><td> Upload time				</td><td> SNS_PHOTO_PID_UPLOAD_TIME </td>	   <td> O </td>			<td> -</td>		</tr>
<tr><td> Owner ID					</td><td> SNS_PHOTO_PID_OWNER_ID	</td>	   <td> O</td>			<td> O</td>		</tr>
<tr><td> Owner name					</td><td> SNS_PHOTO_PID_OWNER_NAME	</td>	   <td> - </td>			<td> -</td>		</tr>
<tr><td> Privacy level				</td><td> SNS_PHOTO_PID_PRIVACY_LEVEL</td>	   <td> - </td>			<td> -</td>		</tr>
<tr><td> Main image information		</td><td> SNS_PHOTO_PID_MAIN_IMAGE	</td>	   <td> O</td>			<td> O</td>		</tr>
<tr><td> Thumbnail image information</td><td> SNS_PHOTO_PID_THUMBNAIL_IMAGES </td> <td> O</td>			<td> O</td>		</tr>
<tr><td> Tag						</td><td> SNS_PHOTO_PID_TAG			</td>	   <td> -</td>			<td> -</td>		</tr>
</table>																		   
* @n
* @remarks @n
*  1. If this %SnsPhotoInfo instance is obtained from SnsGateway::GetPhotosInAlbum(), the album ID is not supported. @n
*  2. In Facebook, if this %SnsPhotoInfo instance is obtained from SnsGateway::GetPhotosInAlbum(), @c SNS_PHOTO_PID_TITLE represents the photo caption. @n
*  3. The default value of @c SNS_PHOTO_PID_PRIVACY_LEVEL is @c SNS_PRIVACY_LEVEL_PUBLIC. If a specific service provider does not support the 
*     @c SNS_PHOTO_PID_PRIVACY_LEVEL property, @c SNS_PRIVACY_LEVEL_PUBLIC will be returned.
*
*/
class  _EXPORT_SOCIAL_ SnsPhotoInfo:
	public Osp::Base::Object
{
	friend class __SnsUtil;

private:
	/**
	* Initializes this instance of %SnsPhotoInfo with the specified parameters.
	*/
	SnsPhotoInfo(const Osp::Base::String& serviceProvider, const Osp::Base::String& photoId);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	SnsPhotoInfo(void);

	/**
	* This is the copy constructor for the %SnsPhotoInfo class. @n
	* It creates an instance of the %SnsPhotoInfo class with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsPhotoInfo
	*/
	SnsPhotoInfo(const SnsPhotoInfo& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SnsPhotoInfo to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsPhotoInfo
	*/
	SnsPhotoInfo& operator =(const SnsPhotoInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsPhotoInfo(void);

public:

	/**
	* Gets the service provider of the SNS photo information.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The service provider
	*/
	Osp::Base::String GetServiceProvider(void) const;

	/**
	* Gets the ID of the photo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The ID of the photo
	*/
	Osp::Base::String GetPhotoId(void) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value as a String instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a String value.
	*/
	result GetValue(SnsPhotoPropertyId propertyId, Osp::Base::String& value) const;
	
	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value as a DateTime instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a DateTime value.
	*/
	result GetValue(SnsPhotoPropertyId propertyId, Osp::Base::DateTime& value) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		A list of the values of the specified property, @n
	*				else an empty list if the specified property is not set or @c null if an exception occurs
	* @param[in]	propertyId			The property ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c propertyId is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::Collection::IList* GetValueN(SnsPhotoPropertyId propertyId) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The value of the specified property as an SnsImageInfo instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsPhotoPropertyId propertyId, SnsImageInfo& value) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The level of privacy as an SnsPrivacyLevel instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsPhotoPropertyId propertyId, SnsPrivacyLevel& value) const;

private:
	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as a String instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsPhotoPropertyId propertyId, const Osp::Base::String& value);

	
	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as a DateTime instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsPhotoPropertyId propertyId, const Osp::Base::DateTime& value);

	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as an IList instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	*/
	result SetValue(SnsPhotoPropertyId propertyId, const Osp::Base::Collection::IList& value);

	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as an %SnsImageInfo instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsPhotoPropertyId propertyId, const SnsImageInfo& value);

	/**
	* Sets the value of the property.
	*
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			The property value as an %SnsPrivacyLevel instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsPhotoPropertyId propertyId, SnsPrivacyLevel value);

private:
	Osp::Base::String		__photoId;
	Osp::Base::String		__serviceProvider;
	Osp::Base::String		__albumId;
	Osp::Base::String		__title;
	Osp::Base::String		__description;
	Osp::Base::String		__location;
	Osp::Base::String		__geoLocation;
	Osp::Base::DateTime		__uploadedTime;
	Osp::Base::String		__ownerId;
	Osp::Base::String		__ownerName;
	SnsPrivacyLevel			__privacyLevel;
	SnsImageInfo			__mainImage;
	Osp::Base::Collection::ArrayList	__thumbnailImages;
	Osp::Base::String		__tag;

	friend class SnsPhotoInfoEx;
	class SnsPhotoInfoEx* __pSnsPhotoInfoEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_PHOTO_INFO_H_
