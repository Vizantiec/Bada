/* $Change: 1145128 $ */
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
 * @file			FMediaPlayer.h
 * @brief			This is the header file for the %Player class.
 *
 * This header file contains the declarations of the %Player class.
 */

#ifndef _FMEDIA_PLAYER_H_
#define _FMEDIA_PLAYER_H_
// Include
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaPlayerCommon.h"
#include "FMediaIPlayerEventListener.h"
#include "FMediaIPlayerVideoEventListener.h"
#include "FMediaMediaStreamInfo.h"

namespace Osp{ namespace Media {

class __PlayerEvent;
class __PlayerVideoEvent;
class __PlayerConfiguration;
class IPlayerPi;

/**
 * @class	Player
 * @brief	This class provides methods to play audio and video.
 * @since	1.0
 *
 * The %Player class provides methods to play audio and video, including:
 * - Playing the audio or video content stored in the local storage (internal and external memory).
 * - Playing the audio or video content stream from the content server over RTSP or HTTP. 
 * - Operating general controls for the audio or video content, such as play, pause, resume, and stop.
 * - Moving the audio or video content on the basis of time.
 * - Controlling the volume of the audio or video content.
 * - Looping the audio or video content.
 * - Getting the duration of an audio or the video content.
 * - Playing back multiple audio streams.
 *
 *
 *  The maximum count of the %Player instance is @c 10.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_audio.htm">Playing Audio</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/playing_video.htm">Playing Video</a>.
 *
 * The following example demonstrates how to use the %Player class to play an audio or video file.
 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FGraphics.h>
 * #include <FUi.h>
 * #include <FApp.h>
 *
 * using namespace Osp::Media;
 * using namespace Osp::App;
 * using namespace Osp::Graphics; 
 *
 * class MyPlayerListener
 * 	: public IPlayerEventListener
 * {
 * 	public:
 * 	MyPlayerListener() {
 * 	}
 * 	void OnPlayerOpened(result r);
 * 	void OnPlayerEndOfClip(void);
 * 	void OnPlayerBuffering(int percent);
 * 	void OnPlayerErrorOccurred(PlayerErrorReason r );
 * 	void OnPlayerInterrupted();
 * 	void OnPlayerReleased();
 * 	void OnPlayerSeekCompleted(result r);
 * };
 * 
 * static  Player* __pPlayer = null;
 * static	MyPlayerListener* __pListener = null;
 * String	path0("SampleFile0.aac");
 * String	path1("SampleFile1.mp4");
 * 
 * // The player's listener should be implemented to control asynchronously.
 * void MyPlayerListener::OnPlayerOpened(result r)
 * {
 * // This listener is used when OpenXXX() is set to work asynchronously.
 * 	// Insert your code to operate after the resource is opened.
 * 	result rt = E_SUCCESS;
 * 	rt = __pPlayer->Play();
 * 
 * 	if (IsFailed(rt))
 * 	{
 * 		// Need to handle the exception.
 * 	}
 * }
 * 
 * 
 * void MyPlayerListener::OnPlayerEndOfClip(void)
 * {
 * 	// Insert your code to operate after the player reaches end of clip.
 * 	result r = E_SUCCESS;
 * 	r = __pPlayer->Close();
 * 	if (IsFailed(r))
 * 	{
 * 		// Handle the exception.
 * 	}
 * }
 * 
 * 
 * void MyPlayerListener::OnPlayerBuffering(int percent)
 * {
 * 	// Insert your code to operate while the buffering for a remote resource is going on.
 * }
 * 
 * void MyPlayerListener::OnPlayerErrorOccurred(PlayerErrorReason r )
 * {
 * 	// Insert your code to operate after any error occurred.
 * }
 * 
 * void MyPlayerListener::OnPlayerInterrupted()
 * {
 * 	// Insert your code here.
 * }
 * 
 * void MyPlayerListener::OnPlayerReleased()
 * {
 * 	// Insert your code here.
 * }
 * 
 * void MyPlayerListener::OnPlayerSeekCompleted(result r)
 * {
 * 	// Insert your code here.
 * }
 * 
 * result TestAudioPlaying(void)
 * {
 * 	result r = E_SUCCESS;
 * 	if(!__pPlayer){
 * 
 * 		__pPlayer = new Player();
 * 		__pListener = new MyPlayerListener;
 * 
 * 		// Create audio player.
 * 		r = __pPlayer->Construct(*__pListener, 0);
 * 		if (IsFailed(r)) goto CATCH;
 * 	}
 * 
 * 	// Open file asynchronously.
 * 	r = __pPlayer->OpenFile(path0, true);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->SetLooping(true);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->SetVolume(80);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * CATCH:
 * 	delete __pPlayer;
 *  	delete __pListener;
 * 
 * 	return r;
 * }
 * 
 * result TestVideoPlaying(void)
 * {
 * 	result r = E_SUCCESS;
 * 	Osp::Ui::Controls::OverlayRegion *pRegion = null;
 * 	Osp::Ui::Controls::Form* pPlayerForm = null;
 * 	Osp::Graphics::BufferInfo bufferInfo;
 * 
 * 	pPlayerForm = Application::GetInstance()->GetAppFrame()->GetFrame()->GetCurrentForm();
 * 	pRegion = pPlayerForm->GetOverlayRegionN(Rectangle(0,0,320,240),OVERLAY_REGION_TYPE_NORMAL);
 * 
 * 	r = pRegion->GetBackgroundBufferInfo(bufferInfo);
 * 	if (IsFailed(r)) { goto CATCH; }
 * 
 * 	if(!__pPlayer)
 * 	{
 * 		Player* __pPlayer = new Player();
 * 		__pListener = new MyPlayerListener;
 * 
 * 		// Create video player.
 * 		r = __pPlayer->Construct(*__pListener, &bufferInfo);
 * 		if (IsFailed(r)) goto CATCH;
 * 	}
 * 
 * 	// Open file asynchronously.
 * 	r = __pPlayer->OpenFile(path1, true);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->SetVolume(80);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * CATCH:
 * 	delete __pPlayer;
 * 	delete __pListener;
 * 
 * 	return r;
 * }
 * 
 *
 * @endcode
 *
 * The following example demonstrates how to use the %Player class to get a video frame through the video event listener. 
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FGraphics.h>
 * 
 * 
 * class MyVideoFrame :
 * 		IPlayerEventListener,
 * 		IPlayerVideoEventListener
 * {
 * public:
 * 	MyVideoFrame(){};
 * 	~MyVideoFrame(){};
 * 
 * public:
 * 	void OnPlayerOpened(result r){};
 * 	void OnPlayerEndOfClip(void){};
 * 	void OnPlayerBuffering(int percent){};
 * 	void OnPlayerErrorOccurred(PlayerErrorReason r ){};
 * 	void OnPlayerInterrupted(){};
 * 	void OnPlayerReleased(){};
 * 	void OnPlayerSeekCompleted(result r){};
 * 	void OnVideoFrameDecoded (Osp::Media::Player &src, Osp::Graphics::BitmapPixelFormat bitmapPixelFormat, const Osp::Graphics::Dimension &dim, const byte *pBuffer, int sizeOfBuffer, result r);
 * 
 * public:
 * 	result TestGetVideoFrame(void);
 * 
 * private:
 * 	Player* pPlayer;
 * };
 * 
 * void
 * MyVideoFrame::OnVideoFrameDecoded (Osp::Media::Player &src, Osp::Graphics::BitmapPixelFormat bitmapPixelFormat, const Osp::Graphics::Dimension &dim, const byte *pBuffer, int sizeOfBuffer, result r)
 * {
 * 	ByteBuffer buf;
 * 	Bitmap bitmap;
 * 
 * 	if(r == E_SUCCESS)
 * 	{
 * 		buf.Construct(sizeOfBuffer);
 * 		buf.SetArray(pBuffer, 0, sizeOfBuffer);
 *		buf.Flip();
 * 		// Get the bitmap using the video frame.
 * 		bitmap.Construct(buf, dim, bitmapPixelFormat);
 * 	}
 * }
 * 
 * result MyVideoFrame::TestGetVideoFrame(void)
 * {
 * 	result r = E_SUCCESS;
 * 
 * 	pPlayer = new Player;
 * 	r = pPlayer->Construct(*this, *this);
 * 	if(IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 * 
 * 	r = pPlayer->OpenFile(String("SampleFile1.mp4"));
 * 	if(IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 * 
 * 	// Request get the first video frame.
 * 	 pPlayer->CaptureVideo();
 * 	return r;
 * 
 * CATCH:
 * 	delete pPlayer;
 * 	return r;
 * }
 * @endcode
 *
 */

class _EXPORT_MEDIA_ Player :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to 
	* 			initialize this instance.
	* @see		Construct()
	*/
	Player(void);

