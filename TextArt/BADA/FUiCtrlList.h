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
 * @file	FUiCtrlList.h
 * @brief	This is the header file for the %List class.
 *
 * This header file contains the declarations of the %List class and its helper classes.
 */

#ifndef _FUICTRL_LIST_H_
#define _FUICTRL_LIST_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListEnum.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiCtrlBackgroundEnum.h"
#include "FUiIItemEventListener.h"


namespace Osp { namespace Ui { namespace Controls {

/**
 * @class		List
 * @brief		This class defines the common behavior of the %List control.
 * @deprecated 	This class is deprecated. Instead of using this class, use the ListView class.
 * @since		1.0
 *
 * The %List class defines the common behavior of the %List control.
 * A list displays the user selection in the form of a list of items. When an item 
 * on the list is selected or deselected, an item event occurs. It is passed on to 
 * any item event listeners that have registered an interest in item events generated 
 * by this list. 
 * 
 * If an application wants to perform something based on a list being selected and 
 * deselected, it should realize IItemEventListener and register the listener to 
 * receive events from this list, by calling the list's AddItemEventListener() method. 
 * 
 * There are several styles supported with differences in the number of columns, rows and 
 * types of data that can be set. The Construct has a parameter for the size of 
 * all 4 aspects of a list item. If the item has less than 2 rows or 2 columns, you 
 * only need to specify the width and height information relevant to the style selected. 
 * Also, the check style causes some space to be taken up on the right side of the list 
 * item. The framework will try to make room for the check from the right-most column, 
 * so the actual width of each column may be different from what you have set.
 *
 * @image html GUI_listconstruct.png
 * 
 * If the application directly allocates resources, the resources must be deleted 
 * (for example, text or bitmap).
 *
 * Example:
 * 
 * @image html GUI_list.png
 *
 *
 * This is a simple UI application which uses a list control.
 *
 *
 * @code

//Sample Code for ListSample.h
#include <FUi.h>

class ListSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IItemEventListener
{
protected:
    static const int ID_LIST_FIRSTITEM = 101;
    static const int ID_LIST_SECONDITEM = 102;

public:
    virtual result OnInitializing(void);
    virtual void OnItemStateChanged(const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status);
};

//Sample Code for ListSample.cpp
#include "ListSample.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Graphics;
using namespace Osp::Ui::Controls;

result
ListSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates List
    List* pList = new List();
    pList->Construct(Rectangle(0, 0, 480, 500), LIST_STYLE_NORMAL, LIST_ITEM_SINGLE_TEXT, 50, 0, 480, 0);
    pList->AddItemEventListener(*this);

    // Creates a String
    String itemText1(L"Text1");
    String itemText2(L"Text2");

    // Adds an item to the List
    pList->AddItem(&itemText1, null, null, null, ID_LIST_FIRSTITEM);
    pList->AddItem(&itemText2, null, null, null, ID_LIST_SECONDITEM);

    // Adds a List to the Form
    AddControl(*pList);

    // Displays the Form
    Draw();
    Show();

    return r;
}

// Implements an IItemEventListener
void
ListSample::OnItemStateChanged (const Osp::Ui::Control &source, int index, int itemId, Osp::Ui::ItemStatus status)
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
class _EXPORT_CONTROLS_	List :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(List);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	List(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~List(void);

	/**
	 * Initializes this instance of %List with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompListConstruct1_1 "1.1" and @ref CompListConstruct2_0 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	rect	            An instance of the Graphics::Rectangle class @n
	 *						            This instance represents the x and y coordinates of the top-left corner of the created list along with
	 *						            the width and height of the list.
	 * @param[in]	style			    The style set of the list
	 * @param[in]	itemFormat		    The layout of the list items
	 * @param[in]	row1Height		    The height of the first row
	 * @param[in]	row2Height		    The height of the second row
	 * @param[in]	column1Width		The width of the first column
	 * @param[in]	column2Width		The width of the second column
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE	    This instance has already been constructed.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier. @n
	 *				If the given size is less than the minimum size, %List is constructed with the minimum size. @n
	 *				When, %List is constructed with LIST_STYLE_NUMBER style, the maximum number of items supported is @c 99.	 
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
     * @remarks		The minimum size of this control is 92 x 72 on a WVGA screen, 60 x 48 on a HVGA screen and 46 x 36 on a WQVGA screen.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, ListStyle style, ListItemFormat itemFormat, int row1Height, int row2Height, int column1Width, int column2Width);

	/**
	 * @page	CompListConstruct1_1	Compatibility for Construct()
	 * @section	CompListConstruct1_1Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.
	 * -# If a row height is less than 50 in WVGA (or 25 in WQVGA), the item is not highlighted when it is pressed.
	 * -# In case the list is constructed with LIST_STYLE_RADIO/LIST_STYLE_MARK and LIST_ITEM_DOUBLE_XXX, the mark image is drawn at the top-right 
	 *	  position of the list item. But the mark image should be drawn at the center-right position of the list item. 
	 *
	 * @section	CompListConstruct1_1Resolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */
	 
