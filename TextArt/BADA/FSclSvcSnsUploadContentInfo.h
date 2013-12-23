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
* @file		FSclSvcSnsUploadContentInfo.h
* @brief	This is the header file for the %SnsUploadContentInfo class.
*
* This header file contains the declarations of the %SnsUploadContentInfo class.
*/
#ifndef _FSCL_SVC_SNS_UPLOAD_CONTENT_INFO_H_
#define _FSCL_SVC_SNS_UPLOAD_CONTENT_INFO_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseColArrayList.h"
#include "FSclConfig.h"

#include "FSclSvcSnsTypes.h"

namespace Osp { namespace Social { namespace Services {

/**
* @enum	SnsUploadContentType
* Defines the types of the upload content.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 		1.0
*/
enum SnsUploadContentType {
	SNS_UPLOAD_CONTENT_PHOTO,	/**< The Photo content*/
	SNS_UPLOAD_CONTENT_VIDEO	/**< The Video content, not yet supported */
};

/**
* @enum SnsUploadContentPropertyId
* Defines the properties of the information for the upload content.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 		1.0
*/
enum SnsUploadContentPropertyId {
	SNS_CONTENT_PID_TYPE,				/**< The content type */
	SNS_CONTENT_PID_SOURCE_FILE,		/**< The source file path */
	SNS_CONTENT_PID_TITLE,				/**< The title */
	SNS_CONTENT_PID_DESCRIPTION,		/**< The description */
	SNS_CONTENT_PID_PRIVACY,			/**< The privacy level */
	SNS_CONTENT_PID_LOCATION,			/**< The location */
	SNS_CONTENT_PID_TAG,				/**< The tag */
};

/**
* @class		SnsUploadContentInfo 
* @brief		This class represents the content metadata information for a photo to be uploaded.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
* 
* The %SnsUploadContentInfo class represents the content metadata information for a photo to be uploaded.
* Some service providers may not support uploading content with metadata. Alternatively, some data may not be available for a specified 
* service provider. @n 
* Only the following properties can be set for the content:
* @n
<table>
<tr><td> Property			</td>	<td> The Property ID						</td> <td> Value type	</td>	<td> The description </td></tr>
<tr><td> Content type		</td>	<td>  SNS_CONTENT_PID_TYPE				</td><td> SnsUploadContentType </td>	<td>The content type </td></tr>
<tr><td> Content source file path</td><td> SNS_CONTENT_PID_SOURCE_FILE		</td><td> String </td>	<td> The source file path </td></tr>
<tr><td> Title				</td>	<td> SNS_CONTENT_PID_TITLE				</td> <td> String </td>	<td> The title of the content </td> </tr>
<tr><td> Description		</td>	<td> SNS_CONTENT_PID_DESCRIPTION		</td><td> String </td>	<td> The description of the content </td></tr>
<tr><td> Privacy level		</td>	<td>SNS_CONTENT_PID_PRIVACY				</td><td> SnsPrivacyLevel </td>	<td> Specifies who can see the content </td> </tr>
<tr><td> Location			</td>	<td> SNS_CONTENT_PID_LOCATION			</td><td> String </td>	<td> The location </td></tr>
<tr><td> Tag				</td>	<td> SNS_CONTENT_PID_TAG				</td><td> String </td>	<td> The comma-separated list of tags to apply to the content </td></tr>
</table>
* @n
* The following table represents the properties supported by each service provider:
<table>
<tr><td> Property		</td>	<td> Property ID						</td><td> Facebook </td><td> MySpace </td></tr>
<tr><td> Content type		</td>	<td>  SNS_CONTENT_PID_TYPE			</td>	<td> O </td>	<td> O </td></tr>
<tr><td> Content source file path</td><td> SNS_CONTENT_PID_SOURCE_FILE	</td>	<td> O </td>	<td> O </td></tr>
<tr><td> Title				</td>	<td> SNS_CONTENT_PID_TITLE			</td>	<td> - </td>	<td> - </td></tr>
<tr><td> Description		</td>	<td> SNS_CONTENT_PID_DESCRIPTION	</td>	<td> O(caption)</td><td> O(caption)</td></tr>
<tr><td> Privacy level		</td>	<td>SNS_CONTENT_PID_PRIVACY			</td>	<td> O </td>	<td> - </td></tr>
<tr><td> Location			</td>	<td> SNS_CONTENT_PID_LOCATION		</td>	<td> - </td>	<td> - </td></tr>
<tr><td> Tag				</td>	<td> SNS_CONTENT_PID_TAG			</td>	<td> - </td>	<td> - </td></tr>
</table>
*
* @remarks
* 1. The default value of the @c SNS_CONTENT_PID_PRIVACY property ID is @c SNS_PRIVACY_LEVEL_PRIVATE. @n
* 2. For Facebook, the value of the @c SNS_CONTENT_PID_PRIVACY property ID should be set as one of SNS_PRIVACY_LEVEL_FRIENDS_ONLY, SNS_PRIVACY_LEVEL_NETWORKS_ONLY, and SNS_PRIVACY_LEVEL_PUBLIC.@n
* 3. Some service providers do not allow setting the privacy level of the content at the time of upload. @n
*    In this case, the @c SNS_CONTENT_PID_PRIVACY property ID is ignored and the privacy level of the uploaded content is set based on the policy of each 
*	 service provider. @n
* Verify the policy document of the service provider.
*
*/

class  _EXPORT_SOCIAL_ SnsUploadContentInfo :
	public Osp::Base::Object
{
private:
	/**
	* This is the default constructor for this class.	
	*/
	SnsUploadContentInfo(void);


public:
	/**
	* Initializes this instance of %SnsUploadContentInfo with the specified parameters. @n
	* It creates an instance of the %SnsUploadContentInfo class with the specified content type and the source file path.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	contentType		The content type
	* @param[in]	srcFilePath		The source file path
	*/
	SnsUploadContentInfo(SnsUploadContentType contentType, const Osp::Base::String& srcFilePath);

	/**
	* This is the copy constructor for the %SnsUploadContentInfo class. @n
	* It creates an instance of the %SnsUploadContentInfo class with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsUploadContentInfo
	*/
	SnsUploadContentInfo(const SnsUploadContentInfo& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SnsUploadContentInfo to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0 
	* @param[in]	value	An instance of %SnsUploadContentInfo
	*/
	SnsUploadContentInfo& operator =(const SnsUploadContentInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsUploadContentInfo(void);

public:
	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The property value as a String instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId does not have a string value.
	*/
	result GetValue(SnsUploadContentPropertyId propertyId, Osp::Base::String& value) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[out]	value			The type of content being uploaded as an SnsUploadContentType instance
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result GetValue(SnsUploadContentPropertyId propertyId, SnsUploadContentType& value) const;

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
	result GetValue(SnsUploadContentPropertyId propertyId, SnsPrivacyLevel& value) const;

	/**
	* Sets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			A string value for the specified property
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsUploadContentPropertyId propertyId, const Osp::Base::String& value);

	/**
	* Sets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			A value of the SnsUploadContentType enumerator for the specified property
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	*/
	result SetValue(SnsUploadContentPropertyId propertyId, SnsUploadContentType value);

	/**
	* Sets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	propertyId		The property ID
	* @param[in]	value			A value of the SnsPrivacyLevel enumerator for the specified property
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c propertyId is invalid.
	* @remarks		For Facebook, SNS_PRIVACY_LEVEL_PRIVATE, SNS_PRIVACY_LEVEL_CUSTOM, SNS_PRIVACY_LEVEL_FRIENDS_OF_FRIENDS are not supported.
    *               If you upload a content with privacy as one of those privacy levels, you will receive a server error.
    *              If an invalid level is set, the privacy level will be set to SNS_PRIVACY_LEVEL_PRIVATE.
	*/
	result SetValue(SnsUploadContentPropertyId propertyId, SnsPrivacyLevel value);

private:
	SnsUploadContentType		__type;	
	Osp::Base::String		__albumId;
	Osp::Base::String		__title;
	Osp::Base::String		__description;
	Osp::Base::String		__location;
	SnsPrivacyLevel		__privacyLevel;
	Osp::Base::String		__tagCaption;
	Osp::Base::String		__filePath;

	friend class SnsUploadContentInfoEx;
	class SnsUploadContentInfoEx* __pSnsUploadContentInfoEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_UPLOAD_CONTENT_INFO_H_
