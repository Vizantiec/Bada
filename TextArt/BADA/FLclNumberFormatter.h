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
 * @file		FLclNumberFormatter.h 
 * @brief		This is the header file for the %NumberFormatter class.
 *
 * This header file contains the declarations of the %NumberFormatter class.
 *  
 */
#ifndef	_FLCL_NUMBER_FORMATTER_H_
#define	_FLCL_NUMBER_FORMATTER_H_

// Includes
#include "FBaseObject.h"
#include "FLclConfig.h"
#include "FLclLocale.h"
#include "FLclCurrency.h"
#include "FLclNumberSymbols.h"
#include "FLclDateTimeFormatter.h"

namespace Osp { namespace Locales {
	class __Digit;
	class __FieldPosition;
};};


namespace Osp { namespace Locales {
/**
 * @class		NumberFormatter
 * @brief		This class provides methods for formatting numbers.
 * @since		1.0
 *
 * The %NumberFormatter class is used to format all number formats, including decimal and real numbers, currency, and percentage for any locale. It also provides methods to determine the locales that have number formats and their names. You can write codes completely independent of the locale conventions for decimal points, thousand separators as well as of the specific decimal digits used or whether the number format is a decimal. A normal decimal number can also be displayed as a currency or as a percentage.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/num_formatter.htm">Number Formatters</a>.
 *
 * The following example demonstrates how to use the %NumberFormatter class.
 *
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Osp::Base;
using namespace Osp::Locales;

void
LocaleApp::NumberFormatterExample(void)
{
	// Construct locale
	Locale koreaLoc(LANGUAGE_KOR, COUNTRY_KR);

	// Get number formatter
	NumberFormatter* pNumberFormatter = NumberFormatter::CreateNumberFormatterN(koreaLoc);

	String formattedString;

	// Format number with number formatter
	double num = 345987.246;
	pNumberFormatter->Format(num, formattedString);

	// Get currency formatter
	NumberFormatter* pCurrencyFormatter = NumberFormatter::CreateCurrencyFormatterN(koreaLoc);

	// Format number with currency formatter
	num = 100321;
	pCurrencyFormatter->Format(num, formattedString);

	// Get percent formatter
	NumberFormatter* pPercentFormatter = NumberFormatter::CreatePercentFormatterN(koreaLoc);

	// Format number with percent formatter
	num = 0.5;
	pPercentFormatter->Format(num, formattedString);


	delete pNumberFormatter;
	delete pCurrencyFormatter;
	delete pPercentFormatter;
}
@endcode
 *
 */

class _EXPORT_LOCALES_ NumberFormatter :
	public Osp::Base::Object
{
// Static Method
public:
	/**
	 * Creates a number formatter for the default locale.
	 * 
	 * @since					1.0
	 * @return				A pointer to the general number formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateNumberFormatterN(void);


	/**
	 * Creates a number formatter for the specified locale.
	 * 
	 * @since					1.0
	 * @return				A pointer to a general number formatter for the specified locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateNumberFormatterN(const Locale& locale);


	/**
	 * Creates a currency formatter for the default locale.
	 * 
	 * @since					1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 				For more information, see @ref NumberFormatterCreateCurrencyFormatterNPage "here".
	 *
	 * @return				A pointer to a currency formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateCurrencyFormatterN(void);


	/**
	 * Creates a currency formatter for the specified locale.
	 * 
	 * @since					1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 				For more information, see @ref NumberFormatterCreateCurrencyFormatterNPage "here".
	 *
	 * @return				A pointer to a currency formatter for the specified locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreateCurrencyFormatterN(const Locale& locale);


	/**
	 *
	 * @page	NumberFormatterCreateCurrencyFormatterNPage Compatibility for CreateCurrencyFormatterN ()
	 *
	 * @section	NumberFormatterCreateCurrencyFormatterNPage IssueSection Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *			-# The decimal separator is incorrectly handled when the input parameter has one of the following locale:
	 *				-   Spanish (spa_US, spa_MX)
	 *			    -   Russian (rus_RU)
	 *				-   Swedish (swe_SE)
	 *			    -   Turkish (tur_TR) @n
	 *			For example, when the input value is '1000.45' for Spanish (spa_US), it is incorrectly displayed as 
	 *		   '1,000,45' instead of '1,000.45'.
	 * @section	NumberFormatterCreateCurrencyFormatterNPageSolutionSection Resolutions
	 *			The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.

	 */


	/**
	 * Creates a percentage formatter for the current default locale.
	 * 
	 * @since					1.0
	 * @return				A pointer to a percentage formatter for the default locale, @n
	 *						else @c null if an error occurs
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The current locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreatePercentFormatterN(void);


	/**
	 * Creates a percentage formatter for the specified locale.
	 * 
	 * @since					1.0
	 * @return				A pointer to a percentage formatter for the specified locale, @n
	 *						else @c null if an error occurs
	 * @param[in]			locale						An instance of Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	static NumberFormatter* CreatePercentFormatterN(const Locale& locale);


// Construct Operations
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~NumberFormatter(void);


// Operations
public:

	/**
	 * Formats a number of type Long to type String and appends the resulting string to a buffer.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			number						The number of type Long to format
	 * @param[out]			str							The string to append to the resultant string
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance is in an invalid state. @n
	 *													After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 */	
	virtual result Format(long number, Osp::Base::String& str) const;


	/**
	 * Formats a number of type Double to type String and appends the resulting string to a buffer.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			number						The number of type Double to format
	 * @param[out]			str							The string to append to the resultant string
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance is in an invalid state. @n
	 *													After creating an instance by calling CreateXxxFormatterN(), this method can be called.
	 */	
	virtual result Format(double number, Osp::Base::String& str) const;


	/** 
	 * Gets the currency used by the current number format when formatting currency values.
	 *
	 * @since				1.0
	 * @return			A pointer to an instance of currency
	 * @remarks			The initial value is derived in a locale dependent way. @n
	 *					The returned value may be @c null if no valid currency is determined 
	 *					or no currency has been set using the SetCurrency() method.
	 * @see				SetCurrency()
	 */
	virtual const Currency* GetCurrency(void) const;
	

	/** 
	 * Sets the currency used by the current number format when formatting currency values.
	 *
	 * @since				1.0
	 * @param[in]		currency			The new currency to be used by the current number format
	 * @remarks			This does not update the minimum or maximum number of fractional digits used by the number format.
	 * @see					GetCurrency()
	 */
	virtual void SetCurrency(const Currency& currency);


	/** 
	 * Gets the maximum number of digits allowed in the integer portion of a number.
	 *
	 * @since				1.0
	 * @return			An integer value representing the maximum number of digits allowed in the integer portion of a number
	 * @see					SetMaxIntegerDigits()
	 */
	virtual int GetMaxIntegerDigits(void) const;
	

	/** 
	 * Sets the maximum number of digits allowed in the integer portion of a number. 
	 *
	 * @since				1.0
	 * @param[in]		newValue				The maximum number of integer digits allowed in the integer portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The maximum integer digits must be greater than or equal to the minimum integer digits.
	 *					If the new value for the maximum integer digits is less than the current value of the minimum integer digits,
	 *					the minimum integer digits are also set to the new value.
	 * @see					GetMaxIntegerDigits()
	 */
	virtual void SetMaxIntegerDigits(int newValue);


	/** 
	 * Gets the minimum number of digits allowed in the integer portion of a number. 
	 *
	 * @since				1.0
	 * @return			An integer value representing the minimum number of digits allowed in the integer portion of a number
	 * @see					SetMinIntegerDigits()
	 */
	virtual int GetMinIntegerDigits(void) const;
	

	/** 
	 * Sets the minimum number of digits allowed in the integer portion of a number.
	 *
	 * @since				1.0
	 * @param[in]		newValue				The minimum number of integer digits allowed in the integer portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The minimum integer digits must be less than or equal to the maximum integer digits.
	 *					If the new value for the minimum integer digits exceeds the current value of the maximum integer digits,
	 *					the maximum integer digits are also set to the new value.
	 * @see					GetMinIntegerDigits()
	 */
	virtual void SetMinIntegerDigits(int newValue);


	/** 
	 * Gets the maximum number of digits allowed in the fractional portion of a number. 
	 *
	 * @since				1.0
	 * @return			An integer value representing the maximum number of digits allowed in the fractional portion of a number
	 * @see					SetMaxFractionDigits()
	 */
	virtual int GetMaxFractionDigits(void) const;
	

	/** 
	 * Sets the maximum number of digits allowed in the fractional portion of a number.
	 *
	 * @since				1.0
	 * @param[in]		newValue				The maximum number of fractional digits allowed in the fractional portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The maximum fractional digits must be greater than or equal to the minimum fractional digits.
	 *					If the new value for the maximum fractional digits is less than the current value of the minimum fractional digits,
	 *					the minimum fractional digits are also set to the new value.
	 * @see					GetMaxFractionDigits()
	 */
	virtual void SetMaxFractionDigits(int newValue);


	/** 
	 * Gets the minimum number of digits allowed in the fractional portion of a number. 
	 *
	 * @since				1.0
	 * @return			An integer value representing the minimum number of digits allowed in the fractional portion of a number
	 * @see					SetMinFractionDigits()
	 */
	virtual int GetMinFractionDigits(void) const;
	

	/** 
	 * Sets the minimum number of digits allowed in the fractional portion of a number.
	 *
	 * @since				1.0
	 * @param[in]		newValue				The minimum number of fractional digits allowed in the fractional portion of a number @n
	 *											If less than zero, @c 0 is used.
	 * @remarks			The minimum fractional digits must be less than or equal to the maximum fractional digits.
	 *					If the new value for the minimum fractional digits exceeds the current value of the maximum fractional digits,
	 *					the maximum fraction digits are also set to the new value.
	 * @see					GetMinFractionDigits()
	 */
	virtual void SetMinFractionDigits(int newValue);


	/** 
	 * Checks whether the grouping is used in the current instance of %NumberFormatter.
	 *
	 * @since				1.0
	 * @return			@c true if grouping is used in the current instance of %NumberFormatter, @n
	 *					else @c false
	 * @remarks			For example, in the English locale, with grouping on, the number 1234567 
	 *					might be formatted as "1,234,567". 
	 *					The grouping separator as well as the size of each group is locale dependent 
	 *					and is determined by subclasses of %NumberFormatter. 
	 * @see					SetGroupingUsed()
	 */
	virtual bool IsGroupingUsed(void) const;


	/** 
	 * Sets the current instance of %NumberFormatter to use or not to use grouping.
	 *
	 * @since				1.0
	 * @param[in]		newValue				Set to @c true if grouping is to be used in the current formatter, @n
	 *											else @c false
	 * @see					IsGroupingUsed()
	 */
	 virtual void SetGroupingUsed(bool newValue);


	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @enum AlignmentField
	 * Defines the style for field alignment.
	 *
	 * @since				1.0
	 */
	enum AlignmentField
	{
		ALIGNMENT_FIELD_INTEGER,		/**< The AlignmentField for integer */
		ALIGNMENT_FIELD_FRACTION		/**< The AlignmentField for fraction */
	};

protected:

// Construct Operations

	/**
	 * This is the default constructor for this class. @n
     * Creates an uninitialized instance.
	 *
	 * @since				1.0
	 * @remarks		After creating an instance of this class, the Construct() method
	 *				must be called explicitly to initialize this instance. 
	 * @see Construct()
	 */
	NumberFormatter(void);


// Attribute

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * Internal variable.
	 *
	 * @since 1.0
	 */
	Locale __locale;

public:

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @enum PadPosition
	 * Defines the pad position type.
	 *
	 * @since				1.0
	 */
	enum PadPosition 
	{
		PAD_BEFORE_PREFIX, /**< The pad position for before prefix */
		PAD_AFTER_PREFIX,  /**< The pad position for after prefix */
		PAD_BEFORE_SUFFIX, /**< The pad position for before suffix */
		PAD_AFTER_SUFFIX,  /**< The pad position for after suffix */
		PAD_UNDEFINED      /**< The undefined pad position */
	};

	// Operations
public:
	/** 
	* Applies the specified pattern to the current instance of %NumberFormatter.
	*
	* @since				1.0
	* @return				An error code
	* @param[in]		pattern						The new pattern
	* @param[in]		localized					The localization On/Off flag @n
	*												Set to @c true if the pattern is applied with the localized symbols, @n
	*                                               else @c false 
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c pattern is invalid or its length is @c 0.
	*/
	result ApplyPattern(const Osp::Base::String& pattern, bool localized);


	/**
	* Gets the positive prefix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @return			The positive prefix of the current %NumberFormatter instance
	* @remarks		Example: +123, $123, sFr123. 
	* @see				SetPositivePrefix()
	*/
	Osp::Base::String GetPositivePrefix(void) const;


	/** 
	* Sets a new value for the positive prefix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @param[in]	newValue				The new positive prefix
	* @see				GetPositivePrefix()
	*/
	void SetPositivePrefix(const Osp::Base::String& newValue);


	/** 
	* Gets the negative prefix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @return			The negative prefix of the current %NumberFormatter instance
	* @remarks		Example: -123, $123 (with negative prefix), sFr-123 
	* @see				SetNegativePrefix()
	*/
	Osp::Base::String GetNegativePrefix(void) const;


	/** 
	* Sets a new value for the negative prefix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @param[in]	newValue					The new negative prefix
	* @see				GetNegativePrefix()
	*/
	void SetNegativePrefix(const Osp::Base::String& newValue);


	/** 
	* Gets the positive suffix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @return			The positive suffix of the current %NumberFormatter instance
	* @remarks		Example: 123% 
	* @see				SetPositiveSuffix()
	*/
	Osp::Base::String GetPositiveSuffix(void) const;


	/** 
	* Sets a new value for the positive suffix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @param[in]	newValue					The new positive suffix
	* @see				GetPositiveSuffix()
	*/
	void SetPositiveSuffix(const Osp::Base::String& newValue);


	/** 
	* Gets the negative suffix of the current instance of %Numberformatter.
	*
	* @since			1.0
	* @return			The negative suffix of the current %NumberFormatter instance
	* @remarks		Example: -123%, $123 (with negative suffix) 
	* @see				SetNegativeSuffix()
	*/
	Osp::Base::String GetNegativeSuffix(void) const;


	/** 
	* Sets a new value for the negative suffix of the current instance of %NumberFormatter.
	*
	* @since			1.0
	* @param[in]	newValue					The new negative suffix
	* @see				GetNegativeSuffix()
	*/
	void SetNegativeSuffix(const Osp::Base::String& newValue);


	/** 
	* Gets the multiplier for use in percent, per mill, and so on.
	*
	* @since			1.0
	* @return			An integer value representing the multiplier
	* @remarks		Example: with 100, 1.23 -> "123", and "123" -> 1.23
	* @see				SetMultiplier()
	*/
	int GetMultiplier(void) const;


	/** 
	* Sets a new value for the multiplier for use in percent, per mill, and so on.
	*
	* @since				1.0
	* @param[in]		newValue					The new value for the multiplier
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified input parameter is invalid.
	* @remarks		For example, in percentage, set the suffixes to have "%" and the multiplier to be 100.
	* @see					GetMultiplier()
	*/
	result SetMultiplier(int newValue);


	/** 
	* Gets the grouping size.
	*
	* @since			1.0
	* @return			An integer value representing the grouping size
	* @remarks		Grouping size is the number of digits between grouping separators in the integer portion of a number. @n 
	*					For example, in the number "123,456.78", the grouping size is 3.
	* @see				SetGroupingSize(), IsGroupingUsed()
	*/
	int GetGroupingSize(void) const;


	/** 
	* Sets a new value for the grouping size.
	*
	* @since				1.0
	* @param[in]		newValue					The new value for the grouping size
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified input parameter is invalid.
	* @see					GetGroupingSize(), SetGroupingUsed()
	*/
	result SetGroupingSize(int newValue);


	/** 
	* Checks whether the decimal separator is always shown.
	*
	* @since			1.0
	* @return			@c true if the decimal separator is always shown, @n
	*					else @c false
	* @remarks			Example: ON: 12345 -> 12345.; OFF: 12345 -> 12345.
	* @see				SetDecimalSeparatorAlwaysShown()
	*/
	bool IsDecimalSeparatorAlwaysShown(void) const;


	/** 
	* Sets the behavior of the decimal separator. @n
	* The decimal separator can be set to always appear using this method.
	*
	* @since				1.0
	* @param[in]		newValue				Set to @c true if the decimal separator is to be always shown, @n
	*											else @c false
	* @see					IsDecimalSeparatorAlwaysShown()
	*/
	void SetDecimalSeparatorAlwaysShown(bool newValue);


	/** 
	* Checks whether the positive sign is always shown.
	*
	* @since			1.0
	* @return			@c true if the positive sign is always shown, @n
	*					else @c false
	* @remarks			Example: ON: 12345 -> +12345.; OFF: 12345 -> 12345.
	* @see				SetPositiveSignAlwaysShown()
	*/
	bool IsPositiveSignAlwaysShown(void) const;


	/** 
	* Sets the behavior of the plus sign. @n
	* The plus sign can be set to always appear using this method.
	*
	* @since				1.0
	* @param[in]		newValue				Set to @c true if the plus sign is to be always shown, @n
	*											else @c false
	* @see					IsPositiveSignAlwaysShown()
	*/
	void SetPositiveSignAlwaysShown(bool newValue);


private:
	/*
	 * @enum Style
	 * Defines the number format.
	 */
	enum Style
	{	
		STYLE_NUMBER,
		STYLE_CURRENCY,
		STYLE_PERCENT,
		STYLE_COUNT
	};

	/**
	 * Creates an instance of NumberFormatter with the specified locale and style. Creates an instance and returns an instance of NumberFormatter with the specified locale and style,
	 * or it returns @c null if some error occurs.
	 *
	 * @return			A pointer to the newly created instance of NumberFormatter @n
	 *					@c null, if an error occurs
	 * @param[in]		locale						An instance of Locale
	 * @param[in]		style						The desired style
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_SYSTEM					Failed during I/O operations internally.
	 */
	static NumberFormatter* CreateInstanceN(const Locale& locale, Style style);


	// Operation

	/**
	* Initializes the attributes of the current instance.
	*
	* @return			An error code
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_SYSTEM					Failed during I/O operations internally.
	*/
	result Initialize(const Osp::Base::String& pattern, const NumberSymbols* symbols);


	/**
	* Sets the currency symbol of this DecimalFormat with the locale of symbol.
	*
	* @return			An error code
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_SYSTEM					Failed during I/O operations internally.
	*/
	result SetCurrencyForSymbols(void);


	/** 
	* Gets the character used for number format.
	*
	* @return			A String representing the number symbol
	* @param[in]		symbol						The instance of NumberFormatter to get the number symbol
	* @see				NumberSymbols::GetConstNumberSymbol()
	*/
	const Osp::Base::String GetNumberSymbol(NumberSymbol symbol) const;


	/**
	* Expands the affix pattern strings into the expanded affix strings.
	*/
	void ExpandAffixes(void);


	/**
	* Expands an affix pattern into an affix string.
	*
	* @param[in]		pattern						The affix pattern
	* @param[out]		affix						The affix string extended via pattern
	*/
	void ExpandAffix(const Osp::Base::String& pattern, Osp::Base::String& affix) const;


	/**
	* Appends an affix string to the specified String.
	* 
	* @return			An integer value representing the length of the appended string
	* @param[in]		isNegative					The value to check whether negative values are present
	* @param[in]		isPrefix					The value to check whether prefix symbols are present
	* @param[out]		str							The appended string
	*/
	int AppendAffix(bool isNegative, bool isPrefix, Osp::Base::String& str) const; 


private:
	/**
	* Initializes an instance of DecimalFormat with the specified pattern and the symbols for the default locale.
	*
	* @return			An error code
	* @param[in]		locale						The given locale
	* @param[in]		pattern						A non-localized pattern string
	* @param[in]		pSymbols					The set of symbols to be used
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c pattern is invalid or its length is 0.
	* @see				NumberFormatter::CreateNumberFormatterN(), NumberFormatter::CreateCurrencyFormatterN(), NumberFormatter::CreatePercentFormatterN()
	*/
	result Construct(const Locale& locale, const Osp::Base::String& pattern, NumberSymbols* pSymbols = null);


	/**
	 * Formats a @c long value into a number string and appends the resulting string to the specified string buffer.
	 *
	 * @param[in]		number						The @c long number to format
	 * @param[in]		pos							On input: an alignment field, if desired @n
	 *												On output: the offsets of the alignment field
	 * @param[out]		str							The String to which the resulting string is to be appended
	 */	
	virtual void Format(long number, __FieldPosition& pos, Osp::Base::String& str) const;


	/**
	 * Formats a @c double value into a number string and appends the resulting string to the specified string buffer.
	 *
	 * @param[in]		number						The @c double number to format
	 * @param[in]		pos							On input: an alignment field, if desired @n
	 *												On output: the offsets of the alignment field
	 * @param[out]		str							The String to which the resulting string is to be appended
	 */	
	virtual void Format(double number, __FieldPosition& pos, Osp::Base::String& str) const;


	/**
	* Formats a real number and appends the resulting string to the specified string buffer.
	*
	* @param[in]			digit					The digit instance
	* @param[in]			pos						On input: an alignment field, if desired @n
	*												On output: the offsets of the alignment field
	* @param[out]			str						The String to which the resulting string is to be appended
	* @param[in]			isInteger				The value to check integer or not
	*/
	void SubFormat(__Digit& digit, __FieldPosition& pos, Osp::Base::String& str, bool isInteger) const;


	/**
	* Checks whether the specified position is a grouping position.
	*
	* @return				@c true if the specified position is a grouping position, @n
	*						else @c false
	* @param[in]			pos						The grouping position
	*/
	bool IsGroupingPosition(int pos) const; 


	/**
	* Gets the maximum fraction digit.
	* 
	* @return				An integer value representing the maximum fraction digit if @c isIntegral is @c false, @n
	*						else @c 0
	* @param[in]			isIntegral				The value to check integer or not
	*/
	int Precision(bool isIntegral) const; 


	/**
	* Inserts the character __pad as needed to expand result to __formatWidth.
	* 
	* @param[in]			fieldPosition			The field position
	* @param[in]			prefixLen				The length of prefix
	* @param[in]			suffixLen				The length of suffix
	* @param[out]			str						The string with the added padding
	*/
	void AddPadding(__FieldPosition& fieldPosition, int prefixLen, int suffixLen, Osp::Base::String& str) const;


// Attribute
private:
	static const int MAX_INTEGER_DIGITS;
	static const int MIN_INTEGER_DIGITS;

	bool __groupingUsed;
	int	 __maxIntegerDigits;
	int  __minIntegerDigits;
	int	 __maxFractionDigits;
	int  __minFractionDigits;
	Currency* __pCurrency;
	NumberSymbols* __pSymbols;

	Osp::Base::String __positivePrefix;
	Osp::Base::String __positiveSuffix;
	Osp::Base::String __negativePrefix;
	Osp::Base::String __negativeSuffix;
	Osp::Base::String __positivePrefixPattern;
	Osp::Base::String __positiveSuffixPattern;
	Osp::Base::String __negativePrefixPattern;
	Osp::Base::String __negativeSuffixPattern;

	int __multiplier;
	int __groupingSize;
	bool __decimalSeparatorAlwaysShown;
	bool __isCurrencyFormat;
	bool __exponentSignAlwaysShown;
	bool __isUsedExponentialNotation;
	bool __isPositiveSignAlwaysShown;

	mchar __pad;
	int __formatWidth;
	PadPosition __padPosition;

	bool __isConstructed;

	friend class DateTimeFormatter;


private:
	friend class NumberFormatterEx;
	class NumberFormatterEx* __pNumberFormatterEx;

}; // NumberFormatter

}; };// Osp::Locales

#endif//_FLCL_NUMBER_FORMATTER_H_
