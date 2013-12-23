/* $Change: 733140 $ */
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
 * @file	FUiCtrlGroupedListView.h
 * @brief	This is the header file for the %GroupedListView class.
 *
 * This header file contains the declarations of the %GroupedListView class and its helper classes.
 */

#ifndef _FUICTRL_GROUPED_LIST_VIEW_H_
#define _FUICTRL_GROUPED_LIST_VIEW_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlGroupedListViewEnum.h"
#include "FUiCtrlIGroupedListViewItemProvider.h"
#include "FUiCtrlIGroupedListViewItemEventListener.h"
#include "FUiCtrlIFastScrollListener.h"
#include "FUiCtrlIScrollEventListener.h"
#include "FUiIUiLinkEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	GroupedListView
 * @brief 	This class defines the common behavior of a %GroupedListView control.
 * @since	2.0
 *
 * The %GroupedListView class displays a list of grouped items in a list. The items in a GroupedList control consist of groups and
 * items. A group represents the grouped items and is placed at the first level. Each group consists of simple or custom items.
 * Therefore, items are uniquely identified with two indexes: group index and item index.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 * The following example demonstrates how to use the %GroupedListView class.
 *
 *
 * @code

//Sample Code for GroupedListViewSample.h
#include <FGraphics.h>
#include <FUi.h>
#include <FUiControl.h>
#include <FBase.h>

class GroupedListViewSample :
	public Osp::Ui::Controls::Form,
    public Osp::Ui::Controls::IGroupedListViewItemEventListener,
 	public Osp::Ui::Controls::IGroupedListViewItemProvider
{
public:
	void GetBitmap(void);
	void CreateGroupedListView(void);

protected:
	static const int ID_FORMAT_STRING = 100;
	static const int ID_FORMAT_BITMAP = 101;
	static const int ID_CONTEXT_ITEM_1 = 102;
	static const int ID_CONTEXT_ITEM_2 = 103;
	Osp::Ui::Controls::GroupedListView* __pList;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IGroupedListViewItemEventListener
	virtual void OnGroupedListViewContextItemStateChanged(Osp::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
	virtual void OnGroupedListViewItemStateChanged(Osp::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Osp::Ui::Controls::ListItemStatus state);
	virtual void OnGroupedListViewItemSwept(Osp::Ui::Controls::GroupedListView &listView, int groupIndex,  int itemIndex, Osp::Ui::Controls::SweepDirection direction);
	
	// IGroupedListViewItemProvider
	virtual int GetGroupCount(void);
	virtual int GetItemCount(int groupIndex);
	virtual Osp::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, int itemWidth);
	virtual bool DeleteGroupItem(int groupIndex, Osp::Ui::Controls::GroupItem* pItem, int itemWidth);
	virtual Osp::Ui::Controls::ListItemBase* CreateItem(int groupIndex, int itemIndex, int itemWidth);
	virtual bool DeleteItem(int groupIndex, int itemIndex, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth);
	
};


//Sample Code for GroupedListViewSample.cpp


#include "GroupedListViewSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Base;
using namespace Osp::Media;

result
GroupedListViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;
	GetBitmap();
	CreateGroupedListView();
	return r;
}

result
GroupedListViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;
	// Deallocates bitmaps
	return r;
}

void
GroupedListViewSample::GetBitmap(void)
{
  // The GetBitmap() method should be implemented.
}

void
GroupedListViewSample::CreateGroupedListView(void)
{
	__pList = new GroupedListView();
	__pList->Construct(Rectangle(0, 0, 480, GetClientAreaBounds().height), true, true);
	__pList->SetItemProvider(*this);
	__pList->AddGroupedListViewItemEventListener(*this);
	AddControl(*__pList);
}

void
GroupedListViewSample::OnGroupedListViewItemStateChanged(Osp::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Osp::Ui::Controls::ListItemStatus state)
{
    switch (elementId)
    {
    case ID_FORMAT_STRING:
        // Todo:
        break;
    case ID_FORMAT_BITMAP:
        // Todo:
        break;
    default:
        break;
    }
}

