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
 * @file		FUiCtrlFrame.h
 * @brief	This is the header file for the %Frame class.
 *
 * This header file contains the declarations of the %Frame class.
 */
#ifndef _FUICTRL_FRAME_H_
#define _FUICTRL_FRAME_H_

// Includes
#include "FBaseTypes.h"
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiIOrientationEventListener.h"
#include "FUiCtrlIFrameEventListener.h"
#include "FUiCtrlMessageBox.h"
#include "FUiCtrlPopup.h"

// Forward declarations
namespace Osp	{ namespace Base { class String; }; };
namespace Osp	{ namespace Graphics { class Rectangle; }; };
namespace Osp	{ namespace Graphics { class Bitmap; }; };
////////////
namespace Osp { namespace Ui { namespace Controls { class Form; }; }; };
namespace Osp { namespace Ui { namespace Controls { class Keypad; }; }; };
namespace Osp { namespace Ui { namespace Controls { class ContextMenu; }; }; };
namespace Osp { namespace Ui { namespace Controls { class OptionMenu; }; }; };
namespace Osp { namespace Ui { namespace Animations{ class FrameAnimator; }; }; };

namespace Osp { namespace App { class __AppFrameShp; }; };

namespace Osp { namespace Ui { namespace Controls {
/**
 * @class	Frame
 * @brief	This class provides the main frame window for an application.
 * @since	1.0
 *
 * The %Frame class provides the main frame window for an application.
 * A frame is the main top-level window of an application. It is the ultimate parent 
 * of all application controls.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_frame.htm">Frame</a>.
 *
 * The following example demonstrates how to use the %Frame class
 *
 * @code

	// Gets a frame pointer
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

	// Creates a Canvas
	Canvas* pCanvas = new Canvas();
	pCanvas->Construct();
	pCanvas->DrawText(Point(30, 30), L"FrameSample");

	// Calls Draw() and Show()
	pFrame->Draw();
	pFrame->Show();

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Frame :
// 	public Osp::Ui::IFrame,
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(Frame);
public:
// Lifecycle
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Frame(void);


	/**
	 *	This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Frame(void);


	/**
	 * Initializes this instance of %Frame with the specified parameter.
	 *
	 * @since		1.0
	 * @return      An error code
	 * @param[in]	screenType          The screen to which the %Frame control belongs
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that
	 *									is, the method is called on an instance that is constructed).
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED      The number of Frames and Forms exceeds the system limitation.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks	The number of frames and forms in total that an application can construct is limited to @c 30.
	 */
	result Construct(ScreenType screenType = SCREEN_0);


// Operation
public:
	/**
	 * Adds an IOrientationEventListener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 * @remarks 	When OnOrientationChanged() event is fired, re-position and draw the child controls, but do not explicitly call
	 *				the Show() method.
	 * @see			RemoveOrientationEventListener()
	 */
	void AddOrientationEventListener(const Osp::Ui::IOrientationEventListener& listener);


	/**
	 * Adds an IFrameEventListener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 * @see			RemoveFrameEventListener()
	 */
	void AddFrameEventListener(const Osp::Ui::Controls::IFrameEventListener& listener);


	/**
	 * Shows the %Frame control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation (that is, this %Frame cannot be displayed).
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result Show(void);


	/**	
	 * Removes the specified Form control from the %Frame control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control				The %Form control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range (that is, the @c control is
	 *								not found).
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result RemoveControl(const Control& control);


	/**
	 * Removes the %Form control present at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index			The index of the %Form control to be removed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual result RemoveControl(int index);


	/**
	 * Removes an IOrientationEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddOrientationEventListener()
	 */
	void RemoveOrientationEventListener(const Osp::Ui::IOrientationEventListener& listener);


	/**
	 * Removes an IFrameEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 		The listener to be removed
	 * @see			AddFrameEventListener()
	 */
	void RemoveFrameEventListener(const Osp::Ui::Controls::IFrameEventListener& listener);

// Accessor
public:
	/**
	 * Gets the current %Form control of the %Frame control.
	 *
	 * @since		1.0
	 * @return		The current %Form, @n
	 *				else @c null if there is no %Form
	 * @see			SetCurrentForm()
	 */
	Form* GetCurrentForm(void) const;


	/**
	 * Sets the specified %Form control as the current %Form of the %Frame control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	form			The form to be set as the current form of the %Frame control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *								The specified @c form is not a child control of the %Frame control.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		If a form is set as the current form, it becomes the topmost form amongst its siblings. @n
	 *         		SetCurrentForm() does not call Draw() and Show() internally, so if the current form needs to be drawn
	 *				immediately, Draw() and Show() should be called after SetCurrentForm().
	 */
	result SetCurrentForm(const Form& form);


	/**
	 * Gets the background color of the %Frame control.
	 *
	 * @since	1.0
	 * @return  The background color of the %Frame control
	 */
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;


	/**
	 * Sets the background color of the %Frame control.
	 *
	 * @since		1.0
	 * @param[in]	color 	The background color
	 */
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);


	/**
	 * Sets the orientation mode of a frame.
	 *
	 * @since		1.0
	 * @param[in] 	orientation		The orientation mode of the %Frame control
	 * @remarks	    To see the change in the orientation mode, the corresponding frame must be the topmost frame in the z-order hierarchy.
	 */
	void SetOrientation(Orientation orientation);


