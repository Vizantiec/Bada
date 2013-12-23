/* $Change: 1035663 $ */
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
 * @file	FUiControl.h 
 * @brief	This is the header file for the Control class.
 *
 * This header file contains the declarations of the %Control class. 
 */
#ifndef _FUI_CONTROL_H_
#define _FUI_CONTROL_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiConfig.h"
#include "FGrpCanvas.h"
#include "FGrpColor.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FUiClassType.h"
#include "FUiIFocusEventListener.h"
#include "FUiIKeyEventListener.h"
#include "FUiITouchEventListener.h"
#include "FUiIDragDropEventListener.h"
#include "FUiITouchModeChangedEventListener.h"
#include "FUiCompositeMode.h"

// Forward declarations
namespace Osp { namespace Base { namespace Runtime { class IEvent; } } }
namespace Osp { namespace Ui { class Container; } }
namespace Osp { namespace Ui { class Window;    } }
namespace Osp { namespace Ui { class __CompositeModeController; } }
namespace Osp { namespace Ui { namespace Controls { class Frame; } } }
namespace Osp { namespace Ui { namespace Controls { class Popup; } } }
namespace Osp { namespace Ui { namespace Controls { class ContextMenu; } } }
namespace Osp { namespace Ui { namespace Controls { class UiBuilderControl; } } }
namespace Osp { namespace Ui { namespace Controls { class UiBuilder; } } }
namespace Osp { namespace Ui { namespace Controls { class Footer; } } }
namespace Osp { namespace Ui { namespace Controls { class Header; } } }
namespace Osp { namespace Ui { namespace Controls { class SearchBar; } } }
namespace Osp { namespace Ui { namespace Animations { class ControlAnimator; } } }
namespace Osp { namespace Ui {

/**
 * @class	Control
 * @brief	This class is the abstract base class of all the UI control classes.
 * @since	1.0
 *
 * @remarks	In order for a %Control to be displayed, it must first be bound to a native window. A %Control's native window is
 * created when it (or its ancestor) is added to a valid control containment hierarchy. A containment hierarchy is valid if and
 * only if the root of the hierarchy is an instance of the Window class.
 *
 * The %Control class is the abstract base class of all user interface elements. It encapsulates a native 
 * "window" of the underlying window system, and provides the infrastructure necessary for the 
 * elements to respond to user inputs. The %Control class also determines how a key event is dispatched 
 * and processed. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/controls.htm">UI Controls</a>.
 *
 *	
 * The following examples demonstrate how to use the %Control class.
 * 
 * Size and Position 
 * 
 * @code
 * // Sets the size
 * pControl->SetSize(100, 100); // 100 pixels wide and 100 pixels long
 *
 * // Sets the position
 * pControl->SetPosition(5, 5); // Control is drawn 5 pixels down and 5 pixels left from the top-left corner of its parent
 * @endcode
 *
 * Draw and Show 
 *
 * @code
 * Canvas* pCanvas = pControl->GetCanvasN(); // Gets the canvas
 *
 * //Draws on to its Canvas
 * pCanvas->Clear(Osp::Graphics::Color(255, 255, 255)); // Fills the pCanvas with white color
 * pControl->Show(); // Shows changes on screen
 * 
 * delete pCanvas;
 * @endcode
 *
 * Key and input focus
 * 
 * @code
 * // Implements MyKeyEventListener
 * IKeyEventListener* pKeyListener = new MyKeyEventListener();
 * pControl->SetFocus();
 * 
 * // __pKeyListern should be deleted after use.
 * pControl->AddKeyEventListener(*pKeyListener);
 * @endcode
 
 */
class _EXPORT_UI_ Control :
	public Osp::Base::Object
{
public:

// Lifecycle
public:
	/** 
	 * This is the destructor for this class. 
	 *
	 * @since	1.0
	 */	
	virtual ~Control(void);


// Operations
public:
	/**
	 * Adds the IFocusEventListener instance to the %Control instance. @n
	 * The added listener gets notified when the control gains or loses its focus.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 * @see			RemoveFocusEventListener()
	 */
	void AddFocusEventListener(const IFocusEventListener& listener);


	/**
	 * Adds the IKeyEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a key is pressed, released, or long-pressed.
	 *
	 * @since		1.0
	 * @param[in]	listener    The event listener to be added
	 * @see         RemoveKeyEventListener()
	 */
	void AddKeyEventListener(const IKeyEventListener& listener);


	/**
	 * Adds the ITouchEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a touch event such as a press or a release is fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 * @see			RemoveTouchEventListener()
	 */
	void AddTouchEventListener(const ITouchEventListener& listener);


    /**
	 * Adds the IDragDropEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a drag or a drop happens in the control.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 * @see			Osp::Ui::IDragDropEventListener::OnTouchDragged()
	 * @see			Osp::Ui::IDragDropEventListener::OnTouchDropped()
	 * @see			RemoveDragDropEventListener()
	 */
	void AddDragDropEventListener(const IDragDropEventListener& listener);


	/**
	 * Draws the control.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlDraw20 "here".
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  Note that this control cannot be displayed.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     Draw() updates the framebuffer of the control. Hence, invoke the Show() method to display 
	 *              the drawn control on the screen.
     * @see         Show()
	 */
	result Draw(void);

	/**
	 * @page	CompControlDraw20	Compatibility for Construct()
	 *
	 * @section	CompControlDraw20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# When the application is not in the foreground, this method returns E_SUCCESS instead of E_INVALID_OPERATION.
	 *
	 * @section	CompControlDraw20Resolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */


    /** 
     * Overrides this method to provide user-specific initialization code.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_FAILURE		The method has failed.
	 * @remarks		OnInitializing() is called when the control is successfully added to a container.
	 * @see			OnTerminating()
	 */
	virtual result OnInitializing(void);


	/**
	 * Called asynchronously when the user event which is sent by the SendUserEvent() method is dispatched to the control.
	 *
	 * @since		1.0
	 * @param[in]   requestId		The user-defined event ID
	 * @param[in]   pArgs			A pointer to the argument list
	 * @see			SendUserEvent()
	 */
	virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs);


