/* $Change: 877620 $ */
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
 * @file	FUiCtrlAnimationFrame.h
 * @brief	This is the header file for the %AnimationFrame class.
 *
 * This header file contains the declarations of the %AnimationFrame class and its helper classes.
 */

#ifndef _FUICTRL_ANIMATION_FRAME_H_
#define _FUICTRL_ANIMATION_FRAME_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseColArrayListT.h"
#include "FBaseString.h"
#include "FGrpColor.h"
#include "FGrpPoint.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"

// Forward declarations
namespace Osp { namespace Ui { namespace Controls {

/**
 * @class	AnimationFrame
 * @brief	This class defines the common behavior of an %AnimationFrame control.
 * @since	1.0
 * 
 * The %AnimationFrame class defines the common behavior of an %AnimationFrame control.
 * An animation frame includes an image to be displayed and its duration. 
 * The duration indicates how long the image is displayed when the animation is playing.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_animation.htm">Animation</a>.
 *
 */
class _EXPORT_CONTROLS_ AnimationFrame 
	: public Osp::Base::Object
{
public:

// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	AnimationFrame(void);

	/**
	* Initializes this instance of %AnimationFrame with the specified parameters. @n
	* It creates an instance of %AnimationFrame with the specified image and duration.
	*
	* @since			1.0
	* @param[in]  frame			The bitmap to be displayed
	* @param[in]  duration		The duration in milliseconds for which the bitmap is displayed
	*/
	AnimationFrame(const Osp::Graphics::Bitmap& frame, long duration);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	~AnimationFrame(void);

	/**
	 *	Sets the bitmap to be displayed during animation play.
	 *
	 * @since		1.0
	 * @param[in]	frame		The bitmap to be displayed
	 */
	void SetFrame(const Osp::Graphics::Bitmap& frame);

	/**
	 * Gets the bitmap to be displayed.
	 *
	 * @since	1.0
	 * @return	The bitmap
	*/
	const Osp::Graphics::Bitmap* GetFrame(void) const;

	/**
	* Sets the duration for which the bitmap is displayed.
	 *
	 * @since		1.0
	 * @param[in]	duration		The duration in milliseconds for which the bitmap is displayed
	 */
	void SetDuration(long duration);

	/**
	* Gets the duration for which the bitmap is displayed.
	 *
	 * @since	1.0
	 * @return	The duration value
	 */
	long GetDuration(void) const;
	

private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Bitmap to be displayed.
     * @since         1.0
     */
	Osp::Graphics::Bitmap*	__pFrame;


	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Bitmap will be displayed for the duration in a millisecond.
     * @since         1.0
     */
	long __duration;

private:
	friend class AnimationFrameEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
     * The internal data structure.
	 * @since         2.0
     */	
	class AnimationFrameEx* __pAnimationFrameEx;
};
}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_ANIMATION_FRAME_H_

