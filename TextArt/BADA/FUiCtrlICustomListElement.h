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
 * @file	FUiCtrlICustomListElement.h 
 * @brief	This is the header file for the %ICustomListElement interface. 
 *
 * This header files contains the declarations of %ICustomListElement interface.
 *
 */

#ifndef _FUICTRL_ICUSTOMLIST_ELEMENT_H_
#define _FUICTRL_ICUSTOMLIST_ELEMENT_H_

//includes
#include "FGrpCanvas.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum	CustomListItemStatus
 * Defines the value of status of the CustomList item.
 *
 * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the ListItemStatus enumeration.
 *
 * @since   1.0
 *
 */
typedef enum
{
	CUSTOM_LIST_ITEM_STATUS_NORMAL = 0,		/**< The status of the item is normal */
	CUSTOM_LIST_ITEM_STATUS_SELECTED,		/**< The status of the item is selected */
	CUSTOM_LIST_ITEM_STATUS_FOCUSED			/**< The status of the item is focused */
} CustomListItemStatus;

/**
 * @interface	ICustomListElement
 * @brief 		This interface represents the common behaviors for a CustomList element.
 * @deprecated 	This interface is deprecated. Instead of using this interface, use the ICustomElement interface.
 * @since		1.0
 *
 *
 * The %ICustomListElement interface provides interfaces used for custom drawing 
 * in a custom list item.
 *
 * If an application wants to draw its own contents in a custom list item, it should 
 * implement %ICustomListElement and add elements by calling SetElement(int elementId, 
 * const %ICustomListElement &element). When the custom list item needs to be redrawn, 
 * DrawElement() is called by the framework.
 *
 */
class _EXPORT_CONTROLS_	ICustomListElement
	: public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~ICustomListElement(void) {}

// Operation
public:
	/**
	 * Draws a custom element of the item.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	canvas		The graphic canvas of the list control
	 * @param[in] 	rect        The location and size of the CustomList element
	 * @param[in]	itemStatus	The status of the item
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	virtual result DrawElement(const Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect, CustomListItemStatus itemStatus) = 0;
};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_ICUSTOMLIST_ELEMENT_H_
