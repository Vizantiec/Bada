// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlIconListViewItem.h
 * @brief	This is the header file for the %IconListViewItem class.
 *
 * This header file contains the declarations of the %IconListViewItem class and its helper classes.
 */
 
#ifndef _FUICTRL_ICONLISTVIEWITEM_H_
#define _FUICTRL_ICONLISTVIEWITEM_H_

//includes
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

namespace Osp { namespace Ui { class __IconListViewEventAdaptor; } }

namespace Osp { namespace Ui { namespace Controls {

class IconListViewItemEx;

/**
 * @class	IconListViewItem
 * @brief 	This class defines the common behavior of a %IconListViewItem control.
 * @since	2.0
 *
 * The %IconListViewItem class displays an IconListView item. It comprises of bitmap images and text. The value is set using the IconListView control. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
 
 
 */
class _EXPORT_CONTROLS_ IconListViewItem
	: public Osp::Base::Object
{
public:
	/** 
	 * This is the default constructor for this class. 
	 *
	 * @since	2.0
	 */	
	IconListViewItem(void);
	
	/** 
	 * This is the destructor for this class. 
	 *
	 * @since	2.0
	 */	
	virtual ~IconListViewItem(void);
	
private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
     * @since         2.0
     */		
	IconListViewItem(const IconListViewItem& iconListViewItem);
	
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * This is the substitution operator for this class.
     * @since         2.0
     */		
	IconListViewItem& operator=(const IconListViewItem& iconListViewItem);
	
public:
	/** 
	 * Initializes this instance of %IconListViewItem with the specified parameters.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	bitmap				The default bitmap image
	 * @param[in]	pText				The item text
	 * @param[in]	pSelectedBitmap		The displayed bitmap image when an item is selected
	 * @param[in]	pHighlightedBitmap	The displayed bitmap image when an item is highlighted
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @remarks		If @c pSelectedBitmap or @c pHighlightedBitmap is @c null, @c bitmap plays its role.
	 */
	result Construct(const Osp::Graphics::Bitmap& bitmap, const Osp::Base::String* pText = null, const Osp::Graphics::Bitmap* pSelectedBitmap = null, const Osp::Graphics::Bitmap* pHighlightedBitmap = null);

private:
	friend class IconListView;
	friend class __IconListViewEventAdaptor;
	friend class IconListViewItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
     class IconListViewItemEx* __pIconListViewItemEx;
};

}; }; }; 

#endif

