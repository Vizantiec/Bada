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
* @file			FCntVideoMetadata.h 
* @brief		This is the header file for the %VideoMetadata class.
*
* This header file contains the declarations of the %VideoMetadata class.
*/

#ifndef _FCNT_VIDEO_METADATA_H_
#define _FCNT_VIDEO_METADATA_H_

#include <FCntConstants.h>
#include <FMediaImage.h>

namespace Osp { namespace Content {

class VideoMetadataEx;
struct VideoMeta;

/**
* @class	VideoMetadata
* @brief	This class provides the methods to access the video metadata.
* @since	1.0
*
* The %VideoMetadata class provides the methods to access video metadata. 
*
* The following example demonstrates how to use the %VideoMetadata class.
*
* @code
* result
* MyClass::TestVideoMetadata(void) 
* {
* 		result r = E_SUCCESS;
*
*		VideoMetadata* pVideoMeta = ContentManagerUtil::GetVideoMetaN(L"/Media/Videos/video.mp4");
*		TryReturn(pVideoMeta != null, GetLastResult(), "ContentManagerUtil::GetVideoMetaN failed.");
*
*		// Width
*		int width = pVideoMeta->GetWidth();
*
*		// Height
*		int height = pVideoMeta->GetHeight();
*
*		// Duration
*		long duration = pVideoMeta->GetDuration();
*
*		delete pVideoMeta;
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ VideoMetadata : public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	VideoMetadata(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~VideoMetadata(void);

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
	* Gets the duration.
	*
	* @since		1.0
	* @return		The duration in milliseconds
	*/
	long GetDuration(void) const;

	/**
	* Gets the frame rate.
	*
	* @since		1.0
	* @return		The frame rate 
	*/
	int GetFramerate(void) const;

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
	* Gets the genre.
	*
	* @since		1.0
	* @return		The genre
	*/
	Osp::Base::String GetGenre(void) const;

	/**
	* Gets the album art of the video.
	*
	* @since		2.0
	* @return		A pointer to the album art
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND	The album art does not exist.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Graphics::Bitmap* GetAlbumArtN(void) const;

private:
	int		__width;
	int		__height;
	long	__duration;
	int		__videoFramerate;
	int		__audioBitrate;
	Osp::Base::String	__artist;
	Osp::Base::String	__genre;
	Osp::Base::String	__description;
	Osp::Base::String	__contentPath;

	class VideoMetadataEx* __pVideoMetadataEx;
	class VideoMetadataEx* GetVideoMetadataEx(void);
	bool AssignValues(const Osp::Base::String& inputPath, Osp::Content::VideoMeta* pVideoMeta);
	//bool AssignValues(const Osp::Base::ByteBuffer& byteBuffer, Osp::Content::VideoMeta* pVideoMeta);

	friend class ContentManagerUtil;
	friend class VideoMetadataEx;

};	// class VideoMetadata

}; };	// Osp::Content

#endif	// _FCNT_VIDEO_METADATA_H_