void
GroupedListViewSample::OnGroupedListViewContextItemStateChanged(Osp::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{
    switch (elementId)
    {
    case ID_CONTEXT_ITEM_1:
        // Todo:
        break;
    case ID_CONTEXT_ITEM_2:
        // Todo:
        break;
    default:
        break;
    }
}

void
GroupedListViewSample::OnGroupedListViewItemSwept(Osp::Ui::Controls::GroupedListView &listView, int groupIndex,  int itemIndex, Osp::Ui::Controls::SweepDirection direction)
{
}

int
GroupedListViewSample::GetGroupCount(void)
{
	return 3;
}

int
GroupedListViewSample::GetItemCount(int groupIndex)
{
	int itemCount = 0;
	switch(groupIndex)
	{
	case 0:
		itemCount = 7;
		break;
	case 1:
		itemCount = 5;
		break;
	case 2:
		itemCount = 3;
		break;
	default:
		break;
	}
	return itemCount;
}

Osp::Ui::Controls::GroupItem*
GroupedListViewSample::CreateGroupItem(int groupIndex, int itemWidth)
{
	GroupItem* pItem = new GroupItem();
	pItem->Construct(Dimension(itemWidth, 32));
	String text("Group");
	text.Append(groupIndex+1);

	pItem->SetElement(text, null);
	return pItem;
}

Osp::Ui::Controls::ListItemBase*
GroupedListViewSample::CreateItem(int groupIndex, int itemIndex, int itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new CustomItem();
	pItem->Construct(Osp::Graphics::Dimension(itemWidth, 100), style);

	switch (itemIndex % 4)
	{
	case 0:
		style = LIST_ANNEX_STYLE_NORMAL;
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"HOME", true);
		break;
	case 1:
		style = LIST_ANNEX_STYLE_MARK;
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Msg", true);
		break;
	case 2:
		style = LIST_ANNEX_STYLE_ON_OFF;
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Alarm", true);
		break;
	case 3:
		style = LIST_ANNEX_STYLE_MORE;
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"CALL", true);
		break;
	default:
		break;
	}
	ListContextItem* pItemContext = new ListContextItem();
	pItemContext->Construct();
	pItemContext->AddElement(ID_CONTEXT_ITEM_1, "Test1");
	pItemContext->AddElement(ID_CONTEXT_ITEM_2, "Test2");
	pItem->SetContextItem(pItemContext);

	return pItem;
}

