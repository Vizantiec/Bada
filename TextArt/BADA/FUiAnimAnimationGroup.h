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
 * @file		FUiAnimAnimationGroup.h
 * @brief		This is the header file for the %AnimationGroup class.
 *
 * This header file contains the declarations of the %AnimationGroup class and its helper classes.
 */

#ifndef _FUIANIM_ANIMATION_GROUP_H_
#define _FUIANIM_ANIMATION_GROUP_H_

#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FUiAnimAnimationBase.h"

namespace Osp { namespace Ui { namespace Animations {


/**
* @enum      AnimationGroupType
* Defines the animation group type information.
*
* @since 2.0
*/
enum AnimationGroupType
{
       ANIMATION_GROUP_TYPE_SEQUENTIAL = 0,      /** The sequential animation group */
       ANIMATION_GROUP_TYPE_PARALLEL,            /** The parallel animation group */
};


/**
 * @class	AnimationGroup
 * @brief	This class is used to group a set of animations together.  
 * @since	2.0
 *
 * The %AnimationGroup class is used to group a set of animations together.
 */ 
class _EXPORT_ANIMATION_ AnimationGroup:
	public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~AnimationGroup(void);

	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since	2.0
	 */
	virtual void RemoveAllAnimations(void) = 0;

	/**
	 * Gets the animation count value.
	 *
	 * @since		2.0
	 * @return 		The total number of animations added to the group
	 */
	virtual int GetAnimationCount(void) const = 0;	

	/**
	* Gets the type information of this instance
	*
	* @since      2.0 
	* @return     The type information of this instance
	*/
	virtual AnimationGroupType GetType(void) const = 0;



protected:
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 * @since	2.0
	 */
	AnimationGroup();

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator implementation for this class.
	 * @since		2.0
	 * @param[in]	rhs		An instance of AnimationGroup
	 */
	AnimationGroup& operator =(const AnimationGroup& rhs);

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
	 * @since	2.0
	 * @param[in]	animationGroup	An instance of AnimationGroup
	 */
	AnimationGroup(const AnimationGroup& animationGroup);
	
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 * 			 responsible for any behavioral correctness, consistency, and
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void AnimationGroup_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void AnimationGroup_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void AnimationGroup_Reserved3(void) { }

	friend class AnimationGroupEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class AnimationGroupEx* __pAnimationGroupEx;	
};

}; }; };

#endif	// _FUIANIM_ANIMATION_GROUP_H_
