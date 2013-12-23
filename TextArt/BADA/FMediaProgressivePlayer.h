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
 * @if PRIVCORE
 * @file			FMediaProgressivePlayer.h
 * @brief			This is the header file for the %ProgressivePlayer class.
 *
 * This header file contains the declarations of the %ProgressivePlayer class.
 * @endif
 */

#ifndef _FMEDIA_PROGRESSIVE_PLAYER_H_
#define _FMEDIA_PROGRESSIVE_PLAYER_H_

// Include
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaPlayerCommon.h"
#include "FMediaPlayer.h"
#include "FMediaProgressivePlayerCommon.h"
#include "FMediaIProgressiveDownloadEventListener.h"

namespace Osp{ namespace Media {

class __PlayerEvent;
class __PlayerConfiguration;
class IPlayerPi;
class __PlayerDownloadEvent;


/**
 * @if PRIVCORE
 * @class	ProgressivePlayer
 * @brief	This class provides methods to play the audio/video content that is progressively increasing.
 * @since	1.2
 *
 * @remarks During the download some of the content cannot be played if the audio and video data are not interleaved.
 *  The GetDuration() method may not work as expected with this class.
 *
 * The %ProgressivePlayer class inherits the %Player class and provides the following additional features:
 *  - Playing the audio or video content that is progressively increasing.
 *  - Downloading the audio or video file and playing it during the download.
 *
 *  
 * The following example demonstrates how to play a video file that is progressively increasing.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FUi.h>
 * #include <FIo.h>
 * 
 * using namespace Osp::Media;
 * using namespace Osp::Base;
 * using namespace Osp::Graphics;
 * 
 * #define PROGRESSIVE_PLAYER_TEST_FILE		L"/Home/test.mp4"
 * #define PROGRESS_BUFFERING_STEP_COUNT		20
 * #define PROGRESSIVE_PLAYER_TEST_URL			L"http://128.0.0.1/test.mp4"
 * #define PROGRESSIVE_PLAYER_TEST_DST_FILE	L"/Home/test_dst.mp4"
 * 
 * class ProgressivePlayerApp :
 * 	public Osp::Ui::Controls::Form,
 * 	public IPlayerEventListener,
 * 	public IProgressiveDownloadEventListener,
 * 	public Osp::Base::Runtime::ITimerEventListener
 * {
 * public:
 * 	ProgressivePlayerApp();
 * 	~ProgressivePlayerApp();
 * 
 * 	result OnInitializing();
 * 	result TestProgressiveFilePlay();
 * 	result TestProgressiveUrlPlay();
 * 
 * protected:
 * 	result CreateProgressivePlayer(Osp::Ui::Controls::OverlayRegion *pRegion);
 * 	// PlayerEventListener
 * 	virtual void OnPlayerBuffering(int percent) {}
 * 	virtual void OnPlayerEndOfClip(void);
 * 	virtual void OnPlayerErrorOccurred(PlayerErrorReason r) {}
 * 	virtual void OnPlayerInterrupted (void) {}
 * 	virtual void OnPlayerOpened(result r);
 * 	virtual void OnPlayerReleased(void) {}
 * 	virtual void OnPlayerSeekCompleted(result r) {}
 * 
 * 	// ProgressiveDownloadEventListener
 * 	virtual void OnProgressiveDownloadStarted(Osp::Media::ProgressivePlayer &src) {}
 * 	virtual void OnProgressiveDownloadInProgress(Osp::Media::ProgressivePlayer &src, int percent) {}
 * 	virtual void OnProgressiveDownloadCompleted(Osp::Media::ProgressivePlayer &src, result r) {}
 * 
 * 	// TimerEventListener
 * 	virtual void OnTimerExpired(Osp::Base::Runtime::Timer &timer);
 * 
 * private:
 * 	ProgressivePlayer *__pPlayer;
 * 	Osp::Ui::Controls::OverlayRegion *__pRegion;
 * 	Osp::Base::Runtime::Timer __Timer;
 * 	long long __totalLength;
 * 	long long __currLength;
 * 	int __bufferingStep;
 * };
 * 
 * ProgressivePlayerApp::ProgressivePlayerApp()
 * : __pPlayer(null), __pRegion(null)
 * {
 * }
 * 
 * ProgressivePlayerApp::~ProgressivePlayerApp()
 * {
 * 	if (__pPlayer)
 * 		delete __pPlayer;
 * }
 * 
 * result ProgressivePlayerApp::OnInitializing()
 * {
 * 	result r;
 *	Osp::Graphics::Rectangle __rect(0, 0, 320, 240);
 *	bool modified = false;
 *
 * 	r = __Timer.Construct(*this);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 *	modified = Osp::Ui::Controls::OverlayRegion::EvaluateBounds(Osp::Ui::Controls::OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN, __rect );
 *	__pRegion = GetOverlayRegionN(__rect, Osp::Ui::Controls::OVERLAY_REGION_TYPE_NORMAL );
 * 
 * 	return E_SUCCESS;
 * 
 * CATCH:
 * 	return r;
 * }
 * 
 * void ProgressivePlayerApp::OnPlayerEndOfClip(void)
 * {
 * 	__pPlayer->Close();
 * 	delete __pPlayer;
 * 	__pPlayer = 0;
 * }
 * 
 * 
 * void ProgressivePlayerApp::OnPlayerOpened(result r)
 * {
 * 	if(IsFailed(r)) {
 * 		// Insert your code here.
 * 		return;
 * 	}
 * 	r= __pPlayer->Play();
 * 	if (IsFailed(r)) {
 * 		// Insert your code here.
 * 		return;
 * 	}
 * }
 * 
 * result ProgressivePlayerApp::CreateProgressivePlayer(Osp::Ui::Controls::OverlayRegion *pRegion)
 * {
 * 	result r;
 * 	Osp::Graphics::BufferInfo bufferInfo;
 * 
 * 	__pPlayer = new ProgressivePlayer();
 * 	r = pRegion->GetBackgroundBufferInfo(bufferInfo);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->Construct(*this, &bufferInfo);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	return E_SUCCESS;
 * 
 * CATCH:
 * 	if (__pPlayer) {
 * 		delete __pPlayer;
 * 		__pPlayer = null;
 * 	}
 * 	return E_FAILURE;
 * }
 * 
 * result ProgressivePlayerApp::TestProgressiveFilePlay()
 * {
 * 	result r;
 * 	Osp::Io::FileAttributes attr;
 * 
 * 	r = Osp::Io::File::GetAttributes(PROGRESSIVE_PLAYER_TEST_FILE, attr);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	__totalLength = attr.GetFileSize();
 * 	__currLength = 0;
 * 	__bufferingStep = __totalLength / PROGRESS_BUFFERING_STEP_COUNT;
 * 
 * 	r = CreateProgressivePlayer(__pRegion);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->OpenProgressiveFile(PROGRESSIVE_PLAYER_TEST_FILE, __totalLength);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __Timer.Start(1000);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	__pPlayer->SetDownloadStatus(PROGRESSIVE_DOWNLOAD_STATUS_STARTED, 0);
 * 
 * 	return E_SUCCESS;
 * 
 * CATCH:
 * 	if (__pRegion)
 * 		delete __pRegion;
 * 	return E_FAILURE;
 * }
 * 
 * result ProgressivePlayerApp::TestProgressiveUrlPlay()
 * {
 * 	result r;
 * 	Osp::Base::String url(PROGRESSIVE_PLAYER_TEST_URL);
 * 	Osp::Base::String dstPath(PROGRESSIVE_PLAYER_TEST_DST_FILE);
 * 
 * 	r = CreateProgressivePlayer(__pRegion);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	r = __pPlayer->OpenProgressiveUrl(url, dstPath, *this);
 * 	if (IsFailed(r)) goto CATCH;
 * 
 * 	return E_SUCCESS;
 * 
 * CATCH:
 * 	if (__pRegion)
 * 		delete __pRegion;
 * 	return E_FAILURE;
 * }
 * 
 * 
 * void ProgressivePlayerApp::OnTimerExpired(Osp::Base::Runtime::Timer &timer)
 * {
 * 	if (__pPlayer == null)
 * 		return;
 * 
 * 	if (__currLength == __totalLength) {
 * 		__pPlayer->SetDownloadStatus(PROGRESSIVE_DOWNLOAD_STATUS_COMPLETED, 0);
 * 		return;
 * 	}
 * 
 * 	__currLength += __bufferingStep;
 * 	__pPlayer->SetDownloadStatus(PROGRESSIVE_DOWNLOAD_STATUS_IN_PROGRESS, __currLength);
 * 
 * 	__Timer.Start(1000);
 * }
 *
 * @endcode
 * @endif
 */


/**
 * @if PRIVCORE
 * @enum ProgressiveDownloadStatus
 * Defines the status of the progressive download.
 *
 * @since	1.2
 * @see		ProgressivePlayer::SetDownloadStatus()
 * @endif
 */
enum ProgressiveDownloadStatus {
	PROGRESSIVE_DOWNLOAD_STATUS_STARTED=0x01,	/**< The download of the progressive content has started */
	PROGRESSIVE_DOWNLOAD_STATUS_IN_PROGRESS,	/**< The downloaded size of the progressive content has been updated */
	PROGRESSIVE_DOWNLOAD_STATUS_COMPLETED		/**< The download of the progressive content is completed */
} ;


class _EXPORT_MEDIA_ ProgressivePlayer : 
	public Player
{

// Lifecycle

public:

	/**
	 *	@if PRIVCORE
 	 *	This is the default constructor for this class.
	 *
	 *  @since		1.2
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *	@see			Construct()
	 *	@endif
	 */
	ProgressivePlayer(void);

	/**
	 *	@if PRIVCORE
	 *	This is the destructor for this class. @n
	 *	Resources are deallocated in this method.
	 *	This method must be called in the same thread in which the Construct() method is called.
	 *
	 *  @since	1.2
	 *	@see		Construct()
	 *  @endif
	 */
	virtual ~ProgressivePlayer(void);


public:

	/**
	 *	@if PRIVCORE
	 *	Initializes this instance of %ProgressivePlayer with the specified parameters.
	 *	
	 *  @since			1.2
	 *	@privlevel	CORE
	 *  @privgroup	MEDIA_SERVICE
	 *
	 *	@return			An error code on failure, @n
	 *                  else E_SUCCESS on success
	 *
	 *	@param[in]	listener						An event listener of this instance
	 *	@param[in]	pBufferInfo						The buffer information that displays the video frame
	 *
	 *	@exception	E_SUCCESS						The method is successful.
	 *	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	 *	@exception	E_RESOURCE_UNAVAILABLE			The resources for the %ProgressivePlayer class are unavailable.
	 *	@exception	E_SYSTEM						A system error has occurred.
	 *
	 *  @endif
	 */
	result Construct( const IPlayerEventListener& listener, const Osp::Graphics::BufferInfo* pBufferInfo=null);

	/**
	 *	@if PRIVCORE
	 *	Opens the progressively increasing audio or video content that is stored in the buffer.
	 *
	 *  @since			1.2
	 *	@privlevel	CORE
	 *  @privgroup	MEDIA_SERVICE
	 *
	 *	@return			An error code on failure, @n
	 *                  else E_SUCCESS on success
	 *
	 *	@param[in]	buffer							A buffer that stores the audio or video content
	 *
	 *	@exception	E_SUCCESS						The method is successful.
	 *	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG 					The specified input parameter is invalid.
	 *	@exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 *	@exception	E_SYSTEM						A system error has occurred.
	 *
	 *	@see				OpenBuffer(), Close(), SetDownloadStatus()
	 *
	 *	@remarks	The specified @c buffer should have enough capacity to store the downloaded content.
	 *		The DRM content cannot be played with this method.
	 *  	SetDownloadStatus() must be called to notify the updated size of @c buffer.
	 *		This method operates in an asynchronous mode. Therefore, Play() should be called after IPlayerEventListener::OnPlayerOpened() is called.
	 *
	 *  @endif
	 */
	result OpenProgressiveBuffer(const Osp::Base::ByteBuffer& buffer);

	/**
	 *	@if PRIVCORE
	 *	Opens a progressively increasing audio or video file to play.
	 *
	 *  @since			1.2
	 *	@privlevel	CORE
	 *  @privgroup	MEDIA_SERVICE
	 *
	 *	@return			An error code on failure, @n
	 *                  else E_SUCCESS on success
	 *
	 *	@param[in]	path							The local file path of the audio or video content
	 *  @param[in]  totalSize						The total size of the input file in bytes when the download is completed
	 *
	 *	@exception	E_SUCCESS						The method is successful.
	 *	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG 					A specified input parameter is invalid.
	 *	@exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 * 	@exception	E_FILE_NOT_FOUND				The specified file cannot be found or accessed.
	 *	@exception	E_SYSTEM						A system error has occurred.
	 *
	 *	@see				SetDownloadStatus(), OpenFile(), Close()
	 *
	 *	@remarks	The DRM content cannot be played with this method.
	 *  	SetDownloadStatus() must be called to update the current size of the downloaded file.
	 *		This method operates in an asynchronous mode. Therefore, Play() should be called after IPlayerEventListener::OnPlayerOpened() is called.
	 *
	 *  @endif
	 */
	result OpenProgressiveFile(const Osp::Base::String& path, int totalSize);

	/**
	 *	@if PRIVCORE
	 *	Opens the audio or video streaming content to download and play with a specified URL. @n
	 *  With this method, an application can download the content with a specified URL, store it into a file, and play the downloaded content during the download.
	 *
	 *  @since			1.2
	 *	@privlevel	CORE
	 *  @privgroup	MEDIA_SERVICE
	 *
	 *	@return			An error code on failure, @n
	 *                  else E_SUCCESS on success
	 *
	 *	@param[in]	mediaUri						The URL of the media source
	 *  @param[in]	destPath						The file path where the downloaded content is stored
	 *  @param[in]	listener						An event listener that receives notification of the download status of the content @n
	 *                                              The event listener receives the notification from the %ProgressivePlayer class.
	 *
	 *	@exception	E_SUCCESS						The method is successful.
	 *	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG 					A specified input parameter is invalid.
	 *	@exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 * 	@exception	E_UNSUPPORTED_PROTOCOL			The protocol is not supported.
	 *	@exception	E_SYSTEM						A system error has occurred.
	 *
	 *	@see				OpenUrl(), Close()
	 *
	 *	@remarks	The DRM content cannot be played with this method.
	 *		This method operates in an asynchronous mode. Therefore, Play() should be called after IPlayerEventListener::OnPlayerOpened() is called.
	 *  	The supported protocol is HTTP.
	 *
	 *  @endif
	 *
	 */
	result OpenProgressiveUrl(const Osp::Base::String &mediaUri, const Osp::Base::String &destPath, const IProgressiveDownloadEventListener &listener);


	/**
	 *	@if PRIVCORE
	 *
	 *  Sets the current download status of the progressively increasing file or buffer.
	 *
	 *  @since			1.2
	 *	@privlevel	CORE
	 *  @privgroup	MEDIA_SERVICE
	 *  
	 *	@return		An error code on failure, @n
	 *              else E_SUCCESS on success
	 *
	 *  @param[in]	status							The download status of the file or buffer
	 *  @param[in]	downloadedSize					The current size of the downloaded file or buffer in bytes
	 * 
	 *	@exception	E_SUCCESS						The method is successful.
	 *	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG 					A specified input parameter is invalid.
	 *	@exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	 *	@exception	E_SYSTEM						A system error has occurred.
	 *
	 *  @see OpenProgressiveFile(), OpenProgressiveBuffer()
	 *
	 *  @endif
	 */
	result SetDownloadStatus(Osp::Media::ProgressiveDownloadStatus status, int downloadedSize);


private:
	ProgressivePlayer(const Player& player);
	ProgressivePlayer& operator =(const Player& player);

	__PlayerDownloadEvent *__pEvent;

	friend class ProgressivePlayerEx;
	class ProgressivePlayerEx* __pPlayerEx;
};


};};// Osp::Media

#endif

