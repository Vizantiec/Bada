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
 * @file		FBaseUtilTypes.h
 * @brief		This is the header file for the various utilities.
 *
 * This header file contains the descriptions of the various utilities.
 */

#ifndef _FBASE_UTIL_TYPES_H_
#define _FBASE_UTIL_TYPES_H_

namespace Osp { namespace Base { namespace Utility {


/**
 *	@enum	CompressionLevel
 *	Defines the compression level.
 *
 *	@since 	1.1
 */
enum CompressionLevel{
	BEST_SPEED			= 	0,		/**< For best speed */
	BEST_COMPRESSION,				/**< For best compression */
	DEFAULT_COMPRESSION				/**< For average speed and average compression */
};


/**
 *	@enum LinkType
 * 	Defines the possible link types.
 *
 *	@since                  2.0
 */
enum LinkType
{
    LINK_TYPE_NONE      = 0x0000,	/**< The no link type */
    LINK_TYPE_URL       = 0x0001,	/**< The URL link type */
    LINK_TYPE_EMAIL     = 0x0002,	/**< The email link type */
    LINK_TYPE_TEL_NUM   = 0x0004,	/**< The telephone number link type */
    LINK_TYPE_APPCONTROL= 0x0008,	/**< The AppControl link type */
    LINK_TYPE_MIME      = 0x0010,	/**< The MIME link type */
    LINK_TYPE_MAX       = 0x7FFF	/*<  Not Used. The placeholder */
};


}}}
#endif /* _FBASE_UTIL_TYPES_H_ */
