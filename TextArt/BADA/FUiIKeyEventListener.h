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
 * @file		FUiIKeyEventListener.h 
 * @brief		This is the header file for the %IKeyEventListener interface.
 *
 * This header file contains the declarations of the %IKeyEventListener interface. @n
 * If a key event is generated, a method of this class is called. @n
 * If an application performs tasks related to the key event, use the methods of this class.
 */
#ifndef _FUI_IKEY_EVENT_LISTENER_H_
#define _FUI_IKEY_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FBaseTypes.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
/**
 * @enum	KeyCode
 * Defines the list of keys supported by the system. @n
 * Note that certain keys may not be available on all devices. @n
 * Please use the Osp::Ui::KeyboardMap class to query the availability of a specific key on the target device.
 *
 * @since	1.0
 */
enum KeyCode
{
	/**
	 *	The invalid key
	 */
	KEY_INVALID		= 0x0000,	

	/**
	 *	The up side key
	 */
	KEY_SIDE_UP,

	/**
	 *	The down side key
	 */
	KEY_SIDE_DOWN,

	/**
	 *	The Ok key
	 */
	KEY_OK,

	/**
	 *	The clear key
	 */
	KEY_CLEAR,

	/**
	 *	The camera key
	 */
	KEY_CAMERA,

	/**
	*	The task switcher key
	*/
	KEY_SWITCH,

	/**
	*	The 0 key
	*/
	KEY_0,

	/**
	*	The 1 key
	*/
	KEY_1,

	/**
	*	The 2 key
	*/
	KEY_2,

	/**
	*	The 3 key
	*/
	KEY_3,

	/**
	*	The 4 key
	*/
	KEY_4,

	/**
	*	The 5 key
	*/
	KEY_5,

	/**
	*	The 6 key
	*/
	KEY_6,

	/**
	*	The 7 key
	*/
	KEY_7,

	/**
	*	The 8 key
	*/
	KEY_8,

	/**
	*	The 9 key
	*/
	KEY_9,

	/**
	*	The asterisk key
	*/
	KEY_ASTERISK,

	/**
	*	The sharp key
	*/
	KEY_SHARP,

	/**
	*	The left directional key
	*/
	KEY_LEFT,

	/**
	*	The up directional key
	*/
	KEY_UP,

	/**
	*	The down directional key
	*/
	KEY_DOWN,

	/**
	*	The right directional key
	*/
	KEY_RIGHT,

	/*
	*	The Placeholder
	*/
	KEY_MAX,
	
	/**
	 *	The A key @b since: @b 1.1
	 */
    KEY_A,

	/**
	 *	The B key @b since: @b 1.1
	 */
    KEY_B,
    
	/**
	 *	The C key @b since: @b 1.1
	 */    
    KEY_C,
    
	/**
	 *	The D key @b since: @b 1.1
	 */    
    KEY_D,
    
	/**
	 *	The E key @b since: @b 1.1
	 */    
    KEY_E,
    
	/**
	 *	The F key @b since: @b 1.1
	 */    
    KEY_F,
    
	/**
	 *	The G key @b since: @b 1.1
	 */    
    KEY_G,
    
	/**
	 *	The H key @b since: @b 1.1
	 */    
    KEY_H,
    
	/**
	 *	The I key @b since: @b 1.1
	 */    
    KEY_I,
    
	/**
	 *	The J key @b since: @b 1.1
	 */    
    KEY_J,
    
	/**
	 *	The K key @b since: @b 1.1
	 */    
    KEY_K,
    
	/**
	 *	The L key @b since: @b 1.1
	 */    
    KEY_L,

	/**
	 *	The M key @b since: @b 1.1
	 */    
    KEY_M,

	/**
	 *	The N key @b since: @b 1.1
	 */    
    KEY_N,

	/**
	 *	The O key @b since: @b 1.1
	 */    
    KEY_O,

	/**
	 *	The P key @b since: @b 1.1
	 */    
    KEY_P,

	/**
	 *	The Q key @b since: @b 1.1
	 */    
    KEY_Q,
 
	/**
	 *	The R key @b since: @b 1.1
	 */    
    KEY_R,

	/**
	 *	The S key @b since: @b 1.1
	 */    
    KEY_S,

	/**
	 *	The T key @b since: @b 1.1
	 */    
    KEY_T,

	/**
	 *	The U key @b since: @b 1.1
	 */    
    KEY_U,

	/**
	 *	The V key @b since: @b 1.1
	 */    
    KEY_V,

	/**
	 *	The W key @b since: @b 1.1
	 */    
    KEY_W,

	/**
	 *	The Y key @b since: @b 1.1
	 */    
    KEY_Y,

	/**
	 *	The X key @b since: @b 1.1
	 */    
    KEY_X,

