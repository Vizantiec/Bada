/* $Change: 1037339 $ */
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
* @file		FUiCtrlMessageBox.h
* @brief	This is the header file for the %MessageBox class.
*
* This header file contains the declarations of the %MessageBox class.
*/
#ifndef _FUICTRL_MESSAGE_BOX_H_
#define _FUICTRL_MESSAGE_BOX_H_

#ifdef MessageBox
#undef MessageBox
#endif

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseString.h"
#include "FUiWindow.h"
#include "FGrpBitmap.h"


namespace Osp { namespace Base      { class String ; }; };
namespace Osp { namespace Graphics  { class Bitmap ; }; };

namespace Osp { namespace Ui { namespace Controls {


	/**
	 * @enum	MessageBoxStyle
	 * Defines the %MessageBox style.
	 *
	 * @since 	1.0
	 */
	enum MessageBoxStyle
	{
		MSGBOX_STYLE_NONE,			        /**< The message box with no push buttons: NONE */
		MSGBOX_STYLE_OK,                 	/**< The message box with one push button: OK */
		MSGBOX_STYLE_CANCEL,             	/**< The message box with one push button: CANCEL */
		MSGBOX_STYLE_OKCANCEL,           	/**< The message box with two push buttons: OK and CANCEL */
		MSGBOX_STYLE_YESNO,              	/**< The message box with two push buttons: YES and NO */
		MSGBOX_STYLE_YESNOCANCEL,       	/**< The message box with three push buttons: YES, NO and CANCEL */
		MSGBOX_STYLE_ABORTRETRYIGNORE,   	/**< The message box with three push buttons: ABORT, RETRY, and IGNORE */
		MSGBOX_STYLE_CANCELTRYCONTINUE,  	/**< The message box with three push buttons: CANCEL, TRY, and CONTINUE */
		MSGBOX_STYLE_RETRYCANCEL        	/**< The message box with two push buttons: RETRY and CANCEL */
	};


	/**
	 * @enum	MessageBoxModalResult
	 * Defines the %MessageBox notifications.
	 *
	 * @since	1.0
	 */
	enum MessageBoxModalResult
	{

