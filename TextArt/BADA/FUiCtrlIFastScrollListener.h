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
 * @file	FUiCtrlIFastScrollListener.h
 * @brief	This is the header file for the %IFastScrollListener interface.
 *
 * This header file contains the declarations of the %IFastScrollListener interface. @n
 * If item event is generated, a method of this class will be called. @n
 * Applications that perform tasks related to the item event call methods of this class.
 *
 */
#ifndef _FUICTRL_IFASTSCROLL_LISTENER_H_
#define _FUICTRL_IFASTSCROLL_LISTENER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp { namespace Ui { namespace Controls {

// constants
/**
 * The string constant representing the index of the magnifying icon in a fast scroll.
 * @since	2.0
 */
static const Osp::Base::String FAST_SCROLL_SEARCH_ICON_INDEX = L"[SEARCH_ICON_INDEX]";


/**
 * @interface	IFastScrollListener
 * @brief		This interface implements the listener for the fast scroll event.
 * @since		2.0
 *
 * The %IFastScrollListener interface is the listener interface for receiving fast scroll events. 
 * The class that processes a fast scroll event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddFastScrollListener() method. When the fast scroll event occurs, the
 * OnFastScrollIndexChanged() method of that instance is invoked. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.

 */
class _EXPORT_CONTROLS_ IFastScrollListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 * @since	2.0
	 */
	virtual ~IFastScrollListener(void) {}

	/**
	 * Called when an index is selected.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	index			The index
	 * @remarks     When the search icon index is enabled, you can check whether the search icon index is touched by comparing @c index with the string 
	 *				constant FAST_SCROLL_SEARCH_ICON_INDEX.
	 *
	 */
	virtual void OnFastScrollIndexSelected(Osp::Ui::Control& source, Osp::Base::String& index)=0;

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
    virtual void IFastScrollListener_Reserved1 (void) {}

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
    virtual void IFastScrollListener_Reserved2 (void) {}

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
    virtual void IFastScrollListener_Reserved3 (void) {}
};

};};};

#endif

