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
* @file			FUiCtrlDateTimePicker.h
* @brief	This is the header file for the %DateTimePicker class.
*
* This header file contains the declarations of the %DateTimePicker class.
*/
#ifndef _FUICTRL_DATETIME_PICKER_H_
#define _FUICTRL_DATETIME_PICKER_H_

#ifdef DateTimePicker
#undef DateTimePicker
#endif

// Includes
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiIDateTimeChangeEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

class __DateTimePickerEventAdaptor;
class __DateTimePickerNotifyAdaptor;

/**
* @class	DateTimePicker
* @brief	This class displays a full screen %DateTimePicker on top of the screen.
* @since		1.0
*
* The %DateTimePicker class displays a full screen window-based selector, which allows the user to select a certain date and time.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 *
* The following example demonstrates how to use the %DateTimePicker class.

*
* @code

// Sample Code for DateTimePickerSample.h
#include <FUi.h>

class DateTimePickerSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IDateTimeChangeEventListener,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON  = 101;

public:
	DateTimePickerSample(void)
	:__pDateTimePicker(null){}

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnDateTimeChanged(const Osp::Ui::Control& source, int year, int month, int day, int hour, int minute);
    virtual void OnDateTimeChangeCanceled(const Osp::Ui::Control& source);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
    void ShowDateTimePicker(bool show);

private:
    Osp::Ui::Controls::DateTimePicker* __pDateTimePicker;
};

// Sample Code for DateTimePickerSample.cpp
#include "DateTimePickerSample.h"
#include <FGraphics.h>

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
DateTimePickerSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Button
    Button* pButton = new Button();
    pButton->Construct(Rectangle(50, 50, 250, 150), L"Show DateTimePicker");
    pButton->SetActionId(ID_BUTTON);
    pButton->AddActionEventListener(*this);
    AddControl(*pButton);

    // Creates a DateTimePicker
    __pDateTimePicker = new DateTimePicker();
    __pDateTimePicker->Construct();

    // Adds a DateTimeChangeEvent listener
    __pDateTimePicker->AddDateTimeChangeEventListener(*this);
    // Shows DateTimePicker after it's owner Form is shown.

    return r;
}

result
DateTimePickerSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pDateTimePicker;

    return r;
}

// Implements an IActionEventListener
void
DateTimePickerSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON:
        	ShowDateTimePicker(true);
            break;

        default:
            break;
    }
}

// Implements an IDateTimeChangeEventListener
void
DateTimePickerSample::OnDateTimeChanged(const Control& source, int year, int month, int day, int hour, int minute)
{
    // Todo:
}

void
DateTimePickerSample::OnDateTimeChangeCanceled(const Control& source)
{
    // Todo:
}



void
DateTimePickerSample::ShowDateTimePicker(bool show)
{
    // Changes to desired show state
	__pDateTimePicker->SetShowState(show);

    // Calls Show() of the control
    if (show == true)
    	__pDateTimePicker->Show();
    // Calls Show() of the container
    else
    	Show();
}

* @endcode
**/
class _EXPORT_CONTROLS_ DateTimePicker :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(DateTimePicker);

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	DateTimePicker(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~DateTimePicker(void);

	/**
	 * Adds the IDateTimeChangeEventListener instance. @n
	 * The added listener gets notified when date or time of the %DateTimePicker instance is changed either by user manipulation or by calling one of its 
	 * setters.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be added
	 * @see			IDateTimeChangeEventListener::OnDateTimeChanged()
	 * @see			IDateTimeChangeEventListener::OnDateTimeChangeCanceled()
	 * @see			RemoveDateTimeChangeEventListener()
	 */
	void AddDateTimeChangeEventListener(const Osp::Ui::IDateTimeChangeEventListener& listener);

	/**
	 * Removes the IDateTimeChangeEventListener instance. @n
	 * The removed listener is not called even when the date and time change events are fired.
	 *
	 * @since		1.0
	 * @param[in]   listener	The listener to be removed
	 * @see			IDateTimeChangeEventListener::OnDateTimeChanged()
	 * @see			IDateTimeChangeEventListener::OnDateTimeChangeCanceled()
	 * @see			AddDateTimeChangeEventListener()
	 */
	void RemoveDateTimeChangeEventListener(const Osp::Ui::IDateTimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %DateTimePicker to the current date and time in the wall time mode.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompDateTimePickerConstruct "here".
	 *
	 * @return	   	An error code
	 * @param[in]  	title				The title
	 * @exception  	E_SUCCESS			The method is successful.
	 * @exception  	E_INVALID_STATE		This instance has already been constructed.
	 * @exception  	E_OUT_OF_MEMORY		The memory is insufficient. 
	 * @exception  	E_SYSTEM			A system error has occurred.
     * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 
	 */
	result Construct(const Osp::Base::String& title = L"");
	
	/**
	 * @page CompDateTimePickerConstruct Compatibility for Construct()
	 * @section CompDateTimePickerConstructIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# Initializes this instance of %DateTimePicker to the current system date and time in the Coordinated Universal Time (UTC) mode.
	 * -#	The method does not return E_INVALID_STATE when the control is already constructed.
	 *
	 * @section CompDateTimePickerConstructResolutions Resolutions
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	 * -# Initializes this instance of %DateTimePicker to the current date and time in the wall time mode.
	 * -#	The method returns E_INVALID_STATE when the control is already constructed.
	 */

	/**
	 *  Sets the date and time value of the %DateTimePicker control.
	 *
	 * @since		1.0
	 * @param[in]	dateTime	The date and time to be set
	 */
	void SetDateTime(const Osp::Base::DateTime& dateTime);

	/**
	 * Sets the date and time value of the %DateTimePicker control with the current date and time in the Coordinated Universal Time (UTC) mode.
	 *
	 * @since		1.0
	 */
	void SetCurrentDateTime(void);

	/**
	 * Sets the year value of the %DateTimePicker control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	year			The year value
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c year value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by SetYearRange().
	 * @remarks		The specified @c year should be in the range set by SetYearRange(). The default year range is from @c 1 to @c 9999.
	 * @see			SetYearRange()
	 */
	result SetYear(int year);

	/**
	 * Sets the month value. @n
	 * The month value should be between @c 1 and @c 12.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	month	The month value
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c month value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetMonth(int month);

	/**
	 * Sets the day value.
	 * The day value should be between @c 1 and @c 31.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	day	 The day value
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c day value is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetDay(int day);
	
	/**
	 * Sets the hour value of the %DateTimePicker control.
	 * The hour value should be between @c 0 and @c 23.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	hour			The hour value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c hour value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result SetHour(int hour);

	/**
	 * Sets the minute value of the %DateTimePicker control.
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	minute		    The minute value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified @c minute value is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	result SetMinute(int minute);

	/**
	 * Gets the current date and time value of the %DateTimePicker control.
	 *
	 * @since		 1.0
	 * @return   The current date and time
	 * @remarks   	This method does not work when %DateTimePicker style is DATETIME_PICKER_STYLE_FROMTO.
	 */
	Osp::Base::DateTime GetDateTime(void) const;

	/**
	 * Gets the current year value of %DateTimePicker. @n
	 * The year value should be between @c 1 to @c 9999.
	 *
	 * @since		1.0
	 * @return	  	The current year value, @n
	 *			  	else @c -1 if an error occurs
	 */
	int GetYear(void) const;

	/**
	 * Gets the current month value of %DateTimePicker. @n
	 * The month value should be between @c 1 to @c 12.
	 *
	 * @since		1.0
	 * @return	  	The current month value, @n
	 *			  	else @c -1 if an error occurs
	 */
	int GetMonth(void) const;

	/**
	 * Gets the current day value of %DateTimePicker. @n
	 * The day value should be between @c 1 to @c 31.
	 *
	 * @since		1.0
	 * @return	  	The current day value , @n
	 *			  	else @c -1 if an error occurs
	 */
	int GetDay(void) const;

	/**
	 * Gets the current hour value of the %DateTimePicker control. @n
	 * The hour value should be between @c 0 to @c 23.
	 *
	 * @since		1.0
	 * @return	  	The current hour value, @n
	 *			  	else @c -1 if an error occurs
	 * @remarks	  	Whether the time display mode is 12-hour or 24-hour, this method always returns the hour value ranging from @c 0 to @c 23.
	 */
	int GetHour(void) const;

	/**
	 * Gets the current minute value of the %DateTimePicker control.
	 *
	 * @since		1.0
	 * @return	  	The current minute value, @n
	 *			  	else @c -1 if an error occurs
	 */
	int GetMinute(void) const;

	/**
	 * Sets the 12-hour or 24-hour display mode of the %DateTimePicker control.
	 *
	 * @since		1.0
	 */
	void Set24HourNotationEnabled(bool enable);

	/**
	 * Checks whether the 24-hour notation is enabled for the %DateTimePicker control. @n
	 * This can be 12-hour or 24-hour mode.
	 *
	 * @since		1.0
	 * @return	@c true if the 24-hour notation is enabled, @n
	 *			else @c false if the 12-hour notation is enabled
	 */
	bool Is24HourNotationEnabled(void) const;

	/**
	 * Sets the valid year range. @n
	 * The range should be set  between @c 1 and @c 9999.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]   minYear                The minimum year for the valid range
	 * @param[in]   maxYear                The maximum year for the valid range
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG          The specified year range is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetYearRange(int minYear, int maxYear);

	/**
	 * Gets the valid year range.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[out]  minYear                The minimum year for the valid range
	 * @param[out]  maxYear                The maximum year for the valid range
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 */
	result GetYearRange(int& minYear, int& maxYear) const;

	/**
	 * Shows the %DateTimePicker control.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE 	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
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
	 *				To draw and show a control, use the Draw() and Show() methods.@n
	 *				Once the control's show state is set to @c false, you need to set show state to @c true again before you draw and show.
	 * @see			GetShowState(), Draw(), Show()
	 *
	 */
	virtual result SetShowState(bool state);


protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window if it is present.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS  The method is successful.
	 * @exception	E_SYSTEM    A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


private:
	// To prevent using the methods.
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
	 *(E_UNSUPPORTED_OPERATION) Gets the control with the specified name. @n
	 * Error code can be received by using the GetLastResult() method.
     * @since         1.0
	 * @return       The control having the specified name @n
	 *               @c null, if the name is not valid
	 * @param[in]	name        The name of the control
	 * @param[in]	recursive   Set to @c true to find a match recursively
     */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

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


private:
	// attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * the data & time value.
     * @since         1.0
     */	
	Osp::Base::DateTime					__dateTime;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Event Adaptor of this DateTimePicker.
     * @since         1.0
     */	
	void*	__pDateTimePickerNotifyEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Event of this DateTimePicker.
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent*	__pDateTimeChangeEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * 24 hour notation flag of this DateTimePicker.
     * @since         1.0
     */	
	bool __24HourNotation;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * AM / PM flag of this DateTimePicker.
     * @since         1.0
     */	
	bool __ampm;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal Form
     * @since         1.0
     */	
	Form*			__pForm;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The previous Form
     * @since         1.0
     */	
	Form* __pPrevForm;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The title value.
     * @since         1.0
     */	
     Osp::Base::String __title;


private:
	friend class __DateTimePickerNotifyAdaptor;
	friend class DateTimePickerEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
     class DateTimePickerEx*	__pDateTimePickerEx;

protected:
	friend class DateTimePickerImpl;
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
	class DateTimePickerImpl* GetImpl(void) const;

};

};};};
#endif		// _FUICTRL_DATETIME_PICKER_H_