	/** 
	 * Overrides this method to provide user-specific termination code.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_FAILURE		The method has failed.
	 * @remarks     OnTerminating() is called right before the control is removed successfully from the container.
	 * @see         OnInitializing()
 	 */
	virtual result OnTerminating(void);


	/**
	 * Draws the control asynchronously.
 	 *
 	 * @since		1.0
	 * @param[in]   show	Set to @c true to show the control, @n
	 *                      else @c false
	 * @remarks		RequestRedraw() posts a draw event in the event queue. The drawing requested by RequestRedraw() occurs when the draw event is fired to 
	 *				the control.
	 */
	void RequestRedraw(bool show = true) const;


	/**
	 * Sends a user event to the control.
	 *
	 * @since		1.0
	 * @param[in]   requestId		The user-defined event ID
	 * @param[in]   pArgs			A pointer to the argument list
	 * @remarks     The method posts a user event in the event queue and returns immediately to 
	 *              support the asynchronous actions of the framework.
	 * @see         OnUserEventReceived()
	 */
	void SendUserEvent(RequestId requestId, const Osp::Base::Collection::IList* pArgs) const;


	/**
     * Enables or disables the control. @n
     * Only an enabled control can respond to the user input. By default, the control is enabled.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	enable              The new state of the object
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  Note that this control cannot be displayed.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	virtual result SetEnabled(bool enable);


	/**
	 * Shows the control on the screen.
	 * 
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  Note that this control cannot be displayed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The control will be automatically moved to the top of the drawing stack when it is displayed by Show().
	 */
	virtual result Show(void);


// Accessors
public:
	/**
	 * Enables or disables the drag operation in the control.
	 *
	 * @since		1.0
	 * @param[in]	enable		Set to @c true to enable the drag operation, @n
	 *							else @c false
	 * @see			SetDropEnabled()
	 */
	void SetDragEnabled(bool enable);


	/**
	 * Enables or disables the drop operations in the control. 
	 * 
	 * @since		1.0
	 * @param[in]	enable		Set to @c true to enable the drop operations, @n
	 *							else @c false
	 * @remarks		To receive a drop event, the drag property of the control has to be enabled.
	 * @see			SetDragEnabled()
	 */
	void SetDropEnabled(bool enable);


  /**
	 * Gets the position and the size of the control.
	 *
	 * @since		1.0
	 * @param[out]	x		The x position of the top-left corner of the control
	 * @param[out]	y		The y position of the top-left corner of the control
     * @param[out]	width	The width of the rectangular region
     * @param[out]	height	The height of the rectangular region
	 * @remarks             The shape of the control is regarded as a rectangle which is defined by the top-left point and the width or height. @n
     *                      The position of the top-left point is relative to the top-left corner of the parent container. 
	 * @see                 SetBounds()
     */
    void GetBounds(int& x, int& y, int& width, int& height) const;


	/**
	 * Gets the position and the size of the control.
	 *
	 * @since		1.0
	 * @return		An instance of the rectangle that represents the position of the top-left corner, width, and height of the control
	 * @remarks     The shape of the control is rectangular which is defined by the top-left point, and the width or height. @n
	 *				The position of the top-left point is relative to the top-left corner of the parent container. 
	 * @see         SetBounds()
	 */
	Osp::Graphics::Rectangle GetBounds(void) const;


	/**
	 * Creates and returns a graphics canvas whose bounds (that is, the position and size) are equal to those of the control.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompGetCanvasN "here"
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_RESOURCE_UNAVAILABLE		A system error has occurred.
	 * @remarks		The method allocates an Osp::Graphics::Canvas whose bounds are equal to that of the control. It is the responsibility of the developer to 
	 *				deallocate the canvas after use. The canvas is guaranteed to be valid only if the properties of the parent controls of the canvas remain 
	 *				unchanged. Therefore, the previously allocated canvas must be deleted and a new canvas must be created using the GetCanvasN()method, if 
	 *				the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form instances (and between different Form instances) share a single frame-buffer. Therefore, if custom drawing is 
	 *				performed on the graphic canvas of Frame and Form, then it will appear on the screen regardless of the control that is currently visible 
	 *				on the screen.
	 * @see			GetCanvasN(int x, int y, int width, int height)
	 */
	Osp::Graphics::Canvas* GetCanvasN(void) const;


	/**
	 * Creates and returns a graphic canvas of the specified position and size in the control.
	 *
	 * @since		  1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *                For more information, see @ref CompGetCanvasN "here"
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	x							The x position relative to the top-left corner of the control
	 * @param[in]	y							The y position relative to the top-left corner of the control
	 * @param[in]	width						The width of the graphic canvas
	 * @param[in]	height						The height of the graphic canvas
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_OUT_OF_RANGE				The specified bounds do not intercept with the bounds of the control.
	 * @exception	E_RESOURCE_UNAVAILABLE		A system error has occurred.
	 * @remarks		Only the graphic canvas of the displayable controls can be obtained. If the specified area is not inside the control, the graphic canvas 
	 *				of the overlapped area between the control and the specified bound is returned. The method allocates an Osp::Graphics::Canvas. It is 
	 *				the responsibility of the developer to deallocate the canvas after use. @n                 
	 *				The canvas is guaranteed to be valid only if the properties of the parent control of the canvas remain unchanged. Therefore, the 
	 *				previously allocated canvas must be deleted and a new canvas must be created using the GetCanvasN()method if the size or position of the 
	 *				control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
 	 * @remarks		The Frame and Form instances (and between different Form instances) share a single frame-buffer. Therefore, if custom drawing is 
	 *				performed on the graphic canvas of Frame and Form, then it will appear on the screen regardless of the control that is currently visible 
	 *				on the screen.
	 * @code
	 * result
	 * MyForm::OnDraw(void)
	 * {
	 *   result r = E_SUCCESS;
	 *   Canvas* pCanvas = GetCanvasN();
	 *   if (pCanvas != null)
	 *   {
	 *      // Add your drawing code here
	 *   }
	 *   if (pCanvas)
	 *      delete pCanvas;
	 *   // Do not call Show(). It will be called automatically after OnDraw() callback.
	 *   return r;
	 * }
	 * @endcode
	 */
	Osp::Graphics::Canvas* GetCanvasN(int x, int y, int width, int height) const;