	/**
	 * Gets the orientation mode of the frame.
	 *
	 * @since	1.0
	 * @return  The orientation mode of the frame
	 */
	Osp::Ui::Orientation GetOrientation(void);


	/**
	 * Gets the current orientation status of the frame.
	 *
	 * @since	1.0
	 * @return	The orientation status
	 * @remarks	The method returns ORIENTATION_STATUS_NONE if the %Frame control is not drawn.
	 *          Once it is drawn, the orientation of the %Frame control is set to portrait and the method
	 *          returns ORIENTATION_STATUS_PORTRAIT if the application has not specified its orientation.
	 */
	Osp::Ui::OrientationStatus GetOrientationStatus(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the bidirectional mode for Frame and its children.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	mode         The bidirectional mode
	 * @exception	E_SUCCESS    The method is successful.
	 * @exception	E_SYSTEM     A system error occurred.
	 */
	result SetBidirectionalModeEnabled (bool mode);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the current bidirectional mode for Frame and its children.
	 *
	 * @since	1.0
	 * @return  The current bidirectional mode
	 */
	bool IsBidirectionalModeEnabled(void) const;


	/**
	 * Adds the specified control to the %Frame control. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control         The control to be added to the container
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid (the specified @c control is not a form).
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED	The number of child controls has exceeded the maximum limit.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		A frame can only take instances of %Form as its child. No other type of control can be a child of the %Frame control.
	 *              The added form becomes the top most form of an application.
	 *              The added control is deleted automatically when its parent container is destroyed.
	 */
	virtual result AddControl(const Osp::Ui::Control& control);

	/**
	 * Returns the FrameAnimator of %Frame.
	 *
 	 * @since		2.0
	 * @return		%FrameAnimator, @n
	 *				else @c null if this instance is not constructed as yet
	 */
	Osp::Ui::Animations::FrameAnimator* GetFrameAnimator(void) const;


protected:
// Operation
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to the Frame.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control			        The Form control to add to this container
	 * @param[in]	index			        The index of @c pControl
	 * @exception	E_SUCCESS		        The method is successful.
	 * @exception	E_INVALID_ARG	        A specified input parameter is invalid.
	 *								        The @c pControl is not an instance of Form or Indicator.
	 * @exception	E_SYSTEM		        A system error occurred.
	 * @exception	E_INVALID_OPERATION	    The current state of the instance prohibits the execution of the specified operation (that is, this Control is already bound to a native window).	 
	 */
	virtual result AddControlImplAt(const Osp::Ui::Control& control, int index);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Activates the current Form.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	form			The Form to be activated
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.@n
	 *								The @c form is not the current Form.
	 * @exception	E_SYSTEM		A system error occurred.
	 *
	 */
	result ActivateForm(const Form& form);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the current Form of the Frame.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error occurred.
	 */
	virtual result DrawChildControls(void);


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
	result Dispose(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the Form control at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control			The Form control
	 * @param[in]	index			The index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		The @c control must be first added to this container.
	 * @remarks		To apply the change to be shown, call the Draw() method after this.
	 * @see			Draw(), GetControlAt()
	 */
	virtual result SetControlAt(const Control& control, int index);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the control.
     * @since       1.0
     * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	virtual result __Draw(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetBounds(int x, int y, int width, int height);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetBounds(const Osp::Graphics::Rectangle &rect);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	result AttachWindow(const Window& window);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	result DetachWindow(const Window& window);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	result SetLocation(int x, int y);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetPosition(int x, int y);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetPosition(const Osp::Graphics::Point& Position);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetSize(int width, int height);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	virtual result SetSize(const Osp::Graphics::Dimension &size);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */

	void SetWindowEventReceiver(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         2.0
     */
	void SetUpdateEnabled(bool enable);


// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent*	__pOrientationEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Base::Object *	__pOrientationEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Ui::Orientation __orientation;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Base::Collection::LinkedList __windows;


// Friend class declaration

	/**
	 *	@internal
	 */
	friend class Form;

	/**
	 *	@internal
	 */
	friend class MessageBox;

	/**
	 *	@internal
	 */
	friend class Popup;

	/**
	 *	@internal
	 */
	friend class Keypad;

	/**
	 *	@internal
	 */
	friend class __VirtualEdit;

	/**
	 *	@internal
	 */
	friend class __VirtualDatePicker;

	/**
	 *	@internal
	 */
	friend class __VirtualTimePicker;

	/**
	 *	@internal
	 */
	friend class DatePicker;

	/**
	 *	@internal
	 */
	friend class TimePicker;

	/**
	 *	@internal
	 */
	friend class EditField;

	/**
	 *	@internal
	 */
	friend class EditArea;

	/**
	 *	@internal
	 */
	friend class ContextMenu;

	/**
	 *	@internal
	 */
	friend class OptionMenu;

	/**
	 *	@internal
	 */
	friend class DateTimePicker;

	/**
	 *	@internal
	 */
	friend class __ClipboardPopup;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	bool __enableUpdate;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	int __controlManagerID;

	/**
	 *	@internal
	 */
	friend class Osp::App::__AppFrameShp;
	friend class FrameEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class FrameEx* __pFrameEx;

protected:
	friend class FrameImpl;
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
	class FrameImpl* GetImpl(void) const;

	/* Declarations for %Animation */

private:
	friend class Osp::Ui::Animations::FrameAnimator;

	/* END - Declarations for Animation */


};
}; }; }; // Osp::Ui::Controls
#endif 


