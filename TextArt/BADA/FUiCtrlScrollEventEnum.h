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
 * @file	FUiCtrlScrollEventEnum.h
 * @brief	This is the header file for the scroll event enumerations.
 * @since	2.0
 *
 * This header file contains the declarations of the scroll event enumerations.
 */
#ifndef _FUICTRL_SCROLL_EVENT_ENUM_H_
#define _FUICTRL_SCROLL_EVENT_ENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum	ScrollEndEvent
 * Defines the constants that represent the type of the scroll end event.
 *
 * @since	2.0
 */
 enum ScrollEndEvent
 {
     SCROLL_END_EVENT_END_TOP = 0,		/**< The scroll reaches top end */
     SCROLL_END_EVENT_END_BOTTOM,		/**< The scroll reaches bottom end */
     SCROLL_END_EVENT_END_LEFT,			/**< The scroll reaches left end */
     SCROLL_END_EVENT_END_RIGHT			/**< The scroll reaches right end */
 };

}; }; }; // Osp::Ui::Controls

#endif
