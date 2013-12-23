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
 * @file		FGrpPixelFormat.h
 * @brief		This is the header file for the PixelFormat enumeration that defines the pixel information.
 *
 * This header file contains the definitions of the PixelFormat enumeration that defines the pixel information.
 */ 
#ifndef _FGRP_PIXEL_FORMAT_H_
#define _FGRP_PIXEL_FORMAT_H_


#include "FGrpConfig.h"


namespace Osp{ namespace Graphics{	
/**
 * @enum	PixelFormat
 *
 * Defines the bits per pixel and the bits per component.
 *
 * @since	1.0
 */
enum PixelFormat 
{
	PIXEL_FORMAT_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	PIXEL_FORMAT_RGB565, /**< The RGB565 pixel format */
	PIXEL_FORMAT_ARGB8888, /**<The ARGB8888 pixel format */
	PIXEL_FORMAT_R8G8B8A8, /**<The R8G8B8A8 pixel format @n 
	                            The order of color component is guaranteed by the byte unit. */
    PIXEL_FORMAT_YCbCr420_PLANAR, /**<The 8-bit Y-plane followed by 8-bit 2x2 sub sampled U-plane and V-plane */
	PIXEL_FORMAT_JPEG, /**<The encoded formats */
	PIXEL_FORMAT_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};

};};
	
#endif
