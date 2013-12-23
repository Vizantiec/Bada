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
 * @file		FUiAnimSequentialAnimationGroup.h
 * @brief		This is the header file for the %SequentialAnimationGroup class.
 *
 * This header file contains the declarations of the %SequentialAnimationGroup class.
 */

#ifndef _FUIANIM_SEQUENTIAL_ANIMATION_GROUP_H_
#define _FUIANIM_SEQUENTIAL_ANIMATION_GROUP_H_


#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FUiAnimAnimationBase.h"
#include "FUiAnimAnimationGroup.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	SequentialAnimationGroup
 * @brief	This class is used to group a set of animations together.  
 * @since	2.0
 *
 * The %SequentialAnimationGroup class is used to group a set of animations together in sequence.
 */ 
class _EXPORT_ANIMATION_ SequentialAnimationGroup:
	public AnimationGroup
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	SequentialAnimationGroup(void);

	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since		2.0
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 */
	SequentialAnimationGroup& operator =(const SequentialAnimationGroup& rhs);

	/**
	 * Checks whether the specified instance and the current instance of %SequentialAnimationGroup have equal animation values.
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %SequentialAnimationGroup have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 */
	bool operator ==(const SequentialAnimationGroup& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %SequentialAnimationGroup have different animation values.
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %SequentialAnimationGroup are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 */
	bool operator !=(const SequentialAnimationGroup& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %SequentialAnimationGroup is equal to the value of the specified instance.
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %SequentialAnimationGroup
	 * @remarks 	The %SequentialAnimationGroup class has a semantic value. @n
	 *				This means the Equals() method checks whether the two instances have the same animation.
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
	 * This is the copy constructor for the %SequentialAnimationGroup class.
	 *
	 * @since	2.0
	 * @param[in]	animationGroup		An instance of %SequentialAnimationGroup	 
	 */
	SequentialAnimationGroup(const SequentialAnimationGroup& animationGroup);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~SequentialAnimationGroup(void);

	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since	2.0
	 */
	virtual void RemoveAllAnimations(void);

	/**
	 * Gets the number of animations currently stored in a group.
	 *
	 * @since	2.0
	 * @return 		The total number of animations stored in a group
	 */
	virtual int GetAnimationCount(void) const;

	/**
	 * Adds the specified animation to the animation group.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	animTarget			The animation target type @n
	 *                              	The animation is applied to the specified animation target type.
	 * @param[in]	animation			An instance of %AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
	 * @exception   E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddAnimation(AnimationTargetType animTarget, const AnimationBase& animation);

	/**
	 * Sets the specified animation to the animation group.
	 *
	 * @since   2.0
	 * @return		An error code
	 * @param[in]	index				The index at which the animation is to be set
	 * @param[in]	animTarget			The AnimationTargetType to which the animation needs to be applied
	 * @param[in]	animation			An instance of %AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified index is out of range.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
	 * @exception   E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception   E_SYSTEM			A system error has occurred.
	 *
	 * @remarks If an animation is added to the same index which already has an animation associated with it, the old animation will be overwritten with the new one.
	 */
	result SetAnimationAt(int index, AnimationTargetType animTarget, const AnimationBase& animation);

	/**
	 * Inserts the specified animation to the animation group.
	 *
	 * @since   2.0
	 * @return		An error code
	 * @param[in]   index				The index at which the animation is to be inserted
	 * @param[in]   animTarget			The %AnimationTargetType to which the animation needs to be applied
	 * @param[in]   animation			An instance of %AnimationBase
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
	 * @exception   E_OUT_OF_RANGE  	The specified index is out of range.
	 * @exception   E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result InsertAnimationAt(int index, AnimationTargetType animTarget, const AnimationBase& animation);

	/**
	 * Removes the animation from the animation group at the specified index.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	index				An index value in the animation group list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_OUT_OF_RANGE		The specified index is out of range.
	 * @exception	E_INVALID_STATE		This instance has not been properly constructed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveAnimationAt(int index);

	/**
	 * Gets the animation object at the specified index.
	 *
	 * @since	2.0
	 * @return 		The animation object at the specified index value in the animation group, @n
	 *				else @c null if the index is invalid
	 * @param[in]	index			The index value in the animation group list
	 */
	AnimationBase* GetAnimationAtN(int index) const;
	
	/**
	 * Gets the target type of the animation at the specified index.
	 *
	 * @since	2.0
	 * @return 		The target type of the animation at the specified index value in the animation group, @n
	 *				else @c ANIMATION_TARGET_NONE if the specified index is invalid
	 * @param[in]	index			The index value in the animation group list
	 */
	AnimationTargetType GetAnimationTargetTypeAt(int index) const;	

	/**
	 * Gets the type information of this instance
	 *
	 * @since      2.0         
	 * @return     The type information of this instance
	 */
	virtual AnimationGroupType GetType(void) const;

protected:

	friend class SequentialAnimationGroupEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class AnimationGroupSequentialEx* __pSequentialAnimationGroupEx;
};

}; }; };

#endif	// _FUIANIM_SEQUENTIAL_ANIMATION_GROUP_H_
