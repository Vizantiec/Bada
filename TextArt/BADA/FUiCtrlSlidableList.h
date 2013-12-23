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
 * @file	FUiCtrlSlidableList.h 
 * @brief	This is the header file for the %SlidableList class. 
 *
 * This header file contains the declarations of the %SlidableList class and its helper classes.
 */

#ifndef _FUICTRL_SLIDABLELIST_H_
#define _FUICTRL_SLIDABLELIST_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlCustomList.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiISlidableListEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class		SlidableList
 * @brief		This class defines the common behavior of a %SlidableList control.
 * @deprecated	This class is deprecated. Instead of using this class, use the ListView class.
 * @since		1.0
 *
 *
 * The %SlidableList class represents a list which loads items on demand and 
 * unloads unused items to save memory. The operation of %SlidableList is the same 
 * as that of a List, except that a %SlidableList does not hold all the items in the memory. 
 * Most of the item manipulations are available when they are loaded, but the check 
 * state is maintained for all items whether they are loaded or not.
 * ISlidableListEventListener should be implemented so that an application can be 
 * notified when items need to be loaded as the user scrolls through a list.
 * If an application wants to perform tasks when the state of a list item is changed, 
 * then it should implement ICustomItemEventListener and register it to the slidable list, 
 * It will then receive related events from %SlidableList.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically 
 * when the %SlidableList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat 
 * should be deleted by the application.
 * 
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 * 
 * @image html GUI_slidablelist.png
 *
 * This is the simple UI application which uses a %SlidableList control.
 *
 * @code

// Sample Code for SlidableListSample.h
#include <FUi.h>
#include <FBase.h>

class SlidableListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::ICustomItemEventListener,
    public Osp::Ui::ISlidableListEventListener
{
public:
    SlidableListSample(void)
	:__pSlidableList(null)
	,__pCustomListItemFormat(null){}

protected:
    static const int ID_LIST_TEXT  = 101;
	static const int ID_LIST_BITMAP = 102;
	static const int ITEM_COUNT = 1000;
	static const int ITEM_HEIGHT = 100;

    Osp::Graphics::Bitmap* GetBitmapN(void);
    Osp::Ui::Controls::CustomListItem* CreateListItem(
		Osp::Base::String itemText,
		Osp::Graphics::Bitmap* pBitmapNormal,
		Osp::Graphics::Bitmap* pBitmapFocused);

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);

    virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
    virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status);

    virtual void OnListPropertyRequested (const Osp::Ui::Control &source);
    virtual void OnLoadToTopRequested(const Osp::Ui::Control &source, int index, int numItems);
    virtual void OnLoadToBottomRequested(const Osp::Ui::Control &source, int index, int numItems);
    virtual void OnUnloadItemRequested(const Osp::Ui::Control& source, int itemIndex);

private:
    Osp::Ui::Controls::SlidableList* __pSlidableList;
    Osp::Ui::Controls::CustomListItemFormat* __pCustomListItemFormat;
};

// Sample Code for SlidableListSample.cpp
#include "SlidableListSample.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
SlidableListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a SlidableList
    __pSlidableList = new SlidableList();
    __pSlidableList->Construct(Rectangle(0, 0, 480, 500), CUSTOM_LIST_STYLE_NORMAL);
    __pSlidableList->AddCustomItemEventListener(*this);
    __pSlidableList->AddSlidableListEventListener(*this);

    // Creates an item format of the SlidableList
    __pCustomListItemFormat = new CustomListItemFormat();
    __pCustomListItemFormat->Construct();
    __pCustomListItemFormat->AddElement(ID_LIST_TEXT, Osp::Graphics::Rectangle(10, 25, 200, 80));
    __pCustomListItemFormat->AddElement(ID_LIST_BITMAP, Osp::Graphics::Rectangle(220, 10, 70, 80));

    // Adds the SlidableList to the Form
    AddControl(*__pSlidableList);

    // Displays the Form
    Draw();
    Show();

    return r;
}

result
SlidableListSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    // Deallocates the item format
    delete __pCustomListItemFormat;

    return r;
}

