// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaAudioEncoder.h
 *	@brief	This is the header file for the %AudioEncoder class.
 *
 *	This header file contains the declarations of the %AudioEncoder class.
 */
#ifndef FMEDIA_AUDIOENCODER_H_
#define FMEDIA_AUDIOENCODER_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioCommon.h"
#include "FMediaTypes.h"

namespace Osp { namespace Media {

/**
 *	@class	AudioEncoder
 *	@brief	This class encodes raw audio data into compressed audio stream.
 *
 *	@since	2.0
 *
 * The %AudioEncoder class encodes raw audio data into compressed audio stream.
 * It supports the audio encoding formats such as CODE_AAC and CODEC_AMR_NB.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm
">Encoding and Decoding Audio</a>.
 *
 * The following example demonstrates how to use the %AudioEncoder class in Advanced Audio Coding (AAC) encoding.
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FIo.h>
 *
 * using namespace Osp::Io;
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Media;
 *
 * #define SRC_BUF_SIZE	(1024*32)
 * #define DST_BUF_SIZE	(1024*8)
 *
 * result EncodeAAC(void)
 * {
 * 	AudioEncoder enc;
 * 	result r;
 * 	ByteBuffer srcBuf, dstBuf;
 * 	File srcFile;
 * 	int sampleRate = 44100;
 * 	AudioChannelType channelType = AUDIO_CHANNEL_TYPE_STEREO;
 * 	int bitRate = 128000;	// 128Kbps
 * 	HashMap option;
 *
 * 	option.Construct();
 * 	option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE)), *(new Integer(channelType)));
 * 	option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_SAMPLE_RATE)), *(new Integer(sampleRate)));
 * 	option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_BIT_RATE)), *(new Integer(bitRate)));
 *
 *  	r = enc.Construct(CODEC_AAC, &option);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *  	r = srcBuf.Construct(SRC_BUF_SIZE);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	r = dstBuf.Construct(DST_BUF_SIZE);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Construct(L"/Home/test.pcm", "rb");
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Read(srcBuf);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	srcBuf.Flip();  // Flips the source buffer and then the position is set to zero.
 *      
 *
 *  	r = enc.Encode(srcBuf, dstBuf);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	AppLog("Success");
 *  	return r;
 *
 * CATCH:
 * 	AppLog("Fail");
 *   	return r;
 * }
 * @endcode
 *
 */
class _EXPORT_MEDIA_ AudioEncoder :
	public Osp::Base::Object
{
public:

	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since	2.0
	 *
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *	@see 		Construct()
	 */
	AudioEncoder(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	2.0
	 */
	virtual ~AudioEncoder(void);

	/**
	 *	Initializes this instance of AudioEncoder with the specified parameters.
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm#encoding_audio">optional parameters</a>
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified encoder is not supported.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_OUT_OF_RANGE		An input parameter has a value that is out of the range.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *
	 *	@remarks	The key type of the specified option is Osp::Base::Integer, and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Osp::Base::Collection::HashMap *pOption = null);


public:

	/**
	 *	Encodes the audio data from the source buffer and stores the encoded data into the destination buffer. @n
	 *	The %AudioEncoder class reads the audio data from the source buffer
	 *  and it writes the encoded audio data into the destination buffer.
	 *  The position of the source buffer is moved to the end of the consumed data and the position of the destination buffer is moved to the end of the written data.
	 *	If there is no space in the destination buffer, the encoder returns E_INVALID_ARG.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *
	 *	@param[in]	srcBuf					The source buffer that stores the uncompressed audio data
	 *	@param[out]	dstBuf					The destination buffer that stores the encoded audio data
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			The specified source or destination buffer is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The specified destination buffer is not sufficient to store the decoded data.
	 *	@exception 	E_SYSTEM				A system error has occurred.
	 */
	result Encode(Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &dstBuf);

	/**
	 *	Resets the internal state of the audio encoder to process a new audio stream.
	 *
	 *	@since	2.0
	 *	@return		An error code
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	result Reset(void);


protected:

private:
	AudioEncoder(const AudioEncoder& enc);
	AudioEncoder& operator =(const AudioEncoder& enc);

	friend class __AudioEncoderImpl;
	class __AudioEncoderImpl* __impl;
};

}; };


#endif
