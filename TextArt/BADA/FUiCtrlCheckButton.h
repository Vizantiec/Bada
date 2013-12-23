/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
//
// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlCheckButton.h
 * @brief	This is the header file for the %CheckButton class.
 *
 * This header file contains the declarations of the %CheckButton class and its helper classes.
 */
#ifndef _FUICTRL_CHECK_BUTTON_H_
#define _FUICTRL_CHECK_BUTTON_H_

// Includes
#include "FBaseResult.h"
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlButton.h"
#include "FUiCtrlBackgroundEnum.h"
#include "FUiCtrlTableViewStyleEnum.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum CheckButtonStatus
 * Defines the %CheckButton status.
 *
 * @since	2.0
 */
typedef enum
{
	CHECK_BUTTON_STATUS_NORMAL,   		/**< The normal status */
	CHECK_BUTTON_STATUS_DISABLED,   	/**< The disabled status */
	CHECK_BUTTON_STATUS_PRESSED,   		/**< The pressed status */
	CHECK_BUTTON_STATUS_HIGHLIGHTED   	/**< The highlighted status */
} CheckButtonStatus;

/**
 * @enum CheckButtonStyle
 * Defines the %CheckButton style.
 *
 * @since	1.0
 */
typedef enum
{
	CHECK_BUTTON_STYLE_MARK,						/**< The mark style for multiple selection */
	CHECK_BUTTON_STYLE_MARK_WITH_DIVIDER,			/**< @deprecated This enumeration field is deprecated because the use of the divider style is no longer recommended @n
															 Instead of using the divider style, use the detailed button style. */
	CHECK_BUTTON_STYLE_ONOFF,						/**< @deprecated This enumeration field is deprecated because the use of the on-off style is no longer recommended @n
															 Instead of using the on-off style, use the on-off sliding style */
	CHECK_BUTTON_STYLE_ONOFF_WITH_DIVIDER,			/**< @deprecated This enumeration field is deprecated because the use of the on-off style is no longer recommended */
	CHECK_BUTTON_STYLE_RADIO,						/**< The radio style for single selection */
	CHECK_BUTTON_STYLE_RADIO_WITH_DIVIDER,			/**< @deprecated This enumeration field is deprecated because the use of the divider style is no longer recommended @n
															 Instead of using the divider style, use the detailed button style */
	CHECK_BUTTON_STYLE_ONOFF_SLIDING,             	/**< The slider style on/off @b since: @b 2.0 */
	CHECK_BUTTON_STYLE_MARK_WITH_DETAILED_BUTTON, 	/**< The mark style with detail button @b since: @b 2.0 */
	CHECK_BUTTON_STYLE_RADIO_WITH_DETAILED_BUTTON,	/**< The radio style with detail button @b since: @b 2.0 */
} CheckButtonStyle;

/**
 * @class	CheckButton
 * @brief	This class defines the common behavior of a %CheckButton control.
 * @since	1.0
 *
 * The %CheckButton class displays a rectangular area, which can be selected, and shows the current selection.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_button.htm">Buttons</a>.
 * 
 * The following example demonstrates how to use the %CheckButton class.
 *
 *
 * @code

// Sample Code for CheckButtonSample.h
#include <FUi.h>

class CheckButtonSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON_CHECKED   = 101;
    static const int ID_BUTTON_UNCHECKED = 102;

public:
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

// Sample Code for CheckButtonSample.cpp
#include "CheckButtonSample.h"
#include <FGraphics.h>

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
CheckButtonSample::OnInitializing()
{
    result r = E_SUCCESS;

    // Creates a CheckButton
    CheckButton *pCheckButton = new CheckButton();
    pCheckButton->Construct(
		Osp::Graphics::Rectangle(10, 100, 460, 100),
		CHECK_BUTTON_STYLE_MARK, BACKGROUND_STYLE_DEFAULT,
		false, L"CheckButton");

    pCheckButton->SetActionId(ID_BUTTON_CHECKED, ID_BUTTON_UNCHECKED);
    pCheckButton->AddActionEventListener(*this);

    // Adds a CheckButton to the Form
    AddControl(*pCheckButton);

    return r;
}

// Implements an IActionEventListener
void
CheckButtonSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
	case ID_BUTTON_CHECKED:
		// Todo:
		break;
	case ID_BUTTON_UNCHECKED:
		// Todo:
		break;
	default:
		break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ CheckButton :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(CheckButton);
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	CheckButton(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~CheckButton(void);

	/**
	 * Initializes this instance of %CheckButton with the specified parameters.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompCheckButtonConstruct20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window
	 *									along with the width and height of the window.
	 * @param[in]	style				The style of the %CheckButton control
	 * @param[in]	backgroundStyle		The background style set of the %CheckButton control
	 * @param[in] 	showTitle		Set to @c true to enable the title, @n
	 *								else @c false
 	 * @param[in] 	text				The text of the %CheckButton control
 	 * @param[in] 	groupStyle			The group style of the %CheckButton control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG   	A specified input parameter is invalid.@n
	 *									The specified size is less than the minimum size of the control.
     * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
     *                                  The background style of BACKGROUND_STYLE_NONE does not work with group styles except GROUP_STYLE_NONE.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier. @n
	 *				For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, CheckButtonStyle style, BackgroundStyle backgroundStyle = BACKGROUND_STYLE_DEFAULT, bool showTitle = false, const Osp::Base::String& text = L"", GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * @page       CompCheckButtonConstruct20        Compatibility for Construct()
	 *
	 * @section    CompCheckButtonConstruct20Issues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0.
	 * -# The background style of BACKGROUND_STYLE_NONE does not work with group styles except GROUP_STYLE_NONE, but Construct() does not generate an 
	 *	  exception.
	 *
	 * @section    CompCheckButtonConstruct20Resolutions Resolutions
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control, or greater than the maximum size of the 
	 *	  control.
	 * -#	The issue 2 is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	 */

	/**
	 * Sets the checked status of the %CheckButton control.
	 *
	 * @since		1.0
	 * @param[in]	select	Set to @c true if the %CheckButton control is checked, @n
	 *				else @c false
	 */
	void SetSelected(bool select);

	/**
	 * Checks whether the %CheckButton control has been selected.
	 *
	 * @since		1.0
	 * @return		@c true if the %CheckButton is selected, @n
	 *				else @c false
	 */
	bool IsSelected(void) const;

