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
 * @file	FUiCtrlHeader.h 
 * @brief	This is the header file for the %Header class.
 *
 * This header file contains the declarations of the %Header class.
 */
#ifndef _FUICTRL_HEADER_H_
#define _FUICTRL_HEADER_H_

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
#include "FUiCtrlHeaderItem.h"
#include "FUiCtrlButtonItem.h"
#include "FUiCtrlAnimation.h"

namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum	HeaderStyle
 * Defines the possible styles of a %Header control.
 * 
 * @since	2.0
 */
enum HeaderStyle
{
	HEADER_STYLE_TITLE,			/**< The title style */
	HEADER_STYLE_TITLE_BUTTON,	/**< The title button style */
	HEADER_STYLE_SEGMENTED		/**< The segmented style */
};
    
    
/**
 * @enum	HeaderAnimationPosition
 * Defines the possible positions of the waiting animation of a header.
 * 
 * @since   2.0
 */
enum HeaderAnimationPosition
{
	HEADER_ANIMATION_POSITION_TITLE,		/**< The title animation */
	HEADER_ANIMATION_POSITION_BUTTON_LEFT,	/**< The left button animation */
	HEADER_ANIMATION_POSITION_BUTTON_RIGHT	/**< The right button animation */
};


/**
 * @class	Header
 * @brief	This class is an implementation of a %Header control.
 * @since	2.0
 *
 * The %Header class displays a multi-purpose area at the top of the screen, which usually acts as a placeholder for descriptive 
 * contents, such as a title of the current screen. It can also contain buttons for performing various user-defined tasks. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_header.htm">Header</a>.
 *
 * The following examples demonstrate how to use the %Header class.

 * 
 * - Constructing a header @n
 * When creating a Form, specify the FORM_STYLE_HEADER parameter in the Form::Construct() method.

 * @code
 *  
 * // Initialize
 *  bool
 * TestForm::Initialize(void) 
 * {  
 * 		Construct(FORM_STYLE_NORMAL | FORM_STYLE_INDICATOR | FORM_STYLE_HEADER );
 * }
 * @endcode
 *
 * - Using the header @n
 * Acquire access to the header with the GetHeader() method, and set the header style.
 *
 * @code
 *  
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		Header* pHeader = GetHeader();
 * 		pHeader->SetStyle(HEADER_STYLE_SEGMENTED);
 * }
 * @endcode 
 *
 * - Adding items to the header: @n
 * Add HeaderItems or ButtonItems according to the header style. The action ID registered in the Construct() method is notified
 * when items are touched.
 *
 * @code
 *  
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		HeaderItem headerItem;
 * 		headerItem.Construct(ID_HEADER_ITEM);
 * 		headerItem.SetText("HeaderItem");
 *
 * 		pHeader->AddItem(headerItem);
 *
 * 		ButtonItem buttonItem;
 *		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_BUTTON);
 * 		buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
 *
 * 		pHeader->SetButton(BUTTON_POSITION_LEFT, buttonItem);
 *
 * }
 * @endcode 
 *
 *
 * - Setting the header title and description:
 *
 * @code
 *
 * bool
 * TestForm::Initialize(void) 
 * {  
 * 		pHeader->SetTitleText(L"Header Title");
 * 		pHeader->SetDescriptionText(L"Description Text");
 * }
 * @endcode 
 */
