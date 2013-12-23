/* $Change: 903964 $ */
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
* @file			FSclCustomField.h
* @brief		This is the header file for the %CustomField class.
*
* This header file contains the declarations of the %CustomField class.
*/
#ifndef _FSCL_CUSTOM_FIELD_H_
#define _FSCL_CUSTOM_FIELD_H_

// Includes
#include "FBaseResult.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {

/**
* @if PRIVCORE
* @class	CustomField
* @brief	This class represents a custom field.
* @since	2.0
*
* The %CustomField class represents a custom field. A custom field contains the information for launching an application. It consists of a title, a description, and a URI that contains the information for launching an application.
*
** For more information, see
* <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/exporting_appcontrol_functionality.htm">Exporting AppControl Functionality</a> and
* <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/resolving_appcontrols.htm">Resolving AppControls</a>.
*
* The following example demonstrates how to define the application control ID and the operation ID in the application.xml file.
*
* @code
	<Multitasking>true</Multitasking>
		<AppControl appcontrolId="osp.appcontrol.TEST" category="0x00">
			<Capability operationID="osp.appcontrol.operation.DEFAULT" />
		</AppControl>
	</Application>
* @endcode
*
* @code
	using namespace Osp::Base;
	using namespace Osp::Social;

	result
	MyClass::SomeMethod(void)
	{
		result r = E_SUCCESS;
		// Creates an instance of CustomField.
		CustomField customField;

		r = customField.SetTitle(L"TestApp");
		if (IsFailed(r)) {
			return r;
		}

		r = customField.SetAppControlInfo(L"osp.appcontrol.TEST://DEFAULT", null, null);
		if (IsFailed(r)) {
			return r;
		}

		return E_SUCCESS;
	}
* @endcode
* @endif
*/
class  _EXPORT_SOCIAL_ CustomField:
	public Osp::Base::Object
{
// Construct Operation
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
	 */
	CustomField(void);

	/**
	 * This is the copy constructor for the %CustomField class. @n
	 * This constructs an instance of %CustomField with the values of the specified instance.
	 *
	 * @since		2.0
	 * @param[in]	value	An instance of %CustomField
	 */
	CustomField(const CustomField& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~ CustomField(void);

public:
	/**
	 * Copies the data contained in the specified instance of %CustomField to the current instance.
	 *
	 * @since		2.0
	 * @param[in]	value	An instance of %CustomField
	 */
	CustomField& operator =(const CustomField& value);

	/**
	 * Checks whether the value of the specified instance of %CustomField is equal to the value of the current instance.
	 *
	 * @since		2.0
	 * @return		@c true if the value of the specified instance of %CustomField is equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %CustomField
	 */
	bool operator ==(const CustomField& rhs) const;

	/**
	 * Checks whether the value of the specified instance of %CustomField does not match the value of the current instance.
	 *
	 * @since 		2.0
	 * @return		@c true if the value of the specified instance of %CustomField is not equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %CustomField
	 */
	bool operator !=(const CustomField& rhs) const;

	// Operations
public:

	/**
	 * Sets the title of the custom field.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup 	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	title					The title to be set for the custom field
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c title is an empty string, or @n
	 *										the length of the specified @c title exceeds 100 characters.
	 */
	result SetTitle(const Osp::Base::String& title);

	/**
	 * Gets the title of the custom field.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup 	EXTERNAL_CONTACTS
	 *
	 * @return		The title of the custom field, @n
	 *				else an empty string if the title is not set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetTitle(void) const;

	/**
	 * Sets the description of the custom field.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup 	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	description				The description to be set for the custom field.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The length of the specified @c description exceeds 100 characters.
	 */
	result SetDescription(const Osp::Base::String& description);

	/**
	 * Gets the description of the custom field.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup 	EXTERNAL_CONTACTS
	 *
	 * @return		The description, @n
	 *				else an empty string if the description is not set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetDescription(void) const;

	/**
	 * Sets the URI, MIME type, and operation ID of the application control that is launched when the user touches this custom field in the Contacts base 
	 * application. @n
	 * The following forms of the URI are accepted: @n
	 * -# The URI with the well-known scheme such as http, mailto, and tel. @n
	 * -# The URI encoded in the bada-defined grammar to represent the AppControl ID and operation ID pair. @n
	 * Note that some operations that return a result are not supported. @n
	 * For more information, refer to the Osp::App::AppManager::StartAppControl(). @n
	 *
	 * This method is not supported with the following application controls provided by the platform: @n
	 * App::APPCONTROL_PROVIDER_AUDIO, App::APPCONTROL_PROVIDER_BLUETOOTH, App::APPCONTROL_PROVIDER_CALENDAR, App::APPCONTROL_PROVIDER_CAMERA, App::APPCONTROL_PROVIDER_CONTACT, App::APPCONTROL_PROVIDER_EMAIL, 
	 * App::APPCONTROL_PROVIDER_IMAGE, App::APPCONTROL_PROVIDER_MEDIA, App::APPCONTROL_PROVIDER_MESSAGE, App::APPCONTROL_PROVIDER_SIGNIN, App::APPCONTROL_PROVIDER_VIDEO,App::APPCONTROL_PROVIDER_BROWSER,
	 * App::APPCONTROL_PROVIDER_SETTINGS, App::APPCONTROL_PROVIDER_CALL.
	 *
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup 	EXTERNAL_CONTACTS
	 *
	 * @return		An error code
	 * @param[in]	uri						The URI
	 * @param[in]	pDataType				The MIME type (RFC 2046)
	 * @param[in]	pOperationId			The operation ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	 * 										- The length of the specified @c uri exceeds 1024 bytes. @n
	 * 										- The length of the specified @c pDataType exceeds 236 bytes. @n
	 * 										- The length of the specified @c pOperationId exceeds 236 bytes. @n
	 *										- At least one parameter of @c uri, @c pDataType, and @c pOperationId should have a non-empty literal.
	 * @remarks		In order to get the number of bytes of a string, use the Osp::Text::Encoding::GetByteCount(const Osp::Base::String& str, int& byteCount) 
	 *				method. @n
	 *				For the detailed description of the URI format, refer to the API reference of 
	 *				Osp::App::AppManager::FindAppControlsN(const Osp::Base::String& uri, const Osp::Base::String* pDataType, 
	 *				const Osp::Base::String* pOperationId, const IAppControlListener* pListener).
	 * @see			Osp::App::AppManager::StartAppControl
	 */
	result SetAppControlInfo(const Osp::Base::String& uri, const Osp::Base::String* pDataType, const Osp::Base::String* pOperationId);

private:
	Osp::Base::String	__title;
	Osp::Base::String	__description;
	Osp::Base::String	__uri;
	Osp::Base::String*	__pDataType;
	Osp::Base::String*	__pOperationId;

	friend class CustomFieldEx;
	class CustomFieldEx * __pCustomFieldEx;

}; // CustomField


};};// Osp::Social

#endif//_FSCL_CUSTOM_FIELD_H_


