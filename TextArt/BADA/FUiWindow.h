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
 * @file		FUiWindow.h
 * @brief		This is the header file for the %Window class.
 *
 * This header file contains the declarations of the Window class.
 */
#ifndef _FUI_WINDOW_H_
#define _FUI_WINDOW_H_

// Includes
#include "FBaseTypes.h"
#include "FUiConfig.h"
#include "FUiContainer.h"
#include "FUiIWindowEventListener.h"

// Forward declarations
namespace Osp { namespace Base { namespace Runtime { class IEvent; } } }

namespace Osp { namespace Ui {

/**
 * @enum	ScreenType
 * Defines the screen type.
 *
 * @since	1.0
 */
enum ScreenType
{
	/**
	*	The invalid Screen 
	*/
	SCREEN_INVALID = -1,    

	/**
	*	The Screen 0: Default screen
	*/
	SCREEN_0	   =  0,

	/**
	*	The Screen 1
	*/
	SCREEN_1,	  

	/**
	*	The Screen 2
	*/
	SCREEN_2,

	/**
	*	The Screen 3
	*/
	SCREEN_3,

	/**
	*	The Screen 4
	*/
	SCREEN_4,

	/**
	*	The Screen 5
	*/
	SCREEN_5,

	/**
	*	The Screen 6
	*/
	SCREEN_6,

	/**
	*	The Screen 7
	*/
	SCREEN_7,

	/**
	*	The Screen 8
	*/
	SCREEN_8,

	/**
	*	The Screen 9
	*/
	SCREEN_9,	

	/**
	*	The Screen max
	*/
//	SCREEN_MAX
};


/**
 * @enum	WindowState
 * Defines the state of Window.
 *
 * @since	1.0
 */
enum WindowState
{
	WINDOW_STATE_INITIALIZED	= 0x0000,	/**< The initial state of the window */
	WINDOW_STATE_ACTIVATED		= 0x0001, 	/**< The state indicates that the window is the topmost window */
	WINDOW_STATE_DEACTIVATED	= 0x0002,	/**< The state indicates that the window is not the topmost window */
}; // WindowState


/**
 * @class	Window 
 * @brief	This class provides abstract top-level 'window' objects.
 * @since	1.0
 *
 * The %Window class is an abstract base class, which represents a top-level UI element, such as Frame, MessageBox, or Popup. The descendants of a %Window can exist outside of their applications's bounds. 
 *
 */
class _EXPORT_UI_ Window :
	public Container
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Window(void) = 0;


// Operation
public:
	/**
	* Adds the listener instance. @n
	* The added listener can listen to events when they are fired. 
	*
	* @since		1.0
	* @param[in]	listener 	The event listener to be added
	* @see			RemoveWindowEventListener(), Osp::Ui::IWindowEventListener
	*/
	void AddWindowEventListener(const Osp::Ui::IWindowEventListener& listener);


	/**
	* Removes a listener instance. @n
	* The removed listener cannot listen to events when they are fired.
	*
	* @since		1.0
	* @param[in]	listener 	The listener to be removed
	* @see			AddWindowEventListener()
	*/
	void RemoveWindowEventListener(const Osp::Ui::IWindowEventListener& listener);


	/**
	 * Shows the %Window control.
	 * 
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (that is, this control cannot be 
	 *									displayed).
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result Show(void);


// Accessor
public:
	/**
	 * Gets the screen to which the window belongs.
	 *
	 * @since		1.0
	 * @return		The screen to which the window belongs
	 */
	ScreenType GetScreen(void) const;


	/**
	 * Gets the current state of the window.
	 *
	 * @since		1.0
	 * @return		The current state of the window
	 */
	WindowState GetWindowState(void) const;


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
	Window(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes an instance of Window.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	x				The x coordinate relative to the top left corner of the pScreen
	 * @param[in]	y				The y coordinate relative to the top left corner of the pScreen
	 * @param[in]	width			The width of the Window
	 * @param[in]	height			The height of the Window
	 * @param[in]	screenType		The screen of the Window
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid. 
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	result Construct(int x, int y, int width, int height, ScreenType screenType = SCREEN_0);


// Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Window.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the state of the window.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	newState		The new window state
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 */
	result SetWindowState(WindowState newState);


// Attribute
protected:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Indicates the current state of this window.	
	 *
	 * @since	1.0
	 */
	WindowState __state;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The virtual screen.	
	 *
	 * @since	1.0
	 */
	ScreenType __screenType;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The window event.	
	 *
	 * @since	1.0
	 */
	Osp::Base::Runtime::IEvent* __pWindowEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The window event adaptor
	 *
	 * @since	1.0
	 */	
	Osp::Base::Object *	__pWindowEventAdaptor;

private:
	friend class __WindowEventAdaptor;
	friend class WindowEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */		
	class WindowEx* __pWindowEx;

protected:
	friend class WindowImpl;
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
	class WindowImpl* GetImpl(void) const;

};
}; };// Osp::Ui
#endif //_FUI_WINDOW_H_