	/**
	* This is the destructor for this class. @n
	* This method deallocates the resources. This method should be called in the same thread as the Construct() 
	* method.
	*
	* @since	1.0
	* @see		Construct()
	*/
	virtual ~Player(void);

// Operation
private:
	/**
	* Initializes the audio or video player interface.
	*
	* @internal
	* @return		An error code
	* @exception	E_SUCCESS			 The method is successful.
	* @exception	E_INVALID_STATE      This method is invalid for the current state of this instance.
	*                                               
	* @exception	E_SYSTEM			 A system error has occurred.
	*/
	result __InitializePi(void);

public:

	/**
	* Initializes this instance of %Player.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener					An event listener instance
	* @param[in]	pBufferInfo					The buffer information to display the video  @n
	*											This information is essential to play a video but not required for an audio content.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_RESOURCE_UNAVAILABLE		The player's resources are unavailable.
	* @remarks 		Multiple instances of %Player can be constructed.
	*/
	result Construct( const IPlayerEventListener& listener, const Osp::Graphics::BufferInfo* pBufferInfo=null);

	/**
	* Opens an audio or video file to be played. @n
	* This method works synchronously, but when the second parameter, @c isAsync is set to @c true, this method works asynchronously. 
	* Note that a method that works asynchronously should implement a listener.
	*
	* @since			1.0
	* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*				   	For more information, see @ref refOpenFile "here".
	* @return			An error code
	* @param[in]		mediaLocalPath			The local file path of the media source
	* @param[in]		isAsync					Set to @c true for the asynchronous mode, @n
	*											else @c false for the synchronous mode
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception		E_SYSTEM				A system error has occurred.
	* @exception		E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception		E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception		E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception  		E_INVALID_DATA     		The specified file contains invalid data.
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @see				Close()
	*/
	result OpenFile(const Osp::Base::String& mediaLocalPath, bool isAsync=false);

