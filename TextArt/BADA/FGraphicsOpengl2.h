/* $Change: 1028567 $ */
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
 * @file		FGraphicsOpengl2.h 
 * @brief		This is the header file for the %Opengl namespace.
 *
 * This header file contains the declarations of the %Opengl namespace.
 *
 */
/**
 * @defgroup opengles OpenGL(R) ES
 * @brief	The list of OpenGL(R)ES functions.
 */

 
#ifndef _FGRAPHICS_OPENGL_H_
#define _FGRAPHICS_OPENGL_H_



/**
 * @namespace	Osp::Graphics::Opengl
 * @brief	This namespace contains interfaces for %OpenGL(R).
 *
 * - <a href ="group__opengles.html"> OpenGL(R) ES</a>
 *
 * @since		1.0
 * @remarks	
 *			For OpenGL(R) ES 1.1: @n
 *			@b Header @b %file: @b \#include @b <FGraphicsOpengl.h> @n
 *			@b Library: @b FGraphicsOpengl, @b FGraphicsEgl @n	    
 *			For OpenGL(R) ES 2.0: @n
 *			@b Header @b %file: @b \#include @b <FGraphicsOpengl2.h> @n
 *			@b Library: @b FGraphicsOpengl, @b FGraphicsEgl @n
 *
 *
 *
 * 
 *
 * 
 * The %Opengl namespace provides support for rendering high performance 2D and 3D graphic objects using the
 * OpenGL(R)(Open %Graphics Library) specification. This namespace further supports the EGL, OpenGL(R) ES 1.1, and
 * OpenGL(R) ES 2.0 features.
 *
 * For more information on the %Opengl namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/opengl.htm">OpenGL&reg; Guide</a>.
 *
 *
 */
namespace Osp { namespace Graphics {
namespace Opengl
{
	#include <egl.h>
	#include <gl2.h>
	#include <gl2ext.h>

}; // Opengl
}; }; // Osp::Graphics
#endif // _FGRAPHICS_OPENGL_H_

