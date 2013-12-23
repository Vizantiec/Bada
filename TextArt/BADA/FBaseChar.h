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
 * @file		FBaseChar.h 
 * @brief		This is the header file for the %Character class.
 *
 * This header file contains the declarations of the %Character class.
 */
#ifndef _FBASE_CHAR_H_
#define _FBASE_CHAR_H_

// includes
#include "FBaseObject.h"
#include "FBaseString.h"


namespace Osp { namespace Base {
/** 
 *	@enum	UnicodeCategory
 *
 *	Defines the constants used to distinguish the categories of Unicode characters.
 *
 *	@since	1.0
 */
enum UnicodeCategory
{
	UNICODE_SURROGATE = 1,			/**<	The surrogate Unicode category		*/
	UNICODE_MODIFIER,				/**<	The spacing modifier Unicode category */
	UNICODE_ARROW,					/**<	The arrow Unicode category			*/
	UNICODE_SPACE,					/**<	The space Unicode category			*/	
	UNICODE_PUNCTUATION,			/**<	The punctuation Unicode category	*/
	UNICODE_CONTROL,				/**<	The control Unicode category		*/	
	UNICODE_MATH,					/**<	The math Unicode category			*/	
	UNICODE_DIGIT,					/**<	The digit Unicode category			*/	
	UNICODE_LATIN,					/*<		@internal This is internal. If used in an application, the application can get rejected during the certification process.*/
	UNICODE_HFWIDTH,				/*<		@internal This is internal. If used in an application, the application can get rejected during the certification process.*/
	UNICODE_HANGUL,					/**<	The Hangul Unicode category			*/
	UNICODE_HANJA,					/**<	The Hanja Unicode category			*/	
	UNICODE_COMBINING,				/**<	The combining Unicode category		*/
	UNICODE_LANGUAGE,				/**<	The language Unicode category		*/
	UNICODE_OTHER					/**<	The other Unicode category			*/	
};


/**
 *	@class	Character 
 *	@brief	This class is the wrapper class for the @c mchar built-in type.
 *	@since	1.0
 *
 *	The %Character class wraps a value of the @c mchar type. It also provides 
 *	several methods for determining a Unicode character's category, and for 
 *	converting the case of intrinsic characters. The class is useful when 
 *	passing a Unicode character to a method expecting an instance of Object.
 *
 * The following example demonstrates how to use the %Character class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 * 
 *	// This method converts the first character of the given @c string to the upper case.
 *	void
 *	MyClass::CharacterSample(String& str)
 *	{
 *		mchar chr, upper;
 *
 *
 *		str.GetCharAt(0, chr)
 *
 *      // convert to upper case
 *		upper = Character::ToUpper(chr);
 *
 *		str.SetCharAt(upper, 0);
 *  }
 *	@endcode
 */
class _EXPORT_BASE_ Character :
	public Object
{
// LIfecyle
public:
	/** 
	 *	Initializes this instance of %Character with the specified parameter.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	A multi-byte character used to initialize the %Character instance
	 */
	Character(mchar value);


	/** 
	 *	This is the copy constructor for the %Character class. @n
	 *	Initializes this instance of %Character with the specified parameter.
	 *
	 *	@since			1.0
	 *	@param[in]	value 	An instance of %Character
	 */
	Character(const Character& value);


	/** 
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~Character(void);


// Operator
public:

	/** 
	* This operator assigns the value of the specified %Character instance to the current instance.
	*
	*	@since			1.0
	* @param[in]	rhs	An instance of %Character
	*/
	Character& operator =(const Character& rhs);


// Operation
public:

	/** 
	 *	Compares (ordinal comparison) the value of the calling instance
	 *	with the value of the input %Character instance.
	 *
	 *	@since		1.0
	 *	@return		A signed 32-bit integer value
	 *  @param[in]	value 	The character instance to be compared with
	 *	@code
	 *	@li <  0  if the value of the current instance is less than the value of the input instance
	 *	@li == 0  if the value of the current instance is equal to the value of the input instance
	 *	@li >  0  if the value of the current instance is greater than the value of the input instance
	 *	@endcode
	 *	 
	 */
	int CompareTo(const Character& value) const;


	/** 
	 *	Checks whether the value of the Object parameter is equal 
	 *	to the value of the calling object.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input %Object is equal to the calling %Object, @n
	 *				else @c false
	 *	@param[in]	obj		The object to be compared with the calling object
	 *	@see			Osp::Base::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;


	/** 
	 *	Returns the hash value of the current instance.
	 *
	 *	@since		1.0
	 *	@return		The hash value of the current instance
	 *	@remarks 	The two Osp::Base::Object::Equals() instances should return the same hash value. For better performance, 
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/** 
	 *	Returns the value of the current instance as
	 *	@c mchar. 
	 *
	 *	@since		1.0
	 *	@return		The value of this instance as 
	 *				@c mchar
	 */
	mchar ToMchar(void) const;


	/** 
	 *	Converts the Unicode characters of the calling object to its equivalent lowercase.
	 *	The Unicode characters other than English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToLowerCase(void) method that supports Unicode characters other than English alphabets.
	 *
	 *	@since	1.0
	 */
	void ToLower(void);


	/**
	 *	Converts the Unicode characters of the calling object to its equivalent lowercase.
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since	1.1
	 */
	void ToLowerCase(void);


	/** 
	 *	Converts the Unicode characters of the current object to its equivalent uppercase.
	 *	The Unicode characters other than English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToUpperCase(void) method that supports the Unicode characters other than English alphabets.
	 *
	 *	@since	1.0
	 */
	void ToUpper(void);


	/**
	 *	Converts the Unicode characters of the current object to its equivalent uppercase.
	 *	The Unicode characters other than English alphabets are also supported.
	 *
 	 *	@since	1.1
	 */
	void ToUpperCase(void);


	/** 
	 *	Returns a string representing the value of the calling %Character instance. 
	 *
	 *	@since		1.0
	 *	@return		An instance of String class that 
	 *				contains a Unicode representation of the calling instance
	 */
	String ToString(void) const;


	/** 
	 *	Returns a string representation of the input 
	 *	@c mchar value.  
	 *
	 *	@since		1.0
	 *	@return		An instance of the String class 
	 *				that contains the Unicode representation of the 
	 *				input value
	 *	@param[in]	value 	The Unicode character to convert
	 */
	static String ToString(mchar value); 

	
	/** 
	 *	Categorizes a Unicode character into a group identified by 
	 *	one of the UnicodeCategory values. 
	 *
	 *	@since	1.0
	 *	@return		    A value of type UnicodeCategory that identifies the group that contains the specified @c ch
	 *	@param[in]	ch 	The Unicode character to categorize
	 *
	 */
	static UnicodeCategory GetUnicodeCategory(mchar ch);


	/** 
	 *	Converts the input Unicode character to its equivalent lowercase.
	 *  The Unicode characters other than English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToLowerCase(mchar ch) method that supports the Unicode characters other than English alphabets.
	 *
	 *	@since		1.0
	 *	@return		A lowercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static mchar ToLower(mchar ch);


	/**
	 *	Converts the input Unicode character to its equivalent lowercase.
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since		1.1
	 *
	 *	@return		A lowercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static mchar ToLowerCase(mchar ch);


	/** 
	 *	Converts the input Unicode character to its equivalent uppercase.
	 *  The Unicode characters other than English alphabets are not changed.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use ToUpperCase(mchar ch) method that supports Unicode characters other than English alphabets.
	 *
	 *	@since		1.0
	 *	@return		An uppercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static mchar ToUpper(mchar ch);


	/**
	 *	Converts the input Unicode character to its equivalent uppercase.
	 *	The Unicode characters other than English alphabets are also supported.
	 *
	 *	@since		1.1
	 *
	 *	@return		An uppercase equivalent of the input Unicode character
	 *	@param[in]	ch 	The Unicode character to convert
	 */
	static mchar ToUpperCase(mchar ch);


// Inquiry
public:
	/** 
	 *	Checks whether the input character is alphanumeric.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input character is alphanumeric, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */	
	static bool IsAlphaNumeric(mchar ch);


	/** 
	 *	Checks whether the input character is a digit.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input character is a digit, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */	
	static bool IsDigit(mchar ch);


	/** 
	 *	Checks whether the input character is an alphabet.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input character is an alphabet, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */
	static bool IsLetter(mchar ch);
	

	/** 
	 *	Checks whether the input character is a lowercase alphabet.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use IsLowerCase(mchar ch) method that supports Unicode characters.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input character is a lowercase English alphabet, @n
	 *				else @c false
	 *	@param[in]	ch	The Unicode character
	 */	
	static bool IsLower(mchar ch);


	/**
	 *	Checks whether the input character is a lowercase alphabet.
	 *	Unicode characters other than English alphabets are also supported.
	 *
	 *	@since		1.1
	 *
	 *	@return		@c true if the input character is a lowercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 */
	static bool IsLowerCase(mchar ch);


	/** 
	 *	Checks whether the input character is an uppercase alphabet.
	 *
	 *	@deprecated This method is deprecated as a new method has been introduced.
	 *	Instead of using this method, use IsUpperCase(mchar ch) method that also supports Unicode characters other than English alphabets.
	 *
	 *	@since		1.0
	 *	@return		@c true if the input character is an uppercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 */	
	static bool IsUpper(mchar ch);


	/**
	 *	Checks whether the input character is an uppercase alphabet.
	 *	Unicode characters other than English alphabets are also supported.
	 *
	 *	@since		1.1
	 *
	 *	@return		@c true if the input character is an uppercase alphabet, @n
	 *				else @c false
	 *	@param[in]	ch The Unicode character
	 */
	static bool IsUpperCase(mchar ch);


// Private member function
private:
	/** 
	 *	Returns whether the input character is the value between
	 *	(0xD800) and (0xF8FF) or not.
	 *
	 *	@return		@c true, if the input character is between (0xD800) and (0xF8FF) @n
					@c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsSurrogate(int ch);

	/** 
	 *	Checks whether the input character is the modifier code.
	 *
	 *	@return		@c true, if the input character is the modifier code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsModifier(int ch);

	/** 
	 *	Checks whether the input character is the arrow code.
	 *
	 *	@return		@c true, if the input character is the arrow code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsArrow(int ch);

	/** 
	 *	Returns whether the input character is a space or not.
	 *
	 *	@return		@c true, if the input character is a space @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsSpace(int ch);

	/** 
	 *	Returns whether the input character is a punctuation mark or not.
	 *
	 *	@return		@c true, if the input character is a punctuation mark @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsPunc(int ch);

	/** 
	 *	Checks whether the input character is a control code.
	 *
	 *	@return		@c true, if the input character is a control code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsControl(int ch);

	/** 
	 *	Checks whether the input character is a math code.
	 *
	 *	@return		@c true, if the input character is a math code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsMath(int ch);

	/** 
	 *	Returns whether the input character is a digit or not.
	 *
	 *	@return		@c true, if the input character is a digit @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsDecimalDigit(int ch);

	/** 
	 *	Checks whether the input character is a LATIN1 code.
	 *
	 *	@return		@c true, if the input character is a LATIN1 code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsAlphaISO8859_1(int ch);

	/** 
	 *	Checks whether the input character is a HFwidth code.
	 *
	 *	@return		@c true, if the input character is a HFwidth code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsHFwidth(int ch);

	/** 
	 *	Checks whether the input character is an Hangul code.
	 *
	 *	@return		@c true, if the input character is an Hangul code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsHangul(int ch);

	/** 
	 *	Checks whether the input character is an Hangul Compatibility Jamo.
	 *
	 *	@return		@c true, if the input character is an Hangul Compatibility Jamo @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsHangulJamo2(int ch);

	/** 
	 *	Check whether the input character is an Hangul Jamo.
	 *
	 *	@return		@c true, if the input character is an Hangul Jamo @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsHangulJamo3(int ch);

	/** 
	 *	Checks whether the input character is a Chinese code.
	 *
	 *	@return		 @c true, if the input character is a Chinese code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsCJK(int ch);

	/** 
	 *	Checks whether the input character is a Combining code.
	 *
	 *	@return		@c true, if the input character is a Combining code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsCombining(int ch);

	/** 
	 *	Checks whether the input character is a language code.
	 *
	 *	@return		@c true, if the input character is a language code @n
					 @c false, otherwise
	 *	@param[in]	ch	A character code
	 */	
	static bool __McIsLang(int ch);


	/** 
 	 *	Returns @c true if the specified character is a digit.
	 *	Otherwise, it returns @c false.
	 *
	 *	@return		@c true, if the input character is a language code @n
					 @c false, otherwise
	 *	@param[in]	ch		A Unicode character
	 *	@param[in]	radix	A radix value
	 */
	static bool _IsDigit(mchar ch, int radix);


	/** 
	*	Returns @c true if the specified string consists of digit characters.
	*	Otherwise, it returns @c false.
	*
	*	@return		@c true, if the input character is a language code @n
					 @c false, otherwise
	*	@param[in]	str		A Unicode string
	*	@param[in]	radix	A radix value
	*/
	static bool _IsDigit(const String& str, int radix);


// Constant
public:
	/** 
	 * A constant holding the largest value of type @c mchar, 0xFFFF. 
	 *
	 * @since	1.0
	 */
	static const mchar VALUE_MAX = 0xFFFF;


	/** 
	 * A constant holding the smallest value of type mchar, 0x0000. 
	 *
	 * @since	1.0
	 */
	static const mchar VALUE_MIN = 0x0000;


	/** 
	 * The minimum radix available for conversion to and from strings. @n
	 * For example, RADIX_BINARY.
	 *
	 * @since	1.0
	 */
	static const int RADIX_MIN = 1;
	
	
	/** 
	 * The radix for binary number.
	 *
	 * @since	1.0
	 */
	static const int RADIX_BINARY = 2;
	

	/** 
	 * The radix for decimal number.
	 *
	 * @since	1.0
	 */

	static const int RADIX_DECIMAL = 10;
	
	
	/** 
	 * The radix for octal number.
	 *
	 * @since	1.0
	 */
	static const int RADIX_OCTAL = 8;


	/** 
	 * The radix for hexadecimal number.
	 *
	 * @since	1.0
	 */
	static const int RADIX_HEXADECIMAL = 16;


	/** 
	 * The maximum radix available for conversion to and from strings. @n
	 * For example, RADIX_HEXADECIMAL.
	 *
	 * @since	1.0
	 */
	static const int RADIX_MAX = 16;


private:
	// Friend class
	friend class Int8;
	friend class Short;
	friend class Long;
	friend class Integer;


// Attribute
private:
	mchar __val;


private:
	friend class CharacterEx;
	class CharacterEx* __pCharacterEx;

};
}; };// Osp::Base
#endif// _FBASE_CHAR_H_
