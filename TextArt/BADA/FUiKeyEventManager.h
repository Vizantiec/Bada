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
 * @file		FUiKeyEventManager.h
 * @brief		This is the header file for the %KeyEventManager class.
 *
 * This header file contains the declarations of the %KeyEventManager class.
 */
#ifndef _FUI_KEY_EVENT_MANAGER_H_
#define _FUI_KEY_EVENT_MANAGER_H_

// Includes
#include "FBaseObject.h"
#include "FBaseErrors.h"
#include "FUiConfig.h"
#include "FUiIKeyEventListener.h"

// Forward declarations
namespace Osp { namespace Base { namespace Runtime { class IEvent;    } } }
namespace Osp { namespace Base { namespace Runtime { class IEventArg; } } }
namespace Osp { namespace Ui   { class Control; } } 

namespace Osp {namespace Ui {
/**
 * @class	KeyEventManager 
 * @brief	This class manages the key events that are fired within the context of this application.
 * @since	1.1
 *
 * The %KeyEventManager class listens to all key events that are generated within the application's context.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _EXPORT_UI_ KeyEventManager :
	public Osp::Base::Object
{
// Life-cycle
protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	1.1
	 */
	KeyEventManager(void);

	/**
	 * Initializes this instance of %KeyEventManager.
	 *
	 * @since		1.1
 	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(void);
	
	
public:		    
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.1
	 */
	virtual ~KeyEventManager(void);


// Operation
public:
    /**
     * Gets the pointer to the current key event manager.
     *
     * @since	 	1.1
     * @return		The current %KeyEventManager instance
     */
    static KeyEventManager* GetInstance(void);

  
    /**
     * Adds an application-wide IKeyEventListener instance. @n
     * The added listeners get notified when a key is pressed, released, or long pressed within the context of this application.
     *
     * @since		1.1  
     * @param[in] 	listener    The event listener to be added
     * @remarks     The listener is called after the key event is delivered to the focused control's key event listeners, but before the
     *              key event is passed onto the focused control itself. @n
     *              Moreover, if the key needs to be consumed by the control itself, the added listeners will not be notified.
     * @see         RemoveKeyEventListener ()
     */
    void AddKeyEventListener(const IKeyEventListener& listener);
    
        
    /**
     * Removes the %IKeyEventListener instance. @n
     * The removed listener is not notified even when the key events are fired.
     *
     * @since		1.1
     * @return		listener		The current application-wide key event listener to be removed
     * @see			AddKeyEventListener()
     */
    void RemoveKeyEventListener(const IKeyEventListener& listener);

        
 // Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Processes the key event fired within this application's context.
     *
     * @since			1.1
     * @return			An error code
     * @param[in]		source          The key event owner
     * @param[in]		arg             The key event arg
     * @exception		E_SUCCESS		The method is successful.
     * @exception		E_SYSTEM		A system error occurred.
     */    
    result ProcessKeyEvent(Control& source, const Osp::Base::Runtime::IEventArg& arg);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Sets the pointer to the current key event manager.
     *
     * @since		1.1
     * @return  The current KeyEventManager instance
     */
    static void SetInstance(KeyEventManager* pKeyEventManager);    
    
    
// Attributes
protected:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The key event.
	 *
	 * @since	1.1
	 */	
	Osp::Base::Runtime::IEvent*	__pKeyEvent;
	
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
    void* __pEx;
	
	
	friend class __KeyEventAdaptor;
	friend class __ControlManager;
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_KEY_EVENT_MANAGER_H_
