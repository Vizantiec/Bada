/* $Change: 1028567 $ */
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
 * @file		FGrpBufferInfo.h
 * @brief		This is the header file for the %BufferInfo class.
 *
 * This header file contains the declarations of the %BufferInfo class.
 *
 */
#ifndef _FGRP_BUFFER_INFO_H_
#define _FGRP_BUFFER_INFO_H_


#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FGrpConfig.h"
#include "FGrpRectangle.h"
#include "FGrpBitmapCommon.h"
#include "FGrpPixelFormat.h"


namespace Osp { namespace Media{ class Player; };};
namespace Osp { namespace Media{ class Camera; };};
namespace Osp { namespace Ui { namespace Controls { class OverlayPanel; };};};


namespace Osp {namespace Graphics {
/**
 * @class	BufferInfo
 * @brief	This class encapsulates the extra information for canvases and bitmaps.
 * @since	1.0
 *
 * The %BufferInfo class provides Canvas and Bitmap related information, such as the dimension and pixel information.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/bufferinfo.htm">Buffer Information</a>.
 * 
 *
 */
class _EXPORT_GRP_ BufferInfo :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	BufferInfo(void) 
		: width(0),
		  height(0),
		  pitch(0),
		  bitsPerPixel(0),
		  pixelFormat(PIXEL_FORMAT_MIN),
		  pPixels(null),
		  __handle(INVALID_HANDLE),
		  __pBufferInfoEx(0)
	{};	

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~BufferInfo(void) {};

	
// Attribute
public:
	/**
	 * The width of the buffer's logical dimensions in pixels.
	 *
	 * @since	1.0
	 */
	int width;

	/**
	 * The height of the buffer's logical dimensions in pixels.
	 *
	 * @since	1.0
	 */
	int height;

	/**
	 * The length of the buffer scan-line in bytes.
	 *
	 * @since	1.0
	 */
	int pitch;

	/**
	 * The bits per pixel of the buffer.
	 *
	 * @since	1.0
	 */
	int bitsPerPixel;

	/**
	 * The color format of the buffer.
	 *
	 * @since	1.0
	 */
	PixelFormat pixelFormat;

	/**
	 * A pointer to the actual locked pixel bits.
	 *
	 * @since	1.0
	 */
	void* pPixels;

private:	
	/*
	 * Gets the handle of the current instance of BufferInfo.
	 *
	 * @return		The runtime handle
	 */
	Handle GetHandle(void) const;

	Handle __handle;

private:
	friend class Osp::Media::Player;
	friend class Osp::Media::Camera;
	friend class Osp::Ui::Controls::OverlayPanel;

private:
	friend class BufferInfoEx;
	class BufferInfoEx* __pBufferInfoEx;
	
};

}; }; // Osp::Graphics

#endif //_FGRP_BUFFER_INFO_H_
