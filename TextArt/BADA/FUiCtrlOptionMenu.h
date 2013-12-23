/* $Change: 1037339 $ */
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
 * @file	FUiCtrlOptionMenu.h
 * @brief	This is the header file for the %OptionMenu class. 
 *
 * This header file contains the declarations of the %OptionMenu class and its helper classes.
 */

#ifndef _FUICTRL_OPTION_MENU_H_
#define _FUICTRL_OPTION_MENU_H_


// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpRectangle.h"
#include "FUiCtrlConfig.h"
#include "FUiWindow.h"
#include "FUiContainer.h"
#include "FUiIActionEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @class		OptionMenu
 * @brief		This class defines a common behavior for an %OptionMenu control. 
 * @deprecated 	This method is deprecated because the use of the %OptionMenu control is no longer recommended.
 * @since		1.0
 *
 * The %OptionMenu class defines a common behavior for an %OptionMenu control.
 * An %OptionMenu is used to present users with multiple options. Hierarchical menu 
 * of depth 2 can be constructed. Option menu consists of main items and sub-items. 
 * Unlike ContextMenu, menus cannot display bitmaps.
 *
 * If an application wants to perform tasks when a menu item is selected, it should 
 * implement IActionEventListener and register the listener by calling %OptionMenu's 
 * AddActionEventListener() method. It will then receive action ID associated 
 * with the menu item.
 * Note that %OptionMenu cannot be used in a Popup.
 *
 * Example:
 *
 * @image html GUI_optionmenu.png
 *
 * This is the simple UI application which uses an %OptionMenu control.
 *
 * @code
 
// Sample code for OptionMenuSample.h
#include <FUi.h>

class OptionMenuSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
public:
	OptionMenuSample(void)
		:__pOptionMenu(null){}

	result Construct();
    void ShowOptionMenu(void);
    void HideOptionMenu(void);

protected:
    static const int ID_OPTIONKEY = 100;
    static const int ID_OPTIONMENU_ITEM1  = 101;
    static const int ID_OPTIONMENU_ITEM2 = 102;

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

private:
    Osp::Ui::Controls::OptionMenu* __pOptionMenu;
};

// Sample code for OptionMenuSample.cpp
#include "OptionMenuSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
OptionMenuSample::Construct()
{
	return Form::Construct(FORM_STYLE_NORMAL|FORM_STYLE_OPTIONKEY);
}

result
OptionMenuSample::OnInitializing(void)
{
	result r = E_SUCCESS;

    // Creates an OptionMenu
    __pOptionMenu = new OptionMenu();
    __pOptionMenu->Construct();
    __pOptionMenu->AddItem("Item1",ID_OPTIONMENU_ITEM1);
    __pOptionMenu->AddItem("Item2",ID_OPTIONMENU_ITEM2);

    SetOptionkeyActionId(ID_OPTIONKEY);
   	AddOptionkeyActionListener(*this);

    return r;
}

result
OptionMenuSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    delete __pOptionMenu;

    return r;
}

void
OptionMenuSample::ShowOptionMenu(void)
{
	__pOptionMenu->SetShowState(true);
	__pOptionMenu->Show();
}

void
OptionMenuSample::HideOptionMenu(void)
{
	__pOptionMenu->SetShowState(false);
	Draw();
	Show();
}

// Implements an IActionEventListener
void
OptionMenuSample::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
    switch (actionId)
    {
    case ID_OPTIONKEY:
    	ShowOptionMenu();
    	break;

	case ID_OPTIONMENU_ITEM1:
		// Todo:
		break;

	case ID_OPTIONMENU_ITEM2:
		// Todo:
		break;

	default:
		break;
    }
}
 
 * @endcode
 *
 */