	/**
	 * @page	CompListConstruct2_0	Compatibility for Construct()
	 * @section	CompListConstruct2_0Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Some controls do not return E_INVALID_STATE when the control is already constructed. @n
	 * -# Some controls do not return E_OUT_OF_MEMORY when the control fails to allocate internal resources. @n
	 * -# The width and height of the control must be greater than zero. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust its 
	 *	  bounds to the minimum size. @n
	 * -# On a WVGA screen, the default minimum size is 92x72. @n
	 * -# On a WVGA Screen, the minimum height of rows is 50. @n
	 * -# Negative values are accepted as the values of row2Height and col2Width.
	 *
	 * @section	CompListConstruct2_0Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n  
	 * -# The method returns E_INVALID_STATE when the control is already constructed. @n
	 * -# The method returns E_OUT_OF_MEMORY when the control fails to allocate the internal resources. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control. @n
	 * -# The width and height of the control can be 0, if its minimum width and height is 0. @n
	 * -# On a WVGA screen, the default minimum size is changed to 0x0. The default minimum size in logical pixels is the same as that on a WVGA screen. @n
	 * -# On a WVGA screen, the minimum height of the rows is changed to 48. The minimum height of the rows in logical pixels is the same as that on a WVGA 
	 *	  screen.
	 */

// Operation

