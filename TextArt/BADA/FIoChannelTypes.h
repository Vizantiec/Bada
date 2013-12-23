/* $Change: 871992 $ */
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
 * @file		FIoChannelTypes.h
 * @brief		This is the header file for the %ChannelType class.
 *
 * This header file contains the enumerator declarations of the %ChannelType class.
 */
#ifndef _FIO_CHANNEL_TYPES_H_
#define _FIO_CHANNEL_TYPES_H_

namespace Osp { namespace Io {

/**
 * @enum ChannelType
 * @since    2.0
 * 
 * Defines the type of the channel.
 */
typedef enum
{
	CHANNEL_TYPE_CLIENT = 0, /**< The client channel */
	CHANNEL_TYPE_SERVER      /**< The server channel */
}ChannelType;

};// Osp::Io
};// Osp
#endif//_FIO_DB_TABLE_H_

