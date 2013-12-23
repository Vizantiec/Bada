/* $Change: 518380 $ */
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
 * @file		FAppGuestPackageInfo.h
 * @brief		This is the header file for the %GuestPackageInfo class.
 *
 * This header file contains the declarations of the %GuestPackageInfo class.
 */
#ifndef _FAPP_GUEST_PACKAGE_INFO_H_
#define _FAPP_GUEST_PACKAGE_INFO_H_

#include "FAppPackageManager.h"
#include "FAppGuestPackageManager.h"
#include "FBaseObject.h"
#include "FAppConfig.h"
#include "FAppTypes.h"
#include "FBase.h"


namespace Osp { namespace App {

/**
 * @if PRIVCORE
 * @class		GuestPackageInfo
 * @brief		This class provides the information on the guest package. 
 * @since		1.2
 *
 * The %GuestPackageInfo class provides the information on the guest package.
 * @endif
 *
 */
class _EXPORT_APP_ GuestPackageInfo : 
	public Osp::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.2
	 */
	GuestPackageInfo(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.2
	 */
	virtual ~GuestPackageInfo(void);

	
	/**
	 * Gets the guest application's ID.
	 *
	 * @since	 1.2
	 * @return The guest application's ID
	 */	 
	Osp::Base::String GetGuestAppId(void) const;

	/**
	 * Gets the guest application's version.
	 *
	 * @since		1.2
	 * @return  The guest application's version
	 */	
	Osp::Base::String GetGuestAppVersion(void) const;
	
	/**
	 * Gets the guest application's name.
	 *
	 * @since		1.2
	 * @return  The guest application's name
	 */	
	Osp::Base::String GetGuestAppName(void) const;

private:
	Osp::Base::String __guestAppId;
	Osp::Base::String __guestAppVersion;
	Osp::Base::String __guestAppName;
	
	friend class GuestPackageInfoEx;
	class GuestPackageInfoEx* __pGuestPackageInfoEx;
};


}; }; // Osp::App

#endif
