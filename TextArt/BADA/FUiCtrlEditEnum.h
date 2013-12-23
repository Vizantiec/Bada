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
 * @file			FUiCtrlEditEnum.h 
 * @brief			This is the header file for the Ui::Controls edit control enumerations.
 *
 * This header file contains the declarations of the Ui::Controls edit control enumerations.
 */
#ifndef _FUICTRL_EDITENUM_H_
#define _FUICTRL_EDITENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum EditInputModeCategory
 * Defines the input modes.
 *
 * @since		1.0
 */
typedef enum {
	EDIT_INPUTMODE_ALPHA = 0x0001, /**< The alphabetic input mode */
	EDIT_INPUTMODE_PREDICTIVE = 0x0002, /**< The predictive input mode*/
	EDIT_INPUTMODE_NUMERIC = 0x0004, /**< The numeric input mode */
	EDIT_INPUTMODE_SYMBOL = 0x0008 /**< The symbolic input mode */
} EditInputModeCategory;

/**
 * @enum EditFieldStyle
 * Defines the EditField style.
 *
 * @since		1.0
 */
typedef enum {
	EDIT_FIELD_STYLE_NORMAL, /**< The normal style */
	EDIT_FIELD_STYLE_PASSWORD, /**< The password style '****' */
	EDIT_FIELD_STYLE_NORMAL_SMALL, /**< The small normal style */
	EDIT_FIELD_STYLE_PASSWORD_SMALL, /**< The small password style '****' */
	EDIT_FIELD_STYLE_EMAIL, /**< The email style */
	EDIT_FIELD_STYLE_URL, /**< The URL style */
	EDIT_FIELD_STYLE_EMAIL_SMALL, /**< The small email style */
	EDIT_FIELD_STYLE_URL_SMALL, /**< The small URL style */
	EDIT_FIELD_STYLE_NUMBER, 					/**< The number style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_NUMBER_SMALL,				/**< The small number style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_PHONE_NUMBER, 				/**< The phone number style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_PHONE_NUMBER_SMALL,		/**< The small phone number style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_PASSWORD_NUMBER, 			/**< The number password style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_PASSWORD_NUMBER_SMALL, 	/**< The small number password style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_IP_V4, 					/**< The IP V4 style @b since: @b 2.0 */
	EDIT_FIELD_STYLE_IP_V4_SMALL, 				/**< The small IP V4 style @b since: @b 2.0 */
} EditFieldStyle;

/**
 * @enum CommandButtonPosition
 * Defines the command button position.
 *
 * @since		1.0
 */
typedef enum {
	COMMAND_BUTTON_POSITION_LEFT, /**< The position is to the left */
	COMMAND_BUTTON_POSITION_RIGHT /**< The position is to the right */
} CommandButtonPosition;

/**
 * @enum EditMarginType
 *
 * Defines the possible margin types of EditField and EditArea.
 * @since		2.0
 */
enum EditMarginType {
	EDIT_MARGIN_TYPE_VERTICAL, /**< The margin for top and bottom */
	EDIT_MARGIN_TYPE_HORIZONTAL /**< The margin for left and right */
};

/**
 * @enum EditTextColor
 *
 * Defines the possible edit text colors.
 * @since		2.0
 */
enum EditTextColor
{
	EDIT_TEXT_COLOR_NORMAL,			/**< The normal text color */
	EDIT_TEXT_COLOR_DISABLED,		/**< The disabled text color */
	EDIT_TEXT_COLOR_HIGHLIGHTED,	/**< The selected text color */
	EDIT_TEXT_COLOR_LINK			/**< The highlighted text color */
};

/**
 * @enum EditStatus
 *
 * Defines the possible edit states.
 * @since		2.0
 */
enum EditStatus
{
	EDIT_STATUS_NORMAL,			/**< The normal state */
	EDIT_STATUS_DISABLED,		/**< The disabled state */
	EDIT_STATUS_HIGHLIGHTED,	/**< The highlighted state */
    EDIT_STATUS_PRESSED			/**< The pressed state */
};

/**
 * @enum EditFieldTitleStyle
 *
 * Defines the possible styles of the title.
 * @since		2.0
 */
enum EditFieldTitleStyle
{
	EDIT_FIELD_TITLE_STYLE_NONE = 0,		/**< No title */
	EDIT_FIELD_TITLE_STYLE_INNER,			/**< The title appears inside of the EditField's input field */
	EDIT_FIELD_TITLE_STYLE_TOP				/**< The title appears at the top input field */
};

/**
 * @enum EllipsisPosition
 *
 * Defines the possible positions of the ellipsis.
 * @since		2.0
 */
enum EllipsisPosition {
	ELLIPSIS_POSITION_START = 0,		/**< The ellipsis appears at the start of text block */
	ELLIPSIS_POSITION_MIDDLE,			/**< The ellipsis appears at the middle of text block */
	ELLIPSIS_POSITION_END,				/**< The ellipsis appears at the end of text block  */
};

/**
 * @enum KeypadStyle
 * Defines the initial keypad style.
 *
 * @since		1.0
 */
typedef enum {
	KEYPAD_STYLE_NORMAL = 0, /**< The normal style */
	KEYPAD_STYLE_PASSWORD, /**< The password style '****' */
	KEYPAD_STYLE_EMAIL, /**< The email style */
	KEYPAD_STYLE_URL, /**< The URL style */
	KEYPAD_STYLE_NUMBER, 		/**< The number style  @b since: @b 2.0 */
	KEYPAD_STYLE_PHONE_NUMBER, 	/**< The phone number style  @b since: @b 2.0 */
	KEYPAD_STYLE_IP_V4, 		/**< The IP V4 style  @b since: @b 2.0 */
} KeypadStyle;

}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_EDITENUM_H_

