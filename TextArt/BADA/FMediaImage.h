/* $Change: 1142016 $ */
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
* @file			FMediaImage.h 
* @brief		This is the header file for the %Image class.
*
* This header file contains the declarations of the %Image class. 
*/

#ifndef _FMEDIA_IMAGE_IMAGEUTIL_H_
#define _FMEDIA_IMAGE_IMAGEUTIL_H_

// Include
#include <FBase.h>
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaImageCommon.h"
#include "FMediaIImageEventListener.h"

namespace Osp{ namespace Media{ 

class IImagePi;
class __ImageUriDataFactory;

/**
 * @class	Image
 * @brief	This class is used for handling images.
 * @since	1.0
 *
 * 
 * The %Image class is used for handling images, including image decoding, encoding, conversion, and JPEG compression. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>.
 *
 * The following example demonstrates how to use the %Image class for image decoding.

 *
 * 
 *
 *	@code
 *	// Includes
 *  #include <FMedia.h>
 *  #include <FGraphics.h>
 *  #include <FIo.h>
 *  #include <FUi.h>
 *	
 *	// Namespace
 *  using namespace Osp::Base;
 *  using namespace Osp::Media;
 *  using namespace Osp::Graphics;
 *  using namespace Osp::Io;
 *  using namespace Osp::Ui::Controls;
 *
 * @endcode
 * 
 * @code
 *	#define SCREEN_WIDTH 320
 *	#define SCREEN_HEIGHT 240
 *	
 *	result TestDecoding(Form *pForm)
 *	{
 *		result r = E_SUCCESS;
 *		Bitmap* pBitmap = null;
 *		Canvas *pCanvas = null;
 *		Osp::Graphics::Rectangle rect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
 *		String path("/Media/Images/Sample.jpg");
 *		int width = 0, height = 0;
 *		
 *		// Create an Image instance.
 *		Image *pImage = new Image();
 *		r = pImage->Construct();
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		// Decode the image.
 *		pBitmap = pImage->DecodeN(path, BITMAP_PIXEL_FORMAT_RGB565, SCREEN_WIDTH, SCREEN_HEIGHT);           
 *		if (null == pBitmap ) goto CATCH;		
 *	
 *		// Get the image's size.
 *		width = pBitmap->GetWidth();
 *		height = pBitmap->GetHeight();
 *		
 *		// Delete the image instance.
 *		delete pImage;
 *	
 *		// Get a Canvas instance.
 *		pCanvas = pForm->GetCanvasN();
 *	
 *		r = pCanvas->DrawBitmap(rect, *pBitmap);
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		r = pCanvas->Show();
 *		if (IsFailed(r)) goto CATCH;
 *	
 *	
 *		CATCH:
 *			delete pImage;
 *			delete pCanvas;	
 *			delete pBitmap;	
 *			
 *		return r;
 *	
 *	}
 * 	@endcode
 *
 *
 * The following example demonstrates how to use the %Image class for image encoding.
 *
 * @code
 *	result TestEncoding()
 *	{
 *		result r = E_SUCCESS;
 *		Bitmap* pBitmap = null;
 *		String path("/Media/Images/Sample.jpg");
 *		ByteBuffer *pBuffer=0;
 *		File *pFile = null;
 *		Image *pImage = null;
 *	
 *		pImage = new Image();
 *		r = pImage->Construct();
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		pBitmap = pImage->DecodeN(path, BITMAP_PIXEL_FORMAT_RGB565, SCREEN_WIDTH, SCREEN_HEIGHT  );
 *		if (null == pBitmap ) goto CATCH;		
 *		
 *		pBuffer = pImage->EncodeToBufferN(*pBitmap, IMG_FORMAT_JPG );
 *		if (null == pBuffer ) goto CATCH;		
 *	
 *		pFile = new File;
 *		r = pFile->Construct("/Home/Sample_out.jpg", L"w+");
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		r = pFile->Write(*pBuffer);
 *	
 *		CATCH:
 *			delete pImage;
 *			delete pBuffer;	
 *			delete pFile;	
 *			
 *		return r;
 *	}
 * @endcode
 *
 * The following example demonstrates how to use the %Image class to compress an image.
 * 
 * @code
 *	result TestJpegCompressing()
 *	{
 *		result r=E_SUCCESS;
 *		int limitSize = 20*1024;		// Limit size is 20 kbytes.
 *		String path("/Media/Images/Sample.jpg");
 *		String destPath("/Media/Images/Sample_compressed.jpg");
 *	
 *		Image *pImage = new Image();
 *		r = pImage->Construct();
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		// Compress the Jpeg.
 *		r = pImage->CompressJpeg (path, destPath,limitSize );
 *		if (IsFailed(r)) goto CATCH;
 *	
 *		CATCH:
 *			delete pImage;	
 *		return r;
 *	}
 * @endcode
 *
 * The following example demonstrates how to use the %Bitmap class to encode an image without using buffer scaling.
 *
 * @code
 *	result TestEncodingToBitmap()
 *	{
 *		result r = E_SUCCESS;
 *		Bitmap* pBitmap = null;
 *		String path("/Media/Images/Sample.jpg");
 *		ByteBuffer *pBuffer=0;
 *		Image *pImage = null;
 *		int widht = 0;
 *		int height = 0;
 *		
 *		pImage = new Image();
 *		r = pImage->Construct();
 *		if (IsFailed(r)) goto CATCH;
 *		
 *		pBuffer = pImage->DecodeToBufferN(path, BITMAP_PIXEL_FORMAT_RGB565, widht, height );
 *		r = GetLastResult();
 *		if (IsFailed(r)) goto CATCH;
 *		
 *		pBitmap = new Bitmap();
 *		// Construct Bitmap without buffer scaling.
 *		r = pBitmap->Construct(*pBuffer, Dimension(widht, height), BITMAP_PIXEL_FORMAT_RGB565, BUFFER_SCALING_NONE);
 *		if (IsFailed(r)) goto CATCH;
 *		
 *		CATCH:
 *			delete pImage;
 *			delete pBuffer;
 *			delete pBitmap;
 *
 *		return r;
 *	}
 * @endcode
 *
 */

class _EXPORT_MEDIA_ Image :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	* @see 		Construct()
	*/	 
	Image(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	* @see 		Construct()
	*/
	virtual ~Image(void);


// Operation
public:

	/**
	* Initializes this instance of %Image.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		A system error has occurred.
	*/	  
	result Construct(void);

	/**
	* Decodes an image file into the decoded bitmap container. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
	*                For more information, see @ref CompMediaImageDecodePage "here".
	*
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A decoded bitmap that is not resized
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]  	pixelFormat				The pixel format defined by Osp::Graphics::BitmapPixelFormat
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			A specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.	
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		This method retains the aspect ratio of the original image.
	*			    E_OUT_OF_MEMORY can be thrown if there is no available memory when decoding a large image.
	*				The specific error code can be accessed using the GetLastResult() method.
	*				The returned %Bitmap will be auto-scaled, if auto-scaling is set to true in application.xml. 
	*/
	Osp::Graphics::Bitmap* DecodeN( const Osp::Base::String& srcImagePath, Osp::Graphics::BitmapPixelFormat pixelFormat ) const;


	/**
	* Decodes an image file into the decoded bitmap container after resizing it as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
	*                For more information, see @ref CompMediaImageDecodePage "here".
	*
	* @privlevel	NORMAL
	* @privgroup	IMAGE
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in] 	pixelFormat				The pixel format defined by Osp::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @param[in]	destHeight				The intended height of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			A specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		This method retains the aspect ratio of the original image.
	*				It supports only the downscaling of an image.
	*				The specific error code can be accessed using the GetLastResult() method.
	*				The returned %Bitmap will be auto-scaled, if auto-scaling is set to true in application.xml. 
	*/
	Osp::Graphics::Bitmap* DecodeN( const Osp::Base::String& srcImagePath, Osp::Graphics::BitmapPixelFormat pixelFormat,
										int destWidth, int destHeight ) const;

	/**
	* Accepts an image URL to receive the decoded resized bitmap as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		An error code
	* @param[in]	srcImageUrl			The URL of the remote image to decode
	* @param[in] 	pixelFormat			The pixel format defined by Osp::Graphics::BitmapPixelFormat
	* @param[in]	destWidth			The intended width of the image @n
	*									An exception is thrown if the value is less than @c 0.
	* @param[in]	destHeight			The intended height of the image @n
	*									An exception is thrown if the value is less than @c 0.
	* @param[out] 	reqId               The request ID
	* @param[in]	listener			An event listener instance
	* @param[in]  	timeout				The timeout period in milliseconds @n
	*									Set to @c TIMEOUT_INFINITE to make the @c timeout period infinite.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_INVALID_DATA		The specified input instance has invalid data.		
	* @exception	E_INVALID_ARG		A specified pixel format is not supported.
	* @exception	E_OUT_OF_RANGE		The specified size is out of range.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_NETWORK_FAILED	The network is unavailable.
	* @exception	E_MAX_EXCEEDED		The number of concurrent accesses to the URLs has reached the maximum limit.
	* @exception	E_INTERRUPTED 		The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		This method retains the aspect ratio of the original image.
	*				It supports only the downscaling of an image.
	*				The maximum limit for downscaling is 3.
	*				The supported protocol is HTTP.
	*/
	result DecodeUrl( const Osp::Base::Utility::Uri& srcImageUrl, Osp::Graphics::BitmapPixelFormat pixelFormat,
												  int destWidth, int destHeight, RequestId &reqId, const IImageDecodeUrlEventListener& listener, long timeout ) const;


	/**
	* Decodes an image data into the decoded bitmap container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. This method retains the 
	* aspect ratio of the original image.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
	*                For more information, see @ref CompMediaImageDecodePage "here".
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A decoded bitmap data that has not been resized
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input file
	* @param[in] 	pixelFormat				The pixel format defined by Osp::Graphics::BitmapPixelFormat
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.		
	* @exception	E_INVALID_ARG			A specified pixel format is not supported.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		This method retains the aspect ratio of the original image.
	*				E_OUT_OF_MEMORY is thrown if the memory is not available when decoding a large image.
	*				The specific error code can be accessed using the GetLastResult() method.
	*				The returned %Bitmap will be auto-scaled, if auto-scaling is set to true in application.xml. 
	*/
	Osp::Graphics::Bitmap* DecodeN( const Osp::Base::ByteBuffer& srcImageBuf, ImageFormat srcImageFormat,
										Osp::Graphics::BitmapPixelFormat pixelFormat ) const;

	/**
	* Decodes an image data into the decoded bitmap container after resizing it as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
	*                For more information, see @ref CompMediaImageDecodePage "here".
	*
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input file
	* @param[in]	pixelFormat				The pixel format defined by Osp::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image @n
	*										An exception is thrown if the value is less than @c 0. 
	* @param[in]	destHeight				The intended height of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			A specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.		
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		This method retains the aspect ratio of the original image.
	*				It supports only the downscaling of an image.
	*				The specific error code can be accessed using the GetLastResult() method.
	*				The returned %Bitmap will be auto-scaled, if auto-scaling is set to true in application.xml. 
	*/
	Osp::Graphics::Bitmap* DecodeN( const Osp::Base::ByteBuffer& srcImageBuf, ImageFormat srcImageFormat,
										Osp::Graphics::BitmapPixelFormat pixelFormat, int destWidth, int destHeight ) const;

	/**
	* Encodes the specified bitmap data into a byte buffer. @n
	* The currently supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A byte buffer containing encoded image data
	* @param[in]	srcBitmap				The bitmap data to encode
	* @param[in]	destImageFormat			The intended image format
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified bitmap data cannot be found.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::ByteBuffer* EncodeToBufferN(const Osp::Graphics::Bitmap& srcBitmap, ImageFormat destImageFormat ) const;


	/**
	* Encodes the specified bitmap data into a file. @n
	* The currently supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		An error code
	* @param[in]	srcBitmap				The bitmap data to encode
	* @param[in]	destImageFormat			The intended image format
	* @param[in]	destImagePath			The intended name of encoded image file @n
	*										The available paths start with prefixes such as: @n
	*										@li "/Media/" @n
	*										@li "/Storagecard/Media/" @n
	*										@li "/Home/" (user home storage)
	* @param[in]	overwrite				Set to @c true to overwrite the file, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OBJ_NOT_FOUND			The specified bitmap data cannot be found.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_STORAGE_FULL 			The storage is full.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed any further due to an interruption from another thread. For example, an incoming call.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*				The application registers newly created files into the Contents database using Osp::Content::ContentManager::CreateContent() if the file's path starts with "/Media" or "/Storagecard/Media".
	*/
	result EncodeToFile(const Osp::Graphics::Bitmap& srcBitmap, ImageFormat destImageFormat,
							const Osp::Base::String& destImagePath, bool overwrite) const;

	/**
	* Converts the image file to the specified image format. @n
	* This is a synchronous method. The converting formats currently supported are JPEG, BMP, and PNG.
	*
	* @since		1.0
	* @privlevel 	NORMAL
	* @privgroup  	IMAGE
	* @return		The byte buffer containing image data
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]	destImageFormat			The intended image format
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.			
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed any further due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::ByteBuffer* ConvertN ( const Osp::Base::String& srcImagePath, ImageFormat destImageFormat ) const;

	/**
	* Recompresses an encoded image file to reduce its size as per the specified limit. @n
	* The only supported compression format is JPEG.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup   	IMAGE
	* @return		An error code
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]	destImagePath			The destination file path @n
	*										If the file already exists, it is overwritten. @n
	*										The available paths start with prefixes such as: 
	*										@li "/Media/"
	*										@li "/Storagecard/Media/" 
	*										@li "/Home/" (user home storage) @n
	* @param[in]	limitSize				The maximum compressed data size in bytes @n
	*										If the data size is too small, the width and height of the original 
	*										image can be reduced @n The size should be less than the original size 
	*										and greater than @c 1024 byte.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_STORAGE_FULL 			The file cannot be created because the file has reached its size limit.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The application can register the newly created files into the Contents database using Osp::Content::ContentManager if the file's path starts with "/Media" or "/Storagecard/Media".
	*/
	result CompressJpeg ( const Osp::Base::String& srcImagePath, const Osp::Base::String& destImagePath, int limitSize ) const;

	/**
	* Recompresses an encoded image data to the byte buffer to reduce its data size as per the specified limit. @n
	* The only supported compression format is JPEG.
	*	
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A byte buffer containing the compressed image data as per the specified size
	* @param[in]	srcImageBuf				The decoded image source in the byte buffer
	* @param[in]	limitSize				The limit size to be compressed in bytes @n
	*										The size should be less than the original size and greater than @c 1024 bytes.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::ByteBuffer* CompressJpegN ( const Osp::Base::ByteBuffer& srcImageBuf, int limitSize ) const;


	/**
	* Gets the format of the image in the specified file.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		ImageFormat				The format of the image
	* @param[in]	srcImageFile			The local path of the image file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Media::ImageFormat GetImageFormat( const Osp::Base::String& srcImageFile) const;

	/**
	* Gets the image format from an image buffer.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		ImageFormat				The format of the image
	* @param[in]	srcImageBuf				The ByteBuffer containing the image data
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Media::ImageFormat GetImageFormat( const Osp::Base::ByteBuffer& srcImageBuf) const;

	/**
	* Checks whether the specified image file has alpha channels. @n
	* Currently, only 32-bit PNG images are supported.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		@c true if the image has alpha channels, @n
	*				else @c false
	* @param[in]	srcImageFile			The local file path of the image file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified image file cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	bool HasAlphaChannels( const Osp::Base::String& srcImageFile) const;

	/**
	* Checks whether the specified image buffer has alpha channels. @n
	* Currently only 32-bit PNG images are supported.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		@c true if the image has alpha channels, @n
	*				else @c false
	* @param[in]	srcImageBuf				The ByteBuffer containing the image data
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	bool HasAlphaChannels( const Osp::Base::ByteBuffer& srcImageBuf) const;

	/**
	* Decodes an image data into the decoded byte buffer container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.1
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A decoded byte data that is not resized, @n
	*				else @c null if an exception occurs
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input data
	* @param[in]	colorFormat				The color format defined by Osp::Graphics::BitmapPixelFormat
	* @param[out]	imageWidth			The original width of the image @n
	*										An exception is thrown if the value is less than @c 0. 
	* @param[out]	imageHeight			The original height of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			A specified color format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified media buffer cannot be found.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::ByteBuffer* DecodeToBufferN(const Osp::Base::ByteBuffer &srcImageBuf, ImageFormat srcImageFormat, Osp::Graphics::BitmapPixelFormat colorFormat, int &imageWidth, int &imageHeight) const;
	
	/**
	* Decodes an image file into the decoded byte buffer container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		1.1
	* @privlevel	NORMAL
	* @privgroup  	IMAGE
	* @return		A decoded byte data that is not resized, @n
	*				else @c null if an exception occurs
	* @param[in]	srcImagePath			The local file path of the image file to decode
	* @param[in]	colorFormat				The color format defined by Osp::Graphics::BitmapPixelFormat
	* @param[out]	imageWidth			The original width of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @param[out]	imageHeight			The original height of the image @n
	*										An exception is thrown if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG			A specified color format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.		
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INTERRUPTED 			The requested operation cannot be performed due to an interruption from another thread. For example, an incoming call.
	* @exception	E_ILLEGAL_ACCESS		The specified image is protected with DRM.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::ByteBuffer* DecodeToBufferN(const Osp::Base::String &srcImagePath, Osp::Graphics::BitmapPixelFormat colorFormat, int &imageWidth, int &imageHeight) const;

	/**
	 * Sets the timeout interval to infinity.
	 *
	 * @since	1.0
	 */
	static const int TIMEOUT_INFINITE = 0; 

	/** 
	* @page 	CompMediaImageDecodePage Compatibility for DecodeN()
	* @section  CompMediaImageDecodeIssueSection Issues 
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	* 
	* -# If the image has orientation value in the EXIF data and is decoded with PIXEL_FORMAT_ARGB8888 format, the result image gets rotated. @n
	* 
	* @section CompMediaImageDecodeIssueSection Resolutions 
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	*/
	
private :
	Image(const Image& image);
	Image& operator =(const Image& image);

	IImagePi*		__pImageInterface;
	__ImageUriDataFactory* __pImageUriDataFactory;

	friend class ImageEx;
	class ImageEx* __pImageEx;
};

};};// Osp::Media

#endif
