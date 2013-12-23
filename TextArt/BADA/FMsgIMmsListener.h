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
 * @file		FMsgIMmsListener.h
 * @brief		This is the header file for the MMS messaging interface.
 *
 * This header file contains the declarations of the %IMmsListener interface.
 */

#ifndef _FMSG_MMSLISTENER_H_
#define _FMSG_MMSLISTENER_H_

// Includes
#include "FBase.h"
#include "FMsgConfig.h"
#include "FMsgCommon.h"

namespace Osp { namespace Messaging {


	/**
	* @interface	IMmsListener
	* @brief		This is the listener interface for receiving MMS sent status.
	* @since		1.0
	*
	* The %IMmsListener interface must be implemented to receive the status of the sent MMS messages asynchronously. An application must register this interface using the MmsManager::Construct() method.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ IMmsListener :
		public Osp::Base::Runtime::IEventListener
	{
		// Operation
	public:

		/**
		* Called when the Multimedia Messaging Service(MMS) message is sent.
		*
		* @since			1.0
		* @param[in]	r						The result of sending the MMS message
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_CONTENT		The content is invalid.
		* @exception	E_NETWORK_UNAVAILABLE	The network has a problem.
		* @exception	E_SERVICE_UNAVAILABLE	The service is unavailable.
		* @exception	E_INVALID_ADDRESS		The address is invalid.
		* @exception	E_FAILURE				The method has failed to send the message.
		* @see			MmsManager::Send()
		*/
		virtual void OnMmsMessageSent(result r) = 0;
	};

};
};

#endif // _FMSG_MMSLISTENER_H_
