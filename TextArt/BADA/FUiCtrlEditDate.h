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
* @file			FUiCtrlEditDate.h 
* @brief	This is the header file for the %EditDate class.
*
* This header file contains the declarations of the %EditDate class. 
*/
#ifndef _FUICTRL_EDITDATE_H_
#define _FUICTRL_EDITDATE_H_

#ifdef EditDate
#undef EditDate
#endif

// Includes 
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiIDateChangeEventListener.h"
#include "FUiIOrientationEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

class __EditDateEventAdaptor;
class __DatePickerNotifyEventAdaptor;
class __VirtualDatePicker;

/**
* @class	EditDate
* @brief 	This class defines the common behavior of an %EditDate control.
* @since		1.0
*
* The %EditDate class displays a small, fixed-size selector that allows the user to select a date. Unlike the DatePicker, %EditDate can be placed in a container. 
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a>.
*
* The following example demonstrates how to use the %EditDate class.
*
* @code

// Sample Code for EditDateSample.h
#include <FUi.h>

class EditDateSample :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IDateChangeEventListener
{
public:
	virtual result OnInitializing(void);
	virtual void OnDateChanged(const Osp::Ui::Control& source, int year, int month, int day);
	virtual void OnDateChangeCanceled(const Osp::Ui::Control& source);
};

// Sample Code for EditDateSample.cpp
#include "EditDateSample.h"

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
EditDateSample::OnInitializing(void)
{
	result r = E_SUCCESS;

    // Creates an EditDate
    EditDate* pEditDate = new EditDate();
    pEditDate->Construct(Point(0,0));

    // Adds a DateChangeEvent listener
    pEditDate->AddDateChangeEventListener(*this);

    // Adds EditDate to the Form
    AddControl(*pEditDate);

    Draw();
    Show();

	return r;
}

// Implements an IDateChangeEventListener
void
EditDateSample::OnDateChanged(const Osp::Ui::Control& source, int year, int month, int day)
{
	// Todo:
}

void
EditDateSample::OnDateChangeCanceled(const Osp::Ui::Control& source)
{
	// Todo:
}

* @endcode
**/
class _EXPORT_CONTROLS_ EditDate :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(EditDate);

