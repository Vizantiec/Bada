/*  */
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
 * @file	FUiAnimAnimationBase.h
 * @brief	This is the header file for the %AnimationBase class.
 *
 * This header file contains the declarations of the %AnimationBase class and the enumerators related to it.
 */

#ifndef _FUIANIM_ANIMATION_BASE_H_
#define _FUIANIM_ANIMATION_BASE_H_


#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FUiAnimConfig.h"


namespace Osp { namespace Ui { namespace Animations {

/**
 * @enum	AnimationType
 * Defines the information of the animation type.
 *
 * @since	2.0
 */
enum AnimationType
{
	ANIMATION_TYPE_FLOAT_ANIMATION = 0,		/**< The float animation */
	ANIMATION_TYPE_INTEGER_ANIMATION,		/**< The integer animation */
	ANIMATION_TYPE_DIMENSION_ANIMATION,		/**< The dimension animation */
	ANIMATION_TYPE_RECTANGLE_ANIMATION,		/**< The rectangle animation */
	ANIMATION_TYPE_POINT_ANIMATION,			/**< The point animation */
	ANIMATION_TYPE_ROTATE_ANIMATION,		/**< The rotate animation */
};

/**
 * @enum	AnimationInterpolatorType
 * Defines the interpolator type used in %Animations.
 *
 * @since	2.0
 */
enum AnimationInterpolatorType
{
	ANIMATION_INTERPOLATOR_LINEAR = 0,		/**< The linear interpolator */		
	ANIMATION_INTERPOLATOR_DISCRETE,		/**< The discrete interpolator*/
	ANIMATION_INTERPOLATOR_EASE_IN,			/**< The EaseIn interpolator*/
	ANIMATION_INTERPOLATOR_EASE_OUT,		/**< The EaseOut interpolator*/
	ANIMATION_INTERPOLATOR_EASE_IN_OUT,		/**< The EaseInOut interpolator*/
	ANIMATION_INTERPOLATOR_BEZIER,			/**< The Bezier interpolator @n 
	                                             Sets the control points for this interpolator using SetBezierControlPoints(). */
};

/**
 * @enum	AnimationTargetType
 * Defines the object property for which the animations are to be applied.
 *
 * @since	2.0
 */
enum AnimationTargetType
{
	ANIMATION_TARGET_NONE = -1,		/**< An Invalid %Animation */
	ANIMATION_TARGET_SIZE, 			/**< An %Animation for the size property */
	ANIMATION_TARGET_POSITION,		/**< An %Animation for the position property */
	ANIMATION_TARGET_ALPHA,			/**< An %Animation for Alpha property @n The value range for playing the Alpha animation should be between 0.0 to 1.0. */
	ANIMATION_TARGET_ROTATION,		/**< An %Animation for Rotate property @n The control will be rotated in the xy-plane along the z-axis. */
	ANIMATION_TARGET_MAX			/**< @internal This value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this value. */
};

/**
 * @enum	AnimatorStatus
 * Defines the status of the animations attached to a control.
 *
 * @since	2.0
 */
enum AnimatorStatus
{
	ANIMATOR_STATUS_PLAYING,		/**< The %Animation being played */
	ANIMATOR_STATUS_STOPPED,		/**< The stopped %Animation */
};

/**
 * @class	AnimationBase
 * @brief	This class is the base class for all the %Animation classes. @n  
 *			It is an abstract base class.
 * @since	2.0
 *
 * The %AnimationBase class defines the basic animation properties, such as the interpolator to be used, the duration of the animation in milliseconds, the delay before the animation is started in milliseconds, and the repeat count. 
 */
class _EXPORT_ANIMATION_ AnimationBase:
		public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
     * @since	2.0
	 */
	virtual ~AnimationBase(void);

	/**
	 * Sets the duration of the animation. 
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	milliseconds		The duration of the animation in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is negative.
	 * @exception 	E_INVALID_STATE		This instance has not been properly constructed.
	 */
	result SetDuration(long milliseconds);
	
	/**
	 * Sets the offset value of the animation. @n
	 * Additionally, this method alters the start value and duration for which an animation is played.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	milliseconds		The offset of the animation in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is negative or greater than the duration of the animation.
	 * @exception 	E_INVALID_STATE		This instance has not been properly constructed.
	 * @remarks		If the start value of the animation is 0.0, the end value is 1.0, the duration is 100 ms and the offset value is 20 ms, 
     *         		the actual animation starts at 0th ms and plays for 80 ms with a start value of 0.2. @n
	 *				If @c autoReverseset is set to @c true, the Backward animation plays for 100ms, from 1.0 to 0.0.
	 */
	result SetOffset(long milliseconds);
		
