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
 * @file	FGrpFontCommon.h 
 * @brief	This is the header file for the enumerations of the Font class.
 *
 * This header file contains the definitions of the enumerations of the Font class.
 */ 
#ifndef _FGRP_FONT_COMMON_H_
#define _FGRP_FONT_COMMON_H_


//include
#include "FGrpConfig.h"


namespace Osp { namespace Graphics {
/**
* @enum	FontStyle
*
* Defines the style of the %Font class instance.
*
* @since		1.0
* @remarks 	Several different font styles can be combined using the "OR" operator. @n
*			(ex: int style = FONT_STYLE_BOLD | FONT_STYLE_ITALIC) 
*/
enum FontStyle 
{	
	FONT_STYLE_MIN = 0, /**< @internal Not used, min number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
	FONT_STYLE_PLAIN = 0x0001, /**< The plain font style */
	FONT_STYLE_BOLD = 0x0002, /**< The bold font style */
	FONT_STYLE_ITALIC = 0x0004, /**<The italic font style */
	FONT_STYLE_MAX /**< @internal Not used, counts the number of enumerated items. This is internal. If used in an application, the application can get rejected during the certification process. */
};


};};

#endif // _FGRP_FONT_COMMON_H_
