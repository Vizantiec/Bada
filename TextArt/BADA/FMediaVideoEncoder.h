// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaVideoEncoder.h
 *	@brief	This is the header file for the %VideoEncoder class.
 *
 *	This header file contains the declarations of the %VideoEncoder class.
 */
#ifndef FMEDIA_VIDEOENCODER_H_
#define FMEDIA_VIDEOENCODER_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaTypes.h"

namespace Osp { namespace Media {

/**
 *	@class	VideoEncoder
 *	@brief	This class encodes a raw video stream into compressed video data.
 *  @since	2.0
 *
 * The %VideoEncoder class encodes a raw video stream into compressed video data.
 *  The video encoders, such as H.263, MPEG4 Part 2, and H.264, are supported.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm
">Encoding and Decoding Video</a>.
 *
 * The following example demonstrates how to use the %VideoEncoder class in H.263 Encoding. 
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FIo.h>

 * using namespace Osp::Io;
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Media;

 * result EncodeH263(void)
 * {
 *	VideoEncoder enc;
 *	result r;
 *	ByteBuffer srcBuf, dstBuf;
 *	File srcFile;
 *	int width = 352;
 *	int height = 288;
 *	int bitRate = 512000; // 512 kbps.
 *	int frameRate = 15;
 *	int gopSize = 15;
 *	int profile = 0;	// baseline profile.
 *	int gobSize = width/16;	// group of block size.
 *	int sliceSize = 1024;	// slice size in byte.
 *	int quantLevel = 10;
 *	int quantMin = 2;
 *	int quantMax = 31;
 *	int useFrameSkip = 1;	// use frame skip.
 *	MediaPixelFormat pixelFormat = MEDIA_PIXEL_FORMAT_YUV420P;
 *
 *	HashMap option;
 *
 *	option.Construct();
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_WIDTH)), *(new Integer(width)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_HEIGHT)), *(new Integer(height)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_PIXEL_FORMAT)), *(new Integer(pixelFormat)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_FRAME_RATE)), *(new Integer(frameRate)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_BIT_RATE)), *(new Integer(bitRate)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_QUANTIZATION_PARAMETER)), *(new Integer(quantLevel)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_GOP_SIZE)), *(new Integer(gopSize)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_PROFILE)), *(new Integer(profile)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_GOB_SIZE)), *(new Integer(gobSize)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_SLICE_SIZE_IN_BYTE)), *(new Integer(sliceSize)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_QUANTIZATION_MIN)), *(new Integer(quantMin)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_QUANTIZATION_MAX)), *(new Integer(quantMax)));
 *	option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_USE_FRAME_SKIP)), *(new Integer(useFrameSkip)));
 *
 *	r = enc.Construct(CODEC_H263, &option);
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 *	r = srcBuf.Construct(width*height*3/2);
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 * 	r = srcFile.Construct(L"/Home/test_cif.yuv", "rb");
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 * 	r = srcFile.Read(srcBuf);
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 *	r = dstBuf.Construct(width*height*3/2);
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 *	enc.SetValue(MEDIA_PROPERTY_VIDEO_QUANTIZATION_PARAMETER, 20);
 *	bitRate = 128000; // change bit rate.
 *	enc.SetValue(MEDIA_PROPERTY_VIDEO_BIT_RATE, bitRate);
 *
 *   	srcBuf.Flip();  // Flip the source Buffer position to zero.
 *
 *	r = enc.Encode(srcBuf, dstBuf);
 *	if (IsFailed(r))
 *		goto CATCH;
 *
 *	r = enc.Reset();
 *
 *	AppLog("Success");
 *	return r;
 *
 * CATCH:
 *	 AppLog("Fail");
 *   return r;
 * }
 * @endcode
 *
 */
class _EXPORT_MEDIA_ VideoEncoder :
	public Osp::Base::Object
{
public:

	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since	2.0
	 *
	 *	@remarks		 After creating an instance of this class, the Construct() method must be 
	 *					 called explicitly to initialize this instance.
	 *	@see 		Construct()
	 */
	VideoEncoder(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	2.0
	 */
	virtual ~VideoEncoder(void);

	/**
	 *	Constructs a video encoder instance.
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#encoding_video">optional parameters</a>
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified encoder is not supported.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG		An input parameter has invalid data.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *
	 *	@remarks	The key type of the specified option is Osp::Base::Integer and the value type varies depending 
	 *              on the key type.
	 *	        	The unsupported keys in @c pOption are ignored.
	 *	         	If specified @c pOption has an invalid value, E_INVALID_ARG is returned.
     *  @remarks The supported codec types can vary depending on the device model or platform version.
	 */
	result Construct(CodecType type, const Osp::Base::Collection::HashMap *pOption = null);

public:

	/**
	 *	Encodes the video data from the source buffer and stores the encoded data in the destination buffer.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *
	 *	@param[in]	srcBuf					The source buffer that stores the raw video data
	 *	@param[out]	dstBuf					The destination buffer that stores the encoded video data
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			The specified source or destination buffer is invalid or has insufficient memory.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception 	E_SYSTEM				A system error has occurred.
	 *	@remarks	The destination buffer must have sufficient free space to store the encoded frame data.
	 *	        	The position of @c srcBuf is moved as per the occupied space.
	 */
	result Encode(Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &dstBuf);

	/**
	 *	Resets the internal state of the video encoder to process a new video stream.
	 
	 *	@since	2.0
	 *	@return		An error code
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	This method resets the properties that were set after the execution of the Construct() method.
	 */
	result Reset(void);

	/**
	 *	Sets the specified property value of this instance.
	 *
	 *	@since	2.0
	 *	@return 		An error code
	 *
	 *	@param[in]		key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#encoding_video">key</a> value to set
	 *	@param[in]		value				The property value to set
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The media property that has the value of type enum can be set using this method.
	 */
	result SetValue(MediaPropertyType key, int value);

	/**
	 *	Sets the specified property value of this instance.
	 *
	 *	@since	2.0
	 *	@return 		An error code
	 *
	 *	@param[in]		key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#encoding_video">key</a> value to set
	 *	@param[in]		value				The property value to set
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The media property that has the value of type enum can be set using this method.
	 */
	result SetValue(MediaPropertyType key, bool value);

	/**
	 *	Gets the properties supported by this instance.
	 *
	 *	@since	2.0
	 *	@return 	A list of the supported properties, @n
	 *				else @c null if no property is supported or if an exception occurs
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 *		        The returned value must be deleted.
	 */
	Osp::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property is supported.
	 *
	 *	@since	2.0
	 *	@return 	@c true if the property is supported, @n
	 *				else @c false
	 *
	 *	@param[in]	key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#encoding_video">key</a> value
	 *	@exception	E_SUCCESS 			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPropertySupported(MediaPropertyType key) const;

protected:



private:
	VideoEncoder(const VideoEncoder& enc);
	VideoEncoder& operator =(const VideoEncoder& enc);

	friend class __VideoEncoderImpl;
	class __VideoEncoderImpl* __impl;
};

}; };


#endif
