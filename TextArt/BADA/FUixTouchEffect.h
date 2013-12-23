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
* @file			FUixTouchEffect.h
* @brief		This is the header file for the %TouchEffect class.
*
* This header file contains the declarations of the %TouchEffect class.
*/

#ifndef _FUIX_TOUCHEFFECT_H_
#define _FUIX_TOUCHEFFECT_H_

// include
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FUixTouchEffectCommon.h"

namespace Osp{ namespace Uix{ class ITouchEffectPi; } }

namespace Osp{ namespace Uix{

/**
* @class	TouchEffect
* @brief	This class is used to control the device's %TouchEffect feature.
* @since	1.0
*
* The %TouchEffect class is used to control the device's %TouchEffect feature.
* It also provides a feature to add the sound and vibration effects.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/touch_effects.htm">Touch Effects</a>.
*
* The following example demonstrates how to use the %TouchEffect class.

* @code
*
* #include <FBase.h>
* #include <FUix.h>
*
* using namespace Osp::Base;
* using namespace Osp::Uix;
*
* void UixExample::TouchEffectPlay(void)
* {
* 		result r = E_SUCCESS;
*
* 		Osp::Uix::TouchEffect *pTouchEffect = new Osp::Uix::TouchEffect();
*
* 		r = pTouchEffect->Construct();
* 		if( IsFailed(r))
* 		{
* 			goto CATCH;
* 		}
*
* 		r = pTouchEffect->Play(TOUCH_EFFECT_SOUND);
* 		if( IsFailed(r))
* 		{
* 			goto CATCH;
* 		}
*
* 		r = pTouchEffect->Play(TOUCH_EFFECT_VIBRATION);
* 		if( IsFailed(r))
* 		{
* 			goto CATCH;
* 		}
*
* 		r = pTouchEffect->Play(TOUCH_EFFECT_SOUND_VIBRATION);
* 		if( IsFailed(r))
* 		{
* 			goto CATCH;
* 		}
*
* CATCH:
* 		delete pTouchEffect;
* 		pTouchEffect = null;
* }
* @endcode
* @n
*/
class _EXPORT_UIX_ TouchEffect:
	public Osp::Base::Object
{

public:

	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	TouchEffect(void);
	
	/**
	* This is the destructor for this class. @n
	*
	* @since		1.0
	*/
	virtual ~TouchEffect(void);

	/**
	* Initializes this instance of %TouchEffect. @n
	* Every application must call Construct() before calling any other method of %TouchEffect.
	*
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS				   	    The method is successful.
	* @exception	E_OUT_OF_MEMORY					The memory is insufficient.
	* @exception	E_INVALID_STATE					This instance has already been constructed.
	*/
	result Construct(void);

	/**
	* Plays a predefined effect.
	*
	* @since		1.0
	* @return		An error code
	*
	* @param[in]	type				The type of the effect to play, like sound or vibration
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_INVALID_ARG   	The specified @c type is invalid.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @see		    Osp::Uix::TouchEffectType
	*/
	result Play(TouchEffectType type);

private:
	friend class TouchEffectEx;
	class TouchEffectEx* __pTouchEffectEx;
};

} } //Osp::Uix

#endif
