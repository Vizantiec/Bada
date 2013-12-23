/* $Change: 719094 $ */
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
 * @file		FUiCtrlIGroupedListViewItemProvider.h
 * @brief		This is the header file for the %IGroupedListViewItemProvider interface.
 *
 * This header file contains the declarations of the %IGroupedListViewItemProvider interface. @n
 * If an event is generated, a method of this class is called. @n
 * Therefore, if an application performs jobs related to the item events, it uses the methods of this class.
 *
 */
#ifndef _FUI_CTRL_IGROUPEDLISTVIEW_ITEM_PROVIDER_H_
#define _FUI_CTRL_IGROUPEDLISTVIEW_ITEM_PROVIDER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FUiCtrlListItemBase.h"
#include "FUiCtrlGroupItem.h"

namespace Osp {namespace Ui { namespace Controls {

/**
 * @interface	IGroupedListViewItemProvider
 * @brief		This interface implements the provider for the events generated by the %GroupedListView control.
 * @since		2.0
 *
 * The %IGroupedListViewItemProvider interface is the interface for handling GroupedListView items.
 * The class that handles list items implements this interface, and the instance created using the GroupedListView's Construct()
 * method.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _EXPORT_CONTROLS_ IGroupedListViewItemProvider
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IGroupedListViewItemProvider(void) {}

	/**
	 * Gets the total number of groups.
	 *
	 * @since		2.0
	 * @return		The total number of groups
	 * @remarks   	This method should be implemented so that it returns the total number of groups in the GroupedListView control.
	 *
	 */
	virtual int GetGroupCount(void) = 0;
	
	/**
	 * Gets the total number of items in the specified group.
	 *
	 * @since		2.0
	 * @return    	The total number of items in the specified group
	 * @param[in] 	groupIndex		The index of the group
	 * @remarks   	This method should be implemented so that it returns the total number of items for the specified group in the GroupedListView control.
	 *
	 */
	virtual int GetItemCount(int groupIndex) = 0;

	/**
	 * Gets the group item for the specified index from the item provider.
	 *
	 * @since		2.0
	 * @return    	A group item of the %GroupedListView control
 	 * @param[in] 	groupIndex    The index of the group
 	 * @param[in] 	itemWidth     The width of the item
 	 * @remark	An application that uses the GroupedListView control must implement this method. This method is expected to return a group item that is 
	 *			allocated on a heap memory. @n
     *			Note that when the item is not required, the GroupedListView control calls IGroupedListViewItemProvider::DeleteGroupItem() and the 
	 *			application deallocates the item.
 	 *
	 */
	virtual Osp::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, int itemWidth) = 0;
	
	/**
	 * Deletes the specified group item.
	 *
	 * @since	2.0
	 * @return   	@c true if the item is deallocated by this method, @n
	 *            	else @c false
	 * @param[in]	groupIndex  	The index of the group
	 * @param[in]	pItem         The pointer to GroupItem that is to be deleted
     * @param[in] 	itemWidth     The width of the item
     * @see       	CreateItem()
     * @remarks   	An application that uses the %GroupedListView control must implement this method. @n
     *				Using this method, an application can deallocate the item. @n
     *				If an application deallocates the item, this method should return @c true. This notifies the %GroupedListView control not to release the 
	 *				item. Otherwise, the item is deallocated by the GroupedListView control.
     */
    virtual bool DeleteGroupItem(int groupIndex, Osp::Ui::Controls::GroupItem* pItem, int itemWidth) = 0;

	/**
	 * Creates the specified item.
	 *
	 * @since		2.0
	 *
	 * @return	  	An item of the list
 	 * @param[in] 	groupIndex  	The index of the group
 	 * @param[in] 	itemIndex  	The index of the item
 	 * @param[in] 	itemWidth		The width of the item
 	 * @see       	DeleteItem()
 	 * @remarks   	An application that uses the %GroupedListView control must implement this method. @n
 	 *				This method is expected to return an item that is allocated on a heap memory. @n
 	 *				The returned item can be a simple or custom item. @n
 	 *				Note that when the item is not required, the %GroupedListView control calls IGroupedListViewItemProvider::DeleteItem() and the application 
	 *				deallocates the item.
 	 *
	 */
	virtual Osp::Ui::Controls::ListItemBase* CreateItem(int groupIndex, int itemIndex, int itemWidth) = 0;

    /**
     * Deletes the specified item.
     *
     * @since	2.0
     *
     * @return		@c true if the item is deallocated by this method, @n
     *				else @c false
     * @param[in]	groupIndex  	The index of the group
 	 * @param[in]	itemIndex  		The index of the item
     * @param[in]	pItem         	The pointer to ListItemBase that is to be deleted
     * @param[in]	itemWidth     	The width of the item
     * @see       	CreateItem()
     * @remarks   	An application that uses the %GroupedListView control must implement this method. @n
     *				Using this method, an application can deallocate the item. @n
     *				If the application deallocates the item, this method should return @c true. This notifies the %GroupedListView control not to release the 
	 *				item. Otherwise, the item is deallocated by the %GroupedListView control.
     */
    virtual bool DeleteItem(int groupIndex, int itemIndex, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth) = 0;

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
    virtual void IGroupedListViewItemProvider_Reserved1 (void) {}

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
    virtual void IGroupedListViewItemProvider_Reserved2 (void) {}

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
    virtual void IGroupedListViewItemProvider_Reserved3 (void) {}

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
    virtual void IGroupedListViewItemProvider_Reserved4 (void) {}

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
    virtual void IGroupedListViewItemProvider_Reserved5 (void) {}
};

};};};

#endif
