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
 * @file			FMediaAudioIn.h
 * @brief			This is the header file for the %AudioIn class.
 *
 * This header file contains the declarations of the %AudioIn class.
 */

#ifndef _FMEDIA_AUDIOIN_H_
#define _FMEDIA_AUDIOIN_H_

//Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioCommon.h"
#include "FMediaIAudioInEventListener.h"

namespace Osp{ namespace Media{

class __AudioInEvent;
class IAudioInPi;

/**
 * @class	AudioIn
 * @brief		This class records directly from an audio device.
 * @since		1.0
 *
 * The %AudioIn class records directly from an audio device by providing methods for capturing PCM data from an audio input device.
 * An application can capture audio data with the help of an event listener after preparing the %AudioIn class 
 * with proper channel count, sample type, and sampling rate.
 * To minimize the overhead of the %AudioIn class, 
 * it is recommended that you use optimal channel type, sample type, and sampling rate.
 * These can be retrieved with GetOptimizedChannelType(), GetOptimizedSampleType()
 * and GetOptimizedSampleRate(). 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_pcm_audio.htm">Recording PCM Audio</a>.
 *
 * The following example demonstrates how to use the %AudioIn class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FIo.h>
 * 
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Base::Runtime;
 * using namespace Osp::Media;
 * using namespace Osp::Io;
 * 
 * class AudioInExampleListener
 *     : public Osp::Media::IAudioInEventListener
 * {
 *   public:
 *     	void OnAudioInBufferIsFilled( Osp::Base::ByteBuffer* pData);
 *     	void OnAudioInErrorOccurred(result r );
 *     	void OnAudioInInterrupted();
 *     	void OnAudioInReleased();
 * };
 * 
 * class AudioInExample
 * {
 * 	// Lifecycle
 * public:
 * 	AudioInExample(void);
 * 	virtual ~AudioInExample(void);
 * 
 * // Example Operation
 * public:
 * 	void AudioInRecord(void);
 * 	void AudioInStop(void);
 * };
 *
 * 	#define MAX_BUFFER_SIZE		56000 // 56kb
 * 
 * 	static ByteBuffer* __pByteBuffer1 = null;
 * 	static ByteBuffer* __pByteBuffer2 = null;
 * 	static ByteBuffer* __pByteBuffer3 = null;
 * 	static ByteBuffer* __pTempBuffer = null;
 * 	static AudioIn* __pAudioInInstance = null;
 * 	static AudioInExampleListener* __pMyAudioInListener = null;
 * 
 * 	void ConsumeBuffer(ByteBuffer* pBuffer);
 * 
 * 	AudioInExample::AudioInExample()
 * 	{
 * 		// Initializes AudioIn
 * 
 * 		__pAudioInInstance = new AudioIn();
 * 		__pMyAudioInListener = new AudioInExampleListener;
 * 	}
 * 
 * 	AudioInExample::~AudioInExample()
 * 	{
 * 
 * 		if(__pByteBuffer1 != null)
 * 		{
 * 			delete __pByteBuffer1;
 * 			__pByteBuffer1 = null;
 * 		}
 * 		if(__pByteBuffer2 != null)
 * 		{
 * 			delete __pByteBuffer2;
 * 			__pByteBuffer2 = null;
 * 		}
 * 		if(__pByteBuffer3 != null)
 * 		{
 * 			delete __pByteBuffer3;
 * 			__pByteBuffer3 = null;
 * 		}
 * 
 * 		if(__pMyAudioInListener != null)
 * 		{
 * 			delete __pMyAudioInListener;
 * 			__pMyAudioInListener = null;
 * 		}
 * 
 * 		delete __pAudioInInstance;
 * 		__pAudioInInstance = null;
 * 
 * 	}
 * 
 * 	void AudioInExample::AudioInRecord(void)
 * 	{
 * 		// Constructs an AudioIn instance
 * 		__pAudioInInstance->Construct(*__pMyAudioInListener);
 * 
 * 		// Prepares an AudioIn instance
 * 		__pAudioInInstance->Prepare(AUDIO_INPUT_DEVICE_MIC,AUDIO_TYPE_PCM_U8, AUDIO_CHANNEL_TYPE_STEREO,8000);
 * 
 * 		// Prepare buffers to store PCM data
 * 		__pByteBuffer1 = new ByteBuffer();
 * 		__pByteBuffer1->Construct(MAX_BUFFER_SIZE);
 * 		__pByteBuffer2 = new ByteBuffer();
 * 		__pByteBuffer2->Construct(MAX_BUFFER_SIZE);
 * 		__pByteBuffer3 = new ByteBuffer();
 * 		__pByteBuffer3->Construct(MAX_BUFFER_SIZE);
 * 
 * 		// Adds buffers
 * 		__pAudioInInstance->AddBuffer(__pByteBuffer1);
 * 		__pAudioInInstance->AddBuffer(__pByteBuffer2);
 * 		__pAudioInInstance->AddBuffer(__pByteBuffer3);
 * 
 * 		// Start
 * 		__pAudioInInstance->Start();
 * 	}
 * 
 * 	void AudioInExample::AudioInStop(void)
 * 	{
 * 		// Stops and unprepares an AudioIn instance
 * 		 __pAudioInInstance->Stop();
 * 		 __pAudioInInstance->Unprepare();
 * 	}
 * 
 * 	void AudioInExampleListener::OnAudioInBufferIsFilled( Osp::Base::ByteBuffer* pData)
 * 	{
 * 		int filledSize = 0;
 * 
 * 		// Handle the input data here
 * 		filledSize = pData->GetLimit();
 * 
 * 		// Copy to temp buffer
 * 		__pTempBuffer = new ByteBuffer();
 * 		__pTempBuffer->Construct(pData->GetLimit());
 * 		__pTempBuffer->CopyFrom(*pData);
 * 
 * 		// User temp buffer, it takes some seconds maybe
 * 		// It needs for estimating a proper delay time
 * 		ConsumeBuffer(__pTempBuffer);
 * 
 * 		// Buffer clear for re-use
 * 		pData->Clear();
 * 
 * 		// Return a pointer of byte buffer again
 * 		__pAudioInInstance->AddBuffer(pData);
 * 	}
 * 
 * 	void AudioInExampleListener::OnAudioInErrorOccurred(result r)
 * 	{
 * 	}
 * 
 * 	void AudioInExampleListener::OnAudioInInterrupted(void)
 * 	{
 * 	}
 * 
 * 	void AudioInExampleListener::OnAudioInReleased(void)
 * 	{
 * 	}
 * 
 * 	// Internal Function
 * 
 * 	void ConsumeBuffer(ByteBuffer* pBuffer)
 * 	{
 * 		//use here
 * 			// User Codes for consuming recorded buffer
 * 		//delete
 * 		delete pBuffer;
 * 		pBuffer = null;
 * 	}
 * 
 *
 * @endcode
 *
 */

class _EXPORT_MEDIA_ AudioIn :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since		1.0
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *
	 *	@see			Construct()
	 */
	AudioIn(void);

