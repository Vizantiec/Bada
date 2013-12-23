/* $Change: 1006494 $ */
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
 * @file	FUiCtrlEditArea.h
 * @brief	This is the header file for the %EditArea class.
 *
 * This header file contains the declarations of the %EditArea class and its helper classes.
 */

#ifndef _FUICTRL_EDIT_AREA_CONTROL_H_
#define _FUICTRL_EDIT_AREA_CONTROL_H_


// Includes
#include "FBaseString.h"
#include "FBaseChar.h"
#include "FGrpBitmap.h"
#include "FGrpColor.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlEditEnum.h"
#include "FUiCtrlInputEnum.h"
#include "FUiITextEventListener.h"
#include "FUiIScrollPanelEventListener.h"
#include "FUiIActionEventListener.h"
#include "FUiILanguageEventListener.h"
#include "FUiIKeypadEventListener.h"
#include "FUiITextBlockEventListener.h"
#include "FUiIUiLinkEventListener.h"
#include "FUiCtrlAlignmentEnum.h"

// Forward declarations
namespace Osp { namespace Locales	{ class Locale;	}; };
namespace Osp { namespace Ui { namespace Controls { class EditArea; }; }; };

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	EditArea
 * @brief	This class defines the common behavior for the %EditArea control.
 * @since	1.0
 *
 * The %EditArea  class displays a multi-line text editor.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.
 *
 * The following example demonstrates how to use the %EditArea class.
 *
 * @code

// Sample Code for EditAreaSample.h
#include <FUi.h>

class EditAreaSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::ITextEventListener
{
public:
    virtual result OnInitializing(void);
    virtual void OnTextValueChanged(const Osp::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Osp::Ui::Control& source);
};

// Sample Code for EditAreaSample.cpp
#include "EditAreaSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
EditAreaSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates an EditArea
    EditArea* pEditArea = new EditArea();

    pEditArea->Construct(Rectangle(0, 100, 480, 150));
    pEditArea->AddTextEventListener(*this);

    // Adds an EditArea to the Form
    AddControl(*pEditArea);

    return r;
}

// Implements an ITextEventListener
void
EditAreaSample::OnTextValueChanged(const Osp::Ui::Control& source)
{
    // Todo:
}

