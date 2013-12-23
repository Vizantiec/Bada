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
* @file		FSclSvcCustomProfile.h
* @brief	This is the header file for the %CustomProfile class.
*
* This header file contains the declarations of the %CustomProfile class.
*/
#ifndef _FSCL_SVC_CUSTROM_PROFILE_H_
#define _FSCL_SVC_CUSTROM_PROFILE_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FBaseColArrayList.h"
#include "FSclSvcProfile.h"

namespace Osp { namespace Social { namespace Services {
	// To create a friendship.
	class __ProfileUtil;

/** The maximum length of the value of a custom property. 
*
* @deprecated	This constant variable is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
static const int MAX_PROFILE_CUSTOM_VALUE_LENGTH	= 1000;


/**
* @class	CustomProfile 
* @brief	This class represents the custom profile of a user.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* @pre		<a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
*            Component Setup</a> should be done.
*
*  The %CustomProfile class represents the custom profile of a user. The custom profile contains the custom properties of the user.
*	A custom property is a property that a developer defines when he needs an additional property.  
*
*/
class  _EXPORT_SOCIAL_ CustomProfile:
	public Osp::Social::Services::Profile
{
	// Friend class
	friend class __ProfileUtil;

private:
	/* default capacity of status */
	static const int DEFAULT_CAPACITY_OF_CUSTOM_PROPERTY	= 10;

	
// inner class
private:
	class __CustomProperty
		: public Object
	{
	public:
		__CustomProperty(void):__isUpdated(false){};
		~__CustomProperty(void) {};
	public:
		Osp::Base::String	__propertyName;
		Osp::Base::String	__propertyValue;
		bool __isUpdated;
	};

	// Construct Operations
protected:	
	/**
	* Initializes this instance of %CustomProfile with the specified user ID.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	userId			The user ID
	*/
	CustomProfile(const UserId& userId);

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	CustomProfile(void):__pCustomPropertyList(null),__pCustomProfileEx(null)
	{};

	/**
	* This is the copy constructor for the %CustomProfile class. @n
	* This constructs an instance of %CustomProfile with the values of the specified instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	value		An instance of %CustomProfile
	*/
	CustomProfile(const CustomProfile& value);
	
	/** 
	* Copies the values of the specified instance of %CustomProfile to the current instance.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		The reference of the current instance
	* @param[in]	value	An instance of %CustomProfile
	*/
	CustomProfile&	operator =(const CustomProfile& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*/
	virtual ~CustomProfile(void);


	// Operations
public:
	/**
	* Gets the value of the specified property name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	propertyName		A property name whose value is to be retrieved
	* @param[out]	value				The value of the specified property @n
	*									else an empty string if the specified property name has no value
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND		The specified @c propertyName does not exist.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*
	*/
	result GetValue(const Osp::Base::String& propertyName, Osp::Base::String &value) const;

	/**
	* Replaces the value of the specified property name with the specified value.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	propertyName		A property name
	* @param[in]	value				The new value to be set
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND		The specified @c propertyName does not exist.
	* @exception	E_INVALID_ARG 		The length of the specified @c value exceeds #MAX_PROFILE_CUSTOM_VALUE_LENGTH.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*
	*/
	result SetValue(const Osp::Base::String &propertyName, const Osp::Base::String &value);

	/**
	* Removes the value of the specified property.
	* 
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	propertyName		A property name
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND		The specified @c propertyName does not exist.
	* @exception	E_INVALID_STATE		This instance is not created by ProfileService.
	*/
	result RemoveValue(const Osp::Base::String& propertyName);

private:
	
	__CustomProperty* FindCustomProperty(const Osp::Base::String& propertyName) const;

	result SetValueString(const Osp::Base::String &propertyName, const Osp::Base::String& value, bool isUpdated);
	
private:	
	Osp::Base::Collection::ArrayList* __pCustomPropertyList;

private:
	friend class CustomProfileEx;
	class CustomProfileEx* __pCustomProfileEx;

}; // CustromProfile

};};};// Osp::Social::Services

#endif// _FSCL_SVC_CUSTROM_PROFILE_H_
