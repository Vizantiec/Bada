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
 * @file		FUiITextBlockEventListener.h 
 * @brief		This is the header file for the %ITextBlockEventListener interface.
 *
 * This header file contains the declarations of the %ITextBlockEventListener interface.
 */
#ifndef _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_
#define _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"

// Forward declaration
namespace Osp { namespace Ui { class Control;  } }

// Namespace declaration
namespace Osp { namespace Ui { 
 /**
  * @interface	ITextBlockEventListener 
  * @brief	    This interface implements the listener for the text block events.
  * @since	    2.0
  *
  * The %ITextBlockEventListener interface is the listener interface for receiving text block selection events, for example, from EditFields.
  * The class that processes a text block selection event implements this interface, and the instance created with that class is
  *  registered with a UI control, using the control's AddTextBlockEventListener() method. When the text block selection event
  *  occurs, the OnTextBlockSelected() method of that instance is invoked.
  *
  * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_editfield_editarea.htm">EditArea and EditField</a>.

  */
class _EXPORT_UI_ ITextBlockEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 * @since		2.0
	 */
	virtual ~ITextBlockEventListener(void) {}


// Operation
public:
	/**
	 * Called when a text block is selected.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source  The source of the event
	 * @param[in] 	start   The start index of the selected text block
	 * @param[in] 	end     The end index of the selected text block
	 */
	virtual void OnTextBlockSelected(Osp::Ui::Control& source, int start, int end) = 0;


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
    virtual void ITextBlockEventListener_Reserved1 (void) { } 

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
    virtual void ITextBlockEventListener_Reserved2 (void) { } 

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
    virtual void ITextBlockEventListener_Reserved3 (void) { } 

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
    virtual void ITextBlockEventListener_Reserved4 (void) { } 

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
    virtual void ITextBlockEventListener_Reserved5 (void) { } 
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_ITEXT_BLOCK_EVENT_LISTENER_H_

