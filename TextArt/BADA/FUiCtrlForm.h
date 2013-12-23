/* $Change: 995804 $ */
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
 * @file		FUiCtrlForm.h
 * @brief	This is the header file for the %Form class.
 *
 * This header file contains the declarations of the %Form class.
 */
#ifndef _FUICTRL_FORM_H_
#define _FUICTRL_FORM_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FBaseColLinkedListT.h"
#include "FUiCtrlConfig.h"
#include "FUiIActionEventListener.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiIOrientationEventListener.h"
#include "FUiCtrlMessageBox.h"
#include "FUiCtrlPopup.h"
#include "FUiCtrlAlignmentEnum.h"
#include "FUiCtrlOverlayRegion.h"
#include "FUiCtrlIFormBackEventListener.h"

// Forward Declarations
namespace Osp { namespace Base { namespace Runtime { class IEvent; }; }; };
namespace Osp { namespace Ui { namespace Controls { class Frame; }; }; };
namespace Osp { namespace Ui { namespace Controls { class Tab; }; }; };
namespace Osp { namespace Ui { namespace Controls { class ContextMenu; }; }; };
namespace Osp { namespace Ui { namespace Controls { class OptionMenu; }; }; };
namespace Osp { namespace Ui { namespace Controls { class Header; }; }; };
namespace Osp { namespace Ui { namespace Controls { class Footer; }; }; };
namespace Osp { namespace Ui { namespace Controls { class OverlayRegion; }; }; };
namespace Osp { namespace Ui { namespace Controls {

class __FormDrawEventAdaptor;

/**
 * @enum FormStyle
 * Defines the %Form control style.
 * @since		1.0
 */
enum FormStyle
{
	FORM_STYLE_NORMAL	 = 0x00000000,	/**< The basic form style */
	FORM_STYLE_TITLE	 = 0x00000001,	/**< @deprecated This enumeration field is deprecated because the use of the Title control is no longer recommended */
	FORM_STYLE_INDICATOR = 0x00000002,	/**< The form with the indicator area */
	FORM_STYLE_SOFTKEY_0 = 0x00000010,	/**< @deprecated This enumeration field is deprecated because the use of the Softkey control is no longer recommended */
	FORM_STYLE_SOFTKEY_1 = 0x00000020,	/**< @deprecated This enumeration field is deprecated because the use of the Softkey control is no longer recommended */
	FORM_STYLE_OPTIONKEY = 0x00000040,	/**< @deprecated This enumeration field is deprecated because the use of the Optionkey control is no longer recommended */
	FORM_STYLE_TEXT_TAB	 = 0x00000100,	/**< @deprecated This enumeration field is deprecated because the use of the Tab control is no longer recommended */
	FORM_STYLE_ICON_TAB	 = 0x00000200,	/**< @deprecated This enumeration field is deprecated because the use of the Tab control is no longer recommended */
	FORM_STYLE_HEADER	 = 0x00001000,	/**< The form with a header @b since: @b 2.0 */
	FORM_STYLE_FOOTER	 = 0x00002000	/**< The form with a footer @b since: @b 2.0 */
};


/**
 * @enum Softkey
 * Defines the softkey.
 * @deprecated This enumeration type is deprecated because the use of the Softkey control is no longer recommended.
 * @since		1.0
 */
enum Softkey
{
	SOFTKEY_0,		/**< The left softkey */
	SOFTKEY_1,		/**< The right softkey */
	SOFTKEY_COUNT	/**< @internal This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum. */
};


/**
 * @enum FormActionBar
 * Defines the action bars that can be attached to the %Form control.
 * @since   2.0
 */
enum FormActionBar
{
	FORM_ACTION_BAR_INDICATOR = 0x0001,	/**< The indicator */
	FORM_ACTION_BAR_HEADER = 0x0002,	/**< The header */
	FORM_ACTION_BAR_FOOTER = 0x0004		/**< The footer */
};


/**
 * @class	Form
 * @brief	This class provides a container with general controls.
 * @since	1.0
 *
 * The %Form class displays a full screen container. It can contain user-created controls and system UI components, such
 * as an indicator area, header, and footer. The application can have multiple forms, which are all added to a single Frame.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_form.htm">Form</a>.
 *
 * The following example demonstrates how to use the %Form class.
 *
 * @code

	// Creates a Form
    Form* pForm = new Form();
    pForm->Construct(FORM_STYLE_NORMAL| FORM_STYLE_HEADER| FORM_STYLE_FOOTER);
    
    // Gets a frame pointer
    Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
    pFrame->AddControl(*pForm);
    pFrame->SetCurrentForm(*pForm);
    
    // Implements MyActionEventListener
    IActionEventListener* pListener = new MyActionEventListener();
    
    // Adds a Header    
    Header * pHeader = GetHeader();
    pHeader->SetTitleText(L"FormSample");
    
    
    // Adds a Footer
    Footer * pFooter = GetFooter();
    pFooter->SetStyle(FOOTER_STYLE_TAB);  
	pFooter->AddActionEventListener(*this);
    
    // Calls Draw() and Show() to display Form
    pForm->Draw();
    pForm->Show();


 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Form :
	public Osp::Ui::Container
{
	DECL_CLASSTYPE(Form);
public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
     * @since   1.0
	 */
	Form(void);

