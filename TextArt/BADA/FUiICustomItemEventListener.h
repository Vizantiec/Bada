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
 * @file		FUiICustomItemEventListener.h 
 * @brief		This is the header file for the %ICustomItemEventListener class.
 *
 * This header file contains the declarations of the ICustomItemEventListener class. @n
 * If an item event is generated, a method of this class is called. @n
 * Application doing tasks related to the item event use the methods of this class.
 *
 */
#ifndef _FUI_ICUSTOMITEM_EVENT_LISTENER_H_
#define _FUI_ICUSTOMITEM_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FUiIItemEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	ICustomItemEventListener 
 * @brief		This interface implements the listener for the item event.
 * @deprecated  This listener is deprecated. Instead of using this listener, use Osp::Ui::Controls::IListViewItemEventListener.
 * @since		1.0
 *
 *
 * The %ICustomItemEventListener interface is the listener interface for receiving item events. The class that processes an item event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's 
 * AddCustomItemEventListener() method. When the item event occurs, the OnItemStateChanged() method of that object is invoked. 
 */
class _EXPORT_UI_ ICustomItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~ICustomItemEventListener(void) {}

	/**
	 * Called when the state of %CustomListItem is changed.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source control from which the event is fired
	 * @param[in]  	index    	The index of the item
	 * @param[in]  	itemId   	The Item ID
	 * @param[in]  	status   	The state of the item	 
	 * @remarks    	Implement this method in a class which derives %ICustomItemEventListener to handle the user interaction at the %CustomListItem.
	 * @remarks		If %CustomList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is called when the radio button is selected.
	 */
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) = 0;


	/**
	 * Called when the state of an element in the %CustomListItem is changed.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompICustomItemEventListenerOnItemStateChanged "here".
	 * @param[in]  		source		The source control from which the event is fired
	 * @param[in]  		index		The index of the item
	 * @param[in]  		itemId		The item ID
	 * @param[in]  		elementId	The element ID
	 * @param[in]  		status		The state of the element
	 * @remarks     	Implement this method in a class which derives %ICustomItemEventListener to handle the user interaction at the element in 
	 *					%CustomListItem.	 
	 * @remarks    	 	If %CustomList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is not called when the radio button is selected. 
	 *					Instead, OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status) is called.
	 */
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status) = 0;
	
	/**
	 * @page	CompICustomItemEventListenerOnItemStateChanged	Compatibility for OnItemStateChanged()
	 * @section	CompICustomItemEventListenerOnItemStateChangedIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If %CustomList is constructed with CUSTOM_LIST_STYLE_MARK_WITH_DIVIDER or CUSTOM_LIST_STYLE_ONOFF_WITH_DIVIDER, an incorrect element Id is 
	 *	  delivered. 
	 *
	 * @section	CompICustomItemEventListenerOnItemStateChangedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n	 
	 */
	
	
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ICUSTOMITEM_EVENT_LISTENER_H_

