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
 * @file	FUiCtrlCustomListItem.h
 * @brief	This is the header file for the %CustomListItem class.
 *
 * This header file contains the declarations of the %CustomListItem class and its helper classes.
 */

#ifndef _FUICTRL_CUSTOMLISTITEM_H_
#define _FUICTRL_CUSTOMLISTITEM_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlCustomListItemFormat.h"
#include "FUiCtrlICustomListElement.h"

namespace Osp { namespace Ui { namespace Controls {
/**
 * @class	  CustomListItem
 * @brief   This class defines the common behavior of an item of the %CustomList control. 
 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class.
 * @since		1.0
 *
 * The %CustomListItem class represents a custom list item which is the unit of 
 * handling of a custom list. A custom list item is composed of one or more elements, 
 * which can be texts and bitmaps. Custom drawable elements are also supported via 
 * ICustomListElement. The value of the elements is set using %CustomListItem.
 * 
 * Note that %CustomListItem needs to be created on a heap. CustomListItems will be deleted automatically 
 * when the CustomList is destroyed. If you want to remove certain list items, you must use RemoveItemAt().
 *
 * Refer to CustomListItemFormat.
 *
 */
class _EXPORT_CONTROLS_ CustomListItem
	: public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	CustomListItem(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~CustomListItem(void);

	/**
	 * Initializes this instance of %CustomListItem with the specified parameter.
	 *
	 * @since					1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *					For more information, see @ref CompCustomListItemConstruct "1.1" and @ref CompCustomListItemConstruct20 "2.0".
	 * @return	An error code
	 * @param[in]	itemHeight			The height of %CustomListItem
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	        This instance has already been constructed.
	 * @exception   E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(int itemHeight);

	/**
	 * @page   CompCustomListItemConstruct	Compatibility for Construct()
	 * @section CompCustomListConstructIssues Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	 * -# If an item height is less than 50 in WVGA (or 25 in WQVGA), the item is not highlighted when it is selected.	 
	 *
	 * @section CompCustomListItemConstructResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1. or above. @n	 
	 */

	/**
	 * @page   CompCustomListItemConstruct20	Compatibility for Construct()
	 * @section CompCustomListItemConstruct20Issues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# On a WVGA screen, the default minimum height is @c 50.
	 *
	 * @section CompCustomListItemConstruct20Resolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	 * -# On a WVGA screen, the default minimum height is changed to @c 48
	 */

	/**
	 * Sets the format of %CustomListItem.
	 *
	 * @since			1.0
	 * @param[in]	itemFormat		An instance of %CustomListItemFormat
	 * @remarks Do not delete @c itemFormat before the associated %CustomListItem is removed from %CustomList, because %CustomListItemFormat is constantly 
	 *			used while CustomListItem is added to CustomList.
	 */
	void SetItemFormat(const CustomListItemFormat& itemFormat);

	/**
	 * Gets the format of %CustomListItem.
	 *
	 * @since			1.0
 	 * @return	A pointer to CustomListItemFormat, @n
	 *			else @c null if a system error occurs
	 */
	const CustomListItemFormat* GetItemFormat(void) const;

	/**
	 * Sets the background bitmap image which is displayed when the item is focused.
   *
   * @since			1.0
   * @param[in] bitmap		The background bitmap image
	 * @remarks  The specified bitmap is automatically scaled to the size of an associated item.
	 * @see SetNormalItemBackgroundBitmap()
   */
    void SetFocusedItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the background image of the item which is displayed when the item is in normal state.
   *
   * @since			1.0
   * @param[in] bitmap	 The background bitmap image
	 * @remarks The specified bitmap is automatically scaled to the size of an+B6 associated item.
	 * @see SetFocusedItemBackgroudBitmap()
   */
    void SetNormalItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

  /**
   * Sets the highlighted background image on the rectangle of each list item.
   *
	 * @since 			1.1
   * @param[in]   bitmap   The background image
   * @remarks     When a user navigates the user interface using the directional keys, @n
   *               	the selected UI control is highlighted and takes the focus.
   */

    void SetHighlightedItemBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the text of the element for %CustomListItem.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in]	elementId	The ID of the element
	 * @param[in] text            The text string to be added
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 * @remarks		To display text in multi-lines or to denote the end of line use '\\n'.
	 */
	result SetElement(int elementId, const Osp::Base::String& text);

