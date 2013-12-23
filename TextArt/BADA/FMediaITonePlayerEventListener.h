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
 * @file		FMediaITonePlayerEventListener.h 
 * @brief		This is the header file for the %ITonePlayerEventListener interface.
 *
 *              This header file contains the declarations of the %ITonePlayerEventListener interface.
 */
 
#ifndef _FMEDIA_TONEPLAYER_EVENTLISTENER_H_
#define _FMEDIA_TONEPLAYER_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaTonePlayer.h"

namespace Osp{ namespace Media{

/**
 * @interface	ITonePlayerEventListener
 * @brief		This interface provides a listener for the tone player events.
 * @since	2.0
 *
 * The %ITonePlayerEventListener interface specifies the methods used to notify the status of the tone player.
 */
class TonePlayer;

class _EXPORT_MEDIA_ ITonePlayerEventListener :
	public Osp::Base::Runtime::IEventListener
{

// Operation
public:
	/**
	*	Called when the tone player reaches to the end of the tone or the end of the list of tones.
	*
	*     @since 2.0
	*	@param[in]	src		A TonePlayer instance that fires the event
	*
	*/
	virtual void OnTonePlayerEndOfTone(Osp::Media::TonePlayer& src) = 0;

	/**
	*	Called when the tone player is interrupted by a task of higher priority than the tone player.
	*
	*     @since 2.0
	*	@param[in]	src		A TonePlayer instance that fires the event
	*
	*/
	virtual void OnTonePlayerInterrupted(Osp::Media::TonePlayer& src) = 0;

	/**
	*	Called when the interrupted tone player is released.
	*
	*     @since 2.0
	*	@param[in]	src		A TonePlayer instance that fires the event
	*
	*/
	virtual void OnTonePlayerReleased(Osp::Media::TonePlayer& src) = 0;

	/**
	*	Called to notify an application that an error has occurred while the tone is played.
	*
	*   @since 2.0
	*	@param[in]	src									A TonePlayer instance that fires the event
	*	@param[in]	r									A cause of the error
	*	@exception	E_SYSTEM							A system error has occurred.
	*/
	virtual void OnTonePlayerErrorOccurred(Osp::Media::TonePlayer& src, result r) = 0; 

protected:
	/**
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
    *
	* The following method is reserved, and its name can be changed at any time without prior notice.
    *
    * @since           2.0
    */
    virtual void ITonePlayerEventListener_Reserved1 (void) {}
	
	/**
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
    *
	* The following method is reserved, and its name can be changed at any time without prior notice.
    *
    * @since           2.0
    */
    virtual void ITonePlayerEventListener_Reserved2 (void) {}
	
	/**
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
    *
	* The following method is reserved, and its name can be changed at any time without prior notice.
    *
    * @since           2.0
    */
    virtual void ITonePlayerEventListener_Reserved3 (void) {}

	
};

};};// Osp::Media

#endif

