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
 * @file	FUiCtrlExpandableList.h
 * @brief	This is the header file for the %ExpandableList class.
 *
 * This header file contains the declarations of the %ExpandableList class and its helper classes.
 */

#ifndef _FUICTRL_EXPANDABLELIST_H_
#define _FUICTRL_EXPANDABLELIST_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlCustomList.h"
#include "FUiIExpandableItemEventListener.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiCtrlListEnum.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	ExpandableList
 * @brief This class defines the common behavior of an %ExpandableList control.
 * @deprecated This class is deprecated. Instead of using this class, use ListView class and implement item expanding and collapsing. @n
 * @since		1.0
 *
 * The %ExpandableList class defines the common behavior of an %ExpandableList control.
 * An expandable list is a list with a hierarchy of depth 2. List items of %ExpandableList 
 * consist of main items and sub-items which are CustomListItem. Main items are inserted 
 * into the first level as items are inserted into List class. Sub-items are inserted under
 * related main items. So, sub-items are uniquely identified with two indices: main item 
 * index and sub-item index.
 *
 * If an application wants to perform tasks when the state of a list item is changed, 
 * it should implement IExpandableItemEventListener and register it to the expandable list, 
 * It will then receive related events from %ExpandableList.
 * 
 * Unlike GroupedList which is also a list with the hierarch of depth 2, main items of 
 * %ExpandableList can be expanded or closed.
 *
 * Note that CustomListItem and CustomListItemFormat need to be created on a heap. CustomListItems will be deleted automatically 
 * when the %ExpandableList itself is destroyed. If you want to remove certain list items, you must use RemoveItemAt(). CustomListItemFormat 
 * should be deleted by the application.
 * 
 * Refer to CustomListItem and CustomListItemFormat.
 *
 * Example:
 * 
 * @image html GUI_expandablelist.png
 *
 * This is the simple UI application which uses an %ExpandableList control.
 *
 * @code
 
//Sample Code for ExpandableListSample.h
#include <FUi.h>

class ExpandableListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IExpandableItemEventListener
{
public:
	ExpandableListSample(void)
	:__pMainItemFormat(null)
	,__pSubItemFormat(null){}

protected:
    static const int ID_LIST_MAINITEM = 101;
    static const int ID_LIST_SUBITEM = 102;
    static const int ID_LIST_TEXT = 103;
    static const int ID_LIST_BITMAP = 104;

    Osp::Graphics::Bitmap* GetBitmapN(void);

    result AddListMainItem(
    		Osp::Ui::Controls::ExpandableList& expandableList,
    		Osp::Base::String itemText,
    		Osp::Graphics::Bitmap* pBitmapNormal,
    		Osp::Graphics::Bitmap* pBitmapFocused);

    result AddListSubItem(
    		Osp::Ui::Controls::ExpandableList& expandableList,
    		int itemId, Osp::Base::String itemText);

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, ItemStatus status);
   	virtual void OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, int elementId, Osp::Ui:: ItemStatus status);

private:
    Osp::Ui::Controls::CustomListItemFormat* __pMainItemFormat;
    Osp::Ui::Controls::CustomListItemFormat* __pSubItemFormat;
};

//Sample Code for ExpandableListSample.cpp
#include "ExpandableListSample.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
ExpandableListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Create Bitmap
    Bitmap *pBitmapNormal  = GetBitmapN();
    Bitmap *pBitmapFocused = GetBitmapN();

    // Create ExpandableList
    ExpandableList* pExpandableList = new ExpandableList();
    pExpandableList->Construct(Rectangle(0, 0, 480, 500), CUSTOM_LIST_STYLE_NORMAL);
    pExpandableList->AddExpandableItemEventListener(*this);

    // Create an item format of the main item
    __pMainItemFormat = new CustomListItemFormat();
    __pMainItemFormat->Construct();
    __pMainItemFormat->AddElement(ID_LIST_TEXT, Osp::Graphics::Rectangle(10, 25, 200, 80));
    __pMainItemFormat->AddElement(ID_LIST_BITMAP, Osp::Graphics::Rectangle(220, 10, 70, 80));

    // Create an item format of the sub-item
    __pSubItemFormat = new CustomListItemFormat();
    __pSubItemFormat->Construct();
    __pSubItemFormat->AddElement(ID_LIST_TEXT, Osp::Graphics::Rectangle(20, 25, 450, 50));

    // Add main item
    AddListMainItem(*pExpandableList, L"MainItem", pBitmapNormal, pBitmapFocused);

    // Add sub-item
    AddListSubItem(*pExpandableList, ID_LIST_MAINITEM, L"SubItem");

    // Add an ExpandableList to the Form
    AddControl(*pExpandableList);

    // Display the Form
    Draw();
    Show();

    // Deallocate a Bitmap
    delete pBitmapNormal;
    delete pBitmapFocused;

    return r;
}

