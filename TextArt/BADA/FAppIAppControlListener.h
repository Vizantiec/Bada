/* $Change: 784508 $ */
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
 * @file			FAppIAppControlListener.h
 * @brief			This is the header file for the %IAppControlListener interface.
 * 
 * This header file contains the declarations of the %IAppControlListener interface.
 */

#ifndef _FAPP_IAPPCONTROL_LISTENER_H
#define _FAPP_IAPPCONTROL_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"
#include "FAppIAppControlEventListener.h"

namespace Osp { namespace App { class AppControl; }; };
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {

/**
 * @interface	IAppControlListener
 * @brief		This interface defines a listener for the AppControl start and result events.
 * @since		2.0
 *
 * The %IAppControlListener interface defines a listener for the AppControl start and result events.
 */
class _EXPORT_APP_ IAppControlListener :
	public IAppControlEventListener
{
public:

	/**
	 * Called when the application control is about to start. @n
	 * The client can get the callback result for some application controls by implementing this listener.
	 *
	 * @since			2.0
	 * @param[in]	pAppControl			A pointer to the AppControl instance that is to be started 
	 * @param[in]	r					The error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_IN_PROGRESS		The target %AppControl is in progress.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see		Osp::App::AppControl, AppControl::Start(), AppManager::StartAppControl()
	 */
	virtual void OnAppControlStarted(const AppControl* pAppControl, result r) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since	2.0
	 */
	virtual void IAppControlListener_Reserved1() {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since	2.0
	 */
	virtual void IAppControlListener_Reserved2() {}
};

}; }; // Osp::App

#endif // _FAPP_IAPPCONTROL_LISTENER_H
