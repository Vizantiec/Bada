/* $Change: 999320 $ */
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
 * @file	FUiGridLayout.h
 * @brief	This is the header file for the %GridLayout class.
 *
 * This header file contains the declarations of the %GridLayout class.
 */
#ifndef _FUI_GRID_LAYOUT_H_
#define _FUI_GRID_LAYOUT_H_

// Includes
#include "FUiLayout.h"

namespace Osp { namespace Ui {

/**
 * @class	GridLayout
 * @brief	The grid layout positions the children of a container in a rectangular grid.
 * @since	2.0
 *
 * The %GridLayout class defines the grid layout for a Container. The layout positions the children of the %Container in a rectangular grid.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/grid_layout.htm">Grid Layout</a>.
 */
class _EXPORT_UI_ GridLayout :
	public Layout
{
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */	
	GridLayout(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~GridLayout(void);

	/**
	 * Initializes this instance of %GridLayout with the specified parameters.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rowCount		The number of rows
	 * @param[in]	columnCount		The number of columns
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified index is out of range. @n
	 *								Either @c rowCount or @c columnCount is @c 0 or negative.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(int rowCount, int columnCount);

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Gets the number of rows in a grid layout.
	 *
	 * @since		2.0
	 * @return		The number of rows
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetRowCount(void) const;

	/**
	 * Gets the number of columns in a grid layout.
	 *
	 * @since		2.0
	 * @return		The number of columns
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetColumnCount(void) const;

	/**
	 * Sets the stretching ability of the specified column.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	stretchable		Set to @c true to make the column stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnStretchable(int columnIndex, bool stretchable);

	/**
	 * Sets the shrinking ability of the specified column.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	shrinkable		Set to @c true to make the column shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnShrinkable(int columnIndex, bool shrinkable);

	/**
	 * Sets the collapsibility of a column.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	collapsed		Set to @c true to make the column collapsible, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnCollapsed(int columnIndex, bool collapsed);
	
	/**
	 * Sets the stretching ability of all the columns.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	stretchable		Set to @c true to set all columns as stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllColumnsStretchable(bool stretchable);

	/**
	 * Sets the shrinking ability of all the columns.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	shrinkable		Set to @c true to set all columns as shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllColumnsShrinkable(bool shrinkable);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c columnIndex is 0.
	 * @remarks		The column spacing cannot be applied to the first column.
	 */
	result SetColumnSpacing(int columnIndex, int space);

	/**
	 * Sets the stretching ability of the specified row.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	stretchable		Set to @c true to make the row stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowStretchable(int rowIndex, bool stretchable);

	/**
	 * Sets the shrinking ability of the specified row.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	shrinkable		Set to @c true to make the row shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowShrinkable(int rowIndex, bool shrinkable);

	/**
	 * Sets the collapsibility of the specified row.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	collapsed		Set to @c true to make the row as collapsible, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowCollapsed(int rowIndex, bool collapsed);
	
	/**
	 * Sets the stretching ability of all the rows.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	stretchable		Set to @c true to set all the rows as stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllRowsStretchable(bool stretchable);

	/**
	 * Sets the shrinking ability of all the rows.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	shrinkable		Set to @c true to set all the rows as shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllRowsShrinkable(bool shrinkable);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c rowIndex is @c 0.
	 * @remarks		The row spacing cannot be applied to the first column.
	 */
	result SetRowSpacing(int rowIndex, int space);

	/**
	 * Adds the control at the specified position. @n
	 * Sets the position and span of the control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl		The control for which the position is set
	 * @param[in]	rowStartIndex		The row index
	 * @param[in]	columnStartIndex	The column index
	 * @param[in]	rowSpan				The row span specifies the total number of cells in a row that are to be merged into a cell
	 * @param[in]	columnSpan			The column span specifies the total number of cells in a column that are to be merged into a cell
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   	Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- Either @c rowSpan or @c columnSpan is @c 0 or negative. @n
	 *									- The specified @c childControl parameter is not a child of the container that owns the layout. @n
	 *									- The specified span has tried to include a cell, which is already included in another span.
	 * @exception	E_OUT_OF_RANGE		The specified index is out of range, or @n
	 *									the calculated range of the cell is out of the grid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPosition(Control& childControl, int rowStartIndex, int columnStartIndex, int rowSpan, int columnSpan);

	/**
	 * Sets the horizontal alignment and the vertical alignment.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	childControl		The control for which the alignment is set
	 * @param[in]	horizontalAlignment	The horizontal alignment
	 * @param[in]	verticalAlignment	The vertical alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG   	A specified input parameter is invalid. @n
	 *									The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		          			By default, the value of @c horizontalAlignment is HORIZONTAL_ALIGN_LEFT and the value of @c verticalAlignment is 
	 *									VERTICAL_ALIGN_TOP.
	 *				          			The column width is set to the largest width amongst controls in the column, and the row height is set to the largest 
	 *									height amongst controls in the row.
	 *				          			Therefore, the smaller controls have vertical or horizontal margins around them, and they are repositioned in cells 
	 *									according to the alignment options.
	 */
	result SetAlignment(Control& childControl, LayoutHorizontalAlignment horizontalAlignment, LayoutVerticalAlignment verticalAlignment);

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
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetMargin(Control& childControl, int left, int right, int top, int bottom);

private:
	/**
	 * This is the copy constructor for this class.
	 *
	 * @since	2.0
	 */
	GridLayout(const GridLayout& layout);
	
	/**
	 * This is the substitution operator for this class.
	 *
	 * @since	2.0
	 */
	GridLayout& operator=(const GridLayout& layout);

protected:

	friend class GridLayoutEx;

	/**
     * @internal This value is for internal use only. The bada platform team is not 
	 *           responsible for any behavioral correctness, consistency, and 
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class GridLayoutEx* __pGridLayoutEx;
};
} } //Osp::Ui
#endif//_FUI_GRID_LAYOUT_H_
