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
* @file			FCntAudioMetadata.h
* @brief		This is the header file for the %AudioMetadata class.
*
* This header file contains the declarations of the %AudioMetadata class.
*/

#ifndef _FCNT_AUDIO_METADATA_H_
#define _FCNT_AUDIO_METADATA_H_

#include <FCntConstants.h>
#include <FMediaImage.h>

namespace Osp { namespace Content {

class AudioMetadataEx;
struct AudioMeta;

/**
* @class	AudioMetadata
* @brief	This class provides the methods to access the audio metadata.
* @since	1.0
*
* The %AudioMetadata class provides the methods to access the audio metadata, which contains audio content-specific attributes.
*
* The following example demonstrates how to use the %AudioMetadata class.
*
* @code
* result
* MyClass::TestAudioMetadata(void) 
* {
* 		result r = E_SUCCESS;
*
*		AudioMetadata* pAudioMeta = ContentManagerUtil::GetAudioMetaN(L"/Media/Sounds/hot.mp3");
*		TryReturn(pAudioMeta != null, GetLastResult(), "ContentManagerUtil::GetAudioMetaN failed.");
*
*		// Title
*		Osp::Base::String title = pAudioMeta->GetTitle();
*
*		// Frequency
*		int frequency = pAudioMeta->GetFrequency();
*
*		// Artist
*		Osp::Base::String artist = pAudioMeta->GetArtist();
*
*		// Album name
*		Osp::Base::String album = pAudioMeta->GetAlbumName();
*
*		// Duration
*		long duration = pAudioMeta->GetDuration();
*
*		// Year
*		int year = pAudioMeta->GetYear();
*
*		// Thumbnail
*		Osp::Media::Image image;
*		r = image.Construct();
*		if (IsFailed(r))
*		{
*			delete pAudioMeta;
*			return r;
*		}
*
*		Osp::Graphics::Bitmap* pBitmap = pAudioMeta->GetThumbnailN();
*		if (pBitmap == null)
*		{
*			delete pAudioMeta;
*			return GetLastResult();
*		}
*
*		r = image.EncodeToFile(*pBitmap, Osp::Media::IMG_FORMAT_BMP, L"/Media/Images/audio.bmp", false);
*		if (IsFailed(r))
*		{
*			delete pAudioMeta;
*			delete pBitmap;
*			return r;
*		}
*
*		delete pAudioMeta;
*		delete pBitmap;
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ AudioMetadata : public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	AudioMetadata(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~AudioMetadata(void);

	/**
	* Gets the title of the audio file.
	*
	* @since		1.0
	* @return		The title of the audio file
	*/
	Osp::Base::String GetTitle(void) const;

	/**
	* Gets the bit rate of the audio file.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompAudioMetadataGetBitratePage "here".
	*
	* @return		The audio bit rate in bits per second (bps)
	*/
	int GetBitrate(void) const;

	/**
	* @page		CompAudioMetadataGetBitratePage Compatibility for GetBitrate(void)
	* @section	CompAudioMetadataGetBitratePageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue:
	* 			-# The unit of the audio bit rate is inconsistent. @n
	*			 For example, the audio bit rate value returned for MP3, WAV, and WMA files is in kilo bits per second (kbps). @n
	*            However, the value returned for all the other audio files is in bits per second (bps).
	*
	* @section	CompAudioMetadataGetBitratePageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 2.0 as follows:
	* 			-# The audio bit rate value returned for all the audio files is in bps.
	*/

	/**
	* Gets the frequency of the audio file.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompAudioMetadataGetFrequencyPage "here".
	*
	* @return		The frequency in hertz (hz)
	*/
	int GetFrequency(void) const;

	/**
	* @page		CompAudioMetadataGetFrequencyPage Compatibility for GetFrequency(void)
	* @section	CompAudioMetadataGetFrequencyPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 2.0 has the following issue:
	* 			-# The unit of the frequency is inconsistent. @n
	*			For example, the frequency value returned for WAV files is in kilo hertz (khz). @n
	*           However, the value returned for all the other files is in hertz (hz).
	*
	* @section	CompAudioMetadataGetFrequencyPageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 2.0 as follows:
	* 			-# The frequency value returned for all the files is in hz.
	*/

