/* $Change: $ */
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
 * @file		FUiAnimIControlAnimatorDetailedEventListener.h 
 * @brief		This is the header file for the %IControlAnimatorDetailedEventListener interface.
 *
 * This header file contains the declarations of the %IControlAnimatorDetailedEventListener interface. 
 */

#ifndef _FUIANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_
#define _FUIANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_


#include "FUiConfig.h"
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseRtIEventListener.h"
#include "FUiAnimAnimationBase.h"

namespace Osp { namespace Ui { class Control; } }
namespace Osp { namespace Ui { namespace Animations { class ControlAnimator; } } }
namespace Osp { namespace Ui { namespace Animations {

/**
 * @enum	ControlAnimatorTriggerType
 * Defines the trigger for animations attached to a control.
 *
 * @since	2.0
 */
enum ControlAnimatorTriggerType
{
	ANIMATION_TRIGGER_USER = 0,				/**< The animation attached to %Control is explicitly triggered by the user */
	ANIMATION_TRIGGER_POSITION_CHANGE,		/**< The animation attached to %Control is implicitly triggered by changing the position of the control */
	ANIMATION_TRIGGER_SIZE_CHANGE,			/**< The animation attached to %Control is implicitly triggered by changing the size of the control */
	ANIMATION_TRIGGER_SHOW_STATE_CHANGE,	/**< The animation attached to %Control is implicitly triggered by changing the ShowState of the control */
};

/**
 * @interface	IControlAnimatorDetailedEventListener
 * @brief		This interface implements a detailed listener for animation events.
 * @since		2.0
 *
 * The %IControlAnimatorDetailedEventListener interface is the listener interface for receiving detailed control animator events. 
 * The class that processes a detailed control animator event implements this interface, and the instance created with that class
 * is registered with a UI control, using the animator's AddDetailedControlAnimatorEventListener() method. When the detailed
 * control animator event occurs, a method of that instance is invoked.
 */
class _EXPORT_UI_ IControlAnimatorDetailedEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0	 
	 */
	virtual ~IControlAnimatorDetailedEventListener(void) {}
	
	/**
	 * Called when an animation starts.
	 *
	 * @since	2.0	 	 
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control @n
	 *                              The animation starts on this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations, 
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the 
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationStarted(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control, Osp::Ui::Animations::ControlAnimatorTriggerType animTrigger,
			Osp::Ui::Animations::AnimationTargetType animTarget, Osp::Ui::Animations::AnimationBase *pAnimation) = 0;
		
	/**
	 * Called when an animation is repeated.
	 * This event occurs only when a user calls StartUserAnimation().
	 *
	 * @since	2.0	 
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control @n
	 *                              The animation is repeated on this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations, 
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the 
	 *								application), @c pAnimation is @c null.
	 * @param[in] 	repeatCount		The current repeat count of the animation
	 */
	virtual void OnControlAnimationRepeated(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control, Osp::Ui::Animations::ControlAnimatorTriggerType animTrigger, 
			Osp::Ui::Animations::AnimationTargetType animTarget, Osp::Ui::Animations::AnimationBase *pAnimation, int repeatCount) = 0;

	/**
	 * Called when an animation finishes.
	 *
 	 * @since	2.0
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control @n
	 *                              The animation with the specified trigger type has finished for this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations, 
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the 
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationFinished(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control, Osp::Ui::Animations::ControlAnimatorTriggerType animTrigger,
			Osp::Ui::Animations::AnimationTargetType animTarget, Osp::Ui::Animations::AnimationBase *pAnimation) = 0;

	
	/**
	 * Called when an animation stops.
	 *
 	 * @since	2.0
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control @n
	 *                              The animation with the specified trigger type has stopped for this control.
	 * @param[in]	animTrigger		The animator trigger type of the control @n
	 *                              The animation event has occurred for the specified trigger type.
	 * @param[in]	animTarget		The animation target type @n
	 *                              The animation event has occurred for the specified animation target type. In the case of implicit animations, 
	 *								@c animTarget is @c ANIMATION_TARGET_NONE.
	 * @param[in]	pAnimation		The animation object @n
	 *                              The event occurs for this animation object. In the case of implicit animations (animations not defined by the 
	 *								application), @c pAnimation is @c null.
	 */
	virtual void OnControlAnimationStopped(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control, Osp::Ui::Animations::ControlAnimatorTriggerType animTrigger,
			Osp::Ui::Animations::AnimationTargetType animTarget, Osp::Ui::Animations::AnimationBase *pAnimation) = 0;

protected:
	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */	
	virtual void IControlAnimatorDetailedEventListener_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */	
	virtual void IControlAnimatorDetailedEventListener_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void IControlAnimatorDetailedEventListener_Reserved3(void) { }
};

}; }; };

#endif // _FUIANIM_ICONTROL_ANIMATOR_DETAILED_EVENT_LISTENER_H_
