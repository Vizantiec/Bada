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
* @file		FSclSvcEducationInfo.h
* @brief	This is the header file for the %EducationInfo class.
*
* This header file contains the declarations of the %EducationInfo class.
*/
#ifndef _FSCL_SVC_EDUCATION_INFO_H_
#define _FSCL_SVC_EDUCATION_INFO_H_

// Includes
#include "FBaseDateTime.h"
#include "FBaseResult.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

// Enums and Constants
/**
* Defines the education types for %EducationInfo.
*
* @deprecated	This enumerator is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
enum EducationType {
	EDU_TYPE_ELEMENTARY_SCHOOL,			/**< The elementary school */
	EDU_TYPE_JUNIOR_HIGH_SCHOOL,		/**< The junior high school*/	
	EDU_TYPE_SENIOR_HIGH_SCHOOL,		/**< The senior high school */	
	EDU_TYPE_UNIVERSITY,				/**< The university */	
	EDU_TYPE_OTHER						/**< The type is Other */	
};

/** The maximum length of the school name field of %EducationInfo. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_EDU_SCHOOL_NAME_LENGTH		= 50;
/** The maximum length of the degree field of %EducationInfo. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_EDU_DEGREE_LENGTH			= 50;
/** The maximum length of the major name field of %EducationInfo. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since			1.0
*/
static const int MAX_EDU_MAJOR_LENGTH			= 50;

/**
* @class	EducationInfo 
* @brief	This class represents the educational history of a person.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* The %EducationInfo class represents the educational history of a person.
*
* The following example demonstrates how to use the %EducationInfo class.
* @code
using namespace Osp::Base;
using namespace Osp::Social::Services;

result
MyClass::SomeMethod(void)
{	
	result r = E_SUCCESS;
	// Creates an instance of EducationInfo.
	EducationInfo eduInfo = EducationInfo();

	// Sets the school name.
	r = eduInfo.SetSchoolName(L"Dream University");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the type.
	eduInfo.SetType(EDU_TYPE_UNIVERSITY);	

	// Sets the major.
	r = eduInfo.SetMajor(L"Computer Science");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the degree.
	r = eduInfo.SetDegree(L"Master");
	if (IsFailed(r)) {
		return r;
	}

	// Sets the start date.
	DateTime startDate = DateTime();
	r = startDate.SetValue(2003, 3, 3);
	if (IsFailed(r)) {
		return r;
	}
	eduInfo.SetStartDate(startDate);

	// Sets the end date.
	DateTime endDate = DateTime();
	r = endDate.SetValue(2005, 2, 14);
	if (IsFailed(r)) {
		return r;
	}
	eduInfo.SetEndDate(endDate);

	return E_SUCCESS;
}
* @endcode
*/
class  _EXPORT_SOCIAL_ EducationInfo:
	public Osp::Base::Object
{
	// Construct Operation
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*/
	EducationInfo(void);

	/**
	* This is the copy constructor for the %EducationInfo class. @n
	* It constructs an instance of %EducationInfo with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 		An instance of %EducationInfo
	*/
	EducationInfo(const EducationInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~EducationInfo(void);

public:
	/**
	* Copies the values of the specified instance of %EducationInfo to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value 		An instance of %EducationInfo to copy from
	*/
	EducationInfo& operator =(const EducationInfo& value);

	// Operations
public:	
	/** 
	* Gets the type of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The type of the %EducationInfo
	*/
	EducationType GetType(void) const;

	/** 
	* Gets the school name of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The school name
	*/
	Osp::Base::String GetSchoolName(void) const;

	/** 
	* Gets the degree of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The degree
	*/
	Osp::Base::String GetDegree(void) const;

	/** 
	* Gets the major (specialization) of the current instance of %EducationInfo.
	*	
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The major (specialization)
	*/
	Osp::Base::String GetMajor(void) const;

	/** 
	* Gets the start date of the current instance of %EducationInfo.
	* If the DateTime value for the specified property has not been set by the user, the property has the minimum value of the DateTime, @n
	* which can be retrieved by DateTime::GetMinValue(). (That is, "January 1 1 00:00:00")
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The start date of the school
	*/
	Osp::Base::DateTime GetStartDate(void) const;

	/** 
	* Gets the end date of the current instance of %EducationInfo.
	* If the DateTime value for the specified property has not been set by the user, the property has the minimum value of the DateTime, @n
	* which can be retrieved by DateTime::GetMinValue(). (That is, "January 1 1 00:00:00")
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since	1.0
	*
	* @return	The end date of the school
	*/
	Osp::Base::DateTime GetEndDate(void) const;

	/** 
	* Sets the education type of the current instance of %EducationInfo.
	*	
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	type		The new education type to be set
	*/
	void SetType(EducationType type);

	/** 
	* Sets the school name of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	schoolName		The school name
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified @c schoolName exceeds #MAX_EDU_SCHOOL_NAME_LENGTH.
	*/
	result SetSchoolName(const Osp::Base::String& schoolName);

	/** 
	* Sets the degree of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	degree			The degree
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified @c degree exceeds #MAX_EDU_DEGREE_LENGTH.
	*/
	result SetDegree(const Osp::Base::String& degree);

	/** 
	* Sets the major (specialization) of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	major			The major
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified @c major exceeds #MAX_EDU_MAJOR_LENGTH.
	*/
	result SetMajor(const Osp::Base::String& major);

	/** 
	* Sets the start date of the current instance of %EducationInfo.
	*	 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	date	The start date
	*/
	void SetStartDate(const Osp::Base::DateTime& date);

	/** 
	* Sets the end date of the current instance of %EducationInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	date	The end date
	*/
	void SetEndDate(const Osp::Base::DateTime& date);

private:
	EducationType __type;
	Osp::Base::String __schoolName;
	Osp::Base::String __degree;
	Osp::Base::String __major;
	Osp::Base::DateTime __startDate;
	Osp::Base::DateTime __endDate;

private:
	friend class EducationInfoEx;
	class EducationInfoEx* __pEducationInfoEx;

}; // EducationInfo

};};};// Osp::Social::Services

#endif// _FSCL_SVC_EDUCATION_INFO_H_


