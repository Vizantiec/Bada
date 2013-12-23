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
* @file		FSclSvcWorkInfo.h
* @brief	This is the header file for the %WorkInfo class.
*
* This header file contains the declarations of the %WorkInfo class.
*/
#ifndef _FSCL_SVC_WORK_INFO_H_
#define _FSCL_SVC_WORK_INFO_H_

// Includes
#include "FBaseDateTime.h"
#include "FBaseResult.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

// Enums and Constants
/** The maximum length of the company name field. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 			1.0
*/
static const int MAX_WORK_COMPANY_NAME_LENGTH		= 50;
/** The maximum length of the company unit field. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 			1.0
*/
static const int MAX_WORK_COMPANY_UNIT_LENGTH		= 50;
/** The maximum length of the job title field. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since 			1.0
*/
static const int MAX_WORK_JOB_TITLE_LENGTH			= 50;


/**
* @class	WorkInfo
* @brief	This class represents the working history of a person.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0 
*
* The %WorkInfo class represents the working history of a person.
*
*/
class  _EXPORT_SOCIAL_ WorkInfo:
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
	WorkInfo(void);

	/**
	* This is the copy constructor for the %WorkInfo class. @n
	* It creates an instance of the %WorkInfo class with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %WorkInfo
	*/
	WorkInfo(const WorkInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 			1.0
	*/
	virtual ~WorkInfo(void);

public:	
	/**
	* Copies the data contained in the specified instance of %WorkInfo to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %WorkInfo to copy from
	*/
	WorkInfo& operator =(const WorkInfo& value);

	// Operations
public:
	/** 
	* Gets the name of the company of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The name of the company
	*/
	Osp::Base::String GetCompanyName(void) const;

	/** 
	* Gets the company unit of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0	 
	* @return	The unit of the company
	*/
	Osp::Base::String GetCompanyUnit(void) const;

	/** 
	* Gets the job title of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The job title
	*/
	Osp::Base::String GetJobTitle(void) const;

	/** 
	* Gets the start date of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The start date of the current instance of %WorkInfo
	*/
	Osp::Base::DateTime GetStartDate(void) const;

	/** 
	* Gets the end date of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 	1.0
	* @return	The end date of the current instance of %WorkInfo
	*/
	Osp::Base::DateTime GetEndDate(void) const;

	/** 
	* Sets or replaces the company name of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	companyName		The name of the company
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of @c companyName exceeds #MAX_WORK_COMPANY_NAME_LENGTH.
	*/
	result SetCompanyName(const Osp::Base::String& companyName);

	/** 
	* Sets or replaces the company unit of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	companyUnit		The unit of the company
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of @c companyUnit exceeds #MAX_WORK_COMPANY_UNIT_LENGTH.
	*/
	result SetCompanyUnit(const Osp::Base::String& companyUnit);

	/** 
	* Sets or replaces the job title of the current instance of %WorkInfo.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @param[in]	jobTitle		The job title
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of @c jobTitle exceeds #MAX_WORK_JOB_TITLE_LENGTH.
	*/
	result SetJobTitle(const Osp::Base::String& jobTitle);

	/** 
	* Sets or replaces the start date of the current instance of %WorkInfo.
	* If the DateTime value for the specified property has not been set by the user, the property has the minimum value of the DateTime, @n
	* which can be retrieved by DateTime::GetMinValue(). (i.e "January 1 1 00:00:00")
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	date	The start date
	*/
	void SetStartDate(const Osp::Base::DateTime& date);

	/** 
	* Sets or replaces the end date of the current instance of %WorkInfo.
	* If the DateTime value for the specified property has not been set by the user, the property has the minimum value of the DateTime, @n
	* which can be retrieved by DateTime::GetMinValue(). (i.e "January 1 1 00:00:00")
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	date	The end date
	*/
	void SetEndDate(const Osp::Base::DateTime& date);

private:	
	Osp::Base::String __companyName;
	Osp::Base::String __companyUnit;
	Osp::Base::String __jobTitle;
	Osp::Base::DateTime __startDate;
	Osp::Base::DateTime __endDate;

private:
	friend class WorkInfoEx;
	class WorkInfoEx* __pWorkInfoEx;

};

};};};// Osp::Social::Services

#endif// _FSCL_SVC_WORK_INFO_H_



