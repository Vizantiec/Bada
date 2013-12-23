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
 * @file			FAppIAppCheckPointEventListener.h
 * @brief			This is the header file for the %IAppCheckpointEventListener interface.
 *
 * This header file contains the declarations of the %IAppCheckpointEventListener interface. @n
 * If a checkpoint event is generated, a method of this class is called.
 */


#ifndef _FAPP_IAPPCHECKPOINT_EVENT_LISTENER_H
#define _FAPP_IAPPCHECKPOINT_EVENT_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace App {

// Forward declaration
class AppRegistry;

/**
 * @interface IAppCheckpointEventListener 
 * @brief	This interface defines the listener for the checkpoint event.
 * @since	2.0
 *
 * The %IAppCheckpointEventListener interface is used for receiving the checkpoint event.
 * The event is fired when the system is about to terminate an application due to, for example, low memory or when another application
 *  is being launched.
 *
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/bada_overview/bada_app_model/multitasking_in_bada.htm">Multitasking in bada</a>.
 *
 */
class _EXPORT_APP_ IAppCheckpointEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IAppCheckpointEventListener(void) {}

	/**
	 * Called when a checkpoint event occurs.
	 * 
	 * @since			2.0
	 * @param[in]	appRegistry	 The application registry
	 */
	virtual void OnAppCheckpointing(AppRegistry& appRegistry) = 0;

protected:
	// Reserved virtual methods for later extension
	/**
	 * @internal
	 * The following methods are reserved and the name of methods can be changed at any time
	 * without prior notice.
	 *
	 * @since           2.0
	 */
	virtual void IAppCheckpointEventListener_Reserved1 (void) {}
	
	/**
	 * @internal	
	 * The following methods are reserved and the name of methods can be changed at any time
	 * without prior notice.
	 *
	 * @since           2.0
	 */
	virtual void IAppCheckpointEventListener_Reserved2 (void) {}
	
	/**
	 * @internal	
	 * The following methods are reserved and the name of methods can be changed at any time
	 * without prior notice.
	 *
	 * @since           2.0
	 */
	virtual void IAppCheckpointEventListener_Reserved3 (void) {}
};

}; }; // Osp::App

#endif  //_FAPP_IAPPCHECKPOINT_EVENT_LISTENER_H
