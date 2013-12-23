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
 * @file		FLocDirectoryFilter.h
 * @brief		This is the header file for the DirectoryFilter class.
 *
 * This header file contains the declarations of the DirectoryFilter class.
 *
 */

#ifndef	_FLOC_DIRECTORY_FILTER_H_
#define _FLOC_DIRECTORY_FILTER_H_

// include
#include "FLocationConfig.h"
#include "FBaseObject.h"

// foward declaration
namespace Osp { namespace Base { class String; }; };
namespace Osp { namespace Base { namespace Collection { class IMap; }; }; };
namespace Osp { namespace Base { namespace Collection { class HashMap; }; }; };


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class ProviderCapabilities;

/**
* @class	DirectoryFilter
* @brief	This class represents the search filter for the directory service provider.
* @deprecated	This class is deprecated.
* @since  1.0
*
* The %DirectoryFilter class represents the search filter for the directory service provider. The filter includes elements such as name, category, keyword, and other user-friendly identifiers 
* that can be used in a search request for the directory service provider.
* There are 3 default filters defined for all directory service providers: @n
* - name
* - category
* - keyword @n
*
* Filter names are defined as constants in this class and they start with the prefix SEARCH_FILTER_. The directory service provider 
* may support additional filters for search requests, such as a brand or a phone number. The names of supported filters can be retrieved with the 
* @ref ProviderCapabilities::GetPropertyValue() method using the @ref ProviderCapabilities::DIR_SUPPORTED_SEARCH_FILTERS property key.
*
* An application retrieves an instance of this class with IDirectoryServiceProvider::GetFilterN() . The returned instance
* contains either the default values, or the last used values for the filter. The default filter returned by this method may not contain any filtering conditions.
* An application can use the GetAllFilters() methods to check values; it may change these values with AddFilter() or RemoveFilter() method.
*/
class _EXPORT_LOCATION_ DirectoryFilter :public Osp::Base::Object
{
// Constant
public:
	/**
	 * Search by name filter.
	 *
	 * @deprecated	This constant is deprecated.
	 * @since	1.0
	 */
	static const Osp::Base::String SEARCH_FILTER_NAME;

	/**
	 * Search by category filter.
	 *
	 * @deprecated	This constant is deprecated.
	 * @since	1.0
	 */
	static const Osp::Base::String SEARCH_FILTER_CATEGORY;

	/**
	 * Search by keyword filter.
	 *
	 * @deprecated	This constant is deprecated.
	 * @since	1.0
	 */
	static const Osp::Base::String SEARCH_FILTER_KEYWORD;

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
	DirectoryFilter(void);

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
	DirectoryFilter(const DirectoryFilter& value);
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	DirectoryFilter& operator=(const DirectoryFilter& rhs);

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~DirectoryFilter(void);

// Operations
public:
	/**
	 * Compares the specified instance with the calling instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		@c true, if the instances are equal @n
	 *				@c false, otherwise
	 * @param[in]	obj	The instance to compare
	 */
	virtual bool Equals(const Object& obj) const;

	/** 
	 * Gets the hash value of the current instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Adds a filter. @n
	 * This method overwrites the value of the filter if it already exists in this instance. @n
	 * If the value is an empty string, the named filter is not applied on the search.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	name	The filter name
	 * @param[in]	value	The filter value
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c name is an empty String or is not supported by the service provider.
	 * @remarks		The names of filters supported by the directory service provider can be retrieved with
	 *				@ref ProviderCapabilities::GetPropertyValue() method using @ref ProviderCapabilities::DIR_SUPPORTED_SEARCH_FILTERS property
	 *				key.
	 */
	result	AddFilter(const Osp::Base::String& name, const Osp::Base::String& value);

	/**
	 * Removes a filter.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	name	The filter name
	 * @exception	E_SUCCESS The method was successful.
	 * @exception	E_INVALID_ARG The specified @c name is an empty string.
	 * @exception	E_OBJ_NOT_FOUND The specified @c name has not been added yet.
	 */
	result	RemoveFilter(const Osp::Base::String& name);

	/**
	 * Gets filters that have been set. @n
	 *
	 * The collection of filter name - value pairs is returned. The name of the filter acts as a key for the returned map.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		The filters that has been set @n
	 *				@c null, if not provided
	 */
	const Osp::Base::Collection::IMap*	GetAllFilters(void) const;

// Data members
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * filter values
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	Osp::Base::Collection::HashMap*	__pFilters;
	
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * Reference of the provider capabilities
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	ProviderCapabilities*						__pCapabilities;

private:
	friend class DirectoryFilterEx;
	class DirectoryFilterEx* __pDirectoryFilterEx;
	
};	// class DirectoryFilter
}; }; };	// Osp::Locations::Services

#endif	// _FLOC_DIRECTORY_FILTER_H_
