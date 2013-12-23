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
 * @file		FLocLandmarkFilter.h 
 * @brief		This is the header file for the %LandmarkFilter class.
 *
 * This header file contains the declarations of the %LandmarkFilter class.
 */

#ifndef	_FLOC_LANDMARK_FILTER_H_
#define _FLOC_LANDMARK_FILTER_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseTypes.h"
#include "FLocQualifiedCoordinates.h"
#include "FLocAddressInfo.h"
#include "FLocGeographicArea.h"

// Forward declaration - SC classes
struct MLandmarkFilter;

namespace Osp { namespace Locations { 

/**
* @class	LandmarkFilter
* @brief	This class holds a number of filters that are used for landmark searching.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %LandmarkFilter class holds a number of filters that are used for landmark searching.
* A priority filter has been introduced from bada API version 1.2. An application sets a priority filter to get landmarks of a specific range.
*
* 
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
*
*/
class _EXPORT_LOCATION_ LandmarkFilter :
	public Osp::Base::Object{
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkFilter(void);

	/**
	* This is the copy constructor for the %LandmarkFilter class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkFilter(const LandmarkFilter& value);

	/**
	* This operator assigns the value of the specified %LandmarkFilter object to the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkFilter& operator=(const LandmarkFilter& rhs);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	~LandmarkFilter(void);

	/**
	* Sets the area filter to find the landmarks whose coordinates are inside the specified area filter.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pAreaFilter		The area filter
	*/
	void SetGeographicAreaFilter(const GeographicArea* pAreaFilter);

	/**
	* Sets the address filter. @n
	*
	* The fields specified in AddressInfo match the address fields in the resulting landmarks. The fields that are not specified (set to @c null) are ignored.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pAddrFilter		The address filter
	*/
	void SetAddressInfoFilter(const AddressInfo* pAddrFilter);

	/**
	* Sets the name filter to find the landmarks having the specified name.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pNameFilter		The name filter
	*/
	void SetNameFilter(const Osp::Base::String* pNameFilter);

	/**
	* Sets the author filter to find the landmarks having the specified author.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pAuthorsFilter		The author filter
	*/
	void SetAuthorFilter(const Osp::Base::String* pAuthorsFilter);

	/**
	* Sets the category filter to find the landmarks having the specified category.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pCategoryFilter		The category filter
	*/
	void SetCategoryFilter(const Osp::Base::String* pCategoryFilter);

  /**
	* Sets the priority filter to find the landmarks of the specified priorities. @n
  *
  * Landmarks whose priority is within the given range are matched in the search process.
	*
	* @deprecated	This method is deprecated.
    * @since		1.2
	* @return		An error code
	* @param[in]	minPriority		The minimum value of the range
	* @param[in]	maxPriority		The maximum value of the range
    * @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c minPriority or @c maxPriority is not an integer within the range [#HIGHEST_LANDMARK_PRIORITY, 
	*								#LOWEST_LANDMARK_PRIORITY], or @n
    *								the specified @c minPriority is greater than the specified @c maxPriority.
	*/
	result SetPriorityFilter(int minPriority, int maxPriority);


    /**
    * Sets the option for string matching. @n
    *
    * If the @c caseSensitive parameter is set to @c false, the string filters are handled in the case-insensitive way. @n
    *
    * The @c criteria controls the way of string matching. It can be one of the constants defined in @ref Osp::Base::StringMatchCriteria. @n
    * If @ref Osp::Base::STRING_MATCH_CRITERIA_EXACT is set, the string filters are matched exactly with the corresponding field of the landmark. @n
    * If @ref Osp::Base::STRING_MATCH_CRITERIA_START_WITH is set, the search does a partial matching by finding landmarks whose fields start with the 
    * specified filter. @n
	* If @ref Osp::Base::STRING_MATCH_CRITERIA_CONTAIN is set, partial matching is fully enabled so that the landmarks whose field contains 
	* the specified filter are searched. @n
	* If @ref Osp::Base::STRING_MATCH_CRITERIA_WILDCARD is set, wild characters can be used in the string filters. The 
	* @c ? character is used as a wildcard that matches any character. The @c * character is a wildcard that matches 0 or more characters. @n
    * Use of @ref Osp::Base::STRING_MATCH_CRITERIA_CONTAIN or @ref Osp::Base::STRING_MATCH_CRITERIA_WILDCARD can be unfavorable for applications where the 
	* performance for search is important. @n
    *
    * If the option has not been set, the landmark search performs the default match. All string filters are handled in a case-sensitive manner and matched 
	* exactly with the corresponding field of the landmark.
    *
	* @deprecated	This method is deprecated.
    * @since		2.0
    *
    * @return  		An error code
    * @param[in]	caseSensitive   	Set to @c true for case-sensitive comparison, @n
	*									else @c false
    * @param[in]	criteria			The manner of string matching
    * @exception	E_SUCCESS			The method is successful.
    * @exception	E_INVALID_ARG		The specified @c criteria is invalid.
    */
    result  SetStringMatchOption (bool caseSensitive, Osp::Base::StringMatchCriteria criteria);
    

private:
	MLandmarkFilter*	__pMLandmarkFilter;

friend class LandmarkStore;
friend class RemoteLandmarkStore;

private:
	friend class LandmarkFilterEx;
	class LandmarkFilterEx* __pLandmarkFilterEx;
};	// class LandmarkFilter
} }	// Osp::Location

#endif	// _FLOC_LANDMARK_FILTER_H_
