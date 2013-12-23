/* $Change: 994829 $ */
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
 * @file	FUiCtrlSlidableGroupedList.h 
 * @brief	This is the header file for the %SlidableGroupedList class.
 *
 * This header file contains the declarations of the %SlidableGroupedList class and its helper classes.
 */

#ifndef _FUICTRL_SLIDABLEGROUPEDLIST_H_
#define _FUICTRL_SLIDABLEGROUPEDLIST_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlGroupedList.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiISlidableGroupedListEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class		SlidableGroupedList
 * @brief 		This class defines the common behavior of the %SlidableGroupedList control.
 * @deprecated 	This class is deprecated. Instead of using this class, use the %GroupedListView class.
 * @since		1.0
 *
 *
 * The %SlidableGroupedList class represents a list which loads grouped 
 * items on demand and unloads unused grouped items to save memory. Like GroupedList, 
 * the list items of GroupedList consist of groups and items. A group represents grouped 
 * items and is inserted into the first level just as items are inserted into List. Items 
 * which are from CustomListItems are inserted under related groups. So, items are uniquely 
 * identified with two indices: group index and item index.
 * 
 * The operation of %SlidableGroupedList is the same as that of a GroupedList, except 
 * that a %SlidableGroupedList does not hold all items in the memory. Most of the item manipulations 
 * are available when they are loaded, but the check state is maintained for all items 
 * whether they are loaded or not.
 * ISlidableGroupedListEventListener should be implemented so that an application can 
 * be notified when the items need to be loaded as the user scrolls through a list.
 * If an application wants to perform tasks when the state of a list item is changed, 
 * it should implement IGroupedItemEventListener and register it to the slidable 
 * grouped list. It will then receive related events from %SlidableGroupedList.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically 
 * when the %SlidableGroupedList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat 
 * should be deleted by the application.
 * 
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 *
 * @image html GUI_slidablegroupedlist.png
 *
 * This is the simple UI application which uses a %SlidableGroupedList control.
 *
 * @code

// Sample Code for SlidableGroupedListSample.h
#include <FBase.h>
#include <FUi.h>

class SlidableGroupedListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IGroupedItemEventListener,
    public Osp::Ui::ISlidableGroupedListEventListener
{
public:
    SlidableGroupedListSample(void)
	:__pSlidableGroupedList(null)
	,__pCustomListItemFormat(null){}

protected:
    static const int ID_LIST_TEXT  = 101;
    static const int ID_LIST_BITMAP = 102;
    static const int ITEM_COUNT = 100;
    static const int ITEM_HEIGHT = 100;
    static const int ITEM_COUNT_GROUP1 = 20;
    static const int ITEM_COUNT_GROUP2 = 40;
    static const int ITEM_COUNT_GROUP3 = 40;
    static const int ITEM_ID_LIMITS = 1000;

    Osp::Graphics::Bitmap* GetBitmapN(void);
    int GetItemIdFrom(int groupIndex, int itemIndex) const;
    void GetIndexesFromItemId(int& groupIndex, int& itemIndex, int itemId) const;
    Osp::Ui::Controls::CustomListItem* LoadListItem(int itemId);

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);

    virtual void  OnItemStateChanged(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int itemId, int elementId, Osp::Ui::ItemStatus status);
    virtual void  OnItemStateChanged(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int itemId, Osp::Ui::ItemStatus status);

    virtual void OnListPropertyRequested(const Osp::Ui::Control &source){}
    virtual void OnLoadToTopRequested(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int numItems);
    virtual void OnLoadToBottomRequested(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int numItems);
    virtual void OnUnloadItemRequested(const Osp::Ui::Control& source, int groupIndex, int itemIndex);

private:
    Osp::Ui::Controls::SlidableGroupedList* __pSlidableGroupedList;
    Osp::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};

// Sample Code for SlidableGroupedListSample.cpp
#include "SlidableGroupedListSample.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Base::Collection;

// Gets a unique ID for the [groupIndex, itemIndex] pair.
int
SlidableGroupedListSample::GetItemIdFrom(int groupIndex, int itemIndex) const
{
    return ITEM_ID_LIMITS * groupIndex + itemIndex;
}

