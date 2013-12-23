/* $Change: 763368 $ */
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
 * @file	FUiCtrlTextBox.h
 * @brief	This is the header file for the %TextBox class.
 *
 * This header file contains the declarations of the %TextBox class and its helper classes.
 */

#ifndef _FUICTRL_TEXT_BOX_H_
#define _FUICTRL_TEXT_BOX_H_

#include "FGrpRectangle.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiITextBlockEventListener.h"
#include "FUiIUiLinkEventListener.h"

namespace Osp { namespace Ui { namespace Controls {
/**
 * @enum	TextBoxBorder
 *
 * Defines the possible types of text box borders.
 * @since	2.0
 */
enum TextBoxBorder
{
    TEXT_BOX_BORDER_NONE, 		/**< No border */
    TEXT_BOX_BORDER_ROUNDED		/**< The rounded border */
};


/**
 * @enum 	TextBoxStatus
 *
 * Defines the possible states of the text box.
 * @since	2.0
 */
enum TextBoxStatus
{
    TEXT_BOX_STATUS_NORMAL,			/**< The normal state */
    TEXT_BOX_STATUS_HIGHLIGHTED,	/**< The focus-highlighted state */
    TEXT_BOX_STATUS_DISABLED		/**< The disabled state */
};


/**
 * @enum 	TextBoxTextColor
 *
 * Defines the possible text colors.
 * @since	2.0
 */
enum TextBoxTextColor
{
    TEXT_BOX_TEXT_COLOR_NORMAL,			/**< The default text color */
    TEXT_BOX_TEXT_COLOR_HIGHLIGHTED,	/**< The highlighted text color */
    TEXT_BOX_TEXT_COLOR_DISABLED,		/**< The disabled text color */
    TEXT_BOX_TEXT_COLOR_BLOCKED,		/**< The text block color */
    TEXT_BOX_TEXT_COLOR_LINK			/**< The link text color */
} ;


/**
 * @enum 	TextBoxTextStyle
 *
 * Defines the possible text styles.
 * @since	2.0
 */
enum TextBoxTextStyle
{
    TEXT_BOX_TEXT_STYLE_NORMAL       = 0x0000,			/**< The normal text style */
    TEXT_BOX_TEXT_STYLE_BOLD         = 0x0001,			/**< The bold text style */
	TEXT_BOX_TEXT_STYLE_ITALIC       = 0x0002,			/**< The italic text style */
    TEXT_BOX_TEXT_STYLE_UNDERLINE    = 0x0004,			/**< The underline text style */
    TEXT_BOX_TEXT_STYLE_STRIKEOUT    = 0x0008,			/**< The strikeout text style */
    TEXT_BOX_TEXT_STYLE_MAX          = 0x7FFF			/**< The placeholder */
};

/**
 * @class	TextBox
 * @brief	This class is an implementation of a %TextBox control 
 * @since	2.0
 *
 * The %TextBox class displays a non-editable text field.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_textbox.htm">TextBox</a>.
 *
 * @code
// Sample Code for TextBoxSample.h
#include <FUi.h>
 
class TextBoxSample :
    public Osp::Ui::Controls::Form

{
protected:
 
	Osp::Ui::Controls::TextBox* __pTextBox;

public:
    virtual result OnInitializing(void);
 
};

// Sample Code for TextBoxSample.cpp
#include "TextBoxSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
TextBoxSample::OnInitializing()
{
 	result r = E_SUCCESS;

	__pTextBox = new TextBox();
	__pTextBox->Construct(Rectangle(50, 50, 380, 450), TEXT_BOX_BORDER_ROUNDED);
	__pTextBox->SetTextSize(50);

	String sampleText1(L"bada developer");
	__pTextBox->SetText(sampleText1);
	__pTextBox->SetTextColor(TEXT_BOX_TEXT_COLOR_HIGHLIGHTED, Color::COLOR_RED);

	String sampleText2(L" bada SDK");
	__pTextBox->AppendText(sampleText2);

	AddControl(*__pTextBox);

	return r;
}

* @endcode
*/
class _EXPORT_CONTROLS_ TextBox :
	public Osp::Ui::Control
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 */
	TextBox(void);

	/**
	 * This is destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~TextBox(void);

	/**
	 * Initializes this instance of %TextBox with the specified parameters.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rect	            An instance of the Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the control.
	 * @param[in]	border	            The border style
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state, @n
	 *									or the object is already constructed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, TextBoxBorder border = TEXT_BOX_BORDER_ROUNDED);

// Operation
public:
	/**
     * Sets the auto-link mask.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	autoLinks		The auto-link mask @n
     *								Multiple link types can be combined using the bitwise OR operator (see Osp::Base::Utility::LinkType). @n
     *								For more information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		When @c autoLinks is set to @c 0, the auto-link detection is disabled.
     * @see			Osp::Base::Utility::LinkType
     * @see			GetAutoLinkMask()
     */	 
	result SetAutoLinkMask(unsigned long autoLinks);

