/* $Change: 1142016 $ */
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
 * @file		FTelITelephonyCallEventListener.h
 * @brief		This is the header file for the %ITelephonyCallEventListener interface.
 *
 * This header file contains the declarations of the %ITelephonyCallEventListener interface.
 */
 
#ifndef _FTEL_TELEPHONY_CALL_EVENT_LISTENER_H_
#define _FTEL_TELEPHONY_CALL_EVENT_LISTENER_H_

#include "FBase.h"
#include "FTelConfig.h"
#include "FTelNetworkStatus.h"
#include "FTelCallInfo.h"

namespace Osp { namespace Telephony {

/**
 * @interface	ITelephonyCallEventListener
 * @brief		This interface provides methods that are called when the status of a call changes.
 * @since		2.0
 *
 * The %ITelephonyCallEventListener interface notifies the application about the changes in the telephony call status.
 *
 */
class _EXPORT_TEL_ ITelephonyCallEventListener
	: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			2.0
	 */
	virtual ~ITelephonyCallEventListener(void) {}

// Operation
public:	

	/**
	* Called when the status of a call is changed.
	*
	* @since			2.0
	*	@param[in]	callStatus		The new status of a call
	*	@param[in]	pCallInfo		The detailed information of a call
	*	@see				Osp::Telephony::CallStatus
	*/
	virtual void OnTelephonyCallStatusChangedN(CallStatus callStatus, CallInfo* pCallInfo) = 0;

protected:

	// reserved virtual methods for later extension

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following methods are reserved, and the name of methods can be changed any time without prior notice.
	 *
	 * @since	2.0
	 */
	virtual void ITelephonyCallEventListener_Reserved1(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following methods are reserved, and the name of methods can be changed any time without prior notice.
	 *
	 * @since	2.0
	 */
	virtual void ITelephonyCallEventListener_Reserved2(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following methods are reserved, and the name of methods can be changed any time without prior notice.
	 *
	 * @since	2.0
	 */
	virtual void ITelephonyCallEventListener_Reserved3(void) {}
};	

};};
#endif // _FTEL_TELEPHONY_CALL_EVENT_LISTENER_H_