class _EXPORT_CONTROLS_ Header
    : public Osp::Ui::Control
{
// Operations
public:
    /**
     * Adds the specified header item.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   item                The header item object to be added
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit. 
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
     *									The specified item is not constructed.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The %Header control does not throw any exception even though the same action ID is assigned to multiple items. @n 
     *              However, the content of the specified item is copied to the %Header control.
     */
    result AddItem(const HeaderItem& item);


    /**
     * Inserts the header item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex           The index where the item should be inserted
     * @param[in]   item                The HeaderItem object to be inserted
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit. 
     * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure, or the index is greater than or equal to the number of elements or less than zero. 
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
     *									The specified item is not constructed.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The %Header control does not throw any exception even though the same action ID is assigned to multiple items. @n 
     *              However, the content of the specified item is copied to the %Header control.
     */
    result InsertItemAt(int itemIndex, const HeaderItem& item);


	/**
	 * Checks whether a button item is set at the specified position.
	 *
	 * @since		2.0
	 * @return		@c true if the button item is set at the specified position, @n
	 *				else @c false
	 * @param[in]	position			The position of the button item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
    bool IsButtonSet(ButtonPosition position) const;


    /**
     * Gets the state of the specified button item.
     *
	 * @since		2.0
     * @return      The state of the button item at the specified position, @n
	 *				else @c BUTTON_ITEM_STATUS_NORMAL if an error occurs
     * @param[in]   position			The position of the button item
     * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *									There is no button set at the specified position.
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    ButtonItemStatus GetButtonStatus(ButtonPosition position) const;


    /**
     * Gets the color of the button item for the specified state.
     *
 	 * @since		2.0
     * @return		The color of the button item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status				The status of the button item
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
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
     * @param[in]   status				The status of the button item
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
    Osp::Graphics::Color GetButtonTextColor(ButtonItemStatus status) const;


	/**
 	 * Gets the description text of the %Header control that has the title style.
     *
 	 * @since		2.0
 	 * @return		The description text, @n
     *				else an empty string if an error occurs
 	 * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Base::String GetDescriptionText(void) const;
	

	/**
	 * Gets the description text color of the Header control that has the title style.
	 *
	 * @since		2.0
	 * @return		The description text color, @n
     *				else RGBA (0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. 
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetDescriptionTextColor(void) const;
	

    /**
     * Gets the color of the header item for the specified item state.
     *
	 * @since		2.0
     * @return		The color of the item, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]	status				The item status
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetItemColor()
     */
    Osp::Graphics::Color GetItemColor(HeaderItemStatus status) const;


    /**
     * Gets the total number of header items.
     *
	 * @since		2.0
     * @return		The total number of header items, @n
     *				else @c -1 if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
    int GetItemCount(void) const;


    /**
     * Gets the state of the specified header item.
     *
	 * @since		2.0
     * @return		The item status
     * @param[in]	itemIndex			The index of the item
     * @param[out]	status				The item status
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than zero.   
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     */
    result GetItemStatus(int itemIndex, HeaderItemStatus& status) const;


    /**
     * Gets the text color of the header item for the specified item state.
     *
	 * @since		2.0
     * @return		The item's text color, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]	status				The item status
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetItemTextColor(HeaderItemStatus status) const;
    

    /**
     * Gets the style of the %Header control.
     *
	 * @since		2.0
     * @return		The %Header control style, @n
	 *				else @c HEADER_STYLE_TITLE if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method. 
     */
    HeaderStyle GetStyle(void) const;


    /**
     * Gets the index of the currently selected item.
     *
	 * @since		2.0
     * @return		The selected item index, @n 
     *				else @c -1 if an error occurs
     * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is not supported when the style of the Header control is not @c HEADER_STYLE_SEGMENTED. 
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @remarks		The specific error code can be accessed using the GetLastResult() method. 
     */
    int GetSelectedItemIndex(void) const;


	/**
	 * Gets the title text of the %Header control that has the title style.
	 *
	 * @since		2.0
	 * @return		The title text, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. 
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Base::String GetTitleText(void) const;


	/**
	 * Gets the title text color of the %Header control that has the title style.
	 *
	 * @since		2.0
	 * @return		The title text color, @n
     *				else RGBA (0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetTitleTextColor(void) const;
	

    /**
     * Gets the color of the %Header control.
     *
	 * @since		2.0
     * @return		The header color, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @remarks		The specific error code can be accessed using the GetLastResult() method. 
     */
    Osp::Graphics::Color GetColor(void) const;
    

	/**
	 * Gets the status of the waiting animation at the specified position.
	 *
	 * @since		2.0
	 * @return		The animation status 
	 * @param[in]	animationPos		The waiting animation position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *              This method returns @c ANIMATION_STOPPED, if no animation is in progress at the specified position.
	 * @see			PauseWaitingAnimation()
	 * @see			PlayWaitingAnimation()
	 * @see			StopWaitingAnimation()
	 */
	AnimationStatus GetWaitingAnimationStatus(HeaderAnimationPosition animationPos) const;


    /**
     * Pauses the waiting animation at the specified position.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	animationPos			The waiting animation position
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
     *										No waiting animation is in progress at the specified position.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @see			PlayWaitingAnimation()
     * @see			StopWaitingAnimation()
     */
    result PauseWaitingAnimation(HeaderAnimationPosition animationPos);


    /**
     * Starts the waiting animation at the specified position.
     *
 	 * @since		2.0
     * @return		An error code
     * @param[in]	animationPos			The waiting animation position
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
     *										There is no button set at the specified position (except for @c HEADER_ANIMATION_POSITION_TITLE).
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @see			SetButton()
     * @see			IsButtonSet()
     * @see			GetWaitingAnimationStatus()
     * @see			PauseWaitingAnimation()
     * @see			StopWaitingAnimation()
     */
    result PlayWaitingAnimation(HeaderAnimationPosition animationPos);

    
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
     * Removes all the %Header control items.
     *
	 * @since		2.0
     * @return		An error code
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state. 
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The left button, right button, and back button items are not removed.
     */
    result RemoveAllItems(void);    
    

    /**
     * Removes the item at the specified index.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	itemIndex			The index of the item to be removed
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
     * @exception	E_INVALID_STATE   	This instance is in an invalid state. 
     * @exception	E_SYSTEM         	A system error has occurred.
     */
    result RemoveItemAt(int itemIndex);


    /**
     * Removes the button item at the specified position.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   position        The position of the button item to remove
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception   E_SYSTEM        A system error has occurred.
     * @remarks     If no button item is set at the specified position, the method returns @c E_SUCCESS. 
     */
    result RemoveButtonAt(ButtonPosition position);
    

    /**
     * Sets the background bitmap image.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   pBitmap				The background image
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
     * @exception   E_SYSTEM			A system error has occurred.
     * @remarks     For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
     */
    result SetBackgroundBitmap(const Osp::Graphics::Bitmap* pBitmap);


    /**
     * Sets the button item at the specified position.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   position			The position at which to set the specified button item
     * @param[in]   button				The button item to be set
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified item is not constructed.
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
     * @exception   E_SYSTEM			A system error has occurred.	 
     * @remarks     If there is an existing button item at the specified position, it is replaced with a new item. @n
     *              The contents of the specified item are copied. 
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
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   position			The button item position
	 * @param[in]   enable				Set to @c true to enable the specified button item, @n
	 *									else @c false to disable
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									There is no button set at the specified position.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 */
	result SetButtonEnabled(ButtonPosition position, bool enable);


    /**
     * Sets the text color of the button item for the specified state.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   status          The status of the button item
     * @param[in]   color           The button item text color to be set
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception   E_SYSTEM        A system error has occurred.
     */
    result SetButtonTextColor(ButtonItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the contents of the %Header control item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex         	The index at which to set the specified item
     * @param[in]   item              	The item to be set
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_OUT_OF_RANGE    	The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than zero.  
     * @exception   E_INVALID_ARG     	A specified input parameter is invalid. 
     * @exception   E_INVALID_STATE   	This instance is in an invalid state. 
     * @exception   E_SYSTEM          	A system error has occurred.
     * @remarks     The contents of the specified item are copied. 
     */
    result SetItemAt(int itemIndex, const HeaderItem& item);


    /**
     * Sets the badge icon of the specified segmented style header item.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	itemIndex				The item index
     * @param[in]	pBadgeIcon				The bitmap for the icon
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.  
	 * @exception	E_UNSUPPORTED_OPERATION This operation is not supported. @n
	 *										The operation is not supported when the style of the %Header control is not @c HEADER_STYLE_SEGMENTED.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @remarks		For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
     */
    result SetItemBadgeIcon(int itemIndex, const Osp::Graphics::Bitmap* pBadgeIcon);


    /**
     * Sets the numbered badge icon of the specified segmented style header item.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	itemIndex					The item index
     * @param[in]	number						The number value that should be displayed as the badge icon
     * @exception	E_SUCCESS					The method is successful.
     * @exception	E_INVALID_ARG				The specified @c number must be in the range defined by 0 and 99999.
     * @exception	E_OUT_OF_RANGE				The specified index is outside the bounds of the data structure. @n
	 *											The index is greater than or equal to the number of elements or less than zero. 
     * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported. @n
     *                                          The operation is not supported when the style of the %Header control is not @c HEADER_STYLE_SEGMENTED.
     * @exception	E_INVALID_STATE				This instance is in an invalid state.
     * @exception	E_SYSTEM					A system error has occurred.
     * @remarks		To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
     */
    result SetItemNumberedBadgeIcon(int itemIndex, int number);


    /**
     * Sets the item color for the specified state.
     *
     * @since   	2.0
     * @return		An error code
     * @param[in]	status          The item status 
     * @param[in]	color           The item color to be set  
     * @exception	E_SUCCESS 	    The method is successful.
     * @exception   E_INVALID_STATE This instance is in an invalid state. 
     * @exception	E_SYSTEM	    A system error has occurred.
     * @see         GetItemColor()
     */
    result SetItemColor(HeaderItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the item state at the specified index in the %Header control.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex            	The index of the item to be set
     * @param[in]   enabled     		 	Set to @c true to enable the item state, @n
     *                        			 	else @c false
     * @exception   E_SUCCESS            	The method is successful.
     * @exception   E_OUT_OF_RANGE       	The specified index is outside the bounds of the data structure. @n 
	 *										The index is greater than or equal to the number of elements or less than zero. 
	 * @exception   E_INVALID_OPERATION  	The current state of the instance prohibits the execution of the specified operation. @n
     *                                   	The specified item is currently selected.
     * @exception   E_INVALID_STATE      	This instance is in an invalid state. 
     * @exception   E_SYSTEM             	A system error has occurred.
     */
    result SetItemEnabled(int itemIndex, bool enabled);


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
    result SetItemTextColor(HeaderItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the selected item at the specified index.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   itemIndex               The index of the item to be selected
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n 
	 *										The index is greater than or equal to the number of elements or less than zero.   
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
     *                                   	The item at the specified index is disabled.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported. @n
	 *										The operation is not supported when the Header control style is @c HEADER_STYLE_TITLE.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM                A system error has occurred.
     */
    result SetItemSelected(int itemIndex);
    

    /**
     * Sets the color of the %Header control.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   color               The header color
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     */
    result SetColor(const Osp::Graphics::Color& color);        
    
    
	/**
	 * Sets the style of the %Header control.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in] 	style		         The header style to be set
	 * @exception   E_SUCCESS			 The method is successful.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @exception   E_SYSTEM			 A system error has occurred.
	 */
	result SetStyle(HeaderStyle style);


	/**
	 * Sets the title icon of the %Header control that has the title style.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in] 	pIcon        	        The title icon to be set @n
	 *								        Set to @c null to remove the title icon.
	 * @exception	E_SUCCESS 		        The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation @n
	 *                                      The style of the %Header control is not @c HEADER_STYLE_TITLE.
	 * @exception	E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_INVALID_STATE         This instance is in an invalid state.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks	    For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>. 
	 */
	result SetTitleIcon(const Osp::Graphics::Bitmap* pIcon);
	

	/**
	 * Sets the title text of the %Header control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text		        	The text to be set
	 * @exception	E_SUCCESS 		    	The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the Header control is not @c HEADER_STYLE_TITLE.
	 * @exception	E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception	E_SYSTEM		    	A system error has occurred.
	 * @remarks		If the text cannot be displayed in a line, then the ellipsis is applied at the end. @n
	 *				When the title icon is set along with the title text, the title retains the left alignment.
	 */
	result SetTitleText(const Osp::Base::String& text);


    /**
     * Sets the title text color.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   color    				The title text color to be set
	 * @exception	E_SUCCESS 		    	The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the %Header control is not @c HEADER_STYLE_TITLE.
     * @exception   E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception	E_SYSTEM		    	A system error has occurred.
     */
    result SetTitleTextColor(const Osp::Graphics::Color& color);


	/**
	 * Sets the description text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text		        	The text to be set
	 * @exception	E_SUCCESS 		    	The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the %Header control is not @c HEADER_STYLE_TITLE.
	 * @exception   E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception	E_SYSTEM		    	A system error has occurred.
	 * @remarks		If the text cannot be displayed in a line, then the ellipsis is applied at the end. @n
	 *				When the title icon is set along with the title text, the title retains the left alignment.
	 */
	result SetDescriptionText(const Osp::Base::String& text);


    /**
     * Sets the description text color.
     *
	 * @since		2.0
     * @return      An error code
     * @param[in]   color    				The description text color to be set
	 * @exception	E_SUCCESS 		    	The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the %Header control is not @c HEADER_STYLE_TITLE.
	 * @exception   E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception	E_SYSTEM		    	A system error has occurred.
     */
    result SetDescriptionTextColor(const Osp::Graphics::Color& color);


	/**
	 * Sets the show state of a control.
	 *
	 * @since   	2.0
	 * @return		An error code
	 * @param[in]	state               	Set to @c true to draw and display the control, @n
	 *										else @c false
	 * @exception	E_SUCCESS           	The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										This control cannot be displayed.
	 * @exception	E_SYSTEM            	A system error has occurred.
	 * @remarks     Even if this method is invoked, the control is not drawn or displayed. @n
	 *              To draw and display the control, use the Draw() and Show() methods respectively. @n
	 *              If the state of the control is set to @c false, the state should be set to @c true before drawing and displaying the control.
	 * @see         GetShowState()
	 * @see         Draw()
	 * @see         Show()
	 *
	 */
	virtual result SetShowState(bool state);


    /**
     * Stops the waiting animation in progress at the specified position.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	animationPos			The waiting animation position
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @remarks		This method returns @c E_INVALID_OPERATION if no waiting animation is in progress at the specified position.
     * @see			GetWaitingAnimationStatus()
     * @see			PauseWaitingAnimation()
     * @see			PlayWaitingAnimation()
     */
    result StopWaitingAnimation(HeaderAnimationPosition animationPos);


// Listeners
public:
    /**
     * Adds an IActionEventListener instance.
     * OnActionPerformed() of the added listener is called when the user selects an item.
     *
	 * @since		2.0
     * @param[in]	listener	The event listener to be added
     */
    void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);


    /**
     * Removes an IActionEventListener instance.
     * The removed listener cannot listen to events when they are fired.
     *
	 * @since		2.0
     * @param[in]   listener	The event listener to be removed
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
     * @since         2.0
     */	 
	Header(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
     * @since         2.0
     */	 
    virtual ~Header(void);
        
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since		2.0
     * @return      An error code
     * @exception   E_SUCCESS   The method is successful.
     * @exception   E_SYSTEM    A system error has occurred. 
     */
    result Dispose(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of Header with the specified parameter.
     *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception   E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	result Construct(Handle headerHandle);

	friend class Form;
	friend class HeaderEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class HeaderEx* __pHeaderEx;

protected:
	friend class HeaderImpl;
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
	class HeaderImpl* GetImpl(void) const;

};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_HEADER_H_