	/**
	* @page  	refOpenFile Compatibility for OpenFile()
	* @section 	CompMediaPlayerOpenFilePageIssueSection Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# When opening a specific media file that contains an invalid data, this method throws E_SUCCESS. @n
	*
	* @section CompMediaPlayerOpenFilePageResolutionSection Resolutions
	*  The issue mentioned above is resolved in bada API version 2.0 as follows. @n
	*  -# When opening a specific media file that contains an invalid data, this operation throws E_INVALID_DATA. @n
	*/
	
	/**
	* Opens an audio or video streaming content to play through the specified URL. @n
	* This method works synchronously, but when the second parameter @c isAsync is set to @c true,
    * this method works asynchronously. Note that a method that works asynchronously should implement a listener.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	mediaUri				The URL of the media source
	* @param[in]	isAsync					Set to @c true for the asynchronous mode, @n
	*										else @c false for the synchronous mode
 	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE	        This method is invalid for the current state of this instance.
	* @exception	E_CONNECTION_FAILED		The network connection has failed.
	* @exception	E_UNSUPPORTED_PROTOCOL	The protocol is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		This method is not thread-safe when @c isAsync is @c false.
	* @see			Close()
	*/
	result OpenUrl(const Osp::Base::Utility::Uri& mediaUri, bool isAsync=false);

