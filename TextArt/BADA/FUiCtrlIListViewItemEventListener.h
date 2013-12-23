/* $Change: 686294 $ */
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
 * @file		FUiCtrlIListViewItemEventListener.h
 * @brief		This is the header file for the %IListViewItemEventListener interface.
 *
 * This header file contains the declarations of the %IListViewItemEventListener interface. @n
 * If an item event is generated, a method of this class is called. @n
 * So, if an application does some jobs related to the item event, use the methods of this class.
 *
 */
#ifndef _FUICTRL_ILISTVIEWITEM_EVENT_LISTENER_H_
#define _FUICTRL_ILISTVIEWITEM_EVENT_LISTENER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseRtIEventListener.h"
#include "FUiCtrlListViewEnum.h"

namespace Osp { namespace Ui { namespace Controls { class ListView;}}}
namespace Osp { namespace Ui { namespace Controls {

/**
 * @interface	IListViewItemEventListener
 * @brief		This interface implements the listener for item event.
 * @since		2.0
 *
 * The %IListViewItemEventListener interface is the listener interface for receiving ListView item events.
 * The class that processes a list item event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddListViewItemEventListener() method. When the list item event occurs, a method of that
 * instance is invoked. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _EXPORT_CONTROLS_ IListViewItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IListViewItemEventListener(void) {}

	/**
	 * Called when the state of an element in the ListViewItem in the ListView or GroupedListView is changed.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	listView      The source of the event
	 * @param[in] 	index         The index of the list
	 * @param[in] 	elementId     The element ID
	 * @param[in] 	status        The status of the element
	 * @remarks     This method is called when an element of the %ListViewItem in the %ListView is checked, unchecked, or selected. @n
	 *				When the event comes from the annex or the whole item, @c elementId is always @c -1.
	 */
	virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status) = 0;
	
	/**
	 * Called when the ListItem is swept.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listView      The source of the event
	 * @param[in] 	index         The index of the list
	 * @param[in] 	direction     The sweep direction
	 */
	virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction) =0;

	/**
	 * Called when the state of an element in the %ListContextItem is changed.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	listView		The source of the event
	 * @param[in] 	index			The index of the list
	 * @param[in] 	elementId		The element ID
	 * @param[in]   status    		The status of the element
	 */
	virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus status) =0;
	
	/**
	 * Called when the item or the element is long pressed.
	 *
	 * @since			2.0
	 *
	 * @param[in] 		listView      				The source of the event
	 * @param[in] 		index         				The index of the list
	 * @param[in] 		elementId     				The element ID
	 * @param[in,out]	invokeListViewItemCallback	Indicates whether to invoke ListView item callback after this method returns
	 * @remarks      	This method is invoked when an item or an element is long pressed. @n
	 *					When the event comes from the annex or the whole item, @c elementId is always @c -1.
	 *					Setting @c invokeListViewItemCallback to @c true invokes %ListView item callbacks after this method returns.
	 *					Set @c invokeListViewItemCallback to @c false to not invoke %ListView item callbacks. The default value of 
	 *					@c invokeListViewItemCallback is @c true.
	 *					Note that other %ListView item callbacks are not called even though @c invokeListViewItemCallback is @c true, in case that ListView 
	 *					loses the focus, for example, due to invoking a Popup or a ContextMenu in this method.
	 */
	virtual void OnListViewItemLongPressed(Osp::Ui::Controls::ListView &listView, int index, int elementId, bool& invokeListViewItemCallback);

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void IListViewItemEventListener_Reserved1 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void IListViewItemEventListener_Reserved2 (void) {}
};

};};};

#endif