public:

	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	EditDate(void);

	/** 
	*	This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~EditDate(void);

	/**
	* Adds a data change event listener instance. %
	* Added listener is called when the date of the DatePicker is changed either through user manipulation or by calling one of its setters.
	*
	* @since			1.0
	* @param[in]	listener 	The listener to be added
	* @see				IDateChangeEventListener::OnDateChanged()
	* @see				IDateChangeEventListener::OnDateChangeCanceled()
	* @see				RemoveDateChangeEventListener()
	*/
	void AddDateChangeEventListener(const Osp::Ui::IDateChangeEventListener& listener);

	/**
	* This method removes a date changed event listener instance. @n
	* Removed listener cannot listen to events when they are fired.
	*
	* @since			1.0
	* @param[in]	listener	The listener to be removed
	* @see				IDateChangeEventListener::OnDateChanged()
	* @see				IDateChangeEventListener::OnDateChangeCanceled()
	* @see				AddDateChangeEventListener()
	*/
	void RemoveDateChangeEventListener(const Osp::Ui::IDateChangeEventListener& listener);

	/**
	* Initializes this instance of %EditDate with the specified parameter.
	*
	* @since			1.0
	* @compatibility       This method has compatibility issues with different bada API versions. @n
	*                      For more information, see @ref CompEditDateConstruct "2.0".
	* @return			An error code
	* @param[in]	point	        The position of the %EditDate in the container
	* @param[in]	title	        The title
	* @exception	E_SUCCESS 		The method is successful.
	* @exception 	E_INVALID_STATE This instance has already been constructed.
	* @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks		A control is fully usable only after it has been added to a container, therefore, some methods may fail if used earlier.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 
	*/
	result Construct(const Osp::Graphics::Point& point, const Osp::Base::String& title = L"");

	/**
	 * @page   CompEditDateConstruct Compatibility for Construct()
	 *
	 * @section CompEditDateConstructIssues Compatibility Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# On a WVGA screen, the size of %EditDate is 468x76 in portrait orientation, and 468x76 in landscape orientation.
	 *
	 * @section CompEditDateConstructResolutions Resolutions
	 * -# On a WVGA screen, the size of %EditDate is changed to 468x78 in portrait orientation, and 468x78 in landscape orientation. The size in logical 
	 *	  pixel is the same as that on a WVGA screen.
	 */

	/** 
	* Gets the current date value of the %EditDate control.
	*
	* @since		1.0
	* @return		The date value 
	*/
	Osp::Base::DateTime GetDate(void) const;

	/** 
	* Gets the current day value of the %EditDate control. 
	*
	* @since		1.0
	* @return		The current day value as an integer, @n
	*			else @c -1 if the %EditDate instance is not constructed
	*/
	int GetDay(void) const;

	/** 
	* Gets the current month value of the %EditDate control. 
	*
	* @since	1.0
	* @return   The current month value as an integer,  @n
	*			else @c -1 if the %EditDate instance is not constructed
	*/
	int GetMonth(void) const;

	/** 
	* Gets the current year value of the %EditDate control. 
	*
	* @since		1.0
	* @return		The current year value, @n
	*				else @c -1 if the %EditDate instance is not constructed
	*/
	int GetYear(void) const;

	/**
	* Sets the designated time value of the %EditDate control.
	*
	* @since		 1.0
	* @param[in]	date	The date to be set
	*/
	void SetDate(const Osp::Base::DateTime& date);

	/**
	* Sets the value of the %EditDate control using the current system date.
	*
	* @since		1.0
	*/
	void SetCurrentDate(void);

	/** 
	* Sets the year value.
	* The year value should be between @c 1 and @c 9999.
	* 
	* @since			1.0
	* @return			An error code
	* @param[in]	year	        The year to be set
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The given year value is invalid.
	* @exception	E_SYSTEM		A system error has occurred.	
	*/
	result SetYear(int year);

	/** 
	* Sets the month value of the %EditDate control.
	* The month value should be between @c 1 and @c 12.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	month	        The month to be set
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The given month value is invalid.
	* @exception	E_SYSTEM		A system error has occurred.
	*
	*/
	result SetMonth(int month);

	/** 
	* Sets the day value of the %EditDate control.
	* The day value should be between @c 1 and @c 31.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	day				The day to be set
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The given day value is invalid.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	result SetDay(int day);

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
	* Enables the %DatePicker control.
	*
	* @since				1.0
	* @param[in]	enable		Set to @c true to enable the %DatePicker control, @n
	*							else @c false
	*/
	void SetDatePickerEnabled(bool enable);

	/**
	* Checks whether the %DatePicker control is enabled.
	*
	* @since		1.0
	* @return		@c true if the DatePicker control is enabled, @n
	*				else @c false
	*/
	bool IsDatePickerEnabled(void);

	/**
	* Sets the valid year range. @n
	* The range should be set in between @c 1 and @c 9999.
	*
	* @since			 1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*        For more information, see @ref CompEditDateSetYearRange "here".
	* @return                             An error code
	* @param[in]   minYear                The minimum year for the valid range
	* @param[in]   maxYear                The maximum year for the valid range
	* @exception   	E_SUCCESS			The method is successful.
	* @exception   E_INVALID_ARG          The given year range is invalid.
	* @exception   	E_SYSTEM			A system error has occurred.
	*/
	result SetYearRange(int minYear, int maxYear);

	/**
	 * @page       CompEditDateSetYearRange    Compatibility for SetYearRange()
	 *
	 * @section    CompEditDateSetYearRangeIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# When a new range is set, the date is automatically reset to January 1st if the year is changed due to the range change.
	 * -# If the changed year is not a leap year and the current date is February 29th, then the date is reset to January 1st.
	 *
	 * @section    CompEditDateSetYearRangeResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# When a new range is set, the date does not change.
	 * -# If the changed year is not a leap year and the current date is February 29th, then the date is reset to February 28th.
	 *
	 * @par When working with bada API versions prior to @b 2.0
	 * Use the SetMonth() and SetDay() methods to reset the date back to the previously set value.
	 */

	/**
	* Gets the valid year range.
	*
	* @since			 1.0
	* @return                             An error code
	* @param[out]  minYear                The minimum year for the valid range
	* @param[out]  maxYear                The maximum year for the valid range
	* @exception   	E_SUCCESS		The method is successful.
	* @exception   	E_SYSTEM		A system error has occurred.
	*/
	result GetYearRange(int& minYear, int& maxYear) const;

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompEditDateSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]   x               The new x position of the control
	 * @param[in]   y               The new y position of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(int x, int y);

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompEditDateSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]	Position				The new position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
	 * @page   CompEditDateSetPosition	Compatibility for SetPosition()
	 *
	 * @section CompEditDateSetPositionIssues Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# This method does not work in bada API versions prior to 1.2.
	 *
	 * @section CompEditDateSetPositionResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

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
	* @exception	E_SUCCESS The method is successful.
	* @exception	E_SYSTEM A system error occurred.
	 */
	result Dispose(void);

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
	 * Shows the DatePicker.
     * @since       1.0
	 * @return		An error code
	* @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM A system error occurred.
	 */
	result ShowDatePicker(void);

private:
	// attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The date & time value.
     * @since         1.0
     */	
	Osp::Base::DateTime					__dateTime;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The date changed event adapter.
     * @since         1.0
     */	
	void*								__pDateChageEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The date change event.
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent*			__pDateChageEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	void*	__pVirtualDatePicker;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The event adapter.
     * @since         1.0
     */	
	void*		__pEditDateEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Orientation status.
     * @since         1.0
     */	
	Osp::Ui::OrientationStatus __orientationStatus;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The flag indicating whether date picker is enabled.
     * @since         1.0
     */	
	bool __datePickerEnable;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The rotate event adaptor.
     * @since         1.0
     */	
	void*	__pRotateEventAdpator;

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
	friend class __EditDateEventAdaptor;
	friend class __DatePickerNotifyEventAdaptor;
	friend class __VirtualDatePicker;
	friend class EditDateEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class EditDateEx*	__pEditDateEx;

protected:
	friend class EditDateImpl;
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
	class EditDateImpl* GetImpl(void) const;

};

};};};

#endif		// _FUICTRL_EDITDATE_H_
