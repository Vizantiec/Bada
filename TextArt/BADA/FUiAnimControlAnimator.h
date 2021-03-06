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
 * @file	FUiAnimControlAnimator.h
 * @brief	This is the header file for the %ControlAnimator class.
 *
 * This header file contains the declarations of the %ControlAnimator class.
 */
 
#ifndef _FUIANIM_CONTROL_ANIMATOR_H_
#define _FUIANIM_CONTROL_ANIMATOR_H_


#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FBaseObject.h"
#include "FUiAnimConfig.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FGrpDimension.h"
#include "FBaseColArrayListT.h"
#include "FBaseColArrayList.h"
#include "FUiAnimAnimationBase.h"		
#include "FUiAnimSequentialAnimationGroup.h"
#include "FUiAnimParallelAnimationGroup.h"
#include "FUiAnimIControlAnimatorEventListener.h"
#include "FUiAnimIControlAnimatorDetailedEventListener.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	ControlAnimator
 * @brief	This class defines the animation methods for %Control.
 * @since	2.0
 *
 * The %ControlAnimator class is used to control the animations operated on Osp::Ui::Controls.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 *
 */
class _EXPORT_ANIMATION_ ControlAnimator :
	public Osp::Base::Object
{
public:
	/** 
	 * This is the destructor for this class. 
     * @since	2.0	 
	 */	
	virtual ~ControlAnimator(void);
	
	/**
	 * Starts an animation explicitly. @n
	 * If multiple controls need to be animated simultaneously, the controls should be part of AnimationTransaction(). @n
	 * This method should be called after AnimationTransaction::Begin() and before AnimationTransaction::Commit().
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	animTarget			The property to be animated
	 * @param[in]	animation			An object of type %AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		An animation is deleted at the end of the animation playback. @n
	 * 				RectangleAnimation is used to animate only one animation target at a time.
	 * 				For example, if %AnimationTarget is @c ANIMATION_TARGET_SIZE, %RectangleAnimation performs only the Dimension animation. @n
	 * 				To perform animation using the ANIMATION_TARGET_POSITION and ANIMATION_TARGET_SIZE properties, %AnimationTransaction should be used with 
	 *				a separate call for each animation target.
	 */
	result StartUserAnimation(AnimationTargetType animTarget, const AnimationBase& animation);
	
	/**
 	 * Starts a group of animations explicitly. @n
	 * If multiple controls need to be animated simultaneously, the control should be part of AnimationTransaction.
	 * This method should be called after AnimationTransaction::Begin and before AnimationTransaction::Commit.
	 *
     * @since	2.0
	 * @return		An error code
	 * @param[in]	animGroup			An animation group having a list of animations.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The animations are deleted at the end of the animation playback. @n
	 * 				%RectangleAnimation is used to animate only one animation target at a time.
	 */
	result StartUserAnimation(const AnimationGroup& animGroup);
	
	/**
	 * Stops all the animations that are currently playing and jumps to the final frame of the animation.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result StopAllAnimations(void);

	/**
	 * Stops the animation with the specified trigger type.
	 *
     * @since		2.0	 
	 * @return		An error code
	 * @param[in]	animTrigger		 	The animator trigger type
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result StopAnimation(ControlAnimatorTriggerType animTrigger);

	/**
	 * Gets the status of an animation with respect to a control.
	 *
     * @since		2.0	 
	 * @return		The animation state
	 */
	AnimatorStatus GetStatus(void) const;
	
	/**
	 * Gets the status of an animation for the specified animation target type.
	 *
     * @since	2.0
	 * @return		The state of an animation with type @c animTarget
	 * @param[in]	animTarget		The animation target type
	 */
	AnimatorStatus GetStatus(AnimationTargetType animTarget) const;

	/**
	 * Adds the %IControlAnimatorEventListener listener instance to the current instance of the control. @n
	 * The %IControlAnimatorEventListener listener is called for status changes of animations associated with a control.
	 * The added listener listens to events on the specified event dispatcher's context when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
 	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		For animations that are part of %AnimationTransaction, the applications need to listen to %IAnimationTransactionEventListener events. @n
	 *				The %IControlAnimatorEventListener events are not fired if the animation is part of a transaction. 
	 */
	result AddControlAnimatorEventListener(const IControlAnimatorEventListener& listener);

	/**
	 * Removes the %IControlAnimatorEventListener listener instance from the current instance of the control. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.	 
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveControlAnimatorEventListener(const IControlAnimatorEventListener& listener);
	
	/**
	 * Adds a %IControlAnimatorDetailedEventListener listener instance to the current instance of the control. @n
	 * The %IControlAnimatorDetailedEventListener listener is called for status changes of each animation associated with the control. @n
	 * The added listener listens to events on the specified event dispatcher's context when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be added
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		For animations that are part of %AnimationTransaction, the applications need to listen to the IAnimationTransactionEventListener events. @n
	 *				The %IControlAnimatorDetailedEventListener events are not fired if the animation is part of a transaction. 
	 */
	result AddControlAnimatorDetailedEventListener(const IControlAnimatorDetailedEventListener& listener);

	/**
	 * Removes an %IControlAnimatorDetailedEventListener instance from the current instance of the control. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
     * @since	2.0	
	 * @return		An error code
	 * @param[in]	listener				The listener to be removed
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION	The animation support is unavailable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RemoveControlAnimatorDetailedEventListener(const IControlAnimatorDetailedEventListener& listener);
	
	/**
  	 * Sets an animation group for the specified trigger type.
	 *
     * @since	2.0	 
	 * @return		An error code
 	 * @param[in]	animTrigger				The animator trigger type to which the animation needs to be applied
	 * @param[in]	pAnimation				An object of type %AnimationBase @n
	 *										If @c null is passed, the default animation values are used for animation with the specified trigger type.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option is not supported.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks ANIMATION_TRIGGER_USER is not supported. @n
	 * 			The @c holdEnd value and @c AutoReverse value are set to @c true and @c false respectively. @n
	 * 			An exception is returned if the animation group does not contain an animation with the target type that is being animated for the specified 
	 *			trigger type. The start value of an animation object of the associated target type for the specified trigger type is overwritten by the 
	 *			current property value of the %Control instance and the end value is overwritten by the value that is being set by the user. @n
	 * 			The associated target types for each trigger are as below: @n
	 * 			\verbatim 
				Animation Trigger          	    	-   Target Type
				ANIMATION_TRIGGER_POSITION_CHANGE   -   ANIMATION_TARGET_POSITION
				ANIMATION_TRIGGER_SIZE_CHANGE       -   ANIMATION_TARGET_SIZE
				ANIMATION_TRIGGER_SHOW_STATE_CHANGE -   ANIMATION_TARGET_ALPHA
				\endverbatim
	 */
	result SetAnimation(ControlAnimatorTriggerType animTrigger, const AnimationGroup* pAnimation);

	/**
  	 * Gets a group of animations.
	 *
     * @since	2.0
	 * @return 		An animation group object at the specified animation trigger type, @n
	 *				else @c null if the animation is empty or %AnimationTriggerType is %ANIMATION_TRIGGER_USER
 	 * @param[in]	animTrigger			The animator trigger type to get an animation group object
	 */
	AnimationGroup* GetAnimationN(ControlAnimatorTriggerType animTrigger) const;

	/**
	 * Sets the position of the control. @n
	 * An animation is played while changing the position of the control.	 
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]   x               		The new X position of the object
	 * @param[in]   y               		The new Y position of the object
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 *
	 * @remarks  The X and Y position of the object are relative to the top-left corner of its parent. @n
	 * 			 Draw() and Show() need not be called to display the control. The animation uses linear interpolator and is played for a default duration if 
	 *			 the user does not overwrite the values using SetAnimation().
	 *
	 * @see		SetBounds()
	 * @see     SetSize()
	 */
	result SetPosition(int x, int y);
	
	/**
	 * Sets the position of the control. @n
	 * An animation is played while changing the position of the control.
	 *
     * @since	2.0	 
	 * @return      An error code
	 * @param[in]   Position        		The new position.
	 * @exception   E_SUCCESS		        The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception   E_SYSTEM                A system error has occurred.
	 *
	 * @remarks		The position of the object is relative to the top-left corner of its parent. @n
	 * 			 	Draw() and Show() need not be called to display the control. @n	 
	 *				The animation uses linear interpolator and is played for a default duration if the user does not overwrite the values using SetAnimation().
	 *
	 * @see         SetPosition()
	 * @see         SetBounds()
	 * @see         SetSize()
	 */
	result SetPosition(const Osp::Graphics::Point& Position);
	
	/**
	 * Sets the size of the control. @n
	 * An animation is played while changing the size of the control. @n	 
	 * The @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
     * @since	2.0	 
	 * @return      An error code
	 * @param[in]   width           		The new width of the object
	 * @param[in]   height          		The new height of the object
	 * @exception   E_SUCCESS           	The method is successful.
	 * @exception   E_INVALID_ARG       	The specified input parameter is invalid. @n
	 *                                      The value of @c width or @c height is @c 0 or is a negative value.
	 * @exception   E_INVALID_OPERATION 	The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception   E_SYSTEM        		A system error has occurred.
	 *
	 * @remarks		Draw() and Show() need not be called to display the control. @n
 	 *				The animation uses linear interpolator and is played for a duration of 250ms if the user does not overwrite the values using SetAnimation().
	 *
	 * @see         SetBounds()
	 * @see         SetPosition()
	 */
	result SetSize(int width, int height);

	/**
	 * Sets the size of the control. @n
 	 * An animation is played while changing the size of the control. @n
	 * The @c width becomes @c size.width, and the @c height becomes @c size.height.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	size             		The new width and height
	 * @exception	E_SUCCESS        		The method is successful.
	 * @exception	E_INVALID_ARG    		The specified input parameter is invalid. @n
	 *                                      The value @c size.width or @c size.height is @c 0 or is a negative value.
	 * @exception   E_INVALID_OPERATION 	The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_SYSTEM		 		A system error has occurred.
	 *
 	 * @remarks		Draw() and Show() need not be called to display the control. @n
 	 *				The animation uses linear interpolator and is played for a duration of 250ms if the user does not overwrite the values using SetAnimation().
	 *
	 * @see			SetSize()
	 * @see	  		SetBounds()
	 * @see   		SetPosition()
	 */
	result SetSize(const Osp::Graphics::Dimension& size);
	
	/**
	 * Sets the position and size of the control. @n
	 * An animation is played while changing the position and size of the control. @n
	 * The position is set to (x, y), and the @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]  	 x               		The new X position of the object
	 * @param[in]  	 y               		The new Y position of the object
	 * @param[in]   width           		The new width of the object
	 * @param[in]   height          		The new height of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	 *                                      The value @c width or the @c height is @c 0 or a negative value.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *
	 * @remarks     Changing the position of a parent object does not change the position of its children, the top-left position that is relative to the 
	 *				top-left corner of the parent container. If calling this method causes re-positioning of an object or changes the size of the object, the 
	 *				system redraws the object and all its children. @n
	 * 		    	Draw() and Show() need not be called to display the control. @n
	 *				The animation uses linear interpolator and is played for a duration of 250ms if the user does not overwrite the values using SetAnimation().
	 *
	 * @see         SetPosition()
	 * @see         SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control. @n
	 * An animation is played while changing the position and size of the control.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	rect					The new bounds of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	 *                                      The value of @c rect.width or @c rect.height is @c 0 or a negative value.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *
	 * @see   		SetBounds()
	 * @see   		SetPosition()
	 * @see   		SetSize()
	 *
	 * @remarks		Draw() and Show() need not be called to display the control. @n	 
 	 *				The animation uses linear interpolator and is played for a duration of 250ms if the user does not overwrite the values using SetAnimation().     
	 */
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	 * Sets the show state of the control with animation.
	 *
     * @since	2.0	 
	 * @return		An error code
	 * @param[in]	show					The show state of the object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 *
     * @remarks		Draw() and Show() need not be called to display the control. @n
	 *				The animation uses linear interpolator and is played for a duration of 250ms if the user does not overwrite the values using SetAnimation().
	 */
	result SetShowState(bool show);
	
	/**
	 * Checks whether animation is supported for the control with the specified target type.
	 *
     * @since	2.0
	 * @return		@c true if animation is supported, @n
	 *				else @c false
	 * @param[in]	animTarget	The animation target
	 */	
	bool IsAnimationSupported(AnimationTargetType animTarget) const;

protected:	

	friend class ControlAnimatorEx;

	/** 
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class ControlAnimatorEx* __pControlAnimatorEx;

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * This method returns %ControlAnimatorEx object
	 *
     * @since	2.0
	 * @return		The %ControlAnimatorEx instance
	 */
	ControlAnimatorEx* GetControlAnimatorEx(void);
	
private:
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * This is the constructor for %ControlAnimator class.
     * @since	2.0	 
	 */
	ControlAnimator(void);

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * Initializes this %ControlAnimator class.
	 *
     * @since	2.0	 	 
	 * @return		An error code
	 * @param[in]	source				An instance of control class
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance is not in valid state.
	 * @exception   E_OUT_OF_MEMORY  	Insufficient memory.
	 * @exception	E_SYSTEM			System error occurred.
	 */
	result Construct(const Osp::Ui::Control& source);
	
	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class. @n
	 *
     * @since	2.0	 	 
	 */
	ControlAnimator(const ControlAnimator& animator);

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator implementation for this class. @n
	 *
     * @since	2.0	 
	 */
	ControlAnimator& operator =(const ControlAnimator& rhs);
	
	friend class Osp::Ui::Control;
	friend class FrameAnimator;
};
	
}; }; }; 

#endif//_FUIANIM_CONTROL_ANIMATOR_H_
