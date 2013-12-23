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
 * @file		FWebJsonJsonBool.h
 * @brief		This header file for the %JsonBool class.
 *
 * This header file contains the declarations of the %JsonBool class.
 * The class represents the JSON value of type bool.
 */


#ifndef _FWEBJSON_JSON_BOOL_H_
#define _FWEBJSON_JSON_BOOL_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonBool
 * @brief	This class represents the JSON value of type bool.
 * @since	2.0
 *
 * The %JsonBool class represents the JSON value of type bool.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.
 * 
 * 
 */
class _EXPORT_WEB_ JsonBool : public IJsonValue, public Osp::Base::Boolean
{
public:
	/**
	 * Initializes this instance of %JsonBool with the specified parameter. 
	 *
	 * @since	2.0
	 * @param[in]	value 	The input bool value to initialize the %JsonBool object
	 */
	JsonBool(bool value);

	/**
	 *	Initializes a new boolean object to the input string represented by the 
	 *	@c value. If the input string is "true" (value is case insensitive), the object is initialized to @c true, 
	 *	else, the value is initialized to @c false.
	 *
	 * @since	2.0
	 *  @param[in]	value 	An instance of String
	 */
	JsonBool (const Osp::Base::String &value); 

	/** 
	 * Initializes this instance of %JsonBool with the specified parameter.

	 *
	 *  @since			2.0
	 * @param[in]	value 	A boolean value to initialize the %JsonBool instance
	 */
	JsonBool (const Boolean &value); 

	/** 
	 * This is the copy constructor for the %JsonBool class. @n
	 * Initializes a new instance of the %JsonBool class to the specified @c value.
	 *
	 *  @since			2.0
	 * @param[in]	value 	An instance of JsonBool
	 */
	JsonBool(const JsonBool& value);	

	/** 
	 * This is the destructor for this class.
	 *
	 *  @since			2.0
	 */
	virtual ~JsonBool(void);

// Operator
public:
	/**
	* Assigns the value of the specified instance of %JsonBool to the current instance of %JsonBool.
	*
	* @since		2.0
	* @param[in]	rhs	An instance of JsonBool
	*/
	JsonBool& operator =(const JsonBool& rhs);
	

public:
	/**
	 * Gets the type of this class (Always JSON_BOOL)
	 *
	 * @since		2.0
	 * @return  The JSON type
	 * @see 		JsonType
	 */
	JsonType GetType(void) const;	

private:
	friend class JsonBoolEx;
	class JsonBoolEx* __pJsonBoolEx;
};

}; };};
#endif /* _FWEBJSON_JSON_BOOL_H_ */
