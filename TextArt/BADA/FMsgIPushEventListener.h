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
 * @file		FMsgIPushEventListener.h 
 * @brief		This is the header file for the %IPushEventListener interface.
 *
 * This header file contains the declaration of the %IPushEventListener interface.
 */

#ifndef _FMSG_IPUSHEVENTLISTENER_H_
#define _FMSG_IPUSHEVENTLISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FMsgConfig.h"
#include "FMsgPushMessage.h"

namespace Osp { namespace Messaging {

	/**
	* @interface	IPushEventListener
	* @brief		This is the listener interface for receiving push messages.
	* @since		2.0
	*
	* The %IPushEventListener interface must be implemented to receive the push messages. An application must register this interface using the PushManager::Construct() method.
	*/
	class  _EXPORT_MSG_ IPushEventListener
		: public Osp::Base::Runtime::IEventListener
	{
		// Operations	
	public:
		/**
		* Called when a push message is received from the server.
		*
		* @since		2.0
		* @param[in]	message		The push message
		*/
		virtual void OnPushMessageReceived(const PushMessage& message) = 0;
	};
};
};

#endif // _FMSG_IPUSHEVENTLISTENER_H_
