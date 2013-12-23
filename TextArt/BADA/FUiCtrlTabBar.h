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
 * @file    FUiCtrlTabBar.h
 * @brief   This is the header file for the %TabBar class.
 *
 * This header file contains the declarations of the %TabBar class.
 */
#ifndef _FUICTRL_TAB_BAR_H_
#define _FUICTRL_TAB_BAR_H_


// Includes
#include "FUiCtrlConfig.h"
#include "FUiControl.h"

// Forward declaration
namespace Osp { namespace Ui { class IActionEventListener; }; };
namespace Osp { namespace Ui { namespace Controls { class TabBarEx;	  }; }; };
namespace Osp { namespace Ui { namespace Controls { class TabBarItem; }; }; };


namespace Osp { namespace Ui { namespace Controls {    
/**
 * @enum	TabBarItemStatus
 *
 * Defines the possible states of %TabBarItem.
 * @since   2.0
 */
enum TabBarItemStatus
{
	TAB_BAR_ITEM_STATUS_NORMAL, 		/**< The normal state */
	TAB_BAR_ITEM_STATUS_SELECTED 		/**< The selected state */
};
    
    
/**
 * @class   TabBar
 * @brief   This class is an implementation of %TabBar.
 * @since   2.0
 *
 * The %TabBar class displays a list of possible options for the user selection in a horizontal list. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_tab_bar.htm">TabBar</a>.
 *
 * The following example demonstrates how to use the %TabBar class.
 *
 * @code

 // Sample Code for TabBarSample.h
#include <FUi.h>
#include <FUiControl.h>

class TabBarSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IActionEventListener
{
protected:

    	TabBar *__pTabBar;
    	static const int  ID_TABBAR_ITEM1 = 200;
    	static const int  ID_TABBAR_ITEM2 = 201;
    	static const int  ID_TABBAR_ITEM3 = 202;

public:
    virtual result OnInitializing(void);
    virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

// Sample Code for TabBarSample.cpp
#include "TabBarSample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

result
TabBarSample::OnInitializing()
{
    result r = E_SUCCESS;

    __pTabBar = new TabBar();
    __pTabBar->Construct(0, 0, 480);

	 TabBarItem tabBarItem1;
	 TabBarItem tabBarItem2;
	 TabBarItem tabBarItem3;

	 tabBarItem1.Construct("1",ID_TABBAR_ITEM1);
	 tabBarItem2.Construct("2",ID_TABBAR_ITEM2);
	 tabBarItem3.Construct("3",ID_TABBAR_ITEM3);

	__pTabBar->AddItem(tabBarItem1);
	__pTabBar->AddItem(tabBarItem2);
	__pTabBar->AddItem(tabBarItem3);

	__pTabBar->AddActionEventListener(*this);
	AddControl(*__pTabBar);

    return r;
}

// Implement an IActionEventListener
void
TabBarSample::OnActionPerformed(const Control& source, int actionId)
{
    switch (actionId)
    {
    case ID_TABBAR_ITEM1:
    	//To do
    	break;
    case ID_TABBAR_ITEM2:
    	//To do
    	break;
    default:
        break;
    }
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ TabBar :
    public Osp::Ui::Control
{
// Lifecycle
public:
    /**
     * This is the default constructor for this class.
     *
     * @since 	2.0
     */
    TabBar(void);
    
    
    /**
     * This is the destructor for this class.
     *
     * @since 	2.0
     */
    virtual ~TabBar(void);

    /**
     * Initializes this instance of %TabBar with the specified parameters.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   x               	The X position of the top left corner
     * @param[in]   y               	The Y position of the top left corner
     * @param[in]   width           	The width
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_INVALID_ARG   	A specified input parameter is invalid.
     * @exception   E_INVALID_STATE 	This instance is in an invalid state. 
     * @exception   E_OUT_OF_MEMORY 	The memory is insufficient. 
     * @exception   E_SYSTEM        	A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
     */
    result Construct(int x, int y, int width);


// Operation
public:
    /**
     * Adds the specified item.
     *		
     * @since       2.0
     * @return      An error code
     * @param[in]   item            	The item to be added
     * @exception   E_SUCCESS       	The method is successful.
     * @exception   E_INVALID_ARG   	The specified input parameter is invalid. @n
     *									The specified item is not constructed.
     * @exception   E_MAX_EXCEEDED  	The number of items has exceeded the maximum limit. 
     * @exception   E_OUT_OF_MEMORY 	The memory is insufficient. 
     * @exception   E_INVALID_STATE 	This instance is in an invalid state. 
     * @exception   E_SYSTEM        	A system error has occurred.
     * @remarks		The maximum number of items for a TabBar control is @c 100. @n
     *              However, the content of the specified item is copied to the %TabBar control. @n
	 *              The item can be deallocated explicitly after this method call if it is created dynamically. @n
     *              The TabBar control does not throw any exception even though the same action ID is assigned to multiple items.
     */
    result AddItem(const TabBarItem& item);


    /**
     * Inserts the %TabBar item at the specified index.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   index             	The index of the item to be inserted
     * @param[in]   item              	The item to be inserted
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_INVALID_ARG     	A specified input parameter is invalid. @n
     *								  	The specified item is not constructed.
     * @exception   E_MAX_EXCEEDED    	The number of items has exceeded the maximum limit. 
     * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n 
	 *									The specified @c index is either greater than or equal to the number of items or is less than zero.
     * @exception   E_OUT_OF_MEMORY   	The memory is insufficient.
     * @exception   E_INVALID_STATE   	This instance is in an invalid state.
     * @exception   E_SYSTEM          	A system error has occurred.
     * @remarks     The maximum number of items for a TabBar control is @c 100. @n 
     *              However, the content of the specified item is copied to the @c TabBar control. @n
	 *              The item can be deallocated explicitly after this method call if it is created dynamically. @n
     *              The %TabBar control does not throw any exception even though the same action ID is assigned to multiple items. 
     */
    result InsertItemAt(int index, const TabBarItem& item);


