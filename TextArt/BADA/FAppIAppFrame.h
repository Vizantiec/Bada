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
 * @file			FAppIAppFrame.h 
 * @brief			This is the header file for the %IAppFrame interface.
 * 
 * This header file contains the declarations of the %IAppFrame interface.
 */

#ifndef _FAPP_IAPP_FRAME_H_
#define _FAPP_IAPP_FRAME_H_


#include "FAppConfig.h"


namespace Osp { namespace Graphics { class Canvas; }; };
namespace Osp { namespace Ui { class IKeyEventListener; }; };
namespace Osp { namespace Ui { class ITouchEventListener; }; };
namespace Osp { namespace Ui { class IWindowEventListener; }; };
namespace Osp { namespace Ui { namespace Controls { class Frame; }; }; };


namespace Osp { namespace App {


/**
 * @interface	IAppFrame
 * @brief		This interface provides the methods for the application frame.
 * @since		1.0
 *
 * The %IAppFrame interface provides the methods for the application frame. A frame is the outermost boundary of the application UI.
 */
class IAppFrame
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~IAppFrame(void) {}


// Operation
public:
	/**
	 * Gets the values of the frame's canvas.
	 *
	 * @since		1.0
	 * @return	A pointer to the Canvas class
	 */
	virtual Osp::Graphics::Canvas* GetCanvasN(void) const = 0;


	/**
	 * Adds a key event listener to the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %IKeyEventListener instance to add
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddKeyEventListener(const Osp::Ui::IKeyEventListener& listener) = 0;


	/**
	 * Removes an existing key event listener from the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %IKeyEventListener instance to remove
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveKeyEventListener(const Osp::Ui::IKeyEventListener& listener) = 0;


	/**
	 * Adds a touch event listener to the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %ITouchEventListener instance to add
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddTouchEventListener(const Osp::Ui::ITouchEventListener& listener) = 0;


	/**
	 * Removes an existing touch event listener from the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %ITouchEventListener instance to add
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveTouchEventListener(const Osp::Ui::ITouchEventListener& listener) = 0;


	/**
	 * Adds a window event listener to the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %IWindowEventListener instance to remove
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddWindowEventListener(const Osp::Ui::IWindowEventListener& listener) = 0;


	/**
	 * Removes an existing window event listener from the frame.
	 *
	 * @since		1.0
	 * @return	An error code
	 * @param[in]	listener	An %IWindowEventListener instance to remove
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveWindowEventListener(const Osp::Ui::IWindowEventListener& listener) = 0;


	/**
	 * Returns the frame of the application.
	 *
	 * @since			1.0
	 * @return		A pointer to Osp::Ui::Controls::Frame if successful, @n
	 *              else @c null
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	This method cannot be supported.
	 */
	virtual Osp::Ui::Controls::Frame* GetFrame(void) = 0;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result Update(void) = 0;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual void EnableUpdate(bool enable) = 0;
};


}; };


#endif // _FAPP_IAPP_FRAME_H_
