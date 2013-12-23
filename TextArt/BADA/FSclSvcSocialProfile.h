/* $Change: 1144988 $ */
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
* @file		FSclSvcSocialProfile.h
* @brief	This is the header file for the %SocialProfile class.
*
* This header file contains the declarations of the %SocialProfile class.
*/
#ifndef _FSCL_SVC_SOCIAL_PROFILE_H_
#define _FSCL_SVC_SOCIAL_PROFILE_H_

// Includes
#include "FBaseColArrayList.h"
#include "FSclSvcProfile.h"
#include "FSclSvcEducationInfo.h"
#include "FSclSvcWorkInfo.h"


namespace Osp { namespace Social { namespace Services {
	// To make friendship.
	class __ProfileUtil;

/**
* The predefined IDs for accessing the properties of %SocialProfile.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since 			1.0
*/
enum SocialProfilePropertyId {
	SP_PID_EDUCATION_HISTORY,	/**< The ID for the Educational History property */
	SP_PID_WORK_HISTORY			/**< The ID for the Work History property */
};

/** The count of properties in %SocialProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
static const int	SOCIAL_PROFILE_PROPERTY_COUNT = 2;
/** The capacity of educational history in %SocialProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
static const int PROFILE_EDUCATION_HISTORY_CAPACITY = 50;
/** The capacity of work history in %SocialProfile. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 	1.0
*/
static const int PROFILE_WORK_HISTORY_CAPACITY = 50;


/**
* @class	SocialProfile
* @brief	This class represents the social profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* The %SocialProfile class represents the social profile of a user. The social profile contains the educational and the work history of the user. The social profile is not 
* constructed. It is obtained from the server using the ProfileService::GetMyProfile() or ProfileService::GetProfile() methods. The profile has a valid user 
* ID.
*/
class  _EXPORT_SOCIAL_ SocialProfile:
	public Osp::Social::Services::Profile
{
	// Friend class
	friend class __ProfileUtil;

	// Construct Operations
protected:
	/**
	* This is the constructor for this class. @n
	* It constructs an instance of %SocialProfile with the specified user ID.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	userId		The user ID
	*
	*/
	SocialProfile(const UserId& userId);


public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	SocialProfile(void):
	__pEduList(null),__pWorkList(null),__pDeletedEduList(null),__pDeletedWorkList(null),__pSocialProfileEx(null)
	{ };

	/**
	* This is the copy constructor for the %SocialProfile class. @n
	* It creates an instance of %SocialProfile with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value		An instance of %SocialProfile
	*/
	SocialProfile(const SocialProfile& value);

	/**
	* This assignment operator copies the data contained in the specified instance of %SocialProfile to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		A reference to the current instance
	* @param[in]	value		An instance of %SocialProfile
	*/
	SocialProfile&	operator =(const SocialProfile& value);

	/**
	* This is the destructor for this class. @n
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SocialProfile(void);

	// Operations
public:
	/**
	* Adds the educational information to the social profile. @n
	* The specified @c eduInfo must have at least the school name, degree, or major.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	eduInfo		        The education information to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_ARG 		The specified input parameter is empty.
	* @exception	E_OVERFLOW  		The count of education information in this %SocialProfile exceeds #PROFILE_EDUCATION_HISTORY_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result AddEducationInfo(const EducationInfo& eduInfo);

	/**
	* Adds the work information to the social profile.
	* The specified @c workInfo must have at least the company name, company unit, or job title.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	workInfo			The work information to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_ARG 		The specified input parameter is empty.
	* @exception	E_OVERFLOW  		The count of work information in this %SocialProfile exceeds #PROFILE_WORK_HISTORY_CAPACITY.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result AddWorkInfo(const WorkInfo& workInfo);

	/**
	* Replaces the educational information at the specified index.
	* The specified @c eduInfo must have at least the school name, degree, or major.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	index				The index of the EducationInfo instance to be replaced
	* @param[in]	eduInfo				The new %EducationInfo instance
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE		The specified index is out of range (valid range: 0 <= index && index < GetCount(SP_PID_EDUCATION_HISTORY)).
	* @exception	E_INVALID_ARG 		A specified input parameter is empty.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result SetEducationInfoAt(int index, const EducationInfo& eduInfo);

	/**
	* Replaces the work information at the specified index.
	* The specified @c workInfo must have at least the company name, company unit, or job title.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	index				The index of the WorkInfo instance to be replaced
	* @param[in]	workInfo			The new %WorkInfo instance
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE		The specified @c index is out of range (valid range: 0 <= index && index < GetCount(SP_PID_WORK_HISTORY)).
	* @exception	E_INVALID_ARG 		A specified input parameter is empty.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result SetWorkInfoAt(int index, const WorkInfo& workInfo);

	/**
	* Gets the number of items of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The number of items of the specified property
	* @param[in]	id		The ID of the property
	*/
	int GetCount(SocialProfilePropertyId id) const;

	/**
	* Gets the value of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The value of the specified property as a list, @n
	*				else an empty list if the property has no value @n
	*				This method returns a list as the value can have multiple items. @n
	*				If the ID is #SP_PID_EDUCATION_HISTORY, the items in the list are instances of Osp::Social::Services::EducationInfo. @n
	*				If the ID is #SP_PID_WORK_HISTORY, the items in the list are instances of Osp::Social::Services::WorkInfo.
	* @param[in]	id					The ID of the property
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c id is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::Collection::IList* GetValueN(SocialProfilePropertyId id) const;

	/**
	* Removes the item at the specified index of the specified property.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	id					The ID of the property
	* @param[in]	index				The index of the item to be removed
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c id is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE		The specified index is out of range (valid range: 0 <= index && index < The count of items of the specified property).
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result RemoveAt(SocialProfilePropertyId id, int index);

private:
	bool IsEmptyEduInfo(const EducationInfo& eduInfo);
	bool IsEmptyWorkInfo(const WorkInfo& workInfo);

	Osp::Base::Collection::IEnumerator* GetValueEnumeratorN(SocialProfilePropertyId id) const;
	Osp::Base::Collection::IEnumerator* GetDeletedItemsN(SocialProfilePropertyId id) const;
	result AddEducationInfo(const EducationInfo& eduInfo, const Osp::Base::String* pSeqId);
	result AddEducationInfo(const EducationInfo& eduInfo, const Osp::Base::String* pSeqId, bool isUpdated);
	result AddWorkInfo(const WorkInfo& workInfo, const Osp::Base::String* pSeqId);
	result AddWorkInfo(const WorkInfo& workInfo, const Osp::Base::String* pSeqId, bool isUpdated);

private:

	Osp::Base::Collection::ArrayList*	__pEduList;
	Osp::Base::Collection::ArrayList*	__pWorkList;

	Osp::Base::Collection::ArrayList*	__pDeletedEduList;
	Osp::Base::Collection::ArrayList*	__pDeletedWorkList;

private:
	friend class SocialProfileEx;
	class SocialProfileEx* __pSocialProfileEx;

}; // SocialProfile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_SOCIAL_PROFILE_H_
