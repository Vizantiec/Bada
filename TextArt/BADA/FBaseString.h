/* $Change: 1145046 $ */
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
 * @file		FBaseString.h
 * @brief		This is the header file for the %String class.
 *
 * This header file contains the declarations of the %String class.
 */
#ifndef _FBASE_STRING_H_
#define _FBASE_STRING_H_

// Includes
#include "FBaseObject.h"


namespace Osp { namespace Base {
/**
 *	@class	String
 *	@brief	This class represents a mutable sequence of Unicode characters.
 *	@since	1.0
 *
 *	The %String class represents a mutable sequence of Unicode characters. Operations that change the Unicode text, such as append, insert, and remove, are contained in the %String class. 
 *
 *	For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/string.htm">String</a>.
 *
 * The following example demonstrates how to use the %String class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *
 *	void
 *	MyClass::StringSample(void)
 *	{
 *		String str;			    // capacity == 16, length == 0
 *
 *		// Append
 *		str.Append((int)100);   // str == L"100"
 *
 *		// Insert
 *		str.Insert(L"abc", 0);  // str == L"abc100"
 *
 *
 *		String str2(L"STRING TEST");
 *
 *		String subStr;
 *
 *		// SubString
 *		str2.SubString(7, 4, subStr);  // subStr == L"TEST"
 *
 *	}
 *	@endcode
 */

class _EXPORT_BASE_ String :
	public Object
{

	// Lifecycle
public:
	/**
	 *	This is the default constructor for this class. @n
	 *	It creates an empty %String instance with the default capacity of @c 16 bytes.
	 *
	 *	@since	1.0
	 */
	String(void);


	/**
 	 *	Initializes this instance of %String with the specified capacity.
	 *
	 *	@since			1.0
	 *	@param[in]	capacity The default capacity of this instance
	 */
	String(int capacity);


	/**
	 * 	Initializes this instance of %String with the specified Unicode character.
	 *
	 *	@since			1.0
	 * 	@param[in]	ch			A Unicode character
	 */
	String(const mchar ch);


	/**
	 *	Initializes this instance of %String with the specified Unicode string.
	 *
	 *	@since			1.0
	 *  @param[in]	pValue		A pointer to an array of Unicode characters
	 */
	String(const mchar* pValue);


	/**
	 *	Initializes this instance of %String with the specified character string.
	 *
	 *	@since			1.0
	 *  @param[in]	pValue		A pointer to an array of UTF-8 characters
	 */
	String(const char* pValue);


	/**
	 *	This is the copy constructor for the %String class.
	 *
	 *	@since			1.0
	 *	@param[in]	value	An instance of %String
	 */
	String(const String& value);


	/**
	 *	This is the destructor for this class.
	 *
	 *	@since			1.0
	 *	@remarks		The internally allocated memory block is freed when the instance is destroyed.
	 */
	virtual ~String(void);


	// Operator
public:

	/**
	 *	This subscript operator returns the Unicode character at the specified index.
	 *
	 *	@since			1.0
	 * 	@return			A reference to the Unicode character
	 * 	@param[in]	index An index within this instance of %String
	 */
	mchar& operator [](int index) const;


	/**
	 * 	This assignment operator copies the text from the specified
	 * 	Unicode string to the calling instance of %String.
	 *
	 *	@since			1.0
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	pRhs A pointer to an array of Unicode characters
	 */
	String& operator =(const mchar* pRhs);


	/**
	 * 	This assignment operator copies the text from the specified instance of %String
	 * 	to the calling instance of %String.
	 *
	 *	@since			1.0
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	rhs A reference to the %String instance to copy
	 */
	String& operator =(const String& rhs);


	/**
 	 * 	This assignment operator appends the text from the specified array of Unicode characters
	 * 	to the calling instance of %String.
	 *
	 *	@since			1.0
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	pRhs	A pointer to an array of Unicode characters
	 */
	String& operator +=(const mchar* pRhs);


	/**
	 * 	This assignment operator appends the text from the specified instance of %String
	 * 	to the calling instance of %String.
	 *
	 *	@since			1.0
	 * 	@return			A reference to the %String instance
	 * 	@param[in]	rhs A reference to the %String instance to copy
	 */
	String& operator +=(const String& rhs);


	/**
	 * 	This operator concatenates the two strings.
	 *
	 *	@since			1.0
	 * 	@return			The concatenated %String instance
	 * 	@param[in]	lhs A reference to the %String instance on the left-hand side of the operator
	 * 	@param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 */
	_EXPORT_BASE_ friend String operator +(const String& lhs, const String& rhs);


	/**
	 * 	This operator checks the two strings for equality.
	 *
	 *	@since			1.0
	 * 	@return			@c true if the text of the specified %String instance equals the calling instance's text, @n
	 *				else @c false
	 * 	@param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 * 	@remarks		The operator performs an ordinal comparison of each Unicode character.
	 */
	bool operator ==(const String& rhs) const;


	/**
	 * 	This operator checks the two strings for inequality.
	 *
	 *	@since			1.0
	 * 	@return			@c true if the text of the specified %String instance is not equal to the calling instance's text, @n
	 *				else @c false
	 * 	@param[in]	rhs A reference to the %String instance on the right-hand side of the operator
	 * 	@remarks		The operator performs an ordinal comparison of each Unicode character.
	 */
	bool operator !=(const String& rhs) const;


	// Operation
public:

	/**
	 *	Checks whether the string is empty.
	 *
	 *	@since		1.0
	 *	@return		@c true if the current instance is a zero-length %String instance L"", @n
	 *				else @c false
	 */
	bool IsEmpty(void) const;


	/**
	 * Appends the specified @c mchar value to this %String instance after converting it.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ch An @c mchar value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(mchar ch);


	/**
	 * Appends the specified @c char value to this %String instance after converting it.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ch A @c char value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(char ch);


	/**
	 * Appends the string representing the specified 32-bit @c int value to this 
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	i A 32-bit integer value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(int i);


	/**
	 * Appends the string representing the specified @c short value to this
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	s A @c short value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(short s);


	/**
	 * Appends the string representing the specified @c long value to this
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	l A @c long value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(long l);


	/**
	 * Appends the string representing the specified @c long @c long value to this
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ll A @c long @c long value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(long long ll);


	/**
	 * Appends the string representing the specified @c float value to this
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	f A @c float value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(float f);


	/**
	 * Appends the string representing the specified @c double value to this
	 * instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	d A @c double value to insert
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(double d);


	/**
	 * Appends the specified null-terminated Unicode text to this instance
	 * of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	p A pointer to a Unicode character array
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A @c null pointer is passed.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(const mchar* p);


	/**
	 * Appends the specified instance of %String to this instance
	 * of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str An instance of %String to append
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 */
	result Append(const String& str);


	/**
	 * Clears the current instance and sets it to an empty %String instance. @n
	 * The capacity is set to @c 16 bytes, which is the default capacity.
	 *
	 * @since	1.0
	 */
	void Clear(void);


	/**
	 *	Compares the values of the two strings.
	 *
	 *  @since			1.0
	 *	@return			A signed 32-bit integer value:
	 *	@code
	 *	<  0  if the value of the first instance is less than the value of the second instance
	 *	== 0  if the value of the first instance is equal to the value of the second instance
	 *	>  0  if the value of the first instance is greater than the value of the second instance
	 *	@endcode
	 *	@param[in]	str0	The first %String instance to compare
	 *	@param[in]	str1	The second %String instance to compare
	 *	@remarks		The method performs an ordinal comparison of each Unicode
	 *				character contained in the two given %String instances.
	 *				For instance, "U+xxx" is greater than "U+XXX", but smaller than "U+yyy".
	 */
	static int Compare(const String& str0, const String& str1);


	/**
	 * Compares the value of the current instance to the value of the specified instance
	 * of %String.
	 *
	 * @since			1.0
	 * @return		A signed 32-bit integer value:
	 *				@code
	 *				<  0  if the value of the current instance is less than the value of the specified %String instance
	 *				== 0  if the value of the current instance is equal to the value of the specified %String instance
	 *				>  0  if the value of the current instance is greater than the value of the specified %String instance
	 *				@endcode
	 * @param[in]	str		An instance of %String to compare
	 * @remarks		The method performs an ordinal comparison of each Unicode character. For instance,
	 *				L"U+xxx" is greater than L"U+XXX", but smaller than L"U+yyy".
	 */
	int CompareTo(const String& str) const;


	/**
	 * Ensures that the specified length is less than or equal to the capacity of
	 * the current instance of %String. @n
	 * Otherwise, it expands the capacity of the internal buffer to a value that is greater than or equal to the specified length.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	minLength		A minimum length to ensure
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified @c minLength is negative.
	 */
	result EnsureCapacity(int minLength);


	/**
	 * Checks whether the value of the specified instance of %Object is equal to the value of the current instance of %String.
	 *
	 * @since			1.0
	 * @return		@c true if the value of the specified instance of %Object is equal to the value of the current instance of %String, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %Object to compare 
	 * @remarks		The method returns @c false if the specified @c obj is not a string.
	 * @see				Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;


	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of the %String class. @n
	 * Case sensitivity can be controlled.
	 *
	 * @since			1.0
	 * @return		@c true if the values match, @n
	 *				else @c false
	 * @param[in]	str				The %String instance to compare with the
	 *								calling instance
	 * @param[in]	caseSensitive	Set to @c true to perform a case sensitive ordinal comparison of the strings, @n
	 *								else @c false
	 *
	 * @remarks		The method performs an ordinal comparison of each Unicode
	 *			character contained in the two given %String instances.
	 */
	bool Equals(const String& str, bool caseSensitive) const;


	/**
	 * Formats the inputs as per the specified format and sets the value of the calling instance to the resultant string.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	length			The maximum number of wide characters to be written, including the terminating @c null character
	 * @param[in]	pFormat			The wide character format specifier
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified @c length is negative or @c pFormat is @c null.
	 * @remarks		If an "l" modifier is present in @c pFormat (for example, L"@%ls"), it is a pointer to an array of wide characters. @n
	 * @remarks		A pointer to an array of UTF-8 characters is not allowed in the Format() method (for example, Format(20, L"@%s", pUTF8Str)).
	 *
	 * The following format specifiers are supported in this method:
	 *
	 * @code
	 * specifier  	Output
	 * ---------  	------
	 * c            single byte character
	 * d(or i)      signed decimal integer
	 * u            unsigned decimal integer
	 * x            unsigned hexadecimal integer
	 * f            decimal floating point
	 * e            scientific notation using e character
	 * g            use the shorter of %e or %f
	 * s            single byte character string
	 * ls(or S)     wide-character string
	 * lld          64-bit signed decimal integer
	 *
	 * @endcode
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	String str;
	 *
	 *	int value = 10;
	 *	mchar* testStr = L"TEST";
	 *
	 *	str.Format(25, L"FORMAT %d %ls", value, testStr);	// str == L"FORMAT 10 TEST"
	 *
	 * @endcode
	 */
	result Format(int length, const mchar* pFormat, ...);



	/**
	 *	Gets the hash value of the current instance.
	 *
	 *  @since		1.0
	 *	@return		The hash value of the current instance
	 *	@remarks 	Two equal instances should return the same hash value. For better performance,
	 *				the hash function used must generate a random distribution
	 *				for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Returns the character at the specified position.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@param[in]	indexAt					The position of the character
	 *	@param[out]	ch						The character at the specified index
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result GetCharAt(int indexAt, mchar& ch) const;


	/**
	 *	Searches for a character in the calling instance. @n
	 *	Gets the index of the first character that matches to
	 *	the specified character in this instance.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@param[in]	ch						The Unicode character to locate
	 *	@param[in]	startIndex				The starting position of search
	 *	@param[out]	indexOf					The index of the character
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result IndexOf(mchar ch, int startIndex, int& indexOf) const;


	/**
	 *	Searches for a specified sub-string in the calling instance. @n
	 *	Gets the starting index of the first occurrence of the specified sub-string.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str						An instance of %String to locate
	 * @param[in]	startIndex				The starting position of the search
	 * @param[out]	indexOf					The index of the substring
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified string is not found.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result IndexOf(const String& str, int startIndex, int& indexOf) const;


	/**
	 * Inserts the string representing the specified Unicode character
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 *
	 * @param[in]	ch						A Unicode character to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(mchar ch, int indexAt);


	/**
	 * Inserts the string representing the specified @c char value
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 *
	 * @param[in]	ch						A @c char value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
 	 */
	result Insert(char ch, int indexAt);


	/**
	 * Inserts the string representing the specified 16-bit integer
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	s						A 16-bit integer value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(short s, int indexAt);


	/**
	 * Inserts the string representing the specified 32-bit integer
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	i						A 32-bit integer value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(int i, int indexAt);


	/**
	 * Inserts the string representing the specified @c long value
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	l						A @c long value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(long l, int indexAt);


	/**
	 * Inserts the string representing the specified @c long @c long value
	 * at the specified position in the calling instance.
 	 *
 	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ll						A @c long @c long value to insert
     * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(long long ll, int indexAt);


	/**
	 * Inserts the string representing the specified @c float value
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	f						A @c float value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(float f, int indexAt);


	/**
	 * Inserts the string representing the specified @c double value
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	d						A @c double value to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(double d, int indexAt);


	/**
	 * Inserts the string representing the specified @c null-terminated
	 * string at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	p						A %String instance to insert
	 * @param[in]	indexAt					The position of the character
	 
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_INVALID_ARG			A @c null pointer is passed.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(const mchar* p, int indexAt);


	/**
	 * Inserts the string representing the specified instance of %String
	 * at the specified position in the calling instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str						A %String instance to insert
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Insert(const String& str, int indexAt);


	/**
	 * Searches the calling instance for the last occurrence of the specified character and returns its index. @n
	 * The search begins at the @c startIndex position and proceeds backward towards the beginning.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@param[in]	ch						The Unicode character to locate
	 *	@param[in]	startIndex				The starting position of search
	 *	@param[out]	indexOf					The index of character
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 *	@exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result LastIndexOf(mchar ch, int startIndex, int& indexOf) const;


	/**
	 * Searches the calling instance for the last occurrence of the specified sub-string and returns its index. @n
	 * The search begins at the @c startIndex position and proceeds backward towards the beginning.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	str						An instance of %String to locate
	 * @param[in]	startIndex				The starting position of search
	 * @param[out]	indexOf					The index of the sub-string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified character is not found.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 * @remarks	If the sub-string is empty, E_SUCCESS is returned and the value of @c indexOf is set to @c startIndex.
	 */
	result LastIndexOf(const String& str, int startIndex, int& indexOf) const;


	/**
	 * Removes the characters within the specified range.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	startIndex				The position where the removal begins
	 * @param[in]	length					The number of characters to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is out of range. @n
	 *										- The specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0. @n
	 *										- The specified @c count is either greater than the length of sub-string starting from @c startIndex or less than @c 0.
	 */
	result Remove(int startIndex, int length);


	/**
	 * Replaces all occurrences of the specified characters.
	 *
	 * @since			1.0
	 * @param[in]	original The character to be replaced
	 * @param[in]	replace A character to replace all occurrences of @c original
	 */
	void Replace(mchar original,  mchar replace);


	/**
	 * Replaces all occurrences of the specified string.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref 	String_Replace2 "here".
	 * @return		An error code
	 * @param[in]	original				An instance of %String to be replaced
	 * @param[in]	replace					A %String instance to replace all occurrences of @c original
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c original is an empty string.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Replace(const String& original, const String& replace);
	/**
	 *
	 * @page		String_Replace2 Compatibility for Replace(const String& original, const String& replace)
	 *
	 * @section		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * When the string to be replaced and the string to be sought (seek(const String& original)) are equal 
	 * and the size of the string to be replaced (replace(const String& replace)) is greater than the string to be replaced with,
	 * an error occurs.
	 *
	 * @section		Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above.
	 * 
	 */


	/**
	 * Replaces all occurrences of the specified string within the sub-string
	 * of this instance of %String.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 					For more information, see @ref 	String_Replace3 "here".
	 * @return		An error code
	 * @param[in]	original				An instance of %String to be replaced
	 * @param[in]	replace					An instance of %String to replace all occurrences of @c original
	 * @param[in]	startIndex				The starting position of the sub-string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c original is an empty string.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Replace(const String& original, const String& replace, int startIndex);
	/**
	 *
	 * @page		String_Replace3 Compatibility for Replace(const String& original, const String& replace, int startIndex)
	 *
	 * @section		Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * When the string to be replaced and the string to be sought (seek(const String& original)) are equal 
	 * and the size of the string to be replaced (replace(const String& replace)) is greater than the string to be replaced with,
	 * an error occurs.
	 *
	 * @section		Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above.
	 * 
	 */


	/**
	 * Reverses the sequence of characters in the calling instance.
	 *
	 * @since	1.0
	 *
	 */
	void Reverse(void);


	/**
	 * Sets the capacity of this instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	newCapacity		The new capacity
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified @c capacity is negative.
	 * @remarks		If the new capacity is smaller than the current length, then
	 *				the text contained in this instance is truncated.
	 */
	result SetCapacity(int newCapacity);


	/**
	 * Replaces the character at the specified index with the given character.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	ch						A new character
	 * @param[in]	indexAt					The position of the character
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c indexAt is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result SetCharAt(mchar ch, int indexAt);


	/**
	 * Sets the length of this instance of %String.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	newLength		The new length
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified @c newLength is negative.
	 * @remarks		If the new length is greater than the current length, the
	 *				string is padded with spaces. On the other hand,
	 *				if the new length is smaller than the current length, then
	 *				the text contained in this instance is truncated.
	 */
	result SetLength(int newLength);


	/**
	 * Gets a sub-string starting from the given index.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	startIndex				The starting index of the sub-string
	 * @param[out]	out						The sub-string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is out of range, or
	 *										the specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0.
	 */
	result SubString(int startIndex, String& out) const;


	/**
	 * Gets a sub-string of the given length starting from the specified index.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	startIndex				The starting position of the sub-string
	 * @param[in]	length					The length of the sub-string
	 * @param[out]	out						The sub-string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is out of range. @n
	 *										- The specified @c startIndex is either greater than or equal to the length of the current instance or less than @c 0. @n
	 *										- The specified @c length is either greater than the length of sub-string starting from @c startIndex or less than @c 0.
	 */
	result SubString(int startIndex, int length, String& out) const;


	/**
	 *	Checks whether this instance contains the specified text from the given index.
	 *
	 *  @since			1.0
	 *	@return			@c true if this instance starts with the specified text, @n
	 *				else @c false
	 *	@param[in]	str					The string to match
	 *	@param[in]	startIndex			The start position of the string
	 */
	bool StartsWith(const String& str, int startIndex) const;


	/**
	 *	Checks whether the given string is present at the end of the calling instance.
	 *
	 *  @since			1.0
	 *	@return			@c true if this instance ends with the specified text, @n
	 *				else @c false
	 *	@param[in]	str				An instance of String to match
	 */
	bool EndsWith(const String& str) const;


	/**
	 *	Gets the lowercase form of the string in the calling instance. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *	@deprecated This method is deprecated as a new API has been introduced.
	 *	Instead of using this API, use the ToLowerCase(%String& out) API that supports Unicode characters other than the English alphabets.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result ToLower(String& out) const;


	/**
	 *	Gets the lowercase form of the string in the calling instance. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since			1.2
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result ToLowerCase(String& out) const;


	/**
	 *	Gets the uppercase form of the string in the calling instance. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new API has been introduced.
	 *	Instead of using this API, use the ToUpperCase(%String& out) API that supports Unicode characters other than the English alphabets.
	 *
	 *  @since			1.0
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result ToUpper(String& out) const;


	/**
	 *	Gets the uppercase form of the string in the calling instance. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since			1.2
	 *	@return			An error code
	 *	@param[out]	out						An instance of %String that contains the modified value of the calling instance
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result ToUpperCase(String& out) const;


	/**
	 *	Converts all the letters in this instance to lowercase. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new API has been introduced.
	 *	Instead of using this API, use the ToLowerCase(void) API that supports Unicode characters other than the English alphabets.
	 *
	 *  @since	1.0
	 */
	void ToLower(void);


	/**
	 *	Converts all the letters in this instance to lowercase. @n
	 *  Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since	1.2
	 */
	void ToLowerCase(void);


	/**
	 *	Converts all the letters in this instance to uppercase. @n
	 *  Unicode characters other than the English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new API has been introduced.
	 *	Instead of using this API, use the ToUpperCase(void) API that supports Unicode characters other than the English alphabets.
	 *
	 *  @since	1.0	 
	 */
	void ToUpper(void);


	/**
	 *	Converts all the letters in this instance to uppercase. @n
     *	Unicode characters other than the English alphabets are also supported.
	 *
	 *	@since	1.2
	 */
	void ToUpperCase(void);


	/**
	 *	Removes the leading and trailing whitespace characters.
	 *
	 *  @since	1.0
	 */
	void Trim(void);


	// Accessor
public:
	/**
	 * Gets the current capacity of this %String instance.
	 *
	 * @since			1.0
	 * @return		The capacity of this instance of %String
	 */
	int GetCapacity(void) const;


	/**
	 * Gets the length of the text contained in this %String instance.
	 *
	 * @since			1.0
	 * @return		The length of this instance of %String
	 */
	int GetLength(void) const;


	/**
	 * Gets a pointer to the instance's internal buffer
	 *
	 * @since			1.0
	 * @return		A Unicode pointer to the calling instance's internal buffer
	 */
	const mchar* GetPointer(void) const;


	// Constant
public:
	/**
	 * A constant holding the default capacity of %String.
	 *
	 * @since	1.0
	 */
	static const unsigned long DEFAULT_CAPACITY = 16;


	// Operation
private:
	/*
	 * Allocates an internal buffer with the specified capacity.
	 * @return		An error code
	 * @param[in]	capacity The initial capacity of this instance of String
	 */
	bool AllocateCapacity(int capacity);


	/*
	 * Expands the size of the internal buffer that is greater than or equal
	 * to the specified capacity.
	 * @return		@c true, if the capacity is expanded @n
	 * 				@c false, otherwise
	 * @param[in]	capacity The new capacity of this instance of String
	 */
	bool ExpandCapacity(int minCapacity);


	/*
	 * Resets the internal state of this instance of String.
	 * @return		@c true, if the internal state is reset @n
	 * 				@c false, otherwise
	 * @param[in]	capacity The new capacity of this instance of String
	 */
	void Reset(void);


	// Attribute
private:
	int				__capacity;
	int				__length;
	mutable mchar*	__pValue;


	// Constants
private:
	static const float GROWTH_FACTOR;


private:
	friend class StringEx;
	class StringEx* __pStringEx;
};
};};// Osp::Base
#endif // _FBASE_STRING_H_