CustomListItem*
SlidableListSample::CreateListItem(String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
    CustomListItem* pItem = new CustomListItem();

    pItem->Construct(ITEM_HEIGHT);
    pItem->SetItemFormat(*__pCustomListItemFormat);
    pItem->SetElement(ID_LIST_TEXT, itemText);
    pItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

    return pItem;
}

Bitmap*
SlidableListSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

// Implements an ICustomItemEventListener
void
SlidableListSample::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status)
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
SlidableListSample::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status)
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

// Implements an ISlidableEventListener
void
SlidableListSample::OnListPropertyRequested (const Control &source)
{
    // Sets the total count and the height of items
    __pSlidableList->SetItemCountAndHeight(ITEM_COUNT, ITEM_COUNT * ITEM_HEIGHT);
}

void
SlidableListSample::OnLoadToTopRequested(const Control &source, int index, int numItems)
{
    // Creates Bitmaps
	Bitmap *pBitmapNormal  = GetBitmapN();
	Bitmap *pBitmapFocused = GetBitmapN();

    // Creates items of the SlidableList
    for(int i = index; i > index - numItems; i--)
    {
        String itemText = "ITEM_";
        itemText.Append(i);
        __pSlidableList->LoadItemToTop(*CreateListItem(itemText, pBitmapNormal, pBitmapFocused), i+1);
    }

    // Deallocates the Bitmaps
    delete pBitmapNormal;
    delete pBitmapFocused;
}

void
SlidableListSample::OnLoadToBottomRequested (const Control &source, int index, int numItems)
{
    // Creates Bitmaps
    Bitmap *pBitmapNormal  = GetBitmapN();
    Bitmap *pBitmapFocused = GetBitmapN();

    // Creates items of the SlidableList
    for(int i = index; i < index + numItems; i++)
    {
        String itemText = "ITEM_";
        itemText.Append(i);
        __pSlidableList->LoadItemToBottom(*CreateListItem(itemText, pBitmapNormal, pBitmapFocused), i+1);
    }

    // Deallocates the Bitmaps
    delete pBitmapNormal;
    delete pBitmapFocused;
}

