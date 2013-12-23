/* $Change: 1252960 $ */
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
 * @file			FMediaAudioRecorder.h
 * @brief			This is the header file for the %AudioRecorder class.
 *
 * This header file contains the declarations of the %AudioRecorder class.
 */

#ifndef _FMEDIA_AUDIORECORDER_H_
#define _FMEDIA_AUDIORECORDER_H_

//include
#include "FMediaConfig.h"
#include "FMediaAudioRecorderCommon.h"
#include "FMediaIAudioRecorderEventListener.h"
#include "FMediaTypes.h"

namespace Osp{ namespace Media{

class __AudioRecorderEvent;
class IAudioRecorderPi;
class __AudioRecorderConfiguration;

/**
 * @class	AudioRecorder
 * @brief	This class records the audio data into a file.
 * @since	1.0
 *
 *
 * The %AudioRecorder class records the audio data from an input device source to the storage device. The 
 * selection of the input device source depends upon the current device status. For example, if a headset device is 
 * connected, it is selected as an input source. The audio recording format, the maximum recording time, and the 
 * maximum recording size can be set using the methods available in this class. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_audio.htm">Recording Audio</a>.
 *
 * The following example demonstrates how to use the %AudioRecorder class.

 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 *
 * using namespace Osp::Media;
 * using namespace Osp::Base; 
 *
 * class MyAudioRecorderListener
 * 	: public IAudioRecorderEventListener
 * {
 *
 * public:
 * 	 void OnAudioRecorderStopped( result r );
 * 	 void OnAudioRecorderCanceled( result r );
 * 	 void OnAudioRecorderPaused( result r );
 * 	 void OnAudioRecorderStarted( result r );
 * 	 void OnAudioRecorderEndReached(RecordingEndCondition endCondition);
 * 	 void OnAudioRecorderClosed( result r );
 * 	 void OnAudioRecorderErrorOccurred( RecorderErrorReason r );
 * };
 *
 * static MyAudioRecorderListener* pListener = null;
 * static AudioRecorder* pAudioRecorder = null;
 * static String path("SampleFile.AMR");
 *
 * void MyAudioRecorderListener::OnAudioRecorderStopped( result r )
 * {
 * 	//Insert your code to operate after the audio recording is stopped.
 *	pAudioRecorder->Close();
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderCanceled( result r )
 * {
 * 	//Insert your code to operate after the audio recording is canceled.
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderPaused( result r )
 * {
 * 	//Insert your code to operate after the audio recording is paused.
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderStarted( result r )
 * {
 * 	//Insert your code to operate after the audio recording is started.
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderEndReached(RecordingEndCondition endCondition)
 * {
 * 	//Insert your code to operate after the audio recording reaches to the end of file.
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderClosed( result r )
 * {
 * 	//Insert your code to operate after the audio recorder is closed.
 *	delete pAudioRecorder;
 *	delete pListener;
 * }
 *
 * void MyAudioRecorderListener::OnAudioRecorderErrorOccurred( RecorderErrorReason r )
 * {
 * 	//Insert your code to operate after an error occurs.
 * }
 *
 * result TestAudioRecording(void)
 * {
 * 	result r = E_SUCCESS;
 *
 * 	pAudioRecorder = new AudioRecorder();
 * 	pListener = new MyAudioRecorderListener;
 *
 * 	r = pAudioRecorder->Construct(*pListener);
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 * 	r = pAudioRecorder->CreateAudioFile(path, true);
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 *    	r = pAudioRecorder->Record();
 * 	if (IsFailed(r)) { goto CATCH; }
 *
 * 	return r;
 *
 * 	CATCH:
 * 		if ( pAudioRecorder )
 * 			delete pAudioRecorder;
 *      if (pListener)
 * 			delete pListener;
 * 		return r;
 * }
 *
 * result TestAudioRecordingStop(void)
 * {
 * 	result r = E_SUCCESS;
 *
 *    	r = pAudioRecorder->Stop();
 *	return r;
 * }
 *
 * @endcode
 *
 */

class _EXPORT_MEDIA_ AudioRecorder :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to 
	 * 				initialize this instance.
	 * @see 		Construct()
	 */
	AudioRecorder(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are released by this method. This method should be called in the same thread in 
	 * which the Construct() method is called.
	 *
	 * @since	1.0
	 * @see	    Construct()
	 */
	virtual ~AudioRecorder(void);


// Operation
public:

	/**
	* Initializes this instance of %AudioRecorder with the specified listener.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener			An event listener instance
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE     This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_DEVICE_BUSY		The device cannot be approached because of other operations.
	*/
	result Construct( const IAudioRecorderEventListener& listener);

	/**
	* Creates an audio file for the recording.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	destMediaPath			The file destination to write @n
	*										The available paths start with prefixes such as: @n
	*										@li "/Media/" @n
	*										@li "/Storagecard/Media/" @n
	*										@li "/Home/" (user home storage)
	* @param[in]	overwrite	 			Set to @c true to overwrite a file if it already exists, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_RESOURCE_UNAVAILABLE	The required path is unavailable.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_STORAGE_FULL			The storage is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see Close()
	* @remarks 		The application can register newly created files into the Contents database using
	*	Osp::Content::ContentManager::CreateContent() if the file's path starts with "/Media" or
	*	"/Storagecard/Media".
	*/
	result CreateAudioFile(const Osp::Base::String& destMediaPath, bool overwrite);

	/**
	* Closes a file.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			CreateAudioFile()
	* @remarks 		This method is synchronous.
	*/
	result Close(void);

	/**
	* Starts recording or resumes a recording after Pause() is called.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return	  	An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Stop(), Pause()
	*/
	result Record(void);

	/**
	* Stops a recording.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Record(), Pause()
	*/
	result Stop(void);

	/**
	* Pauses a recording. @n
	* To resume a recording after this method is called, the Record() method must be called.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Record(), Stop()
	*/
	result Pause(void);

	/**
	* Cancels a recording operation without saving the data.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return	  	An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks	If this method is called, the state is changed to ::RECORDER_STATE_STOPPING. @n
	*			After IAudioRecorderEventListener::OnAudioRecorderCanceled() is called, the state is changed
	*			to ::RECORDER_STATE_STOPPED.
	* @see		Record(), Stop()
	*/
	result Cancel(void);

	/**
	* Gets the state of an audio recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return	  	The current state of an audio recorder
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			CreateAudioFile(), Close(), Record(), Stop(), Pause()
	*/
	RecorderState GetState(void) const;

	/**
	* Gets the current recording time.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return	  	The value indicating the current recording time in milliseconds, @n
	*				else @c -1 if the recording has not started as yet
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	long GetRecordingTime(void) const;

	/**
	* Gets the current recording size.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The value indicating the current recording size in bytes, @n
	*				else @c -1 if the recording has not started as yet
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	long GetRecordingSize(void) const;


	/**
	* Sets the maximum size of a file to store the recorded data in kilobytes.
	*
    * @deprecated    This method is deprecated.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	kbSize		The maximum size in kilobytes @n
	*							The specified size must be greater than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The default size is @c 300 kilobytes.
	* @see			GetMaxRecordingSize()
	*/
	result SetMaxRecordingSize(int kbSize);

	/**
	* Gets the maximum size for recording a file in kilobytes.
	*
	* @deprecated    This method is deprecated.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The maximum file size in kilobytes, @n
	*				else @c -1 if the recording has not started as yet
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMaxRecordingSize()
	*/
	int GetMaxRecordingSize(void) const;

	/**
	* Sets the recording time limit for a file in milliseconds.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	msTime		The maximum recording time in milliseconds @n
	*							The time must be greater than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE			The specified time is out of range.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The default time is @c 60 seconds.
	* @see			GetMaxRecordingTime()
	*/
	result SetMaxRecordingTime(long msTime);

	/**
	* Gets the recording time limit of a file in milliseconds.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		A @c long value indicating the maximum recording time in milliseconds
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMaxRecordingTime()
	*/
	long GetMaxRecordingTime(void) const ;

	/**
	* Sets the audio format of an audio recorder. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @deprecated	This method is deprecated. Instead of this method, use the SetFormat(CodecType audioCodec,
	* MediaContainerType container) method that sets the audio codec and container together.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[in]	format		The audio format to set @n
	*							::AUDIORECORDING_FORMAT_DEFAULT sets the system's default recording format.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetFormat()
	*/
	result SetFormat(AudioRecordingFormat format);

	/**
	* Gets the audio recording format of an audio recorder.
	*
	* @deprecated	This method is deprecated. Instead of this method, use the GetFormat(CodecType& audioCodec,
	* MediaContainerType& container) const method that gets the audio codec and container together.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		The audio recording format, @n
	* 				else default format if SetFormat() is not called before calling this method 
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetFormat()
	*/
	AudioRecordingFormat GetFormat(void) const;

	/**
	* Sets the audio codec and the container of an audio recorder. @n
	* Initially, the default codec and the container format are set using the internal configuration.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[in]	audioCodec				The audio codec to set
	* @param[in]	container				The media container to set
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified container format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		If the specified container does not support the specified codec, E_UNSUPPORTED_FORMAT may be thrown.
	* @see			GetFormat( CodecType& audioCodec, MediaContainerType& container ) const 
	*/
	result SetFormat( CodecType audioCodec, MediaContainerType container );

	/**
	* Gets the audio codec and container of an audio recorder.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[out]	audioCodec			The retrieved audio codec
	* @param[out]	container			The retrieved container
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		If SetFormat(CodecType audioCodec, MediaContainerType container) is not called before calling
	*				this method, the default codec and container are retrieved.
	* @see			SetFormat( CodecType audioCodec, MediaContainerType container )
	*/
	result GetFormat( CodecType& audioCodec, MediaContainerType& container ) const;

	/**
	* Gets a list of the supported audio codecs. @n
	* Each list's item has a ::CodecType value.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	A list of supported audio codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	* 	        	The return value must be released by the caller.
	* @see			SetFormat(CodecType audioCodec, MediaContainerType container), GetFormat(CodecType&
	*				audioCodec, MediaContainerType& container) const
	*/
	Osp::Base::Collection::IListT<CodecType>* GetSupportedCodecListN(void) const;

	/**
	* Gets a list of the supported containers. @n
	* Each list's item has a ::MediaContainerType value.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	A list of supported container list, @n
	*				else @c null if no container is supported or if an exception occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	* 	         	The return value must be released by the caller.
	* @see			SetFormat(CodecType audioCodec, MediaContainerType container), GetFormat(CodecType&
	*				audioCodec, MediaContainerType& container) const
	*/
	Osp::Base::Collection::IListT<MediaContainerType>* GetSupportedContainerListN(void) const;

	/**
	* Sets the audio recording quality of the audio recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	quality				The audio recording quality of the audio recorder @n
	*									The default value is ::RECORDING_QUALITY_MEDIUM.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG		The specified @c quality is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetQuality()
	*/
	result SetQuality(RecordingQuality quality);

	/**
	* Gets the audio recording quality of the audio recorder.
	*
	* @since	    1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current audio recording quality of the audio recorder
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetQuality()
	*/
	RecordingQuality GetQuality(void) const;

	/**
	* Enables or disables the mute state of an audio recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	mute 				The mute state @n
	*									By default, the mute state is disabled.
 	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The audio recording continues even though the audio recorder is in the mute state.
	* @see			IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks whether the mute state is enabled for an audio recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		@c true if the audio recorder is not recording any sound, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMute()
	*/
	bool IsMuted(void) const;

private:
	/**
	* Initializes the audio recorder interface.
	*
	* @internal
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	*/
	result __InitializePi(void);

private:
	/**
	* Retrieves the system information's string value.
	*
	* @return     	An error code
	* @param[in]	key 			The keyword to find
	* @param[in]	value 			The value string
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	result __GetSystemInfoStringValue ( Osp::Base::String& key, Osp::Base::String& value ) const;

	AudioRecorder(const AudioRecorder& );
	AudioRecorder& operator =(const AudioRecorder& audioRecorder);

	IAudioRecorderPi* 			__pAudioRecorderInterface;
	__AudioRecorderEvent*     __pAudioRecorderEvent;
	IAudioRecorderEventListener*	__pAudioRecorderEventListener;
	static bool			__isConstructed;
	__AudioRecorderConfiguration*		__pConfiguration;

	friend class AudioRecorderEx;
	class AudioRecorderEx* __pAudioRecorderEx;
};


};};// Osp::Media

#endif


