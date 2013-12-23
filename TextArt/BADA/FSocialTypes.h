/* $Change: 1142016 $ */
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
 * @file	FSocialTypes.h
 * @brief	This is the header file for the types in the %Social namespace.
 *
 * This header file contains the declarations of the types in the %Social namespace.
 */
#ifndef _FSCL_TYPES_H_
#define _FSCL_TYPES_H_

namespace Osp { namespace Social {

/**
 * @if PRIVCORE
 * The maximum length of a service provider.
 *
 * @since		1.0
 * @endif
 */
static const int MAX_SERVICE_PROVIDER_LENGTH	= 30;

/**
 * @if PRIVCORE
 * The maximum length of an account.
 *
 * @since		1.0
 * @endif
 */
static const int MAX_ACCOUNT_LENGTH	= 320;

/**
 * @enum	RecordSensitivity
 * Defines the sensitivity type of the calendar book record. @n
 * This value represents the access classification property of @c vCalendar and @c iCalendar.
 *
 * @since		1.0
 */
typedef enum {
	SENSITIVITY_PUBLIC,			/**< The public sensitivity */
	SENSITIVITY_PRIVATE,		/**< The private sensitivity */
	SENSITIVITY_CONFIDENTIAL	/**< The confidential sensitivity */
} RecordSensitivity;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. @n
 *
 * @enum	CalendarbookUiReturnValueType
 * Defines the selected return value from the Calendarbook UI.
 *
 * @since		1.0
 */

typedef enum {
	CAL_UI_RETURN_TYPE_VNOTE,			/*< The VNote file path */
	CAL_UI_RETURN_TYPE_VCALENDAR		/*< The VCalendar file path */
} CalendarbookUiReturnValueType;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. @n
 *
 * @enum	AddressbookUiStorageType
 * Defines the type of storage on which the contact will be created.
 *
 * @since		1.0
 */
typedef enum {
	AB_UI_STORAGE_TYPE_PHONE,		/*< The phone type*/
	AB_UI_STORAGE_TYPE_SIM,		/*< The SIM type */
} AddressbookUiStorageType;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. @n
 *
 * @enum	AddressbookUiProperty
 * Defines the property for creating or editing a contact.
 *
 * @since		1.0
 */
typedef enum {
	AB_UI_PROPERTY_PHONE_NUMBER,		/*< The Phone Number*/
	AB_UI_PROPERTY_EMAIL,				/*< The Email address */
	AB_UI_PROPERTY_URL,					/*< The URL */
	AB_UI_PROPERTY_NONE					/*< None */
} AddressbookUiProperty;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. @n
 *
 * @enum	AddressbookUiReturnValueType
 * Defines the selected return value from the Addressbook UI.
 *
 * @since		1.0
 */
typedef enum {
	AB_UI_RETURN_TYPE_PHONE_NUMBER,		/*< The Phone Number */
	AB_UI_RETURN_TYPE_EMAIL,			/*< The Email address */
	AB_UI_RETURN_TYPE_CONTACT_ID,		/*< The Contact ID	 */
	AB_UI_RETURN_TYPE_PHOTO,			/*< The photo	*/
	AB_UI_RETURN_TYPE_VCARD,			/*< The Vcard	*/
} AddressbookUiReturnValueType;

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. @n
 *
 * @enum	AddressbookUiViewType
 * Defines the selected view type from the Addressbook UI.
 *
 * @since		1.0
 */

typedef enum {
	AB_UI_VIEW_TYPE_VCARD,			/*< The view type for vCard */
} AddressbookUiViewType;

};};

#endif
