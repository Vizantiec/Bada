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
 * @file	FLocGeocodingServicePreferences.h
 * @brief	This is the header file for the %GeocodingServicePreferences class.
 *
 * This header file contains the declarations of the %GeocodingServicePreferences class.
 *
 */

#ifndef _FLOC_GEOCODING_SERVICE_PREFERENCES_H_
#define _FLOC_GEOCODING_SERVICE_PREFERENCES_H_

#include "FLocationConfig.h"
#include "FLocServicePreferences.h"
#include "FLclLocale.h"

// Forward declaration
struct MGeocodingServicePreferences;

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class ProviderCapabilities;

/**
 * @class 	GeocodingServicePreferences
 * @brief 	This class encapsulates the preferences related to a geocoding service provider.
 * @deprecated	This class is deprecated.
 * @since 	1.0
 *
 * 	The %GeocodingServicePreferences class captures the preferences related to a geocoding service provider. These preferences include controlling the number of matches and exact matches.
 * 
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/geocoding_service.htm">Geocoding Service</a>.
 */
class _EXPORT_LOCATION_ GeocodingServicePreferences 
	: public Osp::Locations::Services::ServicePreferences
{
// Lifecycle
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	GeocodingServicePreferences(void);

private:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	GeocodingServicePreferences(const GeocodingServicePreferences& value);		// copy constructor
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	GeocodingServicePreferences& operator=(const GeocodingServicePreferences& rhs);	// assignment operator
	
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	virtual ~GeocodingServicePreferences(void);

// Operation
public:
	/**
	 * Compares the calling instance with the specified instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the objects are equal, @n
	 *				else @c false
	 * @param[in]	obj		The Object with which the comparison is done
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Get the maximum count of matches set for the geocoding service provider. @n
	 * The method returns the default value set by the service provider or the value set with @ref SetMaxMatchesCount.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The maximum number of matches
	 */
	int GetMaxMatchesCount(void) const;

	/**
	 * Checks whether the geocoding service provider searches for results that exactly match all the given information in the service requests. @n
	 * If the information in the service request is incomplete, the service provider may not find the results that match all the fields; but can find several 
	 * near matches. If @c exactMatch is set to @c true, then all the fields in the given address information or the given @c freeFormAddress parameters in 
	 * the geocode methods must match exactly with the results. If @c exactMatch is set to @c false, the parameters may be substrings of the results. The 
	 * method returns the default value set by the service provider or the value set with @ref SetExactMatch.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the exact match must be found, @n
	 *				else @c false
	 */
	bool IsExactMatch(void) const;

	/**
	 * Gets the current country code used by the geocoder.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The ISO 3166-1 alpha-2 country code 
	 */
	Osp::Locales::CountryCode GetBaseCountryCode(void) const;

	/**
	 * Sets whether the geocoding service provider must find exact matches to the service requests or not. @n
	 * If @c exactMatch is set to @c true, then all the fields in the given address information or the given @c freeFormAddress parameters in 
	 * the geocode methods must match exactly with the results. If @c exactMatch is set to @c false, the fields in the parameters can be substrings of the 
	 * results. The special characters '*' and '?' do not have any special meaning. If the preference is set to find exact matches and no results are 
	 * returned, the service requests return an empty array.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	exactMatch	Set to @c true if the service provider must find an exact match for the request, @n
	 *							else @c false
	 */
	void SetExactMatch(bool exactMatch);

	/**
	 * %Controls the maximum number of results returned from the service provider for a service request. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	maxNumberOfMatches		The maximum number of results to be received for each query 
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c maxNumberOfMatches is invalid, or @n
	 *										the value of @c maxNumberOfMatches is less than or equal to @c 0.
	 */
	result SetMaxMatchesCount(int maxNumberOfMatches);

	/**
	 * Sets the country code in use by the specified geocoder. @n
	 * The possible country code values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::GEO_SUPPORTED_COUNTRIES property key. Passing a @c null or an empty string as @c pCountryCode sets the country to the 
	 * default country of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	pCountryCode	The ISO 3166-1 alpha-2 country code, @n
	 *								else @c null as default
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified @c pCountryCode is not supported.
	 * @remarks 	The ProviderCapabilities::GetPropertyValue() method using the @ref ProviderCapabilities::GEO_SUPPORTED_COUNTRIES property
	 * 				key may return an empty list. It means that the supported countries are not determined.
	 * 				All country codes defined in ISO-3166 are acceptable to the service preferences.
	 * 				The response of the requested service returns an error if the provider does not support the given country.
	 */
	result SetBaseCountryCode(Osp::Locales::CountryCode* pCountryCode);

protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * MGeocodingServicePreferences instance
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	MGeocodingServicePreferences* __pPreferences;

private:
	friend class GeocodingServicePreferencesEx;
	class GeocodingServicePreferencesEx* __pGeocodingServicePreferencesEx;

};	// class ServicePreferences

}; }; };	// Osp::Locations::Services

#endif // _FLOC_SERVICE_PREFERENCES_H_
