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
 * @file		FUiIColorChangeEventListener.h 
 * @brief		This is the header file for the %IColorChangeEventListener interface.
 *
 * This header file contains the declarations of the %IColorChangeEventListener interface.
 * If a change event is generated, a method of this class is called.
 * So, for tasks related to change events, use the methods of this class.
 *
 */
#ifndef _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_
#define _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseObject.h"

namespace Osp { namespace Ui { class Control;    } }
namespace Osp { namespace Graphics { class Color; } }

namespace Osp {namespace Ui {
 /**
  * @interface	IColorChangeEventListener 
  * @brief		This interface implements the listener for the color change events.
  * @since		1.0
  *
  * The %IColorChangeEventListener interface is the listener interface for receiving color change events. 
  * The class that processes a color change event implements this interface, and the instance created with that class is
  *  registered with a UI control, using the control's AddColorChangeEventListener() method. When the color change event occurs,
  *  the OnColorChanged() method of that instance is invoked.
  *
  *  For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_colorpicker.htm">ColorPicker</a>.
  */
class IColorChangeEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IColorChangeEventListener(void) {}

	/**
	 * Called when there is a change in Color. @n
	 * The Color instance is passed as an input parameter. 
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 * @param[in]	color		The color
	 */
	virtual void OnColorChanged(const Osp::Ui::Control& source, const Osp::Graphics::Color& color) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_