	/**
	 * Creates and returns a graphic canvas of the control of the specified position and size.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *               	For more information, see @ref CompGetCanvasN "here"
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	bounds					The bounds of the graphic canvas
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OUT_OF_RANGE			The specified bounds do not intercept with the bounds of the control.
	 * @exception	E_RESOURCE_UNAVAILABLE	A system error has occurred.
	 * @remarks		Only the graphic canvas of the displayable controls can be obtained. If the specified area is not inside the control, the graphics canvas 
	 *				of overlapped area between the control and the specified bound is returned. @n
	 *				The method allocates an Osp::Graphics::Canvas. It is the responsibility of the developers to deallocate the canvas after use. @n
	 *				The canvas is guaranteed to be valid only if the properties of the parent control of the canvas remains unchanged. Therefore, the 
	 *				previously allocated canvas must be deleted and a new canvas must be created using the GetCanvasN()method if the size or position of the 
	 *				control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
  	 * @remarks		The Frame and Form instances (and between different Form instances) share a single frame-buffer. Therefore, if custom drawing is 
	 *				performed on the graphic canvas of Frame and Form, then it will appear on the screen regardless of which control is currently visible on 
	 *				the screen.
	 */
	Osp::Graphics::Canvas* GetCanvasN(const Osp::Graphics::Rectangle& bounds) const;


	/**
	 * @page	CompGetCanvasN	Compatibility for GetCanvasN()
	 * @section	CompGetCanvasN	Issues
	 * Implementation of this method has the following issue: @n
	 * -# If all the conditions below are satisfied, the method will return the Canvas control whose position is relative to the top left corner of 
	 *  the ScrollPanel control regardless of the %Control instance's actual scroll position: @n
	 *		- The application is developed with bada API version 1.2. @n
	 *		- The control, for which the application wants to obtain the Canvas control, is a child of ScrollPanel.
	 *		- The position of the Canvas control is specified with respect to the top left corner of the view port of the %ScrollPanel control.
	 *
	 * @section	CompGetCanvasNResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * Otherwise, use GetCanvasN(int x, int y, int width, int height), but with the y value of the control minus the current scroll position of the 
	 * ScrollPanel.
	 *
	 * @par When the above conditions are satisfied:
	 * -# Adjust the y position of the Canvas control by the current scroll position of the ScrollPanel control (see GetScrollPosition()).
	 */


	/**
	 * Gets the height of the control.
	 *
	 * @since		1.0
	 * @return		The height of the control
	 * @see			GetBounds()
	 * @see			GetSize()
	 * @see			GetWidth()
	 */
	int GetHeight(void) const;


	/**
	 * @internal
	 * This is internal. If used in an application, the application can get rejected during 
	 * the certification process.
	 * Gets the handle of this control's native peer window.
	 *
	 * @since		1.0
	 * @return		The handle of this control's native peer window
	 */
	Handle GetHandle(void) const;


	/** 
	 * Gets the name of the control.
	 *
	 * @since		1.0
	 * @return		The name of the control
	 */
	Osp::Base::String GetName(void) const;


	/**
	 * Gets the position of the top-left corner of the control.
	 *
	 * @since		1.0
	 * @return		The position of the top-left corner of the control
	 * @remarks		The position of the top-left corner of the control is relative to the top-left corner of its parent Container.
	 * @see			GetBounds()
	 */
	Osp::Graphics::Point GetPosition(void) const;


	/**
	 * Gets the position of the top-left corner of the control.
	 *
	 * @since		1.0
	 * @param[out]	x			The x position of the top-left corner of the control
	 * @param[out]	y			The y position of the top-left corner of the control
	 * @remarks		The position of top-left corner of the control is relative to the top-left corner of its parent Container.
	 * @see			GetBounds()
	 */
	void GetPosition(int& x, int& y) const;


	/**
	 * Gets the parent of the control.
	 *
	 * @since		1.0
	 * @return		The current parent of the control
	 */
	Container* GetParent(void) const;


	/**
	 * Gets the size of the control.
	 *
	 * @since		1.0
	 * @param[out]	width		The width of the control
	 * @param[out]	height		The height of the control
	 * @see         GetBounds()
	 */
	void GetSize(int& width, int& height) const;


	/**
	 * Gets the size of the control.
	 *
	 * @since		1.0
	 * @return		The size of the control
	 * @see			GetBounds()
	 */
	Osp::Graphics::Dimension GetSize(void) const;


	/**
	 * Gets the x position of the control. @n
	 * The position of the control is relative to the top-left corner of its parent Container.
	 *
	 * @since		1.0
	 * @return		The x position of the control
	 * @see			GetBounds()
	 */
	int GetX(void) const;


	/**
	 * Gets the y position of the control. @n
	 * The position of the control is relative to the top-left corner of its parent Container.
	 *
	 * @since		1.0
	 * @return		The y position of the control
	 * @see			GetBounds()
	 */
	int GetY(void) const;


	/**
	 * Gets the width of the control.
	 *
	 * @since		1.0
	 * @return		The width of the control
	 * @see			GetBounds()
	 * @see			GetSize()
	 * @see			GetHeight()
	 */
	int GetWidth(void) const;
	
