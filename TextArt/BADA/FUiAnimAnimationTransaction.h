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
 * @file		FUiAnimAnimationTransaction.h
 * @brief		This is the header file for the %AnimationTransaction class.
 *
 * This header file contains the declarations of %AnimationTransaction class.
 */

#ifndef _FUIANIM_ANIMATION_TRANSACTION_H_
#define _FUIANIM_ANIMATION_TRANSACTION_H_


#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FUiAnimConfig.h"
#include "FUiAnimAnimationBase.h"
#include "FUiAnimIAnimationTransactionEventListener.h"


namespace Osp { namespace Ui { namespace Animations {


/**
 * @class	AnimationTransaction
 * @brief	This class defines the transaction operations of the animation.
 * @since	2.0
 *
 * The %AnimationTransaction class enables the applications to define animation transactions that makes a set of animations on one or more animators to start or stop at the same time.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation_handling.htm">Animation Handling</a>.
 *
 */
class _EXPORT_ANIMATION_ AnimationTransaction:
			public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
     * @since	2.0
	 */
	virtual ~AnimationTransaction(void);

	/**
	 * Initializes a transaction set. @n
     * Call StartUserAnimation() of animator after calling this method and before the EndTransaction() method.
	 * Nesting of the transaction set is allowed.
     *
     * @since		2.0
	 * @return		An error code	 
	 * @param[out]	transactionId		The transaction ID @n
     *                                  Use this transaction ID for further operations related to this transaction.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY  	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 */
	static result Begin(int& transactionId);
	
	/**
	 * Commits a set of animation start or stop commands that are added during the current transaction.
	 *
     * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY  	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	static result Commit(void);

	/**
	 * Stops the transaction that is being played and jumps to the final frame of the animation.
	 *
     * @since		2.0
	 * @return		An error code
	 * @param[in]	transactionId		The transaction ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception 	E_INVALID_ARG 		The specified input parameter is invalid 
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	static result Stop(int transactionId);
		
	/**
	 * Adds a listener instance to listen to the events of a particular transaction. @n
	 * The added listener, %IAnimationTransactionEventListener, can listen to events on the specified event dispatcher's context when they are fired.
	 *
     * @since		2.0
	 * @return		An error code
	 * @param[in]	pListener			The listener to be added
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.	 
	 *
 	 * @remarks		Only one event listener can be set. @n
	 * 				If @c pListener is @c null, the listener already set is unregistered. @n
	 * 				An application should deregister the registered listener if the listener object needs to be deleted.
	 */
	static result SetTransactionEventListener(const IAnimationTransactionEventListener* pListener);

	/**
	 * Returns the status of the specified transaction.
	 *
     * @since		2.0
	 * @return		The state of the transaction
	 * @param[in]	transactionId		The transaction ID
	 */
	static AnimationTransactionStatus GetStatus(int transactionId);

protected:		

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the default constructor for this class.
	 * @since	2.0	
	 */
	AnimationTransaction(void);	

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the copy constructor for this class.
	 * @since		2.0
	 * @param[in]	transaction		An instance of AnimationTransaction	 
	 */
	AnimationTransaction(const AnimationTransaction& transaction);

	/**
	 * @internal This method is for internal use only. The bada platform team is not
	 *			 responsible for any behavioral correctness, consistency, and
	 *			 security-related issues that might arise after using this method.
	 *
	 * This is the assignment operator implementation for this class.
	 * @since		2.0
	 * @param[in]	rhs				An instance of AnimationTransaction
	 */
	AnimationTransaction& operator =(const AnimationTransaction& rhs);
		
	friend class AnimationTransactionEx;

	/** 
	 * @internal This value is for internal use only. The bada platform team is not
	 *           responsible for any behavioral correctness, consistency, and
	 *           security-related issues that might arise after using this value.
	 *
	 * The value for internal usage.
	 *
	 * @since  2.0
	 */
	class AnimationTransactionEx* __pAnimationTransactionEx;	
};

}; }; };

#endif	// _FUIANIM_ANIMATION_TRANSACTION_H_
