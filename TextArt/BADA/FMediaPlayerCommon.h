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
 * @file			FMediaPlayerCommon.h 
 * @brief			This is the header file for the Player class.
 *
 * This header file contains the declarations of the enumerations of the Player class.
 */
 
#ifndef _FMEDIA_PLAYER_COMMON_H_
#define _FMEDIA_PLAYER_COMMON_H_

namespace Osp{ namespace Media { 

#define MIN_PLAYER_VOLUME 0
#define MAX_PLAYER_VOLUME 100
#define DEFAULT_PLAYER_VOLUME 50

/**
 * @enum PlayerState
 * Defines the state of the player.
 *
 * @since	1.0
 * @see		Osp::Media::Player::GetState()
 */
enum PlayerState
{
	PLAYER_STATE_INITIALIZED,		/**< The player is initialized*/
	PLAYER_STATE_OPENING,			/**< The player opening behavior is processed*/
	PLAYER_STATE_OPENED,			/**< The source is opened */
	PLAYER_STATE_ENDOFCLIP,			/**< The player has reached to the end of the clip */
	PLAYER_STATE_STOPPED,			/**< The player has stopped and has no current play-time, but the media content is still opened and initialized */
	PLAYER_STATE_PAUSED,			/**< The player playback is paused  */
	PLAYER_STATE_PLAYING,			/**< The player is playing the media content */
	PLAYER_STATE_CLOSED,			/**< The source is closed */
	PLAYER_STATE_ERROR,				/**< An error has occurred */

};

/**
 * @enum PlayerErrorReason
 * Defines the player error reason.
 *
 * @since	1.0
 */
typedef enum
{
	PLAYER_ERROR_NONE,						/*< Not defined */
	PLAYER_ERROR_INVALID_DATA,				/**< The data is invalid */
	PLAYER_ERROR_CONNECTION_LOST,			/**< The connection is lost */
	PLAYER_ERROR_STREAMING_TIMEOUT,			/**< The streaming has timed out */
	PLAYER_ERROR_TRANSPORT,					/**< The transport has failed */
	PLAYER_ERROR_SERVER,					/**< The server has failed */
	PLAYER_ERROR_OUT_OF_MEMORY,				/**< The memory is insufficient*/
	PLAYER_ERROR_DEVICE_FAILED,				/**< The player device has failed */
}PlayerErrorReason;

#define PLAYER_ERROR_OUT_OF_MEOMORY PLAYER_ERROR_OUT_OF_MEMORY

};}; // Osp::Media

#endif
