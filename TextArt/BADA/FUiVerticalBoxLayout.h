/* $Change: 1006494 $ */
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
 * @file		FUiVerticalBoxLayout.h
 * @brief		This is the header file for the %VerticalBoxLayout class.
 *
 * This header file contains the declarations of the %VerticalBoxLayout class.
 */
#ifndef _FUI_VERTICAL_BOX_LAYOUT_H_
#define _FUI_VERTICAL_BOX_LAYOUT_H_

// includes
#include "FUiLayout.h"

namespace Osp { namespace Ui {

/**
 * @class	VerticalBoxLayout
 * @brief	The vertical box layout positions the children of a container vertically.
 * @since	2.0
 *
 * The %VerticalBoxLayout class defines the vertical box layout for a Container. The layout positions the children of the %Container vertically.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/single_dimensional_layout.htm">Vertical and Horizontal Box Layouts</a>.

 */
class _EXPORT_UI_ VerticalBoxLayout :
	public Layout
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */	
	VerticalBoxLayout(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~VerticalBoxLayout(void);

	/**
	 * Initializes this instance of %VerticalBoxLayout with the specified parameter.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	direction		The direction in which the children are attached
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(VerticalDirection direction);

	/**
	 * Gets the direction of the %VerticalBoxLayout.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[out]	direction		The direction in which the children are attached
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 */
	result GetDirection(VerticalDirection& direction) const;

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Sets the horizontal alignment of the specified control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the alignment is set
	 * @param[in]	alignment		The horizontal alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   	The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error occurred.
	 * @remarks		By default, the horizontal alignment is HORIZONTAL_ALIGNLEFT.
	 */
	result SetHorizontalAlignment(Control& childControl, LayoutHorizontalAlignment alignment);

	/**
	 * Sets the space between the specified control and its predecessor.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the space is set
	 * @param[in]	space		    The space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the spacing is set to @c 0.
	 */
	result SetSpacing(Control& childControl, int space);

	/**
	 * Sets the horizontal margins of the specified control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetHorizontalMargin(Control& childControl, int left, int right);

	/**
	 * Sets the width of the specified control with the fixed length.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width			The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, int width);

	/**
	 * Sets the width of the specified control with the fitting policy.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	policy			The fitting policy for the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHorizontalFitPolicy(Control& childControl, FitPolicy policy);
	
	/**
	 * Sets the height of the specified control with a fixed length.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	height			The value of the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHeight(Control& childControl, int height);

	/**
	 * Sets the height of the specified control with the fitting policy.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	policy			The fitting policy for the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		Setting FIT_POLICY_PARENT as @c policy does not cause the height of the control to change.
	 */
	result SetVerticalFitPolicy(Control& childControl, FitPolicy policy);
	
	/**
	 * Sets the weight of the specified control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the weight is set
	 * @param[in]	weight			The weight that indicates how much extra space the control occupies in proportion to it, in the %VerticalBoxLayout.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the weight is set to @c 0.0f.
	 */
	result SetWeight(Control& childControl, float weight);

private:
	/**
	 * This is the copy constructor for the %VerticalBoxLayout class.
	 *
	 * @since	2.0
	 */
	VerticalBoxLayout(const VerticalBoxLayout& layout);
	
	/**
	 * This is the substitution operator for this class.
	 *
	 * @since	2.0
	 */
	VerticalBoxLayout& operator=(const VerticalBoxLayout& layout);

protected:

	friend class VerticalBoxLayoutEx;

	/**
     * @internal This value is for internal use only. The bada platform team is not 
	 *           responsible for any behavioral correctness, consistency, and 
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class VerticalBoxLayoutEx* __pVerticalBoxLayoutEx;
};
} } //Osp::Ui
#endif //_FUI_VERTICAL_BOX_LAYOUT_H_
