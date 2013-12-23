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
 * @file	FUiCtrlIExpandableEditAreaEventListener.h
 * @brief	This is the header file for the %IExpandableEditAreaEventListener interface.
 *
 * This header file contains the declarations of the %IExpandableEditAreaEventListener interface.
 */
#ifndef _FUICTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_
#define _FUICTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_

// includes
#include "FBaseRtIEventListener.h"
#include "FUiCtrlExpandableEditArea.h"

namespace Osp { namespace Ui { class Control; } }
// namespace declaration
namespace Osp { namespace Ui { namespace Controls {
/**
  * @interface	IExpandableEditAreaEventListener
  * @brief	    This interface defines a listener for the %ExpandableEditArea events.
  *             
  * @since	    2.0
  *
  * The %IExpandableEditAreaEventListener interface is the listener interface for receiving %ExpandableEditArea events.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
  * 
  */
class _EXPORT_CONTROLS_ IExpandableEditAreaEventListener :
	public Osp::Base::Runtime::IEventListener
{

// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
     * @since        2.0
	 */
	virtual ~IExpandableEditAreaEventListener(void) {}


// Operations
public:
	/**
	 * Called when a new line is added to ExpandableEditArea.
	 *
     * @since       2.0
	 * @param[in] 	source	        The source of the event
	 * @param[in] 	newLineCount	The new line count
	 */
	virtual void OnExpandableEditAreaLineAdded(Osp::Ui::Controls::ExpandableEditArea& source, int newLineCount) = 0;

	/**
	 * Called when a line is removed from ExpandableEditArea.
	 *
     * @since       2.0
	 * @param[in] 	source	        The source of the event
	 * @param[in] 	newLineCount	The new line count
	 */
	virtual void OnExpandableEditAreaLineRemoved(Osp::Ui::Controls::ExpandableEditArea& source, int newLineCount) = 0;


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
    virtual void IExpandableEditAreaEventListener_Reserved1 (void) { }

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
    virtual void IExpandableEditAreaEventListener_Reserved2 (void) { }

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
    virtual void IExpandableEditAreaEventListener_Reserved3 (void) { }
};	//IExpandableEditAreaEventListener

}; }; }; //Osp::Ui

#endif //_FUICTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_

