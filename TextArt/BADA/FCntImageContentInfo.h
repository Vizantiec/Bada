/* $Change: 1142016 $ */
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
* @file			FCntImageContentInfo.h
* @brief		This is the header file for the %ImageContentInfo class.
*
* This header file contains the declarations of the %ImageContentInfo class.
*/

#ifndef _FCNT_IMAGE_CONTENT_INFO_H_
#define _FCNT_IMAGE_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FCntContentInfo.h>

namespace Osp { namespace Content {

class ImageContentInfoEx;

/**
* @class	ImageContentInfo
* @brief	This class provides the methods to access the image content information.
* @since	1.0
*
* The %ImageContentInfo class provides the methods to access the image content information.
* Before the image content information can be retrieved, ContentManager must be used to create the content.
*
* For more information on the different types of content information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
*
* The following example demonstrates how to use the %ImageContentInfo class.
*
* @code
* result
* MyClass::TestImageContentInfo(void)
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
*		// Contents information
*		Osp::Base::String contentPath = imageContentInfo.GetContentPath();
*
*		// Metadata
*		Osp::Base::String title = imageContentInfo.GetTitle();
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ ImageContentInfo
	: public Osp::Content::ContentInfo
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	ImageContentInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~ImageContentInfo(void);

	/**
	* Initializes this instance of %ImageContentInfo with the specified parameters.
	*
	* @deprecated   This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	* 				Instead of using this method, use Construct(const Osp::Base::String* pContentPath).
	* 				To set the coordinates in the ContentInfo instance, use SetCoordinates(const Osp::Locations::Coordinates& coordinates) of the %ContentInfo class.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentPath				The content path
	* @param[in]	thumbnailPath			The thumbnail path
	* @param[in]	setGps					Set to @c true to save the device's last known coordinates in the %ContentInfo instance, @n
    *										else @c false @n
	*										The coordinate information may be incorrect if it is outdated or has never been updated.
	* 										To update the coordinate information or to get the exact value,
	* 										use RequestLocationUpdates() of the Osp::Locations::LocationProvider class, before calling this method.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid, or
	* 			                            the length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_LOCATION				The location provider is currently out of service.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'. @n
	* 				The thumbnail path should start with '/Home', '/Media', or '/Storagecard/Media'. @n
	* 				The permitted format for a thumbnail image is Bitmap (bmp).
	*/
	result Construct(const Osp::Base::String& contentPath, const Osp::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	* Initializes this instance of %ImageContentInfo with the specified parameter.
	*
	* @since		2.0
	* @return		An error code
	* @param[in]	pContentPath			The content path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_INVALID_ARG			The specified content path is invalid or its length exceeds the maximum limit of 256 characters.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_SYSTEM				An internal error has occurred.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'. @n
	*				If the content has coordinates as metadata, they are automatically set.
	* 				If the specified @c pContentPath is @c null, use CreateContent() of the ContentManager class. @n
	* 				CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null) @n
	* 				CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null)
	*/
	result Construct(const Osp::Base::String* pContentPath);

	/**
	* Gets the width of the image.
	*
	* @since		1.0
	* @return		The width of the image
	*/
	int GetWidth(void) const;

	/**
	* Gets the height of the image.
	*
	* @since		1.0
	* @return		The height of the image
	*/
	int GetHeight(void) const;

	/**
	* Gets the title of the image.
	*
	* @since		1.0
	* @return		The title of the image
	*/
	Osp::Base::String GetTitle(void) const;

private:
	void* __pImageMeta;
	IContentInfo* __pIContentInfo;

	result SetContentInfo(const IContentInfo* pIContentInfo);
	int	GetMetadata(int value) const;

	friend class ContentManager;
	friend class ContentSearch;

	friend class ImageContentInfoEx;
	class ImageContentInfoEx* __pImageContentInfoEx;
};	// class ImageContentInfo

}; };	// Osp::Content

#endif	// _FCNT_IMAGE_CONTENT_INFO_H_
