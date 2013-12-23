/* $Change: 996421 $ */
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
 * @file	FUiCtrlLabel.h
 * @brief	This is the header file for the %Label class.
 *
 * This header file contains the declarations of the %Label class and its helper classes.
 */

#ifndef _FUICTRL_LABEL_H_
#define _FUICTRL_LABEL_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FGrpColor.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlLabelEnum.h"
#include "FUiCtrlAlignmentEnum.h"


namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	Label
 * @brief 	This class defines the common behavior of a %Label control.
 * @since	1.0
 *
 * The %Label class displays a non-editable text field and does not accept any input from the user.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_label.htm">Label</a>.
 *
 * The following example demonstrates how to use the %Label class.
 *
 * @code

// Sample Code for LabelSample.h
#include <FUi.h>
#include <FGraphics.h>

class LabelSample : public Osp::Ui::Controls::Form
{
public:
    virtual result OnInitializing(void);
};

// Sample Code for LabelSample.cpp
#include "LabelSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
LabelSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Label
    Label *pLabel = new Label();
    pLabel->Construct(Rectangle(50, 200, 150, 40), L"Text");
    pLabel->SetBackgroundColor(Color::COLOR_BLUE);

    // Adds a Label to the Form
    AddControl(*pLabel);
    return r;
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Label
	: public Osp::Ui::Control
{
	DECL_CLASSTYPE(Label);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Label(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Label(void);

	/**
	 * Initializes this instance of %Label with the specified parameters.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref CompControlConstruct20 "here".
	 * @return		An error code
	 * @param[in]	rect				An instance of the Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the window.
	 * @param[in]   text				The text for this label instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *				To display text in multi-lines or to denote the end of line use '\\n'. @n
	 *				In the bada API version prior to 2.0, the width and the height of the control must be greater than @c 0. @n
     *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, const Osp::Base::String& text);


// Operation
public:
	/**
	 * Sets the specified text for the %Label control.
	 *
	 * @since		1.0
	 * @param[in] 	text		The string to set
	 * @remarks		To display text in multi-lines or to denote the end of line use '\\n'.
	 */
	void SetText(const Osp::Base::String& text);

	/**
	 * Gets the text of the %Label control.
	 *
	 * @since	1.0
	 * @return	The text of the %Label control, @n
	 *			else an empty string if an error occurs
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Sets the background bitmap of the %Label control.
	 *
	 * @since		1.0
	 * @param[in]	bitmap	 The background bitmap
	 */
	void SetBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the horizontal alignment of the text of the %Label control.
	 *
	 * @since		1.0
	 * @param[in]	alignment	The horizontal text alignment
	 */
	void SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Gets the horizontal alignment of the text of the %Label control.
	 *
	 * @since	1.0
	 * @return	The horizontal text alignment, @n
	 *			else @c ALIGNMENT_LEFT if the instance is invalid
	 */
	HorizontalAlignment	GetTextHorizontalAlignment(void) const;

	/**
	 * Sets the vertical alignment of the text of the %Label control.
	 *
	 * @since		1.0
	 * @param[in] 	alignment	The vertical text alignment
	 */
	void SetTextVerticalAlignment(VerticalAlignment alignment);

	/**
	 * Gets the vertical alignment of the text of the %Label control.
	 *
	 * @since	1.0
	 * @return	The vertical text alignment, @n
	 *			else @c ALIGNMENT_TOP if the instance is invalid
	 */
	VerticalAlignment	GetTextVerticalAlignment(void) const;

	/**
	 * Sets the background color of the %Label control.
	 *
	 * @since		1.0
	 * @param[in]	color		The normal background color
	 */
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	* Gets the background color of the %Label control.
	*
	* @since		1.0
	* @return		The background color
	*/
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the text color of the %Label control.
	 *
	 * @since		1.0
	 * @param[in]	color		The color to be set
	 */
	virtual void SetTextColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the text color of the %Label control. 
	 *
	 * @since		1.0
	 * @return		The text color
	 */
	virtual Osp::Graphics::Color GetTextColor(void) const;

	/**
	 * Sets the text attributes of the %Label control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompLabelSetTextConfig "here".
	 *
	 * @param[in]	size			The size of the text
	 * @param[in]	style			The style of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *				If @c size is less than the minimum size, this method fails. The minimum font size is 6 on devices of high screen density.
	 */
	void SetTextConfig(int size, LabelTextStyle style);
	
	/**
	 * @page	CompLabelSetTextConfig	Compatibility for SetTextConfig()
	 *
	 * @section    CompLabelSetTextConfigIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The minimum size of text is 9(for WVGA)/4(for WQVGA).
	 * -# When the text size is lower than the minimum size, it is set to the minimum size automatically.
	 *
	 * @section	CompLabelSetTextConfigResolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 2.0 as follows:
	 * -# The minimum size of text is 6(for High Screen Density), 4(for Middle Screen Density), and 3(for Low Screen Density).
	 * -# When the text size is lower than the minimum size, this method fails generating E_INVALID_ARG.
	 */

	/**
	 * Gets the text size of the %Label control.
	 *
	 * @since	1.0
	 * @return	The size of the text, @n
	 *			else @c -1 if an error occurs
	 */
	int GetTextSize(void) const;

	/**
	 * Gets the text style of the %Label control.
	 *
	 * @since	1.0
	 * @return 	The style of the text, @n
	 *			else @c LABEL_TEXT_STYLE_NORMAL if the instance is invalid
	 */
	LabelTextStyle GetTextStyle(void) const;

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
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
	 * The background bitmap
     * @since         1.0
     */	
	Osp::Graphics::Bitmap* __pBackgroundBitmap;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The font.
     * @since         1.0
     */	
	void* __pFont;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The text style
     * @since         1.0
     */	
	LabelTextStyle __textStyle;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The label's text.
     * @since         1.0
     */	
	Osp::Base::String __text;

private:
	friend class LabelEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class LabelEx* __pLabelEx;

protected:
	friend class LabelImpl;
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
	class LabelImpl* GetImpl(void) const;

};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_LABEL_H_

