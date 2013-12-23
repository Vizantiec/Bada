/* $Change: 826527 $ */
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
 * @file	FUiCtrlMarginEnum.h 
 * @brief	This is the header file for the margin property of a control.
 *
 * This header file contains the declarations of the margin enumerations.
 */
#ifndef _FUICTRL_MARGINENUM_H_
#define _FUICTRL_MARGINENUM_H_

namespace Osp { namespace Ui { namespace Controls {

	/**
	 * @enum	MarginType
	 * Defines the different margin types for a control.
	 *
	 * @since	2.0
	 */
	enum MarginType {
		MARGIN_TYPE_LEFT,				/**< The left side of the margin */
		MARGIN_TYPE_RIGHT,				/**< The right side of the margin */
		MARGIN_TYPE_TOP,				/**< The top side of the margin */
		MARGIN_TYPE_BOTTOM				/**< The bottom side of the margin */
	};
	
}; }; }; // Osp::Ui::Controls

#endif