// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FUiCtrlGalleryEnum.h
 * @brief		This is the header file for the %Gallery enumerations.
 *
 * This header file contains the declarations of the %Gallery enumerations.
 *
 * These enumerations define the various properties of a %Gallery control.
 */
#ifndef _FUICTRL_GALLERY_ENUM_H_
#define _FUICTRL_GALLERY_ENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum GalleryImageRotation
 *
 * Defines the rotation of an image of a %Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryImageRotation {
	GALLERY_IMAGE_ROTATION_0 = 0,				/**< The no rotation */
	GALLERY_IMAGE_ROTATION_90,					/**< The 90 degree clockwise rotation */
	GALLERY_IMAGE_ROTATION_180,					/**< The clockwise rotation */
	GALLERY_IMAGE_ROTATION_270					/**< The anticlockwise rotation */
};

/**
 * @enum GalleryAnimation
 *
 * Defines the animation type of a %Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryAnimation {
	GALLERY_ANIMATION_PAGE,							/**< The page turn animation */
	GALLERY_ANIMATION_DISSOLVE,						/**< The dissolve animation */
	GALLERY_ANIMATION_ZOOM							/**< The zoom animation */
};

/**
 * @enum  GalleryRefreshType
 *
 * Defines the update type of a %Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryRefreshType
{
	GALLERY_REFRESH_TYPE_ITEM_ADD = 0,				/**< The refresh type is add */
	GALLERY_REFRESH_TYPE_ITEM_REMOVE,				/**< The refresh type is remove */
	GALLERY_REFRESH_TYPE_ITEM_MODIFY				/**< The refresh type is modify */
};

}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_GALLERY_ENUM_H_
