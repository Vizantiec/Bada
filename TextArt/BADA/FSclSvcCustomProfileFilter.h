/* $Change:  $ */
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
 * @file		FSclSvcCustomProfileFilter.h
 * @brief		This is the header file for the %CustomProfileFilter class.
 *
 * This header file contains declarations of the %CustomProfileFilter class.
 */
#ifndef _FSCL_SVC_CUSTOM_PROFILE_FILTER_H_
#define _FSCL_SVC_CUSTOM_PROFILE_FILTER_H_

// Includes
#include "FBase.h"
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseTypes.h"
#include "FBaseColIList.h"
#include "FBaseColArrayList.h"
#include "FSclConfig.h"
#include "FSclSvcTypes.h"


namespace Osp { namespace Social { namespace Services {

	// To create a friendship.
	class __ProfileUtil;

/**
 * @class	CustomProfileFilter
 * @brief	This class represents a filter to search custom profiles.
 * @deprecated	This class is deprecated due to the operation policy of the bada Server.
 * @since	2.0
 *
 * The %CustomProfileFilter class consists of 5 search conditions and a search scope: @n
 * - Each search condition comprises a custom profile property, comparison operator, and the value to be compared. Multiple search conditions can be combined into a single search criterion using the AND operator. @n
 * - The search scope can be set as either signed-up users or buddies of the calling application. @n
 *
 */
class  _EXPORT_SOCIAL_ CustomProfileFilter:
		public Osp::Base::Object
{
	// Friend class
	friend class __ProfileUtil;

private:
	/* default capacity of filter */
	static const int DEFAULT_MAX_CAPACITY_OF_FILTER	= 5;

	// Construct Operations
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	*/
	CustomProfileFilter(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		2.0
	*/
	virtual ~CustomProfileFilter(void);

private:
	// No implementation. Force to private
	CustomProfileFilter(const CustomProfileFilter& value);
	CustomProfileFilter& operator =(const CustomProfileFilter& value);

	// Operations
public:
	/**
	 * Adds the condition to the filter for searching custom profiles. @n
	 * The added conditions are automatically combined by using the AND operator. @n
	 * The filter can have up to five conditions. @n
	 * In case of LIKE operation by using COMPARISION_OP_LIKE in search conditions, the profiles are searched only by the front match about the specific property of CustomProfile. @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	propertyName		The property name of CustomProfile
	 * @param[in]	operation			The search operator
	 * @param[in]	pValue				The value to compare @n
	 * 									If the type of the value is not Osp::Base::String, the type should be converted by using ToString().
	 * @exception	E_SUCCESS			The method was successful.
	 * @exception	E_INVALID_ARG		The specified propertyName is empty. @n
	 * 									Or, the specified pValue is null when the specified operation is neither COMPARISION_OP_IS_NULL nor COMPARISION_OP_IS_NOT_NULL.
	 * @exception	E_OBJ_ALREADY_EXIST	The same condition already exists in the filter.
	 * @exception	E_MAX_EXCEEDED		The number of conditions exceeds 5.
	 * @exception	E_OUT_OF_MEMORY		Insufficient memory.
	 * @remarks		In case the specified operation is COMPARISION_OP_IS_NULL or COMPARISION_OP_IS_NOT_NULL, the specified pValue is ignored.
	 */
	result AddCondition(const Osp::Base::String& propertyName, Osp::Base::ComparisonOperator operation, const Osp::Base::String* pValue);

	/**
	 * Sets the search scope to control the output. @n
	 * The default value of the search scope is PROFILE_SEARCH_SCOPE_APPUSERS. @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 *
	 * @param[in]	searchScope		The search scope
	 */
	void SetScope(ProfileSearchScope searchScope);

	/**
	 * Gets the search scope. @n
	 *
	 * @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since		2.0
	 *
	 * @return		The search scope @n
	 * 				If the search scope is not explicitly set, PROFILE_SEARCH_SCOPE_APPUSERS is returned as the default value.
	 */
	ProfileSearchScope GetScope(void) const;

	// Variables
private:
	Osp::Base::Collection::ArrayList*	__pSearchConditionList;
	ProfileSearchScope					__searchScope;

private:
	friend class CustomProfileFilterEx;
	class CustomProfileFilterEx* __pCustomProfileFilterEx;

}; // CustomProfileFilter

};};}; // Osp::Social::Services

#endif // _FSCL_SVC_CUSTOM_PROFILE_FILTER_H_