    /**
     * Gets the auto-link mask.
     *
     * @since		2.0
     * @return		The auto-link mask
     * @exception	E_SUCCESS				The method is successful.
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
	 * @param[in]	listener    The event listener to be added
	 * @see			RemoveUiLinkEventListener()
	 */
	void AddUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

    /**
     * Removes the specified link event listener. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since		2.0
     * @param[in]	listener    The event listener to be removed
     * @see			AddUiLinkEventListener()
     */
	void RemoveUiLinkEventListener(const Osp::Ui::IUiLinkEventListener& listener);

// Text
	/**
	 * Appends the specified character at the end of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	character		The character to be added
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %TextBox control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Osp::Base::Character& character);

	/**
	 * Appends the specified text at the end of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text			The text to be appended
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM    	A system error has occurred.
	 * @remarks		To denote the end of a line use '\\n'. @n
     * 				The method modifies the text buffer that is managed by the %TextBox control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result AppendText(const Osp::Base::String& text);

	/**
	 * Clears the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %TextBox control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
	 * Gets the number of the lines contained in the %TextBox control.
	 *
	 * @since		2.0
	 * @return		The line count of the text, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetLineCount(void) const;

	/**
	 * Gets the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 * @return		The text of the %TextBox control, @n
	 *			    else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Gets a portion of the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 * @return		The specified portion of the text, @n 
	 * 				else an empty string if an error occurs
	 * @param[in]	start	        The starting index of the range
	 * @param[in]	end	            The last index of the range
	 * @exception	E_SUCCESS 	    The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	 *								The index is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Osp::Base::String GetText(int start, int end) const;

	/**
     * Gets the length of the text that is displayed by the %TextBox control.
	 *
	 * @since		2.0
	 * @return		The length of the text, @n
	 *            	else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTextLength(void) const;

	/**
	 * Inserts the character at the specified index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index		    The position at which to insert the character
	 * @param[in]	character	    The character to be inserted
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result InsertCharacterAt(int index, const Osp::Base::Character& character);

	/**
	 * Inserts the text at the specified index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index		    The position at which to insert the text
	 * @param[in]	text		    The text to be inserted
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result InsertTextAt(int index, const Osp::Base::String& text);

	/**
	 * Sets the text to be displayed.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text            The text to be displayed
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks     To denote the end of a line use '\\n'. @n
     * 				The method modifies the text buffer that is managed by the %TextBox control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result SetText(const Osp::Base::String& text);

// Line Spacing
	/**
	 * Gets the line spacing.
	 *
	 * @since		2.0
	 * @return    	The line spacing,  @n
	 *            	else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLineSpacing()
	 */
	int GetLineSpacing(void) const;

	/**
	 * Sets the line spacing. @n
	 * The line spacing is determined by multiplying @c multiplier to the default line spacing and adding @c extra. @n
	 *
	 * @code
	 * The line spacing = (default line spacing) * multiplier + extra
	 * @endcode
	 *
	 * @since          2.0
	 * @return         An error code
	 * @param[in]      multiplier			The line spacing multiplier
	 * @param[in]      extra				The extra line spacing
	 * @exception      E_SUCCESS			The method is successful.
	 * @exception      E_INVALID_ARG		A specified input parameter is invalid. @n
	 *										The specified line spacing value cannot be supported.
	 * @exception      E_INVALID_STATE		This instance is in an invalid state.
	 * @exception      E_SYSTEM				A system error has occurred.
	 * @see            GetLineSpacing()
	 */
	result SetLineSpacing(int multiplier, int extra);

	// Text Alignment
    /**
     * Gets the horizontal text alignment.
     *
     * @since		2.0
     * @return		The horizontal text alignment
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
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
     * @param[in]	alignment		The horizontal text alignment
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetTextAlignment()
     */
	result SetTextAlignment(HorizontalAlignment alignment);

	// Text Size
	/**
	 * Gets the text size of the %TextBox control.
	 *
	 * @since		2.0
	 * @return  	The size of the text, @n
	 *          	else @c -1 if an error occurs
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetTextSize()
	 */
	int GetTextSize(void) const;

	/**
	 * Sets the text size.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	size                The text size
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE     This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   	The specified input parameter is invalid. @n
	 *									The specified @c size cannot be a negative integer.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetTextSize()
	 */
	result SetTextSize(int size);

