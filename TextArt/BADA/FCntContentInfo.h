/* $Change: 1171327 $ */
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
 * @file	FCntContentInfo.h
 * @brief	This is the header file for the %ContentInfo class.
 *
 * This header file contains the declarations of the %ContentInfo class.
 */

#ifndef _FCNT_CONTENT_INFO_H_
#define _FCNT_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FLocCoordinates.h>
#include <FMediaImage.h>

struct MThumbnailInfo;
struct MContentAttribute;
struct IContentInfo;
struct MContentInfo;

namespace Osp { namespace Content {

class RemoteContentInfo;
class ContentInfoEx;

/**
 * @class	ContentInfo
 * @brief	This class provides the methods to manage the content information.
 * @since	1.0
 *
 * The %ContentInfo class is an abstract class derived from four base classes: ImageContentInfo, AudioContentInfo, VideoContentInfo, and OtherContentInfo.
 *
 * It includes various attributes such as the user's tags and the metadata that is extracted from a physical file. @n
 * When a user creates content, its content information is created as a new pair. @n
 * When a user deletes content, its content information is deleted from the content database. @n
 * The %ContentInfo class provides methods to get or to set the specific content information.
 * 
 * For more information on the different types of content information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ContentInfo class.
 *
 * @code
 * result
 * MyClass::TestContentInfo(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		Osp::Base::String inputPath(L"/Media/Images/Flower1.jpg");
 *		ImageContentInfo imageContentInfo;
 *		r = imageContentInfo.Construct(&inputPath);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		contentId = contentManager.CreateContent(imageContentInfo);
 *		TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		Osp::Base::String contentPath = imageContentInfo.GetContentPath();
 *		int width = imageContentInfo.GetWidth();
 *
 *		return r;
 * }
 * @endcode
 */
class _EXPORT_CONTENT_ ContentInfo : public Osp::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~ContentInfo(void);

	/**
	 * Initializes this instance of %ContentInfo with the specified parameters.
	 *
	 * @deprecated  This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	 * 				Instead of using this method, use Construct(const Osp::Base::String* pContentPath) of the Image/Audio/Video/OtherContentInfo class. @n
	 * 				To set the coordinates in the %ContentInfo instance, use SetCoordinates(const Osp::Locations::Coordinates& coordinates) of the %ContentInfo class.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	contentPath			The content path
	 * @param[in]	thumbnailPath		The thumbnail path
	 * @param[in]	setGps				Set to @c true to save the device's last known coordinates in the %ContentInfo instance, @n
     *									else @c false
	 */
	virtual result Construct(const Osp::Base::String& contentPath, const Osp::Base::String& thumbnailPath = L"", bool setGps = false) = 0;

	/**
	 * Gets the content ID.
	 *
	 * @since		1.0
	 * @return		The content ID
	 */
	ContentId GetContentId(void) const;

	/**
	 * Gets the content type.
	 *
	 * @since		1.0
	 * @return		The content type
	*/
	ContentType GetContentType(void) const;

	/**
     * Gets the date and time of the created content.
	 *
	 * @since		1.0
	 * @return		The content's creation time (GMT)
	 */
	Osp::Base::DateTime GetDateTime(void) const;

	/**
	 * Gets the file size of the content.
	 *
	 * @since		1.0
	 * @return		The file size of the content
	 */
	unsigned long GetContentSize(void) const;

	/**
	 * Gets the content name.
	 *
	 * @since		1.0
	 * @return		The content name
	 */
	Osp::Base::String GetContentName(void) const;

	/**
	 * Gets the file path of the content.
	 *
	 * @since		1.0
	 * @return		The file path of the content
	 */
	Osp::Base::String GetContentPath(void) const;

	/**
	 * Gets the coordinates of the location.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 * 					For more information, see issues in version @ref CompContentInfoGetCoordinatesPage "1.1", @ref CompContentInfoGetCoordinatesPage "1.2", and @ref CompContentInfoGetCoordinates2Page "2.0".
	 *
	 * @return		A reference to the coordinates
	 */
	const Osp::Locations::Coordinates& GetCoordinates(void) const;

	/**
	* @page		CompContentInfoGetCoordinatesPage Compatibility for GetCoordinates(void)
	* @section	CompContentInfoGetCoordinatesPageIssueSection Issues
	*           Implementation of this method in bada API versions 1.1 and 1.2 has the following issue:
	* 			-# Privacy can be infringed. @n
    *           The privilege level and group in bada API versions 1.1 and 1.2 are mentioned below: @n
	*			@b Privilege @b level: @b NORMAL @n
	*			@b Privilege @b group: @b LOCATION @n
	*			For privilege level and group check, the E_SUCCESS and E_PRIVILEGE_DENIED exceptions are added to ensure privacy. @n
	*			The specific error code can be accessed using the GetLastResult() method.
	*/

	/**
	* @page		CompContentInfoGetCoordinates2Page Compatibility for GetCoordinates(void)
	* @section	CompContentInfoGetCoordinates2PageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issues:
	* 			-# The altitude, latitude, and longitude values are mandatory. @n
	* 			   Therefore, if any one of the three is incorrect, an empty instance of Osp::Locations::Coordinates is returned.
	*			-# In bada API versions 1.1 and 1.2, privacy infringement is checked unnecessarily.
	*
	* @section	CompContentInfoGetCoordinates2PageSolutionSection Resolutions
	*			The issues mentioned above are resolved in bada API version 2.0 as follows:
	*			-# The latitude and longitude values are mandatory, whereas the altitude value is optional. @n
	*			   If the altitude value is not provided, the coordinates are created as per the latitude and longitude values.
	*			-# Privacy infringement is no longer checked.
	*/

