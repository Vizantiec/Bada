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
* @file			FCntAudioContentInfo.h
* @brief		This is the header file for the %AudioContentInfo class.
*
* This header file contains the declarations of the %AudioContentInfo class.
*/

#ifndef _FCNT_AUDIO_CONTENT_INFO_H_
#define _FCNT_AUDIO_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FCntContentInfo.h>

namespace Osp { namespace Content {

class AudioContentInfoEx;

/**
* @class	AudioContentInfo
* @brief	This class provides the methods to access the audio content information.
* @since	1.0
*
* The %AudioContentInfo class provides the methods to access the audio content information.
* Before retrieving the audio content information, ContentManager must be used to create the content.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_attributes.htm#media">Device Content Attributes</a>.
*
* The following example demonstrates how to use the %AudioContentInfo class.
*
* @code
* result
* MyClass::TestAudioContentInfo(void)
* {
*		result r = E_SUCCESS;
*
*		ContentId contentId;
*		ContentManager contentManager;
*		r = contentManager.Construct();
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		Osp::Base::String inputPath(L"/Media/Sounds/Flower.wma");
*		AudioContentInfo audioContentInfo;
*		r = audioContentInfo.Construct(&inputPath);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		contentId = contentManager.CreateContent(audioContentInfo);
*		TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed.");
*
*		// Content information
*		Osp::Base::String contentPath = audioContentInfo.GetContentPath();
*
*		// Metadata
*		Osp::Base::String artist	= audioContentInfo.GetArtist();
*		Osp::Base::String genre		= audioContentInfo.GetGenre();
*		Osp::Base::String composer	= audioContentInfo.GetComposer();
*		Osp::Base::String albumName	= audioContentInfo.GetAlbumName();
*		int releaseyear				= audioContentInfo.GetReleaseYear();
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ AudioContentInfo
	: public Osp::Content::ContentInfo
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	AudioContentInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~AudioContentInfo(void);

	/**
	* Initializes this instance of %AudioContentInfo with the specified parameters.
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
	* @exception	E_INVALID_ARG			A specified input parameter is invalid, or the length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_LOCATION				The location provider is currently out of service.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'. @n
	* 				The thumbnail path should start with '/Home', '/Media', or '/Storagecard/Media'. @n
	* 				The permitted format for a thumbnail image is Bitmap (bmp).
	*/
	result Construct(const Osp::Base::String& contentPath, const Osp::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	* Initializes this instance of %AudioContentInfo with the specified parameter.
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
	* 				If pContentPath is @c null, use CreateContent() of the ContentManager class. @n
	* 				CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null) @n
	* 				CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null)
	*/
	result Construct(const Osp::Base::String* pContentPath);

	/**
	* Gets the genre information of the audio file.
	*
	* @since		1.0
	* @return		The genre information of the audio file
	* @remarks		If the value is an empty string, the method returns "Unknown" for MP3, AAC, WMA, M4A, and 3GA files. @n
	* 				For other files, it returns an empty string.
	*/
	Osp::Base::String GetGenre(void) const;

	/**
	* Gets the artist information of the audio file.
	*
	* @since		1.0
	* @return		The artist information of the audio file
	* @remarks		If the value is an empty string, the method returns "Unknown" for MP3, AAC, WMA, M4A, and 3GA files. @n
	* 				For other files, it returns an empty string.
	*/
	Osp::Base::String GetArtist(void) const;

	/**
	* Gets the composer information of the audio file.
	*
	* @since		1.0
	* @return		The composer information of the audio file
	* @remarks		If the value is an empty string, the method returns "Unknown" for MP3, AAC, WMA, M4A, and 3GA files. @n
	* 				For other files, it returns an empty string.
	*/
	Osp::Base::String GetComposer(void) const;

	/**
	* Gets the album name of the audio file.
	*
	* @since		1.0
	* @return		The album name of the audio file
	* @remarks		If the value is an empty string, the method returns "Unknown" for MP3, AAC, WMA, M4A, and 3GA files. @n
	* 				For other files, it returns an empty string.
	*/
	Osp::Base::String GetAlbumName(void) const;

	/**
	* Gets the release year information of the audio file.
	*
	* @since		1.0
	* @return		The release year information of the audio file
	*/
	int GetReleaseYear(void) const;

	/**
	* Gets the bit rate information of the audio file.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompAudioContentInfoGetBitratePage "here".
	*
	* @return		The bit rate in bits per second (bps)
	*/
	int GetBitrate(void) const;

	/**
	* @page		CompAudioContentInfoGetBitratePage Compatibility for GetBitrate(void)
	* @section	CompAudioContentInfoGetBitratePageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue:
	* 			-# The unit of the audio bit rate is inconsistent. @n
	* 			 For example, the audio bit rate value returned for MP3, WAV, and WMA files is in kilo bits per second (kbps). @n
	*            However, the value returned for all the other audio files is in bps.
    *
	* @section	CompAudioContentInfoGetBitratePagePageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 2.0 as follows:
	* 			-# The audio bit rate value returned for all the audio files is in bps.
	*/

	/**
	* Gets the title of the audio file.
	*
	* @since		1.0
	* @return		The title of the audio
	* @remarks		If the value is an empty string, the method returns "Unknown" for MP3, AAC, WMA, M4A, and 3GA files. @n
	* 				For other files, it returns an empty string.
	*/
	Osp::Base::String GetTitle(void) const;

private:
	void* __pAudioMeta;
	IContentInfo* __pIContentInfo;

	result SetContentInfo(const IContentInfo* pIContentInfo);
	int	GetMetadata(int value) const;

	friend class ContentManager;
	friend class ContentSearch;

	friend class AudioContentInfoEx;
	class AudioContentInfoEx* __pAudioContentInfoEx;

};	// class AudioContentInfo

}; };	// Osp::Content

#endif	// _FCNT_AUDIO_CONTENT_INFO_H_
