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
* @file			FMediaImageCommon.h
* @brief		This is the header file for the common types of Image class.
*
* This header file contains declarations of the enumerations for the Image class.
*/
#ifndef _FMEDIA_IMAGEUTIL_COMMON_H_
#define _FMEDIA_IMAGEUTIL_COMMON_H_

namespace Osp{ namespace Media{ 
 
	/**
	* 	@enum	ImageFormat
	*	Defines the image formats.
	*
	* @since	1.0
	*/
	enum ImageFormat
	{
		IMG_FORMAT_NONE = -1,	/**< No image format type */
		IMG_FORMAT_JPG = 0,		/**< The JPEG image format type*/
		IMG_FORMAT_PNG,			/**< The PNG image format type*/
		IMG_FORMAT_GIF,			/**< The GIF image format type*/
		IMG_FORMAT_BMP,			/**< The BMP image format type*/
		IMG_FORMAT_TIFF,		/**< The TIFF image format type*/
		IMG_FORMAT_WBMP,		/**< The WBMP image format type*/

	};

};}; // Osp::Media


#endif





