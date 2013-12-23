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
 * @file		FUixITextToSpeechEventListener.h
 * @brief		This is the header file for the %ITextToSpeechEventListener interface.
 *
 * This header file contains the declarations of the %ITextToSpeechEventListener interface.
 *
 *
 */

 
#ifndef _FUIX_TEXT_TO_SPEECH_EVENTLISTENER_H_
#define _FUIX_TEXT_TO_SPEECH_EVENTLISTENER_H_

//Includes
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixTextToSpeechCommon.h"

namespace Osp{ namespace Uix{

/**
 * @interface	ITextToSpeechEventListener
 * @brief		This interface is a listener for the speech synthesis events.
 * @deprecated	This interface is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 *
 * The %ITextToSpeechEventListener interface is a listener interface for the speech synthesis events.
 * It provides methods that are used to notify when the status is changed and an error
 * occurs from the voice engine.
 */


 
class _EXPORT_UIX_ ITextToSpeechEventListener :
		public Osp::Base::Runtime::IEventListener
{

public:
	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	*/
	virtual ~ITextToSpeechEventListener( void ) {}
	
	/**
	 * Called when the status of the Text-To-Speech service is changed. 
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	 * @since       2.0
	 * @param[in]	status	The status of the Text-To-Speech service
	 * @see			TextToSpeechStatus
	 */
	 virtual void OnTextToSpeechStatusChanged( TextToSpeechStatus status ) = 0;
	 
	/**
	 * Called when an error occurs in the Text-To-Speech service.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	 * @since       2.0
	 * @param[in]	error	The reason for an error in the Text-To-Speech service
	 * @see			TextToSpeechError
	 */
	 virtual void OnTextToSpeechErrorOccurred( TextToSpeechError error ) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
	 virtual void ITextToSpeechEventListener_Reserved1 (void) {}
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
    virtual void ITextToSpeechEventListener_Reserved2 (void) {}
	/**
	 * @internal
	 * This method is for internal use only.
	 * The bada platform team is not responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since		2.0
	 */
    virtual void ITextToSpeechEventListener_Reserved3 (void) {}

};

};};// Osp::Uix

#endif

