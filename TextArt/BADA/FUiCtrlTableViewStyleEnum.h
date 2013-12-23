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
 * @file		FUiCtrlTableViewStyleEnum.h
 * @brief		This is the header file for the table view style enumeration.
 *
 * This header file contains the declarations of the table view style.
 */
#ifndef _FUICTRL_TABLEVIEWSTYLEENUM_H_
#define _FUICTRL_TABLEVIEWSTYLEENUM_H_

namespace Osp { namespace Ui { namespace Controls {

	/**
	 * @enum	GroupStyle
	 * Defines the table view style of the border of a control.
	 *
	 * @since	1.0
	 */
	typedef enum
	{
		GROUP_STYLE_NONE,				/**< A rectangle with no outline */
		GROUP_STYLE_SINGLE,				/**< A rectangle with all corners rounded */
		GROUP_STYLE_TOP,				/**< A rectangle with the two top corners rounded */
		GROUP_STYLE_MIDDLE,				/**< A rectangle positioned at the center of a group */
		GROUP_STYLE_BOTTOM				/**< A rectangle with the two bottom corners rounded */
	} GroupStyle;

}; }; }; // Osp::Ui::Controls

#endif
