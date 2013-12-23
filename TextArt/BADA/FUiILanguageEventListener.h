/* $Change: 475538 $ */
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
 * @file	FUiILanguageEventListener.h
 * @brief	This is the header file for the %ILanguageEventListener class.
 *
 * This header file contains the declarations of the %ILanguageEventListener class.
 */

#ifndef _FUI_ILANGUAGE_EVENT_LISTENER_H_
#define _FUI_ILANGUAGE_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"
#include "FLclLocale.h"

namespace Osp { namespace Ui { class Control; } }

namespace Osp {namespace Ui {

/**
 * @if PRIVCORE
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * @interface  ILanguageEventListener
 * @brief      This interface implements the listener for the language event.
 * @since		1.0
 *
 * The %ILanguageEventListener interface receives language events. The class that processes a language event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddLanguageEventListener() method. @n
 *
 * When the current input language is changed (for example, when the user toggles the input language from the virtual
 * keypad, the listener's OnLanguageChanged() method is
 * invoked.
 * @endif                   
 */

class _EXPORT_UI_ ILanguageEventListener :
    public Osp::Base::Runtime::IEventListener
{

// Operation

public:
    /**
     * @if PRIVCORE
	 * This is the default constructor for this class.
	 *
	 * @since				1.0
	 * @endif                   
	 */
    ILanguageEventListener(void) {};

	/**
	 * @if PRIVCORE
	 * This is internal. If used in an application, the application can get rejected during the certification process.
	 * This is the destructor for this class.
	 *
	 * @since				1.0
	 * @endif                   
	 */
	virtual ~ILanguageEventListener (void) {}

	/**
	 * @if PRIVCORE
	 * Called when the input language is changed.
	 *
	 * @since		1.0
	 * @param[in] 	source         		The source of the event
	 * @param[in] 	previousLanguage    The previous input language
	 * @param[in] 	currentLanguage     The current input language
	 * @endif                   
	 */
	virtual void OnLanguageChanged(const Osp::Ui::Control& source, Osp::Locales::LanguageCode oldLanguage, Osp::Locales::LanguageCode newLanguage) = 0;
};

};};

#endif
