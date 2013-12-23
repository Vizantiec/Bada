// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaVideoDecoder.h
 *	@brief	This is the header file for the %VideoDecoder class.
 *
 *	This header file contains the declarations of the %VideoDecoder class.
 */
#ifndef FMEDIA_VIDEODECODER_H_
#define FMEDIA_VIDEODECODER_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaTypes.h"

namespace Osp { namespace Media {

/**
 *	@class	VideoDecoder
 *	@brief	This class decodes a compressed video stream into raw video data.
 *  @since	2.0
 *
 * The %VideoDecoder class decodes a compressed video stream into raw video data.
 * The video decoding formats, such as CODEC_H263, CODEC_MPEG4, and CODEC_H264 are supported.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm
">Encoding and Decoding Video</a>.
 *
 * The following example demonstrates how to use %VideoDecoder in H.264 decoding.
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
 *
 * int DecodeH264(void)
 * {
 * 	VideoDecoder dec;
 * 	result r;
 * 	ByteBuffer srcBuf, dstBuf;
 * 	File srcFile;
 * 	bool gotFrame;
 * 	int width, height, value;
 * 	float frameRate;
 * 	MediaPixelFormat pixelFormat;
 *
 *  	r = dec.Construct(CODEC_H264);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *  	r = srcBuf.Construct(SRC_BUF_SIZE);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Construct(L"/Home/test.h264", "rb");
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	r = srcFile.Read(srcBuf);
 *  	if (IsFailed(r))
 *  		goto CATCH;
 *
 *   	srcBuf.Flip();  // Flip the source Buffer position to zero. 
 *
 * 	r = dec.Probe(srcBuf, width, height, pixelFormat);
 * 	if (IsFailed(r))
 * 		goto CATCH;
 *
 * 	if (pixelFormat != MEDIA_PIXEL_FORMAT_YUV420P)
 * 		goto CATCH;
 *
 * 	r = dstBuf.Construct(width*height*3/2);
 * 	if (IsFailed(r))
 * 		goto CATCH;
 *
 * 	gotFrame = false;
 * 	r = dec.Decode(srcBuf, dstBuf, gotFrame);
 * 	if (IsFailed(r))
 * 		goto CATCH;
 *
 *  	if (gotFrame) {
 *  		dec.GetValue(MEDIA_PROPERTY_VIDEO_WIDTH, width);
 *  		dec.GetValue(MEDIA_PROPERTY_VIDEO_HEIGHT, height);
 *  		dec.GetValue(MEDIA_PROPERTY_VIDEO_PIXEL_FORMAT, value);
 *  		pixelFormat = (MediaPixelFormat)value;
 *  	}
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
 */
class _EXPORT_MEDIA_ VideoDecoder :
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
	VideoDecoder(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *	@since	2.0
	 */
	virtual ~VideoDecoder(void);

	/**
	 *	Initializes this instance of %VideoDecoder with the specified parameters.
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#decoding_video">optional parameters</a>
	 *
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified decoder is not supported.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_OUT_OF_RANGE		An input parameter has a value that is out of range.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *
	 *	@remarks	The key type of the specified option is Osp::Base::Integer and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Osp::Base::Collection::HashMap *pOption = null);

public:

	/**
	 *	Checks whether the video data can be decoded and sets the width, height, and pixel format of the video data.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *	@param[in]	srcBuf					The source buffer that stores the compressed video data
	 *	@param[out]	width					The width of the decoded video frame
	 *	@param[out]	height					The height of the decoded video frame
	 *	@param[out]	pixelFormat				The pixel format of the decoded video frame
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			The specified @srcBuf is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception 	E_SYSTEM				A system error has occurred.
	 *	@remarks	The method resets the internal state of the video decoder.
	 */
	result Probe(const Osp::Base::ByteBuffer &srcBuf, int &width, int &height, MediaPixelFormat& pixelFormat);

	/**
	 *	Decodes the video data from the source buffer and stores the decoded data into the destination buffer.
	 *
	 *	@since	2.0
	 *	@return 	An error code
	 *
	 *	@param[in]	srcBuf					The source buffer that stores the compressed video data
	 *	@param[out]	dstBuf					The destination buffer that stores the decoded video data
	 *	@param[out]	gotFrame			@c true when a frame is decoded, @n
											else @c false
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			The specified @c srcBuf or @c dstBuf is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The destination buffer has insufficient memory.
         *      @exception      E_DIMENSION_CHANGED        The dimension of video stream has changed.
         *	@exception 	E_SYSTEM				A system error has occurred.
	 *	@remarks	The destination buffer must have sufficient free space to store the decoded frame data.
	 *	@remarks	The decoder starts the decoding of the frame from the current position of the source buffer, 
	 *				and moves the position of the source buffer to the end of the consumed data. 
	 *				The decoder also fills the destination buffer with the decoded frame from the current position of the destination buffer, 
	 *				and moves the position of the destination buffer to the end of the decoded frame.
         *      @remarks  	When the first decoding begins, the E_DIMENSION_CHANGED exception can occur. 
         *                  	An exception can also occur when the dimension of the video frame in the bitstream has changed.
         *                  	An application should increase the size of @c dstBuf if the @c dstBuf cannot hold the video frame with new dimensions.
         *                  	The video frame can be received even if the result is E_DIMENSION_CHANGED.
         *                  	The application should check the @c position of the destination buffer and the value of @c gotFrame 
         *                  	when the result is E_DIMENSION_CHANGED.
         *	@remarks	The H.264 video decoder returns data with the width and height in multiples of 16.
	*			The application should detect the width and height of the frame and crop the decoder's output data if the original dimension is not a multiple of 16.    
	 *	@see Probe()
	 */
	result Decode(Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &dstBuf, bool &gotFrame);

	/**
	 *	Resets the internal state of the video decoder to process a new video stream.
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
	 *	Gets the specified property value of this instance.
	 *
	 *	@since	2.0
	 *	@return 		An error code
	 *
	 *	@param[in]		key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
	 *	@param[out]		value				The obtained property value
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND		   The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The property whose value is of type enum can be obtained by using this method.
	 */
	result GetValue(MediaPropertyType key, int &value) const;


	/**
	 *	Gets the specified property value of this instance.
	 *
	 *	@since	2.0
	 *	@return 		An error code
	 *
	 *	@param[in]		key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
	 *	@param[out]		value				The obtained property value
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 			This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *    @remarks	The property whose value is of type enum can be obtained using this method.
	 */
	result GetValue(MediaPropertyType key, float &value) const;

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
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 *		The return value must be deleted.
	 */
	Osp::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property is supported.
	 *
	 *	@since	2.0
	 *	@return 	@c true if the property is supported, @n
	 *				else @c false
	 *
	 *	@param[in]	key					The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
	 *	@exception	E_SUCCESS 			The method is successful.
	 *	@exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPropertySupported(MediaPropertyType key) const;

protected:



private:
	VideoDecoder(const VideoDecoder& dec);
	VideoDecoder& operator =(const VideoDecoder& dec);

	friend class __VideoDecoderImpl;
	class __VideoDecoderImpl* __impl;
};

}; };


#endif
