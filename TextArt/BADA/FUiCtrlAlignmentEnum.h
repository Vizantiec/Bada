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
 * @file		FUiCtrlAlignmentEnum.h 
 * @brief		This is the header file for the control alignment property.
 *
 * This header file contains the declarations of the alignment enumeration.
 */
#ifndef _FUICTRL_ALIGNMENTENUM_H_
#define _FUICTRL_ALIGNMENTENUM_H_

namespace Osp { namespace Ui { namespace Controls {

	/**
	 * @enum HorizontalAlignment
	 * Defines the horizontal alignment of the text.
	 *
	 * @since		1.0
	 */
	typedef enum
	{
		ALIGNMENT_LEFT,				/**< The text is left-aligned */
		ALIGNMENT_CENTER,			/**< The text is center-aligned horizontally */
		ALIGNMENT_RIGHT				/**< The text is right-aligned */
	} HorizontalAlignment;

	/**
	* @enum VerticalAlignment
	* Defines the vertical alignment of the text.
	*
	* @since		1.0
	*/
	typedef enum
	{
		ALIGNMENT_TOP,				/**< The text is top-aligned */
		ALIGNMENT_MIDDLE,			/**< The text is center-aligned vertically */
		ALIGNMENT_BOTTOM			/**< The text is bottom-aligned */
	} VerticalAlignment;

}; }; }; // Osp::Ui::Controls

#endif
