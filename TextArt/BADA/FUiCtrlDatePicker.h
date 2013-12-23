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
* @file			FUiCtrlDatePicker.h 
* @brief		This is the header file for the %DatePicker class.
*
* This header file contains the declarations of the %DatePicker class.
*/
#ifndef _FUICTRL_DATE_PICKER_H_
#define _FUICTRL_DATE_PICKER_H_

#ifdef DatePicker
#undef DatePicker
#endif

// Includes 
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiIDateChangeEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

class __DatePickerEventAdaptor;
class __DatePickerNotifyAdaptor;
/**
* @class	DatePicker
* @brief	This class displays a full screen %DatePicker on top of the screen.
* @since		1.0
*
* The %DatePicker class displays a full screen window-based selector, which allows the user to select a certain date.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_datepicker.htm">DatePicker, TimePicker, and DateTimePicker</a>.
 *
* The following example demonstrates how to use the %DatePicker class.

*
* @code

// Sample Code for DatePickerSample.h
#include <FUi.h>

class DatePickerSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IDateChangeEventListener,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON  = 101;

public:
	DatePickerSample(void)
	:__pDatePicker(null){}

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnDateChanged(const Osp::Ui::Control& source, int year, int month, int day);
    virtual void OnDateChangeCanceled(const Osp::Ui::Control& source);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
    void ShowDatePicker(bool show);

private:
    Osp::Ui::Controls::DatePicker* __pDatePicker;
};

// Sample Code for DatePickerSample.cpp
#include "DatePickerSample.h"
#include <FGraphics.h>

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
DatePickerSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Button
    Button* pButton = new Button();
    pButton->Construct(Rectangle(50, 50, 150, 150), L"Show DatePicker");
    pButton->SetActionId(ID_BUTTON);
    pButton->AddActionEventListener(*this);
    AddControl(*pButton);

    // Creates a DatePicker
    __pDatePicker = new DatePicker();
    __pDatePicker->Construct();

    // Adds a DateChangeEvent listener
    __pDatePicker->AddDateChangeEventListener(*this);
    // Show DatePicker after it's owner Form is shown.

    return r;
}

result
DatePickerSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pDatePicker;

    return r;
}

// Implements an IActionEventListener
void
DatePickerSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON:
        	ShowDatePicker(true);
            break;

        default:
            break;
    }
}

// Implements an IDateChangeEventListener
void
DatePickerSample::OnDateChanged(const Control& source, int year, int month, int day)
{
    // Todo:
}

void
DatePickerSample::OnDateChangeCanceled(const Control& source)
{
    // Todo:
}

void
DatePickerSample::ShowDatePicker(bool show)
{
    // Changes to desired show state
	__pDatePicker->SetShowState(show);

    // Calls Show() of the control
    if (show == true)
    	__pDatePicker->Show();
    // Calls Show() of the container
    else
    	Show();
}

* @endcode
**/
class _EXPORT_CONTROLS_ DatePicker :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(DatePicker);

