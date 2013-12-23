/* $Change: 995676 $ */
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
* @file		FUiCtrlTimePicker.h 
* @brief	This is the header file for the %TimePicker class.
*
* This header file contains the declarations of the %TimePicker class.
*/
#ifndef _FUICTRL_TIME_PICKER_H_
#define _FUICTRL_TIME_PICKER_H_

#ifdef TimePicker
#undef TimePicker
#endif

// Includes
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiCtrlForm.h"
#include "FUiITimeChangeEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

class __TimePickerEventAdaptor;
class __TimePickerNotifyAdaptor;

/**
* @class	TimePicker
* @brief	This class displays a %TimePicker control on top of the screen.
* @since	1.0
*
* The %TimePicker class displays a full screen window-based selector which allows the user to select a certain time.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimeimePicker</a>.
*
* The following example demonstrates how to use the %TimePicker class.
*
* @code

// Sample Code for TimePickerSample.h
#include <FUi.h>

class TimePickerSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::ITimeChangeEventListener,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON  = 101;

public:
    TimePickerSample(void)
    :__pTimePicker(null){}

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnTimeChanged(const Osp::Ui::Control& source, int hour, int minute);
    virtual void OnTimeChangeCanceled(const Osp::Ui::Control& source);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
    void ShowTimePicker(bool show);

private:
    Osp::Ui::Controls::TimePicker* __pTimePicker;
};

// Sample Code for TimePickerSample.cpp
#include "TimePickerSample.h"
#include <FGraphics.h>

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
TimePickerSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Button
    Button* pButton = new Button();
    pButton->Construct(Rectangle(50, 50, 150, 150), L"Show TimePicker");
    pButton->SetActionId(ID_BUTTON);
    pButton->AddActionEventListener(*this);
    AddControl(*pButton);

    // Creates a TimePicker
    __pTimePicker = new TimePicker();
    __pTimePicker->Construct();

    // Adds a TimeChangeEvent listener
    __pTimePicker->AddTimeChangeEventListener(*this);
    // Shows TimePicker after its owner Form is shown.

    return r;
}

result
TimePickerSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pTimePicker;

    return r;
}

// Implements an IActionEventListener
void
TimePickerSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON:
        	ShowTimePicker(true);
            break;

        default:
            break;
    }
}

// Implements an ITimeChangeEventListener
void
TimePickerSample::OnTimeChanged(const Control& source, int hour, int minute)
{
    // To do:
}

void
TimePickerSample::OnTimeChangeCanceled(const Control& source)
{
    // To do:
}

void
TimePickerSample::ShowTimePicker(bool show)
{

	// Calls Show() of the control
	if (show == true)
		__pTimePicker->Show();
	// Calls Show() of the container
	else
		Show();
}

* @endcode
**/
class _EXPORT_CONTROLS_ TimePicker :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(TimePicker);

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	TimePicker(void);

	/** 
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~TimePicker(void);

    /**
	 * Adds a time changed event listener instance.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 * @see			ITimeChangeEventListener::OnTimeChanged()
	 * @see			ITimeChangeEventListener::OnTimeChangeCanceled()
	 * @see			RemoveTimeChangeEventListener()
	 */
	void AddTimeChangeEventListener(const Osp::Ui::ITimeChangeEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddTimeChangeEventListener()
	 */
    void RemoveTimeChangeEventListener(const Osp::Ui::ITimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %TimePicker to the current date and time in wall time mode.
	 * 
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompTimePickerConstruct "here".
	 *
	 * @return		An error code
	 * @param[in]	title               The title	 
	 * @exception	E_SUCCESS 		    The method is successful.
	 * @exception	E_INVALID_STATE 	This instance is already constructed.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM		    A system error has occurred.
     * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
   result Construct(const Osp::Base::String& title = L"");
 	
	/**
	 * @page	CompTimePickerConstruct		Compatibility for Construct()
	 *
	 * @section	CompTimePickerConstructIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Initializes this instance of %TimePicker to the current system date and time in Coordinated Universal Time (UTC) mode.
	 *
	 * @section	CompTimePickerConstructResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	 */

	/** 
	 * Gets the current hour value of the %TimePicker control.
	 * The hour value is between @c 0 to @c 23.
	 *
	 * @since		1.0
	 * @return		The current hour value, @n
	 *				else @c -1 if an error occurs	 
	 */
	int GetHour(void) const;

	/** 
	 * Gets the current minute value of the %TimePicker control.
	 * The minute value is between @c 0 to @c 59.
	 *
	 * @since		1.0
	 * @return		The current minute value, @n
	 *				else @c -1 if an error occurs	 
	 */
	int GetMinute(void) const;

	/** 
	 * Gets the current time value of the %TimePicker control.
	 *
	 * @since		1.0
	 * @return		The time value
	 */
	Osp::Base::DateTime GetTime(void) const;

	/**
	 * Sets the 12H or 24H hour display type of the %TimePicker control.
	 *
	 * @since		1.0
	 *
	 * @param[in]	enable		Set to @c true to enable the 24 hour notation, @n
	 *							else @c false
	 */
	void Set24HourNotationEnabled(bool enable);

	/** 
	 * Sets the hour value.
	 * The hour value should be between @c 0 and @c  23.
	 * 
	 * @since		1.0
	 * @param[in]	hour	        The hour value
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The given hour value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHour(int hour);

	/** 
	 * Sets the minute value.
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since		1.0
	 * @param[in]	minute          The minute value
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The given minute value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetMinute(int minute);

	/**
	 * Sets the current time value of the %TimePicker control.
	 *
	 * @since		1.0
	 * @param[in]	time	The time to be set
	 */
	void SetTime(const Osp::Base::DateTime& time);

	/**
	 * Sets the time value of the %TimePicker control with the current system time in the Coordinated Universal Time (UTC) mode.
	 *
	 * @since		1.0
	 */
	void SetCurrentTime(void);

	/**
	 * Shows the %TimePicker control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE 	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			The method has failed.
	 * @remarks		When a %TimePicker control is displayed, it becomes the current form of the frame.
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
	 * @since	1.0
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
	 * @since	1.0
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
	 * @since	1.0
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
	 * @since	1.0
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
	 * @since	1.0
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
	 * @since	1.0
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
	result Dispose(void);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the control at the end of the list maintained by this container.
	 * @since	1.0
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 * @since	1.0
	 */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
	 * @since	1.0
	 */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes all controls from this container.
	 * @since	1.0
	 */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (E_UNSUPPORTED_OPERATION) Gets the control with the specified name. @n
	 * Error code can be received using the GetLastResult() method.
	 *
	 * @since		1.0
	 * @return      The control having the specified name @n
	 *              @c null, if the name is not valid
	 * @param[in]	name        The name of the control
	 * @param[in]	recursive   Set to @c true to find a match recursively @n 
	 *							 @c false, otherwise
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the control at the specified index of the list that are kept by this container.
	 *
	 * @since		1.0
	 */
	virtual Control* GetControl(int index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns the number of the controls in this container.
	 *
	 * @since		1.0
	 */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) This method returns a list of controls of this container.
	 *
	 * @since		1.0
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
	 *
	 * @since		1.0
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 *
	 * @since		1.0
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
	 *
	 * @since		1.0
	 */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the specified control to this container.
	 *
	 * @since		1.0
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
	 *
	 * @since		1.0
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
	 *
	 * @since		1.0
	 */
	virtual result RemoveNotify(void);

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
	 * @param[in]	state			Set to @c true to enable the show state, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Although this method is invoked, the control is not drawn or shown. @n
	 *				To draw and show a control, use the Draw() and Show() methods. @n
	 *				Once the control's show state is set to @c false, you need to set show state to @c true again before you draw and show.
	 * @see			GetShowState(), Draw(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

private:
	// Attributes
	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * time value of this TiemPicker.
	 */
	Osp::Base::DateTime __dateTime;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * Event adaptor of this TiemPicker.
	 */
	void* __pTimePickerNotifyAdaptor;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * Event of this TiemPicker.
	 */
	Osp::Base::Runtime::IEvent* __pTimeChangeEvent;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * 24 hour notation flag of this TiemPicker.
	 */
	bool __b24HourNotation;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 */
	Form* __pForm;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * The internal Frame.
	 */
	Form* __pPrevForm;

	/**
	 * @internal
	 * This value is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this value.
	 *
	 * The title value.
	 */
	Osp::Base::String __title;


private:
	friend class __TimePickerNotifyAdaptor;

private:
	friend class TimePickerEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class TimePickerEx*	__pTimePickerEx;

protected:
	friend class TimePickerImpl;
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
	class TimePickerImpl* GetImpl(void) const;
};

};};};

#endif		// _FUICTRL_TIME_PICKER_H_
