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
 * @file			FMediaVideoRecorder.h
 * @brief			This is the header file for the %VideoRecorder class.
 *
 * This header file contains the declarations of the %VideoRecorder class.
 */

#ifndef _FMEDIA_VIDEORECORDER_H_
#define _FMEDIA_VIDEORECORDER_H_

// Include
#include "FMediaConfig.h"
#include "FMediaVideoRecorderCommon.h"
#include "FMediaIVideoRecorderEventListener.h"
#include "FMediaCamera.h"
#include "FMediaTypes.h"

namespace Osp{ namespace Media{

class __VideoRecorderEvent;
class IVideoRecorderPi;
class __VideoRecorderConfiguration;
class __VideoRecorderSourceManager;

/**
 * @class	VideoRecorder
 * @brief	This class records a video.
 * @since	1.0
 *
 *
 * The %VideoRecorder class provides video recording from the camera device. All the input sources must be 
 * controlled independently from the video recording operation. The supported codecs and resolutions are 
 * device-dependent and the available list can be retrieved using the methods available in this class.
 * The recording operation is limited by the maximum time or size.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/recording_video.htm">Recording Video</a>.
 *
 * The following example demonstrates how to use the %VideoRecorder class.
 *
 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FUi.h> 
 *
 * using namespace Osp::Media;
 * using namespace Osp::Base; 
 *
 * class VideoRecorderTestForm :
 *  public Osp::Ui::Controls::Form,
 *	public Osp::Ui::IActionEventListener,
 *	public Osp::Media::IVideoRecorderEventListener,
 *	public Osp::Media::ICameraEventListener
 * {
 *  // ...
 *  // Call-back functions.
 * public:
 *	virtual result OnInitializing(void);
 *	virtual result OnTerminating(void);
 *	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
 *  // ...
 * protected:
 *   virtual void OnVideoRecorderCanceled( result r );
 *   virtual void OnVideoRecorderClosed( result r );
 *   virtual void OnVideoRecorderEndReached(RecordingEndCondition endCondition);
 *   virtual void OnVideoRecorderErrorOccurred( RecorderErrorReason r );
 *   virtual void OnVideoRecorderPaused( result r );
 *   virtual void OnVideoRecorderStarted( result r );
 *   virtual void OnVideoRecorderStopped( result r );
 *
 *   virtual void OnCameraAutoFocused (bool completeCondition);
 *   virtual void OnCameraCaptured (Osp::Base::ByteBuffer &capturedData, result r);
 *   virtual void OnCameraErrorOccurred (CameraErrorReason err);
 *   virtual void OnCameraPreviewed (Osp::Base::ByteBuffer &previewedData, result r);
 *   static const int ID_BUTTON_RECORD = 101;
 *   static const int ID_BUTTON_STOP = 102;
 *  // ...
 * private:
 * 	 Osp::Media::Camera *__pCamera;
 *	 Osp::Media::VideoRecorder *__pVideoRecorder;
 *	 Osp::Ui::Controls::OverlayRegion *__pOverlayRegion;
 *	 Osp::Graphics::BufferInfo __previewBufferInfo;
 * //  ...
 * };
 *
 * result
 * VideoRecorderTestForm::OnInitializing(void)
 * {
 *   result r = E_SUCCESS;
 *
 *   // ... 
 *	Osp::Graphics::Rectangle rect(0, 0, 320, 240);
 *	bool modified=false;
 *	bool suitable = Osp::Ui::Controls::OverlayRegion::EvaluateBounds(Osp::Ui::Controls::OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN, rect, modified);
 *	if (!suitable)
 *	{
 *		r = GetLastResult();
 *		goto CATCH;	
 *	}
 *
 *	__pOverlayRegion = GetOverlayRegionN(rect, Osp::Ui::Controls::OVERLAY_REGION_TYPE_PRIMARY_CAMERA);
 *    	if (!__pOverlayRegion)
 *	{
 *		r = GetLastResult();
 *		goto CATCH;	
 *	}
 *
 *	 __pOverlayRegion->GetBackgroundBufferInfo(__previewBufferInfo);
 *
 *	 __pCamera = new Osp::Media::Camera();
 *	 r = __pCamera->Construct(*this);
 *	 if (IsFailed(r)) 
 *		goto CATCH;	
 *
 *	 r = __pCamera->PowerOn();
 *	 if (IsFailed(r)) 
 *		goto CATCH;	
 *
 *	 __pVideoRecorder = new Osp::Media::VideoRecorder();
 *	 r = __pVideoRecorder->Construct(*this, *__pCamera);
 *	 if (IsFailed(r))
 *		goto CATCH;	
 *
 *	 r = __pCamera->StartPreview(&__previewBufferInfo, false);
 *	 if (IsFailed(r)) 
 *		goto CATCH;	
 *   // ...
 *
 *      return r; 
 *
 *   CATCH:
 *	if ( __pOverlayRegion )
 *	{	
 *		delete __pOverlayRegion;
 *		__pOverlayRegion = null;
 *	}
 *      return r;
 * }
 *
 * // ...
 * 
 * void
 * VideoRecorderTestForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
 * {
 *	 result r;
 *
 *	switch(actionId)
 *	{
 *	case ID_BUTTON_RECORD:
 *		{
 *			String filename(L"test.mp4");
 *
 *			r = __pVideoRecorder->CreateVideoFile(filename, true);
 *			if (IsFailed(r))
 *             break;
 *
 *			r = __pVideoRecorder->Record();
 *			if (IsFailed(r))
 *             break;
 *		}
 *		break;
 *
 *	case ID_BUTTON_STOP:
 *		{
 *			r = __pVideoRecorder->Stop();
 *			if (IsFailed(r))
 *			   break;
 *		}
 *		break;
 *   // ...
 *  } // end of switch.
 *	// ... 
 * }
 *
 * @endcode
 *
 */
class _EXPORT_MEDIA_ VideoRecorder :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 * @remarks	After creating an instance of this class, the Construct() method must be called explicitly to 
	 * initialize this instance.
	 * @see 	Construct()
	 */
	VideoRecorder(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are deallocated by this method. This method should be called in the same thread in 
	 * which the Construct() method is called.
	 *
	 * @since	1.0
	 * @see 	Construct()
	 */
	virtual ~VideoRecorder(void);


// Operation
private:
	/**
	* Initializes the video recorder interface.
	*
	*  	@internal
	*	@return		An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state 
	* of this instance.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	result __InitializePi(void);
public:

	/**
	* Initializes this instance of %VideoRecorder with an associated listener and an input source.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener			An event listener object
	* @param[in]	camera				A Camera object for the input source
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_DEVICE_BUSY		The device cannot be approached because of other operations.
	*/
	result Construct( const IVideoRecorderEventListener& listener, const Camera& camera);

	/**
	* Creates a video file for a recording.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	destMediaPath				The destination for the file be written @n
	*											The available paths start with prefixes such as: @n
	*											@li "/Media/" @n
	*											@li "/Storagecard/Media/" @n
	*											@li "/Home/" (user home storage)
	* @param[in]	overwrite	 				Set to @c true to overwrite the file, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_RESOURCE_UNAVAILABLE		The required file path is unavailable.
	* @exception	E_FILE_ALREADY_EXIST		The specified file already exists.
	* @exception	E_STORAGE_FULL				The storage is full.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @see 			Close()
	* @remarks 		The application can register newly created files into the Contents database using
	*   			Osp::Content::ContentManager::CreateContent() if the file's path starts with "/Media" 
	*   			or "/Storagecard/Media".
	*/
	result CreateVideoFile(const Osp::Base::String& destMediaPath, bool overwrite);

	/**
	* Closes the video file. @n
	* This is a synchronous method.
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
	* @see			CreateVideoFile()
	*/
	result Close(void);

	/**
	* Starts the recording. @n
	* Resumes the recording if Pause() has been called.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The device cannot be approached because of other operations.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks    	This method must be called after the input media source is started (for example, Camera::StartPreview()).
	* @see			Stop(), Pause()
	*/
	result Record(void);

	/**
	* Stops the recording.
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
	* Pauses the recording. @n
	* To resume the recording after this method is called, Record() must be called.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	  	The application does not have the privilege to call this method.
	* @see			Stop(), Record()
	*/
	result Pause(void);

	/**
	* Cancels the recording operation without saving the data.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	RECORDING
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		When this method is called, the state is changed to ::RECORDER_STATE_STOPPING.
	*				After IVideoRecorderEventListener::OnVideoRecorderCanceled is called, the state is changed to 
	*				::RECORDER_STATE_STOPPED.
	* @see			Record(), Stop()
	*/
	result Cancel(void);

	/**
	* Gets the state of a recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current state of the video recorder
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			CreateVideoFile(), Close(), Record(), Stop(), Pause(), RecorderState()
	*/
	RecorderState GetState(void) const;

	/**
	* Gets the current recording time.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current recording time in milliseconds, @n
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
	* @return		A @c long value indicating the current recording size in bytes, @n
	*				else @c -1 if the recording has not started as yet
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of the Camera.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	long GetRecordingSize(void) const;

	/**
	* Sets the maximum size for the recording in kilobytes.
	*
    * @deprecated    This method is deprecated.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	kbSize				The maximum size in kilobytes @n
	*									The specified size must be greater than @c 0.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE		The specified size is out of range.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The default size is 1024 kilobytes.
	* @see			GetMaxRecordingSize()
	*/
	result SetMaxRecordingSize(int kbSize);

	/**
	* Gets the maximum size set for the recording in kilobytes.
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
	* @exception	E_OUT_OF_MEMORY		 	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	 	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see	    	SetMaxRecordingSize()
	*/
	int GetMaxRecordingSize(void) const;

	/**
	* Sets the time limit for the recording in milliseconds.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	msTime				The maximum recording time in milliseconds @n
	*									The time must be greater than @c 0.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE		The specified time is out of range.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The default time is @c 60 seconds.
	* @see			GetMaxRecordingTime()
	*/
	result SetMaxRecordingTime(long msTime);

	/**
	* Gets the time limit of the recording in milliseconds.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		A @c long value indicating the maximum recording time in milliseconds @n
	*				else @c -1 if the recording has not started as yet
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMaxRecordingTime()
	*/
	long GetMaxRecordingTime(void) const ;

	/**
	* Sets the codec for the recorder. @n
	* Initially, the default codec from the internal configuration is set.
	*
	* @deprecated	This method is deprecated. @n 
	* Instead of using this method, use the SetFormat (CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that 
	* sets the audio/video codec and container together.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	codec					The codec name @n
	*										It should be one of the strings listed by GetSupportedCodecListN(). @n
	*										GetSupportedCodecListN() returns the list of strings in the following formats: @n 
	*										- "VIDEO_CODEC_H263" @n
	*										- "VIDEO_CODEC_MPEG4SP" @n
	*										The returned strings are different depending on each device. @n
	*										The following string is always operated upon. This value is different 
	*										for each device. @n
	*										"VIDEO_CODEC_DEFAULT": the default codec
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetCodec(), GetSupportedCodecListN()
	*/
	result SetCodec(const Osp::Base::String& codec);

	/**
	* Gets the codec for the recorder.
	*
	* @deprecated	This method is deprecated. @n
    * Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const 
	* method that gets the audio/video codec and container together.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current codec
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetCodec(), GetSupportedCodecListN()
	*/
	Osp::Base::String GetCodec(void) const;

	/**
	* Gets the list of supported video recorder codecs. @n
	* Each item in the list is a Osp::Base::String value.
	*
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetSupportedAudioCodecListN() and GetSupportedVideoCodecListN() methods.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	The list of strings that represents the supported video recorder codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* 	         	The return value must be released by the caller.
	*               All items in the list must be released by the caller.
	* @see			SetCodec(), GetCodec()
	*/
	Osp::Base::Collection::IList* GetSupportedCodecListN(void) const;

	/**
	* Gets the list of supported audio codecs. @n
	* Each item in the list has a ::CodecType value.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	A list of supported audio codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* 	         	The return value must be released by the caller.
	* @see  		SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container ),
    *				GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Osp::Base::Collection::IListT<CodecType>* GetSupportedAudioCodecListN(void) const;

	/**
	* Gets the list of supported video codecs. @n
	* Each item in the list has a ::CodecType value.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	A list of supported video codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* 	         	The return value must be released by the caller.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container ), GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Osp::Base::Collection::IListT<CodecType>* GetSupportedVideoCodecListN(void) const;

	/**
	* Gets the list of supported containers. @n
	* Each item in the list has a ::MediaContainerType value.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return     	A list of supported containers, @n
	*				else @c null if no container is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* 	         	The return value must be released by the caller.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container ), 
	*				GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Osp::Base::Collection::IListT<MediaContainerType>* GetSupportedContainerListN(void) const;

	/**
	* Sets the video format of the recorder. @n
	* Initially, the default format from internal configuration is set.
	*
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFormat (CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that sets 
	* the audio/video codec and container together.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[in]	format					The video format @n
	*										::VIDEORECORDING_FORMAT_DEFAULT sets the system's default recording format.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetFormat()
	*/
	result SetFormat(VideoRecordingFormat format);

	/**
	* Gets the current format that has been set for the recorder.
	*
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const method 
	* that gets the audio/video codec and container together.
	*
	* @since		1.0 
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current video format, @n
	* 				else the default format if SetFormat() is not called before this method
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetFormat()
	*/
	VideoRecordingFormat GetFormat(void) const;

	/**
	* Sets the mode of the recorder.
	*
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFormat (CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that 
	* determines whether the video recorder includes the audio codec. 
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	mode				The mode for the recording @n
	*									The default mode is ::VIDEORECORDER_MODE_VIDEO_WITH_AUDIO.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG		The specified @c mode is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetMode()
	*/
	result SetMode(VideoRecorderMode mode);

	/**
	* Gets the mode of the recorder.
	*
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const 
	* method that determines whether the video recorder includes the audio codec.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current mode
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMode()
	*/
	VideoRecorderMode GetMode(void) const;

	/**
	* Sets the audio and video codecs, and the container of the recorder. @n
	* Initially, the default codec and container format are set with the internal configuration.
	*
	* @since 		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[in]	audioCodec				The audio codec to set @n
	*										::CODEC_NONE makes the audio stream empty.
	* @param[in]	videoCodec				The video codec to set @n
	*										::CODEC_NONE cannot be set.
	* @param[in]	container				The media container to set
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified container format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		If the audio codec is ::CODEC_NONE, the audio will be ignored, and only the video stream will be recorded.
	*				If the specified container does not support the specified codec, E_UNSUPPORTED_FORMAT may be thrown.
	* @see			GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	result SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container );

	/**
	* Gets the audio and video codecs, and the container of the recorder.
	*
	* @since		2.0
	* @privlevel	NORMAL
	* @privgroup 	RECORDING
	* @return		An error code
	* @param[out]	audioCodec			The retrieved audio codec
	* @param[out]	videoCodec			The retrieved video codec	
	* @param[out]	container			The retrieved container
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The default codecs and container are retrieved, if SetFormat( CodecType audioCodec, CodecType 
	*				videoCodec, MediaContainerType container) is not called before calling this method.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container )
	*/
	result GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const;

	/**
	* Sets the quality of the recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]	quality				The quality of the recorder @n
	*									The default quality is ::RECORDING_QUALITY_MEDIUM.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG		The specified @c quality is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetQuality()
	*/
	result SetQuality(RecordingQuality quality);

	/**
	* Gets the quality of the recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The current quality
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetQuality()
	*/
	RecordingQuality GetQuality(void) const;

	/**
	* Sets the recording resolution of the recorder. @n
	* Initially, the default resolution from the internal configuration is set.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	RECORDING
	* @return		An error code
	* @param[in]	resolution			The recording resolution @n
	*									It should be one of the listed strings extracted from 
	*									GetSupportedRecordingResolutionListN().
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_RANGE		The specified resolution is out of range.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		If the input source is Osp::Media::Camera, its preview resolution value should be same as that 
	*				of this recording resolution.
	* @see			GetRecordingResolution(), GetSupportedRecordingResolutionListN()
	*/
	result SetRecordingResolution(const Osp::Graphics::Dimension& resolution);

	/**
	* Gets the recording resolution.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The recording resolution
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetRecordingResolution(), GetSupportedRecordingResolutionListN()
	*/
	Osp::Graphics::Dimension GetRecordingResolution(void) const;

	/**
	* Gets a list of the supported video recorder resolutions. @n
	* Each list item is a Osp::Graphics::Dimension value.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		A list of strings representing the supported video recorder resolutions, @n
	*				else an empty list if no recording resolution is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*				The return value must be released by the calling method.
	*				All items in the list must be released by the calling method.
	*				This method works after the input media source is initialized (for example, Camera::PowerOn()).
	* @see			SetRecordingResolution(), GetRecordingResolution()
	*/
	Osp::Base::Collection::IList* GetSupportedRecordingResolutionListN(void) const;

	/**
	* Gets the maximum supported frame rate of the input resolution.
	*
	* @since		2.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The maximum frame rate of the input recording resolution
	* @param[in]	dim						The preview resolution of the Camera 
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			The specified input resolution is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult method.
	*				This method works after the input media source is initialized (for example: Camera::PowerOn()).
	* @see			Camera::SetPreviewFrameRate()
	*/
	int GetSupportedMaxFrameRate(const Osp::Graphics::Dimension& dim) const;

	/**
	* Enables or disables the mute state of a recorder.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		An error code
	* @param[in]  	mute     			Set to @c true to enable the mute state of the recorder, @n
	*									else @c false
	*          							By default, the mute state is disabled.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The recording continues even in the mute state.
	* @see			IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks whether the mute state of the recorder is enabled.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	RECORDING
	* @return		The mute state of the recorder 
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
	* Gets the value of the system information as a string.
	*
	* @return     	An error code
	* @param[in]	key 				The keyword to find
	* @param[in]	value 				A string representing the system information
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result __GetSystemInfoStringValue ( Osp::Base::String& key, Osp::Base::String& value ) const;

	VideoRecorder(const VideoRecorder& videoRecorder);
	VideoRecorder& operator =(const VideoRecorder& videoRecorder);

	IVideoRecorderPi* 			__pVideoRecorderInterface;
	__VideoRecorderEvent*     __pVideoRecorderEvent;
	IVideoRecorderEventListener*	__pVideoRecorderEventListener;
	__VideoRecorderConfiguration*		__pConfiguration;
	__VideoRecorderSourceManager*	__pVideoRecorderSourceManager;
	static bool			__isConstructed;

	friend class VideoRecorderEx;
	class VideoRecorderEx* __pVideoRecorderEx;
};



};};// Osp::Media

#endif



