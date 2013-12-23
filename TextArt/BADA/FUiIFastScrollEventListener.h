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
 * @file		FUiIFastScrollEventListener.h 
 * @brief	This is the header file for the %IFastScrollEventListener class.
 *
 * This header file contains the declarations of %IFastScrollEventListener class. @n
 * If an item event is generated, a method of this class will be called. @n
 * The applications that perform tasks related to the item event, call methods of this class.
 *
 */
#ifndef _FUI_IFASTSCROLL_EVENT_LISTENER_H_
#define _FUI_IFASTSCROLL_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseChar.h"
#include "FBaseRtIEventListener.h"
#include "FUiIItemEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	IFastScrollEventListener 
 * @brief		This interface implements the listener for fast scroll event.
 * @deprecated  This listener is deprecated. Instead of using this listener, use IFastScrollListener.
 * @since		1.0
 *
 *
 * The %IFastScrollEventListener interface is the listener interface for receiving item events. The class that processes a fast scroll
 * implements this interface, and the object created with that class is registered with a UI control, using the control's 
 * AddFastScrollEventListener method. When an item event occurs, the object's OnItemStateChanged() method is invoked. 
 */
class _EXPORT_UI_ IFastScrollEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~IFastScrollEventListener(void) {}

	/**
	 * Called when a main index is selected.
	 *
	 * @since				1.0
	 * @param[in] 	source				The source of the event
	 * @param[in] 	mainIndex			The main index
	 */
	virtual void OnMainIndexChanged(const Osp::Ui::Control& source, Osp::Base::Character& mainIndex)=0;

	/**
	 * Called when a sub index is selected.
	 *
	 * @since				1.0
	 * @param[in] 	source				The source of the event
	 * @param[in] 	mainIndex			The main index
	 * @param[in] 	subIndex			The sub index
	 */
	virtual void OnSubIndexChanged(const Osp::Ui::Control& source, Osp::Base::Character& mainIndex, Osp::Base::Character& subIndex)=0;

	/**
	 * Called when a main index is expanded.
	 *
	 * @since				1.0
	 * @param[in] 	source				The source of the event
	 * @param[in] 	mainIndex			The main index
	 */
	virtual void OnMainIndexSelected(const Osp::Ui::Control& source, Osp::Base::Character& mainIndex)=0;

	/**
	 * Called when a sub index is expanded.
	 *
	 * @since				1.0
	 * @param[in] 	source				The source of the event
	 * @param[in] 	mainIndex			The main index
	 * @param[in] 	subIndex			The sub index
	 */
	virtual void OnSubIndexSelected(const Osp::Ui::Control& source, Osp::Base::Character& mainIndex, Osp::Base::Character& subIndex)=0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IFASTSCROLL_EVENT_LISTENER_H_