	/**
	 * Adds the specified listener instance. @n
	 * The added listener can listen to the item events when they are fired. Only an item event with the ITEM_SELECTED state is fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddItemEventListener(const Osp::Ui::IItemEventListener& listener);

	/**
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveItemEventListener(const Osp::Ui::IItemEventListener& listener);

	/**
	 * Adds the item to the current List instance.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     				For more information, see @ref CompListAddItem "here".
	 *
 	 * @return		An error code
	 * @param[in]	pText1			A pointer to the first string
	 * @param[in]	pText2			A pointer to the second string
	 * @param[in]	pBitmap1		A pointer to the first normal bitmap
	 * @param[in]	pBitmap2		A pointer to the second normal bitmap
	 * @param[in]	itemId			The itemId for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept by the list. 
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when the list item is selected.
	 */
	result	AddItem(const Osp::Base::String* pText1, const Osp::Base::String* pText2, 
		const Osp::Graphics::Bitmap* pBitmap1, const Osp::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @page	CompListAddItem	Compatibility for AddItem()
	 *
	 * @section	CompListAddItemIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# The selected text color of the added items does not change, after the text color is set.
	 *
	 * @section	CompListAddItemResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * Inserts the specified item to list, at the specified index.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompListInsertItemAt "here".
	 * @return		An error code
	 * @param[in]	index			The index at which the item is to be inserted
	 * @param[in]	pText1		    A pointer to the first string
	 * @param[in]	pText2		    A pointer to the second string
	 * @param[in]	pBitmap1	    A pointer to the first normal bitmap
	 * @param[in]	pBitmap2	    A pointer to the second normal bitmap
	 * @param[in]	itemId		    The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the item count.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept by the list. 
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when a list item is selected.
	 */
	result	InsertItemAt(int index, const Osp::Base::String* pText1, const Osp::Base::String* pText2, 
		const Osp::Graphics::Bitmap* pBitmap1, const Osp::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @page	CompListInsertItemAt	Compatibility for InsertItemAt()
	 * @section	CompListInsertItemAtIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# The selected text color of the inserted items does not change, after the text color is set.
	 *
	 * @section	CompListInsertItemAtResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * Sets the contents of the specified item to list at the specified index.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompListSetItemAt "here".
	 * @return		An error code
	 * @param[in]	index			The index at which the contents of the item is to be set
	 * @param[in]	pText1			A pointer to the first string
	 * @param[in]	pText2			A pointer to the second string
	 * @param[in]	pBitmap1		A pointer to the first normal bitmap
	 * @param[in]	pBitmap2		A pointer to the second normal bitmap
	 * @param[in]	itemId			The item ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	The contents of the specified texts and bitmaps are copied and kept in the list. 
	 *			If the size of the text exceeds the displayable area, the text will slide automatically when a list item is selected.
	 */
	result	SetItemAt(int index, const Osp::Base::String* pText1, const Osp::Base::String* pText2, 
		const Osp::Graphics::Bitmap* pBitmap1, const Osp::Graphics::Bitmap* pBitmap2, int itemId = LIST_ITEM_UNSPECIFIED_ID);

	/**
	 * @page	CompListSetItemAt	Compatibility for SetItemAt()
	 * @section	CompListSetItemAtIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# The selected text color of the set items does not change, after the text color is set.
	 *
	 * @section	CompListSetItemAtResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * Removes the item at the specified index of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	index			The index at which the item is to be deleted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than or equal to the item count.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result	RemoveItemAt(int index);

	/**
	 * Removes all the items of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result	RemoveAllItems(void);

	/**
	 * Gets the item count of the list.
	 *
	 * @since		1.0
	 * @return		The number of items in the list
	 */
	int	GetItemCount(void) const;

	/**
	 * Sets the enabled status of the specified item of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index		The index of the list item for which status is to be set
	 * @param[in]	enable	    Set to @c true to enable the item, @n
	 *							else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result SetItemEnabled(int index, bool enable);

	/**
	 * Checks whether the specified item is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the item is enabled, @n
	 *				else @c false
	 * @param[in]	index		The index of the list item
	 */
	bool IsItemEnabled(int index) const;

	/**
	 * Sets the background bitmap image of the focused item.
	 *
	 * @since		1.0
	 * @param[in]	bitmap		The background bitmap of the focused item
	 */
	void SetFocusedItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

    /**
     * Sets the highlighted background image on the rectangle of each list item.
     *
     * @since 		1.1
     * @param[in]	bitmap		The background image
     * @remark		When a user navigates a user interface with directional keys, the selected UI control is highlighted and takes the focus.
     */
    void SetHighlightedItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the background image on the rectangle of each list item.
	 *
	 * @since		1.0
	 * @param[in]	bitmap		The background image
	 */
	void SetNormalItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Gets the index of the top-drawn item of the list.
	 *
	 * @since		1.0
	 * @return		The index of the top-drawn item
	 */
	int	GetTopDrawnItemIndex(void) const;

	/**
	 * Gets the index of the bottom-drawn item of the list.
	 *
	 * @since		1.0
	 * @return		The index of the bottom-drawn item
	 */
	int	GetBottomDrawnItemIndex(void) const;

	/**
	 * Sets the text to be displayed when the list is empty.
	 *
	 * @since		1.0
	 * @param[in]	text	The text message to be displayed
	 */
	void SetTextOfEmptyList (const Osp::Base::String& text);

	/**
	 * Sets the color of the text that is displayed when the list is empty.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompListSetTextColor "here".
	 * @param[in]   	color	The color of the text for an empty List
	 */
	void SetTextColorOfEmptyList(const Osp::Graphics::Color &color);
	
	/**
	 * @page	CompListSetTextColor	Compatibility for SetTextColorOfEmptyList() and SetItemTextColor()
	 *
	 * @section	CompListSetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of specified color.
	 *
	 * @section	CompListSetTextColorResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n        
	 */

	/**
	 * Gets the color of the empty text that is displayed when the list is empty.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompListGetTextColor "here".
	 * @return			The empty text color, @n
	 *					else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetTextColorOfEmptyList(void) const;
	
	/**
	 * @page	CompListGetTextColor	Compatibility for GetTextColorOfEmptyList() and GetItemTextColor()
	 *
	 * @section	CompListGetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color which is converted from the 32-bit color specified by the method which sets the text color, omitting the alpha 
	 *	  value.
	 *
	 * @section	CompListGetTextColorResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	 * -# The method returns a 32-bit color.
	 */

	/**
	* Sets the background color of this control.
	*
	* @since		1.1
	* @param[in]	color	The background color
	*/
	void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Sets the item text color.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompListSetItemTextColor12 "1.2" and @ref CompListSetTextColor "2.0".
	 * @param[in]   	textIndex	The index of the text
	 * @param[in]   	textColor	The color of the text
	 */
	void SetItemTextColor(ListItemText textIndex, const Osp::Graphics::Color &textColor);

	/**
	 * @page	CompListSetItemTextColor12	Compatibility for SetItemTextColor()
	 * @section	CompListSetItemTextColor12Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When SetItemTextColor() is called, the garbage color value is set for the text in the other line.
	 *
	 * @section	CompListSetItemTextColor12Resolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * Gets the text color of item.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *    				For more information, see @ref CompListGetTextColor "here".
	 * @return      	The item text color
	 * @param[in]   	textIndex	The index of the text, @n
	 *								else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Osp::Graphics::Color GetItemTextColor(ListItemText textIndex) const;

	/**
	 * Enables the text slide.
	 *
	 * @since		1.0
	 * @param[in]	textIndex		The text index of the list item format to slide
	 * @remarks		If text slide is enabled, the texts which are too long to fit in the given list item slide show the remnant contents when a user touches 
	 *				the item for a long time.
	 */
	void EnableTextSlide(ListItemText textIndex);

	/**
	 * Disables the text sliding.
	 *
	 * @since	1.0
	 */
	void DisableTextSlide(void);

	/**
	 * Gets the height of the list item.
	 *
	 * @since		1.0
	 * @return		The height of the item
	 */
	int GetItemHeight(void) const;

	/**
	 * Gets the row1 height of the current list
	 *
	 * @since		1.0
	 * @return		The row1 height of the item
	 */
	int GetRow1Height(void) const;

	/**
	 * Gets the row2 height of the current list
	 *
	 * @since		1.0
	 * @return		The row2 height of the item
	 */
	int GetRow2Height(void) const;

	/**
	 * Gets the column1 width of the current list
	 *
	 * @since		1.0
	 * @return		The column1 width of the item
	 */
	int GetColumn1Width(void) const;

	/**
	 * Gets the column2 width of the current list
	 *
	 * @since		1.0
	 * @return		The column2 width of the item
	 */
	int GetColumn2Width(void) const;

	/**
	 * Sets the row1 height of the current List
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompListSetRow1Height1_1 "1.1", @ref CompListSetRow1Height1_2 "1.2", 
	 *					and @ref CompListSetRow1Height2_0 "2.0".
	 * @return		An error code
	 * @param[in]   row1Height		The row1 height of the list item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		In logical pixels, the minimum height of the rows is 48.
	 */
	result SetRow1Height(int row1Height);

	/**
	 * @page	CompListSetRow1Height1_1	Compatibility for SetRow1Height()
	 *
	 * @section	CompListSetRow1HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.
	 * -# If a row height is less than 50 in WVGA (or 25 in WQVGA), the item is not highlighted when it is selected.	 
	 *
	 * @section	CompListSetRow1HeightResolutions	Resolutions
	 * The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n
	 */

	/**
	 * @page	CompListSetRow1Height1_2	Compatibility for SetRow1Height()
	 *
	 * @section	CompListSetRow1HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# After the height of a row is changed, the scroll bar does not indicate its proper position.
	 *
	 * @section	CompListSetRow1HeightResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */
	 
	/**
	 * @page	CompListSetRow1Height2_0	Compatibility for SetRow1Height()
	 *
	 * @section	CompListSetRow1HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# On a WVGA Screen, the minimum height of the rows is 50.
	 *
	 * @section	CompListSetRow1HeightResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# On a WVGA Screen, the minimum height of the rows is changed to 48. The minimum height of the rows in logical pixels is the same as that on a WVGA 
	 *	  screen.
	 */


	/**
	 * Sets the row2 height of the current list.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompListSetRow2Height1_1 "1.1", @ref CompListSetRow2Height1_2 "1.2", 
	 *					and @ref CompListSetRow2Height2_0 "2.0".
	 * @return		An error code
	 * @param[in]	row2Height      The row2 height of the list item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		In logical pixels, the minimum height of the rows is 48.
	 */
	result SetRow2Height(int row2Height);

	/**
	 * @page   CompListSetRow2Height1_1	Compatibility for SetRow2Height()
	 * @section CompListSetRow2HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.
	 * -# If a row height is less than 50 in WVGA (or 25 in WQVGA), the item is not highlighted when it is selected.	 
	 *
	 * @section	CompListSetRow2HeightResolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n
	 */

	/**
	 * @page	CompListSetRow2Height1_2	Compatibility for SetRow2Height()
	 * @section	CompListSetRow2HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# After the height of a row is changed, the scroll bar does not indicate its proper position.
	 *
	 * @section	CompListSetRow2HeightResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */
	 
	/**
	 * @page	CompListSetRow2Height2_0	Compatibility for SetRow2Height()
	 * @section	CompListSetRow2HeightIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# On a WVGA Screen, the minimum height of the rows is 50.
	 *
	 * @section	CompListSetRow2HeightResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# On a WVGA Screen, the minimum height of the rows is changed to 48. The minimum height of the rows in logical pixels is the same as that on a WVGA 
	 *	  screen.
	 */


	/**
	 * Sets the column1 width of the current List
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *					For more information, see @ref CompListSetColumn1Width "here".
	 * @return		An error code
	 * @param[in]   column1Width		The column1 width of the list item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetColumn1Width(int column1Width);

	/**
	 * @page	CompListSetColumn1Width		Compatibility for SetColumn1Width()
	 * @section	CompListSetColumn1WidthIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.	 
	 *
	 * @section	CompListSetColumn1WidthResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */

	/**
	 * Sets the column2 width of the current List
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *					For more information, see @ref CompListSetColumn2Width "here".
	 * @return		An error code
	 * @param[in]   column2Width	The column2 width of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumn2Width(int column2Width);

	/**
	 * @page	CompListSetColumn2Width	Compatibility for SetColumn2Width()
	 * @section	CompListSetColumn2WidthIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n 
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.
	 *
	 * @section	CompListSetColumn2WidthResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */

	/**
	 * Sets the check status of the specified item of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   index       The index of the list
	 * @param[in]   check       The check status
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
	 *
	 * @remarks     This method can only be used when the style of the list allows selection.
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * Checks whether the specified item of the list is checked.
	 *
	 * @since		1.0
	 * @return		@c true if the item is checked, @n
	 *				else @c false
	 * @param[in]	index		The index of the list item
	 *
	 * @remarks		This method can only be used when the style of the list allows selection.
	 */
	bool IsItemChecked(int index) const;

	/**
	 * Sets the checked status of all the items of the list.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompListSetAllItemsChecked "here".
	 * @return		An error code
	 * @param[in]	check			Set to @c true to check all the items, @n
	 *								else @c false 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 */
	result SetAllItemsChecked(bool check);
	
	
	/**
	 * @page	CompListSetAllItemsChecked	Compatibility for SetAllItemsChecked()
	 * @section CompListSetAllItemsCheckedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When the specified item is disabled, the checked status of the item is not changed.
	 *
	 * @section	CompListSetAllItemsCheckedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	

	/**
	 * Removes all the checked items of the list.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *     				For more information, see @ref CompListRemoveAllCheckedItems "here".
	 * @return  	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM 		A system error has occurred.
	 *
	 * @remarks	This method can only be used when the style of the list allows multiple selections.
	 */
	result RemoveAllCheckedItems(void);

	/**
	 * @page	CompListRemoveAllCheckedItems	Compatibility for RemoveAllCheckedItems()
	 *
	 * @section	CompListRemoveAllCheckedItemsIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# The RemoveAllCheckedItems() method removes all the checked items. But the memory allocated to the checked items containing the Bitmaps is not freed.
	 *
	 * @section	CompListRemoveAllCheckedItemsResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */


	/**
	 * Gets the index of the first checked item from the list.
	 *
	 * @since		1.0
	 * @return		The index of the first checked item
	 *
	 * @remarks 		This method can only be used when the style of the list allows multiple selections.
	 */
	int	GetFirstCheckedItemIndex(void) const;

	/**
	 * Gets the index of the last checked item from the list.
	 *
	 * @since		1.0
	 * @return		The index of the last checked item
	 *
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 */
	int	GetLastCheckedItemIndex(void) const;

	/**
	 * Gets the index of the next checked item after the specified index from the list.
	 *
	 * @since		1.0
	 * @return		The index of the next checked item
	 * @param[in]	index		The index of the item
	 *
	 * @remarks		This method can only be used when the style of the list allows multiple selections.
	 */
	int	GetNextCheckedItemIndexAfter(int index) const;

	/**
	 * Gets the index of the item with the specified item ID.
	 *
	 * @since		1.0
	 * @return		The index of the item
	 * @param[in]	itemId		The item ID of the list
	 * @remarks		The method returns -1 when there is no list item with the specified item ID.
	 */
	int GetItemIndexFromItemId(int itemId);

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   x   The x position of the point
	 * @param[in]   y   The y position of the point
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified item position.
	 *
	 * @since		1.0
	 * @return		The index of the item, @n
	 *				else @c -1 if there is no list item at the specified position
	 * @param[in]   position    The position of the point
	 */
	int GetItemIndexFromPosition(const Osp::Graphics::Point& position) const;

	/**
	 * Gets the item ID of the item at the specified index.
	 *
	 * @since		1.0
	 * @return      The ID of the item, @n
	 *				else @c -1 if there is no list item at the specified index
	 * @param[in]   index		The index of the list item
	 */
	int GetItemIdAt(int index) const;

	/**
	 * Scrolls to the bottom of the List. 
	 *
	 * @since		1.0
	 */
	void ScrollToBottom (void);

	/**
	 * Scrolls to the top of the List. 
	 *
	 * @since		1.0
	 */
	void ScrollToTop (void);

	/**
	 * Scrolls to the item at the specified index. @n
	 * The specified item is drawn at the top of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	result ScrollToTop (int index);

	/**
	 * Draws and shows the item of the list.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the list item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	result RefreshItem(int index);

	/**
	 * Sets the position and size of the control. @n
	 * Its relative position is set to (x, y), its width to @c width, and its height to @c height.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompListSetBounds11 "1.1" and @ref CompListSetBounds20 "2.0".
	 * @return		An error code
	 * @param[in]	x				    The x coordinate
	 * @param[in]	y				    The y coordinate
	 * @param[in]	width			    The width
	 * @param[in]	height			    The height
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).  
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remark		If the given size is less than the minimum size, the list is resized to the minimum size.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			Construct ()
	 * @see			SetPosition(), SetSize()
	 * @see			GetBounds()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompListSetBounds11 "1.1" and @ref CompListSetBounds20 "2.0".
	 * @return		An error code
	 * @param[in]	rect			    The bounds of the control
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG	    The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).  
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remark		If the given size is less than the minimum size, the list is resized to the minimum size.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			Construct ()
	 * @see			SetPosition(), SetSize()
	 * @see			GetBounds()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * @page	CompListSetBounds11	Compatibility for SetBounds()
	 *
	 * @section	CompListSetBounds11Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.
	 *
	 * @section	CompListSetBounds11Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */
	 
	/**
	 * @page	CompListSetBounds20	Compatibility for SetBounds()
	 *
	 * @section	CompListSetBounds20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The methods return E_INVALID_OPERATION instead of E_INVALID_STATE when the control is not constructed. @n
	 * -# It is recommended to override all the bounds-related methods to define control-specific behaviors. @n
	 *	  For example, when overriding SetSize() without overriding SetBounds(), unexpected results can occur. @n
	 * -# The width and height of the control must be greater than 0, or SetSize() and SetBounds() return E_INVALID_ARG exception. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust 
	 *	  their bounds to the minimum size.
	 *
	 * @section	CompListSetBounds20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The methods return E_INVALID_STATE when the control is not constructed. @n
	 * -# The methods must not be overridden because the bounds of the control is dependent on the following properties: IsMovable(), IsResizable(), 
	 *	  GetMinimumSize(), and GetMaximumSize(). @n
	 *	  The CustomControlBase class is added to make the custom controls. The CustomControlBase::PrepareBoundsChange() and 
	 *	  CustomControlBase::OnBoundsChanged() will be overridden to define the control-specific behaviors. @n
	 * -# The width and height of the control can be zero, if its minimum width and height is 0.
	 * -# SetSize() and SetBounds() return E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum 
	 *	  size of the control.	 
	 */

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompListSetSize11 "1.1" and @ref CompListSetSize20 "2.0".
	 * @return		An error code
	 * @param[in]	size			    The size of the control
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG	    The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).  
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remark		If the given size is less than the minimum size, the list is resized to the minimum size.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			Construct ()
	 * @see			SetBounds(), SetPosition()
	 * @see			GetSize()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize (const Osp::Graphics::Dimension &size);

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompListSetSize11 "1.1" and @ref CompListSetSize20 "2.0".
	 * @return		An error code
	 * @param[in]	width			    The width of the control
	 * @param[in]	height			    The height of the control
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG	    A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).  
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remark		If the given size is less than the minimum size, the list is resized to the minimum size.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			Construct ()
	 * @see			SetBounds(), SetPosition()
	 * @see			GetSize()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize (int width, int height);