	/**
	* Opens an audio or video content to play on the memory. @n
	* This method works synchronously, but when the second parameter @c isAsync is set to @c true, this method works asynchronously. 
	* Note that a method that works asynchronously should implement a listener.
	*
	* @since			1.0
	* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                	For more information, see @ref refOpenBuffer "here".
	* @return			An error code
	* @param[in]		mediaBuffer				A pointer to the media source in the external memory
	* @param[in]		isAsync					Set to @c true for asynchronous mode, @n
	*											else @c false for synchronous mode
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_STATE	    	This method is invalid for the current state of this instance.
	* @exception		E_SYSTEM				A system error has occurred.
	* @exception		E_OBJ_NOT_FOUND			The specified media buffer cannot be found.
	* @exception		E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception		E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception 		E_INVALID_DATA     		The specified buffer contains invalid data.
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks			DRM content cannot be played by this method.
	* @see				Close()
	*/
	result OpenBuffer(const Osp::Base::ByteBuffer& mediaBuffer, bool isAsync=false);

	/**
	* @page  	refOpenBuffer Compatibility for OpenBuffer()
	* @section 	CompMediaPlayerOpenBufferPageIssueSection Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# When opening a specific media buffer that contains an invalid data, this method throws E_SUCCESS. @n
	*
	* @section CompMediaPlayerOpenBufferPageResolutionSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 as follows. @n
	* -# When opening a specific media buffer that contains an invalid data, this operation throws E_INVALID_DATA.
	*/
	
	/**
	* Closes the audio or video content. @n
	* This method works synchronously.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE     This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			OpenFile(), OpenBuffer(), OpenUrl()
	*/
	result Close(void);

	/**
	* Starts the playback or resumes the playback of the audio or video content after Pause() is called. @n
	* The playback starts from the current position. In case of the ::PLAYER_STATE_ENDOFCLIP player state, the audio or video content 
	* is played again.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_DEVICE_BUSY		The device cannot be approached because of other operations.
	* @exception	E_SYSTEM			A system error has occurred. @n
	*									If playback has been paused, it resumes from the last position. @n
	*									E_SYSTEM is thrown when unsupported format or codec media data are received during streaming. @n
										E_SYSTEM is thrown when the unsupport resolution is set for rendering @b since: @b 2.0.
	* @remarks		When this method is called after the %Player instance is created with the Construct() method that accepts the IPlayVideoEventListener 
	* interface as a parameter, it delivers every video frame of a video content continuously until the state is changed to PLAYER_STATE_ENDOFCLIP, 
	* or the Stop() or Pause() method is called @b since: @b 2.0.
	* @see			Stop(), Pause(), IPlayerVideoEventListener
	*/
	result Play(void);

	/**
	* Stops the playback of the audio or video content. This method works synchronously.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE       	This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		In the Real Time Streaming Protocol (RTSP), this method stops the media stream and requests the termination of the network session.
	* @see			Play(), Pause()
	*/
	result Stop(void);

	/**
	* Pauses the playback of the audio or video content. @n
	* To resume the playback, the Play() method should be called. This method works synchronously.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE     This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Play(), Stop()
	*/
	result Pause(void);

	/**
	* Gets the state of an audio or video player.
	*
	* @since		1.0
	* @return		The current state of the player
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			Close(), Play(), Stop(), Pause(), PlayerState
	*/
	PlayerState GetState(void) const;

	/**
	* Gets the time for the current playback position of the audio or video content. @n
	* Accuracy of the retrieved time is determined by the subsystem (for example, the time slice of the OS scheduler,
	* time resolution of the audio or video codec, or implementation of the audio or video player).
	* Note that it should not be assumed that this method can reach the exact position mentioned by GetDuration().
	*
	* @since		1.0
	* @return		The current position of the player in milliseconds
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SeekTo()
	*/
	long GetPosition(void) const;

