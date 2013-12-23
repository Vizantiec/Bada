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
 * @file    FUiCtrlTabBarItem.h
 * @brief   This is the header file for the %TabBarItem class.
 *
 * This header file contains the declarations of the %TabBarItem class.
 */
#ifndef _FUICTRL_TAB_BAR_ITEM_H_
#define _FUICTRL_TAB_BAR_ITEM_H_


//includes
#include "FBaseObject.h"
#include "FUiCtrlConfig.h"

// forward declaration
namespace Osp { namespace Ui { namespace Controls { class TabBarItemEx; }; }; };


namespace Osp {	namespace Ui { namespace Controls {
/**
 * @class	TabBarItem
 * @brief	This class is an implementation of %TabBarItem.
 * @since	2.0
 *
 * The %TabBarItem class is a helper class that specifies the contents of a tab bar item.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_tab_bar.htm">TabBar</a>.
 */
class _EXPORT_CONTROLS_ TabBarItem :
	public Osp::Base::Object
{
// Lifecycle
public:
    /**
     * This is the default constructor for this class.
     *
     * @since 2.0
     */
	TabBarItem(void);


	/**
	 * This is the destructor for this class
	 *
	 * @since 2.0
	 */
	virtual ~TabBarItem(void);


	/**
	 * Initializes this instance of %TabBarItem with the specified parameters.
	 *
	 * @since 		2.0
	 * @return      An error code
	 * @param[in]   text                The item text
	 * @param[in]	actionId	        The action ID of this item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The @c actionId of the specified item must be greater than or equal to @c 0.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient. 
	 * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 */
    result Construct(const Osp::Base::String& text, int actionId);


// Operation
public:
	/**
	 * Sets the action ID of the item.
	 *
	 * @since 		2.0
	 * @return      An error code
	 * @param[in]	actionId		    The action ID for this item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The @c actionId of the specified item must be a positive integer.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 */
	result SetActionId(int actionId);


	/**
	 * Gets the action ID of the item.
	 *
	 * @since		2.0
	 * @return      The action ID, @n
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE		This instance is in an invalid state. 
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActionId(void) const;


	/**
	 * Gets the text of the item.
	 *
	 * @since 		2.0
	 * @return		The item text, @n
	 *				else an empty string if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetText(void) const;


	/**
	 * Sets the text of the item.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in] 	text		        The text to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state. 
	 * @remarks		If the size of the text exceeds the displayable area, the font size of the text is decreased automatically.
	 */
	result SetText(const Osp::Base::String& text);
	
	
private:
	friend class TabBar;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
	class TabBarItemEx *__pTabBarItemEx;
};	//class declaration
};};};	//for namespaces

#endif /* _FUICTRL_TAB_BAR_ITEM_H_ */
