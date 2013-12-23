/* $Change: 574345 $ */
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
 * @file			FAppIGuestPackageEventListener.h
 * @brief			This is the header file for the %AppControl event listener.
 * 
 * This header file contains the declarations of the %AppControl event listener.
 */

#ifndef _FAPP_IGUEST_PACKAGE_EVENT_LISTENER_H
#define _FAPP_IGUEST_PACKAGE_EVENT_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"
#include "FAppGuestPackageManager.h"
#include "FAppIPackageEventListener.h"

namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {


/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 *
 * @interface	IGuestPackageEventListener.
 * @brief		This interface provides methods for the guest application.
 * @since		1.2
 *
 * The %IGuestPackageEventListener interface implements a listener for the guest package installation.
 */
class _EXPORT_APP_ IGuestPackageEventListener :
	public IPackageEventListener
{
public:

/**
* @internal
* This method is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this method.
*
* Notifies when guest package installation is completed.
*
* @since			1.2
* @param[in]	guestAppId		The ID of the native application running on a guest platform.
* @param[in]	pkgErrType			The installation errors.
*/
virtual void OnGuestAppInstallCompleted (const Osp::Base::String& guestAppId,  Osp::App::PackageErrorType pkgErrType) = 0;

};


}; }; // Osp::App

#endif // _FAPP_IGUEST_PACKAGE_EVENT_LISTENER_H
