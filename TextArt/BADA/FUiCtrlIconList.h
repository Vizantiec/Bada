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
 * @file	FUiCtrlIconList.h
 * @brief	This is the header file for the %IconList class. 
 *
 * This header file contains the declarations of the %IconList class and its helper classes.
 */
#ifndef _FUICTRL_ICON_LIST_H_
#define _FUICTRL_ICON_LIST_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlIconListEnum.h"
#include "FUiCtrlListEnum.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiIItemEventListener.h"

// forward declarations
namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	IconList
 * @brief 	This class defines the common behavior of an %IconList control.
 *
 * @deprecated	This class is deprecated. Instead of using this class, use the IconListView class.
 * @since		1.0
 *
 * @remarks	%IconList can display a maximum of 64 items on the screen at once (for example, 8 x 8 grid).
 * %IconList is not drawn properly when it is resized.
 *
 * The %IconList class can be used to display a list of bitmap images and icons. When 
 * a list item (or icon) is pressed by the user, an item event is generated and the 
 * item event listeners are called to notify the change in the
 * item's state (ITEM_CHECKED, ITEM_UNCHECKED and ITEM_SELECTED).
 * 
 * When %IconList's style is set as ICON_LIST_STYLE_RADIO, only one item
 * can be "selected" at a time. Whereas, if ICON_LIST_STYLE_MARK is set as 
 * the %IconList's style, multiple items can be "checked" at the same time. 
 * However, no item can be selected or checked when %IconList's style is set as 
 * ICON_LIST_STYLE_NORMAL.
 *
 * When a list item is selected by the user, the "focused" bitmap image is displayed 
 * instead of item's "normal" bitmap image.
 *
 * Please note that any image resources (bitmaps) that are allocated by application 
 * must be freed after they are passed to Additem()/InsertItem()/SetItem() to 
 * minimize memory usage. @n
 * 
 * Example:
 * 
 * @image html GUI_iconlist.png
 *
 *@n
 * This is a simple UI application which uses a icon list control.
 *
 *
 * @code

//Sample Code for IconListSample.h
#include <FUi.h>

class IconListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IItemEventListener
{
public:
    IconListSample(void)
    :__pIconList(null){}

protected:
    static const int ID_LIST_FIRSTITEM = 101;
    static const int ID_LIST_SECONDITEM = 102;

    Osp::Graphics::Bitmap* GetBitmapN(void);

public:
    virtual result OnInitializing(void);
    virtual void OnItemStateChanged(const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status);

private:
    Osp::Ui::Controls::IconList *__pIconList;
};

//Sample Code for IconListSample.cpp
#include "IconListSample.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
IconListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates Bitmaps
    Bitmap *pBitmapNormal1  = GetBitmapN();
    Bitmap *pBitmapFocused1 = GetBitmapN();
    Bitmap *pBitmapNormal2  = GetBitmapN();
    Bitmap *pBitmapFocused2 = GetBitmapN();

    // Creates a String
    String itemText1(L"Item1");
    String itemText2(L"Item2");

    // Creates a IconList
    __pIconList = new IconList();
    __pIconList->Construct(Rectangle(0, 100, 480, 500), ICON_LIST_STYLE_NORMAL, 96, 96);
    __pIconList->AddItemEventListener(*this);

    // Adds an item to the IconList
    __pIconList->AddItem(&itemText1, pBitmapNormal1, pBitmapFocused1, ID_LIST_FIRSTITEM);
    // Add a item into the IconList
    __pIconList->AddItem(&itemText2, pBitmapNormal2, pBitmapFocused2, ID_LIST_SECONDITEM);

    // Adds an IconList to the Form
    AddControl(*__pIconList);

    // Displays the Form
    Draw();
    Show();

    // Deallocates a Bitmap
    delete pBitmapNormal1;
    delete pBitmapFocused1;
    delete pBitmapNormal2;
    delete pBitmapFocused2;

    return r;
}

Bitmap*
IconListSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

