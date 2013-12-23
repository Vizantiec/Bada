// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FMediaImageUtil.h
 * @brief		This is the header file for the %ImageUtil class.
 *
 * This header file contains the declarations of the %ImageUtil class.
 *
 */
#ifndef FMEDIA_IMAGEUTIL_H_
#define FMEDIA_IMAGEUTIL_H_

#include "FBase.h"
#include "FGraphics.h"
#include "FMediaConfig.h"

#include "FMediaTypes.h"
#include "FMediaImageUtilTypes.h"

namespace Osp { namespace Media {

/**
 * @class     ImageUtil
 * @brief     This class provides methods for converting the color space of the image, flipping, rotating, or resizing. 
 * @since     2.0
 *
 * The %ImageUtil class provides methods for image pixel format conversion and image scaling, such as resizing, rotating, and flipping.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>.
 *
 * The following example demonstrates how to use the %ImageUtil class.

 * @code
 *  
 * #define YUV_WIDTH 352
 * #define YUV_HEIGHT 288
 * #define YUV420_PIXEL_SIZE 1.5
 * #define RGB565_PIXEL_SIZE 2
 * String YUVsrcImagePath = "/Home/UTsMedia/Images/YUV/ImageUtilTest.yuv";
 * 
 * byte* GetByteFromYUV420N(String srcPath, int width, int height);
 * 
 * result ConvertYUV420ToRGB565()
 * {
 * 	
 * 	result r = E_SUCCESS;
 * 	
 * 	byte* pImageData = null;
 * 	
 * 	ByteBuffer inBuf;
 * 	ByteBuffer outBuf;
 * 	
 * 	Bitmap bitmap;
 * 	Image image;
 * 	Dimension dim;
 * 	
 * 	int YUVsize = YUV_WIDTH*YUV_HEIGHT*YUV420_PIXEL_SIZE;
 * 	int RGBsize = YUV_WIDTH*YUV_HEIGHT*RGB565_PIXEL_SIZE;
 * 	String destImagePath = "/Home/UTsMedia/Images/ConvertYUV2RGB.bmp";
 * 	
 * 	pImageData = GetByteFromYUV420N(YUVsrcImagePath, YUV_WIDTH, YUV_HEIGHT);
 * 	if(pImageData == null) {
 * 		r = E_SYSTEM;
 * 		goto CATCH;
 * 	}
 * 	
 * 	// Create buffer.
 * 	r = inBuf.Construct(YUVsize);
 * 	if(IsFailed(r)) goto CATCH;
 * 	r = outBuf.Construct(RGBsize);
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	// Set limit and position.
 * 	r = inBuf.SetLimit(YUVsize);
 * 	if(IsFailed(r)) goto CATCH;
 * 	r = outBuf.SetLimit(RGBsize);
 * 	if(IsFailed(r)) goto CATCH;
 * 	r = inBuf.SetPosition(0);
 * 	if(IsFailed(r)) goto CATCH;
 * 	r = outBuf.SetPosition(0);
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	// Make input buffer.
 * 	r = inBuf.SetArray(pImageData, 0, YUVsize);
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	dim = Dimension(YUV_WIDTH, YUV_HEIGHT);
 * 	// Convert pixel format.
 * 	ImageUtil::ConvertPixelFormat(inBuf, outBuf, MEDIA_PIXEL_FORMAT_YUV420P, MEDIA_PIXEL_FORMAT_RGB565LE, dim);
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	// Make bitmap.
 * 	r = bitmap.Construct(outBuf, Dimension(YUV_WIDTH, YUV_HEIGHT), BITMAP_PIXEL_FORMAT_RGB565  );
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	r = image.Construct();
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	r = image.EncodeToFile(bitmap, IMG_FORMAT_BMP, destImagePath, true);
 * 	if(IsFailed(r)) goto CATCH;
 * 	
 * 	delete[] pImageData;
 * 	
 * 	return r;
 * CATCH:
 * 	
 * 	delete[] pImageData;
 * 	return r;
 * }
 * 
 * 
 * byte* GetByteFromYUV420N(String srcPath, int width, int height)
 * {
 * 	byte* pImageData = null;
 * 	int size = 0;
 * 	File file;
 * 	
 * 	result r = E_SUCCESS;
 * 	
 * 	r = file.Construct(srcPath, "rb");
 * 	TryCatch(r == E_SUCCESS, ,"File::Construct() Failed - %s", GetErrorMessage(r));
 * 	
 * 	size = (height * width * YUV420_PIXEL_SIZE);
 * 	
 * 	pImageData = new byte[size];
 * 	file.Read(pImageData, size);
 * 	
 * 	return pImageData;
 * 	
 * CATCH:
 * 	if (pImageData != null)
 * 		delete[] pImageData;
 * 	
 * 	return null;
 * 
 * }
 *
 * @endcode
 *
 */

class _EXPORT_MEDIA_ ImageUtil
{

public:
       /**
       *   Converts the pixel format of the image.
       *
       *   @since       2.0
       *   @return     An error code
       *   @param[in]	srcBuf                       The source buffer
       *   @param[out]	destBuf                      The destination buffer
       *   @param[in]	srcPixelFormat               The source pixel format
       *   @param[in]	destPixelFormat              The destination pixel format
       *   @param[in]	dim                          The width and height of the source and destination images @n
       *                                             The value of the width and height must be greater than or equal to @c 1.
       *
       *   @exception   E_SUCCESS                    The method is successful.
       *   @exception   E_UNSUPPORTED_FORMAT         The specified format is not supported.
       *   @exception   E_INVALID_ARG                The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
       *   @exception   E_INVALID_DATA               A source image data in the buffer is invalid.
       *   @exception   E_OUT_OF_MEMORY              The memory is insufficient.
       *   @exception   E_SYSTEM                     A system error has occurred.
       *
       *   @remarks		The supported pixel formats are MEDIA_PIXEL_FORMAT_RGB565LE, MEDIA_PIXEL_FORMAT_BGRA8888, and MEDIA_PIXEL_FORMAT_YUV420P. @n
       *   				The conversion is possible between: @n
       *											- MEDIA_PIXEL_FORMAT_YUV420P and MEDIA_PIXEL_FORMAT_RGB565LE. @n
       *											- MEDIA_PIXEL_FORMAT_YUV420P and MEDIA_PIXEL_FORMAT_BGRA8888. @n
       * @remarks		The position and limit of @c destBuf are set along with the size of the converted data.
       */
       static result ConvertPixelFormat(const Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &destBuf, MediaPixelFormat srcPixelFormat, MediaPixelFormat destPixelFormat, const Osp::Graphics::Dimension &dim);

