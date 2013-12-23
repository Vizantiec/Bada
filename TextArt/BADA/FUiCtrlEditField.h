/* $Change: 984284 $ */
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
 * @file	FUiCtrlEditField.h
 * @brief	This is the header file for the EditField class.
 *
 * This header file contains the declarations of the EditField class and its helper classes.
 */

#ifndef _FUICTRL_EDIT_FIELD_CONTROL_H_
#define _FUICTRL_EDIT_FIELD_CONTROL_H_


// Includes
#include "FBaseString.h"
#include "FBaseChar.h"
#include "FGrpBitmap.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FLclLocale.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlEditEnum.h"
#include "FUiCtrlInputEnum.h"
#include "FUiITextEventListener.h"
#include "FUiIScrollPanelEventListener.h"
#include "FUiIActionEventListener.h"
#include "FUiILanguageEventListener.h"
#include "FUiCtrlTableViewStyleEnum.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiIKeypadEventListener.h"
#include "FUiITextBlockEventListener.h"
#include "FUiIUiLinkEventListener.h"

// Forward declarations
namespace Osp { namespace Locales	{ class Locale;	}; };
namespace Osp { namespace Ui { namespace Controls { class EditField; }; }; };


namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	EditField
 * @brief 	This class defines a common behavior for an %EditField control.
 * @since		1.0
 * 
 * The %EditField  class displays a single-line text editor. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.
 *
 * The following example demonstrates how to use the %EditField class.
 *
 * @code

// Sample Code for EditFieldSample.h
#include <FUi.h>

class EditFieldSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::ITextEventListener
{
public:
    virtual result OnInitializing(void);
    virtual void OnTextValueChanged(const Osp::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Osp::Ui::Control& source);
};

// Sample Code for EditFieldSample.cpp
#include "EditFieldSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
EditFieldSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates an EditField
    EditField* pEditField = new EditField();

    pEditField->Construct(Rectangle(0, 100, 480, 100));
    pEditField->AddTextEventListener(*this);

    //Adds an EditField to the Form
    AddControl(*pEditField);

    return r;
}

// Implements an ITextEventListener
void
EditFieldSample::OnTextValueChanged(const Osp::Ui::Control& source)
{
    // Todo:
}

void
EditFieldSample::OnTextValueChangeCanceled(const Osp::Ui::Control& source)
{
    // Todo:
}

 * @endcode
 *
 */

