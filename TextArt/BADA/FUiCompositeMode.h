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
 * @file	FUiCompositeMode.h
 * @brief	This is the header file for the CompositeMode enumeration.
 *
 * The %CompositeMode enumeration defines the data types for compositing the controls.
 */

#ifndef _FUI_COMPOSITE_MODE_H_
#define _FUI_COMPOSITE_MODE_H_

#ifdef COMPOSITE_MODE_NONE
#undef COMPOSITE_MODE_NONE
#endif

namespace Osp {namespace Ui {

/**
* @enum		CompositeMode
* Defines the mode for compositing the controls.
*
* @since	1.1
*/
enum CompositeMode
{
	/** The mode compositing two UI controls using alpha-blending */
	COMPOSITE_MODE_ALPHA_BLENDING,

	/** The mode compositing two UI controls in the way that the given chroma key color from one control is made transparent */
	COMPOSITE_MODE_CHROMA_KEY,
	
	/** The mode compositing two UI controls in the way that one control overwrites another control */
	COMPOSITE_MODE_OVERWRITE,	

	/** The mode that does not composite the given control */   
	COMPOSITE_MODE_NONE,				
};

};}; // Osp::Ui

#endif // _FUI_COMPOSITE_MODE_H_