// Gets the [groupIndex, itemIndex] pair from the unique item ID
void
SlidableGroupedListSample::GetIndexesFromItemId(int& groupIndex, int& itemIndex, int itemId) const
{
    groupIndex = itemId / ITEM_ID_LIMITS;
    itemIndex  = itemId % ITEM_ID_LIMITS;
}

Bitmap*
SlidableGroupedListSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

CustomListItem*
SlidableGroupedListSample::LoadListItem(int itemId)
{
    // Creates Bitmaps
    Bitmap *pBitmapNormal  = GetBitmapN();
    Bitmap *pBitmapFocused = GetBitmapN();

    int groupIndex, itemIndex;
    GetIndexesFromItemId(groupIndex, itemIndex, itemId);

    String itemText;
    itemText.Format(128, L"ITEM %d-%d", groupIndex+1, itemIndex+1);

    CustomListItem* pItem = new CustomListItem();
    pItem->Construct(ITEM_HEIGHT);
    pItem->SetItemFormat(*__pCustomListItemFormat);
    pItem->SetElement(ID_LIST_TEXT, itemText);
    pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

    // Deallocates the Bitmaps
    delete pBitmapNormal;
    delete pBitmapFocused;

    return pItem;
}

result
SlidableGroupedListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a SlidableGroupedList
    __pSlidableGroupedList = new SlidableGroupedList();
    __pSlidableGroupedList->Construct(Rectangle(0, 0, 480, 500), CUSTOM_LIST_STYLE_NORMAL);
    __pSlidableGroupedList->AddGroupedItemEventListener(*this);
    __pSlidableGroupedList->AddSlidableGroupedListEventListener(*this);

    // Creates an item format of the SlidableGroupedList
    __pCustomListItemFormat = new CustomListItemFormat();
    __pCustomListItemFormat->Construct();
    __pCustomListItemFormat->AddElement(ID_LIST_TEXT, Osp::Graphics::Rectangle(10, 25, 200, 80));
    __pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Osp::Graphics::Rectangle(220, 10, 70, 80));

    // Adds Groups
    __pSlidableGroupedList->AddGroup("Group1", null, ITEM_COUNT_GROUP1, ITEM_COUNT_GROUP1 * ITEM_HEIGHT);
    __pSlidableGroupedList->AddGroup("Group2", null, ITEM_COUNT_GROUP2, ITEM_COUNT_GROUP2 * ITEM_HEIGHT);
    __pSlidableGroupedList->AddGroup("Group3", null, ITEM_COUNT_GROUP3, ITEM_COUNT_GROUP3 * ITEM_HEIGHT);

    // Adds the SlidableGroupedList to the Form
    AddControl(*__pSlidableGroupedList);

    // Displays the Form
    Draw();
    Show();

    return r;
}

result
SlidableGroupedListSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    // Deallocates the item format
    delete __pCustomListItemFormat;

    return r;
}

// Implements an IGroupedItemEventListener
void
SlidableGroupedListSample::OnItemStateChanged(const Control &source, int groupIndex, int itemIndex, int itemId, ItemStatus status)
{
    switch (itemId)
    {
    case 1:
        // Todo:
        break;
    default:
        break;
    }
}

