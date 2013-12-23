/* $Change: 995579 $ */
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
* @file		FUiCtrlKeypad.h
* @brief	This is the header file for the %Keypad class.
*
* This header file contains the declarations of the %Keypad class.
*/

#ifndef _FUICTRL_KEYPAD_H_
#define _FUICTRL_KEYPAD_H_

#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiCtrlInputEnum.h"
#include "FUiITextEventListener.h"
#include "FUiCtrlEditEnum.h"

namespace Osp { namespace  Ui { namespace Controls {

/**
* @enum 	KeypadInputModeCategory
* Defines the keypad input mode.
*
* @since		1.0
*/
typedef enum
{
	KEYPAD_MODE_ALPHA		= 0x0001,						/**< The alphabetic input mode */
	KEYPAD_MODE_PREDICTIVE	= 0x0002,						/**< The predictive input mode */
	KEYPAD_MODE_NUMERIC		= 0x0004,						/**< The numeric input mode */
	KEYPAD_MODE_SYMBOL		= 0x0008						/**< The symbolic input mode */
} KeypadInputModeCategory;

/**
* @class	Keypad
* @brief	This class displays a keypad on top of the screen.
* @since	1.0
*
* The %Keypad class displays the full screen keypad without using an EditField or EditArea.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_keypad.htm">Keypad</a>.
*
* The following example demonstrates how to use the %Keypad class.
*
* @code
// Sample Code for KeypadSample.h
#include <FUi.h>

class KeypadSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener,
    public Osp::Ui::ITextEventListener
{
protected:
    static const int ID_BUTTON  = 101;

public:
    KeypadSample(void)
	:__pKeypad(null){}

    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
    virtual void OnTextValueChanged(const Osp::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Osp::Ui::Control& source);
    void ShowKeypad(bool show);

private:
    Osp::Ui::Controls::Keypad *__pKeypad;
};

// Sample Code for KeypadSample.cpp
#include "KeypadSample.h"
#include <FGraphics.h>

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
KeypadSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Button
    Button* pButton = new Button();
    pButton->Construct(Rectangle(50, 50, 150, 150), L"Show Keypad");
    pButton->SetActionId(ID_BUTTON);
    pButton->AddActionEventListener(*this);
    AddControl(*pButton);

    __pKeypad = new Keypad();
    __pKeypad->Construct(KEYPAD_STYLE_NORMAL, KEYPAD_MODE_ALPHA);
    __pKeypad->AddTextEventListener(*this);
    // Shows Keypad after it's owner Form is shown.

    return r;
}


result
KeypadSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pKeypad;

    return r;
}


// Implements an IActionEventListener
void
KeypadSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON:
        	ShowKeypad(true);
            break;

        default:
            break;
    }
}


// Implements an ITextEventListener
void
KeypadSample::OnTextValueChanged(const Control& source)
{
    // Todo:
}

void
KeypadSample::OnTextValueChangeCanceled(const Control& source)
{
    // Todo:
}

void
KeypadSample::ShowKeypad(bool show)
{
    // Changes to desired show state
    __pKeypad->SetShowState(show);

    // Calls Show() of the control
    if (show == true)
    	__pKeypad->Show();
    // Calls Show() of the container
    else
    	Show();
}

* @endcode
*/

class __KeypadEventAdaptor;

class _EXPORT_CONTROLS_ Keypad :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(Keypad);

//Lifecycle
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Keypad(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	~Keypad(void);

// bada API version 2.0
	/**
	 * Initializes this instance of %Keypad with the specified parameters.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   keypadStyle	        The style of %Keypad
	 * @param[in]   limitLength         The limit of the length of text in %EditField
	 * @exception   E_SUCCESS	        The method is successful.
	 * @exception   E_INVALID_STATE     This instance has already been constructed.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or @n 
	 *									the specified @c limitLength is less than or equal to @c 0.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     If the keypad style is set to password, the input mode category is ignored.
	 * @remarks     The orientation mode of the keypad is decided based on the G-sensor value.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
	result Construct(KeypadStyle keypadStyle, int limitLength);

 	/**
	 * Initializes this instance of %Keypad with input styles.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	keypadStyle		    The style of %Keypad
	 * @param[in]	category		    The initial category that the keypad would show first
	 * @param[in] 	limitLength		    The limit of the length of text in %EditField
	 * @exception	E_SUCCESS	        The method is successful.
	 * @exception	E_INVALID_STATE     This instance has already been constructed.
	 * @exception	E_INVALID_ARG	    A specified input parameter is invalid, or @n
	 *									the specified @c limitLength is less than or equal to @c 0.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 * @remarks		If the keypad style is set to password, the input mode category is ignored.
	 * @remarks		The orientation mode of the keypad is decided based on the G-sensor value.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
	result Construct(KeypadStyle keypadStyle, KeypadInputModeCategory category, int limitLength = 100);

	/**
	 * Enables single-line editing.
	 *
	 * @since          2.0
	 * @return         An error code
	 * @param[in]      enabled              		Set to @c true to enable single-line editing, @n
	 *												else @c false
	 * @exception      E_SUCCESS                    The method is successful.
	 * @exception      E_INVALID_STATE              This instance is in an invalid state.
	 * @exception      E_INVALID_OPERATION          The current state of the instance prohibits the execution of the specified operation. @n
	 *                                              The Keypad control is currently visible.
	 * @exception      E_UNSUPPORTED_OPERATION      The current state of the instance does not support the execution of the specified operation. @n
	 *                                              The password style does not support multi-line editing.
	 * @exception      E_SYSTEM                     A system error has occurred.
	 * @remarks        By default, the single line editing is disabled and the Keypad control supports multi-lines (except the password style which only supports single-line editing).
	 */
	result SetSingleLineEnabled(bool enabled);

	/**
	 * Checks whether single-line editing is enabled.
	 *
	 * @since		2.0
	 * @return		@c true if single-line editing is enabled, @n
	 *				else @c false
	 */
	bool IsSingleLineEnabled(void) const;

	/**
	 * Adds a ITextEventListener instance. @n
	 * The added listener can listen to text changed events when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener 	The listener to be added
	 */
	void AddTextEventListener(const Osp::Ui::ITextEventListener& listener);

	/**
	 * Removes a ITextEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener 	The listener to be removed
	 */
	void RemoveTextEventListener(const Osp::Ui::ITextEventListener& listener);

	/**
	 * Shows this %Keypad control. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE 	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception 	E_MAX_EXCEEDED		The total number of Frame, Forms, and full-screen Keypads are exceeding the limit.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	  	One does not have to call Draw() to render Keypad on screen.
 	 */
	virtual result Show(void);

	/**
	 * Gets the text of the %Keypad control.
	 *
	 * @since		1.0
	 * @return		The string value
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Sets the text of the %Keypad control.
	 *
	 * @since		1.0
	 * @param[in]	text	The text to be set
	 */
	void SetText(Osp::Base::String text);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the show state of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	state			The new show state
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		Although this method is invoked, the control is not drawn or shown. @n
	 *				To draw and show a control, use the Draw() and Show() methods. @n
	 *				Once the control's show state is set to @c false, you need to set show state to @c true again before you draw and show.
	 * @see			GetShowState(), Draw(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since		1.0
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since		1.0
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since		1.0
	 */
	virtual result SetPosition(int x, int y);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since		1.0
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since		1.0
	 */
	virtual result SetSize(int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since		1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);


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
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies Ok or Cancel.
     * @since         1.0
	 */
	bool NotifyOKCancel(void* pState, const void* pEvent);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies Ok pressed.
     * @since         1.0
	 */
	bool OKPressed(void);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies Cancel pressed.
     * @since         1.0
	 */
	bool CancelPressed(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the control at the end of the list maintained by this container.
     * @since         1.0
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since         1.0
	 */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since         1.0
	 */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes all controls from this container.
     * @since         1.0
	 */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the control at the specified index of the list that are kept by this container.
     * @since         1.0
	 */
	virtual Control* GetControl(int index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the number of the controls in this container.
     * @since         1.0
	 */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns a list of controls of this container.
     * @since         1.0
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns @c true if the specified control is within
	 * the containment hierarchy of this container. Otherwise, it returns
	 * @c false.
     * @since         1.0
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
	 */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the specified control to this container.
     * @since         1.0
	 */
	virtual result AddControlImplAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Notifies this container that it is now added to a control
	 * containment hierarchy.
     * @since         1.0
	 */
	virtual result AddNotify(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Notifies this containers that it should be disconnected from the current
	 * native peer window.
     * @since         1.0
	 */
	virtual result RemoveNotify(void);


// Attributions.
private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The string value.
     * @since         1.0
     */		
	Osp::Base::String __string;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The previous string value.
     * @since         1.0
     */		
	Osp::Base::String __prevString;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Keypad Input Mode Category value.
     * @since         1.0
     */		
	KeypadInputModeCategory __category;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Keypad style value.
     * @since         1.0
     */		
	KeypadStyle __keypadStyle;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Keypad input string limit length.
     * @since         1.0
     */		
	int __limitLength;

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
	 * The keypad event adapter.
     * @since         1.0
     */		
	void* __pKeypadEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal Form.
     * @since         1.0
     */		
	Form*	__pForm;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The previous Form
     * @since         1.0
     */		
	Form*	__pPrevForm;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The keypad font.
     * @since         1.0
     */		
	int	__keypadFont;


private:
	friend class __KeypadEventAdaptor;
	friend class KeypadEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class KeypadEx*	__pKeypadEx;

protected:
	friend class KeypadImpl;
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
	class KeypadImpl* GetImpl(void) const;
};		// Keypad;
};};};	// OSp::Ui::Controls;

#endif	// _FUICTRL_KEYPAD_H_
