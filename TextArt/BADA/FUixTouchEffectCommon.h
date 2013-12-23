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
* @file			FUixTouchEffectCommon.h 
* @brief		This is the header file for the type declarations of the CustomEffect class.
*
* This header file contains the type declarations of the CustomEffect class.
*/

#ifndef _FUIX_TOUCHEFFECT_COMMON_H_
#define _FUIX_TOUCHEFFECT_COMMON_H_

#include "FUixConfig.h"

namespace Osp{ namespace Uix{ 

	/**
	* @enum  TouchEffectType
	* Defines the enumeration for the device's effect types.
	*
	* @since	1.0
	*/
 	enum TouchEffectType
 	{
 		TOUCH_EFFECT_SOUND = 0,           /**< The Sound Effect type constant */
 		TOUCH_EFFECT_VIBRATION = 1,       /**< The Vibration Effect type constant */
 		TOUCH_EFFECT_SOUND_VIBRATION = 2  /**< The Sound and Vibration Effect type constant */
 	};

} } // Osp::Uix

#endif