	/**
	* Changes the current playback position of the audio or video content to the specified time. @n
	* This method works asynchronously. @n
	* Note that a method that works asynchronously should implement a listener. @n
	* This method only works for the PLAYER_STATE_PLAYING and PLAYER_STATE_PAUSED states of the player. @n
	* This method changes the playback position as well as the time value. @n
	* In video, it may not change position accurately.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with different bada API versions @b prior @b to @b 1.2. @n
	*                For more information, see issues in version @ref CompMediaPlayerSeekTo1 "1.2" and @ref CompMediaPlayerSeekTo2 "2.0".
	*
	* @return		An error code
	* @param[in]	msTime				The time in milliseconds to move to the current playback position @n
	*									@c 0 indicates the starting position.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE   	This method is invalid for the current state of this instance. @n
	*					  		  		While playing live streaming, this operation returns E_INVALID_STATE. @n
	*							  		This method returns E_INVALID_STATE, if this method is called again before  
	*									IPlayerEventListener::OnPlayerSeekCompleted() is called.
	* @exception	E_OUT_OF_RANGE		The specified time is out of range.
	* @exception	E_INVALID_DATA      The media data is inappropriate for seeking.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		For video, this method delivers one video frame on the specified position through the video 
	*				event. Before calling this method, the %Player instance should be created with the Construct() 
	*				method has a parameter of the IPlayVideoEventListener interface @b since: @b 2.0.
	* @see			GetPosition(), 	IPlayerVideoEventListener
	*/
	result SeekTo(long msTime);
	
	/**
	* @page  	CompMediaPlayerSeekTo1 Compatibility for SeeKTo()
	* @section 	CompMediaPlayerSeekToPageIssueSection Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 
	* -# While seeking a specific position over a duration of time for a media object in MID/MMF/MXMF/XMF/SPM/IMY 
	* formats, this operation throws E_SYSTEM without moving to the position. @n
	* However, in other formats this operation throws E_SUCCESS by moving to the specified position.
	*    
	* @section CompMediaPlayerSeekToPageResolutionSection Resolutions
	*
	* The issue mentioned above is resolved in bada API version 1.2 as follows. @n
	* -# While seeking a specific position over a duration of time for a media object in every 
	* format, this operation throws E_OUT_OF_RANGE without moving to the specified position.
	*/
	
	/**
	* @page  	CompMediaPlayerSeekTo2 Compatibility for SeeKTo()
	* @section 	CompMediaPlayerSeekToPageIssueSection Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	* 
	* -# While seeking a specific position of the video file that has one key frame,
	*    this operation throws E_SYSTEM with the state changing to PLAYER_STATE_ERROR. 
	*
    * -# When seeking a specific position of a media content in the PLAYER_STATE_OPENED or PLAYER_STATE_STOPPED state,
    *    this operation throws E_INVALID_STATE. This method only works for the PLAYER_STATE_PLAYING and PLAYER_STATE_PAUSED states of the player. @n
	*
	* @section CompMediaPlayerSeekToPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0 as follows. @n
	*  
	* -# While seeking a specific position of the video file that has one key frame,
	*    this operation throws E_INVALID_DATA and the state of player instance is not changed.
	*
    * -# While seeking a specific position of a media content in the PLAYER_STATE_OPENED, PLAYER_STATE_STOPPED, PLAYER_STATE_PLAYING, and PLAYER_STATE_PAUSED states of the %Player instance,
	*    this operation throws E_SUCCESS.
	*/

	/**
	* Gets the total running time of the opened media source.
	*
	* @since			1.0	
	* @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*                  	For more information, see @ref CompMediaPlayerGetDuration "here".
	* @return			The running time of the media source in milliseconds
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*					While playing live streaming, this operation returns @c 0.
	* @see				GetPosition()
	*/
	long GetDuration(void) const;
	