    /**
     * Gets the color of the %TabBar control.
     *
     * @since       2.0
     * @return      The color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
    Osp::Graphics::Color GetColor(void) const;


    /**
     * Gets the item count.
     *
     * @since       2.0
     * @return      The item count, @n 
     *              else @c -1 if an error occurs
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
    int GetItemCount(void) const;


    /**
     * Gets the item color that is displayed when an item is selected.
     *
     * @since       2.0
     * @return      The selected item color, @n
	 *				else RGBA(0,0,0,0) if an error occurs  
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetSelectedItemColor(void) const;


    /**
     * Gets the item text color for the specified state.
     *
     * @since       2.0
     * @return      The item text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
     * @param[in]   status              The item state
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Osp::Graphics::Color GetItemTextColor(TabBarItemStatus status) const;


    /**
     * Gets the index of the selected item.
     *
     * @since       2.0
     * @return      The selected item index, @n 
     *              else @c -1 if an error occurs
     * @exception   E_SUCCESS           	The method is successful.
     * @exception   E_INVALID_STATE     	This instance is in an invalid state. 
     * @remarks     The specific error code can be accessed using the GetLastResult() method. 
     */
    int GetSelectedItemIndex(void) const;


    /**
     * Removes the %TabBar item at the specified index.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   index             	The index of the item
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0. 
     * @exception   E_INVALID_STATE   	This instance is in an invalid state. 
     * @exception   E_SYSTEM          	A system error has occurred.
     * @remarks     If the currently selected item is removed, the next item is selected automatically.
     */
    result RemoveItemAt(int index);


    /**
     * Removes all the items from the %TabBar control.
     *
     * @since       2.0
     * @return      An error code
     * @exception   E_SUCCESS         The method is successful.
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     * @exception   E_SYSTEM          A system error has occurred.
     */
    result RemoveAllItems(void);


    /**
     * Sets the color of the %TabBar control.
     *		
     * @since       2.0
     * @return      An error code
     * @param[in]   color             The color
     * @exception   E_SUCCESS         The method is successful.
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     */
    result SetColor(const Osp::Graphics::Color& color);
    
    
    /**
     * Sets the content of the %TabBar item at the specified index.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   index             	The index at which to set the specified item
     * @param[in]   item              	The item to be set
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
     *								  	The specified item is not constructed.
     * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n 
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0. 
     * @exception   E_INVALID_STATE		This instance is in an invalid state. 
     * @exception   E_SYSTEM			A system error has occurred.
     * @remarks     The contents of the specified item are copied. @n
	 *              The item can be deallocated explicitly after this method call if it is created dynamically.
     */
    result SetItemAt(int index, const TabBarItem& item);
        
    
    /**
     * Selects the item at the specified index.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   index             	The index of the item to be selected
     * @exception   E_SUCCESS         	The method is successful.
     * @exception   E_OUT_OF_RANGE    	The specified @c index is not within the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0. 
     * @exception   E_INVALID_STATE   	This instance is in an invalid state. 
     * @exception   E_SYSTEM          	A system error has occurred.
     */
    result SetItemSelected(int index);


    /**
     * Sets the item text color for the specified state.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   status            The item state
     * @param[in]   color             The item text color
     * @exception   E_SUCCESS         The method is successful.
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     * @exception   E_SYSTEM          A system error has occurred.
     */
    result SetItemTextColor(TabBarItemStatus status, const Osp::Graphics::Color& color);


    /**
     * Sets the selected item color.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   color             The item color
     * @exception   E_SUCCESS         The method is successful.
     * @exception   E_INVALID_STATE   This instance is in an invalid state. 
     * @exception   E_SYSTEM          A system error has occurred.
     */
    result SetSelectedItemColor(const Osp::Graphics::Color& color);


    /**
     * Sets the width of the tab bar.
     *
     * @since       2.0
     * @return      An error code
     * @param[in]   width             The width
     * @exception   E_SUCCESS         The method is successful.
     * @exception   E_INVALID_ARG     A specified input parameter is invalid.
     * @exception   E_INVALID_STATE   This instance is in an invalid state.
     * @exception   E_SYSTEM          A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
     */
    result SetWidth(int width);


//Listeners
public:
    /**
     * Adds an action event listener instance. @n
     * The added listener can listen to events on the specified event dispatcher's context when they are fired.
     *
     * @since 		2.0
     * @param[in]   listener		The event listener to be added
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    void AddActionEventListener(const Osp::Ui::IActionEventListener& listener);


    /**
     * Removes an action event listener instance. @n
     * The removed listener cannot listen to events when they are fired.
     *
     * @since 		2.0
     * @param[in]   listener		The event listener to be removed
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    void RemoveActionEventListener(const Osp::Ui::IActionEventListener& listener);


// Lifecycle
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
    result Dispose(void);

//Attributes
private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
    TabBarEx* __pTabBarEx;
protected:
	friend class TabBarImpl;
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
	class TabBarImpl* GetImpl(void) const;
};  //class declaration
};};};  //for namespaces
#endif /* _FUICTRL_TAB_BAR_H_ */
