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
 * @file	FUiCtrlScrollPanel.h 
 * @brief	This is the header file for the %ScrollPanel class.
 *
 * This header file contains the declarations of the %ScrollPanel class.
 */
#ifndef _FUICTRL_SCROLL_PANEL_H_
#define _FUICTRL_SCROLL_PANEL_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiCtrlPanel.h"
#include "FUiCtrlInputEnum.h"
#include "FUiCtrlForm.h"
#include "FUiCtrlIScrollEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
* @class	ScrollPanel
* @brief	This class implements a scrollable container class.
* @since	1.0
*
* The %ScrollPanel class is a Panel with automatic scroll bars. 
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_panels.htm">Panels</a>.
*
* The following example demonstrates how to use the %ScrollPanel class.
*
* @code

// Sample code for ScrollPanelSample.h
#include <FUi.h>

class ScrollPanelSample : public Osp::Ui::Controls::Form
{
public:
    virtual result OnInitializing(void);
};

// Sample code for ScrollPanelSample.cpp
#include "ScrollPanelSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
ScrollPanelSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a ScrollPanel
    ScrollPanel* pScrollPanel = new ScrollPanel();
    pScrollPanel->Construct(Rectangle(100, 250, 300, 300));

    Button* pButton = new Button();
    pButton->Construct(Rectangle(0, 0, 150, 80));
    pScrollPanel->AddControl(*pButton);

    EditField* pEdit = new EditField();
    pEdit->Construct(Rectangle(0, 100, 150, 80));
    pScrollPanel->AddControl(*pEdit);

    // Adds a ScrollPanel to the Form
    AddControl(*pScrollPanel);

    // Note: Using the 'delete' keyword causes a memory access crash.
    // Calls RemoveControl(const Control& control) instead.

    return r;
}

* @endcode
*/
class _EXPORT_CONTROLS_ ScrollPanel :
	public Osp::Ui::Controls::Panel
{
	DECL_CLASSTYPE(ScrollPanel);
// Lifecycle
public:

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */	
	ScrollPanel(void);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */	
	virtual ~ScrollPanel(void);


	/**
	 * Adds a listener instance that listens to the state changes of a scroll event. @n
	 * The added listener can listen to the events on the given event dispatcher's context when they are fired.
	 *
	 * @since 		2.0
	 * @param[in]	listener	The listener to be added
	 * @see			IScrollEventListener::OnScrollEndReached()
	 * @see			RemoveScrollEventListener()
	 */
	void AddScrollEventListener(const IScrollEventListener& listener);


	/**
	 * Removes a listener instance that listens to the state changes of a scroll event. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since 		2.0
	 * @param[in]   listener	The listener to be removed
	 * @see			IScrollEventListener::OnScrollEndReached()
	 * @see			AddScrollEventListener()
	 */
	void RemoveScrollEventListener(const IScrollEventListener& listener);


	/**
	 * Adds the control at the end of the list maintained by the container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control         	The control to be added to the container
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_ARG   	The specified input parameter is invalid. @n
	 *                              	The specified @c control is an instance of Window, or the parent container of this control.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_MAX_EXCEEDED		The number of child controls has exceeded the maximum limit.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks  	When the control is added, it is placed at the top of the z-order hierarchy of its sibling controls, which means it is drawn last. @n
	 *			 	A control can be displayed only after it has been added to a container that can be displayed. @n
	 *			 	The added control is deleted automatically when its parent container is destroyed. @n
	 *			 	Some methods may not work normally if a method of the control is called before the control gets added to a container. After the control 
	 *				is added to a container, the OnInitializing() method of the control is invoked to carry out the initialization of the control such as 
	 *				creating and adding child controls.
	 * @see   	 	Osp::Ui::Control::OnInitializing()
	 * @see   	 	Osp::Ui::Control::OnTerminating()
	 */
	virtual result AddControl(const Control& control);


	/**
	 * Initializes this instance of %ScrollPanel with the specified rectangular region.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref CompControlConstruct20 "here".
	 * @return		An error code
	 * @param[in]	rect		    	The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_STATE 	This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			Osp::Ui::Container
	 */
	result Construct(const Osp::Graphics::Rectangle& rect);
	
	
	/**
	 * Initializes this instance of %ScrollPanel with the specified layout and rectangular region.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		When the layout already bound to another container is assigned again, E_INVALID_ARG occurs.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			Osp::Ui::Container
	 */
	result Construct(const Osp::Ui::Layout& layout, const Osp::Graphics::Rectangle& rect);

	
	/**
	 * Initializes this instance of %ScrollPanel with the specified layouts and rectangular region.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception 	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks		When the layout already bound to another container is assigned again, E_INVALID_ARG occurs.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			Osp::Ui::Container
	 */
	result Construct(const Osp::Ui::Layout& portraitLayout, const Osp::Ui::Layout& landscapeLayout, const Osp::Graphics::Rectangle& rect);


	/**
	 * Gets the vertical scroll position.
	 *
	 * @since		1.0
	 * @return		The vertical scroll position
	 */
	int GetScrollPosition(void) const;


	/**
	 * Sets the vertical scroll position.
	 *
	 * @since		1.0
	 * @param[in]	position	The vertical scroll position
	 */
	void SetScrollPosition(int position);

	
	/**
	 * Scrolls to the bottom of %ScrollPanel.
	 *
	 * @since		1.0
	 */
	void ScrollToBottom(void) const;


	/**
	 * Scrolls to the top of %ScrollPanel.
	 *
	 * @since		1.0
	 */
	void ScrollToTop(void) const;


	/**
	 * Closes the overlay Window for supporting the overlay keypad.
	 *
	 * @since		1.0
	 * @exception	E_SUCCESS		The method is successful.	
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result CloseOverlayWindow(void);


	/** 
	 * Removes the specified control from this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control			    The child control to be removed
	 * @exception	E_SUCCESS		    The method is successful.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c control is not found within this container.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 */
	virtual result RemoveControl(const Control& control);


	/** 
	 * Removes the specified control from the panel.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index				The index of the control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c control is not found within this container.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result RemoveControl(int index);


	/**
	 * Gets the bounds of the client area.
	 *
	 * @since		1.0
	 * @return		The bounds of the client area
	 *
	 */
	Osp::Graphics::Rectangle GetClientAreaBounds(void) const;


	// Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control					The control to add to this container
	 * @param[in]	index					The z-order index of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. (that is, @c control is 
	 *										an instance of Window or this control's parent container).
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
	 * Notifies this container that it is now added to a control
	 * containment hierarchy.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error occurred.
	 * @exception	E_INVALID_OPERATION	This container is currently assigned to a native peer window.
	 * @remarks		When this method is called, the notified containers also notify the information to all their child controls.
	 * @see			Osp::Ui::Control::AddNotify()
	 */
	virtual result AddNotify(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	* Frees the resources allocated by this %container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	Could not free resources possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The vertical scroll position.
     * @since       1.0
	 */
	int __position;


private:
	friend class ScrollPanelEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class ScrollPanelEx*	__pScrollPanelEx;

protected:
	friend class ScrollPanelImpl;
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
	class ScrollPanelImpl* GetImpl(void) const;

};// ScrollPanel
}; }; }; // Osp::Ui::Controls
#endif// _FUICTRL_SCROLL_PANEL_H_

