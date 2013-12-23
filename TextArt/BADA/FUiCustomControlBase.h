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
 * @file	FUiCustomControlBase.h
 * @brief	This is the header file for the %CustomControlBase class.
 *
 * This header file contains the declarations of the %CustomControlBase class and its helper classes.
 */
 
#ifndef _FUI_CUSTOM_CONTROL_BASE_H_
#define _FUI_CUSTOM_CONTROL_BASE_H_

// includes
#include "FUiContainer.h"

namespace Osp { namespace Ui {

/**
 * @class   CustomControlBase
 * @brief   This is the base class for the user-defined UI control classes.
 * @since   2.0
 *
 * The %CustomControlBase class is the base class for the user-defined UI control classes. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_customcontrolbase.htm">CustomControlBase</a>.
 */
class _EXPORT_UI_ CustomControlBase :
	public Container
{
// Lifecycle
public:   
    /**
     * This is the destructor for this class.
     *
     * @since   2.0
     */
	virtual ~CustomControlBase(void);

// Lifecycle
protected:
    /**
     * Initializes this instance of %CustomControlBase.
     *
     * @since       2.0
     * @return      An error code
	 * @param[in]	rect				The bounds rectangle to be set
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *                              	else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *                              	else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_STATE     This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.	 
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     This method should be called from the construct methods of the derived classes.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see	IsResizable()	
     */
	result Construct(const Osp::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	
	/**
	 * Initializes this instance of %CustomControlBase with the specified layout and rectangular region.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	rect				The location and size of %CustomControlBase
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *									else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *									else @c false
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks     This method should be called from the construct methods of the derived classes.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see		IsResizable()	
	 * @see		Osp::Ui::Container::GetLayoutN()
	 */
	result Construct(const Osp::Ui::Layout& layout, const Osp::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);
	
	
	/**
	 * Initializes this instance of %CustomControlBase with the specified layouts and rectangular region.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of $CustomControlBase
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *                              	else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *                              	else @c false
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see		IsResizable()	
	 * @see		Osp::Ui::Container::GetLayoutN()
	 * @see		Osp::Ui::Container::GetPortraitLayoutN()
	 * @see		Osp::Ui::Container::GetLandscapeLayoutN()
	 */
	result Construct(const Osp::Ui::Layout& portraitLayout, const Osp::Ui::Layout& landscapeLayout, const Osp::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);
	
// Operation
public:
	/**
     * Gets the composited scene of %CustomControlBase.
	 *
	 * @since		2.0
	 * @return		A Bitmap instance which captures the current composited scene of %CustomControlBase, @n
	 *				else @c null
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		The method invoked is invalid in this state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The bounds of the control must be within the client area bounds to get a valid bitmap.
	 */
	Osp::Graphics::Bitmap* GetCapturedBitmapN(void) const;


	/**
	 * Checks whether the specified child control is always at the bottom of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is set as always at the bottom, @n 
	 *				else @c false
	 * @param[in]	control          	The child control
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 *                                	The specified control is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysAtBottom()
	 */
	bool IsControlAlwaysAtBottom(const Osp::Ui::Control& control) const;


	/**
	 * Checks whether the specified child control is always on the top of the drawing stack.
	 *
	 * @since		2.0
	 * @return		@c true if the specified child control is set as always on the top, @n 
	 *				else @c false
	 * @param[in]	control          	The child control
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG    	The specified input parameter is invalid. @n
	 *									The specified control is not a child of this container.
	 * @exception	E_INVALID_STATE  	This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetControlAlwaysOnTop()
	 */
	bool IsControlAlwaysOnTop(const Osp::Ui::Control& control) const;


	/**
	 * Sets whether the specified child control should always be above other children.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          	The child control
	 * @param[in]	alwaysOnTop			Set to @c true if the specified @c control should always be on the top, @n
	 *									else @c false
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified control is not a child of this container.
	 * @exception 	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		If multiple child controls are set as "always on top", then their relative order is not specified. @n
	 *				If the specified child control is a container, then all its child controls inherit this property and they are "always on top" of other 
	 *				controls. @n
	 *				If the method is called on a child control with a @c false value, then its state becomes normal. @n
	 *				The relative order of child controls in normal state is not specified.
	 * @see			IsControlAlwaysOnTop()
	 */
	result SetControlAlwaysOnTop(Osp::Ui::Control& control, bool alwaysOnTop);


	/**
	 * Sets whether the specified child control should always be below other children.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	control          	The child control
	 * @param[in]	alwaysAtBottom		Set to @c true if the specified @c control should always be on the bottom, @n
	 *									else @c false
	 * @exception	E_SUCCESS        	The method is successful.
	 * @exception	E_INVALID_ARG    	A specified input parameter is invalid. @n
	 *									The specified control is not a child of this container.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		If multiple child controls are set as "always at bottom", then their relative order is not specified. @n
	 *				If the specified child control is a container, then all its child controls inherit this property and they are "always at bottom" of other 
	 *				controls. @n
	 *				If the method is called on a child control with a @c false value, then its state becomes normal. @n
	 *				The relative order of child controls in normal state is not specified.
	 * @see			IsControlAlwaysAtBottom()
	 */
	result SetControlAlwaysAtBottom(Osp::Ui::Control& control, bool alwaysAtBottom);

	
// Overridable
public:
    /**
     * Called when the bounds of the control are changed.
     *
     * @since		2.0
     * @return		An error code
	 * @param[in]	oldRect		The old position and size values of the control
	 * @param[in]	newRect		The new position and size values of the control
 	 * @see		Osp::Ui::Control::SetBounds()
 	 * @see		Osp::Ui::Control::SetSize()
     */
	virtual void OnBoundsChanged(const Osp::Graphics::Rectangle& oldRect, const Osp::Graphics::Rectangle& newRect);


    /**
     * Called when the show state of the control is changed.
     *
     * @since		2.0
	 * @param[in]	showState	The new show state of the control
 	 * @see		Osp::Ui::Control::SetShowState()
     */
	virtual void OnShowStateChanged(bool showState);

	
	/**
     * Called when the bounds of the control is about to change.
     *
     * @since		2.0
     * @return		An error code
	 * @param[in]	oldRect		The old position and size values of the control
	 * @param[in]	newRect		The new position and size values of the control
	 * @remarks		If the method returns an exception, the resulting exception is propagated and the size of the control is unchanged. @n
	 *              Control specific exceptions should be provided.
 	 * @see         Osp::Ui::Control::SetBounds()
 	 * @see         Osp::Ui::Control::SetSize()
 	 */
	virtual result PrepareBoundsChange(const Osp::Graphics::Rectangle& oldRect, const Osp::Graphics::Rectangle& newRect);

	
	/**
     * Override this method to indicate whether the specified @c width and @c height can be supported or 
	 * a new @c width and @c height should be applied instead of the specified values.
     *
     * @since           2.0
	 * @return          @c true if the specified @c width and @ height are supported, @n
	 *					else @c false
	 * @param[in, out]	width		The width that needs to be evaluated
 	 * @param[in, out]	height		The height that needs to be evaluated
     */
	virtual bool EvaluateSize(int& width, int& height);


// Lifecycle
protected:
    /**
     * This is the default constructor for this class.
     *
     * @since	2.0
     */
	CustomControlBase(void);


private:	
    /**
     * This is the copy constructor for the %CustomControlBase class.
     *
     * @since	2.0
     */	
	CustomControlBase(const CustomControlBase&);


    /**
     * This is the assignment operator for this class.
     *
     * @since   2.0
     */
	CustomControlBase& operator=(const CustomControlBase&);

	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void CustomControlBase_Reserved1(void) {}


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void CustomControlBase_Reserved2(void) {}	


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void CustomControlBase_Reserved3(void) {}


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void CustomControlBase_Reserved4(void) {}


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void CustomControlBase_Reserved5(void) {}
	
private:
	friend class CustomControlBaseEx;
	class CustomControlBaseEx* __pCustomControlBaseEx;

	friend class CustomControlBaseImpl;
	class CustomControlBaseImpl* GetImpl(void) const;
}; // CustomControlBase

}; }; // Osp::Ui

#endif // _FUI_CUSTOM_CONTROL_BASE_H_