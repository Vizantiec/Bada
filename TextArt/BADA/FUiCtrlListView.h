/* $Change: 738045 $ */
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
 * @file	FUiCtrlListView.h
 * @brief	This is the header file for the %ListView class.
 *
 * This header file contains the declarations of the %ListView class and its helper classes.
 */

#ifndef _FUICTRL_LISTVIEW_H_
#define _FUICTRL_LISTVIEW_H_

//includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlIListViewItemProvider.h"
#include "FUiCtrlIListViewItemEventListener.h"
#include "FUiCtrlIFastScrollListener.h"
#include "FUiCtrlIScrollEventListener.h"
#include "FUiIUiLinkEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	ListView
 * @brief	This class defines common behavior for a %ListView control.
 * @since	2.0
 *
 * The %ListView class displays a list of simple and user-configured items. A simple item has a fixed layout consisting of a bitmap
 * and a text string. A user-configured item in a %ListView instance can have a different layout and height than the other items.
 * Each user-configured item is composed of elements, which can be texts and bitmaps, and is configured using the CustomItem class. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 * The following example demonstrates how to use the %ListView class.
 *
 *
 * @code

//Sample Code for ListViewSample.h
#include <FGraphics.h>
#include <FUi.h>
#include <FUiControl.h>
#include <FBase.h>

class CustomListElement : public Osp::Ui::Controls::ICustomElement
{
public:
    CustomListElement(void){}
    ~CustomListElement  (void){}

	bool OnDraw(Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect, Osp::Ui::Controls::ListItemDrawingStatus itemStatus)
	{
		// Sets the Font
		Osp::Graphics::Font font;
		font.Construct(Osp::Graphics::FONT_STYLE_PLAIN , 20);
		canvas.SetFont(font);
		canvas.SetLineWidth(5);
		canvas.SetForegroundColor(Osp::Graphics::Color::COLOR_GREEN);
		if (canvas.DrawRectangle(rect) != E_SUCCESS)
			return false;
		if (canvas.DrawText(Osp::Graphics::Point(rect.x+2, rect.y+20), L"Custom") != E_SUCCESS)
			return false;

		return true;
	}
};

class ListViewSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::Controls::IListViewItemEventListener,
    public Osp::Ui::Controls::IListViewItemProvider
{
public:
    void GetBitmap(void);
    void CreateListView(void);

protected:
    static const int ID_FORMAT_STRING = 100;
    static const int ID_FORMAT_BITMAP = 101;
    static const int ID_FORMAT_CUSTOM = 102;
    static const int ID_CONTEXT_ITEM_1 = 103;
    static const int ID_CONTEXT_ITEM_2 = 104;
    Osp::Ui::Controls::ListView* __pList;
    CustomListElement* __pCustomListElement;

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);

    // IListViewItemEventListener
    virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
    virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status);
    virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction);

    //IListViewItemProvider
    virtual Osp::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
    virtual bool DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth);
    virtual int GetItemCount(void);
};

//Sample Code for ListViewSample.cpp


#include "ListViewSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Base;
using namespace Osp::Media;

result
ListViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;
	__pCustomListElement = new CustomListElement();
	GetBitmap();
	CreateListView();
	return r;
}

result
ListViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;
	// Deallocates bitmaps
	return r;
}

void
ListViewSample::GetBitmap(void)
{
  // You should implement GetBitmap
}

void
ListViewSample::CreateListView(void)
{
	__pList = new ListView();
	__pList->Construct(Rectangle(0, 0, 480, GetClientAreaBounds().height), true, false);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	AddControl(*__pList);
}

void
ListViewSample::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
{
    switch (elementId)
    {
    case ID_FORMAT_BITMAP:
        // Todo:
        break;
    case ID_FORMAT_STRING:
        // Todo:
        break;
    default:
        break;
    }
}

void
ListViewSample::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
{
}

void
ListViewSample::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{
	switch (elementId)
	{
	case ID_CONTEXT_ITEM_1:
		//To do
		break;
	case ID_CONTEXT_ITEM_2:
		//To do
		break;
	}
}

int
ListViewSample::GetItemCount(void)
{
	return 10;
}
Osp::Ui::Controls::ListItemBase*
ListViewSample::CreateItem(int index, int itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new CustomItem();
	pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);

	switch (index % 3)
	{
	case 0:
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"HOME", true);
		break;
	case 1:
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Msg", true);
		break;
	case 2:
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Alarm", true);
		break;
	default:
		break;
	}
	pItem->AddElement(Rectangle(290, 20, 60, 60), ID_FORMAT_CUSTOM, *(static_cast<ICustomElement *>(__pCustomListElement)));

	ListContextItem* pItemContext = new ListContextItem();
	pItemContext->Construct();
	pItemContext->AddElement(ID_CONTEXT_ITEM_1, "Test1");
	pItemContext->AddElement(ID_CONTEXT_ITEM_2, "Test2");
	pItem->SetContextItem(pItemContext);

	return pItem;
}

