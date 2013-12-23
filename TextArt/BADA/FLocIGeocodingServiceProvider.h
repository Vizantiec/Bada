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
 * @file	FLocIGeocodingServiceProvider.h
 * @brief	This is the header file for the %IGeocodingServiceProvider interface.
 *
 * This header file contains the declarations of the %IGeocodingServiceProvider interface.
 *
 */

#ifndef _FLOC_IGEOCODING_SERVICE_PROVIDER_H_
#define _FLOC_IGEOCODING_SERVICE_PROVIDER_H_

#include "FLocationConfig.h"
#include "FLocIServiceProvider.h"
#include "FBaseTypes.h"

// Forward declaration
namespace Osp { namespace Locations { class AddressInfo; }; };
namespace Osp { namespace Locations { class GeographicArea; }; };
namespace Osp { namespace Locations { class Coordinates; }; };

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class GeocodingServicePreferences;
class IGeocodingServiceListener;

/**
 * @interface	IGeocodingServiceProvider
 * @brief		This interface collects the services that the geocoding service providers offer.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IGeocodingServiceProvider interface helps applications to request geocoding and reverse geocoding related services from the service provider.
 *
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geocoding_service.htm">Geocoding Service</a>.
 *
 * The following example demonstrates how to use the %IGeocodingServiceProvider interface in geocoding.
 *
 *
 *  The following code snippet illustrates geocoding using the IGeocodingServiceProvider interface.
 *
 * @code
 *
 * /////////////////////////////////////
 * //Geocoding.cpp
 *
#include <FBase.h>
#include <FLocations.h>

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Locations;
using namespace Osp::Locations::Services;

// Listener
class GeocodingServiceListenerImpl :
    public IGeocodingServiceListener
{
public:
    GeocodingServiceListenerImpl() {};

    virtual void OnGeocodingRequestResultReceivedN(RequestId requestId, 
        const IGeocodingServiceProvider& provider, IList* pLandmarks, 
        result r, const String& errorCode, const String& errorMsg);
    virtual void OnReverseGeocodingRequestResultReceivedN(RequestId requestId,
        const IGeocodingServiceProvider& provider, IList* pLandmarks, result r,
        const String& errorCode, const String& errorMsg);
};

void
GeocodingServiceListenerImpl::OnGeocodingRequestResultReceivedN
    (RequestId requestId, const IGeocodingServiceProvider& provider, 
     IList* pLandmarks, result r, const String& errorCode, 
     const String& errorMsg)
{
    // 3. Gets the response
    if (E_SUCCESS == r && pLandmarks)
    {
		Landmark* pLandmark = dynamic_cast<Landmark*>(pLandmarks->GetAt(0));
		if (pLandmark)
		{
			const QualifiedCoordinates* pCoord = pLandmark->GetQualifiedCoordinates();
		}

		pLandmarks->RemoveAll(true);
		delete pLandmarks;
    }
}

class GeocodingTest
{
public:
	void Geocode(void);
};

void
GeocodingTest::Geocode(void)
{
    result r;
    String defaultProvider;
    String extraInfo;
    GeocodingServiceListenerImpl* pListener = null;

    // 1. Connects to the default geocoding service provider
    IGeocodingServiceProvider* pProvider = static_cast<IGeocodingServiceProvider*>
        (ProviderManager::ConnectToServiceProviderN(defaultProvider,
         LOC_SVC_PROVIDER_TYPE_GEOCODING, extraInfo));
    if (null == pProvider) goto CATCH;

    pListener = new GeocodingServiceListenerImpl();
    if (null == pListener) goto CATCH;

    RequestId reqId;

    // 2. Geocodes the given address
    r = pProvider->Geocode(String((L"4 N 2ND ST, San Jose CA 95113")),
        null, null, *pListener, reqId);
    if (IsFailed(r)) goto CATCH;

    return;

CATCH:
    delete pListener;
    delete pProvider;
}


 * @endcode
 * 
 *  The following example demonstrates how to use the %IGeocodingServiceProvider interface in reverse geocoding.
 *
 * @code

#include <FBase.h>
#include <FLocations.h>

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Locations;
using namespace Osp::Locations::Services;

// Listener
class GeocodingServiceListenerImpl :
    public IGeocodingServiceListener
{
public:
    GeocodingServiceListenerImpl() {};
    virtual void OnGeocodingRequestResultReceivedN(RequestId requestId, 
        const IGeocodingServiceProvider& provider, IList* pLandmarks, 
        result r, const String& errorCode, const String& errorMsg);
    virtual void OnReverseGeocodingRequestResultReceivedN(RequestId requestId,
        const IGeocodingServiceProvider& provider, IList* pLandmarks, result r,
        const String& errorCode, const String& errorMsg);
};

void
GeocodingServiceListenerImpl::OnReverseGeocodingRequestResultReceivedN(RequestId requestId, const IGeocodingServiceProvider& provider, IList* pLandmarks, result r, const String& errorCode, const String& errorMsg)
{
	// 3. Gets the response
	if (E_SUCCESS == r && pLandmarks)
	{
		Landmark* pLandmark = dynamic_cast<Landmark*>(pLandmarks->GetAt(0));
		if (pLandmark)
		{
			const AddressInfo* pAddress = pLandmark->GetAddressInfo();
		}

		pLandmarks->RemoveAll(true);
		delete pLandmarks;
	}
}

class ReverseGeocodingTest
{
public:
	void ReverseGeocode(void);
};

void
ReverseGeocodingTest::ReverseGeocode(void)
{
    result r;
    String defaultProvider;
    String extraInfo;
	Coordinates coord;
    GeocodingServiceListenerImpl* pListener = null;

    // 1. Connects to the default geocoding service provider
    IGeocodingServiceProvider* pProvider = static_cast<IGeocodingServiceProvider*>
        (ProviderManager::ConnectToServiceProviderN(defaultProvider,
         LOC_SVC_PROVIDER_TYPE_GEOCODING, extraInfo));
    if (null == pProvider) goto CATCH;

    pListener = new GeocodingServiceListenerImpl();
    if (null == pListener) goto CATCH;

    r = coord.Set(37.336826, -121.889631, 0);
     if (IsFailed(r)) goto CATCH;

    RequestId reqId;
    // 2. Reverse geocodes the given coordinates
    r = pProvider->ReverseGeocode(coord, null, *pListener, reqId);
    if (IsFailed(r)) goto CATCH;

    return;

CATCH:
    delete pListener;
    delete pProvider;
}

 * @endcode
 */