	/**
	 * @page	CompListSetSize11	Compatibility for SetSize()
	 *
	 * @section	CompListSetSize11Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n 
	 * -# When selecting an item after resizing the list horizontally, a crash may occur.	 
	 *
	 * @section	CompListSetSize11Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */

	/**
	 * @page	CompListSetSize20	Compatibility for SetSize()
	 *
	 * @section	CompListSetSize20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The methods return E_INVALID_OPERATION instead of E_INVALID_STATE when the control is not constructed.
	 * -# It is recommended to override all the bounds-related methods to define control-specific behaviors. @n
	 *	  For example, when overriding SetSize() without overriding SetBounds(), unexpected results can occur.
	 * -# The width and height of the control must be greater than @c 0, or SetSize() and SetBounds() return E_INVALID_ARG exception.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust its 
	 *	  bounds to the minimum size.
	 *
	 * @section	CompListSetSize20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The methods return E_INVALID_STATE when the control is not constructed.
	 * -# The methods must not be overridden because the bounds of the control is dependent on the following properties: IsMovable(), IsResizable(), 
	 *	  GetMinimumSize(), GetMaximumSize(). @n
	 *	  The CustomControlBase class is added to make the custom controls. CustomControlBase::PrepareBoundsChange() and 
	 *	  CustomControlBase::OnBoundsChanged() will be overridden to define the control-specific behaviors. @n
	 * -# The width and height of the control can be 0, if its minimum width and height is @c 0.
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
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item event.
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent* __pItemEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item event adapter.
     * @since         1.0
     */	
	void* __pItemEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The list item format.
     * @since         1.0
     */	
	ListItemFormat	__itemFormat;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The row 1 height.
     * @since         1.0
     */	
	int	__itemRow1Height;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The row 2 height.
     * @since         1.0
     */	
	int	__itemRow2Height;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The column 1 width.
     * @since         1.0
     */	
	int	__itemColumn1Width;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The column 2 width.
     * @since         1.0
     */	
	int	__itemColumn2Width;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The check box width.
     * @since         1.0
     */	
	int	__checkBoxWidth;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The text slide line.
     * @since         1.0
     */	
	int	__itemTextSlideLine;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The text slide column.
     * @since         1.0
     */	
	int	__itemTextSlideColumn;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item background bitmap.
     * @since         1.0
     */	
	Osp::Base::Collection::ArrayList __itemBgBitmap1;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The item background bitmap.
     * @since         1.0
     */	
	Osp::Base::Collection::ArrayList __itemBgBitmap2;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The focused item background bitmap.
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__focusedItemBgBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The normal item background bitmap.
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__normalItemBgBitmap;

	friend class ListEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class ListEx* __pListEx;

protected:
	friend class ListImpl;
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
	class ListImpl* GetImpl(void) const;
};
}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_LIST_H_
