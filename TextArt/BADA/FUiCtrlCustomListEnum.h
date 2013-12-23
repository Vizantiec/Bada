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
 * @file		FUiCtrlCustomListEnum.h
 * @brief		This is the header file for the CustomListStyle enumeration.
 *
 * The CustomListStyle enumeration defines the styles for the CustomList control.
 */
#ifndef _FUICTRL_CUSTOM_LISTENUM_H_
#define _FUICTRL_CUSTOM_LISTENUM_H_

namespace Osp { namespace Ui { namespace Controls {

  /**
   * @enum CustomListStyle
   *
   * Defines the styles of %CustomList.
   *
   * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the ListAnnexStyle enumeration for the CustomItem or SimpleItem class.
   *
   * @since		1.0
   *
   */
  typedef enum
  {
     CUSTOM_LIST_STYLE_NORMAL = 0,					/**< The No mark, radio, or On/Off check */
     CUSTOM_LIST_STYLE_RADIO,						/**< The radio style for single selection */
     CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER,			/**< The radio style with divider for single selection */
     CUSTOM_LIST_STYLE_MARK,						/**< The mark style for multiple selection */
     CUSTOM_LIST_STYLE_MARK_WITH_DIVIDER,			/**< The mark style with divider for multiple selection */
     CUSTOM_LIST_STYLE_ONOFF,						/**< The On/Off style */
     CUSTOM_LIST_STYLE_ONOFF_WITH_DIVIDER			/**< The On/Off style with divider */
  } CustomListStyle;

}; }; }; // Osp::Ui::Controls

#endif
