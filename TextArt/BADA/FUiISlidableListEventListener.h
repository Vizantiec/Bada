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
 * @file	FUiISlidableListEventListener.h 
 * @brief	This is the header file for the %ISlidableListEventListener interface.
 *
 * This header file contains the declarations of the %ISlidableListEventListener interface. @n
 * If the event is generated, a method of this class is called. @n
 * So, if applications do jobs related to item events, use the methods of this class.
 *
 */
#ifndef _FUI_ISLIDABLELIST_EVENT_LISTENER_H_
#define _FUI_ISLIDABLELIST_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	ISlidableListEventListener 
 * @brief		This interface implements the listener for events on %SlidableList.
 * @deprecated  This listener is deprecated. Instead of using this listener, use Osp::Ui::Controls::IListViewItemEventListener.
 * @since		1.0
 *
 *
 * The %ISlidableListEventListener interface implements a listener for receiving scroll events on SlidableList. This listener is implemented
 * to allow the application to load the items as needed, as the user scrolls through the list.
 * The class is registered with a SlidableList, using the control's AddSlidableListEventListener() method. 
 */
class _EXPORT_UI_ ISlidableListEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~ISlidableListEventListener(void) {}

	/**
     * Called when the slidable list is about to be drawn and requests to set the properties of the list such as the total height.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnListPropertyRequested (const Osp::Ui::Control &source)	 = 0;
  
	/**
	 * Called when the items need to be loaded to the top.
	 *
	 * @since		1.0
	 * @param[in]	source		The source of the event
 	 * @param[in]	index		The index of the item
	 * @param[in]	numItems	The number of items
	 */
	virtual void OnLoadToTopRequested(const Osp::Ui::Control &source, int index, int numItems) = 0;

	/**
	 * Called when the items need to be loaded to the bottom.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
 	 * @param[in] 	index		The index of the item
	 * @param[in]	numItems	The number of items
	 */
	virtual void OnLoadToBottomRequested (const Osp::Ui::Control &source, int index, int numItems) = 0;

	/**
	 * Called when an item is about to be unloaded from memory. @n
	 * The user-allocated resources associated with the item should be freed before unloading, when OnUnloadItemRequested() is called.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *					For more information, see @ref CompISlidableListEventListenerOnUnloadItemRequested20 "here".
	 *
	 * @param[in]	source		The source of the event
	 * @param[in]	index		The index of the item
	 */
	virtual void OnUnloadItemRequested(const Osp::Ui::Control& source, int index) = 0;

	/**
	 * @page	CompISlidableListEventListenerOnUnloadItemRequested20	Compatibility for OnUnloadItemRequested ()
	 *
	 * @section	CompISlidableListEventListenerOnUnloadItemRequested20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
     * -# When the SlidableList is resized, the OnUnloadItemRequested() callback may be repeatedly invoked if the size of the internal item cache becomes 
	 *	  smaller than the number of items that can be shown at a time.
	 *
	 * @section CompISlidableListEventListenerOnUnloadItemRequestedResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above.
	 */

};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ISLIDABLELIST_EVENT_LISTENER_H_

