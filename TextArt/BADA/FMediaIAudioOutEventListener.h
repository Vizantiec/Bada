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
 * @file			FMediaIAudioOutEventListener.h 
 * @brief			This is the header file for the %IAudioOutEventListener interface.
 *
 * This header file contains the declarations of the %IAudioOutEventListener interface.
 */
 
#ifndef _FMEDIA_AUDIOOUTEVENTLISTENER_H_
#define _FMEDIA_AUDIOOUTEVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"

namespace Osp{ namespace Media{ 
class AudioOut;
/**
 * @interface	IAudioOutEventListener
 * @brief			This interface represents a listener that receives the AudioOut related events.
 * @since			1.0
 *
 *  The %IAudioOutEventListener interface represents a listener that receives the %AudioOut related events. The %AudioOut class works in asynchronous mode, and when the application plays audio data with the %AudioOut class,
 *  the caller must implement this interface to receive an event from %AudioOut.
 *
 *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_pcm_audio.htm">Playing PCM Audio</a>.
 */ 

class _EXPORT_MEDIA_ IAudioOutEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when the device has written a buffer completely. 
	*
	* @since			1.0
	*	@param[in]	src	A pointer to the %AudioOut instance that fired the event
	*/
	virtual void OnAudioOutBufferEndReached(Osp::Media::AudioOut& src) = 0;

	/**
	 *	Called when the output device is interrupted by a task of higher priority than %AudioOut.
	 *
	 * @since				1.0
	 *	@param[in]	src							A pointer to the %AudioOut instance that fired the event
	 */
	virtual void OnAudioOutInterrupted(Osp::Media::AudioOut& src) = 0;

	/**
	 *	Called when the interrupted output device is released.
	 *
	 * @since				1.0
	 *	@param[in]	src							A pointer to the %AudioOut instance that fired the event
	 */
	virtual void OnAudioOutReleased(Osp::Media::AudioOut& src) = 0;

};

};}; // Osp::Media

#endif

