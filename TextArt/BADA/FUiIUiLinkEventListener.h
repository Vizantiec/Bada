// Copyright (c) 2011 Samsung Electronics Co., Ltd.
//
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FUiIUiLinkEventListener.h
 * @brief		This is the header file for the %IUiLinkEventListener interface.
 *
 * This header file contains the declarations of the %IUiLinkEventListener interface.
 */
#ifndef _FUI_IUILINK_EVENT_LISTENER_H_
#define _FUI_IUILINK_EVENT_LISTENER_H_

// Includes
#include "FBaseUtilTypes.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control; }; };
namespace Osp { namespace Base { class String; }; };

// Namespace declaration
namespace Osp { namespace Ui {

/**
 * @interface    IUiLinkEventListener
 * @brief        This interface implements the listener for link events.
 * @since        2.0
 *
 * The %IUiLinkEventListener interface is the listener interface for receiving link click events, for example, from EditFields. 
 * The class that processes a link click event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddUiLinkEventListener() method. When the link click event occurs, the OnLinkClicked()
 * method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>, <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_textbox.htm">TextBox</a>, and <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.

 */
class _EXPORT_UI_ IUiLinkEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IUiLinkEventListener (void) {}

	// Operation
public:
	/**
	 * Called when a link is clicked.
	 *
	 * @since		  2.0
	 * @param[in]     source   	The source of the event
	 * @param[in]     text     	The text
	 * @param[in]     linkType 	The link type
	 * @param[in]     link     	The optional link text
	 * @remarks       If the clicked link does not contain an optional link text, then the value of @c text and @c link will be the same.
	 */
	virtual void OnLinkClicked(Osp::Ui::Control& source, const Osp::Base::String& text, Osp::Base::Utility::LinkType linkType,	const Osp::Base::String& link) = 0;

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
	virtual void IUiLinkEventListener_Reserved1 (void) {}

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
	virtual void IUiLinkEventListener_Reserved2 (void) {}

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
	virtual void IUiLinkEventListener_Reserved3 (void) {}
};

};};

#endif	// _FUI_ILINK_EVENT_LISTENER_H_
