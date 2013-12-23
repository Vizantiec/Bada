/* $Change: 1241928 $ */
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
* @file			FMediaDrmConstants.h 
* @brief		This is the header file for the DRM constants.
*
* This header file contains the declarations of the DRM constants.
*/
#ifndef _FMEDIA_DRM_CONSTANTS_H_
#define _FMEDIA_DRM_CONSTANTS_H_

// includes
#include <FBase.h>

namespace Osp { namespace Media {

/**
* @enum DrmType
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* Defines the type of the DRM.
*
* @since 1.0
*/
enum DrmType
{
	DRM_UNDEFINED = 0,    /**< The DRM type: Undefined type*/
  DRM_OMA_V1,             /**< The DRM type: OMA DRM v1*/
  DRM_OMA_V2,             /**< The DRM type: OMA DRM v2*/
  DRM_OMA_PDCF,           /**< The DRM type: OMA DRM v2.1*/
  DRM_WMDRM,              /**< The DRM type: WMDRM*/
  DRM_PLAYREADY,          /**< The DRM type: PlayReady DRM @b since: @b 2.0 */

};

/**
* @enum DrmMethodType
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* Defines the DRM method type.
*
* @since 1.0
*/
enum DrmMethodType
{
	DRM_METHOD_TYPE_UNDEFINED = -1,		/**< The undefined method type*/
	DRM_METHOD_TYPE_FORWARD_LOCK,		/**< The forward lock method type*/
	DRM_METHOD_TYPE_COMBINED_DELIVERY,	/**< The combined delivery method type*/
	DRM_METHOD_TYPE_SUPER_DISTRIBUTION,	/**< The super distribution method type*/
	DRM_METHOD_TYPE_SEPARATE_DELIVERY	/**< The separate delivery method type*/
};

/**
* @enum DrmConstraintType
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* Defines the basic constraint types such as unlimited, count, datetime, and interval. @n
* The timed count, accumulated, individual, and system types are added from OMA DRM v2.0. @n
* Timed Count: count-1 is consumed after time-t from the rendering start. @n
* Accumulated: the user can use the content for an accumulated time. @n
* Individual: only users who have SIM cards with the specified WIM values can use the content. @n
* System: only users who have devices with the specified device values can use the content.
*
* @since 1.0
*/
enum DrmConstraintType
{
	DRM_CONSTRAINT_UNLIMITED	= 0,		/**< The unlimited constraints */
	DRM_CONSTRAINT_COUNT		= 1,		/**< The count constraint */
	DRM_CONSTRAINT_DATETIME		= 2,		/**< The datetime constraint */
	DRM_CONSTRAINT_INTERVAL		= 4,		/**< The interval constraint */
	DRM_CONSTRAINT_TIMED_COUNT	= 8,		/**< The timed-count constraint */
	DRM_CONSTRAINT_ACCUMULATED	= 16,		/**< The accumulated constraint */
	DRM_CONSTRAINT_INDIVIDUAL	= 32,		/**< The individual constraint */
	DRM_CONSTRAINT_SYSTEM		= 64,		/**< The system constraint */
	DRM_CONSTRAINT_COUNT_DATETIME = 128		/**< The count-datetime constraint (For WMDRM) */
};

/**
* @enum DrmPermissionType
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* Defines the DRM permission type.
*
* @since 1.0
*/
enum DrmPermissionType
{
	DRM_PERMISSION_TYPE_ANY			= 0x00400000,		/**< The DRM Permission type: Any  */
	DRM_PERMISSION_TYPE_PLAY		= 0x00010000,		/**< The play permission */
	DRM_PERMISSION_TYPE_DISPLAY		= 0x00020000,		/**< The display permission */
	DRM_PERMISSION_TYPE_EXECUTE		= 0x00040000,		/**< The execute permission */
	DRM_PERMISSION_TYPE_PRINT		= 0x00080000,		/**< The print permission */
	DRM_PERMISSION_TYPE_EXPORT_COPY	= 0x00100000,		/**< The export copy permission */
	DRM_PERMISSION_TYPE_EXPORT_MOVE	= 0x00200000,		/**< The export move permission */
	DRM_PERMISSION_TYPE_COLLABORATE_PLAY = -1,			/**< The collaborate play permission (For WMDRM) */  
	DRM_PERMISSION_TYPE_COPY_CD		= -2				/**< The copy to CD permission (For WMDRM) */
};

/**
* @enum DrmRightStatus
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* Defines the status of the right object.
*
* @since 1.0
*/
enum DrmRightStatus
{
	DRM_RIGHT_VALID,				/**< The valid right object */
	DRM_RIGHT_FUTUREUSE,			/**< The future right object */
	DRM_RIGHT_EXPIRED,				/**< The expired right object */
	DRM_RIGHT_PENDING,				/**< No secure clock */
	DRM_RIGHT_NORIGHTS,				/**< No right object */
	DRM_RIGHT_FORCE_SYNC			/**< Need a license (For WMDRM) */
};

#define DRM_RIHGT_PENDING DRM_RIGHT_PENDING

};};// Osp::Media

#endif // _FMEDIA_DRM_CONSTANTS_H_
