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
 * @file		FLclLocaleManager.h 
 * @brief		This is the header file for the %LocaleManager class.
 *
 * This header file contains the declarations of the %LocaleManager class. 
 *  
 */
#ifndef	_FLCL_LOCALE_MANAGER_H_
#define	_FLCL_LOCALE_MANAGER_H_

// Includes
#include "FBase.h"
#include "FLclConfig.h"
#include "FLclTimeZone.h"
#include "FLclLocale.h"

namespace Osp { namespace Locales {
	class ILocaleManagerPi;
};};

namespace Osp { namespace Locales {

/**
 * @class		LocaleManager
 * @brief		This class is used for the %LocaleManager identification.
 * @since		1.0
 *
 * The %LocaleManager class helps application programmers handle the system locale information of the device. Each device system has at least one installed locale and often has many locales from which the user can choose.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locales/lang_country_codes.htm">Retrieving Language and Country Codes</a>.

 * @see Locale, NumberFormatter, DateTimeFormatter
 *
 * 
 * The following example demonstrates how to use the %LocaleManager class to get and set system locale information.
 *
 * 
 * 
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Osp::Base;
using namespace Osp::Locales;

void
LocaleApp::LocaleExample1(void)
{
	LocaleManager localeManager;
	localeManager.Construct();

	// Gets the system locale information.
	Locale	systemLocale = localeManager.GetSystemLocale();

	String countryCodeString = systemLocale.GetCountryCodeString();
	String languageCodeString = systemLocale.GetLanguageCodeString();
	String variantCodString = systemLocale.GetVariantCodeString();

	// Gets the formatted number that is localized.
	NumberFormatter* pNumberFormatter = NumberFormatter::CreateNumberFormatterN(systemLocale);

	String formattedString;
	long inputNumber = 123456;
	pNumberFormatter->Format((long) inputNumber, formattedString);

	// Gets the formatted date/time that is localized.
	DateTimeFormatter* pDateTimeFormatter = DateTimeFormatter::CreateDateTimeFormatterN(systemLocale);
	DateTime dateTime(2009, 2, 24, 15, 22, 00);
	pDateTimeFormatter->Format(dateTime, formattedString);

	// Gets the currency symbol that is localized.
	NumberFormatter* pCurrencyFormatter = NumberFormatter::CreateCurrencyFormatterN(systemLocale);
	inputNumber = 4000;
	pCurrencyFormatter->Format(inputNumber, formattedString);


	delete pNumberFormatter;
	delete pDateTimeFormatter;
	delete pCurrencyFormatter;
}

@endcode
 *
 * The following example demonstrates how to use the %LocaleManager class to get a list of all the available locales from the system.
 *
 * @code

#include <FBase.h>
#include <FLocales.h>

using namespace Osp::Base;
using namespace Osp::Locales;

void
LocaleApp::LocaleExample2(void)
{
	 LocaleManager localeManager;
	 localeManager.Construct();

	 IList* pAvailableLocales = localeManager.GetAvailableLocalesN();
	 if (pAvailableLocales)
	 {
		 for (int i = 0; i < pAvailableLocales->GetCount(); i++)
		 {
			 Locale* pLocale = (Locale*) (pAvailableLocales->GetAt(i));

			 String languageCodeString = pLocale->GetLanguageCodeString();
			 String countryCodeString = pLocale->GetCountryCodeString();
			 String variantCodString = pLocale->GetVariantCodeString();

			 ...
		 }
	 }
}

@endcode

 *
 */
class _EXPORT_LOCALES_ LocaleManager :
	public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of %LocaleManager, one of the
     *              Construct() methods must be called explicitly to initialize this instance.
	 * @see 			Construct()
	 * 
	 */
	LocaleManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~LocaleManager(void);

	/**
	* Initializes this instance of %LocaleManager.
	* 
	* @since					1.0
	* @return					An error code
	* @exception			E_SUCCESS					The method is successful.
	* @exception			E_SYSTEM					A system error has occurred.
	*/
	result Construct(void);


	/** 
	 * Gets the system locale of the device.
	 * 
	 * @since					1.0
	 * @return				An instance of system Locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 *						The resulting Locale instance is Locale (LANGUAGE_INVALID, COUNTRY_INVALID).
	 */
	Locale GetSystemLocale(void);


	/**
	 * Gets a list of all the available locales.
	 * 
	 * @since					1.0
	 * @return				A list of Locale instances, @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The IList returned contains the list of all the locales installed on the system.
	 *						The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetAvailableLocalesN(void);


	/**
	 * Gets the currently selected language of the device by a user from the user setting menu.
	 *
	 * @since					1.0
	 * @return				An instance of String (ISO 639-2 code format), @n
	 *						else empty string if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetSelectedLanguage(void);


	/**
	 * Gets the whole list of languages supported by the device, which can be different according to the target country/region of the device.
	 *
	 * @since					1.0
	 * @return				A list of String instances (ISO 639-2 code format), @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetAvailableLanguagesN(void);


	/** 
	 * Gets a list of all the available time zone IDs.
	 *
	 * @since					1.0
	 * @return				A list of String instances, @n
	 *						else @c null if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::Collection::IList* GetAvailableTimeZonesN(void);


	/** 
	 * Gets a list of all the available time zone IDs with the specified Greenwich Mean Time (GMT) offset for this time zone.
	 *
	 * @since					1.0
	 * @return				A list of String instances, @n
	 *						else @c null if the method fails
	 * @param[in]			rawOffset					The specified GMT offset for this time zone (Daylight Saving Time (DST) is not considered) @n
	 *													The value of @c rawOffset is in minutes.
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 *      				If there are no time zones for the specified GMT offset, an empty list is returned.
	 */
	Osp::Base::Collection::IList* GetAvailableTimeZonesN(int rawOffset);


	/**
	 * Gets the default system time zone.
	 * 
	 * @since					1.0
	 * @return				The default system time zone, @n
     *                      else the time zone name is an empty string and the offset is @c -1 if the method fails
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet.
	 * @remarks				The specific error code can be accessed using the GetLastResult() method.
	 */
	TimeZone GetSystemTimeZone(void); 


	/**
	 * Checks whether the specified instance of %Locale is supported.
	 *
	 * @since					1.0
	 * @return				An error code
	 * @param[in]			locale						An instance of Locale
	 * @param[out]			isSupportedLocale			The flag for checking the supported locale
	 * @exception			E_SUCCESS					The method is successful.
	 * @exception			E_SYSTEM					A system error has occurred.
	 * @exception			E_INVALID_STATE				This instance has not been constructed as yet. 
	 */
	result IsSupportedLocale(const Locale& locale, bool& isSupportedLocale);

private:
	Osp::Base::Collection::IList* __GetTimeZoneListN(int rawOffset);
	Osp::Base::Collection::IList* __GetLocaleListN(void);


private:
	LocaleManager(const LocaleManager& localeManager);
	LocaleManager& operator=(const LocaleManager& localeManager);

	ILocaleManagerPi*		__pILocaleManagerPi;


private:
	friend class LocaleManagerEx;
	class LocaleManagerEx* __pLocaleManagerEx;
}; // Locale 


}; };// Osp::Locales

#endif//_FLCL_LOCALE_MANAGER_H_

