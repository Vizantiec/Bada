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
 * @file		FAppPackageInfo.h
 * @brief		This is the header file for the %PackageInfo class.
 * 
 * This header file contains the declarations of the %PackageInfo class.
 */
#ifndef  _FAPP_PACKAGE_INFO_H_
#define	 _FAPP_PACKAGE_INFO_H_

#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FAppPackageManager.h"

#include <FBaseObject.h>
#include <FBase.h>


namespace Osp { namespace App {


/**
 * @if PRIVCORE
 * @class		PackageInfo
 * @brief		This class represents the information of the package. 
 * @since		1.0
 *
 * The %PackageInfo class provides the information of the package.
 * @endif
 *
 */
class _EXPORT_APP_ PackageInfo : 
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	PackageInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~PackageInfo(void);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Checks whether the value of the Object parameter is equal to the value of the calling object.
	 *
	 * @since			1.0
	 * @return		@c true, if the input Object is equal to the calling Object, or@n
	 *				@c false, otherwise.
	 * @param[in]	obj		The object to be compared with the calling object
	 * @see			Osp::Base::Object::Equals()
	 */
	virtual bool  Equals (const Object &obj) const ;
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Sets package information
	 *
	 * @since			1.0
	 * @return An error code
	 * @param[in]	pMAppPkgInfo   		The application package information
	 * @exception	E_SUCCESS			The method is successful.	 
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.	 
	 */	
	result Set(void* pMAppPkgInfo);
	
	/**
	 * Gets the application ID of the package.
	 *
	 * @since	 1.0
	 * @return The application ID
	 */	 
	AppId GetAppId(void) const;
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Set application ID
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]	appId     			The application ID
	 * @exception	E_SUCCESS			The method is successful.	 	 
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */	
	result SetAppId(AppId appId);
	
	/**
	 * Gets the application version of the package.
	 *
	 * @since		1.0
	 * @return  The application version
	 */	
	Osp::Base::String GetVersion(void) const;
		
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Sets application version
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]	version   The package version 
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.	 
	 */	
	result SetVersion(Osp::Base::String version);
		
		
	/**
	 * Gets the package attribute.
	 *
	 * @since	 1.0
	 * @return The package attribute
	 */	
	PackageManager::PackageAttribute GetAttribute(void) const;
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Set package attribute
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]	attribute  			The package attribute
	 * @exception	E_SUCCESS			The method is successful.	 	 
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.	 
	 */	
	result SetAttribute(PackageManager::PackageAttribute attribute);
		
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Gets package type
	 *
	 * @since	 1.0
	 * @return The package type
	 */	
	PackageManager::PackageType GetType(void) const;
		
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Sets package type
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]	type   				The package type
	 * @exception	E_SUCCESS			The method is successful.	 	 
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.		 
	 */	
	result SetType(PackageManager::PackageType type);		

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the size of R/O data of /Res, /Bin, /Info folders in the package @n
	 * This size is needed to calculate updatable storage size in detail because R/O data will be overwrited.
	 *
	 * @since		1.0
	 * @return	The read only data size of package
	 */
	unsigned long GetReadOnlyDataSize(void) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Sets the size of package R/O data
	 *
	 * @since			1.0
	 * @return 		An error code
	 * @param[in]	type   				The package type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result SetReadOnlyDataSize(unsigned long readOnlyDataSize);

	/**
	 * Gets an application name of the package.
	 *
	 * @since	 2.0
	 * @return	The application name
	 */
	Osp::Base::String GetName(void) const;
	
	/**
	 * Gets the secret code of the package.
	 *
	 * @since	 2.0
	 *
	 * @return	An application's secret code
	 */
	AppSecret GetAppSecret(void) const;


private:
	Osp::Base::String __appId;
	Osp::Base::String __version;
	PackageManager::PackageAttribute __attr;
	PackageManager::PackageType	__type;
	unsigned long __readOnlyDataSize;

private:
	friend class PackageInfoEx;
	class PackageInfoEx* __pPackageInfoEx;
};


}; }; // Osp::App

#endif