	/**
	 *	This is the destructor for this class.
	 *
     * @since   1.0
	 */
	virtual ~Form(void);

	/**
	 * Initializes this instance of %Form with the specified parameters.
	 *
     * @since   	1.0
	 * @return      An error code
	 * @param[in]	formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR (see Osp::Ui::Controls::FormStyle).
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid @b since: @b 2.0. @n
	 *									- FORM_STYLE_HEADER and FORM_STYLE_TITLE are specified at the same time. @n
	 *									- FORM_STYLE_HEADER and FORM_STYLE_TEXT_TAB are specified at the same time. @n
	 *									- FORM_STYLE_HEADER and FORM_STYLE_ICON_TAB are specified at the same time. @n
	 *									- FORM_STYLE_FOOTER and FORM_STYLE_SOFTKEY_0 are specified at the same time. @n
	 *									- FORM_STYLE_FOOTER and FORM_STYLE_SOFTKEY_1 are specified at the same time. @n
	 *									- FORM_STYLE_FOOTER and FORM_STYLE_OPTIONKEY are specified at the same time.
	 * @exception   E_INVALID_STATE     This instance has already been constructed.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     The maximum number of Frames and Forms that an application can construct is 30.
     * @see         FormStyle
	 */
	 result Construct(unsigned long formStyle);

    /**
     * Initializes this instance of %Form with the specified resource ID. @n
     * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. If it fails to find the 
	 * appropriate resource file, the method tries searching in other folders. When AutoScaling is enabled, the method first searches the folder that 
	 * corresponds to the current screen size category and then searches the ScreenSize-Normal folder.
     *
     * @since   1.0	 
     * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *     For more information, see @ref CompFormConstruct20 "here".
     * @return		An error code
     * @param[in]	resourceId          The resource ID describing the form
     * @exception	E_SUCCESS           The method is successful.
     * @exception	E_FILE_NOT_FOUND	The specified file cannot be found.
     * @exception	E_OUT_OF_MEMORY		The memory insufficient.
     * @exception	E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @exception	E_SYSTEM			A system error has occurred, or an error has occurred during resource file parsing.
     * @remarks		The number of Frame and %Form in total that an application can construct is limited to 30.
     * @remarks		The method returns the E_PRIVILEGE_DENIED exception if the specified resource contains the Flash, Map, or Web control
     *              and the application does not have the privilege to use the control.
	 * @see			Osp::Ui::Controls::Flash ,Osp::Locations::Services::ProviderManager, Osp::Web::Controls::Web
     */
    result Construct(Osp::Base::String resourceId);

	/**
	 * @page CompFormConstruct20 Compatibility for Construct()
	 * @section CompFormConstruct20Issues Issues
	 *   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	 *
	 * -# In the bada API versions prior to 2.0, the method first attempts to find the appropriate resource file in the folder corresponding
	 *    to the current screen resolution, either 240x400 or 480x800.
	 *    If it fails to find the resource file, the method tries searching in other folders.
	 * -# In the bada API version prior to 2.0, if parsing XML fails, the application is forced to terminate.
	 * -# In the bada API version prior to 2.0, if a child control specified in the resource file cannot be created, the resource loading is stopped
	 *    and E_SYSTEM is returned, but the Form instance is partially constructed.
	 *
	 * @section CompFormConstruct20Resolutions Resolutions
	 * The issue mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 *
	 * -# From bada API version 2.0, the method first attempts to find the appropriate resource file in the folder that corresponds
	 *    to the current screen resolution. If it fails to find the resource file, the method tries searching in other folders.
	 *    When AutoScaling is enabled, the method first searches the folder that corresponds to the current screen size category
	 *    and then searches the ScreenSize-Normal folder.
	 * -# From bada API Version 2.0, if the specified file is not found, the E_FILE_NOT_FOUND exception is returned.
	 * -# From bada API version 2.0, if XML parsing fails, the application is not forced to terminate and the E_SYSTEM exception is returned.
	 * -# From bada API version 2.0, if a child control cannot be created, the E_SYSTEM exception is returned and %Form construction is failed.
	 */
	
