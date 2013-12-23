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
 * @file			FMediaIVideoRecorderEventListener.h 
 * @brief			This is the header file for the %IVideoRecorderEventListener interface.
 *
 * This header file contains declarations of the %IVideoRecorderEventListener interface.
 */
 #ifndef _FMEDIA_IVIDEORECORDER_EVENTLISTENER_H_
#define _FMEDIA_IVIDEORECORDER_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaRecorderCommon.h"

namespace Osp{ namespace Media{ 

/**
 * @interface	IVideoRecorderEventListener
 * @brief			This interface represents a listener that receives events associated with the VideoRecorder class.
 * @since			1.0
 *
 * The %IVideoRecorderEventListener interface specifies the methods used to notify the status of the video recorder.
 * The video recorder engine works asynchronously. Therefore, it is important to implement this listener to ensure that the recorder flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this interface is called.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_video.htm">Recording Video</a>.
 */ 
class _EXPORT_MEDIA_ IVideoRecorderEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when the VideoRecorder::Stop() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* @see	VideoRecorder::Stop()
	*
	*/
	virtual void OnVideoRecorderStopped( result r ) = 0; 

	/**
	*	Called when the VideoRecorder::Cancel() method is completed.
	*			
	* @since			 1.0	
	* @param[in]   r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	*	@see		VideoRecorder::Cancel()
	*/	 
	virtual void OnVideoRecorderCanceled( result r ) = 0; 

	/**
	*	Called when the VideoRecorder::Pause() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* 	@see	VideoRecorder::Pause()
	*
	*/
	virtual void OnVideoRecorderPaused( result r ) = 0; 

	/**
	*	Called when the VideoRecorder::Record() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* 	@see	VideoRecorder::Record()
	*
	*/
	virtual void OnVideoRecorderStarted( result r ) = 0; 

	/**
	 *	Called when %VideoRecorder reaches the end of the pre-defined file size or time.
	 *	
	 * @since			1.0
	 * @param[in]	endCondition	The end condition of the recording
	 * @see				VideoRecorder::SetMaxRecordingSize(), VideoRecorder::SetMaxRecordingTime()
	 *
	 */
	virtual void OnVideoRecorderEndReached(RecordingEndCondition endCondition) = 0; 

	/**
	*	Called when the VideoRecorder::Close() method is completed.
	*
	* @since			 1.0
	* @param[in]	 r	The cause of the error	
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_SYSTEM	A system error has occurred.
	* @see				 VideoRecorder::Close()
	*
	*/
	virtual void OnVideoRecorderClosed( result r ) = 0; 

	/**
	*	Called when an error occurred in %VideoRecorder.
	*	
	* @since			1.0
	*	@param[in]	r		A video recorder error reason of type ::RecorderErrorReason
	*	@remarks			::RECORDER_ERROR_OUT_OF_STORAGE occurs when the recording size exceeds the maximum available capacity.
	*							While recording to an external memory like MMC card, ::RECORDER_ERROR_STORAGE_FAILED can occur.
	*							::RECORDER_ERROR_DEVICE_FAILED occurs when the recording device has a problem like damaged shape or h/w failure.
	*	@see				RecorderErrorReason
	*/
	virtual void OnVideoRecorderErrorOccurred( RecorderErrorReason r ) = 0; 
   
};

};}; // Osp::Media

#endif