	/**
	 * Sets the coordinates of the location.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	coordinates			The user-defined coordinates
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 */
	result SetCoordinates(const Osp::Locations::Coordinates& coordinates);

	/**
	 * Sets the location tag.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	locationTag			The new location tag
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 */
	result SetLocationTag(const Osp::Base::String& locationTag);

	/**
	 * Gets the location tag.
	 *
	 * @since		1.0
	 * @return		The location tag
	 */
	Osp::Base::String GetLocationTag(void) const;

	/**
	 * Sets the rating.
	 *
	 * @since		1.0
	 * @return		An error code
 	 * @param[in]	rating				The new rating
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 */
	result SetRating(const Osp::Base::String& rating);

	/**
	 * Gets the rating.
	 *
	 * @since		1.0
	 * @return		The rating
	 */
	Osp::Base::String GetRating(void) const;

	/**
	 * Sets the category.
	 *
	 * @since		1.0
	 * @return		An error code
 	 * @param[in]	category			The new category
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 128 characters.
	 * @remarks		This field can contain a maximum of 45 characters since bada 3.0.
	 */
	result SetCategory(const Osp::Base::String& category);

	/**
	 * Gets the category.
	 *
	 * @since		1.0
	 * @return		The category
	 */
	Osp::Base::String GetCategory(void) const;

	/**
	 * Sets the description.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	description			The new description
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 1000 characters.
	 * @remarks		This field can contain a maximum of 140 characters since bada 3.0.
	 */
	result SetDescription(const Osp::Base::String& description);

	/**
	 * Gets the description.
	 *
	 * @since		1.0
	 * @return		The description
	 */
	Osp::Base::String GetDescription(void) const;

	/**
	 * Gets the thumbnail image.
	 *
	 * @since		1.0
 	 * @return		A pointer to the thumbnail image
 	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_DATA_NOT_FOUND	The thumbnail image does not exist.
 	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
 	 * @remarks		This method returns the thumbnail image that is resized to 80x60 pixels.
 	 * 				This method supports an instance of ImageContentInfo and AudioContentInfo class. @n
 	 * 				The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	* Sets the thumbnail path.
	*
	* @deprecated   This method is deprecated as there is a problem in managing the user-defined thumbnail.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	srcImagePath		The new thumbnail path
	* @exception	E_SUCCESS  			The method is successful.
	* @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	* @remarks		The thumbnail path should start with '/Home', '/Media' or '/Storagecard/Media'. @n
	* 				The permitted format for a thumbnail image is Bitmap (bmp).
	*/
	result MakeThumbnail(const Osp::Base::String& srcImagePath);

	/**
	 * Checks whether the content is DRM protected.
	 *
	 * @since		1.0
	 * @return		@c true if this content has DRM, @n
	 *				else @c false
	 */
	bool IsDrmProtected(void) const;

	/**
	 * Gets the keyword.
	 *
	 * @since		1.0
	 * @return		The keyword
	 */
	Osp::Base::String GetKeyword(void) const;

	/**
	 * Sets the content name.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	contentName			The new content name
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 236 characters.
	 * @remarks		This field can contain a maximum of 45 characters since bada 3.0.
	 */
	result SetContentName(const Osp::Base::String& contentName);

	/**
	 * Sets the keyword.
	 *
	 * @since		1.0
	 * @return		An error code
 	 * @param[in]	keyword				The new keyword
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 128 characters.
	 * @remarks		This field can contain a maximum of 45 characters since bada 3.0.
	 */
	result SetKeyword(const Osp::Base::String& keyword);

	/**
	 * Sets the author.
	 *
	 * @since		1.0
	 * @return		An error code
 	 * @param[in]	author				The new author
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 */
	result SetAuthor(const Osp::Base::String& author);

	/**
	 * Gets the author.
	 *
	 * @since		1.0
	 * @return		The author
	 */
	Osp::Base::String GetAuthor(void) const;

	/**
	 * Sets the provider.
	 *
	 * @since		1.0
	 * @return		An error code
 	 * @param[in]	provider			The new content provider
	 * @exception	E_SUCCESS  			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The length of the input data exceeds the maximum limit of 45 characters.
	 */
	result SetProvider(const Osp::Base::String& provider);

	/**
	 * Gets the provider.
	 *
	 * @since		1.0
	 * @return		The content provider
	 */
	Osp::Base::String GetProvider(void) const;

	/**
	* Gets the media format.
	*
	* @since		1.0
	* @return		The media format
	*/
	Osp::Base::String GetMediaFormat(void) const;

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Copies the remote content information to the content information.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	remoteContentinfo	An instance of RemoteContentInfo
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Copy(const RemoteContentInfo& remoteContentinfo);

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	ContentInfo(void);

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Sets the IContentInfo instance.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	pIContnetInfo		The pointer of the %IContentInfo
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result SetInstance(const IContentInfo* pIContnetInfo);

private:
	IContentInfo* __pIContentInfo;
	mutable Osp::Locations::Coordinates __coordinates;

	ContentInfo(IContentInfo* pInfo);
	IContentInfo* GetInstance(void);
	int GetThumbnailSize(void) const;
	Osp::Base::String GetThumbnailPath(void) const;

	friend class ContentManager;

	friend class ContentInfoEx;
	class ContentInfoEx* __pContentInfoEx;
};	// class ContentInfo

}; };	// Osp::Content

#endif	// _FCNT_CONTENT_INFO_H_
