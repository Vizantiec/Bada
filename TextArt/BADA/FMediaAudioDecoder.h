// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaAudioDecoder.h
 *	@brief	This is the header file for the %AudioDecoder class.
 *
 *	This header file contains the declarations of the %AudioDecoder class.
 */
#ifndef FMEDIA_AUDIODECODER_H_
#define FMEDIA_AUDIODECODER_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaAudioCommon.h"
#include "FMediaTypes.h"

namespace Osp { namespace Media {

/**
 *	@class	AudioDecoder
 *	@brief	This class decodes a compressed audio stream to a raw audio data.
 *          The audio decoding formats, such as CODEC_MP3, CODEC_AAC, and CODEC_AMR_NB, are supported.
 *	@since	2.0
 *
 * @remarks
 *  Source data of AAC and AMR decoder must be raw compressed data without header.
 *
 *  The %AudioDecoder class decodes a compressed audio stream to a raw audio data.
 *  The audio decoding formats, such as CODEC_MP3, CODEC_AAC, and CODEC_AMR_NB, are supported.
 * 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm
">Encoding and Decoding Audio</a>.
 *
 * The following example demonstrates how to use the %AudioDecoder class in MP3 decoding. 

 *
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
 * #define SRC_BUF_SIZE	(1024*8)
 * #define DST_BUF_SIZE	(1024*8)
 *
 * result DecodeMP3(void)
 * {
 * 	AudioDecoder dec;
 * 	result r;
 * 	ByteBuffer srcBuf, dstBuf;
 * 	File srcFile;
 * 	int sampleRate, value;
 * 	AudioChannelType channelType;
 * 	AudioSampleType sampleType;
 *
 *  	r = dec.Construct(CODEC_MP3);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	r = srcBuf.Construct(SRC_BUF_SIZE);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Construct(L"/Home/test.mp3", "rb");
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Read(srcBuf);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	srcBuf.Flip();  //Flip the source Buffer position to zero
 *
 *  	r = dec.Probe(srcBuf, sampleType, channelType, sampleRate);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	r = dstBuf.Construct(DST_BUF_SIZE);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	r = dec.Decode(srcBuf, dstBuf);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *  	dec.GetValue(MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE, value);
 *  	channelType = (AudioChannelType)value;
 *  	dec.GetValue(MEDIA_PROPERTY_AUDIO_SAMPLE_TYPE, value);
 *  	sampleType = (AudioSampleType)value;
 *  	dec.GetValue(MEDIA_PROPERTY_AUDIO_SAMPLE_RATE, sampleRate);
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
 * 
 *
 */

class _EXPORT_MEDIA_ AudioDecoder :
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
	AudioDecoder(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	2.0
	 */
	virtual ~AudioDecoder(void);

	/**
	 *	Initializes this instance of AudioDecoder with the specified parameters. @n
	 *  The following example demonstrates a simple decoder construction with optional parameters.
	 *  @code
	 *
	 *	result OpenAacDecoder(void)
	 *	{
	 *		AudioDecoder dec;
	 *		result r;
	 *		HashMap option;
 	 *
	 *		option.Construct();
	 *		option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE)), *(new Integer(AUDIO_CHANNEL_TYPE_STEREO)));
	 *		option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_SAMPLE_RATE)), *(new Integer(44100)));
	 *
	 *		r = dec.Construct(CODEC_AAC, &option);
	 *		if (IsFailed(r))
	 *			goto CATCH;
	 *
	 *		return E_SUCCESS;
	 *	CATCH:
	 *		return r;
	 *	}
	 *  @endcode
	 *
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm#decoding_audio">optional parameters</a>
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified decoder is not supported.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_OUT_OF_RANGE		The specified input parameter has a value that is out of the range.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *
	 *	@remarks	The key type of the specified option is Osp::Base::Integer, and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Osp::Base::Collection::HashMap *pOption = null);


public:

	/**
	 *	Probes whether the audio data can be decoded.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *	@param[in]	srcBuf					The source buffer that stores the compressed audio data
	 *	@param[out]	sampleType				The sample type of the decoded audio sample
	 *	@param[out]	channelType				The channel type of the decoded audio sample
	 *	@param[out]	sampleRate				The sample rate of the decoded audio sample
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			A specified source buffer is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient to decode the sample.
	 *	@exception 	E_SYSTEM				A system error has occurred.
	 *	@remarks	The method resets the internal state of an audio decoder.
	 */
	result Probe(const Osp::Base::ByteBuffer &srcBuf, AudioSampleType &sampleType, AudioChannelType &channelType, int &sampleRate);

	/**
	 *	Decodes the audio data from the source buffer and stores the decoded data into a destination buffer. @n
	 *	The %AudioDecoder class reads and decodes the audio data from the source buffer
	 *	and it also writes the decoded audio data into the destination buffer. @n
	 *  The position of the source buffer is moved to the end of the consumed data and the position of the destination buffer is moved to the end of the written data.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *
	 *	@param[in]	srcBuf					The source buffer that stores the compressed audio data
	 *	@param[out]	dstBuf					The destination buffer that stores the decoded audio data
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			A specified source or destination buffer is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The specified destination buffer is insufficient to store the decoded data.
	 *	@exception 	E_SYSTEM				A system error has occurred.
	 */
	result Decode(Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &dstBuf);

	/**
	 *	Resets the internal state of the audio decoder to process a new audio stream.
	 *
	 *	@since	2.0
	 *	@return		An error code
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	result Reset(void);

	/**
	 *	Gets the specified property type value of this instance.
	 *
	 *	@since	2.0
	 *	@return 		An error code
	 *
	 *	@param[in]		key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm#decoding_audio">key</a> for which the value is to be obtained
	 *	@param[out]		value			The obtained property value
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The property whose value type is enum can be obtained using this method.
	 */
	result GetValue(MediaPropertyType key, int &value) const;

	/**
	 *	Gets the supported properties of this instance.
	 *
	 *	@since	2.0
	 *	@return 	A list of supported properties, @n
	 *				else @c null if no property is supported or if an exception occurs
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method. @n
	 *	        	The return value must be deleted.
	 */
	Osp::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property type is supported.
	 *
	 *	@since	2.0
	 *	@return 	@c true if the property is supported, @n
	 *				else @c false
	 *
	 *	@param[in]		key				The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_audio.htm#decoding_audio">key</a> for which the value is to be obtained
	 *	@exception	E_SUCCESS 			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of the Camera.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPropertySupported(MediaPropertyType key) const;


protected:


private:
	AudioDecoder(const AudioDecoder& dec);
	AudioDecoder& operator =(const AudioDecoder& dec);

	friend class __AudioDecoderImpl;
	class __AudioDecoderImpl* __impl;
};

}; };


#endif /* FMEDIAAUDIODECODER_H_ */
