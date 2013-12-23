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
 * @file		FLocDirectoryServicePreferences.h 
 * @brief		This is the header file for the DirectoryServicePreferences class.
 *
 * This header file contains the declarations of the DirectoryServicePreferences class.
 */

#ifndef	_FLOC_DIRECTORY_SERVICE_PREFERENCES_H_
#define _FLOC_DIRECTORY_SERVICE_PREFERENCES_H_

// include
#include "FLocationConfig.h"
#include "FBaseTypes.h"
#include "FLocServicePreferences.h"

// forward declaration
namespace Osp { namespace Base { class String; }; };
struct MDirectoryServicePreferences;


namespace Osp { namespace Locations { namespace Services {

// forward declaration
class ProviderCapabilities;

/**
* @class	DirectoryServicePreferences
* @brief	This class encapsulates the preferences related to a directory service provider.
* @deprecated	This class is deprecated.
* @since  1.0
*
* The %DirectoryServicePreferences class encapsulates the preferences related to a directory service provider. The preferences include, for example, controlling options for the number of results and sorting.
* An application retrieves an instance of this class with the IServiceProvider::GetServicePreferencesN() method. The returned instance
* contains either the default values or the last used values for all the preferences. An application can check the values with
* Get* methods and it may change these default values with Set* methods.
*
* The API implementation and a directory service provider may also add new service preferences. The mechanism to define
* additional preference properties is provided in the ServicePreferences superclass. Property keys for the additional
* preferences defined by each directory service provider can be retrieved with the @ref ServicePreferences::GetAdditionalPropertyKeys() method.
*
*/
class _EXPORT_LOCATION_ DirectoryServicePreferences :
	public Osp::Locations::Services::ServicePreferences {

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
	DirectoryServicePreferences(void);

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
	DirectoryServicePreferences(const DirectoryServicePreferences& value);
	
	/*
	 * @internal
	 * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 1.0
	 */
	DirectoryServicePreferences& operator=(const DirectoryServicePreferences& rhs);

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~DirectoryServicePreferences(void);

// Operations
public:
	/**
	 * Compares the calling instance with the specified instance.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		@c true if both objects are equal @n
	 *				@c false, otherwise
	 * @param[in]	obj		The object to compare with the current instance 
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
	 * Gets the sort order for the directory service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return	The sort order set with the SetSortOrder() method @n
	 *			Osp::Base::SORT_ORDER_NONE if sorting is not supported by the service provider or the sort order has not been set
	 */
	Osp::Base::SortOrder	GetSortOrder(void) const;

	/**
	 * Sets the sort order for the directory service provider. 
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	sortOrder		The order in which the sorting is done
	 * @exception	E_SUCCESS 		The method was successful.
	 * @exception	E_INVALID_ARG 	The sortOrder is SORT_ORDER_ASCENDING or SORT_ORDER_DESCENDING but the service provider does not support sorting.
	 * @remarks	To find if the directory service provider supports the ability to sort results, query it using the @ref ProviderCapabilities::GetPropertyValue() method with the
	 *			@ref ProviderCapabilities::DIR_SUPPORTS_SORT property key. If an application sets the sorting order to anything other than @ref Osp::Base::SORT_ORDER_NONE,
	 *			it must sort the results from directory searching using the specified sort order.
	 *			If the service provider does not support sorting and @ref Osp::Base::SORT_ORDER_ASCENDING or @ref Osp::Base::SORT_ORDER_DESCENDING
	 *			is passed as the parameter, then E_INVALID_ARG is thrown.
	 */
	result	SetSortOrder(Osp::Base::SortOrder sortOrder);

	/**
	 * Gets the sort criterion for the directory service provider.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return	The sort criterion @n
	 *			An empty string, if sorting is not supported by the service provider, or the sort criterion has not been set
	 * @see			SetSortBy()
	 */
	Osp::Base::String	GetSortBy(void) const;

	/**
	 * Sets the sort criterion for the directory service provider. @n
	 * These criteria can be, for example, name, category, or distance. The sort criteria 
	 * supported by the service provider can be retrieved using the @ref  ProviderCapabilities::GetPropertyValue() method with
	 * @ref ProviderCapabilities::DIR_SUPPORTED_SORT_CRITERIONS property key.
	 * If the given @c pSortBy is not supported by the service provider, or if the service provider does not support sorting and @c pSortBy is something other than a 
	 * @c null or empty string, an E_INVALID_ARG is thrown.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	pSortBy			The sort criterion used to sort the result set @n
	 *								A @c null or empty string gives results in random order.
	 * @exception	E_SUCCESS 		The method was successful.
	 * @exception	E_INVALID_ARG 	The service provider does not support sorting by the specified @c pSortBy criterion.
	 */
	result	SetSortBy(const Osp::Base::String* pSortBy);

	/**
	 * Gets the maximum number of results for the directory service provider. @n
	 * This is a default value given by the service provider. However, it can be changed using @ref SetMaxResultCount.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @return	The maximum number of results for the directory service provider
	 * @see 		SetMaxResultCount();
	 */
	int	GetMaxResultCount(void) const;

	/**
	 * Sets the maximum number of results for the directory service provider. @n
	 * This is a default value given by the service provider. However, it can be changed using this method.
	 *
	 * If the count is less than 1, E_INVALID_ARG is thrown.
	 *
	 * @deprecated	This method is deprecated.
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	count			The maximum number of results
	 * @exception	E_SUCCESS		The method was successful.
	 * @exception	E_INVALID_ARG	The specified @c count is less than @c 1.
	 * @see 			GetMaxResultCount();
	 */
	result	SetMaxResultCount(int count);

// Data members
protected:
	/**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * MDirectoryServicePreferences instance
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 *
	 */
	MDirectoryServicePreferences*	__pPreferences;

private:
	friend class DirectoryServicePreferencesEx;
	class DirectoryServicePreferencesEx* __pDirectoryServicePreferencesEx;
	
};	// class DirectoryServicePreferences
}; }; };	// Osp::Locations::Services

#endif	// _FLOC_DIRECTORY_SERVICE_PREFERENCES_H_
