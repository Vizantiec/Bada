#ifndef _TEXTPIC_H_
#define _TEXTPIC_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>

/**
 * [TextPic] application must inherit from Application class
 * which provides basic features necessary to define an application.
 */
class TextPic :
	public Osp::App::Application,
	public Osp::System::IScreenEventListener
{
public:
		enum InternalAppLanguageEnum {
			EInternalAppLanguage_RU = 0,
			EInternalAppLanguage_EN = 1,
			EInternalAppLanguage_DE = 2,
			EInternalAppLanguage_FR = 3
		};
	/**
	 * [TextPic] application must have a factory method that creates an instance of itself.
	 */
	static Osp::App::Application* CreateInstance(void);

	static InternalAppLanguageEnum __InternalAppLanguageIndex;

public:
	TextPic();
	~TextPic();

public:
	// Called when the application is initializing.
	bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);

	// Called when the application is terminating.
	bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);


	// Called when the application's frame moves to the top of the screen.
	void OnForeground(void);


	// Called when this application's frame is moved from top of the screen to the background.
	void OnBackground(void);

	// Called when the system memory is not sufficient to run the application any further.
	void OnLowMemory(void);

	// Called when the battery level changes.
	void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

	// Called when the screen turns on.
	void OnScreenOn (void);

	// Called when the screen turns off.
	void OnScreenOff (void);

	static result GetTranslated(Osp::Base::String& fullString);
};

#endif
