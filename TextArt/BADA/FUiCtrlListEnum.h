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
 * @file	FUiCtrlListEnum.h
 * @brief	This is the header file for the %List enumerations.
 *
 * This header file contains the declarations of the %List enumerations.
 */
#ifndef _FUICTRL_LISTENUM_H_
#define _FUICTRL_LISTENUM_H_

namespace Osp { namespace Ui { namespace Controls {

 /**
 * @internal
 * This value is for internal use only. The bada platform team is not
 * responsible for any behavioral correctness, consistency, and
 * security-related issues that might arise after using this value.
 *
 * Constant for the List Item Index.
 *
 * @since 1.0
 */
static const int LIST_ITEM_NOTFOUND = 0;

/**
 * The integer value that represents the unspecified item ID.
 *
 * @since 1.0
 */
static const int LIST_ITEM_UNSPECIFIED_ID = -1;

/**
 * @enum ListStyle
 *
 * Defines the list style.
 *
 * @deprecated  This enumeration is deprecated. Instead of using this enumeration, use the ListAnnexStyle enumeration for the CustomItem or SimpleItem class.
 *
 * @since 1.0
 *
 */
typedef enum
{
  LIST_STYLE_NORMAL = 0,							/**< The normal style */
  LIST_STYLE_NUMBER,								/**< The numbered style */
  LIST_STYLE_RADIO,									/**< The radio style for single selection */
  LIST_STYLE_RADIO_WITH_DIVIDER,					/**< The radio style with the divider for single selection */
  LIST_STYLE_MARK,									/**< The mark style for multiple selection */
  LIST_STYLE_MARK_WITH_DIVIDER,						/**< The mark style with the divider for multiple selection */
  LIST_STYLE_ONOFF,									/**< The On/Off style */
  LIST_STYLE_ONOFF_WITH_DIVIDER						/**< The On/Off style with the divider */
} ListStyle;

/**
 * @enum ListItemFormat
 * Defines the list item format.
 *
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration.
 *
 * @since 1.0
 *
 */
typedef enum
{
  LIST_ITEM_SINGLE_IMAGE = 0,						/**< The single line of image */
  LIST_ITEM_SINGLE_TEXT,							/**< The single line of text */
  LIST_ITEM_SINGLE_IMAGE_TEXT,						/**< The single line of image and text */
  LIST_ITEM_SINGLE_TEXT_IMAGE,						/**< The single line of text and image */
  LIST_ITEM_SINGLE_IMAGE_TEXT_IMAGE,			    /**< The single line of image, text and image */
  LIST_ITEM_DOUBLE_IMAGE_TEXT_FULLTEXT,		        /**< The first line of image and text, second line of text */
  LIST_ITEM_DOUBLE_FULLTEXT_IMAGE_TEXT,		        /**< The first line of text, second line of image, and text */
  LIST_ITEM_DOUBLE_TEXT_IMAGE_FULLTEXT,		        /**< The first line of text and image, second line of text */
  LIST_ITEM_DOUBLE_FULLTEXT_TEXT_IMAGE,		        /**< The first line of text, second line of text, and image */
  LIST_ITEM_DOUBLE_IMAGE_TEXT_TEXT,				    /**< A big image followed by two lines of text */
  LIST_ITEM_DOUBLE_TEXT_TEXT_IMAGE				    /**< The two lines of text followed by a big image */
} ListItemFormat;

/**
 * @enum ListItemText
 * Defines the option of text slide.
 *
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration.
 *
 * @since 1.0
 *
 */
typedef enum
{
  LIST_ITEM_TEXT1,									/**< The sliding of the first text is switched on */
  LIST_ITEM_TEXT2									/**< The sliding of the second text is switched on */
} ListItemText;

/**
 * @enum FastScrollIndexDigit
 * Defines the number of digits or characters of the fast scroll index.
 *
 * @deprecated This enumeration is deprecated. There is no need to use this enumeration.
 *
 * @since 1.0
 *
 */
typedef enum
{
  SCROLL_INDEX_DIGIT_NUM_1,							/**< The number of digits or characters of the index is 1 */
  SCROLL_INDEX_DIGIT_NUM_2							/**< The number of digits or characters of the index is 2 */
} FastScrollIndexDigit;

}; }; }; // Osp::Ui::Controls

#endif
