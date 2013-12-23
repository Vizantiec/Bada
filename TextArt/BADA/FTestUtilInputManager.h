/* $$ */
/**
* Copyright (c) 2011 Samsung Electronics Co., Ltd.
* All rights reserved.
* 
* This software contains confidential and proprietary information 
* of Samsung Electronics Co., Ltd.
* The user of this software agrees not to disclose, disseminate or copy such 
* Confidential Information and shall use the software only in accordance with 
* the terms of the license agreement the user entered into with Samsung.
*/
/**
* @file     FTestUtilInputManager.h
* @brief    This is the header file for the InputManager class.
*
* This header file contains the declarations of the InputManager class.
*
*/


#ifndef _FTEST_UTIL_INPUT_MANAGER_H_
#define _FTEST_UTIL_INPUT_MANAGER_H_

#include <FBase.h>

namespace Osp { namespace Test { namespace Utility {

/**
* @if PRIVCORE
* @enum KeyCodeType
* Defines key code types.
* @since 2.0
* @privlevel CORE
* @endif	
*/
enum KeyCodeType
{
    KEY_CODE_TYPE_1 = 1,            /**< @if PRIVCORE	1 key @endif */         
    KEY_CODE_TYPE_2,                /**< @if PRIVCORE 	2 key @endif */         
    KEY_CODE_TYPE_3,                /**< @if PRIVCORE 	3 key @endif */         
    KEY_CODE_TYPE_4,                /**< @if PRIVCORE 	4 key @endif */         
    KEY_CODE_TYPE_5,                /**< @if PRIVCORE 	5 key @endif */         
    KEY_CODE_TYPE_6,                /**< @if PRIVCORE 	6 key @endif */         
    KEY_CODE_TYPE_7,                /**< @if PRIVCORE 	7 key @endif */         
    KEY_CODE_TYPE_8,                /**< @if PRIVCORE 	8 key @endif */         
    KEY_CODE_TYPE_9,                /**< @if PRIVCORE 	9 key @endif */         
    KEY_CODE_TYPE_0,                /**< @if PRIVCORE 	0 key @endif */         
    KEY_CODE_TYPE_SEND,             /**< @if PRIVCORE 	Send key @endif */         
    KEY_CODE_TYPE_END,              /**< @if PRIVCORE 	End key @endif */         
    KEY_CODE_TYPE_HASH,             /**< @if PRIVCORE 	Hash key @endif */         
    KEY_CODE_TYPE_ASTERISK,         /**< @if PRIVCORE 	Asterisk key @endif */         
    KEY_CODE_TYPE_CLEAR,	        /**< @if PRIVCORE 	Clear key @endif */         
    KEY_CODE_TYPE_SIM2MODE,	        /**< @if PRIVCORE 	Sim2 Mode key @endif */         
    KEY_CODE_TYPE_NU = 18,	        /**< @if PRIVCORE 	NU key @endif */         
    KEY_CODE_TYPE_ND = 20,	        /**< @if PRIVCORE 	ND key @endif */         
    KEY_CODE_TYPE_UP = 22,	        /**< @if PRIVCORE 	Up directional key @endif */         
    KEY_CODE_TYPE_DOWN = 23,        /**< @if PRIVCORE 	Down directional key @endif */         
    KEY_CODE_TYPE_NL = 24,	        /**< @if PRIVCORE 	NL key @endif */         
    KEY_CODE_TYPE_NR = 25,	        /**< @if PRIVCORE 	NR key @endif */         
    KEY_CODE_TYPE_CAMERA = 26,      /**< @if PRIVCORE 	Camera Key @endif */         
    KEY_CODE_TYPE_NC = 27,	        /**< @if PRIVCORE 	NC/ OK / WAP key @endif */         
    KEY_CODE_TYPE_SOFTLEFT = 28,    /**< @if PRIVCORE 	Soft1 (Menu) key @endif */         
    KEY_CODE_TYPE_SOFTRIGHT = 29,   /**< @if PRIVCORE 	Soft2 key @endif */         
    KEY_CODE_TYPE_POWER = 30,       /**< @if PRIVCORE 	Power key @endif */         
    KEY_CODE_TYPE_SWITCH = 31,      /**< @if PRIVCORE 	Switch key @endif */         
    KEY_CODE_TYPE_HOME = 32,        /**< @if PRIVCORE 	Home key @endif */         
    KEY_CODE_TYPE_HOLD = 33,        /**< @if PRIVCORE 	Hold key @endif */         
    KEY_CODE_TYPE_A = 65,           /**< @if PRIVCORE 	A key @endif */         
    KEY_CODE_TYPE_B,                /**< @if PRIVCORE 	B key @endif */         
    KEY_CODE_TYPE_C,                /**< @if PRIVCORE 	C key @endif */         
    KEY_CODE_TYPE_D,                /**< @if PRIVCORE 	D key @endif */         
    KEY_CODE_TYPE_E,                /**< @if PRIVCORE 	E key @endif */         
    KEY_CODE_TYPE_F,                /**< @if PRIVCORE 	F key @endif */         
    KEY_CODE_TYPE_G,                /**< @if PRIVCORE 	G key @endif */         
    KEY_CODE_TYPE_H,                /**< @if PRIVCORE 	H key @endif */         
    KEY_CODE_TYPE_I,                /**< @if PRIVCORE 	I key @endif */         
    KEY_CODE_TYPE_J,                /**< @if PRIVCORE 	J key @endif */         
    KEY_CODE_TYPE_K,                /**< @if PRIVCORE 	K key @endif */         
    KEY_CODE_TYPE_L,                /**< @if PRIVCORE 	L key @endif */         
    KEY_CODE_TYPE_M,                /**< @if PRIVCORE 	M key @endif */         
    KEY_CODE_TYPE_N,                /**< @if PRIVCORE 	N key @endif */         
    KEY_CODE_TYPE_O,                /**< @if PRIVCORE 	O key @endif */         
    KEY_CODE_TYPE_P,                /**< @if PRIVCORE 	P key @endif */         
    KEY_CODE_TYPE_Q,                /**< @if PRIVCORE 	Q key @endif */         
    KEY_CODE_TYPE_R,                /**< @if PRIVCORE 	R key @endif */         
    KEY_CODE_TYPE_S,                /**< @if PRIVCORE 	S key @endif */         
    KEY_CODE_TYPE_T,                /**< @if PRIVCORE 	T key @endif */         
    KEY_CODE_TYPE_U,                /**< @if PRIVCORE 	U key @endif */         
    KEY_CODE_TYPE_V,                /**< @if PRIVCORE 	V key @endif */         
    KEY_CODE_TYPE_W,                /**< @if PRIVCORE 	W key @endif */         
    KEY_CODE_TYPE_Y,                /**< @if PRIVCORE 	X key @endif */         
    KEY_CODE_TYPE_X,                /**< @if PRIVCORE 	Y key @endif */         
    KEY_CODE_TYPE_Z,                /**< @if PRIVCORE 	Z key @endif */         
    KEY_CODE_TYPE_SPACE = 97,       /**< @if PRIVCORE 	Space key @endif */         
    KEY_CODE_TYPE_ALT = 99,         /**< @if PRIVCORE 	Alt/Fn key @endif */         
    KEY_CODE_TYPE_ENTER = 100,      /**< @if PRIVCORE 	Enter key @endif */         
    KEY_CODE_TYPE_DOT = 101,        /**< @if PRIVCORE 	Dot key @endif */         
    KEY_CODE_TYPE_BACKSPACE = 102,  /**< @if PRIVCORE 	Backspace key @endif */         
    KEY_CODE_TYPE_COMMA = 103,      /**< @if PRIVCORE 	Comma key @endif */         
    KEY_CODE_TYPE_SYM = 105,        /**< @if PRIVCORE 	Language Symbol key @endif */         
    KEY_CODE_TYPE_QUESTION = 106,   /**< @if PRIVCORE 	Question key @endif */         
    KEY_CODE_TYPE_MSG = 107,        /**< @if PRIVCORE 	Message key @endif */         
    KEY_CODE_TYPE_INTERNET = 108,   /**< @if PRIVCORE 	Internet key @endif */         
    KEY_CODE_TYPE_MAX,              /**< @if PRIVCORE 	Placeholder @endif */         
};


/**
* @if PRIVCORE
* @enum TouchEventType
* Defines touch event types.
* @since 2.0
* @privlevel CORE
* @endif	
*/
enum TouchEventType
{
    TOUCH_EVENT_TYPE_PRESSED,           /**< @if PRIVCORE  Touch pressed event type	 @endif */         
    TOUCH_EVENT_TYPE_LONG_PRESSED,      /**< @if PRIVCORE  Touch long pressed event type	 @endif */         
    TOUCH_EVENT_TYPE_RELEASED,          /**< @if PRIVCORE  Touch released event type	 @endif */         
    TOUCH_EVENT_TYPE_MOVED,             /**< @if PRIVCORE  Touch moved event type	 @endif */         
    TOUCH_EVENT_TYPE_DOUBLE_PRESSED,    /**< @if PRIVCORE  Touch double pressed event type	 @endif */         
};


/**
* @if PRIVCORE
* @class InputManager
* @brief This is a class for generating inputs such as touch and key. It provides 
*        functionalities to simulate user inputs.
* @since 2.0
* @privlevel CORE
*
* The %InputManager class provides methods to generate user's input events such as 
*        touch and key events for helping test application.
* @endif	
*/
class InputManager : public Osp::Base::Object
{
public:
    /**
    *
    * This is a default constructor for this class.
    *
    * @since 2.0
    * @privlevel CORE
    */
    InputManager(void);