	/**
	 * Initializes this instance of %Form with the form style and layout.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]   formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR (see Osp::Ui::Controls::FormStyle).
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance has already been constructed.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception   E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The maximum number of Frames and Forms, that an application can construct is 30. @n
	 *				The children are arranged within the client area bounds of the form area by @c layout.
	 * @see         FormStyle
	 */
	result Construct(const Osp::Ui::Layout& layout, unsigned long formStyle);

	/**
	 * Initializes this instance of %Form with the specified parameters.
	 *
	 * @since		2.0
	 * @return      An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]   formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR (see Osp::Ui::Controls::FormStyle).
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance has already been constructed.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The maximum number of Frames and Forms, that an application can construct is @c 30. @n
	 *				The children are arranged within the bounds of the form area by @c layout.
	 * @see         FormStyle
	 */
	result Construct(const Osp::Ui::Layout& portraitLayout, const Osp::Ui::Layout& landscapeLayout, unsigned long formStyle);

// Operation

	/**
	 * Adds an IOrientationEventListener instance. @n
	 * The added listener can listen to the orientation changed events that are fired when the orientation mode of the screen is changed.
	 *
     * @since   1.0
	 * @param[in]	listener 	The listener to be added
	 * @remarks	    The %Form control can only listen to those changes to the orientation mode that are enabled by calling SetOrientation().
	 * @see			RemoveOrientationEventListener()
	 */
	void AddOrientationEventListener(const Osp::Ui::IOrientationEventListener& listener);


	/**
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to the action events that are fired when an option key is selected.
	 *
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   1.0
	 * @param[in]	listener	The listener to be added
	 * @see			RemoveOptionkeyActionListener()
	 */
	void AddOptionkeyActionListener(const Osp::Ui::IActionEventListener& listener);


	/**
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to the action events that are fired when a softkey is selected.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in]   softkey		The style of the softkey
	 * @param[in]	listener 	The listener to be added
	 * @see			RemoveSoftkeyActionListener()
	 */
	void AddSoftkeyActionListener(Softkey softkey, const Osp::Ui::IActionEventListener& listener);


	/**
	 * Removes the specified control from the %Form control.
	 *
     * @since   1.0
	 * @return		An error code
	 * @param[in]	control			The child control to be removed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified instance is not found within the indicated range (that is, @c control is not found).
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual result RemoveControl(const Control& control);


	/**
	 * Removes the specified control from the %Form control.
	 *
     * @since   	1.0
	 * @return		An error code
	 * @param[in]	index			The index of the control to be removed
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual result RemoveControl(int index);


	/**
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   	1.0
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddOptionkeyActionListener()
	 */
	void RemoveOptionkeyActionListener(const Osp::Ui::IActionEventListener& listener);


	/**
	 * Removes an IOrientationEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
     * @since   1.0
	 * @param[in]	listener	The listener to be removed
	 *
	 * @see			AddOrientationEventListener()
	 */
	void RemoveOrientationEventListener(const Osp::Ui::IOrientationEventListener& listener);


	/**
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in]   softkey		The style of the softkey
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddSoftkeyActionListener()
	 */
	void RemoveSoftkeyActionListener(Softkey softkey, const Osp::Ui::IActionEventListener& listener);


// Accessor
	/**
	 * Gets the background color of the %Form control.
	 *
     * @since   1.0
	 * @return	The background color of the %Form control
	 */
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;


	/**
	 * Gets the bounds of the client area.
	 *
     * @since   1.0
	 * @return	The bounds of the client area
	 * @remarks	The client area of the %Form control does not include the title, indicator, header and footer areas.
	 *
	 */
	Osp::Graphics::Rectangle GetClientAreaBounds(void) const;


	/**
	 * Gets the style of the %Form control.
	 *
     * @since   1.0
	 * @return	An @c unsigned @c long value representing the style of the %Form control
	 */
	unsigned long GetFormStyle(void) const;


