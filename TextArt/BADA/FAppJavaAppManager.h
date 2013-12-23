/* $Change: 1030009 $ */
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
 * @file			FAppJavaAppManager.h 
 * @brief			This is the header file for the %JavaAppManager class.
 *
 * This header file contains the declarations of the %JavaAppManager class.
 */

#ifndef _FAPP_JAVA_APP_MANAGER_H_
#define _FAPP_JAVA_APP_MANAGER_H_



namespace Osp { namespace App {

class IJarEventListener;

/**
 * @if PRIVCORE
 * @class		JavaAppManager
 * @brief		This class manages Java application.
 * @since		2.0
 *
 * The %JavaAppManager class manages a Java application.
 * The Java application manager supports to install, launch the Java application and get the installed application list.
 * @endif
 */
 
class _EXPORT_APP_ JavaAppManager :
	public Osp::Base::Object
{
private:

	/**
	 * This is the default constructor for this class.
	 */
	JavaAppManager(void);

public:

	/**
	 * @if PRIVCORE	
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	JAR_MANAGER
	 *
	 * @endif
	 */
	virtual ~JavaAppManager(void);

	/**
	 * @if PRIVCORE		
	 * Constructs the instance of this class.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	JAR_MANAGER
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result Construct(void);

	/**
	 * @if PRIVCORE
	 *  Retrieves the Java application manager.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	JAR_MANAGER
	 *
	 * @return	An JavaAppManager instance pointer, if successful @n
	 *			@c null, otherwise
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @endif	
	 */
	static JavaAppManager* GetInstance(void);

// Operation
public:

	/**
	 * @if PRIVCORE
	 * Installs the JAR which is not packaged with OAP(bada application package).
	 *
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup JAR_MANAGER
	 *
	 * @return	An error code
	 * @param[in] jarPath	The JAR path
	 * @param[in] jadPath	The JAD path
	 * @param[in] listener	The JAR event listener 
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called before invoking this method.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_IN_PROGRESS		An another application's installation is in progress.
	 * @remarks	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @see IJarEventListener
	 * @endif
	 */
	result Install(const Osp::Base::String& jarPath, const Osp::Base::String& jadPath, const IJarEventListener* listener);


	/**
	 * @if PRIVCORE
	 * Launches the installed Java application.
	 *
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup JAR_MANAGER
	 *
	 * @return	An error code
	 * @param[in] installedJarIndex		The installed JAR Index
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called before invoking this method.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_APP_NOT_INSTALLED	The application is not installed.
	 * @remarks	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @endif
	 */
	result LaunchApplication(int installedJarIndex);

	/**
	 * @if PRIVCORE
	 * Gets the list of the installed Java applications.
	 *
	 *
	 * @since		2.0	
	 * @privlevel	CORE
	 * @privgroup JAR_MANAGER
	 *
	 * @return @c the list of PackageInfo objects if JAR applications are installed.@n
	 * 			@c null, otherwise
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. @n
	 *									The Construct() method must be called.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks	Do not use this API without obtaining prior permissions from the bada platform team.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @see	PackageInfo
	 * @endif
	 */
	Osp::Base::Collection::IList* GetInstalledAppListN(void);

private:
	static bool JarInstallationProgressCB(int dbindex, char *  middleName_data, int result, int progress);
	static void JarInstallationCB(int dbindex, char *  middleName_data, int result, int progress);
	

private:
	static JavaAppManager* __pSelf;
	void* __pIMPackageManagerJava;
	static Osp::Base::Runtime::IEventListener* __pListener;
	
private:
	friend class JavaAppManagerEx;
	class JavaAppManagerEx* __pJavaAppManagerEx;
	
};
}; }; // Osp::App
#endif // _FAPP_JAVA_APP_MANAGER_H_
