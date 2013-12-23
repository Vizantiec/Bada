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
 * @file	FUiClipboardEnum.h
 * @brief	This is the header file for the Clipboard enumeration.
 *
 * The Clipboard enumeration defines the data types for the system clipboard.
 */
#ifndef _FUI_CLIPBOARD_ENUM_H_
#define _FUI_CLIPBOARD_ENUM_H_

namespace Osp { namespace Ui { class ClipboardItemEx; }}
namespace Osp { namespace Ui {
/**
 * @enum	ClipboardDataType
 *
 * Defines the data types supported by Clipboard.
 *
 * @since	2.0
 */
enum ClipboardDataType
{
	CLIPBOARD_DATA_TYPE_NONE  = 0x0000,/**< @internal No data type */
	CLIPBOARD_DATA_TYPE_TEXT  = 0x0001,/**< The text data type */
	CLIPBOARD_DATA_TYPE_HTML  = 0x0002,/**< The HTML data type */
	CLIPBOARD_DATA_TYPE_IMAGE = 0x0004,/**< The image data type */
	CLIPBOARD_DATA_TYPE_VIDEO = 0x0008,/**< The video data type */
	CLIPBOARD_DATA_TYPE_AUDIO = 0x0010,/**< The audio data type */
	CLIPBOARD_DATA_TYPE_MAX   = 0x7fff /**< @internal The data type max */
};
}; }; // Osp::Ui
#endif   // _FUI_CLIPBOARD_ENUM_H_