	/**
	* @page  	CompMediaPlayerGetDuration Compatibility for GetDuration()
	* @section 	CompMediaPlayerGetDurationPageIssueSection Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* -# This method returns an incorrect duration when OpenUrl() is called asynchronously.
	*
	* @section CompMediaPlayerGetDurationPageResolutionSection Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows: @n
	* -# This method returns correct duration when OpenUrl() is called asynchronously.
	*/

	/**
	* Sets the specified value for the volume of an audio or video player.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	volume			The new value of volume @n
	*								The range of this parameter is @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_RANGE	The specified volume is out of range.
	* @exception	E_INVALID_STATE This method is invalid for the current state of this instance.
	* @see			GetVolume(), IsMuted(), SetMute()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume of an audio or video player.
	*
	* @since		1.0
	* @return		The current volume level @n
	*				The range of this return value is @c 0 to @c 100.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			SetVolume(), IsMuted(), SetMute()
	*/
	int GetVolume(void) const;

	/**
	* Sets the mute status of an audio or video player.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	mute				Set to @c true to mute the audio or video player, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @see 			GetVolume(), SetVolume(), IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks the mute status of an audio or video player.
	*
	* @since		1.0
	* @return		@c true if the audio or video player is muted, @n
	*				else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see 			GetVolume(), SetVolume(), SetMute()
	*/
	bool IsMuted(void) const;

	/**
	* Sets an audio or video player to be in a loop. @n
	* Set the looping to @c true to continuously play the audio or video content.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	looping	 			Set to @c true to play the audio or video content in a loop, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		In streaming, this method throws E_INVALID_STATE for the cost of network.
	* @see 			IsLooping()
	*/
	result SetLooping(bool looping);

	/**
	* Checks whether the audio or video player is in a loop.
	*
	* @since		1.0
	* @return		@c true if the audio or video player is in a loop, @n
	*				else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see 			SetLooping()
	*/
	bool IsLooping(void);

	/**
	* Gets the current media stream information.
	*
	* @since 		2.0
	* @return      	A pointer to the MediaStreamInfo instance containing metadata for the current media stream
	* @exception   	E_SUCCESS			The method is successful.
	* @exception   	E_INVALID_STATE  	This method is invalid for the current state of this instance.
	* @exception   	E_INVALID_CONTENT   The content is inappropriate to compose media stream information.
	* @exception   	E_SYSTEM            A system error has occurred.
	* @remarks      	This method returns a stream information of the media, which is currently being played.
	*      			The specific error code can be accessed using the GetLastResult() method.
	*               This method should be called after Play() to get the correct data.
	* @see 			MediaStreamInfo
	*/
	MediaStreamInfo* GetCurrentMediaStreamInfoN(void);

	/**
	* Sets the rendering buffer for the video playback.
	*
	* @since		2.0
	* @return      	An error code
	* @param[in]	bufferInfo			The buffer information to display the video
	* @exception   	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_SYSTEM			A system error has occurred. @n
										E_SYSTEM is thrown when the unsupport resolution is set for rendering @b since: @b 2.0.
	* @remarks     	This method works for the PLAYER_STATE_OPENED, PLAYER_STATE_ENDOFCLIP, PLAYER_STATE_STOPPED, PLAYER_STATE_PAUSED, and PLAYER_STATE_PLAYING states of the player.
	* 		This method throws E_INVALID_STATE after the player instance is constructed with IPlayerVideoEventListener.
	*/
	result SetRenderingBuffer(const Osp::Graphics::BufferInfo& bufferInfo);

	/**
    * Initializes this instance of %Player with the video event listener in addition to the player event listener.
    *   
	* @since       	2.0
    * @return      	An error code
    * @param[in]   	listener                    An IPlayerEventListener instance
    * @param[in]   	videoListener               An IPlayerVideoEventListener instance
    * @exception   	E_SUCCESS                   The method is successful.
    * @exception   	E_INVALID_STATE             This method is invalid for the current state of this instance.
    * @exception   	E_SYSTEM                    A system error has occurred.
    * @exception   	E_RESOURCE_UNAVAILABLE      The player's resources are unavailable.
    * @remarks     	This method constructs the %Player instance to render the video content into the buffer of the video event listener.
	* @see 			IPlayerVideoEventListener
	*/
    result Construct(const IPlayerEventListener& listener, const IPlayerVideoEventListener& videoListener);

