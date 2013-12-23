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
 * @file		FUiAnimDimensionAnimation.h
 * @brief		This is the header file for the %DimensionAnimation class.
 *
 * This header file contains the declarations of the %DimensionAnimation class.
 */

#ifndef _FUIANIM_DIMENSION_ANIMATION_H_
#define _FUIANIM_DIMENSION_ANIMATION_H_

#include "FUiAnimAnimationBase.h"
#include "FGrpDimension.h"
#include "FGrpPoint.h"

namespace Osp { namespace Ui { namespace Animations {

/**
 * @class	DimensionAnimation
 * @brief	This class animates the Osp::Graphics::Dimension object.  
 * @since	2.0
 *
 * The %DimensionAnimation class animates an object from an Osp::Graphics::Dimension value to another Osp::Graphics::Dimension value
 * based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 */
class _EXPORT_ANIMATION_ DimensionAnimation: 
		public AnimationBase
{
public:
	/**
	 * This is the copy constructor for the %DimensionAnimation class.
	 *
	 * @since	2.0
	 * @param[in]	dimensionAnimation	An instance of %DimensionAnimation
	 */
	DimensionAnimation(const DimensionAnimation& dimensionAnimation);
	
	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since	2.0
	 * @param[in]	rhs		An instance of %DimensionAnimation	 
	 */
	DimensionAnimation& operator =(const DimensionAnimation& rhs);

	/**
	 * Checks whether the specified instance and current instance of %DimensionAnimation have equal animation values.
	 *
	 * @since	2.0
	 * @return		@c true if the animation of the two instances of %DimensionAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %DimensionAnimation
	 */
	bool operator ==(const DimensionAnimation& rhs) const;
		
	/**
	 * Checks whether the specified instance and current instance of %DimensionAnimation have different animation values.
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %DimensionAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %DimensionAnimation
	 */
	bool operator !=(const DimensionAnimation& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %DimensionAnimation equals the value of the specified instance.
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
					else @c false
	 * @param[in]	obj		An instance of %DimensionAnimation
	 * @remarks 	The %DimensionAnimation class has a semantic value that means the Equals() method checks whether the two instances have the same animation.
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
	 *Initializes this instance of %DimensionAnimation with the specified parameters.
	 *
	 * @since		2.0
	 * @param[in]	startValue			The start value for the dimension animation
	 * @param[in]	endValue			The end value for the dimension animation
	 * @param[in]	duration			The duration of %Animation in milliseconds
	 * @param[in]	interpolator		The type of interpolator used for the animation's intermediate value calculation
	 */
	DimensionAnimation(const Osp::Graphics::Dimension& startValue,const Osp::Graphics::Dimension& endValue, long duration, AnimationInterpolatorType interpolator);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~DimensionAnimation(void);

	/**
	 * Sets the anchor points for the animation.
	 *
	 * @since	2.0
 	 * @return 		An error code
	 * @param[in] 	anchorX				The X value of the anchor at which the control's animation is performed
	 * @param[in] 	anchorY				The Y value of the anchor at which the control's animation is performed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance is not in a valid state.
	 * @remarks 	A default anchor point value is (0.0, 0.0). The range of an anchor point is @c 0.0 to @c 1.0. @n
	 *              When the anchor point value is (0.0, 0.0), the object is scaled and the top-left corner of the object remains fixed. @n
	 *              For all the other anchor point values, the position property is changed.
	 *              If the anchor point value is (0.5, 0.5), the object is scaled with respect to the center.
	 *              If the anchor point value is (1.0, 1.0), the object is scaled and the bottom-right corner of the object remains fixed.
	 */
	result SetAnchor(float anchorX, float anchorY);

	/**
	 * Gets the anchor point associated with the animation. @n
	 * The default anchor point is (0.0, 0.0).
	 *
	 * @since		2.0
	 * @param[out] 	anchorX		The X value of the anchor at which the control's animation is performed
	 * @param[out] 	anchorY		The Y value of the anchor at which the control's animation is performed
	 */
	void GetAnchor(float& anchorX, float& anchorY) const;

	/**
	 * Returns the animated value for the current time. 
	 *
	 * @since		2.0
	 * @return 		An error code	
	 * @param[in] 	currentTime			The current time value of the animation play @n
	 *									The value should be between @c 0 and the duration of the animation.
	 * @param[out] 	animatedValue		The animated value for the current time passed as the input parameter
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance is not in valid state. 	
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, Osp::Graphics::Dimension& animatedValue);

	/**
	 * Adds a keyframe to the animation.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[in]	time				The time stamp
	 * @param[in]	value				The value at the specified time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 * @remarks		If @c time is greater than the duration, it will become the new duration and @c value becomes the new endValue. @n
	 * 				Also, the old duration and endValue will be added as a new key frame entry in the list. @n
	 * 				If a key-value pair with the current key already exists, the old value will be overwritten with the new one. @n
	 * 				An exception will be returned if time is equal to @c 0 or the duration of the animation.
	 */
	result AddKeyFrame(long time, const Osp::Graphics::Dimension& value);

	/**
	 * Gets the keyframe at a particular index in this animation.
	 *
     * @since	2.0	 
	 * @return 		An error code
	 * @param[in]	index				The index value in the keyframe list that is sorted in an increasing order of time
	 * @param[out]	time				The time stamp at the specified index
	 * @param[out]	value				The value at the specified index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state. 
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range. 
	 * @exception 	E_SYSTEM			A system error has occurred.
	 * @remarks		The time and value returned is the one present at the index of the sorted map list(sorted with respect to key). @n
	 * 				For example, if the user adds key-frame in the order (10,value1),(20,value2),(5,value3) and GetKeyFrameAt(0,time,value) is called, the 
	 *				pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, Osp::Graphics::Dimension& value) const;

	/**
	 * Removes the passed keyframe object from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	time				The keyFrame to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_ARG		The keyframe time value is invalid.
	 * @exception 	E_OBJ_NOT_FOUND		The keyframe time value is not found in the keyframe List.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveKeyFrame(long time);

	/**
	 * Removes the keyframe present at the specified index from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                              	The value is sorted in an increasing order of time.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception 	E_OUT_OF_RANGE		The specified @c index parameter is out of range. 
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 */
	result RemoveKeyFrameAt(int index);

	/**
	 * Removes all the keyframes from the animation.
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
	result SetStartValue(const Osp::Graphics::Dimension& startValue);
	
	/**
	 * Sets the end value of the animation.
	 *
	 * @since	2.0
	 * @return 		An error code
	 * @param[in]	endValue			The end value of the animation to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance is in an invalid state. 		 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(const Osp::Graphics::Dimension& endValue);

	/**
	 * Gets the start value of the animation.
	 *
     * @since	2.0	 
	 * @return	The start value
	 */
	Osp::Graphics::Dimension GetStartValue(void) const;

	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 * @return	The end value
	 */
	Osp::Graphics::Dimension GetEndValue(void) const;

	/**
	 * Gets the animation type information of this instance.
	 *
     * @since	2.0	
	 * @return 	The animation type information of this instance
	 */
	virtual AnimationType GetType(void) const;

protected:
	
	friend class DimensionAnimationEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class DimensionAnimationEx* __pDimensionAnimationEx;
	
private:
	/**
	 * This is the default constructor for this class.
	 * @since	2.0
	 */
	DimensionAnimation(void);
};

}; }; };

#endif	// _FUIANIM_DIMENSION_ANIMATION_H_
