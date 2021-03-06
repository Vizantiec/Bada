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
 * @file            FUiCtrlFooter.h 
 * @brief	This is the header file for the %Footer class.
 *
 * This header file contains the declarations of the %Footer class.
 */
#ifndef _FUICTRL_FOOTER_H_
#define _FUICTRL_FOOTER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FGrpColor.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiCtrlForm.h"
#include "FUiIActionEventListener.h"
#include "FUiCtrlFooterItem.h"
#include "FUiCtrlButtonItem.h"

namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum FooterStyle
 * Defines the possible styles of a %Footer control.
 *
 * @since 2.0
 */
enum FooterStyle
{
	FOOTER_STYLE_BUTTON_TEXT,		/**< The text button style */
    FOOTER_STYLE_BUTTON_ICON,		/**< The icon button style */
    FOOTER_STYLE_SEGMENTED_TEXT,	/**< The text segmented style */
    FOOTER_STYLE_SEGMENTED_ICON,	/**< The icon segmented style */
    FOOTER_STYLE_TAB				/**< The tab style */
};

    
/**
 * @class   Footer
 * @brief	This class is an implementation of a %Footer control.
 * @since   2.0
 *
 * The %Footer class displays a multi-purpose area at the bottom of the screen. It is used to switch between different application
 * "views", or to host buttons for performing user-defined actions. 
 *
 *For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_footer.htm">Footer</a>.
 *
 *The following examples demonstrate how to use the %Footer class.
 * - Constructing a footer
 * When creating a %Form, specify the FORM_STYLE_FOOTER parameter in the Form::Construct() method.
 *
 * @code
 *  
 * // Initialize
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		Construct(FORM_STYLE_NORMAL | FORM_STYLE_INDICATOR | FORM_STYLE_FOOTER);
 * }
 * @endcode
 *
 * - Using the footer 
 * Acquire access to the footer with the GetFooter() method, and set the footer style.
 *
 * @code
 *  
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		Footer* pFooter = GetFooter();
 * 		pFooter->SetStyle(FOOTER_STYLE_SEGMENTED_TEXT);
 * }
 * @endcode 
 *
 * - Adding items to the footer:
 * Add FooterItems or ButtonItems according to the footer style. The action ID registered in the Construct() method is notified
 * when items are touched. 
 *
 * @code
 *  
 *  bool
 * TestForm::Initialize(void) 
 * {  
 * 		FooterItem footerItem;
 * 		footerItem.Construct(ID_FOOTER_ITEM);
 * 		footerItem.SetText("FooterItem");
 *
 * 		pFooter->AddItem(footerItem);
 *
 * 		ButtonItem buttonItem;
 * 		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_BUTTON);
 * 		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
 *
 * 		pFooter->SetButton(BUTTON_POSITION_LEFT, buttonItem);
 *
 * }
 * @endcode 
 *
 * Using the back button
 * The image of back button is internally set by UI framework.
 *
 * @code
 *
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		pFooter->SetBackButton ();
 * }
 * @endcode 
 */
