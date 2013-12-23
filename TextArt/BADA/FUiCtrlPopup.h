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
 * @file	FUiCtrlPopup.h
 * @brief	This is the header file for the %Popup class.
 *
 * This header file contains the declarations of the %Popup class. @n
 */

#ifndef _FUICTRL_POPUP_H_
#define _FUICTRL_POPUP_H_

#include "FUiCtrlConfig.h"
#include "FBaseString.h"
#include "FUiWindow.h"


namespace Osp { namespace Base { class String ; }; };
namespace Osp { namespace Graphics { class Bitmap ; }; };

namespace Osp { namespace Ui { namespace Controls {

/**
* @class	Popup
* @brief	This class displays a popup on the top of the screen.
* @since	1.0
*
* The %Popup class displays messages to alert the user of important changes, to request confirmation for a significant task, or to
* serve as a warning. It is an implementation of the Window class.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_popup_messagebox.htm">Popup and MessageBox</a>.
*
* @see Osp::Ui::Window 
*
* The following example demonstrates how to use the %Popup class.
*
* @code

// Sample code for PopupSample.h
#include <FUi.h>

class PopupSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
public:
    PopupSample(void)
    :__pPopup(null){}

    void ShowPopup(void);
    void HidePopup(void);

protected:
    static const int ID_BUTTON_OPEN_POPUP = 101;
    static const int ID_BUTTON_CLOSE_POPUP = 102;

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
    Osp::Ui::Controls::Popup* __pPopup;
};

// Sample Code for PopupSample.cpp
#include "PopupSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
PopupSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Popup
    __pPopup = new Popup();
    Dimension dim(400, 400);
    __pPopup->Construct(true, dim);
    __pPopup->SetTitleText(L"Popup Sample");

    // Creates a button to open the Popup.
	Button* pBtnOpen = new Button();
	pBtnOpen->Construct(Rectangle(30, 200, 140, 60), L"Open");
	pBtnOpen->SetActionId(ID_BUTTON_OPEN_POPUP);
	pBtnOpen->AddActionEventListener(*this);
	 __pPopup->AddControl(*pBtnOpen);

    // Creates a button to close the Popup.
    Button* pBtnClose = new Button();
    pBtnClose->Construct(Rectangle(214, 200, 140, 60), L"Close");
    pBtnClose->SetActionId(ID_BUTTON_CLOSE_POPUP);
    pBtnClose->AddActionEventListener(*this);
    __pPopup->AddControl(*pBtnClose);

    return r;
}

result
PopupSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pPopup;

    return r;
}

void
PopupSample::ShowPopup(void)
{
	__pPopup->SetShowState(true);
	__pPopup->Show();
}

void
PopupSample::HidePopup(void)
{
	__pPopup->SetShowState(false);
	Draw();
	Show();
}

void
PopupSample::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_OPEN_POPUP:
		ShowPopup();
		break;

	case ID_BUTTON_CLOSE_POPUP:
		HidePopup();
		break;
	}
}

* @endcode
*/

class _EXPORT_CONTROLS_ Popup :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(Popup);
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	*/
	Popup(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Popup(void);

	/**
	* Initializes this instance of %Popup with the specified dimensions.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 					For more information, see @ref CompPopupConstructBounds20 "here".
	*
	* @return		An error code
	* @param[in]	hasTitle			Set to @c true if the %Popup control has a title, @n
	*									else @c false
	* @param[in]	dim			    	The size of the %Popup control
	* @exception	E_SUCCESS	    	The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM	    	A system error has occurred.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">Control Size</a>.
	*/
	result Construct(bool hasTitle, const Osp::Graphics::Dimension& dim);

	/**
	 * @page CompPopupConstructBounds20 Compatibility for Construct()
	 *
	 * @section	CompPopupConstructBounds20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The %Popup control does not return E_INVALID_STATE when the control is already constructed. @n
	 * -# The %Popup control does not return E_OUT_OF_MEMORY when the control fails to allocate internal resources. @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size. @n
	 * -# The %Popup control returns E_INVALID_ARG when the size of the control is greater than the screen size. @n
	 * -# On a WVGA screen, the default minimum size is 388 x 130.
	 *
	 * @section	CompPopupConstructBounds20Resolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The method returns E_INVALID_STATE when the control is already constructed. @n
	 * -# The method returns E_OUT_OF_MEMORY when the control fails to allocate internal resources. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control. @n
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0. @n
	 * -# The maximum size limit of the %Popup control has been removed. @n
	 * -# On a WVGA screen, the default minimum sizes are changed to 384 x 126. The default minimum sizes in logical pixel are the same as those on a WVGA 
	 *	  screen.
	 */

	/**
	* Initializes this instance of %Popup with the specified resource ID. @n
	*
    * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. @n
    * If it fails to find the resource file, it searches in other folders in the following order when AutoScaling is enabled: @n
	* the folder that corresponds to the current screen resolution and the ScreenSize-Normal folder.
    * 
    *
	* @since	  1.0
	*
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    * For more information, see @ref CompPopupConstruct20 "here".
 	*
	* @return	  An error code
	* @param[in]  resourceId		The resource ID describing the %Popup control
    * @exception  E_SUCCESS			The method is successful.
    * @exception  E_FILE_NOT_FOUND	The specified file cannot be found.
    * @exception  E_OUT_OF_MEMORY	The memory is insufficient.
    * @exception  E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
    * @exception  E_SYSTEM           A system has error occurred, or an error has occurred during resource file loading.
    * @remarks    The method returns the E_PRIVILEGE_DENIED exception if the specified resource contains the Flash, Map, or Web control
    *             and the application does not have the privilege to use the control.
	* @see        Osp::Ui::Controls::Flash, Osp::Locations::Services::ProviderManager, Osp::Web::Controls::Web
	*        
    */
	result Construct(Osp::Base::String resourceId);
	
	/**
	* @page CompPopupConstruct20 Compatibility for Construct()
	*
	* @section      CompPopupConstruct20Issues      Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# In the bada API version prior to 2.0, the method first attempts to find the resource file in the folder that corresponds to the current screen 
	*    resolution: one of 240x400 and 480x800. If it fails to find the resource file, then it searches the other folders.
	* -# In the bada API version prior to 2.0, if parsing XML fails, the application is forced to terminate.
	* -# In the bada API version prior to 2.0, if a child control specified in the resource file cannot be created, the resource loading is stopped
	*    and E_SYSTEM is returned, but the Form instance is partially constructed.
	*
	* @section      CompPopupConstruct20Resolutions Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	* -# From bada API version 2.0, the method first attempts to find the resource file in the folder that corresponds to the current screen resolution.
	*    If it fails to find the appropriate resource file, it further tries other folders in the following order when AutoScaling is enabled: 
	*    the folder that corresponds to the current screen resolution and the ScreenSize-Normal folder.
	* -# From bada API Version 2.0, if the specified file is not found, the E_FILE_NOT_FOUND exception is returned.
	* -# From bada API Version 2.0, if the system has insufficient memory, the E_OUT_OF_MEMORY exception is returned.
	* -# From bada API version 2.0, if XML parsing fails, the application is not forced to terminate and the E_SYSTEM exception is returned.
	* -# From bada API version 2.0, if a child control cannot be created, the E_SYSTEM exception is returned and %Popup construction is failed.
	*/

	/**
	* Initializes this instance of %Popup with the specified layout and dimensions.
	*
	* @since		2.0
	* @return		An error code
	* @param[in]	layout				The layout for both the portrait and landscape mode
	* @param[in]	hasTitle	    	Set to @c true if the %Popup control should have a title, @n
	*							    	else @c false
	* @param[in]	dim			    	The size of the %Popup control
	* @exception	E_SUCCESS	    	The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	*									the specified layout is already bound to another container.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM	    	A system error has occurred.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">Control Size</a>.
	*/
	result Construct(const Osp::Ui::Layout& layout, bool hasTitle, const Osp::Graphics::Dimension& dim);

	/**
	* Initializes this instance of %Popup with the specified layouts and dimensions.
	*
	* @since		2.0
	* @return		An error code
	* @param[in]	portraitLayout		The layout for the portrait mode
	* @param[in]	landscapeLayout		The layout for the landscape mode
	* @param[in]	hasTitle			Set to @c true if this %Popup control should have a title, @n
	* 									else @c false
	* @param[in]	dim			    	The size of the %Popup control
	* @exception	E_SUCCESS	    	The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	*									the specified layout is already bound to another container.
	* @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception	E_SYSTEM	    	A system error has occurred.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">Control Size</a>.
	*/
	result Construct(const Osp::Ui::Layout& portraitLayout, const Osp::Ui::Layout& landscapeLayout, bool hasTitle, const Osp::Graphics::Dimension& dim);

	/**
	* Sets the title of the %Popup control.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	title		The title to be set
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	A system error has occurred.
	*/
	result SetTitleText(const Osp::Base::String& title);

	/**
	* Gets the title of the %Popup control.
	*
	* @since		1.0
	* @return		The title of the %Popup control
	*/
	Osp::Base::String GetTitleText(void) const;

	/**
	* Displays the %Popup control.
	*
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompPopupShow "here".
	*
	* @return  	 An error code
	* @exception E_SUCCESS				The method is successful.
	* @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	*          						 	this control is not 'displayable'.
	* @exception E_SYSTEM   			A system error has occurred.
	*/
	virtual result Show(void);

	/**
	* @page	CompPopupShow Compatibility for Show()
	*
	* @section	CompPopupShowIssues	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* -# If a %Popup control created by UiBuilder has child control layout in the landscape mode, the popup is not displayed properly.
    *
	* @section	CompPopupShowResolutions	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	*/


	/**
	* Adds the specified control to the %Popup control.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	control		    The control to be added
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks		The added control is deleted automatically when its parent container is destroyed.
	*/
	virtual result AddControl(const Control& control);

	/**
	* Gets the bounds of the client area.
	*
	* @since		1.0
	* @return		The bounds of the client area in a %Rectangle instance
	*
	*/
	Osp::Graphics::Rectangle GetClientAreaBounds(void);

	/**
	 * Sets the show state of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	state				The new show state
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be displayed).
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Although this method is invoked, the control is not shown. @n
	 *				To show a control, use the Show() methods. @n
	 *				Once the show state of the control is set to @c false, you need to set the show state to @c true again before you draw and show.
	 * @see			GetShowState(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)  Draws the control.
	 *
	 * @since	1.0
	 */
	result Draw(void);
	
	/**
	 * Sets the size of the %Popup control. @n
	 * The width becomes @c width, and the height becomes @c height.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	width           		The new width
	 * @param[in]	height          		The new height
	 * @exception	E_SUCCESS       		The method is successful.
	 * @exception   E_INVALID_ARG   		A specified input parameter is invalid, or
	 *                              		either the @c size.width or @c size.height is less than the minimum size.
	 * @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception   E_SYSTEM        		A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">Control Size</a>.
	 * @see   		GetMinimumSize(), GetMaximumSize()
	 *    		
	 */
	virtual result SetSize(int width, int height);


	/**
	 * Sets the size of the control. @n
	 * Its width becomes @c size.width, and its height becomes @c size.height.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	size             			The new width and height
	 * @exception	E_SUCCESS        			The method is successful.
	 * @exception	E_INVALID_ARG    			A specified input parameter is invalid, or
	 *                               			either the @c size.width or @c the size.height is less than the minimum size.
	 * @exception	E_OUT_OF_MEMORY  			The memory is insufficient.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM		 			A system error has occurred.
  	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">Control Size</a>.
	 * @see   		GetMinimumSize(), GetMaximumSize()
	 *    		
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

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
     * Checks whether the specified child control is always at the bottom of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is always set to remain at the bottom of the stack, @n
	 *				else @c false
	 * @param[in]	control				The child control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified @c control parameter is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysAtBottom()
	 */
	bool IsControlAlwaysAtBottom(const Osp::Ui::Control& control) const;

	/**
	 * Checks whether the specified child control is always at the top of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is always set to remain at the top of the stack, @n
	 *				else @c false
	 * @param[in]	control				The child control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or
	 *									the specified @c control is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysOnTop()
	 */
	bool IsControlAlwaysOnTop(const Osp::Ui::Control& control) const;

	/**
	 * Sets whether the specified child control should always be above other children.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          		The child control
	 * @param[in]	alwaysOnTop				Set to @c  true if the control should always be on the top, @n
	 *										else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG    		A specified input parameter is invalid, or
	 *										the specified @c control is not a child of this container.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *										the specified @c control is set at the bottom of the drawing stack.
	 * @exception	E_INVALID_STATE 		This instance is in an invalid state.
	 * @remarks		If multiple child controls are set as "always on top", then their relative order is not specified. If the specified child control is a 
	 *				container, then all its children inherit this property and they are "always on top" of the other controls. @n
	 *				If this method is called on a child control with a @c false value, then its state becomes normal. The relative order of child controls in 
	 *				the normal state is not specified.
	 * @see			IsControlAlwaysOnTop()
	 */
	result SetControlAlwaysOnTop(Osp::Ui::Control& control, bool alwaysOnTop);

	/**
	 * Sets the specified child control to be below other child controls.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          		The child control
	 * @param[in]	alwaysAtBottom   		Set to @c true if the control should always be at the bottom, @n
	 *										else @c false
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_INVALID_ARG    		A specified input parameter is invalid, or
	 *                                		the specified @c control is not a child of this container.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *                                  	the specified @c control is set on the top of other child controls.
	 * @exception	E_INVALID_STATE  		This instance is in an invalid state.
	 * @remarks		If multiple child controls are set as "always at bottom", then their relative order is not specified. If the specified child control is a 
	 *				container, then all its children inherit this property and they become "always at bottom" as well. @n
	 *				If this method is called on a child control with a @c false value, then its state becomes normal. The relative order of the child 
	 *				controls in normal state is not specified.
	 * @see			IsControlAlwaysAtBottom()
	 */
	result SetControlAlwaysAtBottom(Osp::Ui::Control& control, bool alwaysAtBottom);
	
	/**
	 * Creates and returns a graphics canvas whose bounds (position and size) are equal to the bounds of the client area of the %Popup control.
	 *
	 * @since		2.0
	 * @return		The graphic canvas of the %Popup control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_RESOURCE_UNAVAILABLE		The required resource is currently unavailable.
	 * @remarks		The method allocates an Osp::Graphics::Canvas whose bounds are equal to that of the client area of the %Popup control. @n
	 *				It is the responsibility of the developers to deallocate the canvas after use.
	 * @remarks		The canvas is valid only if the properties of the parent control of the canvas remain unchanged. @n
	 *				Therefore, delete the previously allocated canvas and create a new canvas using the GetCanvasN() method if the size or position of the 
	 *				control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Canvas* GetClientAreaCanvasN(void) const;

	/**
	 * Translates the specified position to the client coordinates.
	 *
	 * @since       2.0
	 * @return      The position in relative to the top-left corner of the client-area, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   position	The position relative to the top-left corner of the %Popup control
	 * @see         TranslateFromClientAreaPosition()
	 */
	Osp::Graphics::Point TranslateToClientAreaPosition(const Osp::Graphics::Point& position) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.0
	 * @return      The position in relative to the top-left corner of the %Popup control, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   clientPosition		The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Osp::Graphics::Point TranslateFromClientAreaPosition(const Osp::Graphics::Point& clientPosition) const;

	/**
	 * Gets the color of the %Popup control.
	 *
	 * @since       2.0
	 * @return      The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Color GetColor(void) const;

	/**
	 * Sets the color of the %Popup control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   color               The color to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @exception   E_SYSTEM            A system error has occurred.
	 */
	result SetColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the title text color of the %Popup control.
	 *
	 * @since		2.0
	 * @return		The color, @n
	 *				else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * Sets the title text color of the %Popup control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   color                The title text color
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_INVALID_STATE      This instance is in an invalid state.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result SetTitleTextColor(const Osp::Graphics::Color& color);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to this %Popup control
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control					The control to be added to this popup
	 * @param[in]	index					The z-order index of @c pControl
	 * @exception	E_SUCCESS				The method is successful. @n
	 *										It contains a NULL reference (i.e., @c pControl is NULL).
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	 *										@c pControl is an instance of Window or this control's parent container.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	virtual result AddControlImplAt(const Osp::Ui::Control& control, int index);


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
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual result __Draw(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
     *
     * @since       1.0
	 */
	result __CheckConditionValidate(const Osp::Ui::Control& control) const;

private:
// attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Title of this %Popup.
     * @since       1.0
	 */
	Osp::Base::String				__title;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Bool whether %Popup has title.
     * @since       1.0
	 */
	bool							__hasTitle;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The show flag.
     * @since       1.0
	 */
	bool	__firstShow;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The showing flag.
     * @since       1.0
	 */
	bool	__showing;

private:
	friend class PopupEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class PopupEx*	__pPopupEx;

protected:
	friend class PopupImpl;
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
	class PopupImpl* GetImpl(void) const;

};

}; }; };	// Osp::Ui::Controls
#endif	//_FUICTRL_POPUP_H_s
