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
 * @file		FWebJsonJsonParser.h
 * @brief		This header file for the %JsonParser class.
 *
 * This header file contains the declarations of the JSON functionalities for parsing the JSON-encoded file.
 */

 
#ifndef _FWEBJSON_JSON_PARSER_H_
#define _FWEBJSON_JSON_PARSER_H_

#include "FWebJsonIJsonValue.h"


namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonParser
 * @brief	This class contains the declarations of JSON functionalities for parsing JSON-encoded file.
 * @since	2.0
 *
 * The %JsonParser class contains the declarations of the JSON functionalities for parsing JSON-encoded files.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to use %JsonParser methods.
 * 
 * @code
 *
 * Sample Data - JsonSample.json 
 *	{"List": {
 *				"debug": "on",
 *				"window": {
 *							"title": "Is an Icon List",
 *							"name": "main_window",
 *							"width": 500,
 *							"height": 500
 *						},
 *				"image": { 
 *							"src": "Images/fun.png",
 *							"name": "fun1"
 *						},
 *				"text": {
 *							"data": "Click Here",
 *							"size": 36,
 *							"style": "bold",
 *							"name": "text1"
 *						},
 *				"properties": [
 *								{"alignment" : "center"},
 *								{"transperancy":"80"}
 *							]
 *	}}
 * 
 *	#include <FWebJson.h>
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *	using namespace Osp::Web::Json;
 *
 *	void
 *	MyClass::JsonParserSample(void)
 *	{
 *		//Parse from a File
 *		String fileName(L"/Home/JsonSample.json");
 *		IJsonValue* pValue = JsonParser::ParseN(fileName);
 *		if( pValue == null )
 *		{
 *			AppLog("ErrorCode %s", GetLastResult());
 *		}
 *		else
 *		{
 *			//use pValue to know what is the type
 *			if( pValue->GetType() == JSON_TYPE_OBJECT )
 *			{
 *				JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);//use pJsonObj to access key-value pairs
 *				pJsonObj->RemoveAll(true);
 *			}
 *			else if( pValue->GetType() == JSON_TYPE_ARRAY )
 *			{
 *				JsonArray* pJsonArray = static_cast<JsonArray*>(pValue);//use pJsonArray to access values
 *				pJsonArray->RemoveAll(true);
 *			}
 *			delete pValue;
 *		}
 *
 *		//Parse from char*
 *		const char* jBuf = "{\"Key\":1,\"Key1\":{\"Key2\":\"val\",\"Key3\":\"val1\"},\"Key4\":[\"val2\",\"val3\"]}";
 *		String str(jBuf);
 *		int length = str.GetLength();
 *		IJsonValue* pValue1 = JsonParser::ParseN(jBuf, length);
 *		JsonObject* pJsonObject = static_cast<JsonObject*>(pValue1);//we know it is a JsonObject
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *
 *		//Parse from bytebuffer
 *		ByteBuffer *pBuf = StringUtil::StringToUtf8N( str );
 *		IJsonValue* pValue2 = JsonParser::ParseN(*pBuf);
 *		pJsonObject = static_cast<JsonObject*>(pValue2);//we know it is a JsonObject
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *		delete pBuf;
 *	}
 * @endcode
 */
class _EXPORT_WEB_ JsonParser
{
public:
	/**
	 * This is the default constructor for this class.  
	 *
	 * @since	2.0
	 */
	JsonParser(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonParser(void);

public:
	/**
	 * Parses a JSON-encoded file to IJsonValue (node).
	 *
	 * @since			2.0
	 * @param[in] filePath                 The path of the JSON-encoded file
	 * @return 	                           A JSON value of type JsonArray or JsonObject, @n
	 *                                     else @c null if the JSON data of the file is invalid
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified file path is incorrect, or the file is not found.	 
	 * @exception	E_INVALID_DATA			The input JSON data is invalid.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.	 
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const Osp::Base::String& filePath);

	/**
	 * Parses a JSON-encoded buffer to %IJsonValue (node).
	 *
	 * @since			2.0
	 * @param[in] pBuffer              A JSON-encoded buffer
	 * @param[in]	bufferLength	   A JSON-encoded buffer length
	 * @return 	                       A JSON value of type JsonArray or JsonObject, @n	
	 *                                 else @c null if the JSON data of the file is invalid
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_DATA			The input JSON data is invalid, or the buffer is empty.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.	 
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const void* pBuffer, int bufferLength);

	/**
	 * Parses a JSON-encoded ByteBuffer to IJsonValue (node).
	 *
	 * @since			2.0
	 * @param[in] buffer                       A JSON-encoded byte buffer
	 * @return 	                              A JSON value of type JsonArray or JsonObject, @n
	 *                                        else @c null if the JSON data of the file is invalid
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_DATA			The input JSON data is invalid, or the buffer is empty.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.	 
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const Osp::Base::ByteBuffer& buffer);

private:
	friend class JsonParserEx;
	class JsonParserEx* __pJsonParserEx;
	
};

}; };};
#endif // End _FWEBJSON_JSON_PARSER_H_
