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
 * @file			FMediaToneCommon.h 
 * @brief			This is the header file for the common types of Tone and TonePlayer.
 *
 * This header file contains the declarations of the enumerations of the Tone class.
 */
 
#ifndef _FMEDIA_TONE_COMMON_H_
#define _FMEDIA_TONE_COMMON_H_

namespace Osp{ namespace Media { 


/**
 * @internal    This variable is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this variable.
 *
 * Default volume level.
 * 
 * @since 2.0
 */
static const int DEFAULT_TONE_PLAYER_VOLUME	= 50;

/**
 * @internal    This variable is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this variable.
 *
 * Sampling rate.
 * 
 * @since 2.0
 */
static const int SAMPLING_RATE = 22050.0;

/**
 * @internal    This variable is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this variable.
 *
 * Maximum frequency.
 * 
 * @since 2.0
 */
static const int MAX_FREQUENCY = 15000;

/**
 * @internal    This variable is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this variable.
 *
 * Minimum frequency.
 * 
 * @since 2.0
 */
static const int MIN_FREQUENCY = 0;

/**
 * @internal    This variable is for internal use only. The bada platform team is not 
 * responsible for any behavioral correctness, consistency, and 
 * security-related issues that might arise after using this variable.
 *
 * Minimum duration.
 * 
 * @since 2.0
 */
static const int MIN_DURATION = 1;



/**
 * @enum TonePlayerState
 * Defines the state of the tone player.
 *
 * @since 2.0
 * @see	Osp::Media::TonePlayer::GetState()
 */
typedef enum 
{
	TONE_PLAYER_STATE_IDLE = 0x00, 		    /**< The tone player is idle */
	TONE_PLAYER_STATE_INITIALIZED,			/**< The tone player is initialized */
	TONE_PLAYER_STATE_OPENED, 				/**< The tone player instance is opened */
	TONE_PLAYER_STATE_PLAYING,				/**< The tone player is playing the tone(s) */
	TONE_PLAYER_STATE_PAUSED, 				/**< The tone player playback is paused  */
	TONE_PLAYER_STATE_STOPPED,				/**< The tone player has stopped and has no current play-time @n
	                                             However, the tone(s) is still opened and initialized. */
	TONE_PLAYER_STATE_CLOSED, 				/**< The tone player is closed */
	TONE_PLAYER_STATE_END_OF_TONE,			/**< The tone player has reached the end of the tone(s) */
	TONE_PLAYER_STATE_ERROR, 				/**< An error has occurred */
}TonePlayerState;

/**
 * @enum DtmfPreset
 * Defines the Dual-Tone Multi-Frequency (DTMF) presets for the keys.
 *
 * @since 2.0
 */
typedef enum 
{
	DTMF_PRESET_0 = 0x00,		/**< The DTMF tone for key 0: 1336Hz, 941Hz */
	DTMF_PRESET_1,				/**< The DTMF tone for key 1: 1209Hz, 697Hz */
	DTMF_PRESET_2,				/**< The DTMF tone for key 2: 1336Hz, 697Hz */
	DTMF_PRESET_3,				/**< The DTMF tone for key 3: 1477Hz, 697Hz */
	DTMF_PRESET_4,				/**< The DTMF tone for key 4: 1209Hz, 770Hz */
	DTMF_PRESET_5,				/**< The DTMF tone for key 5: 1336Hz, 770Hz */
	DTMF_PRESET_6,				/**< The DTMF tone for key 6: 1477Hz, 770Hz */
	DTMF_PRESET_7,				/**< The DTMF tone for key 7: 1209Hz, 852Hz */
	DTMF_PRESET_8,				/**< The DTMF tone for key 8: 1336Hz, 852Hz */
	DTMF_PRESET_9,				/**< The DTMF tone for key 9: 1477Hz, 852Hz */
	DTMF_PRESET_A,				/**< The DTMF tone for key A: 1633Hz, 697Hz */
	DTMF_PRESET_B,				/**< The DTMF tone for key B: 1633Hz, 770Hz */
	DTMF_PRESET_C,				/**< The DTMF tone for key C: 1633Hz, 852Hz */
	DTMF_PRESET_D,				/**< The DTMF tone for key D: 1633Hz, 941Hz */
	DTMF_PRESET_P,				/**< The DTMF tone for key #: 1477Hz, 941Hz */
	DTMF_PRESET_S,				/**< The DTMF tone for key *: 1209Hz, 941Hz */
}DtmfPreset;

};}; // Osp::Media

#endif