	/**
	 *	This is the destructor for this class. @n
	 *	All allocated resources are deallocated with this method. @n
	 *	This method must be called in the same thread as the Construct() method.
	 *
	 * @since		1.0
	 *	@see		Construct()
	 */
	virtual ~AudioIn(void);


// Operation
public:

	/**
	*	Initializes this instance of AudioIn with the specified IAudioInEventListener. @n
	*	This method creates an instance of %AudioIn in the subsystem.
	*
	* @since			1.0
	*	@return			An error code
	*	@param[in]	listener						An event listener instance
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_DEVICE_BUSY					The device cannot be approached because of other operations.
	*	@exception	E_SYSTEM						A system error has occurred.
	* 
	*   @remarks Only one instance of %AudioIn is operational at a given time.
    */
	result Construct( const IAudioInEventListener& listener);

	/**
	*	Prepares the specified audio input device with the application-defined settings. @n
	*   When the caller finishes using the audio input device, the resources must be released by calling the Unprepare() method.
	*
	* @since					 1.0
	* 	@compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	*                  For more information, see @ref CompMediaAudioInPreparePage "here".
	*	@return				   An error code
	*	@param[in]	audioInputDevice		An audio input device
	*	@param[in]	audioSampleType			The type of audio sample
	*	@param[in]	audioChannelType		The audio channel type
	*	@param[in]	audioSampleRate			The audio sample rate in Hertz
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	* 	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	* 	@exception	E_UNSUPPORTED_FORMAT			The specified audio sample type is not supported.
	*	@see		Unprepare()
	*/
	result Prepare(AudioInputDevice audioInputDevice, AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	* @page   	CompMediaAudioInPreparePage Compatibility for Prepare()
	* @section 	CompMediaAudioInPreparePageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	* 
	* -# If this method is used with a sample rate below 8000 Hertz, the AddBuffer() method does not work as expected and returns E_SYSTEM.
	*
	* @section CompMediaAudioInPreparePageResolutionSection Resolutions
	*
	*  The issue mentioned above is resolved in bada API version 1.1 as follows: @n
	*	-# If this method is used with a sample rate below 8000 Hertz, E_INVALID_ARG is returned.
	*/

	
	
	/**
	*	Stops the usage of the input device and releases the allocated resources during the execution of the Prepare() method. @n
	*   Resources allocated during Prepare() are released.
	*
	* @since			1.0
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@see		Prepare()
	*/
	result Unprepare(void);

	/**
	*	Sends an input buffer to the specified audio input device. @n
	*	When the buffer is filled, the %AudioIn class returns the buffer to the caller 
	*   by invoking IAudioInEventListener::OnAudioInBufferIsFilled().
	*
	* @since			1.0
	*	@return			An error code
	*	@param[in]	pByteBuffer		A pointer to the buffer
	*	@exception	E_SUCCESS						The method is successful.
	* 	@exception	E_INVALID_ARG					The input parameter is invalid.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	*	@see		Start(), IAudioInEventListener::OnAudioInBufferIsFilled()
	*	@remarks	The data size of @c pByteBuffer must be the same as every call of this method. 
	*/
	result AddBuffer( const Osp::Base::ByteBuffer* pByteBuffer);

	/**
	*	Starts reading the audio data from an audio input device and fills the data into the buffer.
	*
	* @since			1.0
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_DEVICE_BUSY					The device cannot be approached because of other operations.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@see		Stop(), IAudioInEventListener::OnAudioInBufferIsFilled()
	*  
	* 	@remarks	Several buffers should be added to the queue
	*           with AddBuffer() before calling of this method.
	*/
	result Start(void);

	/**
	*	Stops using the audio input device. @n
	*	All pending and current buffers that are filled with audio data 
	*   at the time of calling this method, are returned to the listener.
	*	Use Start() to start capturing audio input data again.
	*
	* @since			1.0
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@see		Start(), IAudioInEventListener::OnAudioInBufferIsFilled()	
	*/
	result Stop(void);

	/**
	*	Stops using the audio input device without returning buffers to the caller. @n
	*	All pending and current buffers are released immediately without any notifications.
	*	The state is changed to AUDIOIN_STATE_PREPARED.
	*
	* @since			1.0
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	result Reset(void);

	/**
	*	Gets the current state of this instance.
	*
	* @since			1.0
	*	@return			The state of this instance
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioInState GetState(void) const;

	/**
	*	Gets the maximum size of the buffer that can be used with AddBuffer(). @n
	*	This maximum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since			1.0
	*	@return			The maximum size of the buffer in bytes, @n
					else @c -1 if an error occurs
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The return value is available after calling the Prepare() method.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMaxBufferSize(void) const;

	/**
	*	Gets the minimum size of the buffer that can be used with AddBuffer(). @n
	*	This minimum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since			1.0
	*	@return			The minimum size of the buffer in bytes,	@n
					else @c -1 if an error occurs
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The return value is available after calling the Prepare() method.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMinBufferSize(void) const;

	/**
	*	Gets the optimized sample type of the audio input device.
	*
	* @since			1.0
	*	@return			The audio encoding type
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioSampleType GetOptimizedSampleType(void) const;

	/**
	*	Gets the optimized channel type of the audio input device.
	*
	* @since			1.0
	*	@return			The audio channel type
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioChannelType GetOptimizedChannelType(void) const;

	/**
	*	Gets the optimized sample rate of the audio input device.
	*
	* @since			1.0
	*	@return			The sample rate in Hertz
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int	GetOptimizedSampleRate(void) const;


private:
	AudioIn(const AudioIn& audioIn);
	AudioIn& operator =(const AudioIn& audioIn);

	IAudioInPi* 			__pAudioInInterface;
	__AudioInEvent*		__pAudioInEvent;
	IAudioInEventListener*   __pAudioInEventListener;
	static bool		__isConstructed;

	friend class AudioInEx;
	class AudioInEx* __pAudioInEx;	
};

};}; // Osp::Media

#endif




