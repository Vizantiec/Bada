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
 * @file	FUiCtrlSimpleItem.h
 * @brief	This is the header file for the %SimpleItem class.
 *
 * This header file contains the declarations of the %SimpleItem class and its helper classes.
 */

#ifndef _FUICTRL_LISTVIEW_ITEM_H_
#define _FUICTRL_LISTVIEW_ITEM_H_

//includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListItemBase.h"

namespace Osp { namespace Ui { namespace Controls {
    
 /**
 * @class	SimpleItem
 * @brief 	This class defines the common behavior of a %SimpleItem.
 * @since	2.0
 *
 * The %SimpleItem class displays a list item, which is the unit of handling a ListView or GroupedListView. It provides the default
 * formatting of the list items.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 * 
 */

class _EXPORT_CONTROLS_ SimpleItem
	: public ListItemBase
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	SimpleItem(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~SimpleItem(void);

	/**
	 * Initializes this instance of %SimpleItem with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return    	An error code
	 *
	 * @param[in] 	itemSize          The size of the item
	 * @param[in] 	style             The style of the annex
	 *
	 * @exception 	E_SUCCESS         The method is successful.
	 * @exception 	E_INVALID_STATE   This instance has already been constructed.
	 * @exception 	E_OUT_OF_MEMORY   The memory is insufficient.
	 * @exception 	E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Osp::Graphics::Dimension& itemSize, ListAnnexStyle style);

    /**
     * Sets the text string and bitmap image for %SimpleItem.
     *
     * @since		2.0
     *
     * @return    	An error code
     * @param[in] 	text         	  The text string to be added
     * @param[in] 	pBitmap           The bitmap image to be displayed
     *
     * @exception 	E_SUCCESS         The method is successful.
     * @exception 	E_INVALID_STATE   This instance is in an invalid state.
     * @exception 	E_SYSTEM          A system error has occurred.
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
	SimpleItem(const SimpleItem& simpleItem);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */	
	SimpleItem& operator=(const SimpleItem& simpleItem);
	
private:
	friend class SimpleItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class SimpleItemEx* __pSimpleItemEx;
};

}; }; }; 
#endif