class _EXPORT_CONTROLS_ Footer
    : public Osp::Ui::Control
{
// Operations
public:
    /**
     * Adds the specified footer item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   item                The footer item to be added
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit. 
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
     *									The specified item is not constructed.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n 
     *              However, the content of the specified item is copied to the %Footer control. @n
     *              Depending on the style of the %Footer control, several types of items can be added or inserted. 
     */
    result AddItem(const FooterItem& item);


    /**
     * Inserts the footer item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex           The index where the item should be inserted
     * @param[in]   item                The footer item object to be inserted
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit. 
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure. @n 
	 *									The index is greater than or equal to the number of elements or less than @c 0. 
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
     *									The specified item is not constructed.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The %Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n 
     *              However, the content of the specified item is copied to the %Footer control. @n 
     *              Depending on the style of the %Footer control, several types of items can be added or inserted. 
     */
    result InsertItemAt(int itemIndex, const FooterItem& item);


	/**
	 * Checks whether a button item is set at the specified position.
	 *
	 * @since		2.0
	 * @return		@c true if the button item is set at the specified position, @n
	 *				else @c false
	 * @param[in]   position            The position of the button item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
    bool IsButtonSet(ButtonPosition position) const;


	/**
	 * Checks whether the back button item is set.
	 *
	 * @since		2.0
	 * @return		@c true if the back button item is set, @n
	 *				else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
    bool IsBackButtonSet(void) const;


	/**
	 * Checks whether the tab edit mode is enabled.
	 *
	 * @since		2.0
	 * @return      @c true if the tab edit mode is set, @n
	 *				else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 */
	bool IsTabEditModeEnabled(void) const;


    /**
     * Gets the color of the button item for the specified state.
     *
	 * @since		2.0
     * @return      The color of the button item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status              The status of the button item
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetButtonColor()
     */
    Osp::Graphics::Color GetButtonColor(ButtonItemStatus status) const;


    /**
     * Gets the text color of the button item for the specified state.
     *
	 * @since		2.0
     * @return      The text color of the button item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status              The status of the button item
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetButtonTextColor()
     */
    Osp::Graphics::Color GetButtonTextColor(ButtonItemStatus status) const;


    /**
     * Gets the state of the specified button item.
     *
	 * @since		2.0
     * @return      The state of the button item at the specified position
     * @param[in]   position			The position of the button item
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
     *									There is no button set at the specified position.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    ButtonItemStatus GetButtonStatus(ButtonPosition position) const;


	/**
	 * Gets the state of the back button.
	 *
	 * @since       2.0
	 * @return      The state of the back button, @n
	 *				else @c BUTTON_ITEM_STATUS_NORMAL if an error occurs.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *									The back button is not set.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	ButtonItemStatus GetBackButtonStatus(void) const;


    /**
     * Gets the color of the footer item for the specified item state.
     *
	 * @since		2.0
     * @return      The color of the item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status    The item status
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetItemColor()
     */
    Osp::Graphics::Color GetItemColor(FooterItemStatus status) const;


    /**
     * Gets the number of footer items.
     *
	 * @since		2.0
     * @return      The number of footer items, @n
     *              else @c -1 if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    int GetItemCount(void) const;


    /**
     * Gets the state of the specified footer item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex         The index of the item
     * @param[out]  status            The state of the item at the specified index
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_OUT_OF_RANGE    	The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than zero. 
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     */
    result GetItemStatus(int itemIndex, FooterItemStatus& status) const;


    /**
     * Gets the text color of the footer item for the specified item state.
     *
	 * @since		2.0
     * @return      The text color of the item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status              The item status   
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetItemTextColor(FooterItemStatus status) const;
    

    /**
     * Gets the style of the %Footer control.
     *
	 * @since		2.0
     * @return      The footer style, @n
     *				else @c FOOTER_STYLE_BUTTON_TEXT if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    FooterStyle GetStyle(void) const;


    /**
     * Gets the index of the currently selected item.
     *
	 * @since		2.0
     * @return      The selected item index,@n 
     *              else @c -1 if an error occurs
     * @exception   E_SUCCESS           	The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is supported only when the style of the Footer control is either segmented or tab. 
     * @exception   E_INVALID_STATE     	This instance is in an invalid state.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    int GetSelectedItemIndex(void) const;


    /**
     * Gets the color of the footer.
     *
	 * @since		2.0
     * @return      The color, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetColor(void) const;
    
    
    /**
     * Removes all the button items.
     *
	 * @since		2.0
     * @return      An error code
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception   E_SYSTEM        A system error has occurred.
     */
    result RemoveAllButtons(void);
        
    
    /**
     * Removes the button item at the specified position.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   position        The position of the button item to be removed
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception   E_SYSTEM        A system error has occurred.
     * @remarks     If no button item is set at the specified position, the method will return @c E_SUCCESS. 
     */
    result RemoveButtonAt(ButtonPosition position);


    /**
     * Removes the back button item.
     *
	 * @since		2.0
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     If the back button item is not set, the method will return @c E_SUCCESS. 
     */
    result RemoveBackButton(void);


    /**
     * Removes all the footer items. 
     *
	 * @since		2.0
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The left, right, and back button items are not removed. 
     */
    result RemoveAllItems(void);    
    

    /**
     * Removes the item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex			The index of the item to be removed
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n 
	 *									The index is greater than or equal to the number of elements or less than @c 0.  
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     * @exception   E_SYSTEM			A system error has occurred.
     */
    result RemoveItemAt(int itemIndex);


    /**
     * Sets the background bitmap image.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   pBitmap              The background image
     * @exception   E_SUCCESS            The method is successful.
     * @exception   E_INVALID_STATE      This instance is in an invalid state. 
     * @exception   E_SYSTEM             A system error has occurred.
     */
    result SetBackgroundBitmap(const Osp::Graphics::Bitmap* pBitmap);


    /**
     * Sets the button item at the specified position.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]   position                The position at which to set the specified button item.
     * @param[in]   button                  	The button item to be set
     * @exception   E_SUCCESS            		The method is successful.
     * @exception   E_INVALID_ARG        	A specified input parameter is invalid. @n
     *									 		The specified item is not constructed.
     * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.@n
     *											There are more than 2 footer items.
     * @exception   E_UNSUPPORTED_OPERATION This operation is not supported. @n
     *											The operation is supported when the style of the %Footer control is either 
	 *											@c FOOTER_STYLE_SEGMENTED_TEXT or @c FOOTER_STYLE_SEGMENTED_ICON.
     * @exception   E_INVALID_STATE      	This instance is in an invalid state. 
     * @exception   E_SYSTEM             		A system error has occurred.	 
     * @remarks     If there is an existing button item at the specified position, it is replaced with the new item.@n
     *              However, the contents of the specified item are copied to the %Footer control.  
     */
    result SetButton(ButtonPosition position, const ButtonItem& button);


    /**
     * Sets the button item color for the specified state.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	status          The status of the button item
     * @param[in]	color           The button item color to be set
     * @exception	E_SUCCESS 	    The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception	E_SYSTEM	    A system error has occurred.
     * @see         GetButtonColor()
     */
    result SetButtonColor(ButtonItemStatus status, const Osp::Graphics::Color& color);


	/**
	 * Enables or disables the button item at the specified position.
	 *
	 * @since    	2.0
	 * @return      An error code
	 * @param[in]   position             The button item position
	 * @param[in]   enable               	Set to @c true to enable the specified button item, @n
	 *										else @c false
	 * @exception   E_SUCCESS            	The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	 *									 	There is no button set at the specified position.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @exception   E_SYSTEM             	A system error has occurred.
	 */
	result SetButtonEnabled(ButtonPosition position, bool enable);


	/**
	 * Enables or disables the back button.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]   enable               	Set to @c true to enable the back button, @n 
	 *										else @c false
	 * @exception   E_SUCCESS            	The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	 *									 	The back button item is not set.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @exception   E_SYSTEM             	A system error has occurred.
	 */
	result SetBackButtonEnabled(bool enable);


    /**
     * Sets the button item text color for the specified state.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   status          The status of the button item
     * @param[in]   color           The button item text color to be set
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception   E_SYSTEM        A system error has occurred.
     * @see         GetButtonTextColor()
     */
    result SetButtonTextColor(ButtonItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the back button.
     *
     * @since       2.0
     * @return      An error code
     * @exception   E_SUCCESS                     The method is successful.
     * @exception   E_INVALID_OPERATION           The current state of the instance prohibits the execution of the specified operation. @n
     *                                            There are more than 2 footer items.
     * @exception   E_UNSUPPORTED_OPERATION       This operation is not supported. @n
     *											  The operation is not supported when the style of the %Footer control is @c FOOTER_STYLE_TAB. @n
     *                                            This device does not support the software back button.
     * @exception   E_INVALID_STATE               This instance is in an invalid state.
     * @exception   E_SYSTEM                      A system error has occurred.
     * @remarks     When the back button is pressed, OnFormBackRequested() of IFormBackEventListener is called. @n
     *              If the right button is already set, then the button is replaced with the back button.
     * @see         Osp::Ui::Controls::IFormBackEventListener
     */
    result SetBackButton(void);


    /**
     * Sets the content of the footer item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex         The index at which to set the specified item
     * @param[in]   item              The item
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_OUT_OF_RANGE    	The specified index is outside the bounds of the data structure. @n 
	 *									The index is greater than or equal to the number of elements or less than @c 0.  
     * @exception   E_INVALID_ARG     A specified input parameter is invalid. @n
     *								  	The specified item is not constructed. 
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     * @exception   E_SYSTEM          	A system error has occurred.
     * @remarks     The %Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n 
     *              However, the content of the specified item is copied to the Footer control. 
     */
    result SetItemAt(int itemIndex, const FooterItem& item);


    /**
     * Sets the item color for the specified state.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	status          		The item status
     * @param[in]	color           		The item color to be set
     * @exception	E_SUCCESS 	    		The method is successful.
     * @exception   E_INVALID_STATE 		This instance is in an invalid state.
     * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported. @n
     *                                      The current style of the %Footer control does not support the operation.
     * @exception	E_SYSTEM	    		A system error has occurred.
     * @remarks     It is not possible to set the item colors for the normal and disabled status of the @c FOOTER_STYLE_TAB style %Footer control. @n
     				Furthermore, @c FOOTER_STYLE_BUTTON_ICON style %Footer control does not support this operation.
     * @see         GetItemColor()
     */
    result SetItemColor(FooterItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the item state at the specified index in the footer.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]   itemIndex            The index of the item
     * @param[in]   enabled     		 	Set to @c true to enable the item state, @n
     *                        			 	else @c false
     * @exception   E_SUCCESS            	The method is successful.
     * @exception   E_OUT_OF_RANGE       	The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than zero.  
	 * @exception	E_INVALID_OPERATION	 The current state of the instance prohibits the execution of the specified operation. @n
	 *									 	The specified item is currently selected.
     * @exception   E_INVALID_STATE      This instance is in an invalid state. 
     * @exception   E_SYSTEM             	A system error has occurred.	 
     */
    result SetItemEnabled(int itemIndex, bool enabled);


    /**
     * Sets the badge icon of the specified tab style footer item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex               The index of the item to set the badge icon
     * @param[in]   pBadgeIcon           	The bitmap for the icon
     * @exception   E_SUCCESS            	The method is successful.
     * @exception   E_OUT_OF_RANGE       	The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.  
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is not supported when the style of the Footer control is @c FOOTER_STYLE_BUTTON_ICON.
     * @exception   E_INVALID_STATE      	This instance is in an invalid state.
     * @exception   E_SYSTEM             	A system error has occurred.
     */
    result SetItemBadgeIcon(int itemIndex, const Osp::Graphics::Bitmap* pBadgeIcon);


    /**
     * Sets the numbered badge icon of the specified footer item.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   itemIndex               The item index
     * @param[in]   number                  The number value that should be displayed as the badge icon
     * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c number must be in the range defined by @c 0 and @c 99999.
	 * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n 
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_UNSUPPORTED_OPERATION This operation is not supported. @n
     *                                      The operation is not supported when the style of the Footer control is @c FOOTER_STYLE_BUTTON_ICON.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state.
	 * @exception   E_SYSTEM                A system error has occurred.
     * @remarks     To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	 */
    result SetItemNumberedBadgeIcon(int itemIndex, int number);


    /**
     * Sets the item text color for the specified state.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   status              The item status
     * @param[in]   color               The item text color to be set
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 * @exception   E_SYSTEM            A system error has occurred.
     */
    result SetItemTextColor(FooterItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Selects the item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex               The index of the item to be selected
     * @exception   E_SUCCESS            	The method is successful.
     * @exception   E_OUT_OF_RANGE       	The specified index is out of the range of the data structure. @n 
	 *										The specified index is either greater than or equal to the number of items or is less than zero.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation. @n
     *                                      The item at the specified index is disabled.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is not supported if the %Footer control style is either @c FOOTER_STYLE_BUTTON_TEXT or @c FOOTER_STYLE_BUTTON_ICON.
     * @exception   E_INVALID_STATE      	This instance is in an invalid state.
     * @exception   E_SYSTEM             	A system error has occurred.
     */
    result SetItemSelected(int itemIndex);
    

    /**
     * Sets the color of the footer.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   color				The footer color to be set
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     */
    result SetColor(const Osp::Graphics::Color& color);        
    
  
	/**
	 * Sets the style of the footer.
     *
	 * @since		2.0
     * @return      An error code
	 * @param[in] 	style			    The footer style to set
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM			A system error has occurred.
	 */
	result SetStyle(FooterStyle style);  
	

	/**
	 * Changes the show state of the control.
	 *
	 * @since   	2.0
	 * @return		An error code
	 * @param[in]	state               	Set to @c true to draw and display the control, @n
	 *									    else @c false
	 * @exception	E_SUCCESS           	The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      This control cannot be displayed.
	 * @exception	E_SYSTEM            	A system error has occurred.
	 * @remarks     Even if this method is invoked, the control is not drawn or displayed. @n
	 *              To draw and display the control, use the Draw() and Show() methods respectively.@n
	 *              If the show state of the control is set to @c false, the state should be set to @c true before drawing and displaying the control.
	 * @see         GetShowState()
	 * @see         Draw()
	 * @see         Show()
	 */
	virtual result SetShowState(bool state);


	/**
	 * Determines whether the tab edit mode is enabled.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]   enable               	Set to @c true to enable the edit mode, @n
	 *                                   	else @c false
	 * @exception   E_SUCCESS            	The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is not supported when the style of the %Footer control style is not @c FOOTER_STYLE_TAB.
	 * @exception   E_INVALID_STATE      	This instance is in an invalid state.
	 */
	result SetTabEditModeEnabled(bool enable);


// Listeners
public:
    /**
     * Adds an action event listener instance.
     * OnActionPerformed() of the added listener is called when the user selects an item.
     *
	 * @since		2.0
     * @param[in]   listener	The event listener to be added
	 * @remarks		When the user collapses the tab style %Footer control which is in the expanded mode by pressing the more button, OnActionPerformed() is called for the currently selected tab item.
     */
    void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);


    /**
     * Removes an action event listener instance.
     * The removed listener cannot listen to events when they are fired.
     *
	 * @since		2.0
     * @param[in]	listener	The event listener to be removed
     */
    void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);


// Lifecycle
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * This is the default constructor for this class.
	 * @since		2.0
     */
	Footer(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * This is the destructor for this class.
	 * @since		2.0
     */
    virtual ~Footer(void);

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
	 * @exception	E_SYSTEM    A system error occurred.
	 */
    result Dispose(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of Footer with the specified parameter.
     *
     * @since       2.0     
	 * @return		An error code
	 * @exception	E_SUCCESS		        The method is successful.
	 * @exception	E_INVALID_STATE	        This instance has already been constructed.
	 * @exception   E_OUT_OF_MEMORY	        Insufficient memory.
	 * @exception	E_SYSTEM		        A system error occurred.
	 */
	result Construct(Handle footerHandle);

private:
	friend class Form;
	friend class FooterEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */			
	class FooterEx* __pFooterEx;

protected:
	friend class FooterImpl;
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control
     *
     * @since         2.0
     */
	class FooterImpl* GetImpl(void) const;
};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_FOOTER_H_

