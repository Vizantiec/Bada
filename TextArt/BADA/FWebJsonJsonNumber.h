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
 * @file		FWebJsonJsonNumber.h
 * @brief		This is the header file for the %JsonNumber class.
 *
 * This header file contains the declarations of the %JsonNumber class.
 * The class represents the JSON value of type number.
 *
 */


#ifndef _FWEBJSON_JSON_NUMBER_H_
#define _FWEBJSON_JSON_NUMBER_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonNumber
 * @brief	This class represents the JSON value of type number.
 * @since	2.0
 *
 * The %JsonNumber class represents the type of the JSON number.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.

 * 
 */
class _EXPORT_WEB_ JsonNumber : public IJsonValue, public Osp::Base::Double
{
public:
	/**
	 * Initializes this instance of %JsonNumber with the specified parameter.
	 *
	 * @since	2.0
	 * @param[in]	value 	The value of type double
	 */
	JsonNumber(double value=0.0L);

	/**
	 * Initializes this instance of %JsonNumber with the specified parameter.
	 *
	 * @since	2.0
	 * @param[in]	value 	The value of type integer
	 */
	JsonNumber(int value);

	/**
	 * This is the copy constructor for the %JsonNumber class. @n
	 * This constructor initializes a new instance of the %JsonNumber class with the value from another instance.
	 *
	 * @since			2.0
	 * @param[in]	value 	An instance of JsonNumber
	 */
	JsonNumber(const JsonNumber& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonNumber(void);

// Operator
public:
	/**
	* Assigns the value of the specified instance of %JsonNumber to the current instance of %JsonNumber.
	*
	* @since		2.0
	* @param[in]	rhs	An instance of %JsonNumber
	*/
	JsonNumber& operator =(const JsonNumber& rhs);

public:
	/**
	 * Gets the type of JSON number.
	 *
	 * @since		2.0
	 * @return     The type of JSON number
	 * @see 		JsonType
	 */
	JsonType GetType(void) const;

private:
	friend class JsonNumberEx;
	class JsonNumberEx* __pJsonNumberEx;
};

}; };};
#endif /* _FWEBJSON_JSON_NUMBER_H_ */
