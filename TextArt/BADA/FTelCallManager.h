/* $Change: 1154502 $ */
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
 * @file		FTelCallManager.h 
 * @brief		This is the header file for the %CallManager class.
 *
 * This header file contains the declarations of the %CallManager class.
 */

#ifndef _FTEL_CALLMANAGER_H_
#define _FTEL_CALLMANAGER_H_

// Includes
#include "FBase.h"
#include "FTelConfig.h"
#include "FTelEnum.h"
#include "FTelITelephonyCallEventListener.h"
#include "FTelITelephonyCallForwardListener.h"
#include "FTelCallInfo.h"

namespace Osp { namespace Telephony { class ICallManagerPi; };};

namespace Osp { namespace Telephony {

/**
 * @class	CallManager
 * @brief	This class provides the methods to obtain information about the current call.
 * @since	1.0
 *
 * The %CallManager class provides methods to obtain the current call information and status.
 *
 * The following example demonstrates how to use the %CallManager class.
 *
 * @code
 *
 *	result
 *	MyClass::GetCallInfo(void)
 *	{
 *		CallType callType = TYPE_UNDEFINED_CALL;
 *		CallStatus callStatus = CALL_STATUS_UNDEFINED;
 *
 *		CallManager *pCallManager = new CallManager();
 *
 *		result r = pCallManager->Construct(*this);
 *		if (IsFailed(r))
 *		{
 *			delete pCallManager;
 *			return r;
 *		}
 *
 *		callStatus = pCallManager->GetCurrentCallStatus();
 *
 *		if(callStatus == CALL_STATUS_COMMUNICATING)
 *			callType = pCallManager->GetCurrentCallType();
 *
 *		delete pCallManager;
 *		return E_SUCCESS;
 *	}
 *
 *	void
 *	MyClass::::OnTelephonyCallStatusChangedN(CallStatus  callStatus,CallInfo *  pCallInfo)
 *	{
 *		CallType	callType;
 *		String		number;
 *
 *		if (callStatus == CALL_STATUS_RINGING) {
 *			callType  = pCallInfo->GetCallType();
 *			number = pCallInfo->GetNumber();
 *		}
 *
 *		delete pCallInfo;
 *	}
 *
 *
 * @endcode
 */
class _EXPORT_TEL_ CallManager
	: public Osp::Base::Object
{
// Life cycle
public:

	/**
	 *	This is the default constructor for this class.
	 *
	 * @since	1.0
	 */
	CallManager(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~CallManager(void);

	/**
	 * Initializes a new instance of this class. @n
	 * This is the two phase construction.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Initializes a new instance of this class. @n
	 * This is the two phase construction.
	 *
     * @since 		2.0
	 * @return		An error code
	 * @param[in]	listener			The listener for change in status of a call
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const ITelephonyCallEventListener& listener);

// Operation
public:

	/**
	 * @if PRIVCORE
	 * Sets the listener that listens to the call forwarding request.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup PRIVILEGED_TELEPHONY
	 *
	 * @return		An error code
	 * @param[in]	pListener			A pointer to the ITelephonyCallForwardListener instance @n
	 *           The parameter can be set to @c null to remove listener.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @endif
	 */
	result SetCallForwardListener(const ITelephonyCallForwardListener* pListener);

	/**
	 * @if PRIVCORE
	 * Requests call forwarding for the specified phone number. @n
	 * This method sends the request to the network, and receives the response asynchronously.
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup PRIVILEGED_TELEPHONY

	 *
	 * @return		An error code
	 * @param[in]	phoneNumber			The phone number for call forwarding
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_INVALID_FORMAT  	The specified phone number is in an invalid format.
	 * @exception	E_IN_PROGRESS		The previous request is in progress.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_NETWORK_UNAVAILABLE  The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE  The operation has failed because the device is out of the coverage area or in the emergency mode.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks The call will be forwarded unconditionally. Voice calls only. @n
	 *          The phone number can start with plus(+) and the remaining part must contain digits.
	 *
	 * @see 	ITelephonyCallForwardListener::OnTelephonyCallForwardResponseReceived()      
	 *
	 * @endif
	 */
	result RequestCallForward(const Osp::Base::String& phoneNumber);

	/**
	 * @if PRIVCORE
	 * Stops call forwarding.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup PRIVILEGED_TELEPHONY

	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_IN_PROGRESS		The previous request is in progress.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_NETWORK_UNAVAILABLE  The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE  The operation has failed because the device is out of the coverage area or is in the emergency mode.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @see ITelephonyCallForwardListener::OnTelephonyCallForwardStopped()
	 *
	 *
	 * @endif
	 */
	result StopCallForward(void);

	/**
	 * @if PRIVCORE
	 * Gets the phone number to which the call should be forwarded.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup PRIVILEGED_TELEPHONY
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE  	This instance has not been constructed as yet.
	 * @exception	E_IN_PROGRESS		The previous request is in progress.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_NETWORK_UNAVAILABLE  The operation has failed because the device is in the offline mode.
	 * @exception	E_SERVICE_UNAVAILABLE  The operation has failed because the device is out of the coverage area or is in the emergency mode.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @see ITelephonyCallForwardListener::OnTelephonyCallForwardNumberReceived()
	 *
	 * @endif
	 */
	result GetCallForwardNumber(void) const;

	/**
	 * Gets the call type of the current call. 
	 *
	 * @since			1.0
	 * @return		The current call type, @n
     *              else Telephony::TYPE_UNDEFINED_CALL if the method fails
	 */
	CallType GetCurrentCallType(void) const;

	/**
	 * Gets the call status of the current call. 
	 *
	 * @since					1.0
     * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                For more information, see @ref CallManagerGetCurrentCallStatusPage "here".
	 *
	 *
	 * @return		The current call status, @n
     *              else Telephony::CALL_STATUS_UNDEFINED if the method fails
	 */
	CallStatus GetCurrentCallStatus(void) const;

private:
	CallManager(const CallManager& value);
	CallManager& operator =(const CallManager& value);

private:
	ICallManagerPi* 		__iCallManagerInterface;
	
private:
	friend class CallManagerEx;
	class CallManagerEx* __pCallManagerEx;
};

	/**
	* @page         CallManagerGetCurrentCallStatusPage Compatibility for GetCurrentCallStatus()
	*
	* @section       CallManagerGetCurrentCallStatusPageIssueSection Issues
	*                    Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*                -#  This method returns CALL_STATUS_IDLE or CALL_STATUS_ACTIVE.
	* @section       CallManagerGetCurrentCallStatusPageSolutionSection Resolutions
	*                -	From bada API version 2.0, the CallStatus enumerator is extended
	*				       with the CALL_STATUS_IDLE, CALL_STATUS_COMMUNICATING, CALL_STATUS_RINGING, and CALL_STATUS_DIALING call status values. @n
	*                -   The CALL_STATUS_ACTIVE call status value is deprecated. @n
	*/

};};
#endif // _FTEL_CALLMANAGER_H_
