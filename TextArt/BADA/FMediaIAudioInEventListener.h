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
 * @file			FMediaIAudioInEventListener.h 
 * @brief			This is the header file for the %IAudioInEventListener interface.
 *
 * This header file contains the declarations of the %IAudioInEventListener interface.
 */
 
#ifndef _FMEDIA_AUDIOINEVENTLISTENER_H_
#define _FMEDIA_AUDIOINEVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"

namespace Osp{ namespace Media{ 

/**
 * @interface	IAudioInEventListener
 * @brief			This interface represents a listener that receives the AudioIn related events.
 * @since			1.0
 *
 * The %IAudioInEventListener interface provides various methods that are called during the operations of %AudioIn.
 * %AudioIn captures audio data from the device in asynchronous mode,
 * and calls the listener's methods to pass the captured audio data.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_pcm_audio.htm">Recording PCM Audio</a>.
 *
 */ 

class _EXPORT_MEDIA_ IAudioInEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when the device has filled up a buffer with PCM data completely. 
	*
	* @since			1.0
	*	@param[in]  pData	A pointer to the buffer containing the filled data @n
	*							The data address is same as the address added by AudioIn::AddBuffer().
	*/
	virtual void OnAudioInBufferIsFilled( Osp::Base::ByteBuffer* pData) = 0;

	/**
	 *	Called when an input device is interrupted by a task of higher priority than %AudioIn.
	 *
	 * @since	1.0
	 */
	virtual void OnAudioInInterrupted(void) = 0;

	/**
	 *	Called when an interrupted input device is released.
	 *
	 * @since	1.0
	 */
	virtual void OnAudioInReleased(void) = 0;
};

};}; // Osp::Media

#endif