	/**
	 * Sets the bitmap of the element for %CustomListItem.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *     For more information, see @ref CompCustomListItemSetElement "here".
 	 * @return		An error code
	 * @param[in]	elementId	The ID of the element
	 * @param[in]	normalBitmap    	The bitmap displayed when the item is in the normal state
	 * @param[in]   pFocusedBitmap  The bitmap displayed when the item is focused
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 */
	result SetElement(int elementId, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pFocusedBitmap);

	/**
	  * @page   CompCustomListItemSetElement Compatibility for SetElement()
	  * @section CompCustomListItemSetElementIssues Issues
	  * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	  * -# If both the bitmap element and %CustomElement are added to the item, calling this method occasionally leads to a crash.
	  *
	  * @section CompCustomListItemSetElementResolutions Resolutions
	  * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	  */

    /**
     * Sets the bitmap of the element for %CustomListItem.
     *
     * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
     *     For more information, see @ref CompCustomListItemSetElement "here".
     *
	 * @since	   1.1
     * @return     An error code
     * @param[in]  elementId          The ID of the element
     * @param[in]  	normalBitmap       	The bitmap displayed when the item is in the normal state
     * @param[in]  pFocusedBitmap     The bitmap displayed when the item is selected
     * @param[in]  pHighlightedBitmap The bitmap displayed when the item is highlighted
     * @exception  	E_SUCCESS          	The method is successful.
     * @exception  	E_SYSTEM			A system error has occurred.
     */
    result SetElement(int elementId, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pFocusedBitmap, const Osp::Graphics::Bitmap* pHighlightedBitmap);

	/**
	 * Sets the custom element for %CustomListItem.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *     For more information, see @ref CompCustomListItemSetElement "here".
 	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @param[in]	element			 The custom element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 * @remarks   	Do not delete @c element before the associated %CustomListItem is removed from %CustomList, @n 
     *              as ICustomListElement is constantly used while %CustomListItem is added to %CustomList. @n
	 *            	Call RefreshItem() to draw the custom element that has been set with this method.
	 */
	result SetElement(int elementId, const ICustomListElement& element);

	/**
	 * Sets the element ID of the checkbox of %CustomListItem.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 */
	result SetCheckBox(int elementId);

	/**
	 * Sets the percent value of %CustomListItem.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in] 	value  		The percent value of %CustomListItem @n
     *		             The valid range of integers is from @c 0 to @c 100
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception 	E_SYSTEM	A system error has occurred.
	 */
	result SetValue(int value);

	/**
	 * Gets the percentage value of %CustomListItem.
	 *
	 * @since			1.0
	 * @return		The percentage value, @n
	 *              else @c -1 if a system error occurs
	 */
	int GetValue(void);

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
	 * @exception	E_SYSTEM  A system error occurred. @n
                    Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure. 
     * @since         1.0
     */	
	void* __pCustomListItem;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The element store 
     * @since         1.0
     */	
	Osp::Base::Collection::ArrayList* __pElements;

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The custom item format 
     * @since         1.0
     */	
	CustomListItemFormat* __pCustomListItemFormat;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Normal Background Bitmap 
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__pNormalBackgroundBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Focused Background Bitmap
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__pFocusedBackgroundBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * ItemId of this item
     * @since         1.0
     */	
	int	__itemId;

	friend class CustomList;
	friend class ExpandableList;
	friend class SlidableList;
	friend class GroupedList;
	friend class SlidableGroupedList;

	friend class CustomListItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class CustomListItemEx* __pCustomListItemEx;
};

}; }; }; 
#endif