result
ExpandableListSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    // Deallocate a item format
    delete __pMainItemFormat;
    delete __pSubItemFormat;

    return r;
}

result
ExpandableListSample::AddListMainItem(ExpandableList& expandableList, String itemText, Bitmap* pBitmapNormal, Bitmap* pBitmapFocused)
{
    result r = E_SUCCESS;

    // Create a main item of the ExpandableList
    CustomListItem* pMainItem = new CustomListItem();
    pMainItem->Construct(100);
    pMainItem->SetItemFormat(*__pMainItemFormat);
    pMainItem->SetElement(ID_LIST_TEXT, itemText);
    pMainItem->SetElement(ID_LIST_BITMAP, *pBitmapNormal, pBitmapFocused);

    // Add a item to the ExpandableList
    expandableList.AddItem(*pMainItem, ID_LIST_MAINITEM);

    return r;
}

result
ExpandableListSample::AddListSubItem(ExpandableList& expandableList, int itemId, String itemText)
{
    result r = E_SUCCESS;

	// Create a sub-item of the ExpandableList
    CustomListItem* pSubItem = new CustomListItem();
	pSubItem->Construct(100);
	pSubItem->SetItemFormat(*__pSubItemFormat);
    pSubItem->SetElement(ID_LIST_TEXT, itemText);

    // Add a item to the ExpandableList
    expandableList.AddSubItem(expandableList.GetItemIndexFromItemId(ID_LIST_MAINITEM), *pSubItem, ID_LIST_SUBITEM);

    return r;
}

Bitmap*
ExpandableListSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

// Implement an ICustomItemEventListener
void
ExpandableListSample::OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_MAINITEM:
		// Todo:
		break;
	case ID_LIST_SUBITEM:
		// Todo:
		break;
	default:
		break;
	}
}


