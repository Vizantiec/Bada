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
 * @file	FUiCtrlProgress.h
 * @brief	This is the header file for the %Progress class.
 *
 * This header file contains the declarations of the %Progress class and its helper classes.
 */

#ifndef _FUICTRL_PROGRESS_H_
#define _FUICTRL_PROGRESS_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlPositionEnum.h"

namespace Osp { namespace Ui { namespace Controls {


/**
 * @class	Progress
 * @brief	This class is an implementation of a %Progress control.
 * @since	1.0
 * 
 * The %Progress class displays the progress of a lengthy operation in a progress bar.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_progress.htm">Progress</a>.
 *
 * The following example demonstrates how to use the %Progress class.
 *
 * @code

// Sample Code for ProgressSample.h
#include <FUi.h>

class ProgressSample :
    public Osp::Ui::Controls::Form
{
public:
    virtual result OnInitializing(void);
};

// Sample Code for ProgressSample.cpp
#include "ProgressSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
result
ProgressSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Creates a Progress
    Progress* pProgress = new Progress();
    pProgress->Construct(Rectangle(50, 200, 300, 100), 0, 100);
    pProgress->SetValue(10);

    // Adds a Progress to the Form
    AddControl(*pProgress);

    return r;
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Progress :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(Progress);
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	Progress(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Progress(void);


	/**
	 * Initializes this instance of %Progress with the specified parameters.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompProgressConstruct20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect				An instance of the Rectangle class @n
	 *						    		This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *  					    		its width and height.
	 * @param[in]   minValue			The minimum value of the current instance of %Progress
	 * @param[in]   maxValue			The maximum value of the current instance of %Progress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
 	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
 	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The specified values should be positive and @c minValue should be less than @c maxValue.
	 * @exception   E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier. @n
	 *				In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, int minValue, int maxValue);

	/**
	 * @page	CompProgressConstruct20	Compatibility for Construct()
	 * @section	CompProgressConstruct20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The width and height of the control must be greater than @c 0. @n
	 *	  The E_INVALID_ARG exception is returned in case the width and height of the control are not greater than @c 0.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 * -# On a WVGA screen, the default minimum size is 100 x 20.
	 *
	 * @section	CompProgressConstruct20Resolutions	Resolutions
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control, or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be @c 0, if the minimum width and height are @c 0.
	 * -# On a WVGA screen, the default minimum size is 96 x 18. The default minimum sizes in logical pixel are the same as those on a WVGA screen.
	 */

// Operation
public:
	/**
	 * Sets the current value of the %Progress control. @n
	 * If the given value is greater than the @c maxValue with which %Progress is constructed, it will be set to %maxValue. The same applies for @c minValue.
	 *
	 * @since		1.0
	 * @param[in] 	value	The current progress value
	 */
	void SetValue(int value);


	/**
	 * Sets the minimum and maximum value of the %Progress control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *        			For more information, see @ref CompProgressSetRange "here".
	 *
	 * @return		An error code
	 * @param[in]	minValue			The minimum value of the current instance of %Progress
	 * @param[in]	maxValue			The maximum value of the current instance of %Progress
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of an argument is outside the valid range defined by the method. @n
	 *									The specified values should be positive.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetRange(int minValue, int maxValue);

	/**
	 * @page	CompProgressSetRange	Compatibility for SetRange()
	 *
	 * @section	CompProgressSetRangeIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The method sets the new minimum and maximum values. However, even if the current value falls outside of the new range, the value remains unchanged.
	 *
	 * @section	CompProgressSetRangeResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows:
	 * From bada API version 2.0, if the current value falls outside of the new range, the current value is changed to the closest boundary value of the range.
	 *
	 * @par When working with bada API versions prior to 2.0:
	 * -# Use SetValue() to change the value of Progress before calling SetRange().
	 */

	/**
	 * Gets the current value of the %Progress control.
	 *
	 * @since	1.0
	 * @return	An integer value representing the current value of progress, @n
	 *			else @c -1 if an error occurs
	 */
	int GetValue(void) const;


	/**
	 * Gets the minimum value and the maximum value of the %Progress control.
	 *
	 * @since		1.0
	 * @param[out] 	minValue	The minimum value
	 * @param[out] 	maxValue	The maximum value
 	*/
	void GetRange(int& minValue, int& maxValue) const;


	/**
	 * Gets the percent value of the %Progress control.
	 *
	 * @since	1.0
	 * @return	The progress as a percentage, @n
	 *			else @c -1 if an error occurs
	 */
	int GetPercentComplete(void) const;

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
	 * Sets the position and size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	x							The new x coordinate
	 * @param[in]	y							The new y coordinate
	 * @param[in]	width						The new width
	 * @param[in]	height						The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than zero.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control.
	 *	
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	rect						The new bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_OPERATION     	The control has not been constructed as yet.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0. @n
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	width						The new width
	 * @param[in]	height						The new height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than @c 0. @n
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			IsResizable()	 
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);


	/**
	 * Sets the size of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 *
	 * @return		An error code
	 * @param[in]	size						The new width and height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY 			The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method. @n
	 *				In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see			IsResizable()	 
	 * @see   		GetMinimumSize()
	 * @see   		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

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
	 * @exception	E_SYSTEM 	Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	friend class ProgressEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class ProgressEx* __pProgressEx;

protected:
	friend class ProgressImpl;

 	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * Gets the implementation instance of this control
     *
     * @since         2.0
     */	
	class ProgressImpl* GetImpl(void) const;

};
}; }; }; //Osp::Ui::Controls
#endif // _FUICTRL_PROGRESS_H_

