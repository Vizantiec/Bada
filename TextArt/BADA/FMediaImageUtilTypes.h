// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FMediaImageUtilTypes.h
 * @brief		This is the header file for the various types of ImageUtil.
 *
 * This header file contains the declarations of the various types of image filters.
 *
 */
#ifndef FMEDIA_IMAGEUTILTYPES_H_
#define FMEDIA_IMAGEUTILTYPES_H_

#include "FMediaTypes.h"

namespace Osp { namespace Media {

/**
 * @enum ImageRotationType
 * Defines the types of rotation.
 *
 * @since	2.0
 */
typedef enum {
	IMAGE_ROTATION_0 = 0x00,			/**< The no-rotation */
	IMAGE_ROTATION_90,					/**< 90 degree rotation in clockwise direction */
	IMAGE_ROTATION_180,					/**< 180 degree rotation in clockwise direction */
	IMAGE_ROTATION_270,					/**< 270 degree rotation in clockwise direction */
} ImageRotationType;

/**
 * @enum ImageFlipType
 * Defines the type of flip.
 *
 * @since	2.0
 */
typedef enum {
	IMAGE_FLIP_NONE  = 0x00,			/**< The no-flip type */
	IMAGE_FLIP_HORIZONTAL,				/**< The horizontal flip */
	IMAGE_FLIP_VERTICAL,				/**< The vertical flip */
} ImageFlipType;

}; };

#endif /* FMEDIA_IMAGEUTILTYPES_H_ */
