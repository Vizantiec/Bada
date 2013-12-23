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
 * @file		FWebJsonJsonString.h
 * @brief		This is the header file for the %JsonString class.
 *
 * This header file contains the declarations of the %JsonStringclass.
 * The class represents the JSON value of type string.
 */
 

#ifndef _FWEBJSON_JSON_STRING_H_
#define _FWEBJSON_JSON_STRING_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonString
 * @brief	This class represents the JSON value of type string.
 * @since	2.0
 *
 * The %JsonString class represents the JSON value of type string.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.

 * 
 */
class _EXPORT_WEB_ JsonString : public IJsonValue, public Osp::Base::String
{
public:
	/**
	 * Initializes this instance of JsonString with the specified parameter.  
	 *
	 * @since		2.0
	 * @param[in]	pValue	A pointer to an array of UTF-8 characters
	 */
	JsonString(const char* pValue);

	/**
	 * Initializes this instance of JsonString with the specified parameter.  
	 *
	 * @since		2.0
	 * @param[in]	value	A reference to %String
	 */
	JsonString(const Osp::Base::String& value);

	/**
	 *	Initializes this instance of JsonString with the specified Unicode string.
	 *
	 *  @since		2.0
	 *  @param[in]	pValue		A pointer to an array of Unicode characters
	 */
	JsonString(const mchar* pValue);
	

	/**
	 * This is the copy constructor for the %JsonString class.
	 *
	 * @since		2.0
	 * @param[in]	rhs	An instance of JsonString
	 */
	JsonString(const Osp::Web::Json::JsonString& rhs);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonString(void);

//operator
public:
	/**
	 * 	Copies the text from the specified instance of %JsonString to the current instance of %JsonString.
	 *
	 * @since		2.0
	 * @param[in]	rhs A reference to the %JsonString instance to copy
	 */
	JsonString& operator=(const Osp::Web::Json::JsonString& rhs);

public:
	/**
	 * Gets the type of the JSON string.
	 *
	 * @since		2.0
	 * @return 	    The type of the JSON string
	 * @see 		JsonType
	 */
	JsonType GetType(void) const;
	
private:
	friend class JsonStringEx;
	class JsonStringEx* __pJsonStringEx;
};

}; };};
#endif /* _FWEBJSON_JSON_STRING_H_ */