	// Text Font
	/**
	 * Gets the font typeface name and the style mask of the %TextBox control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[out]	typefaceName     	The name of the font typeface
	 * @param[out]	style            	The text style (see TextBoxTextStyle)
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_STATE  	This instance is in an invalid state.
	 * @exception	E_SYSTEM         	A system error has occurred.
	 * @remarks     Multiple styles can be combined using the bitwise OR operator.
	 * @see			SetFontType()
	 * @see			Osp::Graphics::Font::GetSystemFontListN()
	 * @see			TextBoxTextStyle
	 */	
	result GetFontType(Osp::Base::String& typefaceName, unsigned long& style) const;

	/**
	 * Sets the font and the style mask of the %TextBox control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	typefaceName     	The name of the font typeface
	 * @param[in]	style            	The text style @n
	 *								 	Multiple styles can be combined using the bitwise OR operator(see TextBoxTextStyle).
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG    	A specified input parameter is invalid, or the specified font typeface is not supported.
	 * @exception	E_INVALID_STATE  	This instance is in an invalid state.
	 * @exception	E_SYSTEM         	A system error has occurred.
	 * @remarks	    The specified font typeface must be one of the system fonts. @n
	 *              @c italic and @c bold cannot be applied at the same time. If the specified style mask contains both @c italic and @c bold, @c italic will 
	 *				be applied. 
	 * @see			GetFontType()
	 * @see			Osp::Graphics::Font::GetSystemFontListN()
	 * @see			TextBoxTextStyle
	 */
	result SetFontType(const Osp::Base::String& typefaceName, unsigned long style);

	/**
	 * Sets the font to render the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	font             The text font
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_INVALID_STATE  This instance is in an invalid state.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @remarks		All previously set text attributes (style, weight, decoration, and size) will be discarded.
	 */
	result SetFont(const Osp::Graphics::Font& font);

// Text Block
	/**
	 * Releases the selection of the current text block.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @see			GetBlockRange()
	 * @see			SetBlockRange()
	 */
	result ReleaseBlock(void);

	/**
	 * Gets the start and the end index of the currently selected text block.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[out]	start	           The start index of the text block
	 * @param[out]	end  	           The end index of the text block
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_INVALID_STATE    This instance is in an invalid state.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @remarks		The method returns @c start = 0 and @c end = 0 if there is no selected text block.
	 * @see			ReleaseBlock()
	 * @see			SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;

	/**
	 * Sets the specified block of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	start	        The start index of the text block
	 * @param[in]	end  	        The end index of the text block
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n 
	 *								Either the @c start or @c end parameters are greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			ReleaseBlock()
	 * @see			GetBlockRange()
	 */
	result SetBlockRange(int start, int end);
	
// Appearances
	/**
	 * Gets the color of the %TextBox control for the specified status.
	 *
	 * @since		2.0
	 * @return		The color of the %TextBox control, @n
     *				else RGBA (0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetColor()
	 */
	Osp::Graphics::Color GetColor(TextBoxStatus status) const;

    /**
     * Gets the text color of the specified text color type.
     *
     * @since		2.0
     * @return		The color, @n
     *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]	type				The text color type
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetTextColor()
     */
	Osp::Graphics::Color GetTextColor(TextBoxTextColor type) const;

	/**
	 * Sets the background bitmap of the %TextBox control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	status			The state of the %TextBox control
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS   	The method is successful.
	 * @exception	E_SYSTEM    	A system error has occurred.
	 * @see			SetBackgroundColor()
	 */
	result SetBackgroundBitmap(TextBoxStatus status, const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %TextBox control for the specified status.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	status          The state of the %TextBox control
	 * @param[in]	color           The color to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(TextBoxStatus status, const Osp::Graphics::Color& color);

	/**
	 * Sets the text color of the %TextBox control for the specified text type.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	type             The text color type
	 * @param[in]	color            The text color to be set
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_INVALID_STATE  This instance is in an invalid state.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @see			GetTextColor()
	 */
	result SetTextColor(TextBoxTextColor type, const Osp::Graphics::Color& color);

	/**
	 * Adds a text block event listener. 
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @remarks		Programmatically modifying the text selection does not cause the text block selection event to fire.
	 * @see			RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);
		
	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

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
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	friend class TextBoxEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
	class TextBoxEx* __pTextBoxEx;

protected:
	friend class TextBoxImpl;
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
     class TextBoxImpl* GetImpl(void) const;
};	//TextBox
}}}

#endif	// _FUICTRL_TEXT_BOX_H_
