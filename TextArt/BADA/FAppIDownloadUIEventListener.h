/* $Change: 1142016 $ */
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
 * @file			FAppIDownloadUIEventListener.h
 * @brief			This is the header file for the %IDownloadUIEventListener interface.
 * 
 * This header file contains the declarations of the %IDownloadUIEventListener interface.
 */

#ifndef _FAPP_IDOWNLOAD_EVENT_LISTENER_H
#define _FAPP_IDOWNLOAD_EVENT_LISTENER_H

#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FBaseRtIEventListener.h"
#include "FAppDownloadUIManager.h"

namespace Osp { namespace App {

/**
* @if PRIVCORE
* @interface	IDownloadUIEventListener
* @brief		This interface implements a listener for the package download.
* @since		1.0
*
* The %IDownloadUIEventListener interface implements a listener for the package download.
* @endif
*/
class _EXPORT_APP_ IDownloadUIEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	 * @if PRIVCORE
	 * Called when a state transition is requested. For instance, this method is called when the application icon is touched by the user during the download.
	 *
	 * @since				1.0
	 * @param[in] 	appId		The application ID
	 * @param[in] 	state	    The requested change of state.
	 * @endif
	 */
	virtual void OnDownloadUIStateChangeRequested(const Osp::Base::String& appId, DownloadUIManager::DownloadUIState state) = 0;
};


}; }; // Osp::App

#endif // _FAPP_IDOWNLOAD_EVENT_LISTENER_H
