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
 * @file		FWebJsonJsonArray.h
 * @brief		This is the header file for the %JsonArray class.
 *
 * This header file contains the declarations of the %JsonArray class.
 */


#ifndef _FWEBJSON_JSON_ARRAY_H_
#define _FWEBJSON_JSON_ARRAY_H_

#include "FWebJsonIJsonValue.h"

namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonArray
 * @brief	This class represents the JSON value of type array.
 * @since	2.0
 *
 * The %JsonArray class represents the JSON value of type array.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to create and initialize a %JsonArray instance and how to use its methods.
 *
 * @code
 *	#include <FWebJson.h>
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Collection;
 *	using namespace Osp::Web::Json;
 *	
 *	void
 *	MyClass::JsonArraySample(void)
 *	{
 *		//create JsonArray
 *		JsonArray *pJsonArray = new JsonArray();
 *		pJsonArray->Construct();//constrcut must be called for JsonArray
 *
 *		//create Values
 *		JsonString 	*pJsonstr 	= new JsonString(L"myname");
 *		JsonNumber 	*pJsonNum 	= new JsonNumber(99);
 *		JsonBool 	*pJsonBool 	= new JsonBool(true);
 *
 *		//Adding values to JsonArray
 *		pJsonArray->Add(pJsonstr); //For string
 *		pJsonArray->Add(pJsonNum); //For Number
 *		pJsonArray->Add(pJsonBool); //For Boolean 
 *
 *		IJsonValue* pValue = null;
 *		// Get a value at given position(index) in JsonArray
 *		pJsonArray->GetAt(0, pValue);
 *		JsonString *pJsonstrcheck = new JsonString(L"myname");
 *		int index;
 *		// find index of a given value in JsonArray
 *		pJsonArray->IndexOf(pJsonstrcheck, index); 
 *
 *		// Usage of enumerator to access elements in the JsonArray
 *		IEnumeratorT<IJsonValue*>* pEnum = pJsonArray->GetEnumeratorN();
 *		if(pEnum)
 *		{ 
 *			while( pEnum->MoveNext() == E_SUCCESS )
 *			{
 *				IJsonValue* pJsonValue = null;
 *				pEnum->GetCurrent( pJsonValue );//use pJsonValue
 *			}
 *			delete pEnum;
 *		} 
 *		pJsonArray->RemoveAt(index,true);//value in JsonArray is removed with memory deallocation
 *		pJsonArray->RemoveAll(true);//all remaining values are removed with memory deallocation
 *		delete pJsonArray;
 *	}
 * @endcode
 */
class _EXPORT_WEB_ JsonArray : public IJsonValue, public Osp::Base::Collection::ArrayListT<IJsonValue*>
{
public:
	/**
	 * This is the default constructor for this class.  
	 *
	 * @since	2.0
	 */
	JsonArray(void);

	/**
	 * This is the destructor for this class.  
	 *
	 * @since	2.0
	 */
	virtual ~JsonArray(void);

	/**
	 * Initializes this instance of JsonArray.
	 *
	 * @since		2.0
	 * @return 		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_OPERATION	This instance has already been constructed.
	 */	
	result Construct(void);

public:

	/**
	 * Returns the type of this class. @n
	 * In this case, it is always @c JSON_ARRAY.
	 *
	 * @since	2.0
	 * @return 		The JSON type
	 * @see 	JsonType
	 */
	JsonType GetType(void) const;
	
	/**
	 * Adds the specified element to the end of the list.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue		A pointer to %JsonValue that is to be added to the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see			Remove()
	 */
	virtual result Add(IJsonValue* const&pJsonValue);
	
	/**
	 * Searches for an element in this list. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be located
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */	
	virtual result IndexOf(IJsonValue* const&pJsonValue, int& index) const;
	