	/**
    * Captures the video frame. @n
    * This method delivers one video frame of a video content by using the IPlayVideoEventListener interface only once in the %Player instance. @n
    * This method works only for the PLAYER_STATE_OPENED state of the %Player instance, and the state of the %Player instance is changed to PLAYER_STATE_PAUSED from PLAYER_STATE_OPENED after calling this method.
    *
    * @since       	2.0
    * @return      	An error code
    * @exception   	E_SUCCESS				The method is successful.
    * @exception   	E_INVALID_STATE			This method is invalid for the current state of this instance. @n
    *										This method throws E_INVALID_STATE if the %Player instance is 
	*										constructed without IPlayerVideoEventListener.
	* @exception   	E_INVALID_OPERATION		This method is invalid for the current media content.
    * @exception   	E_SYSTEM				A system error has occurred.
	* @remarks     	In the Real Time Streaming Protocol (RTSP), this method does not work properly.
	* @see 			IPlayerVideoEventListener
    */
    result CaptureVideo(void);

	/**
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this method.
	*
	* @prohibited  This method is prohibited. If this method is used in an application, the 
	* application can get rejected during the certification process.
	*
	* Initializes this instance of %Player with the video event listener in addition to the player event listener with gc handle.
    *
	* @since       	2.0
    * @return      	An error code
    * @param[in]   	listener                    An IPlayerEventListener instance
    * @param[in]   	videoListener               An IPlayerVideoEventListener instance
	* @param[out]  	gcHandle		            An gcHandle
    * @exception   	E_SUCCESS                   The method is successful.
    * @exception   	E_INVALID_STATE             This method is invalid for the current state of this instance.
    * @exception   	E_SYSTEM                    A system error has occurred.
    * @exception   	E_RESOURCE_UNAVAILABLE      The player's resources are unavailable.
    * @remarks     	This method constructs the %Player instance to render the video content into the buffer of the video event listener.
	* @see 			IPlayerVideoEventListener
	*/
    result _Construct(const IPlayerEventListener& listener, const IPlayerVideoEventListener& videoListener, int &gcHandle);

	/**
	* @if PRIVCORE
	* Initializes this instance of %Player on the highest priority.
	*
	* @since          2.0
	* @privlevel      CORE
	* @privgroup      PLAYER_PRIORITIZER
	* @return         An error code
	* @param[in]     listener                          An event listener instance
	* @param[in]     pBufferInfo                       The buffer information to display the video @n
	*                                                  This information is essential to play a video but not required for an audio content.
	* @param[in]     setAsHighestPriority              Set to @c true for working on the hightest priority, @n
													   else @c false for the normal mode.
	* @exception      E_SUCCESS                        The method is successful.
	* @exception      E_INVALID_STATE                  This method is invalid for the current state of this instance.
	* @exception      E_SYSTEM                         A system error has occurred.
	* @exception      E_RESOURCE_UNAVAILABLE           The player's resources are unavailable.
	* @exception	  E_PRIVILEGE_DENIED			   The application does not have the privilege to call this method.
	*
	* @endif
	*/
	result Construct( const IPlayerEventListener& listener, const Osp::Graphics::BufferInfo* pBufferInfo, bool setAsHighestPriority);
 
private:
	Player(const Player& player);
	Player& operator =(const Player& player);

	IPlayerPi* 			__pPlayerInterface;
     __PlayerEvent*      __pPlayerEvent;
	IPlayerEventListener*	__pPlayerEventListener;
	__PlayerConfiguration*		__pConfiguration;
	
	void* __reserved01;
	void* __reserved02;

	friend class PlayerEx;
	class PlayerEx* __pPlayerEx;
	friend class ProgressivePlayer;
};


};};// Osp::Media

#endif