class _EXPORT_CONTROLS_ OptionMenu :
	public Osp::Ui::Window
{
	DECL_CLASSTYPE(OptionMenu);
public:


// Lifecycle

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	OptionMenu(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~OptionMenu(void);

	/**
	 * Initializes this instance of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
 	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			This method has failed.
	 */
	result Construct(void);

	/**
	 * Adds a listener instance to receive action events from this control. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes the specified action event listener so that it no longer receives events from this control.
	 *
	 * @since		1.0
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Appends new item to the end of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text			The item to be appended
	 * @param[in]	actionId		The action ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		This method has failed.
	 * @remarks 	%OptionMenu can have a maximum of 12 main items.
	 */
	result AddItem(const Osp::Base::String& text, int actionId);

	/**
	 * Inserts a specific item at the given index of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	mainIndex		The main index
	 * @param[in] 	text			The item to be set
	 * @param[in]	actionId		The item ID
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		The method has failed.
	 * @remarks 	%OptionMenu can have a maximum of 12 main items.
	 */
	result InsertItemAt(int mainIndex, const Osp::Base::String& text, int actionId);

	/**
	 * Sets a specific item at the given index of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	mainIndex		The main index
	 * @param[in] 	text			The string of the item to be set
	 * @param[in]	actionId		The item ID
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM	    The method has failed.
	 */
	result SetItemAt(int mainIndex, const Osp::Base::String& text, int actionId);

	/**
	 * Removes the item of the specified index from %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	mainIndex			The main index
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM			This method has failed.
	 */
	result RemoveItemAt(int mainIndex);
	
	/**
	 * Gets the number of items registered for %OptionMenu.
	 *
	 * @since		1.0
	 * @return		The number of items registered for %OptionMenu
	 */
	int GetItemCount(void) const;

	/**
	 * Gets the index of the item with the specified action ID.
	 *
	 * @since		1.0
	 * @return		The index of the item
	 * @param[in] 	actionId	The action ID of the item
	 */
	int GetItemIndexFromActionId(int actionId);

	/**
	* Gets the action ID of the item at the specified index.
	*
	* @since		1.0
	* @return		The action ID of the item
	* @param[in]	mainIndex	The index of the item
	*/
	int GetItemActionIdAt(int mainIndex) const;

	/**
	 * Appends new sub-item to the end of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]  	mainIndex			The index of the main item
	 * @param[in] 	text				The string of item to be appended
	 * @param[in]	actionId			The item ID
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM			This method has failed.
	 * @remarks 	%OptionMenu can have a maximum of 32 sub-items.
	 */
	result AddSubItem(int mainIndex, const Osp::Base::String& text, int actionId);

	/**
	 * Inserts a specific sub-item at the given index of %OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	mainIndex			The index of the main item
	 * @param[in]	subIndex			The index of the sub-item
	 * @param[in] 	text				The string of the item to be set
	 * @param[in]	actionId			The action ID
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM			This method has failed.
	 * @remarks 	%OptionMenu can have a maximum of 32 sub-items.
	 */
	result InsertSubItemAt(int mainIndex, int subIndex, const Osp::Base::String& text, int actionId);

	/**
	 * Sets a specific sub-item at the given index of %OptionMenu.
	 *
	 * @since		1.0
     * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompOptionMenuSetSubItemAt "here".
	 * @return		An error code
	 * @param[in] 	mainIndex			The index of the main item
	 * @param[in] 	subIndex			The index of the sub-item
	 * @param[in] 	text				The string of the item to be set
	 * @param[in]	actionId			The action ID
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM			This method has failed.
	 */
	result SetSubItemAt(int mainIndex, int subIndex, const Osp::Base::String& text, int actionId);

   /**
    * @page		CompOptionMenuSetSubItemAt	Compatibility for SetSubItemAt()
	*
    * @section	CompOptionMenuSetSubItemAtIssues	Issues
    * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n 
    * -# If more than two sub-items belonging to a certain item have the same ID, only one of them is displayed.
    *
    * @section	CompOptionMenuSetSubItemAtResolutions	Resolutions 
    * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
    */

	/**
	 * Removes the sub-item of the specified index from OptionMenu.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	mainIndex			The index of the main item
	 * @param[in]	subIndex			The index of the sub-item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM			This method has failed.
	 */
	result RemoveSubItemAt(int mainIndex, int subIndex);
	
	/**
	 * Gets the number of sub-items registered for %OptionMenu.
	 *
	 * @since		1.0
	 * @return		The number of sub-items registered for %OptionMenu
	 * @param[in]	mainIndex		The index of the main item
	 */
	int GetSubItemCount(int mainIndex) const;

	/**
	 * Gets the index of the sub-item at the specified action ID.
	 *
	 * @since		1.0
	 * @return		The index of the item
	 * @param[in] 	actionId		The action ID of the item
	 */
	int GetSubItemIndexFromActionId(int actionId);

	/**
	 * Gets the action ID of the sub-item at the specified index.
	 *
	 * @since		1.0
	 * @return		The action ID of the item
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	subIndex		The index of the sub-item
	 */
	int GetSubItemActionIdAt(int mainIndex, int subIndex) const;

	/**
	 * Shows the %OptionMenu co trol.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									That is, this control is not 'displayable'.
	 * @exception	E_SYSTEM			The method has failed.
	 */
	virtual result Show(void);

	/**
	 * Sets the show state of the control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	state			The new show state
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Although this method is invoked, the control is not drawn or shown. @n
	 *				To draw and show a control, use the Draw() and Show() methods. @n
	 *				Once the show state of the control is set to @c false, you need to set the show state to @c true again before you draw and show.
	 * @see			GetShowState(), Draw(), Show()
	 *
	 */
	virtual result SetShowState(bool state);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Draws the control.
	 *
	 * @since			1.0
	 */
	result Draw(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (E_UNSUPPORTED_OPERATION) Gets the control with the specified name. @n
	 * Error code can be received using the GetLastResult() method.
	 *
	 * @since			1.0
	 * @return     The control having the specified name @n
	 *             @c null, if the name is not valid
	 * @param[in]	name        The name of the control
	 * @param[in]	recursive   Set to @c true to find a match recursively @n 
	 *					    @c false, otherwise
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since			1.0
	 */
	virtual result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the position and size of the control.
	 *
	 * @since			1.0
	 */
	virtual result SetBounds(int x, int y, int widht, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 *
	 * @since			1.0
	 */
	virtual result SetPosition(int x, int y);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the relative position of the control.
	 * 
	 * @since			1.0
	 */
	virtual result SetPosition(const Osp::Graphics::Point& Position);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since			1.0
	 */
	virtual result SetSize(int width, int height);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Sets the size of the control. @n
	 * Its width becomes @c width, and its height becomes @c height.
	 *
	 * @since			1.0
	 */
	virtual result SetSize(const Osp::Graphics::Dimension& size);


protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since			1.0
	 * @return			An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the content of this OptionMenu.
	 *
     * @since       1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method has failed.
 	 */
	virtual result __Draw(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Destroys its sub menu.
	 * This method destroys its sub menu.
	 *
     * @since       1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method has failed.
	 */
	bool DestroySubMenu(void);


private:
	// To prevent using the methods.
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the control at the end of the list maintained by this container.
     * @since         1.0
	 */
	virtual result AddControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since         1.0
	 */
	virtual result RemoveControl(const Control& control);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes the specified control from this container.
     * @since         1.0
	 */
	virtual result RemoveControl(int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Removes all controls from this container.
     * @since         1.0
	 */
	virtual void RemoveAllControls(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
 	 * (Blocked) Gets the control at the specified index of the list that are kept by this container.
     * @since         1.0
   	 */
   	virtual Control* GetControl(int index) const;
   
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets the number of the controls in this container.
     * @since         1.0
	 */
	int GetControlCount(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Gets a list of controls of this container.
     * @since         1.0
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Returns @c true if the specified control is within
	 * the containment hierarchy of this container. Otherwise, it returns
	 * @c false.
     * @since         1.0
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Finds the index of the specified control.
     * @since         1.0
	 */
	virtual result SetControlAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Adds the specified control to this container.
     * @since         1.0	 
	 */
	virtual result AddControlImplAt(const Control& control, int index);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked) Notifies this container that it is now added to a control
	 * containment hierarchy.
     * @since         1.0
	 */
	virtual result AddNotify(void);

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
 	 * (Blocked) Notifies this containers that it should be disconnected from the current
	 * native peer window.
     * @since         1.0
	 */
	virtual result RemoveNotify(void);


private:
	// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The action event
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent* __pActionEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The notify event 
     * @since         1.0
     */	
	Osp::Base::Runtime::IEvent* __pNotifyEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The action event adapter
     * @since         1.0
     */	
	void* __pActionEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The notify event adapter
     * @since         1.0
     */	
	void* __pNotifyEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The action Id
     * @since         1.0
     */	
	int __actionId;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
  	 * The show flag.
     * @since         1.0
     */	
	bool	__firstShow;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The showing flag.
     * @since         1.0
     */	
	bool	__showing;

private:
	friend class OptionMenuEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class OptionMenuEx*	__pOptionMenuEx;

protected:
	friend class OptionMenuImpl;
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control
     *
     * @since         2.0
     */	
	class OptionMenuImpl* GetImpl(void) const;


}; // OptionMenu
}; }; };//Osp::Ui::Controls

#endif // _FUICTRL_OPTION_MENU_H_

