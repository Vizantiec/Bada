// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiIFlashRenderingEventListener.h
 * @brief		This is the header file for the %IFlashRenderingEventListener interface.
 *
 * This header file contains the declarations of the %IFlashRenderingEventListener interface.
 * If a flash rendering event is generated, a method of this class is called.
 * 
 *
 */

#ifndef _FUI_IFLASH_RENDERINGEVENT_LISTENER_H_
#define _FUI_IFLASH_RENDERINGEVENT_LISTENER_H_

#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface       IFlashRenderingEventListener
 * @brief           This interface implements the listener for custom drawing
 * @since           2.0
 *
 * The %IFlashRenderingEventListener interface is the listener interface for custom drawing on the flash content. 
 * The class that processes a custom drawing event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddFlashRenderingEventListener() method. When the flash engine finishes
 * drawing the content, the OnFlashRenderingCompleted() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.flashappprogramming.help/html/dev_guide/render_custom_content.htm">Rendering Customized Content</a>.

 */

class _EXPORT_UI_ IFlashRenderingEventListener :
              public Osp::Base::Runtime::IEventListener
{
public:
    /**
    * This is the destructor for this class.
    *
    * @since           2.0
    */
	virtual ~IFlashRenderingEventListener(void) {}
	
	/**
	* Called when the drawing of each frame of the flash content is completed by the flash engine. @n
	* The LCD buffer is refreshed after this callback.
	* Developers should use the canvas provided and refrain from excessive rendering for better performance.
	*
	* @since           2.0
	* @param[in]       source       The source of the event
	* @param[in]       canvas       The canvas of a Flash control
	*
	*/
	virtual void OnFlashRenderingCompleted(const Osp::Ui::Control& source, Osp::Graphics::Canvas& canvas) = 0;

};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IFLASH_RENDERINGEVENT_LISTENER_H_


 

