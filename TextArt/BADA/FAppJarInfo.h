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
 * @file		FAppJarInfo.h
 * @brief		This is the header file for the %JarInfo class.
 * 
 * This header file contains the declarations of the %JarInfo class.
 */
#ifndef  _FAPP_JAR_INFO_H_
#define	 _FAPP_JAR_INFO_H_

#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FAppPackageManager.h"

#include <FBaseObject.h>

namespace Osp { namespace App {


/**
 * @if PRIVCORE
 * @class		JarInfo
 * @brief		This class represents the information of JAR.
 * @since		1.0
 *
 * The %JarInfo class provides the information of JAR.
 * @endif
 *
 */
class _EXPORT_APP_ JarInfo : 
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	JarInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~JarInfo(void);

	/**
  	 * @internal
  	 * This method is for internal use only. The bada platform team is not
  	 * responsible for any behavioral correctness, consistency, and
  	 * security-related issues that might arise after using this method.
  	 *
  	 * Checks whether the value of the Object parameter is equal to the value of the calling object.
  	 *
  	 * @since			2.0
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
	 * Constructs the instance of this class .
	 *
	 * @since		2.0
	 * @return	    An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	if the instance is already initialized
	 */

	result Construct(const Osp::Base::String& appName, const Osp::Base::String& appVersion, int installedJarIndex);
	
	/**
	 * Gets the name of the Java application
	 *
	 * @since  2.0
	 *
	 * @return the name of the Java application.
	 */
	 Osp::Base::String GetAppName (void) const;

	/**
	 * Gets the version of the Java application
	 *
	 * @since  2.0
	 *
	 * @return the version of the Java application.
	 */
	Osp::Base::String GetAppVersion (void) const;

 	/**
	 * Gets the index of the installed JAR.
	 *
	 * @since  2.0
	 *
	 * @return An package index number 
	 * @remarks If the package is not installed, -1 is returned.
	 */
	int GetInstalledIndex(void) const;


private:
	Osp::Base::String* __pAppName;
	Osp::Base::String* __pAppVersion;
	int __index;
	bool __initialized;
	
	friend class JarInfoEx;
	class JarInfoEx* __pJarInfoEx;
};


}; }; // Osp::App

#endif
