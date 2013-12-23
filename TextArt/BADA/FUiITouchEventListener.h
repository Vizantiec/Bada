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
* @file		FUiITouchEventListener.h 
* @brief	This is the header file for the %ITouchEventListener interface.
*
* This header file contains the declarations of the %ITouchEventListener interface.
*/
#ifndef _FUI_ITOUCH_EVENT_LISTENER_H_
#define _FUI_ITOUCH_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FBaseTypes.h"
#include "FGraphics.h"
#include "FUiTouch.h"

// Forward declarations
namespace Osp { namespace Ui { class Control; } }

namespace Osp { namespace Ui  {

/**
 * @interface		ITouchEventListener
 * @brief			This interface is used as the argument to the touch event listener.
 * @since			1.0
 *
 * The %ITouchEventListener interface is the listener interface for receiving touch events. 
 * The class that processes a touch event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddTouchEventListener() method. When the touch event occurs, a method of that instance is
 * invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.

 */
class _EXPORT_UI_ ITouchEventListener :
    public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~ITouchEventListener(void) {}

	/**
	 * Called when an entity is touch pressed. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchPressed(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo & touchInfo) = 0;

	/**
	 * Called when an entity is touched and held for a long time. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchLongPressed(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when an entity is touch released. 
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *               	For more information, see @ref CompITouchEventListenerOnTouchReleased "here".
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchReleased(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;
		
	/**
	 * @page	CompITouchEventListenerOnTouchReleased Compatibility for OnTouchReleased()
	 *
	 * @section	CompITouchEventListenerOnTouchReleasedIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# When drag and drop are enabled, OnTouchPressed() is called, but OnTouchReleased() is not called.
	 *
	 * @section	CompITouchEventListenerOnTouchReleasedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n  
	 *
	 * @par When working with bada API versions prior to 2.0:
	 * -# Perform all work necessary in IDragDropEventListener::OnTouchDropped().
	 */

	/**
	 * Called when an entity is touch moved. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchMoved(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when an entity is touched and double-pressed. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchDoublePressed(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when an entity becomes touch focus-in. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchFocusIn(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when an entity becomes touch focus-out. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information 
	 */
	virtual void OnTouchFocusOut(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo) = 0;
};

} ;} ;// Osp::Ui::Window
#endif// _FUI_ITOUCH_EVENT_LISTENER_H_

