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
 * @file	FSclAddress.h
 * @brief	This is the header file for the %Address class.
 *
 * This header file contains the declarations of the %Address class.
 */
#ifndef _FSCL_ADDRESS_H_
#define _FSCL_ADDRESS_H_

// Includes
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {  

// Enums and Constants
/**
* Defines the types of the address.
*
* @since	1.0
*/
enum AddressType {
	ADDRESS_TYPE_HOME,		/**< The home address */
	ADDRESS_TYPE_WORK,		/**< The work address */	
	ADDRESS_TYPE_OTHER		/**< The other address*/
};

/** The maximum length of the extended field. 
*
* @since	1.0
*/
static const int MAX_ADDR_EXTENDED_LENGTH		= 50;
/** The maximum length of the street field. 
*
* @since	1.0
*/
static const int MAX_ADDR_STREET_LENGTH			= 50;
/** The maximum length of the city field. 
*
* @since	1.0
*/
static const int MAX_ADDR_CITY_LENGTH			= 50;
/** The maximum length of the state field. 
*
* @since	1.0
*/
static const int MAX_ADDR_STATE_LENGTH			= 50;
/** The maximum length of the postal code field. 
*
* @since	1.0
*/
static const int MAX_ADDR_POSTAL_CODE_LENGTH	= 20;
/**
 * @deprecated	This constant is deprecated because the maximum length of the country name has been changed.
 *
 * The maximum length of the country field.
 *
 * @since 1.0
 */
static const int MAX_ADDR_COUNTRY_LENGTH		= 20;
/**
 * The maximum length of the post office box number field.
 *
 * @since 1.0
 */
static const int MAX_ADDR_POBOXNUM_LENGTH		= 20;

/**
 * @class	Address
 * @brief	This class represents the structured address type representing the ADR type definition of the vCard.
 *			It is based on the MIME directory profile specification (RFC 2426).
 * @since	1.0
 *
 * The %Address class represents the structured address type representing the ADR type definition of the vCard.
 *	It is based on the MIME directory profile specification (RFC 2426).
 * The address information consists of country, city, state, street, post office box number, postal code, and the address type.
 * This class represents the structured address type representing the ADR type definition of the vCard.
 * It is based on the MIME directory profile specification (RFC 2426).
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/addressbook_namespace.htm">Address Book</a>.
 */
class  _EXPORT_SOCIAL_ Address:
	public Osp::Base::Object
{
// Construct Operation
public:
	/**
	 * This is the default constructor for this class. @n
	 * It creates a fully initialized instance of the %Address class.
	 *
	 * @since	1.0
	 */
	Address(void);

	/**
	* This is the copy constructor for the %Address class. 
	*
	* @since 		1.0
	* @param[in]	address		An instance of %Address
	*/
	Address(const Address& address);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	~Address(void);

// Operators
public:
	/**
	* This operator copies the data contained in the specified instance of %Address to the current instance.
	*
	* @since 		1.0
	* @param[in]	rhs		The source instance of %Address
	*/
	Address& operator =(const Address& rhs);

	/**
	* Compares the specified instance of %Address with the calling instance.
	*
	* @since 		1.0
	* @return		@c true if the data of the specified instance is equal to the data of the current instance, @n
	*				else @c false
	* @param[in]	rhs		The source data
	*/
	bool operator ==(const Address& rhs) const;

	/** 
	* Compares the specified instance to the calling instance for inequality.
	*
	* @since 		1.0
	* @return		@c true if the data of the specified instance is not equal to the data of the current instance, @n
	*				else @c false
	* @param[in]	rhs		The source data
	*/
	bool operator !=(const Address& rhs) const;


// Get/Set operation
public:
	/**
	* Gets the type the address.
	*
	* @since 		1.0
	* @return		The type of the address
	*/
	AddressType GetType(void) const;

	/**
	 * Gets the extended field of the address.
	 *
	 * @since 		1.0
	 * @return		The extended field of the address
	 */
	Osp::Base::String GetExtended(void) const;
	
	/**
	 * Gets the street of the address.
	 *
	 * @since 		1.0
	 * @return		The street of the address
	 */
	Osp::Base::String GetStreet(void) const;
	
	/**
	 * Gets the city of the address.
	 *
	 * @since 		1.0
	 * @return		The city of the address
	 */
	Osp::Base::String GetCity(void) const;
	
	/**
	 * Gets the state of the address.
	 *
	 * @since 		1.0
	 * @return		The state of the address
	 */
	Osp::Base::String GetState(void) const;
	
	/**
	 * Gets the postal code of the address.
	 *
	 * @since 		1.0
	 * @return		The postal code of the address
	 */
	Osp::Base::String GetPostalCode(void) const;
	
	/**
	 * Gets the country of the address.
	 *
	 * @since 				1.0
	 * @compatibility		This class has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 						For more information, see @ref CompAddressGetCountryPage "here".
	 *
	 *
	 * @return		The country of the address
	 */
	Osp::Base::String GetCountry(void) const;

	/**
	 * @page	CompAddressGetCountryPage	Compatibility for GetCountry()
	 * @section	CompAddressGetCountryPageIssueSection	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the length of the country name is greater than 20 characters, only the first 20 characters are returned.
	 *
	 * @section	CompAddressGetCountryPageSolutionSection	Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * 
	 */

	/**
	 * Gets the post office box number of the address.
	 *
	 * @since 		1.0
	 * @return		The post office box number of the address
	 */
	Osp::Base::String GetPostOfficeBoxNumber(void) const;

	/**
	* Sets the type of the address.
	*
	* @since 		1.0
	* @param[in]	type	The address type to be set
	* @see  		AddressType()
	*/
	void SetType(AddressType type);

	/**
	 * Sets the extended field of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	extended		The new extended value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c extended exceeds #MAX_ADDR_EXTENDED_LENGTH.
	 */
	result SetExtended(const Osp::Base::String& extended);
	
	/**
	 * Sets the street of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	street			The new street value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c street exceeds #MAX_ADDR_STREET_LENGTH.
	 */
	result SetStreet(const Osp::Base::String& street);
	
	/**
	 * Sets the city of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	city			The new city value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c city exceeds #MAX_ADDR_CITY_LENGTH.
	 */
	result SetCity(const Osp::Base::String& city);
	
	/**
	 * Sets the state of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	state		    The new state value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c state exceeds #MAX_ADDR_STATE_LENGTH.
	 */
	result SetState(const Osp::Base::String& state);
	
	/**
	 * Sets the postal code of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	postalCode		The new postal code value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c postalCode exceeds #MAX_ADDR_POSTAL_CODE_LENGTH.
	 */
	result SetPostalCode(const Osp::Base::String& postalCode);
	
	/**
	 * Sets the country of the address.
	 *
	 * @since 			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref CompAddressSetCountryPage "here".
	 *
	 * @return		An error code
	 * @param[in]	country			The new country value to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The length of the specified @c country exceeds the maximum length. @n
	 * @remarks		The maximum length of the country name is 20 characters for bada API versions @b prior @b to @b 2.0, 
	 *				whereas it is 100 characters for bada API versions @b since @b 2.0.
	 */
	result SetCountry(const Osp::Base::String& country);

	/**
	 * @page	CompAddressSetCountryPage		Compatibility for SetCountry()
	 * @section	CompAddressSetCountryPageIssueSection		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the length of the country name to be set is greater than 20 characters, E_INVALID_ARG is returned.
	 *
	 * @section	CompAddressSetCountryPageSolutionSection		Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 * 
	 */

	/**
	 * Sets the post office box number of the address.
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	postOfficeBoxNumber		The new post office box number value to be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The length of the specified @c postofficeBoxNumber exceeds #MAX_ADDR_POBOXNUM_LENGTH.
	 */
	result SetPostOfficeBoxNumber(const Osp::Base::String& postOfficeBoxNumber);

private:
	AddressType		__type;
	Osp::Base::String	__extended;
	Osp::Base::String	__street;
	Osp::Base::String	__city;
	Osp::Base::String	__state;
	Osp::Base::String	__postalCode;
	Osp::Base::String	__country;
	Osp::Base::String	__postOfficeBoxNumber;
	
	friend class AddressEx;
	class AddressEx* __pAddressEx;
};

};};// Osp::Social

#endif//_FSCL_ADDRESS_H_

