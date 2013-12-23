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
* @file			FCntVideoContentInfo.h
* @brief		This is the header file for the %VideoContentInfo class.
*
* This header file contains the declarations of the %VideoContentInfo class.
*/

#ifndef _FCNT_VIDEO_CONTENT_INFO_H_
#define _FCNT_VIDEO_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FCntContentInfo.h>

namespace Osp { namespace Content {

class VideoContentInfoEx;

/**
* @class	VideoContentInfo
* @brief	This class provides the methods to access the video content information.
* @since	1.0
* 
* The %VideoContentInfo class provides the methods to access the video content information. 
* Before retrieving the video content information, the ContentManager class must be used to create the content. 
*
* For more information on the different types of content information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
*
* The following example demonstrates how to use the %VideoContentInfo class.
*
* @code
* result
* MyClass::TestVideoContentInfo(void)
* {
*		result r = E_SUCCESS;
*
*		ContentId contentId;
*		ContentManager contentManager;
*		r = contentManager.Construct();
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		Osp::Base::String inputPath(L"/Media/Videos/Flower.wmv");
*		VideoContentInfo videoContentInfo;
*		r = videoContentInfo.Construct(&inputPath);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		contentId = contentManager.CreateContent(videoContentInfo);
*		TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed.");
*
*		// Content information
*		Osp::Base::String contentPath	= videoContentInfo.GetContentPath();
*
*		// Metadata
*		Osp::Base::String genre		= videoContentInfo.GetGenre();
*		Osp::Base::String artist	= videoContentInfo.GetArtist();
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ VideoContentInfo
	: public Osp::Content::ContentInfo
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	VideoContentInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~VideoContentInfo (void);

	/**
	* Initializes this instance of %VideoContentInfo with the specified parameters.
	*
	* @deprecated   This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	* 				Instead of using this method, use Construct(const Osp::Base::String* pContentPath). @n
	* 				To set the coordinates in the ContentInfo instance, use SetCoordinates(const Osp::Locations::Coordinates& coordinates) of the ContentInfo class.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentPath				The content path
	* @param[in]	thumbnailPath			The thumbnail path
	* @param[in]	setGps					Set to @c true to save the device's last known coordinates in the ContentInfo instance, @n
    *										else @c false @n
	*										The coordinate information may be incorrect if it is outdated or has never been updated. @n
	* 										To update the coordinate information or to get the exact value,
	* 										use RequestLocationUpdates() of the Osp::Locations::LocationProvider class before calling this method.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid or
	* 										the length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_LOCATION				The location provider is currently out of service.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'.
	* 				The thumbnail path should start with '/Home', '/Media', or '/Storagecard/Media'.
	* 				The permitted format for a thumbnail image is bitmap (bmp).
	*/
	result Construct(const Osp::Base::String& contentPath, const Osp::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	* Initializes this instance of %VideoContentInfo with the specified parameter.
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
	* 				If @c pContentPath is @c null, use CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null)
    *             	or CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null) of the ContentManager class. @n
	*/
	result Construct(const Osp::Base::String* pContentPath);

	/**
	* Gets the genre.
	*
	* @since		1.0
	* @return		The genre
	* @remarks		If the value is an empty string, the method returns @c Unknown.
	*/
	Osp::Base::String GetGenre(void) const;

	/**
	* Gets the artist.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompVideoContentInfoGetArtistPage "here".
	*
	* @return		The artist
	* @remarks		If the value is an empty string, the method returns @c Unknown.
	*/
	Osp::Base::String GetArtist(void) const;

	/**
	* @page		CompVideoContentInfoGetArtistPage Compatibility for GetArtist(void)
	* @section	CompVideoContentInfoGetArtistPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 			-# The value returned for wmv and asf is an author instead of an artist.
	*
	* @section	CompVideoContentInfoGetArtistPageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/

	/**
	* Gets the bit rate.
	*
	* @deprecated	This method is deprecated because a new method has been added. @n
    *				Instead of using this method, use GetAudioBitrate(void) or GetVideoBitrate(void).
    *
	* @since		1.0
	* @return		The bit rate in kilo bits per second (kbps)
	* @remarks		There are two kinds of bit rates in a video file: audio and video. @n
	*				The return value is the bit rate for the audio.
	*/
	int GetBitrate(void) const;

	/**
	* Gets the audio bit rate.
	*
	* @since     2.0
	* @return    The audio bit rate in bits per second (bps)
	*/
	int GetAudioBitrate(void) const;

	/**
	* Gets the video bit rate.
	*
	* @since     2.0
	* @return    The video bit rate in bits per second (bps)
	*/
	int GetVideoBitrate(void) const;

	/**
	* Gets the frame rate.
	*
	* @since		1.0
	* @return		The frame rate 
	*/
	int GetFramerate(void) const;

	/**
	* Gets the width.
	*
	* @since		1.0
	* @return		The width 
	*/
	int GetWidth(void) const;

	/**
	* Gets the height.
	*
	* @since		1.0
	* @return		The height 
	*/
	int GetHeight(void) const;

	/**
	* Gets the title.
	*
	* @since		1.0
	* @return		The title
	* @remarks		If the value is an empty string, the method returns @c Unknown.
	*/
	Osp::Base::String GetTitle(void) const;

private:
	void* __pVideoMeta;
	IContentInfo* __pIContentInfo;

	result SetContentInfo(const IContentInfo* pIContentInfo);
	int	GetMetadata(int value) const;

	friend class ContentManager;
	friend class ContentSearch;

	friend class VideoContentInfoEx;
	class VideoContentInfoEx* __pVideoContentInfoEx;

};	// class VideoContentInfo

}; };	// Osp::Content

#endif	// _FCNT_VIDEO_CONTENT_INFO_H_
