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
 * @file	FUiCtrlListItemBase.h
 * @brief	This is the header file for the %ListItemBase class.
 *
 * This header file contains the declarations of the %ListItemBase class and its helper classes.
 */

#ifndef _FUICTRL_LIST_ITEM_BASE_H_
#define _FUICTRL_LIST_ITEM_BASE_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlListContextItem.h"

namespace Osp { namespace Ui { namespace Controls { class ListItemBaseEx; }}}
namespace Osp { namespace Ui { namespace Controls {
    
 /**
 * @class   ListItemBase
 * @brief   This class defines common behavior for a %ListItemBase.
 * @since   2.0
 *
 * The %ListItemBase class is a base class, which represents a list item which is the unit of handling of the ListView or
 * GroupedListView classes.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.


 * 
 */

class _EXPORT_CONTROLS_ ListItemBase :
	public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ListItemBase(void);

	/**
	 * Sets the background image of the item that is displayed when the item is in the specified state.
	 *
	 * @since     2.0
     * @return		An error code
     * @param[in] 	status            The item drawing state
     * @param[in] 	pBitmap           The background bitmap image
	 * @exception 	E_SUCCESS         The method is successful.
	 * @exception 	E_INVALID_STATE   This instance is in an invalid state.
     * @exception 	E_SYSTEM          A system error has occurred.
     *
   	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, 
	 *			only the bitmap is displayed.
     */
	result SetBackgroundBitmap(ListItemDrawingStatus status, const Osp::Graphics::Bitmap* pBitmap);
	
	/**
	 * Sets the background color of the item that is displayed when the item is in the specified state.
	 *
	 * @since     2.0
	 * @return		An error code
	 * @param[in]	status            	The item drawing state
	 * @param[in]	color             	The background color
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 * @remarks 	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only the bitmap is displayed. @n
	 *				The background color of the item is not applied when the item is inserted into the GroupedListView of section style.
	 */
	result SetBackgroundColor(ListItemDrawingStatus status, const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of the item that is displayed when the item is in the specified state.
	 *
	 * @since     2.0
     * @return		The background color of the item
     * @param[in] 	status		The item drawing state, @n
     *							else RGBA(0, 0, 0, 0) if an error occurs
     * @see		SetBackgroundColor()
     */
	Osp::Graphics::Color GetBackgroundColor(ListItemDrawingStatus status) const;

	/**
     * Sets ContextItem that is displayed when an item is swept.
     *
     * @since	2.0
     * @return		An error code
     * @param[in]	pItem 				The %ListContextItem instance
     * @exception	E_SUCCESS         	The method is successful.
     * @exception	E_INVALID_ARG		The specified input parameter is invalid.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM         	A system error has occurred.
     *
     * @remarks	If the context item is not set, ListView() or GroupedListView() does not display the context item and an item sweep event is generated when an 
	 *			item is swept. @n
     *          The specified @c pItem should be deleted by the applications when it is no longer used.
     *
     */
	result SetContextItem(const ListContextItem* pItem);

	/**
	 * Sets the description text.
	 *
	 * @since     2.0
 	 * @return    An error code
	 * @param[in] text              The description text
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetDescriptionText (const Osp::Base::String& text);

	/**
	 * Sets the color of the description text.
	 *
	 * @since     2.0
     * @return    An error code
	 * @param[in] color             The color of the description text
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetDescriptionTextColor(const Osp::Graphics::Color& color);

	/**
	 * Sets the progress value of a list item.
	 *
	 * @since     2.0
 	 * @return    An error code
	 * @param[in] value             The progress value of the list item @n
	 *                              The valid values are integers from @c 0 to @c 100.
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetProgressValue(int value);

	/**
	 * Sets the margin of the progress bar.
	 *
	 * @since     2.0
 	 * @return    An error code
	 * @param[in] leftMargin        The left margin of the progress bar
	 * @param[in] rightMargin       The right margin of the progress bar
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetProgressMargins(int leftMargin, int rightMargin);
	
	/**
	 * Gets the width of the annex area.
	 *
	 * @since  2.0
 	 * @return    The width of the annex
	 * @param[in] style           The style of the annex
	 * @remarks   The width of the annex area is different for different annex styles.
	 */
	static int GetAnnexWidth(ListAnnexStyle style);

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 * @since     2.0
	 */
	ListItemBase(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of ListItem with the specified parameter.
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of the annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance has already been constructed.
	 * @exception E_OUT_OF_MEMORY   The memory is insufficient.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Osp::Graphics::Dimension& itemSize, ListAnnexStyle style);

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
	ListItemBase(const ListItemBase& listItemBase);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */	
	ListItemBase& operator=(const ListItemBase& listItemBase);
	
protected:
	friend class __ListItemProvider;
	friend class ListItemBaseEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class ListItemBaseEx* __pListItemBaseEx;
};

}; }; }; 
#endif
