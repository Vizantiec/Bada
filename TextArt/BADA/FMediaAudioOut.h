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
 * @file			FMediaAudioOut.h
 * @brief			This is the header file for the %AudioOut class.
 *
 * This header file contains the declarations of the %AudioOut class.
 */

#ifndef _FMEDIA_AUDIOOUT_H_
#define _FMEDIA_AUDIOOUT_H_

//include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioCommon.h"
#include "FMediaIAudioOutEventListener.h"

namespace Osp{ namespace Media{

class IAudioOutEventListener;
class __AudioOutEvent;
class IAudioOutPi;

/**
 * @class		AudioOut
 * @brief		This class plays raw audio data.
 * @since		1.0
 *
 * @remarks
 *  The maximum number of %AudioOut instances is @c 64. This number is a system wide count so that the application should not be able to construct more instances than the maximum number permitted. 
 *
 * The %AudioOut class plays raw audio data and provides methods for:
 * - Playing PCM data in various audio sample types
 * - Controlling volume
 *  
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_pcm_audio.htm">Playing PCM Audio</a>.
 *
 * The following example demonstrates how to use the %AudioOut class.

 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FIo.h>
 *
 * #define MAX_BUFFER_SIZE	2520 // 840 byte
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Base::Runtime;
 * using namespace Osp::Media;
 * using namespace Osp::Io;
 *
 *	class AudioOutExampleListener
 *		: public Osp::Media::IAudioOutEventListener
 *	{
 *	   public:
 *		void OnAudioOutBufferEndReached(Osp::Media::AudioOut& src);
 *		void OnAudioOutErrorOccurred(Osp::Media::AudioOut& src, result r);
 *		void OnAudioOutInterrupted(Osp::Media::AudioOut& src);
 *		void OnAudioOutReleased(Osp::Media::AudioOut& src);
 *	};
 *
 *	class AudioOutExample
 *	{
 *		// Lifecycle
 *	public:
 *		AudioOutExample(void);
 *		virtual ~AudioOutExample(void);
 *
 *	// Example Operation
 *	public:
 *		void AudioOutPlay(void);
 *	private:
 *	};
 * 
 * static int	__totalWriteBufferNum = 0;
 * static int	__playCount = 0;
 * static AudioOut* 	__pAudioOutInstance = null;
 * static ArrayList* 	__pDataArray = null;
 * static String*		__pAudioFilePath = null;
 * static AudioOutExampleListener* __pMyAudioOutListener = null;
 * 
 * AudioOutExample::AudioOutExample()
 * {
 * 	// Initialize the AudioOut
 * 	__pAudioFilePath = new String(L"/Media/ExampleRawPcm.dat");
 * 	__pAudioOutInstance = new AudioOut();
 * 	__pMyAudioOutListener = new AudioOutExampleListener;
 * 	__pDataArray = new ArrayList();
 * }
 * 
 * AudioOutExample::~AudioOutExample()
 * {
 * 	delete __pAudioFilePath;
 * 	__pAudioFilePath = null;
 * 
 * 	delete __pMyAudioOutListener;
 * 	__pMyAudioOutListener = null;
 * 
 * 	delete __pAudioOutInstance;
 * 	__pAudioOutInstance = null;
 * 
 * 	__pDataArray->RemoveAll(true);
 * 	delete __pDataArray;
 * 	__pDataArray = null;
 * 
 * }
 * 
 * void AudioOutExample::AudioOutPlay(void)
 * {
 * 	FileAttributes attribute;
 * 	File file;
 * 	ByteBuffer* pTotalData = null;
 * 	long long filesize = 0;
 * 
 * 	// Array Construct
 * 	__pDataArray->Construct();
 * 
 * 	// Read a file into buffer
 * 	file.Construct(*__pAudioFilePath, L"r");
 * 	file.GetAttributes(*__pAudioFilePath, attribute);
 * 	filesize = attribute.GetFileSize();
 * 	pTotalData = new ByteBuffer();
 * 	pTotalData->Construct((int)filesize);
 * 	file.Read(*pTotalData);
 * 	pTotalData->Flip();
 * 
 * 	// Binding data buffers into the array
 * 	if(pTotalData->GetLimit() > MAX_BUFFER_SIZE)
 * 	{
 * 		int totalSize = pTotalData->GetLimit();
 * 		int currentPosition = 0;
 * 		do
 * 		{
 * 			ByteBuffer* pItem = new ByteBuffer();
 * 			pItem->Construct(MAX_BUFFER_SIZE);
 * 			byte givenByte;
 * 			for(int i = 0; i < MAX_BUFFER_SIZE; i++)
 * 			{
 * 				// Read it per 1 byte
 * 				pTotalData->GetByte(currentPosition++,givenByte);
 * 				pItem->SetByte(givenByte);
 * 				if(currentPosition == totalSize ) break;
 * 			}
 * 			__pDataArray->Add(*pItem);
 * 
 * 		}while(currentPosition < totalSize);
 * 		__totalWriteBufferNum = __pDataArray->GetCount();
 * 	}
 * 	delete pTotalData;
 * 	pTotalData = null;
 * 
 * 	// Construct the AudioOut instance with a listener
 * 	__pAudioOutInstance->Construct(*__pMyAudioOutListener);
 * 
 * 	// AudioOut Preparation
 * 	__pAudioOutInstance->Prepare(AUDIO_TYPE_PCM_U8, AUDIO_CHANNEL_TYPE_STEREO,8000);
 * 
 * 	// Write 3 buffers in queue of the device side
 * 	ByteBuffer* pWriteBuffer = null;
 * 	pWriteBuffer = static_cast<ByteBuffer*>(__pDataArray->GetAt(__playCount++));
 * 	__pAudioOutInstance->WriteBuffer(*pWriteBuffer);
 * 	pWriteBuffer = static_cast<ByteBuffer*>(__pDataArray->GetAt(__playCount++));
 * 	__pAudioOutInstance->WriteBuffer(*pWriteBuffer);
 * 	pWriteBuffer = static_cast<ByteBuffer*>(__pDataArray->GetAt(__playCount++));
 * 	__pAudioOutInstance->WriteBuffer(*pWriteBuffer);
 * 
 * 	// Start playing until the end of the array
 * 	__pAudioOutInstance->Start();
 * 
 * }
 * 
 * 
 * void AudioOutExampleListener::OnAudioOutBufferEndReached(Osp::Media::AudioOut& src)
 * {
 * 	result r = E_SUCCESS;
 * 
 * 	if( __playCount == __totalWriteBufferNum)
 * 	{
 * 		// The End of array, it's time to finish
 * 		r = src.Unprepare();
 * 
 * 		//Reset Variable
 * 		__playCount = 0;
 * 		__totalWriteBufferNum = 0;
 * 
 * 	}else
 * 	{
 * 		//Not yet reached the end of array
 * 		//Write the next buffer
 * 
 * 		ByteBuffer* pWriteBuffer = static_cast<ByteBuffer*>(__pDataArray->GetAt(__playCount++));
 * 		r = src.WriteBuffer(*pWriteBuffer);
 * 	}
 * }
 * 
 * void AudioOutExampleListener::OnAudioOutErrorOccurred(Osp::Media::AudioOut& src, result r)
 * {
 * }
 * 
 * void AudioOutExampleListener::OnAudioOutInterrupted(Osp::Media::AudioOut& src)
 * {
 * }
 * 
 * void AudioOutExampleListener::OnAudioOutReleased(Osp::Media::AudioOut& src)
 * {
 * }
 * 
 * 
 * @endcode
 */

class _EXPORT_MEDIA_ AudioOut :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	AudioOut(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are released by this method.
	 * This method should be called in the same thread as the Construct() method.
	 *
	 * @since		1.0
	 * @see			Construct()
	 */
	virtual ~AudioOut(void);


// Operation
public:

	/**
	* Initializes this instance of the %AudioOut with the specified listener.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener				An event listener instance
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_RESOURCE_UNAVAILABLE	The AudioOut's resources are unavailable.
	*/
	result Construct( const Osp::Media::IAudioOutEventListener& listener);

	/**
	* Prepares an audio output device with the defined settings.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	audioSampleType			The type of the audio sample
	* @param[in]	audioChannelType		The type of the audio channel
	* @param[in]	audioSampleRate			The audio sample rate in @c Hertz
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT	The specified audio sample type is not supported.	
	* @see			Unprepare()
	*/
	result Prepare(AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	* Closes the audio output device.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Prepare()
	*/
	result Unprepare(void);

	/**
	* Sends the data buffer containing the audio data to be played to this audio output device. @n
	* When the end of the buffer is reached, the application gets the notification through %IAudioOutEventListener.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	userData			A pointer of the buffer containing the PCM data block
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_OVERFLOW			The specified input instance has overflowed.
	* @see			Start(), IAudioOutEventListener::OnAudioOutBufferEndReached()
	*/
	result WriteBuffer(const Osp::Base::ByteBuffer& userData);

	/**
	* Starts the specified audio output device.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_DEVICE_BUSY		The device cannot be approached because of other operations.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Stop()
	*/
	result Start(void);

	/**
	* Stops or pauses the playing of the audio output device. @n
	* The current position of the playback is stored internally and the playback will restart from this position 
	* when Start() is called again. 
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		Use Start() to resume the playback from the current playback position.
	* @see			Start(), IAudioOutEventListener::OnAudioOutBufferEndReached()
	*/
	result Stop(void);

	/**
	* Stops and resets playing of the audio output device. @n
	* All pending and current data buffers in the queue are removed immediately without any notification. The 
	* state is changed to AUDIOOUT_STATE_PREPARED.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result Reset(void);

	/**
	* Gets the state of the current audio output device.
	*
	* @since		1.0
	* @return		The state of current audio output 
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioOutState GetState(void) const;

	/**
	* Gets the maximum size of buffer that can be used with WriteBuffer(). @n
	* This maximum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since		1.0
	* @return		The maximum size of buffer, @n
	*				else @c -1 if an error occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The return value is available after calling the Prepare() method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMaxBufferSize(void) const;

	/**
	* Gets the minimum size of buffer that can be used with WriteBuffer(). @n
	* This minimum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since		1.0
	* @return		The minimum size of buffer, @n
	*				else @c -1 if an error occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The return value is available after calling the Prepare() method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMinBufferSize(void) const;

	/**
	* Gets the optimized sample type of the audio output device.
	*
	* @since		1.0
	* @return		The audio encoding type
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioSampleType GetOptimizedSampleType(void) const;

	/**
	* Gets the optimized channel type of the audio output device.
	*
	* @since		1.0
	* @return		The audio channel type
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioChannelType GetOptimizedChannelType(void) const;

	/**
	* Gets the optimized sample rate of the audio output device.
	*
	* @since		1.0
	* @return		The sample rate in @c Hertz
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int	GetOptimizedSampleRate(void) const;

	/**
	* Sets the volume level of the audio output device.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	volume				The new value for volume @n
	*									The range of this parameter is from @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified volume is out of range.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		This method should be called after Prepare().
	* @see			GetVolume()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume level of this audio output.
	*
	* @since		1.0
	* @return		The current volume level, @n
	*				else @c -1 if an error occurs @n
	*				This return value ranges from @c 0 to @c 100.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE     This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		This method should be called after calling the Prepare() method.
	* @see			SetVolume()
	*/
	int GetVolume(void) const;


private:
	AudioOut(const AudioOut& audioOut);
	AudioOut& operator =(const AudioOut& audioOut);

	IAudioOutPi* 			__pAudioOutInterface;
	__AudioOutEvent*		__pAudioOutEvent;
	IAudioOutEventListener*   __pAudioOutEventListener;

	friend class AudioOutEx;
	class AudioOutEx* __pAudioOutEx;	
};

};}; // Osp::Media

#endif




