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
 * @file	FUiCtrlGroupedList.h
 * @brief	This is the header file for the %GroupedList class.
 *
 * This header file contains the declarations of the %GroupedList class and its helper classes.
 */

#ifndef _FUICTRL_GROUPEDLIST_H_
#define _FUICTRL_GROUPEDLIST_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlCustomList.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiIFastScrollEventListener.h"
#include "FUiIGroupedItemEventListener.h"
#include "FUiCtrlListEnum.h"


namespace Osp { namespace Ui { namespace Controls {

/**
 * @class		GroupedList
 * @brief 		This class defines the common behavior of a %GroupedList control.
 * @deprecated	This class is deprecated. Instead of using this class, use GroupedListView class.
 * @since		1.0
 *
 *
 * The %GroupedList class represents grouped items in a list. List items of 
 * %GroupedList consist of groups and items. A group represents grouped items and is 
 * inserted into the first level as items are inserted into List. Items which are 
 * CustomListItem are inserted under related groups. So, items are uniquely identified 
 * with two indices: group index and item index.
 * 
 * If an application wants to perform tasks when the state of a list item is changed, 
 * it should implement IGroupedItemEventListener and register it to the grouped list, 
 * It will then receive related events from %GroupedList.
 * 
 * Unlike ExpandableList which is also a list with a hierarchy of depth 2, group 
 * item itself does not have many functions.
 * 
 * A typical use case of %GroupedList would be a list which groups all items alphabetically.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically 
 * when the %GroupedList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat 
 * should be deleted by the application.
 * 
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 * 
 * @image html GUI_groupedlist.png
 *
 * This is the simple UI application that uses a %GroupedList control.
 *
 * @code
 
// Sample Code for GroupedListSample.h
#include <FBase.h>
#include <FUi.h>

class GroupedListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::ICustomItemEventListener
{
public:
    GroupedListSample(void)
    :__pCustomListItemFormat(null){};

protected:
    static const int ID_LIST_       = 101;
	static const int ID_LIST_TEXT   = 102;
	static const int ID_LIST_BITMAP = 103;

    Osp::Graphics::Bitmap* GetBitmapN(void);

    result AddListItem(
        Osp::Ui::Controls::GroupedList& groupedList, int groupId,
        Osp::Base::String itemText,
        Osp::Graphics::Bitmap* pBitmapNormal,
        Osp::Graphics::Bitmap* pBitmapFocused);

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
    virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status);

private:
    Osp::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};

// Sample Code for CutomListSample.cpp
#include "GroupedListSample.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
GroupedListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Create Bitmaps
    Bitmap *pBitmapNormal  = GetBitmapN();
    Bitmap *pBitmapFocused = GetBitmapN();

    // Create a GroupedList
    GroupedList* pGroupedList = new GroupedList();
    pGroupedList->Construct(Rectangle(0,0,480,500), CUSTOM_LIST_STYLE_NORMAL);

    // Create an item format of the GroupedList
    __pCustomListItemFormat = new CustomListItemFormat();
    __pCustomListItemFormat->Construct();
    __pCustomListItemFormat->AddElement(ID_LIST_TEXT, Rectangle(10, 25, 200, 80));
    __pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Rectangle(220, 10, 70, 80));

    // Add a group to the GroupedList
    pGroupedList->AddGroup(L"Group_1", null);
    pGroupedList->AddGroup(L"Group_2", null);

    // Add an item to the GroupedList
    AddListItem(*pGroupedList, 0, L"SubItem1", pBitmapNormal, pBitmapFocused);
    AddListItem(*pGroupedList, 0, L"SubItem2", pBitmapNormal, pBitmapFocused);

    AddListItem(*pGroupedList, 1, L"SubItem1", pBitmapNormal, pBitmapFocused);
    AddListItem(*pGroupedList, 1, L"SubItem2", pBitmapNormal, pBitmapFocused);

     // Add a GroupedList to the Form.
    AddControl(*pGroupedList);

    // Display the Form
    Draw();
    Show();

    // Deallocate a Bitmap
    delete pBitmapNormal;
    delete pBitmapFocused;

    return r;
}

result
GroupedListSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    // Deallocate an item format
    delete __pCustomListItemFormat;

    return r;
}

result
GroupedListSample::AddListItem(GroupedList& groupedList, int groupId, String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
    result r = E_SUCCESS;

    // Create an item of the GroupedList
    CustomListItem* pItem = new CustomListItem();
    pItem->Construct(100);
    pItem->SetItemFormat(*__pCustomListItemFormat);
    pItem->SetElement(ID_LIST_TEXT, itemText);
    pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

    // Add an item to the GroupedList
    groupedList.AddItem(groupId, *pItem, ID_LIST_);

    return r;
}

Bitmap*
GroupedListSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

// Implement an ICustomItemEventListener
void
GroupedListSample::OnItemStateChanged(const Control& source, int index, int itemId, ItemStatus status)
{
    switch (itemId)
    {
    case ID_LIST_:
        // Todo:
        break;
    default:
        break;
    }
}

void
GroupedListSample::OnItemStateChanged(const Control& source, int index, int itemId, int elementId, ItemStatus status)
{
    switch (itemId)
    {
    case ID_LIST_:
        switch (elementId)
        {
            case ID_LIST_TEXT:
                // Todo:
                break;
            case ID_LIST_BITMAP:
                // Todo:
                break;
            default:
                break;
        }
        break;
    default:
        break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_	GroupedList :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(GroupedList);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	GroupedList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~GroupedList(void);

// Operation
	
	/**
	  * Initializes this instance of %GroupedList with the specified parameters.
	  *
	  * @since			1.0
	  * @compatibility	This method has compatibility issues with different bada API versions. @n
	  *					For more information, see @ref CompGroupedListConstruct "1.2" and @ref CompGroupedListConstruct20 "2.0".
	  * @return		An error code
	  * @param[in]	rect			An instance of the Graphics::Rectangle class @n
	  *								This instance represents the X, Y coordinates of the top-left corner of the created GroupedList along with the width and 
	  *								height.
	  * @param[in]	style			The style of the %GroupedList control
	  * @param[in]	itemDivider		Set to @c true to display an item divider, @n
	  *								else @c false
	  * @param[in]	fastScroll		Set to @c true if to use a fast scroll, @n
	  *								else @c false
	  * @exception	E_SUCCESS		The method is successful.
	  * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	  * @exception	E_INVALID_STATE	This instance has already been constructed.
	  * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	  * @exception	E_SYSTEM		A system error has occurred.
	  * @remarks   	In bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
      * @remarks   	From bada API version 2.0, the size of the control must be within the range as defined by the minimum and maximum size.
      * @remarks   	The minimum size of this control is 274 x 148 on a WVGA screen, 180 x 96 on a HVGA screen and 137 x 74 on a WQVGA screen.
	  */
	 result Construct(const Osp::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true, bool fastScroll = false);

