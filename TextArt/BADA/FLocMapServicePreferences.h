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
 * @file	FLocMapServicePreferences.h
 * @brief	This is the header file for the %MapServicePreferences interface.
 *
 * This is the header file for the %MapServicePreferences class.
 *
 */

#ifndef _FLOC_MAP_SERVICE_PREFERENCES_H_
#define _FLOC_MAP_SERVICE_PREFERENCES_H_

#include "FLocationConfig.h"
#include "FLocServicePreferences.h"

// Forward declaration
struct MMapServicePreferences;
namespace Osp { namespace Base { namespace Collection {class ArrayList; }; }; };

namespace Osp { namespace Locations { namespace Services {

// Forward declaration
class ProviderCapabilities;

/**
 * @class		MapServicePreferences
 * @brief		This class captures the preferences related to the map service providers.
 * @deprecated	This class is deprecated.
 * @since		1.0
 *
 * 	The %MapServicePreferences class captures the preferences related to the map service providers. The preferences offered to the user are:
 * 				@li Map type
 * 				@li Information about the map layers
 * 				@li Background transparency @n
 *
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/map_service.htm">Map Service</a>.
 */
class _EXPORT_LOCATION_ MapServicePreferences 
	:	public Osp::Locations::Services::ServicePreferences
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
	 * @since	1.0
	 */
	MapServicePreferences(void);
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
	MapServicePreferences(const MapServicePreferences& value);	// copy constructor
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	MapServicePreferences& operator=(const MapServicePreferences& rhs);	// assignment operator

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~MapServicePreferences(void);



// Operation
public:
	/**
	 * Overrides the Equals() method in the Object class to compare the equality of values.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		@c true if the objects are equal, @n
	 *				else @c false
	 * @param[in]	obj		The Object with which the comparison is done
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the names of the layers that must be included in the map on top of the map base. @n
	 * These layers can be streets, highways, public transportation lines, water areas, parks, buildings, sidewalks or administrative areas. The names of the 
	 * map layers supported by the map service provider can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::MAP_SUPPORTED_LAYERS property key. The method returns the default layer names set by the service provider or the values in 
	 * the same order as is set with the SetLayers() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		A list of map layer names that should be included in a displayed map, @n
	 *				else an empty list if the preference has not been set (@ref Osp::Base::String list)
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 */
	const Osp::Base::Collection::IList*	GetLayers(void) const;


	/**
	 * Sets the map layers that must be included in the service requests of the map service provider. These layers can be streets, highways, public 
	 * transportation lines, water areas, parks, buildings, sidewalks or administrative areas. The names of the map layers supported by the map service 
	 * provider can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the @ref ProviderCapabilities::MAP_SUPPORTED_LAYERS 
	 * property key. An application does not need to worry about setting the layers in the right order. The service provider defines the order in which the 
	 * layers are to be placed on top of the map base when the map is being rendered. Passing @c null or an empty list means that there are no layers on top 
	 * of the map base.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	pLayers			A list of the names of the map layers to be included in generated or displayed maps @n
	 *								Can also be @c null or an empty list.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c pLayers contains elements not supported by the service provider or contains elements that are not String instances.
	 */
	result SetLayers(const Osp::Base::Collection::IList* pLayers);

	/**
	 * Gets the type of map base to be used in the service request. @n
	 * The base of the map can be a regular map, a satellite image, an aerial image, a terrain map or only a latitude and longitude grid. The map bases 
	 * supported by the map service provider can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::MAP_SUPPORTED_MAP_BASES property key. The method returns the default value set by the service provider or a value set with 
	 * the @ref SetMapBase() method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 * @return	The map base type for service requests made by the service provider
	 */
	Osp::Base::String GetMapBase(void) const;

	/**
	 * Sets the preferences for the type of map base in the service requests of the map service provider. @n
	 * The base of the map can be a regular map, a satellite image, an aerial image, a terrain map or only a latitude and longitude grid. The
	 * map bases supported by the map service provider can be retrieved with the @ref ProviderCapabilities::GetPropertyValue() method
	 * using the @ref ProviderCapabilities::MAP_SUPPORTED_MAP_BASES property key.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	mapBase			The preferred map base in service requests
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c mapBase is not supported by the service provider.
	 */
	result	SetMapBase(const Osp::Base::String& mapBase);

	/**
	 * Checks whether background transparency must be used by the map service provider when generating map objects. @n
	 * The support for transparent maps can be queried with the @ref ProviderCapabilities::GetPropertyValue() method using the @ref 
	 * ProviderCapabilities::MAP_SUPPORTS_TRANSPARENT_BACKGROUND property key. The method returns the default value set by the service provider or the 
	 * value set with the @ref SetBackgroundTransparency() method.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 * @return	@c true if a map with transparent background has been requested, @n
	 *			else @c false
	 */
	bool IsBackgroundTransparency(void) const;

	/**
	 * Sets the background transparency for maps. @n
	 * The support for transparent maps can be queried with the @ref ProviderCapabilities::GetPropertyValue() method using the 
	 * @ref ProviderCapabilities::MAP_SUPPORTS_TRANSPARENT_BACKGROUND property key. If the service provider does not support transparent backgrounds and 
	 * @c true is passed as the parameter, E_INVALID_ARG is thrown.
	 * 
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	transparentBackground	Set to @c true if a transparent background is requested @n
	 *										else @c false
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c transparentBackground is @c true, but is not supported by the service provider.
	 */
	result SetBackgroundTransparency(bool transparentBackground);

protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 */
	result SynchronizeMapData(void);

protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * MMapServicePreferences instance
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	MMapServicePreferences* __pPreferences;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Displayed map layers
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::ArrayList*	__pLayers;

private:
	friend class MapServicePreferencesEx;
	class MapServicePreferencesEx* __pMapServicePreferencesEx;

};	// class MapServicePreferences

}; }; };	// Osp::Locations::Services

#endif // _FLOC_MAP_SERVICE_PREFERENCES_H_
