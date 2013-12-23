// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FUiCtrlIGalleryItemProvider.h
 * @brief		This is the header file for the %IGalleryItemProvider class.
 *
 * This header file contains the declarations of the %IGalleryItemProvider class. @n
 * If an event is generated, a method of this class is called. @n
 * Therefore, if applications perform jobs related to the list events, use the methods of this class.
 *
 */
#ifndef _FUICTRL_IGALLERY_ITEM_PROVIDER_H_
#define _FUICTRL_IGALLERY_ITEM_PROVIDER_H_

// Includes
#include "FUiConfig.h"
#include "FUiCtrlGalleryItem.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @interface	IGalleryItemProvider
 * @brief		This interface implements the provider for events on Gallery.
 * @since		2.0
 *
 * The %IGalleryItemProvider interface is the interface for handling Gallery items. The class that handles gallery items implements this
 * interface, and the instance created using the Gallery's SetItemProvider() method.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_gallery.htm">Gallery</a>.
 */
class _EXPORT_CONTROLS_ IGalleryItemProvider
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0 
	 */
	virtual ~IGalleryItemProvider(void) {}
	
	/**
	 * Gets the total number of items.
	 *
	 * @since 	2.0 
	 * @return		The total number of the Gallery control items
	 * @remarks		An application that uses the Gallery control must implement this method.
	 */
	virtual int GetItemCount(void) = 0;
	
	/**
	 * Gets the item at the specified index from the item provider.
	 *
	 * @since	2.0 
	 * @return		An item of the Gallery control
 	 * @param[in]	index			The index of the item
 	 * @see			DeleteItem()
	 * @remarks		An application that uses the Gallery control must implement this method. This method is expected to return an item that is allocated on a 
	 *				heap memory. The returned item can be of type GalleryItem. Note that when the item is not required, the Gallery control calls the 
	 *				IGalleryItemProvider::DeleteItem() method.
	 */
	virtual Osp::Ui::Controls::GalleryItem* CreateItem(int index) = 0;
	
	/**
	 * Deletes the specified item.
	 *
	 * @since 	2.0 
	 * @return		@c true if the item is deallocated by this method, @n
	 * 				else @c false
	 * @param[in]	index		The index of the item
	 * @param[in]	pItem		The pointer to GalleryItem that is to be deleted
	 * @see			CreateItem()
	 * @remarks		An application that uses the Gallery control must implement this method. Using this method, an application can deallocate the item. If an 
	 *				application deallocates the item, this method returns @c true. This notifies the Gallery control to not release the item. 
	 *				Otherwise, the item is deallocated by the Gallery control.
	 */
	virtual bool DeleteItem(int index, Osp::Ui::Controls::GalleryItem* pItem) = 0;

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
    virtual void GalleryItemProvider_Reserved1 (void) {}

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
    virtual void GalleryItemProvider_Reserved2 (void) {}

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
    virtual void GalleryItemProvider_Reserved3 (void) {}

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
    virtual void GalleryItemProvider_Reserved4 (void) {}

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
    virtual void GalleryItemProvider_Reserved5 (void) {}
};

}; /* Osp::Ui::Controls */ }; /* Osp::Ui */ }; /* Osp */

#endif // _FUICTRL_IGALLERY_ITEM_PROVIDER_H_