    /**
	 * Gets the orientation mode of the %Form control.
	 *
     * @since   1.0
	 * @return 	The orientation of the %Form control
	 */
	Osp::Ui::Orientation GetOrientation(void);


	/**
	 * Gets the current orientation status of the %Form control.
	 *
     * @since   1.0
	 * @return	The orientation status of the %Form control, @n
	 *			else ORIENTATION_NONE if the %Form control is not the current form of the Frame control
	 */
	Osp::Ui::OrientationStatus GetOrientationStatus(void);


	/**
	 * Gets the action ID of the specified softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   	1.0
	 * @return		An integer value representing the action ID
	 * @param[in] 	softkey			The softkey
	 */
	int GetSoftkeyActionId(Softkey softkey) const;


	/**
	 * Gets the text of the specified softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   	1.0
	 * @return		The text of the softkey
	 * @param[in] 	softkey			The softkey
	 *
	 */
	Osp::Base::String GetSoftkeyText(Softkey softkey) const;


	/**
	 * Gets the pointer of the %Tab control if it exists.
	 *
 	 * @deprecated This method is deprecated because the use of the %Tab control is no longer recommended.
     * @since   	1.0
	 * @return		A pointer to the %Tab control, @n
	 *				else @c null if there is no tab
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be stored after immediate use.
	 */
	Tab* GetTab(void) const;


	/**
	 * Gets the title of the %Form control.
	 *
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
     * @since   1.0
	 * @return		The title of the %Form control
	 */
	Osp::Base::String GetTitleText(void) const;


	/**
	 * Gets the horizontal alignment of the title text.
	 *
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
     * @since   1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 * 				  For more information, see @ref CompGetTitleTextHorizontalAlignment "here".
	 * @return  The horizontal alignment of the title text
	 * @remarks		By default, the horizontal alignment is center aligned.
	 */
	HorizontalAlignment GetTitleTextHorizontalAlignment(void) const;

	/**
	 * @page CompGetTitleTextHorizontalAlignment Compatibility for GetTitleTextHorizontalAlignment()
	 * @section CompCompGetTitleTextHorizontalAlignment Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# When an icon is set to the title bar, the title text is automatically left-aligned.
	 * However, GetTitleTextHorizontalAlignment() still returns the previous text alignment value.
	 *
	 * @section CompGetTitleTextHorizontalAlignmentResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	 */

	/**
	 * Checks whether the %Form control has an Indicator.
	 *
     * @since   1.0
	 * @return	@c true if the %Form control has a title, @n
	 *			else @c false
	 */
	bool HasIndicator(void) const;


	/**
	 * Checks whether the %Form control has an optionkey.
	 *
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   1.0
	 * @return		@c true if the %Form control has an optionkey, @n
	 *				else @c false
	 */
	bool HasOptionkey(void) const;


	/**
	 * Checks whether the %Form control has the specified softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @return		@c true if the %Form control has the specified softkey, @n
	 *				else @c false
	 * @param[in] 	softkey			The required softkey
	 */
	bool HasSoftkey(Softkey softkey) const;


	/**
	 * Checks whether the %Form control has a tab.
	 *
	 * @deprecated This method is deprecated because the use of the %Tab control is no longer recommended.
     * @since   1.0
	 * @return	@c true if the %Form control has a tab, @n
	 *			else @c false
	 */
	bool HasTab(void) const;


	/**
	 * Checks whether the %Form control has a title.
	 *
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
     * @since   1.0
	 * @return		@c true if the %Form control has a title, @n
	 *				else @c false
	 */
	bool HasTitle(void) const;


	/**
	 * Checks whether the softkey is enabled.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @return		@c true if the softkey is enabled, @n
	 *				else @c false
	 * @param[in] 	softkey			The softkey
	 */
	bool IsSoftkeyEnabled(Softkey softkey) const;


	/**
	 * Sets the background color of the %Form control.
	 *
     * @since   1.0
	 * @param[in]	color 	The background color to set
	 */
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);


