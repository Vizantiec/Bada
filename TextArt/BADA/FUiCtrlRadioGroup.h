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
 * @file	FUiCtrlRadioGroup.h
 * @brief	This is the header file for the %RadioGroup class.
 *
 * This header file contains the declarations of the %RadioGroup class and its helper classes.
 */

#ifndef _FUICTRL_RADIO_GROUP_H_
#define _FUICTRL_RADIO_GROUP_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlCheckButton.h"


namespace Osp { namespace Ui { namespace Controls {

 /**
  * @class	RadioGroup
  * @brief	This class is an implementation of a %RadioGroup control.
  * @since	1.0
  *
  * The %RadioGroup class displays a set of CheckButtons with radio style together in a group, allowing the user to select only
  *  one of the predefined set of buttons.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_button.htm">Buttons</a>.
  *
  * The following example demonstrates how to use the %RadioGroup class.
  *
  * @code
// Sample code for RadioGroupSample.h
#include <FUi.h>

class RadioGroupSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
protected:
    static const int ID_BUTTON1_CHECKED = 101;
    static const int ID_BUTTON1_UNCHECKED = 102;
    static const int ID_BUTTON2_CHECKED = 103;
    static const int ID_BUTTON2_UNCHECKED = 104;

public:
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

// Sample code for RadioGroupSample.cpp
#include "RadioGroupSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
RadioGroupSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates CheckButtons
    CheckButton *pCheckButton1 = new CheckButton();
    pCheckButton1->Construct(Rectangle(10, 50, 460, 100), CHECK_BUTTON_STYLE_RADIO, BACKGROUND_STYLE_DEFAULT, false, L"Radio1");

    CheckButton *pCheckButton2 = new CheckButton();
    pCheckButton2->Construct(Rectangle(10, 160, 460, 100), CHECK_BUTTON_STYLE_RADIO,BACKGROUND_STYLE_DEFAULT, false, L"Radio2");

    pCheckButton1->SetActionId(ID_BUTTON1_CHECKED, ID_BUTTON1_UNCHECKED);
    pCheckButton2->SetActionId(ID_BUTTON2_CHECKED, ID_BUTTON2_UNCHECKED);

    pCheckButton1->AddActionEventListener(*this);
    pCheckButton2->AddActionEventListener(*this);

    // Adds CheckButtons to the Form
    AddControl(*pCheckButton1);
    AddControl(*pCheckButton2);

    // Creates a RadioGroup
    RadioGroup *pGroup = new RadioGroup();
    pGroup->Construct();

    // Adds CheckButtons to the RadioGroup
    pGroup->Add(*pCheckButton1);
    pGroup->Add(*pCheckButton2);

    return r;
}

// Implements an IActionEventListener
void
RadioGroupSample::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
    switch (actionId)
    {
        case ID_BUTTON1_CHECKED:
            // Todo:
            break;
        case ID_BUTTON1_UNCHECKED:
            // Todo:
            break;
        case ID_BUTTON2_CHECKED:
            // Todo:
            break;
        case ID_BUTTON2_UNCHECKED:
            // Todo:
            break;
        default:
            break;
    }
}

	* @endcode
	*
	*/
class _EXPORT_CONTROLS_ RadioGroup :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(RadioGroup);
	// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	RadioGroup(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~RadioGroup(void);


	/**
	 * Initializes this instance of %RadioGroup.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *     				For more information, see issues in version @ref CompRadioGroupConstruct "1.1", @ref CompRadioGroupConstruct "1.2" and 
	 *					@ref CompRadioGroupConstruct "2.0"
	 *
	 * @return 		An error code
	 * @exception	E_SUCCESS   		The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM      		A system error has occurred.
	 */
	 result Construct(void);

	/**
	 * @page	CompRadioGroupConstruct	Compatibility for Construct()
	 * @section	CompRadioGroupConstructIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue(s): @n
	 * -# The check status of disabled items of %RadioGroup can be changed when the item is pressed by a user.
	 *
	 * @section	CompRadioGroupConstructResolutions	Resolutions
	 * The issue(s) mentioned above is(are) resolved in bada API version 1.1, and it is recommended to use bada API versions 1.1. or above. @n
	 */

