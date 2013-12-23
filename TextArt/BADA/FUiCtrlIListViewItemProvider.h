/* $Change: 618169 $ */
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
 * @file	FUiCtrlIListViewItemProvider.h
 * @brief	This is the header file for the %IListViewItemProvider interface.
 *
 * This header file contains the declarations of the %IListViewItemProvider interface. @n
 * If the event is generated, a method of this class is called. @n
 * So, if applications perform tasks related to the item events, use the methods of this class.
 *
 */
#ifndef _FUI_CTRL_ILISTVIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_ILISTVIEW_ITEM_PROVIDER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FUiCtrlListItemBase.h"

namespace Osp {namespace Ui { namespace Controls {

/**
 * @interface	IListViewItemProvider
 * @brief		This interface implements the provider for events on %ListView.
 * @since		2.0
 *
 * The %IListViewItemProvider interface is the interface for handling ListView items.
 * The class that handles list items implements this interface, and the instance created using the ListView's Construct() method. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _EXPORT_CONTROLS_ IListViewItemProvider
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IListViewItemProvider(void) {}

	/**
	 * Called when the %ListView is about to be drawn and returns the number of total items.
	 *
	 * @since		2.0
	 * @return		The count of all items of the list
	 * @remarks    	This method should be implemented so that it returns the number of total items in the list.
	 *
	 */
	virtual int GetItemCount(void) = 0;

	/**
	 * Called when the items need to be loaded.
	 *
	 * @since		2.0
	 * @return    	An item of the ListView
 	 * @param[in]	index        The index of the item
	 * @param[in]	itemWidth    The width of the item
	 * @see       	DeleteItem()
     * @remark		The applications that use ListView must implement this method. @n
     *				This method is expected to return an item which is allocated in a heap memory. @n
     *				The returned item can be a SimpleItem or CustomItem. @n
     *				Note that when the item becomes unnecessary, the ListView calls IListViewItemProvider::DeleteItem() and the application is in charge of 
	 *				deallocating the item.
     */
	virtual Osp::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth) = 0;

    /**
     * Called when an item becomes no longer used by the %ListView.
     *
     * @since		2.0
     * @return		@c true if the item is deallocated by this method, @n
     *				else @c false
     * @param[in]	index			The index of the item
     * @param[in]	pItem        	The pointer to the item to be deleted
     * @param[in]	itemWidth    	The width of the item
     * @see       	CreateItem()
     * @remarks   	Applications which use ListView must implement this method. @n
     *				In this method, the applications have the chance of deallocating the item. @n
     *				If the application deallocates the item, this method returns @c true, notifying the ListView not to free the item. @n
     *				Otherwise, the item will be deallocated by %ListView.
     */
    virtual bool DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth) = 0;

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
    virtual void IListViewItemProvider_Reserved1 (void) {}

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
    virtual void IListViewItemProvider_Reserved2 (void) {}

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
    virtual void IListViewItemProvider_Reserved3 (void) {}

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
    virtual void IListViewItemProvider_Reserved4 (void) {}

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
    virtual void IListViewItemProvider_Reserved5 (void) {}
};

};};};

#endif

