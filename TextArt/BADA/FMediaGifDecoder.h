// Open Service Platform
// Copyright (c) 2011 Samsung Electronics, Inc.
// All rights reserved.
//
// This software is the confidential and proprietary information
// of Samsung Electronics, Inc. ("Confidential Information"). You
// shall not disclose such Confidential Information and shall use
// it only in accordance with the terms of the license agreement
// you entered into with Samsung Electronics.
//
/** 
 * @file		FMediaGifDecoder.h 
 * @brief		This header file contains the declaration of Osp::Media namespace.
 *
 */

#ifndef FMEDIA_GIFDECODER_H_
#define FMEDIA_GIFDECODER_H_

#include <FBase.h>
#include <FIo.h>
#include <FGraphics.h>

#include "FMediaTypes.h"
#include "FMediaConfig.h"


typedef struct GifFileType GifFileType;
typedef unsigned char GifByteType;
typedef struct ColorMapObject ColorMapObject;

namespace Osp { namespace Media {

/**
 * @internal
 * @class	GifDecoder
 * @brief	Support of Gif image decoding.
 * @since 2.0
 *
 *	This class provides APIs for GIF image decoding.
 * 	This class support animated GIF decoding also.
 *
 * @code
 * #include <FMedia.h>
 * #include <FGraphics.h>
 * #include "FMediaGifDecoder.h"
 * 
 * using namespace Osp::Media;
 * using namespace Osp::Graphics;
 * using namespace Osp::Base;
 * 
 * result GifDecoderTest()
 * {
 * 	result r;
 * 	GifDecoder gifDec;
 * 	long duration;
 * 	Bitmap *pBmp = null;
 * 	Image img;
 * 	int i=0;
 * 	String filename;
 * 
 * 	r = gifDec.Construct(L"/Home/test.gif", MEDIA_PIXEL_FORMAT_BGRA8888);
 * 	TryCatch(r == E_SUCCESS, , "gifDec.Construct failed:%s", GetErrorMessage(r));
 * 
 * 	img.Construct();
 * 
 * 	while( (pBmp = gifDec.GetNextBitmapN(duration)) != null) {
 * 		AppLog("pBmp:%dx%d dur=%d", pBmp->GetWidth(), pBmp->GetHeight(), duration);
 * 		filename.Format(256, L"/Home/dump_%d.bmp", i++);
 * 		img.EncodeToFile(*pBmp, IMG_FORMAT_BMP, filename, true);
 * 
 * 		delete pBmp;
 * 	}
 * 
 * CATCH:
 * 	return r;
 * }
 * @endcode
 */
class _EXPORT_MEDIA_ GifDecoder :
	public Osp::Base::Object
{
public:
        /**
	 * @internal
	 * @since 2.0
         *	The constructor.
         */	    
	GifDecoder(void);
	
        /**
	 * @internal
	 * @since 2.0
         *	The destructor.
         */
	virtual ~GifDecoder(void);

	/**
	 * Initializes a new instance of this class
	 *
	 * @internal
	 * @since	2.0
	 * @return	An error code
	 *
	 * @param[in]	filePath	The file path of image.
	 * @param[in]	pixelFormat	The output pixel format of the decoded image.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.
	 * @exception 	E_INVALID_DATA	The input data is invalid.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_INVALID_ARG			A specified pixel format is not supported.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM	A system error occurred.
	 * @remarks	Supported pixelFormats are MEDIA_PIXEL_FORMAT_RGB565LE, and MEDIA_PIXEL_FORMAT_BGRA8888.
	 */
	result Construct(const Osp::Base::String &filePath, MediaPixelFormat pixelFormat);
	
	/**
	 * Initializes a new instance of this class
	 *
	 * @internal
	 * @since	2.0 
	 * @return	An error code
	 *
	 * @param[in]	srcBuf		The source buffer that the image data is stored.
	 * @param[in]	pixelFormat	The output pixel format of the decoded image.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.
	 * @exception 	E_INVALID_DATA	The input data is invalid.
	 * @exception	E_INVALID_ARG			A specified pixel format is not supported.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM	A system error occurred.
	 * @remarks	Supported pixelFormats are MEDIA_PIXEL_FORMAT_RGB565LE, and MEDIA_PIXEL_FORMAT_BGRA8888.
	 */
	result Construct(const Osp::Base::ByteBuffer &srcBuf, MediaPixelFormat pixelFormat);
	
	/**
	 * Gets the width of the image.
	 *
	 * @internal
	 * @since	2.0
	 * @return	The width of image, @n
	 *		else @c 0 when an error occurred.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.
          * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetWidth(void) const;
	
	/**
	 * Gets the height of the image.
	 *
	 * @internal
	 * @since	2.0
	 * @return	The height of the image, @n
	 *		else @c 0 when an error occurred.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.	 
          * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetHeight(void) const;
	
	/**
	 * Decodes and gets the next frame in RAW RGB format.
	 *
	 * @internal
	 * @since	2.0
	 *
	 * @return	The next decoded frame. @n
	 *		else @c null when no frame is left or an error occurred.
	 * @param[out]	duration	The duration of returned frame in miliseconds.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.	 
	 * @exception 	E_INVALID_DATA	The data of the next frame is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM	A system error occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */	
	Osp::Base::ByteBuffer* GetNextFrameN(long &duration);

	/**
	 * Decodes and gets the next frame in Bitmap format.
	 *
	 * @internal
	 * @since	2.0
	 *
	 * @return	The next decoded frame. @n
	 *		else @c null when no frame is left or an error occurred.	 
	 * @param[out]	duration	The duration of returned frame in miliseconds.
	 * @param[in]	bufferScaling		The buffer scaling type.
	 *
	 * @exception	E_SUCCESS	The method was successful.
	 * @exception	E_INVALID_STATE	Current state is invalid.	 
	 * @exception 	E_INVALID_DATA	The data of the next frame is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM	A system error occurred.
	 * @remarks	When autoScale parameter is true auto scaled Bitmap will be returned. @n
	 *			The specific error code can be accessed using the GetLastResult() method.	 
	 */	
	Osp::Graphics::Bitmap* GetNextBitmapN(long &duration, Osp::Graphics::BufferScaling bufferScaling=Osp::Graphics::BUFFER_SCALING_AUTO);

private:
	static int FileReadFuncStatic(GifFileType* gifFile, GifByteType* buf, int count);
	static int BufferReadFuncStatic(GifFileType* gifFile, GifByteType* buf, int count);
	int FileReadFunc(GifFileType* gifFile, GifByteType* buf, int count);
	int BufferReadFunc(GifFileType* gifFile, GifByteType* buf, int count);
	byte* GeneratePalette(MediaPixelFormat pixelFormat, ColorMapObject *colorMap);
	result __Construct(MediaPixelFormat pixelFormat);

	GifFileType *__gifFile;
	Osp::Base::ByteBuffer __srcBuf;
	Osp::Io::File __file;
	MediaPixelFormat __pixelFormat;
	byte *__globalPalette, *__localPalette;
	int __bpp;
	Osp::Base::ByteBuffer __dstBuf;
	bool __transparent;
	unsigned int __transColor;

	GifDecoder(const GifDecoder& gifDecoder);
	GifDecoder& operator =(const GifDecoder& gifDecoder);
	friend class GifDecoderEx;
	class GifDecoderEx* __pGifDecoderEx;
	
};

}; };

#endif /* FMEDIA_GIFIMAGE_H_ */
