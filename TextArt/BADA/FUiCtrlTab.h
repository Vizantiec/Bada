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
 * @file	FUiCtrlTab.h 
 * @brief	This is the header file for the %Tab class.
 *
 * This header file contains the declarations of the %Tab class and its helper classes.
 */

#ifndef _FUICTRL_TAB_H_
#define _FUICTRL_TAB_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlForm.h"
#include "FUiIActionEventListener.h"

// Forward declarations
namespace Osp { namespace Ui { namespace Controls {


/**
 * @class		Tab
 * @brief		This class is an implementation of a %Tab control.
 * @deprecated 	This class is deprecated because the use of the %Tab control is no longer recommended.
 * @since		1.0
 *
 * @remarks 	Note that tabs are part of a Form control, not a Frame control. This means that each tab item cannot be a form. You can associate a Panel 
 *				control or a ScrollPanel control to each tab item.
 * 
 * The %Tab class is an implementation of a %Tab control.
 * %Tab control displays the user selection in the form of a horizontal list. Each 
 * item of %Tab control consists of its text string and optional bitmap image. 
 * Items can be added to an itemlist of the tab model with AddItem(). Items can 
 * be inserted into an itemlist by InsertItemAt(), updated into an itemlist by SetItemAt(), 
 * removed from an itemlist by RemoveItemAt(), etc. It is possible to customize the 
 * background image of the tab shelf, and the image of the currently selected tab item. 
 * A badge icon can also be used to give more information for each tab item.
 *
 * Example:
 *
 * @image html GUI_tab.png
 *
 *
 * This is the simple UI application that uses a tab control.
 *
 * 
 * @code

//Sample Code for TabSample.h
#include <FUi.h>

class TabSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
public:
    result Construct();
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

//Sample Code for TabSample.cpp
#include "TabSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
TabSample::Construct()
{
	return Form::Construct(FORM_STYLE_NORMAL|FORM_STYLE_TEXT_TAB);
}

result
TabSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Gets a Tab control
    Tab* pTab = GetTab();
    if (pTab)
    {
        pTab->AddItem(L"First", 0);
        pTab->AddItem(L"Second", 1);
        pTab->AddActionEventListener(*this);
    }

    return r;
}

// Implements an IActionEventListener
void
TabSample::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
    switch (actionId)
    {
        case 0:
            // Todo:
            break;

        case 1:
            // Todo:
            break;

        default:
            break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Tab :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(Tab);
// Lifecycle
public:
	/**
	 * Adds a listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

// Operation
public:
	/**
	 * Adds an item consisting of the specified text string.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text            The text string of the item
	 * @param[in]	actionId		The action ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks		The @c actionId range is @c 0-999. @n
     *				The maximum number of items for Tab with text style is @c 9. @n
     *				The maximum number of items for icon style Tab is @c 8.
	 * @remarks     This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style.
	 */
	result AddItem(const Osp::Base::String& text, int actionId);

	/**
	 * Adds an item consisting of the title icon and the specified text string.
	 *
	 * @since		1.0
	 * @compatibility       This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                      For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	titleIcon	    The bitmap for the title icon
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for Tab with text style is @c 9. @n
	 *              The maximum number of items for icon style Tab is @c 8. @n
	 *				This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style.
	 * @remarks     If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result AddItem(const Osp::Graphics::Bitmap& titleIcon, const Osp::Base::String& text, int actionId);

	/**
	 * Adds the item that consists of the specified icon.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	icon	 		The bitmap for the icon
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
     *				The maximum number of items for Tab with text style is @c 9. @n
     *				The maximum number of items for icon style Tab is @c 8. @n
	 * 				This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of the bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result AddItem(const Osp::Graphics::Bitmap& icon, int actionId);

	/**
	 * Inserts the item that consists of only a text string at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	text            The text string of the item
	 * @param[in]	actionId        The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
 	 * @exception	E_OUT_OF_RANGE  The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for Tab with text style is @c 9. @n
	 *				The maximum number of items for icon style Tab is @c 8.
	 * @remarks     This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style.
	 */
	result InsertItemAt(int index, const Osp::Base::String& text, int actionId);

	/**
	 * Inserts the item that consists of the title icon and specified text string at the specified index.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	titleIcon	    The bitmap for the title icon
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999.
	 * @remarks     The maximum number of items for Tab with text style is @c 9. @n
	 *              The maximum number of items for icon style Tab is @c 8. @n
	 *				This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result InsertItemAt(int index, const Osp::Graphics::Bitmap& titleIcon, const Osp::Base::String& text, int actionId);

	/**
	 * Inserts the item which consists of the title icon and specified text string at the specified index.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	icon	 		The Bitmap for the Icon
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS 		The method is successful.
 	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks		The @c actionId range is @c 0-999.
     * @remarks		The maximum number of items for Tab with text style is @c 9. @n
     *				The maximum number of items for icon style Tab is @c 8. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down. @n
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result InsertItemAt(int index, const Osp::Graphics::Bitmap& icon, int actionId);

	/**
	 * Sets the item that consists of only a text string at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS 		The method is successful.
 	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style.
	 */
	result SetItemAt(int index, const Osp::Base::String& text, int actionId);