       /**
       *   Resizes the image.
       *
       *   @since       2.0
       *   @return     An error code
       *   @param[in]   srcBuf						The source buffer
       *   @param[out]  destBuf						The destination buffer
       *   @param[in]   srcDim						The width and height of the source image @n
       *                                            The value of the width and height must be greater than or equal to @c 1.
       *   @param[in]   destDim						The width and height of the destination image @n
       *                                            The value of the width and height must be greater than or equal to @c 1.
       *   @param[in]   pixelFormat					The source and destination pixel format
       *
       *   @exception   E_SUCCESS                   The method is successful.
       *   @exception   E_UNSUPPORTED_FORMAT        The specified format is not supported.
       *   @exception   E_INVALID_ARG               The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
       *   @exception   E_INVALID_DATA              A source image data in the buffer is invalid.
       *   @exception   E_OUT_OF_MEMORY             The memory is insufficient.
       *   @exception   E_SYSTEM                    A system error has occurred.
       *
       *   @remarks		The supported pixel formats are MEDIA_PIXEL_FORMAT_RGB565LE, MEDIA_PIXEL_FORMAT_BGRA8888, and MEDIA_PIXEL_FORMAT_YUV420P. @n
       *				The position and limit of @c destBuf are set along with the size of the resized data. @n
       *				The minimum resolution is 16x16.
       */
       static result Resize(const Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &destBuf, const Osp::Graphics::Dimension &srcDim, const Osp::Graphics::Dimension &destDim, MediaPixelFormat pixelFormat );

       /**
       *   Rotates the image.
       *
       *   @since       2.0
       *   @return     An error code
       *   @param[in]   srcBuf						The source buffer
       *   @param[out]  destBuf						The destination buffer
       *   @param[in]   dim							The width and height of the source image @n
       *                                            The value of the width and height must be equal to or greater than @c 1.
       *   @param[in]   rotate						The rotation type
       *   @param[in]   pixelFormat					The source and destination pixel formats
       *
       *   @exception   E_SUCCESS					The method is successful.
       *   @exception  E_UNSUPPORTED_FORMAT			The specified format is not supported.
       *   @exception   E_INVALID_ARG				The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
       *   @exception   E_INVALID_DATA				A source image data in the buffer is invalid.
       *   @exception   E_OUT_OF_MEMORY				The memory is insufficient.
       *   @exception   E_SYSTEM					A system error has occurred.
       *
       *   @remarks		The supported pixel formats are MEDIA_PIXEL_FORMAT_RGB565LE, MEDIA_PIXEL_FORMAT_BGRA8888, and MEDIA_PIXEL_FORMAT_YUV420P. @n
       *				The position and limit of @c destBuf are set along with the size of the rotated data. @n
       *				The dimension of the destination buffer should be calculated by an application.
       *   @see			ImageRotationType
       */
       static result Rotate(const Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &destBuf, const Osp::Graphics::Dimension &dim, ImageRotationType rotate, MediaPixelFormat pixelFormat);

       /**
       *   Flips the image.
       *
       *   @since       2.0
       *   @return     An error code
       *   @param[in]   srcBuf						The source buffer
       *   @param[out]  destBuf						The destination buffer
       *   @param[in]   dim							The width and height of the source and destination images @n
       *                                            The value of the width and height must be equal to or greater than @c 1.
       *   @param[in]   flip						The flip type
       *   @param[in]   pixelFormat					The source and destination pixel formats
       *
       *   @exception   E_SUCCESS					The method is successful.
       *   @exception   E_UNSUPPORTED_FORMAT		The specified format is not supported.
       *   @exception   E_INVALID_ARG				The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
       *   @exception   E_INVALID_DATA				A source image data in the buffer is invalid.
       *   @exception   E_OUT_OF_MEMORY				The memory is insufficient.
       *   @exception   E_SYSTEM					A system error has occurred.
       *
       *   @remarks		The supported pixel formats are MEDIA_PIXEL_FORMAT_RGB565LE, MEDIA_PIXEL_FORMAT_BGRA8888, and MEDIA_PIXEL_FORMAT_YUV420P. @n
       *				The position and limit of @c destBuf are set along with the size of the flipped data.
       *   @see			ImageFlipType
      */
       static result Flip(const Osp::Base::ByteBuffer &srcBuf, Osp::Base::ByteBuffer &destBuf, const Osp::Graphics::Dimension &dim, ImageFlipType flip, MediaPixelFormat pixelFormat);

private:

   ImageUtil(void);
   virtual ~ImageUtil(void);

   ImageUtil(const ImageUtil& image);
   ImageUtil& operator =(const ImageUtil& image);

};

};};


#endif /* FMEDIA_IMAGEUTIL_H_ */
