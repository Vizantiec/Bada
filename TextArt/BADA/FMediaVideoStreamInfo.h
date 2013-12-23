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
 * @file			FMediaVideoStreamInfo.h
 * @brief			This is the header file for the %VideoStreamInfo class.
 *
 * This header file contains the declarations of the %VideoStreamInfo class.
 */

#ifndef FMEDIAVIDEOSTREAMINFO_H_
#define FMEDIAVIDEOSTREAMINFO_H_

#include <FBase.h>
#include "FMediaConfig.h"

#include "FMediaTypes.h"

namespace Osp{ namespace Media {

class VideoStreamInfoEx;

/**
 * @class     VideoStreamInfo
 * @brief     This class provides methods to get video information.
 * @since     2.0
 *
 * The %VideoStreamInfo class provides methods to get video stream information, such as codec type, video width or height, bit rate,
 * and frame rate.
 *
 */

class _EXPORT_MEDIA_ VideoStreamInfo :
             public Osp::Base::Object
{
public :

	/**
	* This is the destructor for this class.
	*
	* @since     2.0
	*/
	virtual ~VideoStreamInfo(void);

public :

	/**
	*      Gets the encoding type of a video.
	*
	* @since     2.0
	*      @return             The value of the encoding type
	*/
	CodecType GetCodecType(void) const;

	/**
	*      Gets the width of a video.
	*
	* @since     2.0
	*      @return             The value of the video width
	*/
	int GetWidth(void) const;

	/**
	*      Gets the height of a video.
	*
	* @since     2.0
	*      @return             The value of the video height
	*/
	int GetHeight(void) const;

	/**
	*      Gets the bit rate of a video.
	*
	* @since     2.0
	*      @return             The video bit rate in bits per second (bps)
	*/
	int GetBitRate(void) const;

	/**
	*      Gets the frame rate of a video.
	*
	* @since     2.0
	*      @return             The video frame rate
	*/
	float GetFrameRate(void) const ;

private:
	/**
	* Initializes this instance of %VideoStreamInfo with the specified parameters.
	*
	* @param [in]	codecType	The value of the encoding type
	* @param [in]	width		The value of the video width
	* @param [in]	height		The value of the video height
	* @param [in]	bitrate		The video bit rate in bits per second (bps)
	* @param [in]	frameRate	The video frame rate
	*/
	VideoStreamInfo(CodecType codecType, int width, int height, int bitrate, float frameRate);

	VideoStreamInfo (const VideoStreamInfo& info);
	VideoStreamInfo& operator =(const VideoStreamInfo& info);

private:

	int __width;
	int __height;
	int __bitrate;
	CodecType __codecType;
	float __frameRate;

	friend class __Player;
	friend class VideoStreamInfoEx;
	VideoStreamInfoEx* __pVideoStreamInfoEx;
};

};};


#endif /* FMEDIAVIDEOSTREAMINFO_H_ */
