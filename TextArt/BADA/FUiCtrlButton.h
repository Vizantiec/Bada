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
 * @file	FUiCtrlButton.h
 * @brief	This is the header file for the %Button class.
 *
 * This header file contains the declarations of the %Button class and its helper classes.
 */

#ifndef _FUICTRL_BUTTON_H_
#define _FUICTRL_BUTTON_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpRectangle.h"
#include "FGrpColor.h"
#include "FUiIActionEventListener.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlAlignmentEnum.h"

// Forward declarations
namespace Osp { namespace Base { namespace Runtime  { class IEvent; }; }; };
namespace Osp { namespace Ui   { namespace Controls { class Button; }; }; };

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum ButtonStatus
 * Defines the Button control status.
 * @since       2.0
 */
typedef enum
{
	BUTTON_STATUS_NORMAL,          /**< The normal status */
	BUTTON_STATUS_DISABLED,        /**< The disabled status */
	BUTTON_STATUS_PRESSED,         /**< The pressed status */
	BUTTON_STATUS_HIGHLIGHTED      /**< The highlighted status */
} ButtonStatus;

/**
 * @class	Button
 * @brief This class defines the common behavior of a %Button control.
 * @since 1.0
 *
 * The %Button class displays a rectangular area, which can be pressed.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_button.htm">Buttons</a>.
 *
 * The following example demonstrates how to use the %Button class.
 *
 *
 * @code

// Sample Code for ButtonSample.h
#include <FUi.h>
#include <FGraphics.h>

class ButtonSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON  = 101;
    static const int ID_BITMAP_BUTTON = 102;

    Osp::Graphics::Bitmap* GetBitmapN(void);

public:
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

// Sample Code for ButtonSample.cpp
#include "ButtonSample.h"

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
ButtonSample::OnInitializing()
{
    result r = E_SUCCESS;

    // Creates a Button
    Button* pButton = new Button();
    pButton->Construct(Rectangle(50, 50, 150, 150), L"Button");
    pButton->SetActionId(ID_BUTTON);
    pButton->AddActionEventListener(*this);
    AddControl(*pButton);


    // Creates a bitmap Button
    Button* pBitmapButton = new Button();
    pBitmapButton->Construct(Rectangle(210, 50, 150, 150));
    pBitmapButton->SetActionId(ID_BITMAP_BUTTON);
    pBitmapButton->AddActionEventListener(*this);

    // Creates Bitmaps
	Bitmap* pBitmapNormal  = GetBitmapN();
	Bitmap* pBitmapPressed = GetBitmapN();

	// Sets the Bitmaps to the bitmap Button.
    pBitmapButton->SetNormalBackgroundBitmap(*pBitmapNormal);
    pBitmapButton->SetPressedBackgroundBitmap(*pBitmapPressed);

    // Deallocates the Bitmaps
   	delete pBitmapNormal;
   	delete pBitmapPressed;

   	// Adds the bitmap Button to the Form
   	AddControl(*pBitmapButton);

    return r;
}

Bitmap*
ButtonSample::GetBitmapN(void)
{
    return null; // Implement GetBitmapN()
}

// Implements an IActionEventListener
void
ButtonSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON:
        	// Todo:
            break;

        case ID_BITMAP_BUTTON:
        	// Todo:
            break;

        default:
            break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Button :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(Button);
// Lifecycle
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Button(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Button(void);

	/**
	 * Initializes this instance of %Button with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlConstruct20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Rectangle class @n
	 *								This instance represents the X and Y coordinates of the top-left corner @n
	 *  							of the created window along with its width and height. @n
	 * @param[in] 	text			The text to be displayed on the button
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception 	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully functional only after it has been added to a container. Therefore, some methods may fail if they are used before 
	 *				adding the control to the container. 
	 * @remarks		To display the text in multi-lines or to denote the end of line, use '\\n'. 
	 * @remarks		In bada API versions prior to 2.0, the width and height of the control must be greater than @c 0. 
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum and maximum sizes.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, const Osp::Base::String& text = L"");

	/**
	 * Adds a listener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Sets the action ID of the button.
	 *
	 * @since		1.0
	 * @param[in]	actionId		The action ID
	 */
	void SetActionId(int actionId);

	/**
	  * Gets the action ID of the button.
	  *
	  * @since		1.0
	  * @return		An integer value representing the action ID
	  */
	 int GetActionId(void) const;

