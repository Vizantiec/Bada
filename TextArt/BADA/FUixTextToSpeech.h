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
 * @file			FUixTextToSpeech.h
 * @brief			This is the header file for the %TextToSpeech class.
 *
 * This header file contains the declarations of the %TextToSpeech class.
 */

#ifndef _FUIX_TEXT_TO_SPEECH_H_
#define _FUIX_TEXT_TO_SPEECH_H_

// Include
#include "FBaseObject.h"
#include "FLocales.h"
#include "FUixConfig.h"
#include "FUixTextToSpeechCommon.h"
#include "FUixITextToSpeechEventListener.h"

namespace Osp { namespace Uix { class ITextToSpeechPi; };};

namespace Osp{ namespace Uix{ 

/**
* @class	TextToSpeech
* @brief	This class is used to convert normal language text into speech.
* @deprecated	This class is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
* @since	2.0
* 
* The %TextToSpeech class is used to convert normal language text into speech.
*
* The following example demonstrates how to use the %TextToSpeech class.
* In the example, the SetXXX() and Speak() methods are called after receiving the TTS_STATUS_INITIALIZED event 
* through the OnTextToSpeechStatusChanged() listener.
*
* @code
*  //Sample Code for TextToSpeechSample.h
*	#include <FUix.h>
*
*	using namespace Osp::Uix;
*
*	class TextToSpeechSample : public ITextToSpeechEventListener
*	{
*	  	public:
*	  		TextToSpeechSample(void);
*	  		virtual ~TextToSpeechSample(void);
*	  		bool Initialize(void);
*			virtual void OnTextToSpeechErrorOccurred( Osp::Uix::TextToSpeechError error );
*			virtual void OnTextToSpeechStatusChanged( Osp::Uix::TextToSpeechStatus status );
*
*	  	private:
*	  		Osp::Uix::TextToSpeech *__pTextToSpeech;
*	};
*
*	//Sample Code for TextToSpeechSample.cpp
*	#include "TextToSpeechSample.h"
*
*	TextToSpeechSample::TextToSpeechSample(void)
*	{
*	}
*
*	TextToSpeechSample::~TextToSpeechSample(void)
*	{
*	}
*
*	void TextToSpeechSample:: OnTextToSpeechStatusChanged(Osp::Uix::TextToSpeechStatus status)
*	{
*		if(status == TTS_STATUS_INITIALIZED)
*		{
*			__pTextToSpeech->Speak("Hello bada");
*		}
*		// Add your code
*	}
*
*	void TextToSpeechSample::OnTextToSpeechErrorOccurred(Osp::Uix::TextToSpeechError error)
*	{
*		// Add your code
*	}
*
*	bool TextToSpeechSample::Initialize(void)
*	{
*		result r = E_SUCCESS;
*
*		__pTextToSpeech = new TextToSpeech();
*		r = __pTextToSpeech->Construct(*this);
*		if(IsFailed(r))
*		{
*			return false;
*		}
*
*		r = __pTextToSpeech->Initialize();
*		if(IsFailed(r))
*		{
*			return false;
*		}
*
*	 	return true;
*	}
*
* @endcode
*/

class _EXPORT_UIX_ TextToSpeech:
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
		TextToSpeech(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since		2.0
	*/
	virtual ~TextToSpeech(void);

//Operation
public:

	/**
	* Initializes this instance of %TextToSpeech with the specified listener. 
	* Sets the following values of Text-To-Speech configuration parameters:
	* 	- The default locale : eng-us
	*	- The default voice type : TTS_VOICE_TYPE_MALE_DEFAULT
	*	- The default speech rate : TTS_SPEECHRATE_NORMAL
	*
	* To change the value of the above parameters, use SetLocale(), SetVoiceType(), and SetSpeechRate() functions.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return		An error code
	* @param[in]	listener	An instance of ITextToSpeechEventListener
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @exception	E_SYSTEM 	A system error has occurred.
	* @exception 	E_SERVICE_BUSY The Text-To-Speech service is already being used.
	* @remarks 		Only one instance is created at a given time.
	*/
	result Construct(const ITextToSpeechEventListener& listener);
	
	/**
	* Initializes the Text-To-Speech service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	An error code
	* @exception	E_SUCCESS	       The method is successful.
	* @exception	E_INVALID_STATE	   This instance is in an invalid state.
	* @exception	E_SYSTEM 	       A system error has occurred.
	* @remarks	This method should be called after Construct().
	*/
	result Initialize(void);

	/**
	* Sets the locale for the Text-To-Speech service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	An error code
	* @param[in] locale The current locale
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @exception E_UNSUPPORTED_LOCALE	This locale is not supported.
	* @remarks   This method should be called after Construct() and Initialize().
	*            The user needs to check the supported locales list by calling 
	*            TextToSpeech::GetSupportedLocalesN() first.
	*/
	result SetLocale(const Osp::Locales::Locale& locale);
	
	/**
	* Gets the current locale.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	A current locale setup for the Text-To-Speech service
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state.
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	* 			This method should be called after Construct().
	*/
	Osp::Locales::Locale GetCurrentLocale(void) const;
		
	/**
	* Gets the list of supported locales.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	A list of locales, @n
    *          	else a @c null pointer if locale is available or if a failure occurs 
	* @exception	E_SUCCESS		   The method is successful.
	* @exception    E_INVALID_STATE	   This instance is in an invalid state or not initialized.
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	* 			This method should be called after Construct() and Initialize().
	*/
	Osp::Base::Collection::IList* GetSupportedLocalesN(void) const;
		
	/**
	* Checks whether a locale is supported.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since     2.0
	* @return	@c true if the locale is available,
	*			else @c false
	* @param[in] locale	The locale
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	* 			This method should be called after Construct() and Initialize().
	*/
	bool IsLocaleSupported(const Osp::Locales::Locale& locale) const;
		
	/**
	* Sets the voice type of the Text-To-Speech service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	An error code
	* @param[in] type A voice type
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state.
	* @remarks This method should be called after Construct().
	* @see TextToSpeechVoiceType
	*/	
	result SetVoiceType(TextToSpeechVoiceType type);
	
	/**
	* Gets the voice type.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	A voice type
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state.
	* @see TextToSpeechVoiceType
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	* 			This method should be called after Construct().
	*/	
	TextToSpeechVoiceType GetVoiceType(void) const;
	
	/**
	* Sets the speech rate of the Text-To-Speech service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	An error code
	* @param[in] rate	A speech rate
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state.
	* @remarks This method should be called after Construct().
	* @see 	TextToSpeechSpeechRate
	*/	
	result SetSpeechRate(TextToSpeechSpeechRate rate);
	
	/**
	* Gets the speech rate of the Text-To-Speech service.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return The speech rate
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state.
	* @see 	TextToSpeechSpeechRate
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	* 			This method should be called after Construct().
	*/	
	TextToSpeechSpeechRate GetSpeechRate(void) const;
	
	/**
	* Starts the conversion of given text and starts playing the synthesized sound.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since            2.0
	* @return	An error code
	* @param[in] text A text string for synthesizing a speech

	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state or not initialized.
	* @exception E_SYSTEM	A system error has occurred.
	* @remarks	This method should be called after Construct() and Initialize().
	*/	
	result Speak(const Osp::Base::String& text);

	/**
	* Stops the synthesis or the sound on playing.
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
	* Pauses the speech.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return	An error code
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state.
	* @exception E_SYSTEM	A system error has occurred.
	* @remarks	 This method should be called while it is in the PLAYING state.
	*/
	result Pause(void);

	/**
	* Resumes the speech.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since        2.0
	* @return	An error code
	* @exception E_SUCCESS The method is successful.
	* @exception E_INVALID_STATE	This instance is in an invalid state.
	* @exception E_SYSTEM	A system error has occurred.
	* @remarks	 This method should be called while it is in the PAUSED state.
	*/
	result Resume(void);

	/**
	* Gets the maximum word count that is supported.
	*
	* @deprecated	This method is deprecated because it is not supported by the platform. An alternate class will be introduced in the near future.
	* @since		2.0
	* @return		The maximum word count that the voice engine can synthesize at a given time
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state.
	* @remarks 		The specific error code can be accessed using the GetLastResult() method.
	*				This method should be called after Construct() and Initialize().
	*/
	int GetMaxWordCount(void) const;

private:
	Osp::Base::String __ConvertLocaleToString(Osp::Locales::Locale locale);
	Osp::Locales::Locale __ConvertStringToLocale(Osp::Base::String) const;

private:
    TextToSpeech(const TextToSpeech& textToSpeech);
    TextToSpeech& operator =(const TextToSpeech& textToSpeech);

	bool* __pIsInitRequested;
	ITextToSpeechPi* __pITextToSpeechPi;
	ITextToSpeechPi* __pConstructedITextToSpeechPi;
	__TextToSpeechCurrentData __currentInfo;
	Osp::Uix::ITextToSpeechEventListener* __pListener;

	friend class TextToSpeechEx;
	class TextToSpeechEx* __pTextToSpeechEx;
};

};}; // Osp::Uix


#endif