	 /**
	  * @page	CompGroupedListConstruct	Compatibility for Construct()
	  *
	  * @section	CompGroupedListConstructIssues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# If the size of the control is less than 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen, then fast scroll is not displayed.
	  *
	  * @section	CompGroupedListConstructResolutions		Solutions
	  * The issue mentioned above is resolved in bada API version 1.2. @n
	  * -# The minimum size of the control is modified to 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen.
	  *
	  */

	 /**
	 * @page	CompGroupedListConstruct20	Compatibility for Construct()
	 *
	 * @section	CompGroupedListConstruct20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size. @n
	 * -# On a WVGA screen, the default minimum sizes are 300 x 250.
	 *
	 * @section	CompGroupedListConstruct20Resolutions	Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0.
	 * -# On a WVGA screen, the default minimum sizes are changed to 270 x 144.
	 */

	/**
	 * Adds the group to the %GroupedList control.
	 *
	 * @since		1.0
 	 * @return		An error code
	 * @param[in]	text				The string of the group to be appended
     * @param[in]	pBackgroundBitmap	The background bitmap of the group
     * @param[in]	groupId				The ID of the group
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 */
	result AddGroup(const Osp::Base::String& text, const Osp::Graphics::Bitmap* pBackgroundBitmap, int groupId=LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Inserts the group of the %GroupedList control at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   groupIndex			The group index
	 * @param[in] 	text				The name of the group item
	 * @param[in] 	pBackgroundBitmap	The background bitmap of the group item
	 * @param[in] 	groupId				The ID of the group item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The @c groupIndex is out of bounds.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result InsertGroupAt(int groupIndex, const Osp::Base::String& text, const Osp::Graphics::Bitmap* pBackgroundBitmap, int groupId=LIST_ITEM_UNSPECIFIED_ID);

   /**
    * Sets the contents of the group of the %GroupedList control at the index.
    *
    * @since		1.0
    * @return		An error code
    * @param[in]  	groupIndex		    The group index
	* @param[in] 	text			    The string of the group to be appended
    * @param[in] 	pBackgroundBitmap	The bitmap of the group
    * @param[in] 	groupId				The ID of the group
    * @exception	E_SUCCESS		    The method is successful.
    * @exception	E_INVALID_ARG		The specified @c groupIndex is invalid.
    * @exception	E_SYSTEM		    A system error has occurred.
    */
    result SetGroupAt(int groupIndex, const Osp::Base::String& text, const Osp::Graphics::Bitmap* pBackgroundBitmap, int groupId=LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Removes the group of the %GroupedList control at the index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed. @n
	 *				The removed list items are deleted from the memory.
	 */
	result RemoveGroupAt(int groupIndex);

	/**
	 * Removes all the groups of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed. @n
	 *				The removed list items are deleted from the memory.
	 */
	result RemoveAllGroups(void);

	/**
	 * Counts all the groups of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		The count of all the groups
	 */
	int	GetGroupCount(void) const;

	/**
	 * Adds the item to the specified group.
	 *
	 * @since		1.0
 	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	item			The custom list item object to be added
	 * @param[in]	itemId			The specified item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The added item is deleted automatically when the list is destroyed. @n
	 *				Do not add, insert, or set an item that already belongs to a %GroupedList control.
	 */
	result AddItem(int groupIndex, const CustomListItem& item, int itemId=LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Inserts the item to the specified group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	itemIndex		The item index in the specified group
	 * @param[in]	item	 		The custom list item to be inserted
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to a %GroupedList control.
	 */
	result InsertItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

   /**
    * Sets the contents of the item in the specified group.
    *
    * @since		1.0
    * @return		An error code
    * @param[in]  	groupIndex		The group index
    * @param[in]  	itemIndex		The item index in the specified group
    * @param[in]	item			The custom list item to be set
    * @param[in]	itemId			The item ID for this item
    * @exception	E_SUCCESS		The method is successful.
    * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemId is invalid.
    * @exception	E_SYSTEM		A system error has occurred.
    * @remarks		Do not add, insert, or set an item that already belongs to a %GroupedList control.
    */
	result SetItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Sets the checked status for the specified item. 
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompGroupedListSetItemChecked "here".
	 * @return						An error code
	 * @param[in] 	groupIndex		The group index of the item
	 * @param[in] 	itemIndex		The item index
	 * @param[in] 	check			Set to @c true to check the item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.	 
	 */	
	result SetItemChecked(int groupIndex, int itemIndex, bool check);
	
	/**
	 * @page	CompGroupedListSetItemChecked	Compatibility for SetItemChecked()
	 * @section	CompGroupedListSetItemCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the specified item is disabled, the checked status of the item is not changed.
	 *
	 * @section	CompGroupedListSetItemCheckedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */

	/**
	 * Enables the specified item. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex		The group index of the item
	 * @param[in] 	itemIndex		The item index
	 * @param[in]	enable			Set to @c true to enable the item, @n
	 *								else @c false   
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */	
	result SetItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * Sets the background color of this control.
	 *
	 * @since 		1.1
	 * @param[in]	color	The background color
	 */
	void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Sets the text that is displayed when %GroupedList is empty. 
	 *
	 * @since		1.0
	 * @param[in]	text	The empty list test
	 */	
	void SetTextOfEmptyList (const Osp::Base::String &text);

	/**
	 * Sets the color of the text that is displayed when %GroupedList is empty.
	 *
	 * @since     1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompGroupedListSetTextColorOfEmptyList "here".
	 *
	 * @param[in]	color	The color of the text to be displayed
	 */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

    /**
     * @page	CompGroupedListSetTextColorOfEmptyList	Compatibility for SetTextColorOfEmptyList()
     *
     * @section	CompGroupedListSetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method ignores the alpha value of specified color.
     *
     * @section	CompGroupedListSetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

	/**
	 * Gets the color of the text that is displayed when %GroupedList is empty.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompGroupedListGetTextColorOfEmptyList "here".
	 *
	 * @return	The color of the text to be displayed
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;

    /**
     * @page	CompGroupedListGetTextColorOfEmptyList	Compatibility for GetTextColorOfEmptyList()
     *
     * @section	CompGroupedListGetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color that is converted from the color specified by SetTextColorOfEmptyList(), omitting the alpha value.
     *
     * @section	CompGroupedListGetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows:
     * -# The method returns a 32-bit color.
     */


	/**
	 * Checks whether the item at the specified index of this grouped list is checked. 
	 *
	 * @since		1.0
	 * @return		@c true if the item is checked, @n
	 * 				else @c false
	 * @param[in]	groupIndex		The group index of the item
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */	
	bool IsItemChecked (int groupIndex, int itemIndex) const;
	
	/**
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]   groupIndex		The group index of the item
	 * @param[in]   itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */	
	bool IsItemEnabled (int groupIndex, int itemIndex) const;

	/**
	 * Removes an item in the specified group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list item is deleted from the memory.
	 */
	result RemoveItemAt(int groupIndex, int itemIndex);

	/**
	 * Removes all the items in the specified group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveAllItemsAt(int groupIndex);

	/**
	 * Removes all the checked items in the specified group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveAllCheckedItemsAt(int groupIndex);

	/**
	 * Counts all items of the %GroupedList instance.
	 *
	 * @since		1.0
	 * @return		The item count of the specified group
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	int	GetItemCountAt(int groupIndex) const;

	/**
	 * Gets the item ID of the item at the specified index.
	 *
	 * @since		1.0
	 * @return		The item ID
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	itemIndex		The item index in the specified group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	int GetItemIdAt(int groupIndex, int itemIndex) const;

	/**
	 * Gets the item index by the specified item ID.
	 *
	 * @since			1.0
	 * @return			An error code
	 * @param[in]		itemId			The item ID
	 * @param[out]  	groupIndex		The group index
	 * @param[out]  	itemIndex		The item index in the specified group
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_SYSTEM		A system error has occurred.
	 */
	result GetItemIndexFromItemId (int itemId, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the group ID at the specified index.
	 *
	 * @since		1.0
	 * @return		The group ID
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	int GetGroupIdAt (int groupIndex) const;

	/**
	 * Gets the group index from the specified group ID.
	 *
	 * @since		1.0
	 * @return		The group index
	 * @param[in]	groupId		    The ID of the group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	int GetGroupIndexFromGroupId (int groupId) const;

	/**
	 * Gets the index of the last item checked.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]  groupIndex		The group index
	 * @param[out]  itemIndex		The item index in the specified group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetLastCheckedItemIndex (int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the next checked item.
	 *
	 * @since			1.0
	 * @return			An error code
	 * @param[in,out] 	groupIndex		The group index
	 * @param[in,out] 	itemIndex		The item index in the specified group
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_SYSTEM		A system error has occurred.
	 */
	result GetNextCheckedItemIndexAfter (int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   x				The x position of the point
	 * @param[in]   y				The y position of the point
	 * @param[out]	groupIndex		The index of the group which the item belongs to
	 * @param[out]	itemIndex		The index of the item 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred. @n 
	 *								There is no item at the specified position.
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   position    	The position of the point
	 * @param[out]	groupIndex  	The index of the group which the item belongs to
	 * @param[out]	itemIndex   	The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred. @n
	 *								There is no item at the specified position.
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * Returns the index of the current top drawn list item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out] 	groupIndex	    The group index of the item
	 * @param[out] 	itemIndex		The item index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetTopDrawnItemIndex (int &groupIndex, int &itemIndex) const;

	/**
	 * Removes all the items of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveAllItems(void);

	/**
	 * Removes all the checked items of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveAllCheckedItems(void);

	/**
	 * Gets the specified item of the %GroupedList control.
	 *
	 * @since		1.0
 	 * @return		A custom list item
	 * @param[in] 	groupIndex			The index of the group which the item belongs to
	 * @param[in] 	itemIndex		    The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	const CustomListItem* GetItemAt (int groupIndex, int itemIndex) const;

	/**
	 * Scrolls to the bottom of the %GroupedList control.
	 *
	 * @since	1.0
	 */
	void ScrollToBottom (void);

	/**
	 * Scrolls to the top of the %GroupedList.
	 *
	 * @since	1.0
	 */
	void ScrollToTop (void);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex or @c itemIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ScrollToTop (int groupIndex, int itemIndex);

	/**
	 * Scrolls to the group at the specified index. @n
	 * The specified group is drawn at the top of the %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ScrollToTop (int groupIndex);

	/**
	 * Sets the first index list of scroll by text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	text			The text of the first index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetFastScrollMainIndex(const Osp::Base::String &text);

	/**
	 * Sets the second index list of scroll by text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	text			The text of the second index @n
	 * 								Separate each second index of the first index by ',';.
	 * @param[in] 	indexDigit		The index digit count
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetFastScrollSubIndex(const Osp::Base::String &text, FastScrollIndexDigit indexDigit = SCROLL_INDEX_DIGIT_NUM_1);

	/**
	 * Adds the fast scroll event listener.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 */
	void AddFastScrollEventListener(const Osp::Ui::IFastScrollEventListener &listener);

	/**
	 * Removes the fast scroll event listener.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be removed
	 */
	void RemoveFastScrollEventListener(const Osp::Ui::IFastScrollEventListener &listener);

	/**
	 * Adds the grouped list item event listener.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 */
	void AddGroupedItemEventListener(const Osp::Ui::IGroupedItemEventListener &listener);

	/**
	 * Removes the grouped list item event listener.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be removed
	 */
	void RemoveGroupedItemEventListener(const Osp::Ui::IGroupedItemEventListener &listener);

	/**
	 * Returns the index of the first checked list item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]  groupIndex	    The group index of the item
	 * @param[out]  itemIndex		The item index of the item
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetFirstCheckedItemIndex (int &groupIndex, int &itemIndex) const;

	/**
	 * Sets the checked status of all the items of the specified group with the given value.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   groupIndex	    The group index of the item
	 * @param[in]   check			Set to @c true to check all the items, @n
	 *							    else @c false
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllItemsChecked (int groupIndex, bool check);

	/**
	 * Returns the index of the current bottom drawn list item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]  groupIndex	    The group index of the item
	 * @param[out]  itemIndex		The item index of the item
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetBottomDrawnItemIndex (int &groupIndex, int &itemIndex) const;

	/**
	 * Draws and shows the item of %GroupedList control.
	 *
	 * @since			1.0
 	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *					For more information, see @ref CompGroupedListRefreshItem "here".
	 * @return		An error code
     * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex or @c itemIndex is invalid.
 	 * @exception	E_INVALID_OPERATION	The item has never been drawn before calling this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RefreshItem(int groupIndex, int itemIndex);
	
   /**
     * @page	CompGroupedListRefreshItem	Compatibility for RefreshItem()
     * @section	CompGroupedListRefreshItemIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the specified item is not drawn at least once, calling this method updates the item in a wrong way and returns E_SUCCESS.
     *
     * @section	CompGroupedListRefreshItemResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     * #- If the specified item has never been drawn before calling this method, it does not update the item and returns E_INVALID_OPERATION.
     */

	/**
	 * Draws and shows the group of %GroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RefreshGroup(int groupIndex);

	/**
	 * Sets the position and size of the control. @n
	 * The position is set at (x, y), and the @c width and @c height parameters contain the width and height values of the control,
	 * respectively.
	 *
	 * @since			1.0
	 * @compatibility   This method has compatibility issues with different bada API versions. @n
	 *                  For more information, see @ref CompGroupedListSetBounds "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	x							The x coordinate
	 * @param[in]	y        					The y coordinate
	 * @param[in]	width       				The width
	 * @param[in]	height       				The height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid. @n
	 *											Either @c dim.width or @c dim.height is out of the range as defined by the minimum and maximum size.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 * @see   SetPosition()
	 * @see   SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since			1.0
	 * @compatibility   This method has compatibility issues with different bada API versions. @n
	 *                  For more information, see @ref CompGroupedListSetBounds "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	rect       					The bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 *											Either @c dim.width or @c dim.height is out of the range as defined by the minimum and maximum size.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 * @see   SetPosition()
	 * @see   SetSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * @page	CompGroupedListSetBounds	Compatibility for SetBounds()
	 * @section	CompGroupedListSetBoundsIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the size of this control is less than 300 x 250 on a WVGA screen or 150 x 125 on a WQVGA screen, the fast scroll is not displayed.
	 *
	 * @section	CompGroupedListSetBoundsResolutions	Solutions
	 * The issue mentioned above is resolved in API version 1.2. @n
	 * -# The minimum size of the control is modified to 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen.
	 *
	 */

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility   This method has compatibility issues with different bada API versions. @n
	 *                  For more information, see @ref CompGroupedListSetSize "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	size       					The size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 *											Either @c dim.width or @c dim.height is out of the range as defined by the minimum and maximum size.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 */
	virtual result SetSize (const Osp::Graphics::Dimension &size);

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility   This method has compatibility issues with different bada API versions. @n
	 *                  For more information, see @ref CompGroupedListSetSize "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	width					The width of the control
	 * @param[in]	height					The height of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION     The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *										Either @c dim.width or @c dim.height is out of the range as defined by the minimum and maximum size.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 */
	virtual result SetSize (int width, int height);

	/**
	 * @page	CompGroupedListSetSize	Compatibility for SetSize()
	 *
	 * @section	CompGroupedListSetSizeIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the size of the control is smaller than 300 x 250 on a WVGA screen or 150 x 125 on a WQVGA screen, the fast scroll is not displayed.
	 *
	 * @section	CompGroupedListSetSizeResolutions	Solutions
	 * The issue mentioned above is resolved in API version 1.2.
	 * -# The minimum size of the control is modified to 300 x 250 on a WVGA screen or 150 x 125 on a WQVGA screen.
	 *
	 */

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
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);
	
private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the control.
     * @since       1.0
     * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	virtual result __Draw(void);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The group item format
     * @since         1.0
     */		
	CustomListItemFormat* __groupFormat;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The custom item event
     * @since         1.0
     */		
	Osp::Base::Runtime::IEvent* __pCustomItemEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The custom item event adapter
     * @since         1.0
     */		
	void* __pCustomItemEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item store
     * @since         1.0
     */		
	Osp::Base::Collection::ArrayList __items;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The FastScroll Event 
     * @since         1.0
     */		

	Osp::Base::Runtime::IEvent* __pFastScrollEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The FastScroll 
     * @since         1.0
     */		
	void* __pFastScroll;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The FastScroll Event Adaptor
     * @since         1.0
     */		
	void* __pFastScrollEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The First index of the FastScroll
     * @since         1.0
     */		
	Osp::Base::String __FirstFastScrollIndex;

	friend class GroupedListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class GroupedListEx* __pGroupedListEx;

protected:
	friend class GroupedListImpl;
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
	class GroupedListImpl* GetImpl(void) const;
};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_GROUPEDLIST_H_
