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
 * @file		FGraphics.h 
 * @brief		This is the header file for the %Graphics namespace.
 *
 * This header file contains the declarations of the %Graphics namespace.
 *
 */
#ifndef _FGRAPHICS_H_
#define _FGRAPHICS_H_


#ifdef DrawText
#undef DrawText
#endif


#include "FGrpPoint.h"
#include "FGrpFontCommon.h"
#include "FGrpFont.h"
#include "FGrpDimension.h"
#include "FGrpRectangle.h"
#include "FGrpColor.h"
#include "FGrpCanvasCommon.h"
#include "FGrpBufferInfo.h"
#include "FGrpCanvas.h"
#include "FGrpBitmapCommon.h"
#include "FGrpBitmap.h"
#include "FGrpEnrichedText.h"	//##hwcho_20091221
#include "FGrpTextElement.h"



/**
 * @namespace Osp::Graphics
 * @brief	This namespace contains classes for drawing-related functionalities.
 * @since	1.0
 * @remarks	@b Header @b %file: @b \#include @b <FGraphics.h> @n
 *			@b Library: @b FOsp
 *
 * The %Graphics namespace provides enhanced two-dimensional graphics, 
 * text, and imaging capabilities.
 * It supports comprehensive features for rendering geometric primitives, text, and images
 * in a flexible framework for developing rich user 
 * interfaces, sophisticated drawing applications, and image editors. 
 * This namespace provides additional features such as Bitmap, Font, and Color to enhance the rendered graphics.
 * The user can also use basic data types, Point, Rectangle, and Dimension to construct 2D graphic objects, such as
 * polygons.
 * 
 * For more information on the %Graphics namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/graphics/graphics_namespace.htm">Graphics Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Graphics namespace. 
 * @image html graphics_namespace_class_relationship.png
 * 
 * The following example demonstrates how to use the %Graphics namespace.
 * 
 *	@code
#include <FBase.h>
#include <FGraphics.h>

using namespace Osp::Base;
using namespace Osp::Graphics;

bool
MyClass::GraphicsSample(void)
{
	result r = E_SUCCESS;
	
	// Creates a canvas instance
	Canvas* pCanvas = new Canvas();
	r = pCanvas->Construct();
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Clears
	pCanvas->SetBackgroundColor(Color(0xFF, 0xFF, 0xFF));
	r = pCanvas->Clear();
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Sets the foreground color of this canvas
	pCanvas->SetForegroundColor(Color::COLOR_GREEN);

	// Draws an ellipse
	r = pCanvas->DrawEllipse(Rectangle(50, 50, 50, 80));
	if (IsFailed(r))
	{
		goto CATCH;
	}

	r = pCanvas->DrawLine(Point(100, 100), Point(150, 150));
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Draws a circular arc
	r = pCanvas->DrawArc(Rectangle(10, 200, 50, 50), 30, 60, ARC_STYLE_PIE);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	{
		// Creates a font instance
		Font font;
		r = font.Construct(FONT_STYLE_PLAIN, 32);
		if (IsFailed(r))
		{
			goto CATCH;
		}

		// Sets the font to canvas
		r = pCanvas->SetFont(font);
		if (IsFailed(r))
		{
			goto CATCH;
		}
	}

	// Draws text at the specified location
	r = pCanvas->DrawText(Point(50, 50), String(L"Hello World"));
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Shows the drawing result on the device screen
	r = pCanvas->Show();
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Cleans up
	delete pCanvas;
	
	return true;

CATCH:
	delete pCanvas;
	
	return false;
}
 *	@endcode
 * 
 * 
 * 
 *
 */
namespace Osp
{

namespace Graphics
{

}; // Osp::Graphics
}; // Osp
#endif //_FGRAPHICS_H_


