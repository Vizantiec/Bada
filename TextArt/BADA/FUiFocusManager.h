//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
// 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file	FUiFocusManager.h
 * @brief	This is the header file for the %FocusManager class.
 *
 * This header file contains the declarations of the %FocusManager class. @n.
 */
#ifndef _FUI_FOCUS_MANAGER_H_
#define _FUI_FOCUS_MANAGER_H_

// Includes
#include "FBaseObject.h"
#include "FUiConfig.h"

namespace Osp { namespace Ui { class Control; } }
namespace Osp { namespace Ui { class Window;  } }

namespace Osp { namespace Ui {
/**
 * @class	FocusManager 
 * @brief	This class manages the current focus of the application owned by the UI control and its ancestor Window.
 * @since	1.1 
 *
 * The %FocusManager class is used to query the application's current focus owner.
 */
class _EXPORT_UI_ FocusManager :
	public Osp::Base::Object
{
// Life-cycle
protected:
	/**
     * This is the default constructor for this class.
     *
     * @since	1.1
     */
	FocusManager(void);

		    
    /**
     * This is the destructor for this class.
     *
     * @since	1.1
     */
	virtual ~FocusManager(void);


// Operation
public:
    /**
     * Gets the pointer to the current focus manager.
     *
     * @since	1.1
     * @return	The current focus manager instance
     */
    static FocusManager* GetInstance(void);
    
    
    /**
     * Gets the current focus owner.
     *
     * @since	1.1
     * @return  The current focus owner
     * @remarks The method returns the current focus owner of this application.
     */    
    Control* GetCurrentFocusOwner(void);


    /**
     * Gets the current focused Window.
     *
     * @since	1.1
     * @return  The current focused Window
     * @remarks The method returns the application's current focus owner's ancestor Window or the Window that is currently focused.
     */      
    Window* GetCurrentFocusedWindow(void);


// Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Sets the current focus owner.
     *
     * @since			1.1
     * @return		An error code
     * @param[in] pCurrentOwner   The current focus owner
     * @exception	E_SUCCESS		The method is successful.
     * @exception	E_INVALID_ARG	The specified @c pCurrentOwner is invalid. @n
     *								
     * @exception	E_SYSTEM		A system error occurred.
     */    
    result SetCurrentFocusOwner(Control* pCurrentOwner);
    
    
// Attributes
protected:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The current focus owner.
	 *
	 * @since	1.1
	 */	
    Control* __pCurrentFocusOwner;
    
    
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The extension.
	 *
	 * @since	1.1
	 */	    
    void*    __pEx;
    
    
	friend class __FocusEventAdaptor;
	friend class Control;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_FOCUS_MANAGER_H_
