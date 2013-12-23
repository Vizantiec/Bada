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
 * @file		FLclNumberSymbols.h 
 * @brief		This is the header file for the %NumberSymbols class.
 *
 * This header file contains the declarations of the %NumberSymbols class.
 *  
 */
#ifndef	_FLCL_NUMBER_SYMBOLS_H_
#define	_FLCL_NUMBER_SYMBOLS_H_

// Includes
#include "FLclLocale.h"

namespace Osp { namespace Locales {


// Enums and Constants

/**
 * @enum	NumberSymbol
 * Defines the possible formats for number symbols. @n
 *
 * This enumeration represents the possible symbols for %NumberFormatter.  
 *
 * @since		1.0
 */
enum NumberSymbol 
{ 
		NUMBER_SYMBOL_DECIMAL_SEPARATOR,		/**< The decimal separator */
		NUMBER_SYMBOL_GROUPING_SEPARATOR,		/**< The grouping separator */
		NUMBER_SYMBOL_PATTERN_SEPARATOR,		/**< The pattern separator */ 
		NUMBER_SYMBOL_PERCENT,					/**< The percent symbol */
		NUMBER_SYMBOL_ZERO_DIGIT,				/**< The zero symbol*/
		NUMBER_SYMBOL_DIGIT,					/**< The character representing a digit in the pattern */
		NUMBER_SYMBOL_CURRENCY,					/**< The currency symbol */
		NUMBER_SYMBOL_INTL_CURRENCY,			/**< The international currency symbol */
		NUMBER_SYMBOL_MONETARY_SEPARATOR,		/**< The monetary separator */
		NUMBER_SYMBOL_PER_MILL,					/**< The per mil symbol */
		NUMBER_SYMBOL_EXPONENTIAL,				/**< The exponential symbol */
		NUMBER_SYMBOL_PLUS_SIGN,				/**< The plus sign */
		NUMBER_SYMBOL_MINUS_SIGN,				/**< The minus sign */
		NUMBER_SYMBOL_COUNT					/**< The number of symbol */
};


/**
 * @class		NumberSymbols
 * @brief		This class provides methods that help in providing number symbols.
 * @since		1.0
 *
 * The %NumberSymbols class represents the set of symbols (such as the decimal separator and the grouping separator) needed by %NumberFormatter to format numbers.
 * %NumberFormatter creates its own instance of %NumberSymbols from its locale data. %NumberSymbols can be adopted by a %NumberFormatter instance, or it can be specified when a %NumberFormatter is created. If you need to change any of these symbols, you can get the %NumberSymbols instance from your %NumberFormatter and then modify it.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/num_symbols_currencies.htm">Number Symbols and Currencies</a>. 
 */
class _EXPORT_LOCALES_ NumberSymbols :
	public Osp::Base::Object
{
// Construct Operations
public:

	/** 
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called
	 *				to initialize this instance. 
	 * @see Construct()
	 */
	NumberSymbols(void);

	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~NumberSymbols(void);


// Operations
public:

	/** 
	 * Initializes this instance of %NumberSymbols with the specified @c locale.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 */
	result Construct(const Locale& locale);

	/** 
	 * Returns the character used for number format.
	 *
	 * @since					1.0
	 * @return				The character used for number format, @n
	 *						else an empty string if this instance has not been constructed as yet
	 * @param[in]			symbol						The number format symbol instance
	 * @see						SetNumberSymbol()
	 */
	Osp::Base::String GetNumberSymbol(NumberSymbol symbol) const;


	/** 
	 * Replaces the character used for number format.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			symbol						A symbol to be set
	 * @param[in]			str							The new string for symbol
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet. 
	 * @see						GetNumberSymbol()
	 */
	result SetNumberSymbol(NumberSymbol symbol, const Osp::Base::String& str);


	/** 
	 * Gets the current locale.
	 *
	 * @since					1.0
	 * @return 				A pointer to the current instance of Locale, @n
	 *						else @c null if this instance has not been constructed as yet
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	const Locale* GetLocale(void) const;


private:
	NumberSymbols(const NumberSymbols& other);
	NumberSymbols& operator=(const NumberSymbols& other);


// Attribute
private:
	Locale __locale;
	Osp::Base::String __symbols[NUMBER_SYMBOL_COUNT];


private:
	friend class NumberSymbolsEx;
	class NumberSymbolsEx* __pNumberSymbolsEx;

}; // NumberSymbols

} }// Osp::Locales

#endif//_FLCL_NUMBER_SYMBOLS_H_