bool
ListViewSample::DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

 * @endcode
 * 
 */
class _EXPORT_CONTROLS_	ListView :
	public Osp::Ui::Control
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ListView(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ListView(void);

	/**
	 * Initializes this instance of %ListView with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Graphics::Rectangle class @n
	 *									This instance represents the X and Y coordinates of the left top corner of the created %ListView along with the width 
	 *									and height.
	 * @param[in]	itemDivider			Set to @c true to display an item divider, @n
	 *									else @c false
	 * @param[in]	fastScroll			Set to @c true to use fast scroll, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									Either the @c rect.width or @c rect.height parameter has a negative value.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks   For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 *
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, bool itemDivider = true, bool fastScroll = false);

    /**
     * Sets the item provider which creates and deletes items for the list.
     *
     * @since		2.0
     *
     * @return		An error code
     * @param[in]	provider			The item provider to create and delete items
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remark		If an item provider is not set for the list, the list does not work. @n
     *				@c provider should be allocated in heap memory.
     */
    result SetItemProvider(const IListViewItemProvider& provider);


	/**
	 * Adds a listener instance that listens to state changes of list view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddListViewItemEventListener(const IListViewItemEventListener &listener);

	/**
	 * Removes a listener instance that listens to state changes of list view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveListViewItemEventListener(const IListViewItemEventListener &listener);
	
	/**
	* Adds a listener instance that listens to state changes of a fast scroll. @n
	* The added listener can listen to events on the specified event dispatcher's context when they are fired.
	*
	* @since		2.0
	*
	* @param[in]	listener		The event listener to be added
	*/
	void AddFastScrollListener (const IFastScrollListener &listener);

	/**
	 * Removes a listener instance that listens to state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener		The event listener to be removed
	 */
	void RemoveFastScrollListener(const IFastScrollListener &listener);
	
	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
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
	 * Removes a listener instance which listens to the state changes of a scroll event. @n
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
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @remarks		The added listener is notified when a link is selected by the user.
	 *
	 * @see		RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

	/**
	 * Removes the specified link event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 *
	 * @see		AddUiLinkEventListener()
	 */
	void RemoveUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

	/**
	 * Sets the enabled status of the sweep event.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	enable				Set to @c true to enable the sweep, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetSweepEnabled(bool enable);

	/**
	 * Sets the index list of the scroll by texts.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text				The text of the index
	 * @param[in]	useSearchIcon		Set to @c true to show the magnifying icon, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetFastScrollIndex(const Osp::Base::String &text,  bool useSearchIcon);

    /**
     * Gets the index of the top drawn item of the %ListView control.
     *
     * @since	2.0
     *
     * @return	The index of the top drawn item
     */
	int GetTopDrawnItemIndex(void) const;
	
    /**
     * Gets the index of the bottom drawn item of the %ListView control.
     *
     * @since	2.0
     *
     * @return	The index of the bottom drawn item
     */
	int GetBottomDrawnItemIndex(void) const;

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %ListView control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The item index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result ScrollToItem(int index);
	
	/**
	 * Scrolls to the item at the specified index.@n
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since			2.0
	 *
	 * @return    An error code
	 * @param[in] index             The item index
	 * @param[in] itemAlignment     The alignment how the item is placed
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_RANGE    A specified input parameter is invalid.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result ScrollToItem(int index, ListScrollItemAlignment itemAlignment);

    /**
	 * Sets the checked status of the item at the specified index.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index					The item index
	 * @param[in]	check					The check status
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The item is disabled.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * Checks whether the item at the specified index is checked.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the item is checked, @n
	 *				else @c false
	 * @param[in]	index		The item index
	 */
	bool IsItemChecked(int index) const;

    /**
	 * Sets the enabled status of the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 *
	 * @param[in]	index				The item index
	 * @param[in]	enable				Set to @c true to enable the item, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 */
	result SetItemEnabled(int index, bool enable);

	/**
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]	index		The item index
	 */
	bool IsItemEnabled(int index) const;

	/**
	 * Counts the number of items.
	 *
	 * @since	2.0
	 *
	 * @return	The total number of items
	 */
	int GetItemCount(void) const;

	/**
	 * Shows the description text of the given item.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		The description text is not set.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks	If no description text is set to the item of the specified index, this method does not show the description text.
	 *
	 */
	result ShowItemDescriptionText(int index);

	/**
	 * Hides the description text of the given item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index             	The index of the item
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_OUT_OF_RANGE    	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		The description text is not set.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result HideItemDescriptionText(int index);

	/**
	 * Refreshes the specified item.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index                	The item index
	 * @param[in]	type                 	The item to be added, removed, or modified
	 * @exception	E_SUCCESS            	The method is successful.
	 * @exception	E_OUT_OF_RANGE       	A specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_INVALID_STATE      	This instance is in an invalid state.
	 * @exception	E_SYSTEM             	A system error has occurred.
     *
	 * @remarks	3 refresh types are supported: LIST_REFRESH_TYPE_ITEM_ADD, LIST_REFRESH_TYPE_ITEM_REMOVE, and LIST_REFRESH_TYPE_ITEM_MODIFY.
	 * 			- LIST_REFRESH_TYPE_ITEM_ADD is used when new data is added to the data model. @n
	 *			- LIST_REFRESH_TYPE_ITEM_REMOVE is used when a data is deleted from the data model. @n
	 *			- LIST_REFRESH_TYPE_ITEM_MODIFY is used when an existing data has changes and needs to be updated. @n
	 *			   Calling this method with LIST_REFRESH_TYPE_ITEM_MODIFY invokes the item provider to call DeleteItem() and CreateItem() for the given index in 
	 *			   sequence.
	 * @remarks	This method internally calls Draw() and Show(), so they need not be called to update the screen.
	 */
	result RefreshList(int index, ListRefreshType type);
	
	/**
	 * Updates the whole items of a list.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 *
	 * @remarks	This method clears the items in the list and re-invokes the methods of the item provider to fill the list.
	 */
	result UpdateList(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return    	The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]	x		The X position of the point
	 * @param[in]	y		The Y position of the point
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since	2.0
	 *
	 * @return		The index of the item
	 * @param[in]	position	The position of the point, @n
	 *							else @c -1 if there is no list item at the specified position
	 */
	int GetItemIndexFromPosition(const Osp::Graphics::Point& position) const;
	
	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  x                 The X position of the item
	 * @param[in]  y                 The Y position of the item
	 * @param[out] itemIndex         The index of the item
	 * @param[out] elementId         The ID of the element
	 * @exception  E_SUCCESS         The method is successful.
	 * @exception  E_INVALID_STATE   This instance is in an invalid state.
	 * @exception  E_SYSTEM          A system error has occurred, or @n
	 *								 there is no item at the specified position.
	 * @remarks    @c itemIndex is -1 when there is no list item at the specified position.
	 * @remarks    @c elementId is -1 when there is no element at the specified position
	 */
	result GetItemIndexFromPosition(int x, int y, int& itemIndex, int& elementId) const;

	/**
	 * Gets the index of the item and ID of the element at the specified position.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  position          The position of the point
	 * @param[out] itemIndex         The index of the item
	 * @param[out] elementId         The ID of the element
	 * @exception  E_SUCCESS         The method is successful.
	 * @exception  E_INVALID_STATE   This instance is in an invalid state.
	 * @exception  E_SYSTEM          A system error has occurred, or @n
	 *								 there is no item at the specified position.
	 * @remarks    @c itemIndex is -1 when there is no list item at the specified position.
	 * @remarks    @c elementId is -1 when there is no element at the specified position
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& itemIndex, int& elementId) const;
	
	/**
	 * Sets the color of a division line between items.
	 *
	 * @since 	2.0
	 *
	 * @return		An error code
	 * @param[in]	color             	The division line color
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 */
	result SetItemDividerColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since	2.0
	 * @return	The color of a section, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	color    			The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 *
	 * @remarks   	The method sets the alpha value of the specified @c color to @c 255, when a device does not support 32bit color space. @n
	 *            	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only 
	 *				the bitmap image is displayed.
	 */
	result SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of this control.
	 *
	 * @since	2.0
	 * @return	The background color, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the bitmap of the empty list.
	 *
	 * @since		2.0
	 *
	 * @return    	An error code
	 * @param[in] 	pBitmap           	The bitmap for the empty list
	 * @exception 	E_SUCCESS         	The method is successful.
	 * @exception 	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception 	E_SYSTEM          	A system error has occurred.
	 */
	 result SetBitmapOfEmptyList(const Osp::Graphics::Bitmap *pBitmap);

	/**
	 * Sets the text of the empty list.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	text				The text for the empty list
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result SetTextOfEmptyList(const Osp::Base::String &text);

	/**
	 * Gets the text to be displayed when there is no item in a list.
	 *
	 * @since	2.0
	 * @return	The text to be displayed, @n
	 *			else an empty string if the instance is invalid
	 */
	Osp::Base::String GetTextOfEmptyList(void) const;

	/**
	 * Sets a color of the text to display when there is no item in a list.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The color of the text to be displayed
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

	/**
	 * Gets a color of the text to display when there is no item in a list.
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
	 * @since		2.0
	 * @return		An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred. Failed to free the resource possessed by this instance.
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
    virtual void ListView_Reserved1 (void) {}

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
    virtual void ListView_Reserved2 (void) {}

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
    virtual void ListView_Reserved3 (void) {}

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
    virtual void ListView_Reserved4 (void) {}

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
    virtual void ListView_Reserved5 (void) {}

protected:
	friend class ListViewImpl;
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
     class ListViewImpl* GetImpl(void) const;

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
	ListView(const ListView& listView);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */	
	ListView& operator=(const ListView& listView);
	
private:
	friend class ListViewEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class ListViewEx* __pListViewEx;
};
}; }; }; // Osp::Ui::Controls
#endif
