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
 * @file		FUiAnimIControlAnimatorEventListener.h 
 * @brief		This is the header file for the %IControlAnimatorEventListener interface.
 *
 * This header file contains the declarations of the %IControlAnimatorEventListener interface. 
 */

#ifndef _FUIANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_
#define _FUIANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_


#include "FUiConfig.h"
#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FBaseRtIEventListener.h"

#include "FUiAnimAnimationBase.h"


namespace Osp { namespace Ui { class Control; } }
namespace Osp { namespace Ui { namespace Animations { class ControlAnimator; } } }

namespace Osp { namespace Ui { namespace Animations {


/**
 * @interface	IControlAnimatorEventListener
 * @brief		This interface implements the listener for animation events.
 * @since		2.0
 *
 * The %IControlAnimatorEventListener interface is the listener interface for receiving control animator events. 
 * The class that processes a control animator event implements this interface, and the instance created with that class is
 * registered with a UI control, using the animator's AddControlAnimatorEventListener() method. When the control animator event
 * occurs, a method of that instance is invoked.
 */
class _EXPORT_UI_ IControlAnimatorEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 * @since	2.0	 
	 */
	virtual ~IControlAnimatorEventListener(void) {}

	/**
	 * Called when an animation starts on the specified control.
	 *
	 * @since		2.0	 
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control on which an animation starts
	 */
	virtual void OnControlAnimationStarted(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control) = 0;
	
	/**
	 * Called when all the animations currently associated with a control have finished.
	 *
	 * @since		2.0	 
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control on which all the animations have finished
	 */
	virtual void OnControlAnimationFinished(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control) = 0;

	/**
	 * Called when all the animations currently associated with a control have stopped.
	 *
	 * @since		2.0	 
	 * @param[in] 	source			The source of the event
 	 * @param[in] 	control			The control on which all the animations have stopped
	 */
	virtual void OnControlAnimationStopped(Osp::Ui::Animations::ControlAnimator& source, Osp::Ui::Control& control) = 0;	
	
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
	virtual void IControlAnimatorEventListener_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */		 
	virtual void IControlAnimatorEventListener_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */		
	virtual void IControlAnimatorEventListener_Reserved3(void) { }
};

}; }; };

#endif // _FUIANIM_ICONTROL_ANIMATOR_EVENT_LISTENER_H_
