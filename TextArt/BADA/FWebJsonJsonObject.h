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
 * @file		FWebJsonJsonObject.h
 * @brief		This is the header file for the %JsonObject class.
 *
 * This header file contains the declarations of the %JsonObject class.
 * The class represents the JSON value of type object.
 */
 

#ifndef _FWEBJSON_JSON_OBJECT_H_
#define _FWEBJSON_JSON_OBJECT_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonObject
 * @brief	This class represents the JSON value of type object.
 * @since	2.0
 *
 * The %JsonObject class represents the JSON value of type object.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to create and initialize a %JsonObject instance and how to use its methods.
 *
 * @code
 *	#include <FWebJson.h>
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Collection;
 *	using namespace Osp::Web::Json;
 *
 *	void
 *	MyClass::JsonObjectSample(void)
 *	{
 *		//create Json Object
 *		JsonObject *pJsonObj = new JsonObject();
 *		pJsonObj->Construct();//constrcut must be called for JsonObject
 *
 *		//create Keys, pointer to string is Jsonkeytype
 *		String 	*pStrFNKey 		= new String(L"firstName");
 *		String 	*pStrAgeKey		= new String(L"age");
 *
 *		//Create Values, pointer to any JsonValue is valueType
 *		JsonString 	*pStrFNVal 		= new JsonString(L"John");
 *		JsonNumber	*pNumAge		= new JsonNumber(25);
 *
 *		//Adding key-value pair to object
 *		pJsonObj->Add(pStrFNKey, pStrFNVal); //For string
 *		pJsonObj->Add(pStrAgeKey, pNumAge); // For Number
 *
 *		IJsonValue* pValue = null;
 *		// Get a value with the specified key
 *		pJsonObj->GetValue(pStrFNKey, pValue);
 *
 *		// Use enumerator to access elements in the map
 *		const String* pKey = null;
 *		IMapEnumeratorT<const String*, IJsonValue*>*  pMapEnum = null;
 *		pMapEnum = pJsonObj->GetMapEnumeratorN(); 
 *		if( pMapEnum )
 *		{
 *			while (pMapEnum->MoveNext() == E_SUCCESS)
 *			{
 *				pMapEnum->GetKey(pKey);
 *				pMapEnum->GetValue(pValue);
 *			}
 *			delete pMapEnum; 
 *		}
 *		// Remove a value with the specified key
 *		pJsonObj->Remove(pStrAgeKey, true);//key-value pair removed with memory deallocation.
 *		pJsonObj->RemoveAll(true);//all remaining key-value pairs are removed with memory deallocation.
 *		delete pJsonObj;
 *	}
 * @endcode
 */
class _EXPORT_WEB_ JsonObject : public IJsonValue, public Osp::Base::Collection::HashMapT<const Osp::Base::String*, IJsonValue*>
{
public:
	/**
	 * This is the default constructor for this class.  
	 *
	 * @since	2.0
	 */
	JsonObject(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonObject(void);

	/**
	 * Initializes this instance of JsonObject.
	 *
	 * @since			2.0
	 * @return 		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_OPERATION	The Construct() method cannot be called twice.
	 */
	result Construct(void);

public:

	/** 
	 * Gets the type of the JSON object.
	 *
	 * @since		2.0
	 * @return 		The type of the JSON object
	 * @see 		JsonType
	 */
	JsonType GetType(void) const;

	/** 
	 * Adds the specified key-value pair to a JSON object.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key-value to add
	 * @param[in]	pJsonValue			A pointer to the value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c pKey already exists.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @see Remove()
	 */	
	virtual result Add(const Osp::Base::String* const&pKey, Osp::Web::Json::IJsonValue* const&pJsonValue);


	/** 
	 * Gets the value associated with a specified key.
	 *
	 * @since	 	2.0
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	pKey				A pointer to the key to locate
	 * @param[out]	pJsonValue			A pointer to the value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @see			SetValue()
	 */	
	virtual result GetValue(const Osp::Base::String* const&pKey, Osp::Web::Json::IJsonValue* &pJsonValue) const;
	
	/** 
	 * Checks whether a JSON object contains the specified value.
	 *
	 * @since	 	2.0
	 * @return		@c true if the JSON object contains the specified value, @n
	 *				else @c false
	 * @param[in]	pJsonValue A pointer to a value to locate
	 */
	virtual bool ContainsValue(IJsonValue* const&pJsonValue) const;
	
	/** 
	 *	Checks whether the value of the specified instance equals the value of the current instance of JsonObject.
	 *
	 *	@since		2.0
	 *	@return		@c true if the value of the current instance equals the value of the specified instance, @n
					else @c false
	 *	@param[in]	obj	The object to compare @n
	 *                  This object is compared with the current instance of %JsonObject.
	 *	@remarks 	This method returns @c false if the specified object is not of type JSON object.
	 *  @see		Object::Equals()
	 */	 
	virtual bool Equals(const Object& obj) const;
	
	/**
	 * Removes the value associated with a specified key.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pKey 				A pointer to the key to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 */	
	virtual result  Remove (const Osp::Base::String* const&pKey);
	
	/** 
	 * Removes the value associated with a specified key.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pKey 				A pointer to the key to remove
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 * 									else @c false	 	 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 */	
	virtual result  Remove (const Osp::Base::String* const&pKey, bool deallocate );
	
	/** 
	 * Removes all the key-value pairs in %JsonObject.
	 *
	 * @since	 2.0
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 * 									else @c false	 	 
	 */
	virtual void    RemoveAll (bool deallocate = false);
	
	/** 
	 * Sets a new value to a specified key.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key for which the value is to be replaced
	 * @param[in]	pJsonValue			A pointer to the new value to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 */
	virtual result  SetValue (const Osp::Base::String* const&pKey, Osp::Web::Json::IJsonValue* const&pJsonValue);	

	/** 
	 * Sets a new value to a specified key.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key for which the value is to be replaced
	 * @param[in]	pJsonValue			A pointer to the new value to be set
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 */
	virtual result  SetValue (const Osp::Base::String* const&pKey, Osp::Web::Json::IJsonValue* const&pJsonValue, bool deallocate);	
	
	/** 
	 * Checks whether a JSON object contains the specified key.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	pKey	The key to locate
	 * @param[out]	out 	@c true if the JSON object contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 */
	virtual result ContainsKey(const Osp::Base::String* const&pKey, bool& out) const;

private:
	
	/*
	 * Copy constructor
	 */	 
	JsonObject(const JsonObject& item);	

	/*
	 * Assign operator
	 */	 
	JsonObject& operator =(const JsonObject& item);	

private:
	friend class JsonObjectEx;
	class JsonObjectEx* __pJsonObjectEx;
};

}; };};
#endif /* _FWEBJSON_JSON_OBJECT_H_ */
