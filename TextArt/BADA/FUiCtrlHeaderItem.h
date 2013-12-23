// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlHeaderItem.h
 * @brief	This is the header file for the %HeaderItem class.
 *
 * This header file contains the declarations of the %HeaderItem class.
 */
#ifndef _FUICTRL_HEADER_ITEM_H_
#define _FUICTRL_HEADER_ITEM_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiCtrlConfig.h"

// namespace declaration
namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum HeaderItemStatus
 *
 * Defines the possible statuses of a %HeaderItem control.
 *
 * @since		2.0
 */
enum HeaderItemStatus
{
	HEADER_ITEM_STATUS_NORMAL,		/**< The normal status */
	HEADER_ITEM_STATUS_PRESSED,		/**< The pressed status */
	HEADER_ITEM_STATUS_SELECTED,	/**< The selected status */
	HEADER_ITEM_STATUS_HIGHLIGHTED,	/**< The highlighted status */
	HEADER_ITEM_STATUS_DISABLED		/**< The disabled status */
};


/**
 * @class	HeaderItem
 * @brief	This class is an implementation of a %HeaderItem control.
 * @since	2.0
 *
 * The %HeaderItem class is a helper class that specifies the properties of the Header item.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_header.htm">Header</a>.
 */
class _EXPORT_CONTROLS_ HeaderItem
	: public Osp::Base::Object
{
public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	HeaderItem(void);


	/**
	 * This is the destructor for this class.
   *
	 * @since		2.0
	 */
    virtual ~HeaderItem(void);


	/**
	 * Initializes this instance of %HeaderItem with the specified parameters.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]	actionId	    The action ID of this item
	 * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The action ID of the specified item must be a positive integer.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_INVALID_STATE	This instance is in an invalid state. 
	 */
	result Construct(int actionId);


// Operation
public:
    /**
     * Gets the action ID of the %HeaderItem control.
     *
	 * @since		2.0
     * @return      The action ID, @n
     *				else @c -1 if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
	int GetActionId(void) const;


    /**
     * Gets the text of the %HeaderItem control.
     *
	 * @since		2.0
     * @return		The item text, @n
     *				else an empty string if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
	Osp::Base::String GetText(void) const;


    /**
     * Sets the action ID of the %HeaderItem control.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]	actionId		    The specified action ID for this item
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The action ID of the specified item must be a positive integer.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     */
	result SetActionId(int actionId);


	/**
	 * Sets the background bitmap of the %HeaderItem control.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   pBitmap             The background bitmap to set,  @n
	 *                                  else @c null if no bitmap is to be displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     If the size of the bitmap is greater than the size of the item, the bitmap is scaled down. @n
     * 				For item size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_item_size.htm">Control Item Size</a>.
	 */
    result SetBackgroundBitmap(HeaderItemStatus status, const Osp::Graphics::Bitmap* pBitmap);


    /**
     * Sets the icon of the header item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   status              The status of the header item
     * @param[in]   pIcon               The icon to be set, @n
     *			                        else @c null if no icon is to be set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @remarks     If the size of the bitmap is greater than the default size, the bitmap is scaled down. @n
     *              The bitmap specified for the @c HEADER_ITEM_STATUS_NORMAL will be applied for all other statuses unless different bitmaps are explicitly 
	 *				set for those by using this method. @n
     *              Note that the specified bitmaps are ignored if the style of the Header control is not @c HEADER_STYLE_TITLE_BUTTON. @n
     *              Furthermore, the title button does not support @c HEADER_ITEM_STATUS_SELECTED status and the bitmap for the status is also ignored. @n
     *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result SetIcon(HeaderItemStatus status, const Osp::Graphics::Bitmap* pIcon);


	/**
	 * Sets the text of the %HeaderItem control.
     *
	 * @since		2.0
	 * @return		An error code
	 * @param[in] 	text		        The text to be set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 * @remarks		If the text cannot be displayed in a line, then the text is automatically displayed in two lines and the ellipsis is applied if the text 
	 *				is longer than two lines. @n
	 *				Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result SetText(const Osp::Base::String& text);


// Lifecycle
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred. 
	 */
	result Dispose(void);


private:
	friend class Header;
	friend class HeaderItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class HeaderItemEx* __pHeaderItemEx;
};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_HEADER_ITEM_H_

