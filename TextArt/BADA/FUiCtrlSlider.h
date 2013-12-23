/* $Change: 1037340 $ */
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
 * @file	FUiCtrlSlider.h 
 * @brief	This header file contains the declarations of the %Slider class.
 *
 * This header file contains the declarations of the %Slider class and its helper classes.
 */

#ifndef _FUICTRL_SLIDER_H_
#define _FUICTRL_SLIDER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseColArrayListT.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FGrpRectangle.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiIAdjustmentEventListener.h"
#include "FUiCtrlPositionEnum.h"
#include "FUiCtrlBackgroundEnum.h"
#include "FUiCtrlTableViewStyleEnum.h"
#include "FUiCtrlSliderEnum.h"
#include "FUiCtrlISliderEventListener.h"

//namespace Osp { namespace Ui { class __ChangeEvent; }; };

// Forward declarations
namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	Slider
 * @brief	This class is an implementation of a %Slider control.
 * @since	1.0
 *
 * The %Slider class displays a slider, which represents changing progress or setting information. The difference between %Slider
 * and Progress is that the former accepts user input by the touch of the slider icon. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_slider.htm">Slider</a>.
 *
 * The following example demonstrates how to use the %Slider class. 
 *
 * @code

// Sample Code for SliderSample.h
#include <FUi.h>
#include <FGraphics.h>

class SliderSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IAdjustmentEventListener
{
public:
    SliderSample(void) {};
    virtual ~SliderSample(void) {};

protected:
    Osp::Graphics::Bitmap* GetBitmapN(void);

public:
    virtual result OnInitializing(void);
    virtual void OnAdjustmentValueChanged(const Osp::Ui::Control& source, int adjustment);
};

// Sample Code for SliderSample.cpp
#include "SliderSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
SliderSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates Bitmaps
    Bitmap* pBitmapLeftIcon = GetBitmapN();
    Bitmap* pBitmapRightIcon = GetBitmapN();

    // Creates a Slider.
    Slider* pSlider = new Slider();
    pSlider->Construct(Rectangle(50, 200, 300, 100), BACKGROUND_STYLE_DEFAULT, false, 0, 100);

    pSlider->SetIcon(ICON_POSITION_LEFT, *pBitmapLeftIcon);
    pSlider->SetIcon(ICON_POSITION_RIGHT, *pBitmapRightIcon);

    // Deallocates a Bitmap.
    delete pBitmapLeftIcon;
    delete pBitmapRightIcon;

    pSlider->SetValue(40);
    pSlider->AddAdjustmentEventListener(*this);

    //Add a Slider to the Form.
    AddControl(*pSlider);

    return r;
}

Bitmap*
SliderSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN.
}