class _EXPORT_CONTROLS_ EditField :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(EditField);
// Lifecycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	EditField(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~EditField(void);

	/**
	 * Initializes this instance of the %EditField control with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions @b prior @b to @b 2.0. @n
	 *                  For more information, see @ref CompEditFieldConstruct "1.2" and @ref CompControlConstruct20 "2.0".
	 * @return			An error code
	 * @param[in]		rect		An instance of the Graphics::Rectangle class @n
	 *										This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *										the width and height of the control.
	 * @param[in] 	style			The style of the %EditField control
	 * @param[in] 	inputStyle		The input style of the %EditField control
	 * @param[in] 	showTitle				Set to @c true to display the title, @n
	 *								else @c false
	 * @param[in] 	limitLength		The limit for the length of the text in the %EditField control
	 * @param[in] 	groupStyle		The table view style of the %EditField control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_INVALID_ARG			The specified @c limitLength is less than or equal to @c 0, or @n
	 *										either the @c rect.width or the @c rect.height is less than @c 0.
	 * @exception   E_UNSUPPORTED_OPTION   	The specified option is not supported. @n 
	 *										The title is not supported by small style %EditField.
	 * @exception 	E_OUT_OF_MEMORY 		The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control has been used 
	 *				earlier. The EditField style of SMALL property cannot be used together with group styles. @n
	 *				If the specified size is less than the minimum size, EditField is constructed with the minimum size.
	 *
	 * @remarks		Following are the input styles used for creating the different orientations of a keypad: @n
	 * 				-	INPUT_STYLE_FULLSCREEN: The orientation is decided by the G-sensor value. @n
	 * 				-	INPUT_STYLE_OVERLAY: The orientation is the same as that of a parent form.
	 *
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, EditFieldStyle style = EDIT_FIELD_STYLE_NORMAL, InputStyle inputStyle = INPUT_STYLE_FULLSCREEN, bool showTitle =	false, int limitLength = 100, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * @page	CompEditFieldConstruct Compatibility for displaying the full screen keypad
	 *
	 * @section CompEditFieldConstructIssues Issues
	 *			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If the keypad language is Greek, Norwegian, or Malay, the full screen keypad is not displayed.
	 * -# The title is not supported with the small style %EditField.
	 *
	 * @section CompEditFieldConstructResolutions Resolutions
     * -# The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
     * -# The method returns E_UNSUPPORTED_OPTION if the title option is specified to small style %EditField.
	 */

	/**
	 * Initializes this instance of the %EditField control.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]	rect            		The bounds of EditField
	 * @param[in]    style           The style of the %EditField control
	 * @param[in]    inputStyle      The input style of the %EditField control
	 * @param[in]    titleStyle      The title style
	 * @param[in]	enableClear	 			Set to @c true to enable the clear button, @n
	 *										else @c false
	 * @param[in]    limitLength     The limit of the length of text in the %EditField control
	 * @param[in]    groupStyle      The table view style of the %EditField control
	 * @exception	E_SUCCESS       		The method is successful.
	 * @exception	E_INVALID_ARG   		A specified input parameter is invalid. @n
	 *                               		The specified @c limitLength is less than or equal to @c 0. @n
	 *								 		The specified @c rect.width or the @c rect.height is less than @c 0.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option is not supported. @n
	 *										Title is not supported in small style EditField.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception    E_INVALID_STATE 		This instance has already been constructed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		 A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control is used earlier.
	 *				The EditField style of SMALL property cannot be used together with group styles. @n
	 *               If the specified size is less than the minimum size, EditFied() is constructed with the minimum size.
	 *
	 * @remarks      Following are the input styles used for creating different orientations of a keypad: @n
	 *										-   INPUT_STYLE_FULLSCREEN: The orientation is decided by the G-sensor value.@n
	 *										-   INPUT_STYLE_OVERLAY: The orientation is similar to the parent Form.
	 *
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect,
			EditFieldStyle style, InputStyle inputStyle,
			EditFieldTitleStyle titleStyle, bool enableClear = false, int limitLength = 100,
			GroupStyle groupStyle = GROUP_STYLE_NONE);


// Operation
public:
// Text alignment
	/**
	 * Gets the horizontal text alignment of the %EditField control.
	 *
	 * @since		2.0
	 * @return		The horizontal text alignment
	 * @exception 	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	    The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextAlignment()
	 */
	HorizontalAlignment GetTextAlignment(void) const;

	/**
	 * Sets the horizontal text alignment of the %EditField control.
	 *
	 * @since     	2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetTextAlignment()
	 */
	result SetTextAlignment(HorizontalAlignment alignment);

//AutoLink
	/**
	 * Checks whether the view mode is enabled.
	 *
	 * @since       2.0
	 * @return		@c true if the view mode is enabled, @n
	 *              else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *				In the view mode, the auto-detected links are displayed as linked text.
	 * @see   SetViewModeEnabled()
	 */
	bool IsViewModeEnabled(void) const;

	/**
	 * Enables or disables the view mode.
	 *
	 * @since       2.0
	 * @return		An error code
	 * @param[in]	enable             	Set to @c true to enable the view mode, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		In the view mode, the auto-detected links are displayed as linked text.
	 * @see         IsViewModeEnabled()
	 */
	result SetViewModeEnabled(bool enable);

    /**
     * Sets the auto-link mask.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	autoLinks				The auto-link mask @n
     *										Multiple link types can be combined using bitwise OR operator (see Osp::Base::Utility::LinkType). @n
     *										For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		When @c autoLinks is set to @c 0, the auto-link detection is disabled.
     * @see			Osp::Base::Utility::LinkType
     * @see			GetAutoLinkMask()
     * @see			IsViewModeEnabled()
     * @see			SetViewModeEnabled()
     */
	result SetAutoLinkMask(unsigned long autoLinks);

    /**
     * Gets the auto-link mask.
     *
     * @since		2.0
     * @return		The auto-link mask
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetAutoLinkMask()
     */
	unsigned long GetAutoLinkMask(void) const;

    /**
     * Adds a link event listener. 
     *
     * @since		2.0
     * @param[in]	listener	The event listener to be added
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY. @n
     *				The added listener is notified when the links are selected by the user.
     * @see			RemoveUiLinkEventListener()
     */
	void AddUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

    /**
     * Removes the specified link event listener. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since		2.0
     * @param[in]	listener	The event listener to be removed
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.
     * @see			AddUiLinkEventListener()
     */
	void RemoveUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