	/**
	 * Sets the item that consists of the title icon and the specified text string at the given index.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	titleIcon       The bitmap for the title icon
	 * @param[in]	text            The text string of the item
	 * @param[in]	actionId		The action ID for the item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetItemAt(int index, const Osp::Graphics::Bitmap& titleIcon, const Osp::Base::String& text, int actionId);

	/**
	 * Sets the item that consists of only a title icon at the specified index.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	icon	        The bitmap for the icon
	 * @param[in]	actionId		The action ID for the item
	 * @exception	E_SUCCESS 		The method is successful.
 	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetItemAt(int index, const Osp::Graphics::Bitmap& icon, int actionId);

	/**
	 * Removes item at the given index from the tab.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result RemoveItemAt(int index);

	/**
	 * Removes all the items from the tab.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAllItems(void);

	/**
	 * Sets the badge icon of the specified item.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTabIconSize20 "2.0".
	 * @return		An error code
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @param[in]	pBadgeIcon	 	The bitmap for the icon
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetBadgeIcon(int actionId, const Osp::Graphics::Bitmap* pBadgeIcon);

	/**
	 * @page	CompTabIconSize20	Compatibility for Tab Control	Icon Sizes
	 * @section	CompTabIconSize20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The size of the title icon, badge and icon sizes are: @n
	 * <table>
	 *     <tr>
	 *         <th>Type</th>
	 *         <th>WVGA</th>
	 *         <th>WQVGA</th>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Icon</td>
	 *         <td>52x52</td>
	 *         <td>26x26</td>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Badge Icon</td>
	 *         <td>40x40</td>
	 *         <td>20x20</td>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Title Icon</td>
	 *         <td>32x32</td>
	 *         <td>16x16</td>
	 *     </tr>
	 * </table>
	 *
	 * @section	CompTabIconSize20Resolutions	Resolutions
	 * The size of the title icon, badge and icon sizes are: @n
	 * <table>
	 *     <tr>
	 *         <th>Type</th>
	 *         <th>WVGA</th>
	 *         <th>WQVGA</th>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Icon</td>
	 *         <td>54x54</td>
	 *         <td>27x27</td>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Badge Icon</td>
	 *         <td>42x42</td>
	 *         <td>21x21</td>
	 *     </tr>
	 *     <tr>
	 *         <td>Tab Title Icon</td>
	 *         <td>38x36</td>
	 *         <td>18x18</td>
	 *     </tr>
	 * </table>
	 */

	/**
	 * Gets the number of items in the specified tab.
	 *
	 * @since		1.0
	 * @return		The number of items in the tab
	 */
	int GetItemCount(void) const;

	/**
	 * Gets the index of the item at the specified action ID.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *			    else @c -1 if an error occurs
	 * @param[in]	actionId		The action ID of the item
	 * @remarks		The @c actionId range is @c 0-999.
	 */
	int GetItemIndexFromActionId(int actionId) const;

	/**
	 * Gets the action ID of the item at the specified index.
	 *
	 * @since		1.0
	 * @return		The action ID of the item, @n
	 * 			    else @c -1 if @c index is less than @c 0 or greater than the item count of tab
	 * @param[in]	index		The index of the item
	 */
	int GetItemActionIdAt(int index) const;

	/**
	 * Sets the selected item for the specified index.
	 *
	 * @since		1.0
	 * @param[in]	index	The index of the item
	 */
	void SetSelectedItem(int index);

	/**
	 * Gets the index of the selected item from the tab.
	 *
	 * @since		1.0
	 * @return  	The index of the item, @n
	 *				else @c -1 if an error occurs
	 */
	int GetSelectedItemIndex(void) const;

	/**
	 * Sets the edit-enabled mode.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompTabSetEditModeEnabled "here".
	 * @param[in]	enable	Set to @c true to enable edit mode, @n
	 *						else @c false
	 */
	void SetEditModeEnabled(bool enable);

	/**
	 * @page	CompTabSetEditModeEnabled	Compatibility for SetEditModeEnabled()
	 * @section	CompTabSetEditModeEnabledIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	 * -#  When the tab mode changes from edit to normal, the first item gets focused, but listeners are not notified on the focus change. @n
	 * -#  When the tab mode is in the edit mode state and the form moves to the background, the tab mode does not change to the normal mode.
	 *
	 * @section	CompTabSetEditModeEnabledResolutions	Resolutions
	 * The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * Checks whether the edit mode is set.
	 *
	 * @since		1.0
	 * @return		@c true if the edit mode is set, @n
	 *				else @c false
	 */
	bool IsEditModeEnabled(void) const;

	/**
	 * Sets the background bitmap of the tab.
	 *
	 * @since		1.0
	 * @return	  	An error code
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The background bitmap is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the background bitmap of the focused item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	bitmap			The background bitmap of the focused item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The background bitmap is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetFocusedItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the text color of the tab.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabSetTextColor "here".
	 * @param[in]	textColor		The color to be set
	 */
	void SetTextColor(const Osp::Graphics::Color& textColor);