	/**
	* Gets the artist information of the audio file.
	*
	* @since		1.0
	* @return		The artist information of the audio file
	*/
	Osp::Base::String GetArtist(void) const;

	/**
	* Gets the album name of the audio file.
	*
	* @since		1.0
	* @return		The album name of the audio file
	*/
	Osp::Base::String GetAlbumName(void) const;

	/**
	* Gets the comment of the audio file.
	*
	* @since		1.0
	* @return		The comment of the audio file
	*/
	Osp::Base::String GetComment(void) const;

	/**
	* Gets the track number of the audio file.
	*
	* @since		1.0
	* @return		The track number of the audio file
	*/
	int GetTrack(void) const;

	/**
	* Gets the genre information of the audio file.
	*
	* @since		1.0
	* @return		The genre information of the audio file
	*/
	Osp::Base::String GetGenre(void) const;

	/**
	* Gets the composer information of the audio file.
	*
	* @since		1.0
	* @return		The composer information of the audio file
	*/
	Osp::Base::String GetComposer(void) const;

	/**
	* Gets the copyright information of the audio file.
	*
	* @since		1.0
	* @return		The copyright information of the audio file
	*/
	Osp::Base::String GetCopyright(void) const;

	/**
	* Gets the duration of the audio file.
	*
	* @since		1.0
	* @return		The duration in milliseconds
	*/
	long GetDuration(void) const;

	/**
	* Gets the year information of the audio file.
	*
	* @since		1.0
	* @return		The year information of the audio file
	*/
	int GetYear(void) const;

	/**
	* Gets the track information of the audio file.
	*
	* @since		2.0
	* @return		The track number/position in set
	* @remarks		This method returns track information that is embedded in the content metadata. @n
	*				The format returned can be like "4/9" or "4" (in case the position is not available).
	*/
	Osp::Base::String GetTrackInfo(void) const;

	/**
	* Gets the recording date of the audio file.
	*
	* @since		2.0
	* @return		The recording date of the audio file
	*/
	Osp::Base::String GetRecordingDate(void) const;

	/**
	* Gets the number of channels of the audio file.
	*
	* @since		2.0
	* @return		The number of channels of the audio file
	* @remarks		A monophonic stream has one channel and a stereophonic stream has two channels. @n
	*				Valid values are either @c 1 or @c 2.
	*/
	int GetChannelCount(void) const;

	/**
	* Gets the thumbnail of the audio file.
	*
	* @since		1.0
	* @return		A pointer to the thumbnail image
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND	The thumbnail image does not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		This method returns the thumbnail image that is resized to 80x60 pixels. @n
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	* Gets the album art of the audio file.
	*
	* @since		2.0
	* @return		A pointer to the album art
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND	The album art does not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		GetThumbnailN() returns the thumbnail image that is resized to 80x60 pixels. @n
	*				GetAlbumArtN() returns the original album art that is embedded in the content metadata. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Graphics::Bitmap* GetAlbumArtN(void) const;

private:
	int		__bitrate;
	int		__sampleRate;
	int		__trackNum;
	int		__year;
	long	__duration;
	Osp::Base::String	__title;
	Osp::Base::String	__artist;
	Osp::Base::String	__comment;
	Osp::Base::String	__album;
	Osp::Base::String	__genre;
	Osp::Base::String	__provider;
	Osp::Base::String	__rating;
	Osp::Base::String	__url;
	Osp::Base::String	__copyright;
	Osp::Base::String	__composer;
	Osp::Base::String	__contentPath;

	class AudioMetadataEx* __pAudioMetadataEx;
	class AudioMetadataEx* GetAudioMetadataEx(void);
	bool AssignValues(const Osp::Base::String& inputPath, Osp::Content::AudioMeta* pAudioMeta);
	//bool AssignValues(const Osp::Base::ByteBuffer& byteBuffer, Osp::Content::AudioMeta* pAudioMeta);

	friend class ContentManagerUtil;
	friend class AudioMetadataEx;
};	// class AudioMetadata

}; }; // Osp::Content

#endif// _FCNT_AUDIO_METADATA_H_