bool
GroupedListViewSample::DeleteItem(int groupIndex, int itemIndex, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

bool
GroupedListViewSample::DeleteGroupItem(int groupIndex, Osp::Ui::Controls::GroupItem* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}
 * @endcode
 *
 */

class _EXPORT_CONTROLS_	GroupedListView :
	public Osp::Ui::Control
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	GroupedListView(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~GroupedListView(void);

	/**
	 * Initializes this instance of %GroupedListView with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return    	An error code
	 *
	 * @param[in] 	rect				An instance of the Graphics::Rectangle class @n
	 *                              	This instance represents the X and Y coordinates of the top-left corner of the created 	
	 *									%GroupedListView control along with the width and height.
	 * @param[in] 	style				The style of the %GroupedListView control
	 * @param[in] 	itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in] 	fastScroll			Set to @c true to use the fast scroll, @n
	 *									else @c false
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid. @n 
	 *									Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception 	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception 	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks   	For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 *
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, GroupedListViewStyle style, bool itemDivider = true, bool fastScroll = false);

    /**
     * Sets the item provider that creates and deletes items from the list.
     *
     * @since		2.0
     *
     * @return		An error code
     * @param[in]	provider			The item provider to create and delete items
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remark							If an item provider is not set for the list, the list does not work. @n
     *									A provider should be allocated on a heap memory.
     */
    result SetItemProvider(const IGroupedListViewItemProvider& provider);

	/**
	 * Adds an IGroupedListViewItemEventListener instance that listens to the state changes of the list view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddGroupedListViewItemEventListener(const IGroupedListViewItemEventListener &listener);

	/**
	 * Removes an IGroupedListViewItemEventListener instance that listens to the state changes of the list view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveGroupedListViewItemEventListener(const IGroupedListViewItemEventListener &listener);

	/**
	 * Adds an IFastScrollListener instance that listens to the state changes of a fast scroll. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddFastScrollListener (const IFastScrollListener &listener);

	/**
	 * Removes an IFastScrollListener instance that listens to the state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveFastScrollListener(const IFastScrollListener &listener);

	/**
	 * Adds an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 *
	 * @see       IScrollEventListener::OnScrollEndReached()
	 * @see       RemoveScrollEventListener()
	 */
	void AddScrollEventListener (const IScrollEventListener &listener);

	/**
	 * Removes an IScrollEventListener instance that listens to the state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 *
	 * @see       IScrollEventListener::OnScrollEndReached()
	 * @see       AddScrollEventListener()
	 */
	void RemoveScrollEventListener(const IScrollEventListener &listener);
	
	/**
	 * Adds a link event listener.
	 *
	 * @since     	2.0
	 * @param[in]	listener	The event listener to be added
	 * @remarks		The added listener is notified when a link is selected by the user.
	 *
	 * @see         RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 *
	 * @see			AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

	/**
	 * Enables or disables the sweep event.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enable            	Set to @c true to enable the item sweep, @n
	 *									else @c false
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result SetSweepEnabled(bool enable);

	/**
	 * Sets the index list of the fast scroll.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text				The text of the index
	 * @param[in]	useSearchIcon		Set to @c true to display the magnifying icon, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetFastScrollIndex(const Osp::Base::String &text, bool useSearchIcon);

	/**
	 * Gets the group and item indexes of the top item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	groupIndex       	The group index
	 * @param[out]	itemIndex        	The item index
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
    result GetTopDrawnItemIndex (int &groupIndex, int &itemIndex) const;

	/**
	 * Gets the group and item indexes of the bottom item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	groupIndex       The group index
	 * @param[out]	itemIndex        The item index
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_INVALID_STATE  This instance is in an invalid state.
	 * @exception	E_SYSTEM         A system error has occurred.
	 */
	result GetBottomDrawnItemIndex (int &groupIndex, int &itemIndex) const;


	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %GroupedListView control.
	 *
	 * @since	  2.0
	 *
	 * @return    An error code
     * @param[in] groupIndex        The group index
	 * @param[in] itemIndex         The item index
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result ScrollToItem(int groupIndex, int itemIndex);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
   	 * @param[in] groupIndex        The group index
	 * @param[in] itemIndex         The item index
	 * @param[in] itemAlignment		The alignment how the item is placed
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result ScrollToItem(int groupIndex, int itemIndex, ListScrollItemAlignment itemAlignment);

	/**
	 * Checks or unchecks the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return    	An error code
	 * @param[in]	groupIndex				The group index of the item to check
	 * @param[in]	itemIndex				The index of the item to check
	 * @param[in]	check					Set to @c true to select the item, @n
	 *										else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The item is disabled.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remark		This method works only when the annex style of the item allows selection.
	 */
	result SetItemChecked(int groupIndex, int itemIndex, bool check);

	/**
	 * Checks whether the item at the specified index is selected.
	 *
	 * @since			2.0
	 *
	 * @return		@c true if the item is selected, @n
	 *				else @c false
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 * @remark		This method returns @c false, if the annex style of the item does not allow selection.
	 */
	bool IsItemChecked (int groupIndex, int itemIndex) const;

    /**
	 * Enables or disables the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @param[in]	enable				Set to @c true to enable the specified item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks   This method can only be used when the annex style of the list allows selection.
	 */
	result SetItemEnabled(int groupIndex, int itemIndex, bool enable);

	/**
	 * Checks whether the item at the specified index is enabled or disabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]	groupIndex		The group index
	 * @param[in]	itemIndex		The item index
	 */
	bool IsItemEnabled(int groupIndex, int itemIndex) const;
	
	/**
	 * Counts the total number of groups.
	 *
	 * @since	2.0
	 * @return	The total number of groups
	 */
	int GetGroupCount(void) const;

	/**
	 * Counts all the items of the specified group.
	 *
	 * @since	2.0
	 * @return	The total number of items in the specified group
	 *
	 * @param[in]	groupIndex	The group index
	 */
	int GetItemCountAt(int groupIndex) const;

	/**
	 * Shows the description text of the specified item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index of the item
	 * @param[in]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		The description text is not set.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks   If no description text is set for the item at the specified index, it is not displayed.
	 *
	 */
	result ShowItemDescriptionText(int groupIndex, int itemIndex);

	/**
	 * Hides the description text of the specified item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index of the item
	 * @param[in]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		The description text is not set.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result HideItemDescriptionText(int groupIndex, int itemIndex);

	/**
	 * Updates the specified item. @n
	 * For instance, LIST_REFRESH_TYPE_ITEM_ADD is used when a new item needs to be added and LIST_REFRESH_TYPE_ITEM_REMOVE is used when an item is deleted from the 
	 * list. Moreover, LIST_REFRESH_TYPE_ITEM_MODIFY is used when the content of an existing item has changed and it needs to be updated. @n
	 * Note that calling this method with LIST_REFRESH_TYPE_ITEM_MODIFY invokes item provider's DeleteItem() and CreateItem() for the given index in sequence.
	 *
	 * @since	 2.0
	 *
	 * @return		An error code
	 * @param[in]	groupIndex			The group index
	 * @param[in]	itemIndex			The item index
	 * @param[in]	type 				The item to be added, removed, or modified
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM 			A system error has occurred.
	 *
	 * @remark	If the specified itemIndex is @c -1, then the method is applied to the group item with the given index. @n
	 *			Note that if LIST_REFRESH_TYPE_ITEM_REMOVE option is used to a group item, all the items in the group (including the group item itself) are 
	 *			removed from the list.
	 * @remark	This method internally calls Draw() and Show(), so you do not need to call them to update the screen.
	 */
	result RefreshList(int groupIndex, int itemIndex, ListRefreshType type);

	/**
	 * Updates all the items of a list.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remark	This method clears all the items in the list and invokes the methods of the item provider again to update the list.
	 */
	result UpdateList(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since			 2.0
	 *
	 * @return		An error code
	 * @param[in]	x					The X position of the item
	 * @param[in]	y					The Y position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred, or @n
	 *									there is no item at the specified position.
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position			The position of the item
	 * @param[out]	groupIndex			The index of the group that the item belongs to
	 * @param[out]	itemIndex			The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred, or @n
	 *									there is no item at the specified position.
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& groupIndex, int& itemIndex) const;
	
	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 *
	 * @param[in]  x                 The X position of the item
	 * @param[in]  y                 The Y position of the item
	 * @param[out] groupIndex        The index of the group that the item belongs to
	 * @param[out] itemIndex         The index of the item
	 * @param[out] elementId         The ID of the element
	 *
	 * @exception  E_SUCCESS         The method is successful.
	 * @exception  E_INVALID_STATE   This instance is in an invalid state.
	 * @exception  E_SYSTEM          A system error has occurred, or @n
	 *								 there is no item at the specified position.
	 * @remarks    @c groupIndex and @c itemIndex are -1 when there is no list item at the specified position.
	 * @remarks    @c elementId is -1 when there is no element at the specified position
	 */
	result GetItemIndexFromPosition(int x, int y, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 *
	 * @param[in]  position          The position of the point
	 * @param[out] groupIndex        The index of the group that the item belongs to
	 * @param[out] itemIndex         The index of the item
	 * @param[out] elementId         The ID of the element
	 *
	 * @exception  E_SUCCESS         The method is successful.
	 * @exception  E_INVALID_STATE   This instance is in an invalid state.
	 * @exception  E_SYSTEM          A system error has occurred, or @n
	 *								 there is no item at the specified position.
	 * @remarks    @c groupIndex and @c itemIndex are -1 when there is no list item at the specified position.
	 * @remarks    @c elementId is -1 when there is no element at the specified position
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& groupIndex, int& itemIndex, int& elementId) const;

	/**
	 * Sets the color of a section.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color				The section color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (this control cannot be displayed).
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks   This method works only when the style of the %GroupedListView control is GROUPED_LIST_VIEW_STYLE_SECTION. @n
	 *            If the device does not support the 32-bit color space, the method sets the alpha value of the specified @c color to @c 255.
	 */
	result SetSectionColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the color of a section.
	 *
	 * @since	2.0
	 * @return	The section color, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetSectionColor(void) const;

	/**
	 * Sets the color of a division line between items.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color				The division line color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 */
	result SetItemDividerColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since     2.0
	 * @return    The color of a division line, @n
	 *			  else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since     2.0
	 * @return    An error code
	 *
	 * @param[in]	color    			The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 * @remarks	If the device does not support the 32-bit color space, the method sets the alpha value of the specified @c color to @c 255. @n
	 *			The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, 
	 *			only the bitmap image is displayed.
	 */
	result SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of this control.
	 *
	 * @since		2.0
	 * @return		The background color, @n
	 *				else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the bitmap of the empty list.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	pBitmap				The bitmap for the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	 result SetBitmapOfEmptyList(const Osp::Graphics::Bitmap *pBitmap);

	/**
	 * Sets the text of the empty list.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text				The text for the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextOfEmptyList(const Osp::Base::String &text);

	/**
	 * Gets the text to display when there is no item in a list.
	 *
	 * @since		2.0
	 * @return		The text to be displayed, @n
	 *				else an empty string when the instance is invalid
	 */
	Osp::Base::String GetTextOfEmptyList(void) const;

	/**
	 * Sets the color of the text to be displayed when there is no item in a list.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color				The color of the text to be displayed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

	/**
	 * Gets the color of the text to be displayed when there is no item in a list.
	 *
	 * @since		2.0
	 * @return    	The color of the text to be displayed, @n
	 *				else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since      2.0
	 * @return    An error code
	 *
	 * @exception E_SUCCESS          The method is successful.
	 * @exception E_SYSTEM           A system error has occurred, or failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void GroupedListView_Reserved1 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void GroupedListView_Reserved2 (void) {}

    /**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void GroupedListView_Reserved3 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void GroupedListView_Reserved4 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void GroupedListView_Reserved5 (void) {}

protected:
	friend class GroupedListViewImpl;
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
	class GroupedListViewImpl* GetImpl(void) const;

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
     * @since         2.0
     */		
	GroupedListView(const GroupedListView& groupedListView);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */		
	GroupedListView& operator=(const GroupedListView& groupedListView);
	
private:
	friend class GroupedListViewEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class GroupedListViewEx* __pGroupedListViewEx;
};
}; }; }; // Osp::Ui::Controls
#endif
