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
 * @file		FCntConstants.h 
 * @brief		This header file contains the definitions for the constants and enumerators in the Content namespace.
 *
 * This header file contains the definitions for the constants and enumerators in the %Content namespace.
 */

#ifndef _FCNT_CONSTANTS_H_
#define _FCNT_CONSTANTS_H_

#include <FBase.h>
#include <FCntConfig.h>

namespace Osp { namespace Content {

/**
 * Content service ID
 *
 * @since	1.0
 */
typedef Osp::Base::String	ContentServiceID;

/**
 * Content Id
 *
 * @since	1.0
 */
typedef Osp::Base::UuId		ContentId;

#define MAX_CONTENT_DEFAULT		256
#define MAX_CONTENT_INSERT_QUERY	4096
#define MAX_CONTENT_UPDATE_QUERY	2048
#define MAX_CONTENT_SELECT_QUERY	1024
#define MAX_CONTENT_DELETE_QUERY	512
#define MAX_CONTENT_URL_LENGTH	2048
#define REMOTE_COUNT_PER_PAGE	10
#define MAX_CONTENT_NUMBER_FORMAT	12
#define MAX_CONTENT_DOWNLOAD_NUMBER	3

/**
 * @enum ContentType
 * Defines the content type.
 *
 * @since	1.0
 */
typedef enum {
	CONTENT_TYPE_OTHER = 0,			/**< The content type: other types */
	CONTENT_TYPE_IMAGE, 			/**< The content type: image */
	CONTENT_TYPE_AUDIO, 			/**< The content type: audio */
	CONTENT_TYPE_VIDEO, 			/**< The content type: video */
	CONTENT_TYPE_ALL,				/**< The content type: all types */ /**< @deprecated This enumeration field is deprecated as unified search will not be supported. */
	CONTENT_TYPE_UNKNOWN			/**< The content type: unknown types */
	//CONTENT_TYPE_RINGTONE, 		/**< A Ringtone (currently not supported) */
	//CONTENT_TYPE_WALLPAPER,		/**< The Wallpaper (currently not supported) */
	//CONTENT_TYPE_GAME,			/**< A Game (currently not supported) */
	//CONTENT_TYPE_APP				/**< An App (currently not supported) */	
} ContentType;

/**
 * @enum RemoteContentStatus
 * Defines the remote content status.
 * @deprecated	This enum is deprecated due to the operation policy of the bada Server.
 * @since	1.0
 */
typedef enum {
	CONTENT_STATUS_UNKNOWN = 0,	/**< The remote content status: unknown status */
	CONTENT_STATUS_DRAFT,		/**< The remote content status: draft status */
	CONTENT_STATUS_PUBLISH,		/**< The remote content status: publish status */
	CONTENT_STATUS_ARCHIVE,		/**< The remote content status: archive status */
	CONTENT_STATUS_DESTROY		/**< The remote content status: destroy status */
} RemoteContentStatus;


}; }; // Osp::Content

#endif// _FCNT_CONSTANTS_H_