// Margin
	/**
     * Gets the margin value of the specified margin type.
	 *
	 * @since       2.0
	 * @return	    The margin value of the specified margin type, @n
	 *				else @c -1 if an error occurs
	 * @param[in]   marginType		The margin type
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	int GetMargin(EditMarginType marginType) const;

	/**
	 * Sets the margin for the specified margin type.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]   marginType		The margin type
	 * @param[in]   margin			The margin to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid. @n
	 *								The specified @c margin cannot be a negative integer.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, int margin);

// Keypad action
    /**
     * Gets the keypad action type.
     *
     * @since		2.0
     * @return      The keypad action
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE     	This instance is in an invalid state.
     * @exception	E_SYSTEM            	A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadAction()
     */	
     Osp::Ui::KeypadAction GetKeypadAction(void) const;

    /**
     * Sets the keypad action type.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   keypadAction			The keypad action
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		Based on the specified value of @c keypadAction, the enter key label of the keypad changes accordingly.
	 * @see         GetKeypadAction()
     */
	result SetKeypadAction(Osp::Ui::KeypadAction keypadAction);


    /**
     * Sets the visibility of the command buttons of the overlay style keypad.
     *
     * @since		2.0 
     * @return		An error code
     * @param[in]	visible					Set to @c true to set the visibility of the overlay keypad command buttons, @n
	 *                                      else @c false
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     */
	result SetOverlayKeypadCommandButtonVisible(bool visible);

    /**
     * Checks whether the command buttons of the overlay style keypad are visible.
     *
     * @since       2.0
     * @return      @c true if the overlay command buttons are visible, @n
     *              else @c false
     * @exception   E_SUCCESS           		The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
     *											The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE     		This instance is in an invalid state.
     * @exception   E_SYSTEM            		A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
	bool IsOverlayCommandButtonVisible(void) const;

    /**
     * Hides the keypad.
     *
     * @since       2.0
     * @return      An error code
     * @exception   E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *										The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @see         ShowKeypad()
     */
    result HideKeypad(void);

// Ellipsis
    /**
     * Gets the position of the ellipsis.
     *
     * @since       2.0
     * @return      The ellipsis position
     * @exception	E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetEllipsisPosition()
     */
    EllipsisPosition GetEllipsisPosition(void) const;

    /**
     * Sets the position of the ellipsis.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   position	The ellipsis position
     * @exception	E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @see         GetEllipsisPosition()
     */
    result SetEllipsisPosition(EllipsisPosition position);

// Text size
    /**
     * Gets the text size.
     *
     * @since       2.0
     * @return      The size of the text, @n
     *              else @c -1 if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetTextSize()
     */
    int GetTextSize(void) const;

    /**
     * Sets the text size.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	size			The text size
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
     *								The @c size cannot be a negative integer.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetTextSize()
     */
    result SetTextSize(int size);

// Appearances
    /**
     * Gets the color of the %EditField control for the specified status.
     *
     * @since        2.0
     * @return       The color, @n
     *				 else RGBA(0,0,0,0) if an error occurs
     * @param[in]    status				The status
     * @exception	E_SUCCESS			The method is successful.
     * @exception    E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks      The specific error code can be accessed using the GetLastResult() method. 
     */
	Osp::Graphics::Color GetColor(EditStatus status) const;

    /**
     * Gets the text color of the specified text color type.
     *
     * @since		2.0
     * @return		The color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
     * @param[in]	type			The text color type
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method. 
     * @see			SetTextColor()
     */
    Osp::Graphics::Color GetTextColor(EditTextColor type) const;

    /**
     * Sets the background bitmap of the %EditField control for the specified status.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	status			The status
     * @param[in]   bitmap			The background bitmap
     * @exception	E_SUCCESS		The method is successful.
     * @exception   E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     */
    result SetBackgroundBitmap(EditStatus status, const Osp::Graphics::Bitmap& bitmap);

    /**
     * Sets the color of the %EditField control for the specified status.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	status			The status
     * @param[in]	color			The color
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetColor()
     */
    result SetColor(EditStatus status, const Osp::Graphics::Color& color);

    /**
     * Sets the text color of the %EditField control for the specified text color type.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	type			The text color type
     * @param[in]	color			The text color
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetTextColor()
     */
    result SetTextColor(EditTextColor type, const Osp::Graphics::Color& color);

    /**
     * Gets a portion of text that is displayed by the %EditField control.
     *
	 * @since		2.0
     * @return      The specified portion of the text, @n 
     *				else an empty string if an error occurs
     * @param[in]   start			The starting index of the range
     * @param[in]   end				The last index of the range
     * @exception   E_SUCCESS		The method is successful.
     * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or @n
	 *								the index is greater than the number of elements or less than @c 0.
     * @exception	E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM		A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetText()
     */
	Osp::Base::String GetText(int start, int end) const;

