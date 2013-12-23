// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FUiCtrlIconListViewEnum.h
 * @brief		This is the header file for the %IconListView enumerations.
 *
 * This header file contains the declarations of the %IconListView enumerations.
 *
 * These enumerations define the various properties of the %IconListView control.
 */
#ifndef _FUICTRL_ICONLISTVIEW_ENUM_H_
#define _FUICTRL_ICONLISTVIEW_ENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum IconListViewStyle
 *
 * Defines the styles of the %IconListView control.
 *
 * @since 2.0
 */
enum IconListViewStyle {
	ICON_LIST_VIEW_STYLE_NORMAL = 0,					/**< The No mark or radio check */
	ICON_LIST_VIEW_STYLE_RADIO,							/**< The radio style for a single selection */
	ICON_LIST_VIEW_STYLE_MARK							/**< The mark style for multiple selections */
};

/**
 * @enum IconListViewItemBorderStyle
 *
 * Defines the constants used to identify the border style of the item.
 *
 * @since 2.0
 */
enum IconListViewItemBorderStyle {
    ICON_LIST_VIEW_ITEM_BORDER_STYLE_NONE = 0,    /**< The item that has no border */
    ICON_LIST_VIEW_ITEM_BORDER_STYLE_OUTLINE,     /**< The item that has a line border */
    ICON_LIST_VIEW_ITEM_BORDER_STYLE_SHADOW       /**< The item that has a bitmap border with the drop shadow effect */
};

/**
 * @enum IconListViewScrollDirection
 * Defines the scroll direction of the %IconListView control.
 *
 * @since 2.0
 */
enum IconListViewScrollDirection {
	ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL,			/**< The vertical direction */
	ICON_LIST_VIEW_SCROLL_DIRECTION_HORIZONTAL			/**< The horizontal direction */
};

/**
 * @enum IconListViewItemTextVerticalAlignment
 * Defines the vertical alignment of the item text.
 * 
 * @since 2.0
 */
enum IconListViewItemTextVerticalAlignment {
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_TOP,		/**< The text is top-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_MIDDLE,	/**< The text is middle-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_BOTTOM,	/**< The text is bottom-aligned inside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_OUTSIDE_TOP,	/**< The text is top-aligned outside the item */
	ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_OUTSIDE_BOTTOM	/**< The text is bottom-aligned outside the item */
};

/**
 * @enum IconListViewItemStatus
 * Defines the constants used to identify the item state.
 * 
 * @since 2.0
 */
enum IconListViewItemStatus {
	ICON_LIST_VIEW_ITEM_CHECKED = 0,					/**< The item has been checked (toggle of the check area) */
	ICON_LIST_VIEW_ITEM_UNCHECKED,						/**< The item has been unchecked (toggle of the check area) */
	ICON_LIST_VIEW_ITEM_SELECTED,						/**< The item has been selected (non-check area of the item) */
	ICON_LIST_VIEW_ITEM_HIGHLIGHTED						/**< The item has been highlighted (non-check area of the item) */
};

/**
 * @enum  IconListViewItemDrawingStatus
 *
 * Defines the drawing state of the %IconListView control items.
 *
 * @since 2.0
 */
enum IconListViewItemDrawingStatus
{
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_NORMAL = 0,		/**< The drawing status for normal items */
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_PRESSED,			/**< The drawing status for pressed items */
	ICON_LIST_VIEW_ITEM_DRAWING_STATUS_HIGHLIGHTED		/**< The drawing status for highlighted items */
};

/**
 * @enum IconListViewCheckBoxPosition
 * Defines the checkbox position.
 * 
 * @since 2.0
 */
enum IconListViewCheckBoxPosition {
    ICON_LIST_VIEW_CHECK_BOX_POSITION_TOP_LEFT,			/**< The position of the checkbox is top-left */
    ICON_LIST_VIEW_CHECK_BOX_POSITION_TOP_RIGHT,		/**< The position of the checkbox is top-right */
    ICON_LIST_VIEW_CHECK_BOX_POSITION_BOTTOM_LEFT,		/**< The position of the checkbox is bottom-left */
    ICON_LIST_VIEW_CHECK_BOX_POSITION_BOTTOM_RIGHT		/**< The position of the checkbox is bottom-right */
};

}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_ICONLISTVIEW_ENUM_H_
