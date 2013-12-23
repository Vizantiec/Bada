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
 * @file	FUiISlidableGroupedListEventListener.h 
 * @brief	This is the header file for the %ISlidableGroupedListEventListener interface.
 *
 * This header file contains the declarations of the %ISlidableGroupedListEventListener interface. @n
 * If an event is generated, a method of this class is called. @n
 * So, if an application performs tasks related to item events, it uses the methods of this class.
 *
 */
#ifndef _FUI_ISLIDABLEGROUPEDLIST_EVENT_LISTENER_H_
#define _FUI_ISLIDABLEGROUPEDLIST_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @interface	ISlidableGroupedListEventListener 
 * @brief		This interface implements the listener for events on SlidableGroupedList.
 * @deprecated  This listener is deprecated. Instead of using this listener, use Osp::Ui::Controls::IGroupedListViewItemEventListener.
 * @since		1.0
 *
 * The %ISlidableGroupedListEventListener interface implements a listener for receiving scroll events on %SlidableGroupedList. @n
 * The role of this interface is similar to ISlidableListEventListener.  
 * The class is registered with a %SlidableGroupedList, using the control's AddSlidableGroupedListEventListener() method. 
 */
class _EXPORT_UI_ ISlidableGroupedListEventListener :
	public Osp::Base::Runtime::IEventListener 
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~ISlidableGroupedListEventListener(void) {}

	/**
     * Called when the %SlidableGroupedList is about to be drawn and requests the listener to set the properties of the list such as the total height and the 
	 * number of items in each group.
	 *
	 * @since		1.0
	 * @param[in] 	source		The source of the event
	 */
	virtual void OnListPropertyRequested(const Osp::Ui::Control &source) = 0;
  
	/**
	 * Called when the items need to be loaded to the top.
	 *
	 * @since		1.0
	 * @param[in]	source		  The source of the event
 	 * @param[in]   groupIndex	  The index of the list group
	 * @param[in]   itemIndex	  The index of the list item in the specified group		
	 * @param[in]   numItems	  The number of items
	 */
	virtual void OnLoadToTopRequested(const Osp::Ui::Control &source, int groupIndex, int itemIndex, int numItems) = 0;

	/**
	 * Called when the items need to be loaded to the bottom.
	 *
	 * @since		1.0
	 * @param[in] 	source        The source of the event
 	 * @param[in] 	groupIndex	  The index of the list group
	 * @param[in] 	itemIndex     The index of the list item in the specified group
	 * @param[in]   numItems      The number of items
	 */
	virtual void  OnLoadToBottomRequested (const Osp::Ui::Control &source, int groupIndex, int itemIndex, int numItems) = 0;

	/**
	 * Called when an item is about to be unloaded from memory. @n
	 * The user-allocated resources associated with the item to be unloaded need to be freed when OnUnloadItemRequested() is called.
	 *
	 * @since		1.0
	 * @compatibility     	This method has compatibility issues with different bada API versions. @n
	 *                    	For more information, see @ref CompISlidableGroupedListEventListenerOnUnloadItemRequested "1.2" and 
	 *						@ref CompISlidableGroupedListEventListenerOnUnloadItemRequested20 "2.0".
	 *
	 * @param[in] 	source	  		The source of the event
	 * @param[in] 	groupIndex	  	The index of the list group
	 * @param[in] 	itemIndex     	The index of the list item in the specified group
	 */
	virtual void OnUnloadItemRequested(const Osp::Ui::Control& source, int groupIndex, int itemIndex) = 0;

	 /**
	  * @page	CompISlidableGroupedListEventListenerOnUnloadItemRequested	Compatibility for Construct()
	  *
	  * @section	CompISlidableGroupedListEventListenerOnUnloadItemRequestedIssues	Issues
	  * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	  * -# OnUnloadItemRequested() callback is invoked with the wrong group index and item index.
	  *
	  * @section CompISlidableGroupedListEventListenerOnUnloadItemRequestedResolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2. or above. @n
	  */

	 /**
	  * @page	CompISlidableGroupedListEventListenerOnUnloadItemRequested20	Compatibility for OnUnloadItemRequested ()
	  *
	  * @section CompISlidableGroupedListEventListenerOnUnloadItemRequested20Issues	Issues
	  * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	  * -# When the SlidableGroupedList is resized, the OnUnloadItemRequested() callback may be repeatedly invoked if the
	  *    size of the internal item cache becomes smaller than the number of items that can be shown at a time.
	  *
	  * @section	CompISlidableGroupedListEventListenerOnUnloadItemRequestedResolutions	Resolutions
	  * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0. or above. @n
	  */

};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ISLIDABLEGROUPEDLIST_EVENT_LISTENER_H_