		MSGBOX_RESULT_CLOSE,			/**< The message box is closed */
		MSGBOX_RESULT_OK,			    /**< The OK button is selected */
		MSGBOX_RESULT_CANCEL,			/**< The cancel button is selected */
		MSGBOX_RESULT_YES,			    /**< The Yes button is selected */
		MSGBOX_RESULT_NO,			    /**< The No button is selected */
		MSGBOX_RESULT_ABORT,			/**< The Abort button is selected */
		MSGBOX_RESULT_TRY,			    /**< The Try button is selected */
		MSGBOX_RESULT_RETRY,			/**< The Retry button is selected */
		MSGBOX_RESULT_IGNORE,			/**< The Ignore button is selected */
		MSGBOX_RESULT_CONTINUE,			/**< The Continue button is selected */
	};


/**
* @class	MessageBox
* @brief	This class implements a message box.
* @since	1.0
*
* The %MessageBox class displays a confirmation message when the user is asked to confirm an action, or a warning message when the
* user wants to continue a potentially dangerous action. It can also display information, question, alarm, and lock messages, or
* the user selections. 
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_popup_messagebox.htm">Popup and MessageBox</a>.
*
* The following example demonstrates how to use the %MessageBox class.
*
* @code

// Sample Code for MessageBoxSample.h
#include <FUi.h>

class MessageBoxSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
public:
    void DoSomething(void);

protected:
    static const int ID_BTN_DO_SOMETHING = 101;

public:
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

// Sample Code for MessageBoxSample.cpp
#include "MessageBoxSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
MessageBoxSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Button to do something
	Button* pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 280, 60), L"Do something");
	pButton->SetActionId(ID_BTN_DO_SOMETHING);
	pButton->AddActionEventListener(*this);
	AddControl(*pButton);

    return r;
}

void
MessageBoxSample::DoSomething(void)
{
	MessageBox messageBox;
	messageBox.Construct(L"My MessageBox", L"This is MessageBox Sample Code.", MSGBOX_STYLE_OK, 3000);

	// Calls ShowAndWait - draw, show itself and process events
	int modalResult = 0;
	messageBox.ShowAndWait(modalResult);

	switch(modalResult)
	{
	case MSGBOX_RESULT_OK:
		// Todo:
		break;

	default:
		break;
	}
}

void
MessageBoxSample::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BTN_DO_SOMETHING:
		DoSomething();
		break;
	}
}

* @endcode
*/
class _EXPORT_CONTROLS_ MessageBox :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(MessageBox);
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	 MessageBox(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~MessageBox(void);

	/**
	 * Initializes this instance of %MessageBox with the specified parameters.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompControlConstruct20 "here".
	 *
	 * @return		An error code
	 * @param[in]	title				The title string to be set
	 * @param[in]	text				The text string to be set
	 * @param[in]	style				The style of the %MessageBox control
	 * @param[in]	timeout				The duration of the timeout in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c text is too long.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @remarks		To create a %MessageBox control, call ShowAndWait() after the Construct() method is called. @n
	 *				The message box text cannot contain over @c 399 characters. @n
	 *				To display the text in multi-lines or to denote the end of line use '\\n'. @n
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			ShowAndWait()
	 */
	result Construct(const Osp::Base::String& title, const Osp::Base::String& text, MessageBoxStyle style, unsigned long timeout = 0);

// Operation
public:
	/**
	 * Runs the modal window. @n
	 * This method should be called only after calling the Construct() method.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out] 	modalResult		The %MessageBox notification
	 * @exception	E_SUCCESS	    The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
     * @remarks   	Do not call this method from Osp::App::Application::OnAppInitializing. @n
	 *				To show a MessageBox properly from Osp::Ui::Controls::Form::OnInitializing(), the Draw() and Show() methods of the corresponding Form must 
	 *				be called before the ShowAndWait() method is called.
	 */
	virtual result ShowAndWait(int& modalResult);

	/**
	 * Gets the text of the %MessageBox control.
	 *
	 * @since		1.0
	 * @return		The text of this %MessageBox instance, @n 
	 *				else an empty string if the instance is invalid
	 */
	 Osp::Base::String GetText(void) const;

	/**
	 * Gets the title of the %MessageBox control.
	 *
	 * @since		1.0
	 * @return		The title of this %MessageBox instance, @n 
	 *				else an empty string if the instance is invalid
	 */
	Osp::Base::String GetTitleText(void) const;

	/**
	 * Gets the style of the current %MessageBox.
	 *
	 * @since		1.0
	 * @return		The style of the current %MessageBox, @n 
	 *				else @c MSGBOX_STYLE_NONE if the instance is invalid
	 */
	MessageBoxStyle GetMessageBoxStyle(void) const;

// Access
	/**
	 * Gets the timeout value of %MessageBox.
	 *
	 * @since		1.0
	 * @return		The timeout value in milliseconds, @n 
	 *				else @c 0 if the instance is invalid
	 */
	virtual unsigned long GetTimeout(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Draws the control.
	 *
	 * @since			1.0
	 */
	result Draw(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Displays this Control.
	 *
	 * @since			1.0
	 */
	result Show(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since			1.0
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
	 * @since			1.0
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
	 * @since			1.0
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
	 * @since			1.0
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
	 * @since			1.0
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
	 * @since			1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

private:
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
	 * (Blocked) Adds the control at the end of the list maintained by this container.
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes all controls from this container.
	 */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets the control at the specified index of the list that are kept by this container.
	 */
	virtual Control* GetControl(int index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (E_UNSUPPORTED_OPERATION) Gets the control with the specified name. @n
	 * Error code can be received using the GetLastResult() method.
	 *
	 * @return       The control having the specified name @n
	 *               @c null, if the name is not valid
	 * @param[in]	name        The name of the control
	 * @param[in]	recursive   Set to @c true to find a match recursively @n 
	 *			    			 @c false, otherwise
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets the number of the controls in this container.
	 */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets a list of controls of this container.
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets the @c true if the specified control is within
	 * the containment hierarchy of this container. Otherwise, it returns
	 * @c false.
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the specified control to this container.
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
	 */
	virtual result RemoveNotify(void);


private:
// attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Title of this MessageBox
     * @since         1.0
     */			
	Osp::Base::String							__title;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Text of this MessageBox
     * @since         1.0
     */			
	Osp::Base::String							__text;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * During time of this MessageBox
     * @since         1.0
     */			
	unsigned long									__timeout;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * MessageBox Style of this MessageBox
     * @since         1.0
     */			
	MessageBoxStyle		__messageBoxStyle;


private:
	friend class MessageBoxEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class MessageBoxEx*	__pMessageBoxEx;

protected:
	friend class MessageBoxImpl;
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
	class MessageBoxImpl* GetImpl(void) const;
};			// MessageBox
};};};		// Osp::Ui::Controls
#endif		// _FUICTRL_MESSAGE_BOX_H_
