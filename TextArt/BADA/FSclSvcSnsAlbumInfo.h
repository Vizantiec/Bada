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
* @file		FSclSvcSnsAlbumInfo.h
* @brief	This is the header file for the %SnsAlbumInfo class.
*
* This header file contains the declarations of the %SnsAlbumInfo class.
*/
#ifndef _FSCL_SVC_SNS_ALBUM_INFO_H_
#define _FSCL_SVC_SNS_ALBUM_INFO_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FSclConfig.h"
#include "FSclSvcSnsTypes.h"

#include "FSclSvcSnsImageInfo.h"

namespace Osp { namespace Social { namespace Services {

class __SnsUtil;

/**
* @enum		SnsAlbumPropertyId
* Defines the property of an album.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
enum SnsAlbumPropertyId {
	SNS_ALBUM_PID_TITLE,				/**< The title */
	SNS_ALBUM_PID_DESCRIPTION,			/**< The description */
	SNS_ALBUM_PID_PRIVACY_LEVEL,		/**< The privacy level */
	SNS_ALBUM_PID_OWNER_ID,				/**< The owner ID */
	SNS_ALBUM_PID_OWNER_NAME,			/**< The owner name */
	SNS_ALBUM_PID_COVER_IMAGE,			/**< The cover image information */
	SNS_ALBUM_PID_CONTENT_COUNT			/**< The content count */

};

/**
* @class		SnsAlbumInfo 
* @brief		This class provides the methods to access the information of an SNS album.
*				The album is a user-created album that contains photos. 
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
* 
*  The %SnsAlbumInfo class provides the methods to access the information of an SNS album.
*	The album is a user-created album that contains photos. 
* Some service providers may not support the album entity. The metadata about the album is different for each service provider. Some data may not be 
* available for a specific service provider.
* The following properties can be obtained: @n
* 
<table>
<tr><td> Property	</td>	<td> Property ID </td> <td> Value type	</td>	<td> The description of the property</td></tr>
<tr><td> Title </td>	<td> SNS_ALBUM_PID_TITLE </td>  <td> String </td>	<td> The title of the album </td></tr>
<tr><td> Description  </td>	<td> SNS_ALBUM_PID_DESCRIPTION </td> <td> String </td>	<td> The description of the album </td></tr>
<tr><td> Privacy level	</td>	<td> SNS_ALBUM_PID_PRIVACY_LEVEL </td> <td> SnsPrivacyLevel </td>	<td> Who can view the album </td></tr>
<tr><td> Owner ID </td>	<td> SNS_ALBUM_PID_OWNER_ID </td> <td> String </td>	<td> The snsUserId of the user who owns the album </td></tr>
<tr><td> Owner name </td>	<td> SNS_ALBUM_PID_OWNER_NAME </td> <td> String </td>	<td> The user name of the user who owns the album </td></tr>
<tr><td> Cover content image information </td>	<td> SNS_ALBUM_PID_COVER_IMAGE </td>  <td> SnsImageInfo </td>	<td> The content image information which represents the album </td></tr>
<tr><td> Content count </td>	<td> SNS_ALBUM_PID_CONTENT_COUNT </td> <td> int </td>	<td> The count of the content that belongs to the album  </td></tr>
</table>
* @n
* The following table represents the properties each service provider supports: @n
<table>
<tr><td> Property		</td>	<td> Property ID								</td> <td> Facebook</td><td> MySpace</td></tr>
<tr><td> Title			</td>	<td> SNS_ALBUM_PID_TITLE						</td> <td> O	</td>	<td> O	</td>	</tr>
<tr><td> Description	</td>	<td> SNS_ALBUM_PID_DESCRIPTION					</td> <td> O	</td>	<td> -	</td>	</tr>
<tr><td> Privacy level	</td>	<td> SNS_ALBUM_PID_PRIVACY_LEVEL				</td> <td> O	</td>	<td> -	</td>	</tr>
<tr><td> Owner ID		</td>	<td> SNS_ALBUM_PID_OWNER_ID						</td> <td> O	</td>	<td> O	</td>	</tr>
<tr><td> Owner name		</td>	<td> SNS_ALBUM_PID_OWNER_NAME					</td> <td> -	</td>	<td> -	</td>	</tr>
<tr><td> Cover content image information </td>	<td> SNS_ALBUM_PID_COVER_IMAGE	</td> <td> O	</td>	<td> O	</td>	</tr>
<tr><td> content count </td>	<td> SNS_ALBUM_PID_CONTENT_COUNT				</td> <td> O	</td>	<td> O	</td>	</tr>
</table>																			  
* @n
* @remarks	1. If the album is not the album of a logged-in user, then the @c SNS_ALBUM_PID_PRIVACY_LEVEL is always @c SNS_PRIVACY_LEVEL_PUBLIC. @n
*			2. The default value of @c SNS_ALBUM_PID_PRIVACY_LEVEL is @c SNS_PRIVACY_LEVEL_PUBLIC. If a specific service provider does not support the 
*			   @c SNS_PHOTO_PID_PRIVACY_LEVEL property, @c SNS_PRIVACY_LEVEL_PUBLIC will be returned.
*
*
*/
class  _EXPORT_SOCIAL_ SnsAlbumInfo:												  
	public Osp::Base::Object														  
{																					  
	friend class __SnsUtil;															  
																					  
private:
	/**
	* Initializes this instance of %SnsAlbumInfo with the specified parameters.
	*/
	SnsAlbumInfo(const Osp::Base::String& serviceProvider, const Osp::Base::String& albumId );

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	SnsAlbumInfo(void);

	/**
	* This is the copy constructor for the %SnsAlbumInfo class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value		An instance of %SnsAlbumInfo
	*/
	SnsAlbumInfo(const SnsAlbumInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsAlbumInfo(void);

public:
	/**
	* Gets the service provider.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The service provider
	*/
	Osp::Base::String	GetServiceProvider(void) const;

	/**
	* Gets the ID of the album.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The album ID
	*/
	Osp::Base::String	GetAlbumId(void) const;

	/**
	* Gets the value of the String type property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is got
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsAlbumPropertyId propertyId, Osp::Base::String& value ) const;

	/**
	* Gets the value of the integer type property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is got
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsAlbumPropertyId propertyId, int& value ) const;

	/**
	* Gets the value of the SnsImageInfo type property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is got
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsAlbumPropertyId propertyId, SnsImageInfo& value ) const;

	/**
	* Gets the value of the SnsPrivacyLevel type property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is got
	* @param[out]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsAlbumPropertyId propertyId, SnsPrivacyLevel& value ) const;

private:
	/**
	* Sets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is set
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsAlbumPropertyId propertyId, const Osp::Base::String& value );

	/**
	* Sets the value of specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is set
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsAlbumPropertyId propertyId, int value );

	/**
	* Sets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is set
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsAlbumPropertyId propertyId, const SnsImageInfo& value );

	/**
	* Sets the value of specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID for which the value is set
	* @param[in]	value			The property value
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsAlbumPropertyId propertyId, SnsPrivacyLevel value );

private:
	Osp::Base::String		__serviceProvider;
	Osp::Base::String		__albumId;
	Osp::Base::String		__title;
	Osp::Base::String		__description;
	SnsPrivacyLevel			__privacyLevel;
	Osp::Base::String		__ownerId;
	Osp::Base::String		__ownerName;
	SnsImageInfo			__converImage;
	int						__contentCount;

	friend class SnsAlbumInfoEx;
	class SnsAlbumInfoEx* __pSnsAlbumInfoEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_ALBUM_INFO_H_
