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
 * @file	FUiCtrlListContextItem.h
 * @brief	This is the header file for the %ListContextItem class.
 *
 * This header file contains the declarations of the %ListContextItem class and its helper classes.
 */

#ifndef _FUICTRL_LIST_CONTEXT_ITEM_H_
#define _FUICTRL_LIST_CONTEXT_ITEM_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { namespace Controls {

/**
* @class	ListContextItem
* @brief 	This class defines common behavior for  %ListContextItem.
* @since	2.0
*
* The %ListContextItem class displays the context item for a ListView or GroupedListView.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
*/

class _EXPORT_CONTROLS_ ListContextItem 
  : public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ListContextItem(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ListContextItem(void);

	/**
	 * Initializes this instance of %ListContextItem with the specified parameter.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY   	The memory is insufficient.
	 * @exception	E_SYSTEM          	A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Adds the text element to the context item.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	elementId		The ID of the element
	 * @param[in]	text			The text to be displayed
	 * @param[in]	enable			Set to @c true to enable this element, @n
	 *								else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_INVALID_STATE   This instance is in an invalid state.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement( int elementId, const Osp::Base::String& text, bool enable = true);

	/**
	 * Adds the bitmap element to the context item.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in] 	elementId           The ID of the element
	 * @param[in] 	normalBitmap        The bitmap displayed when the item is in normal status
	 * @param[in] 	pressedBitmap       The bitmap displayed when the item is pressed
	 * @param[in] 	pHighlightedBitmap	The bitmap displayed when the item is highlighted
	 * @param[in] 	enable              Set to @c true to enable this element, @n
	 *									else @c false
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception 	E_INVALID_ARG     	A specified input parameter is invalid.
	 * @exception 	E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception 	E_SYSTEM          	A system error has occurred.
	 */
	result AddElement( int elementId, const Osp::Graphics::Bitmap& normalBitmap,
								const Osp::Graphics::Bitmap& pressedBitmap,
								const Osp::Graphics::Bitmap* pHighlightedBitmap = null, bool enable = true);

	/**
	 * Adds the text and the bitmap element to the context item.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in] 	elementId				The ID of the element
	 * @param[in] 	text				  	The text to be displayed
	 * @param[in] 	normalBitmap        	The bitmap displayed when the item is in normal status
	 * @param[in] 	pressedBitmap       	The bitmap displayed when the item is pressed
	 * @param[in] 	pHighlightedBitmap  	The bitmap displayed when the item is highlighted
	 * @param[in] 	enable              	Set to @c true to enable this element, @n
	 *                                		else @c false
	 * @exception E_SUCCESS					The method is successful.
	 * @exception E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception E_INVALID_STATE			This instance is in an invalid state.
	 * @exception E_SYSTEM          		A system error has occurred.
	 */
	result AddElement( int elementId, const Osp::Base::String& text,
								const Osp::Graphics::Bitmap& normalBitmap,
								const Osp::Graphics::Bitmap& pressedBitmap,
								const Osp::Graphics::Bitmap* pHighlightedBitmap = null, bool enable = true);

	/**
	 * Sets the background image of the context item.
	 *
	 * @since 	2.0
 	 * @return    	An error code
 	 * @param[in] 	pBitmap           The background bitmap image
 	 * @exception	E_SUCCESS         The method is successful.
 	 * @exception 	E_INVALID_STATE   This instance is in an invalid state.
 	 * @exception 	E_SYSTEM          A system error has occurred.
 	 *
 	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only 
	 *			the bitmap is displayed. @n
 	 *			When @c pBitmap is set as @c null, the background color of the context item is drawn.
 	 */
	result SetBackgroundBitmap(const Osp::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the background color of the context item.
	 *
	 * @since 	2.0
	 * @return		An error code
	 * @param[in]	color				The background color
	 * @exception	E_SUCCESS         	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only 
	 *			the bitmap is displayed.
	 */
	result SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of the context item.
	 *
 	 * @since 	2.0
	 * @return	The background color of the context item
	 */
	Osp::Graphics::Color GetBackgroundColor(void) const;

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for the ListContextItem class.
     * @since         2.0
     */	
	ListContextItem(const ListContextItem& listContextItem);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */		
	ListContextItem& operator=(const ListContextItem& listContextItem);
	
private:
	friend class ListItemBase;
	friend class ListContextItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class ListContextItemEx* __pListContextItemEx;
};

}; }; }; 
#endif
