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
 * @file	FUiCtrlCustomItem.h
 * @brief	This is the header file for the %CustomItem class.
 *
 * This header file contains the declarations of the %CustomItem class and its helper classes.
 */

#ifndef _FUICTRL_CUSTOM_ITEM_H_
#define _FUICTRL_CUSTOM_ITEM_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FGrpBitmap.h"
#include "FGrpEnrichedText.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListItemBase.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlICustomElement.h"
#include "FUiCtrlAlignmentEnum.h"

namespace Osp { namespace Ui { namespace Controls {

 /**
 * @class	CustomItem
 * @brief 	This class defines the common behavior for %CustomItem.
 * @since	2.0
 *
 * The %CustomItem class displays a list item, which is the unit of handling a ListView or GroupedListView. It provides customized formatting of specific list items.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 * 
 */

class _EXPORT_CONTROLS_ CustomItem
	: public ListItemBase
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	CustomItem(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~CustomItem(void);

	/**
	 * Initializes this instance of %CustomItem with the specified parameters.
	 *
	 * @since			2.0
	 *
	 * @return    An error code
	 *
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of the annex
	 *
	 * @exception	E_SUCCESS         The method is successful.
	 * @exception E_INVALID_STATE   This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY   The memory is insufficient.
	 * @exception	E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Osp::Graphics::Dimension& itemSize, ListAnnexStyle style);

    /**
     * Adds an instance of EnrichedText as an element to the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     * @param[in] rect              The bounds of the element
     * @param[in] elementId         The element ID
     * @param[in]	text              An instance of %EnrichedText
     * @exception	E_SUCCESS         The method is successful.
     * @exception E_INVALID_ARG     A specified input parameter is invalid.
     * @exception E_INVALID_STATE   This instance is in an invalid state.
     * @exception	E_SYSTEM          A system error has occurred.
     */
	result AddElement(const Osp::Graphics::Rectangle& rect, int elementId, const Osp::Graphics::EnrichedText& text);

    /**
     * Adds the text as an element to the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     *
     * @param[in] rect              The bounds of the element
     * @param[in] elementId         The element ID
     * @param[in] 	text              	The text string to be added
     * @param[in] textSliding       Set to @c true to allow a long text to slide, @n
	 *                              else @c false
     * @exception 	E_SUCCESS         	The method is successful.
     * @exception E_INVALID_ARG     A specified input parameter is invalid.
     * @exception E_INVALID_STATE   This instance is in an invalid state.
     * @exception 	E_SYSTEM          	A system error has occurred.
     *
     * @remarks     If the width of the specified @c text exceeds the width of the element and @c textSliding is set to @c true, the text slides 
	 *				automatically when the user long-presses.
     */
	result AddElement(const Osp::Graphics::Rectangle& rect, int elementId, const Osp::Base::String& text,
					bool textSliding = true);
					
    /**
     * Adds the text as an element to the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     *
     * @param[in] rect                  The bounds of the element
     * @param[in] elementId             The element ID
     * @param[in] 	text                  	The text string to be added
     * @param[in] textSize              The size of the text
     * @param[in] normalTextColor       The color of the text in the normal status
     * @param[in] pressedTextColor	    The color of the text in the pressed status
     * @param[in] highlightedTextColor 	The color of the text in the highlighted status
     * @param[in] textSliding           Set to @c true to allow a long text to slide, @n
     *                                  else @c false
     * @exception 	E_SUCCESS             	The method is successful.
     * @exception E_INVALID_ARG         A specified input parameter is invalid.
     * @exception E_INVALID_STATE       This instance is in an invalid state.
     * @exception 	E_SYSTEM				A system error has occurred.
     * @remarks  The default size of text is 38 on a WVGA screen, 22 on a HVGA screen and 20 on a WQVGA screen.
     */
	result AddElement(const Osp::Graphics::Rectangle& rect, int elementId, const Osp::Base::String& text,
			int textSize,
			const Osp::Graphics::Color& normalTextColor,
			const Osp::Graphics::Color& pressedTextColor,
			const Osp::Graphics::Color& highlightedTextColor,
			bool textSliding = true);
	
    /**
     * Adds the bitmap image as an element to the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     * @param[in] rect                  The bounds of the element
     * @param[in] elementId          	The element ID
     * @param[in] normalBitmap          The bitmap image displayed when the item is in normal status
     * @param[in] pPressedBitmap        The bitmap image displayed when the item is pressed
     * @param[in] pHighlightedBitmap    The bitmap image displayed when the item is highlighted
     * @exception	E_SUCCESS             	The method is successful.
     * @exception E_INVALID_ARG         A specified input parameter is invalid.
     * @exception E_INVALID_STATE       This instance is in an invalid state.
     * @exception	E_SYSTEM              	A system error has occurred.
     */
	result AddElement(const Osp::Graphics::Rectangle& rect, int elementId,
			const Osp::Graphics::Bitmap& normalBitmap,
			const Osp::Graphics::Bitmap* pPressedBitmap = NULL,
			const Osp::Graphics::Bitmap* pHighlightedBitmap = NULL);

    /**
     * Adds the custom drawing element to the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     * @param[in] rect              The bounds of the element
     * @param[in] elementId         The element ID
     * @param[in] element           The custom element
     * @exception	E_SUCCESS			The method is successful.
     * @exception E_INVALID_ARG     A specified input parameter is invalid.
     * @exception E_INVALID_STATE   This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     */
	result AddElement(const Osp::Graphics::Rectangle& rect, int elementId, const ICustomElement& element);
	
    /**
     * Removes the element from the %CustomItem control.
     *
     * @since			2.0
     *
     * @return    An error code
     * @exception	E_SUCCESS			The method is successful.
     * @exception E_INVALID_STATE   This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     */
	result RemoveAllElements(void);

	/**
	* Removes the element with the specified element ID.
	*
	* @since	 2.0
	*
	* @return	  An error code
	* @param[in] elementId				 The element ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception E_INVALID_STATE	   This instance is in an invalid state.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result RemoveElement(int elementId);
	

    /**
     * Sets the selection type of an element.
     *
     * @since			2.0
     *
     * @param[in] elementId         The element ID
     * @param[in]	enable				Set to @c true to enable the selection of the specified element, @n
	 *									else @c false
     * @exception	E_SUCCESS         	The method is successful.
     * @exception E_INVALID_ARG     A specified input parameter is invalid.
     * @exception E_INVALID_STATE   This instance is in an invalid state.
     * @exception	E_SYSTEM          	A system error has occurred.
     *
     * @remarks    Based on the selection type of an element, the area within which the background color changes is different when an element is touched.
     */
	result SetElementSelectionEnabled(int elementId, bool enable);

	/**
     * Sets the horizontal alignment of the text in the specified element.
     *
     * @since     2.0
     *
     * @param[in] elementId         The element ID
     * @param[in]	alignment				The horizontal alignment of the text
     * @exception	E_SUCCESS             	The method is successful.
     * @exception E_INVALID_ARG         A specified input parameter is invalid.
     * @exception E_INVALID_STATE       This instance is in an invalid state.
	 * @exception E_INVALID_OPERATION   The specified element does not handle text.@n
	 *										The specified element does not contain text.
     * @exception	E_SYSTEM				A system error has occurred.
     */
	result SetElementTextHorizontalAlignment(int elementId, HorizontalAlignment alignment);

	/**
     * Sets the vertical alignment of the text in the specified element.
     *
     * @since     2.0
     *
     * @param[in] elementId         The element ID
     * @param[in]	alignment				The vertical alignment of the text
     * @exception	E_SUCCESS				The method is successful.
     * @exception E_INVALID_ARG         A specified input parameter is invalid.
     * @exception E_INVALID_STATE       This instance is in an invalid state.
	 * @exception E_INVALID_OPERATION   The specified element does not handle text.@n
	 *										The specified element does not contain text.
     * @exception	E_SYSTEM				A system error has occurred.
     */
	result SetElementTextVerticalAlignment(int elementId, VerticalAlignment alignment);

/**
    * Sets the auto-link mask.
    *
    * @since     2.0
    * @return    An error code
    *
    * @param[in] elementId		The element ID
    * @param[in] mask			The auto-link mask @n
    * 							Multiple link types can be combined using bitwise OR operator (see Osp::Base::Utility::LinkType). @n
    * 							For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
    * @exception E_SUCCESS				The method is successful.
    * @exception E_INVALID_ARG			A specified input parameter is invalid.
    * @exception E_INVALID_STATE		This instance is in an invalid state.
    * @exception E_INVALID_OPERATION 	The specified element does not handle text.
    * @exception E_SYSTEM				A system error has occurred.
    * @remarks      When @c mask is set to @c 0, the auto-link detection is disabled.
    * @see Osp::Base::Utility::LinkType
    */
   result SetElementAutoLinkMask(int elementId, unsigned long mask);
private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * This is the copy constructor for this class.
     *
     * @since         2.0
     */	
	CustomItem(const CustomItem& customItem);
	
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * This is the substitution operator for this class.
     *
     * @since         2.0
     */	
	CustomItem& operator=(const CustomItem& customItem);
	
private:
	friend class CustomItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class CustomItemEx* __pCustomItemEx;
};

}; }; }; 
#endif
