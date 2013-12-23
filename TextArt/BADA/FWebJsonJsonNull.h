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
 * @file		FWebJsonJsonNull.h
 * @brief		This is the header file for the %JsonNull class.
 *
 * This header file contains the declarations of the %JsonNull class.
 * The class represents the JSON value of type null.
 */


#ifndef _FWEBJSON_JSON_NULL_H_
#define _FWEBJSON_JSON_NULL_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonNull
 * @brief	This class represents the JSON value of type null.
 *  @since	2.0
 *
 * The %JsonNull class represents the JSON value of type null.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.

 *
 */
class _EXPORT_WEB_ JsonNull : public IJsonValue, public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. 
	 *
	 * @since	2.0
	 */
	JsonNull(void);

	/**
	 * This is the copy constructor for the %JsonNull class. @n
	 * Initializes a new instance of JsonNull to the specified @c value.
	 *
	 * @since	2.0
	 * @param[in]	value 	An instance of %JsonNull
	 */
	JsonNull(const JsonNull& value);
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonNull(void);

// Operator
public:

	/**
	 * Assigns the value of the specified instance of JsonNull to the current instance of JsonNull.
	 *
	 * @since		2.0
	 * @param[in]	rhs	An instance of JsonNull
	 */
	JsonNull& operator =(const JsonNull& rhs);
	
	/** 
	 *	Checks whether the values of the two %JsonNull objects are equal.
	 *
	 *	@since		2.0
	 *	@return			@c true if the values of the objects are equal, @n
					    else @c false
	 *	@param[in]	rhs		A JsonNull instance to compare with the current instance
	 */
	bool operator ==(const JsonNull& rhs) const;


	/** 
	 *	Checks whether the two %JsonNull objects are equal. 
	 *
	 *	@since		2.0
	 *	@return			    @c true if the values of the objects are not equal, @n
					        else @c false
	 *	@param[in]	rhs		A JsonNull instance to compare with the current instance
	 */
	bool operator !=(const JsonNull& rhs) const;

	/** 
	 *	Checks whether the value of the specified instance equals the value of the current instance.
	 *
	 *	@since		2.0
	 *	@return			             @c true if the value of the current instance equals the value of the specified instance, @n
					                 else @c false
	 *	@param[in]	obj	             The object to compare with the current instance of %JsonNull
	 *	@remarks 	                 The method returns @c false if the specified object is not %JsonNull.
	 *  @see		Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/** 
	 *	Gets the hash value of the current instance.
	 *
	 *	@since		2.0
	 *	@return		An integer value indicating the hash value of the current instance
	 *	@remarks 	The two equal instances should return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@par
	 *				The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;
	

public:
	/**
	 * Gets the type of the object (Always JSON_NULL)
	 *
	 * @since		2.0
	 * @return 	The JSON type
	 */
	JsonType GetType(void) const;

	/** 
	 *	Converts the value of the calling object from %JsonNull to a string. 
	 *
	 *	@since	2.0
	 *	@return	A string representing the value of the current instance.
	 */
	Osp::Base::String ToString(void) const;


private:
	friend class JsonNullEx;
	class JsonNullEx* __pJsonNullEx;
};

}; };};
#endif /* _FWEBJSON_JSON_NULL_H_ */