	/**
	 * Searches for an element starting from the specified index. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be located
	 * @param[in]	startIndex	The starting index for the search @n
	 *									It must be less than the number of elements in the array.
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or the specified @c startIndex is either equal to or greater than the number of elements or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf( IJsonValue* const&pJsonValue, int startIndex, int& index) const;
	
	/**
	 * Searches for an element within the specified range. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be located
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count				The number of elements to be read
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The specified index is outside the bounds of the data structure. @n
	 *									- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *									- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf( IJsonValue* const&pJsonValue, int startIndex, int count, int& index) const;
	
	/**
	 * Searches for the last occurrence of an element in this list. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be located
	 * @param[out]	index				The index of the last occurrence of the specified element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pJsonValue is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf( IJsonValue* const&pJsonValue, int& index) const;
	
	/**
	 * Checks whether the list contains the specified @c JsonValue.
	 *
	 * @since	 	2.0
	 * @return		@c true if the specified @c JsonValue is present in the list, @n
	 *				else @c false
	 * @param[in]	pJsonValue 		A pointer to the %JsonValue class to be located
	 */
	virtual bool Contains( IJsonValue* const&pJsonValue) const;
	
	/** 
	 * Checks whether the value of the specified instance equals the value of the current instance of @c JsonArray.
	 *
	 *	@since		2.0
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj			The element to be compared with the current instance of @c JsonArray
	 * @remarks 	The method returns @c false if the specified element is not @c JsonArray.
	 *  @see		Object::Equals()
	 */	 
	virtual bool Equals(const Object& obj) const;

	/**
	 * Removes the first occurrence of the specified element.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be removed
	 * @param[in]	deallocate			Set to @c true to deallocate the @c JsonValue, @n
	 * 									else @c false	 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			Add(), RemoveAt(), RemoveAll()
	 */	
	virtual result Remove(IJsonValue* const&pJsonValue, bool deallocate = false);	
	
	/**
	 * Removes all the elements of the specified collection from the list.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	collection 		The collection to be removed from this list
	 * @param[in]	deallocate				Set to @c true to deallocate the @c JsonValues, @n
	 * 										else @c false	 	 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c collection is modified during the operation of this method.
	 */
	virtual result  RemoveItems (const Osp::Base::Collection::ICollectionT< IJsonValue* > &collection, bool deallocate = false);
	
	/**
	 * Removes an element from the specified location.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	index 					The index of the element to be removed
	 * @param[in]	deallocate				Set to @c true to deallocate the @c JsonValue, @n
	 * 										else @c false	 	 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or the specified @c index is greater than or equal to the number of elements or less than @c 0.
	 * @remarks		The elements that follow the deleted element move up the list to occupy the empty location.
	 */	
	virtual result  RemoveAt (int index, bool deallocate = false);	
	
	/**
	 * Removes all the elements within a specified range.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to remove
	 * @param[in]	deallocate				Set to @c true to deallocate the JsonValue, @n
	 * 										else @c false	 	 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds. @n
	 *										- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The elements that follow the deleted elements move up the list to occupy the empty locations.
	 */
	virtual result  RemoveItems (int startIndex, int count, bool deallocate = false);
	
	/**
	 * Removes all the elements in the %JsonArray class.
	 *
	 * @since	 2.0
	 * @param[in]	deallocate		Set to @c true to deallocate all the elements, @n
	 * 								else @c false		 
	 */
	virtual void    RemoveAll (bool deallocate = false);  
	
	/**
	 * Replaces the element at the specified index with the specified element.
	 *
	 * @since	 	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be set
	 * @param[in]	index				The index at which the element should be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.		 
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(IJsonValue* const&pJsonValue, int index);
	
	/**
	 * Replaces the element at the specified index with the specified element.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be set
	 * @param[in]	index				The index at which the element should be set
	 * @param[in]	deallocate			Set to @c true to deallocate the @c JsonValue, @n
	 * 									else @c false	 	 
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.		 
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(IJsonValue* const&pJsonValue, int index, bool deallocate);

private:
	
	/*
	 * Copy constructor
	 */	 
	JsonArray(const JsonArray& item);	

	/*
	 * Assign operator
	 */	 
	JsonArray& operator =(const JsonArray& item);	

private:
	friend class JsonArrayEx;
	class JsonArrayEx* __pJsonArrayEx;
};

}; };};
#endif /* _FWEBJSON_JSON_ARRAY_H_ */
