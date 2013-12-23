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
* @file		FUiIDragDropEventListener.h 
* @brief	This is the header file for the %IDragDropEventListener interface.
*
* This header file contains the declarations of the %IDragDropEventListener interface.
*/
#ifndef _FUI_IDRAG_DROP_EVENT_LISTENER_H_
#define _FUI_IDRAG_DROP_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FBaseTypes.h"
#include "FGraphics.h"

// Forward declarations

// Forward declarations
namespace Osp { namespace Ui { class Control;    } }

namespace Osp { namespace Ui  {
/**
 * @interface	IDragDropEventListener
 * @brief		This interface implements the listener for a drag and drop event.
 * @since		1.0
 *
 * The %IDragDropEventListener interface is the listener interface for receiving drag and drop events. 
 * The class that processes a drag and drop event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddDragDropEventListener() method. When the drag and drop event occurs, a
 * method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.

 */
class _EXPORT_UI_ IDragDropEventListener :
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
	virtual ~IDragDropEventListener(void) {}

	/**
	 * Called when an entity is dragged. 
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	startPosition	The start position
	 * @param[in] 	currentPosition	The current position
	 */
	virtual void OnTouchDragged(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& startPosition, const Osp::Graphics::Point& currentPosition) = 0;

	/**
	 * Called when an entity is dropped.
	 *
	 * @since		1.0
	 * @param[in] 	source			The source of the event
	 * @param[in] 	startPosition	The start position
	 * @param[in] 	currentPosition	The current position
	 */
	virtual void OnTouchDropped(const Osp::Ui::Control& source, 
		const Osp::Graphics::Point& startPosition, const Osp::Graphics::Point& currentPosition) = 0;
};

} ;} ;// Osp::Ui::Window
#endif// _FUI_IDRAG_DROP_EVENT_LISTENER_H_

