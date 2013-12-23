// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FUiCtrlSliderEnum.h
 * @brief		This is the header file for the SliderStyle enumerations.
 *
 * This header files contains the declarations of the %SliderStyle enumeration.
 * 
 */
#ifndef _FUICTRL_SLIDER_ENUM_H_
#define _FUICTRL_SLIDER_ENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum	SliderStyle
 * Defines the slider styles.
 *
 * @since	2.0
 */
enum SliderStyle {
	SLIDER_STYLE_NONE 			= 0x0000,			/**< The no bubble, no title slider */
	SLIDER_STYLE_BUBBLE			= 0x0001,			/**< The bubble style slider */
	SLIDER_STYLE_TITLE			= 0x0002,			/**< The title style slider */
};

}; }; }; // Osp::Ui::Controls

#endif	//_FUICTRL_SLIDER_ENUM_H_