	/**
	 * Gets the minimum size of the control.
	 *
	 * @since		2.0
	 * @return		The minimum size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.	 
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined minimum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see   		IsResizable()
	 */
	Osp::Graphics::Dimension GetMinimumSize(void) const;
	
	/**
	 * Gets the maximum size of the control.
	 *
	 * @since		2.0
	 * @return		The maximum size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.	 
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined maximum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see   IsResizable()
	 */
	Osp::Graphics::Dimension GetMaximumSize(void) const;

	/**
	 * Removes the specified focus listener instance. @n
	 * The removed listener is not notified even when focus events are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddFocusEventListener()
	 */
	void RemoveFocusEventListener(const IFocusEventListener& listener);


	/**
	 * Removes the specified key event listener instance. @n
	 * The removed listener is not notified even when key events are fired.
	 *
	 * @since		1.0
 	 * @param[in]	listener 	The listener to be removed
	 * @see			AddKeyEventListener()
	 */
	void RemoveKeyEventListener(const IKeyEventListener& listener);


	/**
	 * Removes the specified touch event listener instance. @n
	 * The removed listener is not notified even when touch events are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddTouchEventListener()
	 */
	void RemoveTouchEventListener(const ITouchEventListener& listener);


	/**
	 * Removes the specified drag and drop event listener instance. @n
	 * The removed listener is not notified even when drag and drop events are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The listener to be removed
	 * @see			AddDragDropEventListener()
	 */
	void RemoveDragDropEventListener(const IDragDropEventListener& listener);


	/**
	 * @page	CompControlBoundsSetter20	Compatibility for SetPosition(), SetSize(), and SetBounds()
	 *
	 * @section	CompControlBoundsSetter20Issues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 * -# The methods return E_INVALID_OPERATION instead of E_INVALID_STATE when the control is not constructed. @n
	 * -# It is recommended to override all the bounds-related methods to define control-specific behaviors. @n
	 *	  For example, when overriding SetSize() without overriding SetBounds(), unexpected results can occur.
	 * -# There were no methods to query whether the control is movable and resizable.
	 * -# The width and height of the control must be greater than 0, else SetSize() and SetBounds() return E_INVALID_ARG exception.
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, while some other controls adjust their 
	 *	  bounds to the minimum size.
	 * -# The following issue is specific to the concrete type (class) of the control:
	 *		@li	The Popup control returns E_INVALID_ARG when the size of the control is greater than the screen size.
	 *
	 * @section	CompControlBoundsSetter20Resolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The methods return E_INVALID_STATE when the control is not constructed.
	 * -# The methods must not be overridden because the bounds of the control is dependent on the following properties: IsMovable(), IsResizable(), 
	 *	  GetMinimumSize(), and GetMaximumSize(). @n
	 *	  The CustomControlBase class is added to make the custom controls. The CustomControlBase::PrepareBoundsChange() and 
	 *	  CustomControlBase::OnBoundsChanged() methods will be overridden to define the control-specific behaviors. @n
	 * -# New query methods are added to check whether the control is movable and resizable. @n
	 *    These properties determine whether the methods below are supported:
	 *		@li	SetPosition() returns E_UNSUPPORTED_OPERATION, if the control is not movable.
	 *		@li	SetSize() returns E_UNSUPPORTED_OPERATION, if the control is not resizable.
	 *		@li	SetBounds() returns E_UNSUPPORTED_OPERATION, if the control is neither movable nor resizable.
	 * -# The width and height of the control can be 0, if its minimum width and height is 0.
	 * -# SetSize() and SetBounds() return E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the 
	 *    maximum size of the control.
	 * -# The following issue is specific to the concrete type (class) of the control.
	 * 			@li	The maximum size limit of the Popup control has been removed.
	 */
	
	 
	/**
	 * Sets the position and size of the control. @n
	 * The position is set at (@c x, @c y), and the @c width and @c height parameters respectively contain the width and height values of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompControlSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]	x               			The new x position of the control
	 * @param[in]	y              				The new y position of the control
	 * @param[in]	width           			The new width of the control
	 * @param[in]	height          			The new height of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method for bada API versions 2.0 onwards.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSize()
	 */ 
	virtual result SetBounds(int x, int y, int width, int height);

	
 	/**
	 * Sets the position and size of the control. 
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompControlSetBounds "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]	rect						The new bounds of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		Do not override this method for bada API versions 2.0 onwards.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0 onwards, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSize()
	 */  
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);


	/**
	 * @page	CompControlSetBounds	Compatibility for SetBounds()
	 *
	 * @section	CompControlSetBoundsIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If this control is added to a ScrollPanel control as a child, this control is positioned relative to the top-left corner of the screen, 
	 *    and not to that of the ScrollPanel control.
	 *
	 * @section	CompControlSetBoundsResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	 

	/** 
	 * Sets the name of the control.
	 *
	 * @since		1.0
	 * @param[in] 	name	The name of the control
	 */
	void SetName(const Osp::Base::String& name);

	 
	/**
	 * Sets the position of the control. 
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see issues in version @ref CompControlSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]   x               		The new x position of the control
	 * @param[in]   y               		The new y position of the control
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks     The x,y position of the control are relative to the top-left corner of its parent.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see			IsMovable()	 
	 */
	virtual result SetPosition(int x, int y);

	 
	/**
	 * Sets the relative position of the control. 
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see issues in version @ref CompControlSetPosition "1.2" and @ref CompControlBoundsSetter20 "2.0".
	 * @return		An error code
	 * @param[in]   Position				The new position
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported because this control is not movable.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		The position of the control is relative to the top-left corner of its parent.	 
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @see	SetBounds()
	 * @see	SetSize()
	 * @see	IsMovable()
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);
	
	/**
	 * @page	CompControlSetPosition	Compatibility for SetPosition()
	 * @section	CompControlSetPositionIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If this control is added to a ScrollPanel control as a child, this control is positioned relative to the top-left corner of the screen, 
	 *	  and not to that of the ScrollPanel control.
	 *
	 * @section CompControlSetPositionResolutions Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */

	 
	/**
	 * Sets the size of the control. @n
	 * The @c width and @c height parameters, respectively, contain the width and height values of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]   width           			The new width of the control
	 * @param[in]   height          			The new height of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see	IsResizable()
	 * @see	GetMinimumSize()
	 * @see	GetMaximumSize()
	 */
	virtual result SetSize(int width, int height);


