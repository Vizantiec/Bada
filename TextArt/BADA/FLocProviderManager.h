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
 * @file	FLocProviderManager.h
 * @brief	This is the header file for the %ProviderManager class.
 *
 * This header file contains the declarations of the %ProviderManager class.
 *
 */

#ifndef _FLOC_IPROVIDER_MANAGER_H_
#define _FLOC_IPROVIDER_MANAGER_H_

#include "FLocProviderCapabilities.h"


// Forward declaration
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class IServiceProvider;
class __ProviderCapsInfo;

/**
 * @class	ProviderManager
 * @brief 	This class is the starting point for using the service provider interfaces.
 * @deprecated	This class is deprecated.
 * @since 	1.0
 *
 * The %ProviderManager class is used to search different service providers and get the actual provider instances.
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/locations_namespace.htm">Locations Guide</a>.
 */
class _EXPORT_LOCATION_ ProviderManager
{
// Lifecycle
private:
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	ProviderManager(void);
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	~ProviderManager(void);

// Operation
public:
	/**
	 * Gets an instance of the specified service provider to be used in the service requests. @n
	 * If an empty string or "DEFAULT_SERVICE_PROVIDER" is specified as the service provider name, this method returns the default service provider for the requested service type
	 * and @ref ProviderCapabilities::GetServiceProviderName() returns "DEFAULT_SERVICE_PROVIDER". 
	 * The @c type parameter is passed to clarify the type of service requested, if the service provider supports more than one type of service. 
	 * The service type must be one of the constants defined in @ref LocationServiceProviderType.
	 * The method always returns a new instance of the requested service provider. 
	 * In some cases, the service provider may require authentication or some other additional information. 
	 * This information can be sent to the service provider using @c extraInfo. The service provider specifies the format of this additional information.
	 * There may be service provider-specific property keys in the ProviderCapabilities class to define this information, and an empty string is used if there is no additional information. 
	 * If @c extraInfo is an empty string or contains incorrect information even though an additional information is required to connect to the service provider, E_INVALID_ARG is thrown.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, @ref ReferencePageConnectToServiceProviderN "here".
	 * @privlevel      NORMAL
	 * @privgroup   LOCATION_SERVICE
	 *
	 * @return		A new instance of the requested service provider, @n
	 *				else @c null if no service provider fulfills the given name and type requirements, or if additional information is needed that is not 
	 *				provided with the @c extraInfo parameter
	 * @param[in]	name				The name of the service provider to be instantiated @n
	 *									For empty string or "DEFAULT_SERVICE_PROVIDER", this method returns the default service provider for the requested service type.
	 * @param[in]	type				The type of the requested service
	 * @param[in]	extraInfo			The additional information, for example, a user name or URL that is sent to the service provider @n
	 *									An empty string if no additional information is needed
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c type is not one of the constants defined in this class or needs additional information that has not 
	 *									been provided by the @c extraInfo parameter.
	 * @exception	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_LOCATION_SERVICE	The method has failed to connect to the service provider.
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	static IServiceProvider* ConnectToServiceProviderN(const Osp::Base::String& name, LocationServiceProviderType type, const Osp::Base::String& extraInfo);

	/**
	 * @page	ReferencePageConnectToServiceProviderN Compatibility for ConnectToServiceProviderN()
	 * @section	SectionConnectToServiceProviderIssue Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 * -# If an empty string or "DEFAULT_SERVICE_PROVIDER" is specified as the service provider name, E_INVALID_ARG is returned.
	 * 
	 *
	 * @section	SectionConnectToServiceProviderResolution Resolutions 
	 * The issue mentioned above is resolved in bada API version 2.0 as follows. @n
	 * If an empty string or "DEFAULT_SERVICE_PROVIDER" is specified as the service provider name,
	 * the default service provider for the requested service type is returned.
	 *
	 * @par When working with bada API versions prior to 2.0:
	 * Specify the real name of the default service provider instead of an empty string or "DEFAULT_SERVICE_PROVIDER".
	 */
	 
	/**
	 * Gets the capabilities for service providers of the specified service type. @n
	 * The possible service types are defined as constants in @ref LocationServiceProviderType. This method may return information about more than one service provider. An 
	 * application can check the capabilities of different service providers from the returned %ProviderCapabilities instances. Returns a list of 
	 * %ProviderCapabilities instances of all the service providers on the device that provide the requested service. The returned %ProviderCapabilities 
	 * instances contain only the capabilities of the service providers for the requested service type. 
	 * The default service provider defined by the platform is returned to the first element of the list.
	 * In some service providers, the actual service request may be performed on a remote server. However, even for these kinds of services the capabilities of the service
	 * must be stored on the device. Therefore, while searching for the service providers, the use of this method does not cause network traffic.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		A list of the @ref ProviderCapabilities objects for all the service providers that support the specified service type, @n
	 *				else @c null if there are no providers for the specified service type
	 * @param[in]	type				The type of the requested service
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c type is not @ref LocationServiceProviderType.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @remarks		The returned list must be deleted. Be sure not to delete its elements.
	 *
	 */
	static Osp::Base::Collection::IList* GetServiceProviderCapabilitiesN(LocationServiceProviderType type);

private:
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	static Osp::Base::Collection::IList* GetServiceProviderCapabilitiesN(LocationServiceProviderType type, const Osp::Base::String* pName);

};	// class ProviderManager

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IPROVIDER_MANAGER_H_
