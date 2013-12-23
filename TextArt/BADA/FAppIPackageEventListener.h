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
 * @file			FAppIPackageEventListener.h
 * @brief			This is the header file for the %IPackageEventListener interface.
 * 
 * This header file contains the declarations of the %IPackageEventListener interface.
 */

#ifndef _FAPP_IPACKAGE_EVENT_LISTENER_H
#define _FAPP_IPACKAGE_EVENT_LISTENER_H

#include "FAppConfig.h"
#include "FBaseRtIEventListener.h"
#include "FAppPackageManager.h"

namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };

namespace Osp { namespace App {

/**
 * @if PRIVCORE 
 * @enum PackageErrorType
 * Defines the type of package error information.
 *
 * @since 1.0  
 * @endif
 */
typedef enum
{
	PACKAGE_ERROR_NONE	= 0,			/**< @if PRIVCORE Success @endif */	
	PACKAGE_INSTALLING,					/**< @if PRIVCORE Another application is installing @endif */
	PACKAGE_INVALID_PACKAGE,			/**< @if PRIVCORE An invalid package @endif */
	PACKAGE_MAX_APP_COUNT,				/**< @if PRIVCORE %Application count max @endif */
	PACKAGE_OUT_OF_STORAGE,				/**< @if PRIVCORE The installation target storage is full @endif */
	PACKAGE_CERTIFICATE,				/**< @if PRIVCORE Error while passing the certificate @endif */
	PACKAGE_CERTIFICATE_VALIDITY,		/**< @if PRIVCORE The certificate is expired @endif */
	PACKAGE_CERTIFICATE_REVOKED,		/**< @if PRIVCORE The certificate is revoked and is checked by OCSP @endif */
	PACKAGE_ROOT_CA_NOT_FOUND,			/**< @if PRIVCORE Failed to find root certificate @endif */
	PACKAGE_SIGNATURE_FAILURE,			/**< @if PRIVCORE Failed to check the signature @endif */
	PACKAGE_UNKNOWN,					/**< @if PRIVCORE Unknown Error @endif */
}PackageErrorType;

/**
 * @if PRIVCORE
 * The package installation has started.
 *
 * @since 2.0
 * @endif
 */
static const int INSTALL_ACTION_START = 0;

/**
 * @if PRIVCORE
 * The package installation is in progress.
 *
 * @since 2.0
 * @endif
 */
static const int INSTALL_ACTION_ONGOING = 1;

/**
 * @if PRIVCORE
 * The package installation has finished.
 *
 * @since 2.0
 * @endif
 */
static const int INSTALL_ACTION_FINISH	 = 2;

/**
 * @if PRIVCORE
 * The package installation has canceled.
 *
 * @since 2.0
 * @endif
 */
static const int INSTALL_ACTION_CANCEL = 3;


/**
* @if PRIVCORE 
* @interface	IPackageEventListener
* @brief		This interface implements a listener for the package installation.
* @since		1.0
*
* The %IPackageEventListener interface implements a listener for the package installation.

* @endif
*/
class _EXPORT_APP_ IPackageEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:

/**
* @if PRIVCORE 
* Called when the package installation is completed.
*
* @since 			1.0
* @param[in]	appId		The application ID
* @param[in]	pkgType		The package type
* @param[in]	pkgErrType	The installation errors
* @endif
*/
virtual void OnPackageInstallCompleted(const Osp::Base::String& appId, Osp::App::PackageManager::PackageType pkgType, Osp::App::PackageErrorType pkgErrType) = 0;

/**
* @if PRIVCORE 
* Called when the installation is in progress.
*
* @since 		 1.0
* @param[in] appId		The application ID
* @param[in] pkgType	The package type
* @param[in] action 	It specifies the state of installation progress including Osp::App::INSTALL_ACTION_START, Osp::App::INSTALL_ACTION_ONGOING, Osp::App::INSTALL_ACTION_FINISH and Osp::App::INSTALL_ACTION_CANCEL.
* @param[in] progress 	It specifies the installation progress as an index percentage
* @remarks		This method is not invoked to the package with PackageManager::PKG_TYPE_WIDGET.
* @endif
*/
virtual void OnPackageInstalling(const Osp::Base::String& appId, Osp::App::PackageManager::PackageType pkgType, int action, int progress) = 0;


};


}; }; // Osp::App

#endif // _FAPP_IPACKAGE_EVENT_LISTENER_H
