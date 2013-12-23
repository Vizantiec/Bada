/* $Change: 1142016 $ */
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
 * @file		FUiContainer.h
 * @brief		This is the header file for the %Container class.
 *
 * This header file contains the declarations of the %Container class.
 */
#ifndef _FUI_CONTAINER_H_
#define _FUI_CONTAINER_H_

//Includes
#include "FBaseTypes.h"
#include "FBaseColLinkedList.h"
#include "FUiConfig.h"
#include "FUiControl.h"

//Forward declarations
namespace Osp { namespace Ui { namespace Controls { class Frame; } } }
namespace Osp { namespace Ui { namespace Controls { class Form; } } }
namespace Osp { namespace Ui { namespace Controls { class MessageBox; } } }
namespace Osp { namespace Ui { namespace Controls { class Popup; } } }
namespace Osp { namespace Ui { namespace Controls { class ContextMenu; } } }
namespace Osp { namespace Ui { namespace Controls { class OptionMenu; } } }
namespace Osp { namespace Ui { namespace Controls { class ColorPicker; } } }
namespace Osp { namespace Ui { namespace Controls { class DatePicker; } } }
namespace Osp { namespace Ui { namespace Controls { class TimePicker; } } }
namespace Osp { namespace Ui { namespace Controls { class EditDate; } } }
namespace Osp { namespace Ui { namespace Controls { class EditTime; } } }
namespace Osp { namespace Ui { namespace Controls { class Keypad; } } }
namespace Osp { namespace Ui { namespace Controls { class ScrollPanel; } } }
namespace Osp { namespace Ui { namespace Controls { class __ClipboardPopup; } } }
namespace Osp { namespace Ui {

class __ContainerDrawEventAdaptor;

class Layout;

/**
 * @class	Container
 * @brief	This class is an abstract base class of all the generic containers of Controls.
 * @since	1.0
 *
 * @remarks As the %Container is an abstract class, use the Osp::Ui::Controls::Panel class or another class derived from
 * %Container to apply the container functionality.
 *
 * The %Container class is the abstract base class of all generic Control containers. A container is a UI element which can contain
 * other UI elements. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/containers.htm">Containers</a>.
 *
 
 *
 */
class _EXPORT_UI_ Container :
	public Control
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Container(void) = 0;


// Operations
public:
	/**
	 * Adds the control at the end of the list maintained by the container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control         The control to be added to the container
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid. @n
	 *                              The specified @c control is an instance of Window, or this control's parent container.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient. 
	 * @exception	E_MAX_EXCEEDED	The number of child controls has exceeded the maximum limit.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		When the control is added, it is placed at the top of the drawing stack maintained by the container. @n
	 *              This means the last control added is drawn last.
	 * @remarks		A control becomes displayable only after it has been added to a displayable container. Some methods may not work normally if the methods 
	 *				of the control are called before adding the control to a container. After the control is added to a %Container, the OnInitializing() 
	 *				method of the control are called before adding the control to a container. After the control is added to a Container, the 
	 *				OnInitializing() method of the control is invoked for the initialization of the control such as creating and adding child controls.
	 * @see			Osp::Ui::Control::OnInitializing()
	 * @see			Osp::Ui::Control::OnTerminating()
	 * @code
	 *	{
	 *		// Sample uses Panel instead of Container, because Container is an abstract class.
	 *		Panel* pPanel = new Panel();
	 *		pPanel->Construct(Rectangle(100, 250, 300, 300));
	 *
	 *		Form* pForm = new Form();
	 *		pForm->Construct(FORM_STYLE_NORMAL|FORM_STYLE_TITLE|FORM_STYLE_INDICATOR);
	 *		pForm->AddControl(*pPanel);
	 *
	 *		//...
	 *		pForm->Draw();
	 *		pForm->Show();
	 *		//...
	 *	}
	 * @endcode
	 */
	virtual result AddControl(const Control& control);


	/**
	 * Called when the container needs to draw itself. @n
	 * Users can override this method to display user-specific drawings. @n
	 * This method is called after the container has drawn itself, but just before the container draws its child controls.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	virtual result OnDraw(void);


	/**
	 * Removes the specified control from the container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control         	The child control to be removed
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range (that is, the @c control is not found).
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		The removed child control is deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see			Osp::Ui::Control::OnTerminating()
	 */
	virtual result RemoveControl(const Control& control);


	/**
	 * Removes the specified control from the container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	index           	The index of the control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE  	The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		The removed child control is deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see			Osp::Ui::Control::OnTerminating()
	 */
	virtual result RemoveControl(int index);


	/**
	 * Removes all the controls from the container.
	 *
	 * @since			1.0
	 * @remarks 		The removed child controls are deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see				Osp::Ui::Control::OnTerminating()
	 */
	virtual void RemoveAllControls(void);


// Accessor
public:
	/**
	 * Gets the control at the specified index of the list that is kept by the container.
	 *
	 * @since		1.0
	 * @return		The control at the specified index of the list, @n
	 *              else @c null if the index is not valid
	 * @param[in]	index	The index of the control 
	 */
	virtual Control* GetControl(int index) const;


	/**
	 * Gets the control with the specified name. @n
	 * If there are multiple matches of the name, the first match is returned.
	 *
	 * @since		1.0
	 * @return		The control having the specified name, @n
	 *				else @c null if the name is not valid
	 * @param[in]	name		The name of the control
	 * @param[in]	recursive	Set to @c true to find a match recursively, @n 
	 *							else @c false
	 */
	virtual Control* GetControl(const Osp::Base::String& name, bool recursive = false) const;