// Implements an IItemEventListener
void
IconListSample::OnItemStateChanged (const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status)
{
    switch (itemId)
    {
        case ID_LIST_FIRSTITEM:
            // Todo:
            break;
        case ID_LIST_SECONDITEM:
            // Todo:
            break;
        default:
            break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ IconList 
	: public Osp::Ui::Control
{
	DECL_CLASSTYPE(IconList);
public:

// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	IconList(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IconList(void);

	/**
	 * Initializes this instance of %IconList with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompIconListConstruct12 "1.2" and @ref CompIconListConstruct20 "2.0".
	 * @return		An error code
	 * @param[in]	rect	        An instance of the Graphics::Rectangle class @n
	 *						        This instance represents the X and Y coordinates of the top-left corner of the created %IconList along with
	 *						        the width and height. @n
	 * @param[in]	style			The style set of %IconList
	 * @param[in] 	itemWidth		The width of the items in the %IconList
	 * @param[in]	itemHeight		The height of the items in the %IconList
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 * @remarks		The %IconList cannot display more than 64 items on screen at once.	 
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum and maximum size.
     * @remarks		The minimum size of this control is 0 x 0.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, IconListStyle style, int itemWidth, int itemHeight);

	/**
	 * @page	CompIconListConstruct12	Compatibility for Construct()
	 * @section	CompIconListConstruct12Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When displaying more than 64 items on screen at once, a crash may occur.
	 *
	 * @section	CompIconListConstruct12Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	 
	/**
	 * @page	CompIconListConstruct20	Compatibility for Construct()
	 * @section	CompIconListConstruct20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	 * -# Some controls do not return E_INVALID_STATE when the control is already constructed. @n
	 * -# Some controls do not return E_OUT_OF_MEMORY when the control fails to allocate internal resources. @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 *
	 * @section	CompIconListConstruct20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	 
	 * -# The method returns E_INVALID_STATE when the control is already constructed.
	 * -# The method returns E_OUT_OF_MEMORY when the control fails to allocate internal resources.
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0.
	 */

// Operation
    /**
     * Adds a listener instance. @n
	 * The added listener can listen to item events when they are fired. Only an item event with the ITEM_SELECTED state is fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be added
	 */
	void AddItemEventListener(const Osp::Ui::IItemEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be removed
	 */
	void RemoveItemEventListener(const Osp::Ui::IItemEventListener& listener);

	/**
	 * Sets the background bitmap of the %IconList control.
	 *
	 * @since		1.0
	 * @param[in]	bitmap		The background bitmap
	 */
	void SetBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the top and left margins of the items for %IconList.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompIconListSetMargin "here".
	 * @return		An error code
	 * @param[in]	topMargin			The top margin of the background bitmap
	 * @param[in]	leftMargin			The left margin of the background bitmap
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The %IconList cannot display more than 64 items on screen at once.	 
	 */
	result SetMargin(int topMargin, int leftMargin);
		
	/**
	 * @page	CompIconListSetMargin	Compatibility for SetMargin()
	 * @section	CompIconListSetMarginIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n 
	 * -# When displaying more than 64 items on screen at once, a crash may occur.
	 *
	 * @section	CompIconListSetMarginResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
		
	/**
	 * Gets the top margin of the items for the %IconList control.
	 *
	 * @since		1.0
	 * @return		The top margin of the background bitmap
	 */
	int GetTopMargin(void) const;

	/**
	 * Gets the left margin of the items for the %IconList control.
	 *
	 * @since		1.0
	 * @return		The left margin of the background bitmap
	 */
	int GetLeftMargin(void) const;
		
	/**
	 * Adds a list item with the specified text and bitmap images to the %IconList control.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListAddItem "here".
	 * @return		An error code
	 * @param[in] 	pText			The item text
	 * @param[in] 	pNormalBitmap   The default bitmap image
	 * @param[in] 	pFocusedBitmap  The displayed bitmap image when an item is selected
	 * @param[in]	itemId		    The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	    The contents of the specified texts and bitmaps are copied and kept by %List.
	 *				To display text in multi-lines or to denote the end of line, use '\\n'.
	 */
	result AddItem(const Osp::Base::String* pText, const Osp::Graphics::Bitmap* pNormalBitmap, const Osp::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);
	
	/**
	 * @page	CompIconListAddItem	Compatibility for AddItem()
	 * @section	CompIconListAddItemIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	 * -# The method scales the specified input bitmaps to the size of %IconList item before creating their copies.
	 *
	 * @section	CompIconListAddItemResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n  
	 */
	
	/**
	 * Inserts the specified text and bitmap item in the specified index of the specified %IconList.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListInsertItemAt "here".
	 * @return		An error code
	 * @param[in]	index			The item text
	 * @param[in]	pText			The text item to be added
	 * @param[in]	pNormalBitmap	The default bitmap image
	 * @param[in]	pFocusedBitmap	The displayed bitmap image when an item is selected
	 * @param[in]	itemId			The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The contents of the specified texts and bitmaps are copied and kept by IconList.
	 *				To display text in multi-lines or to denote the end of line, use '\\n'.
	 */
	result InsertItemAt(int index, const Osp::Base::String* pText, const Osp::Graphics::Bitmap* pNormalBitmap, const Osp::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);
	
	/**
	 * @page	CompIconListInsertItemAt	Compatibility for InsertItemAt()
	 * @section	CompIconListInsertItemAtIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	 * -# The method scales the specified input bitmaps to the size of IconList item before creating their copies.
	 *
	 * @section	CompIconListInsertItemAtResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n  
	 */
	
	/**
	 * Sets the specified text and bitmap item in the specified index of the specified %IconList.
	 *
	 * @since		1.0
 	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListSetItemAt "here".
	 * @return		An error code
	 * @param[in]	index			The index of the List item
	 * @param[in]	pText			The item text	
	 * @param[in]	pNormalBitmap	The default bitmap image
	 * @param[in]	pFocusedBitmap	The displayed bitmap image when an item is selected
	 * @param[in]	itemId		    The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The contents of the specified texts and bitmaps are copied and kept by %IconList.
	 *			    Call RefreshItem() to update item images.  
	 *				To display text in multi-lines or to denote the end of line, use '\\n'.
	 */
	result SetItemAt(int index, const Osp::Base::String* pText, const Osp::Graphics::Bitmap* pNormalBitmap, const Osp::Graphics::Bitmap* pFocusedBitmap, int itemId = LIST_ITEM_UNSPECIFIED_ID);
	
	/**
	 * @page	CompIconListSetItemAt	Compatibility for SetItemAt()
	 *
	 * @section	CompIconListSetItemAtIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method scales the specified input bitmaps to the size of IconList item before creating their copies.
	 *
	 * @section	CompIconListSetItemAtResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n  
	 */

	/**
	 * Removes the item at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the IconList item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveItemAt(int index);
	
	/**
	 * Removes all items of the %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAllItems(void);
	
	/**
	 * Gets the column count of the %IconList control.
	 *
	 * @since		1.0
	 * @return		The count of all the items of the %IconList control
	 */
	int GetColumnCount(void) const;
	
	/**
	 * Gets the item count of the %IconList control.
	 *
	 * @since		1.0
	 * @return		The count of all the items of the %IconList control
	 */
	int GetItemCount(void) const;
	
	/**
	 * Sets the checked status of the specified item of the %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index		The index of the %IconList item
	 * @param[in]	check		Set to @c true to check the specified item, @n
	 *							else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 *
	 * @remarks	This method can only be used when the style of the list allows selection (ICON_LIST_STYLE_MARK).
	 * @remarks	The method only changes the state of the list item. %IconList needs to be redrawn (Draw() and Show()) to reflect the change on the screen.
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * Checks whether the specified item of the %IconList control is checked.
	 *
	 * @since		1.0
	 * @return		@c true if the specified item is checked, @n
	 *				else @c false
	 * @param[in]	index	The index of the list item
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */
	bool IsItemChecked(int index) const;

	/**
	 * Sets the checked status of all the items of the %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	check			Set to @c true to check all the items, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections (ICON_LIST_STYLE_MARK).
	 * @remarks		The method only changes the states of the list items. %IconList needs to be redrawn (Draw() and Show()) to reflect the changes on the screen.
	 */
	result SetAllItemsChecked(bool check);

	/**
	 * Removes all checked items of the %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 */
	result	RemoveAllCheckedItems(void);

	/**
	 * Gets the first checked items of the %IconList control.
	 *
	 * @since		1.0
	 * @return		The index of the %IconList item
	 */
	int	GetFirstCheckedItemIndex(void) const;

    /**
     * Gets the last checked items of the %IconList control.
     *
     * @since		1.0
     * @return		The index of the %IconList item
     */
	int	GetLastCheckedItemIndex(void) const;

    /**
     * Gets the next checked items at the specified index of the %IconList control.
     *
     * @since		1.0
     * @return		The index of the list item
     * @param[in] 	index	The index of the %IconList item
     */
    int	GetNextCheckedItemIndexAfter(int index) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   x   	The x position of the point
	 * @param[in]   y   	The y position of the point
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]	position	The position of the point
	 */
	int GetItemIndexFromPosition(const Osp::Graphics::Point& position) const;

	/**
	 * Sets a horizontal alignment of the text in the current %IconList control.
	 *	 
	 * @since		1.0
	 * @param[in]	alignment	The horizontal alignment of the text
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Sets a vertical alignment of the text of the current %IconList control.
	 *	 
	 * @since		1.0
	 * @param[in] 	alignment	The vertical alignment of the icon and text
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

	/**
	 * Gets the horizontal alignment of the text of the current %IconList control.
	 *
	 * @since		1.0
	 * @return		The horizontal alignment of the %IconList control
	 */
	HorizontalAlignment	GetTextHorizontalAlignment(void) const;

	/**
	 * Gets the vertical alignment of the text of the current %IconList control.
	 *
	 * @since		1.0
	 * @return		The vertical alignment of the %IconList control
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	* Sets the background color of the %IconList control.
	*
	* @since 		1.1
	* @param[in]	color	The background color
	*/
	void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Sets the text to display when the %IconList control contains no item.
	 *
	 * @since		1.0
	 * @param[in]	text	The text 
	 */
	void SetTextOfEmptyList(const Osp::Base::String &text);

	/**
	 * Sets the color of the text that is displayed when the %IconList control contains no item.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListSetTextColor "here".
	 * @param[in]	color	The color of the text   	 	 
	 */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);
	
	/**
	 * @page	CompIconListSetTextColor	Compatibility for SetTextColorOfEmptyList() and SetItemTextColor()
	 *
	 * @section	CompIconListSetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of specified color.
	 *
	 * @section	CompIconListSetTextColorResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n        
	 */

	/**
	 * Gets the color of the text that is displayed when the %IconList control contains no item.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListGetTextColor "here".
	 *
	 * @return		The color of the text, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;
	
	/**
	 * @page	CompIconListGetTextColor	Compatibility for GetTextColorOfEmptyList() and GetItemTextColor()
	 *
	 * @section	CompIconListGetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color which is converted from the 32-bit color specified by the text color setting methods, omitting the alpha value.
	 *
	 * @section	CompIconListGetTextColorOfEmptyListResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The method returns a 32-bit color.
	 */

	/**
	 * Sets the text color of the item.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListSetTextColor "here".
	 * @param[in]	textColor	The color of the text 
	 */
	void SetItemTextColor(const Osp::Graphics::Color &textColor);

	/**
	 * Gets the text color of the item.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompIconListGetTextColor "here".
	 *
	 * @return		The color of the text, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs	
	 */
	Osp::Graphics::Color GetItemTextColor(void) const;
	
	/**
	 * @page	CompIconListGetItemTextColor	Compatibility for GetItemTextColor()
	 *
	 * @section	CompIconListGetItemTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color which is converted from the color specified by SetTextColor(), omitting the alpha value.
	 *
	 * @section	CompIconListGetItemTextColorResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The method returns a 32-bit color.
	 */

	/**
	 * Sets the size of the text of the current %IconList control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompIconListSetTextSize "here".
	 * @param[in]	size			The size of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If @c size is less than the minimum size, this method fails. The minimum font size is 6 on devices of high screen density.
	 */
	void SetTextSize(int size);
	
	/**
	 * @page	CompIconListSetTextSize	Compatibility for SetTextSize()
	 *
	 * @section	CompIconListSetTextSizeIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The minimum size of the text is 9(for WVGA)/5(for WQVGA).
	 * -# When the text size is lower than the minimum size, it is set to the minimum size automatically.
	 *
	 * @section	CompIconListSetTextSizeResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The minimum size of the text is 6(for High Screen Density), 4(for Middle Screen Density), and 3(for Low Screen Density).
	 * -# When the text size is lower than the minimum size, this method fails generating E_INVALID_ARG.
	 */

	/**
	 * Gets the size of the text of the current %IconList control.
	 *
	 * @since	1.0
	 * @return 	The size of the text of the current %IconList control
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the index of the item with the specified item ID.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item with the specified item ID
	 * @param[in]	itemId		The item ID of the list item
	 */
	int GetItemIndexFromItemId(int itemId) const;

	/**
	 * Gets the item ID of the item at the specified index.
	 *
	 * @since		1.0
	 * @return		The item ID of the item, @n
	 *				else @c -1 if there is no list item at the specified index
	 * @param[in]	index		The index of the list item
	 */
	int GetItemIdAt(int index) const;

	/**
	 * Sets the position of the checkbox of the current %IconList control.
	 *	 
	 * @since		1.0
	 * @param[in]	position	The position of the checkbox of the current %IconList control
	 * @remarks		This method changes the position of the checkbox image displayed for the "selected" item(s), when the style of %IconList is either 
	 *				ICON_LIST_STYLE_RADIO or ICON_LIST_STYLE_MARK.
	 */
	void SetCheckBoxPosition(IconListCheckBoxPosition position);

	/**
	 * Gets the position of the checkbox of the current %IconList control.
	 *
	 * @since		1.0
	 * @return		The position of the checkbox of the current %IconList control
	 */
    IconListCheckBoxPosition GetCheckBoxPosition(void) const;

	/**
	 * Enables or disables focus animation.
	 *
	 * @since		1.0
	 * @param[in]	enable	Set to @c true to enable focus animation, @n
	 * 						else @c false
	 * @remarks		If a separate Focused Bitmap is to be used, the animation effect must be disabled.
	 */
	void SetFocusAnimationEnabled(bool enable);

	/**
	 * Scrolls to the bottom of the %IconList control. 
	 *
	 * @since	1.0
	 */
	void ScrollToBottom (void);

	/**
	 * Scrolls to the top of the %IconList control.
	 *
	 * @since	1.0
	 */
	void ScrollToTop (void);

	/**
	 * Scrolls the specified item to the top of %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	itemIndex		The index of the item 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	result ScrollToTop (int itemIndex);

	/**
	 * Draws and shows the item of %IconList control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the %IconList item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 */
	result RefreshItem(int index);

	/**
	 * Sets the position and size of the control. @n
	 * The position is set to (x, y), the width to @c width, and the height to @c height.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompIconListSetBounds12 "1.2" and @ref CompIconListSetBounds20 "2.0".
	 * @return		An error code
	 * @param[in]	x					The x position of the control
	 * @param[in]	y					The y position of the control
	 * @param[in]	width				The width of the control
	 * @param[in]	height				The height of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).
	 * @remarks		The %IconList cannot display more than 64 items on screen at once. 
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			SetSize()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompIconListSetBounds12 "1.2" and @ref CompIconListSetBounds20 "2.0".
	 * @return		An error code
	 * @param[in]	rect				The bounds of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The %IconList cannot display more than 64 items on screen at once. 
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			SetSize()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * @page	CompIconListSetBounds12	Compatibility for SetBounds()
	 * @section	CompIconListSetBounds12Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issues: @n 
	 * -# %IconList is not drawn properly when it is resized. @n
	 * -# When displaying more than 64 items on screen at once, a crash may occur.
	 *
	 * @section CompIconListSetBounds12Resolutions Resolutions 
	 * The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	 
	/**
	 * @page	CompIconListSetBounds20	Compatibility for SetBounds()
	 *
	 * @section	CompIconListSetBounds20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The methods return E_INVALID_OPERATION instead of E_INVALID_STATE when the control is not constructed. @n
	 * -# It is recommended to override all the bounds-related methods to define control-specific behaviors. @n
	 *    For example, when overriding SetSize() without overriding SetBounds(), unexpected results can occur.
	 * -# The width and height of the control must be greater than @c 0, or SetSize() and SetBounds() return E_INVALID_ARG exception.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 *
	 * @section	CompIconListSetBounds20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The methods returns E_INVALID_STATE when the control is not constructed. @n
	 * -# The methods must not be overridden because the bounds of the control are dependent on the following properties: IsMovable(), IsResizable(), 
	 *	  GetMinimumSize(), and GetMaximumSize(). @n
	 *	  The CustomControlBase class is added to make custom controls. CustomControlBase::PrepareBoundsChange() and CustomControlBase::OnBoundsChanged() 
	 *	  will be overridden to define the control-specific behaviors. @n
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0. @n
	 * -# SetSize() and SetBounds() return E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum 
	 *	  size of the control.
	 */
	 

	/**
	 * Sets the size of the control. @n
	 * Its width is set to @c width, and its height to @c height.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompIconListSetSize12 "1.2" and @ref CompIconListSetSize20 "2.0".
	 * @return		An error code
	 * @param[in]	width				The width
	 * @param[in]	height				The height
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @remarks		Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	 *				%IconList is not drawn properly when it is resized. @n
	 *				The IconList cannot display more than 64 items on screen at once. @n
	 *				Note that the issues above are resolved with bada API version 1.2.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			SetBounds()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);

	/**
	 * Sets the size of the control. @n
	 * Its width is set to @c size.width, and its height to @c size.height.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompIconListSetSize12 "1.2" and @ref CompIconListSetSize20 "2.0".
	 * @return		An error code
	 * @param[in]	size				The width and height
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The IconList cannot display more than 64 items on screen at once. 
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			SetBounds()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
	 * @page	CompIconListSetSize12	Compatibility for SetSize()
	 *
	 * @section	CompIconListSetSize12Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	 * -# %IconList is not drawn properly when it is resized. @n
	 * -# When displaying more than 64 items on screen at once, a crash may occur.
	 *
	 * @section	CompIconListSetSize12Resolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	 
	/**
	 * @page	CompIconListSetSize20	Compatibility for SetSize()
	 *
	 * @section	CompIconListSetSize20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The methods return E_INVALID_OPERATION instead of E_INVALID_STATE when the control is not constructed. @n
	 * -# It is recommended to override all the bounds-related methods to define control-specific behaviors. @n
	 *	  For example, when overriding SetSize() without overriding SetBounds(), unexpected results can occur. @n
	 * -# The width and height of the control must greater than @c 0, or SetSize() and SetBounds() return E_INVALID_ARG exception. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 *
	 * @section	CompIconListSetSize20Resolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The methods return E_INVALID_STATE when the control is not constructed. @n
	 * -# The methods must not be overridden because the bounds of the control are dependent on the following properties: IsMovable(), IsResizable(), 
	 *	  GetMinimumSize(), and GetMaximumSize(). @n
	 *	  The CustomControlBase class is added to make custom controls. CustomControlBase::PrepareBoundsChange() and CustomControlBase::OnBoundsChanged() 
	 *	  will be overridden to define the control-specific behaviors. @n
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0.
	 * -# SetSize() and SetBounds() return E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum 
	 *	  size of the control.	 
	 */

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the control.
	 *
	 * @since		1.0
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
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item event
     * @since         1.0
     */		
	Osp::Base::Runtime::IEvent* __pItemEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item event adapter
     * @since         1.0
     */		
	void* __pItemEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The background bitmap
     * @since         1.0
     */		
	Osp::Graphics::Bitmap*	__pBackgroundBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item store
     * @since         1.0
     */		
	Osp::Base::Collection::ArrayList	__items;	

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The font
     * @since         1.0
     */		
	void* __pFont;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Width of the item
     * @since         1.0
     */		
	int __itemWidth;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Height of the item
     * @since         1.0
     */		
	int __itemHeight;

	friend class IconListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class IconListEx* __pIconListEx;

protected:
	friend class IconListImpl;
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
	class IconListImpl* GetImpl(void) const;
};
}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_ICON_LIST_H_