// Operation
public:
	/**
	 * Sets the text that the button displays.
	 *
	 * @since		1.0
	 * @param[in] 	text	The text of the button
	 * @remarks		To display text in multi-lines or to denote the end of line, use '\\n'.
	 */
	void SetText(const Osp::Base::String& text);


	/**
	 * Sets the horizontal alignment of the text of the button.
	 *
	 * @since		1.0
	 * @param[in]	alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);


	/**
	 * Sets the vertical alignment of the text of the button.
	 *
	 * @since		1.0
	 * @param[in] 	alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

// Access
public:
	/**
	 * Gets the text displayed by the button.
	 *
	 * @since	1.0
	 * @return	The text of the button
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Gets the horizontal alignment of the text of the button.
	 *
	 * @since	1.0
	 * @return	The horizontal text alignment
	 */
	HorizontalAlignment	GetTextHorizontalAlignment(void) const;


	/**
	 * Gets the vertical alignment of the text of the button.
	 *
	 * @since	1.0
	 * @return	The vertical text alignment
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;


	//Normal color
	/**
	 * Sets the color of the text to be displayed on the button.
	 *
	 * @since			1.0
	 * @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompButtonSetTextColor "here".
	 *
	 * @param[in]	color	The text color to be set
	 */
	virtual void SetTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompButtonSetTextColor        Compatibility for SetTextColor()
	 *
	 * @section    CompButtonSetTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method ignores the alpha value of the specified color.
	 *
	 * @section    CompButtonSetTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the color of the text to be displayed on the button.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *               	For more information, see @ref CompButtonGetTextColor "here".
	 *
	 * @return      The text color
	 */
	virtual Osp::Graphics::Color GetTextColor(void) const;

	/**
	 * @page   CompButtonGetTextColor Compatibility for GetTextColor()
	 * @section CompButtonGetTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color to specify the text color.
	 *
	 * @section CompButtonGetTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0 onwards, the method returns a 32-bit color to specify the text color.
	 * It also returns the same color value that is set using SetTextColor().
	 *
	 */

	//Pressed color
	/**
	 * Sets the text color of the button for the pressed state.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompButtonSetPressedTextColor "here".
	 *
	 * @param[in]	color	The color to be set
	 */
	void SetPressedTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompButtonSetPressedTextColor        Compatibility for SetPressedTextColor()
	 *
	 * @section    CompButtonSetPressedTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method ignores the alpha value of the specified color.
	 *
	 * @section    CompButtonSetPressedTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color of the button for the pressed state.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *               	For more information, see @ref CompButtonGetPressedTextColor "here".
	 *
	 * @return      The text color when the button is pressed
	 */
	Osp::Graphics::Color GetPressedTextColor(void) const;

	/**
	 * @page   CompButtonGetPressedTextColor Compatibility for GetPressedTextColor()
	 *
	 * @section	CompButtonGetTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color to specify the text color.
	 *
	 * @section CompButtonGetTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0 onwards, the method returns a 32-bit color to specify the text color.
	 * It also returns the same color value that is set using SetPressedTextColor().
	 *
	 */

	//Disabled color
	/**
	 * Sets the text color of the button for the disabled state.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompButtonSetDisabledTextColor "here".
	 *
	 * @param[in]	color	The color to be set
	 */
	void SetDisabledTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompButtonSetDisabledTextColor        Compatibility for SetDisabledTextColor()
	 *
	 * @section    CompButtonSetDisabledTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method ignores the alpha value of the specified color.
	 *
	 * @section    CompButtonSetDisabledTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color of the button for the disabled state.	 
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *               	For more information, see @ref CompButtonGetDisabledTextColor "here".
	 *
	 * @return	 		The disabled text color
	 */
	Osp::Graphics::Color GetDisabledTextColor(void) const;

	/**
	 * @page   CompButtonGetDisabledTextColor Compatibility for GetDisabledTextColor()
	 * @section CompButtonGetTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color to specify the text color.
	 *
	 * @section CompButtonGetTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0 onwards, the method returns a 32-bit color to specify the text color.
	 * It also returns the same color value that is set using SetDisabledTextColor().
	 */

	/**
	 * Sets the text color of the button for the highlighted state.	 
	 *
	 * @since 			1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompButtonSetHighlightedTextColor "here".
	 *
	 * @param[in]	color	The color to be set
	 * @remarks     While navigating the user interface using the directional keys, the focused UI control is highlighted.
	 */
	void SetHighlightedTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompButtonSetHighlightedTextColor        Compatibility for SetHighlightedTextColor()
	 *
	 * @section    CompButtonSetHighlightedTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method ignores the alpha value of the specified color.
	 *
	 * @section    CompButtonSetHighlightedTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color of the button for the highlighted state.
	 *
	 * @since 			1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *               	For more information, see @ref CompButtonGetHighlightedTextColor "here".
     *
     * @return    The highlighted text color
     * @remarks    While navigating the user interface using the directional keys, the selected UI control is highlighted and takes the focus.
     */
	Osp::Graphics::Color GetHighlightedTextColor(void) const;

	/**
	 * @page   CompButtonGetHighlightedTextColor Compatibility for GetHighlightedTextColor()
	 * @section CompButtonGetTextColorIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color to specify the text color.
	 *
	 * @section CompButtonGetTextColorResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0 onwards, the method returns a 32-bit color to specify the text color. @n
	 * It also returns the same color value that is set using SetHighlightedTextColor().
	 *
	 */

	/**
	 * Sets a bitmap that is to be displayed when the button is not pressed.
	 *
	 * @since	  	1.0
	 * @param[in]	position	The location of a bitmap where it is to be displayed on the button
	 * @param[in]	bitmap		The bitmap of to be set
	 */
	void SetNormalBitmap(const Osp::Graphics::Point& position, const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the bitmap that is to be displayed on the button when it is pressed.
	 *
	 * @since		1.0
	 * @param[in]	position	The location of a bitmap where it is to be displayed on the Button control
	 * @param[in]	bitmap		The bitmap to be set
	 */
	void SetPressedBitmap(const Osp::Graphics::Point& position, const Osp::Graphics::Bitmap& bitmap);

	/**
	* Sets the disabled bitmap of the button.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n	
    *					For more information, see @ref CompButtonSetDisabledBitmap "here".
    *
	* @param[in]		position	The location of disabled bitmap
	* @param[in]	bitmap		The disabled bitmap of the button	
	*/
	void SetDisabledBitmap(const Osp::Graphics::Point& position, const Osp::Graphics::Bitmap& bitmap);

	/**
	 * @page   CompButtonSetDisabledBitmap	Compatibility for SetDisabledBitmap()
	 * @section CompButtonSetDisabledBitmapIssues Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	 * -#	When the disabled button is pressed, the pressed background bitmap is shown. 
	 *
	 * @section CompButtonSetDisabledBitmapResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n	 
	 */


	/**
	 * Sets the normal background bitmap of the button.
	 *
	 * @since		1.0
	 * @param[in]	bitmap			The normal background image
	 */
	void SetNormalBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the pressed background bitmap of the button.
	 *
	 * @since		1.0
	 * @param[in]	bitmap			The pressed background bitmap
	 */
	void SetPressedBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the highlighted background bitmap of the button.
	 *
	 * @since		1.1
	 * @param[in]	bitmap    The highlighted background bitmap
	 * @remarks		When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 */
	void SetHighlightedBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the position and size of the Button control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	x				The new x coordinate
	 * @param[in]	y				The new y coordinate
	 * @param[in]	width			The new width
	 * @param[in]	height			The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and height of the control must be greater than zero.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum and maximum sizes.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the button.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect						The new bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum and maximum sizes.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * Sets the size of the button.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	width			The new width
	 * @param[in]	height			The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum and maximum sizes.
	 * @see		IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);


	/**
	 * Sets the size of the button.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	size						The new width and height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum and maximum sizes.
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
	 * Gets the color of the button for the specified status.
	 *
	 * @since       2.0
	 * @return      The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @param[in]   status               The status
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Color GetColor(ButtonStatus status) const;

	/**
	 * Sets the color of the button for the specified status.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   status               The status
	 * @param[in]   color                The button color
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result SetColor(ButtonStatus status, const Osp::Graphics::Color& color);

	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS                 The method is successful.
	 * @exception   E_INVALID_STATE           This instance is in an invalid state.
	 * @exception   E_SYSTEM                  A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   size              The text size
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     A specified input parameter is invalid. @n
	 *                                The specified @c size must be greater than @c 0.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 * @see                           GetTextSize()
	 */
	result SetTextSize(int size);

	// Lifecycle
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
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


	friend class CheckButton;
	friend class RadioButton;

private:

	// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Action Event.
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pActionEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Action Event Adaptor.
     * @since         1.0
     */
	void* __pActionEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID.
     * @since         1.0
     */
	int __actionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Indicates whether it is made for Button or sub classed.
     * @since         1.0
     */
	int __isParent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Normal Bitmap Position
     * @since         1.0
     */
	Osp::Graphics::Point*		__pNormalBitmapPosition;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Normal Bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pNormalBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Pressed Bitmap Position
     * @since         1.0
     */
	Osp::Graphics::Point*		__pPressedBitmapPosition;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Pressed Bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pPressedBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Disabled Bitmap Position
     * @since         1.0
     */
	Osp::Graphics::Point*		__pDisabledBitmapPosition;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Disabled Bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pDisabledBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Normal Background Bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pNormalBackgroundBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Pressed Background Bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pPressedBackgroundBitmap;

private:
	friend class ButtonEx;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */
	class ButtonEx* __pButtonEx;

protected:
	friend class ButtonImpl;
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
	class ButtonImpl* GetImpl(void) const;

};// Button

}; }; }; //Osp::Ui::Controls
#endif// _FUICTRL_BUTTON_H_

