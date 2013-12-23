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
* @file			FUiCtrlEditTime.h 
* @brief		This is the header file for the %EditTime class.
*
* This header file contains the declarations of the %EditTime class.
*/
#ifndef _FUICTRL_EDITTIME_H_
#define _FUICTRL_EDITTIME_H_

#ifdef EditTime
#undef EditTime
#endif

// Includes 
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiITimeChangeEventListener.h"
#include "FUiIOrientationEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

class __EditTimeEventAdaptor;
class __TimePickerNotifyEventAdaptor;
class __VirtualTimePicker;
class __TimePickerWindowEventAdaptor;

/**
* @class	EditTime
* @brief    This class defines the common behavior of an %EditTime control.
* @since	1.0
*
* The %EditTime class displays a small, fixed-size selector that allows the user to select a time.
* Unlike TimePicker, %EditTime can be placed in a container.
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_edittime_editdate.htm">EditDate and EditTime</a>.
*
* The following example demonstrates how to use the %EditTime class.
*
* @code

// Sample Code for EditTimeSample.h
#include <FUi.h>

class EditTimeSample :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::ITimeChangeEventListener
{
public:
	virtual result OnInitializing(void);
	virtual void OnTimeChanged(const Osp::Ui::Control& source, int hour, int minute);
	virtual void OnTimeChangeCanceled(const Osp::Ui::Control& source);
};

// Sample Code for EditTimeSample.cpp
#include "EditTimeSample.h"

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
EditTimeSample::OnInitializing(void)
{
	result r = E_SUCCESS;

    // Creates an EditTime.
    EditTime* pEditTime = new EditTime();
    pEditTime->Construct(Point(0,0));

    // Adds a TimeChangeEvent listener.
    pEditTime->AddTimeChangeEventListener(*this);

    // Adds EditTime to the Form.
    AddControl(*pEditTime);

    Draw();
    Show();

    return r;
}

// Implements TimeChangeEventListener.
void
EditTimeSample::OnTimeChanged(const Osp::Ui::Control& source, int hour, int minute)
{
	// Todo:
}

void
EditTimeSample::OnTimeChangeCanceled(const Osp::Ui::Control& source)
{
	// Todo:
}

* @endcode
**/
class _EXPORT_CONTROLS_ EditTime :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(EditTime);

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	EditTime(void);

	/** 
	 *	This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~EditTime(void);

	/**
	 * Adds a time changed event listener instance.
	 *
	 * @since			1.0
	 * @param[in]	listener 	The listener to be added
	 * @see				ITimeChangeEventListener::OnTimeChanged()
	 * @see				ITimeChangeEventListener::OnTimeChangeCanceled()
	 * @see				RemoveTimeChangeEventListener()
	 */
	void AddTimeChangeEventListener(const Osp::Ui::ITimeChangeEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see				AddTimeChangeEventListener()
	 */
	void RemoveTimeChangeEventListener(const Osp::Ui::ITimeChangeEventListener& listener);

	/**
	 * Initializes this instance of %EditTime with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility       This method has compatibility issues with bada API versions. @n
	*                      For more information, see @ref CompEditTimeConstruct "2.0".
	 * @return		An error code
	 * @param[in]	point				The position of %EditTime in container
	 * @param[in]	title			The title
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception 	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 
	 */
	result Construct(const Osp::Graphics::Point& point, const Osp::Base::String& title =  L"");

	/**
	 * @page   CompEditTimeConstruct Compatibility for Construct()
	 * @section CompEditTimeConstructIssues Compatibility Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The method does not return E_INVALID_STATE when the control is already constructed.
	 * -# On a WVGA screen, the size of %EditTime is 468 x 76 in portrait orientation and 468 x 76 in landscape orientation.
	 *
	 * @section CompEditTimeConstructResolutions Resolutions
	 * -#	The method returns E_INVALID_STATE when the control is already constructed.
	 * -# On a WVGA screen, the size of %EditDate is changed to 468 x 78 in a portrait orientation and 468 x 78 in a landscape orientation. The size in 
	 *	  logical pixel is the same as that on a WVGA screen.
	 */

	/** 
	 * Gets the current hour value of the %EditTime control. 
	 *
	 * @since		1.0
	 * @return	The current hour value, @n
	 *			else @c -1 if the %EditTime instance is not constructed @n
	 *			The hour value is between @c 0 to @c 23.
	 */
	int GetHour(void) const;

	/** 
	 * Gets the current minute value of the %EditTime control. 
	 *
	 * @since	1.0
	 * @return	The current minute value, @n
	 *			else @c -1 if this EditTime instance is not constructed
	 */
	int GetMinute(void) const;

	/** 
	 * Gets the current time value of the %EditTime control.
	 *
	 * @since			1.0
	 * @return		The time value
	 */
	Osp::Base::DateTime GetTime(void) const;

	/**
	 * Sets the 12-hour or 24-hour display type of the %EditTime. @n
	 * This can be 12-hour or 24-hour type.
	 *
	 * @since			1.0
	 * @param[in]	enable	Set to @c true to set the 24-hour notation, @n
	 *						else @c false to set the 12-hour notation
	 */
	void Set24HourNotationEnabled(bool enable);

	/** 
	 * Sets the hour value of the %EditTime control. @n
	 * The hour value should be between @c 0 and @c 23.
	 *
	 * @since			1.0
	 * @param[in]	hour			The hour value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified hour value is invalid.	
	 * @exception	E_SYSTEM        A system error has occurred.
	 *
	 */
	result SetHour(int hour);

	/** 
	 * Sets the minute value of the %EditTime control. @n
	 * The minute value should be between @c 0 and @c 59.
	 *
	 * @since			1.0
	 * @param[in]	minute			The minute value to be set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified minute value is invalid.	
	 * @exception	E_SYSTEM        A system error has occurred.
	 *
	 */
	result SetMinute(int minute);

	/**
	 * Sets the designated time value of the %EditTime control.
	 *
	 * @since			1.0
 	 * @param[in]	time	The time to be set
	 */
	void SetTime(const Osp::Base::DateTime& time);

	/**
	 * Sets the value of the %EditTime control using the current system time.
	 *
	 * @since		1.0
	 */
	void SetCurrentTime(void);

	/**
	 * Enables TimePicker.
	 *
	 * @since				1.0
	 * @param[in]	enable		Set to @c true to enable %TimePicker, @n
	 *							else @c false
	 */
	void SetTimePickerEnabled(bool enable);

	/**
	 * Checks whether TimePicker is enabled.
	 *
	 * @since		1.0
	 * @return	@c true if %TimePicker is enabled, @n
	 *			else @c false
	 */
	bool IsTimePickerEnabled(void);

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompEditTimeSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]   x               The new x position of the control
	 * @param[in]   y               The new y position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent. @n
	 * 				From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(int x, int y);

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompEditTimeSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]	Position				The new position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent. @n
	 *				From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
	 * @page   CompEditTimeSetPosition	Compatibility for SetPosition()
	 * @section CompEditTimeSetPositionIssues Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# This method in bada API versions prior to 1.2 does not work as expected. 
	 *
	 * @section CompEditTimeSetPositionResolutions Resolutions 
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
	 * Shows the TimePicker. @n
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM A system error occurred.
     * @since         1.0
	 */
	result ShowTimePicker(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * 
	 * (Blocked) Sets the position and size of the control.
     * @since         1.0
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * 
	 * (Blocked) Sets the position and size of the control.
     * @since         1.0
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
     * @since         1.0
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
     * @since         1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

private:
	// Attributes
 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The time value of this TiemPicker.
     * @since         1.0
     */
	Osp::Base::DateTime					__dateTime;

 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * boundary of this TiemPicker.
     * @since         1.0
     */
	Osp::Graphics::Rectangle			__bound;

 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Event adaptor of this TiemPicker.
     * @since         1.0
     */
	void*	__pTimeChageEventAdaptor;

 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Event of this TiemPicker.
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent*			__pTimeChageEvent;

 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * 24 hour notation flag of this TiemPicker.
     * @since         1.0
     */
	bool	__b24HourNotation;
	
 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * VirtualTimePicker.
     * @since         1.0
     */
	void*	__pVirtualTimePicker;
	
 	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * VirtualTimePickerAdaptor for touch.
     * @since         1.0
     */
	void*		__pEditTimeEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The orientation status
     * @since         1.0
     */
	Osp::Ui::OrientationStatus __orientationStatus;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The flag indicating whether the time picker is enabled.
     * @since         1.0
     */
	bool __timePickerEnable;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The rotate event adapter
     * @since         1.0
     */
	void*	__pRotateEventAdpator;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The title value
     * @since         1.0
     */
	Osp::Base::String __title;

private:
	friend class __EditTimeEventAdaptor;
	friend class __TimePickerWindowEventAdaptor;
	friend class __TimePickerNotifyEventAdaptor;
	friend class __VirtualTimePicker;
	friend class EditTimeEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class EditTimeEx*	__pEditTimeEx;

protected:
	friend class EditTimeImpl;
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
	class EditTimeImpl* GetImpl(void) const;
};

};};};

#endif		// _FUICTRL_EDITTIME_H_
