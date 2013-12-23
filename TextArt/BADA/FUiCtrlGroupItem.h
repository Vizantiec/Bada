/* $Change: 720383 $ */
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
 * @file	FUiCtrlGroupItem.h
 * @brief	This is the header file for the %GroupItem class.
 *
 * This header file contains the declarations of the %GroupItem class and its helper classes.
 */

#ifndef _FUICTRL_GROUP_ITEM_H_
#define _FUICTRL_GROUP_ITEM_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { namespace Controls { class GruopItemEx; }}}
namespace Osp { namespace Ui { namespace Controls {
    
 /**
 * @class	GroupItem
 * @brief 	This class defines common behavior of %GroupItem.
 * @since	2.0
 *
 * The %GroupItem class displays a group item. The basic layout of the %GroupItem instance is text and a bitmap arranged horizontally in one line. The bitmap can be omitted while text must be given.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */

class _EXPORT_CONTROLS_ GroupItem : public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	GroupItem(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~GroupItem(void);

	/**
	 * Initializes this instance of %GroupItem with the specified parameter.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	itemSize          	The size of the item
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE   	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result Construct(const Osp::Graphics::Dimension& itemSize);

	/**
	 * Sets the background image of the item.
	 *
	 * @since		2.0
     *
     * @return		An error code
     * @param[in]	pBitmap           The background bitmap image
 	 * @exception	E_SUCCESS         The method is successful.
 	 * @exception	E_INVALID_STATE   This instance is in an invalid state.
     * @exception	E_SYSTEM          A system error has occurred.
     *
 	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and background color are specified, only 
	 *			the bitmap is displayed.
     */
	result SetBackgroundBitmap(const Osp::Graphics::Bitmap* pBitmap);
	
	/**
	 * Sets the background color of the item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks 	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only the bitmap is displayed. @n
	 *				The background color of the item is not applied when the item is inserted into the GroupedListView of section style.
	 */
	result SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of the item.
	 *
	 * @since     2.0
     *
     * @return		The background color of the item, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
     * @see       	SetBackgroundColor()
     */
	Osp::Graphics::Color GetBackgroundColor(void) const;

    /**
     * Sets the color of the text.
	 *
	 * @since     2.0
     *
     * @return    	An error code
     * @param[in] 	color             	The text color
 	 * @exception 	E_SUCCESS         	The method is successful.
 	 * @exception 	E_INVALID_STATE		This instance is in an invalid state.
     * @exception 	E_SYSTEM          	A system error has occurred.
     * @see       	GetTextColor()
     */
	result SetTextColor(const Osp::Graphics::Color& color);

    /**
     * Gets the color of the text.
	 *
	 * @since	2.0
     *
     * @return	The text color, @n
	 *			else RGBA(0, 0, 0, 0) if an error occurs
     * @see		SetTextColor()
     */
	Osp::Graphics::Color GetTextColor(void) const;

    /**
     * Sets the size of the text.
	 *
	 * @since		2.0
     *
     * @return		An error code
     * @param[in]	size              	The size of the text
 	 * @exception	E_SUCCESS         	The method is successful.
 	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
 	 * @exception	E_INVALID_ARG     	The specified input parameter is invalid.
     * @exception	E_SYSTEM          	A system error has occurred.
     * @see       	GetTextSize()
     */
	result SetTextSize(int size);

    /**
     * Gets the size of the text.
	 *
	 * @since     	2.0
     *
     * @return    	The size of the text,
	 *				else @c -1 if an error occurs
     * @see       	SetTextSize()
     */
	int GetTextSize(void) const;

    /**
     * Sets the text and bitmap of the element for %GroupItem.
     *
     * @since     2.0
     *
     * @return		An error code
     * @param[in]	text				The text string to be added
     * @param[in]	pBitmap           	The bitmap to be displayed
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The behavior of %GroupItem is different according to the style of GroupedListView. @n
     *            	When the style is GROUPED_LIST_VIEW_INDEXED, the text and bitmap of %GroupItem are displayed, if they are given. However, when the style 
	 *				is GROUPED_LIST_VIEW_STYLE_SECTION, the bitmap is not displayed in any case and setting an empty text to %GroupItem does not show 
	 *				%GroupItem.
     */
	result SetElement(const Osp::Base::String& text, const Osp::Graphics::Bitmap *pBitmap = null);

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
	GroupItem(const GroupItem& groupItem);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */		
	GroupItem& operator=(const GroupItem& groupItem);
	
private:
	friend class __ListItemProvider;
	friend class GroupItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class GroupItemEx* __pGroupItemEx;
};

}; }; }; 
#endif