	/**
	 * Sets the style of the %Form control.
	 *
     * @since   	1.0
	 * @param[in]   formStyle		The form style to set @n
	 *								This parameter can be a combination of Osp::Ui::Controls::FormStyle.
	 * @exception	E_SUCCESS		The method is successful @b since: @b 2.0.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid @b since: @b 2.0. @n
	 *								- FORM_STYLE_HEADER and FORM_STYLE_TITLE are specified at the same time. @n
	 *								- FORM_STYLE_FOOTER and FORM_STYLE_SOFTKEY_0 are specified at the same time. @n
	 *								- FORM_STYLE_FOOTER and FORM_STYLE_SOFTKEY_1 are specified at the same time. @n
	 *								- FORM_STYLE_FOOTER and FORM_STYLE_OPTIONKEY are specified at the same time. @n
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *				Note that you must not change the style of %Form control that is constructed with FORM_STYLE_TEXT_TAB or FORM_STYLE_ICON_TAB style.
	 */
	void SetFormStyle(unsigned long formStyle);


	/**
	 * Sets an action ID of the optionkey.
	 *
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   1.0
	 * @param[in] 	actionId		The action ID of this button instance
	 */
	void SetOptionkeyActionId(int actionId);


	/**
	 * Sets the orientation of the %Form control.
	 *
     * @since   1.0
	 * @param[in]	orientation		The orientation of the %Form control
	 */
	void SetOrientation(Orientation orientation);

	
	/**
	 * Sets an action ID of each softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in] 	softkey			The softkey
	 * @param[in] 	actionId		The action ID to be set
	 */
	void SetSoftkeyActionId(Softkey softkey, int actionId);


	/**
	 * Enables or disables the specified softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in] 	softkey			The softkey
	 * @param[in]	enable		Set to @c true to enable this softkey, @n
	 *							else @c false
	 */
	void SetSoftkeyEnabled(Softkey softkey, bool enable);


	/**
	 * Sets the title icon of the %Form control.
	 *
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
     * @since   		1.0
     * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref CompFormTitleIcon20 "2.0".
	 * @return			An error code
	 * @param[in] 		pTitleBitmap			The title icon to be set, @n
	 *											else @c null if the title icon is removed
	 * @exception		E_SUCCESS 		        The method is successful.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of a specified operation (that is, this control cannot be displayed).
	 * @exception		E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception		E_SYSTEM		        A system error has occurred.
	 * @remarks	    	For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	result SetTitleIcon(const Osp::Graphics::Bitmap* pTitleBitmap);

	/**
	 * @page CompFormTitleIcon20 Compatibility for SetTitleIcon()
	 * @section CompFormTitleIcon20Issues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The size of the title icon is 32x32 on a WVGA screen and 16x16 on a WQVGA screen.
	 *
	 * @section CompFormTitleIcon20Resolutions Resolutions
	 * From 2.0, the size of the title icon is 30x30 on a WVGA screen and 15x15 on a WQVGA screen.
	 */

	/**
	 * Sets the title of this %Form control.
	 *
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
     * @since   1.0
	 * @return		An error code
	 * @param[in] 	title				The title to be set
	 * @param[in] 	alignment		    The horizontal alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of a specified operation (that is, this control cannot be displayed).
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		If the size of the text exceeds the displayable area, the text slides automatically. @n
	 *				Note that when the title icon is set along with the title text, the title retains the left alignment.
	 */
	result SetTitleText(const Osp::Base::String& title, HorizontalAlignment alignment = ALIGNMENT_CENTER);


    /**
	 * Sets the icon of the softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in] 	softkey		    The softkey
	 * @param[in] 	normalBitmap	The Bitmap of the normal icon
	 * @param[in] 	pPressedBitmap	The %Bitmap of the pressed icon
	 * @remarks		If both the icon and text are set for a softkey at the same time, the text takes precedence over the icon.
	 * @remarks	    For icon size details, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_icon_size.htm">Control Icon Size</a>.
	 */
	void SetSoftkeyIcon(Softkey softkey, const Osp::Graphics::Bitmap& normalBitmap, const Osp::Graphics::Bitmap* pPressedBitmap);

	/**
	 * Sets the text of the specified softkey.
	 *
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   1.0
	 * @param[in] 	softkey	The softkey
	 * @param[in] 	text		The text to be set
	 * @remarks		If both the icon and text are set for a softkey at the same time, the text takes precedence over the icon. @n
	 *				To display text in multi-lines or to denote the end of line, use '\\n'.
	 *
	 */
	void SetSoftkeyText(Softkey softkey, const Osp::Base::String& text);

