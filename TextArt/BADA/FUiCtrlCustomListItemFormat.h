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
 * @file	FUiCtrlCustomListItemFormat.h
 * @brief	This is the header file for the %CustomListItemFormat class.
 *
 * This header file contains the declarations of the %CustomListItemFormat class and its helper classes.
 */

#ifndef _FUICTRL_CUSTOMLISTITEMFORMAT_H_
#define _FUICTRL_CUSTOMLISTITEMFORMAT_H_

//includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FGrpRectangle.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { namespace Controls {
/**
 * @class	CustomListItemFormat
 * @brief		This class defines the common behavior of an item format of a CustomList control.
 * @deprecated	This class is deprecated. There is no need to use this class.
 * @since		1.0
 *
 * The %CustomListItemFormat class defines the common behavior of an item format of a CustomList control.
 * A custom list item is composed of elements, which can be texts and bitmaps. 
 * A custom list item format determines the configuration of elements of a list item
 * and the position and the size of a custom list item.
 * 
 * Note that %CustomListItemFormat needs to be created on a heap and it should be 
 * deleted explicitly after use. However, CustomListItem should 
 * be manually deleted because items are removed from memory by the List when 
 * it is destroyed.
 *
 * Refer to CustomListItem.
 *
 */
class _EXPORT_CONTROLS_ CustomListItemFormat
	: public Osp::Base::Object
{
	//DECL_CLASSTYPE(CustomListItemFormat);
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	CustomListItemFormat(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~CustomListItemFormat(void);
	

	/**
	 * Initializes this instance of %CustomListItemFormat.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 */
	result Construct(void);
	
	/**
	 * Adds the %CustomListElement with bounds equal to @c rect.
	 *
	 * @since			1.0
 	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @param[in]	rect	The bounds of the element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 */
	result	AddElement(int elementId, const Osp::Graphics::Rectangle& rect);
	
	/**
	 * Adds the %CustomListElement with bounds equal to @c rect and size of the text @c textSize.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	elementId		The ID of the element
	 * @param[in]	rect			The bounds of the element
	 * @param[in]	textSize		The size of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_SYSTEM        A system error has occurred.
	 */
	result AddElement(int elementId, const Osp::Graphics::Rectangle& rect, int textSize);

	/**
	 * Adds the %CustomListElement with bounds equal to @c rect, specifying the size of text and the color of text.
	 *
	 * @since     1.0
 	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompCustomListItemFormatAddElement "here".
	 *
 	 * @return    An error code
     * @param[in] elementId          The ID of the element
     * @param[in] rect               The bounds of the element
     * @param[in] textSize           The size of the text
     * @param[in] normalTextColor    The color of the text in the normal status
     * @param[in] focusedTextColor   The color of the text in the focused status
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 */
	result	AddElement(int elementId, const Osp::Graphics::Rectangle& rect, int textSize,
		const Osp::Graphics::Color& normalTextColor, const Osp::Graphics::Color& focusedTextColor);

	/**
	 * Adds the %CustomListElement with bounds equal to @c rect, specifying the size of text and the color of text.
	 *
	 * @since     1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompCustomListItemFormatAddElement "here".
	 *
 	 * @return    An error code
     * @param[in] elementId              The ID of the element
     * @param[in] rect                   The bounds of the element
     * @param[in] textSize               The size of the text
     * @param[in] normalTextColor        The color of the text in the normal status
     * @param[in] focusedTextColor       The color of the text in the focused status
     * @param[in] highlightedTextColor   The color of the text in the highlighted status
	 * @exception 	E_SUCCESS              The method is successful.
	 * @exception 	E_SYSTEM               A system error has occurred.
	 */
	result	AddElement(int elementId, const Osp::Graphics::Rectangle& rect, int textSize,
		const Osp::Graphics::Color& normalTextColor, const Osp::Graphics::Color& focusedTextColor, const Osp::Graphics::Color& highlightedTextColor);

    /**
     * @page       CompCustomListItemFormatAddElement Compatibility for AddElement()
     *
     * @section    CompCustomListItemFormatAddElementIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -#   The method ignores the alpha value of specified color.
     *
     * @section    CompCustomListItemFormatAddElementResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */



	/**
	 * Gets the position and size of the element.
	 *
	 * @since			1.0
 	 * @return		The bounds of the element, @n
	 *				else a rectangle of (0, 0, -1, -1) if there is no element matching the specified ID
   * @param[in]	elementId	 The ID of the element
	 */
	Osp::Graphics::Rectangle GetElement(int elementId) const;
	
	/**
	 * Gets the ID of the first element.
	 *
	 * @since		1.0
	 * @return  	The ID of the first element, @n
	 *          	else @c -1 if a system error occurs
	 */
	int		GetFirstElementId(void);
	
	/**
	 * Gets the ID of the next element of the specified element.
	 *
	 * @since		1.0
	 * @return  	The ID of the next element of the specified element, @n
	 *              else @c -1 if there is no element next to the element specified by @c elementId
 	 * @param[in] elementId		The ID of the element
	 */	
	int		GetNextElementId(int elementId);
	
	/**
	 * Gets the ID of the first element of all enabled items.
	 *
	 * @since		1.0
	 * @return		The ID of the first enabled element, @n
	 *				else @c -1 if no element is enabled
	 */
	int		GetFirstEnabledElementId(void);
	
	/**
	 * Gets the ID of the next enabled element after the specified element.
	 *
	 * @since		1.0
	 * @return		The ID of the next enabled element, @n
	 *				else @c -1 if no element after the specified element is enabled
 	 * @param[in] elementId		The ID of the element
	 */
	int		GetNextEnabledElementId(int elementId);

	/**
	 * Gets the ID of the previous enabled element ID of the specified element.
	 *
	 * @since		1.0
	 * @return		The ID of the previous enabled element, @n
	 *				else @c -1 if no element before the specified element is enabled
 	 * @param[in] elementId		The ID of the element
	 */
	int		GetPreviousEnabledElementId(int elementId);

	/**
	 * Sets the event status for the specified element.
	 *
	 * @since			1.0
 	 * @param[in] elementId		The ID of the element
	 * @param[in] 	enable  		Set to @c true to allow the specified element to handle the events, @n
	 *                              else @c false
	 */
	void SetElementEventEnabled(int elementId, bool enable);

	/**
	 * Checks whether the event status is enabled for the specified element.
	 *
	 * @since			1.0
 	 * @return		@c true if the event status is enabled, @n
	 *				else @c false
 	 * @param[in] elementId		The ID of the element
	 */
	bool IsElementEventEnabled(int elementId);

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	void* __pCustomListFormat;
	
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * To store fonts.
     * @since         1.0
     */		
     Osp::Base::Collection::ArrayList	__fonts;

	friend class CustomListItem;
	friend class CustomList;

	friend class CustomListItemFormatEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
     class CustomListItemFormatEx* __pCustomListItemFormatEx;
};
}; }; }; 
#endif
