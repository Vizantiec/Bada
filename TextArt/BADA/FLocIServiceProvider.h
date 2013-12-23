/* $Change: 1267243 $ */
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
 * @file		FLocIServiceProvider.h
 * @brief		This is the header file for the IServiceProvider interface.
 *
 * This header file contains the declarations of the IServiceProvider interface.
 *
 */

#ifndef _FLOC_ISERVICE_PROVIDER_H_
#define _FLOC_ISERVICE_PROVIDER_H_

#include "FLocationConfig.h"

// Forward declaration

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class ProviderCapabilities;
class ServicePreferences;

/**
 * @interface	IServiceProvider
 * @brief		This interface implements a listener for all the service providers.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * 	The %IServiceProvider interface implements a listener for all the service providers and thus acts as a super interface for all the service providers. It 
 *				contains the methods common to all the providers.
 *
 */
class _EXPORT_LOCATION_ IServiceProvider
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IServiceProvider(void);

// Operation
public:

	/** 
	 * Gets the capabilities of the service provider. @n
	 * 
	 * This information contains, for example, the type of the service, and the name of the service provider. The method returns the capabilities of the 
	 * service type of the specific service provider. This means that if an application has, for example, searched and connected to 
	 * @ref IMapServiceProvider, this method returns only the capabilities related to the map service.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 * @return	The service provider capabilities
	 *
	 */
	virtual const ProviderCapabilities&	GetProviderCapabilities(void) const = 0;


	/** 
	 * Gets the service preferences for this service provider. @n
	 * 
	 * The method returns a new instance of ServicePreferences. With the parameter @c defaultValues, an application controls whether it requests the default 
	 * values of the service provider or the values that were used in the last service request. If there have not been any service requests, and the last 
	 * used preferences are requested (meaning @c defaultValues is set to @c false), the default values are returned. The values for each preference
	 * are returned with the ServicePreferences::Get* methods. An application may change these values with the ServicePreferences::Set* methods.
	 *
	 * The returned instance of %ServicePreferences is tied to one specific service provider. Passing the preferences retrieved from another service provider 
	 * causes the exception E_INVALID_ARG to be thrown in the service request.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The service preferences for this service provider
	 * @param[in]	defaultValues		Set to @c true if the application requests the default values of the service provider, @n 
	 *									else @c false
	 * @remarks		The returned %ServicePreferences instance must be deleted.
	 */
	virtual ServicePreferences*	GetServicePreferencesN(bool defaultValues) const = 0;

};	// class IServiceProvider

}; }; };	// Osp::Locations::Services

#endif // _FLOC_ISERVICE_PROVIDER_H_
