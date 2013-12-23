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
 * @file		FLocAddressInfo.h 
 * @brief		This is the header file for the %AddressInfo class.
 *
 * This header file contains the declarations of the %AddressInfo class and the address field index.
 */

#ifndef	_FLOC_ADDRESS_INFO_H_
#define _FLOC_ADDRESS_INFO_H_


#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FLocRouteServicePreferences.h"

// Forward declaration
struct MAddressInfo;
//struct RouteServicePreferences;
namespace Osp { namespace Locations { 

/**
 * @enum	AddressField
 * Defines the field constants that can be used to retrieve the field data.
 *
 * @deprecated	This enumerated type is deprecated.
 * @since	1.0
 */
typedef enum {
	ADDRESS_FIELD_EXTENSION = 1,	/**< The address field denoting the address extension, such as a flat number*/
	ADDRESS_FIELD_STREET_NAME,		/**< The address field denoting the street name*/
	ADDRESS_FIELD_STREET_NUMBER,	/**< The address field denoting the street number*/
	ADDRESS_FIELD_POSTAL_CODE,		/**< The address field denoting the zip or postal code*/
	ADDRESS_FIELD_CITY,				/**< The address field denoting the town or city name*/
	ADDRESS_FIELD_COUNTY,			/**< The address field denoting a county, which is an entity between a state and a city*/
	ADDRESS_FIELD_STATE,			/**< The address field denoting the state or province*/
	ADDRESS_FIELD_COUNTRY,			/**< The address field denoting the country*/
	ADDRESS_FIELD_COUNTRY_CODE,		/**< The address field denoting the country as a two-letter =ISO 3166-1 alpha-2 code*/
	ADDRESS_FIELD_DISTRICT,			/**< The address field denoting a municipal district*/
	ADDRESS_FIELD_CROSSING1,		/**< The address field denoting a street in a crossing*/
	ADDRESS_FIELD_CROSSING2,		/**< The address field denoting a street in a crossing*/
	ADDRESS_FIELD_PHONE_NUMBER		/**< The address field denoting a phone number for this place*/
} AddressField;

/**
* @class	AddressInfo
* @brief	This class encapsulates textual address information about a location.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %AddressInfo class encapsulates textual address information about a location.
* Typically, the information is a street address divided into fields (such as street, postal code, and city). Defined field constants can be used 
* to retrieve the field data, and if the value of a field is not available, it is set to @c null. The names of the fields use terms and definitions 
* that are commonly used in the United States. Addresses for other countries must map these to the closest corresponding entities used in that 
* country. @n
* This class is only a container for the information. The GetField() method returns the value set for the defined field using the SetField() 
* method. When %AddressInfo instances are returned, only the instances where the parameter values are set as described in the class semantics are 
* returned. @n
* @{
*/
class _EXPORT_LOCATION_ AddressInfo :
public Osp::Base::Object{

// Lifecycle
public:	
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	AddressInfo(void);

	/**
	* This is the copy constructor for the %AddressInfo class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	AddressInfo(const AddressInfo& value);
	
	/**
	* Assigns the value of the specified %AddressInfo object to the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	AddressInfo& operator=(const AddressInfo& rhs);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual	~AddressInfo(void);

// Operations - Osp::Base::Object
public:

	/**
	* Overrides the Equals() method in the Object class to compare the equality of values in two AddressInfo objects.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if all the fields in the objects are equal, @n
	*				else @c false
	* @param[in]	obj		The object with which the comparison is made
	*
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

	
	/** 
	* Overrides the GetHashCode() method in the %Object class to generate the hash value of the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An integer value representing the hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

// Operations - Osp::Locations::AddressInfo
public:

   /**
	* Gets the value of the specified address field.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The value of the address field, @n
	*				else an empty string if the field is not set
	* @param[in]	field	The ID of the field to be retrieved
	*
	* @see			SetField()
	*/
	Osp::Base::String GetField(AddressField field) const;
	
	/**
	* Sets the specified value for the specified address field.
	*	
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	field			The ID of the address field to be set
	* @param[in]	value			The new value for the address field, @n
	*								else an empty string to indicate that the field has no content
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @see				GetField()
	*/
	result	SetField(AddressField field, const Osp::Base::String& value);

private:
	MAddressInfo* __pMAddressInfo;

/**
* @internal
{@
*/
private:
	//NOTE : ownership for pObject is transferred to the AddressInfo instance.
	AddressInfo(MAddressInfo* pObject);
	
	// no implementation. force to private

friend class Landmark;
friend class Location;
friend class LandmarkFilter;
friend class Services::RouteServicePreferences;

private:
	friend class AddressInfoEx;
	class AddressInfoEx* __pAddressInfoEx;
/**
* @}
*/

};	// class AddressInfo
/**
 * @}
 */

} }	// Osp::Location

#endif	// _FLOC_ADDRESS_INFO_H_