	/**
	 * Sets the delay for the animation. @n
	 * The animation starts after the duration of delay has passed.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	milliseconds		The delay for the animation to start in milliseconds
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is negative.
	 * @exception 	E_INVALID_STATE		This instance has not been properly constructed.
	 * @remarks		This method does not alter the start, end, and duration values of the animation.
	 */
	result SetDelay(long milliseconds);

	/**
	 * Sets the repeat count for the animation. @n
	 * Repeats an animation for the specified number of times.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	count				The number of times the animation has to be repeated
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is negative.
	 * @exception 	E_INVALID_STATE		This instance has not been properly constructed.
	 * @remarks		A delay and offset is applied to an animation only when the animation is played for the first time.
	 */
	result SetRepeatCount(long count);	
	
	/**
	 * Sets the AutoReverse property of the animation. @n
	 * If enabled, the forward and backward animation can also be played.
	 *
     * @since		2.0	 
	 * @param[in]	autoReverse			Set to @c true to enable the AutoReverse property of the animation, @n
	 *									else @c false
	 * @remarks		If @c autoReverseset is set to @c true, the duration of the animation is doubled.
	 *				If the repeat count is more than 1, @n
	 *				@c autoReverse is applied to each iteration.
	 * 				Note that if @c autoReverse is set to @c true, one forward animation play and one backward animation play is one
	 *				iteration.
     */
	void 	SetAutoReverseEnabled(bool autoReverse);
	
	/**
	 * Sets the scale ratio of the animation. @n
	 * This method multiplies the duration, offset, and delay using the scale ratio. 
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	scaleRatio			The scale ratio property of the animation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The value of the specified parameter is negative.
	 * @exception 	E_INVALID_STATE		This instance has not been properly constructed.
	 *
	 */
	result SetScaleRatio(float scaleRatio);

	/**
	 * Sets the hold end value of the animation. @n
	 * This method retains the end values of an animation or goes to the start value of an animation.
	 *
     * @since		2.0
	 * @param[in]	holdEnd		Set to @c true to hold the end values of the animation, @n
	 *							else @c false
	 *
	 */
	void SetHoldEndEnabled(bool holdEnd);
		
	/**
	 * Gets the duration of the animation in milliseconds.
	 *
     * @since		2.0
	 * @return 		The duration value of the animation @n 
	 */
	long GetDuration(void) const;
	
	/**
	 * Gets the offset value in milliseconds after the animation starts.
	 *
     * @since		2.0	 
	 * @return 		The offset value of the animation in milliseconds @n
	 *				The default value of the offset is @c 0.
	 */
	long GetOffset(void) const;
	
	/**
	 * Gets the delay value in milliseconds before the animation starts.
	 *
     * @since		2.0	 
	 * @return		The delay value in milliseconds @n
	 *				The default value of the delay is @c 0.
	 */
	long GetDelay(void) const;

	/**
	 * Gets the repeat count value of the animation.
	 *
     * @since		2.0	 
	 * @return		The repeat count value of the animation @n
	 *				The default value of the repeat count is @c 1.
	 */
	long GetRepeatCount(void) const;

	/**
	 * Checks whether the auto reverse is enabled.
	 *
     * @since		2.0	
	 * @return		@c true if the auto reverse is enabled, @n
	 *				else @c false @n
	 *				The default auto reverse value is @c false.
	 */
	bool IsAutoReverseEnabled(void) const;
	
	/**
	 * Gets the scale ratio value of the animation.
	 *
     * @since		2.0	
	 * @return		The scale ratio value of the animation @n
	 *				The default value of scale ratio is @c 1.0f
	 */
	float GetScaleRatio(void) const;

	/**
	 * Checks whether the hold end value of the animation is enabled.
	 *
     * @since		2.0	
	 * @return		@c true if the hold end value is enabled, @n
	 *				else @c false @n
	 *				The default hold end value is @c true.
	 */
	bool IsHoldEndEnabled(void) const;

	/**
	 * Sets the interpolator type.
	 *
     * @since		2.0
	 * @param[in]	interpolatorType	The interpolator type used for the animation
	 */
	void SetInterpolatorType(AnimationInterpolatorType interpolatorType);
	