// Listeners
    /**
     * Adds a keypad event listener. @n
     * The added listener is notified when the keypad associated with the %EditField control is opened or closed.
     *
     * @since       2.0
     * @param[in]   listener	The event listener to be added
     * @see         RemoveKeypadEventListener()
     */
	void AddKeypadEventListener(const IKeypadEventListener& listener);

	/**
	 * Removes the specified keypad event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 * @param[in]   listener	The event listener to be removed
	 * @see         AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(const IKeypadEventListener& listener);

    /**
     * Adds a text block event listener. @n
     * The added listener is notified when the text block is selected.
     *
     * @since		2.0
     * @param[in]	listener	The event listener to be added
     * @remarks		Programmatically modifying the text block does not cause the text block selection event to fire.
     * @see			RemoveTextBlockEventListener()
     */
	void AddTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
     * @since     	2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	/**
	 * Adds the ITextEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be added
	 */
	void AddTextEventListener(const Osp::Ui::ITextEventListener& listener);


	/**
	* Removes the ITextEventListener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener 	The listener to be removed
	*/
	void RemoveTextEventListener(const Osp::Ui::ITextEventListener& listener);

    /**
     * Adds the specified listener instance to listen to the scroll panel events.
     *
     * @since		1.0
     * @param[in]	listener	The listener to be added
     * @remarks    	To listen to the scroll panel events, the parent of EditArea must be an instance of ScrollPanel. @n
     *              When OnOverlayControlCreated() or OnOvelayControlClosed() is called, the application resets the bounds of the controls placed
     *             	within the ScrollPanel control. ScrollPanel is automatically drawn again after this method is called.
     * @see			RemoveScrollPanelEventListener()
     */
	void AddScrollPanelEventListener(const Osp::Ui::IScrollPanelEventListener& listener);


	/**
	* Removes the specified scroll panel event listener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener	The listener to be removed
	*/
	void RemoveScrollPanelEventListener(const Osp::Ui::IScrollPanelEventListener& listener);


	/**
	 * Adds the specified listener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener	The event listener to remove
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

    /**
	 * @if PRIVCORE
	 * Adds the specified listener instance for language events. @n
	 * The added listener is notified when the input language is changed.
	 *
	 * @since      1.0
	 * @privlevel  CORE
	 * @privgroup  INPUT_METHOD_SETTING
	 * @param[in]  listener				The listener to be added
	 * @exception  E_SUCCESS			The method is successful @b since: @b 2.0.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception  E_INVALID_STATE		This instance is in an invalid state @b since: @b 2.0.
	 * @exception  E_SYSTEM				A system error has occurred @b since: @b 2.0.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	void AddLanguageEventListener(const Osp::Ui::ILanguageEventListener& listener);

    /**
	 * @if PRIVCORE
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since      1.0
	 * @privlevel  CORE
	 * @privgroup  INPUT_METHOD_SETTING
	 * @param[in]  listener				The listener to be removed
	 * @exception  E_SUCCESS			The method is successful @b since: @b 2.0.
	 * @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception  E_INVALID_STATE		This instance is in an invalid state @b since: @b 2.0.
	 * @exception  E_SYSTEM				A system error has occurred @b since: @b 2.0.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	void RemoveLanguageEventListener(const Osp::Ui::ILanguageEventListener& listener);

    /**
     * Gets the remaining length of the %EditField control.
     *
     * @since	1.0
     * @return	The remaining length of the %EditField control, @n
     *			else @c -1 if an error occurs
     */
	int  GetRemainingLength(void) const;

    /**
     * Enables or disables the lowercase mode.
     *
     * @since		1.0
     * @param[in]	enable	Set to @c true to enable the lowercase mode, @n
     *                      else @c false
     */
	void SetLowerCaseModeEnabled(bool enable);


    /**
     * Checks whether the lowercase mode is enabled.
     *
     * @since	1.0
     * @return	@c true if the lowercase mode is enabled, @n
     *			else @c false
     */
	bool IsLowerCaseModeEnabled(void) const;


    /**
     * Sets the input mode category.
     *
     * @since        1.0
     * @return       An error code
     * @param[in]    categories  			The categories to be set @n
     *                           	Multiple input categories can be combined using bitwise OR operator (see Osp::Ui::Controls::EditInputModeCategory).
     * @param[in]    enable			The category value to set
     * @exception    E_SUCCESS				The method is successful.
     * @exception    E_INVALID_ARG			A specified input mode category is invalid.
     * @exception	 E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation @b since: @b 2.0. @n
     *										The specified @c categories cannot be supported with the current keypad style.
     * @exception    E_SYSTEM				A system error has occurred.
     */
	result SetInputModeCategory(unsigned long categories, bool enable);


    /**
     * Sets the current input mode category.
     *
     * @since		1.0
     * @return		An error code
     * @param[in]	inputModeCategory 	An item of input category
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_SYSTEM			A system error has occurred.
     */
	result SetCurrentInputModeCategory(EditInputModeCategory inputModeCategory);


    /**
     * Gets the input mode category.
     *
     * @since	1.0
     * @return  A bitwise combination of Osp::Ui::Controls::EditInputModeCategory, @n
     *			else EDIT_INPUTMODE_ALPHA if an error occurs
     */
	unsigned long GetInputModeCategory(void) const;


    /**
     * Gets the current input mode category.
     *
     * @since    1.0
     * @return   The current input mode category
     */
	EditInputModeCategory GetCurrentInputModeCategory(void) const;


	/**
	 * Sets the cursor in the %EditField control at the specified position.
	 *
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompEditFieldSetCursorPosition12 "1.2" and @ref CompEditFieldSetCursorPosition20 "2.0".
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	position		The cursor position that is to be set 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c position is less than @c 0 or greater than the maximum length.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetCursorPosition(int position);

	/**
	 * @page   	CompEditFieldSetCursorPosition12 Compatibility for SetCursorPosition()
	 *
	 * @section CompEditFieldSetCursorPositionIssues Issues
	 *			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# The SetCursorPosition() method allows to set the cursor to a position that is greater than the current text length but less than or equal to 
	 *	  @c limitLength.
	 *
	 * @section CompEditFieldSetCursorPositionResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

	/**
	 * @page	CompEditFieldSetCursorPosition20 Compatibility for SetCursorPosition()
	 *
	 * @section CompEditFieldSetCursorPositionIssues Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The SetCursorPosition() method does not allow the cursor to be set at a position that is equal to the current text length.
	 *
	 * @section CompEditFieldSetCursorPositionResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	 *
	 */
   
    /**
     * Gets the cursor position.
     *
     * @since			1.0
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompEditFieldGetCursorPosition "here".
	 *
     * @return			The current cursor position, @n
     *                  else @c -1 if an error occurs
     */
	int GetCursorPosition(void) const;

	/**
	 * @page	CompEditFieldGetCursorPosition	Compatibility for GetCursorPosition()
	 *
	 * @section CompEditFieldGetCursorPositionIssues Issues
	 *			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# GetCursorPosition() does not return the current cursor position, but the position specified by the SetCursorPosition() method.
	 *
	 * @section CompEditFieldGetCursorPositionResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */

    /**
     * Gets the text that is displayed by the %EditField control.
     *
     * @since	1.0
     * @return	The text of the %EditField control, @n
     *          else an empty string if an error occurs
     */
	Osp::Base::String GetText(void) const;


    /**
     * Gets the length of the text that is displayed by the %EditField control.
     *
     * @since	1.0
     * @return	The length of the text, @n
	 *          else @c -1 if an error occurs
     */
	int GetTextLength(void) const;


	/**
	 * Sets the text of the %EditField control.
	 *
	 * @since		1.0
	 * @param[in]	text			The text to be displayed by the %EditField control
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The length of the specified @c text exceeds the system limitation or the limit length.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result SetText(const Osp::Base::String& text);


    /**
     * Inserts the specified text at the current cursor position.
     *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text        The text to be inserted
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception   E_SYSTEM    A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result InsertTextAtCursorPosition(const Osp::Base::String& text);


	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text        The text to be appended
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception   E_SYSTEM    A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result AppendText(const Osp::Base::String& text);


	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since		1.0
	 * @return      An error code
	 * @param[in]	character		The character to be appended
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the 
     *              changes, the control must be drawn again.
	 */
	result AppendCharacter(const Osp::Base::Character& character);


 	/**
	 * Clears the text that is displayed by the %EditField control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the 
     *              changes, the control must be drawn again.
	 */
	result Clear(void);


	/**
	 * Deletes a character at the current cursor position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditField control. To display the 
     *              changes, the control must be drawn again.
	 */
	result DeleteCharacterAtCursorPosition(void);


    /**
     * Gets the range of the current text block.
     *
     * @since        1.0
     * @param[out]   start   The first index of the current text block
     * @param[out]   end     The last index of the current text block
     */
	void GetCurrentTextRange(int& start, int& end) const;


    /**
     * Sets the guide text.
     *
     * @since		1.0
     * @param[in]	guideText    The guide text
     * @remarks		This is the default text that is displayed in the %EditField 
     *              control when the focus is given to it and no text is entered.
     */
	void SetGuideText(const Osp::Base::String& guideText);


    /**
     * Gets the guide text.
     *
     * @since       2.0
     * @return      The guide text, @n
     *              else an empty string if an error occurs
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception   E_SYSTEM			A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetGuideText()
     */
	Osp::Base::String GetGuideText(void) const;

    /**
     * Gets the text color of the guide text.
     *
     * @since       2.0
     * @return      The guide text color
     * @exception	E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     * @see         SetGuideTextColor()
     */
	Osp::Graphics::Color GetGuideTextColor(void) const;

    /**
     * Sets the text color of the guide text.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   color            The guide text color
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception   E_SYSTEM			A system error has occurred.
     * @see         GetGuideTextColor()
     */
	result SetGuideTextColor(const Osp::Graphics::Color& color);


	/**
	 * Gets the text color of the title for the specified status.
	 *
	 * @since		2.0
	 * @return		The title text color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The state of the %EditField control     
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state. 
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 * @see			SetTitleTextColor()
	 */
    Osp::Graphics::Color GetTitleTextColor(EditStatus status) const;

    /**
	 * Sets the text color of the title for the specified status.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]	status			The state of the %EditField control     
	 * @param[in]   color			The title text color
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state. 
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @see         GetTitleTextColor()
	 */
    result SetTitleTextColor(EditStatus status, const Osp::Graphics::Color& color);


    /**
	 * Enables or disables the keypad.
	 *
	 * @since		1.0
	 * @param[in]	enable	Set to @c true to enable the keypad,
	 *                      else @c false
	 */
	void SetKeypadEnabled(bool enable);


    /**
	 * Checks whether the keypad is enabled.
	 *
	 * @since        1.0
	 * @return       @c true if the keypad is enabled, @n
     *               else @c false
	 */
	bool IsKeypadEnabled(void);


    /**
     * Displays the keypad. 
     *
     * @since		1.0
     * @return		An error code
     * @exception	E_SUCCESS   	The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
     */
	result ShowKeypad(void);


	/**
	 * Gets the range of the current text block that is selected.
	 *
	 * @since		1.0
     * @param[out]	start   The starting index of the current block
	 * @param[out]	end     The end index of the current block
	 */
	void GetBlockRange(int& start, int& end) const;


    /**
	 * Begins the text block from the current cursor position. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Move the cursor position to the end of the text block.
	 * @see         SetCursorPosition()
	 * @see         ReleaseBlock()
	 * @see			IsBlocked()
	 */
	result BeginBlock(void);


    /**
	 * Releases the selection of the current text block.
     *
     * @since		1.0
     * @return		An error code
     * @exception   E_SUCCESS		The method is successful.
     * @exception   E_SYSTEM		A system error has occurred.
     * @see         BeginBlock()
     * @see			IsBlocked()
     */
	result ReleaseBlock(void);


    /**
	 * Checks whether a portion of the text is blocked.
	 *
	 * @since	1.0
	 * @return	@c true if the text is blocked, @n
	 *			else @c false
	 * @see     BeginBlock()
	 * @see		ReleaseBlock()
     */
	bool IsBlocked(void) const;


	/**
     * Copies the text block to the clipboard.
     *
     * @since		1.0
     * @return		An error code
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_SYSTEM	A system error has occurred.
     * @see         Cut(), Paste(), Remove()
     */
	result Copy(void);


    /**
	 * Cuts the text block and copies it to the clipboard.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			Copy(), Remove(), Paste()
	 */
	result Cut(void);


    /**
     * Pastes the copied text at the cursor position.
     *
     * @since		1.0
     * @return		An error code
     * @exception	E_SUCCESS   	The method is successful.
     * @exception	E_SYSTEM    	A system error has occurred.
     * @see			Copy(), Cut(), Remove()
     */
	result Paste(void);



	/**
	 * Removes the text that is marked by the text block.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			Copy(), Cut(), Paste()
	 */
	result Remove(void);


    /**
     * Checks whether the text in the %EditField control is clipped.
     *
     * @since	1.0
     * @return	@c true if the text is clipped, @n
     *			else @c false
     * @remarks	'clipped' means that the text is copied to the clipboard.
	 * @see		Copy(), Cut(), Paste(), Remove()
     */
	bool IsClipped(void) const;


	/**
	 * Sets the title of the %EditField control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	title			The title to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	The %EditField control has no title style.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetTitleText(const Osp::Base::String& title);


	/**
	 * Gets the title text of the %EditField control.
	 *
	 * @since		1.0
	 * @return		The title text, @n
	 *				else an empty string if an error occurs
	 */
	Osp::Base::String GetTitleText(void) const;


    /**
     * Sets the command button properties of the keypad. 
     *
     * @since       1.0
     * @return		An error code
     * @param[in]	position			The position of the command button
     * @param[in]	text				The label of the command button
     * @param[in]	actionId			The action ID
     * @exception	E_SUCCESS   		The method is successful.
     * @exception	E_INVALID_STATE     The input style is not INPUT_STYLE_OVERLAY.
     * @exception	E_SYSTEM    		A system error has occurred.
     * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.
     */
	result SetOverlayKeypadCommandButton(CommandButtonPosition position, const Osp::Base::String& text, int actionId);


    /**
     * Gets the text of the specified command button. 
     *
     * @since		1.0
     * @return		The text of the specified command button
     * @param[in]	position    The position of the command button
     * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.     
     */
	Osp::Base::String GetOverlayKeypadCommandButtonText(CommandButtonPosition position) const;


    /**
     * Gets the action ID of the specified command button.
     *
     * @since		1.0
     * @return		The action ID of the specified command button
     * @param[in]	position    The position of the command button
     * @remarks		This method is supported only when the input style is INPUT_STYLE_OVERLAY.    
     */
	int GetOverlayKeypadCommandButtonActionId(CommandButtonPosition position) const;

	/**
	 * Sets the position and size of the control. @n
	 * Its relative Position is set to (x, y), its width becomes @c width, and its height becomes @c height.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	x				The new x coordinate
	 * @param[in]	y				The new y coordinate
	 * @param[in]	width			The new width
	 * @param[in]	height			The new height
 	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified @c width or @c height is less than the minimum size.
	 * @exception   E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remark		If the specified size is less than the minimum size, %EditField is resized to the minimum size.
	 * @see			Construct ()
	 * @see			GetBounds()
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	rect			The new bounds of the control
         * @exception	E_SUCCESS		The method is successful.
         * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
         *								the @c bounds.width or @c bounds.height is less than the minimum size.
         * @exception   E_INVALID_STATE    		This instance is in an invalid state.
         * @exception	E_SYSTEM		A system error has occurred.
         * @remark		If the specified size is less than the minimum size, %EditField() is resized to the minimum size.
         * @see		Construct ()
         * @see		GetBounds()
    */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

 /**
  * Sets the size of the control. @n
  * Its width becomes the @c width, and its height becomes the @c height.
  *
  * @since		1.0
  * @return		An error code
  * @param[in]	width					The new width
  * @param[in]	height					The new height
  * @exception	E_SUCCESS		The method is successful.
  * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
  *								the specified @c width or @c height is less than the minimum size.
  * @exception   E_INVALID_STATE    		This instance is in an invalid state.
  * @exception	E_SYSTEM		A system error has occurred.
  * @see		Construct ()
  * @see		SetBounds(), SetPosition()
  * @see		GetSize()
  */
  virtual result SetSize(int width, int height);

 /**
  * Sets the size of the control. @n
  * Its width becomes @c size.width, and its height becomes @c size.height.
  *
  * @since		1.0
  * @return		An error code
  * @param[in]	size					The new width and height
  * @exception	E_SUCCESS		The method is successful.
  * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
  *								the @c size.width or the @c size.height is less than the minimum size.
  * @exception	E_INVALID_STATE    		This instance is in an invalid state.
  * @exception	E_SYSTEM		A system error has occurred.
  * @see		Construct ()
  * @see		SetBounds(), SetPosition()
  * @see		GetSize()
  */
  virtual result SetSize(const Osp::Graphics::Dimension& size);

   /**
	* Enables or disables the object depending on the specified value (@c enabled). @n
	* Only an enabled object can respond to user input. By default, the object is enabled.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	enable				Set to @c true to enable the control, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (this control cannot be displayed).
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
  virtual result SetEnabled(bool enable);

  /**
	* @if PRIVCORE
	* Sets the input language.
	*
	* @since      1.0
	* @privlevel  CORE
	* @privgroup  INPUT_METHOD_SETTING
	* @return     An error code
	* @param[in]  language				The language to be set
	* @exception  E_SUCCESS				The method is successful.
	* @exception  E_INVALID_ARG          The specified input parameter is invalid. @n
	*									The specified language is not supported or is unavailable.
	* @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method @b since: @b 2.0.
	* @exception  E_INVALID_STATE		This instance is in an invalid state @b since: @b 2.0.
	* @exception  E_SYSTEM				A system error has occurred.
	*/
	result SetCurrentLanguage(Osp::Locales::LanguageCode languageCode);

  /**
	* @if PRIVCORE
	* Gets the current input language.
	*
	* @since      1.0
	* @privlevel  CORE
	* @privgroup  INPUT_METHOD_SETTING
	* @return     An error code
	* @param[out] language               The current input language
	* @exception  E_SUCCESS				The method is successful.
	* @exception  E_PRIVILEGE_DENIED	The application does not have the privilege to call this method @b since: @b 2.0.
	* @exception  E_INVALID_STATE		This instance is in an invalid state @b since: @b 2.0.
	* @exception  E_SYSTEM				A system error has occurred.
	*/
 	result GetCurrentLanguage(Osp::Locales::LanguageCode& language) const;


protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window if it is present.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The text event
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pTextEvent;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The text event adapter
     * @since         1.0
     */	void* __pTextEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The scroll panel event 
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pScrollPanelEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The scroll panel event listener
     * @since         1.0
     */
	Osp::Base::Runtime::IEventListener* __pScrollPanelEventListener;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action event
     * @since         1.0
     */		 
	Osp::Base::Runtime::IEvent* __pActionEvent;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action event adapter
     * @since         1.0
     */		 
	void* __pActionEventAdaptor;

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * keypadEnable.
     * @since         1.0
     */		 
	bool	__keypadEnable;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The event adapter.
     * @since         1.0
     */		 
	void*	__pEditEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The VirtualEdit.
     * @since         1.0
     */		 
	void* __pVirtualEdit;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Input style.
     * @since         1.0
     */		 
	InputStyle __inputStyle;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * EditField style.
     * @since         1.0
     */		 
	EditFieldStyle __editFieldStyle;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for the left command button.
     * @since         1.0
     */		 
	int __leftButtonActionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for the left command button.
     * @since         1.0
     */		 
	Osp::Base::String* __pLeftButtonString;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for the right command button.
     * @since         1.0
     */		 
	int __rightButtonActionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for the left command button.
     * @since         1.0
     */		 
	Osp::Base::String* __pRightButtonString;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The lowercase-enabled mode.
     * @since         1.0
     */		 
	bool __isLowerCase;

private:
	friend class EditFieldEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
     class EditFieldEx* __pEditFieldEx;

protected:
	friend class EditFieldImpl;
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
	class EditFieldImpl* GetImpl(void) const;
};// EditField
}; }; }; //Osp::Ui::Controls
#endif// _FUICTRL_EDIT_FIELD_CONTROL_H_

