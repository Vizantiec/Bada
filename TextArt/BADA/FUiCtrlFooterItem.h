// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlFooterItem.h
 * @brief	This is the header file for the %FooterItem class.
 *
 * This header file contains the declarations of the %FooterItem class.
 */

#ifndef _FUICTRL_FOOTER_ITEM_H_
#define _FUICTRL_FOOTER_ITEM_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

// namespace declaration
namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum FooterItemStatus
 * Defines the possible status of %FooterItem.
 * @since 2.0
 */
enum FooterItemStatus
{
	FOOTER_ITEM_STATUS_NORMAL = 0,	/**< The normal state */
	FOOTER_ITEM_STATUS_PRESSED ,	/**< The pressed state */
	FOOTER_ITEM_STATUS_SELECTED,	/**< The selected state */
	FOOTER_ITEM_STATUS_HIGHLIGHTED,	/**< The highlighted state */
	FOOTER_ITEM_STATUS_DISABLED		/**< The disabled state */
};


/**
 * @class	FooterItem
 * @brief	This class is an implementation of %FooterItem.
 * @since	2.0
 *
 * The %FooterItem class is a helper class that specifies the contents of the footer item.
 *
 *For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_footer.htm">Footer</a>.
 */
class _EXPORT_CONTROLS_ FooterItem
	: public Osp::Base::Object
{
public:
// Lifecycle
    /**
     * This is the default constructor for this class.
	 *
	 * @since		2.0
     */
    FooterItem(void);


    /**
     * This is the destructor for this class.
     *
	 * @since		2.0
	 */
    virtual ~FooterItem(void);


    /**
     * Initializes this instance of %FooterItem with the specified parameter.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   actionId	    The action ID of this item
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
     *								The specified @c actionId of the specified item must be a positive integer.
     * @exception   E_OUT_OF_MEMORY A system error has occurred.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     */
    result Construct(int actionId);


// Operation
public:
    /**
     * Gets the action ID of the item.
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
     * Gets the text of the footer item.
     *
	 * @since		2.0
     * @return	    The item text, @n
     *				else an empty string if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
    Osp::Base::String GetText(void) const;


    /**
     * Sets the action ID of the footer item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   actionId		The specified action ID of the footer item
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
     *								The specified @c actionId of the specified item must be a positive integer.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     */
    result SetActionId(int actionId);


    /**
     * Sets the background bitmap of the footer item.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]   status              The status of the footer item
	 * @param[in]   pBitmap             The background bitmap to set, @n
	 *                                  else @c null if no bitmap is displayed.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     If the size of the bitmap is greater than the size of the item, the bitmap is scaled down. @n
     * 				For item size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_item_size.htm">Control Item Size</a>.
	 */
    result SetBackgroundBitmap(FooterItemStatus status, const Osp::Graphics::Bitmap* pBitmap);


    /**
     * Sets the icon of the footer item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   status              The status of the footer item	 
     * @param[in]   pIcon               The icon to set, @n
     *			                        else @c null if no bitmap is displayed
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     If the size of the bitmap is greater than the default icon size, the bitmap is scaled down. @n
     *              The bitmap specified for the @c FOOTER_ITEM_STATUS_NORMAL will be applied for all other statues unless different bitmaps are explicitly 
	 *				set for those by using this method. @n
     *              Furthermore, the icon button does not support @c FOOTER_ITEM_STATUS_SELECTED status and the bitmap for the status is also ignored.@n
     *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result SetIcon(FooterItemStatus status, const Osp::Graphics::Bitmap* pIcon);


    /**
     * Sets the text of the footer item.
     *
     * @since		2.0
     * @return	    An error code
     * @param[in]   text		        The text to be set
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks	    If the text cannot be displayed in a line, then the text is automatically displayed in two lines and the ellipsis is applied if the text 
	 *				is longer than two lines. @n
	 *				Use @htmlonly '\n' @endhtmlonly to denote the end of the first line.
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
	 * Frees the resources allocated by this control and destroys its native window if it is present.
	 *
	 * @since		2.0
	 * @return		An error code
     * @exception	E_SUCCESS   The method is successful.
     * @exception   E_SYSTEM    A system error has occurred. 
     *                          
	 */
    result Dispose(void);


private:
	friend class Footer;
	friend class FooterItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class FooterItemEx* __pFooterItemEx;
};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_FOOTER_ITEM_H_

