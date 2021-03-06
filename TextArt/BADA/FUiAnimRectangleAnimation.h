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
 * @file		FUiAnimRectangleAnimation.h
 * @brief		This is the header file for the %RectangleAnimation class.
 *
 * This header file contains the declaration of the %RectangleAnimation class.
 */

#ifndef _FUIANIM_RECTANGLEANIMATION_H_
#define _FUIANIM_RECTANGLEANIMATION_H_


#include "FUiAnimAnimationBase.h"
#include "FGrpRectangle.h"
#include "FGrpPoint.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	RectangleAnimation
 * @brief	This class animates the %Rectangle object.  
 * @since	2.0
 *
 * The %RectangleAnimation class animates an object from an Rectangle value to another %Rectangle value based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 */
class _EXPORT_ANIMATION_ RectangleAnimation: 
		public AnimationBase
{
public:
	/**
	 * This is the copy constructor for the %RectangleAnimation class.
	 *
	 * @since		2.0
	 * @param[in]	rectangleAnimation		An instance of %RectangleAnimation	 
	 */
	RectangleAnimation(const RectangleAnimation& rectangleAnimation);

	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since		2.0
	 * @param[in]	rhs		An instance of %RectangleAnimation	 
	 */
	RectangleAnimation& operator =(const RectangleAnimation& rhs);

	/**
	 * Checks whether the specified instance and the current instance of %RectangleAnimation have equal animation values.
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %RectangleAnimation have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %RectangleAnimation
	 */
	bool operator ==(const RectangleAnimation& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %RectangleAnimation have different animation values.
	 * @since		2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %RectangleAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs			An instance of %RectangleAnimation
	 */
	bool operator !=(const RectangleAnimation& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %RectangleAnimation is equal to the value of the specified instance.
	 * @since		2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj			An instance of %RectangleAnimation
	 * @remarks 	The %RectangleAnimation class has a semantic value. This means the %Equals() method checks whether the two instances have the same 
	 *				animation.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 * Gets the hash value of the current instance.
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks 	The two equal instances should return the same hash value. For better performance, the used hash function must generate a random 
	 *				distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Initializes this %RectangleAnimation with the specified parameters.
	 *
	 * @since		2.0	 
	 * @param[in]	startValue			The start value for rectangle animation
	 * @param[in]	endValue			The end value for rectangle animation
	 * @param[in]	duration			The duration of %Animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator @n
	 *                                  This is used for the intermediate value calculation of the animation.
	 */
	RectangleAnimation(const Osp::Graphics::Rectangle& startValue, const Osp::Graphics::Rectangle& endValue, long duration, AnimationInterpolatorType interpolator);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~RectangleAnimation(void);

	/**
	 * Sets the anchor points for the animation.
	 *
 	 * @since		2.0
	 * @param[in] 	anchorX				The X value of the anchor @n
	 *                              	The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @param[in] 	anchorY				The Y value of the anchor @n
	 *                              	The control's animation is performed at this point. The range of the anchor point is @c 0.0 to @c 1.0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks 	The default anchor point value is (0.0, 0.0). The range of an anchor point is @c 0.0 to @c 1.0. @n
	 *              When the anchor point value is (0.0, 0.0), the object is scaled and the top-left corner of the object remains fixed. @n
	 *              For all the other anchor point values, the position property is changed. @n
	 *              If the anchor point value is (0.5, 0.5), the object is scaled with respect to the center. @n
	 *              If the anchor point value is (1.0, 1.0), the object is scaled and the bottom-right corner of the object remains fixed.
	 */
	result SetAnchor(float anchorX, float anchorY);

	/**
	 * Gets the anchor point associated with the animation. @n
	 * The default anchor point is (0.0, 0.0). 
	 *
	 * @since	2.0	 
	 * @param[out] 	anchorX		The X value of the anchor @n
	 *                          The control's animation is performed at this point.
	 * @param[out] 	anchorY		The Y value of the anchor @n
	 *                          The control's animation is performed at this point.
	 */
	void GetAnchor(float& anchorX, float& anchorY) const;
	
	/**
	 * Gets the animated value for the current time. 
	 *
	 * @since	2.0	 
	 * @return 		An error code	
	 * @param[in] 	currentTime		The current time value of the animation play @n
	 *								The value should be between @c 0 and the duration of the animation.
	 * @param[out] 	animatedValue	The animated value for the current time passed as the input parameter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG 	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, Osp::Graphics::Rectangle& animatedValue);

	/**
	 * Adds a key frame to the animation.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[in]	time				The time stamp
	 * @param[in]	value				The value at the specified time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_OUT_OF_MEMORY  	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 * @remarks		If @c time is greater than the duration, it becomes the new duration and @c value becomes the new end value. @n
	 * 				Also, the old duration and end value are added as a new keyframe entry in the list.
	 * @remarks		If a key-value pair with the current key already exists, the old value is overwritten with the new one.
	 * @remarks		An exception is returned if time is equal to @c 0 or the duration of the animation.
	 */
	result AddKeyFrame(long time, const Osp::Graphics::Rectangle& value);

	/**
	 * Gets the keyframe at a specified index in this animation.
	 *
	 * @since	2.0
	 * @return 		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  This is sorted in an increasing order of time.
	 * @param[out]	time				The time stamp at the specified index
	 * @param[out]	value				The value at the specified index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range. 
	 * @exception 	E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned is the one present at the index of the sorted map list (sorted with respect to the key).
	 * 				For example, if the user adds keyframe in the order (10,value1), (20,value2), (5,value3), and GetKeyFrameAt(0,time,value) is called, 
	 *				the pair returned is (5, value3).
	 */
	result GetKeyFrameAt(int index, long& time, Osp::Graphics::Rectangle& value) const;
	
	/**
	 * Removes the passed keyframe object from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	time				The keyframe to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		The specified time value is invalid.
	 * @exception 	E_OBJ_NOT_FOUND		The time passed is not found in the KeyFrame list.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveKeyFrame(long time);

	/**
	 * Removes the keyframe present at the specified index from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  This is sorted in an increasing order of time.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range. 
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 */
	result RemoveKeyFrameAt(int index);

	/**
	 * Removes all the keyframes from an animation.
	 *
     * @since	2.0
	 * @return		An error code	
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 */
	result RemoveAllKeyFrames(void);
	
	/**
	 * Sets the start value of the animation.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	startValue			The start value of the animation to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance is in an invalid state. 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetStartValue(const Osp::Graphics::Rectangle& startValue);

	/**
	 * Sets the end value of the animation.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	endValue			The end value of the animation to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance is in an invalid state.	 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(const Osp::Graphics::Rectangle& endValue);

	/**
	 * Gets the start value of the animation.
	 *
     * @since	2.0	 
	 * @return	The start value
	 */
	Osp::Graphics::Rectangle GetStartValue(void) const;

	/**
	 * Gets the end value of the animation.
	 *
     * @since		2.0	 
	 * @return		The end value
	 */
	Osp::Graphics::Rectangle GetEndValue(void) const;

	/**
	 * Gets the type information of this instance.
	 *
     * @since	2.0	
	 * @return 	The type information of this instance
	 */	
	virtual AnimationType GetType(void) const;
	
protected:	

	friend class RectangleAnimationEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class RectangleAnimationEx* __pRectangleAnimationEx;

private:
	/**
	 * This is the default constructor for this class.
	 * @since	2.0
	 */
	RectangleAnimation(void);
};

}; }; };

#endif	// _FANIM_RECTANGLEANIMATION_H_