public:

	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	DatePicker(void);

	/** 
	*	This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~DatePicker(void);

	/**
	* Adds a data change event listener instance. @n
	* The added listener is called when the date of the DatePicker is changed either through user manipulation or by calling one of its setters.
	*
	* @since		1.0
	* @param[in]	listener	The listener to be added
	* @see			IDateChangeEventListener::OnDateChanged()
	* @see			IDateChangeEventListener::OnDateChangeCanceled()
	* @see			RemoveDateChangeEventListener()
	*/
	void AddDateChangeEventListener(const Osp::Ui::IDateChangeEventListener& listener);

	/**
	* This method removes a date changed event listener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener	The listener to be removed
	* @see			IDateChangeEventListener::OnDateChanged()
	* @see			IDateChangeEventListener::OnDateChangeCanceled()
	* @see			AddDateChangeEventListener()
	*/
	void RemoveDateChangeEventListener(const Osp::Ui::IDateChangeEventListener& listener);

	/**
	* Initializes this instance of %DatePicker with the specified parameter.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                  	For more information, see @ref CompControlConstruct20 "here".
    *
	* @return		An error code
	* @param[in]	title            	The title
	* @exception	E_SUCCESS 		 	The method is successful.
	* @exception 	E_INVALID_STATE 	This instance has already been constructed.
	* @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM		 	A system error has occurred.
    * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	*/
	result Construct(const Osp::Base::String& title = L"");

	/** 
	* Gets the current date value of the %DatePicker control.
	*
	* @since	1.0
	* @return   A %DateTime instance
	*/
	Osp::Base::DateTime GetDate(void) const;

	/** 
	* Gets the current day value of the %DatePicker control. @n
	* The day value is between @c 1 to @c 31.
	*
	* @since	1.0
	* @return	The current day value, @n
	*           else @c -1 if an error occurs
	*/
	int GetDay(void) const;

	/** 
	* Gets the current month value of the %DatePicker control. @n
	* The month value is between @c 1 to @c 12.
	*
	* @since	1.0
	* @return	The current month value, @n
	* 			else @c -1 if an error occurs
	*/
	int GetMonth(void) const;

	/** 
	* Gets the current year value of the %DatePicker control.
	* The year value is between @c 1 to @c 9999.
	*
	* @since	1.0
	* @return	The current year value, @n
	* 			else @c -1 if an error occurs
	*
	*/
	int GetYear(void) const;

	/**
	* Sets the date value of the %DatePicker control. 
	*
	* @since		1.0
	* @param[in] 	date	The date to be set
	*/
	void SetDate(const Osp::Base::DateTime& date);

	/**
	* Sets the date value of the %DatePicker control with the current date.
	*
	* @since		1.0
	*/
	void SetCurrentDate(void);

	/** 
	* Sets the year value. @n
	* The year value should be between @c 1 and @c 9999.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	year	The year value
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified year value is invalid.
	*/
	result SetYear(int year);

	/** 
	* Sets the month value. @n
	* The month value should be between @c 1 and @c 12.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	month	        The month value
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified month value is invalid.
	*/
	result SetMonth(int month);

	/** 
	* Sets the day value. @n
	* The day value should be between @c 1 and @c 31.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	day	            The day value
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c day is invalid.	
	*/
	result SetDay(int day);

	/**
	* Shows the DatePicker control.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM		    The method has failed.
	* @exception 	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, that is, this control cannot be displayed.
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
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	state			The new show state
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		Although this method is invoked, the control is not drawn or shown. @n
	 *						To draw and show a control, use the Draw() and Show() methods.@n
	 *						Once the control's show state is set to @c false, you need to set show state to @c true again before you draw and show.
	 * @see				GetShowState(), Draw(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

	/**
	* Sets the valid year range.
	* The range should be set in between @c 1 and @c 9999.
	*
	* @since			 1.0
	* @return                              An error code
	* @param[in]   minYear                The minimum year for the valid range
	* @param[in]   maxYear                The maximum year for the valid range
	* @exception   	E_SUCCESS			The method is successful.
	* @exception   E_INVALID_ARG          The given year range is invalid.
	* @exception   	E_SYSTEM			A system error has occurred.
	*/
	result SetYearRange(int minYear, int maxYear);

	/**
	* Gets the valid year range.
	*
	* @since			 1.0
	* @return                             An error code
	* @param[out]  minYear                The minimum year for the valid range
	* @param[out]  maxYear                The maximum year for the valid range
	* @exception   	E_SUCCESS			The method is successful.
	* @exception   	E_SYSTEM			A system error has occurred.
	*/
	result GetYearRange(int& minYear, int& maxYear) const;


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
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


private:
	// To prevent using the methods.
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Adds the control at the end of the list maintained by this container.
     * @since       1.0
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since       1.0
     */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since       1.0
     */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Removes all controls from this container.
     * @since       1.0
     */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) This method returns the control at the specified index of the list that are kept by this container.
     * @since       1.0
	 */
	virtual Control* GetControl(int index) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Gets the control with the specified name. @n
	 * Error code can be received using the GetLastResult() method.
	 *
     * @since       1.0
     * @return      The control having the specified name @n
	 *              @c null, if the name is not valid
	 * @param[in]	name        The name of the control
	 * @param[in]	recursive   Set to @c true to find a match recursively @n 
	 *							@c false, otherwise
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) This method returns the number of the controls in this container.
     * @since         1.0
     */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) This method returns a list of controls of this container.
     * @since         1.0
     */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) This method returns @c true if the specified control is within
	 * the containment hierarchy of this container. Otherwise, it returns
	 * @c false.
     * @since         1.0
     */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
     */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
     */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Adds the specified control to this container.
     * @since         1.0
     */
	virtual result AddControlImplAt(const Control& control, int index);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * (Blocked) Notifies this container that it is now added to a control
	 * containment hierarchy.
     * @since         1.0
     */
	virtual result AddNotify(void);

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
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
	 * The Notify event adapter
     * @since         1.0
     */	
	void*	__pDatePickerNotifyEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The date change event
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent*			__pDateChangeEvent;

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
	friend class __DatePickerNotifyAdaptor;
	friend class DatePickerEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
     class DatePickerEx*	__pDatePickerEx;

protected:
	friend class DatePickerImpl;
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
	class DatePickerImpl* GetImpl(void) const;

};

};};};

#endif		// _FUICTRL_DATE_PICKER_H_
