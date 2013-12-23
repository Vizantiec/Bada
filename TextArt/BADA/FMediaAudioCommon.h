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
* @file			FMediaAudioCommon.h
* @brief		This is the header file for the common types of AudioIn and AudioOut.
*
* This header file contains declarations of the enumerations of the Audio In/Out classes.
*/
#ifndef _FMEDIA_AUDIO_COMMON_H_
#define _FMEDIA_AUDIO_COMMON_H_

namespace Osp{ namespace Media{

#define MIN_AUDIOOUT_VOLUME 0
#define MAX_AUDIOOUT_VOLUME 100
#define DEFAULT_AUDIOOUT_VOLUME 50

/**
 * @enum AudioInputDevice
 * Defines the audio input device.
 *
 * @since 1.0
 * @see	AudioIn::Prepare()
 */
typedef enum{
	AUDIO_INPUT_DEVICE_MIC,		/**< The audio input device is a microphone  */
} AudioInputDevice;

/**
 * @enum AudioChannelType
 * Defines the audio channel type.
 *
 * @since 1.0
 * @see	AudioIn::Prepare(), AudioOut::Prepare()
 */
typedef enum{
	AUDIO_CHANNEL_TYPE_NONE,	/*< The audio channel type is none */
	AUDIO_CHANNEL_TYPE_MONO,	/**< The audio channel type is mono */
	AUDIO_CHANNEL_TYPE_STEREO,	/**< The audio channel type is stereo */
} AudioChannelType;

/**
 * @enum AudioSampleType
 * Defines the audio sample type with bit depth.
 *
 * @since 1.0
 * @see	AudioIn::Prepare(), AudioOut::Prepare()
 */
typedef enum{
	AUDIO_TYPE_NONE,		/*< The audio encoding type is none */
	AUDIO_TYPE_PCM_U8,		/**< The 8-bit samples are unsigned */
	AUDIO_TYPE_PCM_S8,		/**< The 8-bit samples are signed */
	AUDIO_TYPE_PCM_U16_LE,	/**< The 16-bit little-endian samples are unsigned */
	AUDIO_TYPE_PCM_U16_BE,	/**< The 16-bit big-endian samples are unsigned */
	AUDIO_TYPE_PCM_S16_LE,	/**< The 16-bit little-endian samples are signed */
	AUDIO_TYPE_PCM_S16_BE	/**< The 16-bit big-endian samples are signed */
} AudioSampleType;

/**
 * @enum AudioInState
 * Defines the audio input state.
 *
 * @since 1.0
 * @see	AudioIn::GetState()
 */
typedef enum{
	AUDIOIN_STATE_INITIALIZED,		/**< The device is initialized */
	AUDIOIN_STATE_PREPARED,			/**< The device is prepared  */
	AUDIOIN_STATE_RECORDING,		/**< The device is recording  */
	AUDIOIN_STATE_STOPPED,			/**< The device is stopped  */
	AUDIOIN_STATE_UNPREPARED,		/**< The device is uninitialized  */
	AUDIOIN_STATE_ERROR,			/**< An error has occurred   */
} AudioInState;

/**
 * @enum AudioOutState
 * Defines the audio output state.
 *
 * @since 1.0
 * @see	AudioOut::GetState()
 */
typedef enum{
	AUDIOOUT_STATE_INITIALIZED,		/**< The device is initialized */
	AUDIOOUT_STATE_PREPARED,		/**< The device is prepared  */
	AUDIOOUT_STATE_PLAYING,			/**< The device is playing data */
	AUDIOOUT_STATE_STOPPED,			/**< The device is stopped  */
	AUDIOOUT_STATE_UNPREPARED,		/**< The device is uninitialized  */
	AUDIOOUT_STATE_ERROR,			/**< An error has occurred   */
} AudioOutState;

/**
 * @internal    This type is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this type.
 *
 * @enum AudioCodecType
 *
 * Defines the audio codec type.
 * @since 1.0
 */
typedef enum{
	AUDIO_FORMAT_NONE, /* Audio codec type is none */
	AUDIO_FORMAT_WAVE /* Audio codec type is WAVE*/
} AudioCodecType;

};}; // Osp::Media


#endif

