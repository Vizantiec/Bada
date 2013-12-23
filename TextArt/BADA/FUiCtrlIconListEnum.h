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
 * @file		FUiCtrlIconListEnum.h
 * @brief		This is the header file for the IconList enumerations.
 *
 * This header file contains the declarations of the %IconList enumerations.
 *
 * These enumerations define the various properties of the %IconList control.
 */
#ifndef _FUICTRL_ICON_LISTENUM_H_
#define _FUICTRL_ICON_LISTENUM_H_

namespace Osp { namespace Ui { namespace Controls {

  /**
   * @enum 	IconListStyle
   *
   * Defines the styles of %IconList.
   *
   * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the IconListViewStyle enumeration.
   *
   * @since		1.0
   *
   */
  typedef enum
  {
      ICON_LIST_STYLE_NORMAL = 0,				        /**< The No mark or radio check */
      ICON_LIST_STYLE_RADIO,						    /**< The radio style for single selection */
      ICON_LIST_STYLE_MARK,							    /**< The mark style for multiple selection */
  } IconListStyle;

  /**
   * @enum IconListCheckBoxPosition
   *
   * Defines the check-box position.
   *
   * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the IconListViewCheckBoxPosition enumeration.
   *
   * @since	1.0
   *
   */
  typedef enum
  {
      ICON_LIST_CHECK_BOX_POSITION_TOP_LEFT,			/**< The position of checkbox is top-left */
      ICON_LIST_CHECK_BOX_POSITION_TOP_RIGHT,			/**< The position of checkbox is top-right */
      ICON_LIST_CHECK_BOX_POSITION_BOTTOM_LEFT,		    /**< The position of checkbox is bottom-left */
      ICON_LIST_CHECK_BOX_POSITION_BOTTOM_RIGHT			/**< The position of checkbox is bottom-right */
  } IconListCheckBoxPosition;
}; }; }; // Osp::Ui::Controls

#endif
