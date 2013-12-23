/* $Change: 1198808 $ */
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
 * @file	FAppDownloadUIManager.h 
 * @brief	This is the header file for the %DownloadUIManager class.
 *
 * This header file contains the declarations of the %DownloadUIManager class.
 */


#ifndef  _FAPP_DOWNLOAD_MANAGER_H_
#define	 _FAPP_DOWNLOAD_MANAGER_H_

#include "FBaseObject.h"
#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FBase.h"
#include "FAppPackageManager.h"

namespace Osp { namespace Base { class String; }; };

typedef	int	DUIHandle;

namespace Osp { namespace App {

class IDownloadUIEventListener;

/**
* @if PRIVCORE
* @class	DownloadUIManager
* @brief	This class provides methods to manage the downloads.
* @since	1.0
*
* The %DownloadUIManager class provides methods to manage the downloads.
* @endif
*/
class _EXPORT_APP_ DownloadUIManager :
	public Osp::Base::Object
{
public:

	/**
	 * @if PRIVCORE
	 * @enum DownloadUIState
	 * Defines download UI states
	 *
	 * @since	1.0
	 * @endif
	 */
	enum DownloadUIState
	{
		DUI_STATE_NONE = 0,
		DUI_STATE_DOWNLOAD_START,
		DUI_STATE_DOWNLOADING,
		DUI_STATE_DOWNLOAD_COMPLETE,
		DUI_STATE_SET_ACTIVATE,
		DUI_STATE_SET_DEACTIVATE,
		DUI_STATE_INSTALL_START,
		DUI_STATE_INSTALLING,
		DUI_STATE_INSTALL_COMPLETE,
		DUI_STATE_SET_IMAGE,
		DUI_STATE_DOWNLOAD_CANCEL,
		DUI_STATE_DOWNLOAD_PAUSE,
		DUI_STATE_INSTALL_READY,  	// In case of installation failure, this state refers installable again.
		DUI_STATE_INSTALL_ERROR_FATAL, // In case of installation failure, this state refers uninstallable again.
		DUI_STATE_SERVICE_AVAILABLE,
		DUI_STATE_SERVICE_UNAVAILABLE,
		DUI_STATE_DOWNLOAD_MEMORY_FULL, // this will be deprecated. please use DUI_STATE_DOWNLOAD_MEMORY_FULL.  
		DUI_STATE_DOWNLOAD_ERROR_FATAL,
		DUI_STATE_STATE_DOWNLOAD_MEMORY_FULL = DUI_STATE_DOWNLOAD_MEMORY_FULL // DUI_STATE_STATE_DOWNLOAD_MEMORY_FULL will be deprecated.
	};

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	DownloadUIManager();

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~DownloadUIManager();
	
	/**
	 * @if PRIVCORE
	 * Initializes this instance of %DownloadUIManager with the specified parameter.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return		An error code
	 * @param[in]	pListener			A pointer to the IDownloadUIEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result Construct(IDownloadUIEventListener* pListener);

public:

	/**
	 * @if PRIVCORE
	 * Displays a graphical effect when starting a download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	pIconPath			The icon path
	 * @param[in]	showMenu			Set to @c true to show the menu, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team
	 * @endif
	 */
	result Start(const Osp::Base::String& appId, const Osp::Base::String* pIconPath, bool showMenu );

	/**
	 * @if PRIVCORE
	 * Displays a graphical effect when canceling a download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team
	 * @endif
	 */
	result Cancel(const Osp::Base::String& appId);

	/**
	 * @if PRIVCORE
	 * Displays a graphical effect when pausing a download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId				The application ID 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result Pause(const Osp::Base::String& appId);

	/**
	 * @if PRIVCORE
	 * Displays a graphical effect when resuming a download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId				The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result Resume(const Osp::Base::String& appId);

	/**
	 * @if PRIVCORE
	 * Updates a downloading application icon.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId	 			The application ID
	 * @param[in]	pIconPath			The icon path
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result UpdateIcon(const Osp::Base::String& appId, const Osp::Base::String* pIconPath);

	/**
	 * @if PRIVCORE
	 * Updates the progress of the download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId		 		The application ID
	 * @param[in]	progress			The progress as an index percentage
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result UpdateProgress(const Osp::Base::String& appId, int progress);

	/**
	 * @if PRIVCORE
	 * Gets a list of the pending application downloads.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[out]	pPendingAppList	 	The pending list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result GetPendingAppList(Osp::Base::Collection::ArrayList& pPendingAppList);

	/**
	 * @if PRIVCORE
	 * Updates the state of the download.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	appId				The application ID
	 * @param[in]	state				The state to be updated
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result UpdateState(const Osp::Base::String& appId, DownloadUIState state);


	/**
	 * @if PRIVCORE
	 * Updates the downloading state with a package type, application icon, progress value, and progress visible option.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	pkgType				The type of application
	 * @param[in]	appId				The application ID
	 * @param[in]	state				The state to be updated
	 * @param[in]	pIconPath			The location of the icon
	 * @param[in]	progress			The progress value
	 * @param[in]	showMenu			Set to @c true to display the menu, @n
     *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result UpdateState(PackageManager::PackageType pkgType, const Osp::Base::String& appId, DownloadUIState state , const Osp::Base::String* pIconPath, int progress, bool showMenu);
		
	/**
	 * @if PRIVCORE
	 * Gets the count of the available icons.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return The number of available icons
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	int	GetAvailableIconCount(void) const;
	
	/**
	 * @if PRIVCORE
	 * Gets the count of the Una badge.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return The number of Una badges
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	int	GetUnaBadgeCount(void) const;
	
	/**
	 * @if PRIVCORE
	 * Gets the count of the available widgets.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return The number of available widgets
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	int	GetAvailableWidgetCount(void) const;

private:
	static bool DownloadUICB(char* pAppId, int state);

	static bool DownloadUIWidgetCB(char* pWidgetId, int state, int progress);

	result UpdateDownloadUIInfo(const Osp::Base::String& appId, void* pDUIInfo);

private:
	static Osp::Base::Runtime::IEventListener* __pListener;
	void* __pIMPackageManager;

private:
	friend class DownloadUIManagerEx;
	class DownloadUIManagerEx* __pDownloadUIManagerEx;

}; /* -----  end of class DownloadUIManager  ----- */

}; }; // Osp::App

#endif     /* -----  not _FAPP_DOWNLOAD_MANAGER_H_  ----- */

