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
* @file			FCntImageMetadata.h 
* @brief		This is the header file for the %ImageMetadata class.
*
* This header file contains the declarations of the %ImageMetadata class.
*/

#ifndef _FCNT_IMAGE_METADATA_H_
#define _FCNT_IMAGE_METADATA_H_

#include <FCntConstants.h>
#include <FMediaImage.h>

namespace Osp { namespace Content {

class ImageMetadataEx;
struct ImageMeta;

/**
* @class	ImageMetadata
* @brief	This class provides the methods to access the image metadata.
* @since	1.0
*
* The %ImageMetadata class provides the methods to access the image metadata that contains the image content-specific attributes.
*
* The following example demonstrates how to use the %ImageMetadata class.
*
* @code
* result
* MyClass::TestImageMetadata(void) 
* {
* 		result r = E_SUCCESS;
*
*		ImageMetadata* pImgMeta = ContentManagerUtil::GetImageMetaN(L"/Media/Images/full_meta.jpg");
*		TryReturn(pImgMeta != null, GetLastResult(), "ContentManagerUtil::GetImageMetaN failed.");
*
*		// Width
*		int width = pImgMeta->GetWidth();
*
*		// Height 
*		int height = pImgMeta->GetHeight();
*
*		// Camera
*		Osp::Base::String camera = pImgMeta->GetCameraManufacturer();
*
*		// Model
*		Osp::Base::String model = pImgMeta->GetCameraModel();
*
*		// Software
*		Osp::Base::String software = pImgMeta->GetSoftware();
*
*		// Date time
*		Osp::Base::String dateTime = pImgMeta->GetDateTime();
*
*		// Thumbnail
*		Osp::Media::Image image;
*		r = image.Construct();
*		if (IsFailed(r))
*		{
*			delete pImgMeta;
*			return r;
*		}
*
*		Osp::Graphics::Bitmap* pBitmap = pImgMeta->GetThumbnailN();
*		if (pBitmap == null)
*		{
*			delete pImgMeta;
*			return GetLastResult();
*		}
*
*		r = image.EncodeToFile(*pBitmap, Osp::Media::IMG_FORMAT_BMP, L"/Media/Images/image.bmp", false);
*		if (IsFailed(r))
*		{
*			delete pImgMeta;
*			delete pBitmap;
*			return r;
*		}
*
*		delete pImgMeta;
*		delete pBitmap;
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ ImageMetadata : public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	ImageMetadata(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~ImageMetadata(void);

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
	* Gets the name of the camera's manufacturer.
	*
	* @since		1.0
	* @return		The name of the camera's manufacturer
	*/
	Osp::Base::String GetCameraManufacturer(void) const;

	/**
	* Gets the model of the camera.
	*
	* @since		1.0
	* @return		The model of the camera
	*/
	Osp::Base::String GetCameraModel(void) const;

	/**
	* Gets the version of either the software or the firmware of the camera or the image input device 
	* used to generate the image.
	*
	* @since		1.0
	* @return		The version of either the software or the firmware of the camera or the image input device 
	*				used to generate the image
	*/
	Osp::Base::String GetSoftware(void) const;

	/**
	* Gets the date and time of the created content.
	*
	* @since		1.0
	* @return		The date and time of the created content
	*/
	Osp::Base::String GetDateTime(void) const;      

	/**
	* Gets the latitude of the image.
    *
    * @since		1.0
    * @compatibility	This method has compatibility issues with different bada API versions. @n
    *					For more information, see issues in versions @ref CompImageMetadataGetLatitudePage "1.1", @ref CompImageMetadataGetLatitudePage "1.2" and @ref CompImageMetadataGetLatitude2Page "2.0".
    *
    * @return		The latitude of the image
    * @remarks		If there is no latitude in the image, @c -200.0 will be returned.
    */
	double GetLatitude(void) const;

