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
 * @file		FUiAnimPointAnimation.h
 * @brief		This is the header file of the %PointAnimation class.
 *
 * This header file contains the declarations of the %PointAnimation class.
 */

#ifndef _FUIANIM_POINTANIMATION_H_
#define _FUIANIM_POINTANIMATION_H_


#include "FUiAnimAnimationBase.h"
#include "FGrpPoint.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	PointAnimation
 * @brief	This class animates the Point object.  
 * @since	2.0
 *
 * The %PointAnimation class animates an object from an Point value to another Point value
 * based on the specified interpolator type.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 */
class _EXPORT_ANIMATION_ PointAnimation: 
			public AnimationBase
{
public:
	/**
	 * This is the copy constructor for the %PointAnimation class.
	 *
	 * @since	2.0
	 * @param[in]	pointAnimation	An instance of %PointAnimation 	 
	 */
	PointAnimation(const PointAnimation& pointAnimation);
	
	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since	2.0
	 * @param[in]	rhs		An instance of %PointAnimation 
	 */
	PointAnimation& operator =(const PointAnimation& rhs);

	/**
	 * Checks whether the specified instance and the current instance of %PointAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %PointAnimation are equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PointAnimation
	 */
	bool operator ==(const PointAnimation& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %PointAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %PointAnimation are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %PointAnimation
	 */
	bool operator !=(const PointAnimation& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %PointAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance equals the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %PointAnimation
	 * @remarks 	The %PointAnimation class has a semantic value. @n
	 *				This means the Equals() method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	The two equal instances should return the same hash value. For better performance, the used hash function must generate a random 
	 *			distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;
	
	/**
	 * Initializes this instance of %PointAnimation with the specified parameters.
	 *
	 * @since	2.0
	 * @param[in]	startValue		The start value for %PointAnimation
	 * @param[in]	endValue		The end value for %PointAnimation
	 * @param[in]	duration		The duration of %Animation in milliseconds
	 * @param[in]	interpolator	The type of interpolator used for the intermediate value calculation of the animation
	 */
	PointAnimation(const Osp::Graphics::Point& startValue,const Osp::Graphics::Point& endValue, long duration, AnimationInterpolatorType interpolator);

	/**
	 * The destructor for %PointAnimation class.
	 *
	 * @since	2.0
	 */
	virtual ~PointAnimation(void);

	/**
	 * Gets the animated value for the current time. 
	 *
	 * @since	2.0
	 * @return 		An error code	
	 * @param[in] 	currentTime		The current time value of the animation @n
	 *								The value should be between @c 0 and the duration of the animation
	 * @param[out] 	animatedValue	The animated value for the current time passed as the input parameter
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception 	E_INVALID_ARG 	A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE This instance has not been properly constructed.  	
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result GetAnimatedValue(long currentTime, Osp::Graphics::Point& animatedValue);

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
	 * @remarks		If @c time is greater than the duration, it becomes the new duration and @c value becomes the new @c endValue. @n
	 * 				The old duration and @c endValue are added as a new key frame entry in the list. @n
	 *      		If a key-value pair with the current key already exists, then the old value will be overwritten with the new one. @n
	 *     		    An exception will be returned if time is equal to @c 0 or duration of the animation.
	 */
	result AddKeyFrame(long time, const Osp::Graphics::Point& value);

	/**
	 * Gets the keyframe at a particular index in this animation.
	 *
     * @since	2.0	 
	 * @return 		An error code
	 * @param[in]	index				The index value in the Keyframe list @n
	 *                              	The value is sorted in an increasing order of time.
	 * @param[out]	time				The time stamp at the specified index
	 * @param[out]	value				The value at the specified index
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed. 
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range. 
	 * @exception 	E_SYSTEM			A system error has occurred.
	 * @remarks		The @c time and @c value returned are present at the index of the sorted map list that is sorted with respect to the key.
	 * 				For example, if the user adds key-frame in the order (10,value1),(20,value2),(5,value3) and 
	 * 				GetKeyFrameAt(0,time,value) is called, the pair returned is (5,value3).
	 */
	result GetKeyFrameAt(int index, long& time, Osp::Graphics::Point& value) const;

	/**
	 * Removes the passed keyframe object from the keyframe list.
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
	 *                              	The value is sorted in an increasing order of time.
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
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE 	This instance has not been properly constructed.  		 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetStartValue(const Osp::Graphics::Point& startValue);

	/**
	 * Sets the end value of the animation.
	 *
	 * @since	2.0
	 * @return 		An error code
	 * @param[in]	endValue			The end value of the animation to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.  		 
 	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetEndValue(const Osp::Graphics::Point& endValue);

	/**
	 * Gets the start value of the animation.
	 *
     * @since	2.0	 
	 * @return	The start value
	 */
	Osp::Graphics::Point GetStartValue(void) const;

	/**
	 * Gets the end value of the animation.
	 *
	 * @since	2.0
	 * @return	The end value
	 */
	Osp::Graphics::Point GetEndValue(void) const;

	/**
	 * Gets the type information of this instance.
	 *
     * @since	2.0	
	 * @return 	The type information of this instance
	 */
	virtual AnimationType GetType(void) const;

protected:
	
	friend class PointAnimationEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class PointAnimationEx* __pPointAnimationEx;	
	
private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	PointAnimation(void);
};

}; }; };

#endif	// _FUIANIM_POINTANIMATION_H_
