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
 * @file		FMsgISmsListener.h
 * @brief		This is the header file for the %ISmsListener interface.
 *
 * This header file contains the declarations of the %ISmsListener interface.
 */

#ifndef _FMSG_ISMSLISTENER_H_
#define _FMSG_ISMSLISTENER_H_

// Includes
#include "FBase.h"
#include "FMsgConfig.h"
#include "FMsgCommon.h"

namespace Osp { namespace Messaging {


	/**
	* @interface	ISmsListener
	* @brief		This is the listener interface for receiving SMS sent status.
	* @since		1.0
	*
	* The %ISmsListener interface must be implemented to receive the status of the sent SMS messages asynchronously. An application must register this interface using the SmsManager::Construct() method.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ ISmsListener :
		public Osp::Base::Runtime::IEventListener
	{
		// Operation
	public:

		/**
		* Called when the SMS message is sent.
		*
		* @since			1.0
		* @param[in]	r					The result of sending the SMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FAILURE			The method has failed to send the message.
		* @see			SmsManager::Send()
		*/
		virtual void OnSmsMessageSent(result r) = 0;
	};

};
};

#endif // _FMSG_ISMSLISTENER_H_
