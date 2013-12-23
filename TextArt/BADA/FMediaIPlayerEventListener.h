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
 * @file		FMediaIPlayerEventListener.h 
 * @brief		This is the header file for the %IPlayerEventListener interface.
 *
 * This header file contains the declarations of the %IPlayerEventListener interface.
 */
 
#ifndef _FMEDIA_PLAYER_EVENTLISTENER_H_
#define _FMEDIA_PLAYER_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaPlayerCommon.h"

namespace Osp{ namespace Media{

/**
 * @interface	IPlayerEventListener
 * @brief			This interface provides a listener for media playing events.
 * @since			1.0
 *
 * The %IPlayerEventListener interface specifies the methods used to notify the status of the media player during the media playing events.
 * The player engine works asynchronously. Therefore, it is important to implement this listener to ensure that the player flows correctly.
 * When each operation of the Player is completed, an event is generated, and a method from this class is called.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_audio.htm">Playing Audio</a> and 
 <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_video.htm">Playing Video</a>.
 */
 
class _EXPORT_MEDIA_ IPlayerEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when an audio/video content is opened asynchronously.
	*
	* @since			 1.0
	* @param[in]	 r	                                The cause of the error	
	*	@exception	 E_SUCCESS							The method is successful.
	*	@exception	 E_SYSTEM							A system error has occurred.
	*	@exception	 E_CONNECTION_FAILED				The network connection has failed.
	* 	@exception	 E_UNSUPPORTED_FORMAT				The specified format is not supported.
	* 	@exception	 E_UNSUPPORTED_CODEC				The specified codec is not supported.
	*	@exception	 E_OUT_OF_MEMORY					The memory is insufficient.
	*	@see		Player::OpenFile(), Player::OpenUrl(), Player::OpenBuffer()
	*/
	virtual void OnPlayerOpened( result r ) = 0; 

	/**
	*	Called when the Player reaches the end of the clip.
	*
	* @since	1.0
	*/
	virtual void OnPlayerEndOfClip(void) = 0; 

	/**
	*	Called when the position of the audio/video content moves asynchronously.
	*
	* @since			 1.0
	*	@exception	 E_SUCCESS		The method is successful.
	*	@exception	 E_SYSTEM		A system error has occurred.
	*	@see				 Player::SeekTo()
	*/

	virtual void OnPlayerSeekCompleted( result r ){};


	/**
	*	Called when the streaming data is being buffered.
	*
	* @since			1.0
	*	@param[in]	percent		The percentage of buffering is completed
	*	@see				Player::OpenUrl()
	*/
	virtual void OnPlayerBuffering(int percent) = 0; 

	/**
	*	Called when an error has occurs while the Player is working.
	*	
	* @since			1.0
	*	@param[in]	r		A player error reason of type ::PlayerErrorReason
	*	@remarks			While playing streaming media, the player might throw an error like ::PLAYER_ERROR_CONNECTION_LOST 
	*				::PLAYER_ERROR_STREAMING_TIMEOUT, ::PLAYER_ERROR_TRANSPORT or ::PLAYER_ERROR_SERVER.
	*				If the content includes invalid data, ::PLAYER_ERROR_INVALID_DATA may occur.
	*	@see				PlayerErrorReason
	*/
	virtual void OnPlayerErrorOccurred( PlayerErrorReason r ) = 0; 

	
	/**
	 *	Called when the Player is being interrupted by a task of higher priority than the Player.
	 *
	 * @since	1.0
	 */
	virtual void OnPlayerInterrupted(void) = 0;

	/**
	 *	Called when the interrupting Player has been released.
	 *
	 * @since	1.0
	 */
	virtual void OnPlayerReleased(void) = 0;

};

};};// Osp::Media

#endif

