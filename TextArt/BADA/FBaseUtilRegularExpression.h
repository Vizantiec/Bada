/* $Change: $ */
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
 * @file		FBaseUtilRegularExpression.h
 * @brief		This is the header file for the %RegularExpression class.
 *
 * This header file contains the declarations of the %RegularExpression class.
 */
#ifndef _FBASE_UTIL_REGEX_H_
#define _FBASE_UTIL_REGEX_H_

//Includes
#include "FBaseColIList.h"
#include "FBaseString.h"

namespace Osp { namespace Base { namespace Utility {


/**
 *	@enum	RegularExpressionOptions
 *	Defines the options available for a regular expression.
 *	@since 	2.0
 */
enum RegularExpressionOptions {
	REGEX_CASELESS			= 	0x00000001,		/**< The case insensitive match option */
	REGEX_MULTI_LINE		= 	0x00000002,		/**< The multiple lines match option @n
													Without this option,(^) matches only at the start of the string, while ($) matches only at
													the end of the string, or before a terminating newline */
	REGEX_DOTALL 			= 	0x00000004,		/**< The dot matches newlines option @n
													Without this option, a dot does not match when the current position is at a newline */
	REGEX_EXTENDED 			= 	0x00000008,		/**< The ignored whitespaces in a pattern */
	REGEX_DOLLAR_ENDONLY 	= 	0x00000020,		/**< The option to match the dollar symbol ($) only at the end @n
	                                                Without this option, a dollar symbol also matches immediately before a newline */
	REGEX_UNGREEDY 			= 	0x00000200,		/**< The option to reverse the (*) and (*?) symbols @n
													If this option is set, the quantifiers are not greedy by default, however they are, if followed by a question mark */
	REGEX_UNICODE 			= 	0x20000000,		/**< The option to support the unicode characters @n
													Without this option, only the ASCII characters are recognized */
};


/**
 * @class	RegularExpression
 * @brief		This class provides the functionality for a regular expression.
 * @since	2.0
 *
 * The %RegularExpression class provides operations of a regular expression based on PCRE and the syntax based on 
 * the Perl regular expression.
 * The various supported operations are Match(), Replace(), and Consume().
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/regular_expression.htm">Regular Expression</a>.
 *
 *
 * The following example demonstrates how to use the %RegularExpression class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Osp::Base;
 *	using namespace Osp::Base::Collection;
 *	using namespace Osp::Base::Utility;
 *
 *	void
 *	MyClass:RegularExpressionSample(void)
 *	{
 *		bool ret = false;
 *
 *	 	String pattern(L"the quick brown fox");
 *		String text(L"What do you know about the quick brown fox?");
 *		String out;
 *
 *	 	RegularExpression regex;
 *		regex.Construct(pattern, REGEX_CASELESS);
 *	
 *		// Match
 *	 	ret = regex.Match(text, false);	// This returns true value
 *	}	
 *
 * @endcode
 */
class _EXPORT_BASE_ RegularExpression :
	public Osp::Base::Object
{

// Lifecycle
public:

	/**
	 * This is the default constructor for this class. 
	 *
 	 * @since	2.0
	 */
	RegularExpression(void);


	/** 
	 * This is the destructor for this class.
	 *
 	 * @since	2.0
	 */	
	virtual ~RegularExpression(void);


	/**
	 * Initializes this instance of %RegularExpression with the specified parameters. 
	 *
 	 * @since	2.0
 	 *
	 * @return			An error code
	 * @param[in] 		pattern	The pattern to be used
	 * @param[in] 		options	The option for the regular expression
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_STATE		This instance has already been constructed.
	 * @exception		E_INVALID_ARG		The length of the specified @c pattern parameter is @c 0.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *
	 *	String pattern(L"^CRUEL$");
	 * 	String text(L"Hello\ncruel\nworld");
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern, REGEX_CASELESS | REGEX_MULTI_LINE);
	 *	ret = regex.Match(text, false);		// This returns true value
	 *
	 * @endcode
	 */
	result Construct(const Osp::Base::String& pattern, unsigned long options = 0x0);


// Operation
public:

	/**
	 * Checks whether the specified text matches completely or partially.
	 *
 	 * @since	2.0
 	 *
	 * @return			@c true if the text matches successfully, @n
	 *					else @c false
	 * @param[in] 		text  The text to match
	 * @param[in] 		fullMatch		Set to @c true to match exactly, @n
	 *								else @c false to match any substring of the text
	 * @param[out] 		pMatchedString	A list of the matched string instances @n
                    	 The count of the matched items is acquired from IList::GetCount() and
	 *					the maximum count of the items is @c 16.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		The length of the specified @c text parameter is @c 0.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.	
	 * @remarks			If the grouping subpatterns are used in a pattern, 
	 *                  the @c pMatchedString list will contain the grouping data. @n
	 *					For example, if the pattern has two grouping subpatterns, 
	 *                  there will be three data sets in the @c pMatchedString list. @n
	 *					The first data set will be a full grouping data and the second 
	 *                  and the third data sets will contain individual grouping data.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *
	 *	String pattern(L"(\\d\\d)-(\\d\\d)-(\\d\\d\\d\\d)");
	 *	String text(L"04-12-1979");
	 *	String out;
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern);
	 *	
	 *	ArrayList list;
	 *	list.Construct();
	 *
	 *	// Match
	 *	ret = regex.Match(text, true, &list);		// The list will contain four string instances
	 *	
	 *	out = *(String *)list.GetAt(0);		//  L"04-12-1979"
	 *	out = *(String *)list.GetAt(1);		//  L"04"
	 *	out = *(String *)list.GetAt(2);		//  L"12"
	 *	out = *(String *)list.GetAt(3);		//  L"1979"
	 *
	 *	list.RemoveAll(true);
	 * @endcode
	 */
	bool Match(const Osp::Base::String& text, bool fullMatch, Osp::Base::Collection::IList* pMatchedString = null) const;	


	/**
	 * Matches the pattern from the starting point of the text and removes the matched string. @n
     * If the pattern does not match the text at the starting point, it will return @c false.
	 *
 	 * @since	2.0
 	 *
	 * @return			@c true if the text matches successfully, @n
	 *					else @c false
	 * @param[in, out] 	text  The text to consume
	 * @param[out] 		pMatchedString	A list of matched string instances @n  
	 *                                 The count of the matched items is acquired from IList::GetCount() and
	 *								   the maximum count of the items is @c 16.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		The length of the specified @c text parameter is @c 0.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @remarks			If the grouping subpatterns are used in a pattern, the @c pMatchedString list will 
	 *                  contain the grouping data. @n
	 *					For example, if the pattern has two grouping subpatterns, 
	 *                  there will be three data sets in the @c pMatchedString list. @n
	 *					The first data set will be a full grouping data and the second 
	 *                  and the third data sets will contain individual grouping data.

	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *	String out;
	 *
	 *	String pattern(L"(\\s+)([a-z]+)(\\d+)");
	 * 	String text(L"    abcd1234test");
	 *	ArrayList list;
	 *	list.Construct();
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern);
	 *	ret = regex.Consume(text, &list);		// The list will contain four string instances
	 *									// and the text instance will be changed to L"test"
	 *	out = *(String *)list.GetAt(0);		//  L"    abcd1234"
	 *	out = *(String *)list.GetAt(1);		//  L"    "
	 *	out = *(String *)list.GetAt(2);		//  L"abcd"
	 *	out = *(String *)list.GetAt(3);		//  L"1234"
	 *
	 *	list.RemoveAll(true);
	 * @endcode
	 */
	bool Consume(Osp::Base::String& text, Osp::Base::Collection::IList* pMatchedString = null) const;


	/**
	 * Matches the pattern in strings similar to the Consume() method but does not anchor the match at the beginning of the string. @n
     * This operation can be used to find certain patterns in the text and extract the required information.
	 * 
	 *
 	 * @since	2.0
 	 *
	 * @return			@c true if the text matches successfully, @n
	 *					else @c false
	 * @param[in, out] 	text  The text to find and consume
	 * @param[out] 		pMatchedString	A list of matched string instances @n
     *                  The count of the matched items is acquired from IList::GetCount() and
	 *						the maximum count of the items is @c 16.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		The length of the specified @c text parameter is @c 0.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @remarks			If the grouping subpatterns are used in a pattern, 
	 *                  the @c pMatchedString list will contain the grouping data. @n
	 *					For example, if the pattern has two grouping subpatterns, 
	 *                  there will be three data sets in the @c pMatchedString list. @n
	 *					The first data set will be a full grouping data and the second 
	 *                  and the third data sets will contain individual grouping data.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *	String out;
	 *
	 *	String pattern(L"(\\s+)([a-z]+)(\\d+)");
	 * 	String text(L"test    abcd1234test");
	 *	ArrayList list;
	 *	list.Construct();
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern);
	 *	ret = regex.FindAndConsume(text, &list);		// The list will contain four String instances
	 *									// and text instance will be changed to  L"test"
	 *	out = *(String *)list.GetAt(0);		//  L"    abcd1234"
	 *	out = *(String *)list.GetAt(1);		//  L"    "
	 *	out = *(String *)list.GetAt(2);		//  L"abcd"
	 *	out = *(String *)list.GetAt(3);		//  L"1234"
	 *
	 *	list.RemoveAll(true);
	 * @endcode
	 */
	bool FindAndConsume(Osp::Base::String& text, Osp::Base::Collection::IList* pMatchedString = null) const;


	/**
	 * Replaces either the first match of a pattern in the text with the @c rewrite string or 
	 * all the occurrences of a pattern in the text.
	 *
 	 * @since	2.0
 	 *
	 * @return			@c true if the text is replaced successfully, @n
	 *					else @c false
	 * @param[in, out] 	text  The text to be replaced when it is matched to a pattern
	 * @param[in] 		rewrite         The text with which to replace
	 * @param[in] 		globalReplace	Set to @c true to replace globally, @n
	 *								    else @c false to replace the first match of the pattern in the text
	 * @param[in] 		startPos       The starting position of the text
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		The length of the specified @c pattern parameter is @c 0, or 
	 *										the size of @c pMatchedString exceeds limitations.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *
	 *	String pattern(L"replace");
	 * 	String text(L"test replace method");
	 *	String rewrite(L"REPLACE");
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern);
	 *	ret = regex.Replace(text, rewrite, false);		// text = L"test REPLACE method"
	 *
	 * @endcode
	 */
	bool Replace(Osp::Base::String& text, const Osp::Base::String& rewrite, bool globalReplace, int startPos = 0) const;


	/**
	 * Extracts the first match of the pattern in the text. @n
	 * Similar to Replace() but @c rewrite is copied to @c out with substitutions.
	 *
 	 * @since	2.0
 	 *
	 * @return			@c true if the text is extracted successfully, @n
	 *					else @c false
	 * @param[in] 		text     The text to match
	 * @param[in] 		rewrite  The text to replace
	 * @param[out] 		out      The text to be extracted
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception 		E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception		E_INVALID_ARG		The length of the specified @c pattern parameter is @c 0, or
	 *										the size of @c pMatchedString exceeds limitations.
	 * @remarks		   The specific error code can be accessed using the GetLastResult() method.
	 *
	 * The following example demonstrates how to use this method.
	 *
	 * @code
	 *
	 *	bool ret = false;
	 *	String out;
	 *
	 *	String pattern(L"(.*)@([^.]*)");
	 * 	String text(L"test@email.com");
	 *	String rewrite(L"\\2!\\1");
	 *
	 *	RegularExpression regex;
	 *	regex.Construct(pattern);
	 *	ret = regex.Extract(text, rewrite, out);		// out = L"email!test"
	 *
	 * @endcode
	 */
	bool Extract(const Osp::Base::String& text, const Osp::Base::String& rewrite, Osp::Base::String& out) const;


	/**
	 * Compares the specified instance to the calling instance.
	 *
 	 * @since	2.0
 	 *
	 * @return		@c true if the specified instance is equal to the current instance, @n
	 *				else @c false
	 * @param[in]	obj	The object to be compared with the current instance
	 * @remarks 	The method returns @c true if all the attributes in the instance are the same.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
 	 * @since	2.0
 	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;	
	

// Accessor
public:

	/**
	* Gets the pattern used to compile the regular expression.
	*
	* @since	2.0
	*
	* @return 	The pattern used to compile the regular expression. An empty string if this instance is not initialized.
	*/
	Osp::Base::String GetPattern(void) const;


	/**
	 * Sets the value of the regular expression options.  
	 *
 	 * @since	2.0
 	 *
	 * @param[in]		options	         The logical OR operator values of RegularExpressionOptions
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The value of the @c options is invalid.
	 */
	result SetOptions(unsigned long options);


	/**
	 * Gets the value of the regular expression options.
	 *
 	 * @since	2.0
 	 *
	 * @return			The logical OR operator values of RegularExpressionOptions
	 */
	unsigned long GetOptions(void) const;


private:
	friend class RegularExpressionEx;
	class RegularExpressionEx* __pRegexEx;

};
}; };  }; // Osp::Base::Utility
#endif // _FBASE_UTIL_REGEX_H_

