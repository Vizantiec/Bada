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
 * @file			FMediaCameraCommon.h 
 * @brief			This is the header file for the Camera enumerations.
 *
 * This header file contains the enumeration declaration for Camera. 
 */
 
#ifndef _FMEDIA_CAMERA_COMMON_H_
#define _FMEDIA_CAMERA_COMMON_H_

namespace Osp{ namespace Media{ 

#define MAX_CAMERA_STRING_LENGTH 200

#define MIN_CAMERA_BRIGHTNESS 0
#define MAX_CAMERA_BRIGHTNESS 9
#define DEFAULT_CAMERA_BRIGHTNESS 5

#define MIN_CAMERA_CONTRAST 0
#define MAX_CAMERA_CONTRAST 9
#define DEFAULT_CAMERA_CONTRAST 5

#define MIN_CAMERA_EXPOSURE 0
#define MAX_CAMERA_EXPOSURE 9
#define DEFAULT_CAMERA_EXPOSURE 5

#define DEFAULT_CAMERA_PREVIEW_FPS 15

/**
 * @enum CameraSelection
 * Defines a functional camera.
 *
 * @since 1.0
 * @see		Camera::PowerOn()
 */
typedef enum
{
	CAMERA_PRIMARY,          /**< The primary camera */
	CAMERA_SECONDARY,       /**< The secondary camera */
}CameraSelection;

/**
 * @enum CameraState
 * Defines the state of the camera.
 *
 * @since 1.0
 * @see		Camera::GetState()
 */
typedef enum
{
	CAMERA_STATE_INITIALIZED,		/**< The camera in the initialized state */        
	CAMERA_STATE_PREVIEW,			/**< The camera in the preview state */
	CAMERA_STATE_AUTO_FOCUSING,		/**< The camera state while auto-focusing */	
	CAMERA_STATE_CAPTURING,			/**< The camera state while capturing */
	CAMERA_STATE_CAPTURED,			/**< The camera state after capturing */
	CAMERA_STATE_ERROR				/**< The camera in an error state */
}CameraState;

/**
 * @enum CameraWhiteBalance
 * Defines the white balance levels of the camera.
 *
 * @since 1.0
 * @see		Camera::SetWhiteBalance(), Camera::GetWhiteBalance()
 */
typedef enum
{
	CAMERA_WHITE_BALANCE_AUTO,					/**< The camera's white balance level: Auto */
	CAMERA_WHITE_BALANCE_SUNNY,					/**< The camera's white balance level: Sunny */
	CAMERA_WHITE_BALANCE_CLOUDY,				/**< The camera's white balance level: Cloudy */
	CAMERA_WHITE_BALANCE_FLUORESCENT,			/**< The camera's white balance level: Fluorescent */
	CAMERA_WHITE_BALANCE_TUNGSTEN,				/**< The camera's white balance level: Tungsten */
}CameraWhiteBalance;

/**
 * @enum CameraEffect
 * Defines the effects of the camera.
 *
 * @since 1.0
 * @see		Camera::SetEffect(), Camera::GetEffect()
 */
typedef enum
{
	CAMERA_EFFECT_NONE,					/**< The camera's effect: None */
	CAMERA_EFFECT_COLOR,				/**< The camera's effect: Color */
	CAMERA_EFFECT_BW,					/**< The camera's effect: Black and White */
	CAMERA_EFFECT_SEPIA,				/**< The camera's effect: Sepia */
	CAMERA_EFFECT_SOLARIZE,				/**< The camera's effect: Solarize */
	CAMERA_EFFECT_NEGATIVE,				/**< The camera's effect: Negative */
	CAMERA_EFFECT_NIGHT,				/**< The camera's effect: Night */
} CameraEffect;

/**
 * @enum CameraIsoLevel
 * Defines the ISO levels of the camera.
 *
 * @since 1.0
 * @see		Camera::SetIsoLevel(), Camera::GetIsoLevel()
 */
typedef enum{
	CAMERA_ISO_DEFAULT,					/**< The device dependent default ISO level */
	CAMERA_ISO_MIN,						/**< The minimum supported ISO level */
	CAMERA_ISO_AUTO,					/**< The auto ISO level */
	CAMERA_ISO_50,						/**< The ISO 50 level */
	CAMERA_ISO_100,						/**< The ISO 100 level */
	CAMERA_ISO_200,						/**< The ISO 200 level */
	CAMERA_ISO_400,						/**< The ISO 400 level */
	CAMERA_ISO_800,						/**< The ISO 800 level */
	CAMERA_ISO_1600,					/**< The ISO 1600 level */
	CAMERA_ISO_MAX						/**< The maximum supported ISO level */
}CameraIsoLevel;

/**
 * @enum CameraQuality
 * Defines the capturing quality of the camera.
 *
 * @since 1.0
 * @remarks The capturing quality of the camera cannot be set to CAMERA_QUALITY_MAX.
 * @see		Camera::GetQuality(), Camera::SetQuality()
 */
typedef enum
{
	CAMERA_QUALITY_NORMAL,				/**< The camera's capturing quality: Normal */
	CAMERA_QUALITY_FINE,				/**< The camera's capturing quality: Fine */
	CAMERA_QUALITY_SUPER_FINE,			/**< The camera's capturing quality: Super Fine */
	CAMERA_QUALITY_MAX,					/**< The camera's capturing quality: Max boundary */
}CameraQuality;

/**
 * @enum CameraErrorReason
 * Defines the reason for the camera error.
 *
 * @since 1.0
 */
typedef enum
{
	CAMERA_ERROR_NONE,			        /*< The undefined error */
	CAMERA_ERROR_OUT_OF_MEMORY,		    /**< The insufficient memory error */
	CAMERA_ERROR_DEVICE_FAILED,			/**< The camera device failed error */
	CAMERA_ERROR_DEVICE_INTERRUPTED,	/**< The camera device interrupted error @b since: @b 2.0 */
}CameraErrorReason;


/**
 * @enum CameraDirection
 * Defines the physical direction of the camera.
 *
 * @since 1.1
 */
typedef enum
{
	CAMERA_DIRECTION_FRONT=0x01,	/**< The camera's direction: Front */
	CAMERA_DIRECTION_BACK,			/**< The camera's direction: Backward */
} CameraDirection;

/**
 * @enum CameraRotation
 * Defines the physical rotation of the camera in degrees clockwise.
 *
 * @since 1.1
 */
typedef enum
{
	CAMERA_ROTATION_NONE = 0x01,	/**< The camera's rotation: None */
	CAMERA_ROTATION_90,			/**< The camera's rotation: 90 degree rotation */
	CAMERA_ROTATION_180,			/**< The camera's rotation: 180 degree rotation @b since: @b 2.0 */	
	CAMERA_ROTATION_270,			/**< The camera's rotation: 270 degree rotation @b since: @b 2.0 */		
} CameraRotation;

/**
 * @enum CameraZoomType
 * Defines the zoom types of the camera.
 *
 * @since 1.1
 */
typedef enum
{
	CAMERA_ZOOM_TYPE_DIGITAL = 0x01,	/**< The camera's zoom type: Digital */
	CAMERA_ZOOM_TYPE_SMART,				/**< The camera's zoom type: Smart */
} CameraZoomType;

/**
 * @enum CameraExifOrientation
 * Defines the camera's EXIF orientation flags.
 *
 * @since 1.2
 */
typedef enum
{
	CAMERA_EXIF_ORIENTATION_TOP_LEFT = 0x01,	/**< The row #0 is top, column #0 is left */
	CAMERA_EXIF_ORIENTATION_TOP_RIGHT,		/**< The row #0 is top, column #0 is right */
	CAMERA_EXIF_ORIENTATION_BOTTOM_RIGHT,	/**< The row #0 is bottom, column #0 is right */
	CAMERA_EXIF_ORIENTATION_BOTTOM_LEFT,	/**< The row #0 is bottom, column #0 is left */
	CAMERA_EXIF_ORIENTATION_LEFT_TOP,		/**< The row #0 is left, column #0 is top */
	CAMERA_EXIF_ORIENTATION_RIGHT_TOP,		/**< The row #0 is right, column #0 is top */
	CAMERA_EXIF_ORIENTATION_RIGHT_BOTTOM,	/**< The row #0 is right, column #0 is bottom */
	CAMERA_EXIF_ORIENTATION_LEFT_BOTTOM,	/**< The row #0 is left, column #0 is bottom */
} CameraExifOrientation;

/**
 * @enum CameraFlipType
 * Defines the camera's flip types.
 *
 * @since 2.0
 */
typedef enum
{
	CAMERA_FLIP_NONE,				/**< The Camera's flip - None*/
	CAMERA_FLIP_HORIZONTAL,		/**< The Camera's flip - Horizontal*/
	CAMERA_FLIP_VERTICAL,			/**< The Camera's flip - Vertical*/
} CameraFlipType;

};}; // Osp::Media


#endif





