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
 * @file		FLocServicePreferences.h
 * @brief		This is the header file for the ServicePreferences class.
 *
 * This header file contains the declarations of the ServicePreferences class.
 *
 */

#ifndef _FLOC_SERVICE_PREFERENCES_H_
#define _FLOC_SERVICE_PREFERENCES_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FLclLocale.h"

// forward declaration
struct LocationServicePreferences;
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection {class IList; }; }; };
namespace Osp { namespace Base { namespace Collection {class HashMap; }; }; };

namespace Osp { namespace Locations { namespace Services {

/**
 * @class	ServicePreferences
 * @brief	This class contains the mechanism to control the service provider preferences.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * 	The %ServicePreferences class is a base class for service preferences. The child classes have dedicated methods for controlling the service-specific preferences. 	
 *			This class provides a mechanism to control additional service provider-specific preferences. The service providers must define a default language 
 *			and a length unit.
 *
 */
class _EXPORT_LOCATION_ ServicePreferences 
	:	public Osp::Base::Object
{
// Lifecycle
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
	ServicePreferences(const ServicePreferences& prefs);
	
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	ServicePreferences(void);
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~ServicePreferences(void) = 0;

// Operation
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
	ServicePreferences& operator=(const ServicePreferences& prefs);
	
public:
	/**
	 * Gets the list of the property keys, for the additional preferences, that have been defined for a service provider. @n
	 * The actual property value can be retrieved with the @ref GetPropertyValue() method and set with the @ref SetPropertyValue() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	A list of @c string objects that indicate key values of properties for additional service preferences, @n
	 *			else @c null if no properties have been defined
	 */
	const Osp::Base::Collection::IList*	GetAdditionalPropertyKeys(void) const;

	/**
	 * Gets the language to be used in the service requests. @n
	 * The possible language tag values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::SUPPORTED_LANGUAGES property key. The method returns the default value set by the service provider, or the value set with 
	 * the @ref SetLanguage() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The preferred language, @n
	 *			else the default language of the service provider if no preference for language has been set
	 */
	Osp::Locales::LanguageCode GetLanguage(void) const;

	/**
	 * Gets the preferred length unit to be used in the service provider UIs. The possible length units can be retrieved with the 
	 * @ref ProviderCapabilities::GetPropertyValue() method using the @ref ProviderCapabilities::SUPPORTED_LENGTH_UNITS property
	 * key. The method returns the default value set by the service provider, or the value set with the @ref SetLengthUnit method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 * @return	The preferred length unit, @n
	 * 			else the default length unit of the service provider if no preference for length unit has been set
	 */
	Osp::Base::String GetLengthUnit(void) const;


	/**
	 * Gets the value of the requested additional property as a string. @n
	 * The application must convert the returned value into the right object type defined in the property key description.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return	   	The value of the property, @n
	 *			    else @c null if the key is not defined
	 * @param[in]		key	 The identifier of the property
	 */
	const Osp::Base::String* GetPropertyValue(const Osp::Base::String& key) const;


	/**
	 * Sets the language to be used in service requests. @n
	 * The possible language tag values can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::SUPPORTED_LANGUAGES property key. Passing @c null or an empty string as the languageCode sets the language to the default 
	 * language of the service provider. @n
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0	 
	 * @remarks	ProviderCapabilities::GetPropertyValue() method using @ref ProviderCapabilities::SUPPORTED_LANGUAGES property 
	 * 			key value may return an empty list. It means that the supported languages are not determined. @n
	 * 			All language tags defined in ISO 639-2 are acceptable to the service preferences. @n
	 * 			But the response of the requested service returns an error if the provider does not support the given language. @n
	 * 			If this value is an empty list, the default language tag of the service preferences is set to the language of the current locale.
	 * @return		An error code
	 * @param[in]	pLanguageCode	The language to be used in service requests
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified @c pLanguageCode is not one of the values retrieved with the ProviderCapabilities::GetPropertyValue() method.
	 */
	result SetLanguage(Osp::Locales::LanguageCode* pLanguageCode);


	/**
	 * Sets the length unit to be used in the service provider UIs. The possible length unit values can be retrieved with the 
	 * @ref ProviderCapabilities::GetPropertyValue() method key values @ref ProviderCapabilities::SUPPORTED_LENGTH_UNITS. Passing @c null, or an empty
	 * string as the lengthUnit sets the length unit to the default length unit of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	pLengthUnit		The length unit to be used in service provider UIs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified @c pLengthUnit is not one of the values retrieved with the ProviderCapabilities::GetPropertyValue() method.
	 */
	result SetLengthUnit(const Osp::Base::String* pLengthUnit);


	/**
	 * Sets the property value for the specified key. @n
	 * The additional key values can be retrieved with the @ref GetAdditionalPropertyKeys() method. Passing @c null as the property value resets the property 
	 * to the default value.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	key				The key identifier of the property
	 * @param[in]	pValue			The value of the property, @n
	 *								else @c null to reset the property
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_INVALID_ARG 	The specified @c key is not one of the keys retrieved with the GetAdditionalPropertyKeys() method.
	 */
	result SetPropertyValue(const Osp::Base::String& key, const Osp::Base::String* pValue);

// internal operation
public:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Add additional property value. @n
	 * This method may be used by implementation of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	key	           The key identifier of the property
	 * @param[in]	value	       The value of the property
	 * @param[in]	defaultValue   The default value of the property
	 * @exception	E_SUCCESS      The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified key already exists.
	 */
	result AddPropertyValue(const Osp::Base::String& key, const Osp::Base::String& value, const Osp::Base::String& defaultValue);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the name of service provider. This method may be used by implementation of the service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		The service provider name
	 */
	Osp::Base::String GetServiceProviderName(void) const;

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
	virtual const LocationServicePreferences* GetMServicePreferences(void) const = 0;	
	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual LocationServicePreferences* GetMServicePreferences(void) = 0;

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Synchronize __pAdditionalProperties from the properties of the MServicePreferences
	 * 
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_OUT_OF_MEMORY	Insufficient memory.
	 */
	result SynchronizeData(void);

protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Additional properties
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::HashMap* __pAdditionalProperties;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Additional keys. This is a list of the reference pointers of the key string.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::IList* __pAdditionalKeys;

private:
	friend class ServicePreferencesEx;
	class ServicePreferencesEx* __pServicePreferencesEx;

};	// class ServicePreferences

}; }; };	// Osp::Locations::Services

#endif // _FLOC_SERVICE_PREFERENCES_H_
