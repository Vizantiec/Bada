/* $Change: 1006494 $ */
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
 * @file		FGrpBitmap.h 
 * @brief		This is the header file for the %Bitmap class.
 *
 * This header file contains the declarations of the %Bitmap class. @n
 * The class encapsulates a bitmap, which consists of the pixel data
 * for a graphics image and its attributes.
 *
 */
#ifndef _FGRP_BITMAP_H_
#define _FGRP_BITMAP_H_


#include "FBaseObject.h"
#include "FBaseByteBuffer.h"
#include "FGrpConfig.h"
#include "FGrpPoint.h"
#include "FGrpColor.h"
#include "FGrpDimension.h"
#include "FGrpRectangle.h"
#include "FGrpBitmapCommon.h"
#include "FGrpBufferInfo.h"


namespace Osp { namespace Graphics { class Canvas; } }
namespace Osp { namespace Media { class Image; } }


namespace Osp {namespace Graphics {
/**
 * @class	Bitmap
 * @brief	This class encapsulates a bitmap.
 * @since	1.0
 *
 * The %Bitmap class encapsulates a bitmap, which consists of the pixel data
 * for an image and its attributes.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/bitmap.htm">Bitmaps</a>.
 *
 *
 */
class _EXPORT_GRP_ Bitmap :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the
     *              Construct() methods must be called explicitly to initialize this instance.
	 *
	 */
	Bitmap(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~Bitmap(void);

	/**
	 * Initializes this instance of Bitmap by copying a rectangular area of the screen.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	rect		The rectangular area of the screen to be copied into bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The area defined by @c rect is clipped to the edges of the screen so that 
	 *							the rectangle does not fall outside the edges of the screen. @n
	 *							The rectangle must not fall outside the edges of the screen entirely. @n
	 *							If these conditions are not satisfied, an E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
 	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Construct(const Rectangle& rect);

	/**
	 * Initializes this instance of Bitmap with the specified dimensions and pixel format.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	format		The pixel format
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
 	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Construct(const Dimension& dim, BitmapPixelFormat format);
	
	/**
	 * Initializes this instance of Bitmap by copying the specified rectangular area of the specified canvas.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	canvas		The canvas to copy @n
	 *							The canvas must be constructed successfully before it is passed into this method. @n
	 *							If not, an E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the canvas to be copied into a bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the canvas so that 
	 *							the rectangle does not fall outside the edges of the canvas. @n
	 *							The rectangle must not fall outside the edges of the canvas entirely. @n
	 *							If these conditions are not satisfied, an E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Construct(const Canvas& canvas, const Osp::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of Bitmap by copying a rectangular area of the specified bitmap.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	bitmap		The source bitmap @n
	 *							The bitmap must be constructed successfully before it is passed into this method. @n
	 *							If not, an E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the source bitmap to be copied into this bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the source bitmap so that 
	 *							the rectangle does not fall outside the edges of the source bitmap. @n
	 *							The rectangle must not fall outside the edges of the source bitmap entirely. @n
	 *							If these conditions are not satisfied, an E_OUT_OF_RANGE exception is returned. 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Construct(const Bitmap& bitmap, const Osp::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of Bitmap by using a buffer that contains raw data.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in] 	buffer		The buffer containing raw data
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	pixelFormat	The pixel format of raw data
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 *
  	 * @remarks The position property of %ByteBuffer can be changed.
	 * 
	 */
	result Construct(const Osp::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat);

	/**
	 * Initializes this instance of Bitmap by using a buffer that contains raw data.
	 *
	 * @since	1.1
	 *
	 * @return     An error code
	 * @param[in]  buffer          The buffer containing raw data
	 * @param[in]  dim             The dimensions of the bitmap @n
	 *                             The width and height must be greater than @c 0.
	 * @param[in]  pixelFormat     The pixel format of raw data
	 * @param[in]  bufferScaling   The buffer scaling type
	 * @exception  E_SUCCESS       The method is successful.
	 * @exception  E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception  E_UNSUPPORTED_FORMAT The specified format is not supported.
	 * @exception  E_OUT_OF_MEMORY The memory is insufficient.
	 *
 	 * @remarks The position property of %ByteBuffer can be changed.
	 * 
	 */
	result Construct(const Osp::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat, BufferScaling bufferScaling);

// Operation
public:
	/**
	 * Scales the bitmap to the specified width and height.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	dim	    The dimensions of the specified rectangular area @n
	 *						The width and height must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Scale(const Dimension& dim);
	
	/**
	 * Merges the specified area of the source bitmap into the calling bitmap at the given Point.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	destPoint		The X and Y coordinate of the top-left corner of the destination area in the calling bitmap instance
	 * @param[in]	srcBitmap		The source bitmap instance to copy from
	 * @param[in]	srcRect		    The rectangular area to copy from the source bitmap @n
								    The width and height of the rectangle must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The value of the argument is outside the valid range defined by the method. @n
	 *									- The destX, destY, srcX, or srcY has a negative value. @n
	 *									- The specified @c srcWidth or @c srcHeight is less than @c 0.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *
	 */
	result Merge(const Point& destPoint, const Bitmap& srcBitmap, const Rectangle& srcRect);

	/**
	 * Gets the height of the bitmap.
	 *
	 * @since		1.0
	 * @return	The height of the bitmap, @n
	 *			else @c -1 if the method fails
	 * 
	 */
	int GetHeight(void) const;

	/**
	 * Gets the width of the bitmap.
	 *
	 * @since		1.0
	 * @return	The width of the bitmap, @n
	 *			else @c -1 if the method fails
	 * 
	 */
	int GetWidth(void) const;

	/**
	 * Gets the number of bits per pixel of the bitmap.
	 *
	 * @since		1.0
	 * @return	The bits per pixel, @n
	 *			else @c -1 if the method fails
 	 * 
	 */
	int GetBitsPerPixel(void) const;
	
	/**
	 * Gets the pixel color format of the bitmap.
	 *
	 * @since		1.0
	 * @return	The pixel color format
	 * 
	 */
	BitmapPixelFormat GetPixelColorFormat(void) const;		

	/** 
	 * Sets the specified color as masking color. @n
	 * All pixels with this color are treated as transparent.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pColor	The color that is treated as transparent @n
	 *						If the parameter is set to @c null, the masking color is removed from this bitmap. @n
  	 *						Only BitmapPixelFormat::BITMAP_PIXEL_FORMAT_RGB565 is supported.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
	 */
	result SetMaskingColor(const Color* pColor);

	/** 
	 * Gets a masking color.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	color	The color that is treated as transparent
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_DATA	The masking color is not defined.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
	 */
	result GetMaskingColor(Color& color) const;

	/**
	 * Sets the alpha constant.
	 *
	 * @since			1.0
	 * @param[in]	opacity		The opacity of the bitmap @n
	 *				            This value ranges from @c 0 to @c 255.
	 * @remarks The alpha constant is used for the Canvas::DrawBitmap() method.
	 */
	void SetAlphaConstant(int opacity);
	
	/**
	 * Gets the alpha constant.
	 *
	 * @since		1.0
	 * @return	The alpha constant, @n
	 *			else @c -1 if the method fails
	 */
	int GetAlphaConstant(void) const;

	/**
	 * Checks whether the instance is nine patched bitmap.
	 *
	 * @since			1.0
	 * @return    @c true if the instance is nine patched bitmap, @n
	 *	          else @c false
	 */
	bool IsNinePatchedBitmap(void) const;
	
	/** 
	 * Locks a bitmap for direct pixel access. @n
	 * It sets up a bitmap for accessing the pixels directly. Between the calls to Bitmap::Lock and Bitmap::Unlock,
	 * you can write to and read from the bitmap's pixels. After you are done accessing the bitmap's pixels,
	 * you must call Bitmap::Unlock to release the lock.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	info		The extra information of the bitmap
	 * @param[in]	timeout		The time in milliseconds @n
	 *                          This value determines the time the caller waits for the lock to be obtained. @n
	 *							If the lock attempt fails, E_TIMEOUT is returned. @n
	 *							The default value is @c INFINITE, which means that the method does not return a value until the lock is acquired.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_TIMEOUT		The operation is not completed within the specified time period.
	 * @exception	E_SYSTEM 		An unknown operating system error has occurred. 
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
	 */	
	result Lock(BufferInfo& info, long timeout = INFINITE);

	/** 
	 * Unlocks a bitmap. @n
	 * A bitmap that is locked using Bitmap::Lock() must be unlocked using Bitmap::Unlock(). 
     * The bitmap buffer can be modified when the bitmap is locked, but is applied only when the bitmap is unlocked.
     * Therefore, all locked bitmap operations can only be used after the bitmap is unlocked using Bitmap::Unlock().
	 *
	 * @since			1.0
	 * @return		An error code	 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM 		An unknown operating system error has occurred. 
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 *
	 */
	result Unlock(void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Creates and returns a non scaled bitmap.
	 *
	 * @since	2.0
	 * @return	The non scaled bitmap @n
	 *          @c null, if an exception occurs
 	 * @param[in]	buffer		The buffer containing raw data
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	pixelFormat	The pixel format of raw data
 	 * @exception	E_SUCCESS            The method was successful.
	 * @exception	E_INVALID_ARG        The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT The specified format is not supported.
	 * @exception	E_OUT_OF_MEMORY      Insufficient memory.
	 *
 	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Bitmap* GetNonScaledBitmapN(const Osp::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat);

// Lifecycle
private:
	/*
	 * This is the copy constructor for the Bitmap class.
	 *
	 * @param[in]	src	The source from which this instance is copied
	 *
	 */
	Bitmap(const Bitmap& src);

	/*
	 * This is the assignment operator.
	 *
	 * @param[in]	value	The source from which this instance is assigned
	 *
	 */
	Bitmap& operator=(const Bitmap& value);

	/*
	 * Initializes this instance of Bitmap by using a buffer that contains raw data.
	 *
	 * @since	1.1
	 *
	 * @return     An error code
	 * @param[in]  buffer          The buffer containing raw bitmap data
	 * @param[in]  dim             The dimensions of the bitmap @n
	 *                             The width and height must be greater than @c 0.
	 * @param[in]  pixelFormat     The pixel format of the raw bitmap buffer
	 * @param[in]  autoScaling     Set to @c true to automatically scale the bitmap, @n
	 *									else @c false
	 * @exception  E_SUCCESS       The method is successful.
	 * @exception  E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception  E_UNSUPPORTED_FORMAT The specified format is not supported.
	 * @exception  E_OUT_OF_MEMORY The memory is insufficient.
	 * 
	 */
	result Construct(const Osp::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat, bool autoScaling);

	/*
	 * Initializes this instance of Bitmap by using a raw bitmap buffer data.
	 *
	 * @since	1.1
	 *
	 * @return     An error code
	 * @param[in]  pBuffer         A pointer to the raw bitmap buffer
	 * @param[in]  bufferSize      The size of the raw bitmap buffer
	 * @param[in]  dim             The dimensions of the bitmap @n
	 *                             The width and height must be greater than @c 0.
	 * @param[in]  pixelFormat     The pixel format of the raw bitmap buffer
	 * @param[in]  autoScaling     Set to @c true to automatically scale the bitmap, @n
	 *									else @c false
	 * @exception  E_SUCCESS       The method is successful.
	 * @exception  E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception  E_UNSUPPORTED_FORMAT The specified format is not supported
	 * @exception  E_OUT_OF_MEMORY The memory is insufficient.
	 * 
	 */
	result Construct(const byte* pBuffer, int bufferSize, const Dimension& dim, BitmapPixelFormat pixelFormat, bool autoScaling);

	friend class Canvas;
	friend class CanvasEx;
	friend class Osp::Media::Image;
	
protected:
	struct __Bitmap;

	/** 
	 *@internal This value is for internal use only. The bada platform team is not
	 *          responsible for any behavioral correctness, consistency, and
	 *          security-related issues that might arise after using this method.
	 *
	 * The value for internal usage.
	 *
	 * @since  1.0
	 */
	__Bitmap* __pImpl;

private:
	friend class BitmapEx;
	class BitmapEx* __pBitmapEx;

};

}; }; // Osp::Graphics

#endif //_FGRP_BITMAP_H_

