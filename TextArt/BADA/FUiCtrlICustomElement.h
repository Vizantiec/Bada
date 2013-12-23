/* $Change: 763368 $ */
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
 * @file	FUiCtrlICustomElement.h
 * @brief	This is the header file for the %ICustomElement interface.
 *
 * This header file contains the declarations of %ICustomElement and its helper classes.
 */

#ifndef _FUICTRL_ICUSTOM_ELEMENT_H_
#define _FUICTRL_ICUSTOM_ELEMENT_H_

//Includes
#include "FUiCtrlConfig.h"
#include "FBaseObject.h"
#include "FGrpCanvas.h"
#include "FUiCtrlListViewEnum.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @interface	ICustomElement
 * @brief 		This interface represents the common behaviors of a custom element.
 * @since		2.0
 *
 * The %ICustomElement interface is the listener interface for custom drawing in a list item.
 * The class that processes a custom drawing event implements this interface. The list items are added by calling the
 * AddElement(int elementId, const %ICustomElement &element) method. When the custom drawing event occurs and the list item must be
 * redrawn, the OnDraw() method is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_listviews.htm">ListViews</a>.

 * 
 *
 */
class _EXPORT_CONTROLS_	ICustomElement
{
public:
	/**
	 * This is the destructor for this class.
	 * @since	2.0
	 */
	virtual ~ICustomElement(void) {}

// Operation
public:
    /**
    * Called when a custom element of the item is drawn.
	*
    * @since	2.0
    *
    * @return    @c true if the drawing is successful, @n
    *            else @c false
    *
    * @param[in] canvas      The graphic canvas of the list control
    * @param[in] rect        The position and size of the element
    * @param[in] status      The status of the element
    * @remarks   This method should return @c true if the drawing is successful, else @c false. 
    */
	virtual bool OnDraw(Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect, Osp::Ui::Controls::ListItemDrawingStatus status) = 0;

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
    virtual void ICustomElement_Reserved1 (void) {}

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
    virtual void ICustomElement_Reserved2 (void) {}

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
    virtual void ICustomElement_Reserved3 (void) {}

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
    virtual void ICustomElement_Reserved4 (void) {}

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
    virtual void ICustomElement_Reserved5 (void) {}
};
}; }; }; // Osp::Ui::Controls
#endif
