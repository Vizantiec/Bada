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
* @file		FMessaging.h
* @brief	This header file contains the declarations of the %Messaging namespace.
*
* This header file contains the declarations and descriptions of the %Messaging namespace.
*/
#ifndef _FMESSAGING_H_
#define _FMESSAGING_H_

// Include
#include "FMsgCommon.h"
#include "FMsgSmsMessage.h"
#include "FMsgMmsMessage.h"
#include "FMsgEmailMessage.h"
#include "FMsgPushMessage.h"
#include "FMsgSmsManager.h"
#include "FMsgMmsManager.h"
#include "FMsgEmailManager.h"
#include "FMsgPushManager.h"
#include "FMsgRecipientList.h"
#include "FMsgISmsListener.h"
#include "FMsgIMmsListener.h"
#include "FMsgIEmailListener.h"
#include "FMsgISmsEventListener.h"
#include "FMsgISmsMessageEventListener.h"
#include "FMsgIPushEventListener.h"
#include "FMsgIPushManagerListener.h"

/**
 * @namespace	Osp::Messaging
 * @brief		This namespace contains classes and interfaces for messaging services.
 * @since		1.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FMessaging.h> @n
 *				@b Library: @b FOsp
 *
 * The %Messaging namespace accesses the messaging capabilities of the device. @n
 * It provides classes and interfaces for the following: @n
 * - SMS: create, send, receive, and retrieve
 * - MMS: create and send
 * - email: create and send
 * - push: receive
 *
 * For more information on the %Messaging namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Messaging namespace.
 * @image html messaging_using_the_apis_classdiagram.png
 *
 */
namespace Osp
{ 
	namespace Messaging
	{

	};

}; // Osp::Messaging

#endif // _FMESSAGING_H_
