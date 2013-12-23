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
 * @file		FUiAnimIntegerAnimation.h
 * @brief		This is the header file for the %IntegerAnimation class.
 *
 * This header file contains the declaration of the %IntegerAnimation class.
 */

#ifndef _FUIANIM_INTEGERANIMATION_H_
#define _FUIANIM_INTEGERANIMATION_H_


#include "FUiAnimAnimationBase.h"
#include "FBaseInteger.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	IntegerAnimation
 * @brief	This class animates an object from an integer value to another integer value.
 * @since	2.0
 *
 * The %IntegerAnimation class animates an object from an integer value to another integer value based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 */
class _EXPORT_ANIMATION_ IntegerAnimation: 
		public AnimationBase
{
public:
	/**
	 * This is the copy constructor for the %IntegerAnimation class.
	 *
	 * @since	2.0
	 * @param[in]	integerAnimation	An instance of %IntegerAnimation
	 */
	IntegerAnimation(const IntegerAnimation& integerAnimation);
	
	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since	2.0
	 * @param[in]	rhs		An instance of %IntegerAnimation 
	 */
	IntegerAnimation& operator =(const IntegerAnimation& rhs);

	/**
	 * Checks whether the specified and current instance of %IntegerAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %IntegerAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %IntegerAnimation
	 */
	bool operator ==(const IntegerAnimation& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %IntegerAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %IntegerAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %IntegerAnimation
	 */
	bool operator !=(const IntegerAnimation& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %IntegerAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
					else @c false
	 * @param[in]	obj		An instance of %IntegerAnimation
	 * @remarks 	The %IntegerAnimation class has a semantic value. @n 
	 *				This means the Equals() method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks 	Two equal instances should return the same hash value. For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;
	
	/**
	 * Initializes this instance of %IntegerAnimation with the specified parameters.
	 *
	 * @since	2.0
	 * @param[in]	startValue			The start value for Integer animation
	 * @param[in]	endValue			The end value for Integer animation
	 * @param[in]	duration			The duration of %Animation in milliseconds
	 * @param[in]	interpolator		The type of Interpolation @n
	 *									This is used for the intermediate value calculation of the animation.
	 */
	IntegerAnimation(int startValue,int endValue, long duration, AnimationInterpolatorType interpolator);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IntegerAnimation(void);

	/**
	 * Gets the animated value for the current time. 
	 *
	 * @since	2.0
	 * @return 		An error code	
	 * @param[in] 	currentTime		The current time value of the animation play @n
	 *								The value should be between @c 0 and the duration of the animation.
	 * @param[out] 	animatedValue	The animated value for the current time @n
	 *                              The value is passed as the input parameter.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG 	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE This instance has not been properly constructed.  	
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, int& animatedValue);
	
	/**
	 * Adds a key frame to the animation.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[in]	time				The time stamp
	 * @param[in]	value				The value at the specified time
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 
	 * @exception   E_OUT_OF_MEMORY  	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 * @remarks		If @c time is greater than the duration, it becomes the new duration and @c value becomes the new @c endValue.
	 * 				Also the old duration and @c endValue are added as a new keyframe entry in the list.
	 * @remarks		If a key-value pair with the current key already exists, the old value is overwritten with the new one.
	 * @remarks		An exception is returned if @c time is equal to @c 0 or the duration of the animation.
	 */
	result AddKeyFrame(long time, int value);

	/**
	 * Returns the keyframe at a particular index in this animation.
	 *
	 * @since	2.0
	 * @return 		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                                  The value is sorted in an increasing order of time.
	 * @param[out]	time				The time stamp at the specified index
	 * @param[out]	value				The value at the specified index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range. 
	 * @exception 	E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned are present at the index of the sorted map list (sorted with respect to key).
	 * 				For example, if the user adds keyframe in the order (10,value1), (20,value2), (5,value3), and then
	 * 				GetKeyFrameAt(0,time,value) is called, the pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, int& value) const;
	
	/**
	 * Removes the specified keyframe object from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	time				The keyFrame to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
	 * @exception	E_INVALID_ARG		The specified time value is invalid.
	 * @exception 	E_OBJ_NOT_FOUND		The specified @c time is not found in the KeyFrame List.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveKeyFrame(long time);

	/**
	 * Removes the keyframe present at the specified index from the keyframe list.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	                                    The value is sorted in an increasing order of time.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 
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
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
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
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 	 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetStartValue(int startValue);

	/**
	 * Sets the end value of the animation.
	 *
	 * @since	2.0
	 * @return 		An error code
	 * @param[in]	endValue			The end value of the animation to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 	 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(int endValue);

	/**
	 * Gets the start value of the animation.
	 *
     * @since	2.0	 
	 * @return	The start value
	 */
	int GetStartValue(void) const;

	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 * @return		The end value
	 */
	int GetEndValue(void) const;

	/**
	 * Gets the type information of this instance.
	 *
     * @since	2.0	
	 * @return 	The type information of this instance
	 */
	virtual AnimationType GetType(void) const;

protected:
	
	friend class IntegerAnimationEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class IntegerAnimationEx* __pIntegerAnimationEx;

private:
	/**
	 * This is the default constructor for this class.
	 * @since	2.0
	 */
	IntegerAnimation(void);
};

}; }; };

#endif	// _FUIANIM_INTEGERANIMATION_H_
