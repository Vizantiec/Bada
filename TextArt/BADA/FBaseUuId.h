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
 * @file		FBaseUuId.h 
 * @brief		This is the header file for the %UuId class.
 *
 * This header file contains the declarations of the %UuId class.
 */
#ifndef _FBASE_UUID_H_
#define _FBASE_UUID_H_

// Includes
#include "FBaseConfig.h"
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseString.h"

#ifndef ClassId
#define ClassId	UUID
#endif 

namespace Osp { namespace Base { 
/**
 * @class	UuId
 * @brief	This class is the base class of the wrapped UUID types and provides useful operators.
 * @since	1.0
 * 
 * The %UuId class is the base class of the wrapped UUID types and provides useful operators. The UUID structure consists of 32 hexadecimal digits displayed in 5 groups separated by hyphens to form a total of 36 characters (32 digits and 4 hyphens '-'). 
 * The 5 groups in the UUID structure are represented as 8-4-4-4-12 with each number representing the number of hexadecimal digits in the group as follows:
 *
 * @code
 *
 * typedef struct
 *	{
 *		unsigned long x;
 *		unsigned short s1;
 *		unsigned short s2;
 *		unsigned char  c[8];
 *	} UUID;
 * @endcode
 *
 * It also provides operators for assignment and equality, and methods for parsing, comparing, and generalization.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/base_namespace.htm">Base Guide</a>.
 *
 * The following example demonstrates how to use the %UuId class.
 *
 * @code
 *
 * #include <FBase.h>
 *
 * using namespace Osp::Base;
 *
 * void
 * MyClass::UuIdSamples(void)
 * {
 *		UuId uuid;
 *		String str(L"A02D0DA1-80A0-4E73-B61F-793263C029EE");
 *		String uuidStr_upper
 *		UuId::Parse(str, uuid);		// UuId = A02D0DA1-80A0-4E73-B61F-793263C029EE
 *		
 *		String uuidStr = uuid.ToString();
 *		uuidStr.ToUpper(uuidStr_upper);
 *		
 *		if (str.Equals(uuidStr_upper))	// true
 *		{
 *			...
 *		}
 *
 * }
 * @endcode
 */
class _EXPORT_BASE_ UuId :
	public Object
{

// life-cycle
public:
	/**
	 * This is the default constructor for this class. @n
	 * The %UuId is set to @c 0.
	 *
	 * @since	1.0
	 */
	UuId(void);


	/**
	 * This is the copy constructor for the %UuId class.
	 *
	 * @since			1.0
	 * @param[in] uuid		An instance of %UuId
	 */
	UuId(const UuId& uuid);

	/**
	 * Initializes an instance of %UuId with the value of the specified UUID.
	 *
	 * @since			1.0
	 * @param[in] uuid		An instance of UUID
	 */
	UuId(const UUID& uuid);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~UuId(void);


// Operators
public:

	/** 
	 * This operator checks if the specified instance of %UuId is equal to the specified UUID.
	 *
	 * @since			1.0
	 * @return		@c true if the UUID and the %UuId instance are equal, @n
					else @c false
	 * @param[in]	uuid1		An instance of UUID
	 * @param[in] uuid2		An instance of %UuId
	 */
	_EXPORT_BASE_ friend bool operator==(const UUID& uuid1, const UuId& uuid2);
	
	/**
	 * This operator checks if the current instance of %UuId is equal to the specified instance of %UuId.
	 *
	 * @since			1.0
	 * @return		@c true if the two IDs are equal, @n
					else @c false
	 * @param[in]	uuid		An instance of %UuId
	 */
	bool operator==(const UuId& uuid) const;

	/**
	 * This operator checks if the specified instance of %UuId is not equal to the specified UUID.
	 *
	 * @since			1.0
	 * @return		@c true if the two IDs are not equal, @n
					else @c false
	 * @param[in]	uuid1		An instance of UUID
	 * @param[in] uuid2		An instance of %UuId
	 */
	_EXPORT_BASE_ friend bool operator!=(const UUID& uuid1, const UuId& uuid2);
	

	/**
	 * This operator checks if the current instance of %UuId is not equal to the specified instance of %UuId.
	 * 
	 * @since			1.0
	 * @return		@c true if the two IDs are not equal, @n
					else @c false
	 * @param[in]	uuid		An instance of %UuId
	 */
	bool operator!=(const UuId& uuid) const;

	/**
	 * This operator assigns the value of the specified instance of %UuId to the current instance of %UuId.
	 *
	 * @since			1.0
	 * @return		A reference to the current instance
	 * @param[in]	uuid		An instance of %UuId
	 */
	UuId& operator=(const UuId& uuid);


// Operations
public:
	/** 
	 *	Checks whether the specified instance of Object is equal to the current instance of %UuId.
	 *
	 *  @since		1.0
	 *	@return		@c true if the specified instance of %Object is equal to the current instance of %UuId, @n
	 *				else @c false
	 *	@param[in]	obj	An instance of %Object to compare
	 *	@remarks 	This method can be overridden to support value equality. Furthermore, the method must return the same result as the equality operator.
	 *	@see			Osp::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;

	/** 
	 *	Gets the hash value of the current instance of %UuId.
	 *
	 *  @since		1.0
	 *	@return		The integer value equivalent of the hash value of the current instance of %UuId
	 *	@remarks 	Two equal instances should return the same hash value. For better performance, 
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@par
	 *				The default implementation of this method returns the value of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/** 
	 *	Gets the string representing the value of the current instance when implemented by a class. 
	 *
	 *  @since		1.0
	 *	@return		An instance of the String class with the unicode representation of the value of the current instance @n
	 *				If an error such as E_OUT_OF_MEMORY occurs, an empty string is returned.
	 */
	String ToString(void) const;

	/**
	 * 	Gets the UUID of the %UuId instance.
	 *
	 *  @since		1.0
	 * 	@return		The UUID
	 */
	UUID ToUUID(void) const;


// static 
	/**
	 * Parses the specified string representing a %UuId value.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str			A string representing the %UuId value
     * @param[out]	uuid		An instance of %UuId
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The string does not contain an %UuId that can be parsed.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks	The format of a string representing a %UuId value is xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx. (ex.130DF2EC-8233-4975-B03D-F0AD99E3449D)
	 */
	static result Parse(const String& str, UuId& uuid);


// Attribute
public:
	/**
	 * This attribute is pre-defined. Its value is an invalid UUID.
	 *
	 * @since	1.0
	 */
	static const UuId INVALID_UUID;

	/**
     * @internal
     * This variable is for internal use only. The bada platform team is not 
     * responsible for any behavioral correctness, consistency, and 
     * security-related issues that might arise after using this method.
     *
     * @since    1.0
     */
	UUID __uuid;


private:
	friend class UuIdEx;
	class UuIdEx* __pUuIdEx;

}; // UuId
};}; // Osp::Base

#endif 

