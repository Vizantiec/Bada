/* $Change: 1198808 $ */
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
 * @if PRIVCORE
 * @file		FSecIdentityInfo.h
 * @brief		This is the header file for the %IdentityInfo class.
 *
 * This header file contains the declarations and descriptions of the %IdentityInfo class.
 *
 * @endif
 */
#ifndef _FSEC_IDENTITY_IDETITYINFO_H
#define _FSEC_IDENTITY_IDETITYINFO_H

// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"
 
namespace Osp { namespace Security { namespace Identity {

/**
 * @if PRIVCORE
 * @enum 	IdentityPropertyId
 * Defines IDs for accessing the single value type properties of the %IdentityInfo class.
 *
 * @since 		1.0
 * @endif 
 */
enum IdentityPropertyId{
	IDENTITY_PROPERTY_ID_USER_ID,	/**< @if PRIVCORE An ID for the user ID property @endif */
	IDENTITY_PROPERTY_ID_LOGIN_ID,	/**< @if PRIVCORE An ID for the login ID property @endif */
	IDENTITY_PROPERTY_ID_BIRTHDAY,	/**< @if PRIVCORE An ID for the birthday property @endif */
	IDENTITY_PROPERTY_ID_PASSWORD,	/**< @if PRIVCORE An ID for the password property @endif */
	IDENTITY_PROPERTY_ID_DEVICE_ID	/**< @if PRIVCORE An ID for the device ID property @b Since 2.0 @b @endif */
};
#define IDENTITY_PROPERTY_ID_PASSOWRD IDENTITY_PROPERTY_ID_PASSWORD

/**
 * @if PRIVCORE
 *
 * @class		IdentityInfo
 * @brief      This class provides the device user's identity information.
 * @since 		1.0
 *
 * The %IdentityInfo class provides a method to get the user information. The user information contains the user ID, the login ID, the birthday, and the password. To get 
 * valid values, the user must be signed into the bada Server.
 *
 * @endif
 */
class _EXPORT_SECURITY_ IdentityInfo
{
public:
	/**
	* @if PRIVCORE
	* Gets the value of the specified property. @n
	* If the user has not signed into the bada Server, the E_USER_NOT_REGISTERED exception will be thrown.
	*
	* @since 		1.0
	* @privlevel	CORE
	*
	* @privgroup   	USER_IDENTITY
	*
	*  @return		An error code
	*  @param[in]	The ID of the property whose value is to be retrieved
	*  @param[out]	The value of the specified property
	*  @exception	E_SUCCESS               The method is successful.
	*  @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	*  @exception	E_OBJ_NOT_FOUND        	The specified @c ID is not found.
	*  @exception  	E_SYSTEM                A system error has occurred.
	*  @exception	E_USER_NOT_REGISTERED	The user is not registered.
	*  @remarks		This method should not be used without obtaining prior permission from the bada platform team. 
	* @endif
	*/
	static result GetValue(IdentityPropertyId id, Osp::Base::String &value); 
private:
	friend class		IdentityInfoEx;
	class IdentityInfoEx*	__pIdentityInfoEx;

};
}; }; }; // Osp::Security::Identity

#endif //_FSEC_IDENTITY_IDETITYINFO_H

