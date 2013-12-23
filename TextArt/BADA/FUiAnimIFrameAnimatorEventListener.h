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
 * @file	FUiAnimIFrameAnimatorEventListener.h 
 * @brief	This is the header file for the %IFrameAnimatorEventListener interface.
 *
 * This header file contains the declarations of the %IFrameAnimatorEventListener interface. 
 */

#ifndef _FUICTRL_IFRAME_ANIMATOR_EVENT_LISTENER_H_
#define _FUICTRL_IFRAME_ANIMATOR_EVENT_LISTENER_H_


#include "FUiConfig.h"
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseRtIEventListener.h"

#include "FUiAnimAnimationBase.h"


namespace Osp { namespace Ui { namespace Controls { class Form; } } }
namespace Osp { namespace Ui { namespace Controls { class Frame; } } }
namespace Osp { namespace Ui { namespace Animations { class FrameAnimator; } } }

namespace Osp { namespace Ui { namespace Animations {

/**
 * @enum	FrameAnimatorFormTransitionAnimation
 * Defines the platform predefined animation set for the animation events.
 *
 * @since	2.0	 
 */
enum FrameAnimatorFormTransitionAnimation
{
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_LEFT = 0,	/**< The transition animation using Translate Left animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_RIGHT,		/**< The transition animation using Translate Right animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_FADE_IN_OUT,			/**< The transition animation using Alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_IN,				/**< The transition animation using Scale animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_OUT,				/**< The transition animation using Scale animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_DEPTH_IN,				/**< The transition animation using Scale and Alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_DEPTH_OUT,				/**< The transition animation using Scale and Alpha animation */
	FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_MAX					/**< @internal This value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this value. */
};

/**
 * @interface	IFrameAnimatorEventListener
 * @brief		This interface implements the listener for animation events.
 * @since		2.0
 *
 * The %IFrameAnimatorEventListener interface is the listener interface for receiving frame animator events. 
 * The class that processes a frame animator event implements this interface, and the instance created with that class is
 * registered with a Frame, using the animator's AddFrameAnimatorEventListener() method. When the frame animator event occurs, a
 * method of that instance is invoked.
 */
class _EXPORT_UI_ IFrameAnimatorEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0	 
	 */
	virtual ~IFrameAnimatorEventListener(void) {}
	
	/**
	 * Called when the animation of a form transition starts.
	 *
	 * @since		2.0	 	 
	 * @param[in] 	source			The source of the event
  	 * @param[in] 	frame			The frame @n
	 *                              The frame that starts the animation of a form transition.
 	 * @param[in] 	form1			The form @n
	 *                              The animation starts on this form.
 	 * @param[in] 	form2			The form @n
	 *                              The animation starts on this form
 	 */
	virtual void OnFormTransitionAnimationStarted(Osp::Ui::Animations::FrameAnimator& source, Osp::Ui::Controls::Frame& frame, Osp::Ui::Controls::Form& form1, Osp::Ui::Controls::Form& form2) = 0;

	/**
	 * Called when the animation of a form transition stops.
	 *
	 * @since		2.0	 	 
	 * @param[in] 	source			The source of the event
  	 * @param[in] 	frame			The frame @n
	 *                              The frame that stops the animation of a form transition.
 	 * @param[in] 	form1			The form @n
	 *                              The animation stops on this form.
 	 * @param[in] 	form2			The form @n
	 *                              The animation stops on this form.
 	 */
	virtual void OnFormTransitionAnimationStopped(Osp::Ui::Animations::FrameAnimator& source, Osp::Ui::Controls::Frame& frame, Osp::Ui::Controls::Form& form1, Osp::Ui::Controls::Form& form2) = 0;

	/**
	 * Called when the animation of a form transition finishes.
	 *
 	 * @since	2.0
	 * @param[in] 	source			The source of the event
  	 * @param[in] 	frame			The frame @n
	 *                              The frame that finishes the animation of a form transition.
 	 * @param[in] 	form1			The form @n
	 *                              The animation finishes on this form.
 	 * @param[in] 	form2			The form @n
	 *                              The animation finishes on this form.
	 */
	virtual void OnFormTransitionAnimationFinished(Osp::Ui::Animations::FrameAnimator& source, Osp::Ui::Controls::Frame& frame, Osp::Ui::Controls::Form& form1, Osp::Ui::Controls::Form& form2) = 0;

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
	virtual void IFrameAnimatorEventListener_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */		
	virtual void IFrameAnimatorEventListener_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */		
	virtual void IFrameAnimatorEventListener_Reserved3(void) { }
};

}; }; }; 

#endif // _FUIANIM_IFRAME_ANIMATOR_EVENT_LISTENER_H_