public:
	/**
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Sets the action IDs for the %CheckButton control.
	 *
	 * @since		1.0
	 * @param[in] 	checkedActionId			The action ID for the checked state
	 * @param[in] 	uncheckedActionId		The action ID for the unchecked state
	 * @param[in] 	selectedActionId		The action ID for the selected state
	 */
	void SetActionId(int checkedActionId, int uncheckedActionId, int selectedActionId = -1);

	/**
	 * Gets the action ID for the checked state.
	 *
	 * @since		1.0
	 * @return		An integer value representing the action ID
	 */
	int GetCheckedActionId(void) const;

	/**
	 * Gets the action ID for the unchecked state.
	 *
	 * @since		1.0
	 * @return		An integer value representing the action ID
	 */
	int GetUncheckedActionId(void) const;

	/**
	 * Gets the action ID for the selected state.
	 *
	 * @since		1.0
	 * @return		An integer value representing the action ID
	 */
	int GetSelectedActionId(void) const;


// Operation
public:
	/**
	 * Sets the text that the %CheckButton control displays.
	 *
	 * @since		1.0
	 * @param[in] 	text	The text of the %CheckButton control
	 */
	void SetText(const Osp::Base::String& text);


	/**
	 * Sets the horizontal alignment of the text of the %CheckButton control.
	 *
	 * @since		1.0
	 * @param[in] 	alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);


	/**
	 * Sets the vertical alignment of the text of the %CheckButton control.
	 *
	 * @since		1.0
	 * @param[in] 	alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

	// Access
public:
	/**
	 * Gets the text of the %CheckButton control.
	 *
	 * @since	1.0
	 * @return	The text of the %CheckButton control
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Gets the horizontal alignment of the text of the %CheckButton control.
	 *
	 * @since	1.0
	 * @return	The horizontal text alignment
	 */
	HorizontalAlignment	GetTextHorizontalAlignment(void) const;

	/**
	 * Gets the vertical alignment of the text of the %CheckButton control.
	 *
	 * @since	1.0
	 * @return	The vertical text alignment
	 */
	VerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	 * Sets the title text of the %CheckButton control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   title				The title text to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The %CheckButton control is not set to display the title.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTitleText(const Osp::Base::String& title);

	/**
	 * Gets the title text of the %CheckButton control.
	 *
	 * @since		1.0
	 * @return		The title text
	 */
	Osp::Base::String GetTitleText(void) const;

	/**
	 * Sets the position and size of the %CheckButton control. 
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	x							The new x coordinate
	 * @param[in]	y							The new y coordinate
	 * @param[in]	width			The new width
	 * @param[in]	height			The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 *				In the bada API version prior to 2.0, the width and height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and maximum size.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect						The new bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 * 				In bada API version prior to 2.0, the width and the height of the control must be greater than @c 0.
	 * 				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and maximum size.
	 * @see   IsMovable()
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * Sets the size of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	width						The new width
	 * @param[in]	height						The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 *				In bada API version prior to 2.0, the width and height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and maximum size.
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);


	/**
	 * Sets the size of the %CheckButton control. @n
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	size						The new width and height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 *				In bada API version prior to 2.0, the width and height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and maximum size.
	 * @see   IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);
	
	//Normal color
	/**
	 * Sets the text color of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompCheckButtonSetTextColor "here".
	 *
	 * @param[in]	color 	The text color to be set
	 */
	void SetTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompCheckButtonSetTextColor        Compatibility for SetTextColor()
	 *
	 * @section    CompCheckButtonSetTextColorIssues Issues
	 *             Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of the specified color.
	 *
	 * @section    CompCheckButtonSetTextColorResolutions Resolutions
	 *             The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the text color of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompCheckButtonGetTextColor "here".
	 *
	 * @return    The text color
	 */
	Osp::Graphics::Color GetTextColor(void) const;

	/**
	 * @page       CompCheckButtonGetTextColor        Compatibility for GetTextColor()
	 *
	 * @section    CompCheckButtonGetTextColorIssues Issues
	 *             Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method returns a 16-bit color that is converted from the color specified by SetTextColor(), omitting the alpha value.
	 *
	 * @section    CompCheckButtonGetTextColorResolutions Resolutions
	 *             The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The method returns a 32-bit color.
	 */

	//Normal color
	/**
	 * Sets the title text color of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompCheckButtonSetTitleTextColor "here".
	 *
	 * @param[in]	color 	The text color to be set
	 */
	void SetTitleTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page       CompCheckButtonSetTitleTextColor        Compatibility for SetTitleTextColor()
	 *
	 * @section    CompCheckButtonSetTitleTextColorIssues Issues
	 *             Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of the specified color.
	 *
	 * @section    CompCheckButtonSetTitleTextColorResolutions Resolutions
	 *             The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the title text color of the %CheckButton control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *       			For more information, see @ref CompCheckButtonGetTitleTextColor "here".
	 *
	 * @return		The text color
	 */
	Osp::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * @page       CompCheckButtonGetTitleTextColor        Compatibility for GetTitleTextColor()
	 *
	 * @section    CompCheckButtonGetTitleTextColorIssues Issues
	 *             Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -#   The method returns a 16-bit color that is converted from the color specified by SetTitleTextColor(), omitting the alpha value.
	 *
	 * @section    CompCheckButtonGetTitleTextColorResolutions Resolutions
	 *             The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The method returns a 32-bit color.
	 */

	/**
	 * Sets the color of the %CheckButton control for the specified status.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]	color					The color to be set
	 * @param[in]   status                	The status
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.@n
	 *										The operation is not supported if the background style is BACKGROUND_STYLE_NONE.
	 * @exception   E_SYSTEM             	A system error has occurred.
	 */
	result SetColor(CheckButtonStatus status, const Osp::Graphics::Color& color);

	/**
	 * Gets the color of the %CheckButton control for the specified status.
	 *
	 * @since       2.0
	 * @return      The color, @n
	 *				else RGBA (0, 0, 0, 0) if an error occurs
	 * @param[in]   status              The status
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception 	E_INVALID_OPERATION The background style is not proper.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetColor(CheckButtonStatus status) const;

	/**
	 * Sets the text color of the %CheckButton control for the pressed status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in]	color				The text color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE      This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPressedTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the pressed status.
	 *
	 * @since      2.0
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetPressedTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the pressed status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in] color				The pressed title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPressedTitleTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the title text color of the %CheckButton for the pressed status.
	 *
	 * @since      2.0
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetPressedTitleTextColor(void) const;

	/**
	 * Sets the text color of the %CheckButton control for the highlighted status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in]	color				The text color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE     This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetHighlightedTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the highlighted status.
	 *
	 * @since      2.0
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetHighlightedTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the highlighted status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in] color				The highlighted title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetHighlightedTitleTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the title text color of the %CheckButton control for the highlighted status.
	 *
	 * @since      2.0
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetHighlightedTitleTextColor(void) const;

	/**
	 * Sets the text color of the %CheckButton control for the disabled status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in]	color				The text color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetDisabledTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the text color of the %CheckButton control for the disabled status.
	 *
	 * @since      2.0
	 * @return     The text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE	This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetDisabledTextColor(void) const;

	/**
	 * Sets the title text color of the %CheckButton control for the disabled status.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in] color                The disabled title text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE      This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetDisabledTitleTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the title text color of %CheckButton for the disabled status.
	 *
	 * @since      2.0
	 * @return     The title text color, @n
	 *			   else RGBA (0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception  E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetDisabledTitleTextColor(void) const;

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
	 * @exception	E_SYSTEM  A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

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
	 * The action ID for checked.
     * @since         1.0
     */
	int __checkedActionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for unchecked.
     * @since         1.0
     */
	int __uncheckedActionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The action ID for selected.
     * @since         1.0
     */
	int __selectedActionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The style of the checkbutton.
     * @since         1.0
     */
	CheckButtonStyle __checkStyle;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The title text of the checkbutton.
     * @since         1.0
     */
	Osp::Base::String __titleText;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The CheckButton Controller.
     * @since         1.0
     */
	Osp::Ui::Control* __pControl;

private:
	friend class RadioGroup;
	friend class CheckButtonEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */
	class CheckButtonEx* __pCheckButtonEx;

protected:
	friend class CheckButtonImpl;
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
	class CheckButtonImpl* GetImpl(void) const;

};
}; }; }; //Osp::Ui::Controls

#endif // _FUICTRL_CHECK_BUTTON_H_