	/**
	 *	The Z key @b since: @b 1.1
	 */    
    KEY_Z,

	/**
	 *	The backspace key @b since: @b 1.1
	 */    
    KEY_BACKSPACE,

	/**
	 *	The comma key @b since: @b 1.1
	 */    
    KEY_COMMA,

	/**
	 *	The enter key @b since: @b 1.1
	 */    
    KEY_ENTER,

	/**
	 *	The Caps Lock key @b since: @b 1.1
	 */    
    KEY_CAPSLOCK,

	/**
	 *	The Question key @b since: @b 1.1
	 */    
    KEY_QUESTION,

	/**
	 *	The Alt key @b since: @b 1.1
	 */    
    KEY_ALT,

	/**
	 *	The Language Symbol key @b since: @b 1.1
	 */    
    KEY_SYM,

	/**
	 *	The Language Setting key @b since: @b 1.1
	 */    
    KEY_SETTING,

	/**
	 *	The Space key @b since: @b 1.1
	 */    
    KEY_SPACE,

	/**
	 *	The Dot key @b since: @b 1.1
	 */    
    KEY_DOT,

	/**
	 *	The Function key @b since: @b 1.1
	 */    
    KEY_FN,

	/**
	 *	The camera half shutter key @b since: @b 1.1
	 */    
    KEY_CAMERA_HALF_SHUTTER,

	/**
	 *	The Character symbol 1 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_1,

	/**
	 *	The Character symbol 2 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_2,

	/**
	 * The Character symbol 3 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_3,

	/**
	 *	The Character symbol 4 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_4,

	/**
	 *	The Character symbol 5 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_5,

	/**
	 *	The Character symbol 6 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_6,

	/**
	 *	The Character symbol 7 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_7,

	/**
	 *	The Character symbol 8 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_8,

	/**
	 *	The Character symbol 9 key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_9,

	/**
	 *	The Character symbol A key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_A,

	/**
	 *	The Character symbol B key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_B,

	/**
	 *	The Character symbol C key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_C,

	/**
	 *	The Character symbol D key @b since: @b 1.1
	 */    
    KEY_CHAR_SYM_D,

	/**
	 *	The Character symbol E key @b since: @b 1.1 
	 */    
    KEY_CHAR_SYM_E,

	/**
	 *	The Character symbol F key @b since: @b 1.1 
	 */    
    KEY_CHAR_SYM_F,

	/**
	 *	The Special function 1 key @b since: @b 1.1
	 */    
    KEY_FN_1,

	/**
	 *	The Special function 2 key @b since: @b 1.1
	 */    
    KEY_FN_2,

	/**
	 *	The Special function 3 key @b since: @b 1.1
	 */    
    KEY_FN_3,

	/**
	 *	The Special function 4 key @b since: @b 1.1
	 */    
    KEY_FN_4,

	/**
	 *	The Special function 5 key @b since: @b 1.1
	 */    
    KEY_FN_5,

	/*
	 *	placeholder key
	 */    
    KEY_HARDWARE_MAX	
};


/**
 *  @enum 	KeyState
 *	Defines the state of the key.
 *
 * @since	1.0
 */
enum KeyState
{
	KEY_PRESSED		= 0x0001,	/**< The key is pressed		*/
	KEY_RELEASED	= 0x0002,	/**< The key is released		*/
	KEY_LONGPRESSED = 0x0003	/**< The key is pressed and held down over a predefined duration	*/
};

/**
 * @interface	IKeyEventListener 
 * @brief		This interface implements the listener for the key event.
 * @since		1.0
 * 
 * @remarks	Use the %ITextEventListener interface to listen to key events related to the virtual keypad used with EditField and EditArea.
 *
 * The %IKeyEventListener interface is the listener interface for receiving key events, which are fired when hardware keyboard keys are pressed or
 * released. The class that processes a key event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddKeyEventListener() method. When the key event occurs, a method of that
 * instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.
 * 
 

 *
 */
class _EXPORT_UI_ IKeyEventListener :
    public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 * This is the destructor for this class.
	 *
	 * @since				1.0
	 */
	virtual ~IKeyEventListener(void) {}


	/**
	 * Called when a key is pressed.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code 
	 */
	virtual void OnKeyPressed(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode) = 0;


	/**
	 * Called when a key is released.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code 
	 */
	virtual void OnKeyReleased(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode) = 0;


	/**
	 * Called when a key is pressed and held down for some time.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in] 	keyCode		The key code 
	 * @remarks	The key long pressed event is fired after the key pressed event is initially generated.
	 */
	virtual void OnKeyLongPressed(const Osp::Ui::Control& source, Osp::Ui::KeyCode keyCode) = 0;
};

 } }; // Osp::Ui

#endif //_FUI_IKEY_EVENT_LISTENER_H_

