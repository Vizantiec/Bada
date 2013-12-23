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
 * @file		FUiIClipboardPopupEventListener.h
 * @brief		This is the header file for %IClipboardPopupEventListener interface.
 *
 * This header file contains declarations of %IClipboardPopupEventListener interface. @n
 * If the item event is generated, a method of this class will be called. @n
 * The applications that perform tasks related to the item event, must call methods of this class.
 */
#ifndef _FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_
#define _FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class ClipboardItem; };};

namespace Osp { namespace Ui { 
/**
 * @interface	IClipboardPopupEventListener
 * @brief		This interface defines the listener for clipboard pop-up events.
 * @since		2.0
 *
 * The %IClipboardPopupEventListener interface is the listener interface for receiving clipboard pop-up events.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/clipboard.htm">Clipboard</a>.
 */
class _EXPORT_CONTROLS_ IClipboardPopupEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
    /**
     * This is the destructor for this class.
     * @since     2.0
     */
    virtual ~IClipboardPopupEventListener(void) {}

    /**
     * Called when the clipboard popup is closed by user interaction.
     *
     * @since		2.0
     * @param[in]	pClipboardItem	The pointer to ClipboardItem that is selected, @n
	 *								else @c null if no item is selected
     * @remarks 	@c pClipboardItem is deleted by the system after this method call.
     */
    virtual void OnClipboardPopupClosed(const ClipboardItem* pClipboardItem)=0;


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
    virtual void IClipboardPopupEventListener_Reserved1 (void) {}

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
    virtual void IClipboardPopupEventListener_Reserved2 (void) {}

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
    virtual void IClipboardPopupEventListener_Reserved3 (void) {}
};

};};
#endif //_FUI_ICLIPBOARD_POPUP_EVENT_LISTENER_H_

