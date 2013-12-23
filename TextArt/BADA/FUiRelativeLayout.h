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
 * @file		FUiRelativeLayout.h
 * @brief		This is the header file for the %RelativeLayout class.
 *
 * This header file contains the declarations of the %RelativeLayout class.
 */
#ifndef _FUI_RELATIVE_LAYOUT_H_
#define _FUI_RELATIVE_LAYOUT_H_

// includes
#include "FUiLayout.h"
#include "FUiControl.h"

namespace Osp { namespace Ui {

/**
 * @class	RelativeLayout
 * @brief	The relative layout positions the children of a container in a manner that is relative to other children or its parent container.
 * @since	2.0
 *
 * The %RelativeLayout class defines the relative layout for a %Container. The layout positions the children of the %Container relative to the
 * Container or its other children.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/relative_layout.htm">Relative Layout</a>.

 */
class _EXPORT_UI_ RelativeLayout :
	public Layout
{
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */	
	RelativeLayout(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~RelativeLayout(void);

	/**
	 * Initializes this instance of %RelativeLayout.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Gets the type of the layout.
	 *
	 * @since		2.0
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Sets the relation of the specified child control for the edge with other control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the relation is set
	 * @param[in]	targetControl	The target control @n
	 *								It should be a parent or sibling.
	 * @param[in]	edgeRelation	The edge of the specified control to be aligned with the edge of the target control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								Either the specified @c childControl or the specified @c targetControl is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRelation(Control& childControl, const Control& targetControl, RectangleEdgeRelation edgeRelation);

	/**
	 * Resets the relation of the specified control for the vertical edge.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the relation is reset
	 * @param[in]	edgeType		The edge type of the specified control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ResetRelation(Control& childControl, RectangleEdgeType edgeType);

	/**
	 * Sets the specified control at the center of the parent control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control to be center aligned
	 * @param[in]	alignment		The center alignment for a control either vertically or horizontally
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The relation value that is set to a child control is ignored when the center-alignment is applied to the control.
	 */
	result SetCenterAligned(Control& childControl, CenterAlignmentType alignment);

	/**
	 * Resets the center position of the specified control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control to be center aligned
	 * @param[in]	alignment		The center alignment for a control either vertically or horizontally
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result ResetCenterAligned(Control& childControl, CenterAlignmentType alignment);

	/**
	 * Sets the margins of the specified control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @param[in]	top				The top margin
	 * @param[in]	bottom			The bottom margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetMargin(Control& childControl, int left, int right, int top, int bottom);

	/**
	 * Sets the width of the specified control to the fixed size.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	width			The value of the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetWidth(Control& childControl, int width);

	/**
	 * Sets the width of the specified control as per the fitting policy.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the width is set
	 * @param[in]	policy			The fitting policy for the width
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHorizontalFitPolicy(Control& childControl, FitPolicy policy);
	
	/**
	 * Sets the height of the specified control to the fixed size.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	height			The value of the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetHeight(Control& childControl, int height);

	/**
	 * Sets the height of the specified control as per the fitting policy.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl	The control for which the height is set
	 * @param[in]	policy			The fitting policy for the height
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetVerticalFitPolicy(Control& childControl, FitPolicy policy);

private:
	/**
	 * This is the copy constructor for the %RelativeLayout class.
	 *
	 * @since	2.0
	 */
	RelativeLayout(const RelativeLayout& layout);
	
	/**
	 * This is the substitution operator for this class.
	 *
	 * @since	2.0
	 */
	RelativeLayout& operator=(const RelativeLayout& layout);

protected:

	friend class RelativeLayoutEx;

	/**
     * @internal This value is for internal use only. The bada platform team is not 
	 *           responsible for any behavioral correctness, consistency, and 
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class RelativeLayoutEx* __pRelativeLayoutEx;
};
} } //Osp::Ui
#endif//_FUI_RELATIVE_LAYOUT_H_
