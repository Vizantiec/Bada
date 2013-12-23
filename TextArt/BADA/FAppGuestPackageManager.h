/* $Change: 520028 $ */
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
 * @file		FAppGuestPackageManager.h 
 * @brief		This is the header file for the %GuestPackageManager class.
 *
 * This header file contains the declarations of the %GuestPackageManager class.
 */

#ifndef  _FAPP_GUEST_PACKAGE_MANAGER_H_
#define	 _FAPP_GUEST_PACKAGE_MANAGER_H_

#include <FAppPackageManager.h>
#include <FAppIPackageEventListener.h>

namespace Osp { namespace App {

class IGuestPackageEventListener;
	
/**
 * @if PRIVCORE
 * @class		GuestPackageManager
 * @brief		This class provides the methods for managing a guest package.
 * @since		1.2
 * 
 * The %GuestPackageManager class provides the methods for managing a guest package.
 * @endif
 */

class _EXPORT_APP_ GuestPackageManager :
	public Osp::App::PackageManager
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.2
	 */
	GuestPackageManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.2
	 */
	virtual ~GuestPackageManager(void);
		
	/**
	 * @if PRIVCORE
	 * Initializes this instance of %GuestPackageManager with the specified parameter.
	 *
	 * @since     	1.2
	 * @privlevel		CORE
	 * @privgroup 	INSTALLATION
	 *
	 * @return			An error code
	 * @param[in]	pListener			A pointer to the IGuestPackageEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 		This method only supports %IGuestPackageEventListener.
	 * @endif
	 */
	result Construct(const IGuestPackageEventListener* pListener);
	
	/**
	 * @if PRIVCORE
	 * Gets the host application ID from the guest application ID.
	 *
	 * @since       1.2
	 * @privlevel		CORE
	 * @privgroup 	INSTALLATION
	 *
	 * @return		The system-assigned application ID to treat a guest application like a native application, @n
					else @c null if there is no match to the specified @c guestAppId
	 * @param[in]	guestAppId			The ID of the native application running on a guest platform
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	 
	 * @see DownloadUIManager.
	 * @remarks A host application ID is available on the DownloadUIManager. @n
	 					 The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String* GetHostAppIdFromN (const Osp::Base::String& guestAppId) const;
	
	/**
	 * @if PRIVCORE
	 * Gets the guest application ID from the host application ID.
	 *
	 * @since       1.2
	 * @privlevel		CORE
	 * @privgroup 	INSTALLATION
	 *
	 * @return		The	ID of the native application running on a guest platform, @n 
					else @c null if there is no match to the specified @c hostAppId.
	 * @param[in]	hostAppId			The system-assigned application ID to treat a guest application like a native application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	 
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::String* GetGuestAppIdFromN (const Osp::Base::String& hostAppId) const;
		
	/**
	 * @if PRIVCORE
	 * Installs a guest application.
	 *
	 * @since      1.2
	 * @privlevel	 CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code	
	 * @param[in] guestAppId			The ID of the native application running on a guest platform
	 * @param[in] packagePath 			The guest package file path
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_IN_PROGRESS		The installation of another application is in progress.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.	
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 */
	result InstallGuestApp (const Osp::Base::String& guestAppId ,const Osp::Base::String& packagePath);
	
 /**
	* @if PRIVCORE
	* Notifies the installation state of the guest application.
	*
	* @since     1.2
	* @privlevel CORE
	* @privgroup INSTALLATION
	*
	* @return			An error code	
	* @param[in] 	guestAppId					The ID of the native application running on a guest platform
	* @param[in] 	pkgErrCode 					The installation error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM						A system error has occurred.
	* @exception	E_INVALID_ARG				A specified input parameter is invalid.	
	* @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	*																	The Construct()	method must be called.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks    Currently, this API supports only SyncML-based PC agent installing guest applications by side-loading.
	* @endif
	*/	
	result NotifyGuestAppInstallationState(const Osp::Base::String& guestAppId, Osp::App::PackageErrorType pkgErrCode);
 	/**	 
	 * @if PRIVCORE
	 * Gets the guest application's version.
	 *
	 * @since     1.2
   * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return An error code
	 * @param[in]	guestAppId	  				The ID of the native application running on a guest platform	
	 * @param[out]	version	  						The application's version
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_SYSTEM						The method has failed.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.	 
	 * @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	 *										The Construct() method must be called.
	 * @exception	E_OBJ_NOT_FOUND		The application is not found.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @endif
	 *	
	 */
	result GetGuestAppVersion(const Osp::Base::String& guestAppId, Osp::Base::String& version) const;
	
