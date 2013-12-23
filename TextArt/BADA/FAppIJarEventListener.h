/* $Change: 1006494 $ */
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
 * @file			FAppIJarEventListener.h
 * @brief			This is the header file for the %IJarEventListener event listener.
 * 
 * This header file contains the declarations of the %IJarEventListener event listener.
 */

#ifndef _FAPP_IJAREVENT_LISTENER_H
#define _FAPP_IJAREVENT_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"


namespace Osp { namespace Base { class String; }; };

namespace Osp { namespace App {


/**
* @if PRIVCORE 
* @interface	IJarEventListener
* @brief		This interface implements a listener for JAR installation.
* @since		2.0
*
* The %IJarEventListener interface implements a listener for JAR installation.

* @endif
*/
class _EXPORT_APP_ IJarEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

	/**
	* @if PRIVCORE 
	* Notifies JAR installation completed.
	*
	* @since 			2.0
	* @param[in]	appName		The installed Java application name. In case of MIDP/CLDC, it will be a MIDlet name.
	* @param[in]	InstalledJarIndex	The index of the installed JAR
	* @param[in]	r	The installation errors	
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	A system error has occurred.
	* @exception	E_IN_PROGRESS	Another installation is in progress.
	* @exception	E_INVALID_CONTENT	The JAR and JAD are invalid.
	* @exception	E_MAX_EXCEEDED	Installation storage full.
	* @exception	E_INVALID_CONTENT	The JAR and JAD are invalid.
	* @endif
	*/
	virtual void OnJarInstallationCompleted(Osp::Base::String& appName,int InstalledJarIndex, result r) = 0;

	/**
	* @if PRIVCORE 
	* Notifies JAR installation progress.
	*
	* @since 		 2.0
	* @param[in]	appName		The installed Java application name. In case of MIDP/CLDC, it will be a MIDlet name.
	* @param[in] progress	The installation percentage of JAR
	* @endif
	*/
	virtual void OnJarInstallationInProgress(Osp::Base::String& appName, int progress) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since	2.0
	 */
	virtual void IJarEventListener_Reserved1() {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since	2.0
	 */
	virtual void IJarEventListener_Reserved2() {}


};


}; }; // Osp::App

#endif // _FAPP_IJAREVENT_LISTENER_H
