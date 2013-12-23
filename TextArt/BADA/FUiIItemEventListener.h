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
 * @file	FUiIItemEventListener.h 
 * @brief	This is the header file for the %IItemEventListener interface.
 *
 * This header file contains the declarations of the %IItemEventListener interface. @n
 * If an item event is generated, a method of this class is called. @n
 * So, if an application performs tasks related to the item event, use the methods of this class.
 *
 */
#ifndef _FUI_IITEM_EVENT_LISTENER_H_
#define _FUI_IITEM_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {
	/**
	 * @enum		ItemStatus
	 * Defines the constants used to identify the item state.
	 *
	 * @deprecated This enumeration is deprecated. Instead of using this enumeration, use the ListItemStatus enumeration.
	 * @since	1.0
	 */
	enum ItemStatus
	{
		ITEM_CHECKED = 0,		/**< The item has been checked (toggle of the check area) */
		ITEM_UNCHECKED,			/**< The item has been unchecked (toggle of the check area) */
		ITEM_SELECTED,			/**< The item has been selected (non-check area of the item) */
		ITEM_HIGHLIGHTED		/**< The item has been highlighted (non-check area of the item) @b since: @b 1.1 */
	};

/**
 * @interface		IItemEventListener 
 * @brief			This interface implements the listener for the item event.
 * @deprecated 		This listener is deprecated. Instead of using this listener, use IListViewItemEventListener.
 * @since			1.0
 *
 * The %IItemEventListener interface is the listener interface for receiving item events. The class that processes an item event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's 
 * AddItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that instance is invoked. 
 */
class _EXPORT_UI_ IItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~IItemEventListener(void) {}

	/**
	 * Called when an item event occurs.
	 *
	 * @since				1.0
	 * @param[in] 	source		The source of the event
 	 * @param[in] 	index		The index of the item
	 * @param[in] 	itemId		The item ID
	 * @param[in] 	status		The ItemStatus
	 */
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) = 0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IITEM_EVENT_LISTENER_H_