	/**
	 * @if PRIVCORE
	 * Registers a guest application on the main menu for displaying the status of the download.
	 *
	 * @since       1.2
	 * @privlevel		CORE
	 * @privgroup   INSTALLATION
	 *
	 * @return			An error code
	 * @param[in] 	guestPlatformId 	A guest platform ID
	 * @param[in] 	guestAppId			The ID of the native application running on a guest platform
	 * @param[in] 	appName 			The application's name
	 * @param[in] 	iconPath 			The icon file's path
	 * @exception		E_SUCCESS						The method is successful.
	 * @exception		E_IN_PROGRESS				The installation of another application is in progress.
	 * @exception		E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state. @n
	 *											The Construct() method must be called.
	 * @exception   	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.		
	 * @exception   	E_SYSTEM 				A system error has occurred.
	 * @endif
	 */
	result RegisterGuestApp (const Osp::Base::String& guestPlatformId, const Osp::Base::String& guestAppId, const Osp::Base::String& appName, const Osp::Base::String& iconPath);
	
	/**
	 * @if PRIVCORE
	 * Checks whether the guest platform is installed.
	 *
	 * @since       1.2
	 * @privlevel		CORE
	 * @privgroup   INSTALLATION
	 *
	 * @return	@c true if the guest platform is installed, @n
     *        		else @c false
	 * @param[in] 	guestAppId 				The ID of the native application running on a guest platform
	 *	
	 * @exception		E_SUCCESS						The method is successful.	
	 * @exception		E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state. @n
	 *											The Construct() method must be called.
	 * @exception   	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.		
	 * @exception   	E_SYSTEM 						A system error has occurred.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */			
	bool IsGuestPlatformInstalled (const Osp::Base::String& guestAppId) const;
		
	/**
 	 * @if PRIVCORE
	 * Installs or updates the guest platform.
	 *
	 * @since       1.2
	 * @privlevel		CORE
	 * @privgroup   INSTALLATION
	 *
	 * @return			An error code
	 * @param[in]   guestPlatformId			The guest platform ID
	 * @param[in] 	packagePath 					The package file's path
	 * @param[in] 	pRoPath 							The right object's path
	 * @exception		E_SUCCESS						The method is successful.	
	 * @exception		E_IN_PROGRESS				The installation of another application is in progress.
	 * @exception		E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception		E_INVALID_STATE			This instance is in an invalid state. @n
	 *											The Construct() method must be called.
	 * @exception   	E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.		
	 * @exception   	E_SYSTEM 						A system error has occurred.	
	 * @remarks If the guest platform is already installed, it will be updated.
	 * @endif
	 */			
	result InstallGuestPlatform(const Osp::Base::String& guestPlatformId, const Osp::Base::String& packagePath, const Osp::Base::String* pRoPath);
		
	/**
	 * @if PRIVCORE
   * Gets the installed guest package list.
	 *
	 * @since      1.2
   * @privlevel	 CORE
	 * @privgroup  INSTALLATION
	 *
	 * @return 		The guest package list (GuestPackageInfo) @n 
					An empty list is returned if there is no match to the package, @n 
					else @c null if an error occurs
	 * @param[in] 	guestPlatformId 			The guest platform ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Osp::Base::Collection::IList* GetGuestPackageListN (const Osp::Base::String& guestPlatformId) const;

    /**
     * @if PRIVCORE
	 * Checks whether the guest application is installed.
	 *
	 * @since      1.2
   * @privlevel	 CORE
	 * @privgroup  INSTALLATION
	 *
	 * @return	@c true if the application is installed, @n
     *        		else @c false
	 * @param[in]   guestAppId 					The ID of the installed native application running on a guest platform
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	bool IsGuestAppInstalled(const Osp::Base::String& guestAppId) const;

   /**
   	* @if PRIVCORE
	* Gets the guest application's information.
	*
	* @since      1.2
	* @privlevel  CORE
	* @privgroup  INSTALLATION
	*
	* @return An error code
	* @param[in]  appId                         The application ID
	* @param[in]  key                        The @c key name
	* @param[out] value                       The @c value of the specified key
	* @exception  E_SUCCESS                     The method is successful.
	* @exception  E_OBJ_NOT_FOUND               The application is not installed.
	* @exception  E_KEY_NOT_FOUND               The specified @c key is not found.
	* @exception  E_INVALID_STATE				This instance is in an invalid state.
	* @exception  E_OUT_OF_MEMORY               The memory is insufficient.
	* @exception  E_SYSTEM                      A system error has occurred.
	* @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks    Do not use this method without obtaining prior permissions from the bada platform team.
	* @endif
	*/
	result GetGuestAppInfo(const Osp::Base::String& appId, const Osp::Base::String& key, Osp::Base::String& value) const;

	/**
	 * @if PRIVCORE
	 *  Retrieves the instance of guest package manager.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 * @return	An GuestPackageManager instance pointer, if successful @n
	 *			@c null, otherwise
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.	 
	 * @endif	
	 */
	static GuestPackageManager* GetInstance(void);

private:
	
	void* __pIMPackageManagerGuest;
	friend class GuestPackageManagerEx;
	class GuestPackageManagerEx* __pGuestPackageManagerEx;

}; /* -----  end of class GuestPackageManager  ----- */


}; }; // Osp::App

#endif     /* -----  not _FAPP_GUEST_PACKAGE_MANAGER_H_  ----- */

