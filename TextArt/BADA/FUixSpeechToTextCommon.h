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
* @file			FUixSpeechToTextCommon.h
* @brief		This is the header file for common data types used by SpeechToText.
*
* This header file contains the declarations of the common data types and constants used by %SpeechToText.
*/

#ifndef _FUIX_SPEECH_TO_TEXT_COMMON_H_
#define _FUIX_SPEECH_TO_TEXT_COMMON_H_


//Include
#include "FUixConfig.h"
#include "FBaseObject.h"
#include "FLclLocale.h"

namespace Osp{ namespace Uix{ 

/**
 * @enum SpeechToTextError
 * Defines the errors in %SpeechToText. 
 * When an error occurs, the user cannot receive any SpeechToText result.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since            2.0
 * @see ISpeechToTextEventListener::OnSpeechToTextErrorOccurred()
 */
typedef enum
{
	STT_ERROR_INITIALIZATION_FAILED,	/**< The SpeechToText has failed to initialize the service */
	STT_ERROR_START_FAILED,				/**< The SpeechToText has failed to start the service */
	STT_ERROR_STOP_FAILED,				/**< The SpeechToText has failed to stop the service */
	STT_ERROR_RECORDING_FAILED,			/**< The SpeechToText has failed to record the speech */
	STT_ERROR_NETWORK_FAILED,			/**< The SpeechToText has failed because of the network connection */
	STT_ERROR_CANCELED, 				/**< The SpeechToText service has been canceled by the user or failed to continue because of handling system events with higher priority */
	STT_ERROR_RECOGNITION_FAILED,		/**< The SpeechToText has failed to recognize the speech */
	STT_ERROR_TOO_SOON,					/**< The SpeechToText has failed because the speech started too soon */
	STT_ERROR_TOO_SHORT,				/**< The SpeechToText has failed because the speech is too short */
	STT_ERROR_TOO_LONG,					/**< The SpeechToText has failed because the speech is too long */
	STT_ERROR_TOO_QUIET,				/**< The SpeechToText has failed because the speech is too quiet to listen */
	STT_ERROR_TOO_LOUD,					/**< The SpeechToText has failed because the speech is too loud to listen */
	STT_ERROR_TOO_FAST,					/**< The SpeechToText has failed because the speech is too fast to listen */
}SpeechToTextError;

/**
 * @enum SpeechToTextWarning
 * Defines the warnings in SpeechToText. 
 * When a warning occurs, the user can receive any recognition result by ISpeechToTextEventListener::OnSpeechToTextCompleted(). The result may vary.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since            2.0
 * @see ISpeechToTextEventListener::OnSpeechToTextCompleted()
 */
typedef enum
{
	STT_WARNING_NONE,       /**< No warning */
	STT_WARNING_TOO_SOON,	/**< The speech has started too soon */
	STT_WARNING_TOO_SHORT,	/**< The speech is too short */
	STT_WARNING_TOO_LONG,	/**< The speech is too long */
	STT_WARNING_TOO_QUIET,	/**< The speech is too quiet to listen */
	STT_WARNING_TOO_LOUD,	/**< The speech is too loud to listen */
	STT_WARNING_TOO_FAST	/**< The speech is too fast to listen */
}SpeechToTextWarning;

/**
 * @enum SpeechToTextRecordingStatus
 * Defines the SpeechToText recording status.
 *
 * @deprecated	This enum is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since            2.0
 * @see ISpeechToTextEventListener::OnSpeechToTextRecordingStatusChanged()
 */
typedef enum
{
	STT_STATUS_RECORDING_STARTED,	/**< The recording has started */
	STT_STATUS_RECORDING_STOPPED,	/**< The recording has stopped */
	STT_STATUS_RECORDING_COMPLETED,	/**< The recording has completed */
}SpeechToTextRecordingStatus;

/**
 * @internal
 * This struct is for internal use only.
 * The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
 * that might arise after using this struct.
 * @enum SpeechToTextCurrentInfo
 * Defines current information of SpeechToText.
 * @since            2.0
 */
typedef struct
{
	Osp::Base::String* currentLocale;
	Osp::Base::String* currentGrammar;
	bool currentPunctuationOverride;
	bool currentProfanityFilter;
	bool currentSilenceDetection;
	Osp::Base::Collection::IList* supportedLocaleList;
}__SpeechToTextCurrentInfo;

};}; // Osp::Uix

#endif