	/**
     * Gets the captured bitmap of the current composite scene on the form.
     * 
     * @since		1.2
	 * @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *                 For more information, see @ref CompFormGetCapturedBitmapN "here".
	 * @return		A Bitmap instance that captures the current composite scene on the %Form control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	Osp::Graphics::Bitmap* GetCapturedBitmapN(void) const;
	
	/**
	 * @page	CompFormGetCapturedBitmapN Compatibility for GetCapturedBitmapN()
	 * @section	CompFormGetCapturedBitmapNIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The bitmap size is different from the size of the control captured by this method.
	 *
	 * @section CompFormGetCapturedBitmapNResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	 * -# The bitmap size is the same as the size of the control captured by this method.
	 */

// For Bada 2.O
	/**
	 * Gets the pointer to the %Footer control if it exists.
	 *
	 * @since		2.0
	 * @return		A pointer to the %Footer control, @n
	 *				else @c null if there is no %Footer
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be stored after immediate use.
	 */
	Footer* GetFooter(void) const;


	/**
	 * Gets the pointer to the %Header control if it exists.
	 *
	 * @since		2.0
	 * @return		A pointer to the %Header control, @n
	 *				else @c null if there is no %Header
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be 
	 *              stored after immediate use.
	 */
	Header* GetHeader(void) const;


	/**
	 * Checks whether the %Form control has a %Footer.
	 *
	 * @since		2.0
	 * @return		@c true if the %Form control has a %Footer, @n
	 *				else @c false
	 */
	bool HasFooter(void) const;


	/**
	 * Checks whether the %Form control has a %Header.
	 *
	 * @since		2.0
	 * @return		@c true if the %Form control has a %Header, @n
	 *				else @c false
	 */
	bool HasHeader(void) const;


	/**
	 * Checks whether the Indicator control is visible.
	 *
	 * @since		2.0
	 * @return		@c true if the %Indicator control is visible, @n
	 *				else @c false
	 */
	bool IsIndicatorVisible(void) const;


	/**
	 * Checks whether the %Header control is visible.
	 *
	 * @since		2.0
	 * @return		@c true if the %Header control is visible, @n
	 *				else @c false
	 */
	bool IsHeaderVisible(void) const;


	/**
	 * Checks whether the %Footer control is visible.
	 *
	 * @since		2.0
	 * @return		@c true if the %Footer control is visible, @n
	 *				else @c false
	 */
	bool IsFooterVisible(void) const;


	/**
	 * Checks whether the Indicator control is translucent.
	 *
	 * @since		2.0
	 * @return		@c true if the %Indicator control is translucent, @n
	 *				else @c false
	 */
	bool IsIndicatorTranslucent(void) const;


	/**
	 * Checks whether the %Header control is translucent.
	 *
	 * @since		2.0
	 * @return		@c true if the %Header control is translucent, @n
	 *				else @c false
	 */
	bool IsHeaderTranslucent(void) const;


	/**
	 * Checks whether the %Footer control is translucent.
	 *
	 * @since		2.0
	 * @return		@c true if the %Footer control is translucent, @n
	 *              else @c false
	 */
	bool IsFooterTranslucent(void) const;


	/**
	 * Sets the translucency of the action bars.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	actionBars          	The action bars @n
	 *										Multiple action bars can be combined using bitwise OR (see Osp::Ui::Controls::FormActionBar).
	 * @param[in]	translucent				Set to @c to make the action bars translucent, @n
	 *										else @c false
	 * @exception	E_SUCCESS           	The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of a specified operation, or
	 *										the specified action bars do not exist.
	 * @exception	E_INVALID_STATE     	This instance is in an invalid state.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_SYSTEM            	A system error has occurred.
	 * @remarks		Modifying the translucency of the action bars causes the client area of the %Form to change. @n
	 *              The translucency of multiple action bars can be modified at the same time by using logical OR for several values of FormActionBar.
	 * @remarks		The method is not supported in 16-bit devices.
     * @see         FormActionBar
	 */
	result SetActionBarsTranslucent(unsigned long actionBars, bool translucent);


	/**
	 * Sets the visibility state of the action bars.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	actionBars          The action bars @n
	 *									Multiple action bars can be combined using bitwise OR (see Osp::Ui::Controls::FormActionBar).
	 * @param[in]	visible             Set to @c true to make the action bars visible, @n
	 *									else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *                                  the specified action bars does not exist.
	 * @exception	E_INVALID_STATE     This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Modifying the translucency of action bars causes the client area of the %Form to change. @n
	 *              The visibility of multiple action bars can be modified at the same time by using logical OR for several values of FormActionBar.
     * @see         FormActionBar
	 */
	result SetActionBarsVisible(unsigned long actionBars, bool visible);


