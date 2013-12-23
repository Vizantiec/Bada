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
* @file		FUiCtrlLabelEnum.h
* @brief	This is the header file for the LabelTextStyle enumeration.
*
* This header file contains the declarations of the %LabelTextStyle enumeration.
*/
#ifndef _FUICTRL_LABELENUM_H_
#define _FUICTRL_LABELENUM_H_

namespace Osp { namespace Ui { namespace Controls {

  /**
   * @enum	LabelTextStyle
   * Defines the text styles of the label.
   *
   * @since		1.0
   */
  typedef enum
  {
      LABEL_TEXT_STYLE_NORMAL,		/**< The plain text style */
      LABEL_TEXT_STYLE_BOLD,		/**< The bold text style */
      LABEL_TEXT_STYLE_ITALIC,		/**< The italic text style */
  } LabelTextStyle;

}; }; }; // Osp::Ui::Controls

#endif