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
 * @file			FMediaAudioStreamInfo.h
 * @brief			This is the header file for the %AudioStreamInfo class.
 *
 * This header file contains the declarations of the %AudioStreamInfo class.
 */

#ifndef FMEDIAAUDIOSTREAMINFO_H_
#define FMEDIAAUDIOSTREAMINFO_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioCommon.h"

#include "FMediaTypes.h"


namespace Osp{ namespace Media {

class AudioStreamInfoEx;

/**
 * @class     AudioStreamInfo
 * @brief     This class provides the methods to get audio stream information.
 * @since     2.0
 *
 * The %AudioStreamInfo class provides the methods to get audio stream information, such as codec type, bit rate, sample rate, and channel count.
 *
 */

class _EXPORT_MEDIA_ AudioStreamInfo  :
             public Osp::Base::Object
{
public :

	/**
	* This is the destructor for this class.
	*
	* @since     2.0
	*/
	virtual ~AudioStreamInfo(void);

public :

	/**
	*      Gets the encoding type of an audio stream.
	*
	* @since     2.0
	*      @return		The value of the encoding type 
	*
	*/
	CodecType GetCodecType(void) const;

	/**
	*      Gets the bit rate of an audio.
	*
	* @since     2.0
	*      @return             The audio bit rate in bits per second (bps) 
	*/
	int GetBitRate(void) const;

	/**
	*      Gets the sampling rate of an audio.
	*
	* @since     2.0
	*      @return             The audio sampling rate in hertz (Hz) 
	*/
	int GetSampleRate(void) const;

	/**
	*      Gets the audio channel of an audio.
	*
	* @since     2.0
	*      @return             The audio channel type 
	*/
	AudioChannelType GetChannelType(void) const;

private:
	/**
	* Initializes this instance of AudioStreamInfo with the specified parameters.
	*
	* @param [in]	codecType	The value of encoding type @n
	* @param [in]	bitrate		The audio bit rate in bits per second (bps) @n
	* @param [in]	sampleRate	The audio sample rate in hertz (Hz) @n
	* @param [in]	channel		The audio channel type @n
	*/
	AudioStreamInfo(CodecType codecType, int bitrate, int sampleRate, AudioChannelType channel);


	AudioStreamInfo (const AudioStreamInfo& info);
	AudioStreamInfo& operator =(const AudioStreamInfo& info);

private:

	CodecType __codecType;
	int	__bitrate;
	int	__sampleRate;
	AudioChannelType __channel;

	friend class __Player;
	friend class AudioStreamInfoEx;
	class AudioStreamInfoEx* __pAudioStreamInfoEx;
};

};};

#endif /* FMEDIAAUDIOSTREAMINFO_H_ */
