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
 * @file		FUiLayout.h
 * @brief		This is the header file for the %Layout class.
 *
 * This header file contains the declarations of the %Layout class.
 */
#ifndef _FUI_LAYOUT_H_
#define _FUI_LAYOUT_H_

#include "FBaseObject.h"
#include "FUiConfig.h"

namespace Osp { namespace Ui {

/**
 *	@enum	LayoutType
 *	Defines the layout type.
 *
 *  @since	2.0
 */
enum LayoutType
{
	LAYOUT_RELATIVE,       /**< The relative layout */
	LAYOUT_VERTICAL_BOX,   /**< The vertical box layout */
	LAYOUT_HORIZONTAL_BOX, /**< The horizontal box layout */
	LAYOUT_GRID            /**< The grid layout */
};

/**
 *	@enum	RectangleEdgeRelation
 *	Defines the relative relation between the source control and the target control.
 *
 *  @since	2.0
 */
enum RectangleEdgeRelation
{
	RECT_EDGE_RELATION_LEFT_TO_LEFT,     /**< The left edge of the source control is aligned with the left edge of the target control */
	RECT_EDGE_RELATION_LEFT_TO_RIGHT,    /**< The left edge of the source control is aligned with the right edge of the target control */
	RECT_EDGE_RELATION_RIGHT_TO_RIGHT,   /**< The right edge of the source control is aligned with the right edge of the target control */
	RECT_EDGE_RELATION_RIGHT_TO_LEFT,    /**< The right edge of the source control is aligned with the left edge of the target control */
	RECT_EDGE_RELATION_TOP_TO_TOP,       /**< The top edge of the source control is aligned with the top edge of the target control */
	RECT_EDGE_RELATION_TOP_TO_BOTTOM,    /**< The top edge of the source control is aligned with the bottom edge of the target control */
	RECT_EDGE_RELATION_BOTTOM_TO_BOTTOM, /**< The bottom edge of the source control is aligned with the bottom edge of the target control */
	RECT_EDGE_RELATION_BOTTOM_TO_TOP     /**< The bottom edge of the source control is aligned with the top edge of the target control */
};

/**
 *	@enum	RectangleEdgeType
 *	Defines the edges of a rectangle.
 *
 *  @since	2.0
 */
enum RectangleEdgeType
{
	RECT_EDGE_LEFT,   /**< The left edge of a rectangle */
	RECT_EDGE_RIGHT,  /**< The right edge of a rectangle */
	RECT_EDGE_TOP,    /**< The top edge of a rectangle */
	RECT_EDGE_BOTTOM  /**< The bottom edge of a rectangle */
};


/**
 *	@enum	CenterAlignmentType
 *	Defines the center alignment for a control.
 *
 *  @since	2.0
 */
enum CenterAlignmentType
{
	CENTER_ALIGN_HORIZONTAL, /**< The alignment centers the child control horizontally with respect to the left and right side of its parent control */
	CENTER_ALIGN_VERTICAL    /**< The alignment centers the child control vertically with respect to the top and bottom side of its parent control */
};

/**
 *	@enum	FitPolicy
 *	Defines the fitting policy for a control.
 *
 *  @since	2.0
 */
enum FitPolicy
{
	FIT_POLICY_FIXED,   /**< The fixed size of a control */
	FIT_POLICY_CONTENT, /**< The size of the control that is large enough to fit its internal content */
	FIT_POLICY_PARENT   /**< The size of the control that is as large as its parent control */
};

/**
 *	@enum	VerticalDirection
 *	Defines the direction for the vertical box layout.
 *
 *  @since	2.0
 */
enum VerticalDirection
{
	VERTICAL_DIRECTION_DOWNWARD, /**< The direction that runs from the top to the bottom */
	VERTICAL_DIRECTION_UPWARD    /**< The direction that runs from the bottom to the top */
};

/**
 *	@enum	HorizontalDirection
 *	Defines the direction for the horizontal box layout.
 *
 *  @since	2.0
 */
enum HorizontalDirection
{
	HORIZONTAL_DIRECTION_RIGHTWARD, /**< The direction that runs from left to right */
	HORIZONTAL_DIRECTION_LEFTWARD   /**< The direction that runs from right to left */
};

/**
 *	@enum	LayoutHorizontalAlignment
 *	Defines the horizontal alignment for the grid layout.
 *
 *  @since	2.0
 */
enum LayoutHorizontalAlignment
{
	LAYOUT_HORIZONTAL_ALIGN_LEFT,   /**< The horizontal left alignment of the control */
	LAYOUT_HORIZONTAL_ALIGN_CENTER, /**< The horizontal center alignment of the control */
	LAYOUT_HORIZONTAL_ALIGN_RIGHT   /**< The horizontal right alignment of the control */
};

/**
 *	@enum	LayoutVerticalAlignment
 *	Defines the vertical alignment for the grid layout.
 *
 *  @since	2.0
 */
enum LayoutVerticalAlignment
{
	LAYOUT_VERTICAL_ALIGN_TOP,    /**< The vertical top alignment of the control */
	LAYOUT_VERTICAL_ALIGN_MIDDLE, /**< The vertical middle alignment of the control */
	LAYOUT_VERTICAL_ALIGN_BOTTOM  /**< The vertical bottom alignment of the control */
};


/**
 * @class	Layout
 * @brief	This class is the abstract base class of all the %Layout classes.
 * @since	2.0
 *
 * The %Layout class is the abstract base class of all the %Layout classes.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/layout.htm">Layout</a>.
 */
class _EXPORT_UI_ Layout :
	public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Layout(void);

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const = 0;

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */	
	Layout(void);

private:
	/**
	 * This is the copy constructor for the %Layout class.
	 *
	 * @since	2.0
	 */
	Layout(const Layout& layout);
	
	/**
	 * This is the substitution operator for this class.
	 *
	 * @since	2.0
	 */
	Layout& operator=(const Layout& layout);

protected:
	// reserved virtual methods for later extension
	/** 
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * The following methods are reserved, and the name of the methods can be changed at any time without prior notice.
	 *
	 * @since  2.0
	 */
	virtual void Layout_Reserved1 (void) {}

	/** 
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and its name can be changed at any time without prior notice.
	 *
	 * @since  2.0
	 */
	virtual void Layout_Reserved2 (void) {}

	friend class LayoutEx;

	/**
     * @internal This value is for internal use only. The bada platform team is not 
	 *           responsible for any behavioral correctness, consistency, and 
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class LayoutEx*	__pLayoutEx;
};

}; }; //Osp::Ui

#endif//_FUI_LAYOUT_H_