	/**
	 * @page	CompTabSetTextColor		Compatibility for SetTextColor()
	 *
	 * @section	CompTabSetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of the specified color.
	 *
	 * @section	CompTabSetTextColorResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color of the tab.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabGetTextColor "here".
	 * @return		The text color
	 */
	Osp::Graphics::Color GetTextColor(void) const;

    /**
     * @page	CompTabGetTextColor		Compatibility for GetTextColor()
     *
     * @section	CompTabGetTextColorIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color that is converted from the color specified by SetTextColor(), omitting the alpha value.
     *
     * @section	CompTabGetTextColorResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows:
     * -# The method returns a 32-bit color.
     */

	/**
	 * Sets the text color for the selected item of the tab.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabSetSelectedTextColor "here".
	 * @param[in]		textColor		The color to be set
	 */
	void SetSelectedTextColor(const Osp::Graphics::Color& textColor);

	/**
	 * @page	CompTabSetSelectedTextColor	Compatibility for SetSelectedTextColor()
	 *
	 * @section	CompTabSetSelectedTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of the specified color.
	 *
	 * @section	CompTabSetSelectedTextColorResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color for the selected item of the tab.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabGetSelectedTextColor "here".
	 * @return			The text color
	 */
	Osp::Graphics::Color GetSelectedTextColor(void) const;

    /**
     * @page	CompTabGetSelectedTextColor		Compatibility for GetSelectedTextColor()
     *
     * @section    CompTabGetSelectedTextColorIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color that is converted from the color specified by SetSelectedTextColor(), omitting the alpha value.
     *
     * @section	CompTabGetSelectedTextColorResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows:
     * -# The method returns a 32-bit color.
     */

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Enables or disables the object depending on the specified value ( @c enabled). @n
	 * Only an enabled object can respond to user input. By default, the object is enabled.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetEnabled(bool enable);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
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
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetPosition(int x, int y);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 * Its width becomes @c width, and its height becomes @c height.
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
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the show state of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetShowState(bool state);

	/**
	 * Gets the color of the text when the Tab item is highlighted.
	 *
	 * @since   		1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabGetHighlightedTextColor "here".
	 * @return			The highlighted text color
	 * @remarks			When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 */
	Osp::Graphics::Color GetHighlightedTextColor(void) const;

    /**
     * @page	CompTabGetHighlightedTextColor	Compatibility for GetHighlightedTextColor()
     *
     * @section	CompTabGetHighlightedTextColorIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color that is converted from the color specified by SetHighlightedTextColor(), omitting the alpha value.
     *
     * @section	CompTabGetHighlightedTextColorResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows:
     * -# The method returns a 32-bit color.
     */

	/**
	 * Sets the color of the text when the tab item is highlighted.
	 *
	 * @since   		1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompTabSetHighlightedTextColor "here".
	 * @param[in]		color	The color to be set
	 * @remarks      	When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 */
	void SetHighlightedTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page	CompTabSetHighlightedTextColor	Compatibility for SetHighlightedTextColor()
	 *
	 * @section	CompTabSetHighlightedTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of the specified color.
	 *
	 * @section	CompTabSetHighlightedTextColorResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Sets the background bitmap of the highlighted tab item.
	 *
	 * @since		1.1
	 * @return		An error code
	 * @param[in]	bitmap            The background bitmap of the focused item
	 * @exception	E_SUCCESS         The method is successful.
	 * @exception	E_INVALID_ARG     The background bitmap is invalid.
	 * @exception	E_SYSTEM          A system error has occurred.
	 * @remarks		The background bitmap should use the 9-patched bitmap.
	 * @remarks		When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 */
   	result SetHighlightedItemBackgroundBitmap (const Osp::Graphics::Bitmap& bitmap);

// Lifecycle
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the constructor for this class.
     * @since         1.0
     */	
	Tab(void);
			
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
     * @since         1.0
     */	
	virtual ~Tab(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of Tab with the specified parameter.
	 *
     * @since         1.0
	 * @return		An error code
	 * @param[in]	tabHandle		The handle of the tab
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY Insufficient memory.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	result Construct(int tabHandle);

	// Attribute
	/**
	 * @internal
	 * The ActionEvent
	 */
	Osp::Base::Runtime::IEvent* __pActionEvent;

	/**
	 * @internal
	 * The ActionEventAdaptor.
	 */
	void* __pActionEventAdaptor;

	/**
	 * @internal
	 * Stores __BitmapItem.
	 */
	Osp::Base::Collection::ArrayList	__items;

	/**
	 * @internal
	 * The form pointer.
	 */
	Form* __pParentForm;

	/**
	 * @internal
	 * __pBackgroundBitmap
	 */
	Osp::Graphics::Bitmap*	__pBackgroundBitmap;

	/**
	 * @internal
	 * __pFocusedItemBackgroundBitmap
	 */
	Osp::Graphics::Bitmap*	__pFocusedItemBackgroundBitmap;

private:
	friend class Form;
	friend class TabEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class TabEx* __pTabEx;

protected:
	friend class TabImpl;
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
	class TabImpl* GetImpl(void) const;

};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_TAB_H_

