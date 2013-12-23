// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiCtrlIIconListViewItemProvider.h 
 * @brief		This is the header file for the %IIconListViewItemProvider interface.
 *
 * This header file contains the declarations of the %IIconListViewItemProvider class. @n
 * If the event is generated, a method of this class is called. @n
 * So, if applications performs tasks related to list events, use the methods of this class.
 *
 */
#ifndef _FUICTRL_IICONLISTVIEW_ITEM_PROVIDER_H_
#define _FUICTRL_IICONLISTVIEW_ITEM_PROVIDER_H_

// Includes
#include "FUiConfig.h"
#include "FUiCtrlIconListViewItem.h"

namespace Osp { namespace Ui { namespace Controls {

class IconListView;

/**
 * @interface	IIconListViewItemProvider
 * @brief		This interface implements the provider for events on %IconListView.
 * @since		2.0
 *
 * The %IIconListViewItemProvider interface is the interface for handling IconListView items.
 * The class that handles list items implements this interface, and the instance created using the IconListView's Construct()
 * method. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _EXPORT_CONTROLS_ IIconListViewItemProvider
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~IIconListViewItemProvider(void) {}
	
	/**
	 * Called when the IconListView is about to be drawn and requests the listener to set the number of total items.
	 *
	 * @since 		2.0
	 * @return		The item count of the %IconListView
	 * @remarks		Applications which use %IconListView must implement this method. This method is expected to return the number of total items in the 
	 *				%IconListView.
	 */
	virtual int GetItemCount(void) = 0;
	
	/**
	 * Called when items need to be loaded.
	 *
	 * @since 		2.0
	 * @return		The item of the %IconListView
 	 * @param[in]	index		The index of the item
 	 * @see			DeleteItem()
	 * @remarks		Applications which use %IconListView must implement this method. This method is expected to return an item which is allocated in a heap 
	 *				memory. The returned item can be %IconListViewItem. Note that when the item becomes unnecessary, the %IconListView calls 
	 *				IIconListViewItemProvider::DeleteItem() and applications is in charge of deallocating the item.
	 */
	virtual Osp::Ui::Controls::IconListViewItem* CreateItem(int index) = 0;
	
	/**
	 * Called when an item becomes no longer used by the %IconListView.
	 *
	 * @since 		2.0
	 * @return		@c true if the item is deallocated by this method, @n
	 * 				else @c false
	 * @param[in]	index		The index of the item
	 * @param[in]	pItem		The pointer to the item to be deleted
	 * @see			CreateItem()
	 * @remarks		Applications which use %IconListView must implement this method. In this method, the applications have the chance of deallocating the 
	 *				item. If the application deallocates the item, this method should return @c true, notifying the %IconListView not to free the item. 
	 *				Otherwise, the item will be deallocated by the %IconListView.
	 */
	virtual bool DeleteItem(int index, Osp::Ui::Controls::IconListViewItem* pItem) = 0;

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
    virtual void IconListViewItemProvider_Reserved1 (void) {}

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
    virtual void IconListViewItemProvider_Reserved2 (void) {}

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
    virtual void IconListViewItemProvider_Reserved3 (void) {}

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
    virtual void IconListViewItemProvider_Reserved4 (void) {}

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
    virtual void IconListViewItemProvider_Reserved5 (void) {}
};

}; /* Osp::Ui::Controls */ }; /* Osp::Ui */ }; /* Osp */

#endif // _FUICTRL_IICONLISTVIEW_ITEM_PROVIDER_H_

