// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 *	@file	FMediaHwVideoDecoder.h
 *	@brief	This is the header file for the %HwVideoDecoder class.
 *
 *	This header file contains the declarations of the %HwVideoDecoder class.
 */
#ifndef FMEDIA_HWVIDEODECODER_H_
#define FMEDIA_HWVIDEODECODER_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaTypes.h"

namespace Osp { namespace Media {


/**
 * @internal    This class is for internal use only. The bada platform team is not
 * responsible for any behavioral correctness, consistency, and
 * security-related issues that might arise after using this method.
 *
 *	@class	HwVideoDecoder
 *	@brief	This class decodes a compressed video stream into raw video data.
 *
 *	@since	2.0
 *
 * This class decodes a compressed video stream into raw video data.
 * The supported video decoder is CODEC_H264. @n@n
 *
 * The following example demonstrates how to use %HwVideoDecoder in H.264 decoding.
 * @code
 *
 * #include "FMediaHwVideoDecoder.h"
 *
 * using namespace Osp::Media;
 * using namespace Osp::Base;
 *
 * result GetFrameData(byte * &srcBuf, int &srcLength);
 * result GetDciInfo(ByteBuffer &dciBuf);
 * void DisplayFrame(const byte* frameData, int length, int width, int height, int pixelFormat);
 *
 * result TestVideoDecoder()
 * {
 * 	HwVideoDecoder dec;
 * 	MediaPixelFormat pixelFormat;
 * 	int width, height;
 * 	ByteBuffer dciInfo;
 * 	result r;
 * 	byte *srcBuf = null;
 * 	int srcLength;
 * 	byte *dstBuf = null;
 * 	int dstLength = 0;
 *
 * 	// Load SPS + PPS data with nal header.
 * 	GetDciInfo(dciInfo);

 * 	r = dec.Construct(CODEC_H264, dciInfo, pixelFormat, width, height);
 * 	if (IsFailed(r))
 * 		goto CATCH;
 *
 * 	while (true) {
 * 		r = GetFrameData(srcBuf, srcLength);
 * 		if (IsFailed(r))
 * 			break;
 * 		r = dec.Decode(srcBuf, srcLength, dstBuf, dstLength);
 * 		if (IsFailed(r))
 * 			break;
 *
 * 		// Get deferred frame.
 * 		while (dstBuf) {
 * 			DisplayFrame(dstBuf, dstLength, width, height, pixelFormat);
 *
 * 			r = dec.Decode(null, 0, dstBuf, dstLength);
 * 			if (IsFailed(r))
 * 				break;
 * 		}
 * 	}
 *
 * CATCH:
 * 	return r;
 * }
 * @endcode
 *
 */
class _EXPORT_MEDIA_ HwVideoDecoder :
	public Osp::Base::Object
{
public:

	/**
	 * @internal    This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 *	This is the default constructor for this class.
	 *
	 *	@since	2.0
	 *
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *	@see 		Construct()
	 */
	HwVideoDecoder(void);

	/**
	 * @internal    This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 *	This is the destructor for this class.
	 *
	 *	@since	2.0
	 */
	virtual ~HwVideoDecoder(void);

	/**
	 * @internal    This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited  This method is prohibited. If this method is used in an application, the
	 * application can get rejected during the certification process.
	 *
	 *	Initializes this instance with the specified parameters.
	 *
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type					The codec type
	 *	@param[in]	dciInfo					The bitstream that describes decoder config information
	 *	@param[out]	pixelFormat				Output pixel format
	 *	@param[out]	width					The video frame width
	 *	@param[out]	height					The video frame height
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC 	The specified decoder is not supported.
	 *	@exception	E_INVALID_ARG			One of input parameter is invalid.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_UNSUPPORTED_OPERATION	The API is not supported on this model.
	 *	@exception	E_OUT_OF_MEMORY			The memory is not sufficient.
	 *	@exception	E_DEVICE_BUSY			The H/W codec device is busy.
	 *  @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *
	 *	@remarks	The @c dciInfo is SPS(Sequence Parameter Sets) and PPS(Picture Parameter Sets) data with nal header in each data in case of CODEC_H264.
     *				If E_DEVICE_BUSY exception happens, then this instance should be deleted.
	 */
	result Construct(CodecType type, const Osp::Base::ByteBuffer &dciInfo, MediaPixelFormat& pixelFormat, int &width, int &height);


	/**
	 * @internal    This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited  This method is prohibited. If this method is used in an application, the
	 * application can get rejected during the certification process.
	 *
	 *	Decodes the video data from the source buffer and returns the address of decoded video frame in the destination buffer.
	 *
	 *	@since	2.0
	 *
	 *	@param[in]	srcBuf					The source buffer that stores the compressed video data
	 *	@param[in]	srcLength				The source buffer length
	 *	@param[out]	dstBuf					The destination buffer address that stores the decoded video data
	 *	@param[out]	dstLength				The destination buffer size that was filled.
	 *
	 *	@return 	An error code
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_INVALID_ARG			The specified @c srcBuf or @c dstBuf is invalid.
	 *	@exception	E_INVALID_DATA			The input data is invalid.
	 *	@exception	E_UNSUPPORTED_CODEC		The input data is not in a supported codec.
	 *	@exception	E_DEVICE_BUSY			The H/W codec device is busy.
	 *	@exception	E_OUT_OF_MEMORY			The system has insufficient memory.
	 *  @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
     *	@exception 	E_SYSTEM				A system error has occurred.
     *
     *	@remarks	The @c srcBuf should have one frame data, and the data should be sequence of nal units with nal header.@n
     *				The @c dstBuf is valid until next Decode(). @n
     *				The @c dstBuf should not be modified or deleted by application. @n
     *				If the @c srcBuf is null, then the deferred frame will be returned. @n
     *				If E_DEVICE_BUSY exception happens, then this instance should be deleted. @n
	 */
	result Decode(const byte* srcBuf, int srcLength, byte* &dstBuf, int &dstLength);

	/**
	 * @internal    This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @prohibited  This method is prohibited. If this method is used in an application, the
	 * application can get rejected during the certification process.
	 *
	 *	Resets the internal state of the video decoder to process new frame data.
	 *
	 *	@since	2.0
	 *
	 *	@return		An error code
	 *
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE 		This method is invalid for the current state of this instance.
	 *	@exception	E_DEVICE_BUSY			The H/W codec device is busy.
	 *  @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *
	 *	@remarks	This method will flush internal frame buffers, so that new frame can be processed. @n
	 *				Usually this method will be used when seeking, or unrecoverable frame corruption. @n
     *				If E_DEVICE_BUSY exception happens, then this instance should be deleted. @n
	 */
	result Reset(void);

protected:



private:
	HwVideoDecoder(const HwVideoDecoder& dec);
	HwVideoDecoder& operator =(const HwVideoDecoder& dec);

	class IHwVideoDecoderPi *__pPi;
	bool __opened;

	friend class __HwVideoDecoderEx;
	class __HwVideoDecoderEx* __ex;
};

}; };


#endif
