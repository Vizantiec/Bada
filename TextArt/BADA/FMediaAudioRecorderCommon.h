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
 * @file			FMediaAudioRecorderCommon.h 
 * @brief			This is the header file for the %AudioRecordingFormat enumeration.
 *
 * This header file contains the descriptions for the %AudioRecordingFormat enumeration.
 */
 
#ifndef _FMEDIA_AUDIORECORDER_COMMON_H_
#define _FMEDIA_AUDIORECORDER_COMMON_H_

//include
#include "FMediaRecorderCommon.h"

namespace Osp{ namespace Media{ 

#define DEFAULT_AUDIORECORDING_TIME	(60*1000)		/*The default audio recording time - 60 seconds */
#define DEFAULT_AUDIORECORDING_SIZE	(300*1024)		/*The default audio recording size - 300 kb*/

/**
 * @enum AudioRecordingFormat
 * Defines the formats for audio recording.
 * @deprecated	This enumeration is deprecated because new methods do not use it. @n
 * Instead of using this enumeration, use ::MediaContainerType.
 *
 * @since 1.0
 * @see		AudioRecorder::SetFormat(), AudioRecorder::GetFormat()
 */
 typedef enum
{
	AUDIORECORDING_FORMAT_DEFAULT,				/**< The default format */
	AUDIORECORDING_FORMAT_AMR,					/**< The AMR format */
	AUDIORECORDING_FORMAT_WAVE,					/**< The WAVE format */
}AudioRecordingFormat;

};};	//Osp::Media

#endif
