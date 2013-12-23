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
 * @file			FAppPackageManager.h 
 * @brief		This is the header file of the %PackageManager class.
 * 
 * This header file contains the declarations of the %PackageManager class.
 */

#ifndef  _FAPP_PACKAGE_MANAGER_H_
#define	 _FAPP_PACKAGE_MANAGER_H_

#include "FBaseObject.h"
#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FBase.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Base { class String; }; };

typedef	int	DUIHandle;

namespace Osp { namespace App {


/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Package update notify string
 *
 * @since		1.0
 *
 * This class provides the methods to install/uninstall the various kinds of the applications, retrieve the information of the packages that are installed on the device and handle DRM(Digital Rights Management) of the package.
 */
static const Osp::Base::String PACKAGE_UPDATE_NOTIFY_OFF= L"off";

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Package update notify Wi-Fi string
 *
 * @since		1.0
 */
static const Osp::Base::String PACKAGE_UPDATE_NOTIFY_WIFI= L"wifi";

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process.
 * Package update notify packet string.
 *
 * @since		1.0
 */
static const Osp::Base::String PACKAGE_UPDATE_NOTIFY_PACKET= L"packet";

class IPackageEventListener;
class PackageInfo;

/**
 * @if PRIVCORE
 * @class		PackageManager
 * @brief		This class manages the application package.
 * @since		1.0
 *
 * The %PackageManager class provides the methods to install/uninstall diverse kinds of application packages that are installed on the device and retrieve the package information.
 * The %PackageManager instance can be obtained through PackageManager::GetInstance().
 * @endif
 */
class _EXPORT_APP_ PackageManager :
	public Osp::Base::Object
{
	

private:
	/*
	 * @class		__PackageInstallationInfo
	 * @brief		This class represents information of package installation. 
	 * @since		1.0
	 *
	 * The %__PackageInstallationInfo class provides appid and result code of a package.
	 * This class is used for internals of the Package Manager.
	 *
	 */
	 
	class __PackageInstallationInfo : public Osp::Base::Object
	{
	public:
		Osp::Base::String __appId;
		int __result;
	
		inline __PackageInstallationInfo(){ __appId=""; __result=0; };
		inline ~__PackageInstallationInfo(){};
	};
	


public:

	/**
	 * @enum PackageAttribute
	 * Defines the package attributes.
	 *
	 * @since		1.0
	 */
	enum PackageAttribute
	{
		PKG_ATT_NONE							= 0x00000000, /**< @internal invalid package attribute */
		PKG_ATT_NORMAL							= 0x00000001,		/**< package attribute representing a downloadable application */
		PKG_ATT_PRELOADED_SYSTEM				= 0x00000002,		/**< @internal package attribute representing a preloaded application */
		PKG_ATT_PRELOADED_SAMPLE				= 0x00000004,		/**< @internal package attribute for internal usage only */
		PKG_ATT_SERVICE							= 0x00000008,		/**< @internal package attribute for internal usage only */		
		PKG_ATT_JIL								= 0x00000010,		/**< @internal package attribute for internal usage only */
		PKG_ATT_NOTIFICATION					= 0x00000020,		/**< @internal package attribute for internal usage only */
		PKG_ATT_AGENT							= 0x00000040,		/**< @internal package attribute representing agent */
		PKG_ATT_AGENT_LAUNCH_ON_BOOT			= 0x00000080,		/**< @internal package attribute representing boot-on agent */
		PKG_ATT_POSTLOADED						= 0x00000100,		/**< @internal package attribute representing postloaded application */
		PKG_ATT_JAVA							= 0x00000200,		/**< package attribute representing Java application */
		PKG_ATT_GAME							= 0x00000400,       /**< @internal package attribute for internal usage only */
		PKG_ATT_THEME							= 0x00000800,      	/**< @deprecated This attribute is deprecated. Instead of using this attribute, use PKG_ATT_THEME_DOWNLOADABLE */

		PKG_ATT_WIDGET_PRELOADED				= 0x10010000,		/**< @internal package attribute representing a preloaded widget application */
		PKG_ATT_WIDGET_POSTLOADED				= 0x10020000,		/**< @internal package attribute representing a postloaded widget application */
		PKG_ATT_WIDGET_DOWNLOADED				= 0x10040000,		/**< @internal package attribute representing a downloadable widget application */
		PKG_ATT_WIDGET_DOWNLOADABLE				= 0x10040000,		/**< package attribute representing a downloadable widget application  @b since: @b 2.0 */
		
		PKG_ATT_THEME_PRELOADED					= 0x20100001,		/**< @internal package attribute representing a preloaded theme  @b since: @b 2.0 */
		PKG_ATT_THEME_POSTLOADED				= 0x20100002,		/**< @internal package attribute representing a postloaded theme  @b since: @b 2.0 */
		PKG_ATT_THEME_DOWNLOADABLE				= 0x20100004,		/**< package attribute representing a downloadable theme  @b since: @b 2.0 */

		PKG_ATT_FONT_PRELOADED					= 0x20200001,		/**< @internal package attribute representing a preloaded font  @b since: @b 2.0 */
		PKG_ATT_FONT_POSTLOADED					= 0x20200002,		/**< @internal package attribute representing a postloaded font  @b since: @b 2.0 */
		PKG_ATT_FONT_DOWNLOADABLE				= 0x20200004,		/**< package attribute representing a downloadable font  @b since: @b 2.0 */
		
		PKG_ATT_FLASH_PRELOADED					= 0x20400001,		/**< @internal package attribute representing a preloaded Flash application  @b since: @b 2.0 */
		PKG_ATT_FLASH_POSTLOADED				= 0x20400002,		/**< @internal package attribute representing a postloaded Flash application  @b since: @b 2.0 */
		PKG_ATT_FLASH_DOWNLOADABLE				= 0x20400004,		/**< package attribute representing a downloadable Flash application  @b since: @b 2.0 */		
		
		PKG_ATT_WEB_PRELOADED					= 0x20800001,		/**< @internal package attribute representing a preloaded %Web application  @b since: @b 2.0 */
		PKG_ATT_WEB_POSTLOADED					= 0x20800002,		/**< @internal package attribute representing a postloaded %Web application  @b since: @b 2.0 */
		PKG_ATT_WEB_DOWNLOADABLE				= 0x20800004,		/**< package attribute representing a downloadable %Web application  @b since: @b 2.0 */	

		PKG_ATT_CONTENT_PRELOADED				= 0x21000001,		/**< @internal package attribute representing a preloaded content application  @b since: @b 2.0 */
		PKG_ATT_CONTENT_POSTLOADED				= 0x21000002,		/**< @internal package attribute representing a postloaded content application  @b since: @b 2.0 */
		PKG_ATT_CONTENT_DOWNLOADABLE			= 0x21000004,		/**< package attribute representing a downloadable content application  @b since: @b 2.0 */

		PKG_ATT_PRELOADED_ATTRIBUTE_MAX		= 0xFFFFFFFF  /**< @internal maximum range of package attribute */

	};

	/**
	 * @enum PackageType
	 * Defines package types
	 *
	 * @since		1.0
	 */
	enum PackageType
	{
		PKG_TYPE_NATIVE 	= 0x0001,			/**< Native package type */
		PKG_TYPE_WIDGET 	= 0x0002,			/**< Widget package type */
		PKG_TYPE_JAVA 		= 0x0004,			/**< Java package type */
		PKG_TYPE_JIL		= 0x0008,			/**< @internal JIL package type */
		PKG_TYPE_THEME		= 0x0010,			/**< Theme package type  @b since: @b 2.0 */
		PKG_TYPE_FONT		= 0x0020,			/**< @internal Font package type  @b since: @b 2.0 */		
		PKG_TYPE_FLASH		= 0x0040,			/**< Flash application package type  @b since: @b 2.0 */
		PKG_TYPE_WEB		= 0x0080,			/**< %Web application package type  @b since: @b 2.0 */
		PKG_TYPE_CONTENT	= 0x0100,			/**< %Content package type  @b since: @b 2.0 */
		
		PKG_TYPE_MAX		= 0xFFFF
	};

	/**
	 * @enum UpdateNotifyOperationType
	 * Defines notify operation types to update.
	 *
	 * @since		1.0
	 */
	enum UpdateNotifyOperationType
	{
		UNO_TYPE_READ = 0,				/**< The notification operation to update: read */
		UNO_TYPE_WRITE = 1	  /**< The notification operation to update: write */
	};

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	PackageManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~PackageManager(void);
	
	/**
	 * @if PRIVCORE
	 * Initializes this instance of %PackageManager with the specified listener.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return		An error code
	 * @param[in]	pListener			A pointer to the IPackageEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result Construct(const IPackageEventListener* pListener);

	/**
	 * @if PRIVCORE
	 * Generates a license request and URL.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	licenseRequestInfo	The string buffer of license request information
	 * @param[out]  licenseRequest      The string buffer of DRM license request
	 * @param[out]	licenseUrl		    The URL for DRM license
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result  GenerateDrmLicenseRequest(const Osp::Base::String& licenseRequestInfo, Osp::Base::String& licenseRequest, Osp::Base::String& licenseUrl);

	/**
	 *
	 * @if PRIVCORE
	 *  Updates DRM license(Right Object). It stores the right object when it doesn't exist in the DRM repository.
	 *
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in]	rightObject		DRM right object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @exception	E_INVALID_STATE 	This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks 	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result UpdateDrmLicense(const Osp::Base::String& rightObject); 
	
	/**
	 *
	 * @if PRIVCORE
	 *  Gets the remaining time of the package until DRM license expiration. 
	 *
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	The remaining time of DRM license
	 * @param[in]	pkgContentId		cid of an OMA DRM content.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	An unknown system error has occurred.
	 * @exception	E_RIGHT_EXPIRED		DRM license has been expired or is not found.
	 * @exception	E_INVALID_OPERATION		DRM license is unlimited, which will not expire.
	 * @exception	E_INVALID_STATE 	This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	Osp::Base::TimeSpan GetRemainingTimeUntilDrmExpiration(const Osp::Base::String& pkgContentId);

	/**
	* @if PRIVCORE
	* Installs the application with an attribute and application ID. @n
	* This method operates asynchronously, that is, it ends immediately without installation results. The application is notified when the installation is done, so the results are available via the IPackageEventListener::OnPackageInstallCompleted() method if this method returns E_SUCCESS.
	* 
	*
	* @since			1.0
	* @privlevel	CORE
	* @privgroup  INSTALLATION
	*
	* @return	An error code
	* @param[in] pkgType 				The package type
	* @param[in] appId 					The application ID
	* @param[in] packagePath 			The package path
	* @param[in] pRoPath 				The right object path
	* @param[in] attribute 				The application attribute
   * @param[in] enableUiCallback   Set to @c true to receive the installation progress using IPackageEventListener::OnPackageInstalling(), @n 
      *									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_FAILURE			The method has failed.
	* @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	*									The Construct() method must be called.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_IN_PROGRESS		An application's installation is in progress.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks	Do not use this method without obtaining prior permissions from the bada platform team.
	* @see IPackageEventListener
	* @endif
	*/
	result InstallApp(PackageType pkgType, const Osp::Base::String& appId, const Osp::Base::String& packagePath, const Osp::Base::String* pRoPath, PackageAttribute attribute, bool enableUiCallback=false);


	/**
	 * @if PRIVCORE
	 * Installs the application.
	 *
	 * @deprecated	This method is deprecated. Instead of using this API, use InstallApp() with the argument of application ID.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return	An error code
	 * @param[in] pkgType 				The package type
	 * @param[in] packagePath 			The package file path
	 * @param[in] pRoPath 				The right object path
	 * @param[in] enableUiCallback 		Set to @c true to receive the installation progress using IPackageEventListener::OnPackageInstalling(), @n 
      *									else @c false

	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_IN_PROGRESS		An application's installation is in progress.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not use this method without obtaining prior permissions from the bada platform team.
	 * @see IPackageEventListener
	 * @endif
	 */
	result InstallApp(PackageType pkgType, const Osp::Base::String& packagePath, const Osp::Base::String* pRoPath, bool enableUiCallback=false);

	/**
	* @if PRIVCORE
	* Installs the application with attribute.
	*
	* @deprecated	This method is deprecated. Instead of using this API, use InstallApp() with the argument of application ID.
	*
	* @since			1.0
	* @privlevel	CORE
	* @privgroup  INSTALLATION
	*
	* @return	An error code
	* @param[in] pkgType 				The package type
	* @param[in] packagePath 			The package path	
	* @param[in] pRoPath 				The right object path
	* @param[in] attribute 				The application attribute
	* @param[in] enableUiCallback 		Set to @c true to receive the installation progress using IPackageEventListener::OnPackageInstalling(), @n 
      *									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_FAILURE			The method has failed.
	* @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	*									The Construct() method must be called.
	* @exception   	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @exception	E_IN_PROGRESS		An application's installation is in progress.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		Do not use this method without obtaining prior permissions from the bada platform team.
	* @see IPackageEventListener
	* @endif
	*/
	result InstallApp(PackageType pkgType, const Osp::Base::String& packagePath, const Osp::Base::String* pRoPath, PackageAttribute attribute, bool enableUiCallback=false);

	/**
	 * @if PRIVCORE
	 * Gets an application version of the native package.
	 *
	 * @since			1.0
   * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return An error code
	 * @param[in]	appId	  The application ID
	 * @param[out]	version	  The application version
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_OBJ_NOT_FOUND		The application is not found.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @endif
	 *	
	 */
	result GetAppVersion(const Osp::Base::String& appId, Osp::Base::String& version) const;

	/**
	 * @if PRIVCORE
	 * Gets packages with an attribute.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return 	An error code
	 * @param[in]	attributes			The package attribute to be retrieved
	 * @param[out]	pkgList	    		The package list of a PackageInfo type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result GetAppPackageList(PackageAttribute attributes, Osp::Base::Collection::ArrayList& pkgList) const;

	/**
	 * @if PRIVCORE
	 * Gets packages with a type and an attribute.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return An error code
	 * @param[in]	pkgType		The package type
	 * @param[in]	pkgAttribute	The attribute of the application
	 * @param[out]	pkgList		The package list of PackageInfo type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result GetAppPackageList(PackageType pkgType, PackageAttribute pkgAttribute, Osp::Base::Collection::ArrayList& pkgList) const;

	/**
	 * @if PRIVCORE
	 * Gets or sets update notification for application store.
	 *
	 * @since			1.0
   * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @param[in]	operation			The operation type (read/write)
	 * @param[out]	value	    		The string value of the update notification type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result	AccessUpdateNotify(UpdateNotifyOperationType operation, Osp::Base::String& value);


	/**
	* @if PRIVCORE
	* Checks whether the application is installed.
	*
	* @since			1.0
  * @privlevel	CORE
	* @privgroup  INSTALLATION
	*
	* @return	@c true if the application is installed @n
  *             else @c false
	* @param[in] appId 	The installed application ID
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance is in an invalid state.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks 		Do not use this method without obtaining prior permissions from the bada platform team.
	* @endif
	*/
	bool IsAppInstalled(const Osp::Base::String& appId) const;

	/**
	 * @if PRIVCORE
	 * Gets an application version.
	 *
	 * @since			1.0
   * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return An error code
	 * @param[in]	pkgType				The package type
	 * @param[in]	appId	  			The application ID
	 * @param[out]	version	  			The application version
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			This method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_OBJ_NOT_FOUND		The application is not found.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif
	 *
	 */
	result GetAppVersion(PackageType pkgType, const Osp::Base::String& appId, Osp::Base::String& version) const;

	/**
	 * @if PRIVCORE
	 * Gets the package information of an application.
	 *
	 * @since			1.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 *
	 * @return An error code
	 * @param[in]	pkgType				The package type
	 * @param[in]	appId	  			The application ID
	 * @param[out]	pkgInfo				The package information
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FAILURE			The method has failed.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_OBJ_NOT_FOUND		The application is not found.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 *          	Only native application type(PKG_TYPE_NATIVE) is available on bada API version 1.0.
	 * @endif
	 */
	result GetAppPackageInfo(PackageType pkgType, const Osp::Base::String& appId, Osp::App::PackageInfo& pkgInfo) const;

	/**
	 * @if PRIVCORE
	 * Uninstalls the application with a given application ID.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup UNINSTALLATION
	 *
	 * @return An error code
	 * @param[in]	appId	  			The application ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_APP_NOT_INSTALLED		The application is not installed.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 * @endif	
	 */
	result UninstallApp(const Osp::Base::String& appId);

	/**
	 * @if PRIVCORE
	 *  Retrieves the package manager instance.
	 *
	 * @since			2.0
	 * @privlevel	CORE
	 * @privgroup INSTALLATION
	 * @return	An PackageManager instance pointer, if successful @n
	 *			@c null, otherwise
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @endif	
	 */
	static PackageManager* GetInstance(void);
	

private:
	/*
	 * Update AppId of internal package information.
	 */
	static bool RegisterInstallPackageCB(int recordId, char* pAppId);

	/*
	 * Forward a package installation complete event to upper application through the IPackageExEventListener.
	 */
	static bool InstallPackageCB(int errorType);

	/*
	 * Forward a package installation complete event to upper application through the IPackageExEventListener.
	 */

  	static bool InstallPackageCBEx( char* pszAppId, int errorType );

	
	/*
	 * Forward a package installation progress event to upper application through the IPackageExEventListener.
	 */
	static bool InstallProgressCB(int action, unsigned long param1, unsigned long param2, void* pParam3);

	/*
	 * Forward a package installation progress event to upper application through the IPackageExEventListener for widget.
	 */
	static bool InstallWidgetProgressCB(void *appId, int state, int progress);

	/* Application Uninstall callback function */
	static bool UninstallAppCB(char* pszAppId, int errorType);
	/*
	 * Forward a widget installation complete event to upper application through the IPackageExEventListener.
	 */
	static bool InstallWidgetCB(int errorType);

	result InstallNativeApp(const Osp::Base::String& packagePath, const Osp::Base::String* pRoPath, PackageAttribute attribute, bool enableUiCallback);

	result InstallWidget(const Osp::Base::String& packagePath, const Osp::Base::String* roPath, PackageAttribute attribute, bool enableUiCallback);

	result InstallJar(const Osp::Base::String& packagePath, const Osp::Base::String& roPath, PackageAttribute attribute, bool enableUiCallback);

	static Osp::Base::Runtime::IEventListener* __pListener;
	void* __pIMPackageManager;
	static __PackageInstallationInfo* __pInstallationInfo;

private:
	friend class PackageManagerEx;
	class PackageManagerEx* __pPackageManagerEx;

}; /* -----  end of class PackageManager  ----- */


}; }; // Osp::App

#endif     /* -----  not _FAPP_PACKAGE_MANAGER_H_  ----- */