	/**
	* @page		CompImageMetadataGetLatitudePage Compatibility for GetLatitude(void)
	* @section	CompImageMetadataGetLatitudePageIssueSection Issues
	*           Implementation of this method in bada API versions 1.1 and 1.2 has the following issue:
	* 			-# Privacy can be infringed. @n 
    *           The privilege level and group in bada API versions 1.1 and 1.2 are mentioned below: @n
	*			@b Privilege @b level: @b NORMAL @n
	*			@b Privilege @b group: @b LOCATION @n
	*			For privilege level and group check, the E_SUCCESS and E_PRIVILEGE_DENIED exceptions are added to ensure privacy. @n
	*			The specific error code can be accessed using the GetLastResult() method.
	*/

	/**
	* @page		CompImageMetadataGetLatitude2Page Compatibility for GetLatitude(void)
	* @section	CompImageMetadataGetLatitude2PageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue:
	*			-# The bada API versions 1.1 and 1.2 unnecessarily check whether the privacy is infringed.
	*
	* @section	CompContentInfoGetCoordinates2PageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0 as follows:
	*			-# Privacy infringement is no longer checked.
	*/

	/**
    * Gets the longitude of the image.
    *
    * @since		1.0
    * @compatibility	This method has compatibility issues with different bada API versions. @n
    * 					For more information, see issues in versions @ref CompImageMetadataGetLongitudePage "1.1", @ref CompImageMetadataGetLongitudePage "1.2", and @ref CompImageMetadataGetLongitude2Page "2.0".
    *
    * @return		The longitude of the image
    * @remarks		If there is no longitude in the image, @c -200.0 will be returned.
    */
	double GetLongitude(void) const;

	/**
	* @page		CompImageMetadataGetLongitudePage Compatibility for GetLongitude(void)
	* @section	CompImageMetadataGetLongitudePageIssueSection Issues
	*           Implementation of this method in bada API versions 1.1 and 1.2 has the following issue:
	* 			-# Privacy can be infringed. @n
    *           The privilege level and group in bada API versions 1.1 and 1.2 are mentioned below: @n
	*			@b Privilege @b level: @b NORMAL @n
	*			@b Privilege @b group: @b LOCATION @n
	*			For privilege level and group check, the E_SUCCESS and E_PRIVILEGE_DENIED exceptions are added to ensure privacy. @n
    * 			The specific error code can be accessed using the GetLastResult() method.
	*/

	/**
	* @page		CompImageMetadataGetLongitude2Page Compatibility for GetLongitude(void)
	* @section	CompImageMetadataGetLongitude2PageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue:
	*			-# The bada API versions 1.1 and 1.2 unnecessarily check whether the privacy is infringed.
	*
	* @section	CompContentInfoGetCoordinates2PageSolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0 as follows:
	*			-# Privacy infringement is no longer checked.
	*/

	/**
	* Gets the orientation of the picture.
	*
	* @since		1.0
	* @return		The orientation of the picture
	*/
	int GetOrientation(void) const;

	/**
	* Gets the white balance of the image.
	*
	* @since		1.0
	* @return		The white balance of the image
	*/
	Osp::Base::String GetWhiteBalance(void) const;

	/**
	* Gets the thumbnail image.
	*
	* @since		1.0
	* @return		A pointer to the thumbnail image
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND	The thumbnail image does not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		This method returns the thumbnail image that is resized to 80x60 pixels. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Graphics::Bitmap* GetThumbnailN(void) const;

private:
	int		__width;
	int		__height;
	int		__orientation;
	bool	__flash;
	double	__exposureTime;
	double	__latitude;
	double	__longitude;
	Osp::Base::String	__aperture;
	Osp::Base::String	__manufacturer;
	Osp::Base::String	__model;
	Osp::Base::String	__software;
	Osp::Base::String	__dateTime;
	Osp::Base::String	__whiteBalance;
	Osp::Base::String	__meteringMode;
	Osp::Base::String	__contentPath;

	class ImageMetadataEx* __pImageMetadataEx;
	class ImageMetadataEx* GetImageMetadataEx(void);
	bool AssignValues(const Osp::Base::String& inputPath, Osp::Content::ImageMeta* pImageMeta);
	//bool AssignValues(const Osp::Base::ByteBuffer& byteBuffer, Osp::Content::ImageMeta* pImageMeta);

	friend class ContentManagerUtil;
	friend class ImageMetadataEx;

};	// class ImageMetadata

}; }; // Osp::Content

#endif// _FCNT_IMAGE_METADATA_H_
