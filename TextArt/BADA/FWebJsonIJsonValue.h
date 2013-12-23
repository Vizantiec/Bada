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
 * @file		FWebJsonIJsonValue.h
 * @brief		This is the header file for the %IJsonValue class for the JSON (generic) value.
 *
 * This header file contains the definition of basic JSON types and declarations for
 * getting the type of a JSON value.
 */

#ifndef _IJSON_VALUE_H_
#define _IJSON_VALUE_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web { namespace Json {
/**
 * @interface	IJsonValue
 * @brief	This class provides interface for basic JSON (generic) value.
 * @since	2.0
 *
 * The %IJsonValue class provides the interface for the JSON (generic) value.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.

 */

/**
 * @enum JsonType
 * Defines the JSON value types.
 *
 * @since	2.0
 */
enum JsonType
{
	JSON_TYPE_STRING,	/**< The JSON string type*/
	JSON_TYPE_NUMBER,	/**< The JSON number type*/
	JSON_TYPE_OBJECT,	/**< The JSON object type*/
	JSON_TYPE_ARRAY,	/**< The JSON array type*/
	JSON_TYPE_BOOL,	    /**< The JSON bool type*/
	JSON_TYPE_NULL	    /**< The JSON null type*/
};

class _EXPORT_WEB_ IJsonValue
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IJsonValue(void) {}

	/**
	 * Gets the type of the object contained.
	 *
	 * @since	 2.0
	 * @return   The JSON type
	 */
	virtual JsonType GetType(void) const = 0;

protected:	

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/
	virtual void IJsonValue_Reserved1 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IJsonValue_Reserved2 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IJsonValue_Reserved3 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IJsonValue_Reserved4 (void) {}

	/** 
	* @internal    This method is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security
	*
	* Following method is reserved and may change its name at any time without prior notice.
	* 
	* @since		2.0
	*/	
	virtual void IJsonValue_Reserved5 (void) {}	

};

}; };};
#endif // End _IJSON_VALUE_H_