class _EXPORT_LOCATION_ IGeocodingServiceProvider 
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
	virtual ~IGeocodingServiceProvider(void);

// Operation
public:
	/** 
	 * Requests a geocoding service from the service provider. @n 
	 *
	 * Geocoding converts a street address into coordinates. This asynchronous method returns the request ID immediately. The application may cancel the 
	 * request using this ID. The results of the asynchronous service requests are delivered to the application through the 
	 * IGeocodingServiceListener::OnGeocodingRequestResultReceivedN() interface callback method. In order to receive these results, the application must 
	 * implement that interface and set the listener in the asynchronous method calls. @n
	 *
	 * Since geocoding converts a street address into coordinates, it is easier for a geocoding service provider to find the matching coordinates if the 
	 * address information is complete. The AddressInfo provided as an input parameter should contain at least a street address. The returned Landmark 
	 * instances contain both coordinates and address information. The service provider must treat the provided address information in a case-insensitive 
	 * manner.
	 *
	 * The application may cancel the asynchronous service request using the @ref IGeocodingServiceProvider::CancelRequest() method. This causes the method
	 * to call the IGeocodingServiceListener::OnGeocodingRequestResultReceivedN() callback method with E_OPERATION_CANCELED. @n
	 *
	 * The geocoding service provider must return the best match for the given address information as the first element in the returned array. If the provided 
	 * address information is incomplete, the geocoding service provider may find several coordinates for it. This can happen, for example, when several cities have 
	 * the same street name and the given AddressInfo does not contain city information. It is left to the service provider to decide the order in which the 
	 * results should be ranked. The results must match all the given AddressInfo fields; however, the matches may be substrings. If the service provider 
	 * cannot find any matches, an empty array is returned. @n
	 *
	 * An application may give some preferences for the geocoding service provider. These are done through the GeocodingServicePreferences class and passed 
	 * as a parameter in the request. The application retrieves the preferences with the @ref IServiceProvider::GetServicePreferencesN method. The 
	 * preferences include, for example, the number of matches and whether an exact match is required. If @c null is passed as the preference, the default 
	 * values of the service preferences are used. @n	 
	 *
	 * With the @c pLocationHint parameter, the applications can provide a hint to the geocoding service provider where the best match for the service 
	 * request is. Providing this hint area is optional, and a @c null value indicates that no hint is provided.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	address				The address to be converted into coordinates
	 * @param[in]	pLocationHint		A hint for the service provider to indicate where the best match is, @n
	 *									else @c null if no hint is provided
	 * @param[in]	pPreferences		The preferences for the geocoding service request, @n
	 *									else @c null to use the default preferences of the provider
	 * @param[in]	listener			The event listener
	 * @param[out]	requestId			The ID of the request
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	 *									- The specified @c address does not have any field set. @n
	 *									- The specified @c pPreferences is not supported by this service provider. @n
	 *									- The service provider has used different preferences to retrieve this object.
	 * @exception	E_LOCATION_SERVICE 	The service provider cannot serve the request.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception   E_SYSTEM  			A system error has occurred.  
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @see			@ref ReverseGeocode(), @ref CancelRequest()
	 */
	virtual result Geocode(const AddressInfo& address,
		const GeographicArea* pLocationHint, 
		const GeocodingServicePreferences* pPreferences, 
		const IGeocodingServiceListener& listener, RequestId& requestId) = 0;

	/**
	 * Requests a geocoding service from the geocoding service provider. @n 
	 * The service provider returns all the places that have a field set that matches the given @c freeFormAddress search. The match may be in fields other 
	 * than address information fields. The service provider must treat the provided @c freeFormAddress in a case-insensitive manner. @n
	 *
	 * This asynchronous method returns the request ID immediately. The application may cancel the request using this ID. The results of the asynchronous 
	 * service requests are delivered to the application through the @ref IGeocodingServiceListener::OnGeocodingRequestResultReceivedN() callback methods.
	 * In order to receive these results, the application must implement that interface and set the listener in the asynchronous method calls. @n
	 *
	 * The application may cancel the asynchronous service request with the @ref IGeocodingServiceProvider::CancelRequest() method. This causes the method
	 * to call the @ref IGeocodingServiceListener::OnGeocodingRequestResultReceivedN() callback method with E_OPERATION_CANCELED. @n
	 *
	 * An application may provide some preferences for the geocoding service provider. These are done through the @ref GeocodingServicePreferences class and 
	 * passed as a parameter to the request. The application retrieves the preferences with the @ref IServiceProvider::GetServicePreferencesN() method.
	 * The preferences include, for example, the number of matches and whether a match is required. If @c null is passed as @c pPreferences, the default 
	 * values of the service preferences are used. @n
	 *
	 * The preferences also contain the base country code for the service request. This country code restricts the search area. The @c freeFormAddress may 
	 * have the country name or country code, but it may be ignored.
	 *
	 * With the @c pLocationHint parameter, the applications can provide a hint for the geocoding service provider where the best match
	 * for the service request is. Providing this hint area is optional and a @c null value indicates that no hint is given.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	freeFormAddress			The text that is searched from the fields of the places
	 * @param[in]	pLocationHint			A hint for the service provider to indicate where the best match is, @n
	 *										else @c null if no hint is provided
	 * @param[in]	pPreferences			The preferences for the geocoding service request, @n
	 *										else @c null to use the default preferences of the provider
	 * @param[in]	listener				The event listener
	 * @param[out]	requestId				The ID with which the application may cancel the request
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_INVALID_ARG 			The specified @c freeFormAddress is an empty string,
	 *										or the specified @c pPreferences is not supported by this service provider.
	 * @exception	E_LOCATION_SERVICE		The service provider cannot serve the request.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception   E_SYSTEM				A system error has occurred.  
	 * @exception   E_PRIVILEGE_DENIED  	The application does not have the privilege to call this method.
	 * @see	@ref ReverseGeocode(), @ref CancelRequest()
	 */
	virtual result Geocode(const Osp::Base::String& freeFormAddress,
		const GeographicArea* pLocationHint,
		const GeocodingServicePreferences* pPreferences,
		const IGeocodingServiceListener& listener, RequestId& requestId) = 0;

	/** 
	 * Requests a reverse geocoding service from the geocoding service provider. @n
	 * 
	 * This asynchronous method returns the request ID immediately. The application may cancel the request using this ID. The results of the asynchronous 
	 * service requests are delivered to the application through the @ref IGeocodingServiceListener::OnReverseGeocodingRequestResultReceivedN() callback 
	 * methods. In order to receive these results, the application must implement that interface and set the listener in the asynchronous method calls.
	 *
	 * The application may cancel the asynchronous service request with the @ref IGeocodingServiceProvider::CancelRequest() method. This causes the method
	 * to call @ref IGeocodingServiceListener::OnReverseGeocodingRequestResultReceivedN() callback method with E_OPERATION_CANCELED @n
	 *
	 * In some cases the provided coordinates can be mapped to several street addresses. This situation can happen, for example, if the coordinates are in a 
	 * street crossing and can be mapped into either of the crossing streets. The service provider must return the best match as the first element in the 
	 * result array. The ranking of the results is left to the service provider. If no matches are found for the given coordinates, an empty array is
	 * returned and the altitude information is ignored. @n
	 *
	 * An application may give some preferences for the geocoding service provider. These are done through the GeocodingServicePreferences class and passed 
	 * as a parameter to the request. The application retrieves the preferences with the @ref IServiceProvider::GetServicePreferencesN() method. The 
	 * preferences include, for example, the number of matches and whether an exact match is required. If @c null is passed in as a preference, the default 
	 * values of the service preferences are used. @n
	 * 
	 * The country code of the preferences is ignored.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @privlevel	NORMAL
	 * @privgroup	LOCATION_SERVICE
	 *
	 * @return		An error code
	 * @param[in]	coordinates			The coordinates to be converted to a street address
	 *									else @c null to use the default preferences of the provider
	 * @param[in]	pPreferences		The preferences for the geocoding service request
	 * @param[in]	listener	    	The event listener
	 * @param[out]	requestId	    	The ID with which the application may cancel the request
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c pPreferences are not suitable for this service provider, or @n
	 *									the service provider used different preferences to retrieve this object.
	 * @exception	E_LOCATION_SERVICE 	The service provider cannot serve the request.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception   E_SYSTEM  			A system error has occurred.  
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see			@ref Geocode(), @ref CancelRequest()
	 */
	virtual result ReverseGeocode(const Coordinates& coordinates,
		const GeocodingServicePreferences* pPreferences,
		const IGeocodingServiceListener& listener, RequestId& requestId) = 0;

	/**
	 * Requests the geocoding service provider to cancel the request. @n
	 * 
	 * The specified pending service request is aborted on a best-efforts basis. This method may be used with both geocode and reverse-geocode requests. @n
	 *
	 * In the asynchronous service requests, the application is notified of the cancel request through the 
	 * @ref IGeocodingServiceListener::OnGeocodingRequestResultReceivedN() or 
	 * @ref IGeocodingServiceListener::OnReverseGeocodingRequestResultReceivedN() callback method. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	requestId			The ID of the request to be canceled
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_INVALID_ARG 		The specified @c requestId does not exist in the list of pending requests.
	 * @exception	E_OPERATION_FAILED 	A system error has occurred.
	 */	
	virtual result CancelRequest(RequestId requestId) = 0;

};	// class IGeocodingServiceProvider

}; }; };	// Osp::Locations::Services

#endif // _FLOC_IGEOCODING_SERVICE_PROVIDER_H_
