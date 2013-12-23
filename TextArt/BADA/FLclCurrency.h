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
 * @file		FLclCurrency.h 
 * @brief		This is the header file for the %Currency class.
 *
 * This header file contains the declarations of the %Currency class.
 *  
 */
#ifndef	_FLCL_CURRENCY_H_
#define	_FLCL_CURRENCY_H_


// Includes
#include "FBase.h"
#include "FLclConfig.h"

namespace Osp {namespace Locales {

// Forward declaration
class Locale;

/**
 * @class		Currency
 * @brief		This class represents currencies.
 * @since		1.0
 *
 * The %Currency class represents currencies, and is used when the localized currency symbol is retrieved.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/num_symbols_currencies.htm">Number Symbols and Currencies</a>.
 * @see Locale, LanguageCode, CountryCode
 *
 */
class _EXPORT_LOCALES_ Currency
	:public Osp::Base::Object
{

// Constructs Operations
public:

	/** 
	 * Creates an uninitialized instance.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the
     *               Construct() methods must be called explicitly to initialize this instance. 
	 * @see 			Construct()
	 */
	Currency(void);


	/** 
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Currency(void);


	/**
	 * Initializes the instance of %Currency with the specified locale.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		loc							The specified locale to get the currency symbol
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified @c locale is not supported.
	 * @exception		E_SYSTEM					The system has failed during the I/O operations. 
	 */
	result Construct(const Locale& loc);


	/**
	 * Initializes an instance of %Currency with the specified currency code.
	 *
	 * @since				1.0
	 * @return			An error code
	 * @param[in]		currencyCode				The specified currency code to get the currency symbol
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION		The specified currency code is not supported.
	 * @exception		E_SYSTEM					The system has failed during the I/O operations. 
	 */
	result Construct(const Osp::Base::String& currencyCode);
	

// Operations
public:

	/** 
	 * Gets the ISO 4217 currency code for the specified currency.
	 *
	 * @since			1.0
	 * @return		The currency code that is already set
	 * @see				GetSymbol()
	 */
	Osp::Base::String GetCurrencyCode(void) const;


	/** 
	 * Gets the symbol of this currency. @n
	 * The symbol will be localized for the system locale.
	 * For example, if the locale of this currency is kor_KR and the system locale is eng_US,
	 * the symbol will be "KRW"; if the locale of this currency is eng_US and the system locale is kor_KR,
	 * the symbol will be "US$".
	 *
	 * @since				1.0
	 * @return			symbol						The currency symbol string
	 */
	Osp::Base::String GetSymbol(void) const;


	/**
	 * Gets a list of all available currencies.
	 *
	 * @since				1.0
	 * @return			A pointer to an array of %Currency objects @n
     *                   else a @c null pointer is returned if there is no currency available or there is some failure
     *                   The array is a list of all the available currencies.
	 */
	static Osp::Base::Collection::IList* GetAvailableCurrenciesN(void);


private:
	result __GetSymbol(const Locale& inLocale, Osp::Base::String& symbol) const;


private:
	Osp::Base::String __currencyCode;		/* currency code to get the currency symbol */


	friend class NumberFormatter;

private:
	friend class CurrencyEx;
	class CurrencyEx* __pCurrencyEx;
}; // Currency

} } // Osp::Locales

#endif//_FLCL_CURRENCY_H_