	/**
	 * Gets the interpolator type.
	 *
     * @since		2.0
	 * @return 		The interpolator type of an animation @n
	 *				The default interpolator type is @c ANIMATION_INTERPOLATOR_LINEAR.
	 */
	AnimationInterpolatorType GetInterpolatorType(void) const;

	/**
	 * Sets the control points for Bezier interpolator. @n
	 * This method is supported only if the interpolator is ANIMATION_INTERPOLATOR_BEZIER.
	 *
     * @since		2.0
	 * @return		An error code
	 * @param[in]	time1				The control point 1 - Time @n
	 *									The time should be in the range @c 0.0 to @c 1.0. The time value is scaled relative to the duration of the animation.
	 * @param[in]	value1				The control point 1 - Value @n
	 *									The value should be in the range @c 0.0 to @c 1.0. The value is scaled relative to the start and end value of the animation.
	 * @param[in]	time2				The control point 2 - Time @n
	 *									The time should be in the range @c 0.0 to @c 1.0. The time value is scaled relative to the duration of the animation.
	 * @param[in]	value2				The control point 2 - Value @n
	 *									The time should be in the range @c 0.0 to @c 1.0. The value is scaled relative to the start and end value of the animation.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed as yet. 
	 * @exception 	E_INVALID_OPERATION This method is not supported for the interpolator set of this instance.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @remarks		@c time1 can be greater than @c time2 and vice versa.
	 */
	result SetBezierControlPoints(float time1, float value1, float time2, float value2);
	
	/**
	 * Gets the control points of the Bezier interpolator. @n
	 * This method is supported only if the interpolator is ANIMATION_INTERPOLATOR_BEZIER. @c 0 is returned for the other interpolators.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[out]	time1				The control point 1 - Time @n 
	 *									The default value of control point 1 is @c 0.0.
	 * @param[out]	value1				The control point 1 - Value @n 
	 *									The default value of control point 1 is @c 0.0.
	 * @param[out]	time2				The control point 2 - Time @n 
	 *									The default value of control point 2 is @c 0.0.
	 * @param[out]	value2				The control point 2 - Value @n 
	 *									The default value of control point 2 is @c 0.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed as yet. 
	 * @exception 	E_INVALID_OPERATION This method is not supported for the interpolator set of this instance.
	 * 
	 */
	result GetBezierControlPoints(float& time1, float& value1, float& time2, float& value2) const;

	/**
	 * Gets the count of key frames added to this animation.
	 *
     * @since		2.0
	 * @return		The key frame count	
	 */
	int GetKeyFrameCount(void) const;

	/**
	 * Sets the name of the animation.
	 *
     * @since		2.0	 
	 * @param[in]	name	The name of the animation
	 */		
	void SetName(const Osp::Base::String& name);
	
	/**
	 * Gets the name of the animation.
	 *
     * @since		2.0	 
	 * @return		The name of the animation @n	
	 *				The default value of the name is an empty string.
	 */	
	Osp::Base::String GetName(void) const;

	/**
	 * Gets the type information of this instance.
	 *
     * @since		2.0	 
	 * @return		The type information of this instance
	 */
	virtual AnimationType GetType(void) const = 0;
	
protected:
	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * Default constructor for AnimationBase class.
	 *
     * @since	2.0
	 */
	AnimationBase(void);

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class. @n
	 *
     * @since	2.0	 	 
     * @remarks		The animation name of the copied %AnimationBase object will be same as the %AnimationBase object passed.
	 * 				User should change the name using the SetName() method of this class in order to make animation name unique.
	 * @param[in]	animationBase		An instance of AnimationBase
	 */
	AnimationBase(const AnimationBase& animationBase);

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * Constructor for AnimationBase.
	 *
     * @since	2.0
	 * @param[in]	duration			Duration of animation in milliseconds
	 * @param[in]	interpolator		Type of Interpolation used for animation's intermediate value calculation
	 */
	AnimationBase(long duration, AnimationInterpolatorType interpolator);

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator.
	 *
	 * @since	2.0
	 * @param[in]	value	The source from which this instance is assigned
	 * @remarks		The animation name of the returned %AnimationBase object will be same as the %AnimationBase object passed.
	 * 				User should change the name using SetName() method of this class in order to make animation name unique.
	 */
	AnimationBase& operator=(const AnimationBase& value);

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void AnimationBase_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */	
	virtual void AnimationBase_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void AnimationBase_Reserved3(void) { }

	friend class AnimationBaseEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class AnimationBaseEx* __pAnimationBaseEx;		
};

}; }; };

#endif	// _FUIANIM_ANIMATION_BASE_H_
