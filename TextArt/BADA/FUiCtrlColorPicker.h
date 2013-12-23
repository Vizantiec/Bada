/* $Change: 995676 $ */
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
* @file			FUiCtrlColorPicker.h
* @brief	This is the header file for the %ColorPicker class.
*
* This header file contains the declarations of the %ColorPicker class.
*/
#ifndef _FUICTRL_COLOR_PICKER_H_
#define _FUICTRL_COLOR_PICKER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiIColorChangeEventListener.h"
#include "FUiIOrientationEventListener.h"

namespace Osp { namespace Ui { namespace  Controls {

/**
* @class	ColorPicker
* @brief This class defines the common behavior of a %ColorPicker control.
* @since 1.0
*
* The %ColorPicker class displays a set of 3 sliders (hue, saturation, and luminance) with which the user can define a color.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_colorpicker.htm">ColorPicker</a>.
*
* The following example demonstrates how to use the %ColorPicker class.
*
* @code

// Sample Code for ColorPickerSample.h
#include <FUi.h>

class ColorPickerSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IColorChangeEventListener
{
public:
    virtual result OnInitializing(void);
    virtual void OnColorChanged(const Osp::Ui::Control& source, const Osp::Graphics::Color& color);
};

// Sample Code for ColorPickerSample.cpp
#include "ColorPickerSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

result
ColorPickerSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a ColorPicker.
    ColorPicker* pColorPicker = new ColorPicker();
    pColorPicker->Construct(Point(10,0));

    // Adds a ColorChangeEvent listener.
    pColorPicker->AddColorChangeEventListener(*this);

    // Adds a ColorPicker to the Form.
    AddControl(*pColorPicker);

    return r;
}

// Implements an IColorChangeEventListener
void
ColorPickerSample::OnColorChanged(const Osp::Ui::Control& source, const Osp::Graphics::Color& color)
{
    // Todo:
}

* @endcode
*/

class _EXPORT_CONTROLS_ ColorPicker :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(ColorPicker);
public:
	/**	
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	ColorPicker(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~ColorPicker(void);

	/**
	* Initializes this instance of %ColorPicker with the specified parameter.
	 *
	 * @since			1.0
	* @compatibility       This method has compatibility issues with bada API versions. @n
	 *                      For more information, see @ref CompColorPickerConstruct "2.0".
	 *
	 * @return			An error code
	* @param[in]	point	        The position of this %ColorPicker in the container
	* @exception	E_SUCCESS 		The method is successful.
	 * @exception 	E_INVALID_STATE This instance has already been constructed.
	* @exception	E_SYSTEM		A system error has occurred.
	* @exception 	E_OUT_OF_MEMORY	The memory is insufficient.
	* @remarks		A control is fully usable only after it has been added to a container. Therefore, some methods may fail if the control is used earlier.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Point& point);

	/**
	 * @page   CompColorPickerConstruct Compatibility for Construct()
	 * @section CompColorPickerConstructIssues Compatibility Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* -# On a WVGA screen, the size of %ColorPicker is 460 x 306 in portrait orientation and 780 x 306 in landscape orientation.
	 *
	 * @section CompColorPickerConstructResolutions Resolutions
	 * -# On a WVGA screen, the size of ColorPicker is changed to 462x306 in portrait orientation and 702x306 in landscape orientation. The size in logical pixel is the same as that on a WVGA screen.
	 */

	/**
	* Gets the current color value of %ColorPicker.
	 *
	 * @since		1.0
	 * @return		The current color value
	 */
	Osp::Graphics::Color GetColor(void) const;

	/**
	 * Gets the current hue value of %ColorPicker.
	 *
	 * @since		1.0
	 * @return		The current hue value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetHue(void) const;

	/**
	* Gets the current saturation value of %ColorPicker.
	 *
	 * @since		1.0
	 * @return		The current saturation value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetSaturation(void) const;

	/**
	* Gets the current luminance value of %ColorPicker.
	 *
	 * @since		1.0
	 * @return		The current luminance value
	 * @remarks		The return value is between @c 0 to @c 100.
	 */
	int GetLuminance(void) const;

	/**
	* Sets the color value of %ColorPicker.
	 *
	 * @since			1.0
	* @param[in]	color	The color value
	 */
	void  SetColor (const Osp::Graphics::Color& color);

	/**
	* Sets the hue value of %ColorPicker.
	 *
	 * @since			1.0
	 * @param[in]	hue	The hue value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetHue(int hue);

	/**
	* Sets the saturation value of %ColorPicker.
	 *
	 * @since			1.0
	 * @param[in]	saturation	The saturation value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetSaturation(int saturation);

	/**
	* Sets the luminance value of %ColorPicker.
	 *
	 * @since			1.0
	 * @param[in]	luminance	The luminance value of this object
	 * @remarks			The value should be between @c 0 to @c 100.
	 *
	 */
	void SetLuminance(int luminance);

	/**
	 * Adds a listener instance.
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since			1.0
	* @param[in]	listener 	The event listener to be added
	 * @see				RemoveColorChangeEventListener()
	 */
	void AddColorChangeEventListener(const Osp::Ui::IColorChangeEventListener& listener);

	/**
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			1.0
	* @param[in]	listener 	The event listener to be removed
	 * @see				AddColorChangeEventListener()
	 */
	void RemoveColorChangeEventListener(const Osp::Ui::IColorChangeEventListener& listener);

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompColorPickerSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]   x               The new x position of the control
	 * @param[in]   y               The new y position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent control.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(int x, int y);

	/**
	 * Sets the position of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see @ref CompColorPickerSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]	Position				The new position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent control.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see	IsMovable()
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
	 * @page   CompColorPickerSetPosition Compatibility for SetPosition()
	 * @section CompColorPickerSetPositionIssues Compatibility Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# This method does not work in bada API versions prior to 1.2.
	 *
	 * @section CompColorPickerSetPositionResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */

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

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this Window.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);

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
	 * @exception	E_UNSUPPORTED_OPERATION The	method is not supported.
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
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported.
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);


private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Item Event.
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent* __pColorChangeEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Item Event Adaptor.
     * @since         1.0
     */
	void* __pColorChangeEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Item color.
     * @since         1.0
     */
	Osp::Graphics::Color __color;

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

private:
	friend class ColorPickerEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class ColorPickerEx*	__pColorPickerEx;

protected:
	friend class ColorPickerImpl;
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
	class ColorPickerImpl* GetImpl(void) const;

};

};};};

#endif // _FUICTRL_COLOR_PICKER_H_