// Implements an IAdjustmentEventListener
void
SliderSample::OnAdjustmentValueChanged(const Osp::Ui::Control& source, int adjustment)
{
    // Todo:
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Slider
	: public Osp::Ui::Control
{
	DECL_CLASSTYPE(Slider);
public:

// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Slider(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Slider(void);

	/**
	 * Initializes this instance of %Slider with the specified parameters.
	 *
	 * @since		1.0
	 * @compatibility 	This method has compatibility issues with different bada API versions. @n
	 *     				For more information, see issues in version @ref CompSliderConstruct1_2 "1.2" and @ref CompSliderConstruct2_0 "2.0".
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *									the width and height of the control. 
	 * @param[in]	backgroundStyle		The background style set of the slider
	 * @param[in] 	showTitle			Set to @c true to enable the show title, @n
	 *									else @c false
	 * @param[in]	minValue			The minimum slider value
	 * @param[in]	maxValue			The maximum slider value
 	 * @param[in] 	groupStyle			The table view style of the slider
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
     * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
     *                                  The background style of BACKGROUND_STYLE_NONE does not work with group styles except GROUP_STYLE_NONE.
	 * @exception	E_OUT_OF_RANGE		The specified values are less than @c -99 or greater than @c 999.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if used earlier. @n
	 *				If the given size is less than the minimum, %Slider is constructed with the minimum size in @b SDK @b 1.x. @n
     *				In @b SDK @b 2.0 or above versions, it returns E_INVALID_ARG.
     * @remarks		In bada API versions prior to 2.0, @c width and @c height of the control must be greater than @c 0. @n
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, BackgroundStyle backgroundStyle = BACKGROUND_STYLE_DEFAULT, bool showTitle = false, int minValue = 0, int maxValue = 100, GroupStyle groupStyle = GROUP_STYLE_NONE);

	/**
	 * @page	CompSliderConstruct1_2	Compatibility for Construct()
	 * @section	CompSliderConstruct1_2Issues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	 * -# When touch-canceling the slider, IAdjustmentEventListener::OnAdjustmentValueChaned() is not called.
	 * -# When touch-dropping the slider after touch-drag, IAdjustmentEventListener::OnAdjustmentValueChaned() is not called and the value-box remains.
	 *
	 * @section	CompSliderConstruct1_2Resolutions	Resolutions
	 * The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2. or above. @n
	 */

	/**
	 * @page	CompSliderConstruct2_0	Compatibility for Construct()
	 * @section	CompSliderConstruct2_0Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# When the input size is less than the minimum size of %Slider, it is resized to the minimum size of %Slider. @n
	 * -# If the user moves out of the %Slider's range, IAdjustmentValueChanged() is called even when the value of the %Slider has not changed.
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust its 
	 *	  bounds to the minimum size. @n
	 * -# The background style of BACKGROUND_STYLE_NONE does not work with group styles except GROUP_STYLE_NONE, but Construct() does not generate an 
	 *	  exception. @n
	 * -# On a WVGA screen, the default minimum sizes are 200 x 90 (normal), and 200 x 106 (with a title).
	 *
	 * @section	CompSliderConstruct2_0Resolutions	Resolutions
	 * -# The issue 1 is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The issue 2 is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control. @n
	 * -# The width and height of the control can be @c 0, if its minimum width and height is @c 0. @n
	 * -# Construct() generates an exception when a background style of BACKGROUND_STYLE_NONE and group styles except GROUP_STYLE_NONE are specified at the 
	 *	  same time. @n
	 * -# On a WVGA screen, the default minimum sizes are 198x90 (normal), and 198x102 (with a title). The default minimum sizes in logical pixel are the 
	 *	  same as those on a WVGA screen.
	 */

	/**
	 * Adds a IAdjustmentEventListener instance. @n
	 * The added listener listens to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddAdjustmentEventListener(const Osp::Ui::IAdjustmentEventListener& listener);

    /**
	 * Removes a IAdjustmentEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveAdjustmentEventListener(const Osp::Ui::IAdjustmentEventListener& listener);

// Operation
public:
	/**
	 * Sets the range of the %Slider control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	minValue		The minimum value of the %Slider control
	 * @param[in]	maxValue		The maximum value of the %Slider control
	 * @exception	E_SUCCESS 	    The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified values are greater than @c -99 or less than @c 999.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRange(int minValue, int maxValue);

	/**
	 * Gets the minimum value and the maximum value of the slider.
	 *
	 * @since		1.0
	 * @param[out]	minValue		The minimum value of the slider
	 * @param[out]	maxValue		The maximum value of the slider
	 */
	void GetRange(int& minValue, int& maxValue) const;

	/**
	 * Sets the value of the current thumb position. @n
	 * If the specified @c value is greater than @c maxValue, the value is set to @c maxValue, and
	 * if the specified @c value is less than @c minValue, the value is set to @c minValue.
	 *
	 * @since		1.0
	 * @param[in]   value  The value of the position
	 */
	void SetValue(int value);

	/**
	 * Gets the value of the current thumb position.
	 *
	 * @since		1.0
	 * @return		The current thumb position
	 */
	int GetValue(void) const;

	/**
	 * Sets the icon of the slider.
	 *
	 * @since		1.0
 	 * @param[in] 	position	The position of the icon (ICON_POSITION_LEFT/ICON_POSITION_RIGHT)
	 * @param[in] 	icon 		The bitmap image of the icon
	 * @remarks     If the size of the bitmap is greater than the default size, the bitmap image is scaled down. @n
	 *				For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	void SetIcon(IconPosition position, const Osp::Graphics::Bitmap& icon);

	/**
	* Sets the title of the slider.
	*
	* @since		1.0
	* @return		An error code
	* @param[in] 	title		        The title to be set
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The slider control has no title style.
	* @exception	E_SYSTEM	        A system error has occurred.
	*/
	result SetTitleText(const Osp::Base::String& title);

	/**
	 * Gets the title of the slider.
	 *
	 * @since		1.0
	 * @return		The title text of the entered string, @n
	 *			    else an empty string if the %Slider instance is not constructed
	 */
	Osp::Base::String GetTitleText(void) const;

	/**
	 * Sets the position and size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]	x							The new x coordinate
	 * @param[in]	y							The new y coordinate
	 * @param[in]	width						The new width
	 * @param[in]	height						The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API version prior to 2.0, @c width and @c height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]	rect						The new bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API version prior to 2.0, @c width and @c height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * Sets the size of the %Slider control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]	width						The new width
	 * @param[in]	height						The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API version prior to 2.0, @c width and @c height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);

	/**
	 * Sets the size of the %Slider control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]	size						The new width and height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_SYSTEM					A system error occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In bada API version prior to 2.0, @c width and @c height of the control must be greater than @c 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	/**
	 * Sets the title text color of the %Slider control.
	 *
	 * @since		1.0
	 * @compatibility  	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompSliderSetTitleTextColor "here".
	 *
	 * @param[in]	color 	The title text color to be set
	 */
	void SetTitleTextColor(const Osp::Graphics::Color& color);

	/**
	 * @page	CompSliderSetTitleTextColor	Compatibility for SetTitleTextColor()
	 *
	 * @section	CompSliderSetTitleTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method ignores the alpha value of specified color.
	 *
	 * @section	CompSliderSetTitleTextColorResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the title text color of the %Slider control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *               	For more information, see @ref CompSliderGetTitleTextColor "here".
	 *
	 * @return		The title text color	 	 	 
	 */
	Osp::Graphics::Color GetTitleTextColor(void) const;

	/**
	 * @page	CompSliderGetTitleTextColor	Compatibility for GetTitleTextColor()
	 *
	 * @section	CompSliderGetTitleTextColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method returns a 16-bit color to specify the text color.
	 *
	 * @section	CompSliderGetTitleTextColorResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	 * -# The method returns a 32-bit color to specify the text color. @n
	 * -# It also returns the same color value that is set using SetTitleTextColor().
	 *
	 */

	/**
	 * Initializes this instance of %Slider with the specified parameters. 
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rect				An instance of the Graphics::Rectangle class
	 *								  	This instance represents the X and Y coordinates of the top-left corner of the created window along with
	 *  					    	  	its width and height.
	 * @param[in]	sliderStyle      	The style of the slider @n
	 *                                	Multiple link types can be combined using bitwise OR operator. See Osp::Ui::Controls::SliderStyle. 
	 * @param[in]	minValue         	The minimum slider value
	 * @param[in]	maxValue         	The maximum slider value
	 * @exception	E_SUCCESS        	The method is successful. 
	 * @exception	E_INVALID_STATE  	This instance has already been constructed. 
	 * @exception	E_OUT_OF_RANGE   	The specified minimum and maximum values are less than @c -99, or greater than @c 999. 
	 * @exception	E_INVALID_ARG    	A specified input parameter is invalid, or the specified @c minValue is greater than @c maxVaue.
	 * @exception	E_OUT_OF_MEMORY  	The memory is insufficient. 
	 * @exception	E_SYSTEM         	A system error has occurred. 
	 * @remarks		A control is fully functional only after it has been added to a container. Therefore, some methods may fail if they are used before 
	 *				adding the control to the container. @n
	 *				If the specified size is less than the minimum size, the %Slider control is constructed with the minimum size.
	 * @remarks		The width and the height of the control must be greater than @c 0.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, unsigned long sliderStyle, int minValue = 0, int maxValue = 100); 

	/**
	 * Adds a ISliderEventListener instance. @n
	 * The added listener can listen to the slider-related events. 
	 *
	 * @since     2.0
	 * @param[in] listener    The event listener to be added
	 */
	void AddSliderEventListener(const ISliderEventListener& listener); 

	/**
	 * Removes a ISliderEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired. 
	 *
	 * @since     2.0
	 * @param[in] listener    The event listener to be removed
	 */
	void RemoveSliderEventListener(const ISliderEventListener& listener); 
	   
	/**
	 * Sets the color of the bar. 
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in] color           	The color to be set
	 * @exception E_SUCCESS       	The method is successful. 
	 * @exception E_INVALID_STATE	This instance is in an invalid state. 
	 * @exception E_SYSTEM        	A system error has occurred. 
	 * @remarks   The method ignores the alpha value of the @c color parameter and sets the alpha value to @c 255.
	 */
	result SetBarColor(const Osp::Graphics::Color& color); 

	/**
	 * Gets the color of the bar. 
	 *
	 * @since     2.0
	 * @return    The color of the bar, @n
	 *			  else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception E_SUCCESS       	The method is successful. 
	 * @exception E_INVALID_STATE 	This instance is in an invalid state. 
	 * @remarks   The specific error code can be accessed using the GetLastResult() method.
	 */
	 Osp::Graphics::Color GetBarColor(void) const; 

	/**
	 * Sets the color of the slider.
	 *
	 * @since     2.0
	 * @return    An error code
	 * @param[in] color           			The color to be set
	 * @exception E_SUCCESS       			The method is successful.
	 * @exception E_INVALID_STATE 			The instance is in an invalid state.
	 * @exception E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The operation is not supported if the background style of the Slider control is BACKGROUND_STYLE_NONE.
	 * @exception E_SYSTEM        			A system error has occurred.
	 * @remarks   If a device supports only the 16-bit color space, this method considers the color as opaque by ignoring the alpha value of @c color.
	 */
	result SetColor(const Osp::Graphics::Color& color); 

	/** 
	 * Gets the color of the slider. 
	 * 
	 * @since		2.0 
	 * @return		The color , @n
	 *				else RGBA(0, 0, 0, 0) if an instance is invalid or the background style is BACKGROUND_STYLE_NONE
	 * @exception	E_SUCCESS			The method is successful. 
	 * @exception	E_INVALID_STATE		The instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION	The background style is not proper.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. 
	 */
	Osp::Graphics::Color GetColor(void) const;

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
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Stores The adjustment event.
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent* __pAdjustmentEvent;
	    
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The adjustment event.
     * @since         1.0
     */	
	void* __pAdjustmentEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Sets title of the object.
     * @since         1.0
     */	
	Osp::Base::String		__title;
	    
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Stores left bitmap image of the slider.
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__pMinBitmap;
	    
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Stores right bitmap image of the slider.
     * @since         1.0
     */	
	Osp::Graphics::Bitmap*	__pMaxBitmap;

private:
	friend class SliderEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class SliderEx* __pSliderEx;

protected:
	friend class SliderImpl;
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
	class SliderImpl* GetImpl(void) const;

};
}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_SLIDER_H_

