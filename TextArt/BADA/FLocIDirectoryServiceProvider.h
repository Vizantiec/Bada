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
 * @file	FLocIDirectoryServiceProvider.h
 * @brief	This is the header file for the IDirectoryServiceProvider interface.
 *
 * This header file contains the declarations of the IDirectoryServiceProvider interface.
 */

#ifndef _FLOC_IDIRECTORY_SERVICE_PROVIDER_H_
#define _FLOC_IDIRECTORY_SERVICE_PROVIDER_H_

// include
#include "FLocationConfig.h"
#include "FLocIServiceProvider.h"
#include "FBaseTypes.h"

// forward declaration
namespace Osp { namespace Base { namespace Collection { class IList; }; }; };
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Locations { class GeographicArea; }; };
namespace Osp { namespace Locations { class AddressInfo; }; };


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class DirectoryFilter;
class DirectoryServicePreferences;
class IDirectoryServiceListener;

/**
 * @interface	IDirectoryServiceProvider
 * @brief		This interface is used to access the services offered by directory service providers.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IDirectoryServiceProvider interface accesses the services that directory service providers offer. The application can
 * request geographically constrained search for any data such as places, products, services, and so on.
 *
 * A typical request consists of 'what' and 'where' information. Parameters such as name, category, keyword, phone number, or some other
 * user-friendly identifiers can provide information about 'what'. These properties of a search request can be set by using the @ref DirectoryFilter class.
 * It includes filters supported by the directory service provider. If an application tries to use filters which are not supported by the service provider,
 * an E_LOCATION_SERVICE exception is thrown. @n
 * Information about 'where' is provided by the street address, city name, postal code, or geographic coordinates.
 * There are three ways to supply the 'where' information in a search request: using a free-form string address, structured address, or a
 * geographic area. Some providers may not support all three methods. Support for each service can be queried
 * using the @ref ProviderCapabilities::GetPropertyValue() method with the corresponding property key. @n
 * - For freeform address, @ref ProviderCapabilities::DIR_SUPPORTS_FREEFORM_ADDRESS,
 * - For structured address, @ref ProviderCapabilities::DIR_SUPPORTS_ADDRESS,
 * - For geographic area, @ref ProviderCapabilities::DIR_SUPPORTS_CIRCLE_GEOGRAPHIC_AREA, @ref ProviderCapabilities::DIR_SUPPORTS_RECTANGLE_GEOGRAPHIC_AREA, or @ref ProviderCapabilities::DIR_SUPPORTS_POLYGON_GEOGRAPHIC_AREA corresponding to the type of the geographic area. @n
 *
 * If an application tries to use a service that is not supported by the service provider, E_LOCATION_SERVICE is thrown. @n
 *
 * An application can set preferences for the directory service provider by using the @ref DirectoryServicePreferences class. These
 * preferences include controlling options for the number of results and sorting.
 * The preferences are passed in as a parameter to the service requests. Directory service providers must follow these preferences.
 * If they do not, E_LOCATION_SERVICE is thrown in service requests. @n
 *
 * The following code snippet illustrates searching, using the %IDirectoryServiceProvider interface.
 * @code
 *
 *   #include <FBase.h>
 *   #include <FLocations.h>
 *
 *    using namespace Osp::Base;
 *    using namespace Osp::Base::Collection;
 *    using namespace Osp::Locations;
 *    using namespace Osp::Locations::Services;
 *
 *    // Listener
 *    class MyClass : public IDirectoryServiceListener
 *    {
 *    public:
 *        MyClass(void):__pProvider(null){};
 *        ~MyClass(void) {
 *            if (__pProvider)	delete __pProvider;
 *        }
 *
 *        void Search(void);
 *
 *         void OnDirectoryRequestResultReceivedN(RequestId requestId, const IDirectoryServiceProvider& provider, IList* pLandmarks, result r, const String& errorCode, const String& errorMsg) {
 *            if (IsFailed(r)) {
 *                AppLog("Failed to Search(ErrorCode: %S-%S)", errorCode.GetPointer(), errorMsg.GetPointer());
 *            }
 *
 *            if (pLandmarks) {
 *                IEnumerator* pEnumerator = pLandmarks->GetEnumeratorN();
 *
 *                while(!IsFailed(pEnumerator->MoveNext())) {
 *                    const Landmark* item = static_cast<const Landmark*>(pEnumerator->GetCurrent());
 *                    String name = item->GetName();
 *                    AppLog("Landmark Retrieved(%S).", name.GetPointer());
 *                }
 *
 *                delete pEnumerator;
 *                pLandmarks->RemoveAll(true);
 *                delete pLandmarks;
 *            }
 *         }
 *
 *    private:
 *        IDirectoryServiceProvider* __pProvider;
 *    };
 *
 *    void
 *    MyClass::Search(void) {
 *        result r;
 *        RequestId reqId;
 *        String defaultProvider;
 *        String extraInfo;
 *
 *        // 1. Connect to the default directory service provider
 *        IDirectoryServiceProvider* __pProvider = static_cast<IDirectoryServiceProvider*> (ProviderManager::ConnectToServiceProviderN(
 *                                                defaultProvider, LOC_SVC_PROVIDER_TYPE_DIRECTORY, extraInfo));
 *
 *        // 2. Set up a search filter
 *        DirectoryFilter* pFilter = __pProvider->GetFilterN(true);
 *        pFilter->AddFilter(DirectoryFilter::SEARCH_FILTER_KEYWORD, L"coffee");
 *
 *        // 3. Search
 *        r = __pProvider->Search(*pFilter, null, *this, reqId);
 *
 *        delete pFilter;
 *    }
 *
 * @endcode
 */
