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
 * @file			FMediaMediaStreamInfo.h
 * @brief			This is the header file for the %MediaStreamInfo class.
 *
 * This header file contains the declarations of the %MediaStreamInfo class.
 */

#ifndef FMEDIASTREAMINFO_H_
#define FMEDIASTREAMINFO_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioStreamInfo.h"
#include "FMediaVideoStreamInfo.h"

namespace Osp{ namespace Media {

class MediaStreamInfoEx;

/**
 * @class     MediaStreamInfo
 * @brief     This class provides methods to get media stream information.
 * @since     2.0
 *
 * The %MediaStreamInfo class provides the methods to get media stream information, including:
 * - Content metadata, such as the title, artist, album title, genre, year, and album art.
 * - Audio and video stream information.
 *
 * This class supports multiple stream content that consists of several audio or video tracks.
 * This class provides a list of AudioStreamInfo and VideoStreamInfo that has the stream information of each audio or video track.
 *
 * For more detailed information, see AudioStreamInfo and VideoStreamInfo classes.

 *
 * The following example demonstrates how to use the %MediaStreamInfo class.
 * @code
 * #include <FMediaPlayer.h>
 * #include <FBase.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Media;
 *
 * class MyPlayerListener
 *       : public Osp::Media::IPlayerEventListener
 * {
 *   public:
 * 	  MyPlayerListener() {
 * 		}
 * 	  void OnPlayerOpened(result r){};
 * 	  void OnPlayerEndOfClip(void){};
 * 	  void OnPlayerBuffering(int percent){};
 * 	  void OnPlayerErrorOccurred(PlayerErrorReason r ){};
 * 	  void OnPlayerInterrupted(){};
 * 	  void OnPlayerReleased(){};
 * 	  void OnPlayerSeekCompleted(result r){};
 * };
 *
 * String path0("SampleFile0.aac");
 *
 * void
 * MediaPlaying(void)
 * {
 * 	result r = E_SUCCESS;
 * 	Player*  pPlayer = new Player();
 *
 * 	MediaStreamInfo*  pStreamInfo = null;
 * 	const IList* pAudioStreamList = null;
 * 	const AudioStreamInfo*  pAudioStream = null;
 * 	int bitrate = -1;
 *
 * 	MyPlayerListener* pListener = new MyPlayerListener();
 *
 * 	// Creates audio player.
 * 	r = pPlayer->Construct( *pListener, 0);
 * 	if (IsFailed(r)) goto CATCH;
 *
 * 	// Opens the file asynchronously.
 * 	r = pPlayer->OpenFile(path0, false);
 * 	if (IsFailed(r)) goto CATCH;
 *
 * 	r = pPlayer->SetLooping(true);
 * 	if (IsFailed(r)) goto CATCH;
 *
 * 	r = pPlayer->SetVolume(80);
 * 	if (IsFailed(r)) goto CATCH;
 *
 * 	r = pPlayer->Play();
 * 	if (IsFailed(r)) goto CATCH;
 *
 * 	// Checks the player state.
 * 	if(pPlayer->GetState() == PLAYER_STATE_PLAYING)
 * 	{
 * 		pStreamInfo = pPlayer->GetCurrentMediaStreamInfoN();
 * 		r = GetLastResult();
 * 		if (IsFailed(r)) goto CATCH;
 *
 * 		pAudioStreamList = pStreamInfo->GetAudioStreamInfoList();
 * 		if(pAudioStreamList != null)
 *		{
 *	 		pAudioStream = (const AudioStreamInfo*)pAudioStreamList->GetAt(0);
 * 			if(pAudioStream != null)
 * 				bitrate = pAudioStream->GetBitRate();
 *		}
 * 	}
 *
 * CATCH:
 *   delete pPlayer;
 *   delete pListener;
 *
 *   if(pStreamInfo != null)
 * 	delete pStreamInfo;
 *
 * }
 *
 * @endcode
 */
class _EXPORT_MEDIA_ MediaStreamInfo
       : public Osp::Base::Object
{
public :
	/**
	*	This is the destructor for this class.
	*
	* @since     2.0
	*/
	virtual ~MediaStreamInfo(void);

public :

	/**
	*	Gets the title.
	*
	*	@since		2.0
	*	@return		  The value of the title, @n
	*	              else an empty string if the content has no title
	*/
	Osp::Base::String GetTitle(void);

    /**
    *	Gets the name of the artist from the content.
    *
    *	@since		2.0
    *	@return                     The artist, @n
    * 	                            else an empty string if the content has no artist name
    */
    Osp::Base::String GetArtist(void) const;

    /**
    *	Gets the album title.
    *
    *	@since		2.0
    *	@return		  The title of the album, @n
    *	              else an empty string if the content has no album 
    */
    Osp::Base::String GetAlbumTitle(void) const;

    /**
    *	Gets the genre.
    *
    *	@since		2.0
    *	@return		  The genre, @n
    *	              else an empty string if the content has no genre 
    */
    Osp::Base::String GetGenre(void) const;

    /**
    *	Gets the year.
    *
    *	@since		2.0
    *	@return		The year, @n
    *	            else @c 0 if the content has no year 
    */
    int GetYear(void) const;

    /**
    *	Gets the album art.
    *
    *	@since		2.0
    *	@return		The album art in the content, @n
    *	            else @c null if the content has no album art 
    */
    Osp::Base::ByteBuffer* GetAlbumArtN(void) const;

	/**
	*	Gets a list of the audio stream information.
	*
	* @since     		2.0
	*	@return				                    A pointer to the list containing the audio stream information @n
	*						                    The value belongs to the %AudioStreamInfo class.
	*	@exception   	E_SUCCESS				The method is successful. 
	*	@exception   	E_INVALID_DATA			The stream cannot be parsed successfully.
	*	@exception   	E_SYSTEM				 A system error has occurred.
	*	@remarks				The specific error code can be accessed using the GetLastResult() method.
	*/
	const Osp::Base::Collection::IList* GetAudioStreamInfoList(void) const;

	/**
	*	Gets a list of the video stream information.
	*
	* @since        2.0
	*	@return     	A pointer to a list containing the video stream information @n
	*								The value belongs to the %VideoStreamInfo class.
	*	@exception   	E_SUCCESS				The method is successful.
	*	@exception   	E_INVALID_DATA			The stream cannot be parsed successfully.
	*	@exception   	E_SYSTEM				 A system error has occurred.
	*	@remarks				The specific error code can be accessed using the GetLastResult() method.
	*/
	const Osp::Base::Collection::IList* GetVideoStreamInfoList(void) const;

private :
	/**
	*	Initializes this instance of %MediaStreamInfo with the specified parameters. @n
	*
	*	@param[in]		title					The value of the title @n
	*	@param[in]		artist					The value of the artist @n
	*	@param[in]		albumTitle				The value of the title of the album @n
	*	@param[in]		genre					The value of the genre @n
	*	@param[in]		year					The value of the year @n
	*	@param[in]		albumArt				The value of the album art @n
	*	@param[in]		pAudioStream			A pointer to an audio stream list @n
	*	@param[in]		pVideoStream			A pointer to a video stream list @n
	*	@param[in]		titleException			An exception generated due to the title of audio or video @n
	*	@param[in]		audioStreamException	The exception generated during audio streaming @n
	*	@param[in]		videoStreamException	The exception generated during video streaming @n
	*/
	MediaStreamInfo(const Osp::Base::String &title, const Osp::Base::String &artist, const Osp::Base::String &albumTitle,
			        const Osp::Base::String &genre, int year, Osp::Base::ByteBuffer* pAlbumArt,
			        Osp::Base::Collection::IList* pAudioStream, Osp::Base::Collection::IList* pVideoStream,
					result audioStreamException, result videoStreamException);

	MediaStreamInfo(const MediaStreamInfo& info);
	MediaStreamInfo& operator =(const MediaStreamInfo& info);

private :

	int __year;
	Osp::Base::String __title;
	Osp::Base::String __artist;
	Osp::Base::String __albumTitle;
	Osp::Base::String __genre;
	Osp::Base::ByteBuffer* __pAlbumArt;

	Osp::Base::Collection::IList* __pAudioStreamList;
	Osp::Base::Collection::IList* __pVideoStreamList;

	result __audioStreamListException;
	result __videoStreamListException;

	friend class __Player;
	friend class MediaStreamInfoEx;
	MediaStreamInfoEx* __pMediaStreamInfoEx;

};

};};

#endif /* FMEDIASTREAMINFO_H_ */