	/**
	 * @page	CompRadioGroupConstruct	Compatibility for Construct()
	 *
	 * @section	CompRadioGroupConstructIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue(s): @n
	 * -# Internally %RadioGroup cannot be focused, so the functions related to the focus are not supported.
	 *
	 * @section	CompRadioGroupConstructResolutions	Resolutions
	 * The issue(s) mentioned above is(are) resolved in bada API version 1.2, and it is recommended to use bada API version 1.2. or above. @n
	 */

	 /**
	  * @page	CompRadioGroupConstruct	Compatibility for Construct()
	  *
	  * @section	CompRadioGroupConstructIssues	Issues
	  * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	  * -# When RadioGroup is constructed its bounds are set to (0,0,1,1) in the bada API version 1.1 and (0,0,2,2) in the bada API version 1.2.
	  *
	  * @section	CompRadioGroupConstructResolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	  * From bada API version 2.0, the bounds of %RadioGroup are set to (0,0,0,0).
	  */

	// Operation
public:
	/**
	 * Adds the check button to the radio group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	checkButton		The %CheckButton instance to be added
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Only CheckButtons whose style is CHECK_BUTTON_STYLE_RADIO or CHECK_BUTTON_STYLE_RADIO_WITH_DIVIDER can be added to %RadioGroup.
	 */
	result Add(const CheckButton& checkButton);

	/**
	 * Removes the check button from the radio group.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	checkButton			The %CheckButton instance to be removed
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The object is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Before removing %CheckButton from its parent container, it should be removed from %RadioGroup.
	 */
	result Remove(const CheckButton& checkButton);

	// Access
public:
	/**
	 * Gets the number of check buttons in the radio group.
	 *
	 * @since	1.0
	 * @return	The number of check buttons in the radio group
	 */
	int GetItemCount(void) const;

	/**
	 * Selects the specified check button in the radio group.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *					For more information, see @ref CompRadioGroupSetSelectedItem "here".
	 * @param[in]		checkButton		The check button to be selected
	 */
	void SetSelectedItem(const CheckButton& checkButton);

	/**
	 * @page	CompRadioGroupSetSelectedItem		Compatibility for SetSelectedItem()
	 * @section	CompRadioGroupSetSelectedItemIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	 * -# The Draw() and Show() methods are called internally in this method. 
	 *
	 * @section	CompRadioGroupSetSelectedItemResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API versions 1.1. or above. @n
	 */

	/**
	 * Gets the selected check button in the radio group.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *               	For more information, see @ref CompRadioGroupGetSelectedItem "here".
	 *
	 * @return	The pointer to the selected check button, @n
	 *			else  @c null if an error occurs or no check button in the radio group is selected
	 *
	 */
	const CheckButton* GetSelectedItem(void) const;

	/**
	 * @page	CompRadioGroupGetSelectedItem	Compatibility for GetSelectedItem()
	 * @section	CompRadioGroupGetSelectedItemIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns the last added check button even if no check button in the radio group is selected.
	 *
	 * @section	CompRadioGroupGetSelectedItemResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0, the method returns @c null when no check button in the radio group is selected. @n
	 */

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Draws the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result Draw(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Shows this control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result Show(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Enables or disables the object depending on the specified value ( @c enabled). @n
	 * Only an enabled object can respond to user input. By default, the object is enabled.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetEnabled(bool enable);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
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
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
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
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
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
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
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
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Sets the show state of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetShowState(bool state);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *	 
	 * (Blocked) Gives the input focus to the control. @n
	 * One should call this method if the control needs to listen to the user input events such as key pressed.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 */
	virtual result SetFocus(void);

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * Frees the resources allocated by this control and destroys its native window if it is present).
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private :
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * array of radio
     * @since       1.0
	 */
	Osp::Base::Collection::ArrayList __checks;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The RadioGroupEventListener.
     * @since       1.0
	 */
	void* __pRadioGroupEventListener;

private:
	friend class RadioGroupEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class RadioGroupEx* __pRadioGroupEx;

protected:
	friend class RadioGroupImpl;
 	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * Gets the implementation instance of this control
     *
     * @since         2.0
     */	
	class RadioGroupImpl* GetImpl(void) const;

};
}; }; };//Osp::Ui::Controls
#endif // _FUICTRL_RADIO_GROUP_H_
