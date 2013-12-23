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
 * @file	FUiAnimRotateAnimation.h
 * @brief	This is the header file for the %RotateAnimation class.
 *
 * This header file contains the declaration of the %RotateAnimation class.
 */

#ifndef _FUIANIM_ROTATEANIMATION_H_
#define _FUIANIM_ROTATEANIMATION_H_


#include "FUiAnimFloatAnimation.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	RotateAnimation
 * @brief	This class animates between two angle values.  
 * @since	2.0
 *
 * The %RotateAnimation class animates an object from an angle value (float) to another angle value (float)
 * based on the specified interpolator type. When associated with a Control, the animation is applied on the z axis of the %Control.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 */
class _EXPORT_ANIMATION_ RotateAnimation: 
		public FloatAnimation
{
public:
	/**
	 * This is the copy constructor for the %RotateAnimation class.
	 *
	 * @since		2.0
	 * @param[in]	rotateAnimation		An instance of %RotateAnimation	 
	 */
	RotateAnimation(const RotateAnimation& rotateAnimation);
	
	/**
	 * This is the assignment operator implementation for this class. 
	 *
	 * @since		2.0
	 * @param[in]	rhs		An instance of %RotateAnimation	 
	 */
	RotateAnimation& operator =(const RotateAnimation& rhs);

	/**
	 * Checks whether the specified instance and the current instance of %RotateAnimation have equal animation values.
	 *
	 * @since		2.0
	 * @return		@c true if the animation of the two instances of %RotateAnimation have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %RotateAnimation
	 */
	bool operator ==(const RotateAnimation& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %RotateAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %RotateAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %RotateAnimation
	 */
	bool operator !=(const RotateAnimation& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %RotateAnimation is equal to the value of the specified instance.
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %RotateAnimation
	 * @remarks 	The %RotateAnimation class has a semantic value. This means the Equals() method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks 	The two equal instances should return the same hash value. For better performance, the used hash function must generate a random 
	 *				distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Initializes this %RotateAnimation with the specified parameters.
	 *
	 * @since		2.0	 
	 * @param[in]	startValue			The start value for the rotate animation @n
	 *									If the value is positive, the control is rotated in the clockwise direction and if the value is negative, the control 
	 *									is rotated in the anti-clockwise direction.
	 * @param[in]	endValue			The end value for the rotate animation @n
	 *                                  The value must be @c 0 or @c 360, else ControlAnimator() returns an E_INVALID_ARG exception.
	 * @param[in]	duration			The duration of %Animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator @n 
	 *                                  This is used for the intermediate value calculation of the animation.
	 */
	RotateAnimation(float startValue, float endValue, long duration, AnimationInterpolatorType interpolator);
	
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~RotateAnimation(void);

	/**
	 * Sets the anchor points for the animation.
	 *
 	 * @since	2.0
	 * @param[in]	anchorX			The x value of the anchor @n
	 *								The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @param[in]	anchorY			The y value of the anchor @n
	 *                              The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG 	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @remarks 	The default anchor point value is (0.5, 0.5). The range of an anchor point is @c 0.0 to @c 1.0. @n
	 *              If the anchor point value is (0.5, 0.5), the object is rotated and the center of the object remains fixed. @n
	 *              If the anchor point value is (0.0, 0.0), the object is rotated with the top-left corner of the object remains fixed. @n
	 *              If the anchor point value is (1.0, 1.0), the object is rotated and the right-bottom corner of the object remains fixed.
	 */
	result SetAnchor(float anchorX, float anchorY);

	/**
	 * Gets the anchor point associated with the animation. @n
	 * The default anchor point is (0.5, 0.5).
	 *
	 * @since	2.0	 
	 * @param[out]	anchorX		The x value of the anchor @n
	 *                          The control's animation is performed at this point.
	 * @param[out]	anchorY		The y value of the anchor @n
	 *                          The control's animation is performed at this point.
	 */
	void GetAnchor(float& anchorX, float& anchorY) const;
	
	/**
	 * Gets the type information of this instance.
	 *
     * @since	2.0
	 * @return 	The type information of this instance
	 */
	virtual AnimationType GetType(void) const;

protected:
	
	friend class RotateAnimationEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class RotateAnimationEx* __pRotateAnimationEx;
	
private:
	/**
	 * This is the default constructor for this class.
	 * @since	2.0
	 */
	RotateAnimation(void);
};

}; }; };

#endif	// _FUIANIM_ROTATEANIMATION_H_
