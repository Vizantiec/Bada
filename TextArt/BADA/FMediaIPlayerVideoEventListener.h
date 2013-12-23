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
 * @file		FMediaIPlayerVideoEventListener.h 
 * @brief		This is the header file for the %IPlayerVideoEventListener interface.
 *
 * This header file contains the declarations of the %IPlayerVideoEventListener interface.
 */
 
#ifndef _FMEDIA_PLAYER_VIDEO_EVENTLISTENER_H_
#define _FMEDIA_PLAYER_VIDEO_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaPlayerCommon.h"

namespace Osp{ namespace Media{

/**
 * @interface	IPlayerVideoEventListener
 * @brief			This interface provides a listener for the video event.
 * @since			2.0
 *
 * The %IPlayerVideoEventListener interface specifies the method used to get the decoded video frame.
 */
 
class _EXPORT_MEDIA_ IPlayerVideoEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when the video frame is decoded asynchronously.
	*
	* 	@since		 2.0
	*	@param[in]	 src				A pointer to the Player instance that fired the event
	*	@param[in]	 bitmapPixelFormat	A pixel format type	of the decoded video frame
	*	@param[in]	 dim				A dimension	of the decoded video frame
	*	@param[in]	 pBuffer			A pointer to a decoded video frame buffer
	*	@param[in]	 sizeOfBuffer		A size of a buffer
	* 	@param[in]	 r					The cause of the error	
	*	@exception	 E_SUCCESS							The method is successful.
	*	@exception	 E_SYSTEM							A system error has occurred.
	*	@exception	 E_INVALID_DATA	 					The video frame has invalid blocks.
	*	@see		Player::Play(), Player::PlayAndPause(), Player::SeekTo()
	*	@remarks	The lifecycle of @c pBuffer is valid inside this method.
	*/
	virtual void OnVideoFrameDecoded(Osp::Media::Player& src, Osp::Graphics::BitmapPixelFormat bitmapPixelFormat, const Osp::Graphics::Dimension &dim, const byte* pBuffer, int sizeOfBuffer, result r) = 0;


};

};};// Osp::Media

#endif

