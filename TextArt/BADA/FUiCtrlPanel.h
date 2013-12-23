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
 * @file	FUiCtrlPanel.h 
 * @brief	This is the header file for the %Panel class.
 *
 * This header file contains the declarations of the %Panel class.
 */
#ifndef _FUICTRL_PANEL_H_
#define _FUICTRL_PANEL_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiContainer.h"
#include "FUiCtrlTableViewStyleEnum.h"

namespace Osp { namespace Base { class String; };};

namespace Osp { namespace Ui { namespace Controls {
/**
* @class	Panel
* @brief	This class provides a %Panel, that is the simplest container.
* @since	1.0
*
* The %Panel class displays a space where other UI elements can be placed. It is a concrete implementation of the Container class.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_panels.htm">Panels</a>.
*
* The following example demonstrates how to use the %Panel class.
*
* @code

// Sample Code for PanelSample.h
#include <FUi.h>

class PanelSample : public Osp::Ui::Controls::Form
{
public:
    virtual result OnInitializing(void);
};

// Sample Code for PanelSample.cpp
#include "PanelSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
PanelSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Panel
    Panel* pPanel = new Panel();
    pPanel->Construct(Rectangle(100, 250, 300, 300));
    pPanel->SetBackgroundColor(Osp::Graphics::Color(0x50, 0xFF, 0x38));

    //Adds a Panel to the Form
    AddControl(*pPanel);

    // Note: Using the 'delete' keyword causes a memory access crash.
    // Calls RemoveControl(const Control& control) instead.

    return r;
}

* @endcode
*/
class _EXPORT_CONTROLS_ Panel :
	public Osp::Ui::Container
{
	DECL_CLASSTYPE(Panel);
// Lifecycle
public:

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */	
	Panel(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */	
	virtual ~Panel(void);

	/**
	 * Initializes this instance of %Panel with the specified parameters.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlConstruct20 "here".
	 * @return		An error code
	 * @param[in]	rect				The location and size of the %Panel control as a Rectangle instance
	 * @param[in]	groupStyle			The group style of the %Panel control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specified group style determines the border look of the %Panel control. 
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see  		Osp::Ui::Container, Osp::Ui::GroupStyle
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);
	
	/**
	 * Initializes this instance of %Panel with the specified parameters.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape modes
	 * @param[in]	rect				The location and size of the %Panel control as an instance of a Rectangle 
	 * @param[in]	groupStyle			The table view style of the %Panel control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE     This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified layout is already bound to another container. 
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specified group style determines the border look of the %Panel control. 
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see  		Osp::Ui::Container, Osp::Ui::GroupStyle
	 */
	result Construct(const Osp::Ui::Layout& layout, const Osp::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * Initializes this instance of %Panel with the specified layouts, rectangular region, and group style.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %Panel control as an instance of a Rectangle
	 * @param[in]	groupStyle			The table view style of the %Panel control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE     This instance has already been constructed.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified layout is already bound to another container. 
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks 	The specified group style determines the border look of the %Panel control. 
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see  		Osp::Ui::Container, Osp::Ui::GroupStyle
	 */
	result Construct(const Osp::Ui::Layout& portraitLayout, const Osp::Ui::Layout& landscapeLayout, const Osp::Graphics::Rectangle& rect, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/** 
	 * Adds the control at the end of the list maintained by this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control				The control to be added to this container
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid @n
	 *									The specified @c control is an instance of Window or the parent container of this control.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The added child control is deleted automatically when its parent container is destroyed.
	 */
	virtual result AddControl(const Control& control);

	/** 
	 * Gets the background color of the %Panel control.
	 *
	 * @since		1.0
	 * @return		The background color
	 */
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;

	/** 
	 * Sets the background color of this control.
	 *
	 * @since	1.0
	 * @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                 For more information, see @ref CompPanelSetBackgroundColor "here".
	 * @param[in]	color	The background color
	 */
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * @page	CompPanelSetBackgroundColor	Compatibility for SetBackgroundColor()
	 * @section	CompPanelSetBackgroundColor	Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# When the group style is applied to %Panel, the method does not work as expected.
	 *
	 * @section	CompProgressSetRangeResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	 * From bada API version 2.0, the SetBackgroundColor() method works as expected when the group style is applied to %Panel.
	 */

	/** 
	 * Removes the specified control from this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control				The child control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range. @n
	 *						        	The specified @c control is not a child control of this container.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result RemoveControl(const Control& control);

	/** 
	 * Removes the specified control from this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index				The index of the control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result RemoveControl(int index);

	/** 
	 * Removes all the controls from this container.
	 *
	 * @since		1.0
	 */
	virtual void RemoveAllControls(void);

	/**
	 * Enables the %Panel control to be composited to the screen buffer.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompPanelSetCompositeEnabled "here". @n
	 * @return		An error code
	 * @param[in]	composite			Set to @c true to make the %Panel control composited to the screen buffer, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_SYSTEM 			A system error occurred.
	 * @remarks 	In case a %Panel is transparent and nothing is drawn on the canvas of the %Panel control, the graphic performance can be improved if the 
	 *				compositing of the %Panel control to the screen buffer is disabled. @n
	 * 				By default, compositing is enabled. For example, if a Form control has a %Panel that has a List, by disabling the compositing of the 
	 *				%Panel, the scroll performance of the %List will improve.
	 */
	result SetCompositeEnabled(bool composite);
	
	/**
	 * @page	CompPanelSetCompositeEnabled	Compatibility for SetCompositeEnabled()
	 * @section	CompPanelSetCompositeEnabledIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the composition is disabled for the ScrollPanel control, the child controls of the %ScrollPanel are not composited to the screen buffer when the 
	 *	  scroll end effect is applied.
	 *
	 * @section	CompPanelSetCompositeEnabledResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	 */

	/**
	 * Checks whether the %Panel control is composited to the screen buffer.
	 *
	 * @since	1.0
	 * @return	@c true if the %Panel control is composited to the screen buffer, @n
	 *			else @c false
	 */
	bool IsCompositeEnabled(void) const;

	/**
	 * Captures the composited scene of the %Panel control.
	 *
	 * @since		1.2
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompPanelGetCapturedBitmapN "here".
	 * @return		A Bitmap instance which captures the current composited scene of the %Panel control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				The method invoked is invalid in this state.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The method is not supported in the following classes that are derived from %Panel class:
	 *				@li OverlayPanel
	 * @remarks		The bounds of the %Panel control must be within the client area of the %Form control to get a valid composited scene.
	 */
	Osp::Graphics::Bitmap* GetCapturedBitmapN(void) const;

	/**
	 * @page	CompPanelGetCapturedBitmapN	Compatibility for GetCapturedBitmapN()
	 * @section	CompPanelGetCapturedBitmapNIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The bitmap size is different from the size of the control captured by this method.
	 *
	 * @section	CompPanelGetCapturedBitmapNResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * -# The bitmap size is the same as the size of the control captured by this method.
	 */
	
	/**
     * Checks whether the specified child control is always at the bottom of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is always set to remain at the bottom of the stack, @n
	 *				else @c false
	 * @param[in]	control          	The child control
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG    	A specified input parameter is invalid. @n
	 *                               	The specified @c control is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysAtBottom()
	 */
	bool IsControlAlwaysAtBottom(const Osp::Ui::Control& control) const;


	/**
	 * Checks whether the specified child control is always at the top of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is always set to remain on top of the stack, @n
	 *				else @c false
	 * @param[in]	control          	The child control
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG    	A specified input parameter is invalid. @n
	 *                                	The specified @c control is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysOnTop()
	 */
	bool IsControlAlwaysOnTop(const Osp::Ui::Control& control) const;


	/**
	 * Sets whether the specified child control should always be above the other children.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          		The child control
	 * @param[in]	alwaysOnTop      		Set to @c true if the @c control should always be on the top, @n
	 *										else @c false
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_INVALID_ARG    		A specified input parameter is invalid. @n
	 *                                		The specified @c control is not a child of this container.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  	The specified @c control is set at the bottom of the drawing stack.
	 * @exception	E_INVALID_STATE 		This instance is in an invalid state.
	 * @remarks		If multiple child controls are set as "always on top", their relative order is not specified. If the specified child control is a 
	 *				container, then all its children inherit this property and they are "always on top" of the other controls. @n
	 *				If this method is called on a child control with a @c false value, then its state becomes normal. The relative order of child controls in 
	 *				normal state is not specified.
	 * @see			IsControlAlwaysOnTop()
	 */
	result SetControlAlwaysOnTop(Osp::Ui::Control& control, bool alwaysOnTop);


	/**
	 * Sets whether the specified child control should always be below other children.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          		The child control
	 * @param[in]	alwaysAtBottom   		Set to @c true if the @c control should always be at the bottom, @n
	 *										else @c false
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_INVALID_ARG    		A specified input parameter is invalid. @n
	 *                                		The specified @c control is not a child of this container.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  	The specified @c control is set on the top of other child controls.
	 * @exception	E_INVALID_STATE  		This instance is in an invalid state.
	 * @remarks		If multiple childs control are set as "always at bottom", then their relative order is not specified. If the specified child control is a 
	 *				container, then all its children inherit this property and they become "always at bottom" as well. @n
	 *				If this method is called on a child control with a @c false value, then its state becomes normal. The relative order of child controls in 
	 *				the normal state is not specified.
	 * @see			IsControlAlwaysAtBottom()
	 */
	result SetControlAlwaysAtBottom(Osp::Ui::Control& control, bool alwaysAtBottom);


// Accessor
	/** 
	 * Gets the control at the specified index of the list that is kept by this container.
	 *
	 * @since		1.0
	 * @return		The control at the specified index, @n
	 *				else @c null if the index is invalid
	 * @param[in]	index		The index of the control
	 */
	virtual Control* GetControl(int index) const;


	/**
	 * Gets the control with the specified name. @n
	 * If there are multiple matches of the name, it returns the first match.
	 *
	 * @since		1.0
	 * @return		The control having the specified name, @n
	 *             	else @c null if the name is not valid
	 * @param[in]	name		The name of the control
	 * @param[in]	recursive	Set to @c true to find a match recursively, @n 
	 *							else @c false
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;


	/** 
	 * Gets a list of controls of this container.
	 *
	 * @since		1.0
	 * @return		An IList instance containing the controls of this container
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;


protected:
// Operation
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to the container
	 *
	 * @since		1.0
	 *
	 * @return		An error code
	 * @param[in]	control					The control to add to this container
	 * @param[in]	index					The z-order index of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid, @n 
	 *							The @c control is an instance of Window or the parent container of this control.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @exception	E_SYSTEM				A system error occurred.
	 */
	virtual result AddControlImplAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the foreground color of this control.
	 *
	 * @since		1.0
	 * @param[in]	color 	The foreground color
	 */
	void SetForegroundColor(const Osp::Graphics::Color& color);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 */
	result __CheckConditionValidate(const Osp::Ui::Control& control) const;
	friend class PanelEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class PanelEx*	__pPanelEx;

protected:
	friend class PanelImpl;
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
	class PanelImpl* GetImpl(void) const;

};// Panel
}; }; }; // Osp::Ui::Controls
#endif// _FUICTRL_PANEL_H_