	/**
	 * Sets the size of the control.
	 *
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlBoundsSetter20 "here".
	 * @return		An error code
	 * @param[in]	size             			The new width and height
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported because this control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		From bada API version 2.0, do not override this method.
	 * @remarks		In the bada API version prior to 2.0, the width and the height of the control must be greater than 0.
	 * @remarks		From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see		IsResizable()
	 * @see		GetMinimumSize()
	 * @see		GetMaximumSize()
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);

	
	/**
	 * Sets the minimum size of the control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	minSize						The new minimum size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.	 
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The method can affect the maximum and current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current maximum size or the control size is smaller than the new minimum size, they become the same as the new minimum size.
	 * @see		IsResizable()
	 */
	result SetMinimumSize(const Osp::Graphics::Dimension& minSize);
	
	/**
	 * Sets the maximum size of the control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	maxSize						The new maximum size of the control
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This control is not resizable.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.	 
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The method can affect the minimum size and the current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current minimum size or the control size is greater than the new maximum size, they become the same as the new maximum size.
	 * @see   IsResizable()
	 */
	result SetMaximumSize(const Osp::Graphics::Dimension& maxSize);

	
	/**
	 * Sets the focus to the control. @n
	 * This method is called if the control needs to listen to user input events such as key pressed.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions	 @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompControlSetFocus "here".
	 * @return			An error code
	 * @exception		E_SUCCESS           The method is successful.
	 * @exception		E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  	Note that this control cannot be displayed.
	 * @exception		E_INVALID_CONDITION	The control is not contained in, or is not the top z-order frame or form.
	 */
	virtual result SetFocus(void);

	/**
	 * @page	CompControlSetFocus	Compatibility for SetFocus()
	 * @section	CompControlSetFocusIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Even unfocusable controls return E_SUCCESS.
	 *
	 * @section	CompEditDateSetPositionResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */


	/** 
	 * Changes the show state of the control. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	state				The new show state
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									Note that this control cannot be displayed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     Even if this method is invoked, the control is not drawn or shown. @n
	 *              To draw and show the control, use the Draw() and Show() methods. @n
	 *              Once the show state of the control is set to @c false, the show state needs to be set to @c true again before the control is drawn and 
	 *				shown.
	 * @see			GetShowState()
	 * @see			Draw()
	 * @see			Show()
	 * 
	 */
	virtual result SetShowState(bool state);

	/**
 	 * Gets the control animator of the current instance of %Control.
	 *
 	 * @since		2.0
	 * @return		The control animator, @n
 	 *				else @c null if this instance is not constructed or not added to a parent or is non-animatable
	 */
	Osp::Ui::Animations::ControlAnimator* GetControlAnimator(void) const;

// Inquiry
public:
	/** 
	 * Checks whether the specified point is inside the control.
	 *
	 * @since		1.0
	 * @return		Set to @c true if the specified point is inside the control, @n
	 *				else @c false
	 * @param[in]	x		The x position of the point to be checked
	 * @param[in]	y		The y position of the point to be checked
	 * @remarks		The specified point must be defined relative to the top-left corner of the control.
	 */
	bool Contains(int x, int y) const;


	/** 
	 * Checks whether the specified point is inside the control.
	 *
	 * @since		1.0
	 * @return		@c true if the specified point is inside the control, @n
	 *				else @c false
	 * @param[in]	point	The point to be checked
	 */
	bool Contains(const Osp::Graphics::Point& point) const;


	/**
	 * Checks whether the control currently has the input focus.
	 *
	 * @since		1.0
	 * @return		@c true if the control currently has the input focus, @n
	 *				else @c false
	 * @remarks		If this method is called before the control is added to a parent, @c false is returned.
	 * @see			SetFocus()
	 */
	bool HasFocus(void) const;

	/**
	 * Checks whether the control is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the control is enabled, @n
	 *				else @c false
	 * @remarks     If this method is called before the control is added to a parent, @c false is returned.
	 * @see			SetEnabled()
	 */
	bool IsEnabled(void) const;


	/**
	 * Checks whether the control is currently visible on the screen.
	 *
	 * @since		1.0
	 * @return		@c true if the control is currently visible on the screen, @n
	 *				else @c false
	 * @remarks		If this method is called before the control is added to a parent, @c false is returned.
	 * @see			SetShowState()
	 * @see			GetShowState()
	 */
	bool IsVisible(void) const;


	/** 
	 * Checks whether the control is movable.
	 *
	 * @since		2.0
	 * @return		@c true if the position can be changed, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		When the control is not movable, SetPosition() and SetBounds() return E_UNSUPPORTED_OPERATION.
	 * @see			SetPosition()
	 * @see			SetBounds() 
	 */
	bool IsMovable(void) const;

	
	/**
	 * Checks whether the control is resizable.
	 *
	 * @since		2.0
	 * @return		@c true if the size can be changed, @n
	 * 				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		Even if this method returns @c true, the size can be changed internally.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		When the control is not resizable, SetSize(), SetBounds(), SetMinimumSize(), and SetMaximumSize() return E_UNSUPPORTED_OPERATION.
	 * @see		SetSize()
	 * @see		SetBounds() 
	 * @see		SetMinimumSize() 
	 * @see		SetMaximumSize() 
	 */
	bool IsResizable(void) const;

	
	/** 
	 * Gets the current show state of the control. 
	 *
	 * @since		1.0
	 * @return		The show state of the control
	 * @remarks		Even if the control's state is "show", the control may not be visible.
	 * @see         SetShowState()
	 * @see         IsVisible()
	 */
	bool GetShowState(void) const;


