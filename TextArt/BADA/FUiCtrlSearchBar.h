/* $Change: 777631 $ */
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
 * @file	FUiCtrlSearchBar.h
 * @brief	This is the header file of the %SearchBar class.
 *
 * This header file contains the declarations of the %SearchBar class.
 */

#ifndef _FUICTRL_SEARCHBAR_H_
#define _FUICTRL_SEARCHBAR_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiCtrlConfig.h"
#include "FUiControl.h"
#include "FUiITextEventListener.h"
#include "FUiIKeypadEventListener.h"
#include "FUiITextBlockEventListener.h"
#include "FUiIActionEventListener.h"
#include "FUiCtrlEditEnum.h"

// Forward declaration
namespace Osp { namespace Graphics { class Rectangle; };} ;
namespace Osp { namespace Ui { namespace Controls {

class ISearchBarEventListener;

/**
 * @enum 	SearchFieldStatus
 *
 * Defines the possible states of the search field of the search bar.
 * @since	2.0
 */
enum SearchFieldStatus
{
    SEARCH_FIELD_STATUS_NORMAL,			/**< The normal state */
    SEARCH_FIELD_STATUS_HIGHLIGHTED,	/**< The focus-highlighted state */
    SEARCH_FIELD_STATUS_DISABLED		/**< The disabled state */
};

/**
 * @enum 	SearchBarButtonStatus
 *
 * Defines the possible states of the search bar button.
 * @since	2.0
 */
enum SearchBarButtonStatus
{
	SEARCH_BAR_BUTTON_STATUS_NORMAL = 0,		/**< The normal status */
	SEARCH_BAR_BUTTON_STATUS_PRESSED,			/**< The selected status */
	SEARCH_BAR_BUTTON_STATUS_HIGHLIGHTED,		/**< The highlighted status */
	SEARCH_BAR_BUTTON_STATUS_DISABLED			/**< The disabled status */
};

/**
 * @enum	SearchBarMode
 *
 * Defines the possible modes of the search bar.
 * @since	2.0
 */
enum SearchBarMode
{
	SEARCH_BAR_MODE_NORMAL,		/**< The normal mode */
	SEARCH_BAR_MODE_INPUT		/**< The input mode */
};

/**
 * @class	SearchBar
 * @brief	This class is an implementation of a search bar.
 * @since	2.0
 *
 * The %SearchBar class displays an editable search field for entering keywords and an optional button that is displayed in the
 * input mode. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_searchbar.htm">SearchBar</a>.
 *
 * The following example demonstrates how to use the %SearchBar class.
 * 
 * @code

// Sample Code for SearchBarSample.h
#include <FGraphics.h>
#include <FUi.h>
#include <FUiControl.h>
#include <FBase.h>

class SearchBarSample :
    public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::ISearchBarEventListener,
	public Osp::Ui::ITextEventListener,
	public Osp::Ui::Controls::IListViewItemEventListener,
	public Osp::Ui::Controls::IListViewItemProvider
{
protected:
	Osp::Ui::Controls::SearchBar*	__pSearchBar;
	Osp::Ui::Controls::Label*		__pLabel;
	Osp::Ui::Controls::Header*		__pHeader;
	Osp::Ui::Controls::ListView* __pList;

	static const int ID_FORMAT_STRING = 500;

public:
	SearchBarSample(void)
	virtual ~SearchBarSample(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnSearchBarModeChanged(Osp::Ui::Controls::SearchBar& source, Osp::Ui::Controls::SearchBarMode mode);
	virtual void OnSearchBarContentAreaResized(Osp::Ui::Controls::SearchBar& source, Osp::Graphics::Dimension& size) {};
	virtual void OnTextValueChanged(const Osp::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Osp::Ui::Control& source){};

	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction);

	//IListViewItemProvider
	virtual Osp::Ui::Controls::ListItemBase* CreateItem (int index, int itemWidth);
	virtual bool  DeleteItem (int index, Osp::Ui::Controls::ListItemBase *pItem, int itemWidth);
	virtual int GetItemCount(void);
};

// Sample Code for SearchBarSample.cpp

#include "SearchBarSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Base;
using namespace Osp::Media;

result
SearchBarSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	__pSearchBar = new SearchBar();
	r = __pSearchBar->Construct(Rectangle(0, 0, 480, 72));
	__pSearchBar->SetText("Click here! ");
	if(IsFailed(r))
	{
		return r;
	}
	AddControl(*__pSearchBar);
	__pSearchBar->AddSearchBarEventListener(*this);
	__pSearchBar->AddTextEventListener(*this);

	__pList = new ListView();
	__pList->Construct(Rectangle(0, 0, 480, GetClientAreaBounds().height - 72), true, true);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	
	__pSearchBar->SetContent(__pList);

	__pLabel = new Label();
	__pLabel->Construct(Rectangle(0,100,480,300),"SearchBar Sample");
	AddControl(*__pLabel);
	// TODO: Add your initialization code here

	return r;
}

result
SearchBarSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
SearchBarSample::OnSearchBarModeChanged(Osp::Ui::Controls::SearchBar& source, Osp::Ui::Controls::SearchBarMode mode)
{
	__pSearchBar->SetText("");

	if(mode == SEARCH_BAR_MODE_INPUT)
	{
		__pLabel->SetText("");
		__pList->UpdateList();
	}
	else
	{
		__pSearchBar->SetText("Click here! ");
	}
	Draw();
	Show();
}

void
SearchBarSample::OnTextValueChanged(const Osp::Ui::Control& source)
{
	if(__pList)
	{
		__pList->UpdateList();
		__pList->ScrollToItem(0);
	}
	Draw();
	Show();
}

// IListViewItemEventListener
 void
 SearchBarSample::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
 {
 // Todo:
 }
 
 void
 SearchBarSample::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
 {
 // Todo:
 }
 void
 SearchBarSample::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
 {
 // Todo:
 }

//IListViewItemProvider
 Osp::Ui::Controls::ListItemBase* SearchBarSample::CreateItem (int index, int itemWidth)
 {
		ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
		CustomItem* pItem = new CustomItem();

		String str;
		str =__pSearchBar->GetText();
		if(str == "a" || str == "A")
		{
			switch (index%3)
			{
			case 0:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"ajo", true);
				break;
			case 1:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"aeun", true);
				break;
			case 2:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"abee", true);
				break;
			}
		}
		else if (str == "b" || str == "B")
		{

			switch (index%3)
			{
			case 0:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bonge", true);
				break;
			case 1:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bnpyo", true);
				break;
			case 2:
				pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bkueon", true);
				break;
			}
		}
		else
		{
			style = LIST_ANNEX_STYLE_NORMAL;
			pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);
			pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"default", true);
		}

		return pItem;

 }
 
 bool
 SearchBarSample::DeleteItem (int index, Osp::Ui::Controls::ListItemBase *pItem, int itemWidth)
 {
	delete pItem;
	pItem = null;
	return true;
 }
 
 int
 SearchBarSample::GetItemCount(void)
 {
		 return 3;
 }
 
 * @endcode
 *
 */

class _EXPORT_CONTROLS_ SearchBar :
	public Osp::Ui::Control
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	SearchBar(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~SearchBar(void);

	/**
	 * Initializes this instance of the %SearchBar control with the specified parameters.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rect			An instance of the Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *								the width and height of the control.
	 * @param[in]	searchBarButton	Set to @c true to display the search bar button, @n
	 *                              else @c false
	 * @param[in]	keypadAction	The keypad action
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the action ID of the specified item must be a positive integer.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks 	It is recommended that SearchBar should be placed at the top-left corner of Form's client area.
	 * @remarks     By default, a "Cancel" button is displayed if @c searchBarButton is set to @c true. When the user presses the cancel button,
	 *              the %SearchBar control returns to SEARCH_BAR_MODE_NORMAL automatically.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 */
    result Construct(const Osp::Graphics::Rectangle& rect, bool searchBarButton = true,
        KeypadAction keypadAction = KEYPAD_ACTION_SEARCH);

// Content
    /**
     * Gets the content of %Control.
     *
     * @since		2.0
     * @return		The control that is displayed in the content area of %SearchBar in the SEARCH_BAR_MODE_INPUT mode, @n
     *				else @c null if an error occurs
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Ui::Control* GetContent(void) const;

    /**
     * Sets the content control.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   pContent			The control that is to be displayed in the content area of the search bar.
     * @exception   E_SUCCESS			The method is successful.
     * @exception   E_INVALID_STATE		This instance is in an invalid state.
     * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
     *									The following controls cannot be set as the content: @n
     *									@li All classes derived from the Window class
     *									@li All picker classes (For example, DateTimePicker)
     *									@li Form
     *									@li Keypad
     *									@li OverlayPanel
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specified content control is displayed when the mode of the %SearchBar control is changed to SEARCH_BAR_MODE_INPUT.
     * @see			GetContentAreaSize()
     * @see			AddSearchBarEventListener()
     * @see			ISearchBarEventListener
     */
    result SetContent(const Osp::Ui::Control* pContent);

    /**
     * Updates the content area of the %SearchBar control.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	show					Set to @c true to perform show on the content area, @n
	 *										else @c false
     * @exception	E_SUCCESS				The method is successful.
     * @exception	E_INVALID_STATE			This instance is in an invalid state.
     * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
     *										The current mode of %SearchBar prohibits the execution of the method.
     * @exception	E_SYSTEM				A system error has occurred.
     * @remarks		The method performs Draw() and Show() on the content area.
     */
    result UpdateContentArea(bool show = true);

    /**
     * Sets the visibility state of the content area.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	visible				Set to @c true to make the content area visible, @n
	 *									else @c false
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @see			IsContentAreaVisible()
     */
    result SetContentAreaVisible(bool visible);

    /**
     * Checks whether the content area is visible.
     *
     * @since		2.0
     * @return		@c true if the content area is visible, @n
	 *				else @c false
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @see			SetContentAreaVisible()
     */
    bool IsContentAreaVisible(void) const;

    /**
     * Sets the size of the content area of the %SearchBar control.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	size				The size of the content area
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
     *                                 	The width and height of @c size must be greater than or equal to @c 0.
     * @remarks		The content area must be resized when the orientation of the form is changed once the size of the content area is changed.
     * @see         GetContentAreaSize()
     */
    result SetContentAreaSize(const Osp::Graphics::Dimension& size);

// Operation
    /**
     * Gets the size of the content area of the %SearchBar control.
     *
     * @since		2.0
     * @return		The size of the content area
     * @remarks		The content area is the area where the 'content' of the %SearchBar control is displayed. The size of the content areas can
     *              be changed at runtime.
     * @see         AddSearchBarEventListener()
     * @see         ISearchBarEventListener
     */
    Osp::Graphics::Dimension GetContentAreaSize(void) const;

// Modes
	/**
	 * Gets the search bar mode.
	 *
	 * @since		2.0
	 * @return      The search bar mode
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMode()
	 */
	SearchBarMode GetMode(void);

	/**
	 * Checks whether the search bar mode is locked.
	 *
	 * @since		2.0
	 * @return		@c true if the mode is locked, @n 
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetModeLock()
	 */
	bool IsModeLocked(void) const;

	/**
	 * Sets the search bar mode.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or @n
	 *									the mode is locked.
	 * @exception	E_INVALID_STATE     This instance is in an invalid state.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetMode()
	 * @see			SetModeLock()
	 */
	result SetMode(SearchBarMode mode);

    /**
     * Sets the lock status of the search bar mode.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]   modeLocked      	Set to @c true to lock the search bar mode, @n
	 *									else @c false
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_INVALID_STATE 	This instance is in an invalid state.
     * @exception   E_SYSTEM        	A system error has occurred.
     * @see         GetMode()
     */
    result SetModeLocked(bool modeLocked);

// Button
    /**
     * Gets the action ID of the search bar button.
     *
     * @since		2.0
     * @return      The action ID, @n
     *				else @c -1 if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
     *				By default, the method returns @c -1 if no user defined search bar button is set.
     */
    int GetButtonActionId(void) const;

    /**
     * Gets the color of the search bar button for the specified state.
     *
     * @since		2.0
     * @return		The color of the search bar button, @n
     *				else RGBA(0,0,0,0) if an error occurs
     * @param[in]	status				The status of the search bar button
     * @exception	E_SUCCESS			The method is successful.
     * @exception	E_INVALID_STATE		This instance is in an invalid state.
     * @exception	E_SYSTEM			A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     * @see			SetButtonColor()
     */
    Osp::Graphics::Color GetButtonColor(SearchBarButtonStatus status) const;

    /**
     * Gets the text color of the search bar button for the specified state.
     *
     * @since		2.0
     * @return		The text color of the search bar button, @n
     *				else RGBA(0,0,0,0) if an error occurs
     * @param[in]   status              The status of the search bar button
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetButtonTextColor(SearchBarButtonStatus status) const;

    /**
     * Gets the state of the search bar button.
     *
     * @since		2.0
     * @return		The state of the search bar button
     * @exception	E_SUCCESS           The method is successful.
     * @exception	E_INVALID_STATE     This instance is in an invalid state.
     * @exception	E_SYSTEM            A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
    SearchBarButtonStatus GetButtonStatus(void) const;

    /**
     * Sets the user defined search bar button.
     *
     * @since		2.0
     * @return      An error code
     * @param[in]	text			The button text
     * @param[in]	actionId		The button action ID
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified @c actionId must greater than or equal to @c 0.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     */
    result SetButton(const Osp::Base::String& text, int actionId);
    
    /**
     * Sets the enabled status of the search bar button.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	enabled			Set to @c true to enable the search bar button, @n
	 *								else @c false
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.	 
     */    
    result SetButtonEnabled(bool enabled);
    
    /**
     * Sets the color of the search bar button for the specified state.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	status          The button status
     * @param[in]	color           The button color to be set
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     * @see			GetButtonColor()
     */
    result SetButtonColor(SearchBarButtonStatus status, const Osp::Graphics::Color& color);
    
    /**
     * Sets the text color of the button of the %SearchBar control for the specified state.
     *
     * @since		2.0
     * @return		An error code
     * @param[in]	status			The button status
     * @param[in]	color			The button text color to set
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_STATE	This instance is in an invalid state.
     * @exception	E_SYSTEM		A system error has occurred.
     */
    result SetButtonTextColor(SearchBarButtonStatus status, const Osp::Graphics::Color& color);

// Text
	/**
	 * Appends the specified character at the end of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	character		The character to be added
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
     * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n 
     *              To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Osp::Base::Character& character);

	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	text		The text to be appended
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
	 * @remarks		To denote the end of a line use '\\n'. @n
     * 				The method modifies the text buffer that is managed by the %SearchBar control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result AppendText(const Osp::Base::String& text);


	/**
	 * Sets the text to be displayed.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	text			The text to be displayed
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		To denote the end of a line use '\\n'. @n
     * 				The method modifies the text buffer that is managed by the %SearchBar control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result SetText(const Osp::Base::String& text);

	/**
	 * Inserts the character at the specified index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index			The position to insert the character
	 * @param[in]	character		The character to be inserted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n 
	 * 								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_MAX_EXCEEDED	The length of the specified @c text exceeds the system limitation.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n
     *				To display the changes, the control must be drawn again.
	 */
	result InsertCharacterAt(int index, const Osp::Base::Character& character);

	/**
	 * Inserts the specified text at the specified index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index			The position at which to insert
	 * @param[in]	text			The text to be inserted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n 
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_MAX_EXCEEDED 	The length of the specified @c text exceeds the system limitation.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. 
     *				To display the changes, the control must be drawn again.
	 */
	result InsertTextAt(int index, const Osp::Base::String& text);

	/**
	 * Deletes the character at the specified position.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index			The index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c index is negative.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n 
	 * 								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The method modifies the text buffer that is managed by the %SearchBar control. @n
     *              To display the changes, the control must be drawn again.
	 */
	result DeleteCharacterAt(int index);

	/**
	 * Clears the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n
     *				To display the changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
     * Gets the length of the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		The length of the text, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTextLength(void) const;

	/**
	 * Gets the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		The text displayed by the %SearchBar control, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Osp::Base::String GetText(void) const;

	/**
	 * Gets a portion of text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		The specified portion of the text, @n 
	 *				else an empty string if an error occurs
	 * @param[in]	start	        The starting index of range
	 * @param[in]	end	            The last index of range
	 * @exception	E_SUCCESS 	    The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure, or @n
	 *								either the @c start or @c end parameter is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Osp::Base::String GetText(int start, int end) const;

// Max Char Count
	/**
	 * Gets the limit of the length of the text.
	 *
	 * @since		2.0
	 * @return		The limit of the text length, @n 
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *				The default limit length is @c 500.
	 * @see         SetLimitLength()
	 */
	int GetLimitLength(void) const;

	/**
	 * Sets the limit of the length of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	limitLength		The limit text length to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
	 *								the specified limit length cannot be @c 0 or negative.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetLimitLength()
	 */
	result SetLimitLength(int limitLength);

// Keypad
	/**
	 * Opens the keypad associated with the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			HideKeypad()
	 */
	result ShowKeypad(void) const;

	/**
	 * Hides the keypad associated with the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			ShowKeypad()
	 */
	result HideKeypad(void) const;
	
// Text Size
	/**
	 * Gets the text size of the search field.
	 *
	 * @since		2.0
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetSearchFieldTextSize()
	 */
	int GetSearchFieldTextSize(void) const;

	/**
	 * Sets the text size of the text field of the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	size			The text size
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
	 *								the specified @c size cannot be a negative value.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetSearchFieldTextSize()
	 */
	result SetSearchFieldTextSize(int size);
	
// Text Selection
	/**
	 * Gets the start and the end index of the currently selected text block.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[out]	start			The start index of the text block
	 * @param[out]	end				The end index of the text block
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method returns @c start = 0 and @c end = 0 if no text block is selected.
	 * @see			ReleaseBlock()
	 * @see			SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;
	
	/**
	 * Releases the selection of the current text block.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetBlockRange()
	 * @see			SetBlockRange()
	 */
	result ReleaseBlock(void);
	
	/**
	 * Selects the specified block of the text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	start	        The start index of the text block
	 * @param[in]	end  	        The end index of the text block
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or @n
	 *								either the @c start or @c end parameter is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			ReleaseBlock()
	 * @see			GetBlockRange()
	 */
	result SetBlockRange(int start, int end);
	
	/**
	 * Removes the text of the selected text block.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveTextBlock(void);


// Appearances
	/**
	 * Gets the color of the %SearchBar control for the specified status.
	 *
	 * @since		2.0
	 * @return		The color of the %SearchBar control, @n
     *				else RGBA(0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetColor()
	 */
	Osp::Graphics::Color GetColor(void) const;
	
	/**
	 * Gets the color of the search field for the specified status.
	 *
	 * @since		2.0
	 * @return		The color, @n
     *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The search field status
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetSearchFieldColor()
	 */
	Osp::Graphics::Color GetSearchFieldColor(SearchFieldStatus status) const;

	/**
	 * Gets the text color of the search field for the specified status.
	 *
	 * @since		2.0
	 * @return		The text color, @n
     *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The search field status
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetSearchFieldTextColor()
	 */
	Osp::Graphics::Color GetSearchFieldTextColor(SearchFieldStatus status) const;
	
	/**
	 * Sets the background bitmap of the %SearchBar control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetBackgroundBitmap(const Osp::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the search bar.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color			The color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(const Osp::Graphics::Color& color);
	
	/**
	 * Sets the color of the search field for the specified status.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	status				The state of the search field
	 * @param[in]	color				The text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetSearchFieldColor()
	 */
	result SetSearchFieldColor(SearchFieldStatus status, const Osp::Graphics::Color& color);

	/**
	 * Sets the text color of the search field for the specified status.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	status			The state of the search field
	 * @param[in]	color			The text color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetSearchFieldTextColor()
	 */
	result SetSearchFieldTextColor(SearchFieldStatus status, const Osp::Graphics::Color& color);

// Guide Text	
	/**
	 * Gets the guide text.
	 *
	 * @since		2.0
	 * @return		The guide text, @n 
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_INVALID_STATE  This instance is in an invalid state.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetGuideText()
	 */
	Osp::Base::String GetGuideText(void) const;

	/**
     * Sets the guide text.
	 * This text is displayed when there is no text in the %SearchBar control.
     *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	guideText			The guide text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetGuideText()
	 */
	result SetGuideText(const Osp::Base::String& guideText);

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since		2.0
	 * @return		The text color of the guide text, @n
     *				else RGBA(0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetGuideTextColor()
	 */
	Osp::Graphics::Color GetGuideTextColor(void) const;

	/**
	 * Sets the text color of the guide text.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	color				The guide text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetGuideTextColor()
	 */
	result SetGuideTextColor(const Osp::Graphics::Color& color);
	
// Cursor
	/**
	 * Gets the current cursor position index.
	 *
	 * @since		2.0
	 * @return		The cursor position, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetCursorPosition()
	 */
	int GetCursorPosition(void) const;

	/**
	 * Sets the cursor at the specified index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	index			The cursor index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @see			GetCursorPosition()
	 */
	result SetCursorPosition(int index);

    /**
     * Checks whether the lowercase mode is enabled.
	 *
	 * @since		2.0
	 * @return		@c true if the lowercase mode is enabled, @n
	 *				else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLowerCaseModeEnabled()
	 */
	bool IsLowerCaseModeEnabled(void) const;

    /**
     * Enables or disables the lowercase mode.
	 *
	 * @since		2.0
	 * @param[in]	enable			Set to @c true to enable the lowercase mode, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			IsLowerCaseModeEnabled()
	 */
	void SetLowerCaseModeEnabled(bool enable);

// Ellipsis
	/**
	 * Gets the ellipsis position.
	 *
	 * @since		2.0
	 * @return		The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetEllipsisPosition()
	 */
	EllipsisPosition GetEllipsisPosition(void) const;

	/**
	 * Sets the ellipsis position.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	position			The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetEllipsisPosition()
	 */
	result SetEllipsisPosition(EllipsisPosition position);

// Keypad Action
	/**
	 * Gets the keypad action type.
	 *
	 * @since		2.0
	 * @return		The keypad action
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	KeypadAction GetKeypadAction(void) const;

// Listeners
	/**
	 * Adds the specified action event listener. @n
	 * The added listener is notified when the user clicks the search bar button.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @see			RemoveActionEventListener()
	 */
	void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Removes the specified action event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddActionEventListener()
	 */
	void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);

	/**
	 * Adds the specified text event listener. @n
	 * The added listener can listen to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener		The event listener to be added
	 * @remarks		The added listener is notified when: @n
	 *              @li the user presses a key on the software keypad.
	 *              @li the user selects a word in the candidate list.
	 *              @li the user pastes a text.
	 * @see			RemoveTextEventListener()
	 */
	void AddTextEventListener(const Osp::Ui::ITextEventListener& listener);

	/**
	 * Removes the specified text event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextEventListener()
	 */
	void RemoveTextEventListener(const Osp::Ui::ITextEventListener& listener);

	/**
	 * Adds the specified search bar event listener. @n
	 * The added listener can listen to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @remarks		The added listener is notified when: @n
	 *              @li the user presses a key on the software keypad.
	 *              @li the user selects a word in the candidate list.
	 *              @li the user pastes a text.
	 * @see			AddSearchBarEventListener()
	 */
	void AddSearchBarEventListener(const ISearchBarEventListener& listener);

	/**
	 * Removes the specified search bar event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see         RemoveTextEventListener()
	 */
	void RemoveSearchBarEventListener(const ISearchBarEventListener& listener);
	
	/**
	 * Adds the specified text block event listener. 
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @remarks		Programmatically, modification of the text selection does not cause the text block selection event to fire.
	 * @see			RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(const Osp::Ui::ITextBlockEventListener& listener);

	/**
	 * Adds the specified keypad event listener. @n
	 * The added listener is notified when the keypad associated with this text editor is opened or closed.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be added
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

	/**
	 * Removes the specified keypad event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(const Osp::Ui::IKeypadEventListener& listener);

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 * Frees the resources allocated by this control and destroys its native window if it is present).
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);

	// Reserves
protected:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
	virtual void SearchBar_Reserved1 (void) {};

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
	virtual void SearchBar_Reserved2 (void) {};

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
	virtual void SearchBar_Reserved3 (void) {};

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
	virtual void SearchBar_Reserved4 (void) {};

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
	virtual void SearchBar_Reserved5 (void) {};

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Set SearchBar input content information.
     * @since         2.0
	 */
	result SetContentInformation(Osp::Ui::Control* pContent);

private:
	friend class SearchBarEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
	class SearchBarEx* __pSearchBarEx;
	
protected:
	friend class SearchBarImpl;
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
	class SearchBarImpl* GetImpl(void) const;
}; // SearchBar
};};}; // Osp::Ui::Controls
#endif // _FUICTRL_SEARCHBAR_H_
