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
 * @file	FGrpCanvasCommon.h 
 * @brief	This is the header file for the %Canvas class.
 *
 * This header file contains the definitions of the enumerations of the %Canvas class.
 */ 
#ifndef _FGRP_CANVAS_COMMON_H_
#define _FGRP_CANVAS_COMMON_H_

//include
#include "FGrpConfig.h"


namespace Osp{ namespace Graphics{


/**
 * @enum	LineStyle
 *
 * Defines the line style. 
 *
 * @since	1.0
 */
enum LineStyle
{
	LINE_STYLE_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	LINE_STYLE_SOLID, /**< The solid line style */
	LINE_STYLE_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};

/**
 * @enum	ArcStyle
 *
 * Defines the arc style.
 *
 * @since	1.0
 */
enum ArcStyle
{
	ARC_STYLE_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	ARC_STYLE_ONLY, /**< An arc line is drawn */	
	ARC_STYLE_PIE, /**< A pie (arc and chords) is drawn */	
	ARC_STYLE_CHORD, /**< A chord is drawn */	
	ARC_STYLE_FILLED_PIE, /**< A filled pie is drawn */
	ARC_STYLE_FILLED_CHORD, /**< A filled chord is drawn */
	ARC_STYLE_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};

/**
 * @enum           FlipDirection
 *
 * Defines the flip direction.
 *
 * @since	1.0
 */
enum FlipDirection
{
	FLIP_DIRECTION_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	FLIP_DIRECTION_HORIZONTAL, /**< The horizontal type */
	FLIP_DIRECTION_VERTICAL, /**< The vertical type */
	FLIP_DIRECTION_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};

} }

#endif // _FGRP_CANVAS_COMMON_H_