	/**
	 * Sets the focusability of the control. The non-focusable controls cannot take the key focus.
	 *
	 * @since		1.1
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									Note that the control does not permit to change its focus ability.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The focusability of the container classes like Panel is @c false by default.
 	 * @remarks		The RadioGroup class does not render the UI. Therefore, RadioGroup::SetFocusable() returns E_SYSTEM.
	 */
	result SetFocusable(bool focusable);


	/**
	 * Checks whether the control is focusable.
	 *
	 * @since	1.1
	 * @return	@c true if the control is focusable, @n
	 *			else @c false
	 * @remarks	The focusability of the container classes like Panel is @c false by default.
	 */
	bool IsFocusable(void) const;


	/**
	 * Checks whether the device is in the touch mode. @n
	 * When the user interacts with the device by touching it, the device is in the touch mode.
	 *
	 * @since	1.1
	 * @return	@c true if the device is in the touch mode, @n
	 *			else @c false
	 * @remarks	This method returns @c false, for devices with QWERTY keyboard. @n
	 *			The user can navigate the UI using directional keys.
	 */
	bool IsInTouchMode(void) const;


	/**
	 * Adds the ITouchModeChangedEventListener instance to the %Control instance. @n
	 * The added listener gets notified when the touch mode of the device is changed.
	 *
	 * @since		1.1
	 * @param[in]	listener		The event listener to be added
	 * @see			RemoveTouchModeChangedEventListener()
	 */
	void AddTouchModeChangedEventListener(const Osp::Ui::ITouchModeChangedEventListener& listener);


	/**
	 * Removes the ITouchModeChangedEventListener instance. @n
	 * The removed listeners are not notified even when the touch events are fired.
	 *
	 * @since		1.1
	 * @param[in]	listener	The listener to be removed
	 * @see			AddTouchModeChangedEventListener()
	 */
	void RemoveTouchModeChangedEventListener(const Osp::Ui::ITouchModeChangedEventListener& listener);


	/**
	 * Sets the composite mode for merging with other controls. 
	 *
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since 		1.1
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlSetCompositeMode "here".
	 * @return		An error code
	 * @param[in]	compositeMode				A composite mode
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_OPTION		The specified option is not supported. 
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported.   
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The RadioGroup class does not render the UI. @n
	 *				Therefore, RadioGroup::SetCompositeMode() returns E_SYSTEM.
	 * @remarks		The OverlayRegion will not be displayed correctly if the composite mode of the Form control is changed.
	 * @remarks		Since API version 3.0, only COMPOSITE_MODE_ALPHA_BLENDING is allowed.
	 *				Otherwise, this method returns E_UNSUPPORTED_OPERATION.
	 */
	result SetCompositeMode(Osp::Ui::CompositeMode compositeMode);

	/**
	 * @page	CompControlSetCompositeMode	Compatibility for SetCompositeMode()
	 *
	 * @section	CompControlSetCompositeModeIssues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If COMPOSITE_MODE_NONE is applied to the ScrollPanel control, the child controls of the ScrollPanel control are not composited to the screen 
	 *	  buffer when the scroll end effect is applied.
	 *
	 * @section	CompControlSetCompositeModeResolutions	Resolutions 
	 * The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	 */
	
	/**
	 * Gets the composite mode for merging with other controls. 
	 *
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since	1.1
	 * @return	The composite mode
	 * @exception	E_SUCCESS				The method was successful.
	 * @exception	E_INVALID_STATE			This instance is not initialized yet.
	 * @remarks		Since API version 3.0, this method only returns COMPOSITE_MODE_ALPHA_BLENDING.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Ui::CompositeMode GetCompositeMode(void) const;

	
	/**
	 * Sets the chroma key color value that is used for the control composition.
	 *
	 * @deprecated  This method is deprecated because chromakey color is not supported any more.
	 * @since 		1.1
	 * @return		An error code
	 * @param[in]	chromaKeyColor				The chroma key color
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION		The method is not supported.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		This method is not supported for the devices whose ScreenBitsPerPixel value is 32. @n
	 *				The RadioGroup class does not render the UI. Therefore, RadioGroup::SetChromaKeyColor() returns E_SYSTEM.
	 * @remarks		Since API version 3.0, this method always fails.
	 */
	result SetChromaKeyColor(Osp::Graphics::Color chromaKeyColor);
	
	
	/**
	 * Gets the chroma key color value which is used for the control composition.
	 *	 
	 * @deprecated  This method is deprecated because chromakey color is not supported any more.
	 * @since			1.1
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompControlGetChromaKeyColor "1.2" and @ref CompControlGetChromaKeyColor20 "2.0".
	 * @return		The chroma key color
	 * @remarks		If this control does not support COMPOSITE_MODE_CHROMA_KEY or the chroma key color is not modified explicitly, @n
	 *				Osp::Graphics::Color::COLOR_MAGENTA is returned as the default value for the devices whose ScreenBitsPerPixel value is 16 and @n
	 *				Osp::Graphics::Color(0, 0, 0, 0) is returned as the default value for the devices whose ScreenBitsPerPixel value is 16.
	 * @remarks		Since API version 3.0, this method always fails.
	 *          
	 */
	Osp::Graphics::Color GetChromaKeyColor(void) const;
	
