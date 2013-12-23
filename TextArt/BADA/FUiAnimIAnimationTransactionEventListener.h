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
 * @file		FUiAnimIAnimationTransactionEventListener.h
 * @brief		This is the header file for the %IAnimationTransactionEventListener interface.
 *
 * This header file contains the declarations of the %IAnimationTransactionEventListener interface.
 */

#ifndef _FUIANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_
#define _FUIANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_

#include "FUiConfig.h"
#include "FBaseTypes.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { namespace Animations {

/**
 * @enum	AnimationTransactionStatus
 *
 * Defines the transaction status of the animation.
 * @since	2.0
 */
enum AnimationTransactionStatus
{
	ANIMATION_TRANSACTION_STATUS_PLAYING,		/**< A transaction being played */
	ANIMATION_TRANSACTION_STATUS_STOPPED,		/**< A transaction stopped */
};

/**
 * @interface	IAnimationTransactionEventListener
 * @brief		This interface implements the listener for the %Animation transaction events defined in the %Osp::%Ui::%Animations namespace.
 * @since		2.0
 *
 * The %IAnimationTransactionEventListener interface is the listener interface for receiving animation transaction events. 
 * The class that processes an animation transaction event implements this interface, and the instance created with that class is
 * registered with AnimationTransaction, using the AnimationTransaction::SetTransactionEventListener() method. When the animation
 * transaction event occurs, a method of that instance is invoked.
 */
class _EXPORT_UI_ IAnimationTransactionEventListener :
	public Osp::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
     * @since	2.0
	 */
	virtual ~IAnimationTransactionEventListener(void) {}
	
	/**
	 * Called when the transaction starts.
	 *
     * @since		2.0	 
	 * @param[in] 	transactionId		The transaction ID of the transaction for which the event has occurred
	 */
	virtual void OnAnimationTransactionStarted(int transactionId) = 0;
		
	/**
	 * Called when the transaction stops.
	 *
     * @since		2.0	 
	 * @param[in] 	transactionId		The transaction ID of the transaction for which the event has occurred
	 * @remarks 	This callback is called when user calls AnimationTransaction::Stop().
	 */
	virtual void OnAnimationTransactionStopped(int transactionId) = 0;

	/**
	 * Called when the transaction is finished.
	 *
	 * @since		2.0	 
	 * @param[in]	transactionId		The source of the event
 	 * @remarks 	This callback is called when all the animations in a transaction are finished.
	 */
	virtual void OnAnimationTransactionFinished(int transactionId) = 0;

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
	virtual void IAnimationTransactionEventListener_Reserved1(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void IAnimationTransactionEventListener_Reserved2(void) { }

	/** 
	 * @internal This method is for internal use only. The bada platform team is not 
	 * 			 responsible for any behavioral correctness, consistency, and 
	 * 			 security-related issues that might arise after using this method.
	 *
	 * The method for internal usage.
	 *
	 * @since  2.0
	 */
	virtual void IAnimationTransactionEventListener_Reserved3(void) { }
};

}; }; }; 

#endif // _FUIANIM_IANIMATION_TRANSACTION_EVENT_LISTENER_H_
