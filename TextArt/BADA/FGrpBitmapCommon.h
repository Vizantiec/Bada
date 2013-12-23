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
 * @file		FGrpBitmapCommon.h 
 * @brief		This is the header file for the %Bitmap class.
 *
 * This header file contains the definitions of the enumerations of the %Bitmap class.
 */ 
#ifndef _FGRP_BITMAP_COMMON_H_
#define _FGRP_BITMAP_COMMON_H_


#include "FGrpConfig.h"


namespace Osp{ namespace Graphics{
/**
 * @enum	BitmapPixelFormat
 *
 * Defines the bitmap pixel format.
 *
 * @since	1.0
 */
enum BitmapPixelFormat
{
	BITMAP_PIXEL_FORMAT_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	BITMAP_PIXEL_FORMAT_RGB565, /**< The RGB565 pixel format */
	BITMAP_PIXEL_FORMAT_ARGB8888, /**< The ARGB8888 pixel format */
	BITMAP_PIXEL_FORMAT_R8G8B8A8, /**< The R8G8B8A8 pixel format, the order of the color component is guaranteed by the byte unit */
	BITMAP_PIXEL_FORMAT_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};


/**
 * @enum	BufferScaling
 *
 * Defines the bitmap buffer scaling type.
 *
 * @since	1.1
 *
 */
enum BufferScaling
{
	BUFFER_SCALING_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	BUFFER_SCALING_NONE, /**< The bitmap buffer is created without scaling */
	BUFFER_SCALING_AUTO, /**< The bitmap buffer is created according to the auto scaling rule */
	BUFFER_SCALING_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};


};};
	
#endif





