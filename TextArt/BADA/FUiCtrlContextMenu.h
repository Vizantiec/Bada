/* $Change: 1037339 $ */
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
 * @file	FUiCtrlContextMenu.h
 * @brief	This is the header file for the %ContextMenu class.
 *
 * This header file contains the declarations of the %ContextMenu class and its helper classes.
 */

#ifndef _FUICTRL_CONTEXT_MENU_H_
#define _FUICTRL_CONTEXT_MENU_H_


// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FGrpRectangle.h"
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiContainer.h"
#include "FUiIActionEventListener.h"

namespace Osp { namespace Graphics { class Bitmap; }; };
namespace Osp { namespace Ui { namespace Controls {

/**
* @enum ContextMenuStyle
* Defines the %ContextMenu style.
*
* @since	1.0
*/
typedef enum
{
	CONTEXT_MENU_STYLE_LIST,		/**< The style of the text */
	CONTEXT_MENU_STYLE_ICON,		/**< The style of the bitmap icon */
} ContextMenuStyle;

/**
 * @enum ContextMenuItemStatus
 * Defines the possible states of the %ContextMenu control item.
 * 
 * @since 2.0
 */
enum ContextMenuItemStatus
{
	CONTEXT_MENU_ITEM_STATUS_NORMAL,		/**< The normal state */
	CONTEXT_MENU_ITEM_STATUS_PRESSED,		/**< The pressed state  */
	CONTEXT_MENU_ITEM_STATUS_HIGHLIGHTED	/**< The highlighted state */
};

/**
 * @enum ContextMenuAnchorDirection
 * Defines the direction of the %ContextMenu control.
 *
 * @since 2.0
 */
enum ContextMenuAnchorDirection
{
	CONTEXT_MENU_ANCHOR_DIRECTION_LEFTWARD,     /**< The anchor arrow direction is leftward */
	CONTEXT_MENU_ANCHOR_DIRECTION_RIGHTWARD,    /**< The anchor arrow direction is rightward */
	CONTEXT_MENU_ANCHOR_DIRECTION_UPWARD,       /**< The anchor arrow direction is upward */
	CONTEXT_MENU_ANCHOR_DIRECTION_DOWNWARD      /**< The anchor arrow direction is downward */
};

/**
 * @class	ContextMenu
 * @brief This class defines the common behavior of a %ContextMenu control.
 * @since	1.0
 *
 * The %ContextMenu class displays a special purpose window that is used to present users with context-sensitive options.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_contextmenus.htm">ContextMenu</a>.
 * 
 * The following example demonstrates how to use the %ContextMenu class.

 *
 * @code

// Sample Code for ContextMenuSample.h
#include <FUi.h>

class ContextMenuSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
public:
	ContextMenuSample(void)
	:__pContextMenu(null){}

protected:
    static const int ID_CONTEXTMENU_ITEM1 = 101;
    static const int ID_CONTEXTMENU_ITEM2 = 102;
    static const int ID_BTN_SHOW_CONTEXTMENU = 103;

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
    Osp::Ui::Controls::ContextMenu *__pContextMenu;
};

// Sample Code for ContextMenuSample.cpp
#include "ContextMenuSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
ContextMenuSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Create a ContextMenu
    __pContextMenu = new ContextMenu();
    __pContextMenu->Construct(Point(0, 0), CONTEXT_MENU_STYLE_LIST);

    __pContextMenu->AddItem("Item1",ID_CONTEXTMENU_ITEM1);
    __pContextMenu->AddItem("Item2",ID_CONTEXTMENU_ITEM2);
    __pContextMenu->AddActionEventListener(*this);

    // Create a Button to show the ContextMenu
	Button* pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 280, 60), L"Show ContextMenu");
	pButton->SetActionId(ID_BTN_SHOW_CONTEXTMENU);
	pButton->AddActionEventListener(*this);
	AddControl(*pButton);

    return r;
}

result
ContextMenuSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pContextMenu;

    return r;
}

// Implement an IActionEventListener
void
ContextMenuSample::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
    switch (actionId)
    {
	case ID_CONTEXTMENU_ITEM1:
		// Todo:
		break;

	case ID_CONTEXTMENU_ITEM2:
		// Todo:
		break;

	case ID_BTN_SHOW_CONTEXTMENU:
		// Set the anchor position of the ContextMenu
		__pContextMenu->SetPosition(Point(150, 70));

		// Show the ContextMenu
		__pContextMenu->SetShowState(true);
		__pContextMenu->Show();
		break;

	default:
		break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ ContextMenu :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(ContextMenu);
public:

// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	ContextMenu(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ContextMenu(void);

	/**
	 * Initializes this instance of %ContextMenu with the specified parameters.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	point	        The X and Y coordinates of the anchor of ContextMenu
	 * @param[in]	style			The context menu style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
	result Construct(const Osp::Graphics::Point& point, ContextMenuStyle style);

	/**
	 * Initializes this instance of %ContextMenu with the specified parameters.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	point			The X and Y coordinates of the anchor of the ContextMenu control
	 * @param[in]	style			The context menu style
	 * @param[in]	direction		The anchor arrow direction
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
	result Construct(const Osp::Graphics::Point& point, ContextMenuStyle style, ContextMenuAnchorDirection direction);

	/**
	 * Adds a listener instance.
	 * The added listener can listen to events on the given context of the event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes the specified listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);


// Operation
	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	normalBitmap		The normal bitmap of the item
	 * @param[in] 	pPressedBitmap		The pressed bitmap of the item
	 * @param[in]	actionId		    The action ID for this item
	 * @exception	E_SUCCESS 		    The method is successful.
	 * @exception	E_MAX_EXCEEDED	    The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
	 * 				The %ContextMenu control can have a maximum of 3 icons. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result AddItem(const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, int actionId);

    /**
     * Appends the specified item at the end of the %ContextMenu control.
     *
     * @since 		1.1
     * @return      An error code
     * @param[in]   normalBitmap        The normal bitmap of the item
     * @param[in]   pPressedBitmap      The pressed bitmap of the item
     * @param[in]   pHighlightedBitmap  The highlighted bitmap of the item
     * @param[in]   actionId            The action ID for this item
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
     *				When a user navigates the user interface using the directional keys, the selected UI control is highlighted and the control takes the 
	 *				focus. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result AddItem(const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, const Osp::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	text			The string of the item to be appended
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST. @n
	 * 				The ContextMenu control can have a maximum of 32 items in a list. 
	 */
	result AddItem(const Osp::Base::String& text, int actionId);

	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in] 	text				The string of the item to be appended
	 * @param[in]	actionId			The specified action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
     * @param[in] 	pPressedBitmap      The pressed bitmap of the item
     * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The total number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST. @n
	 * 				The ContextMenu control can have a maximum of 32 items in a list.@n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result AddItem(const Osp::Base::String& text, int actionId, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap = null, const Osp::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @param[in] 	normalBitmap	The normal bitmap of the item
	 * @param[in] 	pPressedBitmap	The pressed bitmap of the item
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
	 * 				The ContextMenu control can have a maximum of 3 icons. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result InsertItemAt(int index, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, int actionId);

    /**
     * Inserts the specified item at the given index of the %ContextMenu control.
     *
     * @since 		1.1
     * @return		An error code
     * @param[in]	index                      The location
     * @param[in]	normalBitmap               The normal bitmap of the item
     * @param[in]	pPressedBitmap             The pressed bitmap of the item
     * @param[in]	pHighlightedBitmap         The highlighted bitmap of the item
     * @param[in]	actionId                   The specified action ID for this item
     * @exception	E_SUCCESS                  The method is successful.
     * @exception	E_MAX_EXCEEDED             The number of items has exceeded the maximum limit.
     * @exception	E_OUT_OF_RANGE             The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
     * @exception	E_SYSTEM                   A system error has occurred.
     * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
     *				The ContextMenu control can have a maximum of 3 icons.
     * @remarks		When a user navigates the user interface using the directional keys, the selected UI control is highlighted and the control takes the focus. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result InsertItemAt(int index, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, const Osp::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   index			The location
	 * @param[in]   text			The string of the item to set
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST. @n
	 * 				A ContextMenu control can have a maximum of 32 items in a list.
	 */
	result InsertItemAt(int index, const Osp::Base::String& text, int actionId);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	text				The string of the item to set
	 * @param[in]	actionId			The specified action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
     * @param[in] 	pPressedBitmap      The pressed bitmap of the item
     * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST. @n
	 * 				A ContextMenu control can have a maximum of 32 items in a list.@n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result InsertItemAt(int index, const Osp::Base::String& text, int actionId, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap = null, const Osp::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	normalBitmap		The normal bitmap of the item
	 * @param[in] 	pPressedBitmap		The pressed bitmap of the item
	 * @param[in]	actionId		    The action ID for this item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE	    The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetItemAt(int index, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, int actionId);

    /**
     * Sets the specified item at the given index of the %ContextMenu control.
     *
     * @since 			1.1
     * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     				For more information, see @ref CompContextMenuSetItemAt "here".
     *
     * @return        An error code
     * @param[in]     index                      The location
     * @param[in]     normalBitmap               The normal bitmap of the item
     * @param[in]     pPressedBitmap             The pressed bitmap of the item
     * @param[in]     pHighlightedBitmap         The highlighted bitmap of the item
     * @param[in]     actionId                   The action ID for this item
     * @exception     E_SUCCESS                  The method is successful.
     * @exception     E_OUT_OF_RANGE             The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
     * @exception     E_SYSTEM                   A system error has occurred.
     * @remarks       This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_ICON. @n
     * @remarks       When a user navigates the user interface using the directional keys, @n
     *                the selected UI control is highlighted and the control takes the focus. @n
	 *				  For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result SetItemAt(int index, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap, const Osp::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @param[in] 	text			The string of the item to set
	 * @param[in]	actionId		The action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST.
	 */
	result SetItemAt(int index, const Osp::Base::String& text, int actionId);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	text				The string of the item to set
	 * @param[in]	actionId			The action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
	 * @param[in] 	pPressedBitmap      The pressed bitmap of the item
	 * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks    	This method can only be used when the style of the context menu is CONTEXTMENU_STYLE_LIST. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetItemAt(int index, const Osp::Base::String& text, int actionId, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap = null, const Osp::Graphics::Bitmap* pHighlightedBitmap = null);

    /**
     * @page CompContextMenuSetItemAt Compatibility for SetItemAt()
     * @section CompContextMenuSetItemAtIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -#  When the %ContextMenu control has the maximum number of items, SetItemAt() takes a highlighted bitmap. The SetItemAt() method returns 
	 *	   E_MAX_EXCEEDED and does not work as expected. @n
	 *	   When the style is set as icon, the maximum number of items is 3. On the other hand, when the style is set as list, the maximum number is 32.
     *
     * @section CompContextMenuSetItemAtResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */


	/**
	 * Removes the item at the specified index from the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveItemAt(int index);

	/**
	 * Removes all items from the %ContextMenu control.
	 *
	 * @since		1.0
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAllItems(void);

	/**
	 * Gets the number of items of the %ContextMenu control.
	 *
	 * @since	1.0
	 * @return	The number of items registered for %ContextMenu, @n
	 * 			else @c -1 if an error occurs
	 */
	int GetItemCount(void) const;

	/**
	 * Gets the index of the item with the specified action ID.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 * 				else @c -1 if an error occurs
	 * @param[in] 	actionId	The action ID
	 */
	int GetItemIndexFromActionId(int actionId) const;

	/**
	 * Gets the action ID of the item at the specified index.
	 *
	 * @since		1.0
	 * @return		The action ID of the item, @n
	 * 				else @c -1 if the specified index is invalid
	 * @param[in]   index		The index of the item
	 */
	int GetItemActionIdAt(int index) const;

	/**
	 * Gets the position of the anchor.
	 *
	 * @since		1.0
	 * @return		The position of the anchor
	 * @remarks		The coordinate of the anchor position is defined from the top-left corner of its parent Container.
	 */
	Osp::Graphics::Point GetPosition(void) const;

	/**
	 * Gets the position of the anchor.
	 *
	 * @since		1.0
	 * @param[out]	x	The x coordinate of the anchor position
	 * @param[out]	y	The y coordinate of the anchor position
	 * @remarks			The coordinate of the anchor position is defined from the top-left corner of its parent container.
	 */
	void GetPosition(int& x, int& y) const;

	/**
	 * Shows the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Show(void);

	/**
	 * Sets the position of the anchor.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	x			The new x coordinate
	 * @param[in]	y			The new y coordinate
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		The X and Y coordinates of the anchor are defined in the coordinates of its parent,
	 *				which means that @c x and @c y must be defined relative to the top-left corner (0,0) of its parent.
	 */
	virtual result SetPosition(int x, int y);

	/**
	 * Sets the position of the anchor.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	Position		The new position
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The X and Y coordinates of the anchor are defined in the coordinates of its parent,
	 *				which means that @c x and @c y must be defined relative to the top-left corner (0,0) of its parent.
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
	 * Sets the show state of the %ContextMenu control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	state			Set to @c true to enable the show state, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Although this method is invoked, the control is not drawn or shown. @n
	 *				To show a control, use the Show() method. @n
	 *				The specified @c state is set to @c true to show a control, else @c false.
	 * @see			GetShowState(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Draws the control.
	 *
	 * @since	1.0
	 */
	result Draw(void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (E_UNSUPPORTED_OPERATION) Gets the control with the specified name. @n
	 * Error code can be received using the GetLastResult() method.
	 *
	 * @since	1.0
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since	1.0
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since	1.0
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since	1.0
	 */
	virtual result SetSize(int width, int height);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since	1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
	 * Gets the item text color of the %ContextMenu control for the specified status.
	 *
	 * @since 		2.0
	 * @return      The item text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status		The item status
	 */
	Osp::Graphics::Color GetItemTextColor(ContextMenuItemStatus status) const;

	/**
	 * Sets the item text color of the %ContextMenu control for the specified status.
	 *
	 * @since 		2.0
	 * @return      An error code
	 * @param[in]   status				The item status
	 * @param[in]   color				The item text color to be set
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result SetItemTextColor(ContextMenuItemStatus status, const Osp::Graphics::Color& color);

	/**
	 * Gets the color of the %ContextMenu control.
	 *
	 * @since		2.0
	 * @return		The color of %ContextMenu control, @n
	 * 				else RGBA(0, 0, 0, 0) if an error occurs
	 * @see			SetColor()
	 */
	Osp::Graphics::Color GetColor(void) const;

	/**
	 * Sets the color of the %ContextMenu control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color				The color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the item color for the specified status.
	 *
	 * @since		2.0
	 * @return		The color of %ContextMenu control, @n
	 *  			else RGBA(0, 0, 0, 0) if an error occurs
	 * @param[in]	status				The menu item status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 * 									The item color for CONTEXT_MENU_ITEM_STATUS_NORMAL is not supported.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				The item color for the CONTEXT_MENU_ITEM_STATUS_NORMAL status is always the same as the color of the ContextMenu control.
	 * @see			SetItemColor()
	 */
	Osp::Graphics::Color GetItemColor(ContextMenuItemStatus status) const;

	/**
	 * Sets the item color for the specified status.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	status				The menu item status
	 * @param[in]	color				The color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 * 									The item color for CONTEXT_MENU_ITEM_STATUS_NORMAL is not supported.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The item color for the CONTEXT_MENU_ITEM_STATUS_NORMAL status is always the same as the color of the ContextMenu control.
	 * @see			GetItemColor()
	 */
	result SetItemColor(ContextMenuItemStatus status, const Osp::Graphics::Color& color);

	/**
	 * Gets maximum number of visible items.
	 *
	 * @since		2.0
	 * @return		The maximum number of visible items, @n
	 * 				else @c -1 if an error occurs
	 * @see			SetMaxVisibleItemsCount()
	 */
	int GetMaxVisibleItemsCount(void) const;

	/**
	 * Sets maximum number of visible items.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	maxItemsCount		The maximum number of the visible menu items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c parameter is out of possible range.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		@c maxItemsCount should be greater than @c 0 and less than @c 8. The default value for
	 * 				the maximum number of the visible menu items is @c 4.
	 * @see			GetMaxVisibleItemsCount()
	 */
	result SetMaxVisibleItemsCount(int maxItemsCount);


protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window (if it is present).
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the content of this Popup.
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error occurred.
	 */
	virtual result __Draw(void);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the control at the end of the list maintained by this container.
	 * @since		1.0
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 * @since		1.0
	 */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 * @since		1.0
	 */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes all controls from this container.
	 * @since		1.0
	 */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the control at the specified index of the list that are kept by this container.
	 * @since		1.0
	 */
	virtual Control* GetControl(int index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the number of the controls in this container.
	 * @since		1.0
	 */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns a list of controls of this container.
	 * @since		1.0
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns @c true if the specified control is within @n
	 * the containment hierarchy of this container. Otherwise, it returns @c false.
	 * @since		1.0
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 * @since		1.0
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 * @since		1.0
	 */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the specified control to this container.
	 * @since		1.0
	 */
	virtual result AddControlImplAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Notifies this container that it has been added to a control
	 * containment hierarchy.
	 * @since		1.0
	 */
	virtual result AddNotify(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Notifies this containers that it should be disconnected from the current
	 * native peer window.
	 * @since		1.0
	 */
	virtual result RemoveNotify(void);


private:
	// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Action Event.
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pActionEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Notify Event.
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pNotifyEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Action Event Adaptor.
     * @since         1.0
     */
	void* __pActionEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Notify Event Adaptor.
     * @since         1.0
     */
	void* __pNotifyEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID.
     * @since         1.0
     */
	int __actionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Stores __BitmapItem.
     * @since         1.0
     */
	Osp::Base::Collection::ArrayList	__items;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * ContextMenu Style
     * @since         1.0
     */
	ContextMenuStyle	__style;
	
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The first show flag.
     * @since         1.0
     */
	bool	__firstShow;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The showing flag.
     * @since         1.0
     */
	bool	__showing;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The rotate event adaptor.
     * @since         1.0
     */
	void*	__pRotateEventAdpator;


private:
	friend class __ContextMenuRotateAdaptor;
	friend class ContextMenuEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class ContextMenuEx*	__pContextMenuEx;

protected:
	friend class ContextMenuImpl;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control
     *
     * @since         2.0
     */
	class ContextMenuImpl* GetImpl(void) const;

}; // ContextMenu
}; }; };//Osp::Ui::Controls

#endif // _FUICTRL_CONTEXT_MENU_H_

