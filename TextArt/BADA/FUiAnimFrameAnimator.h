/* $Change:  $ */
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
 * @file		FUiAnimFrameAnimator.h 
 * @brief		This is the header file for the %FrameAnimator class.
 *
 * This header file contains the declarations of the %FrameAnimator class.
 */
 
#ifndef _FUIANIM_FRAME_ANIMATOR_H_
#define _FUIANIM_FRAME_ANIMATOR_H_


#include "FUiAnimIFrameAnimatorEventListener.h"


namespace Osp { namespace Ui {  namespace Controls { class Form; } } }

namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	FrameAnimator
 * @brief	This class defines the animation methods for Frame.
 * @since	2.0
 *
 * The %FrameAnimator class is used to control the animations operated on a Frame.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 *
 */
class _EXPORT_ANIMATION_ FrameAnimator :
	public Osp::Base::Object
{
public:
	/** 
	 * This is the destructor for this class.
	 *	 
     * @since	2.0
	 */	
	virtual ~FrameAnimator(void);

	/**
	 * Adds an %IFrameAnimatorEventListener instance to the current instance of the frame. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result AddFrameAnimatorEventListener(const IFrameAnimatorEventListener& listener);

	/**
	 * Removes an %IFrameAnimatorEventListener instance from the current instance of the frame. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION		The animation support is unavailable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveFrameAnimatorEventListener(const IFrameAnimatorEventListener& listener);

	/**
	 * Gets the animation status of the frame animator.
	 *
     * @since	2.0
	 * @return	The animation state of the frame animator
	 */
	AnimatorStatus GetStatus(void) const;

	/**
	 * Sets the specified form as the current form of the frame with an animation.	 
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	form			        The form object to be set
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
 	 * @exception	E_SYSTEM				A system error has occurred.
	 *
     * @remarks		Draw() and Show() need not be called to show the form. @n
	 *				To select the animation to be used during SetCurrentForm(), use SetFormTransitionAnimation() before calling SetCurrentForm().
	 */
	result SetCurrentForm(const Osp::Ui::Controls::Form& form);

	/**
	 * Sets the type of the form transition animation.
	 *
     * @since	2.0
	 * @param[in]	animation			The type of form transition animation to be set
 	 * @param[in]	duration			The duration of Animation in milliseconds @n 
	 *									The maximum duration is one second.
	 * @param[in]	interpolator		The type of interpolator used for the intermediate value calculation of the animation
	 */
	void SetFormTransitionAnimation(FrameAnimatorFormTransitionAnimation animation, long duration, AnimationInterpolatorType interpolator);

	/**
	 * Gets the type of the form transition animation.
	 *
     * @since	2.0
	 * @param[out]	animation			The type of form transition animation used
 	 * @param[out]	duration			The duration of Animation in milliseconds
	 * @param[out]	interpolator		The type of interpolator used for the intermediate value calculation of the animation
	 */
	void GetFormTransitionAnimation(FrameAnimatorFormTransitionAnimation& animation, long& duration, AnimationInterpolatorType& interpolator) const;

	/**
	 * Sets the control points for the Bezier interpolator. @n
	 * This method is supported only if the interpolator is ANIMATION_INTERPOLATOR_BEZIER.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[in]	time1				The control point 1 - Time @n
	 *									The time should be within the range @c 0.0 to @c 1.0.
	 * @param[in]	value1				The control point 1 - Value @n
	 *									The value should be within the range @c 0.0 to @c 1.0.
	 * @param[in]	time2				The control point 2 - Time @n
	 *									The time should be within the range @c 0.0 to @c 1.0.
	 * @param[in]	value2				The control point 2 - Value @n
	 *									The value should be within the range @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed properly.
	 * @exception 	E_INVALID_OPERATION This method is not supported for the interpolator set for this instance.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result SetFormTransitionBezierControlPoints(float time1, float value1, float time2, float value2);

	/**
	 * Gets the control points of the Bezier interpolator. @n
	 * This method is supported only if the interpolator is ANIMATION_INTERPOLATOR_BEZIER. @n 
	 * Therefore, @c 0 will be returned for other interpolators.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[out]	time1				The control point 1 - Time
	 * @param[out]	value1				The control point 1 - Value
	 * @param[out]	time2				The control point 2 - Time
	 * @param[out]	value2				The control point 2 - Value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed properly.
	 * @exception 	E_INVALID_OPERATION This method is not supported for the interpolator set for this instance.
	 */
	result GetFormTransitionBezierControlPoints(float& time1, float& value1, float& time2, float& value2) const;

	/**
	 * Stops all the animations that are being played and jumps to the final frame of the animation.
	 *
     * @since	2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result StopAllAnimations(void);

protected:	
	
	friend class FrameAnimatorEx;

	/** 
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class FrameAnimatorEx* __pFrameAnimatorEx;

private:	
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 * 			 responsible for any behavioral correctness, consistency, and
	 * 			 security-related issues that might arise after using this method.
	 *
	 * This is the constructor for %FrameAnimator class.
     * @since	2.0	 
	 */
	FrameAnimator(void);

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 * 			 responsible for any behavioral correctness, consistency, and
	 * 			 security-related issues that might arise after using this method.
	 *
	 * Initializes this %FrameAnimator class.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	source				An instance of the Frame class
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance is not in valid state.
	 * @exception   E_OUT_OF_MEMORY  	Insufficient memory.
	 * @exception	E_SYSTEM			System error occurred.
	 */
	result Construct(const Osp::Ui::Controls::Frame& source);
	
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 * 			 responsible for any behavioral correctness, consistency, and
	 * 			 security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class. @n
     * @since	2.0
	 */
	FrameAnimator(const FrameAnimator& frameAnimator);
	
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 * 			 responsible for any behavioral correctness, consistency, and
	 * 			 security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator implementation for this class. @n
     * @since	2.0	 
	 *
	 */
	FrameAnimator& operator =(const FrameAnimator& rhs);
	
	friend class Osp::Ui::Controls::Frame;
};
	
}; }; };

#endif//_FUIANIM_FRAME_ANIMATOR_H_
