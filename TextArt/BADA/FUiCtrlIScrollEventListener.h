/* $Change: 763081 $ */
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
 * @file	FUiCtrlIScrollEventListener.h
 * @brief	This is the header file for the %IScrollEventListener interface.
 *
 * This header file contains the declarations of the %IScrollEventListener interface. @n
 * If a change event is generated, a method of this class is called. @n
 * The applications that perform tasks related to the change events, call the methods of this class.
 *
 */
#ifndef _FUICTRL_ISCROLL_EVENT_LISTENER_H_
#define _FUICTRL_ISCROLL_EVENT_LISTENER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseRtIEventListener.h"
#include "FUiCtrlScrollEventEnum.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui { namespace Controls {

 /**
  * @interface	IScrollEventListener
  * @brief		This interface implements a listener for ScrollPanel events.
  * @since		2.0
  *
  * The %IScrollEventListener interface is the listener interface for receiving scroll events.
  * The class that processes a scroll event implements this interface, and the instance created with that class is registered with
  *  a UI control, using the control's AddScrollEventListener() method. When the scroll event occurs, the OnScrollEndReached()
  * method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_panels.htm">Panels</a> and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.
  */
class _EXPORT_CONTROLS_ IScrollEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 *
	 */
	virtual ~IScrollEventListener(void) {}

    /**
     * Called when the scroll reaches the top, bottom, left or right end.
     *
     * @since 			2.0
     *
     * @param[in]		source        The source of the event
     * @param[in]		type          The type of scroll end event
     */
    virtual void OnScrollEndReached(Osp::Ui::Control& source, Osp::Ui::Controls::ScrollEndEvent type) = 0;
		
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
	virtual void ScrollEventListener_Reserved1 (void) {}

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
	virtual void ScrollEventListener_Reserved2 (void) {}

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
	virtual void ScrollEventListener_Reserved3 (void) {}

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
	virtual void ScrollEventListener_Reserved4 (void) {}

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
	virtual void ScrollEventListener_Reserved5 (void) {}
};

};};};

#endif // _FUICTRL_ISCROLL_EVENT_LISTENER_H_