	/**
	 * Gets the number of the controls in the container.
	 *
	 * @since		1.0
	 * @return		The number of controls in the container
	 */
	int GetControlCount(void) const;


	/**
	 * Gets a list of the controls of the container.
	 *
	 * @since		1.0
	 * @return		The list of the controls of the container
	 */
	virtual Osp::Base::Collection::IList* GetControls(void) const;

// Layout Operations
public:
	/**
	 * Gets the portrait layout of the container.
	 *
	 * @since		2.0
	 * @return		The portrait layout of the container, @n
	 *				else @c null if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetPortraitLayoutN(void) const;

	/**
	 * Gets the landscape layout of the container.
	 *
	 * @since		2.0
	 * @return		The landscape layout of the container @n
	 *				@c null, if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetLandscapeLayoutN(void) const;

	/**
	 * Gets the layout of the current orientation.
	 *
	 * @since		2.0
	 * @return		The layout of the current orientation, @n
	 *				else @c null if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetLayoutN(void) const;

// Inquiry
public:
	/**
	 * Checks whether the specified control is a child or descendant of the container.
	 *
	 * @since		1.0
	 * @return      @c true if the specified control is within the containment hierarchy of the container, @n
	 *              else @c false
	 * @param[in]	control		The control
	 */
	bool IsAncestorOf(const Control& control) const;


// Lifecycle
protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	Container(void);


	/**
	 * Initializes this instance of %Container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 */
	result Construct(void);


	/**
	 * Gets the index of the specified control.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control				The control
	 * @param[out]	index				The index of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance of Control is not found. 
	 * @see			SetControlAt()
	 *
	 */
	result GetControlAt(const Control& control, int& index) const;


	/**
	 * Sets the control at the specified index.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control         The control
	 * @param[in]	index           The index
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c control must be first added to this container. @n
	 *				Call the Draw() method after this, to apply the change to be shown.
	 * @see         Draw(), GetControlAt()
	 *
	 */
	virtual result SetControlAt(const Control& control, int index);


// Operation
protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Adds the specified control to the container.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @param[in]	control         The control to add to this container
	 * @param[in]	index           The z-order index of the control
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The argument passed to a method contains an invalid value (that is, the control is an instance of Window, or the control's parent container).
	 * @exception	E_OUT_OF_RANGE  The specified @c index is out of range.
	 * @exception	E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception	E_SYSTEM        A system error has occurred.
	 */
	virtual result AddControlImplAt(const Control& control, int index);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Notifies the container that it is now added to a control containment hierarchy.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @exception	E_INVALID_OPERATION This container is currently assigned to a native peer window.
	 * @remarks		When this method is called, the notified containers also notify the information to all their child controls.
	 * @see         Osp::Ui::Control::AddNotify(void)
	 */
	virtual result AddNotify(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this Container.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS   The method is successful.
	 * @exception	E_SYSTEM    Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the child controls of the container.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	virtual result DrawChildControls(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Returns a pointer to the given control handle
	 *
	 * @since				 1.0
	 * @return       A pointer to the given control handle
	 * @param[in]    handle		The control handle
	 * @param[in]    recursive	Set to @c true to find a match recursively @n 
	 *				  @c false, otherwise
	 * @remarks		This method is valid only if the given Control is in the Parent-Child hierarchy of the Container.
	 *
	 */
	Control* GetControl(Handle handle, bool recursive) const;


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		@b WARNING: This method should only be invoked by the framework.
	 * @remarks		When this method is called, the containers also notify all their child controls.
	 * @see         Osp::Ui::Control::RemoveNotify(void)
	 */
	virtual result RemoveNotify(void);


	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Removes the specified control from index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]   handle			The control handle
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result	RemoveContolFromIndex(const Handle handle);

private:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Draws the content of this container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method failed.
	 */
	virtual result __Draw(void);

	/*
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Add the child controls to the container.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @exception	E_INVALID_OPERATION This container is currently assigned to a native peer window.
	 */
	result AddNotifyToChildControl(void);

// Attribute
protected:

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The list of controls.
     * @since         1.0
	 */
	Osp::Base::Collection::LinkedList __controls;

private:
	friend class Osp::Ui::Control;
	friend class Osp::Ui::Controls::Frame;
	friend class Osp::Ui::Controls::Form;
	friend class Osp::Ui::Controls::MessageBox;
	friend class Osp::Ui::Controls::Popup;
	friend class Osp::Ui::Controls::ContextMenu;
	friend class Osp::Ui::Controls::OptionMenu;
	friend class Osp::Ui::Controls::ColorPicker;
	friend class Osp::Ui::Controls::DatePicker;
	friend class Osp::Ui::Controls::TimePicker;
	friend class Osp::Ui::Controls::Keypad;
	friend class Osp::Ui::Controls::ScrollPanel;
	friend class Osp::Ui::Controls::__ClipboardPopup;
	friend class __ContainerDrawEventAdaptor;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The draw event adapter
     * @since         1.0
	 */
    void *	__pContainerDrawEventAdaptor;

	friend class ContainerEx;
	class ContainerEx* __pContainerEx;
	
protected:
	friend class ContainerImpl;

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
	class ContainerImpl* GetImpl(void) const;
	
};// Container
}; }; //Osp::Ui
#endif //_FUI_CONTAINER_H_

