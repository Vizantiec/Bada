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
 * @file		FUixISpeechToTextEventListener.h
 * @brief		This is the header file for the %ISpeechToTextEventListener interface.
 *
 * This header file contains the declarations of the %ISpeechToTextEventListener interface.
 *
 */
 
#ifndef _FUIX_SPEECH_TO_TEXT_EVENTLISTENER_H_
#define _FUIX_SPEECH_TO_TEXT_EVENTLISTENER_H_

//Includes
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixSpeechToTextCommon.h"

namespace Osp{ namespace Uix{

/**
 * @interface	ISpeechToTextEventListener
 * @brief		This interface is a listener for speech recognition events.
 * @deprecated	This interface is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
 * @since		2.0
 *
 * The %ISpeechToTextEventListener interface is a listener interface for speech recognition events.
 * It provides methods that are invoked by the voice engine when the status is changed, an
 * error or warning occurs or the result is received in the Speech-To-Text service.
 */
 
class _EXPORT_UIX_ ISpeechToTextEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:
	/**
	* This is the destructor for this class.	
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	*/
	virtual ~ISpeechToTextEventListener( void ) {}
	
    /**
     * Called when the Speech-To-Text service is initialized.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
     * @since       2.0
     * @see			SpeechToText::Initialize()
     */
    virtual void OnSpeechToTextInitialized ( void ) = 0;

	/**
	 * Called when the Speech-To-Text recording status is changed.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	 * @since       2.0
	 * @param[in]	status	The recording status of the Speech-To-Text service
	 * @see			SpeechToTextRecordingStatus
	 */
	virtual void OnSpeechToTextRecordingStatusChanged( SpeechToTextRecordingStatus status ) = 0;
	
	/**
	 * Called when an error occurs in the Speech-To-Text service.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	 * @since       2.0
	 * @param[in]	error	The reason for an error in the Speech-To-Text service
	 * @see			SpeechToTextError
	 */
	virtual void OnSpeechToTextErrorOccurred( SpeechToTextError error ) = 0;

	/**
	 * Called when the Speech-To-Text service is completed.
	 *
	 * @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	 * @since		2.0
	 * @param[in]	result	The result of the Speech-To-Text service
	 * @param[in]	warning	A warning that occurred during the Speech-To-Text service
	 */
	virtual void OnSpeechToTextCompleted( Osp::Base::String& result, SpeechToTextWarning warning ) = 0;

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
    virtual void ISpeechToTextEventListener_Reserved1 (void) {}
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
    virtual void ISpeechToTextEventListener_Reserved2 (void) {}
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
    virtual void ISpeechToTextEventListener_Reserved3 (void) {}

};

};};// Osp::Uix

#endif

