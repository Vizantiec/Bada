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
 * @file	FUiIGroupedItemEventListener.h
 * @brief	This is the header file for the %IGroupedItemEventListener interface.
 *
 * This header file contains the declarations of the %IGroupedItemEventListener interface.
 */

#ifndef _FUI_IGROUPED_ITEM_EVENT_LISTENER_H_
#define _FUI_IGROUPED_ITEM_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FUiIItemEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

 /**
  * @interface		IGroupedItemEventListener 
  * @brief			This interface implements the listener for the events on the items of GroupedList.
  * @deprecated     This listener is deprecated. Instead of using this listener, use Osp::Ui::Controls::IGroupedListViewItemEventListener.
  * @since			1.0
  *
  *
  * The %IGroupedItemEventListener interface implements a listener for detecting state changes on the item of the grouped list. 
  * The class is registered with a GroupedList, using the control's AddGroupedItemEventListener() method. 
  */
class _EXPORT_UI_ IGroupedItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	IGroupedItemEventListener(void) {};
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~IGroupedItemEventListener(void) {};
	
	/**
	 * Called when the state of an element in the %CustomListItem instance in the %GroupedList instance is changed. 
	 * For example, this method is called when an element of %CustomListItem in %GroupedList is checked, unchecked, or selected.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompIGroupedItemEventListenerOnItemStateChanged "here".
	 * @param[in]  	source			The source of the event
	 * @param[in]  	groupIndex   	The index of the list group
	 * @param[in]  	itemIndex   	The index of the list item in the specified group 
	 * @param[in]  	itemId    		The item ID
	 * @param[in]  	elementId   	The element ID
	 * @param[in]  	status    		The state of the element
	 * @remarks     If %GroupedList or %SlidableGroupedList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is not called when the 
	 *				radio button is selected. Instead, OnItemStateChanged(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int itemId, 
	 *				Osp::Ui::ItemStatus status) is called.
	 */
	virtual void  OnItemStateChanged(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int itemId, int elementId, Osp::Ui::ItemStatus status)=0;
	
	/**
	 * @page	CompIGroupedItemEventListenerOnItemStateChanged	Compatibility for OnItemStateChanged()
	 * @section CompIGroupedItemEventListenerOnItemStateChangedIssues	Issues
	 * Implementation of this method in API versions prior to 1.2 has the following issue: @n
	 * -# If GroupedList or SlidableGroupedList is constructed with CUSTOM_LIST_STYLE_MARK_WITH_DIVIDER or CUSTOM_LIST_STYLE_ONOFF_WITH_DIVIDER, an 
	 *	  incorrect element ID is delivered. 
	 *
	 * @section CompIGroupedItemEventListenerOnItemStateChangedResolutions	Resolutions 
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use API version 1.2 or above. @n	 
	 */
	
	/**
	 * Called when the state of an item in the grouped list is changed. @n
	 * For example, this method is called when an item of the %GroupedList control is checked, unchecked, or selected.
	 *
	 
	 * @since		1.0
	 * @param[in]  	source			The source of the event
	 * @param[in]  	groupIndex   	The index of the list group
	 * @param[in]  	itemIndex   	The index of the list item in the specified group 
	 * @param[in]  	itemId     		The item ID
	 * @param[in]  	status    		The state of the item
	 * @remarks		If %GroupedList or %SlidableGroupedList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is called when the radio 
	 *				button is selected.
	 */
	virtual void  OnItemStateChanged(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int itemId, Osp::Ui::ItemStatus status)=0;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif //_FUI_IGROUPED_ITEM_EVENT_LISTENER_H_
