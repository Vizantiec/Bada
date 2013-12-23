/* $Change: 777631 $ */
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
 * @file	FUiCtrlExpandableEditArea.h
 * @brief	This is the header file for the %ExpandableEditArea class.
 *
 * This header file contains the declarations of the %ExpandableEditArea class.
 */

#ifndef _FUICTRL_EXPANDABLE_EDIT_AREA_H_
#define _FUICTRL_EXPANDABLE_EDIT_AREA_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiITextEventListener.h"
#include "FUiIKeypadEventListener.h"
#include "FUiITextBlockEventListener.h"
#include "FUiCtrlEditEnum.h"
#include "FUiCtrlITokenFilter.h"


// Forward declaration
namespace Osp { namespace Graphics { class Rectangle; };} ;
namespace Osp { namespace Ui { namespace Controls {

class IExpandableEditAreaEventListener;

/**
 * @enum ExpandableEditAreaStyle
 *
 * Defines the possible styles of the expandable edit area.
 * @since		2.0
 */
enum ExpandableEditAreaStyle
{
	EXPANDABLE_EDIT_AREA_STYLE_NORMAL,  /**< The normal expandable edit area */
	EXPANDABLE_EDIT_AREA_STYLE_TOKEN    /**< The token expandable edit area */
};


/**
 * @enum ExpandableEditAreaTitleStyle
 *
 * Defines the possible styles of the expandable edit area title.
 * @since		2.0
 */
enum ExpandableEditAreaTitleStyle
{
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_NONE = 0,		/**< The style with no title */
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_INNER,			/**< The title appears as a right aligned text inside the edit text field */
	EXPANDABLE_EDIT_AREA_TITLE_STYLE_TOP			/**< The title appears at the top of the edit text field */
};


/**
 * @enum ExpandableEditAreaTokenStatus
 *
 * Defines the possible status of the expandable edit area tokens.
 * @since		2.0
 */
enum ExpandableEditAreaTokenStatus
{
	EXPANDABLE_EDIT_AREA_TOKEN_STATUS_NORMAL = 0,	/**< The normal status */
	EXPANDABLE_EDIT_AREA_TOKEN_STATUS_SELECTED   	/**< The selected status */
};


/**
 * @class	ExpandableEditArea
 * @brief	This class is an implementation of %ExpandableEditArea.
 * @since	2.0
 *
 * The %ExpandableEditArea class displays a multi-line text editor the height of which is automatically adjusted according to the number of lines currently visible in the text box.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
 *
* The following sample code demonstrates how to use the %ExpandableEditArea class.
*
* @code
// Sample code for ExpandableEditAreaSample.h
#include <FUi.h>

class ExpandableEditAreaSample :
public Osp::Ui::Controls::Form,
public Osp::Ui::IKeypadEventListener,
public Osp::Ui::Controls::IExpandableEditAreaEventListener

{
protected:

  Osp::Ui::Controls::ExpandableEditArea* __pExpandableEdit;


public:
  virtual result OnInitializing(void);

  //IKeypadEventListener
  virtual void OnKeypadActionPerformed(Osp::Ui::Control& source, Osp::Ui::KeypadAction keypadAction);
  virtual void OnKeypadClosed(Osp::Ui::Control& source);
  virtual void OnKeypadOpened(Osp::Ui::Control& source);
  virtual void OnKeypadWillOpen(Osp::Ui::Control& source);
  
  //IExpandableEditAreaEventListener
  virtual void OnExpandableEditAreaLineAdded(Osp::Ui::Controls::ExpandableEditArea& source, int newLineCount);
  virtual void OnExpandableEditAreaLineRemoved(Osp::Ui::Controls::ExpandableEditArea& source, int newLineCount);


};

// Sample code for ExpandableEditAreaSample.cpp
#include "ExpandableEditAreaSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;;


result
ExpandableEditAreaSample::OnInitializing()
{
  result r = E_SUCCESS;
  
  __pExpandableEdit = new ExpandableEditArea();
  __pExpandableEdit->Construct(Rectangle(0, 100, 480, 150),
  EXPANDABLE_EDIT_AREA_STYLE_NORMAL,
  EXPANDABLE_EDIT_AREA_TITLE_STYLE_NONE, 5);
  __pExpandableEdit->AddKeypadEventListener(*this);
  __pExpandableEdit->AddExpandableEditAreaEventListener(*this);
  
  AddControl(*__pExpandableEdit);
  __pExpandableEdit->SetFocus();
  
  return r;
}

void
ExpandableEditAreaSample::OnKeypadActionPerformed(Control& source, KeypadAction keypadAction)
{
  // Todo:
}

void
ExpandableEditAreaSample::OnKeypadClosed(Control& source)
{
  // Todo:
}

void
ExpandableEditAreaSample::OnKeypadOpened(Control& source)
{
  // Todo:
}

void
ExpandableEditAreaSample::OnKeypadWillOpen(Control& source)
{
  // Todo:
}


void
ExpandableEditAreaSample::OnExpandableEditAreaLineAdded(
ExpandableEditArea &source, int newLineCount)
{
  // Todo:
}

void
ExpandableEditAreaSample::OnExpandableEditAreaLineRemoved(
ExpandableEditArea &source, int newLineCount)
{
  // Todo:
}
* @endcode
*/
class _EXPORT_CONTROLS_ ExpandableEditArea
	: public Osp::Ui::Control {
public:
	/**
	 * This is default constructor for this class.
	 *
	 * @since	2.0
	 */
	ExpandableEditArea(void);

	/**
	 * This is destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ExpandableEditArea(void);

    /**
	 * Initializes this instance of %ExpandableEditArea with the specified parameters.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    rect             An instance of the Graphics::Rectangle class @n
	 *										This instance represents the x and y coordinates of the top-left corner of the expandable edit area along with 
	 *										the width and height.
	 * @param[in]    style            The style of the expandable edit area
	 * @param[in]    titleStyle       The title style
	 * @param[in]    maxLines         The maximum number of lines supported
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception    E_UNSUPPORTED_OPTION 	The specified option is not supported. @n
	 *										The token style %ExpandabledEditArea does not support EXPANDABLE_EDIT_AREA_TITLE_STYLE_TOP.
	 * @exception	E_OUT_OF_MEMORY  		The memory is insufficient.
	 * @exception    E_MAX_EXCEEDED   		The number of lines has exceeded the maximum limit.
	 * @exception	E_INVALID_ARG    		A specified input parameter is invalid, or @n
	 *										the specified @c maxLines is either negative or @c 0.
	 * @exception	E_SYSTEM         		A system error has occurred.
	 * @remarks      By default, the line count is @c 1.
	 * @remarks		 For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, ExpandableEditAreaStyle style, ExpandableEditAreaTitleStyle titleStyle, int maxLines = 10);

// TEXT MANAGEMENT
	/**
	 * Appends the specified character at the end of the existing text.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]	character       The character to be appended 
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_MAX_EXCEEDED  The number of items has exceeded the maximum limit. @n
	 *                              The number of characters has exceeded the maximum limit.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %ExpandableEditArea control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Osp::Base::Character& character);

    /**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   text            The text to be appended
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception	E_MAX_EXCEEDED  The number of items has exceeded the maximum limit @n
	 *                              The number of characters has exceeded the maximum limit.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The method modifies the text buffer that is managed by the %ExpandableEditArea control. @n
     *              To display the changes, the control must be drawn again.
	 */
    result AppendText(const Osp::Base::String& text);

	 /**
	 * Deletes the character present at the current cursor position.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   index			The index
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	The specified input parameter is invalid. @n
	 *								The specified @c index is negative.
	 * @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The method modifies the text buffer that is managed by the %ExpandableEditArea control. @n
     *              To display the changes, the control must be drawn again.
	 */
    result DeleteCharacterAt(int index);

	 /**
	 * Inserts a character at the specified index.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]   index           The position to insert the character
	 * @param[in]   character	    The character to be inserted
	 * @exception   E_SUCCESS 	    The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *                              The specified @c index is negative.
	 * @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements.
	 * @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds system limitations.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The method modifies the text buffer that is managed by the %ExpandableEditArea control. @n
     *              To display the changes, the control must be drawn again.
	 */
    result InsertCharacterAt(int index, const Osp::Base::Character& character);

	 /**
	 * Inserts the text at the specified index.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]   index           The position to insert the text
	 * @param[in]   text            The text to be inserted
	 * @exception   E_SUCCESS 	    The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *                              The specified @c index is negative.
	 * @exception   E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements.
	 * @exception   E_MAX_EXCEEDED  The length of the specified @c text exceeds system limitations.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM	    A system error has occurred.
	 */
    result InsertTextAt(int index, const Osp::Base::String& text);

	 /**
	 * Gets the portion of the text that is displayed by the %ExpandableEditArea control.
	 *
	 * @since        2.0
	 * @return       The specified portion of the text, @n 
	 *               else an empty string if an error occurs
	 * @param[in]    start           The starting index of the range
	 * @param[in]    end             The last index of the range
	 * @exception    E_SUCCESS       The method is successful.
	 * @exception    E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	 *								 The specified @c start or @c end is greater than the number of elements or less than @c 0.
	 * @exception	 E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception    E_INVALID_STATE This instance is in an invalid state.
	 * @exception    E_SYSTEM        A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          GetText()
	 * @see          SetText()
	 */
    Osp::Base::String GetText(int start, int end) const;

	 /**
	 * Gets the text of the %ExpandableEditArea control.
	 *
	 * @since        2.0
	 * @return       The text of the %ExpandableEditArea control, @n 
	 *               else an empty string if an error occurs
	 * @exception    E_SUCCESS       The method is successful.
	 * @exception    E_INVALID_STATE This instance is in an invalid state.
	 * @exception    E_SYSTEM        A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
    Osp::Base::String GetText(void) const;

	 /**
	 * Gets the text length.
	 *
	 * @since       2.0
	 * @return      The length of the text, @n 
	 *	 			else @c -1 if an error occurs
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
    int GetTextLength(void) const;

	 /**
	 * Sets the text to be displayed by the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 * @param[in]	text            The text to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid, @n
	 *								or the length of the specified @c text exceeds system limitations.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks     To denote the end of a line use '\\n'.
     * 				The method modifies the text buffer that is managed by the %ExpandableEditArea control. 
     *              To display the changes, the control must be drawn again.
	 */
    result SetText(const Osp::Base::String& text);

	 /**
	 * Clears the text that is displayed by the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %ExpandableEditArea control. 
     *              To display the changes, the control must be drawn again.
	 */
    result Clear(void);

	/**
	 * Sets the title of the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in] 	title			The title to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetTitleText(const Osp::Base::String& title);

	/**
	 * Gets the title of the %ExpandableEditArea control.
	 *
	 * @since		2.0
	 * @return		The title text of the entered string, @n
	 *			    else empty string if an error occurs
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetTitleText(void) const;

// GUIDE TEXT
	/**
	 * Gets the guide text.
	 *
	 * @since       2.0
	 * @return	    The guide text, @n 
	 *              else an empty string if an error occurs
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetGuideText()
	 */
	Osp::Base::String GetGuideText(void) const;

	 /**
	 * Sets the guide text to be displayed, when there is no data in the search field.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]   guideText		 The guide text
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state.
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetGuideText()
	 */
    result SetGuideText(const Osp::Base::String& guideText);
	 
// LINE MANAGEMENT
	/**
	 * Gets the maximum line count supported by the flexible text edit.
	 *
	 * @since       2.0
	 * @return      The maximum line count, @n
	 *	 			else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetMaxLineCount(void) const;

	 /**
	 * Gets the current line count.
	 *
	 * @since       2.0
	 * @return      The line count of the text
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
    int GetTextLineCount(void) const;

// TEXT SIZE
	/**
	 * Gets the text size.
	 *
	 * @since       2.0
	 * @return      The size of the text, @n 
	 *	 			else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetTextSize()
	 */
	int GetTextSize(void) const;

	 /**
	 * Sets the text size.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   size                The text size
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified @c size is invalid, @n
	 *									or the specified @c size is a negative integer.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         GetTextSize()
	 */
    result SetTextSize(int size);

// MARGINS
	/**
	 * Gets the margin of the specified margin type.
	 *
	 * @since       2.0
	 * @return      The margin value of the specified margin type, @n
	 *	 			else @c -1 if an error occurs
	 * @param[in]   marginType      The margin type
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMargin()
	 */
	int GetMargin(EditMarginType marginType) const;

	/**
	 * Sets the margin for the specified margin type.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   marginType          The margin type
	 * @param[in]   margin              The margin to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *                                  The specified @c margin cannot be negative integer.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         GetMargin()
	 */
	result SetMargin(EditMarginType marginType, int margin);

// LOWER CASE
	/**
	 * Enables or disables the lowercase mode.
	 
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   enable              Set to @c true to enable the lowercase mode, @n
	 *	 								else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     When the lowercase mode is enabled, the text input starts with a lowercase character.
	 * @see         IsLowerCaseModeEnabled()
	 */
	result SetLowerCaseModeEnabled(bool enable);

	/**
	 * Checks whether the lowercase mode is enabled.
	 *
	 * @since       2.0
	 * @return      @c true if the lowercase mode is enabled, @n
	 *	 			else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetLowerCaseModeEnabled()
	 */
	bool IsLowerCaseModeEnabled(void) const;

// CURSOR MANAGEMENT
	/**
	 * Gets the cursor position.
	 *
	 * @since        2.0
	 * @return       The current cursor position, @n
	 *				 else @c -1 if an error occurs
	 * @exception    E_SUCCESS       	The method is successful.
	 * @exception    E_INVALID_STATE This instance is in an invalid state.
	 * @exception    E_SYSTEM        	A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCursorPosition(void) const;

	/**
	 * Sets the cursor at the specified position.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    position        The cursor position to be set
	 * @exception    E_SUCCESS       The method is successful.
	 * @exception    E_OUT_OF_RANGE  The specified @c position is less than @c 0 or greater than the maximum length.
	 * @exception    E_SYSTEM        A system error has occurred.
	 */
	result SetCursorPosition(int position);

// TEXT BLOCKING
	/**
	 * Gets the start and end indexes of the currently selected text block.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[out]  start              The start index of the text block
	 * @param[out]  end                The end index of the text block
	 * @exception   E_SUCCESS          The method is successful.
	 * @exception   E_INVALID_STATE    This instance is in an invalid state.
	 * @exception   E_SYSTEM           A system error has occurred.
	 * @remarks     The method returns the start and end indexes as @c 0 if no text block is selected.
	 * @see         ReleaseBlock()
	 * @see         SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;

	 /**
	 * Releases the selection of the current text block.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @exception   E_SUCCESS          The method is successful.
	 * @exception   E_INVALID_STATE    This instance is in an invalid state.
	 * @exception   E_SYSTEM           A system error has occurred.
	 * @see         GetBlockRange()
	 * @see         SetBlockRange()
	 */
    result ReleaseBlock(void);

	 /**
	 * Removes the text content of the current text block.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OBJ_NOT_FOUND    The specified instance is not found, @n
	 *									or the text block is not selected.
	 * @exception    E_INVALID_STATE    This instance is in an invalid state.
	 * @exception    E_SYSTEM           A system error has occurred.
	 */
    result RemoveTextBlock(void);

	 /**
	 * Selects the specified block of the text.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   start           The start index of the text block
	 * @param[in]   end             The end index of the text block
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure. @n
	 *								Either the index is greater than the number of elements or less than zero.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         ReleaseBlock()
	 * @see         GetBlockRange()
	 */
    result SetBlockRange(int start, int end);

// KEYPAD MANAGEMENT
	/**
	 * Gets the keypad action type.
	 *
	 * @since       2.0
	 * @return      The keypad action
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadAction()
	 */
	Osp::Ui::KeypadAction GetKeypadAction(void) const;

	 /**
	 * Gets the keypad style.
	 *
	 * @since       2.0
	 * @return      The keypad style
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadStyle()
	 */
    KeypadStyle GetKeypadStyle(void) const;

	 /**
	 * Hides the keypad associated with the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         ShowKeypad()
	 */
    result HideKeypad(void);

	 /**
	 * Checks whether the keypad is enabled.
	 *
	 * @since       2.0
	 * @return      @c true if the keypad is enabled, @n
	 *	 			else @c false
	 * @exception   E_SUCCESS       		The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state.
	 * @exception   E_SYSTEM        		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetKeypadEnabled()
	 */
    bool IsKeypadEnabled(void) const;

    /**
     * Sets the keypad action type.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   keypadAction			The keypad action
     * @exception   E_SUCCESS				The method is successful.
     * @exception   E_INVALID_STATE			This instance is in an invalid state.
     * @exception   E_SYSTEM				A system error has occurred.
     * @remarks     Depending on the value of @c keypadAction, the enter key label of the keypad will change accordingly.
	 * @see         GetKeypadAction()
     */
	result SetKeypadAction(Osp::Ui::KeypadAction keypadAction);

	 /**
	 * Sets the keypad style.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   keypadStyle         The keypad style
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	 *                                  The specified @c keypadStyle is KEYPAD_STYLE_PASSWORD.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     Depending on the value of the keypad style, the layout of the keypad will change accordingly.
	 * @see         GetKeypadStyle()
	 */
    result SetKeypadStyle(KeypadStyle keypadStyle);

	 /**
	 * Enables or disables the keypad.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   enable			Set to @c true to enable the virtual keypad, @n
	 *								else @c false
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @see         IsKeypadEnabled()
	 */
    result SetKeypadEnabled(bool enable);

	 /**
	 * Shows the keypad. 
	 *
	 * @since       2.0
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         HideKeypad()
	 */
    result ShowKeypad(void);

// TOKEN FILTER
	/**
	 * Sets the text token filter.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   pFilter            		The filter
	 * @exception   E_SUCCESS          		The method is successful.
     * @exception	E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *										The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception   E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception   E_SYSTEM           		A system error has occurred.
	 * @remarks     The %ExpandableEditArea control checks with the registered filter to decide whether the user-entered text should be replaced.
	 */
	result SetTokenFilter(const ITokenFilter* pFilter);

	 /**
	 * Gets the text token filter.
	 *
	 * @since        2.0
	 * @return       The filter, @n 
	 *				 else @c null if an error occurs
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state.
	 * @exception    E_SYSTEM            		A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	ITokenFilter* GetTokenFilter(void) const;

	 /**
	 * Appends the specified token.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    token              		The token to be appended
	 * @exception    E_SUCCESS          		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_ARG      		The specified input parameter is invalid. @n
	 *                                 	 		The length of the specified @c token is @c 0.
	 * @exception    E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception    E_SYSTEM           		A system error has occurred.
	 */
	result AppendToken(const Osp::Base::String& token);

	/**
	 * Inserts the token at the specified index.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]	 index						The position to insert the token
	 * @param[in]    token              		The token to be added
	 * @exception    E_SUCCESS          		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_ARG      		A specified input parameter is invalid. @n
	 *                                  		The length of the specified @c token is @c 0.
	 * @exception    E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception    E_SYSTEM           		A system error has occurred.
	 */
	result InsertTokenAt(int index, const Osp::Base::String& token);

	/**
	 * Gets the token text at the specified index.
	 *
	 * @since        2.0
	 * @return       The token text at the specified index, @n
	 *               else an empty string if an error occurs
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_OUT_OF_RANGE				The specified index parameter is outside the bounds of the data structure. @n
	 *											Either the index is greater than the number of elements or less than @c 0.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state.
	 * @exception    E_SYSTEM            		A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetTokenAt(int index) const;

	/**
	 * Gets the total token count.
	 *
	 * @since        2.0
	 * @return       The total token count, @n 
	 *	 			 else @c -1 if an error occurs
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state.
	 * @exception    E_SYSTEM            		A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTokenCount(void) const;

	/**
	 * Gets the index of the token that is selected.
	 *
	 * @since        2.0
	 * @return       The index of the selected token, @n
	 *	 			 else @c -1 if no token is selected or if an error occurs
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state.
	 * @exception    E_SYSTEM            		A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
    int GetSelectedTokenIndex(void) const;

	 /**
	 * Checks whether the token editing mode is enabled.
	 *
	 * @since        2.0
	 * @return       @c true if the editing mode is enabled, @n
	 *	 			 else @c false
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state.
	 * @exception    E_SYSTEM            		A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
    bool IsTokenEditModeEnabled(void) const;

	 /**
	 * Removes the token at the specified index.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    index              		The index of the token to be removed
	 * @exception    E_SUCCESS          		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_OUT_OF_RANGE     		The specified index is outside the bounds of the data structure. @n
	 *											Either the index is greater than the number of elements or less than @c 0.
	 * @exception    E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception    E_SYSTEM           		A system error has occurred.
	 */
    result RemoveTokenAt(int index);

	 /**
	 * Sets the selected state of the specified token.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    index              		The index of the token to select
	 * @param[in]    selected           		Set to @c true to select the specified token, @n
	 *											else @c false to unselect
	 * @exception    E_SUCCESS          		The method is successful.
   * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *                              The specified @c index is negative.
	 * @exception    E_OUT_OF_RANGE     		The specified index is outside the bounds of the data structure. @n
	 *											The specified @c index is greater than the number of elements.
	 * @exception    E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception    E_SYSTEM           		A system error has occurred.
	 * @remarks      The currently selected token gets unselected automatically.
	 */
    result SetTokenSelected(int index, bool selected);

	 /**
	 * Enables or disables the token edit mode.
	 *
	 * @since        2.0
	 * @return       An error code
	 * @param[in]    enable	            		Set to @c true to enable the token editing mode, @n
	 *											else @c false
	 * @exception    E_SUCCESS          		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE    		This instance is in an invalid state.
	 * @exception    E_SYSTEM           		A system error has occurred.
	 */
    result SetTokenEditModeEnabled(bool enable);

// LIMIT LENGTH
	/**
	 * Gets the limit length.
	 *
	 * @since		2.0
	 * @return      The limit length, @n 
	 *	 			else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *              The default limit length is @c 2048.
	 * @see         SetLimitLength()
	 */
	int GetLimitLength(void) const;

    /**
	 * Sets the limit length.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   limitLength		The limit text length to be set
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	The specified input parameter is invalid, @n
	 *								or the specified limit length is @c 0 or negative.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %ExpandableEditArea control. @n
     *              To display the changes, the control must be drawn again.
	 * @see         GetLimitLength()
	 */
	result SetLimitLength(int limitLength);
	 
// APPEARANCES
	/**
	 * Gets the color of the %ExpandableEditArea control for the specified status.
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
	 * Gets the text color of the specified text type.
	 *
	 * @since        2.0
	 * @return       The text color, @n
     *				 else RGBA (0,0,0,0) if an error occurs
	 * @param[in]    type                The text type
	 * @exception    E_SUCCESS			The method is successful.
	 * @exception    E_INVALID_STATE     This instance is in an invalid state.
	 * @exception    E_INVALID_ARG		The specified type is not supported, or @n
	 *									the specified @c type is EDIT_TEXT_COLOR_LINK.
	 * @exception    E_SYSTEM			A system error has occurred. 
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTextColor()
	 */
    Osp::Graphics::Color GetTextColor(EditTextColor type) const;

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since       2.0
	 * @return	    The guide text color, @n
     *				else RGBA (0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state. 
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. 
	 * @see         SetGuideTextColor()
	 */
    Osp::Graphics::Color GetGuideTextColor(void) const;
	 
	/**
	 * Gets the text color of the title for the specified status.
	 *
	 * @since		2.0
	 * @return		The title text color, @n
     *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	status			The state of the %ExpandableEditArea control     
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state. 
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 * @see			SetTitleTextColor()
	 */
    Osp::Graphics::Color GetTitleTextColor(EditStatus status) const;   
	 
    /**
	 * Gets the color of the tokens for the specified status.
	 *
	 * @since        2.0
	 * @return       The token color, @n
     *				 else RGBA (0,0,0,0) if an error occurs
	 * @param[in]    status              		The status
	 * @exception    E_SUCCESS           	 	The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state. 
	 * @exception    E_SYSTEM            		A system error has occurred. 
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTokenColor
	 */
	Osp::Graphics::Color GetTokenColor(ExpandableEditAreaTokenStatus status) const;

    /**
	 * Gets the text color of tokens.
	 *
	 * @since        2.0
	 * @return       The text color, @n
     *				 else RGBA (0,0,0,0) if an error occurs
	 * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
	 * @exception    E_INVALID_STATE     		This instance is in an invalid state. 
	 * @exception    E_SYSTEM            		A system error has occurred. 
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          SetTokenTextColor()
	 */
	Osp::Graphics::Color GetTokenTextColor(void) const;
	 
	/**
	 * Sets the background bitmap of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   status          The status
	 * @param[in]   bitmap          The background bitmap
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state. 
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
    result SetBackgroundBitmap(EditStatus status, const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   status          The status of the %ExpandableEditArea control
	 * @param[in]   color           The color
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_STATE This instance is in an invalid state. 
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         GetColor()
	 */
    result SetColor(EditStatus status, const Osp::Graphics::Color& color);

	/**
	 * Sets the text color of the guide text.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]   color		     The guide text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state. 
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetGuideTextColor()
	 */
    result SetGuideTextColor(const Osp::Graphics::Color& color);
	 
	/**
	 * Sets the text color of the title for the specified status.
	 *
	 * @since       2.0
	 * @return	    An error code
	 * @param[in]	status			The status of the %ExpandableEditArea control     
	 * @param[in]   color			The title text color
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state. 
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @see         GetTitleTextColor()
	 */
    result SetTitleTextColor(EditStatus status, const Osp::Graphics::Color& color);
	 
	/**
	 * Sets the text color of the %ExpandableEditArea control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   type             The text type
	 * @param[in]   color            The text color
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_STATE  This instance is in an invalid state. 
	 * @exception   E_SYSTEM         A system error has occurred.
	 * @see         GetTextColor()
	 */
    result SetTextColor(EditTextColor type, const Osp::Graphics::Color& color);

    /**
     * Sets the color of the tokens for the specified status.
     *
     * @since        2.0
     * @return       An error code
     * @param[in]    status              		The status
     * @param[in]    color               		The token color
     * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
     * @exception    E_INVALID_STATE     		This instance is in an invalid state.
     * @exception    E_SYSTEM            		A system error has occurred.
     * @see          GetTokenColor()
     */
    result SetTokenColor(ExpandableEditAreaTokenStatus status, const Osp::Graphics::Color& color);

    /**
     * Sets the text color of the tokens.
     *
     * @since        2.0
     * @return       An error code
     * @param[in]    color               		The token text color
     * @exception    E_SUCCESS           		The method is successful.
     * @exception	 E_UNSUPPORTED_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n 
	 *											The operation is not supported if the style is not EXPANDABLE_EDIT_AREA_STYLE_TOKEN.
     * @exception    E_INVALID_STATE     		This instance is in an invalid state.
     * @exception    E_SYSTEM            		A system error has occurred.
     * @see          GetTokenTextColor()
     */
    result SetTokenTextColor(const Osp::Graphics::Color& color);

    /**
	 * Enables or disables the auto resizing if the candidate word list appears.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   enable            		Set to @c true to enable the auto resizing, @n
	 *										else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      The current style of the %ExpandableEditArea does not support the operation.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state.
	 * @remarks     Note that when this option is enabled, the normal style %ExpandableEditArea is auto resized and the line added and removed events are 
	 *				generated if the candidate word list pop-up appears during the predictive texting. @n
	 *              The operation is not supported by the token style %ExpandableEditArea.
	 * @see         IsAutoResizingEnabled()
	 * @see         Osp::Ui::Controls::IExpandableEditAreaEventListener
	 */
	result SetAutoResizingEnabled(bool enable);

	/**
	 * Checks whether the auto-resizing is enabled.
	 *
	 * @since       2.0
	 * @return      @c true if the auto-resizing is enabled, @n
	 *				else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *										The current style of the %ExpandableEditArea control does not support the operation.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetAutoResizingEnabled()
	 */
	bool IsAutoResizingEnabled(void) const;


// EVENT LISTENER MANAGEMENT
	/**
	 * Adds the specified IExpandableEditAreaEventListener instance. @n
	 * The added listener can listen to events when a line is added or removed or when a button is pressed.
	 *
	 * @since       2.0
	 * @param[in]	listener	The event listener to be added
	 * @see         RemoveExpandableEditAreaEventListener()
	 */
	void AddExpandableEditAreaEventListener(const IExpandableEditAreaEventListener& listener);

	/**
	 * Adds the specified IKeypadEventListener instance. @n
	 * The added listener is notified if the keypad associated with the edit area is opened or closed. 
	 *
	 * @since       2.0
	 * @param[in]	listener	The event listener to be added
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

	/**
	 * Adds the specified ITextBlockEventListener instance. 
	 *
	 * @since       2.0
	 * @param[in]	listener		The event listener to be added
	 * @remarks		Programmatically modifying the text block does not cause the text block selection event to fire. 
	 * @see         RemoveTextBlockEventListener()
	 */
    void AddTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	 /**
	 * Adds the specified ITextEventListener instance. @n
	 * The added listener can listen to the text-changed event.
	 *
	 * @since       2.0
	 * @param[in]	listener		The listener to be added
	 * @see         RemoveTextEventListener()
	 */
    void AddTextEventListener(const Osp::Ui::ITextEventListener& listener);

	/**
	 * Removes the specified IExpandableEditAreaEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 * @param[in]	listener		The event listener to be removed
	 * @see         AddActionEventListener()
	 */
    void RemoveExpandableEditAreaEventListener(const IExpandableEditAreaEventListener& listener);

	/**
	 * Removes the specified IKeypadEventListener listener. @n
	 * The removed listener cannot listen to events when they are fired. 
	 *
	 * @since       2.0
	 * @param[in]	listener		The event listener to be removed
	 * @see         AddKeypadEventListener()
	 */
    void RemoveKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

	/**
	 * Removes the specified ITextBlockEventListener listener. @n
	 * The removed listener cannot listen to events when they are fired. 
	 *
	 * @since       2.0
	 * @param[in]   listener		The event listener to be removed
	 * @see         AddTextBlockEventListener()
	 */
    void RemoveTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified ITextEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since       2.0
	 * @param[in]   listener		The listener to be removed
	 * @see         AddTextEventListener()
	 */
    void RemoveTextEventListener(const Osp::Ui::ITextEventListener& listener);

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
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	friend class ExpandableEditAreaEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
	class ExpandableEditAreaEx* __pExpandableEditAreaEx;

protected:
	friend class ExpandableEditAreaImpl;
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
	class ExpandableEditAreaImpl* GetImpl(void) const;
};

};};};

#endif		// _FUICTRL_EXPANDABLE_EDIT_AREA_H_
