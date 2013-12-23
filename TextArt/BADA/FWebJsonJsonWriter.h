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
 * @file		FWebJsonJsonWriter.h
 * @brief		This is the header file for composing a JSON-encoded file.
 *
 * This header file contains the declarations of JSON functionalities for composing JSON-encoded file.
 */
 
 
#ifndef _FWEBJSON_JSON_WRITER_H_
#define _FWEBJSON_JSON_WRITER_H_

#include "FBaseErrorDefine.h"
#include "FWebJsonIJsonValue.h"


namespace Osp { namespace Web { namespace Json {

/**
 * @class	JsonWriter
 * @brief	This class contains the declarations of the JSON functionalities for composing JSON-encoded file.
 * @since	2.0
 *
 * The %JsonWriter class contains declarations of JSON functionalities for composing JSON-encoded files.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to use %JsonWriter methods.
 * 
 * @code
 *	#include <FWebJson.h>
 *	using namespace Osp::Base;
 *	using namespace Osp::Web::Json;
 *	
 *	void
 *	MyClass::JsonWriterSample(void)
 *	{
 *		String *pKey1 = new String(L"Key1");
 *		String *pKey2 = new String(L"Key2");
 *		JsonString *pJsonValue1 = new JsonString(L"Value1");
 *		JsonString *pJsonValue2 = new JsonString(L"Value2");
 *		JsonObject *pJsonObject = new JsonObject();
 *		pJsonObject->Construct();
 *		pJsonObject->Add(pKey1, pJsonValue1);
 *		pJsonObject->Add(pKey2, pJsonValue2);
 *
 *		//Compose To a File
 *		String fileName(L"/Home/JsonComposeSample.json");
 *		result r = JsonWriter::Compose( pJsonObject, fileName );
 *		if( r != E_SUCCESS )
 *		{
 *			AppLog("Compose failed");
 *		}
 *
 *		//compose to char*
 *		char* pComposeBuf = new char[40];
 *		r = JsonWriter::Compose( pJsonObject, pComposeBuf, 40 );
 *
 *		//compose to bytebuffer
 *		ByteBuffer *pBuffer = new ByteBuffer();
 *		r = JsonWriter::Compose(pJsonObject, *pBuffer);
 *
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *		delete pBuffer;
 *	}
 * @endcode
 */
class _EXPORT_WEB_ JsonWriter
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	JsonWriter(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~JsonWriter(void);

public:
	/**
	 * Serializes the JSON-encoded data from %IJsonValue to a file.
	 *
	 * @since			2.0
	 * @param[in] 		pValue				JSON value to be encoded.
	 * @param[out] 	    filePath            The JSON file path
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null. 
	 * @exception		E_INVALID_ARG		The specified @c filePath is incorrect.
	 * @exception		E_FAILURE			The method has failed.
	 */
	static result Compose(const IJsonValue* pValue, Osp::Base::String& filePath);

	/**
	 * Serializes the JSON-encoded data from %IJsonValue to a buffer
	 *
	 * @since			2.0
	 * @param[in] 		pValue 				JSON value to be encoded.
	 * @param[in]		bufferLength		Json encoded data buffer length.
	 * @param[out] 		pBuffer 			The buffer with Json encoded data.
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @exception		E_FAILURE		    The method has failed.
	 */
	static result Compose(const IJsonValue* pValue, void* pBuffer, int bufferLength);

	/**
	 * Serializes the JSON-encoded data from %IJsonValue to %ByteBuffer.
	 *
	 * @since			2.0
	 * @param[in] 		pValue 				JSON value to be encoded.
	 * @param[out] 		buffer              The buffer with JSON-encoded data
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null. 
	 * @exception		E_FAILURE		    The method has failed.
	 */
	static result Compose(const IJsonValue* pValue, Osp::Base::ByteBuffer& buffer);

private:
	friend class JsonWriterEx;
	class JsonWriterEx* __pJsonWriterEx;

};// End JsonWriter

}; };};
#endif // End _FWEBJSON_JSON_WRITER_H_
