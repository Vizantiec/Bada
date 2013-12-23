// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file	FUiCtrlIIconListViewItemEventListener.h
 * @brief	This is the header file for the %IIconListViewItemEventListener interface.
 *
 * This header file contains the declarations of the %IIconListViewItemEventListener interface. @n
 * If an item event is generated, a method of this class is called. @n
 * So, if an application does some jobs related to the item event, use the methods of this class.
 *
 */
#ifndef _FUICTRL_IICONLISTVIEWITEM_EVENT_LISTENER_H_
#define _FUICTRL_IICONLISTVIEWITEM_EVENT_LISTENER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { namespace Controls { class IconListView; } } }

namespace Osp { namespace Ui { namespace Controls {

/**
 * @interface	IIconListViewItemEventListener
 * @brief		This interface implements the listener for the item event.
 * @since		2.0
 *
 * The %IIconListViewItemEventListener interface is the listener interface for receiving IconListView item events.
 * The class that processes a list item event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddIIconListViewItemEventListener() method. When the list item event occurs, the
 * OnIconListViewItemStateChanged() method of that instance is invoked. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _EXPORT_CONTROLS_ IIconListViewItemEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~IIconListViewItemEventListener(void) {}
	
	/**
	 * Called when an item event occurs.
	 *
	 * @since 		2.0
	 * @param[in] 	listView	The source ListView of the event
 	 * @param[in] 	index		The index of the item
	 * @param[in] 	status		The item status
	 */
	virtual void OnIconListViewItemStateChanged(Osp::Ui::Controls::IconListView& listView, int index, Osp::Ui::Controls::IconListViewItemStatus status) = 0;
	
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
    virtual void IconListViewItemEventListener_Reserved1 (void) {}

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
    virtual void IconListViewItemEventListener_Reserved2 (void) {}

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
    virtual void IconListViewItemEventListener_Reserved3 (void) {}

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
    virtual void IconListViewItemEventListener_Reserved4 (void) {}

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
    virtual void IconListViewItemEventListener_Reserved5 (void) {}
};

}; }; }; /* Osp::Ui::Controls */

#endif // _FUICTRL_IICONLISTVIEWITEM_EVENT_LISTENER_H_
