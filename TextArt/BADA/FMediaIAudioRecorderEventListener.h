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
 * @file			FMediaIAudioRecorderEventListener.h 
 * @brief			This is the header file for the %IAudioRecorderEventListener interface.
 *
 * This header file contains declarations of the %IAudioRecorderEventListener interface.
 */
 
#ifndef _FMEDIA_IAUDIORECORDER_EVENTLISTENER_H_
#define _FMEDIA_IAUDIORECORDER_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaRecorderCommon.h"

namespace Osp{ namespace Media{ 

/**
 * @interface	IAudioRecorderEventListener
 * @brief		This interface represents a listener that receives events associated with the AudioRecorder class.
 * @since		1.0
 *
 * The %IAudioRecorderEventListener interface represents a listener that receives events associated with the %AudioRecorder class.
 * %IAudioRecorderEventListener specifies the methods used to notify the status of the audio recorder.
 * The audio recorder engine works asynchronously. Therefore, it is important to implement this listener to ensure that the recorder flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this class is called.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_audio.htm">Recording Audio</a>.
 */ 
class _EXPORT_MEDIA_ IAudioRecorderEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when the AudioRecorder::Stop() method is completed.
	*
	* @since				1.0
	* @param[in]   	r	The cause of the error	
	*	@exception	  E_SUCCESS	The method is successful.
	*	@exception	  E_SYSTEM	A system error has occurred.
	*	@see					AudioRecorder::Stop()
	*/	 
	virtual void OnAudioRecorderStopped( result r) = 0; 

	/**
	*	Called when the AudioRecorder::Cancel() method is completed.
	*		
	* @since		   1.0		
	* @param[in] 	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*	@see		AudioRecorder::Cancel()
	*/	 
	virtual void OnAudioRecorderCanceled( result r ) = 0; 

	/**
	*	Called when the AudioRecorder::Pause() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* @see				 AudioRecorder::Pause()
	*
	*/
	virtual void OnAudioRecorderPaused( result r ) = 0; 

	/**
	*	Called when the AudioRecorder::Record() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* @see				 AudioRecorder::Record()
	*
	*/
	virtual void OnAudioRecorderStarted( result r ) = 0; 

	/**
	*	Called when %AudioRecorder reaches the end of the pre-defined file size or time.
	*
	* @since			1.0
	*	@param[in]	endCondition	The end condition of the recording
	*
	* @see				AudioRecorder::SetMaxRecordingSize(), AudioRecorder::SetMaxRecordingTime()
	*
	*/
	virtual void OnAudioRecorderEndReached(RecordingEndCondition endCondition) = 0; 

	/**
	*	Called when the AudioRecorder::Close() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* @see				 AudioRecorder::Close()
	*
	*/
	virtual void OnAudioRecorderClosed( result r ) = 0; 

	/**
	*	Called when an error has occurred in %AudioRecorder.
	*	
	* @since			1.0
	*	@param[in]	r		An audio recorder error reason of type ::RecorderErrorReason
	*	@remarks		::RECORDER_ERROR_OUT_OF_STORAGE occurs when the recording size exceeds the maximum available capacity.
	*				While recording especially to the external memory like MMC card, ::RECORDER_ERROR_STORAGE_FAILED can occur.
	*				::RECORDER_ERROR_DEVICE_FAILED occurs when the recording device has a problem like damaged shape or hardware malfunction.
	*	@see	RecorderErrorReason
	*/
	virtual void OnAudioRecorderErrorOccurred( RecorderErrorReason r ) = 0; 


};

};}; // Osp::Media

#endif

