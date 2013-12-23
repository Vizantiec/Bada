// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlButtonItem.h
 * @brief	This is the header file for the %ButtonItem class.
 *
 * This header file contains the declarations of the %ButtonItem class.
 */

#ifndef _FUICTRL_BUTTON_ITEM_H_
#define _FUICTRL_BUTTON_ITEM_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

// Namespace declaration
namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum ButtonItemStatus
 * Defines the possible states of the button item.
 *
 * @since		2.0
 */
enum ButtonItemStatus
{
	BUTTON_ITEM_STATUS_NORMAL = 0,	/**< The normal status */
	BUTTON_ITEM_STATUS_PRESSED,		/**< The selected status */
	BUTTON_ITEM_STATUS_HIGHLIGHTED,	/**< The highlighted status */
	BUTTON_ITEM_STATUS_DISABLED		/**< The disabled status */
};


/**
 * @enum ButtonPosition
 * Defines the possible positions of the button item.
 *
 * @since		2.0
 */
enum ButtonPosition
{
	BUTTON_POSITION_LEFT = 0,		/**< The position of the button is towards the left of the object */
	BUTTON_POSITION_RIGHT 			/**< The position of the button is towards the right of the object */
};


/**
 * @enum ButtonItemStyle
 * Defines the possible styles of the button item.
 *	
 * @since 2.0
 */
enum ButtonItemStyle
{
	BUTTON_ITEM_STYLE_TEXT = 0,		/**< The text ButtonItem style */
	BUTTON_ITEM_STYLE_ICON			/**< The icon ButtonItem style */
};


/**
 * @class	ButtonItem
 * @brief	This class is an implementation of %ButtonItem.
 * @since	2.0
 *
 * The %ButtonItem class is a helper class that specifies the
 * properties of button items in a Footer or Header.
 */
class _EXPORT_CONTROLS_ ButtonItem
	: public Osp::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	ButtonItem(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
    virtual ~ButtonItem(void);
    	
	
	/**
	 * Initializes this instance of ButtonItem with the specified parameters.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]	style		    The style of the button item
	 * @param[in]	actionId	    The action ID of the button item
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid. @n
	 *                              The specified @c actionId of the specified item must be a positive integer.
	 * @exception   E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 */
	result Construct(ButtonItemStyle style, int actionId);


// Operation
public:
	/**
	 * Gets the action ID of the button item.
	 *
	 * @since		2.0
	 * @return      The action ID, @n 
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActionId(void) const;


	/**
	 * Gets the text of the button item.
	 *
	 * @since		2.0
	 * @return	 	The item text, @n
	 *           	else an empty string if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetText(void) const;


	/**
	 * Sets the action ID of the button item.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]	actionId	      The action ID of the button item
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     A specified input parameter is invalid. @n
	 *                                The specified @c actionId of the specified item must be a positive integer.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 */
	result SetActionId(int actionId);


	/**
	 * Sets the background bitmap image of the button item.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   pBitmap             The background bitmap image to be set, @n
	 *                                  else @c null if no bitmap image is displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     If the size is greater than the default size, the bitmap image is scaled accordingly. @n
	 *              For item size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_item_size.htm">Control Item Size</a>.
	 */
	result SetBackgroundBitmap(ButtonItemStatus status, const Osp::Graphics::Bitmap* pBitmap);


	/**
	 * Sets the icon of the button item for the specified state.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in] 	pIcon               The icon to be set, @n
	 *					   		        else @c null if no icon is displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @remarks     If the style of ButtonItem is BUTTON_ITEM_STYLE_TEXT, the method returns E_INVALID_OPERATION. @n
	 *              If an icon is not set for a state, the icon for BUTTON_ITEM_STATUS_NORMAL is used. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetIcon(ButtonItemStatus status, const Osp::Graphics::Bitmap* pIcon);


	/**
	 * Sets the text of %ButtonItem.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in] 	text		        The text to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.@n
	 *                                  The style of %ButtonItem is BUTTON_ITEM_STYLE_ICON.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks		If the text cannot be displayed in a line, then the text is automatically displayed in two lines and the ellipsis is applied if the text 
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
	 * Frees the resources allocated by this control and destroys its native window, if present.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred. @n
	 *                          Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


private:
	friend class Footer;
	friend class Header;
	friend class ButtonItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */
	class ButtonItemEx* __pButtonItemEx;
};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_BUTTONITEM_H_