void
SlidableListSample::OnUnloadItemRequested(const Control& source, int itemIndex)
{
	// Releases resources of the specified item
	// Todo:
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_	SlidableList :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(SlidableList);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	SlidableList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~SlidableList(void);

// Operation
	
	/**
	 * Initializes this instance of %SlidableList with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *					For more information, see @ref CompSlidableListConstruct "here".
	 * @return		An error code
	 * @param[in]	rect			This instance represents the X and Y coordinates of the top-left corner of the created SlidableList along with the width and height
	 * @param[in]	style			The style set of %CustomList
	 * @param[in]	itemDivider		Set to @c true to display an item divider, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception E_INVALID_ARG 	A specified input parameter is invalid. @n
	 *        						Either the @c rect.width or the @c rect.height is @c 0 or negative.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM		The method has failed.
	 * @remarks   In the bada API version prior to 2.0, the width and the height of the control must be greater than @c 0.
     * @remarks   From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
     * @remarks   The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
     *
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true);

	 /**
	 * @page	CompSlidableListConstruct	Compatibility for Construct()
	 *
	 * @section	CompSlidableListConstructIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust its 
	 *	  bounds to the minimum size. @n
	 * -# On a WVGA screen, the default minimum sizes are 92 x 72.
	 *
	 * @section	CompSlidableListConstructResolutions	Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use API version 2.0 or above. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0.
	 * -# On a WVGA screen, the default minimum sizes are changed to 90 x 72.
	 */

    /**
	 * Adds a listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddSlidableListEventListener(const Osp::Ui::ISlidableListEventListener& listener);

	/**
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveSlidableListEventListener(const Osp::Ui::ISlidableListEventListener& listener);

	/**
	 * Adds a listener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
    void AddCustomItemEventListener(const Osp::Ui::ICustomItemEventListener &listener);
  
  	/**
	 * Adds the specified item to the %SlidableList control.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in]	item			The CustomListItem to be added
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The added item is deleted automatically when the list is destroyed. @n
	 *				Do not add, insert, or set an item which already belongs to %SlidableList.
	 */
    result AddItem(const CustomListItem &item, int itemId=LIST_ITEM_UNSPECIFIED_ID);
  
    /**
     * Gets the index of the bottom drawn item from the %SlidableList control.
     *
     * @since		1.0
     * @return		An integer value representing the index of the bottom drawn item
     */
    int GetBottomDrawnItemIndex(void) const;

	/**
	 * Gets the first item of all the checked items in the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		The index of the first selected item
	 *
	 * @remarks   This method can only be used when the style of the list allows multiple selections.
	 */
    int GetFirstCheckedItemIndex(void) const;

	/**
	 * Gets the count of the number of items in the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		The number of items in the %SlidableList control
	 */
    int GetItemCount(void) const;
  
    /**
     * Gets the last item of all the checked items in the %SlidableList control.
     *
     * @since		1.0
     * @return		The index of the last selected item
     *
     * @remarks		This method can only be used when the style of the list allows multiple selections.
     */
    int GetLastCheckedItemIndex(void) const;
  
    /**
     * Gets the radio checked item of the %SlidableList control.
     *
     * @since		1.0
     * @return		The next item index
     * @param[in]   index	The item index
     *
     * @remarks		This method can only be used when the style of the list allows multiple selections.
     */
    int GetNextCheckedItemIndexAfter(int index) const;
  
    /**
     * Gets the index of the top drawn item of the %SlidableList control.
     *
     * @since		1.0
     * @return		The index of the top drawn item
     */
    int GetTopDrawnItemIndex(void) const;
  
  	/**
	 * Inserts the specified item in the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index           The item index at which to insert the item
	 * @param[in]	item            The CustomListItem to be inserted
	 * @param[in]	itemId		    The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to %SlidableList.
	 */
    result InsertItemAt(int index, const CustomListItem &item, int itemId=LIST_ITEM_UNSPECIFIED_ID);
  
  	/**
	 * Removes all the items of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remark		The removed list items are deleted from the memory.
	 * @remark		After items have been removed, the ISlidableListEventListener::OnListPropertyRequested() method is called.
	 * @see			ISlidableListEventListener 
	 */
    result RemoveAllItems(void);
  
    /**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
    void RemoveCustomItemEventListener(const Osp::Ui::ICustomItemEventListener &listener);
  
    /**
	 * Scrolls to the bottom of the %SlidableList control.
	 *
	 * @since	1.0
	 */
    void ScrollToBottom(void);
  
    /**
	 * Scrolls to the top of the %SlidableList control.
	 *
	 * @since	1.0
	 */
    void ScrollToTop(void);
  
	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The item index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
    result ScrollToTop(int index);
  
  	/**
	 * Sets the check status for all items of the %SlidableList control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableListSetAllItemsChecked "here".
	 * @return		An error code
	 * @param[in]	check		Set to @c true to check all the items, @n
	 *							else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @remarks This method can only be used when the style of the list allows multiple selections.
	 */
    result SetAllItemsChecked(bool check);
  
    /**
	 * @page	CompSlidableListSetAllItemsChecked	Compatibility for SetAllItemsChecked()
	 *
	 * @section	CompSlidableListSetAllItemsCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the specified item is disabled, the checked status of the item is not changed.
	 *
	 * @section	CompSlidableListSetAllItemsCheckedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
  
    /**
	 * Sets the check status of the item at the specified index of the %SlidableList control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableListSetItemChecked "here".
	 * @return		An error code
	 * @param[in]   index		The item index
	 * @param[in]   check		The check status
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @remarks      This method can only be used when the style of the list allows selection.	 
	 */
    result SetItemChecked(int index, bool check);
  
  	/**
	 * @page	CompSlidableListSetItemChecked	Compatibility for SetItemChecked()
	 *
	 * @section	CompSlidableListSetItemCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n 
	 * -# When the specified item is disabled, the checked status of the item is not changed.
	 *
	 * @section	CompSlidableListSetItemCheckedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
  
  	/**
	 * Enables or disables the status of the item at the specified index of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   index		The item index
	 * @param[in]   enable	    Set to @c true to enable, @n
	 *						 	else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *						
	 */
    result SetLoadedItemEnabled(int index, bool enable);

	/**
	 * Sets the background color of the %SlidableList control.
	 *
	 * @since 		1.1
	 * @param[in]	color	The background color
	 */
	void SetBackgroundColor(const Osp::Graphics::Color& color);

    /**
     * Sets the text to display in the absence of a %SlidableList item.
     *
     * @since		1.0
     * @param[in]	text	The text message
     */
    void SetTextOfEmptyList(const Osp::Base::String &text);

    /**
     * Sets a color of the text to display in the absence of a %SlidableList item.
     *
     * @since			1.0
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompSlidableListSetTextColorOfEmptyList "here".
	 *
     * @param[in]	color	The color of the text to be displayed
     */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

    /**
     * @page	CompSlidableListSetTextColorOfEmptyList	Compatibility for SetTextColorOfEmptyList()
     *
     * @section	CompSlidableListSetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method ignores the alpha value of the specified color.
     *
     * @section	CompSlidableListSetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */


    /**
 	 * Gets a color of the text to display in the absence of a %SlidableList item.
	 *
	 * @since  			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompSlidableListGetTextColorOfEmptyList "here".
	 *
	 * @return	The color of the text to be displayed
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;

    /**
     * @page	CompSlidableListGetTextColorOfEmptyList	Compatibility for GetTextColorOfEmptyList()
     *
     * @section	CompSlidableListGetTextColorOfEmptyListIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color which is converted from the color specified by SetTextColorOfEmptyList(), omitting the alpha value.
     *
     * @section	CompSlidableListGetTextColorOfEmptyListResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows:
     * -# The method returns a 32-bit color.
     */


	/**
	 * Gets the loaded item at the specified index of the %SlidableList control.
	 *
	 * @since		1.0
 	 * @return		A CustomListItem
	 * @param[in]	index		The item index
	 */
    const CustomListItem* GetLoadedItemAt(int index) const;
  
  	/**
	 * Gets the index of the loaded item at the specified item ID.
	 *
	 * @since		1.0
	 * @return		The item ID
	 * @param[in]	index		The item index
	 */
    int GetLoadedItemIdAt(int index) const;
  
	/**
	 * Checks whether the item at the specified index is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]	index		The item index
	 */
    bool IsItemChecked(int index) const;
  
    /**
	 * Checks whether the loaded item at the specified index is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in] 	index		The item index
	 */
    bool IsLoadedItemEnabled(int index) const;
  
    /**
	 * Gets the index of the loaded item at the specified item ID.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompSlidableListGetLoadedItemIndexFromItemId "here".
	 * @return			The index of the item
	 * @param[in]  	  	itemId		The item ID
	 */
    int GetLoadedItemIndexFromItemId(int itemId) const;

	/**
	 * @page	CompSlidableListGetLoadedItemIndexFromItemId	Compatibility for GetLoadedItemIndexFromItemId()
	 * @section	CompSlidableListGetLoadedItemIndexFromItemIdIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the index of the first loaded item is not @c 0, this method returns @c -1.
	 *
	 * @section	CompSlidableListGetLoadedItemIndexFromItemIdResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */

	/**
	 * Loads the item to the top of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	item			The %CustomListItem to be loaded
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result LoadItemToTop(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

    /**
	 * Loads the item to the end of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
     * @param[in]	item			The CustomListItem to be loaded
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result LoadItemToBottom(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

    /**
     * Unloads all loaded items of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result UnloadAllItems(void);

	/**
     * Sets the contents of the item at the specified index of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index               The item index
	 * @param[in]	item				The CustomListItem to be set
	 * @param[in]	itemId				The item ID for this item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not add, insert, or set an item which already belongs to %SlidableList.
	 */
    result SetItemAt(int index, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * Removes the item at the specified index of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index		The item index to be deleted
	 * @param[in]	itemHeight	The height of the item to be deleted
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		The removed list item is deleted from the memory.
	 */
	result RemoveItemAt(int index, int itemHeight);

	/**
	 * Removes all the checked items of the %SlidableList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	itemHeight		The height of the item to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks	The removed list items are deleted from the memory.
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 */
	result RemoveAllCheckedItems(int itemHeight);

	/**
	 * Sets the number of items and the combined height of all the items of the %SlidableList control.
	 *
	 * @since		1.0
	 * @param[in] 	count		The count of list items
	 * @param[in] 	listHeight	The height of the list
	 *
	 */
	void SetItemCountAndHeight(int count, int listHeight);

	/**
	 * Checks whether the specific item is loaded.
	 *
	 * @since		1.0
	 * @return		@c true if the item is loaded, @n
	 *				else @c false
	 * @param[in] 	index	The item index
	 */
	bool IsItemLoaded(int index) const;

	/**
	 * Gets the index of the first loaded item.
	 *
	 * @since		1.0
	 * @return		The index of the first loaded item
	 */
	int GetFirstLoadedItemIndex(void) const;

	/**
	 * Gets the index of the last loaded item.
	 *
	 * @since		1.0
	 * @return		The index of the last loaded item
	 */
	int GetLastLoadedItemIndex(void) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return      The index of the item, @n
	 *				else @c -1 if there is no list item with the specified position
	 * @param[in]   x		The x position of the point
	 * @param[in]   y		The y position of the point
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item with the specified position
	 * @param[in]   position    The position of the point
	 */
	int GetItemIndexFromPosition(const Osp::Graphics::Point& position) const;

	/**
	 * Draws and shows the item of the %SlidableList control.
	 *
	 * @since		1.0
 	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *					For more information, see @ref CompSlidableListRefreshItem "here".
	 * @return		An error code
	 * @param[in]	index				The index of the %SlidableList item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @exception   E_INVALID_OPERATION	The item has never been drawn before calling this method.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result RefreshItem(int index);
	
    /**
     * @page	CompSlidableListRefreshItem	Compatibility for RefreshItem()
     * @section	CompSlidableListRefreshItemIssues	Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# If the specified item is not drawn at least once, calling this method updates the item in a wrong way and returns E_SUCCESS.
     *
     * @section	CompSlidableListRefreshItemResolutions	Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     *
     * If the specified item has never been drawn before calling this method, it does not update the item and returns E_INVALID_OPERATION.
     */

	/**
	 * Sets the position and size of the control. @n
	 * Its position is set to (x, y), its width is set @c width, and its height is set to @c height.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	x				    		The x coordinate
	 * @param[in]	y				    		The y coordinate
	 * @param[in]	width			    		The width
	 * @param[in]	height						The height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid. @n
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
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect			    		The bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
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
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	size			         The new size of the control
	 * @exception	E_SUCCESS		         The method is successful.
	 * @exception	E_INVALID_STATE			 This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION  The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG            The specified input parameter is invalid. @n
	 *									     Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
	 * @exception	E_SYSTEM                 A system error has occurred.
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
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	width			         The width of the control
	 * @param[in]	height			         The height of the control
	 * @exception	E_SUCCESS		         The method is successful.
	 * @exception	E_INVALID_STATE			 This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION  The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG            The specified input parameter is invalid. @n
	 *									     Either @c dim.width or @c dim.height is out of the range defined by the minimum size and the maximum size.
	 * @exception	E_SYSTEM                 A system error has occurred.
	 * @remarks		Do not override this method.
	 * @see   IsResizable()
	 * @see   GetMinimumSize()
	 * @see   GetMaximumSize()
	 */
	virtual result SetSize (int width, int height);

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
	 * @exception	E_SYSTEM		A system error has occurred.
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
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
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
	 * The __ListExAppCallback
     * @since         1.0
     */
     void* __pListCallback;

	friend class SlidableListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class SlidableListEx* __pSlidableListEx;

protected:
	friend class SlidableListImpl;
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
	class SlidableListImpl* GetImpl(void) const;

};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_SLIDABLELIST_H_