void
EditAreaSample::OnTextValueChangeCanceled(const Osp::Ui::Control& source)
{
    // Todo:
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ EditArea :
    public Osp::Ui::Control
{
    DECL_CLASSTYPE(EditArea);

// Lifecycle
public:
    /**
     * This is the default constructor for this class.
     *
     * @since		1.0
     */
    EditArea(void);

    /**
     * This is the destructor for this class.
     *
     * @since		1.0
     */
    virtual ~EditArea(void);

    /**
     * Initializes this instance of the %EditArea control with the specified parameters.
     *
     * @since			1.0
     * @compatibility 	This method has compatibility issues with different bada API versions. @n
     * 					For more information, see issues in version @ref CompEditAreaConstruct "1.2" and @ref CompControlConstruct20 "2.0"
     *
     * @return		An error code
     * @param[in]	rect		An instance of the Graphics::Rectangle class @n
     * 									This instance represents the x and y coordinates of the top-left corner of the created window along with
     * 									the width and height of the control.
     * @param[in]	inputStyle			Determines whether the fullscreen keypad or overlay keypad is displayed
     * @param[in]	limitLength			The maximum limit of the length of the text that can be displayed by %EditArea
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_ARG		A specified input parameter is invalid.@n
     *									The specified @c limitLength is less than or equal to @c 0. @n
     *									The @c rect.width or the @c rect.height is less than 0.
     * @exception	E_INVALID_STATE		This instance has already been constructed.
     * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		Some methods of the control will only work as expected when it becomes 'displayable'.
     *				For more information, see Control::IsDisplayable() @n
     *				The orientation of the full-screen style keypad is determined by the current device orientation.
     * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
     */
    result Construct(const Osp::Graphics::Rectangle& rect, InputStyle inputStyle = INPUT_STYLE_FULLSCREEN, int limitLength = 1000);

    /**
     * @page	CompEditAreaConstruct	Compatibility for showing full screen keypad
     * @section	CompEditAreaConstructIssues Issues
     * Implementation of this class in bada API versions prior to 1.2 has the following issue: @n
     * -# If the keypad language is either Greek, Norwegian, or Malay, the full-screen style keypad is not displayed properly.
     *
     * @section CompEditAreaConstructResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
     */

// Operation
public:
// Text Alignment
    /**
     * Gets the horizontal text alignment.
     *
     * @since		2.0
     * @return		The horizontal text alignment
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetTextAlignment()
     */
    HorizontalAlignment GetTextAlignment(void) const;

    /**
     * Sets the horizontal text alignment.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	alignment           The horizontal text alignment
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @see			GetTextAlignment()
     */
    result SetTextAlignment(HorizontalAlignment alignment);

//AutoLink
    /**
     * Checks whether the view mode is enabled.
     *
     * @since		2.0
     * @return		@c true if the view mode is enabled, @n
	 *				else @c false
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetViewModeEnabled()
     */
    bool IsViewModeEnabled(void) const;

    /**
     * Enables or disables the view mode.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	enable				Set to @c true to enable the view mode, @n
	 *									else @c false
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		When the view mode is enabled, the auto-detected links will be displayed as linked text.
     * @see			IsViewModeEnabled()
     */
    result SetViewModeEnabled(bool enable);

    /**
     * Sets the auto-link mask.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	autoLinks				The auto-link mask @n
     *										Multiple link types can be combined using bitwise OR (see Osp::Base::Utility::LinkType). @n
     *										For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										The operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		When @c autoLinks is set to zero, the auto-link detection is disabled.
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
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult()() method.
     * @see			SetAutoLinkMask()
     */
    unsigned long GetAutoLinkMask(void) const;

    /**
     * Adds the specified link event listener.
     *
     * @since		2.0
     * @param[in]	listener	The event listener to be added
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.@n
     *				The added listener will be notified when the links are selected by the user.
     * @see			RemoveUiLinkEventListener()
     */
    void AddUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

    /**
     * Removes the specified link event listener. @n
     * The removed listener cannot listen to the events when they are fired.
     *
     * @since		2.0
     * @param[in]	listener	The event listener to be removed
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.
     * @see			AddUiLinkEventListener()
     */
    void RemoveUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

//Line spacing
    /**
     * Gets the line spacing.
     *
     * @since		2.0
     * @return		The line spacing,  @n
     *				else @c -1 if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @remarks		The specific error code can be accessed using the GetLastResult()() method.
     * @see         SetLineSpacing()
     */
    int GetLineSpacing(void) const;

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra.
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 * @since          2.0
	 * @return         An error code
	 * @param[in]      multiplier		The line spacing multiplier
	 * @param[in]      extra            The extra line spacing
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified line spacing value cannot be supported.
	 * @exception      E_INVALID_STATE  This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see            GetLineSpacing()
	 */
     result SetLineSpacing(int multiplier, int extra);

// Margin
    /**
     * Gets the margin value of the specified margin type.
     *
     * @since		2.0
     * @return      The margin value, @n 
     *              else @c -1 if an error occurs
     * @param[in]	marginType			The margin type
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult()() method.
     * @see         SetMargin()
     */
    int GetMargin(EditMarginType marginType) const;

    /**
     * Sets the margin value for the specified margin type.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   marginType		The margin type
     * @param[in]   margin			The margin value to set
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_ARG	A specified input parameter is invalid. @n
     *								The specified @c margin cannot be a negative integer.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see         GetMargin()
     */
    result SetMargin(EditMarginType marginType, int margin);

// Keypad Action
    /**
     * Gets the keypad action type.
     *
     * @since		2.0
     * @return      The keypad action
     * @exception   E_SUCCESS           	The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE     	This instance is in an invalid state.
     * @exception   E_SYSTEM            	A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult()() method.
     */
    Osp::Ui::KeypadAction GetKeypadAction(void) const;

    /**
     * Sets the keypad action type.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   keypadAction			The keypad action
     * @exception   E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @remarks     Depending on the value of @c keypadAction specified, the enter key label of the keypad will change accordingly.
     */
    result SetKeypadAction(Osp::Ui::KeypadAction keypadAction);

    /**
     * Gets the keypad style.
     *
     * @since		2.0
     * @return		The keypad style
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM            A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see         SetKeypadStyle()
     */
    KeypadStyle GetKeypadStyle(void) const;

    /**
     * Sets the keypad style. 
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   keypadStyle			The keypad style
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_ARG		The specified input parameter is invalid. @n
     *                                  The specified @c keypadStyle cannot be @c KEYPAD_STYLE_PASSWORD.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     Depending on the value of the specified @c keypadStyle, the keypad's layout will change accordingly.
     * @see         GetKeypadStyle()
     */
    result SetKeypadStyle(KeypadStyle keypadStyle);

    /**
     * Determines the visibility of the command buttons of the overlay style keypad.
     *
     * @since		2.0 
     * @return		An error code
     * @param[in]	visible					Set to @c true to make the overlay keypad command buttons visible, @n
	 *										else @c false
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_SYSTEM				A system error has occurred.
     */
    result SetOverlayKeypadCommandButtonVisible(bool visible);

    /**
     * Checks whether the command buttons of the overlay style keypad are visible.
     *
     * @since       2.0
     * @return      @c true if the overlay command buttons are set to be visible, @n
     *              else @c false
     * @exception   E_SUCCESS           	The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE     		This instance is in an invalid state.
     * @exception   E_SYSTEM            	A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult()() method.
     */
    bool IsOverlayCommandButtonVisible(void) const;

    /**
     * Hides the keypad.
     *
     * @since       2.0
     * @return      An error code
     * @exception   E_SUCCESS				The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation.@n
     *										This operation is not supported if the input style is not INPUT_STYLE_OVERLAY.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @see         ShowKeypad()
     */
    result HideKeypad(void);

// Text Size
    /**
     * Gets the text size.
     *
     * @since       2.0
     * @return      The size of the text, @n
     *              else @c -1 if an error occurs
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state.
     * @exception   E_SYSTEM			A system error has occurred.
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
     *								The specified @c size cannot be a negative integer.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetTextSize()
     */
    result SetTextSize(int size);

// Appearances
    /**
     * Gets the color of %EditArea for the specified status.
     *
     * @since        2.0
     * @return       The color, @n
     *				 else RGBA (0,0,0,0) if an error occurs
     * @param[in]    status				The status
     * @exception    E_SUCCESS			The method is successful.
     * @exception    E_INVALID_STATE	This instance is in an invalid state.
     * @exception    E_SYSTEM			A system error has occurred.
     * @remarks      The specific error code can be accessed using the GetLastResult() method. 
     */
    Osp::Graphics::Color GetColor(EditStatus status) const;

    /**
     * Gets the text color of the specified text color type.
     *
     * @since		2.0
     * @return		The color, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]	type			The text color type
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetTextColor()
     */
    Osp::Graphics::Color GetTextColor(EditTextColor type) const;

    /**
     * Sets the background bitmap of the %EditArea control for the specified status.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	status			The status
     * @param[in]   bitmap			The background bitmap
     * @exception   E_SUCCESS		The method is successful.
     * @exception   E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     */
    result SetBackgroundBitmap(EditStatus status, const Osp::Graphics::Bitmap& bitmap);

    /**
     * Sets the color of the %EditArea control for the specified status.
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
     * Sets the text color of the %EditArea control for the specified text color type.
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
     * Gets a portion of text that is displayed by the %EditArea control.
     *
	 * @since		2.0
     * @return      The specified portion of the text, @n 
     *				else an empty string if an error occurs.
     * @param[in]   start			The starting index of the range
     * @param[in]   end				The last index of the range
     * @exception   E_SUCCESS		The method is successful.
     * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure. @n
     *								The index is greater than the number of elements or less than @c 0.
     * @exception	E_INVALID_STATE This instance is in an invalid state.
     * @exception   E_SYSTEM		A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult()() method.
     * @see         SetText()
     */
    Osp::Base::String GetText(int start, int end) const;

// Listeners
    /**
     * Adds the specified keypad event listener. @n
     * The added listener is notified when the keypad associated with the %EditArea control is opened or closed.
     *
     * @since       2.0
     * @param[in]   listener	The event listener to be added
     * @see         RemoveKeypadEventListener()
     */
    void AddKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

    /**
     * Removes the specified keypad event listener. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since       2.0
     * @param[in]   listener	The event listener to be removed
     * @see         AddKeypadEventListener()
     */
    void RemoveKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

    /**
     * Adds a text block event listener.
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
     * @since		2.0
     * @param[in]	listener	The event listener to be removed
     * @see         AddTextBlockEventListener()
     */
    void RemoveTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

    /**
     * Adds a listener instance. @n
     * The added listener can listen to the text related events.
     *
     * @since		1.0
     * @param[in]	listener    The listener to be added
     * @see			RemoveTextEventListener()
     */
    void AddTextEventListener(const Osp::Ui::ITextEventListener& listener);

    /**
     * Removes a listener instance. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since		1.0
     * @param[in]	listener    The listener to be removed
     * @see			AddTextEventListener()
     */
    void RemoveTextEventListener(const Osp::Ui::ITextEventListener& listener);

    /**
     * Adds a listener instance to listen to the scroll panel events.
     *
     * @since		1.0
     * @param[in]	listener    The listener to be added
     * @remarks    	To listen to scroll panel events, the parent of the %EditArea control must be an instance of ScrollPanel. @n
     *              When OnOverlayControlCreated() or OnOvelayControlClosed() is called, the application resets the bounds of the controls placed
     *             	within the %ScrollPanel. %ScrollPanel is automatically redrawn after this method is called.
     * @see			RemoveScrollPanelEventListener()
     */
    void AddScrollPanelEventListener(const Osp::Ui::IScrollPanelEventListener& listener);

    /**
     * Removes the scroll panel event listener. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since		1.0
     * @param[in]	listener    The listener to be removed
     * @see			AddScrollPanelEventListener()
     */
    void RemoveScrollPanelEventListener(const Osp::Ui::IScrollPanelEventListener& listener);

    /**
     * Adds a listener instance. @n
     * The added listener is notified when the action event is fire by the command buttons of the keypad.   
     *
     * @since		1.0
     * @param[in]	listener	The event listener to be added
     * @see			RemoveActionEventListener()
     */
    void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);


    /**
     * Removes a listener instance. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since		1.0
     * @param[in]	listener    The event listener to be removed
     * @see			AddActionEventListener()
     */
    void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

    /**
	 * @if PRIVCORE
	 * Adds a listener instance for language events. @n
	 * The added listener is notified when the input language is changed.
	 *
	 * @since      1.0
	 * @privlevel  CORE
	 * @privgroup  INPUT_METHOD_SETTING
	 * @param[in]  listener               The listener to be added
	 * @exception  E_SUCCESS              The method is successful @b since: @b 2.0.
	 * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception  E_INVALID_STATE        This instance is in an invalid state @b since: @b 2.0.
	 * @exception  E_SYSTEM               A system error has occurred @b since: @b 2.0.
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
	 * @param[in]  listener               The listener to be removed
	 * @exception  E_SUCCESS              The method is successful @b since: @b 2.0.
	 * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception  E_INVALID_STATE        This instance is in an invalid state @b since: @b 2.0.
	 * @exception  E_SYSTEM               A system error has occurred @b since: @b 2.0.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
    void RemoveLanguageEventListener(const Osp::Ui::ILanguageEventListener& listener);

    /**
     * Gets the remaining length of the %EditArea control.
     *
     * @since	1.0
     * @return	The remaining length of the %EditArea control, @n
     *			else @c -1 if an error occurs.
     */
    int GetRemainingLength(void) const;


    /**
     * Enables or disables the lowercase mode.
     *
     * @since		1.0
     * @param[in]	enable	Set to @c true to enable the lowercase mode, @n
     *						else @c false
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
     * @param[in]    categories  	The categories to be set @n
     *                           			Multiple input categories can be combined using bitwise OR (see Osp::Ui::Controls::EditInputModeCategory).
     * @param[in]    enable			The category value to be set
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
     *			else @c EDIT_INPUTMODE_ALPHA if an error occurs
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
     * @internal
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 * Sets user dictionary enable flag.
	 *
	 * @since		1.0
	 * @param[in]	enable  The user dictionary enable flag value to be set
	 */
    void SetUserDictionaryEnabled(bool enable);


    /**
     * @internal
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 * This method tells if user dictionary is enabled or not currently.
	 *
	 * @since    1.0
	 * @return   if user dictionary is enabled or not currently
	 */
    bool IsUserDictionaryEnabled(void) const;


    /**
     * Sets the cursor at the specified position.
     *
     * @since			1.0
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 * 					For more information, see issues in version @ref CompEditAreaSetCursorPosition12 "1.1"  
	 *                  and @ref CompEditAreaSetCursorPosition20 "2.0".
     *
     * @return		An error code
     * @param[in]	position 		The cursor position that is to be set
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_OUT_OF_RANGE	The specified @c position is less than @c 0 or greater than the maximum length.
     * @exception	E_SYSTEM		A system error has occurred.
     */
    result SetCursorPosition(int position);

    /**
     * @page	CompEditAreaSetCursorPosition12 Compatibility for SetCursorPosition()
	 *
     * @section CompEditAreaSetCursorPositionIssues Issues
     * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
     * -# The SetCursorPosition() method allows to set the cursor to a position that is greater than the current text length but less than or equal to 
	 *	  @c limitLength.
     *
     * @section CompEditAreaSetCursorPositionResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
     */

    /**
     * @page	CompEditAreaSetCursorPosition20 Compatibility for SetCursorPosition()
	 *
     * @section CompEditAreaSetCursorPositionIssues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# The SetCursorPosition() method does not allow to set the cursor to be set at a position that is equal to the current text length.
     *
     * @section CompEditAreaSetCursorPositionResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
     */

    /**
     * Gets the cursor position.
     *
     * @since			1.0
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompEditAreaGetCursorPosition "here".
	 *
     * @return			The current cursor position, @n
     *                  else @c -1 if an error occurs
     */
    int GetCursorPosition(void) const;

    /**
     * @page	CompEditAreaGetCursorPosition    Compatibility for GetCursorPosition()
     * @section CompEditAreaGetCursorPositionIssues Issues
     * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
     * -# GetCursorPosition() does not return the current cursor position, but the position specified by the SetCursorPosition() method.
     *
     * @section CompEditAreaGetCursorPositionResolutions Resolutions
     * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
     */

    /**
     * Gets the text that is displayed by the %EditArea control.
     *
     * @since	1.0
     * @return	The text of the %EditArea control, @n
     *          else an empty string if an error occurs
     */
    Osp::Base::String GetText(void) const;


    /**
     * Gets the length of the text that is displayed by the %EditArea control.
     *
     * @since	1.0
     * @return	The length of the text, @n
	 *          else @c -1 if an error occurs
     */
    int GetTextLength(void) const;


	/**
	 * Sets the text of the %EditArea control.
	 *
	 * @since		1.0
	 * @param[in]	text			The text that needs to be displayed by the %EditArea control.
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
	 * @exception	E_SUCCESS   	The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.@n
	 */
    result InsertTextAtCursorPosition(const Osp::Base::String& text);


	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text        	The text to be appended
	 * @exception	E_SUCCESS   	The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred.
	 * @remarks     Use @htmlonly '\n' @endhtmlonly to denote the end of the line.@n
	 */
    result AppendText(const Osp::Base::String& text);


	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since		1.0
	 * @return      An error code
	 * @param[in]   character   	The character to be appended
	 * @exception   E_SUCCESS   	The method is successful.
	 * @exception   E_SYSTEM    	A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the 
     *              changes, the control must be drawn again.
	 */
    result AppendCharacter(const Osp::Base::Character& character);


	/**
	 * Clears the text that is displayed by the %EditArea control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the 
     *              changes, the control must be drawn again.
	 */
    result Clear(void);


	/**
	 * Deletes a character at the current cursor position.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception   E_SUCCESS	The method is successful.
	 * @exception   E_SYSTEM	A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %EditArea control. To display the 
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
     * Displays the guide text when there is no text in the %EditArea control.
     *
     * @since		1.0
     * @param[in]	guideText    The guide text
     * @remarks		This is the default text that is displayed in the %EditArea control when the focus is given to it.
     */
    void SetGuideText(const Osp::Base::String& guideText);

    /**
     * Gets the guide text.
     *
     * @since       2.0
     * @return      The guide text, @n
     *              else an empty string if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see         SetGuideText()
     */
    Osp::Base::String GetGuideText(void) const;

    /**
     * Gets the text color of the guide text.
     *
     * @since       2.0
     * @return      The guide text color
     * @exception   E_SUCCESS        The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception   E_SYSTEM         A system error has occurred.
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
     * @exception   E_SUCCESS        The method is successful.
     * @exception   E_INVALID_STATE  This instance is in an invalid state.
     * @exception   E_SYSTEM         A system error has occurred.
     * @see         GetGuideTextColor()
     */
    result SetGuideTextColor(const Osp::Graphics::Color& color);

    /**
	 * Enables or disables the keypad.
	 *
	 * @since		1.0
	 * @param[in]	enable	Set to @c true to enable the keypad, @n
	 *						else @c false
	 */
    void SetKeypadEnabled(bool enable);


    /**
	 * Checks whether the keypad is enabled.
	 *
	 * @since        1.0
	 * @return		@c true if the keypad is enabled, @n
     *				else @c false
	 */
    bool IsKeypadEnabled(void);

    /**
     * Shows the keypad. 
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
     * Gets the line count.
     *
     * @since	1.0
     * @return	The line count
     */
    int GetTextLineCount(void) const;


	/**
	 * Gets the range of the current text block.
	 *
	 * @since		1.0
     * @param[out]	start   The starting index of the current text block
	 * @param[out]	end     The end index of the current text block
	 */
    void GetBlockRange(int& start, int& end) const;


    /**
	 * Begins the text block from the current cursor position. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks		Move the cursor position to the end of the text block.
	 * @see         SetCursorPosition()
	 * @see         ReleaseBlock()
	 * @see			IsBlocked()
	 */
    result BeginBlock(void);


    /**
     * Releases the text block.
     *
     * @since		1.0
     * @return		An error code
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_SYSTEM		A system error has occurred.
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
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_SYSTEM		A system error has occurred.
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
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_SYSTEM		A system error has occurred.
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
     * Checks whether the text in the %EditArea control has been clipped. 
     *
     * @since	1.0
     * @return	@c true if the text has been clipped, @n
     *			else @c false
     * @remarks	'Clipped' means that the text has been copied to the clipboard.
	 * @see		Copy(), Cut(), Paste(), Remove()
     */
    bool IsClipped(void) const;

    /**
     * Sets the command button properties of the keypad. 
     *
     * @since       1.0
     * @return		An error code
     * @param[in]	position			The position of the command button
     * @param[in]	text				The label of the command button
     * @param[in]	actionId			The action ID
     * @exception	E_SUCCESS   		The method is successful.
     * @exception	E_INVALID_STATE     The input style is not @c INPUT_STYLE_OVERLAY.
     * @exception	E_SYSTEM    		A system error has occurred.
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.     
     */
    result SetOverlayKeypadCommandButton(CommandButtonPosition position, const Osp::Base::String& text, int actionId);

    /**
     * Gets the text of the specified command button. 
     *
     * @since		1.0
     * @return		The text of the specified command button
     * @param[in]	position    The position of the command button
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.     
     */
    Osp::Base::String GetOverlayKeypadCommandButtonText(CommandButtonPosition position) const;

    /**
     * Gets the action ID of the specified command button.
     *
     * @since		1.0
     * @return		The action ID of the specified command button
     * @param[in]	position    The position of the command button
     * @remarks		This method is supported when the input style is @c INPUT_STYLE_OVERLAY.    
     */
    int GetOverlayKeypadCommandButtonActionId(CommandButtonPosition position) const;

    /**
     * Sets the position and size of the %EditArea control. @n
     * Its relative position is set to (x, y), its width becomes @c width, and its height becomes @c height.
     *
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     				For more information, see @ref CompEditAreaSetBounds20 "here".
	 *
     * @since		1.0
     * @return      An error code
     * @param[in]   x               The new x coordinate
     * @param[in]   y               The new y coordinate
     * @param[in]   width           The new width
     * @param[in]   height          The new height
     * @exception   E_SUCCESS       		The method is successful.
     * @exception   E_INVALID_ARG			A specified input parameter is invalid. @n
     *                                		Either the specified @c width or @c height is less than the minimum size.
     * @exception   E_INVALID_STATE    		This instance is in an invalid state.
     * @exception   E_SYSTEM        		A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
     */
    virtual result SetBounds(int x, int y, int width, int height);

    /**
     * Sets the position and size of the %EditArea control. @n
     * Its position is set to (@c rect.x, @c rect.y), its width becomes @c rect.width, and its height becomes @c rect.height.
     *
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     				For more information, see @ref CompEditAreaSetBounds20 "here".
     *
     * @since		1.0
     * @return      An error code
     * @param[in]   rect            		The bounds of the control
     * @exception   E_SUCCESS       		The method is successful.
     * @exception   E_INVALID_ARG   		The specified input parameter is invalid. @n
     *										- Either @c bounds.width or @c bounds.height is less than the minimum size.
     * @exception   E_INVALID_STATE    		This instance is in an invalid state.
     * @exception   E_SYSTEM        		A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
     */
    virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

    /**
     * @page CompEditAreaSetBounds20 Compatibility for SetBounds()
	 *
     * @section CompEditAreaSetBounds20Issues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# From bada API version 2.0, the method returns E_INVALID_STATE instead of E_INVALID_OPERATION when the control is not constructed.
     * -# From bada API version 2.0, the method returns E_UNSUPPORTED_OPERATION, if the control is neither movable nor resizable.
     * -# From bada API version 2.0, the minimum and maximum sizes are introduced as new properties of the Control class. @n
     *  Therefore, if the specified size is smaller than the minimum size or greater than the maximum size, the method returns E_INVALID_ARG.
     *
     * @section CompEditAreaSetBounds20Resolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

    /**
     * Sets the size of the %EditArea control. @n
     * Its width becomes the @c width, and its height becomes the @c height.
     *
     * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     				For more information, see @ref CompEditAreaSetSize20 "here".
     *
     * @since		1.0
     * @return      An error code
     * @param[in]   width           		The new width
     * @param[in]   height          		The new height
     * @exception   E_SUCCESS       		The method is successful.
     * @exception   E_INVALID_ARG   		A specified input parameter is invalid. @n
     *										- Either the @c width or the @c height is less than the minimum size.
     * @exception   E_INVALID_STATE    		This instance is in an invalid state.
     * @exception   E_SYSTEM        		A system error has occurred.
  	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
  	 * @see   		GetMinimumSize()
  	 * @see   		GetMaximumSize()
     */
    virtual result SetSize(int width, int height);


    /**
     * Sets the size of the %EditArea control. @n
     * Its width becomes @c size.width, and its height becomes @c size.height.
     *
     * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     				For more information, see @ref CompEditAreaSetSize20 "here".
     *
     * @since		1.0
     * @return      An error code
     * @param[in]   size            		The new width and height
     * @exception   E_SUCCESS       		The method is successful.
     * @exception   E_INVALID_ARG   		The specified input parameter is invalid. @n
     *                              		- Either the @c size.width or the @c size.height is less than the minimum size.
     * @exception   E_INVALID_STATE    		This instance is in an invalid state.
     * @exception   E_SYSTEM        		A system error has occurred.
  	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
  	 * @see   		GetMinimumSize()
  	 * @see   		GetMaximumSize()
     */
    virtual result SetSize(const Osp::Graphics::Dimension& size);

    /**
     * @page CompEditAreaSetSize20 Compatibility for SetSize()
     * @section CompEditAreaSetSize20Issues Issues
     * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# From bada API version 2.0, the method returns E_INVALID_STATE instead of E_INVALID_OPERATION when the control is not constructed.
     * -# From bada API version 2.0, the method returns E_UNSUPPORTED_OPERATION, if the control is not resizable.
     * -# From bada API version 2.0, the minimum and maximum sizes are introduced as new properties of the Control class. @n
     *  Therefore, if the specified size is smaller than the minimum size or greater than the maximum size, the method returns E_INVALID_ARG.
     *
     * @section CompEditAreaSetSize20Resolutions Resolutions
     * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */

    /**
     * Enables or disables the object depending on the specified value (@c enabled). @n
     * Only an enabled object can respond to the user input. By default, the object is enabled.
     *
     * @since       1.0
     * @return      An error code
     * @param[in]   enable              The new state of the object
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_SYSTEM            A system error has occurred.
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
	 * @param[in]  language               The language to be set
	 * @exception  E_SUCCESS              The method is successful.
	 * @exception  E_INVALID_ARG          The specified input parameter is invalid. @n
	 *                                    The specified language is not supported or unavailable.
	 * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception  E_INVALID_STATE        This instance is in an invalid state @b since: @b 2.0.
	 * @exception  E_SYSTEM               A system error has occurred.
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
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method @b since: @b 2.0.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state @b since: @b 2.0.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
    result GetCurrentLanguage(Osp::Locales::LanguageCode& language) const;

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window if it is present).
	 *
	 * @since		1.0
	 * @return		An error code
     * @exception   E_SUCCESS The method is successful.
     * @exception   E_SYSTEM Failed to free the resource possessed by this instance.
	 */
    result Dispose(void);

private:

    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The text event.
     * @since         1.0     
     */
    Osp::Base::Runtime::IEvent* __pTextEvent;
    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The text event adapter.
     * @since         1.0     
     */
    void* __pTextEventAdaptor;

    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The scroll panel event.
     * @since         1.0     
     */
    Osp::Base::Runtime::IEvent* __pScrollPanelEvent;

    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The scroll panel event listener.
     * @since         1.0     
     */
    Osp::Base::Runtime::IEventListener* __pScrollPanelEventListener;

    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The Action event.
     * @since         1.0     
     */
     Osp::Base::Runtime::IEvent* __pActionEvent;
    
    /**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The Action event adapter.
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
	 * The flag for keypad enable
     * @since         1.0
     */	
    bool    __keypadEnable;

   	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 *  Event Adaptor
     * @since         1.0
     */	
    void*   __pEditEventAdaptor;

  	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Virtual Edit.
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
	 * The text for the left command button.
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
	 * The text for the left command button.
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
    friend class EditAreaEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */    
    class EditAreaEx* __pEditAreaEx;

protected:
    friend class EditAreaImpl;
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
    class EditAreaImpl* GetImpl(void) const;
};// EditArea
}; }; }; //Osp::Ui::Controls
#endif// _FUICTRL_EDIT_AREA_CONTROL_H_