	/**
	 * Creates and returns an overlay region of the specified position and size. @n
	 * Due to the hardware accelerated rendering, there are limitations for an overlay region. @n
	 * The hardware capability for an overlay region is checked by using OverlayRegion::GetWidthUnit(), OverlayRegion::GetHeightUnit() and 
	 * OverlayRegion::GetMaxCount().
	 * If the specified condition is not satisfied, E_INVALID_ARG exception is returned.
	 *
	 * @since		2.0
	 * @return		An overlay region instance
	 * @param[in]	rect         		 	The X and Y coordinates relative to the top-left corner of the form along with the width and height
	 * @param[in]	regionType				The type of the overlay region
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_MAX_EXCEEDED			The number of overlay regions has reached the maximum limit.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option of the overlay region type is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations of the overlay region. @n
	 *              In such cases, GetOverlayRegionN() returns the E_INVALID_ARG exception. To prevent this problem, the application should use the
	 *  			OverlayRegion::EvaluateBounds() method to get the validated bounds that can be used as the input bounds of the GetOverlayRegionN() method.
	 * @remarks		Form::Draw() and Form::Show() methods should be called at least once to display input buffer.
	 * @remarks		Do not use OverlayRegion with OverlayPanel. If used, the E_SYSTEM exception is thrown.
	 */
	OverlayRegion* GetOverlayRegionN(const Osp::Graphics::Rectangle& rect, OverlayRegionType regionType);


	/**
	 * Creates and returns a graphics canvas whose bounds (position and size) are equal to the bounds of the client area of the %Form.
	 *
	 * @since         2.0
	 * @return      The graphic canvas of the %Form control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception   E_RESOURCE_UNAVAILABLE        The required resource is currently unavailable.
	 * @remarks		The method allocates Osp::Graphics::Canvas whose bounds are equal to that of the client area of the %Form. @n
	 *				It is the responsibility of the developers to deallocate the canvas after use.
	 * @remarks		The canvas is valid only if the properties of the parent control of the canvas remain unchanged. @n
	 *              Therefore, delete the previously allocated canvas and create a new canvas using the GetCanvasN() method @n
	 *              if the size or position of the control is changed.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @remarks     The Frame and %Form instances share a single frame-buffer. @n
	 *				Therefore, the custom drawing on the graphic canvas of the Frame and %Form controls appears on the screen regardless of whether the 
	 *				control is currently visible on the screen.
	 */
	Osp::Graphics::Canvas* GetClientAreaCanvasN(void) const;

	/**
	 * Translates the specified position to the client coordinate.
	 *
	 * @since       2.0
	 * @return      The position relative to the top-left corner of the client area, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]	position		The position relative to the top-left corner of the %Form control
	 * @see         TranslateFromClientAreaPosition()
	 */
	Osp::Graphics::Point TranslateToClientAreaPosition(const Osp::Graphics::Point& position) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.0
	 * @return      The position relative to the top-left corner of the %Form control, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   clientPosition     The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Osp::Graphics::Point TranslateFromClientAreaPosition(const Osp::Graphics::Point& clientPosition) const;


