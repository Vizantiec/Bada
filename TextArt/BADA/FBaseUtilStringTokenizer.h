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
 * @file		FBaseUtilStringTokenizer.h 
 * @brief		This is the header file for the %StringTokenizer class.
 *
 * @see			String() 
 *
 * This header file contains the declarations of the %StringTokenizer class. 
 */

#ifndef _FBASE_UTIL_STRING_TOKENIZER_H_
#define _FBASE_UTIL_STRING_TOKENIZER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseString.h"

namespace Osp { namespace Base { namespace Utility {
/**
 * @class	StringTokenizer
 * @brief	This class implements %StringTokenizer.
 * @since	1.0
 *
 * The %StringTokenizer class is used to break a String into tokens. It also provides ways to count the number of tokens. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/string_tokenizer.htm">String Tokenizer</a>.
 *
 * The following example demonstrates how to use the %StringTokenizer class.
 *
 * @code
 *	#include <FBase.h>
 *	
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Utility;
 *	
 *	void
 *	MyClass::StringTokenizerSample(void)
 *	{
 *		String str(L"Osp-StringTokenizer/Sample code");
 *		String delim(L" /-");
 *
 *
 *		// Create a StringTokenizer instance
 *		StringTokenizer strTok(str, delim);
 *		
 *		int count = strTok.GetTokenCount();		// count == 4
 *
 *		String token;
 *		while (strTok.HasMoreTokens())
 *		{
 *			strTok.GetNextToken(token);			// Osp, StringTokenizer, Sample, code
 *		}	
 *	
 *	}
 * @endcode
 *
 * 
 */

class _EXPORT_BASE_ StringTokenizer :
	public Object
{
// Lifecycle
public:
	/**
	 * Initializes an instance of %StringTokenizer with the specified parameters.
	 *
	 * @since			1.0
	 * @param[in]	value		An instance of %String to be parsed
	 * @param[in]	delimiters	The delimiters
	 * @param[in]	isToken		A flag indicating whether to return the delimiters as tokens @n
	 *							Set to @c true to treat the delimiters as tokens, @n
	 *							else @c false to skip the delimiters.
     * 							
	 */
	StringTokenizer(const String& value, const String& delimiters = L" \t\n\r\f", bool isToken = false);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 * @remarks		The internally allocated memory block is freed when the instance is destroyed.
	 */
	virtual ~StringTokenizer(void);


// Operation
public:
	/** 
	 * Counts the number of times the GetNextToken() method can be called before it returns an error code.
	 *
	 * @since			1.0
	 * @return		An integer value indicating the number of times the %GetNextToken() method can be called
	 */
	int GetTokenCount(void);
	
	/**
	 * Checks whether there are any more tokens in the string after the current position.
	 *
	 * @since			1.0
	 * @return		@c true if there is at least one more token in the string after the current position, @n
	 *				else @c false
	 */
	bool HasMoreTokens(void);

	/**
	 * Gets the next token from the string tokenizer.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[out]	token	The next token
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The string tokenizer has no more tokens.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result GetNextToken(String& token);

	
	/**
	 * Sets the new @c delimiters.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	delimiters	The new delimiters
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *
	 * The following example demonstrates how to use this method.
	 * 
	 * @code
	 *	
	 *	 String str(L"Osp-Framework-Utility::StringTokenizer/class");
	 *	 String delim(L":-");
	 *
	 *	 String token;
	 *
	 *	 StringTokenizer strTok(str, delim);
	 *
	 *	 for (int i = 0; i < 3; i++)
	 *		strTok.GetNextToken(token);				// Osp, Framework, Utility
	 *
	 *	 String newDelim(L"/");
	 *
	 *	 strTok.SetDelimeters(newDelim);
	 *	 strTok.GetNextToken(token);				// token == L"::StringTokenizer"
	 *
	 * @endcode
	 */	
	result SetDelimeters(const String &delimiters);


// Operation
private:

	/*
	 * Sets the maximum characters of delimiters.
	 *
	 * @return	An @c mchar value indicating the maximum characters
	 */
	mchar SetMaxDelimChar(void);

	/*
	 * Skips the delimiters starting from the specified position. 
	 *
	 * @return	If the delimiter is not regarded as a token, the method returns the index of the first non-delimiter character. @n
	 *			If the delimiter is regarded as a token, the method returns the starting position.
	 * @param[in]	position	The position from where the delimiters need to skip
	 */
	int	SkipDelimiters(int position);

	/*
	 * Scans the tokens starting from the specified position.
	 *
	 * @return		The index of the next delimiter after the specified position
	 * @param[in] position	The position to start scan
	 */
	int	ScanToken(int position);

// Attribute
private:
	String __string;
	String __delimiters;
	int __curPosition;
	int __newPosition;
	int __maxStrLen;
	mchar __maxDelimChar;
	bool __isToken;
	bool __isDelimChanged;


private:
	friend class StringTokenizerEx;
	class StringTokenizerEx* __pStringTokenizerEx;
};
}; }; };// Osp::Base::Utility
#endif//_FBASE_UTIL_STRING_TOKENIZER_H_