    /**
    *
    * This is a destructor for this class.
    *
    * @since 2.0
    * @privlevel CORE
    */
    virtual ~InputManager(void);

public:
    /**
    * Generates a key pressed event
    *
    * @since 2.0
    * @privlevel CORE
    * @privgroup INPUT_MANAGER
    *
    * @return		An error code
    * @param[in]	keyCode	        The code of a key for which key press event has to be generated
    * @exception    E_SUCCESS		The method was successful.
    * @exception    E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
    * @exception    E_SYSTEM	    A system error occurred.
    */
    static result GenerateKeyPressedEvent(KeyCodeType keyCode);

    /**
    * Generates a key released event
    *
    * @since 2.0
    * @privlevel CORE
    * @privgroup INPUT_MANAGER
    *
    * @return		An error code
    * @param[in]	keyCode	    The code of a key for which key release event has to be generated
    * @exception    E_SUCCESS		The method was successful.
    * @exception    E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
    * @exception    E_SYSTEM	    A system error occurred.
    */
    static result GenerateKeyReleasedEvent(KeyCodeType keyCode);

    /**
    * Generates a key long pressed event
    *
    * @since 2.0
    * @privlevel CORE
    * @privgroup INPUT_MANAGER
    *
    * @return		An error code
    * @param[in]	keyCode	    The code of a key for which key release event has to be generated
    * @exception    E_SUCCESS		The method was successful.
    * @exception    E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
    * @exception    E_SYSTEM	    A system error occurred.
    */	
    static result GenerateKeyLongPressedEvent(KeyCodeType keyCode);

    /**
    * Generates a touch event
    *
    * @since 2.0
    * @privlevel CORE
    * @privgroup INPUT_MANAGER
    *
    * @return		An error code
    * @param[in]	touchEvent  TouchEventType which need to be generated
    * @param[in]	x	        X coordinate for the TouchStatus
    * @param[in]	y	        Y coordinate for the TouchStatus	 
    * @exception    E_SUCCESS		The method was successful.
    * @exception    E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
    * @exception    E_SYSTEM	    A system error occurred.
    */	
    static result GenerateTouchEvent(TouchEventType touchEvent, int x, int y);
	
private:
    friend class InputManagerEx;
    class InputManagerEx* __pInputManagerEx; // forward declaration InputManagerEx
    

};
}}}
#endif