class _EXPORT_LOCATION_ IDirectoryServiceProvider 
	:	public Osp::Locations::Services::IServiceProvider
{
// Lifecycle
public:
	/**
	 * This is the destructor for this interface.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~IDirectoryServiceProvider(void);

// Operation
public:

	/** 
	* Returns the filter for the directory service provider. @n
	* 
	* The method returns a new instance of the DirectoryFilter. The parameter @c defaultValues controls 
	* whether the request contains the default values of the service provider or the values used in the last service request.
	* If there were no previous service requests and the last filter is requested (@c defaultValues is set to @c false ),
	* the default values are returned. The default filter returned by this method may not contain any filtering conditions.
	*
	* The returned DirectoryFilter instance is specific to one directory service provider. Passing in a filter
	* retrieved from another service provider causes E_LOCATION_SERVICE to be thrown.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @return			The directory filter for this service provider
	* @param[in]	defaultValues	Set to @c true to request provider's default values @n
	*								@c false to request last used filter
	* @remark			The returned DirectoryFilter instance must be deleted by the application.
	*/
	virtual DirectoryFilter*	GetFilterN(bool defaultValues=true) const = 0;

	/** 
	* Requests a search service from a directory service provider. @n
	* 
	* The filter contains parameters for the search request such as name, category, keyword, or some other
	* user-friendly identifiers supported by the service provider. The results are retrieved as a list of Landmark objects.
	* The available properties of Landmark are highly dependent on information provided by the service provider.
	* The directory service provider can decide what result is returned for an empty filter: it may be an error code (for an inadequate request),
	* or a zero result, or the whole available listing.
	*
	* The directory service provider may employ a local filter for the request. It can be the device's current location, or the 
	* default location for the service provider.
	* If an application tries to use filters that are not supported by the service provider, E_LOCATION_SERVICE is thrown.
	*
	* An application may give some preferences for the directory service provider using the 
	* @ref DirectoryServicePreferences class as a parameter. The application retrieves the preferences with the 
	* @ref IServiceProvider::GetServicePreferencesN() method. The preferences include, for example, options for the number of results and sorting.
	* If this is null, the default values of the service preferences are used. @n
	* If the application uses preferences that are not supported by the service provider,  E_LOCATION_SERVICE is thrown.
	*
	* This asynchronous method returns the request ID immediately. The results of the asynchronous requests 
	* are delivered to the application through @ref IDirectoryServiceListener::OnDirectoryRequestResultReceivedN() interface callback methods.
	* In order to receive these results, the application must implement that interface and set the listener in the asynchronous method calls.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref SearchPage "here".
	* @privlevel	NORMAL
	* @privgroup	LOCATION
	*
	* @return			An error code
	* @param[in]	filter			The filters for search
	* @param[in]	pPreferences	The preferences for the directory service request @n
	*								@c null to use provider's default preferences
	* @param[in]	listener		The event listener
	* @param[out]	requestId		The request ID with which the application may cancel the request
	* @exception	E_SUCCESS 			The method was successful.
	* @exception	E_LOCATION_SERVICE  The service provider cannot serve the request.
	* @exception	E_OUT_OF_MEMORY 	Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method, or the user blocks an application from using the location information.
	* @see				IDirectoryServiceListener::OnDirectoryRequestResultReceivedN()
	*/
	virtual result	Search(const DirectoryFilter& filter, const DirectoryServicePreferences* pPreferences, const IDirectoryServiceListener& listener, RequestId& requestId) = 0;

    /**
    * @page SearchPage Compatibility for Search()
    * 
    * @section SearchPageIssueSection Issues
    * Implementation of this method in API versions prior to 2.0 has the following issues: @n
    * -# The privilege group in bada API versions prior to 2.0 is mentioned below: @n
    *       @b Privilege @b group: @b LOCATION_SERVICE @n@n
    * -# if the privilege for using the location information is blocked by user consent, the E_LOCATION_SERVICE exception is thrown.
    *
    * @section SearchPageResolutionsSection Resolutions 
    * The issues mentioned above are resolved in API version 2.0 as follows: @n
    * -# The privilege group in bada API version 2.0 or above is mentioned below: @n
    *       @b Privilege @b group: @b LOCATION @n@n
    * -# if the privilege for using the location information is blocked by user consent, the E_PRIVILEGE_DENIED exception is thrown.
    */

	/** 
	* Requests a search service with address filter from a directory service provider. @n
	* 
	* The filter contains parameters for the search request such as name, category, keyword, or some other
	* user-friendly identifiers supported by the service provider. The matched results are retrieved as a list of Landmark objects.
	* The available properties of Landmark are highly dependent on what information the service provider 
	* provides. What result is returned for an empty filter is left to the directory service provider: it may be an error code for an inadequate request,
	* or a zero result, or the whole available listing.

	* A local filter is employed on this method using a freeform address. Support for a freeform address as a local filter
	* can be queried from the @ref ProviderCapabilities class with the key value @ref ProviderCapabilities::DIR_SUPPORTS_FREEFORM_ADDRESS.
	* If the application tries to use a filter that is not supported by the service provider, E_LOCATION_SERVICE is thrown.
	* 
	* An application may give some preferences for the directory service provider. These are done through a
	* @ref DirectoryServicePreferences instance passed as a parameter to the request. The application retrieves the preferences with the
	* @ref IServiceProvider::GetServicePreferencesN() method. The preferences include, for example, options for the number of results and sorting.
	* If null is passed, the default values of the service preferences are used. @n
	* If the application tries to use preferences that is not supported by the service provider, an E_LOCATION_SERVICE exception is thrown.
	*
	* This asynchronous method returns the request ID immediately. The results of the asynchronous service requests 
	* are delivered to the application through the @ref IDirectoryServiceListener::OnDirectoryRequestResultReceivedN() interface callback methods.
	* In order to receive these results, the application must implement that interface and set the listener in the asynchronous method calls.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @privlevel	NORMAL
	* @privgroup	LOCATION_SERVICE
	*
	* @return			An error code
	* @param[in]	filter			The filters for search
	* @param[in]	freeFormAddress	The address string used as as a local filter
	* @param[in]	pPreferences	The preferences for the directory service request @n
	*								@c null to use provider's default preferences
	* @param[in]	listener		The event listener
	* @param[out]	requestId		The request ID with which the application may cancel the request
	* @exception	E_SUCCESS 			The method was successful.
	* @exception	E_INVALID_ARG 		The specified @c freeFormAddress is an empty String.
	* @exception	E_LOCATION_SERVICE  The service provider cannot serve the request.
	* @exception	E_OUT_OF_MEMORY 	Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @see				IDirectoryServiceListener::OnDirectoryRequestResultReceivedN()
	*/
	virtual result	Search(const DirectoryFilter& filter, const Osp::Base::String& freeFormAddress, const DirectoryServicePreferences* pPreferences, const IDirectoryServiceListener& listener, RequestId& requestId) = 0;

	/** 
	* Requests a search service with an address filter from a directory service provider. @n
	* 
	* The filter contains parameters for the search request such as name, type, category, keyword, or some other
	* user-friendly identifiers supported by the service provider. The matched results are retrieved as a list of Landmark objects
	* that is filled by the directory service provider. The available properties of Landmark are highly dependent on information 
	* provided by the service provider. The directory service provider can decide which result is returned for an empty filter: 
	* it may be an error code (for an inadequate request), or a zero result, or the whole available listing.
	*
	* A local filter is employed on this method in the form of structured address. Support for a structured address as a local filter
	* can be queried from the @ref ProviderCapabilities class using the key value @ref ProviderCapabilities::DIR_SUPPORTS_ADDRESS.
	* If application tries to use filters that are not supported by the service provider, E_LOCATION_SERVICE is thrown.
	* 
	* An application may give some preferences for the directory service provider. These are done through the 
	* @ref DirectoryServicePreferences class and passed in as a parameter to the request. The application retrieves the preferences with the 
	* @ref IServiceProvider::GetServicePreferencesN() method. These preferences include, for example, options for the number of results and sorting.
	* If null is passed, the default values of the service preferences are used. @n
	* If application tries to use preferences that are not supported by the service provider, E_LOCATION_SERVICE is thrown.
	*
	* This asynchronous method returns the request ID immediately. The results of the asynchronous service requests 
	* are delivered to the application through the @ref IDirectoryServiceListener::OnDirectoryRequestResultReceivedN() interface callback methods.
	* In order to receive this results, the application must implement that interface and set the listener in the asynchronous method calls.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @privlevel	NORMAL
	* @privgroup	LOCATION_SERVICE
	*
	* @return			An error code
	* @param[in]	filter			The filters for search
	* @param[in]	address			The address as a local filter
	* @param[in]	pPreferences	The preferences for the directory service request @n
	*								@c null to use provider's default preferences
	* @param[in]	listener		The event listener
	* @param[out]	requestId		The request ID with that the application may cancel the request
	* @exception	E_SUCCESS			The method was successful.
	* @exception	E_INVALID_ARG 		The specified @c address does not have any field set.
	* @exception	E_LOCATION_SERVICE  The service provider cannot serve the request.
	* @exception	E_OUT_OF_MEMORY 	Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @see				IDirectoryServiceListener::OnDirectoryRequestResultReceivedN()
	*/
	virtual result	Search(const DirectoryFilter& filter, const AddressInfo& address, const DirectoryServicePreferences* pPreferences, const IDirectoryServiceListener& listener, RequestId& requestId) = 0;

	/** 
	* Requests a search service with an area filter from a directory service provider. @n
	* 
	* The filter contains parameters for the search request such as name, type, category, keyword, or some other
	* user-friendly identifiers supported by the service provider. The matched results are retrieved as a list of Landmark objects
	* that is filled by the directory service provider. The available properties of Landmark depend on what information the service provider 
	* provides. What result is returned for an empty filter is left to the directory service provider. It may be an error code for the inadequate request,
	* or a zero result, or a whole available listing.
	*
	* A local filter is employed on this method by the form of a geographical area. There are 3 types of geographic area defined in the package: 
	* circle, rectangle, and polygon. Support for each geographical area as a local filter can be queried from the @ref ProviderCapabilities class 
	* with the key value @ref ProviderCapabilities::DIR_SUPPORTS_CIRCLE_GEOGRAPHIC_AREA, @ref ProviderCapabilities::DIR_SUPPORTS_RECTANGLE_GEOGRAPHIC_AREA, 
	* and @ref ProviderCapabilities::DIR_SUPPORTS_POLYGON_GEOGRAPHIC_AREA, respectively.
	* If the application tries to use filters that are not supported by the service provider, E_LOCATION_SERVICE is thrown.
	* 
	* An application may give some preferences for the directory service provider. These are done through the 
	* @ref DirectoryServicePreferences class and passed in as a parameter to the request. The application retrieves the preferences with the 
	* IServiceProvider::GetServicePreferencesN() method. The preferences include options for the number of results and sorting.
	* If null is passed, the default values of the service preferences are used. @n
	* If application tries to use preferences that are not supported by the service provider, E_LOCATION_SERVICE is thrown.
	*
	* This asynchronous method returns the request ID immediately. The results of the asynchronous service requests 
	* are delivered to the application through the IDirectoryServiceListener::OnDirectoryRequestResultReceivedN() interface callback methods.
	* In order to receive these results, the application must implement the interface and set the listener in the asynchronous method calls.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @privlevel	NORMAL
	* @privgroup	LOCATION_SERVICE
	*
	* @return			An error code
	* @param[in]	filter			The filters for search
	* @param[in]	area			The area as a local filter
	* @param[in]	pPreferences	The preferences for the directory service request @n
	*								@c null to use provider's default preferences
	* @param[in]	listener		The event listener
	* @param[out]	requestId		The request ID with which the application may cancel the request
	* @exception	E_SUCCESS 			The method was successful.
	* @exception	E_LOCATION_SERVICE  The service provider cannot serve the request.
	* @exception	E_OUT_OF_MEMORY 	Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @see				IDirectoryServiceListener::OnDirectoryRequestResultReceivedN()
	*/
	virtual result	Search(const DirectoryFilter& filter, const GeographicArea& area, const DirectoryServicePreferences* pPreferences, const IDirectoryServiceListener& listener, RequestId& requestId) = 0;

	/**
	* Requests the directory service provider to cancel the specified request. @n
	* 	
	* The specified pending service request is aborted on a best effort basis.
	*
	* In asynchronous service requests the application is notified from the cancel request through the 
	* @ref IDirectoryServiceListener::OnDirectoryRequestResultReceivedN() callback method with the E_OPERATION_CANCELED result. @n
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @return			An error code
	* @param[in]	requestId	The ID of the request to be canceled
	* @exception	E_SUCCESS	The method was successful.
	* @exception	E_INVALID_ARG	The specified @c requestId does not exist in the list of pending requests.
	* @exception	E_OPERATION_FAILED	A system error occurred.
	*/	
	virtual result CancelRequest(RequestId requestId) = 0;
};	// class IDirectoryServiceProvider

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IDIRECTORY_SERVICE_PROVIDER_H_
