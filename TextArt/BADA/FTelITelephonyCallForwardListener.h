/* $Change: 904753 $ */
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
 * @file		FTelITelephonyCallForwardListener.h
 * @brief		This is the header file for the %ITelephonyCallForwardListener interface.
 *
 * This header file contains the declarations of the %ITelephonyCallForwardListener interface.
 */
 
#ifndef _FTEL_TELEPHONY_CALL_FORWARD_LISTENER_H_
#define _FTEL_TELEPHONY_CALL_FORWARD_LISTENER_H_

#include "FBase.h"
#include "FTelConfig.h"

namespace Osp { namespace Telephony {

/**
 * @if PRIVCORE
 * @interface	ITelephonyCallForwardListener
 * @brief		This interface provides the methods to listen to the results of the call forwarding request.
 * @since		2.0
 *
 * The %ITelephonyCallForwardListener interface provides the methods to listen to the results of the call forwarding request.
 * @endif
 */
class _EXPORT_TEL_ ITelephonyCallForwardListener
	: public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * @if PRIVCORE
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 * @endif
	 */
	virtual ~ITelephonyCallForwardListener(void) {}

// Operation
public:	

	/**
	* @if PRIVCORE
	* Called when a response of the call forwarding request is received.
	*
	* @since	2.0
	* @param[in]	phoneNumber				The phone number
	* @param[in]	r						The result of the call forwarding request
    * @exception	E_SUCCESS				The method is successful.
	* @exception	E_NOT_RESPONDING  		The server on the telephony network is not responding.
    * @exception	E_SYSTEM				A system error has occurred.
    *
	* @endif
	*/
	virtual void OnTelephonyCallForwardResponseReceived(const Osp::Base::String& phoneNumber, result r) = 0;

	/**
	* @if PRIVCORE
	* Called when a response of the call forwarding stop request is received.
	*
	* @since	2.0
	* @param[in]	phoneNumber				The phone number
	* @param[in]	r						The result of the call forwarding request
    * @exception	E_SUCCESS				The method is successful.
	* @exception	E_NOT_RESPONDING  		The server on the telephony network is not responding.
    * @exception	E_SYSTEM				A system error has occurred.
    *
	* @endif
	*/
	virtual void OnTelephonyCallForwardStopped(const Osp::Base::String& phoneNumber, result r) = 0;

	/**
	* @if PRIVCORE
	* Called when a query for the call forwarding number is completed.
	*
	* @since	2.0
	* @param[in]	phoneNumber				The phone number
	* @param[in]	r						The result of the query request
    * @exception	E_SUCCESS				The method is successful.
	* @exception	E_NOT_RESPONDING  		The server on the telephony network is not responding.
	* @exception	E_SERVICE_DEACTIVATED 	The call forwarding service is not enabled.
    * @exception	E_SYSTEM				A system error has occurred.
    *
  	* @endif
	*/
	virtual void OnTelephonyCallForwardNumberReceived(const Osp::Base::String& phoneNumber, result r) = 0;

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
	virtual void ITelephonyCallForwardListener_Reserved1(void) {}

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
	virtual void ITelephonyCallForwardListener_Reserved2(void) {}

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
	virtual void ITelephonyCallForwardListener_Reserved3(void) {}
};	

};};
#endif // _FTEL_TELEPHONY_CALL_FORWARD_LISTENER_H_
