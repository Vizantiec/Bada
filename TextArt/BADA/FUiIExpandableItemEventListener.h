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
 * @file	FUiIExpandableItemEventListener.h 
 * @brief	This is the header file for the %IExpandableItemEventListener interface.
 *
 * This header file contains the declarations of the %IExpandableItemEventListener interface. @n
 * If an item event is generated, a method of this interface is called.
 *
 */
#ifndef _FUI_IEXPANDABLEITEM_EVENT_LISTENER_H_
#define _FUI_IEXPANDABLEITEM_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FUiIItemEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	IExpandableItemEventListener 
 * @brief 		This interface implements a listener for the item events.
 * @deprecated  This listener is deprecated. There is no need to use this listener.
 * @since		1.0
 *
 * The %IExpandableItemEventListener interface implements a listener for the item events. 
 * A class that needs to process an item event
 * should implement this interface. The object created with that class is registered with a UI Control using the controls.
 * ExpandableList::AddExpandableItemEventListener() method. When the item event occurs, that instance's OnItemStateChanged() method is invoked. 
 */
class _EXPORT_UI_ IExpandableItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~IExpandableItemEventListener(void) {}

	/**
	 * Called when the state of CustomListItem in the ExpandableList is changed. @n
	 * If a main item is selected, the index of the sub-item is @c -1.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *    				For more information, see @ref CompIExpandableItemEventListenerOnItemStateChanged_1 "here".
	 * @param[in]  source		The source control from which the event is fired
	 * @param[in]  mainIndex	The main index of the item
	 * @param[in]  subIndex   	The sub index of the item
	 * @param[in]  itemId      	The item ID
	 * @param[in]  status  		The state of the item
	 * @remarks Implement this method in a class that derives %IExpandableItemEventListener to handle the user interaction at the %CustomListItem of the 
	 *			%ExpandableList.
	 */
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int mainIndex, int subIndex, int itemId, Osp::Ui::ItemStatus status) = 0;

	/**
	  * @page	CompIExpandableItemEventListenerOnItemStateChanged_1	Compatibility for OnItemStateChanged()
	  *
	  * @section	CompIExpandableItemEventListenerOnItemStateChanged_1Issues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# If %ExpandableList is constructed with CUSTOM_LIST_STYLE_MARK_WITH_DIVIDER or CUSTOM_LIST_STYLE_ONOFF_WITH_DIVIDER, this method is called when the 
	  *	   check box is selected. Another version of OnItemStateChanged() is called for CustomList, GroupedList, SlidableList, and SlidableGroupedList.
	  *
	  * @section	CompIExpandableItemEventListenerOnItemStateChanged_1Resolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	  */


	/**
	  * Called when the state of an element in %CustomListItem in %ExpandableList is changed. @n
	  * If a main item is selected, the index of the sub-item is @c -1.
	  *
	  * @since		1.0
	  * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	  *    				For more information, see @ref CompIExpandableItemEventListenerOnItemStateChanged_2 "here".
	  * @param[in]	source			The source control from which the event is fired
	  * @param[in]	mainIndex		The main index of the item
	  * @param[in]	subIndex		The sub index of the item
	  * @param[in]  itemId			The item ID
	  * @param[in]  elementId		The element ID
	  * @param[in]  status  		The state of the element
	  * @remarks Implement this method in a class that derives %IExpandableItemEventListener to handle the user interaction at the element in
	  *			%CustomListItem of %ExpandableList.
	  */
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int mainIndex, int subIndex, int itemId, int elementId, Osp::Ui::ItemStatus status) = 0;

	 /**
	  * @page	CompIExpandableItemEventListenerOnItemStateChanged_2	Compatibility for OnItemStateChanged()
	  *
	  * @section	CompIExpandableItemEventListenerOnItemStateChanged_2Issues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# If ExpandableList is constructed with CUSTOM_LIST_STYLE_RADIO_WITH_DIVIDER, this method is called with an incorrect element ID , when the check box 
	  *	   is selected. Another version of OnItemStateChanged() is called for CustomList, GroupedList, SlidableList, and SlidableGroupedList.
	  *
	  * @section	CompIExpandableItemEventListenerOnItemStateChanged_2Resolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	  */
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IEXPANDABLEITEM_EVENT_LISTENER_H_