void
SlidableGroupedListSample::OnItemStateChanged(const Control &source, int groupIndex, int itemIndex, int itemId, int elementId, ItemStatus status)
{
    switch (itemId)
    {
    case 1:
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

// Implements an ISlidableGroupedListEventListener
void
SlidableGroupedListSample::OnLoadToTopRequested(const Control &source, int groupIndex, int itemIndex, int numItems)
{
	for(int i=0; i< numItems; ++i)
	{
		// Loads items upwards.
		int curItemIndex = itemIndex - i;

		int itemId = GetItemIdFrom(groupIndex, curItemIndex);
		CustomListItem* pItem = LoadListItem(itemId);
		__pSlidableGroupedList->LoadItemToTop(*pItem, itemId);
	}
}

void
SlidableGroupedListSample::OnLoadToBottomRequested (const Control &source, int groupIndex, int itemIndex, int numItems)
{
	for(int i=0; i< numItems; ++i)
	{
		// Loads items downwards.
		int curItemIndex = itemIndex + i;

		int itemId = GetItemIdFrom(groupIndex, curItemIndex);
		CustomListItem* pItem = LoadListItem(itemId);
		__pSlidableGroupedList->LoadItemToBottom(*pItem, itemId);
	}
}

void
SlidableGroupedListSample::OnUnloadItemRequested(const Control& source, int groupIndex, int itemIndex)
{
	// Releases resources of the specified item
	// Todo:
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_	SlidableGroupedList :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(SlidableGroupedList);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	SlidableGroupedList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~SlidableGroupedList(void);

// Operation
	 /**
	  * Initializes this instance of %SlidableGroupedList with the specified parameters.
	  *
	  * @since     1.0
	  * @compatibility      This method has compatibility issues with different bada API versions. @n
	  *                     For more information, see @ref CompSlidableGroupedListConstruct "1.2" and @ref CompSlidableGroupedListConstruct20 "2.0".
	  * @return		An error code
	  * @param[in]	rect				An instance of the Graphics::Rectangle class @n
	  *									This instance represents the x and y coordinates of the top-left corner of the created %SlidableGroupedList along with 
	  *									the width and height.
	  * @param[in]	style				The style of the CustomListItem instances
	  * @param[in]	itemDivider			Set to @c true to display an item divider, @n
	  *									else @c false
	  * @param[in]	fastScroll			Set to @c true to use fast scroll, @n
	  *									else @c false
	  * @exception	E_SUCCESS			The method is successful.
	  * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	  * @exception	E_INVALID_STATE		This instance has already been constructed.
	  * @exception	E_SYSTEM			A system error has occurred.
	  * @remarks	In the bada API versions prior to 2.0, the width and the height of the control must be greater than 0. @n
      *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size. @n
      *				The minimum size of this control is 274 x 148 on a WVGA screen, 180 x 96 on a HVGA screen and 137 x 74 on a WQVGA screen.
      *
	  */
	 result Construct(const Osp::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true, bool fastScroll = false);

	 /**
	  * @page	CompSlidableGroupedListConstruct	Compatibility for Construct()
	  * @section	CompSlidableGroupedListConstructIssues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# If the size of this control is less than 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen, the fast scroll is not displayed.
	  *
	  * @section	CompSlidableGroupedListConstructResolutions	Resolutions
  	  * The issue mentioned above is resolved in bada API version 1.2. @n
	  * The minimum size of this control is modified to 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen.
	  */

	 /**
	 * @page	CompSlidableGroupedListConstruct20	Compatibility for Construct()
	 *
	 * @section	CompSlidableGroupedListConstruct20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than 0. @n
	 *    The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust the 
	 *	  bounds to the minimum size. @n
	 * -# On a WVGA screen, the default minimum size is 300 x 250.
	 *
	 * @section CompSlidableGroupedListConstruct20Resolutions Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control, or greater than the maximum size of the 
	 *    control. @n
	 * -# The width and height of the control can be @c 0, if its minimum width and height is 0. @n
	 * -# On a WVGA screen, the default minimum size is changed to 270 x 144.
	 */

	/**
	* Adds the specified listener instance.
	* The added listener can listen to the events on the context of the given event dispatcher when they are fired.
	*
	* @since		1.0
	* @param[in]	listener	The event listener to be added
	*/
	void AddSlidableGroupedListEventListener (const Osp::Ui::ISlidableGroupedListEventListener& listener);

	/**
	* Removes the specified listener instance.
	* The removed listener cannot listen to the events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener	The event listener to be removed
	*/
	void RemoveSlidableGroupedListEventListener (const Osp::Ui::ISlidableGroupedListEventListener& listener);

	/**
	 * Loads the item to the top of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	item	 		The CustomListItem instance
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result LoadItemToTop(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

  /**
	 * Loads the item to the end of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	item	 		The %CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result LoadItemToBottom(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	 /**
	 * Unloads all the loaded items of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result UnloadAllItems(void);


	/**
	 * Removes all the items in the specified group. @n
	 * The group is not removed.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveAllItemsAt(int groupIndex);
	
	/**
	 * Removes all the items in the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The removed list items are deleted from the memory.
	 * @remarks		After the items have been removed, the ISlidableGroupedListEventListener::OnListPropertyRequested() method is called.
	 * @see			ISlidableGroupedListEventListener
	 */
	result RemoveAllItems();

	/**
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener		The event listener to be removed
	 */
	void RemoveFastScrollEventListener(const Osp::Ui::IFastScrollEventListener &listener);

	/**
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 		The event listener to be removed
	 */
	void RemoveGroupedItemEventListener(const Osp::Ui::IGroupedItemEventListener &listener);


	/**
	 * Scrolls to the bottom of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 */
	void ScrollToBottom (void);

	/**
	 * Scrolls to the top of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 */
	void ScrollToTop (void);

	/**
	* Scrolls to the item at the specified index. @n
	* The specified item is drawn at the top of the %SlidableGroupedList control.
	*
	* @since		1.0
	* @return		An error code
    * @param[in]	groupIndex		The group index
	* @param[in]	itemIndex		The item index
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_SYSTEM	    A system error has occurred.
	*/
	result ScrollToTop (int groupIndex, int itemIndex);

	/**
	* Scrolls to the group at the specified index. @n
	* The specified group is drawn at the top of the %SlidableGroupedList control.
	*
	* @since		1.0
	* @return		An error code
    * @param[in]	groupIndex		The group index
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified input parameter is invalid.
	* @exception	E_SYSTEM	    A system error has occurred.
	*/
	result ScrollToTop (int groupIndex);


	/**
	 * Sets all the items at the specified group index.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableGroupedListSetAllItemsChecked "here".
	 * @param[in]	groupIndex		The group index
	 * @param[in]	check			Set to @c true to check the item, @n 
     *								else @c false to uncheck
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 */
	result SetAllItemsChecked (int groupIndex, bool check);

	/**
	 * @page   CompSlidableGroupedListSetAllItemsChecked	Compatibility for SetAllItemsChecked()
	 * @section	CompSlidableGroupedListSetAllItemsCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When a %SlidableGroupedList is configured for multiple selection, this method generates the E_SYSTEM exception.
	 *
	 * @section CompSlidableGroupedListSetAllItemsCheckedResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */

	/**
     * Sets the contents of the group of the %SlidableGroupedList control at the specified group index.
	 *
	 * @since		1.0
     * @return		An error code
     * @param[in]	groupIndex			The group index
	 * @param[in] 	text				The string of the group to be appended
     * @param[in] 	pBackgroundBitmap	The bitmap of the group
	 * @param[in] 	groupId				The group ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
     */
	result SetGroupAt(int groupIndex, const Osp::Base::String& text, const Osp::Graphics::Bitmap* pBackgroundBitmap, int groupId=LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Sets the specified item as checked or unchecked.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableGroupedListSetItemChecked "here".
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index of the item to be checked
	 * @param[in] 	itemIndex		The index of the item to be checked
	 * @param[in] 	check			Set to @c true to check the item, @n
	 * 								else @c false to uncheck it
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.	 
	 */	
	result SetItemChecked(int groupIndex, int itemIndex, bool check);
	
	/**
	 * @page   CompSlidableGroupedListSetItemChecked	Compatibility for SetItemChecked()
	 *
	 * @section	CompSlidableGroupedListSetItemCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the specified item is disabled, the checked status of the item is not changed.
	 *
	 * @section	CompSlidableGroupedListSetItemCheckedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */


	/**
	 * Enables the specified item. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex		The group index of the item to be checked
	 * @param[in]	itemIndex		The index of the item to be checked
	 * @param[in]	enable			Set to @c true to enable the item, @n
	 * 								else @c false to disable it
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */	
	result SetLoadedItemEnabled(int groupIndex, int itemIndex, bool enable);


	/**
	 * Removes all the checked items from the group. 
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     				For more information, see @ref CompSlidableGroupedListRemoveAllCheckedItemsAt "here".
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @param[in] 	height			The estimated/real height of the items of the group
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */	
	result RemoveAllCheckedItemsAt (int groupIndex, int height);
	
	 /**
	  * @page	CompSlidableGroupedListRemoveAllCheckedItemsAt	Compatibility for RemoveAllCheckedItemsAt()
	  *
	  * @section	CompSlidableGroupedListRemoveAllCheckedItemsAtIssues	Compatibility Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# The RemoveAllCheckedItemAt() method not only removes all the checked items from the specified group, but also removes all the checked items 
	  *    present in other groups.
	  *
	  * @section	CompSlidableGroupedListRemoveAllCheckedItemsAtResolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 1.2. @n
	  * The RemoveAllCheckedItemAt() method is called to remove only the checked items from the specified group.
	  */


	/**
	 * Removes the specified item from the group. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex			The group index
	 * @param[in] 	itemIndex			The item index
	 * @param[in] 	height				The estimated/real height of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks   	The removed list item is deleted from the memory.
	 */	
	result RemoveItemAt (int groupIndex, int itemIndex, int height);


	/**
	 * Removes the group of the %SlidableGroupedList control at the group index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	groupIndex		The group index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed.
	 * @remarks   	The removed list items are deleted from the memory.
	 */
	result RemoveGroupAt(int groupIndex);


	/**
	 * Gets the item at the specified indexes if the item is currently loaded.
	 *
	 * @since		1.0
	 * @return		A pointer to the loaded item, @n
	 *				else @c null if the specified item is not currently loaded
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 */
	const CustomListItem * GetLoadedItemAt (int groupIndex, int itemIndex) const;
	

	/**
	 * Gets the item ID at the specified index if the item is currently loaded.
	 *
	 * @since		1.0
	 * @return		The item ID, @n
	 *				else LIST_ITEM_UNSPECIFIED_ID if the specified item is not currently loaded
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 */
	int GetLoadedItemIdAt (int groupIndex, int itemIndex) const;


	/**
	 * Gets the item index from the specified item ID.
	 *
	 * @since		1.0
	 * @return		An error code, @n
	 *				else @c -1 if the specified item is not currently loaded
	 * @param[in]	itemId			The item ID
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetLoadedItemIndexFromItemId (int itemId, int& groupIndex, int& itemIndex) const;

	/**
	 * Removes all the checked items of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	height			The height of the item to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list items are deleted from the memory.
	 * @remarks	  	This method can only be used when the style of the list allows multiple selections.
	 */
	result RemoveAllCheckedItems(int height);

	/**
	 * Gets the index of the first loaded item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetFirstLoadedItemIndex (int& groupIndex, int& itemIndex) const;
	
	/**
	 * Gets the index of the last loaded item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetLastLoadedItemIndex (int& groupIndex, int& itemIndex) const;

	/**
	 * Sets the first index list of the scroll by text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text			The text of the first index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetFastScrollMainIndex(const Osp::Base::String &text);


	/**
	 * Sets the second index list of the scroll by text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	text			The text of the second index @n
	 * 								Each second index of the first index has to be separated by ','; .
	 * @param[in] 	indexDigit		The index digit count
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The sub-index of fast scroll does not support SCROLL_INDEX_DIGIT_NUM_2. Therefore, when SCROLL_INDEX_DIGIT_NUM_2 is passed to 
	 *				@c indexDigit, this method returns E_SYSTEM.
	 */
	result SetFastScrollSubIndex(const Osp::Base::String &text, FastScrollIndexDigit indexDigit = SCROLL_INDEX_DIGIT_NUM_1);

	/**
	 * Sets the background color of this control.
	 *
	 * @since 		1.1
	 * @param[in]	color	The background color
	 */
	void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Sets the text of the empty list. 
	 *
	 * @since		1.0
	 * @param[in] 	text	The text of the empty list
	 */	
	void SetTextOfEmptyList (const Osp::Base::String &text);

	/**
	 * Sets the color of the text to be displayed in the absence of a %SlidableGroupedList item.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompSlidableGroupedListSetTextColorOfEmptyList "here".
	 *
	 * @param[in]	color	The color of the text to be displayed
	 */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

    /**
     * @page	CompSlidableGroupedListSetTextColorOfEmptyList	Compatibility for SetTextColorOfEmptyList()
     *
     * @section	CompSlidableGroupedListSetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method ignores the alpha value of the specified color.
     *
     * @section	CompSlidableGroupedListSetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */


	/**
	 * Gets the color of the text to be displayed in the absence of a %SlidableGroupedList item.
	 *
	 * @since   1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompSlidableGroupedListGetTextColorOfEmptyList "here".
	 *
	 * @return	The color of the text to be displayed
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;

    /**
     * @page	CompSlidableGroupedListGetTextColorOfEmptyList	Compatibility for GetTextColorOfEmptyList()
     *
     * @section	CompSlidableGroupedListGetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color, that is converted from the color specified by SetTextColorOfEmptyList(), omitting the alpha value.
     *
     * @section	CompSlidableGroupedListGetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
     * The method returns a 32-bit color.
     */


	/**
	 * Sets the contents of the item in the specified group.
     *
     * @since		1.0
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableGroupedListSetItemAt "here".
     * @return		An error code
     * @param[in] 	groupIndex		The group index
     * @param[in]	itemIndex	    The %CustomListItem object
	 * @param[in]	item	        The item
	 * @param[in]	itemId		    The item ID
     * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
     * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		Do not add, insert, or set an item, that already belongs to %SlidableGroupedList.
     */
    result SetItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);
    
    /**
	 * @page	CompSlidableGroupedListSetItemAt	Compatibility for SetItemAt()
	 * @section	CompSlidableGroupedListSetItemAtIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the given item is set at the specified position by this method, the check state of the item becomes checked by default.
	 *    But the check state should be maintained the same as the previous state. 
	 *
	 * @section	CompSlidableGroupedListSetItemAtResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 *
	 * @par When working with bada API versions prior to 1.2:
	 * To maintain the previous check state, keep the state of the item at the specified index and set it again after calling this method.
	 *
	 */

  	/**
	 * Adds the specified listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddFastScrollEventListener (const Osp::Ui::IFastScrollEventListener &listener);

	/**
	 * Adds the specified group to the %SlidableGroupedList control.
	 *
	 * @since		1.0
 	 * @return		An error code
	 * @param[in] 	text					The string of the group to be appended
     * @param[in] 	pBackgroundBitmap		The background bitmap of the group
     * @param[in] 	itemCount				The number of items of the group
     * @param[in] 	groupHeight				The total height of the items of the group
	 * @param[in] 	groupId					The group ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result AddGroup (const Osp::Base::String &text, const Osp::Graphics::Bitmap *pBackgroundBitmap, int itemCount, int groupHeight, int groupId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Adds the specified listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddGroupedItemEventListener (const Osp::Ui::IGroupedItemEventListener &listener);


	/**
	 * Adds the item to the specified group.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableGroupedListAddItem "here".
	 *
 	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	item			The CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The added item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to %SlidableGroupedList.
	 */
	result AddItem(int groupIndex, const CustomListItem &item, int itemId=LIST_ITEM_UNSPECIFIED_ID);
	
	/**
	 * @page	CompSlidableGroupedListAddItem	Compatibility for AddItem()
	 *
	 * @section	CompSlidableGroupedListAddItemIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n 
	 * -# The specified item is added even if this method returns an exception.
	 *
	 * @section	CompSlidableGroupedListAddItemResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */


	/**
	 * Gets the index of the current bottom drawn item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out] 	groupIndex		The group index
	 * @param[out] 	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetBottomDrawnItemIndex (int &groupIndex, int &itemIndex) const;


	/**
	 * Gets the index of the first checked list item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetFirstCheckedItemIndex (int &groupIndex, int &itemIndex) const;


	/**
	 * Gets the group ID from the specified group index.
	 *
	 * @since		1.0
	 * @return		The group ID
	 * @param[in]	groupIndex		The group index	
	 */
	int GetGroupIdAt (int groupIndex) const;


	/**
	 * Gets the group index from the specified group ID.
	 *
	 * @since		1.0
	 * @return		The group index
	 * @param[in]	groupId		The group ID
	 */
	int GetGroupIndexFromGroupId (int groupId) const;


	/**
	 * Gets the index of the last checked item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]	groupIndex		The group index
	 * @param[out]	itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result GetLastCheckedItemIndex (int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the next checked item after the specified item.
	 *
	 * @since			1.0
	 * @return			An error code
	 * @param[in,out]	groupIndex		The group index
	 * @param[in,out]	itemIndex		The item index
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception	    E_SYSTEM		A system error has occurred.
	 */
	result GetNextCheckedItemIndexAfter (int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the current top drawn item.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]  groupIndex		The group index
	 * @param[out]  itemIndex		The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 */
	result GetTopDrawnItemIndex (int &groupIndex, int &itemIndex) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   x				The x position of the point
	 * @param[in]   y				The y position of the point
	 * @param[out]	groupIndex		The index of the group, that the item belongs to
	 * @param[out]	itemIndex		The index of the item 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred. @n
	 *								There is no item at the specified position.
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   position    	The position of the point
	 * @param[out]	groupIndex  	The index of the group, that the item belongs to
	 * @param[out]	itemIndex   	The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred. @n
	 *								There is no item at the specified position.
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& groupIndex, int& itemIndex) const;

	/**
	 * Inserts the group at the specified group index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in] 	text				The string of the group to be appended
     * @param[in] 	pBackgroundBitmap	The background bitmap of the group
	 * @param[in] 	itemCount			The count of all the items in the group
     * @param[in] 	groupHeight			The total height of all the items in the group
	 * @param[in] 	groupId				The group ID
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_ARG	    A specified input parameter is invalid.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 */
	result InsertGroupAt(int groupIndex, const Osp::Base::String &text, const Osp::Graphics::Bitmap *pBackgroundBitmap, int itemCount, int groupHeight, int groupId=LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Checks whether the item at the specified index is checked. 
	 *
	 * @since		1.0
	 * @return		@c true if the item is checked, @n
	 *	 			else @c false
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 *
	 * @remarks 	This method can only be used when the style of the list allows selection.
	 */	
	bool IsItemChecked (int groupIndex, int itemIndex) const;
	
	/**
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @since		1.0
	 * @return  	@c true if the item is enabled, @n
	 * 				else @c false
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 */	
	bool IsLoadedItemEnabled (int groupIndex, int itemIndex) const;


	/**
	 * Checks whether the item at the specified index is currently loaded to the slidable list.
	 *
	 * @since		1.0
	 * @return  	@c true if the item is loaded, @n 
	 *				else @c false
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 */	
	bool IsItemLoaded  (int groupIndex, int itemIndex) const;


	/**
	 * Removes all the groups of the %SlidableGroupedList control.
	 *
	 * @since			1.0
	 * @compatibility 	This class has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     				For more information, see @ref CompSlidableGroupedListRemoveAllGroups "here".
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		When the specified group is removed, all the items in the group are also removed.
	 * @remarks		The removed list items are deleted from the memory.
	 * @remarks		After the items have been removed, the ISlidableGroupedListEventListener::OnListPropertyRequested() method is called.
	 */
	result RemoveAllGroups(void);

	  /**
	  * @page	CompSlidableGroupedListRemoveAllGroups	Compatibility for RemoveAllGroups()
	  *
	  * @section	CompSlidableGroupedListRemoveAllGroupsIssues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# After all the items are removed, the OnListPropertyRequest() callback method is not called.
	  *
	  * @section CompSlidableGroupedListRemoveAllGroupsResolutions Resolutions
	  * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	  */



	/**
	 * Gets the count of all the groups of the %SlidableGroupedList control.
	 *
	 * @since		1.0
	 * @return		The count of all the groups
	 */
	int	GetGroupCount(void) const;

	/**
	 * Inserts the item to the specified group and item indices.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @param[in]	item	 		The CustomListItem object
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item, that already belongs to %SlidableGroupedList.
	 */
	result InsertItemAt(int groupIndex, int itemIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);


	/**
	 * Gets the count of all the items in the specified group.
	 *
	 * @since		1.0
	 * @return		The count of all the items in the specified group
	 * @param[in]	groupIndex		The group index
	 */
	int	GetItemCountAt(int groupIndex) const;

	/**
	 * Draws and shows the specified item of %SlidableGroupedList.
	 *
	 * @since			1.0
  	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *					For more information, see @ref CompSlidableGroupedListRefreshItem "here".
	 * @return		An error code
     * @param[in]	groupIndex				The group index
	 * @param[in]	itemIndex				The item index
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c groupIndex or @c itemIndex is invalid.
 	 * @exception	E_INVALID_OPERATION 	The item has never been drawn before calling this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RefreshItem(int groupIndex, int itemIndex);
	
   /**
     * @page	CompSlidableGroupedListRefreshItem	Compatibility for RefreshItem()
     * @section	CompSlidableGroupedListRefreshItemIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the specified item is not drawn at least once, calling this method updates the item in a wrong way and returns E_SUCCESS.
     *
     * @section	CompSlidableGroupedListRefreshItemResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     * If the specified item has never been drawn before calling this method, it does not update the item and returns E_INVALID_OPERATION.
     */

	/**
	 * Draws and shows the specified group of %SlidableGroupedList.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	groupIndex			The group index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c groupIndex is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RefreshGroup(int groupIndex);

	/**
	 * Sets the position and size of the control. @n
	 * The relative position is set to (x, y), the width is set to @c width, and the height is set to @c height.
	 *
	 * @since			1.0
	 * @compatibility   This method has compatibility issues with different bada API versions. @n
	 *                  For more information, see @ref CompGroupedListSetBounds "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	x							The x coordinate
	 * @param[in]	y							The y coordinate
	 * @param[in]	width						The width
	 * @param[in]	height						The height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid. @n
	 *											Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
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
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompGroupedListSetBounds "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	rect						The bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION			The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid. @n
	 *											Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
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
	 * -# If the size of this control is less than 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen, the fast scroll is not displayed.
	 *
	 * @section	CompGroupedListSetBoundsResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2. @n
	 * The minimum size of the control is modified to 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen.
	 */

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompGroupedListSetSize "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	size						The size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid. @n
	 *											Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
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
	 * @since				1.0
	 * @compatibility		This method has compatibility issues with different bada API versions. @n
	 *						For more information, see @ref CompGroupedListSetSize "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	width						The width of the control
	 * @param[in]	height						The height of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid. @n
	 *											Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 */
	virtual result SetSize (int width, int height);

	/**
	 * @page	CompGroupedListSetSize	Compatibility for SetSize()
	 * @section	CompGroupedListSetSizeIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the size of the control is smaller than 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen, the fast scroll is not displayed.
	 *
	 * @section	CompGroupedListSetSizeResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2. @n
	 * The minimum size of the control is modified to 300 x 250 on a WVGA screen, or 150 x 125 on a WQVGA screen.
	 */

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
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM  A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
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
	 * The ItemEvent
     * @since         1.0
     */		
	Osp::Base::Runtime::IEvent* __pCustomItemEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The CustomItemEventAdaptor.
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
	 * The ItemEvent
     * @since         1.0
     */		
	Osp::Base::Runtime::IEvent* __pSlidableEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The __groupList
     * @since         1.0
     */		
	Osp::Base::Collection::ArrayList __groupItems;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The __ListExAppCallback
     * @since         1.0
     */		
	void* __pListCallback;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The ItemEvent
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

	friend class SlidableGroupedListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class SlidableGroupedListEx* __pSlidableGroupedListEx;

protected:
	friend class SlidableGroupedListImpl;
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
	class SlidableGroupedListImpl* GetImpl(void) const;

};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_SLIDABLEGROUPEDLIST_H_
