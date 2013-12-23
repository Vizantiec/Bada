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
 * @file		FUiCtrlISearchBarEventListener.h
 * @brief		This is the header file for the %ISearchBarEventListener interface.
 *
 * This header file contains the declarations of the %ISearchBarEventListener interface.
 */
#ifndef _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_
#define _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FUiCtrlSearchBar.h"

// Forward declaration
namespace Osp { namespace Ui { namespace Controls {class SearchBar;  } } }

// Namespace declaration
namespace Osp { namespace Ui { namespace Controls {
 /**
  * @interface	ISearchBarEventListener 
  * @brief	    This interface implements the listener for the SearchBar events.
  * @since	    2.0
  *
  * The %ISearchBarEventListener interface is the listener interface for receiving SearchBar events.
  * The class that processes a search bar event implements this interface, and the instance created with that class is registered
  *  with a UI control, using the control's AddSearchBarEventListener() method. When the search bar event occurs, the
  *  OnSearchBarModeChanged() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_searchbar.htm">SearchBar</a>.
  */
class _EXPORT_CONTROLS_ ISearchBarEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ISearchBarEventListener(void) {}


// Operation
public:
	/**
	 * Called when the mode of the SearchBar is changed. 
	 *
	 * @since		2.0
	 * @param[in]	source  The source of the event
	 * @param[in]	mode    The current search bar mode.
	 */
	virtual void OnSearchBarModeChanged(Osp::Ui::Controls::SearchBar& source, Osp::Ui::Controls::SearchBarMode mode) = 0;

// Reserves
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
    virtual void ISearchBarEventListener_Reserved1 (void) { } 

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
    virtual void ISearchBarEventListener_Reserved2 (void) { } 

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
    virtual void ISearchBarEventListener_Reserved3 (void) { } 

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
    virtual void ISearchBarEventListener_Reserved4 (void) { } 

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
    virtual void ISearchBarEventListener_Reserved5 (void) { } 
};

}; /* Osp::Ui::Controls*/ }; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_

