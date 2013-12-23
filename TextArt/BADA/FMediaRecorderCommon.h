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
 * @file			FMediaRecorderCommon.h 
 * @brief			This is the header file for the %Recorder enumeration.
 *
 * This header file contains the enumerations that can be used by a AudioRecorder and VideoRecorder.
 */
 
#ifndef _FMEDIA_RECORDER_COMMON_H_
#define _FMEDIA_RECORDER_COMMON_H_

namespace Osp{ namespace Media{ 

/**
 * @enum RecorderState
 * Defines the state of the recorder.
 *
 * @since	1.0
 * @see		AudioRecorder::GetState(), VideoRecorder::GetState()
 */
typedef enum
{
	RECORDER_STATE_INITIALIZED,		/**< The recorder is initialized */
	RECORDER_STATE_OPENED,			/**< The file to write to is opened */
	RECORDER_STATE_ENDOF_FILE,		/**< The recorder has reached to the end of size or time */
	RECORDER_STATE_STOPPING,		/**< The recorder stops recording */
	RECORDER_STATE_STOPPED,			/**< The recorder is stopped and has no current record-time @n
                                         However, the media content is opened and initialized. */
	RECORDER_STATE_PAUSING,			/**< The recorder is paused at a specific position */
	RECORDER_STATE_PAUSED,			/**< The recorder is paused */
	RECORDER_STATE_STARTING,		/**< The recording operation is starting */
	RECORDER_STATE_RECORDING,		/**< The recording state of the recorder */
	RECORDER_STATE_CLOSING,			/**< The recorder process is closing */
	RECORDER_STATE_CLOSED,			/**< The file is closed */
	RECORDER_STATE_ERROR,			/**< An error occurred in the recorder */
}RecorderState;


/**
 * @enum RecordingQuality
 * Defines the quality of the recorder.
 * @see	Osp::Media::AudioRecorder::SetQuality(), Osp::Media::AudioRecorder::GetQuality(), Osp::Media::VideoRecorder::SetQuality(), Osp::Media::VideoRecorder::GetQuality() 
 * @since	1.0
 */
typedef enum
{
	RECORDING_QUALITY_LOW,					/**< The low quality */
	RECORDING_QUALITY_MEDIUM,				/**< The medium quality */
	RECORDING_QUALITY_HIGH,					/**< The high quality */
}RecordingQuality;

/**
 * @enum RecordingEndCondition
 * Defines the record ending by reaching the limit.
 * @see	Osp::Media::AudioRecorder::SetMaxRecordingSize(), Osp::Media::AudioRecorder::SetMaxRecordingTime(), Osp::Media::VideoRecorder::SetMaxRecordingSize(), Osp::Media::VideoRecorder::SetMaxRecordingTime() 
 * @since	1.0
 */
typedef enum
{
	RECORDING_ENDOF_MAX_SIZE,			/**< The end of file size */	
	RECORDING_ENDOF_MAX_TIME,			/**< The end of time */	
}RecordingEndCondition;

/**
 * @enum RecorderErrorReason
 * Defines the error reasons of the recorder.
 *
 * @since	1.0
 */
typedef enum
{
	RECORDER_ERROR_NONE,						/*< Not defined */
	RECORDER_ERROR_OUT_OF_STORAGE,			/**< The storage is insufficient */
	RECORDER_ERROR_STORAGE_FAILED,			/**< The device storage access has failed */
	RECORDER_ERROR_DEVICE_FAILED,			/**< The recording device has failed */
}RecorderErrorReason;

};};
#endif





