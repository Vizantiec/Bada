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
 * @file		FContent.h 
 * @brief		This is the header file for the %Content namespace.
 *
 * This header file contains the declarations and descriptions of the %Content namespace.
 */

#ifndef _FCNT_H_
#define _FCNT_H_

#include "FCntAudioContentInfo.h"
#include "FCntImageContentInfo.h"
#include "FCntVideoContentInfo.h"
#include "FCntOtherContentInfo.h"
#include "FCntContentManager.h"
#include "FCntContentManagerUtil.h"
#include "FCntRemoteContentManager.h"
#include "FCntContentSearch.h"
#include "FCntContentSearchResult.h"
#include "FCntRemoteCategory.h"
#include "FCntRemoteContentSearch.h"
#include "FCntRemoteContentSharing.h"
#include "FCntContentTransfer.h"

namespace Osp { 

/**
 * @namespace	Osp::Content
 * @brief		This namespace contains classes and interfaces for content management and search services.
 * @since		1.0
 *
 * @remarks    @b Header @b %file: @b \#include @b <FContent.h> @n
 *			   @b Library : @b FOsp
 *
 *
 * The %Content namespace contains classes for managing the most common media data types, such as image, audio, and video on the device. This namespace also provides operations to search content and content information stored on the device, and to download content from servers through HTTP access.
 *
 * For more information on the %Content namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/content_namespace.htm">Content Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Content namespace.
 * @image html content_using_the_apis_classdiagram.png
 */
namespace Content
{
}; }; // Osp::Content

#endif// _FCNT_H_

