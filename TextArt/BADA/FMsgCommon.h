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
 * @file		FMsgCommon.h
 * @brief		This is the header file for the messaging classes.
 *
 * This header file contains the type declarations for the %Messaging namespace.
 */

#ifndef _FMSG_COMMON_H_
#define _FMSG_COMMON_H_

// Include
#include "FMsgConfig.h"

namespace Osp { namespace Messaging {
	/**
	* @enum RecipientType
	* Defines the recipient type for Short Message Service(SMS), Multimedia %Messaging Service(MMS) and email messages.
	*
	* @since 1.0
	*/
	typedef enum {
		RECIPIENT_TYPE_TO = 0,		/**<The recipient is in 'To' list */
		RECIPIENT_TYPE_CC,			/**<The recipient is in 'Cc' list */
		RECIPIENT_TYPE_BCC			/**<The recipient is in 'Bcc' list */
	} RecipientType;

	/**
	* @enum AddressType
	* Defines the address type format. @n
	* All recipient addresses must be of one of the following types.
	*
	* @since 1.0
	*/
	typedef enum {
		ADDRESS_TYPE_PHONE = 0,		/**<The phone number type */
		ADDRESS_TYPE_EMAIL			/**<The email type */
	} AddressType;

	/**
	* @enum SmsMessageBoxType
	* Defines the message box type for Short Message Service(SMS) messages.
	*
	* @since 2.0
	*/
	typedef enum {
		SMS_MESSAGE_BOX_TYPE_NONE = -1,		/**< None	*/
		SMS_MESSAGE_BOX_TYPE_INBOX = 0,		/**< The Inbox type */
		SMS_MESSAGE_BOX_TYPE_SENTBOX = 1,	/**< The Sentbox type */
		SMS_MESSAGE_BOX_TYPE_OUTBOX = 2,	/**< The Outbox type */
		SMS_MESSAGE_BOX_TYPE_ALL = 10		/**< All message box type */
	} SmsMessageBoxType;


	/**
	* @internal
	* This enum is for internal use only. The bada platform team is not responsible
	* for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	*
	* @enum EmailMessagePriority
	* Defines the priority for email.
	*
	* @since 1.0
	*/
	typedef enum {
		EMAIL_MESSAGE_PRIORITY_HIGH = 0,	/**< @internal	High priority	*/
		EMAIL_MESSAGE_PRIORITY_NORMAL,		/**< @internal	Normal priority	*/
		EMAIL_MESSAGE_PRIORITY_LOW			/**< @internal	Low priority	*/
	} EmailMessagePriority;
};
};

#endif





