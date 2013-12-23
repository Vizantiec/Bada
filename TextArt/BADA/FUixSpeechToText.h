/* $Change: 618169 $ */
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
 * @file			FUixSpeechToText.h
 * @brief			This is the header file for the %SpeechToText class.
 *
 * This header file contains the declarations of the %SpeechToText class.
 */


#ifndef _FUIX_SPEECH_TO_TEXT_H_
#define _FUIX_SPEECH_TO_TEXT_H_

// Include
#include "FBaseObject.h"
#include "FLocales.h"
#include "FUixConfig.h"
#include "FUixSpeechToTextCommon.h"
#include "FUixISpeechToTextEventListener.h"

namespace Osp { namespace Uix { class ISpeechToTextPi; };};

namespace Osp{ namespace Uix{ 

/**
* @class	SpeechToText
* @brief	This class is used to convert spoken words to text.
* @deprecated	This class is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
* @since	2.0
*
* The %SpeechToText class converts spoken words into text.
* 
* The following example demonstrates how to use the %SpeechToText class.
* In the example, the Start() method is called after invoking the ISpeechToTextEventListener::OnSpeechToTextInitialized() 
* method.
*
* @code
*  	//Sample Code for SpeechToTextSample.h
*  	#include <FUix.h>
*
* 	using namespace Osp::Uix;
*
*	class SpeechToTextSample : public ISpeechToTextEventListener
*	{
*	  	public:
*	  		SpeechToTextSample(void);
*	  		virtual ~SpeechToTextSample(void);
*	  		bool Initialize(void);
*	  		virtual void OnSpeechToTextInitialized ( void );
*	  		virtual void OnSpeechToTextRecordingStatusChanged(Osp::Uix::SpeechToTextRecordingStatus status);
*	  		virtual void OnSpeechToTextErrorOccurred(Osp::Uix::SpeechToTextError error);
*	  		virtual void OnSpeechToTextCompleted(Osp::Base::String& result, Osp::Uix::SpeechToTextWarning warning);
*
*	  	private:
*	  		Osp::Uix::SpeechToText *__pSpeechToText;
*	};
*
*	//Sample Code for SpeechToTextSample.cpp
*	#include "SpeechToTextSample.h"
*
*	SpeechToTextSample::SpeechToTextSample(void)
*	{
*	}
*
*	SpeechToTextSample::~SpeechToTextSample(void)
*	{
*	}
*
*	void SpeechToTextSample::OnSpeechToTextInitialized ( void )
*	{
*		__pSpeechToText->Start();
*	}
*
*	void SpeechToTextSample:: OnSpeechToTextRecordingStatusChanged( Osp::Uix::SpeechToTextRecordingStatus status )
*	{
*		// Add your code
*	}
*
*	void SpeechToTextSample::OnSpeechToTextErrorOccurred( Osp::Uix::SpeechToTextError error )
*	{
*		// Add your code
*	}
*
*	void SpeechToTextSample::OnSpeechToTextCompleted( Osp::Base::String& result, Osp::Uix::SpeechToTextWarning warning )
*	{
*		// Add your code
*	}
*
*	bool SpeechToTextSample::Initialize(void)
*	{
*		result r = E_SUCCESS;
*
*		__pSpeechToText = new SpeechToText();
*		r = __pSpeechToText->Construct(*this);
*		if(IsFailed(r))
*		{
*				return false;
*		}
*		r = __pSpeechToText->Initialize();
*		if(IsFailed(r))
*		{
*				return false;
*		}
*	  	return true;
*	}
*
* @endcode
*/

class _EXPORT_UIX_ SpeechToText:
	public Osp::Base::Object
{
// Lifecycle
public:

	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since		2.0
	*/
		SpeechToText(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	*/
	virtual ~SpeechToText(void);

//Operation
public:

	/**
	* Initializes this instance of %SpeechToText with the specified listener. 
	* Sets the following values of Speech-To-Text configuration parameters: 
	* 	- The default locale: eng-us
	* 	- The default grammar: free_form_dictation
	* 	- The default silence detection: true
	* 	- The default profanity filter: true
	* 	- The default punctuation override: true
	*
	* To change the value of the above parameters, use the SetLocale(), SetGrammar(), SetSilenceDetectionEnabled(),
    * SetProfanityFilterEnabled(), and SetPunctuationOverrideEnabled() functions, respectively.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	listener		An instance of ISpeechToTextEventListener
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @exception	E_SYSTEM		A system error has occurred.
	* @exception 	E_SERVICE_BUSY	The Speech-To-Text service is being used.
	* @remarks 		Only one instance is created at a given time.
	*/
	result Construct(const ISpeechToTextEventListener& listener);
	/**
	* Initializes the Speech-To-Text service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since		2.0
	* @return	    An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks	This method should be called after Construct().
	*/
	result Initialize(void);
	/**
	* Starts recording the speech of a user and converts it to text.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks		This method should be called after Construct() and Initialize().
	*/	
	result Start(void);
	/**
	* Stops the recording and current Speech-To-Text service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks		This method should be called after Construct() and Initialize().
	*/	
	result Stop(void);
	/**
	* Cancels the in progress recognition of the Speech-To-Text service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks		This method should be called after Construct() and Initialize().
	*/	
	result Cancel(void);
	/**
	* Sets the locale for the next recognition of the Speech-To-Text service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	locale					The current locale
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state or not initialized.
	* @exception	E_UNSUPPORTED_LOCALE	This locale is not supported.
	* @remarks		This method should be called after Construct() and Initialize(). @n
	*				The user needs to check the supported locales list by calling SpeechToText::GetSupportedLocalesN() first.
	*/
	result SetLocale(const Osp::Locales::Locale& locale);
	/**
	* Gets the current locale.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		A current locale setup for the Speech-To-Text service
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				This method should be called after Construct().
	*/
	Osp::Locales::Locale GetCurrentLocale(void) const;
	/**
	* Checks whether a locale is supported or not.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		@c true if the locale is available,
	*				else @c false
	* @param[in]	locale	The locale
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				This method should be called after Construct() and Initialize().
	*/
	bool IsLocaleSupported(const Osp::Locales::Locale& locale) const;
	/**
	* Gets the list of supported locales.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		A list of locales. If there is no available Osp::Locales::Locale or
    *				in case of some failure, null pointer is returned.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				This method should be called after Construct() and Initialize().
	*/
	Osp::Base::Collection::IList* GetSupportedLocalesN(void) const;
	/**
	* Sets the grammar for SpeechToText.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	grammar	A grammar @n
	* 						The value should be one of the key strings "free_form_dictation" and "web_search".
	* 						It can be added or changed in the future.
	* 						The "free_form_dictation" key is used for general purpose dictation.
	* 						The "web_search" key is used for recognizing short phrases such as the ones used for %Web search.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @exception	E_INVALID_ARG	The value of input parameter is invalid.
	* @remarks		This method should be called after Construct().
	*/
	result SetGrammar(Osp::Base::String& grammar);
	/**
	* Gets the current grammar.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		The current grammar used by recognition
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* 				This method should be called after Construct().
	*/		
	Osp::Base::String GetCurrentGrammar(void) const;
	/**
	* Sets the silence detection enabled or disabled.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	enable	Set to @c true to enable the silence detection, @n
	* 						else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		This method should be called after Construct().
	*/
	result SetSilenceDetectionEnabled(bool enable);
	/**
	* Checks whether the silence detection feature is enabled.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		@c true if the silence detection is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*				This method should be called after Construct().
	*/
	bool IsSilenceDetectionEnabled(void) const;
	/**
	* Sets the profanity filtering enabled or disabled.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	enable	Set to @c true to enable the profanity filtering, @n
	*						else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		This method should be called after Construct().
	*/
	result SetProfanityFilterEnabled(bool enable);
	/**
	* Checks whether the profanity filtering feature is enabled.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		@c true if the profanity filtering is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*				This method should be called after Construct().
	*/
	bool IsProfanityFilterEnabled(void) const;
	/**
	* Sets the punctuation override enabled or disabled.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	enable	Set to @c true to enable the punctuation override
	* 						else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		This method should be called after Construct().
	*/
	result SetPunctuationOverrideEnabled(bool enable);
	/**
	* Checks whether the punctuation override feature is enabled.  
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		@c true if the punctuation override setting is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @see			SpeechToTextPunctuationOverride
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*				This method should be called after Construct().
	*/
	bool IsPunctuationOverrideEnabled(void) const;

private:
	Osp::Base::String __ConvertLocaleToString(Osp::Locales::Locale locale);
	Osp::Locales::Locale __ConvertStringToLocale(Osp::Base::String) const;

private:
	SpeechToText(const SpeechToText& speechToText);
	SpeechToText& operator =(const SpeechToText& speechToText);

	bool* __pIsInitRequested;
	ISpeechToTextPi* __pISpeechToTextPi;
	ISpeechToTextPi* __pConstructedISpeechToTextPi;
	Osp::Uix::ISpeechToTextEventListener* __pListener;
	__SpeechToTextCurrentInfo __currentInfo;

	friend class SpeechToTextEx;
	class SpeechToTextEx* __pSpeechToTextEx;
};

};}; // Osp::Uix


#endif
