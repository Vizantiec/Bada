/**
 * Name        : TextPic
 * Version     : 
 * Vendor      : 
 * Description : 
 */


#include "TextPic.h"
#include "FormManager.h"

#include "Retina.h"
#include "TextArtRegistry.h"
#include "StartAPI.h"

#include <FLocales.h>

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Locales;


TextPic::InternalAppLanguageEnum TextPic::__InternalAppLanguageIndex = TextPic::EInternalAppLanguage_EN;

TextPic::TextPic()
{
}

TextPic::~TextPic()
{
}

Application*
TextPic::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new TextPic();
}

bool
TextPic::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	/*
	// Create a form
	Form1 *pForm1 = new Form1();
	pForm1->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);

	// Set the current form
	pFrame->SetCurrentForm(*pForm1);

	// Draw and Show the form
	pForm1->Draw();
	pForm1->Show();
	*/
	//Frame *pFrame = GetAppFrame()->GetFrame();
	//pFrame->SetOrientation(ORIENTATION_STATUS_PORTRAIT);

	//pFrame->SetOrientation(ORIENTATION_STATUS_PORTRAIT );

	LocaleManager localeManager;
	localeManager.Construct();
	Locale locale = localeManager.GetSystemLocale();
	LanguageCode lc = locale.GetLanguageCode();
	AppLog("DEVICE LANGUAGE %d", lc);
	if (lc == LANGUAGE_RUS) {
		TextPic::__InternalAppLanguageIndex = TextPic::EInternalAppLanguage_RU;
	} else if (lc == LANGUAGE_ENG || lc == LANGUAGE_ANG) {
		TextPic::__InternalAppLanguageIndex = TextPic::EInternalAppLanguage_EN;
	} else if (lc == LANGUAGE_DEU || lc == LANGUAGE_GMH || lc == LANGUAGE_GOH || lc == LANGUAGE_GSW || lc == LANGUAGE_NDS) {
		TextPic::__InternalAppLanguageIndex = TextPic::EInternalAppLanguage_DE;
	} else if (lc == LANGUAGE_FRM || lc == LANGUAGE_FRO || lc == LANGUAGE_FRA) {
		TextPic::__InternalAppLanguageIndex = TextPic::EInternalAppLanguage_FR;
	}

	Retina::Setup();
	TextArtRegistry::Setup();

	StartAPI* _pStartAPI = new StartAPI();
	_pStartAPI->CreateBody();


	FormManager *pFormMgr = new FormManager();
	pFormMgr->Initialize();
	GetAppFrame()->GetFrame()->AddControl(*pFormMgr);
	pFormMgr->SetStarterForm(FormManager::REQUEST_CATEGORYLIST, null);

	return true;
}

bool
TextPic::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void
TextPic::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
TextPic::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.
}

void
TextPic::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.
}

void
TextPic::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void
TextPic::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void
TextPic::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}

result TextPic::GetTranslated(String& fullString) {
	int i = -1;
	int cursor = 0;
	while (cursor != TextPic::__InternalAppLanguageIndex && fullString.IndexOf('|', i + 1, i) == E_SUCCESS) {
		cursor++;
	}

	int end = -1;
	if (fullString.IndexOf('|', i + 1, end) == E_SUCCESS) { //start or in the line
		if (cursor == 0 && end == 1) { //first language is empty
			return E_FAILURE;
		}

		result r = fullString.SubString(i + 1, end - i - 1, fullString);
		if (IsFailed(r) || fullString.GetLength() == 0) {
			return E_FAILURE;
		}
		return E_SUCCESS;
	} else if (i + 1 + 1 < fullString.GetLength()) { //at the end of line; +1 '\n'
		result r = fullString.SubString(i + 1, fullString.GetLength() - i - 1, fullString);
		if (IsFailed(r) || fullString.GetLength() == 0) {
			return E_FAILURE;
		}
		return E_SUCCESS;
	}
	return E_FAILURE;//finished
}