    /**
     * Sets the %Form back event listener.
	 *
     * @since   	2.0
     * @param[in]	pFormBackEventListener		The %Form back event listener to set
     * @see         Osp::Ui::Controls::IFormBackEventListener
     */
     void SetFormBackEventListener(const IFormBackEventListener* pFormBackEventListener);

protected:
// Operation

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to the container
	 *
     * @since   	1.0
	 * @return		An error code
	 * @param[in]	control					The control to add to this container
	 * @param[in]	index					The z-order index of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	 *										the specified @c control parameter is an instance of window or this control's parent container.
	 * @exception	E_OUT_OF_RANGE			The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY			Insufficient memory.
	 * @exception	E_SYSTEM				A system error occurred.
	 * @exception	E_MAX_EXCEEDED			The number of opened files exceeds the limit.	
	 */
	virtual result AddControlImplAt(const Control& control, int index);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies when the Control is added to a valid control containment hierarchy
	 * (that is, a hierarchy with an instance of Window class as the root).
	 *
     * @since   	1.0
	 * @return		An error code
	 * @param[in]	parent					The parent of the control
	 * @param[in]	x						The x coordinate relative to the top-left corner of the control
	 * @param[in]	y						The y coordinate relative to the top-left corner of the control
	 * @param[in]	width					The width
	 * @param[in]	height					The height
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_ARG_NULL				The pointer passed to the method contains a @c null reference (that is, @c pParent is NULL).
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	 *										Either the @c width or @c height is less than @c 1.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of a specified @n
	 *										operation (that is, this Control is already bound to a native window).
	 * @exception	E_SYSTEM				A system error occurred.
	 * @remarks		@b Note @b to @b implementers: One must call this method when a
	 *				Control instance needs to be inserted to the native window
	 *				hierarchy (that is, when a control is added to a container).
	 */
	virtual result AddToParent(const Container& parent, int x, int y, int width, int height);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window if it is present.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS 				The method is successful.
	 * @exception	E_SYSTEM 				Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);


private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the control.
     * @since       1.0
     * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		The method has failed.
	 */
	virtual result __Draw(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result AttachWindow(const Window& window);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result DetachWindow(const Window& window);


// Helper
private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result Activate(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	bool IsActivated(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	bool CheckSoftkey(Softkey softkey) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result CreateSoftkey(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result CreateTab(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result CreateHeader(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result CreateFooter(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetBounds(int x, int y, int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle &rect);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	result SetLocation(int x, int y);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetPosition(int x, int y);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetSize(int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension &size);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * @since         1.0
     */	
	void RebuildSoftkeys(void) const;

// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The activated flag.
     * @since         1.0
     */	
	bool __activated;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */	
	bool 	__isMonitored;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The title
     * @since         1.0
     */	
     Osp::Base::String __title;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The softkey text
     * @since         1.0
     */
	Osp::Base::String __softkeyText[SOFTKEY_COUNT + 1];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The form style
     * @since         1.0
     */
	unsigned long __formStyle;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The form title alignment
     * @since         1.0
     */
	HorizontalAlignment __titleAlignment;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The softkey action event
     * @since         1.0
     */
	Osp::Base::Collection::LinkedListT<Osp::Base::Runtime::IEvent*> __softkeyActionEvent;	// MAX_SOFTKEY_COUNT


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The orientation event
     * @since         1.0
     */
	Osp::Base::Runtime::IEvent*	__pOrientationEvent;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 *  The softkey action event adaptor
     * @since         1.0
     */
	Osp::Base::Collection::LinkedListT<Osp::Base::Object*> __softkeyActionEventAdaptor;	// MAX_SOFTKEY_COUNT


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The orientation event adapter
     * @since         1.0
     */
	Osp::Base::Object *	__pOrientationEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The softkey count
     * @since         1.0
     */
	int __softkeyCount;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The softkey action Id
     * @since         1.0
     */
	int __actionId[SOFTKEY_COUNT + 1];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	bool __enableSoftkey[SOFTKEY_COUNT + 1];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	bool __showSoftkey[SOFTKEY_COUNT + 1];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The normal bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pSoftkeyNormalBitmap[SOFTKEY_COUNT];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The pressed bitmap
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pSoftkeyPressedBitmap[SOFTKEY_COUNT];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The window event
     * @since         1.0
     */
	Osp::Base::Object *	__pWindowEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The Form event adaptor
     * @since         1.0
     */
    void *	__pFormEventAdaptor;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Tab* __pTab;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Ui::Orientation __orientation;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	IActionEventListener* __pActionEventListener[SOFTKEY_COUNT + 1];


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * @since         1.0
     */
	Osp::Base::Collection::LinkedList __windows;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Title Bitmap.
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pTitleBitmap;


// Friend Class Declaration

	/**
	 *	@internal
	 */
	friend class UiBuilder;

	/**
	 *	@internal
	 */
	friend class Frame;

	/**
	 *	@internal
	 */
	friend class MessageBox;

	/**
	 *	@internal
	 */
	friend class Popup;

	/**
	 *	@internal
	 */
	friend class Tab;

	/**
	 *	@internal
	 */
	friend class ContextMenu;

	/**
	 *	@internal
	 */
	friend class OptionMenu;

	/**
	 *	@internal
	 */
	friend class Header;

	/**
	 *	@internal
	 */
	friend class Footer;

	/**
	 *	@internal
	 */
	friend class __ClipboardPopup;

private:
	friend class __FormEventAdaptor;
	friend class FormEx;
	friend class FormMaker;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class FormEx* __pFormEx;

protected:
	friend class FormImpl;
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control.
     *
     * @since         2.0
     */
	class FormImpl* GetImpl(void) const;

}; // Form
}; }; }; // Osp::Ui::Controls
#endif// 


