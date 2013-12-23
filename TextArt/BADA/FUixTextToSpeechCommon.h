/* $Change: 618169 $ */
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
*
* @file			FUixTextToSpeechCommon.h
* @brief		This is the header file for common data types used by the TextToSpeech class.
*
* This header file contains the declarations of the common data types and constants used by the %TextToSpeech class.
*/

#ifndef _FUIX_TEXT_TO_SPEECH_COMMON_H_
#define _FUIX_TEXT_TO_SPEECH_COMMON_H_


//Include
#include "FUixConfig.h"


namespace Osp{ namespace Uix{ 

/**
 * @enum 		TextToSpeechVoiceType
 * Defines the voice types.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 * @see 		TextToSpeech::SetVoiceType(), TextToSpeech::GetVoiceType()
 */
typedef enum
{
	TTS_VOICE_TYPE_NONE,			/*< The voice type: None */
	TTS_VOICE_TYPE_MALE_DEFAULT,	/**< The default male voice */
	TTS_VOICE_TYPE_FEMALE_DEFAULT,	/**< The default female voice */
}TextToSpeechVoiceType;

/**
 * @enum 	TextToSpeechSpeechRate
 * Defines the level of the speech rate.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 * @see			TextToSpeech::GetSpeechRate(), TextToSpeech::SetSpeechRate()
 */
typedef enum
{
	TTS_SPEECH_RATE_NONE,		/*< The speech rate: None */
	TTS_SPEECH_RATE_VERY_SLOW,	/**< The speech rate is very slow */
	TTS_SPEECH_RATE_SLOW,		/**< The speech rate is slow */
	TTS_SPEECH_RATE_NORMAL,		/**< The speech rate is normal */
	TTS_SPEECH_RATE_FAST,		/**< The speech rate is fast */
	TTS_SPEECH_RATE_VERY_FAST,	/**< The speech rate is very fast */
}TextToSpeechSpeechRate;

/**
 * @enum 	TextToSpeechStatus
 * Defines the status of the Text-To-Speech service.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 * @see			ITextToSpeechEventListener::OnTextToSpeechStatusChanged()
 */
typedef enum
{
	TTS_STATUS_IDLE,			/**< The Text-To-Speech service is in idle status */
	TTS_STATUS_INITIALIZED,		/**< The Text-To-Speech service has been initialized */
	TTS_STATUS_SYNTHESIZING,	/**< The Text-To-Speech service is synthesizing the speech */
	TTS_STATUS_PLAYING,			/**< The Text-To-Speech service is playing the TTS result */
	TTS_STATUS_COMPLETED,		/**< The Text-To-Speech service has been completed */
	TTS_STATUS_PAUSED,			/**< The Text-To-Speech service has been paused */
}TextToSpeechStatus;

/**
 * @enum	TextToSpeechError
 * Defines the errors that occur in the Text-To-Speech service.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 * @see			ITextToSpeechEventListener::OnTextToSpeechErrorOccurred()
 */
typedef enum
{
	TTS_ERROR_INITIALIZATION_FAILED,	/**< The application has failed to initialize the Text-To-Speech service */
	TTS_ERROR_START_FAILED,				/**< The application has failed to start the Text-To-Speech service */
	TTS_ERROR_STOP_FAILED,				/**< The application has failed to stop the Text-To-Speech service */
	TTS_ERROR_PLAYING_FAILED,			/**< The application has failed to play the Text-To-Speech service */
	TTS_ERROR_NETWORK_FAILED,			/**< The Text-To-Speech service failed because of the network connection */
	TTS_ERROR_PAUSE_FAILED,				/**< The application has failed to pause the Text-To-Speech service */
	TTS_ERROR_RESUME_FAILED,			/**< The application has failed to resume the Text-To-Speech service */
}TextToSpeechError;

/**
 * @internal
 * This struct is for internal use only.
 * The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
 * that might arise after using this struct.
 * @enum TextToSpeechCurrentData
 * Defines current information of TextToSpeech.
 *
 * @since 	2.0
 */
typedef struct
{
	TextToSpeechVoiceType currentType;
	TextToSpeechSpeechRate currentRate;
	Osp::Base::String* currentLocale;
	Osp::Base::Collection::IList* supportedLocaleList;
}__TextToSpeechCurrentData;

};}; // Osp::Uix






#endif