	/**
	 * @page	CompControlGetChromaKeyColor20	Compatibility for GetChromaKeyColor()
	 * @section	CompControlGetChromaKeyColor20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# There is accuracy loss for the chroma key color.
	 * -# The class does not keep the chroma key color if the composite mode is changed to other modes from COMPOSIT_MODE_CHROMA_KEY.
	 *
	 * @section	CompControlGetChromaKeyColor20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	 
	 */
	
	/**
	 * @page	CompControlGetChromaKeyColor	Compatibility for GetChromaKeyColor()
	 * @section	CompControlGetChromaKeyColorIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# When GetChromaKeyColor() is called for RadioGroup, the application terminates abnormally.
	 *
	 * @section	CompControlGetChromaKeyColorResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */


    /**
     * Stops the current UI event dispatch sequence by indicating that the current input event is consumed.
     *
	 * @since 		2.0
     * @return		An error code
     * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @remarks		If this method is invoked during an UI event (key or touch) propagation sequence, the method will stop the propagation and
     *              consequently the system will not be notified of the event. @n
     *              The method will not have any effect if no UI event is being dispatched. @n
     *              It is recommended that this method is called within IKeyEventListener or ITouchEventListener to stop the event from propagating to the 
	 *				next step.
     */
    result ConsumeInputEvent(void);

// Constants
public:

// Lifecycle
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */	
	Control(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes an instance of this class.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed. @b since: @b 2.0
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_SYSTEM			A system error occurred.
	 */
	result Construct(void);

	 /**
	 * @page	CompControlConstruct20	Compatibility for Construct()
	 *
	 * @section	CompControlConstruct20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# Some controls do not return E_INVALID_STATE even though the control is already constructed. @n
	 * -# Some controls do not return E_OUT_OF_MEMORY even though the control fails to allocate internal resources. @n
	 * -# The width and height of the control must be greater than 0 @n
	 *	  E_INVALID_ARG exception is returned in case the width and height of the control are not greater than 0. @n
	 * -# When the size specified is smaller than the minimum size of the control, some controls return E_INVALID_ARG, some other controls adjust its bounds 
	 *	  to the minimum size. @n
	 * -# The following issue is specific to the concrete type (class) of the control. @n
	 * 		@li	The Popup control returns E_INVALID_ARG when the size of the control is greater than the screen size.
	 *
	 * @section	CompControlConstruct20Resolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n	
	 * -# The method returns E_INVALID_STATE when the control is already constructed. @n
	 * -# The method returns E_OUT_OF_MEMORY when the control fails to allocate internal resources. @n
	 * -# The method returns E_INVALID_ARG when the size specified is smaller than the minimum size of the control or greater than the maximum size of the 
	 *	  control.
	 * -# The width and height of the control can be 0, if its minimum width and height is 0.
	 * -# The following issues are specific to the concrete type (class) of the control.
	 *		@li	The maximum size limit of the Popup control has been removed.
	 */

// Accessors
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the default size of this control. The default size of a control
	 * determined by control creator.
	 *
	 * @since		1.0
	 * @return		The default size of the control
	 * @remarks		Note to implementers: the default size is used to create native window 
	 *				when the client has not specified the control's size and the control has no IControlUi.
	 */
	virtual Osp::Graphics::Dimension GetDefaultSize(void) const;


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This method determines whether the current control's bounds has been set.
	 *
	 * @since		1.0
	 * @return		@c true, if the current control's bounds are set @n
	 *				@c false, otherwise
	 */
	bool IsBoundsSet(void) const;


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the show state of the containment hierarchy.
	 *
	 * @since		1.0
	 * @return		@c true, if the states of the control and all of its ancestors are "show" @n
	 *				@c false, otherwise
	 * @remarks		Even if the control's state is "show", the control may not be visible.
	 * @see			GetShowState(), SetShowState(), IsVisible()
	 * 
	 */
	bool GetHierarchyShowState(void) const;



// Operations
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies the control that it is now added to a control containment hierarchy.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error occurred.
	 * @exception	E_INVALID_OPERATION	This control is currently assigned to a native peer window.
	 * @remarks		When this method is called, the method creates a native peer window and connects it to this control. @n
	 *				@b WARNING: This method should only be invoked by the framework.
	 */
	virtual result AddNotify(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies when the Control is added to a valid control containment hierarchy (that is, a hierarchy with an instance of Window class as the root).
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	parent				The parent of the control
	 * @param[in]	x					The x coordinate relative to the top-left corner of the control
	 * @param[in]	y					The y coordinate relative to the top-left corner of the control
	 * @param[in]	width				The width
	 * @param[in]	height				The height
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid, @n 
	 *									@c width or @c height is less than 1.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the 
	 *                                  execution of the specified operation.
	 *                                  Note: This Control is already bound to a native window.
	 * @exception	E_SYSTEM			A system error occurred.
	 * @remarks		Note to implementers: One must call this method when a 
	 *				Control instance is to be inserted to the native window 
	 *				hierarchy (that is, when a control is added to a container).
	 */
	virtual result AddToParent(const Container& parent, int x, int y, int width, int height);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Window.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the parent of the control.
	 *
	 * @since		1.0
	 * @param[in]	pParent		The parent of the control
	 */
	void SetParent(const Container* pParent);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Shows the specified rectangular region of this control on screen.
	 * 
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	x		The x coordinate relative to the top left corner of this control
	 * @param[in]	y		The x coordinate relative to the top left corner of this control
	 * @param[in]	width	The width of the rectangular region
	 * @param[in]	height	The height of the rectangular region
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the 
	 *                                  	execution of the specified operation.
	 *                                   	Note: This control cannot be displayed.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid. @n 
	 *										The specified bounds exceeds the bounds of this control.
	 * @exception	E_SYSTEM				A system error occurred.
	 * @remarks		The @c x and @c y must be defined relative to the top-left corner of this control.
	 */
	result Show(int x, int y, int width, int height);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies the control that it should be disconnected from the current native peer window.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error occurred.
	 * @remarks		@b WARNING: This method should only be invoked by the framework.
	 * @see			AddNotify()
	 */
	virtual result RemoveNotify(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the peerHandle of this control's native peer window.
	 *
	 * @since			1.0
	 * @return		The peerHandle of the control's native peer window
	 */
	virtual Handle GetPeerHandle(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Replace the composite mode controller.
	 *
	 * @since			1.1
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error occurred.
	 */
	result ReplaceCompositeModeController(__CompositeModeController* pCompositeModeController);

// Inquiry
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This method returns @c true if this control is displayable. A
	 * control is displayable if its native peer window is assigned to
	 * this control.
	 *
	 * @since			1.0
	 * @return		@c true, if the control is displayable @n
	 *				@c false, otherwise
	 */
	bool IsDisplayable(void) const;


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the control.
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method has failed.
	 */
	virtual result __Draw(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Determines this control's default focus ability.
	 *
	 * @since		1.0
	 */
	void SetDefaultFocusable(bool enable);


    /**
     * Gets the default key event listener.
     *
	 * @since		2.0
     * @return		The default key event listener, @n
	 *				else @c null if no listener is set or a system error has occurred
     * @see         SetDefaultKeyEventListener()
     */
    IKeyEventListener* GetDefaultkeyEventListener(void) const;


	/**
     * Sets the default key event listener.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	pDefaultListener	The default key event listener
     * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @remarks		The registered listener will be notified to handle the key events after all the application event listeners have been notified.
     * @see			GetDefaultkeyEventListener()
     */
    result SetDefaultKeyEventListener(const IKeyEventListener* pDefaultListener);


    /**
     * Gets the default touch event listener.
     *
	 * @since	2.0
     * @return	The default touch event listener, @n
	 *			else @c null if no listener is set or a system error has occurred
     * @see		SetDefaultTouchEventListener()
     */
    ITouchEventListener* GetDefaultTouchEventListener(void) const;


    /**
     * Sets the default touch event listener.
     *
	 * @since		2.0
     * @return		An error code
     * @param[in]	pDefaultListener	The default touch event listener
     * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @remarks		The registered listener will be notified to handle the touch events after all the application event listeners are notified.
     */
    result SetDefaultTouchEventListener(const ITouchEventListener* pDefaultListener);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Removes from the parent's list.
     *
	 * @since     	2.0
     */
    void RemoveFromParentList(void) const;

// Attributes
protected:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The handle of this object's native peer window.
	 *
	 * @since	1.0
	 */
	Handle	__handle;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The handle of this object's initial native peer window.
	 *
	 * @since	1.0
	 */
	Handle	__peerHandle;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Determines whether this object's bounds are externally set.
	 *
	 * @since	1.0
	 */
	bool __boundsSet;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * A pointer to the parent.
	 *
	 * @since	1.0
	 */
	Container* __pParent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Specifies the relative-position and size of this object.
	 *
	 * @since	1.0
	 */
	Osp::Graphics::Rectangle __bounds;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Determines this control's show state.
	 *
	 * @since	1.0
	 */	
	bool __showState;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The control's background color.
	 *
	 * @since	1.0
	 */	
	Osp::Graphics::Color __bg;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The control's foreground color.
	 *
	 * @since	1.0
	 */	
	Osp::Graphics::Color __fg;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The name of this control
	 *
	 * @since	1.0
	 */	
	Osp::Base::String	__name;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The focus event.
	 *
	 * @since	1.0
	 */	
	Osp::Base::Runtime::IEvent*	__pFocusEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The key event.
	 *
	 * @since	1.0
	 */	
	Osp::Base::Runtime::IEvent*	__pKeyEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The touch event.
	 *
	 * @since	1.0
	 */	
	Osp::Base::Runtime::IEvent*	__pTouchEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The dragdrop event.
	 *
	 * @since	1.0
	 */	
	Osp::Base::Runtime::IEvent*	__pDragDropEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The redraw event.
	 *
	 * @since	1.0
	 */	
	Osp::Base::Runtime::IEvent*	__pRedrawEvent;


private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The dragdrop event.
	 * @since	1.0
	 */	
	bool __hidedInitially;


	// friends
	friend class Container;
	friend class Osp::Ui::Controls::Frame;
	friend class Osp::Ui::Controls::Popup;
	friend class Osp::Ui::Controls::ContextMenu;
	friend class Osp::Ui::Controls::UiBuilderControl;
	friend class Osp::Ui::Controls::UiBuilder;
	friend class Osp::Ui::Controls::Footer;
	friend class Osp::Ui::Controls::Header;
	friend class Osp::Ui::Controls::SearchBar;
	friend class __KeyEventAdaptor;
	friend class __TouchEventAdaptor;
	friend class __ControlManager;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The focus event.
	 * @since	1.0
	 */	
    Osp::Base::Object *	__pFocusEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The key event.
	 * @since	1.0
	 */	
    Osp::Base::Object *	__pKeyEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The touch event.
	 * @since	1.0
	 */	
	Osp::Base::Object *	__pTouchEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The redraw event.
	 * @since	1.0
	 */	
	Osp::Base::Object *	__pRedrawEventAdaptor;


	friend class ControlEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */
	class ControlEx* __pControlEx;
	
protected:
	friend class ControlImpl;

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
	class ControlImpl* GetImpl(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Replaces the implementation instance of this control
	 *
	 * @since         2.0
	 */
	void SetImpl(class ControlImpl* pImpl);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Checks if the implementation instance of this control already exists
	 * @since         2.0
	 */
	bool HasRefToImpl(void) const;
	

	/* Declarations for %Animation */

private:
	friend class Osp::Ui::Animations::ControlAnimator;

	/* END - Declarations for Animation */
};
}; }; //Osp::Ui
#endif//_FUI_CONTROL_H_

