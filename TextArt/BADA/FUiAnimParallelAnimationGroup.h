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
 * @file		FUiAnimParallelAnimationGroup.h
 * @brief		This is the header file for the %ParallelAnimationGroup class.
 *
 * This header file contains the declarations of the %ParallelAnimationGroup class.
 */

#ifndef _FUIANIM_PARALLEL_ANIMATION_GROUP_H_
#define _FUIANIM_PARALLEL_ANIMATION_GROUP_H_


#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FUiAnimAnimationBase.h"
#include "FUiAnimAnimationGroup.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	ParallelAnimationGroup
 * @brief	This class is used to group a set of animations together.  
 * @since	2.0
 *
 * The %ParallelAnimationGroup class is used to group a set of animations together in parallel.  
 */ 
class _EXPORT_ANIMATION_ ParallelAnimationGroup:
	public AnimationGroup
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ParallelAnimationGroup(void);

	/**
	 * This is the assignment operator implementation for this class.
	 *
	 * @since	2.0
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup	 
	 */
	ParallelAnimationGroup& operator =(const ParallelAnimationGroup& rhs);

	/**
	 * Checks whether the specified instance and the current instance of %ParallelAnimationGroup have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %ParallelAnimationGroup have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup
	 */
	bool operator ==(const ParallelAnimationGroup& rhs) const;
		
	/**
	 * Checks whether the specified instance and the current instance of %ParallelAnimationGroup have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %ParallelAnimationGroup are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup
	 */
	bool operator !=(const ParallelAnimationGroup& rhs) const;	

	/** 
	 * Checks whether the value of the current instance of %ParallelAnimationGroup equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %ParallelAnimationGroup
	 * @remarks 	The %ParallelAnimationGroup class has a semantic value. @n
	 *				This means the Equals() method checks whether the two instances have the same animation.
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
	 * This is the copy constructor for the %ParallelAnimationGroup class.
	 *
	 * @since	2.0
	 * @param[in]	animationGroup	An instance of %ParallelAnimationGroup 
	 */
	ParallelAnimationGroup(const ParallelAnimationGroup& animationGroup);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ParallelAnimationGroup(void);

	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since	2.0
	 */
	virtual void RemoveAllAnimations(void);

	/**
	 * Gets the total number of animations currently stored in a group.
	 *
	 * @since	2.0
	 * @return 		The total number of animations stored in a group
	 */
	virtual int GetAnimationCount(void) const;

	/**
	 * Adds an animation to the animation group. @n
	 * Each animation target can have only one animation.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	animTarget			The animation target type @n
	 *                              	The animation is applied to the specified animation target type.
	 * @param[in]	animation			An object of type AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		A specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance has not been constructed properly.
	 * @exception   E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks If an animation is added to a target type that already has an animation associated with it, the old animation is overwritten with the new animation.
	 */
	result AddAnimation(AnimationTargetType animTarget, const AnimationBase& animation);
	
	/**
	 * Removes an animation from the animation group with the specified animation target.
	 *
	 * @since	2.0
	 * @return		An error code
	 * @param[in]	animTarget		The animation target
	 * @exception	E_SUCCESS		The method is successful.
 	 * @exception 	E_INVALID_ARG 	The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	This instance has not been constructed properly.
	 * @exception	E_OBJ_NOT_FOUND	The animation with the specified animation target does not exist in the animation group.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAnimation(AnimationTargetType animTarget);
	
	/**
	 * Gets the animation object for the specified animation target.
	 *
	 * @since		2.0
	 * @return 		An animation for the specified animation target in the animation group, @n
	 *				else @c null if the animation target is empty
     * @param[in]	animTarget		The animation target type to get an animation object
	 */
	AnimationBase* GetAnimationN(AnimationTargetType animTarget) const;
	
	/**
	 * Checks whether an animation is added for the specified target type.
	 *
	 * @since	2.0
	 * @return 		@c true if an animation is associated with the specified target type, @n
	 *              else @c false
	 * @param[in]	targetType		The animation target type
	 */
	bool IsAnimationAdded(AnimationTargetType targetType);

	/**
	 * Returns the type information of this instance.
	 *
	 * @since      2.0         
	 * @return     The type information of this instance
	 */
	virtual AnimationGroupType GetType(void) const;

protected:

	friend class ParallelAnimationGroupEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class AnimationGroupParallelEx* __pParallelAnimationGroupEx;
};

}; }; };

#endif	// _FUIANIM_PARALLEL_ANIMATION_GROUP_H_