void
ExpandableListSample::OnItemStateChanged(const Control& source, int mainIndex, int subIndex, int itemId, int elementId, ItemStatus status)
{
	switch (itemId)
	{
	case ID_LIST_MAINITEM:
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
	case ID_LIST_SUBITEM:
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
class _EXPORT_CONTROLS_	ExpandableList :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(ExpandableList);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	ExpandableList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~ExpandableList(void);

// Operation

	/**
	 * Initializes this instance of %ExpandableList with the specified parameters.
	 *
	 * @since    1.0
	 * @compatibility      This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                     For more information, see @ref CompExpandableListConstruct "here".
	 * @return    An error code
	 * @param[in]	rect				The x, y position of the top-left corner of the %ExpandableList along with the width and the height of the control
	 * @param[in] style             The style set
	 * @param[in]	itemDivider			Set to @c true to display the divider, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE   This instance has already been constructed.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than @c 0. @n
     *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
     *				The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, CustomListStyle style, bool itemDivider = true);
	
	 /**
	 * @page	CompExpandableListConstruct	Compatibility for Construct()
	 *
	 * @section	CompExpandableListConstructIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 * -# On a WVGA screen, the default minimum size is 92 x 72.
	 *
	 * @section CompExpandableListConstructResolutions Resolutions
	 * The issues mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0.
	 * -# On a WVGA screen, the default minimum size is changed to 90 x 72.
	 */

	/**
	 * Adds the ExpandableItemEventListener instance. @n
	 * The added listener gets notified when the state of an item is changed.
 	 *
 	 * @since			1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddExpandableItemEventListener(const Osp::Ui::IExpandableItemEventListener& listener);

	/**
	 * Removes the ExpandableItemEventListener instance. @n
	 * The removed listener is not notified even when the expandable item events are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveExpandableItemEventListener(const Osp::Ui::IExpandableItemEventListener& listener);

	/**
	 * Adds the specified item to the %ExpandableList control.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in]	item		The CustomListItem to be added
	 * @param[in]	itemId		The item ID for the item
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		The item ID can be used to identify the specific %CustomListItem instance or to associate the user-allocated resources. @n
	 *				Note that %ExpandableList does not throw an exception, if the same item ID is given to multiple items. @n
	 * 				The added item is deleted automatically when the list is destroyed. @n
	 *				Do not add, insert, or set an item which already belongs to the %ExpandableList.
	 */
	result AddItem(const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**	 
	 * Inserts the specified item to the %ExpandableList control at the specified index.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index at which to insert the item
	 * @param[in]	item            The CustomListItem to be inserted
	 * @param[in]	itemId          The item ID for the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The inserted item is deleted automatically when the list is destroyed.
	 *				Do not add, insert, or set an item that already belongs to the %ExpandableList control.
	 */
	result InsertItemAt(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**	 
	 * Changes the contents of the item at the specified index in the %ExpandableList control.
	 *
	 * @since					1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompExpandableListSetItemAt "here".
	 * @return		An error code
	 * @param[in]   mainIndex       The index at which to set the contents of the item
	 * @param[in]	item            The CustomListItem to be set
	 * @param[in]	itemId          The item ID for the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		Do not add, insert, or set an item that already belongs to the %ExpandableList control.
	 */
	result SetItemAt(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @page   CompExpandableListSetItemAt	Compatibility for SetItemAt()
	 * @section CompExpandableListSetItemAtIssues Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the specified item is set at the specified position, all the sub-items of the changed item are removed.
	 *
	 * @section CompExpandableListSetItemAtResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 *
	 * @par When working with bada API versions prior to 1.2: 
	 * If the sub-items are to be maintained, get CustomListItem at that index and change the content of its elements. 
	 *
	 */

	/**
	 * Removes the item at the specified index in the %ExpandableList control. 
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]	mainIndex		The index of the item to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks   	The removed list item is deleted from the memory.
	 */
	 result RemoveItemAt(int mainIndex);

	/**
	 * Removes all the items from the %ExpandableList control.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks   The removed list items are deleted from the memory.
	 */
	result RemoveAllItems(void);

	/**
	 * Gets the item at the specified index in the %ExpandableList control.
	 *
	 * @since		1.0
	 * @return		A CustomListItem instance, @n
	 *				else @c null if the specified index is out of range
	 * @param[in]	mainIndex		The index of the item
	 */
	const CustomListItem* GetItemAt(int mainIndex) const;

	/**	
	 * Adds the specified sub-item to the main item in the %ExpandableList control. 
	 *
	 * @since				1.0
 	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item to which the sub-item is added
	 * @param[in]	item            The CustomListItem instance to be added
	 * @param[in]	itemId          The item ID for the sub-item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified index is less than @c 0, or greater than the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result AddSubItem(int mainIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**	 
	 * Inserts the specified sub-item at the specified index to the main item in the %ExpandableList control.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item to which the sub-item is added
	 * @param[in]   subIndex        The index of the sub-item at which to insert the item
	 * @param[in]	item            The CustomListItem instance to be inserted
	 * @param[in]	itemId          The item ID
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified index is less than @c 0, or greater than the item count.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result InsertSubItemAt(int mainIndex, int subIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

   	/**	 
	 * Changes the contents of the sub-item at the specified index in the %ExpandableList control.
 	 *
 	 * @since				1.0
 	 * @return			An error code
	 * @param[in]   mainIndex       The main index of the sub-item at which to set the contents of the item
	 * @param[in]   subIndex        The sub-index of the sub-item at which to set the contents of the item
	 * @param[in]   item            The CustomListItem instance to be set
	 * @param[in]   itemId          The item ID
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified index is less than @c 0, or greater than the item count.
	 * @exception   E_SYSTEM        A system error has occurred.
   	 */
  	result SetSubItemAt(int mainIndex, int subIndex, const CustomListItem& item, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**	 
	 * Removes the sub-item at the specified index in the %ExpandableList control.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        The index of the sub-item to be deleted in the main item
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified index is less than @c 0, or greater than the item count.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result RemoveSubItemAt(int mainIndex, int subIndex);

	/**	 
	 * Removes all sub-items of the specified main item in the %ExpandableList control.
	 *
	 * @since			1.0
	 * @return		An error code
     * @param[in]	mainIndex		The index of the main item of the %ExpandableList control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified index is less than @c 0, or greater than or equal to the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAllSubItemsAt(int mainIndex);

	/**
	 * Gets the number of items in the %ExpandableList control.
	 *
	 * @since		1.0
	 * @return  	The number of items in %ExpandableList, @n
	 *          else @c -1 if an error occurs
	 */
	int GetItemCount(void) const;
  
	/**
	 * Gets the number of sub-items in the main item.
	 *
	 * @since			1.0
	 * @return    	The number of sub-items in the main item, @n
	 *          else @c -1 if an error occurs
	 * @param[in] mainIndex The index of the main item
	 */
	int GetSubItemCount(int mainIndex) const;

	/**	 
	 * Gets the sub-item at the specified index.
	 *
	 * @since		1.0
	 * @return		A pointer to the CustomListItem instance at the specified index,  @n
	 *				else @c null if the specified index does not exist in the %ExpandableList control
	 * @param[in]   mainIndex   The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex    The index of the sub-item to get in the main index
	 */
	const CustomListItem* GetSubItemAt(int mainIndex, int subIndex) const;

	/**	 
	 * Gets the first item of all the checked main items in the %ExpandableList control.
	 *
	 * @since		1.0
	 * @return  The index of the first checked item,  @n
	 *          else @c -1 if no main item is checked
   */
  	int GetFirstCheckedItemIndex (void) const;
  	  	
 /**
	 * Gets the item ID of the specified main item.
	 *
	 * @since				1.0
	 * @return      The item ID of the main item, @n
	 *              else @c -1 if the specified @c mainIndex is less than @c 0 or greater than the main item count
	 * @param[in]   mainIndex  The index of the main item
	 */
  	int GetItemIdAt (int mainIndex) const;
  	  	
	/**
	 * Gets the index of the specified main item.
	 *
	 * @since				1.0
	 * @return      The index of the main item, @n
	 *              else @c -1 if no main item has the specified item ID
	 * @param[in]	itemId		The item ID
	 * @remarks A main item can have the same item ID and this method returns the first main item among such items.
	 */
  	int GetItemIndexFromItemId (int itemId) const;
  	
 /**
	 * Gets the item ID of the specified sub-item.
	 *
	 * @since			1.0
	 * @return    The item ID of the specified sub-item, @n
	 *            else @c -1 if the specified sub-item does not exist
	 * @param[in]	mainIndex	The index of the main item, which the sub-item belongs to
	 * @param[in] subIndex      The index of the sub-item
	 */
  	int GetSubItemIdAt (int mainIndex, int subIndex) const;

	/**
	 * Expands or shrinks the specified main item.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in] mainIndex       The index of the main item
	 * @param[in] 	expand			Set to @c true to expand the specified main item, @n
	 *						        else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or greater than the main item count.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 */
	result SetItemExpanded(int mainIndex, bool expand);

	/**
	 * Checks whether the main item is expanded.
	 *
	 * @since				1.0
	 * @return      @c true if the main item is expanded, @n
	 *				else @c false
	 * @param[in]   mainIndex   The index of the main item
	 */
	bool IsItemExpanded(int mainIndex) const;

	/**
	 * Enables or disables the status of the main item at the specified index of the %ExpandableList control.
	 *
	 * @since				1.0
	 * @return      An error code
	 * @param[in]   mainIndex       The index of the main item, for which the status is to be set
	 * @param[in]   enable          Set to @c true to enable the main item, @n
	 *								else @c false
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or no less than the main item count.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result SetItemEnabled(int mainIndex, bool enable);

	/**
	 * Checks whether the main item at the specified index in the %ExpandableList control is enabled.
	 *
	 * @since			1.0
	 * @return  	@c true if the main item is enabled, @n
	 *          	else @c false
	 * @param[in]	mainIndex	The index of the main item to be checked
	 */
	bool IsItemEnabled(int mainIndex) const;

	/**
	 * Sets the enabled status of the specific sub-item.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        The index of the sub-item in the main item
	 * @param[in]   enable			Set to @c true to enable the sub-item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The sub-item at the specified index does not exist.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result SetSubItemEnabled(int mainIndex, int subIndex, bool enable);

	/**
	 * Checks whether the specified sub-item is enabled.
	 *
	 * @since			1.0
	 * @return  	@c true if the specified sub-item is enabled, @n
	 *				else @c false
	 * @param[in] mainIndex         The index of the main item which the sub-item belongs to
	 * @param[in] subIndex          The index of the sub-item in the main item
	 */
	bool IsSubItemEnabled(int mainIndex, int subIndex) const;

	/**
	 * Sets the check status of the main item at the specified index.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	mainIndex	    The index of the main item
	 * @param[in] 	check		    Set to @c true to check the main item, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or no less than the main item count.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */
	result SetItemChecked(int mainIndex, bool check);

	/**
	 * Checks whether the status of the main item at the specified index is checked. 
	 *
	 * @since		1.0
	 * @return  	@c true if the main item is checked, @n
	 *				else @c false
	 * @param[in]	mainIndex	The index of the main item
	 *
	 * @remark		This method can only be used when the style of the list allows selection.
	 */
	bool IsItemChecked(int mainIndex) const;


	/**
	 * Sets the check status of the specified sub-item of the %ExpandableList control.
	 *
	 * @since				1.0
	 * @return	    An error code
	 * @param[in]   mainIndex       The index of the main item which the sub-item belongs to
	 * @param[in]   subIndex        The index of the sub-item in the main index
	 * @param[in]	check			Set to @c true to check the sub-item, @n
	 *								else @c false
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The sub-item at the specified index does not exist.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */
	result SetSubItemChecked(int mainIndex, int subIndex, bool check);

	/**
	 * Checks whether the specified sub-item is checked.
	 *
	 * @since		1.0
	 * @return		@c true if the sub-item is checked, @n
	 *				else @c false
	 * @param[in] mainIndex  The index of the main item which the sub-item belongs to
	 * @param[in] subIndex  The index of the sub-item in the main item
	 *
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */
	bool IsSubItemChecked(int mainIndex, int subIndex) const;

	/**
	 * Sets the check status of all sub-items of the specified main item.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in] mainIndex       The index of the main item
	 * @param[in]	check			Set to @c true to check the items, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or greater than the main item count.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 */
	result SetAllSubItemsChecked(int mainIndex, bool check);

	/**
	 * Removes all the checked sub-items of the specified main item.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or not less than the main item count.
	 * @exception   E_SYSTEM        A system error has occurred.
	 *
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 */
	result RemoveAllCheckedSubItemsAt(int mainIndex);

	/**
	 * Gets the first sub-item of all the checked sub-items in the main item.
	 *
	 * @since		1.0
	 * @return  The index of the first checked sub-item, @n
	 *          else @c -1 if no sub-item is checked, or the specified main item does not exist
	 */
	int	GetFirstCheckedSubItemIndex(int mainIndex) const;

  /**
	 * Gets the last item of all the checked main items in the %ExpandableList control.
	 *
	 * @since		1.0
	 * @return  The index of the last checked item, @n
	 *          else @c -1 if no main item is checked
   */
	int GetLastCheckedItemIndex(void) const;

  /**
	 * Gets the last sub-item of all the checked sub-items in the main item.
	 *
	 * @since		1.0
	 * @return  The index of the last checked sub-item, @n
	 *          else @c -1 if no sub-item is checked or the specified main item does not exist
   */
	int	GetLastCheckedSubItemIndex(int mainIndex) const;

  /**
	 * Gets the next checked main item from the specified index in the %ExpandableList control.
   *
   * @since		1.0
	 * @return  The index of the next checked main item, @n
	 *          else @c -1 if no more main item after the specified index is checked, or the specified main item does not exist
	 * @param[in] mainIndex  The index of the main item
   */
	int GetNextCheckedItemIndexAfter(int mainIndex) const;

  /**
	 * Gets the next checked sub-item from the specified index in the main item.
   *
   * @since		1.0
	 * @return  The index of the next checked sub-item, @n
	 *          else @c -1 if no more sub-item after the specified index is checked, or the specified sub-item does not exist
	 * @param[in]	mainIndex	The index of the main item, that the sub-item belongs to
	 * @param[in] subIndex  The index of the sub-item in the main item
   */
	int	GetNextCheckedSubItemIndexAfter(int mainIndex, int subIndex) const;

	/**
	 * Gets the index of the sub-item with the specified @c itemId.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in] 	itemId			The item ID
	 * @param[out]  mainIndex       The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex		The index of the sub-item
	 * @exception	E_SUCCESS		The method is successful.	 
	 * @exception	E_OBJ_NOT_FOUND	The specified item is not found.
	 * @remarks 	Note that one or more sub-items can have the same item ID. This method returns the first sub-item among such sub-items.
	 */
	result GetSubItemIndexFromItemId(int itemId, int& mainIndex, int& subIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   x               The x position of the point
	 * @param[in]   y               The y position of the point
	 * @param[out]  mainIndex       The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex        The index of the sub-item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result GetItemIndexFromPosition(int x, int y, int& mainIndex, int& subIndex) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   position        The position of the point
	 * @param[out]  mainIndex       The index of the main item which the sub-item belongs to
	 * @param[out]  subIndex        The index of the sub-item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result GetItemIndexFromPosition(const Osp::Graphics::Point& position, int& mainIndex, int& subIndex) const;

	/**
	 * Gets the index of the first item of the visible items in the %ExpandableList control.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     For more information, see @ref CompExpandableListGetTopDrawnItemIndex "here".
	 * @return		An error code
	 * @param[out]  mainIndex   The main index of the top drawn item
	 * @param[out]	subIndex		The sub-index of the top drawn item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM		A system error has occurred.
	 * @remarks     @c mainIndex is @c -1 if no item is visible. @n
     *				@c subIndex is @c -1 if the top item drawn is a main item.
	 */
	result GetTopDrawnItemIndex(int& mainIndex, int& subIndex) const;

	/**
	 * @page   CompExpandableListGetTopDrawnItemIndex Compatibility for GetTopDrawnItemIndex()
	 * @section CompExpandableListGetTopDrawnItemIndexIssues Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If an %ExpandableList control has no item, the values of @c mainIndex and @c subIndex are not set to @c -1 as specified in the bada API reference 
	 *	  manual.
	 *
	 * @section CompExpandableListGetTopDrawnItemIndexResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */


	/**
	 * Gets the index of the last of the visible items in the %ExpandableList control.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     For more information, see @ref CompExpandableListGetBottomDrawnItemIndex "here".
	 * @return		An error code
	 * @param[out]  mainIndex   The main index of the bottom drawn item
	 * @param[out]	subIndex		The sub-index of the bottom drawn item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     @c mainIndex is @c -1 if no item is visible. @n
     *				@c subIndex is @c -1 if the bottom item drawn is a main item.
	 */
	result GetBottomDrawnItemIndex(int& mainIndex, int& subIndex) const;

	/**
	 * @page   CompExpandableListGetBottomDrawnItemIndex Compatibility for GetBottomDrawnItemIndex()
	 * @section CompExpandableListGetBottomDrawnItemIndexIssues Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If %ExpandableList has no item, the values of @c mainIndex and @c subIndex are not set to @c -1 as specified in the bada API reference manual.
	 *
	 * @section CompExpandableListGetBottomDrawnItemIndexResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */


	/**
	* Sets the background color of this control.
	*
	* @since 				1.1
	* @param[in]    color    The background color
	*/
	void SetBackgroundColor(const Osp::Graphics::Color& color);

  /**
	 * Sets the text to display when there is no item in the %ExpandableList control.
	 *
	 * @since			1.0
	 * @param[in]	text	The text message to be displayed
	 */
  	void SetTextOfEmptyList (const Osp::Base::String &text);

	/**
	 * Sets the color of the text to be displayed when there is no item in the %ExpandableList control.
	 *
	 * @since     1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompExpandableListSetTextColorOfEmptyList "here".
	 *
	 * @param[in]	color	The color of the text to be displayed
	 */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);

    /**
     * @page       CompExpandableListSetTextColorOfEmptyList Compatibility for SetTextColorOfEmptyList()
     *
     * @section    CompExpandableListSetTextColorOfEmptyListIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method ignores the alpha value of the specified color.
     *
     * @section    CompExpandableListSetTextColorOfEmptyListResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

	/**
	 * Gets the color of the text to be displayed when there is no item in the %ExpandableList control.
	 *
	 * @since    1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompExpandableListGetTextColorOfEmptyList "here".
	 *
	 * @return	The color of the text to be displayed
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;

    /**
     * @page       CompExpandableListGetTextColorOfEmptyList Compatibility for GetTextColorOfEmptyList()
     *
     * @section    CompExpandableListGetTextColorOfEmptyListIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The method returns a 16-bit color that is converted from the color specified by SetTextColorOfEmptyList(), omitting the alpha value.
     *
     * @section    CompExpandableListGetTextColorOfEmptyListResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
     * -# The method returns a 32-bit color.
     */


	/**
	 * Scrolls to the bottom of the %ExpandableList control.
	 *
	 * @since		1.0
	 */
	void ScrollToBottom(void);

	/**
	 * Scrolls to the top of the %ExpandableList control.
	 *
	 * @since		1.0
	 */
	void ScrollToTop(void);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the %ExpandableList control.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item
	 * @param[in]   subIndex        The index of the sub-item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @exception   E_INVALID_ARG   The specified item does not exist.
	 */
	result ScrollToTop(int mainIndex, int subIndex);

	/**
	 * Scrolls to the main item at the specified index. @n
	 * The specified main item is drawn at the top of the %ExpandableList control.
 	 *
 	 * @since				1.0
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @exception   E_INVALID_ARG   The specified @c mainIndex is less than @c 0, or not less than the main item count.
	 */
	result ScrollToTop(int mainIndex);

	/**
	 * Draws and shows the item at the specified index in the %ExpandableList control.
	 *
	 * @since				1.0
  	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *			For more information, see @ref CompExpandableListRefreshItem "here".
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item
	 * @param[in]   subIndex        The index of the sub-item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception   E_INVALID_ARG   The specified item does not exist.
	 */
	result RefreshSubItem(int mainIndex, int subIndex);

	/**
	 * Draws and shows the main item at the specified index in the %ExpandableList control.
	 *
	 * @since				1.0
 	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *			For more information, see @ref CompExpandableListRefreshItem "here".
	 * @return			An error code
	 * @param[in]   mainIndex       The index of the main item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @exception   E_INVALID_OPERATION The item has never been drawn before calling this method.
	 * @exception   E_INVALID_ARG   The specified @c mainIndex is invalid.
	 */
	result RefreshItem(int mainIndex);
	
   /**
     * @page   CompExpandableListRefreshItem	Compatibility for RefreshItem()
     * @section CompExpandableListRefreshItemIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -#	If the specified item is not drawn at least one time, calling this method updates the item in a wrong way and returns E_SUCCESS.
     *
     * @section CompExpandableListRefreshItemResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     *
     * If the specified item has never been drawn before calling this method, it does not update the item and returns E_INVALID_OPERATION.
     */
	
	/**
	 * Sets the position and size of the control. @n
	 * Its position is set to (@c x, @c y), its width to @c width, and its height to @c height.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	x				    The x coordinate
	 * @param[in]	y				    The y coordinate
	 * @param[in]	width			    The width
	 * @param[in]	height			    The height
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
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect			    The bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
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
	 *									     Either @c dim.width or @c dim.height is out of range defined by the minimum size and the maximum size.
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
	 * @exception	E_INVALID_ARG            A specified input parameter is invalid.
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
	 * Frees the resources allocated by this control and destroys its native window if it is present.
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
	 * The custom event.
     * @since         1.0
     */		
	Osp::Base::Runtime::IEvent* __pCustomItemEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The custom event adapter.
     * @since         1.0
     */		
	void* __pCustomItemEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item store.
     * @since         1.0
     */		
	Osp::Base::Collection::ArrayList __items;

	friend class ExpandableListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class ExpandableListEx* __pExpandableListEx;

protected:
	friend class ExpandableListImpl;
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
	class ExpandableListImpl* GetImpl(void) const;
};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_EXPANDABLELIST_H_
