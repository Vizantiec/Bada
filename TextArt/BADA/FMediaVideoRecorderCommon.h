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
 * @file			FMediaVideoRecorderCommon.h 
 * @brief			This is the header file for the video recording enumerations.
 *
 * This header file contains the declarations of the video recording enumerations.
 */
 
#ifndef _FMEDIA_VIDEORECORDER_COMMON_H_
#define _FMEDIA_VIDEORECORDER_COMMON_H_

// Include
#include "FMediaRecorderCommon.h"

namespace Osp{ namespace Media{ 

#define DEFAULT_VIDEORECORDING_TIME	60000		    /* 60 sec */
#define DEFAULT_VIDEORECORDING_SIZE	1024*1024		/* 1 Megabytes */

/**
 * @enum VideoRecordingFormat
 * Defines the format of a video recorder.
 * @deprecated	This enumeration is deprecated because new methods do not use this enumeration. Instead of this enumeration, use
 *				::MediaContainerType.
 *
 * @since 1.0
 * @see		VideoRecorder::SetFormat(), VideoRecorder::GetFormat()
 */
typedef enum
{
    	VIDEORECORDING_FORMAT_DEFAULT,				/**< The default format */
    	VIDEORECORDING_FORMAT_MP4,					/**< The MP4 format */
	VIDEORECORDING_FORMAT_3GP,						/**< The 3GP format */
}VideoRecordingFormat;

/**
 * @enum VideoRecorderMode
 * Defines the mode of a video recorder.
 * @deprecated	This enumeration is deprecated because new methods do not use this enumeration. For video only recording, instead of using this enumeration use
 *				::CODEC_NONE.
 *
 * @since 1.0
 * @see		VideoRecorder::SetMode(), VideoRecorder::GetMode()
 */
typedef enum
{
    	VIDEORECORDER_MODE_VIDEO_WITH_AUDIO,			/**< The video with audio mode*/
    	VIDEORECORDER_MODE_VIDEO_ONLY,					/**< The video only mode*/
}VideoRecorderMode;

};};

#endif
